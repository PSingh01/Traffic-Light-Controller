/*******************************************************************************
* File Name: SYellow.c  
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
#include "SYellow.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        SYellow_PC =   (SYellow_PC & \
                                (uint32)(~(uint32)(SYellow_DRIVE_MODE_IND_MASK << (SYellow_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (SYellow_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: SYellow_Write
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
void SYellow_Write(uint8 value) 
{
    uint8 drVal = (uint8)(SYellow_DR & (uint8)(~SYellow_MASK));
    drVal = (drVal | ((uint8)(value << SYellow_SHIFT) & SYellow_MASK));
    SYellow_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: SYellow_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SYellow_DM_STRONG     Strong Drive 
*  SYellow_DM_OD_HI      Open Drain, Drives High 
*  SYellow_DM_OD_LO      Open Drain, Drives Low 
*  SYellow_DM_RES_UP     Resistive Pull Up 
*  SYellow_DM_RES_DWN    Resistive Pull Down 
*  SYellow_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SYellow_DM_DIG_HIZ    High Impedance Digital 
*  SYellow_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SYellow_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(SYellow__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: SYellow_Read
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
*  Macro SYellow_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SYellow_Read(void) 
{
    return (uint8)((SYellow_PS & SYellow_MASK) >> SYellow_SHIFT);
}


/*******************************************************************************
* Function Name: SYellow_ReadDataReg
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
uint8 SYellow_ReadDataReg(void) 
{
    return (uint8)((SYellow_DR & SYellow_MASK) >> SYellow_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SYellow_INTSTAT) 

    /*******************************************************************************
    * Function Name: SYellow_ClearInterrupt
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
    uint8 SYellow_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(SYellow_INTSTAT & SYellow_MASK);
		SYellow_INTSTAT = maskedStatus;
        return maskedStatus >> SYellow_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
