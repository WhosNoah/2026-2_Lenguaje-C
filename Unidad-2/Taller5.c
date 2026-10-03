/*
 *  Resolver el siguiente programa usando apuntadores sobre arreglos, asignando direcciones y desreferenciar para realizar las operaciones sobre los datos del arreglo
 *  (utilizando aritmetica de apuntadores).
 *  Implementar un programa con la siguiente funcionalidad en un menu de opciones:
 *
 *  1. Capturar Frase: el usuario captura una cadena de texto sore un arreglo de caracteres (arreglo 1) de hasta maximo 1024 caracteres (incluyendo el caracter vacio).
 *  2. Mostrar frase: se muestra en pantalla la cadena de caracteres almacenada en el arreglo 1.
 *  3. Reemplazar palabra: el usuario captura una palabra sobre un arreglo de caracteres (arreglo 2) de hasta máximo 1024 caracteres (incluyendo el carácter vacío).
 *     a. El programa busca la palabra sobre el arreglo 1, si la encuentra, el programa solicita nuevamente una cadena de texto que reemplazará la actual
 *        (se reemplaza la palabra por otra palabra).
 *     b. Distingue entre mayúsculas y minúsculas.
 *     c. Busca palabras completas, las palabras están separadas por espacios, por una coma o por un punto.
 *     d. Se reemplaza la primera palabra encontrada.
 *  4. Terminar el programa.
 *
 * Se puede utilizar la libreria string.h solamente las funciones strlen y strncpy.
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX 1024

// Funcion extra del profesor.
int buscar(char *texto, char *palabra);

// Esto me ayuda al momento de querer escanear la frase, ya que varias veces van que al momento de realizar salto de linea
// No me deja capturar la frase.
void limpiar_buffer(void);

// Funciones a implementar.
void capturar_frase(char *ptrFrase);
void mostrar_frase(char *ptrFrase);
void reemplazar_palabra(char *ptrFrase, char *palabra_buscar, char *palabra_nueva);

// Extra function, only in some cases.
void quitar_salto(char *ptrFrase);

int main(void)
{
    int opcion;

    char frase[MAX] = "";
    char palabra_buscar[100];
    char palabra_nueva[100];
    char *ptrFrase;

    ptrFrase = &frase[0];

    do
    {
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

        switch ( opcion )
        {
            case 1:
                capturar_frase(ptrFrase);
                break;
            case 2:
                mostrar_frase(ptrFrase);
                break;
            case 3:
                reemplazar_palabra(ptrFrase, palabra_buscar, palabra_nueva);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Seleccione una opcion valida.\n");

        }
    } while ( opcion != 4 );

    printf("PROGRAMA FINALIZADO!\n");

    return 0;
}

void limpiar_buffer(void)
{
    char c;
    while ( (c = getchar()) != '\n' && c != EOF );
}

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

void capturar_frase(char *ptrFrase)
{
    printf("Capture su frase: ");
    fgets(ptrFrase, MAX, stdin);
}

void mostrar_frase(char *ptrFrase)

{
    for ( int i = 0; *(ptrFrase + i) != '\0'; i++ )
    {
        printf("%c", *(ptrFrase + i));
    }
}

int buscar(char *texto, char *palabra)
{
    int i, j, iguales;
    for ( i = 0; *(texto + i) != '\0'; i++ )
    {
        j = 0;
        if ( *(texto + i) == *(palabra + j) && (i == 0 || (*(texto + i - 1) == ' ' || *(texto + i - 1) == ',' || *(texto + i - 1) == '.')) )
        {
            iguales = 1;
            for ( j = 0; *(palabra + j) != '\0'; j++ )
            {
                if ( *(texto + i + j) != *(palabra + j) )
                {
                    iguales = 0;
                    break;
                }
            }
            if ( !(*(texto + i + j) == ' ' || *(texto + i + j) == ',' || *(texto + i + j) == '.' || *(texto + i + j) == '\0') )
                iguales = 0;
            if ( iguales == 1 )
                return i;
        }
    }
    return -1;
}

void reemplazar_palabra(char *ptrFrase, char *palabra_buscar, char *palabra_nueva)
{
    printf("Ingrese la palabra que desea buscar: ");
    fgets(palabra_buscar, 100, stdin);
    quitar_salto(palabra_buscar);

    printf("Ingrese la nueva palabra: ");
    fgets(palabra_nueva, 100, stdin);
    quitar_salto(palabra_nueva);

    int pos = buscar(ptrFrase, palabra_buscar);

    if ( pos == -1 )
    {
        printf("Palabra no encontrada.\n");
        return;
    }

    int len_frase = (int)strlen(ptrFrase);
    int len_buscar = (int)strlen(palabra_buscar);
    int len_nueva = (int)strlen(palabra_nueva);
    int diferencia = len_nueva - len_buscar;

    if ( diferencia > 0 )
    {
        for ( int i = len_frase; i >= pos + len_buscar; i-- )
        {
            *(ptrFrase + i + diferencia) = *(ptrFrase + i);
        }
    } 
    else if ( diferencia < 0 ) 
    {
        for ( int i = pos + len_buscar; i <= len_frase; i++ )
        {
            *(ptrFrase + i + diferencia) = *(ptrFrase + i);
        }
    }

    for ( int k = 0; k < len_nueva; k++ )
    {
        *(ptrFrase + pos + k) = *(palabra_nueva + k);
    }
}