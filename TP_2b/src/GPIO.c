/*
 * GPIO.c
 *
 *  Created on: 1 abr. 2022
 *      Author: valkur
 */
#include "chip.h"
#include "sapi_datatypes.h"

void Init_LED(char LED){ // Función para inicializar los LEDs de la EDU-CIAA
	switch(LED){
	case '1':
		Chip_SCU_PinMux(2,10, MD_PUP,FUNC0);
		Chip_GPIO_SetPinDIR(LPC_GPIO_PORT,0,14,1);
		break;
	case '2':
		Chip_SCU_PinMux(2,11, MD_PUP,FUNC0);
		Chip_GPIO_SetPinDIR(LPC_GPIO_PORT,1,11,1);
		break;
	case '3':
		Chip_SCU_PinMux(2,12, MD_PUP,FUNC0);
		Chip_GPIO_SetPinDIR(LPC_GPIO_PORT,1,12,1);
		break;
	case 'R':
		Chip_SCU_PinMux(2,0, MD_PUP,FUNC4);
		Chip_GPIO_SetPinDIR(LPC_GPIO_PORT,5,0,1);
		break;
	case 'G':
		Chip_SCU_PinMux(2,1, MD_PUP,FUNC4);
		Chip_GPIO_SetPinDIR(LPC_GPIO_PORT,5,1,1);
		break;
	case 'B':
		Chip_SCU_PinMux(2,2, MD_PUP,FUNC4);
		Chip_GPIO_SetPinDIR(LPC_GPIO_PORT,5,2,1);
		break;
	}
}

void Encender(char LED){// Función encargada de encender los LEDs
	switch(LED){
		case '1':
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,0,14);
			break;
		case '2':
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,1,11);
			break;
		case '3':
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,1,12);
			break;
		case 'R':
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,5,0);
			break;
		case 'G':
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,5,1);
			break;
		case 'B':
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,5,2);
			break;
		}
}

void Apagar(char LED){// Función encargada de apagar los LEDs
	switch(LED){
		case '1':
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,0,14);
			break;
		case '2':
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,1,11);
			break;
		case '3':
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,1,12);
			break;
		case 'R':
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,0);
			break;
		case 'G':
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,1);
			break;
		case 'B':
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,2);
			break;
	}
}

void Switch_LED(char LED){
	switch(LED){
		case '1':
			if((bool_t)Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,14) == true){
				Apagar('1');
			} else{
				Encender('1');
			}
			break;
		case '2':
			if((bool_t)Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,1,11) == true){
				Apagar('2');
			} else{
				Encender('2');
			}
			break;
		case '3':
			if((bool_t)Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,1,12) == true){
				Apagar('3');
			} else{
				Encender('3');
			}
			break;
		case 'R':
			if((bool_t)Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,5,0) == true){
				Apagar('R');
			} else{
				Encender('R');
			}
			break;
		case 'G':
			if((bool_t)Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,5,1) == true){
				Apagar('G');
			} else{
				Encender('G');
			}
			break;
		case 'B':
			if((bool_t)Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,5,2) == true){
				Apagar('B');
			} else{
				Encender('B');
			}
			break;
	}
}

void Init_TEC(int TECLA){// Función para inicializar las teclas de la EDU-CIAA
	switch(TECLA){
		case 1:
			Chip_SCU_PinMux(1,0,MD_PUP|MD_EZI|MD_ZI,FUNC0);
			Chip_GPIO_SetPinDIR(LPC_GPIO_PORT,0,4,0);
			break;
		case 2:
			Chip_SCU_PinMux(1,1,MD_PUP|MD_EZI|MD_ZI,FUNC0);
			Chip_GPIO_SetPinDIR(LPC_GPIO_PORT,0,8,0);
			break;
		case 3:
			Chip_SCU_PinMux(1,2,MD_PUP|MD_EZI|MD_ZI,FUNC0);
			Chip_GPIO_SetPinDIR(LPC_GPIO_PORT,0,9,0);
			break;
		case 4:
			Chip_SCU_PinMux(1,6,MD_PUP|MD_EZI|MD_ZI,FUNC0);
			Chip_GPIO_SetPinDIR(LPC_GPIO_PORT,1,9,0);
			break;
		}
}

bool_t Leer_TEC(int TECLA){// Función para leer el valor de la tecla correspondiente
	bool_t aux=0;
	switch(TECLA){
		case 1:
			aux = (bool_t)Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,4);
			break;
		case 2:
			aux = (bool_t)Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,8);
			break;
		case 3:
			aux = (bool_t)Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,9);
			break;
		case 4:
			aux = (bool_t)Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,1,9);
			break;
		}
	return aux;
}

