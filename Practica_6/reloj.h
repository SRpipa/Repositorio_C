//modulo reloj.h
//Autor: Adrian Gomez
//Fecha: 17 - 05 - 2025
//Descripcion: Este modulo.h contiene los headers de la funciones del modulo reloj.c

#ifndef AGR_RELOJ_H
#define AGR_RELOJ_H

#include<stdio.h>

typedef struct Reloj
{
    int segundos;
} Reloj;

/** 
*ACCION: aCero
*ENTRADA:
*REQUISITOS:
*SALIDA: Reloj con la cuenta puesta a cero
*/
void aCero(Reloj *);

/** 
*ACCION: tic
*ENTRADA: Reloj
*REQUISITOS:
*MODIFICA: aumenta en uno la cuenta del Reloj 
*/
void tic(Reloj *);

/** 
*FUNCION: instante
*ENTRADA: Reloj
*REQUISITOS:
*SALIDA: i, entero con la cuenta en segundos del Reloj
*/
int instante(Reloj);

#endif