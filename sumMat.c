#include <stdio.h>

#define N 3
typedef int matriz[N][N];

int main(void)
{
    printf("Algoritmo sumMat\n");
    printf("Vamos a introducir los valores en la matriz\n");
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("Introduce el valor de la matriz[%d][%d]: %d ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    } 
}