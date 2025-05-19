//Modulo: cabinas.h
//Autor: Adrian Gomez
//fecha: 17 - 05 - 2025
//Descripcion: Este modulo contiene los tipos y los headers de las funciones de cabinas.c

#ifndef AGR_CABINAS_H
#define AGR_CABINAS_H

#include "colaDeEnteros.h"
#include "reloj.h"

typedef struct cabina
{
    int nCoches;  //numero de coches esperando en la cabina
    int maxCoches; //maximo de coches esperando
    int servidos; //coches servidos
    int totalEsperado; //tiempo total de esperas
    int proxServ; //instante proximo servicio
    int minServ; //tiempo minimo del servicio
    int maxServ; //tiempo maximo del servicio
    colaDeEnteros colaCoches; //cola de coches
} cabina;

/** 
*ACCION: iniciarCab
*ENTRADA: cabina cab, entero tmin, entero tmax
*REQUISITOS:
*SALIDA: cabina cab inicializada
*/
void iniciarCab(cabina *, int, int);

/** 
*ACCION: encolarCoche
*ENTRADA: cabina cab, Reloj r
*REQUISITOS:
*SALIDA: cabina cab con un coche en el instante r
*/
void encolarCoche(cabina *, Reloj);

/** 
*FUNCION: cuantosCoches
*ENTRADA: cabina cab
*REQUISITOS:
*SALIDA: entero n con el numero de coches esperando en la cabina
*/
int cuantosCoches(cabina);

/** 
*ACCION: servCabina
*ENTRADA: cabina cab, Reloj r
*REQUISITOS:
*SALIDA: cabina cab; se simula un servicion en el instante r
*/
void servCabina(cabina *, Reloj);


#endif