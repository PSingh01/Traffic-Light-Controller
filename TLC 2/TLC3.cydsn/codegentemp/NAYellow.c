/*******************************************************************************
* File Name: NAYellow.c  
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
#include "NAYellow.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        NAYellow_PC =   (NAYellow_PC & \
                                (uint32)(~(uint32)(NAYellow_DRIVE_MODE_IND_MASK << (NAYellow_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (NAYellow_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: NAYellow_Write
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
void NAYellow_Write(uint8 value) 
{
    uint8 drVal = (uint8)(NAYellow_DR & (uint8)(~NAYellow_MASK));
    drVal = (drVal | ((uint8)(value << NAYellow_SHIFT) & NAYellow_MASK));
    NAYellow_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: NAYellow_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  NAYellow_DM_STRONG     Strong Drive 
*  NAYellow_DM_OD_HI      Open Drain, Drives High 
*  NAYellow_DM_OD_LO      Open Drain, Drives Low 
*  NAYellow_DM_RES_UP     Resistive Pull Up 
*  NAYellow_DM_RES_DWN    Resistive Pull Down 
*  NAYellow_DM_RES_UPDWN  Resistive Pull Up/Down 
*  NAYellow_DM_DIG_HIZ    High Impedance Digital 
*  NAYellow_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void NAYellow_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(NAYellow__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: NAYellow_Read
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
*  Macro NAYellow_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 NAYellow_Read(void) 
{
    return (uint8)((NAYellow_PS & NAYellow_MASK) >> NAYellow_SHIFT);
}


/*******************************************************************************
* Function Name: NAYellow_ReadDataReg
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
uint8 NAYellow_ReadDataReg(void) 
{
    return (uint8)((NAYellow_DR & NAYellow_MASK) >> NAYellow_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(NAYellow_INTSTAT) 

    /*******************************************************************************
    * Function Name: NAYellow_ClearInterrupt
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
    uint8 NAYellow_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(NAYellow_INTSTAT & NAYellow_MASK);
		NAYellow_INTSTAT = maskedStatus;
        return maskedStatus >> NAYellow_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
