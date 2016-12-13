/*******************************************************************************
* File Name: SRed.c  
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
#include "SRed.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        SRed_PC =   (SRed_PC & \
                                (uint32)(~(uint32)(SRed_DRIVE_MODE_IND_MASK << (SRed_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (SRed_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: SRed_Write
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
void SRed_Write(uint8 value) 
{
    uint8 drVal = (uint8)(SRed_DR & (uint8)(~SRed_MASK));
    drVal = (drVal | ((uint8)(value << SRed_SHIFT) & SRed_MASK));
    SRed_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: SRed_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SRed_DM_STRONG     Strong Drive 
*  SRed_DM_OD_HI      Open Drain, Drives High 
*  SRed_DM_OD_LO      Open Drain, Drives Low 
*  SRed_DM_RES_UP     Resistive Pull Up 
*  SRed_DM_RES_DWN    Resistive Pull Down 
*  SRed_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SRed_DM_DIG_HIZ    High Impedance Digital 
*  SRed_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SRed_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(SRed__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: SRed_Read
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
*  Macro SRed_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SRed_Read(void) 
{
    return (uint8)((SRed_PS & SRed_MASK) >> SRed_SHIFT);
}


/*******************************************************************************
* Function Name: SRed_ReadDataReg
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
uint8 SRed_ReadDataReg(void) 
{
    return (uint8)((SRed_DR & SRed_MASK) >> SRed_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SRed_INTSTAT) 

    /*******************************************************************************
    * Function Name: SRed_ClearInterrupt
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
    uint8 SRed_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(SRed_INTSTAT & SRed_MASK);
		SRed_INTSTAT = maskedStatus;
        return maskedStatus >> SRed_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
