/*******************************************************************************
* File Name: SAYellow.c  
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
#include "SAYellow.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        SAYellow_PC =   (SAYellow_PC & \
                                (uint32)(~(uint32)(SAYellow_DRIVE_MODE_IND_MASK << (SAYellow_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (SAYellow_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: SAYellow_Write
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
void SAYellow_Write(uint8 value) 
{
    uint8 drVal = (uint8)(SAYellow_DR & (uint8)(~SAYellow_MASK));
    drVal = (drVal | ((uint8)(value << SAYellow_SHIFT) & SAYellow_MASK));
    SAYellow_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: SAYellow_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SAYellow_DM_STRONG     Strong Drive 
*  SAYellow_DM_OD_HI      Open Drain, Drives High 
*  SAYellow_DM_OD_LO      Open Drain, Drives Low 
*  SAYellow_DM_RES_UP     Resistive Pull Up 
*  SAYellow_DM_RES_DWN    Resistive Pull Down 
*  SAYellow_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SAYellow_DM_DIG_HIZ    High Impedance Digital 
*  SAYellow_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SAYellow_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(SAYellow__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: SAYellow_Read
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
*  Macro SAYellow_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SAYellow_Read(void) 
{
    return (uint8)((SAYellow_PS & SAYellow_MASK) >> SAYellow_SHIFT);
}


/*******************************************************************************
* Function Name: SAYellow_ReadDataReg
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
uint8 SAYellow_ReadDataReg(void) 
{
    return (uint8)((SAYellow_DR & SAYellow_MASK) >> SAYellow_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SAYellow_INTSTAT) 

    /*******************************************************************************
    * Function Name: SAYellow_ClearInterrupt
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
    uint8 SAYellow_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(SAYellow_INTSTAT & SAYellow_MASK);
		SAYellow_INTSTAT = maskedStatus;
        return maskedStatus >> SAYellow_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
