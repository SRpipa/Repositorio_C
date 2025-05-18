//Modulo: ruleta.h
//Autor: Adrian Gomez
//Fecha: 17 - 05 - 2025
//Descripcion: Este modulo.h contiene los headers de la funciones del modulo ruleta.c

#ifndef AGR_RULETA_H
#define AGR_RULETA_H

/** 
*ACCION: iniciarRuleta
*ENTRADA: 
*REQUISITOS:
*MODIFICA: inicia la ruleta
*/
void iniciarRuleta();

/** 
*FUNCION: distribucionExponencial
*ENTRADA: media, entero
*REQUISITOS:
*SALIDA: t entero
*/
int distribucionExponencial(int);

/** 
*FUNCION: distribucionLineal
*ENTRADA: min entero, max entero
*REQUISITOS:
*SALIDA: t entero
*/
int distribucionLineal(int, int);

/** 
*FUNCION: eleccionCon3Probabilidades
*ENTRADA: maxp real, medp rea, minp real
*REQUISITOS:
*SALIDA: n entero
*/
int eleccionCon3Probabilidades(float, float, float);

#endif