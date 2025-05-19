//Modulo: controles.c
//Autor: Adrian Gomez
//fecha: 18 - 05 - 2025
//Descripcion: contiene la implementacion de las funciones del modulo controles.h

#include<stdio.h>
#include"controles.h"
#include"cabinas.h"
#include"ruleta.h"

//accion: iniciarControl
void iniciarControl(control *c)
{
    printf("Introduzca el tiempo medio entre llegadas\n");
    scanf("%d", &(c->trafico.tMedio));
    c->trafico.tLlegada = distribucionExponencial(c->trafico.tMedio);
    iniciarPeaje(&(c->peaje));
}

//accion:llegaCoche
void llegaCoche(control *c, Reloj r)
{
    int n;
    if (instante(r) == c->trafico.tLlegada)
    {
        n = eligeCabina(c->peaje);
        guardaCola(c->peaje, n, r);
        c->trafico.tLlegada = instante(r) + distribucionExponencial(c->trafico.tMedio);
    }
}

//accion marchaCoche
void marchaCoche(control *c, Reloj r)
{
    rondaCabinas(&c->peaje, r);
}

//mostarCabina
void mostrarCabina(cabina cab, float *t)
{
    if (cab.servidos != 0)
    {
        printf("El tiempo medio esperado es: %f\n",cab.totalEsperado/(float)cab.servidos);
        printf("El maximo de coches fue: %d\n",cab.maxCoches);
        printf("Coches servidos: %d\n",cab.servidos);
        *t = *t + cab.totalEsperado;
    }
    else{
        printf("El tiempo medio esperado es: %f\n",0.00000);
        printf("El maximo de coches fue: %d\n",cab.maxCoches);
        printf("Coches servidos: %d\n",cab.servidos);
    }
}

//mostarResultados
void mostrarResultados(peaje p)
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