#include <stdio.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
    int OpcionInicial;
    int CantidadRopa[13] = {10, 5, 7, 3, 15, 8, 6, 20, 10, 12, 9, 4, 11};
    char NombresRopa[13][20] = {
        {"Camisa"}, {"Camiseta"}, {"Sudadera"}, {"Chaqueta"}, {"Pantalones"},
        {"Shorts"}, {"Falda"}, {"Calzoncillos"}, {"Sujetador"}, {"Bragas"},
        {"Zapatos"}, {"Botas"}, {"Sandalias"}
    };
    float PreciosRopa[13] = {
        10.50, 8.99, 15.00, 25.00, 18.00,
        12.50, 14.99, 5.00, 10.00, 7.00,
        30.00, 45.00, 20.00
    };

    printf("=========== Bienvenido a Cloudclothes ===========\n");
    printf("\nStock Inicial:\n");
    for (int i = 0; i < 13; i++) {
        printf("%s: %d unidades - Precio: %.2f\n", NombresRopa[i], CantidadRopa[i], PreciosRopa[i]);
    }

    do {
        printf("\nSeleccione una opcion:\n");
        printf("-------------------------\n");
        printf("1. Anadir al stock\n");
        printf("2. Mostrar Inventario\n");
        printf("3. Buscar Ropa\n");
        printf("4. Editar Ropa\n");
        printf("5. Salir\n");
        printf("-------------------------\n");
        printf(">> ");
        scanf("%d", &OpcionInicial);

        if (OpcionInicial < 1 || OpcionInicial > 5) {
            printf("\n* Opción invalida. Por favor, ingrese un número entre 1 y 5 *\n");
        } else {
            switch (OpcionInicial) {
                case 1:
                    ingresarNuevaRopa(CantidadRopa, NombresRopa, PreciosRopa);
                    break;
                case 2:
                    mostrarInventario(CantidadRopa, NombresRopa, PreciosRopa);
                    break;
                case 3:
                    buscarRopa(NombresRopa, CantidadRopa, PreciosRopa, 13);
                    break;
                case 4:
                    editarPrenda(NombresRopa, CantidadRopa, PreciosRopa);
                    break;
                case 5:
                    printf("Saliendo del programa...\n");
                    break;
            }
        }
    } while (OpcionInicial != 5);

    return 0;
}
