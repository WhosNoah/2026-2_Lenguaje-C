/*
	Declarar tres variables de tipo entero para poder calcular el área de un rectángulo. 
	El nombre de las variables deben de estar relacionado con lo que representa en el programa. El usuario debe capturar los valores de alto y largo del rectángulo, 
	para después realizar la operación del cálculo del área y almacenar el resultado en una variable. Finalmente se muestra en pantalla el área calculada.
	arearectangulo = alto x largo
*/

#include <stdio.h>
int main(void)
{
	int alto;
	int largo;
	int areaRectangulo;
	
	printf("\nCaptura el alto del rectangulo: " );
	scanf("%d", &alto);
	printf("\nCaptura el largo del rectangulo: ");
	scanf("%d", &largo);
	
	areaRectangulo = alto*largo;
	printf("\nEl area del rectangulo es %d", areaRectangulo);
	printf("\nFIN DEL PROGRAMA\n");
	
	return 0;
}