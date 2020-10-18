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
#include "InterruptRoutines.h"


CY_ISR(CUSTOM_UART_isr)
{
    if (UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY)
    {
        Timer_Start();   
        if (count == 0)
        {
            header = UART_ReadRxData();            
            if (header == 'v')
            {
                v_string=1;
            }
            else if (header != HEADER)
            {
                error=1;
            }   
        }
        else if (count==1)
        {           
            c.red=UART_ReadRxData();
        }
        else if (count==2)
        {
            c.green=UART_ReadRxData();
        }
        else if (count==3)
        {
            c.blue= UART_ReadRxData();
        }
        else if (count==4)
        {
            tail=UART_ReadRxData();
            if (tail != TAIL) //if tail is not the correct one
            {
                error=1;
            }
        if (error == 0)
        {
            end_transmission =1;
        }
    }
    count ++;
}
}


/* [] END OF FILE */
