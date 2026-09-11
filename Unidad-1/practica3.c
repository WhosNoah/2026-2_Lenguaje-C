#include <stdio.h>

unsigned short int setBit(unsigned short int numero, int bit, int valor);
unsigned short int invertirBit(unsigned short int numero, int bit);

int main(void) {
    int opcion;
    unsigned short int numero, res;
    int bit, valor;

  do {
    printf("Seleccione una opcion: \n");
    printf("[1] Set bit.\n");
    printf("[2] Invertir bit.\n");
    printf("[3] Cerrar programa.\n");
    scanf("%d", &opcion);

    switch(opcion) {
      case 1:
        printf("Escanee un numero: ");
        scanf("%hu", &numero);
        printf("Numero: %hu   Binario: ", numero);
        for (int i = 15; i >= 0; i--) {
          printf("%d", (numero >> i) & 1);
        }
        printf("\n");
        printf("Ingrese el bit a cambiar (15-0): ");
        scanf("%d", &bit);
        printf("Ingrese el nuevo valor del bit (0 o 1): ");
        scanf("%d", &valor);
        res = setBit(numero, bit, valor);
        printf("RESULTADO: Decimal: %hu   Binario: ", res);
        for (int i = 15; i >= 0; i--) {
          printf("%d", (res >> i) & 1);
        }
        printf("\n");
        break;
      case 2:
        printf("Escanee un numero: ");
        scanf("%hu", &numero);
        printf("Numero: %hu   Binario: ", numero);
        for (int i = 15; i >= 0; i--) {
          printf("%d", (numero >> i) & 1);
        }
        printf("\n");
        printf("Ingrese el bit a invertir (15-0): ");
        scanf("%d", &bit);
        res = invertirBit(numero, bit);
        printf("RESULTADO: Decimal: %hu   Binario: ", res);
        for (int i = 15; i >= 0; i--) {
          printf("%d", (res >> i) & 1);
        }
        printf("\n");
        break;
      case 3:
        printf("Cerrando...\n");
        break;
      default:
        printf("Seleccione una opcion valida.\n");
        break;
    }
  } while (opcion != 3);
  return 0;
}

unsigned short int setBit(unsigned short int numero, int bit, int valor) {
  if (valor == 1) {
    numero = numero | (1 << bit);
  } else {
    numero = numero & ~(1 << bit);
  }

  return numero;
}

unsigned short int invertirBit(unsigned short int numero, int bit) {
  numero = numero ^ (1 << bit);

  return numero;
}
