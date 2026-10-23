#include <stdio.h>
#include <stdlib.h>

#define RENGLONES 3
#define COLUMNAS 3

void limpiar_buffer(void);
void capturar_matriz(int *matriz, int renglones, int columnas);
void imprimir_matriz(int *matriz, int renglones, int columnas);
void multiplicacion(int *matriz1, int *matriz2, int *matriz3, int renglones, int columnas);
void matriz_ceros(int *matriz, int renglones, int columnas);

int main(void)
{
    system("clear");

    int opcion;
    int A[RENGLONES][COLUMNAS] = {0};
    int B[RENGLONES][COLUMNAS] = {0};
    int C[RENGLONES][COLUMNAS] = {0};

    do
    {
        printf("\n");
        printf("========    PRACTICA 6_2    ========\n");
        printf(" [1] Capturar matriz A y B.\n [2] Imprimir matriz A y B.\n [3] Multiplicar matriz A y B.\n [4] Limpiar matriz A y B.\n [5] Terminar programa.\n-> ");
        scanf("%d", &opcion);
        limpiar_buffer();

        switch ( opcion )
        {
            case 1:
                printf("\nCaptura de Matriz A:\n");
                capturar_matriz((int *)A, RENGLONES, COLUMNAS);
                printf("\nCaptura de Matriz B:\n");
                capturar_matriz((int *)B, RENGLONES, COLUMNAS);
                printf("\nPresione Enter para continuar...");
                getchar();
                break;
            case 2:
                printf("\nMatriz A: \n");
                imprimir_matriz((int *)A, RENGLONES, COLUMNAS);
                printf("\nMatriz B:\n");
                imprimir_matriz((int *)B, RENGLONES, COLUMNAS);
                printf("\nPresione Enter para continuar...");
                getchar();
                break;
            case 3:
                multiplicacion((int *)A, (int *)B, (int *)C, RENGLONES, COLUMNAS);
                printf("\nMatriz C (Resultado A * B)\n");
                imprimir_matriz((int *)C, RENGLONES, COLUMNAS);
                printf("\nPresione Enter para continuar...");
                getchar();
                break;
            case 4:
                matriz_ceros((int *)A, RENGLONES, COLUMNAS);
                matriz_ceros((int *)B, RENGLONES, COLUMNAS);
                matriz_ceros((int *)C, RENGLONES, COLUMNAS);
                printf("\nLas matrices A, B y C han sido reiniciadas a ceros.\n");
                printf("\nPresione Enter para continuar...");
                getchar();
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Seleccione una opcion valida.\n");
        }
    } while ( opcion != 5 );

    return 0;
}

void limpiar_buffer(void)
{
    int c;
    while ( (c = getchar()) != '\n' && c != EOF );
}

void capturar_matriz(int *matriz, int renglones, int columnas)
{
    for ( int i = 0; i < renglones; i++ )
    {
        for ( int j = 0; j < columnas; j++ )
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", matriz + i * columnas + j);
            limpiar_buffer();
        }
    }
}

void imprimir_matriz(int *matriz, int renglones, int columnas)
{
    printf("Contenido de la matriz (%dx%d):\n", renglones, columnas);
    for ( int i = 0; i < renglones; i++ )
    {
        for (int j = 0; j < columnas; j++ )
        {
            printf("%d\t", *(matriz + i * columnas + j));
        }
        printf("\n");
    }
}

void multiplicacion(int *matriz1, int *matriz2, int *matriz3, int renglones, int columnas)
{
    for ( int i = 0; i < renglones; i++ )
    {
        for ( int j = 0; j < columnas; j++ )
        {
            *(matriz3 + i * columnas + j) = 0;
            for ( int k = 0; k < columnas; k++ )
            {
                *(matriz3 + i * columnas + j) += (*(matriz1 + i * columnas + k)) * (*(matriz2 + k * columnas + j));
            }
        }
    }
}

void matriz_ceros(int *matriz, int renglones, int columnas)
{
    for ( int i = 0; i < renglones; i++ )
    {
        for ( int j = 0; j < columnas; j++ )
        {
            *(matriz + i * columnas + j) = 0;
        }
    }
}
