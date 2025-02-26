#include <stdio.h>
#include <stdbool.h>
#define M 1008002

// Funcion es_primo que recibe un entero n y devuelve true si es primo y false si no lo es
bool es_primo(int n)
{
    int k;
    bool b;

    if (n == 1)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    if (n > 3)
    {
        if (n % 2 == 0)
        {
            return false;
        }
        k = 3;
        while(n > k * k && n % k != 0)
        {
            k = k + 2;
        }
        b = n % k != 0;
    }
    return b;
}

//Funcion main que escribe un fichero binario de enteros con todos los primos menores que M

int main(void)
{
    FILE *f;
    f = fopen("primos.int", "wb");
    if (f == NULL)
    {
        printf("Error al abrir el fichero\n");
        return 1;
    }
    for(int i = 1; i < M; i++)
    {
        if (es_primo(i))
        {
            fwrite(&i, sizeof(int), 1, f);
        }
    }
    return 0;
}
