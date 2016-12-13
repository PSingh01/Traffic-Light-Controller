/*******************************************************************************
* File Name: WYellow.c  
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
#include "WYellow.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        WYellow_PC =   (WYellow_PC & \
                                (uint32)(~(uint32)(WYellow_DRIVE_MODE_IND_MASK << (WYellow_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (WYellow_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: WYellow_Write
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
void WYellow_Write(uint8 value) 
{
    uint8 drVal = (uint8)(WYellow_DR & (uint8)(~WYellow_MASK));
    drVal = (drVal | ((uint8)(value << WYellow_SHIFT) & WYellow_MASK));
    WYellow_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: WYellow_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  WYellow_DM_STRONG     Strong Drive 
*  WYellow_DM_OD_HI      Open Drain, Drives High 
*  WYellow_DM_OD_LO      Open Drain, Drives Low 
*  WYellow_DM_RES_UP     Resistive Pull Up 
*  WYellow_DM_RES_DWN    Resistive Pull Down 
*  WYellow_DM_RES_UPDWN  Resistive Pull Up/Down 
*  WYellow_DM_DIG_HIZ    High Impedance Digital 
*  WYellow_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void WYellow_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(WYellow__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: WYellow_Read
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
*  Macro WYellow_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 WYellow_Read(void) 
{
    return (uint8)((WYellow_PS & WYellow_MASK) >> WYellow_SHIFT);
}


/*******************************************************************************
* Function Name: WYellow_ReadDataReg
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
uint8 WYellow_ReadDataReg(void) 
{
    return (uint8)((WYellow_DR & WYellow_MASK) >> WYellow_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(WYellow_INTSTAT) 

    /*******************************************************************************
    * Function Name: WYellow_ClearInterrupt
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
    uint8 WYellow_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(WYellow_INTSTAT & WYellow_MASK);
		WYellow_INTSTAT = maskedStatus;
        return maskedStatus >> WYellow_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
