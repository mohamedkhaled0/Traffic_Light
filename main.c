/*
 * main.c
 *
 *  Created on: Mar 7, 2022
 *      Author: gerges
 */

#include "LIB/LSTD_TYPES.h"
#include "MCAL/MDIO/MDIO_Interface.h"
#include "HAL/HLED/HLED_Interface.h"
#include "RTOS_Stack/RTOS_Interface.h"
#include "avr/io.h"
#include "util/delay.h"
#include "Seven_G.h"



 static u8  Main_Counter = 0 ;
 static  u8 Time_Frame = 0 ;


LED_t Led1={MDIO_PORTC,PIN0};
LED_t Led2={MDIO_PORTC,PIN1};
LED_t Led3={MDIO_PORTC,PIN2};




void RUN_DC_MOTOR_FORWARD(void){
	// enable the motor driver bin
	PORTB |= (1<<5);
	PORTB |= (1<<3);
	PORTB &= ~(1<<4);



}


void RUN_DC_MOTOR_BACKWARD(void){
	// enable the motor driver bin
	PORTB |= (1<<5);
	PORTB |= (1<<4);
	PORTB &= ~(1<<3);
}


void MOTOR_OFF(void){

	PORTB &= ~(1<<5);
	PORTB &= ~(1<<3);
	PORTB &= ~(1<<4);


}




 void Traffic_Lights(void){

	 if ( Main_Counter >= 0 &&  Main_Counter < 60  ){
	 	HLED_VidLed_On(&Led1);
	 	HLED_VidLed_Off(&Led2);
	 	HLED_VidLed_Off(&Led3);
	    }
	else if ( Main_Counter >= 60 &&  Main_Counter < 70 ){

		HLED_VidLed_On(&Led2);
		HLED_VidLed_Off(&Led1);
		HLED_VidLed_Off(&Led3);
	}

	else if ( Main_Counter >= 70 &&  Main_Counter < 130 ){

		HLED_VidLed_On(&Led3);
		HLED_VidLed_Off(&Led1);
		HLED_VidLed_Off(&Led2);
	}

	else {


	}

 }


  void Motor_Operation (void){

	   if (Main_Counter >= 0  && Main_Counter < 5 ){


		   RUN_DC_MOTOR_FORWARD ();

	   }
	   else if (Main_Counter >= 70  && Main_Counter < 75){

		   RUN_DC_MOTOR_BACKWARD();
	   }


	   else {

		   MOTOR_OFF();
	   }


  }


  void SSG_COUNTER(){
     Time_Frame++;

     if (Time_Frame == 40)
     {
    	 Main_Counter++;


    	  if ( Main_Counter >= 0 &&  Main_Counter < 60 )
    	       {

    		  SevenSegmentUpdate (Main_Counter);
    	   }

    	  else if ( Main_Counter >= 60 &&  Main_Counter < 70 ) {

    		  SevenSegmentUpdate (Main_Counter - 60);
    	  }

    	 else if ( Main_Counter >= 70 &&  Main_Counter < 130 ) {

    	     		  SevenSegmentUpdate (Main_Counter - 70);
    	   }
    	 else if (Main_Counter == 130)
    	 {
    		 Main_Counter = 0;

    	 }
    	 else {


    	 }

    	Time_Frame = 0;
     }


  }








int main(void)
{
	HLED_VidInit(&Led1);
	HLED_VidInit(&Led2);
	HLED_VidInit(&Led3);
	SevenSegmentInit ();

	MDIO_Error_State_SetPortDirection(MDIO_PORTB,PORT_OUTPUT);


	RTOS_VidCreateTask(SSG_COUNTER , 1 , 0 , 0 );
	RTOS_VidCreateTask(Traffic_Lights , 10 , 1 , 1 );
	RTOS_VidCreateTask(Motor_Operation, 10 , 2 , 2 );

	RTOS_VidInit();

	while(1)
	{

	}
	return 0;

}





