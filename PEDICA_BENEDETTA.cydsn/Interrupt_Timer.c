/* ========================================
 *
 * In this .c file is implemented the timer
 * As the period of the timer is set to 1s,
 * the variable time is incremented and if it
 * reaches the timeout value all the variables
 * are reset and is printed on the terminal 
 * a message of timeout. 
 *
 * ========================================
*/
#include "Interrupt_Timer.h"
#include "Variables.h"
#include "UART.h"

uint8_t timeout=5; //timeout value after which must return to IDLE state in each case

CY_ISR(Custom_TIMER_ISR)
{
    Timer_ReadStatusRegister();
    if (state!=0)
    {
    time ++;  //incrementing time value 
    
    if (time == timeout) 
    {
        UART_PutString("Time Out\r\n");   //display an Error message in the peripheral
        time=0;                          //initializing again all the values to start again from 0
        flag=0;           
        state=0;  
    }
    }
}
    
/* [] END OF FILE */
