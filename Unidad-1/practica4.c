#include <stdio.h>

void capturarArreglo(int *arreglo, int longitud);
void mostrarArreglo(int *arreglo, int longitud);
int masRepetido(int *arreglo, int longitud);
void ordenar(int *arreglo, int longitud);

int main(void) {
    int arreglo[6];
    int longitud = 6;

    int opcion;

    do {
        printf("*-------------------------*\n");
        printf("|  Seleccione una opcion  |\n");
        printf("*-------------------------*\n");
        printf("| 1. Capturar array.      |\n");
        printf("| 2. Mostrar array.       |\n");
        printf("| 3. Mostrar repetido.    |\n");
        printf("| 4. Ordenar array.       |\n");
        printf("| 5. Salir del programa.  |\n");
        printf("*-------------------------*\n");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                capturarArreglo(arreglo, longitud);
                break;
            case 2:
                mostrarArreglo(arreglo, longitud);
                break;
            case 3:
                printf("El valor mas repetido es: %d\n", masRepetido(arreglo, longitud));
                break;
            case 4:
                ordenar(arreglo, longitud);
                mostrarArreglo(arreglo, longitud);
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Seleccione una opcion valida.\n");
                break;
        }
    } while( opcion != 5 );

    return 0;
}

void capturarArreglo(int *arreglo, int longitud) {
    for ( int i = 0; i < longitud; i++ ) {
        printf("Captura un numero en la posicion %d: ", i);
        scanf("%d", &arreglo[i]);
    }
    printf("\n");
}

void mostrarArreglo(int *arreglo, int longitud) {
    for ( int i = 0; i < longitud; i++ ) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

int masRepetido(int *arreglo, int longitud) {
    int masRepetido = arreglo[0];
    int mayorConteo = 0;

    for ( int i = 0; i < longitud; i++ ) {
        int conteo = 0;

        for ( int j = 0; i < longitud; j++ ) {
            if ( arreglo[j] == arreglo[i] ) {
                conteo++;
            }
        }

        if ( conteo > mayorConteo ) {
            mayorConteo = conteo;
            masRepetido = arreglo[i];
        }
    }

    return masRepetido;
}

void ordenar(int *arreglo, int longitud) {
    for ( int i = 0; i <= longitud - 2; i++ ) {
        int minimo = i;

        for ( int j = i + 1; j <= longitud - 1; j++ ) {
            if ( arreglo[j] < arreglo[minimo] ) {
                minimo = j;
            }
        }

        int temp = arreglo[i];
        arreglo[i] = arreglo[minimo];
        arreglo[minimo] = temp;
    }
}