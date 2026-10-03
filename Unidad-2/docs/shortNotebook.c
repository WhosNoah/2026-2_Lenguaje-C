// NO COMPILAR ESTO, solo es un pequeño cuaderno de notas.

/*
    Vamos primero con lo que quisiera empezar con esto, hacer esto fue un tremendo dolor de cabeza intentando ver
    como podria funcionar la funcion "reemplazar_palabra", aunque no parezca tan dificil como se ve en el archivo
    "Taller5.c", el hacer que funcione fue un dolor de cabeza, ya que tuve que modificar cierta parte de la funcion "buscar"
    que nos proporciono el maestro Betancourt.

    A continuacion las partes que se cambiaron.
 */

// Esta funcion aunque no lo parezca, me dio un pequeño dolor de cabeza ya que pensaba que mis problemas estaban en el codigo
// que yo creaba.

int buscar(char *texto,char *palabra)
{
	int i,j,iguales;
    // Se cambia la "parte de texto[i]" por algo de aritmetica de apuntadores.
    // De aqui en adelante mayoria de cambios que se ven como arreglos pasan a ser aritmetica de apuntadores.
	for( i = 0; texto[i]!='\0' ; i++)
	{
		j = 0;
		if( texto[i] == palabra[j] && (i==0 || (texto[i-1]==' ' || texto[i-1]==',' || texto[i-1]=='.')))
		{
			iguales = 1;
			for(j = 0 ; palabra[j]!='\0' ; j++)
			{
				//printf("\n %c == %c",texto[i+j],palabra[j]);
				if( texto[i+j] != palabra[j])
				{
					iguales = 0;
					break;
				}
			}
			if( !(texto[i+j]==' ' || texto[i+j]==',' || texto[i+j]=='.' || texto[i+j]=='\0') )				
				iguales = 0;
			if(iguales == 1)			
				return i;
		}
	}
	return -1;
}

/*
    La funcion "limpiar_buffer" como dice en el archivo "Taller5.c" ayuda demasiado al momento
    de despues de escanear la opcion, limpia el salto de linea que genera el scanf y hace que 
    al momento de pasar al fgets no skipee la opcion de "Capturar frase".
*/

printf("*-------------------------*\n");
printf("|  Seleccione una opcion  |\n");
printf("*-------------------------*\n");
printf("|                         |\n");
printf("| 1. Capturar frase.      |\n");
printf("| 2. Mostrar frase.       |\n");
printf("| 3. Reemplazar palabra.  |\n");
printf("| 4. Terminar programa.   |\n");
printf("|                         |\n");
printf("*-------------------------*\n");
printf("-> ");
scanf("%d", &opcion);
limpiar_buffer();

/*
    Sin la funcion de limpiar_buffer, el output se veria asi:

    *-------------------------*
    |  Seleccione una opcion  |
    *-------------------------*
    |                         |
    | 1. Capturar frase.      |
    | 2. Mostrar frase.       |
    | 3. Reemplazar palabra.  |
    | 4. Terminar programa.   |
    |                         |
    *-------------------------*
    -> 1
    Capture su frase: *-------------------------*
    |  Seleccione una opcion  |
    *-------------------------*
    |                         |
    | 1. Capturar frase.      |
    | 2. Mostrar frase.       |
    | 3. Reemplazar palabra.  |
    | 4. Terminar programa.   |
    |                         |
    *-------------------------*

    Mientras que con la funcion limpiar_buffer el output se ve asi:
    
    *-------------------------*
    |  Seleccione una opcion  |
    *-------------------------*
    |                         |
    | 1. Capturar frase.      |
    | 2. Mostrar frase.       |
    | 3. Reemplazar palabra.  |
    | 4. Terminar programa.   |
    |                         |
    *-------------------------*
    -> 1
    Capture su frase: *frase epica*
*/

/*
    Una que otra vez suelo agregar funciones, como es el caso de 
    "quitar_salto", esta funcion es parecida a la que se nos da en varios
    ejercicios por el maestro Betancourt, las unicas diferencias es que la de el
    funciona con arreglos y la mia funciona con apuntadores, aunque en teoria, hagan lo mismo.
*/

// Funcion original.
void removerEnter(char *cad)
{
    int i = 0;
    while(cad[i]!='\0')
    {
        if(cad[i]=='\n')
        {
            cad[i] = '\0'
            break;
        }
        i++;
    }
}

// Misma funcion, pero con apuntadores.
void quitar_salto(char *ptrFrase)
{
    char *p = ptrFrase;

    while ( *p != '\0' )
    {
        if ( *p == '\n' )
        {
            *p = '\0';
            break;
        }
        p++;
    }
}

// Aunque en teoria funcionen igual, a mi me ayuda a no confundir variables.

// Creo que estas serian casi todas mis quejas, si encuentro otra, seguramente la terminare
// agregando al README.md o aqui.