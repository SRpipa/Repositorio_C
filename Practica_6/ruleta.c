//Modulo: ruleta.c
//Autor: Adrian Gomez
//Fecha: 17 - 05 - 2025
//Descripcion: Este modulo contiene la imprementacion de las funciones de ruleta.h

#include "ruleta.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stddef.h>

//accion: iniciarRuleta
void iniciarRuleta()
{
    srand(time(NULL));
}

//Fucion: distribucionLineal
int distribucionExponencial(int media)
{
    float x ,r;
    int t;
    r = RAND_MAX;
    x =(float)rand() / r;
    t = (int)( - log(1 - x) * media);
    
    while (t == 0)
    {
        x =(float)rand() / r;
        t = (int)( - log(1 - x) * media);
    }
    return t;
}

//Funcion: distribucionLineal
int distribucionLineal(int min, int max)
{
    int t;
    float x ,r;
    r = RAND_MAX;
    x = rand() / r;
    t = (int)((max - min) * x) + min;
    return t;
}

//Funcion: eleccionCon3Probabilidades
int eleccionCon3Probabilidades(float maxp, float medp, float minp)
{
    float x;
    int n;
    float elec[3], z;

    elec[0] = maxp;
    elec[1] = medp + maxp;
    elec[2] = 1;
    z = RAND_MAX;
    x = rand() / z;
    n = 0;
    while ((elec[n] < x) && (n < 2))
    {
        n++;
    }
    return n;
}