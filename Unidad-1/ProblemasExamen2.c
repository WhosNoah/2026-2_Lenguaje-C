/*
 * Crea un programa que te muestre en pantalla los numeros en comun que tienen 2 arrays, ejemplo: {1, 5, 6, 2, 4} y {1, 5, 4, 3, 2, 0, 9} (Numeros en comun: 1, 5 y 4)
 * Ejemplo de funcion: void comunes(int arr1, int numero1, int arr2, int numero2)
*/

#include <stdio.h>

void comunes(int arr1[], int tam1, int arr2[], int tam2); // Donde tam1 y tam2 son los tamaños de los arreglos

int main(void) {
    int arr1[5] = {1, 5, 6, 2, 4};
    int arr2[7] = {1, 5, 4, 3, 2, 0, 9};

    int numero1 = 5;
    int numero2 = 7;

    printf("Numeros en comun: ");
    comunes(arr1, numero1, arr2, numero2);

    return 0;
}

void comunes(int arr1[], int tam1, int arr2[], int tam2) {
    for ( int i = 0; i < tam1; i++ ) {
        for ( int j = 0; j < tam2; j++ ) {
            if ( arr1[i] == arr2[j] ) {
                printf("%d ", arr1[i]);
                break;
            }
        }
    }
}
