/*******************************************************************************
* File Name: NGreen.c  
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
#include "NGreen.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        NGreen_PC =   (NGreen_PC & \
                                (uint32)(~(uint32)(NGreen_DRIVE_MODE_IND_MASK << (NGreen_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (NGreen_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: NGreen_Write
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
void NGreen_Write(uint8 value) 
{
    uint8 drVal = (uint8)(NGreen_DR & (uint8)(~NGreen_MASK));
    drVal = (drVal | ((uint8)(value << NGreen_SHIFT) & NGreen_MASK));
    NGreen_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: NGreen_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  NGreen_DM_STRONG     Strong Drive 
*  NGreen_DM_OD_HI      Open Drain, Drives High 
*  NGreen_DM_OD_LO      Open Drain, Drives Low 
*  NGreen_DM_RES_UP     Resistive Pull Up 
*  NGreen_DM_RES_DWN    Resistive Pull Down 
*  NGreen_DM_RES_UPDWN  Resistive Pull Up/Down 
*  NGreen_DM_DIG_HIZ    High Impedance Digital 
*  NGreen_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void NGreen_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(NGreen__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: NGreen_Read
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
*  Macro NGreen_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 NGreen_Read(void) 
{
    return (uint8)((NGreen_PS & NGreen_MASK) >> NGreen_SHIFT);
}


/*******************************************************************************
* Function Name: NGreen_ReadDataReg
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
uint8 NGreen_ReadDataReg(void) 
{
    return (uint8)((NGreen_DR & NGreen_MASK) >> NGreen_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(NGreen_INTSTAT) 

    /*******************************************************************************
    * Function Name: NGreen_ClearInterrupt
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
    uint8 NGreen_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(NGreen_INTSTAT & NGreen_MASK);
		NGreen_INTSTAT = maskedStatus;
        return maskedStatus >> NGreen_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
