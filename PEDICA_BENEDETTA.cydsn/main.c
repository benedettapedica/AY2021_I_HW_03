/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "InterruptRoutines.h"
#include "Interrupt_Timer.h"

int main(void)
{
    CyGlobalIntEnable; 
    UART_Start();
    PWM_RG_Start();
    PWM_B_Start();
    
    isr_timer_StartEx(Custom_TIMER_ISR);
    isr_UART_StartEx(CUSTOM_UART_isr);
    for(;;)
   
    {      
        if (end_transmission==1)
        {
            SetColour(c);
            UART_PutString("Congifuration OK: all bytes acquired\n");  
            count = 0;
            Timer_Stop();
            end_transmission=0;           
        }
        else if (time_passed == 1)
        { 
            UART_PutString("5 seconds have passed\n"); 
            count = 0;
            UART_Init();
            Timer_Stop();
            time_passed=0;
        }
        
        else if (v_string == 1)
        { 
            UART_PutString("RGB LED Program $$$\n");
            UART_Init();
            count = 0;
            Timer_Stop();
            v_string = 0;
        }
        else if (error == 1)
        { 
            UART_PutString("Transmission error\n");
            UART_Init();
            count = 0;
            Timer_Stop();
            error = 0;
        }
            
    }
}

/* [] END OF FILE */
