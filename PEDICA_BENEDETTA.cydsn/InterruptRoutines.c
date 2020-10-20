/* ========================================
 *
 * In this files is implemented the state machine
 * All values are initialized and using two switch
 * the first one checking on the input and the
 * second one checking for the status.
 * the status are consequently scanned.
 * The UART is triggered when recieving a single byte.
 *
 * ========================================
*/
#include "InterruptRoutines.h"
#include "Interrupt_Timer.h"
#include "UART.h"
#include "stdio.h"
#include "PWM_RG.h"
#include "PWM_B.h"

#define HEADER_VALUE 0xA0
#define TAIL_VALUE 0xC0
#define V_INPUT 'v' 

//defining a value for each of the state

#define IDLE 0
#define HEAD 1
#define RED 2
#define GREEN  3
#define BLUE 4
#define TAIL 5
#define V_STRING 6

CY_ISR(CUSTOM_UART_isr)
{
    if(UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY)    
    {
        uint8_t input = UART_ReadRxData();       //reading the input from the peripheral 

        time=0;    

        switch (input)  //using a switch for the input value
           {
            case V_INPUT:                                           
                state=V_STRING;                                    
                break;
            
            case HEADER_VALUE:                
                    flag=1;     
                    state++;
                break;
            
            default:
                if(flag==1)
                {           
                 state++;    //increment to scan over all states
                }
                else
                {
                 UART_PutString("Incorrect Header\r\n");
                }
                break;
            }

    switch(state)    
        {         
            case IDLE:
                UART_PutString("Please, insert correct Header\r\n");
                break;
                
            case HEAD:
                UART_PutString("Header OK,insert Red value\r\n");
                break;
                
            case RED:
                PWM_RG_WriteCompare1(input);    //input value is set as the value of RED channel 
                UART_PutString("Insert Green value\r\n");
                break;
                
            case GREEN:
                PWM_RG_WriteCompare2(input);    //input value is set as the value of GREEN channel   
                UART_PutString("Insert Blue value\r\n");
                break;
                
            case BLUE:
                PWM_B_WriteCompare(input);      //input value is set as the value of BLUE channel 
                UART_PutString("Insert TAIL value\r\n");
                break;
                
            case TAIL:
                if(input == TAIL_VALUE)
                {
                    UART_PutString("Success! LED correctly programmed\r\n");            
                    state=IDLE;     //going back to the IDLE state
                    flag=0;
                }
                else
                {
                    UART_PutString("Incorrect Tail, start again\r\n");
                    PWM_RG_WriteCompare1(0);      //setting again initial conditions   
                    PWM_RG_WriteCompare2(0);          
                    PWM_B_WriteCompare(0); 
                    state=0;   
                    flag=0;     //reset of the flag to start again the procedure
                }
                break;
                
            case V_STRING:
                UART_PutString("RGB LED Program $$$\r\n");
                flag=0;
                break;
                
            default:
                break;
            } 
    }
   
}




/* [] END OF FILE */
