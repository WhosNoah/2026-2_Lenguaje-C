#include <stdio.h>

void imprimr_matriz(int *matriz, int renglones, int columnas);
void matriz_ceros(int *matriz, int renglones, int columnas);
void tablero(int *matriz, int renglones, int columnas);
void horizontal(int *matriz, int renglones, int columnas);
void vertical(int *matriz, int renglones, int columnas);
void limpiar_buffer(void);

int main(void)
{
    int renglones = 0, columnas = 0;
    int opcion;

    printf("Ingrese el numero de renglones: ");
    scanf("%d", &renglones);
    limpiar_buffer();
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);
    limpiar_buffer();

    if ( renglones <= 0 && columnas <= 0 )
    {
        printf("Las dimensiones deben ser mayores de 0.\n");
        return 1;
    }

    // Declaracion de matriz.
    int matriz[renglones][columnas];

    do
    {
        printf("========    MENU    ========\n");
        printf(" [1] Imprimir matriz.\n");
        printf(" [2] Matriz ceros.\n");
        printf(" [3] Matriz tablero.\n");
        printf(" [4] Matriz horitontal.\n");
        printf(" [5] Matriz vertical.\n");
        printf(" [6] Terminar programa.\n");
        printf("-> ");
        scanf("%d", &opcion);
        limpiar_buffer();

        switch ( opcion )
        {
            case 1:
                imprimr_matriz((int *)matriz, renglones, columnas);
                break;
            case 2:
                printf("Matriz reestablecia a 0's.\n");
                matriz_ceros((int *)matriz, renglones, columnas);
                break;
            case 3:
                printf("Diseño de tablero.\n");
                tablero((int *)matriz, renglones, columnas);
                break;
            case 4:
                printf("Diseño con lineas horizontales.\n");
                horizontal((int *)matriz, renglones, columnas);
                break;
            case 5:
                printf("Diseño con lineas verticales.\n");
                vertical((int *)matriz, renglones, columnas);
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
        }
    } while ( opcion != 6 );

    return 0;
}

void imprimr_matriz(int *matriz, int renglones, int columnas)
{
    printf("Contenido de la matriz (%dx%d):\n", renglones, columnas);
    for ( int i = 0; i < renglones; i++)
    {
        for ( int j = 0; j < renglones; j++)
        {
            printf("%d\t", *(matriz + i * columnas + j));
        }
        printf("\n");
    }
}

void matriz_ceros(int *matriz, int renglones, int columnas)
{
    for (int i = 0; i < renglones; i++) {
        for (int j = 0; j < columnas; j++) {
            *(matriz + i * columnas + j) = 0;
        }
    }
}


void tablero(int *matriz, int renglones, int columnas)
{
    for (int i = 0; i < renglones; i++) {
        for (int j = 0; j < columnas; j++) {
            *(matriz + i * columnas + j) = (i + j) % 2;
        }
    }
}

void horizontal(int *matriz, int renglones, int columnas) {
    for (int i = 0; i < renglones; i++) {
        for (int j = 0; j < columnas; j++) {
            *(matriz + i * columnas + j) = (i % 2 == 0) ? 1 : 0;
        }
    }
}

void vertical(int *matriz, int renglones, int columnas) {
    for (int i = 0; i < renglones; i++) {
        for (int j = 0; j < columnas; j++) {
            *(matriz + i * columnas + j) = (j % 2 == 0) ? 1 : 0;
        }
    }
}

void limpiar_buffer(void)
{
    char c;
    while ( (c = getchar()) != '\n' && c != EOF );
}
