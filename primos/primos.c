#include <stdio.h>
#include <stdbool.h>

// Funcion es_primo que recibe un entero n y devuelve true si es primo y false si no lo es
bool es_primo(int n)
{
    int k;
    bool b;

    if (n == 1)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }
    if (n == 3)
    {
        return true;
    }
    if (n > 3)
    {
        if (n % 2 == 0)
        {
            return false;
        }
        if (n % 2 != 0)
        {
            k = 3;
            while(n > k * k && n % k != 0)
            {
                k = k + 2;
            }
            b = n % k == 0;
        }
    }
    return b;
}
