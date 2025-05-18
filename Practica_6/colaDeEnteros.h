//Modulo: colaDeEnteros.h
//Autor: Adrian Gomez
//Fecha: 17 - 05 - 2025
//Descripcion: Este modulo contiene los headers de las funciones de colaDeEnteros.c

#ifndef AGR_COLADEENTEROS_H
#define AGR_COLEDEENTEROS_H

#include <stdbool.h>
//Definicion de la estructura celda para la cola dinamica
typedef struct celda
{
    int e;
    struct celda *s;
} celda;

//Definicion de la colaDeEnteros dinamica
typedef struct colaDeEnteros
{
    celda *i;
    celda *f;
} colaDeEnteros;

/**
*ACCION: nuevaCola
*ENTRADA: colaDeEnteros
*REQUISITOS:
*SALIDA: colaDeEnteros inicializada
*/
void nuevaCola(colaDeEnteros *);

/**
*ACCION: pideTurno
*ENTRADA: c colaDeEnteros, e entero
*REQUISITOS:
*MODIFICA: almacena e como ultimo elemento de c
*/
void pideTurno(colaDeEnteros *, int);

/**
*ACCION: avance
*ENTRADA: c colaDeEnteros
*REQUISITOS: La cola no esta vacia
*MODIFICA: elimina el elemento mas antiguo de la cola
*/
void avance(colaDeEnteros *);

/**
*ACCION: primero
*ENTRADA: c colaDeEnteros
*REQUISITOS: La cola no esta vacia
*SALIDA: e entero con el primer elemento de la cola copiado
*/
void primero(colaDeEnteros, int *);

/**
*FUNCION: esNula
*ENTRADA: c colaDeEnteros
*REQUISITOS: 
*SALIDA: b booleano que sera verdadero si la cola no tiene elementos
*/
bool esNula(colaDeEnteros);

#endif