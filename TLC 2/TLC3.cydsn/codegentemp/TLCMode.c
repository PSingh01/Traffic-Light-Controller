/*******************************************************************************
* File Name: TLCMode.c  
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
#include "TLCMode.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        TLCMode_PC =   (TLCMode_PC & \
                                (uint32)(~(uint32)(TLCMode_DRIVE_MODE_IND_MASK << (TLCMode_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (TLCMode_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: TLCMode_Write
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
void TLCMode_Write(uint8 value) 
{
    uint8 drVal = (uint8)(TLCMode_DR & (uint8)(~TLCMode_MASK));
    drVal = (drVal | ((uint8)(value << TLCMode_SHIFT) & TLCMode_MASK));
    TLCMode_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: TLCMode_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  TLCMode_DM_STRONG     Strong Drive 
*  TLCMode_DM_OD_HI      Open Drain, Drives High 
*  TLCMode_DM_OD_LO      Open Drain, Drives Low 
*  TLCMode_DM_RES_UP     Resistive Pull Up 
*  TLCMode_DM_RES_DWN    Resistive Pull Down 
*  TLCMode_DM_RES_UPDWN  Resistive Pull Up/Down 
*  TLCMode_DM_DIG_HIZ    High Impedance Digital 
*  TLCMode_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void TLCMode_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(TLCMode__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: TLCMode_Read
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
*  Macro TLCMode_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 TLCMode_Read(void) 
{
    return (uint8)((TLCMode_PS & TLCMode_MASK) >> TLCMode_SHIFT);
}


/*******************************************************************************
* Function Name: TLCMode_ReadDataReg
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
uint8 TLCMode_ReadDataReg(void) 
{
    return (uint8)((TLCMode_DR & TLCMode_MASK) >> TLCMode_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(TLCMode_INTSTAT) 

    /*******************************************************************************
    * Function Name: TLCMode_ClearInterrupt
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
    uint8 TLCMode_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(TLCMode_INTSTAT & TLCMode_MASK);
		TLCMode_INTSTAT = maskedStatus;
        return maskedStatus >> TLCMode_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */