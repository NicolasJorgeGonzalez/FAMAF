package com.ehrian.encriptador.Menu;

import java.util.Scanner;

public class Menu {

    public int menu(Scanner scanner) {
        int opcion;

        mostrarMenuPrincipal();

        opcion = scanner.nextInt();

        return opcion;
    }

    private static void mostrarMenuPrincipal() {
        System.out.print("Seleccione una opción:\n");
        System.out.println("1. Encriptar");
        System.out.println("2. Desencriptar");
        System.out.println("3. Salir");
    }
}
