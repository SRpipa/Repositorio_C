#include <stdio.h>
#include <stdbool.h>

#define N 100000
#define M 1008002

//Funcion reverso que devuelve el numero n al reves
int reverso(int n)
{
    int m = 0;
    while (n > 0)
    {
        m = m * 10 + n % 10;
        n = n / 10;
    }
    return m;
}

//Funcion esCapicua que devuelve true si el numero n es capicua, false en el caso contrario

bool esCapicua (int n)
{
    bool b;
    b = n == reverso(n);
}

//Programa principal, crea el fichero binario capicuas.int con todos los numeros capicua menores que Mç

int main(void)
{
    FILE *f;
    f = fopen("capicuas.int", "wb");
    if (f == NULL)
    {
        printf("Error al abrir el fichero\n");
        return 1;
    }
    for (int i = 0; i < M; i++)
    {
        if (esCapicua(i))
        {
            fwrite(&i, sizeof(int), 1, f);
        }
    }
    fclose(f);
    return 0;
}