//Modulo: peaje.h
//Autor: Adrian Gomez
//Fecha: 17 - 05 - 2025
//Descripcion: contiene los headers de las funciones de peajes.c

#ifndef AGR_PEAJES_H
#define AGR_PEAJES_H

#include"cabinas.h"
#include<stdio.h>
#include"ruleta.h"

#define NCAB  5
#define PROB_MAX  0.6
#define PROB_MEDIA  0.3
#define PROB_MIN  0.1 

typedef cabina peaje[NCAB];

typedef struct pareja
{
    int can;
    int cab;
}pareja;

typedef pareja taux[NCAB];

/** 
*ACCION: iniciarPeaje
*ENTRADA: peaje p
*REQUISITOS:
*SALIDA: peaje p inicializado
*/
void iniciarPeaje(peaje *);

/** 
*ACCION: guardaCola
*ENTRADA: peaje p, entero nCab, Reloj r
*REQUISITOS:
*SALIDA: peaje p con un nuevo coche encolado en cabina
*/
void guardaCola(peaje, int, Reloj);

/** 
*FUNCION: eligeCabina
*ENTRADA: peaje p
*REQUISITOS:
*SALIDA: entero n
*/
int eligeCabina(peaje);

/** 
*ACCION: rondaCabinas
*ENTRADA: peaje p, Reloj r
*REQUISITOS:
*SALIDA: peaje p con una ronda simulada
*/
void rondaCabinas(peaje *, Reloj);


#endif