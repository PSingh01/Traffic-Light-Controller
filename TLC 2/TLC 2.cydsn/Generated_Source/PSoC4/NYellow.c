/*******************************************************************************
* File Name: NYellow.c  
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
#include "NYellow.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        NYellow_PC =   (NYellow_PC & \
                                (uint32)(~(uint32)(NYellow_DRIVE_MODE_IND_MASK << (NYellow_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (NYellow_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: NYellow_Write
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
void NYellow_Write(uint8 value) 
{
    uint8 drVal = (uint8)(NYellow_DR & (uint8)(~NYellow_MASK));
    drVal = (drVal | ((uint8)(value << NYellow_SHIFT) & NYellow_MASK));
    NYellow_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: NYellow_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  NYellow_DM_STRONG     Strong Drive 
*  NYellow_DM_OD_HI      Open Drain, Drives High 
*  NYellow_DM_OD_LO      Open Drain, Drives Low 
*  NYellow_DM_RES_UP     Resistive Pull Up 
*  NYellow_DM_RES_DWN    Resistive Pull Down 
*  NYellow_DM_RES_UPDWN  Resistive Pull Up/Down 
*  NYellow_DM_DIG_HIZ    High Impedance Digital 
*  NYellow_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void NYellow_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(NYellow__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: NYellow_Read
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
*  Macro NYellow_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 NYellow_Read(void) 
{
    return (uint8)((NYellow_PS & NYellow_MASK) >> NYellow_SHIFT);
}


/*******************************************************************************
* Function Name: NYellow_ReadDataReg
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
uint8 NYellow_ReadDataReg(void) 
{
    return (uint8)((NYellow_DR & NYellow_MASK) >> NYellow_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(NYellow_INTSTAT) 

    /*******************************************************************************
    * Function Name: NYellow_ClearInterrupt
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
    uint8 NYellow_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(NYellow_INTSTAT & NYellow_MASK);
		NYellow_INTSTAT = maskedStatus;
        return maskedStatus >> NYellow_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
