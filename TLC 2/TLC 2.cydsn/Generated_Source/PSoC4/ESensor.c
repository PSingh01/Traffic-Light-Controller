/*******************************************************************************
* File Name: ESensor.c  
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
#include "ESensor.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        ESensor_PC =   (ESensor_PC & \
                                (uint32)(~(uint32)(ESensor_DRIVE_MODE_IND_MASK << (ESensor_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (ESensor_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: ESensor_Write
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
void ESensor_Write(uint8 value) 
{
    uint8 drVal = (uint8)(ESensor_DR & (uint8)(~ESensor_MASK));
    drVal = (drVal | ((uint8)(value << ESensor_SHIFT) & ESensor_MASK));
    ESensor_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: ESensor_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ESensor_DM_STRONG     Strong Drive 
*  ESensor_DM_OD_HI      Open Drain, Drives High 
*  ESensor_DM_OD_LO      Open Drain, Drives Low 
*  ESensor_DM_RES_UP     Resistive Pull Up 
*  ESensor_DM_RES_DWN    Resistive Pull Down 
*  ESensor_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ESensor_DM_DIG_HIZ    High Impedance Digital 
*  ESensor_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ESensor_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(ESensor__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: ESensor_Read
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
*  Macro ESensor_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ESensor_Read(void) 
{
    return (uint8)((ESensor_PS & ESensor_MASK) >> ESensor_SHIFT);
}


/*******************************************************************************
* Function Name: ESensor_ReadDataReg
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
uint8 ESensor_ReadDataReg(void) 
{
    return (uint8)((ESensor_DR & ESensor_MASK) >> ESensor_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ESensor_INTSTAT) 

    /*******************************************************************************
    * Function Name: ESensor_ClearInterrupt
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
    uint8 ESensor_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(ESensor_INTSTAT & ESensor_MASK);
		ESensor_INTSTAT = maskedStatus;
        return maskedStatus >> ESensor_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
