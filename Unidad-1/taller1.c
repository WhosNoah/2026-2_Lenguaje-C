#include <stdio.h>

int capturarInicial(char* mensaje, char *inicial);
int capturarEdad(char* mensaje2, int *edad);
int capturarPeso(char* mensaje3, float *peso);
int capturarPrecio(char* mensaje4, double *precio);

int main(void)
{
	char a;
	int b;
	float c;
	double d;
	
	capturarInicial("\n CAPTURA TU INICIAL: ", &a);
	capturarEdad("\n CAPTURA TU EDAD: ", &b);
	capturarPeso("\n CAPTURA TU PESO: ", &c);
	capturarPrecio("\n CAPTURA UN PRECIO: ", &d);
	
	int divisionInicialEdad;
	divisionInicialEdad = (int)a/b;
	int moduloInicialEdad;
	moduloInicialEdad = a%b;
	float divisionEdadPeso;
	divisionEdadPeso = (float)b/c;
	double multiplicacionPesoPrecio;
	multiplicacionPesoPrecio = (double)c*d;
	
	printf("\nLa division inicial/edad es: %d", divisionInicialEdad);
	printf("\nEl modulo inicial/edad es: %d", moduloInicialEdad);
	printf("\nLa division entre Edad/Peso es: %f", divisionEdadPeso);
	printf("\nLa multiplicacion Peso/Precio es: %lf", multiplicacionPesoPrecio);
	printf("\nPROGRAMA FINALIZADO :)\n");
	
	return 0;
}

int capturarInicial(char* mensaje, char *inicial) 
{
	printf("\n %s", mensaje);
	return scanf("%c", inicial);
}

int capturarEdad(char* mensaje2, int *edad) 
{
	printf("\n %s", mensaje2);
	return scanf("%d", edad);
}

int capturarPeso(char* mensaje3, float *peso) 
{
	printf("\n %s", mensaje3);
	return scanf("%f", peso);
}

int capturarPrecio(char* mensaje4, double *precio) 
{
	printf("\n %s", mensaje4);
	return scanf("%lf", precio);
}
