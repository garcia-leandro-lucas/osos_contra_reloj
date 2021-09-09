#include <stdlib.h>
#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "test_de_personalidad.h"
#include "osos_contra_reloj.h"
#include "utiles.h"

const int MAXIMO_ALEATORIO_FILA = 20;
const int MAXIMO_ALEATORIO_COL = 30;

const int MAXIMO_DE_DISTANCIA_MANHATTAN = 3;
const int MAXIMO_DE_POSICIONES_VELA = 8;

static const char POLAR = 'I';
static const char PANDA = 'P';
static const char PARDO = 'G';

const char OSCURIDAD = '#';
const char VACIO = ' ';

#define ARRIBA 'W'
#define DERECHA 'D'
#define ABAJO 'S'
#define IZQUIERDA 'A'

const char ARBOL     = 'A';
const char PIEDRA    = 'R';
const char KOALAS    = 'K';

#define LINTERNA 'L'
#define VELA     'V'
#define BENGALA  'E'

const char PILA      = 'B';

const char CHLOE     = 'C';

const char TIEMPO_RESTANTE = 'T';

/*
 * Devolvera true en caso de ser una jugada valida (W,A,S,D,L,V,E o T)
 * Devolvera false en caso contrario.
 */
/**/bool es_jugada_valida(char jugada){
    
    return( jugada == ARRIBA || jugada == DERECHA || jugada == ABAJO || jugada ==IZQUIERDA || jugada == LINTERNA || jugada == VELA || jugada == BENGALA || jugada == TIEMPO_RESTANTE ); 

}

/*
 *
 *
 *
 *
*/
void informacion_del_juego(juego_t juego){

    printf("---------------------------------------------------------------------------------------------\n");
    printf("--------------------------------------  HERRAMIENTAS  ---------------------------------------\n");
    printf("                          %c : Linterna | %c : Vela | %c : Bengala\n", LINTERNA, VELA, BENGALA );
    printf("\n");
    printf("--------------------------------------  MOVIMIENTOS  ----------------------------------------\n");
    printf("               %c : Arriba | %c : Derecha | %c : Abajo | %c : Izquierda\n", ARRIBA, DERECHA, ABAJO, IZQUIERDA  );

    printf("\n");

    //printf("\n", juego.personaje.cantidad_elementos );
}

/*
 *
 *
 *
 *
*/
void imprimir_terreno(char terreno[ALTO_TERRENO][ANCHO_TERRENO]){
    
    juego_t juego;

    printf("\n");
    printf("   00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29\n");

    for (int i = 0; i < ALTO_TERRENO; i++){
        printf("%02d ", i);
        for (int j = 0; j < ANCHO_TERRENO; j++){
             printf(" %c ", terreno[i][j] );

        }
        printf("\n");

    }
        printf("\n");

        informacion_del_juego(juego);
}

void mostrar_zonas_vacias_del_terreno( juego_t* juego, char terreno[ALTO_TERRENO][ANCHO_TERRENO] ){

    switch ( (*juego).personaje.mochila[(*juego).personaje.elemento_en_uso].tipo ){
    
        case LINTERNA:
    
            switch ( (*juego).personaje.ultimo_movimiento ){
           
                case ARRIBA:
               
                    for (int i = (*juego).personaje.posicion.fil - 1; i >= 0; i--){
                        if ( terreno[i][(*juego).personaje.posicion.col] == OSCURIDAD ){
                                
                            terreno[i][(*juego).personaje.posicion.col] = VACIO;

                        }
                    }

                break;

                case DERECHA:
               
                    for (int i = ((*juego).personaje.posicion.col + 1); i < ANCHO_TERRENO; i++){
                        if ( terreno[(*juego).personaje.posicion.fil][i] == OSCURIDAD ){
                            
                            terreno[(*juego).personaje.posicion.fil][i] = VACIO;
                        }
                    }

                break;

                case ABAJO:
               
                    for (int i = ( (*juego).personaje.posicion.fil + 1 ); i < ALTO_TERRENO; i++){
                        if ( terreno[i][(*juego).personaje.posicion.col] == OSCURIDAD ){
                                
                            terreno[i][(*juego).personaje.posicion.col] = VACIO;

                        }
                    }

                break;

                case IZQUIERDA:
               
                    for (int i = (*juego).personaje.posicion.col - 1 ; i >= 0; i--){
                        if ( terreno[(*juego).personaje.posicion.fil][i] == OSCURIDAD ){
                                
                            terreno[(*juego).personaje.posicion.fil][i] = VACIO;

                        }
                    }

            break;

            }

        break;

        case VELA:{

            coordenada_t areas_a_iluminar[MAXIMO_DE_POSICIONES_VELA];


            areas_a_iluminar[0].fil = (*juego).personaje.posicion.fil - 1;
            areas_a_iluminar[0].col = (*juego).personaje.posicion.col - 1;
            areas_a_iluminar[1].fil = (*juego).personaje.posicion.fil - 1;
            areas_a_iluminar[1].col = (*juego).personaje.posicion.col;
            areas_a_iluminar[2].fil = (*juego).personaje.posicion.fil - 1;
            areas_a_iluminar[2].col = (*juego).personaje.posicion.col + 1;
            areas_a_iluminar[3].fil = (*juego).personaje.posicion.fil;
            areas_a_iluminar[3].col = (*juego).personaje.posicion.col - 1;
            areas_a_iluminar[4].fil = (*juego).personaje.posicion.fil;
            areas_a_iluminar[4].col = (*juego).personaje.posicion.col + 1;
            areas_a_iluminar[5].fil = (*juego).personaje.posicion.fil + 1;
            areas_a_iluminar[5].col = (*juego).personaje.posicion.col - 1;
            areas_a_iluminar[6].fil = (*juego).personaje.posicion.fil + 1;
            areas_a_iluminar[6].col = (*juego).personaje.posicion.col;
            areas_a_iluminar[7].fil = (*juego).personaje.posicion.fil + 1;
            areas_a_iluminar[7].col = (*juego).personaje.posicion.col + 1;

            for( int i = 0 ; i < 8 ;i++ ){   
                         
                if( (terreno[areas_a_iluminar[i].fil][areas_a_iluminar[i].col] == OSCURIDAD) && ( areas_a_iluminar[i].col >= 0 &&  areas_a_iluminar[i].col < ANCHO_TERRENO ) && ( areas_a_iluminar[i].fil >= 0 &&  areas_a_iluminar[i].fil < ALTO_TERRENO ) ){

                    terreno[areas_a_iluminar[i].fil][areas_a_iluminar[i].col] = VACIO;
                }          
                           
            }

        break;
        }
    
        case BENGALA:



        break;
    
    }

}

/*
 *
 *
 *
 *
*/
/**/void mostrar_juego(juego_t juego){

    char terreno[ALTO_TERRENO][ANCHO_TERRENO];

    for (int i = 0; i < ALTO_TERRENO; i++){
        for (int j = 0; j < ANCHO_TERRENO; j++){
            
            terreno[i][j] = OSCURIDAD;

        }
    }
    

    if( juego.chloe_visible ){
        terreno[juego.amiga_chloe.fil][juego.amiga_chloe.col] = CHLOE;
    }
    //printf("cantidad_obstaculos: %i\n",juego.cantidad_obstaculos );
    for (int i = 0; i < juego.cantidad_obstaculos; i++){
        if( juego.obstaculos[i].visible ){
            //printf("M [%i] obstaculo:[%i, %i] \n",i,juego.obstaculos[i].posicion.fil,juego.obstaculos[i].posicion.col);
            terreno[juego.obstaculos[i].posicion.fil][juego.obstaculos[i].posicion.col] = juego.obstaculos[i].tipo;
        }
    
    }
    //terreno[juego.personaje.posicion.fil][juego.personaje.posicion.col] = juego.personaje.tipo;
    for (int i = 0; i < juego.cantidad_herramientas; i++){
        if ( juego.herramientas[i].visible ){
            terreno[juego.herramientas[i].posicion.fil][juego.herramientas[i].posicion.col] = juego.herramientas[i].tipo;
        }
    }

    terreno[juego.personaje.posicion.fil][juego.personaje.posicion.col] = juego.personaje.tipo;
    //printf("POSICIÓN DEL PERSONAJE [%i][%i]", juego.personaje.posicion.fil, juego.personaje.posicion.col);
    
    mostrar_zonas_vacias_del_terreno( &juego, terreno );
    imprimir_terreno(terreno);

}





/*
 *
 *
 *
 *
*/
coordenada_t posicion_inicial_del_personaje(){
    
    coordenada_t coordenada;

    int posicion_inicial_del_personaje = rand() % 20;

    coordenada.fil = posicion_inicial_del_personaje;
    coordenada.col = 0;

    return coordenada;

}

/*
 *
 *
 *
 *
*/
void inicializar_personaje(juego_t* juego, char tipo_personaje){

    (*juego).personaje.tipo = tipo_personaje;
    (*juego).personaje.posicion = posicion_inicial_del_personaje();
    (*juego).personaje.elemento_en_uso = -1;
    (*juego).personaje.tiempo_perdido = 0;
    (*juego).personaje.ultimo_movimiento = DERECHA;

    if ( (*juego).personaje.tipo == POLAR ){
        
        (*juego).personaje.cantidad_elementos = 0;
        
        for (int i = (*juego).personaje.cantidad_elementos; i < 6; i++){
            (*juego).personaje.mochila[i].tipo = VELA;
            (*juego).personaje.mochila[i].movimientos_restantes = 5;
            (*juego).personaje.cantidad_elementos++;
        }   

        (*juego).personaje.mochila[(*juego).personaje.cantidad_elementos].tipo = LINTERNA;
        (*juego).personaje.mochila[(*juego).personaje.cantidad_elementos].movimientos_restantes = 4;
        (*juego).personaje.cantidad_elementos++;


    }else if ( (*juego).personaje.tipo == PARDO ){
        
        (*juego).personaje.cantidad_elementos = 0;
        
        for (int i = (*juego).personaje.cantidad_elementos; i < 4; i++){
            (*juego).personaje.mochila[i].tipo = VELA;
            (*juego).personaje.mochila[i].movimientos_restantes = 5;
            (*juego).personaje.cantidad_elementos++;
        }

        (*juego).personaje.mochila[(*juego).personaje.cantidad_elementos].tipo = LINTERNA;
        (*juego).personaje.mochila[(*juego).personaje.cantidad_elementos].movimientos_restantes = 4;
        (*juego).personaje.cantidad_elementos++;


    }else if ( (*juego).personaje.tipo == PANDA ){

        (*juego).personaje.cantidad_elementos = 0;
        
        for (int i = (*juego).personaje.cantidad_elementos; i < 4; i++){
            (*juego).personaje.mochila[i].tipo = VELA;
            (*juego).personaje.mochila[i].movimientos_restantes = 5;
            (*juego).personaje.cantidad_elementos++;
        }

        int cantidad_de_bengalas = (*juego).personaje.cantidad_elementos + 2;

         for (int i = (*juego).personaje.cantidad_elementos; i < cantidad_de_bengalas; i++){
            (*juego).personaje.mochila[i].tipo = BENGALA;
            (*juego).personaje.mochila[i].movimientos_restantes = 3;
            (*juego).personaje.cantidad_elementos++;
        }

        (*juego).personaje.mochila[(*juego).personaje.cantidad_elementos].tipo = LINTERNA;
        (*juego).personaje.mochila[(*juego).personaje.cantidad_elementos].movimientos_restantes = 10;
        (*juego).personaje.cantidad_elementos++;

    }  

}

/*
 *
 *
 *
 *
*/
bool es_posicion_valida( juego_t* juego, char terreno[ALTO_TERRENO][ANCHO_TERRENO]){    
    bool posicion = false;

    // Validando posición de Chloe
    if( terreno[(*juego).amiga_chloe.fil][(*juego).amiga_chloe.col] != (*juego).personaje.tipo ){

        posicion = true;
    }

    return posicion;

}

/*
 *
 *
 *
 *
*/
coordenada_t coordenada_valida(juego_t* juego){

    coordenada_t coordenada;
    coordenada.fil =-1;
    coordenada.col = -1;
   
 
   while ( coordenada.fil == -1  && coordenada.col == -1  ) {
   
        int posicion_fil = rand() % MAXIMO_ALEATORIO_FILA;
        int posicion_col = rand() % MAXIMO_ALEATORIO_COL;
        
        bool posicion_valida = true;
    
    
        //Valida contra coordenada personaje
        if((posicion_fil== (*juego).personaje.posicion.fil ) && (posicion_col == (*juego).personaje.posicion.col)){

            posicion_valida=false;
        
        }else if((posicion_fil== (*juego).amiga_chloe.fil ) && (posicion_col == (*juego).amiga_chloe.col)){  
            posicion_valida=false;
        }
        
        
        for (int i = 0; i < (*juego).cantidad_obstaculos; ++i){
        
                //valida contra Obstaculos        
                if( posicion_valida && (posicion_fil == (*juego).obstaculos[i].posicion.fil ) && (posicion_col == (*juego).obstaculos[i].posicion.col)){
                
                  posicion_valida=false;
                
                }
        }
        
        for (int i = 0; i < (*juego).cantidad_herramientas; ++i){
                //valida contra herramientas        
                if(posicion_valida && (posicion_fil == (*juego).herramientas[i].posicion.fil ) && (posicion_col == (*juego).herramientas[i].posicion.col)){
                
                  posicion_valida=false;

                }
        }

        if(posicion_valida){
            coordenada.fil = posicion_fil;
            coordenada.col = posicion_col;
        }

    } 

    return coordenada;
    
    }    

/*
 *
 *
 *
 *
*/
void inicializar_chloe(juego_t* juego){
   /* Se inicializa las variables con valores por defectos para poder encontrar una coordenada valida */
   (*juego).amiga_chloe.fil = -2;
   (*juego).amiga_chloe.col = -2;

   (*juego).amiga_chloe = coordenada_valida(juego);
   (*juego).chloe_visible = false;

}

/*
 *
 *
 *
 *
*/
void inicializar_obstaculos(juego_t* juego){

    (*juego).cantidad_obstaculos = 0;

    for (int i = (*juego).cantidad_obstaculos; i < 350; i++){
        (*juego).obstaculos[i].posicion = coordenada_valida(juego);
        (*juego).obstaculos[i].tipo = ARBOL;
        (*juego).obstaculos[i].visible = false;
        (*juego).cantidad_obstaculos++;
    }


     for (int i = (*juego).cantidad_obstaculos; i < 430; i++){
        (*juego).obstaculos[i].posicion = coordenada_valida(juego);
        (*juego).obstaculos[i].tipo = PIEDRA;
        (*juego).obstaculos[i].visible = false;
        (*juego).cantidad_obstaculos++;
    }

        (*juego).obstaculos[(*juego).cantidad_obstaculos].posicion = coordenada_valida(juego);
        (*juego).obstaculos[(*juego).cantidad_obstaculos].tipo = KOALAS;
        (*juego).obstaculos[(*juego).cantidad_obstaculos].visible = false;
        (*juego).cantidad_obstaculos++;
}

/*
 *
 *
 *
 *
*/
void inicializar_herramientas( juego_t* juego ){

    (*juego).cantidad_herramientas = 0;

    for (int i = (*juego).cantidad_herramientas; i < 30; i++){
        (*juego).herramientas[i].posicion = coordenada_valida(juego);
        (*juego).herramientas[i].tipo = PILA;
        (*juego).herramientas[i].visible = false;
        (*juego).cantidad_herramientas++;
    }
    //printf("%i\n", (*juego).cantidad_herramientas);

    for (int i = (*juego).cantidad_herramientas; i < 60; i++){
        (*juego).herramientas[i].posicion = coordenada_valida(juego);
        (*juego).herramientas[i].tipo = VELA;
        (*juego).herramientas[i].visible = false;
        (*juego).cantidad_herramientas++;
        
    }
    //printf("%i\n", (*juego).cantidad_herramientas);
    
    for (int i = (*juego).cantidad_herramientas; i < 70; i++){
        (*juego).herramientas[i].posicion = coordenada_valida(juego);
        (*juego).herramientas[i].tipo = BENGALA;
        (*juego).herramientas[i].visible = false;
        (*juego).cantidad_herramientas++;
        
    }
    //printf("%i\n", (*juego).cantidad_herramientas);
}


/*
 * Inicializará el juego, cargando toda la información inicial
 * y los datos del personaje. 
 */
/**/void inicializar_juego(juego_t* juego, char tipo_personaje){

    inicializar_personaje(juego,tipo_personaje);
    inicializar_chloe(juego);
    inicializar_obstaculos(juego);
    inicializar_herramientas(juego);

}

/*
 *
 *
 *
 *
*/
/**/int estado_juego(juego_t juego);

/*
 *
 *
 *
 *
*/
void resetear_visibilidad(juego_t* juego){

    (*juego).chloe_visible = false;
    
    for (int j = 0; j < (*juego).cantidad_obstaculos; j++){
        (*juego).obstaculos[j].visible = false;                             
    }

     for (int j = 0; j < (*juego).cantidad_herramientas; j++){
        (*juego).herramientas[j].visible = false;                             
    }

}

/*
 *
 *
 *
 *
*/
void iluminar_con_bengala( juego_t* juego ){
    
    printf("movimientos_restantes: %i\n", (*juego).personaje.mochila[(*juego).personaje.elemento_en_uso].movimientos_restantes );

    if ( (*juego).personaje.mochila[(*juego).personaje.elemento_en_uso].movimientos_restantes != 3 ){
        

        return ;
    }

    coordenada_t centro_de_iluminacion;

    centro_de_iluminacion.fil = rand() % MAXIMO_ALEATORIO_FILA;
    centro_de_iluminacion.col = rand() % MAXIMO_ALEATORIO_COL;

      
    if( ((abs( centro_de_iluminacion.fil - (*juego).amiga_chloe.fil ) + abs( centro_de_iluminacion.col - (*juego).amiga_chloe.col )) <= MAXIMO_DE_DISTANCIA_MANHATTAN) ){
                
        (*juego).chloe_visible = true;

    }

    for (int i = 0; i < (*juego).cantidad_obstaculos; i++){
                
        if( (abs( centro_de_iluminacion.fil - (*juego).obstaculos[i].posicion.fil ) + abs( centro_de_iluminacion.col - (*juego).obstaculos[i].posicion.col )) <= MAXIMO_DE_DISTANCIA_MANHATTAN ){
            (*juego).obstaculos[i].visible = true;
        }

    }

    for (int i = 0; i < (*juego).cantidad_herramientas; i++){
                
        if ( (abs( centro_de_iluminacion.fil - (*juego).herramientas[i].posicion.fil ) + abs( centro_de_iluminacion.col - (*juego).herramientas[i].posicion.col )) <= MAXIMO_DE_DISTANCIA_MANHATTAN ){
            (*juego).herramientas[i].visible = true;
        }
    }

}

bool es_ultimo_movimiento_valido(juego_t* juego){

    return( ((*juego).personaje.ultimo_movimiento == ARRIBA) || ((*juego).personaje.ultimo_movimiento == DERECHA) || ((*juego).personaje.ultimo_movimiento == ABAJO) || ((*juego).personaje.ultimo_movimiento == IZQUIERDA) );

}

/*
 *
 *
 *
 *
*/
void iluminar_con_linterna_arriba(juego_t* juego){

    if ( ((*juego).amiga_chloe.fil < (*juego).personaje.posicion.fil) && ( (*juego).amiga_chloe.col == (*juego).personaje.posicion.col ) ){
        (*juego).chloe_visible = true;                                
    }else{
        (*juego).chloe_visible = false;                                

    }

    for (int i = 0; i < (*juego).cantidad_obstaculos; i++){        
        if ( ((*juego).obstaculos[i].posicion.fil < (*juego).personaje.posicion.fil) && ( (*juego).obstaculos[i].posicion.col == (*juego).personaje.posicion.col ) ){
            (*juego).obstaculos[i].visible = true;
        }else{
            (*juego).obstaculos[i].visible = false;
        }
    }

    for (int i = 0; i < (*juego).cantidad_herramientas; i++){     
        if ( ((*juego).herramientas[i].posicion.fil < (*juego).personaje.posicion.fil) && ( (*juego).herramientas[i].posicion.col == (*juego).personaje.posicion.col )){
            (*juego).herramientas[i].visible = true;
        }else{
            (*juego).herramientas[i].visible = false;
        }
    }

}

/*
 *
 *
 *
 *
*/
void iluminar_con_linterna_derecha(juego_t* juego){

    if (((*juego).amiga_chloe.fil == (*juego).personaje.posicion.fil) && ((*juego).amiga_chloe.col > (*juego).personaje.posicion.col)){
                (*juego).chloe_visible = true;                                
    }else{
        (*juego).chloe_visible = false;                                
    }

    for (int i = 0; i < (*juego).cantidad_obstaculos; i++){
        if (((*juego).obstaculos[i].posicion.fil == (*juego).personaje.posicion.fil) && ( (*juego).obstaculos[i].posicion.col > (*juego).personaje.posicion.col)){
            (*juego).obstaculos[i].visible = true;
        }else{
            (*juego).obstaculos[i].visible = false;
        }
    }

    for (int i = 0; i < (*juego).cantidad_herramientas; i++){
        if (((*juego).herramientas[i].posicion.fil == (*juego).personaje.posicion.fil) && ( (*juego).herramientas[i].posicion.col > (*juego).personaje.posicion.col)){
            (*juego).herramientas[i].visible = true;
        }else{
            (*juego).herramientas[i].visible = false;
        }
    }
}

/*
 *
 *
 *
 *
*/
void iluminar_con_linterna_abajo(juego_t* juego){

    if (((*juego).amiga_chloe.fil > (*juego).personaje.posicion.fil) && ((*juego).amiga_chloe.col == (*juego).personaje.posicion.col)){
        (*juego).chloe_visible = true;
    }else{
        (*juego).chloe_visible = false;
    }

    for (int i = 0; i < (*juego).cantidad_obstaculos; i++){
        if (((*juego).obstaculos[i].posicion.fil > (*juego).personaje.posicion.fil) && ( (*juego).obstaculos[i].posicion.col == (*juego).personaje.posicion.col)){
            (*juego).obstaculos[i].visible = true;
        }else{
            (*juego).obstaculos[i].visible = false;
        }
    }

    for (int i = 0; i < (*juego).cantidad_herramientas; i++){
        if (((*juego).herramientas[i].posicion.fil > (*juego).personaje.posicion.fil) && ( (*juego).herramientas[i].posicion.col == (*juego).personaje.posicion.col)){
            (*juego).herramientas[i].visible = true;
        }else{
            (*juego).herramientas[i].visible = false;
        }
    }

}

/*
 *
 *
 *
 *
*/
void iluminar_con_linterna_izquierda(juego_t* juego){

    if (((*juego).amiga_chloe.fil == (*juego).personaje.posicion.fil) && ((*juego).amiga_chloe.col < (*juego).personaje.posicion.col)){
        (*juego).chloe_visible = true;
    }else{
        (*juego).chloe_visible = false;

    }

    for (int i = 0; i < (*juego).cantidad_obstaculos; i++){
        if (((*juego).obstaculos[i].posicion.fil == (*juego).personaje.posicion.fil) && ( (*juego).obstaculos[i].posicion.col < (*juego).personaje.posicion.col)){
            (*juego).obstaculos[i].visible = true;
        }else{
            (*juego).obstaculos[i].visible = false;
        }
    }

    for (int i = 0; i < (*juego).cantidad_herramientas; i++){
        if (((*juego).herramientas[i].posicion.fil == (*juego).personaje.posicion.fil) && ( (*juego).herramientas[i].posicion.col < (*juego).personaje.posicion.col)){
            (*juego).herramientas[i].visible = true;
        }else{
            (*juego).herramientas[i].visible = false;
        }
    }

}

/*
 *
 *
 *
 *
*/
void iluminar_con_linterna(juego_t* juego){

    resetear_visibilidad(juego);

    switch ( (*juego).personaje.ultimo_movimiento ){
   
        case ARRIBA:
       
            iluminar_con_linterna_arriba(juego);    
       
        break;

        case DERECHA:
       
            iluminar_con_linterna_derecha(juego);       
       
        break;

        case ABAJO:
       
            iluminar_con_linterna_abajo(juego);           
       
        break;

        case IZQUIERDA:
       
            iluminar_con_linterna_izquierda(juego);              

        break;   
    }
}

/*
 *
 *
 *
 *
*/
void iluminar_con_vela(juego_t* juego){
    
    //int posicion = 0;
    coordenada_t areas_a_iluminar[MAXIMO_DE_POSICIONES_VELA];

    areas_a_iluminar[0].fil = (*juego).personaje.posicion.fil - 1;
    areas_a_iluminar[0].col = (*juego).personaje.posicion.col - 1;
    areas_a_iluminar[1].fil = (*juego).personaje.posicion.fil - 1;
    areas_a_iluminar[1].col = (*juego).personaje.posicion.col;
    areas_a_iluminar[2].fil = (*juego).personaje.posicion.fil - 1;
    areas_a_iluminar[2].col = (*juego).personaje.posicion.col + 1;
    areas_a_iluminar[3].fil = (*juego).personaje.posicion.fil;
    areas_a_iluminar[3].col = (*juego).personaje.posicion.col - 1;
    areas_a_iluminar[4].fil = (*juego).personaje.posicion.fil;
    areas_a_iluminar[4].col = (*juego).personaje.posicion.col + 1;
    areas_a_iluminar[5].fil = (*juego).personaje.posicion.fil + 1;
    areas_a_iluminar[5].col = (*juego).personaje.posicion.col - 1;
    areas_a_iluminar[6].fil = (*juego).personaje.posicion.fil + 1;
    areas_a_iluminar[6].col = (*juego).personaje.posicion.col;
    areas_a_iluminar[7].fil = (*juego).personaje.posicion.fil + 1;
    areas_a_iluminar[7].col = (*juego).personaje.posicion.col + 1;

    resetear_visibilidad(juego);

    for( int i = 0 ; i < 8 ;i++ ){   
        bool es_visible = false;
        //printf("%i\n",i );
                
        if(areas_a_iluminar[i].fil == (*juego).amiga_chloe.fil && areas_a_iluminar[i].col == (*juego).amiga_chloe.col){
            (*juego).chloe_visible = true;
            es_visible=true;
        }
                
        if(!es_visible){
            for (int j = 0; j < (*juego).cantidad_obstaculos; j++){

                if(areas_a_iluminar[i].fil == (*juego).obstaculos[j].posicion.fil && areas_a_iluminar[i].col == (*juego).obstaculos[j].posicion.col){
                    (*juego).obstaculos[j].visible = true;
                    /*if ( i == 3 ){
                        posicion = j;
                        printf("%i, %c \n", j , (*juego).obstaculos[j].tipo);
                        printf("Area:[%i, %i] \n",areas_a_iluminar[i].fil,areas_a_iluminar[i].col);
                        printf("obstaculo:[%i, %i] \n",(*juego).obstaculos[j].posicion.fil,(*juego).obstaculos[j].posicion.col);
                        printf("Visible: %s \n", (*juego).obstaculos[j].visible?"true":"false" );
                    }*/
                    es_visible=true;
                }                   
            }
        }
                
        if(!es_visible){
            for (int k = 0; k < (*juego).cantidad_herramientas; k++){
                if(areas_a_iluminar[i].fil == (*juego).herramientas[k].posicion.fil && areas_a_iluminar[i].col == (*juego).herramientas[k].posicion.col){
                    (*juego).herramientas[k].visible = true;
                    es_visible=true;
                }
                        
            }                            
        }              
    }

    //printf("OBSTACULO [%i].Visible: %s \n",posicion,(*juego).obstaculos[posicion].visible?"true":"false" );
}

/*
 *
 *
 *
 *
*/
void movimiento_del_jugador( juego_t* juego, char jugada ){

    if((jugada == ARRIBA) && ((*juego).personaje.posicion.fil > 0 )){

        ((*juego).personaje.posicion.fil)--;
        (*juego).personaje.ultimo_movimiento = ARRIBA;

        if ((*juego).personaje.elemento_en_uso > 0){
            (*juego).personaje.mochila[(*juego).personaje.elemento_en_uso].movimientos_restantes--;

            if((*juego).personaje.mochila[(*juego).personaje.elemento_en_uso].movimientos_restantes <= 0){
                (*juego).personaje.elemento_en_uso = -1;
                   
            }
        }
                
    }else if((jugada == ABAJO) && ((*juego).personaje.posicion.fil < (ALTO_TERRENO - 1))){
            
        ((*juego).personaje.posicion.fil)++;
        (*juego).personaje.ultimo_movimiento = ABAJO;

        if ((*juego).personaje.elemento_en_uso > 0){
            (*juego).personaje.mochila[(*juego).personaje.elemento_en_uso].movimientos_restantes--;

            if((*juego).personaje.mochila[(*juego).personaje.elemento_en_uso].movimientos_restantes <= 0){
                (*juego).personaje.elemento_en_uso = -1;
                   

            }
        }

    }else if((jugada == DERECHA) && ((*juego).personaje.posicion.col < (ANCHO_TERRENO - 1))) {

            ((*juego).personaje.posicion.col)++;
            (*juego).personaje.ultimo_movimiento = DERECHA;

            if ((*juego).personaje.elemento_en_uso > 0){
                (*juego).personaje.mochila[(*juego).personaje.elemento_en_uso].movimientos_restantes--;

                if((*juego).personaje.mochila[(*juego).personaje.elemento_en_uso].movimientos_restantes <= 0){
                    (*juego).personaje.elemento_en_uso = -1;
                }
            }            

    }else if((jugada == IZQUIERDA) && ((*juego).personaje.posicion.col > 0 )){
            
            ((*juego).personaje.posicion.col)--;
            (*juego).personaje.ultimo_movimiento = IZQUIERDA;

            if ((*juego).personaje.elemento_en_uso > 0){
                (*juego).personaje.mochila[(*juego).personaje.elemento_en_uso].movimientos_restantes--;

                if((*juego).personaje.mochila[(*juego).personaje.elemento_en_uso].movimientos_restantes <= 0){
                    (*juego).personaje.elemento_en_uso = -1;
                }
            }    
        }

}

/*
 *
 *
 *
 *
*/
void realizar_jugada(juego_t* juego, char jugada){
        
    movimiento_del_jugador( juego, jugada );

        if( es_jugada_valida(jugada) ){
            
            for (int i = 0; i < (*juego).personaje.cantidad_elementos; i++){

                if ((*juego).personaje.mochila[i].movimientos_restantes > 0 ){
                    if (jugada == (*juego).personaje.mochila[i].tipo){
                        if (i != (*juego).personaje.elemento_en_uso){
                        (*juego).personaje.elemento_en_uso = i;
                        
                        }else{
                            (*juego).personaje.elemento_en_uso = -1;
                        }
                    }
                    
                }else{
                     resetear_visibilidad(juego);
                }
            }  
        }

        if ((*juego).personaje.elemento_en_uso > -1){
        
            switch((*juego).personaje.mochila[(*juego).personaje.elemento_en_uso].tipo){

                case LINTERNA:
                    iluminar_con_linterna(juego);
                break;

                case VELA:
                    iluminar_con_vela(juego);
                break;

                case BENGALA:
                    iluminar_con_bengala( juego );
                break;
            }
        }
}









