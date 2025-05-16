//cuenta.c contiene el main del programa cuenta utilizando los modulos de la practica 4


#include <stdio.h>
#include "palabras.h"


// cuenta, funcion main; cuenta el numero de veces que se repite la primera palabra del fichero
int main(void)
{
    FILE *f;
    int cuenta = 0;
    palabra p1, p2;
    char nombre[100];
    printf("Introduzca el nombre del fichero a tratar: \n");
    scanf("%s", nombre);
    while ((f = fopen(nombre, "r")) == NULL)
    {
        printf("Nombre incorrecto. Introduzca el nombre de un fichero valido: \n");
        scanf("%s", nombre);
    }
    printf("El fichero %s se ha abierto correctamente. \n",nombre);
    iniciarPrimeraPalabra (f, &p1);
        while (!feof (f))
        {
            leerPalabra (f, &p2);
            if (sonPalabrasIguales (p1, p2))
            {
                cuenta++;
            }
        }
    printf ("El numero de palabras iguales a la primera es de: %d \n", cuenta);
    fclose (f);
    return 0;
}