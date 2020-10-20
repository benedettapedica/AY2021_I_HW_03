/**
* \file main.c
* \brief Main source file for the Assignment 03.
*
* This source file allows to control the color of an RGB
* LED through a Serial Port. 
*
* \author: Benedetta Pedica
* \date: October 15, 2020
*/

#include "project.h"
#include "InterruptRoutines.h"
#include "Interrupt_Timer.h"
#include "stdio.h"

//initializing control variables 

uint8_t time=0;
uint8_t flag=0;
uint8_t state=0;

int main(void)
{
    CyGlobalIntEnable; 
    
    //initializing all the functions for PWMs, UART and TIMER
    
    UART_Start();
    PWM_RG_Start();
    PWM_B_Start();    
    isr_timer_StartEx(Custom_TIMER_ISR);
    isr_UART_StartEx(CUSTOM_UART_isr);
    
    state=0;
    time=0;
    Timer_Start();   
    
    //setting values so that at the start the LED is OFF (0,0,0)
  
    PWM_RG_WriteCompare1(0);         
    PWM_RG_WriteCompare2(0);          
    PWM_B_WriteCompare(0);  
    
    for(;;)
    {      
      
    }
}
                    
   

/* [] END OF FILE */
