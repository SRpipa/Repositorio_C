//ALGORITMO VECTORES
//ADRIAN GOMEZ REY
//12/02/2025

#include <stdio.h>
#define N 10
typedef float Vector[N];

float prodEscalar(Vector v1, Vector v2)
{
    int i;
    float prod = 0;
    for(i = 0; i < N; i++)
    {
        prod += v1[i] * v2[i];
    }
    return prod;
}

int posMaxPre(Vector v, int m)
{
    float max = v[0];
    int pos = 0;
    for(int i = 1; i < m; i++)
    {
        if(max <= v[i])
        {
            max = v[i];
            pos = i;
        }
    }
    return pos;
}

void intercambio(float *a, float *b)
{
    float aux = *a;
    *a = *b;
    *b = aux;
}

void ordenaVector(Vector v)
{
    for(int i = N-1; i > 0; i--)
    {
        intercambio(&v[i], &v[posMaxPre(v, i+1)]);
    }
}

int main(void)
{
    float productoEscv1_v1, productoEscv1_v2, diferencia, valorAbs;
    Vector v1, v2;

    printf("Algoritmo Vectores \n");
    printf("Por favor, introduzca los %d valores para el vector.\n", N);
    for(int i = 0; i < N; i++)
    {
        printf("Introduzca el valor numero %d : ", i+1);
        scanf("%f", &v1[i]);
        v2[i] = v1[i];
    }

    productoEscv1_v1 = prodEscalar(v1, v1);
    ordenaVector(v1);
    productoEscv1_v2 = prodEscalar(v1, v2);
    diferencia = productoEscv1_v1 - productoEscv1_v2;
    valorAbs = (diferencia >= 0) ? diferencia : -diferencia;
    printf("producto escalar 1 es %1.f \n", productoEscv1_v1);
    printf("producto escalar 2 es %1.f \n", productoEscv1_v2);
    printf("La diferencia es %1.f \n", diferencia);
    return 0;
}