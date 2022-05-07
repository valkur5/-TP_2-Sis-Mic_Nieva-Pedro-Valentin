/*=============================================================================
 * Author: Pedro Valentin Nieva <valentin9702@gmail.com>
 * Date: 2022/05/06
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "TP_2b.h"
#include "sapi.h"
#include "GPIO.h"

/*=====[Definición de funciones]==============================*/

void Abriendo();
void Cerrando();

/*=====[Definición de variables globales]==============================*/

bool_t abierto=false;

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   // ----- Setup -----------------------------------
   boardInit();
   Init_LED('2'); //Abriendo
   Init_LED('3'); //Cerrando
   Init_LED('R'); //Motor Encendido
   Init_LED('G'); //Motor Apagado

   Init_TEC(1); //Presencia
   Init_TEC(2); //final de carrera cerrado
   Init_TEC(3); //final de carrera abierto

   Encender('G'); //Estado inicial, motor apagado
   // ----- Repeat for ever -------------------------
   while( true ) {

	   if(Leer_TEC(1)!=true && abierto==false){ //Si detecta presencia y la puerta corrediza está cerrada, se abre
		   Abriendo();
	   }
	   if(Leer_TEC(1)==true && abierto==true){//Si ya no detecta presencia y está abierto, entonces empieza a cerrarse
		   Cerrando();
	   }
   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}
void Abriendo(){
	Apagar('G'); //Se apaga el led que indica que el motor está apagado
	Encender('R');//Se enciende le motor
	Encender('2');//Se enciende la luz indicando que se está abriendo
	while(Leer_TEC(3)==true);//Espera a que el final de carrera abierto indique que se terminó de abrir
	Apagar('2');
	Apagar('R');
	//Al terminar de abrirse se apaga el motor y la luz que indica que se está abriendo
	Encender('G');//Se enciende el led que indica que el motor está apagado
	abierto=true;//Cambia la función indicando que la puerta está abierta
}
void Cerrando(){
    if (abierto==true){//Si está abierto, espera 3 segundos y luego se cierra
	   delay(3000);
	   abierto=false;
	}
    Apagar('G');
	Encender('R');
	Encender('3');
	while(Leer_TEC(2)==true);//Espera a que el final de carrera indique que está cerrado
	Apagar('R');
	Apagar('3');
	Encender('G');
}
