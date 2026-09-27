/*
 * Crea un programa que te pida escanear un limite inferior y un limite superior, que te imprima todos los numeros primos
 * si son numeros multiplos de 3 sean ignorados y que verifique que limite superior sea mayor o igual al limite inferior
 * void impares(int limSuperior, int limInferior)
 * El programa debe de escanear los numeros con solo un scanf.
*/

#include <stdio.h>

void impares(int limSuperior, int limInferior);

int main(void) {
    int limSuperior, limInferior;

    scanf("%d %d", &limSuperior, &limInferior);
    
    if ( limSuperior <= limInferior ) {
        printf("Error: El limite Superior debe ser mayor o igual al inferior.\n");
    }

    impares(limSuperior, limInferior);

    return 0;
}

void impares(int limSuperior, int limInferior) {
    int primos;

    for ( int i = limInferior; i < limSuperior; i++ ) {
        if ( i % 3 == 0 ) // Ignoramos multiplos de 3
            continue;

        primos = 1;

        if ( i < 2 )
            primos = 0;

        for ( int j = 2; j < i; j++ ) {
            if ( i % j == 0 ) {
                primos = 0;
                break;
            }
        }
        if ( primos )
            printf("%d ", i);
    }
    printf("\n");
}
