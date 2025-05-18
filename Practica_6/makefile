all: simPeaje

simPeaje: simPeaje.c controles.o
	gcc -g simPeaje.c controles.o ruleta.o reloj.o peajes.o cabinas.o colaDeEnteros.o -lm -o simPeaje

controles.o: controles.c peajes.o ruleta.o
	gcc -Wall -c controles.c

peajes.o: peajes.c cabinas.o ruleta.o
	gcc -Wall -c peajes.c

cabinas.o: cabinas.c ruleta.o reloj.o colaDeEnteros.o
	gcc -Wall -c cabinas.c

colaDeEnteros.o: colaDeEnteros.c
	gcc -Wall -c colaDeEnteros.c
	
ruleta.o: ruleta.c
	gcc -Wall -c ruleta.c

reloj.o: reloj.c
	gcc -Wall -c reloj.c

clean:
	rm *.o