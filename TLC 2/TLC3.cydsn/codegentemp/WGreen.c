/*******************************************************************************
* File Name: WGreen.c  
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
#include "WGreen.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        WGreen_PC =   (WGreen_PC & \
                                (uint32)(~(uint32)(WGreen_DRIVE_MODE_IND_MASK << (WGreen_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (WGreen_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: WGreen_Write
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
void WGreen_Write(uint8 value) 
{
    uint8 drVal = (uint8)(WGreen_DR & (uint8)(~WGreen_MASK));
    drVal = (drVal | ((uint8)(value << WGreen_SHIFT) & WGreen_MASK));
    WGreen_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: WGreen_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  WGreen_DM_STRONG     Strong Drive 
*  WGreen_DM_OD_HI      Open Drain, Drives High 
*  WGreen_DM_OD_LO      Open Drain, Drives Low 
*  WGreen_DM_RES_UP     Resistive Pull Up 
*  WGreen_DM_RES_DWN    Resistive Pull Down 
*  WGreen_DM_RES_UPDWN  Resistive Pull Up/Down 
*  WGreen_DM_DIG_HIZ    High Impedance Digital 
*  WGreen_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void WGreen_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(WGreen__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: WGreen_Read
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
*  Macro WGreen_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 WGreen_Read(void) 
{
    return (uint8)((WGreen_PS & WGreen_MASK) >> WGreen_SHIFT);
}


/*******************************************************************************
* Function Name: WGreen_ReadDataReg
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
uint8 WGreen_ReadDataReg(void) 
{
    return (uint8)((WGreen_DR & WGreen_MASK) >> WGreen_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(WGreen_INTSTAT) 

    /*******************************************************************************
    * Function Name: WGreen_ClearInterrupt
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
    uint8 WGreen_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(WGreen_INTSTAT & WGreen_MASK);
		WGreen_INTSTAT = maskedStatus;
        return maskedStatus >> WGreen_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
