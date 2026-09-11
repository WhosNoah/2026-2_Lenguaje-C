#include <stdio.h>
#include <stdlib.h>

void limpiarBuffer(void);
void imprimirBinario(unsigned short int numero);
void imprimirBinarioInvertido(unsigned short int numero);
unsigned short int capturarUnsignedShortInt(char *mensaje);

int main(void) {
    system("clear");    
    int opcion;
    unsigned short int numero;

    do {
        printf("Ingrese una opcion.\n");
        printf("  [1] Imprimir binario.\n");
        printf("  [2] Imprimir binario invertido.\n");
        printf("  [3] Terminar programa.\n");
        scanf("%d", &opcion);


        switch(opcion) {
            case 1:
                numero = capturarUnsignedShortInt("Capture un numero: ");
                imprimirBinario(numero);
                break;
            case 2:
                capturarUnsignedShortInt("Capture un numero: ");
                imprimirBinarioInvertido(numero);
                break;
            case 3:
                break;
            default:
                printf("Opcion incorrecta, seleccione una opcion disponible.");
                break;
        }
    } while(opcion != 3);

    return 0;
}


void limpiarBuffer(void) {
    char c;
	while( (c=getchar())!='\n' && c!=EOF);
}

void imprimirBinario(unsigned short int numero) {
    int i;

    for ( i = 15; i >= 0; i--) {
        printf("%d", ((numero >> i)) & 1);
    }
    printf("\n");
}

void imprimirBinarioInvertido(unsigned short int numero) {
    int i;

    for ( i = 0; i <= 15; i++) {
        printf("%d", ((numero >> i)) & 1);
    }
    printf("\n");
}

unsigned short int capturarUnsignedShortInt(char *mensaje) {
    unsigned short int numero;
    
    printf("\n %s", mensaje);
    scanf("%hu", &numero);
    limpiarBuffer();

    return numero;
}