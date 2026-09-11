#include <stdio.h>

void pares(int inf, int sup);
void impares(int inf, int sup);
void triangulo(char caracter, int alto);
int factorial(int numero);

int main(void) {
    int opcion;
    int inf, sup, alto, numero;
    char caracter;

    do {
        printf("Ingrese una opcion: \n");
        printf("    [1] Pares\n");
        printf("    [2] Impares\n");
        printf("    [3] Triangulo\n");
        printf("    [4] Factorial\n");
        printf("    [0] Matar programa\n");

        scanf("%d", &opcion);

        switch(opcion) {
            case 1: // Pares
                printf("Ingrese limite inferior: ");
                scanf("%d", &inf);
                printf("Ingrese limite superior: ");
                scanf("%d", &sup);
                pares(inf, sup);
                break;
            case 2: // Impares
                printf("Ingrese limite superior: ");
                scanf("%d", &sup);
                printf("Ingrese limite inf: ");
                scanf("%d", &sup);
                pares(inf, sup);
                break;
            case 3: // Triangulo
                printf("Ingrese un caracter: ");
                scanf("%c", caracter);
                printf("Ingrese el alto: ");
                scanf("%d", &alto);
                triangulo(caracter, alto);
                break;
            case 4: // Factorial
                printf("Ingrese un numero: ");
                scanf("%d", &numero);
                printf("El factorial es: %d\n", factorial(numero));
                break;
            case 0:
                printf("Matando programa.");
                break;
            default:
                printf("Opcion no valida.");
                break;
        }
    } while( opcion != 0 );

    return 0;
}

void pares(int inf, int sup) {
    while ( sup >= inf ) {
        if ( sup % 2 == 0) {
            printf("%d ", sup);
        }
        sup--;
    }
}

void impares(int inf, int sup) {
    while( sup >= inf ) {
        if( sup % 2 != 0 ) {
            printf("%d ", sup);
        }
        sup--;
    }
}

void triangulo(char caracter, int alto) {
    int fila = 1;
    int columna;

    while( fila <= alto ) {
        columna = 1;

        while( columna <= fila ) {
            printf("%c", caracter);
            columna++;
        }
        printf("\n");
        fila++;
    }
}

int factorial(int numero) {
    int resultado = 1;

    while( numero > 0 ) {
        resultado = resultado * numero;
        numero--;
    }
    return resultado;
}
