//Modulo: controles.h
//Autor: Adrian Gomez
//Fecha: 18 - 05 -2025
//Descripcion: contienes los headers y los tipos del modulo controles.c

#ifndef AGR_CONTROLES_H
#define AGR_CONTROLES_H

#include"peajes.h"
#include<stdio.h>

typedef struct frecuencia
{
    int tLlegada;
    int tMedio;
}frecuencia;

typedef struct control
{
    peaje peaje;
    frecuencia trafico;
}control;

/**
*ACCION: iniciarControl
*ENTRADA: control c
*REQUISITOS:
*SALIDA: control c; inicia el control
*/
void iniciarControl(control *);

/**
*ACCION: llegaCoche
*ENTRADA: control c, Reloj r
*REQUISITOS:
*SALIDA: conrol c; simula la llegada de un coche al control
*/
void llegaCoche(control *, Reloj);

/**
*ACCION: marchaCoche
*ENTRADA: control c, Reloj r
*REQUISITOS:
*SALIDA: conrol c; simula la marcha de un coche del control
*/
void marchaCoche(control *, Reloj);

#endif