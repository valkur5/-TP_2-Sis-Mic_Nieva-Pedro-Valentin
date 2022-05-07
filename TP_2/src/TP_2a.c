/*=============================================================================
 * Author: Pedro Valentin Nieva <valentin9702@gmail.com>
 * Date: 2022/04/26
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "TP_2.h"
#include "sapi.h"
#include "GPIO.h"

/*=====[Definicion de funciones]==============================*/

void forma_sin();
void forma_sqr();
void forma_tri();
void F_V();
void UP();
void Down();

/*=====[Definicion de variables globales]==============================*/

char onda = '0';
bool_t modo = true; //true = tensión, false = frecuencia

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   // ----- Setup -----------------------------------
   boardInit();

   // Se inicializan los LEDs
   Init_LED('1');
   Init_LED('2');
   Init_LED('3');
   Init_LED('R');
   Init_LED('G');
   Init_LED('B');
   // Se inicializan las teclas
   Init_TEC(1);
   Init_TEC(2);
   Init_TEC(3);
   Init_TEC(4);
   // Estado inicial del modo de edición
   onda='s';
   Encender('1');
   // ----- Repeat for ever -------------------------
   while( true ) {

	   switch (onda){
					   case 's':
						   forma_sin();
						   break;
					   case 'c':
						   forma_sqr();
						   break;
					   case 't':
						   forma_tri();
						   break;
	   }

   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}

void forma_sin(){
	Encender('R');//Se enciende el led Rojo indicando que está en modo "seno"
	while(onda == 's'){

		if(Leer_TEC(2)!=true){//Esto se encarga de determinar el cambio de modo (Tensión o frecuencia)
			while(Leer_TEC(2)!=true);
			if(modo==true){
				modo=false;
			}
			else if(modo==false){
				modo=true;
			}
			F_V();
		}
		if(Leer_TEC(3)!=true){//Detecta si se quiere aumentar el valor
			UP();
		}
		if(Leer_TEC(4)!=true){//Detecta si se quiere disminuir el valor
			Down();
		}

		if (Leer_TEC(1) != true){//Esta es la que se encarga de hacer un cambio de onda
			while(Leer_TEC(1)!=true);
			onda='c';
		}
	}
	Apagar('R');//Al cambiar de onda se sale del bucle y se apaga el led rojo
}
void forma_sqr(){
	Encender('G');//Se enciende el led Verde indicando que está en modo onda cuadrada
	while(onda == 'c'){
		if(Leer_TEC(2)!=true){
			while(Leer_TEC(2)!=true);
			if(modo==true){
				modo=false;
			}
			else if(modo==false){
				modo=true;
			}
			F_V();
		}
		if(Leer_TEC(3)!=true){
			UP();
		}
		if(Leer_TEC(4)!=true){
			Down();
		}

		if(Leer_TEC(1) != true){
			while(Leer_TEC(1)!=true);
			onda = 't';
		}
	}
	Apagar('G');
}
void forma_tri(){
	Encender('B');//Se enciende el led azul indicando que está en modo onda triangular
	while(onda == 't'){
		if(Leer_TEC(2)!=true){
			while(Leer_TEC(2)!=true);
			if(modo==true){
				modo=false;
			}
			else if(modo==false){
				modo=true;
			}
			F_V();
		}
		if(Leer_TEC(3)!=true){
			UP();
		}
		if(Leer_TEC(4)!=true){
			Down();
		}


		if(Leer_TEC(1) != true){
			while(Leer_TEC(1) != true);
			onda = 's';
		}
	}
	Apagar('B');
}
void F_V(){ //Cambio de modo de edición (tensión o frecuencia)
	if(modo==true){
	Encender('1');
	} else {
	Apagar('1');
	}
}
void UP(){//Esta funcion se encarga de denotar cuando aumenta la tensión o frecuencia
	while(Leer_TEC(3)!=true){
		Encender('2');
		delay(100);
		Apagar('2');
		delay(100);
	}
}
void Down(){//Esta funcion se encarga de denotar cuando disminuye la tensión o frecuencia
	while(Leer_TEC(4)!=true){
		Encender('3');
		delay(100);
		Apagar('3');
		delay(100);
	}
}
