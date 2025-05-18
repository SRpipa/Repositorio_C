//Programa: simPeaje
//Autor: Adrian Gomez
//fecha: 19 - 05 -2025
//Descripcion: simula iteraciones en el peaje de la autopista y muesta algunos datos

#include <stdio.h>
#include "controles.h"
#define TSMI 10800

//headers de algunas funciones auxiliares
void iniciarSimulacion(control *c);
void siguienteIteracion(control *c, Reloj r);
void mostrarResultados(control c); //PREGUNTAR A LUCAS EN QUE MODULO VA ESTO !!!

int main(void)
{
    Reloj r;
    control c;
    aCero(&r);
    iniciarSimulacion(&c);
    while(instante(r) != TSMI)
    {
        tic(&r);
        siguienteIteracion(&c, r);
    }
    mostrarResultados(c);
    return 0;
}

//implementacion de las acciones auxiliares
void iniciarSimulacion(control *c)
{
    iniciarRuleta();
    iniciarControl(c);
}

void siguienteIteracion(control *c, Reloj r)
{
    llegaCoche(c, r);
    marchaCoche(c, r);
}

void mostrarResultados(control c)
{
    mostrarPeaje(c.peaje);
}