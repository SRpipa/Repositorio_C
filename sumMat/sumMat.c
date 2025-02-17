#include <stdio.h>

#define N 3
typedef int matriz[N][N];

//accion sumaMat que suma dos matrices y guarda el resultado en una tercera matriz

void sumMat(matriz m, matriz n, matriz l)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            l[i][j] = m[i][j] + n[i][j];
        }
    }
}

//accion intercambio que intercambia los valores de dos enteros

void intercambio (int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

//accion traspuesta que calcula la traspuesta de una matriz y la sobreescribe en la misma matriz

void traspuesta(matriz m)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            intercambio(&m[i][j], &m[j][i]);
        }
    }
}

//accion mostrarMatriz que muestra por pantalla los valores de una matriz

void mostrarMatriz(matriz m)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
}
int main(void)
{
    matriz m, n, l;
    printf("Algoritmo sumMat\n");
    printf("Vamos a introducir los valores en la matriz m\n");
    
    //crea matriz l con valores 0 para usarla como valor de entrada salida en la accion sumMat

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            l[i][j] = 0;
        }
    }
    
    //pide al usuario los valores de las matrices m y n

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("Introduce el valor de la matriz m[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
    printf("Vamos a introducir los valores en la matriz n \n");
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("Introduce el valor de la matriz n [%d][%d]: ", i, j);
            scanf("%d", &n[i][j]);
        }
    }
    
    //calcula la suma de matrices m y n y la guarda en l

    sumMat(m, n, l);
    printf("La matriz resultante de la suma de m y n es: \n");
    mostrarMatriz(l);

    //calcula la traspuesta de la matriz m y n y despues la suma entre ellas

    traspuesta(m);
    traspuesta(n);
    sumMat(m, n, l);
    printf("La matriz resultante de la suma de las traspuestas es: \n");
    mostrarMatriz(l);
}