#include<stdio.h>
#include<stdbool.h>

//Funcion es_primo4n1 recibe un entero primo y devuelve true si es de la forma 4n+1

bool es_primo4n1(int n)
{
    return n % 4 == 1;
}

//Funcion main que recibe un fichero binario de enteros primos y escribe otro solo que con los que son de la forma 4n+1

int main(void)
{
    FILE *f, *g;
    int n,i;
    char nombre[100];
    printf("Introduzca el nombre del fichero a tratar: \n");
    scanf("%s", nombre);
    while ((f = fopen(nombre, "rb")) == NULL)
    {
        printf("Nombre incorrecto. Introduzca el nombre de un fichero valido: \n");
        scanf("%s", nombre);
    }
    g = fopen("primos4n1.int", "wb");
    for(i = 0; fread(&n, sizeof(int), 1, f) == 1; i++)
    {
        if (es_primo4n1(n))
        {
            fwrite(&n, sizeof(int), 1, g);
        }
    }
    fclose(f);
    fclose(g);
    return 0;
}