//Modulo reloj.c
//Autor: Adrian Gomez
//Fecha: 17 - 05 - 2025
//Descripcion: contiene la implementacion de las funciones del modulo reloj.h

#include "reloj.h"

//funcion aCero
void aCero(Reloj *r)
{
    r -> segundos = 0;
}

//funcion tic
void tic(Reloj *r)
{
    r -> segundos++;
}

//funcion instante
int instante(Reloj r)
{
    return r.segundos;
}