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
#ifndef __COLOUR_DRIVER__
    #define __COLOUR_DRIVER__
    
#include "project.h"
#include "cytypes.h"
    
typedef struct 
{
   uint8_t red;
   uint8_t green;
   uint8_t blue;
}colour;

colour c; 

void SetColour(colour c);

#endif

/* [] END OF FILE */
