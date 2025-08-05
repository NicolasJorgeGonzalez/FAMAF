#include "command.h"
#include "strextra.h"

#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct scommand_s
{
    GList *command;
    char *input;
    char *output;
};

struct pipeline_s
{
    GSList *scommands;
    bool fg;
};

scommand scommand_new(void)
{
    scommand new_scommand = malloc(sizeof(struct scommand_s));
    new_scommand->command = NULL;
    new_scommand->input = NULL;
    new_scommand->output = NULL;

    assert(new_scommand != NULL && scommand_is_empty(new_scommand) && scommand_get_redir_in(new_scommand) == NULL && scommand_get_redir_out(new_scommand) == NULL);

    return new_scommand;
}

static void scommand_free(void *self)
{
    assert(self != NULL);
    scommand aux = self;
    scommand_destroy(aux);
}

scommand scommand_destroy(scommand self)
{
    assert(self != NULL);

    if (self->command != NULL)
    {
        g_list_free_full(self->command, free);
        self->command = NULL;
    }

    if (self->input != NULL)
    {
        free(self->input);
        self->input = NULL;
    }

    if (self->output != NULL)
    {
        free(self->output);
        self->output = NULL;
    }

    free(self);
    self = NULL;
    assert(self == NULL);
    return self;
}

void scommand_push_back(scommand self, char *argument)
{
    assert(self != NULL && argument != NULL);

    self->command = g_list_append(self->command, g_strdup(argument));

    assert(!scommand_is_empty(self));
}

void scommand_pop_front(scommand self)
{
    assert(self != NULL && !scommand_is_empty(self));

    gchar *element = g_list_nth_data(self->command, 0);
    self->command = g_list_remove(self->command, element);
    free(element);
}

void scommand_set_redir_in(scommand self, char *filename)
{
    assert(self != NULL);
    if (self->input != NULL)
    { // Si ya había una cadena, liberarla
        free(self->input);
    }
    self->input = g_strdup(filename); // DUPLICAR STRING
}

void scommand_set_redir_out(scommand self, char *filename)
{
    assert(self != NULL);
    if (self->output != NULL)
    { // Si ya había una cadena, liberarla
        free(self->output);
    }
    self->output = g_strdup(filename); // DUPLICAR STRING
}

bool scommand_is_empty(const scommand self)
{
    assert(self != NULL);

    bool result = g_list_length(self->command) == 0;

    return result;
}

unsigned int scommand_length(const scommand self)
{
    assert(self != NULL);

    unsigned int result = g_list_length(self->command);

    assert((result == 0) == scommand_is_empty(self));

    return result;
}

char *scommand_front(const scommand self)
{
    assert(self != NULL && !scommand_is_empty(self));

    char *result = g_list_nth_data(self->command, 0);

    assert(result != NULL);

    return result;
}

char *scommand_get_redir_in(const scommand self)
{
    assert(self != NULL);

    return self->input;
}

char *scommand_get_redir_out(const scommand self)
{
    assert(self != NULL);

    return self->output;
}

char *scommand_to_string(scommand self)
{
    assert(self != NULL);

    // Inicia con una cadena vacía asignada dinámicamente.
    // strmerge puede manejar un NULL como primer argumento, pero g_strdup("") es más explícito
    // y asegura que 'result_str' siempre apunte a memoria dinámica válida.
    char *result_str = g_strdup("");

    gchar *arg = NULL;
    int i = 0; // Contador para añadir espacios entre argumentos
    while (self->command != NULL)
    { // Mientras la lista de argumentos no esté vacía
        // Obtener el puntero al dato (el string) del primer nodo
        arg = (gchar *)self->command->data;

        // Eliminar el primer nodo de la lista y actualizar self->command.
        // g_list_remove solo desvincula el nodo, NO libera 'arg' ni el nodo GList.
        self->command = g_list_remove(self->command, arg);

        if (i > 0)
        {
            // Concatenar un espacio. strmerge libera el 'result_str' anterior.
            result_str = strmerge(result_str, " ");
        }
        // Concatena el argumento. strmerge libera el 'result_str' anterior.
        result_str = strmerge(result_str, arg);

        // ¡CRÍTICO!: Libera la memoria del argumento individual que acabamos de usar.
        g_free(arg);
        i++;
    }
    // Después del bucle, self->command será NULL (la lista está vacía)

    // Gestionar y concatenar redirecciones
    if (self->input != NULL)
    {
        result_str = strmerge(result_str, " < ");       // Añade " < ". strmerge libera el 'result_str' anterior.
        result_str = strmerge(result_str, self->input); // Añade el nombre del archivo. strmerge libera el 'result_str' anterior.
        g_free(self->input);                            // Libera la memoria del string 'input' de la estructura.
        self->input = NULL;                             // Marca el puntero como NULL para evitar dobles liberaciones.
    }
    if (self->output != NULL)
    {
        result_str = strmerge(result_str, " > ");        // Añade " > ". strmerge libera el 'result_str' anterior.
        result_str = strmerge(result_str, self->output); // Añade el nombre del archivo. strmerge libera el 'result_str' anterior.
        g_free(self->output);                            // Libera la memoria del string 'output' de la estructura.
        self->output = NULL;                             // Marca el puntero como NULL.
    }

    // La memoria de la propia estructura 'scommand' no se libera aquí.
    // Solo se vacían y liberan sus contenidos dinámicos.

    // La cadena final 'result_str' se asignó dinámicamente y debe ser liberada por el llamador.
    return result_str;
}

pipeline pipeline_new(void)
{
    pipeline new_pipeline = malloc(sizeof(struct pipeline_s));
    new_pipeline->scommands = NULL;
    new_pipeline->fg = true;

    assert(new_pipeline != NULL && pipeline_is_empty(new_pipeline) && pipeline_get_wait(new_pipeline));

    return new_pipeline;
}

pipeline pipeline_destroy(pipeline self)
{
    assert(self != NULL);

    if (self->scommands != NULL)
    {
        g_slist_free_full(self->scommands, scommand_free);
        self->scommands = NULL;
    }

    free(self);
    self = NULL;
    assert(self == NULL);
    return self;
}

void pipeline_push_back(pipeline self, scommand sc)
{
    assert(self != NULL && sc != NULL);

    self->scommands = g_slist_append(self->scommands, sc);

    assert(!pipeline_is_empty(self));
}

void pipeline_pop_front(pipeline self)
{
    assert(self != NULL && !pipeline_is_empty(self));

    scommand *element = g_slist_nth_data(self->scommands, 0);
    self->scommands = g_slist_remove(self->scommands, element);
}

void pipeline_set_wait(pipeline self, const bool w)
{
    assert(self != NULL);

    self->fg = w;
}

bool pipeline_is_empty(const pipeline self)
{
    assert(self != NULL);

    bool result = g_slist_length(self->scommands) == 0;

    return result;
}

unsigned int pipeline_length(const pipeline self)
{
    assert(self != NULL);

    unsigned int length = g_slist_length(self->scommands);

    assert((length == 0) == pipeline_is_empty(self));

    return length;
}

scommand pipeline_front(const pipeline self)
{
    assert(self != NULL);

    scommand result = g_slist_nth_data(self->scommands, 0);

    assert(result != NULL);

    return result;
}

bool pipeline_get_wait(const pipeline self)
{
    assert(self != NULL);

    return self->fg;
}

char *pipeline_to_string(pipeline self)
{
    assert(self != NULL);
    char *result_str = g_strdup(""); // Inicia con una cadena vacía asignada dinámicamente.

    scommand current_scommand = NULL;
    int i = 0; // Contador para añadir " | " entre comandos
    while (self->scommands != NULL)
    { // Mientras la lista de scommands no esté vacía
        // Obtener el puntero al scommand del primer nodo
        current_scommand = (scommand)self->scommands->data;

        // Eliminar el primer nodo de la lista y actualizar self->scommands.
        // g_slist_remove solo desvincula el nodo, NO libera 'current_scommand' ni el nodo GSList.
        self->scommands = g_slist_remove(self->scommands, current_scommand);

        // Llamar a scommand_to_string para obtener la representación del comando.
        // ¡Importante!: Esta llamada a scommand_to_string CONSUME los argumentos del 'current_scommand'
        // y retorna un string que debe ser liberado.
        char *scommand_str = scommand_to_string(current_scommand);

        if (i > 0)
        {
            result_str = strmerge(result_str, " | "); // Añade " | ". strmerge libera el 'result_str' anterior.
        }
        result_str = strmerge(result_str, scommand_str); // Añade el string del scommand. strmerge libera el 'result_str' anterior.

        // ¡CRÍTICO!: Libera el string retornado por scommand_to_string.
        g_free(scommand_str);

        // ¡CRÍTICO!: Libera la memoria del scommand en sí, ya que ha sido sacado de la lista y procesado.
        scommand_destroy(current_scommand);
        i++;
    }
    // Después del bucle, self->scommands será NULL (la lista está vacía)

    // Gestionar y concatenar el indicador de background
    if (self->fg == false) // 'fg' es el nombre real del campo, no pipeline_get_wait()
    {
        result_str = strmerge(result_str, " &"); // Añade " &". strmerge libera el 'result_str' anterior.
    }

    // La propia estructura 'pipeline' no se libera aquí.
    // Solo se vacían y liberan sus contenidos dinámicos.

    // Aserción final (ajustada para el campo directo 'fg')
    assert(pipeline_is_empty(self) || self->fg || strlen(result_str) > 0);

    // La cadena final 'result_str' se asignó dinámicamente y debe ser liberada por el llamador.
    return result_str;
}