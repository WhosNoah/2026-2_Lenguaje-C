#include <stdio.h>
#include <stdlib.h>

void limpiarBuffer(void);
void capturarValores(float *arreglo, int longitud);
void mostrarValores(float *arreglo, int longitud);
float valorMaximo(float *arreglo, int longitud);
float valorMinimo(float *arreglo, int longitud);

int main(void) {
	int opcion;
	int longitud = 6;

	float array[6];

	do {
		printf("Seleccione una opcion: \n");
		printf("	1. Capturar arreglo.\n");
		printf("	2. Desplegar arreglo.\n");
		printf("	3. Maximo.\n");
		printf("	4. Minimo.\n");
		printf("	5. Terminar el programa.\n");
		scanf("%d", &opcion);

		switch(opcion) {
			case 1:
				capturarValores(array, longitud);
				break;
			case 2:
				mostrarValores(array,longitud);
				break;
			case 3:
				valorMaximo(array,longitud);
				break;
			case 4:
				valorMinimo(array,longitud);
				break;
			case 5:
				printf("Cerrando programa...\n");
				break;
			default:
				printf("Seleccione una opcion valida.\n");
				break;
		}

	} while (opcion != 5);

	return 0;
}

void limpiarBuffer(void)
{
	char c;
	while( ( c = getchar() ) != '\n' && c != EOF );
}
void capturarValores(float *arreglo, int longitud) {
	for ( int i = 0; i < longitud; i++ ) {
		printf("Capture el numero para la posicion %d: \n", i);
		scanf("%f", &arreglo[i]);
		limpiarBuffer();
	}
}

void mostrarValores(float *arreglo, int longitud) {
	for ( int i = 0; i < longitud; i++ ) {
		printf("%f \n", arreglo[i]);
	}
}

float valorMaximo(float *arreglo, int longitud) {
	float maximo;
	maximo = arreglo[1];
	for ( int i = 0; i<longitud; i++) {
		if (arreglo[i]>maximo) {
			maximo = arreglo[i];
		}
	}
	printf("El valor minimo es: %f\n", maximo);
}

float valorMinimo(float *arreglo, int longitud) {
	float minimo;
	minimo = arreglo[1];
	for ( int i = 0; i<longitud; i++) {
		if (arreglo[i]<minimo) {
			minimo = arreglo[i];
		}
	}
	printf("El valor minimo es: %f\n", minimo);
}