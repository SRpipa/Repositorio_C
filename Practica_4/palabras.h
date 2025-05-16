//modulo palabras.h
//Autor: Adrian Gomez
//Fecha: 15 -05 - 2025
//Descripcion: Este modulo contiene los headers de las funciones del modulo palabras.c

#ifndef AGR_PALABRAS_H
#define AGR_PALABRAS_H
#include <stdio.h>
#include <stdbool.h>

//define del maximo de letras y typedef del struct palabra
#define MAX 100
typedef struct palabra
{
    char letras [MAX];
    int longitud;
}palabra;

/**
*ACCION: prepararPalabra
*ENTRADA:
*REQUISITOS:
*SALIDA: p, una palabra inicializada a 0 letras
*/
void prepararPalabra (palabra *p);

/** 
*ACCION: agregarCaracter
*ENTRADA: p, una palabra y c, un caracter
*REQUISITOS: 
*MODIFICA: p, incorpora c como ultimo caracter de p
*/
void agregarCaracter (char c, palabra *p);

/** 
*ACCION: modificarCaracter
*ENTRADA: p, una palabra, el entero i y c un caracter
*REQUISITOS:  i es menor o igual que la longitud de p
*MODIFICA:  Cambia por c el caracter i-esimo de p
*/
void modificarCaracter (palabra *p, int i, char c);

/** 
*FUNCION: consultarCaracter
*ENTRADA: p, una palabra y el entero i
*REQUISITOS: i es menor o igual que la longitud de p
*SALIDA: el caracter i-esimo de p
*/
char consultarCaracter (palabra *p, int i);

/** 
*FUNCION: longitudPalabra
*ENTRADA: p, una palabrea
*REQUISITOS: 
*SALIDA: long, la longitud de p
*/
int longitudPalabra (palabra *p);

/** 
*FUNCION: esPalabraVacia
*ENTRADA: p, una palabra
*REQUISITOS:
*SALIDA: el booleano b es verdadero si y solo si p no tiene letras
*/
bool esPalabraVacia (palabra *p);

/** 
*FUNCION: sonPalabrasIguales
*ENTRADA: p1 y p2, dos palabras
*REQUISITOS:
*SALIDA: el booleano b es verdadero si y solo si p1 y p2 son iguales
*/
bool sonPalabrasIguales (palabra p1, palabra p2);

/** 
*ACCION: leerPalabra
*ENTRADA: fichero de caracter
*REQUISITOS: El fichero no esta vacio y la secuencia de palabra no contiene fin de fichero
*MODIFICA: f avanzando el elemento distinguido hasta el principio
de la siguiente palabra 
*SALIDA:  p (entero) contiene la primera palabra de la secuencia
*/
void leerPalabra (FILE *f, palabra *p);

void iniciarPrimeraPalabra (FILE *f, palabra *p);

#endif