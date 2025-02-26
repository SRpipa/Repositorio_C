#include <stdio.h>

/* Funcion main recibe las rutas de dos ficheros binarios de enteros ordenados y crea un tercer fichero
con los elementos comunes a ambos */

int main(void)
{
    FILE *f1, *f2, *f3;
    int n1, n2;
    char nombre1[100], nombre2[100];

    printf("Introduce el nombre del primer fichero: \n");
    scanf("%s", nombre1);
    while((f1 = fopen(nombre1, "rb")) == NULL)
    {
        printf("Nombre incorrecto. Introduce el nombre de un fichero valido: \n");
        scanf("s", nombre1);
    }

    printf("Introduce el nombre del segundo fichero: \n");
    scanf("%s", nombre2);
    while((f2 = fopen(nombre2, "rb")) == NULL)
    {
        printf("Nombre incorrecto. Introduce el nombre de un fichero valido: \n");
        scanf("s", nombre2);
    }

    f3 = fopen("priycap.int", "wb");

    if (f1 == NULL || f2 == NULL || f3 == NULL)
    {
        printf("Error al abrir los ficheros\n");
        return 1;
    }

    fread(&n1, sizeof(int), 1, f1);
    fread(&n2, sizeof(int), 1, f2);

    while (!feof(f1) && !feof(f2))
    {
        if (n1 == n2)
        {
            fwrite(&n1, sizeof(int), 1, f3);
            fread(&n1, sizeof(int), 1, f1);
            fread(&n2, sizeof(int), 1, f2);
        }
        else if (n1 < n2)
        {
            fread(&n1, sizeof(int), 1, f1);
        }
        else
        {
            fread(&n2, sizeof(int), 1, f2);
        }
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);

    return 0;
}