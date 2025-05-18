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