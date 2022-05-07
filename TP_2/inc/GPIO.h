/*
 * GPIO.h
 *
 *  Created on: 12 abr. 2022
 *      Author: valkur
 */

#ifndef PROGRAMAS_TP_1_INC_GPIO_H_
#define PROGRAMAS_TP_1_INC_GPIO_H_

// --- Declaración de funciones ---
void Init_LED(char LED);
void Encender(char LED);
void Apagar(char LED);
void Switch_LED(char LED);
void Init_TEC(int TECLA);
bool_t Leer_TEC(int TECLA);



#endif /* PROGRAMAS_TP_1_INC_GPIO_H_ */
