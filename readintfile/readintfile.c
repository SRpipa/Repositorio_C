#include <stdio.h>

//programa principal pide que introduzcas el nombre de un fichero int para leerlo y mostrarlo por pantalla
//si no existe el fichero mostrara error
//si el fichero esta vacio mostrara un mensaje
int main(void)
{
    FILE *f;
    char nombre[100];
    printf("Introduzca el nombre del fichero a tratar: \n");
    scanf("%s", nombre);
    while ((f = fopen(nombre, "rb")) == NULL)
    {
        printf("Nombre incorrecto. Introduzca el nombre de un fichero valido: \n");
        scanf("%s", nombre);
    }
    int n;
    while (fread(&n, sizeof(int), 1, f) == 1)
    {
        printf("%d\n", n);
    }
}