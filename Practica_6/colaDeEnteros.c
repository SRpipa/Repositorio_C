//Modulo: colaDeEnteros.c
//Auror: Adrian Gomez
// Fecha: 17 - 05 - 2025
// Descripcion: Este modulo contiene la implenetacon de las funciones para la colaDeEnteros.h

#include "colaDeEnteros.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // para conocer exit y malloc

//accion: errorColaDeEnteros
void errorColaDeEnteros(char s[])
{
    printf("\n\n\nERROR en el modulo colas: %s \n", s);
    while (1)
        exit(-1);
}

//funcion: esNula
bool esNula(colaDeEnteros c)
{
    return (c.i == NULL);
}

//accion: nuevaCola
void nuevaCola(colaDeEnteros *c)
{
    c -> i = NULL;
    c -> f = NULL;
}

//accion: pideTurno
void pideTurno(colaDeEnteros *c, int e)
{
    celda *q;
    //verifico si hay memoria disponible
    if ((q = malloc(sizeof(celda))) == NULL)
    {
        errorColaDeEnteros("no hay memoria para pideTurno");
    }
    q -> e = e;
    q -> s = NULL;
    if (c -> f == NULL)
    {
        c -> i = q;
    }
    else
    {
        c -> f -> s = q;
    }
    c -> f = q;
}

//accion: avance
void avance(colaDeEnteros *c)
{
    celda *q;

    //verifico si la cola es nula
    if (esNula(*c))
    {
        errorColaDeEnteros("intentando avanzar en cola nula");
    }
    q = c -> i;
    c -> i = c -> i -> s;
    if (c -> i == NULL)
    {
        c -> f = NULL;
    }
    free(q);
}

//accion: primero
void primero(colaDeEnteros c, int *e)
{
    //verifico si la cola es nula
    if (esNula(c))
    {
        errorColaDeEnteros("intentando acceder al primero de cola nula");
    }
    *e = c.i -> e;
}


