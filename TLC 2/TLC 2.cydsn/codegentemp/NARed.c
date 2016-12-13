/*******************************************************************************
* File Name: NARed.c  
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
#include "NARed.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        NARed_PC =   (NARed_PC & \
                                (uint32)(~(uint32)(NARed_DRIVE_MODE_IND_MASK << (NARed_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (NARed_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: NARed_Write
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
void NARed_Write(uint8 value) 
{
    uint8 drVal = (uint8)(NARed_DR & (uint8)(~NARed_MASK));
    drVal = (drVal | ((uint8)(value << NARed_SHIFT) & NARed_MASK));
    NARed_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: NARed_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  NARed_DM_STRONG     Strong Drive 
*  NARed_DM_OD_HI      Open Drain, Drives High 
*  NARed_DM_OD_LO      Open Drain, Drives Low 
*  NARed_DM_RES_UP     Resistive Pull Up 
*  NARed_DM_RES_DWN    Resistive Pull Down 
*  NARed_DM_RES_UPDWN  Resistive Pull Up/Down 
*  NARed_DM_DIG_HIZ    High Impedance Digital 
*  NARed_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void NARed_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(NARed__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: NARed_Read
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
*  Macro NARed_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 NARed_Read(void) 
{
    return (uint8)((NARed_PS & NARed_MASK) >> NARed_SHIFT);
}


/*******************************************************************************
* Function Name: NARed_ReadDataReg
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
uint8 NARed_ReadDataReg(void) 
{
    return (uint8)((NARed_DR & NARed_MASK) >> NARed_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(NARed_INTSTAT) 

    /*******************************************************************************
    * Function Name: NARed_ClearInterrupt
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
    uint8 NARed_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(NARed_INTSTAT & NARed_MASK);
		NARed_INTSTAT = maskedStatus;
        return maskedStatus >> NARed_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
