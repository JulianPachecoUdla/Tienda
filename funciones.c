#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarNuevaRopa(int CantidadRopa[], char NombresRopa[][20], float PreciosRopa[]) {
    int UnidadRopa;
    char RopaIngresada[20];

    printf("Que tipo de ropa quieres ingresar?\n");
    scanf("%s", RopaIngresada);
    printf("Cuántas unidades de %s quieres ingresar?\n", RopaIngresada);
    scanf("%d", &UnidadRopa);

    int indiceRopa = -1;
    for (int i = 0; i < 13; i++) {
        if (strcmp(RopaIngresada, NombresRopa[i]) == 0) {
            indiceRopa = i;
            break;
        }
    }

    if (indiceRopa != -1) {
        printf("Ingrese el precio de %s:\n", RopaIngresada);
        scanf("%f", &PreciosRopa[indiceRopa]);
        CantidadRopa[indiceRopa] += UnidadRopa;
        printf("Se han agregado %d unidades de %s al inventario.\n", UnidadRopa, RopaIngresada);
    } else {
        printf("Tipo de ropa no reconocido. Por favor, ingrese un tipo de ropa valido.\n");
    }
}

void mostrarInventario(int CantidadRopa[], char NombresRopa[][20], float PreciosRopa[]) {
    printf("Inventario de Ropa:\n");
    printf("==============================================\n");
    for (int i = 0; i < 13; i++) {
        printf("%s - Cantidad: %d - Precio: %.2f\n", NombresRopa[i], CantidadRopa[i], PreciosRopa[i]);
    }
}

void buscarNombres(char NombresRopa[][20], int n, char RopaBuscada[], int indices[]) {
    int indexCount = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(NombresRopa[i], RopaBuscada) == 0) {
            indices[indexCount] = i;
            indexCount++;
        }
    }
}

void buscarRopa(char NombresRopa[][20], int CantidadRopa[], float PreciosRopa[], int n) {
    char RopaBuscada[20];
    int indices[13];
    for (int i = 0; i < 13; i++) {
        indices[i] = -1;
    }
    int noexiste = 0;

    printf("Que tipo de ropa deseas buscar?\n");
    scanf("%s", RopaBuscada);
    buscarNombres(NombresRopa, n, RopaBuscada, indices);

    for (int i = 0; i < n; i++) {
        if (indices[i] != -1) {
            printf("--------------------------------\n");
            printf("La cantidad de %s en el inventario es: %d || Precio: %.2f\n", RopaBuscada, CantidadRopa[indices[i]], PreciosRopa[indices[i]]);
            noexiste = 1;
        }
    }

    if (noexiste == 0) {
        printf("Tipo de ropa no encontrada en el inventario.\n");
    }
}

int buscarXNombre(char NombresRopa[][20], int tamanio, char nombreABuscar[]) {
    for (int i = 0; i < tamanio; i++) {
        if (strcmp(NombresRopa[i], nombreABuscar) == 0) {
            return i;
        }
    }
    return -1;
}

void editarPrenda(char NombresRopa[][20], int CantidadRopa[], float PreciosRopa[]) {
    char nuevaDireccion[20], nombreABuscar[20];
    int nuevoValor;
    float nuevoPrecio;

    printf("Ingrese la prenda que desea editar: ");
    scanf("%s", nombreABuscar);

    int index = buscarXNombre(NombresRopa, 13, nombreABuscar);

    if (index != -1) {
        printf("Ingrese la nueva prenda: ");
        scanf("%s", nuevaDireccion);

        printf("Ingrese la nueva cantidad: ");
        scanf("%d", &nuevoValor);

        printf("Ingrese el nuevo precio: ");
        scanf("%f", &nuevoPrecio);

        strcpy(NombresRopa[index], nuevaDireccion);
        CantidadRopa[index] = nuevoValor;
        PreciosRopa[index] = nuevoPrecio;

        printf("Prenda actualizada exitosamente.\n");
    } else {
        printf("El nombre buscado no existe.\n");
    }
}
