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

#ifndef __INTERRUPT_ROUTINES_H
#define __INTERRUPT_ROUTINES_H

#include "cytypes.h"
#include "project.h"
#include "ColourDriver.h"
#include "Variables.h" 
    
#define TAIL 0xC0
#define HEADER 0xA0

CY_ISR_PROTO(CUSTOM_UART_isr);

#endif

/* [] END OF FILE */
