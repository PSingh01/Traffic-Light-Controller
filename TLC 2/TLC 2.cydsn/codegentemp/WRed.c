/*******************************************************************************
* File Name: WRed.c  
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
#include "WRed.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        WRed_PC =   (WRed_PC & \
                                (uint32)(~(uint32)(WRed_DRIVE_MODE_IND_MASK << (WRed_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (WRed_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: WRed_Write
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
void WRed_Write(uint8 value) 
{
    uint8 drVal = (uint8)(WRed_DR & (uint8)(~WRed_MASK));
    drVal = (drVal | ((uint8)(value << WRed_SHIFT) & WRed_MASK));
    WRed_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: WRed_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  WRed_DM_STRONG     Strong Drive 
*  WRed_DM_OD_HI      Open Drain, Drives High 
*  WRed_DM_OD_LO      Open Drain, Drives Low 
*  WRed_DM_RES_UP     Resistive Pull Up 
*  WRed_DM_RES_DWN    Resistive Pull Down 
*  WRed_DM_RES_UPDWN  Resistive Pull Up/Down 
*  WRed_DM_DIG_HIZ    High Impedance Digital 
*  WRed_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void WRed_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(WRed__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: WRed_Read
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
*  Macro WRed_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 WRed_Read(void) 
{
    return (uint8)((WRed_PS & WRed_MASK) >> WRed_SHIFT);
}


/*******************************************************************************
* Function Name: WRed_ReadDataReg
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
uint8 WRed_ReadDataReg(void) 
{
    return (uint8)((WRed_DR & WRed_MASK) >> WRed_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(WRed_INTSTAT) 

    /*******************************************************************************
    * Function Name: WRed_ClearInterrupt
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
    uint8 WRed_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(WRed_INTSTAT & WRed_MASK);
		WRed_INTSTAT = maskedStatus;
        return maskedStatus >> WRed_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
