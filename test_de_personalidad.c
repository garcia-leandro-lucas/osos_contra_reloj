#include <stdio.h>
#include <stdbool.h>

#include "test_de_personalidad.h"
#include "osos_contra_reloj.h"

const int VALOR_VACIO = 0;

const char POLAR = 'I';
const char PANDA = 'P';
const char PARDO = 'G';

const char ANIME = 'A';
const char MUSICA_POP = 'M';
const char LIMPIEZA = 'L';

const char BAMBU = 'B';
const char PESCADO = 'P';
const char FOCAS = 'F';

const int PISO_DE_TORRE_MINIMO = 1;
const int PISO_DE_TORRE_MAXIMO = 18;

const int FUERZA_DE_GRITO_MINIMO = 1;
const int FUERZA_DE_GRITO_MAXIMO = 18;

const int VALOR_DE_LIMPIEZA = 1;
const int VALOR_DE_ANIME = 2;
const int VALOR_DE_MUSICA_POP = 3;

const int VALOR_DE_FOCAS = 3;
const int VALOR_DE_BAMBU = 6;
const int VALOR_DE_PESCADO = 9;

const int VALOR_DE_DETERMINACION_MINIMO = 5;
const int VALOR_DE_DETERMINACION_BAJO = 25;
const int VALOR_DE_DETERMINACION_MEDIO = 44;
const int VALOR_DE_DETERMINACION_MAXIMO = 63;


/*
 *
 *	Pre: -
 *
 * 	Post: Mensaje de bienvenida y breve introdución del programa.
 *
*/
void imprimir_mensaje_de_bienvenida(){

	printf("║║▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ║║\n");
	printf("║║ ▓ ▓ ▓ ▓ ▓  UBAfiuba ▓ ▓ ▓ ▓ ▓ ▓║║\n");
	printf("║║▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ║║\n");
	printf("║╔════════════════════════════════╗║\n");
	printf("║║BIENVENIDOS * TP1 * ALGO1MENDEZ ║║\n");
	printf("║║  2021 * TEST DE PERSONALIDAD   ║║\n");
	printf("║║                                ║║\n");
	printf("║║      GARCÍA LEANDRO LUCAS      ║║\n");
	printf("║╚════════════════════════════════╝║\n");
	printf("\n");
	printf("║║▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓║║\n");
	printf("║║                                ║║\n");
	printf("║║ Los escandalosos son tres osos ║║\n");
	printf("║║ hermanos ( de corazón ): Pardo,║║\n");
	printf("║║ Panda y Polar,cada uno con sus ║║\n");
	printf("║║     propias personalidades,    ║║\n");
	printf("║║      intereses y talentos.     ║║\n");
	printf("║║                                ║║\n");
	printf("║║      ¿Descubrí cuál es tu      ║║\n");
	printf("║║    personalidad escandalosa?   ║║\n");
	printf("\n");
	printf("║║                ▓               ║║\n");
	printf("║║                ▓               ║║\n");
	printf("║║      ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓     ║║\n");
	printf("║║       ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓      ║║\n");
	printf("║║        ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓       ║║\n");
	printf("║║         ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓        ║║\n");
	printf("║║          ▓ ▓ ▓ ▓ ▓ ▓ ▓         ║║\n");
	printf("║║           ▓▓▓▓▓▓▓▓▓▓▓          ║║\n");
	printf("║║            ▓ ▓ ▓ ▓ ▓           ║║\n");
	printf("║║             ▓▓▓▓▓▓▓            ║║\n");
	printf("║║              ▓ ▓ ▓             ║║\n");
	printf("║║               ▓ ▓              ║║\n");
	printf("║║                ▓               ║║\n");
	printf("\n");
	printf("\n");

}

/*
 *
 *	Pre: los datos ingresados no deben de ser datos de tipo entero ni
 *       caracteres especiales. Solo caracteres en mayúscula.
 *
 * 	Post: Devuelve true: si recibe A, M y L. False: si no recibe lo indicado.
 *
*/
bool es_canal_de_television_valido( char canal_de_television ){

	return ((canal_de_television == ANIME) || (canal_de_television == MUSICA_POP) || (canal_de_television == LIMPIEZA));

}

/*
 *
 *	Pre: los datos ingresados no deben de ser datos de tipo entero ni
 *       caracteres especiales. Solo caracteres en mayúscula.
 *
 * 	Post: Devuelve por consola un mensaje pidiendo los datos nuevamente por ser invalidos.
 *
*/
void imprimir_canal_de_television( char *canal_de_television ){


	printf( "Vas a ver televisión un rato, ponés el canal de:\n■ Anime ( %c ), \n■ Música Pop ( %c ),\n■ Limpieza ( %c ).\n", ANIME, MUSICA_POP, LIMPIEZA );
	scanf( " %c", canal_de_television );

	while( !es_canal_de_television_valido(*canal_de_television ) ){

		printf( "El dato ingresado es invalido. Selecciona las iniciales según corresponda.\nVas a ver televisión un rato, ponés el canal de:\n■ Anime ( %c ), \n■ Música Pop ( %c ),\n■ Limpieza ( %c ).\n", ANIME, MUSICA_POP, LIMPIEZA );
		scanf(" %c", canal_de_television );

	}
}

/*
 *
 *	Pre: los datos ingresados no deben de ser datos de tipo entero ni
 *       caracteres especiales. Solo caracteres en mayúscula.
 *
 * 	Post: Devuelve true: si recibe B, P y F. False: si no recibe lo indicado.
 *
*/
bool es_alimento_de_vianda_valido( char alimento_de_vianda ){

	return ( (alimento_de_vianda == BAMBU) || (alimento_de_vianda == PESCADO) || (alimento_de_vianda == FOCAS) );

}

/*
 *
 *	Pre: los datos ingresados no deben de ser datos de tipo entero ni
 *       caracteres especiales. Solo caracteres en mayúscula.
 *
 * 	Post: Devuelve por consola un mensaje pidiendo los datos nuevamente por ser invalidos.
 *
*/
void imprimir_alimento_de_vianda( char *alimento_de_vianda ){

	printf( "Solo podes guardar un alimento en tu vianda:\n■ Bambú = ( %c ),\n■ Pescado = ( %c ),\n■ Focas = ( %c ).\n", BAMBU, PESCADO, FOCAS );
	scanf( " %c", alimento_de_vianda );

	while( !es_alimento_de_vianda_valido( *alimento_de_vianda ) ){

		printf( "El dato ingresado es invalido. Selecciona las iniciales según corresponda.\nSolo podes guardar un alimento en tu vianda:\n■ Bambú = ( %c ),\n■ Pescado = ( %c ),\n■ Focas = ( %c ).\n", BAMBU, PESCADO, FOCAS );
		scanf( " %c", alimento_de_vianda );

	}

}

/*
 *
 *	Pre: los datos ingresados no deben de ser del tipo char.
 *
 * 	Post: Devuelve true: si recibe un número de 1 al 18 ( ambos inclusives ). False: si no recibe lo indicado.
 *
*/
bool es_piso_en_la_torre_valido( int piso_en_la_torre ){

	return ( (piso_en_la_torre >= PISO_DE_TORRE_MINIMO) && (piso_en_la_torre <= PISO_DE_TORRE_MAXIMO) );

}

/*
 *
 *	Pre: los datos ingresados no deben de ser del tipo char.
 *
 * 	Post: Devuelve por consola un mensaje pidiendo los datos nuevamente por ser invalidos.
 *
*/
void imprimir_piso_en_la_torre( int *piso_en_la_torre ){

	printf( "Te compras una torre con tus dos hermanos de 18 pisos. ¿En qué piso te gustaría vivir?\nElegir un piso del %i al %i.\n", PISO_DE_TORRE_MINIMO, PISO_DE_TORRE_MAXIMO );
	scanf( "%i", piso_en_la_torre );

	while( !es_piso_en_la_torre_valido( *piso_en_la_torre ) ){

		printf( "El dato ingresdo es invalido. Selecciona el intervalo correspondiente.\nTe compras una torre con tus dos hermanos de 18 pisos. ¿En qué piso te gustaría vivir?\nElegir un piso del %i al %i.\n", PISO_DE_TORRE_MINIMO, PISO_DE_TORRE_MAXIMO );
		scanf( "%i", piso_en_la_torre );

	}

}

/*
 *
 *	Pre: los datos ingresados no deben de ser del tipo char.
 *
 * 	Post: Devuelve true: si recibe un número de 1 al 18 ( ambos inclusives ). False: si no recibe lo indicado.
 *
*/
bool es_fuerza_de_grito_valido( int fuerza_de_grito ){

	return ( (fuerza_de_grito >= FUERZA_DE_GRITO_MINIMO) && (fuerza_de_grito <= FUERZA_DE_GRITO_MAXIMO) );

}

/*
 *
 *	Pre: los datos ingresados no deben de ser del tipo char.
 *
 * 	Post: Devuelve por consola un mensaje pidiendo los datos nuevamente por ser invalidos.
 *
*/
void imprimir_fuerza_de_grito( int *fuerza_de_grito ){

	printf( "¡Oh, una rata! ¿Qué tan fuerte gritas del %i al %i? Siendo %i no gritar y %i desgarrarse la garganta.\n", FUERZA_DE_GRITO_MINIMO, FUERZA_DE_GRITO_MAXIMO, FUERZA_DE_GRITO_MINIMO, FUERZA_DE_GRITO_MAXIMO );
	scanf( "%i", fuerza_de_grito );

	while( !es_fuerza_de_grito_valido( *fuerza_de_grito ) ){

	printf( "¡Oh, el dato ingresado es invalido! ¿Qué tan fuerte gritas del %i al %i? Siendo %i no gritar y %i desgarrarse la garganta.\n", FUERZA_DE_GRITO_MINIMO, FUERZA_DE_GRITO_MAXIMO, FUERZA_DE_GRITO_MINIMO, FUERZA_DE_GRITO_MAXIMO );
	scanf( "%i", fuerza_de_grito );

	}
}

/*
 *
 *	Pre: los datos ingresados no deben de ser datos de tipo entero ni
 *       caracteres especiales. Solo caracteres en mayúscula.
 *
 * 	Post: Devuelve la asociación de un valor numérico ( constantes )
          correspondiente a cada canal de televisión
 		  (constantes ).
 *
*/
int multiplicador_por_canal_de_television( char canal_de_television ){

	int valor_segun_canal = VALOR_VACIO;

	if ( canal_de_television == LIMPIEZA){

		valor_segun_canal = VALOR_DE_LIMPIEZA;

	}else if (canal_de_television == ANIME ){

		valor_segun_canal = VALOR_DE_ANIME;

	}else if ( canal_de_television == MUSICA_POP){

		valor_segun_canal = VALOR_DE_MUSICA_POP;

	}

	return valor_segun_canal;

}

/*
 *
 *	Pre: los datos ingresados no deben de ser datos de tipo entero ni
 *       caracteres especiales. Solo caracteres en mayúscula.
 *
 * 	Post: Devuelve la asociación de un valor numérico ( constantes )
          correspondiente a cada alimento de vianda ( constantes ).
 *
*/
int puntaje_por_alimento( char alimento_de_vianda ){

	int valor_segun_alimento = VALOR_VACIO;

	if ( alimento_de_vianda == FOCAS){

		valor_segun_alimento = VALOR_DE_FOCAS;

	}else if (alimento_de_vianda == BAMBU ){

		valor_segun_alimento = VALOR_DE_BAMBU;

	}else if ( alimento_de_vianda == PESCADO){

		valor_segun_alimento = VALOR_DE_PESCADO;

	}

	return valor_segun_alimento;

}

/*
 *
 *	Pre: recibe los valores del tipo de datos que estan en los
 *       parámetros de la firma de la función puntaje_total.
 *
 * 	Post: Devuelve un número entero de la cuenta correspondiente de
 *        puntaje_total.
 *
 *
*/
int puntaje_total( char alimento_de_vianda, char canal_de_television, int puntaje_por_piso_en_la_torre, int puntaje_por_grito  ){

	int puntaje_total = VALOR_VACIO;
	int valor_punjate_por_alimento = puntaje_por_alimento( alimento_de_vianda );
	int valor_multiplicador_por_canal_de_television = multiplicador_por_canal_de_television( canal_de_television );

	puntaje_total = ((valor_punjate_por_alimento *  valor_multiplicador_por_canal_de_television) + ( puntaje_por_piso_en_la_torre  + puntaje_por_grito ));

	return puntaje_total;


}

/*
 *
 *  Pre: recibe los valores del tipo de datos que estan en los
 *       parametros de la firma de la función imprimir_resultado_esperado.
 *
 * 	Post: Devuelve la impresión del resultado esperado según el valor del
          puntaje total.
 *
*/
void imprimir_resultado_esperado( char alimento_de_vianda, char canal_de_television, int piso_en_la_torre, int fuerza_de_grito ){

	if ( (puntaje_total( alimento_de_vianda, canal_de_television, piso_en_la_torre, fuerza_de_grito )) >= VALOR_DE_DETERMINACION_MINIMO && (puntaje_total( alimento_de_vianda, canal_de_television, piso_en_la_torre, fuerza_de_grito )) < VALOR_DE_DETERMINACION_BAJO){
		
		printf("%c\n", POLAR );

	}else if( (puntaje_total( alimento_de_vianda, canal_de_television, piso_en_la_torre, fuerza_de_grito ) >= VALOR_DE_DETERMINACION_BAJO) && (puntaje_total( alimento_de_vianda, canal_de_television, piso_en_la_torre, fuerza_de_grito ) < VALOR_DE_DETERMINACION_MEDIO )){

		printf("%c\n", PANDA);

	}else if( ( puntaje_total( alimento_de_vianda, canal_de_television, piso_en_la_torre, fuerza_de_grito ) >= VALOR_DE_DETERMINACION_MEDIO ) && ( puntaje_total( alimento_de_vianda, canal_de_television, piso_en_la_torre, fuerza_de_grito ) <= VALOR_DE_DETERMINACION_MAXIMO )){

		printf("%c\n", PARDO );

	}

}


void test_de_personalidad(char* personalidad_detectada){
	char alimento_de_vianda = ' ';
	char canal_de_television = ' ';
	int piso_en_la_torre = ' ';
	int fuerza_de_grito = ' ';

	imprimir_mensaje_de_bienvenida();
	imprimir_canal_de_television( &canal_de_television );
	imprimir_alimento_de_vianda( &alimento_de_vianda );
	imprimir_piso_en_la_torre( &piso_en_la_torre );
	imprimir_fuerza_de_grito( &fuerza_de_grito );

	imprimir_resultado_esperado( alimento_de_vianda, canal_de_television, piso_en_la_torre, fuerza_de_grito );
}


























































//