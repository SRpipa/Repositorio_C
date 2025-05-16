//modulo palabras.c
//Autor: Adrian Gomez
//Fecha: 15 - 05 - 2025
//Descripcion: Este modulo implementa las acciones y funciones del tipo palabra:
#include "palabras.h"

//accion: prepararPalabra
void prepararPalabra (palabra *p)
{
    p -> longitud = 0;
    p -> letras[0] = '\0';
}

//accion: agrgarCaracter 
void agregarCaracter (char c, palabra *p)
{
    if (longitudPalabra(p) < MAX)
    {
        p -> letras[p -> longitud] = c;
        p -> longitud++;
    }
}

//accion: modificarCaracter
void modificarCaracter(palabra *p, int i, char c)
{
    p -> letras[i] = c;
}

//funcion: consultarCaracter
char consultarCaracter (palabra *p, int i)
{
    char c;
    c = p -> letras[i];
    return c;
}

//funcion: longitudPalabra
int longitudPalabra (palabra *p)
{
    int longitud;
    longitud = p -> longitud;
    return longitud;
}

//funcion: esPalabraVacia
bool esPalabraVacia (palabra *p)
{
    bool b;
    b = (longitudPalabra(p) == 0);
    return b;
}

//funcion: sonPalabrasIguales
bool sonPalabrasIguales (palabra p1, palabra p2)
{
    bool b;
    int i;
    if (p1.longitud == p2.longitud)
    {
        i = 0;
        while ((i < p1.longitud) && (p1.letras[i] == p2.letras[i]))
        {
            i++;
        }
        b = (p1.letras[i] == p2.letras[i]);
    }
        else
    {
        b = 0;
    }
    return b;
}

//accion: saltarBlancos
void saltarBlancos (FILE *f, char *c)
{
    *c = fgetc(f);
    while ((*c != EOF ) && (*c ==' '))
    {
        *c = fgetc(f);
    }
}

//accion: copiarLetras
void copiarLetras (FILE *f, palabra *p, char *c)
{
    p -> longitud = 0;
    while ((*c != EOF ) && (*c != ' '))
    {
        agregarCaracter(*c, p);
        *c = fgetc(f);
    }
    if (*c != ' ' && *c != EOF)
    {
        agregarCaracter(*c, p);
    }
}

//accion: leerPalabra
void leerPalabra (FILE *f, palabra *p)
{
    char c;
        saltarBlancos(f, &c);
        copiarLetras(f, p, &c);
        p -> letras[p -> longitud] = '\0';
}

//accion: iniciarPrimeraPalabra
void iniciarPrimeraPalabra (FILE *f, palabra *p)
{
    char c;
    saltarBlancos (f, &c);
    copiarLetras (f, p, &c);
}
