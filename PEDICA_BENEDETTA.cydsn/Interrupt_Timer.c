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
#include "Interrupt_Timer.h"

CY_ISR(Custom_TIMER_ISR)
{
    Timer_ReadStatusRegister();
    time_passed=1;
}
    
/* [] END OF FILE */
