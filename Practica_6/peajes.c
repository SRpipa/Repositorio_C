//Modulo: peajes.c
//Autor: Adrian Gomez
//Fecha: 17 - 05 - 2025
//Descripcion: contiene la implementacion de tipos y de las funciones de peajes.h

#include"peajes.h"
#include <stdio.h>

typedef struct intervalo
{
    int min;
    int max;
} intervalo;

intervalo tipocobro[NCAB] = {{15,30}, {15,30}, {15,45}, {15,45}, {30,60}};

//accion: ordenar
void ordenar(taux t)
{
    int i,j;
    pareja aux;
    for (i = 0; i < NCAB - 1; i++ )
    {
        for (j = i + 1; j < NCAB; j++)
        {
            if(t[j].can < t[i].can)
            {
                aux = t[j];
                t[j] = t[i];
                t[i] = aux;
            }
        }
    }
}

//accion iniciarPeaje
void iniciarPeaje(peaje *p)
{
    int i;
    for (i = 0; i < NCAB; i++)
    {
        iniciarCab(&((*p)[i]), tipocobro[i].min, tipocobro[i].max);
    }
}

//accion guardaCola
void guardaCola(peaje p, int nCab, Reloj r)
{
    encolarCoche(&(p[nCab]), r);
}

//funcion eligeCabina
int eligeCabina(peaje p)
{
    int n, x, i;
    taux t;
    for(i = 0; i < NCAB; i++)
    {
        t[i].can = cuantosCoches(p[i]);
        t[i].cab = i;
    }
    ordenar(t);
    x = eleccionCon3Probabilidades(PROB_MAX, PROB_MEDIA, PROB_MIN);
    n = t[x].cab;
    return n;
}

//accion: rondaCabinas
void rondaCabinas(peaje *p, Reloj r)
{
    int i;
    for (i = 0; i < NCAB; i++)
    {
        servCabina(&((*p)[i]), r);
    }
}

//mostrarPeaje
void mostrarPeaje(peaje p)
{
    float t;
    int coches = 0, i;
    for (i = 0; i < NCAB; i++)
    {
        printf("Cabina %d : \n", i+1);
        mostrarCabina(p[i], &t);
        coches = coches + p[i].servidos;
    }
    printf("\n Total peaje; \n");
    if (coches == 0)
    {
        printf("El tiempo de espera medio %f \n", t/coches);
    }
    else
    {
        printf("El tiempo de espera medio en el peaje es %f \n", t/coches);
        printf("Se han servido %d coches. \n", coches);
    }
}
