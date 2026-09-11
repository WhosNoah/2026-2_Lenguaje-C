#include <stdio.h>
#include <stdlib.h>

int multiplicar(int x, int y);
int potencia(int x, int y);

int main(void) {

    system("clear");

    int boton;
    int x;
    int y;
    int resMultiplicar;
    int resPotencia;

    printf("+*-----–-----------------------*+\n");
    printf("|      Ingrese su operacion     |\n");
    printf("+*-----------------------------*+\n");
    printf("|                               |\n");
    printf("|   [1] Multiplicacion entera.  |\n");
    printf("|   [2] Potencia entera.        |\n");
    printf("|   [3] Salir del programa.     |\n");
    printf("|                               |\n");
    printf("+*-----–-----------------------*+\n");

    scanf("%d", &boton);
    switch(boton) {
        case 1: // Multiplicacion
            printf("\nIngrese su numero x: ");
            scanf("%d", &x);
            printf("\nIngrese su numero y: ");
            scanf("%d", &y);
            resMultiplicar = multiplicar(x, y);
            printf("\nEl resultado es: %d\n", resMultiplicar);
            break;
        case 2: // Potencia
            printf("\nIngrese su numero x: ");
            scanf("%d", &x);
            printf("\nIngrese su numero y: ");
            scanf("%d", &y);
            resPotencia = potencia(x, y);
            printf("\nEl resultado es: %d\n", resPotencia);

            if ( y == 0) { printf("El resultado es 1.\n"); }
            if (y < 0 ) { printf("Ingrese un valor positivo.\n"); }

            break;
        case 3: // Salida del programa.
            system("pkill -9 taller2");
    }

    return 0;
}

int multiplicar(int x, int y) {
    int res = 0;
    int negativo = 0;

    if ( x < 0 ) {
        x = -x;
        negativo++;
    }

    if ( y < 0 ) {
        y = -y;
        negativo++;
    }

    // Optimizador
    if ( x > y ) {
        int aux = x;
        x = y;
        y = aux;
    }

    while( x > 0 ) {
        res = res + y;
        x--;
    }

    if ( negativo == 1 ) {
        res = -res;
    }

    return res;
}

int potencia(int x, int y) {
    int res = 1;

    while ( y > 0 ) {
        res = multiplicar(res, x);
        y--;
    }
    return res;
}
