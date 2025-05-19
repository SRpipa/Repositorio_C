//Modulo: cabinas.c
//Autor: Adrian Gomez
//fecha: 17 - 05 - 2025
//Descripcion: Este modulo contiene la implementacion de las funciones de cabinas.h

#include <stdio.h>
#include"cabinas.h"
#include"ruleta.h"


//accion: iniciarCab
void iniciarCab(cabina *cab, int tmin, int tmax)
{
    cab -> nCoches = 0;
    cab -> maxCoches = 0;
    cab -> servidos = 0;
    cab -> totalEsperado = 0;
    cab -> proxServ = 0;
    cab -> minServ = tmin;
    cab -> maxServ = tmax;
    nuevaCola(&cab -> colaCoches);
}

//accion: contarCoche  solo en la implementacion; no es publica en la interfaz del modulo
void contarCoche(cabina *cab, Reloj r)
{
    if ( cab -> nCoches == 0)
    {
        cab -> proxServ = instante(r) + distribucionLineal(cab -> minServ, cab -> maxServ);
    }
    cab -> nCoches++;
    if (cab -> nCoches > cab -> maxCoches)
    {
        cab -> maxCoches = cab -> nCoches;
    }
}

//accion: encolarCoche
void encolarCoche(cabina *cab, Reloj r)
{
    contarCoche(cab, r);
    pideTurno(&cab -> colaCoches, instante(r));
}

//funcion: cuantosCoches
int cuantosCoches(cabina cab)
{
    int n;
    n = cab.nCoches;
    return n;
}

//accion servCabina
void servCabina(cabina *cab, Reloj r)
{
    int x;
    if (cab -> proxServ == instante(r))
    {
        cab -> servidos++;
        primero(cab -> colaCoches, &x);
        avance(&cab -> colaCoches);
        cab -> totalEsperado = cab -> totalEsperado + (instante(r) - x);
        cab -> nCoches = cab -> nCoches - 1;
        if (cab -> nCoches == 0)
        {
            cab -> proxServ = 0;
        }
        else
        {
            cab -> proxServ = instante(r) + distribucionLineal(cab -> minServ, cab -> maxServ);
        }
    }
}