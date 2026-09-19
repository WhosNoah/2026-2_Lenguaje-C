#include <stdio.h>
#define LONGITUD 1000

char mayus(char carac);
char minus(char carac);
void minusculas(char *cad);
void mayusculas(char *cad);
void limpiarBuffer(void);
void removerSalto(char *cad);
int comparar(char *cadA, char *cadB); 

int main(void) {
	char cadA[LONGITUD], cadB[LONGITUD], cadC[LONGITUD], cadD[LONGITUD]; 
	

	// Conversion de mayusculas y minusculas.
	printf("Capture una cadena de texto: ");
	fgets(cadA, LONGITUD, stdin);

	for ( int i = 0; i < LONGITUD; i++ ) {
		cadB[i] = cadA[i];
	       if ( cadA[i] == '\0' ) break;	
	}

	minusculas(cadA);
	printf("Cadena en minusculas: %s\n", cadA);

	mayusculas(cadB);
	printf("Cadena en mayusculas: %s\n\n", cadB);

	// Comparacion de cadenas
	printf("Capture la cadena 1: ");
	fgets(cadA, LONGITUD, stdin);
	removerSalto(cadA);

	printf("Capture la cadena 2: ");
	fgets(cadB, LONGITUD, stdin);
	removerSalto(cadB);

	printf("Capture la cadena 3: ");
	fgets(cadC, LONGITUD, stdin);
	removerSalto(cadC);

	printf("Capture la cadena 4: ");
	fgets(cadD, LONGITUD, stdin);
	removerSalto(cadD);

	// Cad A y Cad B son iguales alfabeticamente
	int res1 = comparar(cadA, cadB);
	if ( res1 == 0 )  {
		printf("\ncadA (%s) y cadB (%s) son iguales alfabeticamente", cadA, cadB);
	} else if ( res1 == -1 ) { 
		printf("\n cadA es menor que cadB\n");
	} else {
		printf("\n cadA es mayor que cadB");
	}

	// Cad C es menor que cad B
	int res2 = comparar(cadC, cadB);
	if ( res2 == -1 ) {
		printf("\ncadC (%s) es menor que cadB (%s)\n", cadC, cadB);
	} else if ( res2 == 0 ){
		printf("cadC y cadB no son iguales alfabeticamente.\n");
	} else {
		printf("cadC es mayor que cadB.\n");
	}

	// Cad D es mayor que Cad C
	int res3 = comparar(cadD, cadC);
    if (res3 == 1) { 
		printf("\ncadD (%s) es mayor que cadC (%s)\n", cadD, cadC);
	} else if (res3 == 0) { 
		printf("cadD y cadC son iguales alfabeticamente\n");
	} else {
		printf("cadD es menor que cadC\n");
	}

	return 0;
}

char mayus(char carac) {
	if ( carac >= 'a' && carac <= 'z' ) {
		return carac - 32;
	}
	return carac;
}

char minus(char carac) {
	if ( carac >= 'A' && carac <= 'Z' ) {
		return carac + 32;
	}
	return carac;
}

void minusculas(char *cad) {
	for ( int i = 0; cad[i] != '\0'; i++ ) {
		cad[i] = minus(cad[i]);
	}
}

void mayusculas (char *cad) {
	for ( int i = 0; cad[i] != '\0'; i++ ) {
		cad[i] = mayus(cad[i]);
	}
}

void limpiarBuffer(void) {
	char c;
	while ( (c=getchar() ) != '\n' && c != EOF );
}

int comparar(char *cadA, char *cadB) {
	for ( int i = 0; cadA[i] != '\0' || cadB[i] != '\0'; i++ ) {
		char a = minus(cadA[i]);
		char b = minus(cadB[i]);

		if ( a < b ) {
			return -1;
		} else if ( a > b ) {
			return 1;
		}
	}
	return 0;
}

void removerSalto(char *cad) {
	for (int i = 0; cad[i] != '\0'; i++) {
		if (cad[i] == '\n') {
			cad[i] = '\0';
			break;
		}
	}
}
