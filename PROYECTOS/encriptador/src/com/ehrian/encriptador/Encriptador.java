package com.ehrian.encriptador;

import com.ehrian.encriptador.Desencriptacion.Desencriptacion;
import com.ehrian.encriptador.Encriptacion.Encriptacion;
import com.ehrian.encriptador.Menu.Menu;
import java.util.Scanner;

public class Encriptador {

    public static void main(String[] args) {
        System.out.println("Bienvenido al Encriptador de EHRIAN");
        System.out.println("Desarrollado por: EHRIAN\n");

        try (Scanner scanner = new Scanner(System.in)) {
            Menu menu = new Menu();
            int opcion = menu.menu(scanner);

            while (opcion != 3) {
                switch (opcion) {
                    case 1 -> {
                        Encriptacion.encriptar();
                    }
                    case 2 -> {
                        Desencriptacion.desencriptar();
                    }
                    default -> {
                        System.out.println("Opción no válida. Intente de nuevo.\n");
                    }
                }
                opcion = menu.menu(scanner); // Volver a mostrar el menú
            }

            scanner.close();
            System.out.println("Gracias por usar el Encriptador de EHRIAN. ¡Hasta luego!");
        } catch (Exception e) {
            System.out.println("Ocurrió un error: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
