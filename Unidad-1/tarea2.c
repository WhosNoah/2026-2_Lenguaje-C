/* Declarar dos variables de tipo flotante y una constante del mismo tipo para poder calcular el área de un círculo. 
	El nombre de las variables y constante deben de estar relacionado con lo que representa en el programa. El usuario debe capturar el valor del radio, 
	para después realizar la operación del cálculo del área y almacenar el resultado en una variable. Finalmente se muestra en pantalla el área calculada.
																			areacirculo= π*r2
*/

#include <stdio.h>
int main(void)
{
	const float PI = 3.1416; // Constantes siempre en mayusculas
	
	float radio;
	float areaCirculo;
	
	printf("\nCaptura el radio del circulo: ");
	scanf("%f", &radio);
	
	areaCirculo = PI*(radio*radio);
	printf("\nEl valor del area es: %.2f", areaCirculo);
	
	printf("\nFIN DEL PROGRAMA\n");
	
	return 0;
	
}