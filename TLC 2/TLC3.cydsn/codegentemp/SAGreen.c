/*******************************************************************************
* File Name: SAGreen.c  
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
#include "SAGreen.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        SAGreen_PC =   (SAGreen_PC & \
                                (uint32)(~(uint32)(SAGreen_DRIVE_MODE_IND_MASK << (SAGreen_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (SAGreen_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: SAGreen_Write
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
void SAGreen_Write(uint8 value) 
{
    uint8 drVal = (uint8)(SAGreen_DR & (uint8)(~SAGreen_MASK));
    drVal = (drVal | ((uint8)(value << SAGreen_SHIFT) & SAGreen_MASK));
    SAGreen_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: SAGreen_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SAGreen_DM_STRONG     Strong Drive 
*  SAGreen_DM_OD_HI      Open Drain, Drives High 
*  SAGreen_DM_OD_LO      Open Drain, Drives Low 
*  SAGreen_DM_RES_UP     Resistive Pull Up 
*  SAGreen_DM_RES_DWN    Resistive Pull Down 
*  SAGreen_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SAGreen_DM_DIG_HIZ    High Impedance Digital 
*  SAGreen_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SAGreen_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(SAGreen__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: SAGreen_Read
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
*  Macro SAGreen_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SAGreen_Read(void) 
{
    return (uint8)((SAGreen_PS & SAGreen_MASK) >> SAGreen_SHIFT);
}


/*******************************************************************************
* Function Name: SAGreen_ReadDataReg
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
uint8 SAGreen_ReadDataReg(void) 
{
    return (uint8)((SAGreen_DR & SAGreen_MASK) >> SAGreen_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SAGreen_INTSTAT) 

    /*******************************************************************************
    * Function Name: SAGreen_ClearInterrupt
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
    uint8 SAGreen_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(SAGreen_INTSTAT & SAGreen_MASK);
		SAGreen_INTSTAT = maskedStatus;
        return maskedStatus >> SAGreen_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
