/*******************************************************************************
* File Name: SGreen.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "SGreen.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        SGreen_PC =   (SGreen_PC & \
                                (uint32)(~(uint32)(SGreen_DRIVE_MODE_IND_MASK << (SGreen_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (SGreen_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: SGreen_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void SGreen_Write(uint8 value) 
{
    uint8 drVal = (uint8)(SGreen_DR & (uint8)(~SGreen_MASK));
    drVal = (drVal | ((uint8)(value << SGreen_SHIFT) & SGreen_MASK));
    SGreen_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: SGreen_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SGreen_DM_STRONG     Strong Drive 
*  SGreen_DM_OD_HI      Open Drain, Drives High 
*  SGreen_DM_OD_LO      Open Drain, Drives Low 
*  SGreen_DM_RES_UP     Resistive Pull Up 
*  SGreen_DM_RES_DWN    Resistive Pull Down 
*  SGreen_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SGreen_DM_DIG_HIZ    High Impedance Digital 
*  SGreen_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SGreen_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(SGreen__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: SGreen_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro SGreen_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SGreen_Read(void) 
{
    return (uint8)((SGreen_PS & SGreen_MASK) >> SGreen_SHIFT);
}


/*******************************************************************************
* Function Name: SGreen_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 SGreen_ReadDataReg(void) 
{
    return (uint8)((SGreen_DR & SGreen_MASK) >> SGreen_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SGreen_INTSTAT) 

    /*******************************************************************************
    * Function Name: SGreen_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 SGreen_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(SGreen_INTSTAT & SGreen_MASK);
		SGreen_INTSTAT = maskedStatus;
        return maskedStatus >> SGreen_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
