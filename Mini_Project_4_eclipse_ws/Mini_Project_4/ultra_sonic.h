 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.h
 *
 * Description: Header file for the AVR GPIO driver
 *
 * Author: Sohail Talaat
 *
 *******************************************************************************/


#ifndef ULTRA_SONIC_H_
#define ULTRA_SONIC_H_
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define TRIGGER_PORT   PORTB_ID /*trigger port*/
#define TRIGGER_PIN    PIN6_ID /*trigger pin*/

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * 1.initiate icu
 * 2.set callback function to be execute every time icu caputer rising or falling edge
 * 3.set the trigger pin direction
 */
void Ultrasonic_init(void);

/*
 * Description :
 * make a pulse for 10us to trigger the ultrasonic sensor
 */
void Ultrasonic_Trigger(void);

/*
 * Description :
 * make a trigger and start reading the time between the rising and falling edge
 * of ultrasonic sensor echo pulse using icu
 */
uint16 Ultrasonic_readDistance(void);

/*
 * Description :
 * this function has two parts first part responsible to detect the time
 * of rising edge detection and clear the timer register and wait for the falling
 * edge in the second part of this function. once the falling edge came the time
 * will be stored in a variable and the timer register will be cleared and wait for
 * the next rising edge to calculate again. this function will passed as callback
 * to Icu_setCallBack to be executed every time an interrupt happens
 */
void Ultrasonic_edgeProcessing(void);



#endif /* ULTRA_SONIC_H_ */
