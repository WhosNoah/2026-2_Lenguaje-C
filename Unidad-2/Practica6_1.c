#include <stdio.h>
#include <string.h>

#define RENGLONES 10
#define COLUMNAS  1024

void limpiarBuffer(void);
void quitar_salto(char *ptrFrase);
char minus(char c);
int compararCadenasIC(char *cadA, char *cadB);
void ordenarListaAscendente(char *lista, int renglones, int columnas);
void mostrarLista(char *lista, int renglones, int columnas);
void agregarPalabra(char *lista, int renglones, int columnas);
void eliminarPalabra(char *lista, int renglones, int columnas);

int main(void)
{
    char lista[RENGLONES][COLUMNAS];
    int opcion;

    for ( int i = 0; i < RENGLONES; i++ )
    {
        lista[i][0] = '\0';
    }

    do
    {
        mostrarLista(&lista[0][0], RENGLONES, COLUMNAS);

        printf("========    PRACTICA 6_1    ========\n");
        printf(" [1] Agregar palabra.\n");
        printf(" [2] Eliminar palabra.\n");
        printf(" [3] Terminar programa.\n");
        printf("-> ");

        if ( scanf("%d", &opcion) != 1 )
        {
            opcion = 0;
        }
        limpiarBuffer();

        switch ( opcion )
        {
            case 1:
                agregarPalabra(&lista[0][0], RENGLONES, COLUMNAS);
                break;
            case 2:
                eliminarPalabra(&lista[0][0], RENGLONES, COLUMNAS);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Seleccione una opcion valida.\n");
        }
        printf("\n");
    } while ( opcion != 3 );

    return 0;
}

void limpiarBuffer(void)
{
    int c;
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

char minus(char c)
{
    if ( c >= 'A' && c <= 'Z' )
    {
        return c + ('a' - 'A');
    }
    return c;
}

int compararCadenasIC(char *cadA, char *cadB)
{
    for ( int i = 0; cadA[i] != '\0' || cadB[i] != '\0'; i++ )
    {
        char a = minus(cadA[i]);
        char b = minus(cadB[i]);

        if ( a < b )
        {
            return -1;
        }
        else if ( a > b )
        {
            return 1;
        }
    }
    return 0;
}

void ordenarListaAscendente(char *lista, int renglones, int columnas)
{
    char temp[columnas];

    for ( int i = 0; i < renglones - 1; i++ )
    {
        for ( int j = 0; j < renglones - 1 - i; j++ )
        {
            char *actual    = lista + j * columnas;
            char *siguiente = lista + (j + 1) * columnas;
            int intercambiar = 0;

            if ( actual[0] == '\0' && siguiente[0] != '\0' )
            {
                intercambiar = 1; // Los vacios se van hacia abajo.
            }
            else if ( actual[0] != '\0' && siguiente[0] != '\0'
                && compararCadenasIC(actual, siguiente) > 0 )
            {
                intercambiar = 1;
            }

            if ( intercambiar )
            {
                strcpy(temp, actual);
                strcpy(actual, siguiente);
                strcpy(siguiente, temp);
            }
        }
    }
}

void mostrarLista(char *lista, int renglones, int columnas)
{
    printf("LISTA:\n");
    for ( int i = 0; i < renglones; i++ )
    {
        printf(" %d \"%s\"\n", i, lista + i * columnas);
    }
    printf("\n");
}

void agregarPalabra(char *lista, int renglones, int columnas)
{
    char palabra[columnas];
    int hueco = -1;

    // Busca el primer renglon vacio.
    for ( int i = 0; i < renglones; i++ )
    {
        if ( lista[i * columnas] == '\0' )
        {
            hueco = i;
            break;
        }
    }

    if ( hueco == -1 )
    {
        printf("La lista esta llena, elimine una palabra primero.\n");
        return;
    }

    printf("Palabra a agregar: ");
    if ( fgets(palabra, columnas, stdin) == NULL )
    {
        return;
    }

    if ( strchr(palabra, '\n') == NULL )
    {
        limpiarBuffer();
    }
    quitar_salto(palabra);

    if ( palabra[0] == '\0' )
    {
        printf("No se puede agregar una palabra vacia.\n");
        return;
    }

    strcpy(lista + hueco * columnas, palabra);
    ordenarListaAscendente(lista, renglones, columnas);
    printf("Palabra agregada.\n");
}

void eliminarPalabra(char *lista, int renglones, int columnas)
{
    int indice;

    printf("Indice de la palabra a eliminar: ");
    if ( scanf("%d", &indice) != 1 )
    {
        limpiarBuffer();
        printf("Indice invalido.\n");
        return;
    }
    limpiarBuffer();

    if ( indice < 0 || indice >= renglones || lista[indice * columnas] == '\0' )
    {
        printf("Indice invalido.\n");
        return;
    }

    for ( int i = indice; i < renglones - 1; i++ )
    {
        strcpy(lista + i * columnas, lista + (i + 1) * columnas);
    }
    lista[(renglones - 1) * columnas] = '\0';

    ordenarListaAscendente(lista, renglones, columnas);
    printf("Palabra eliminada.\n");
}
