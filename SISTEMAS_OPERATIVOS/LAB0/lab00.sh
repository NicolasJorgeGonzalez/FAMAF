# Ejercicio 1
cat /proc/cpuinfo | grep "model name"

# Ejercicio 2
cat /proc/cpuinfo | grep "model name" | wc -l

# Ejercicio 3
wget -O heroes.csv https://raw.githubusercontent.com/dariomalchiodi/superhero-datascience/master/content/data/heroes.csv && cat heroes.csv | tail -n +2 | cut -d ';' -f 2 | grep -v '^$' | tr -d ' ' | tr '[:upper:]' '[:lower:]' > names.txt

# Ejercicio 4
sort -k 5 -n < weather_cordoba.in > weather_sorted.txt; head -n 1 weather_sorted.txt | cut -d ' ' -f 1-3; tail -n 1 weather_sorted.txt | cut -d ' ' -f 1-3

# Ejercicio 5
sort -k 3 -n < atpplayers.in > atpplayers_sorted.txt

# Ejercicio 6
sort -k 2 -n -r < superliga.in > superliga_sorted.txt; 

awk '
NR == 1 {
    # Inicializa variables para la primera línea.
    prev_points = $2;
    prev_goal_diff = $7 - $8;
    prev_line = $0;
    next
} 

{
    curr_goal_diff = $7 - $8;
    if ($2 == prev_points) {
        # Si los puntos son iguales, compara la diferencia de goles.
        if (curr_goal_diff > prev_goal_diff) {
            # Si la diferencia de goles actual es mayor, intercambia la línea actual con la anterior.
            aux_line = prev_line;
            prev_line = $0;
            $0 = aux_line;
            prev_goal_diff = curr_goal_diff;
        } else {
            # Si la diferencia de goles actual es menor, no hace nada y pasa a la siguiente línea.
            next;
        }
    }
}
END {
    # Asegúrate de imprimir la última línea procesada.
    print prev_line;
}' superliga_sorted.txt > superliga_final_sorted.txt

# Anotacion: se podria con sort -k 2,2n -k 7,7n superliga.in > superliga_sorted.txt

# Ejercicio 7
ip link show | grep -o -P "(?<=link/ether )([0-9a-f]{2}:){5}[0-9a-f]{2}"

# Anotacion: (?<=link/ether ) es un lookbehind assertion en las expresiones regulares de Perl. Busca una coincidencia que esté precedida por link/ether 

# Ejercicio 8
for file in SISTEMAS_OPERATIVOS/LAB0/breaking_bad/*_es.srt; do mv "$file" "${file/_es.srt/.srt}"; done

# Anotacion: con /*_es.srt iteramos sobre todos los archivos que terminan en _es.srt.
# ${file/_es.srt/.srt}: Usa una sustitución de cadena para reemplazar _es.srt con .srt