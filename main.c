 /******************************************************************************
 *
 * File Name: main.c
 *
 * Description:source file to test the temperature controlled fan using ATmega16
 *
 *
 * Author: Shimaa Gamal
 *
 *******************************************************************************/

#include "lcd.h"
#include "dc_motor.h"
#include "lm35_sensor.h"
#include "adc.h"

uint8 temp;

ADC_ConfigType adc_Config ={Internal,F_CPU_8};

int main(void){

	LCD_init();
	ADC_init(&adc_Config);
	DcMotor_Init();
	LCD_displayStringRowColumn(0,3,"FAN is ");
	LCD_displayStringRowColumn(1,3,"Temp =     C");

	while(1){
		temp = LM35_getTemperature();
		if (temp>=30){
			LCD_displayStringRowColumn(0,10,"ON ");   /*ON followed by ' ' in case it became on after off*/
			DcMotor_State state = CW;
			if (temp>=120){
				DcMotor_Rotate(state,100);
			}

			else if (temp >=90)
			{
				DcMotor_Rotate(state,75);
			}
			else if (temp>= 60){
				DcMotor_Rotate(state,50);
			}
			else if(temp>=30){
				DcMotor_Rotate(state,25);
			}

		}

		else if (temp<30){
			DcMotor_State state=Stop;
			LCD_displayStringRowColumn(0,10,"OFF");
			DcMotor_Rotate(state,0);
		}
		/* Display the temperature value every time at same position */
		LCD_moveCursor(1,10);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}

	}



}

