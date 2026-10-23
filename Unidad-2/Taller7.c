#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 5
#define MAX_CARAC_USER 100
#define MAX_CARAC_PASS 64

typedef struct
{
    char username[MAX_CARAC_USER];
    char password[MAX_CARAC_PASS];
} Users;

void limpiarTerminal(void);
void limpiarBuffer(void);
void quitarEnter(char *cad);
void inicializar(char *cad, int max, char c);
void fgetsPlus(char *cad, int max);
void registrarUsuario(Users *user);
void iniciarSesion(Users *user);
int buscarC(char *cad, char c);
int existeUsuario(Users *user, const char *nombre);

int main(void)
{
    limpiarTerminal();

    Users user[MAX_USERS];
    int op;

    for ( int i = 0; i < MAX_USERS; i++ )
    {
        user[i].username[0] = '\0';
        user[i].password[0] = '\0';
    }

    do
    {
        printf("========  TALLER 7  ========\n");
        printf(" [1] Iniciar Sesion.\n");
        printf(" [2] Registrar Usuario.\n");
        printf(" [3] Terminar programa.\n");
        printf("-> ");
        if ( scanf("%d", &op) != 1 )
            op = 0;
        limpiarBuffer();

        switch ( op )
        {
            case 1:
                iniciarSesion(user);
                break;
            case 2:
                registrarUsuario(user);
                break;
            case 3:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Seleccione una opcion valida.\n");
        }
    } while ( op != 3 );

    return 0;
}

void limpiarTerminal(void)
{
    #ifdef _WIN32
        system("cls");
    #elif defined(__linux__)
        system("clear");
    #elif defined(__APPLE__)
        system("clear");
    #endif
}

void limpiarBuffer(void)
{
    int c;
    while ( (c = getchar()) != '\n' && c != EOF );
}

void quitarEnter(char *cad)
{
    char *ptr = cad;
    while ( *ptr != '\0' )
    {
        if ( *ptr == '\n' )
        {
            *ptr = '\0';
            break;
        }
        ptr++;
    }
}

void inicializar(char *cad, int max, char c)
{
    for ( int i = 0; i < max; i++ )
        cad[i] = c;
}

void fgetsPlus(char *cad, int max)
{
    int e = max - 2;
    inicializar(cad, max, '\0');
    cad[e] = '\n';
    fgets(cad, max, stdin);
    if ( cad[e] != '\n' && buscarC(cad, '\n') == 0 )
        limpiarBuffer();
    else
        quitarEnter(cad);
}

void registrarUsuario(Users *user)
{
    int libre = -1;
    char nombre[MAX_CARAC_USER];
    char contrasena[MAX_CARAC_PASS];

    for ( int i = 0; i < MAX_USERS; i++ )
    {
        if ( user[i].username[0] == '\0' )
            libre = i;
    }

    if ( libre == -1 )
    {
        printf("No hay cupo para mas usuarios.\n");
        return;
    }

    do
    {
        printf("Nuevo usuario: ");
        fgetsPlus(nombre, MAX_CARAC_USER);

        if ( nombre[0] == '\0' )
            printf("El nombre no puede estar vacio.\n");
        else if ( existeUsuario(user, nombre) != -1 )
            printf("Este nombre de usuario ya esta ocupado, pruebe con otro.\n");
        else
            break;
    } while ( 1 );

    printf("Contrasena: ");
    fgetsPlus(contrasena, MAX_CARAC_PASS);
    if ( contrasena[0] == '\0' )
    {
        printf("La contraseña no puede estar vacia.\n");
        return;
    }
    strcpy(user[libre].username, nombre);
    strcpy(user[libre].password, contrasena);
    printf("Usuario registrado!\n");
}

void iniciarSesion(Users *user)
{
    char nombre[MAX_CARAC_USER];
    char contrasena[MAX_CARAC_PASS];

    printf("Usuario: ");
    fgetsPlus(nombre, MAX_CARAC_USER);
    printf("Contrasena: ");
    fgetsPlus(contrasena, MAX_CARAC_PASS);

    int i = existeUsuario(user, nombre);

    if ( i != -1 && strcmp(user[i].password, contrasena) == 0 )
        printf("Inicio exitoso!\n");
    else
        printf("Usuario no registrado o contrasena invalida.\n");
}

int buscarC(char *cad, char c)
{
    int i = 0;
    while ( cad[i] != '\0' )
    {
        if ( cad[i] == c )
            return 1;
        i++;
    }
    return 0;
}

int existeUsuario(Users *user, const char *nombre)
{
    for ( int i = 0; i < MAX_USERS; i++ )
    {
        if ( user[i].username[0] != '\0' && strcmp(user[i].username, nombre) == 0 )
            return i;
    }

    return -1;
}
