#include <stdio.h>
#include <stdbool.h>

#define N 100000

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

int main(void)
{
    int n;
    printf("Por favor, introduzca un numero entero positivo menor que  %d\n", N);
    scanf("%d", &n);

    //comprueba si el numero introducido es valido

    if (n < N && n > 0)
    {
        //comprueba si es capicua con la funcion esCapicua

        if (esCapicua(n))
        {
            printf("El numero %d es capicua\n", n);
        }
        else
        {
            printf("El numero %d no es capicua\n", n);
        }
    }
    else
    {
        printf("El numero introducido no es valido\n");
    }
}

