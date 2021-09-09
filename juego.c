#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "test_de_personalidad.h"
#include "osos_contra_reloj.h"
#include "utiles.h"

int main(){
	srand((unsigned) time(NULL));
	char personalidad_detectada = 'P';
	//test_de_personalidad(&personalidad_detectada);
	char jugada;
	juego_t juego;

	inicializar_juego(&juego, personalidad_detectada);
	mostrar_juego(juego);

	scanf(" %c", &jugada);
	//Se incicia el cronometro

	while( es_jugada_valida(jugada) && tiempo_actual() < 120 ){
		realizar_jugada(&juego, jugada);
		system("clear");		
		//iniciar_cronometro();
		mostrar_juego(juego);
		scanf(" %c", &jugada);
	}

	//detener_cronometro();


		
	
	
	return 0;
}