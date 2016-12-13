/*******************************************************************************
* File Name: EGreen.c  
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
#include "EGreen.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        EGreen_PC =   (EGreen_PC & \
                                (uint32)(~(uint32)(EGreen_DRIVE_MODE_IND_MASK << (EGreen_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (EGreen_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: EGreen_Write
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
void EGreen_Write(uint8 value) 
{
    uint8 drVal = (uint8)(EGreen_DR & (uint8)(~EGreen_MASK));
    drVal = (drVal | ((uint8)(value << EGreen_SHIFT) & EGreen_MASK));
    EGreen_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: EGreen_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  EGreen_DM_STRONG     Strong Drive 
*  EGreen_DM_OD_HI      Open Drain, Drives High 
*  EGreen_DM_OD_LO      Open Drain, Drives Low 
*  EGreen_DM_RES_UP     Resistive Pull Up 
*  EGreen_DM_RES_DWN    Resistive Pull Down 
*  EGreen_DM_RES_UPDWN  Resistive Pull Up/Down 
*  EGreen_DM_DIG_HIZ    High Impedance Digital 
*  EGreen_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void EGreen_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(EGreen__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: EGreen_Read
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
*  Macro EGreen_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 EGreen_Read(void) 
{
    return (uint8)((EGreen_PS & EGreen_MASK) >> EGreen_SHIFT);
}


/*******************************************************************************
* Function Name: EGreen_ReadDataReg
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
uint8 EGreen_ReadDataReg(void) 
{
    return (uint8)((EGreen_DR & EGreen_MASK) >> EGreen_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(EGreen_INTSTAT) 

    /*******************************************************************************
    * Function Name: EGreen_ClearInterrupt
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
    uint8 EGreen_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(EGreen_INTSTAT & EGreen_MASK);
		EGreen_INTSTAT = maskedStatus;
        return maskedStatus >> EGreen_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
