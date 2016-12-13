/*******************************************************************************
* File Name: NASensor.c  
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
#include "NASensor.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        NASensor_PC =   (NASensor_PC & \
                                (uint32)(~(uint32)(NASensor_DRIVE_MODE_IND_MASK << (NASensor_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (NASensor_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: NASensor_Write
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
void NASensor_Write(uint8 value) 
{
    uint8 drVal = (uint8)(NASensor_DR & (uint8)(~NASensor_MASK));
    drVal = (drVal | ((uint8)(value << NASensor_SHIFT) & NASensor_MASK));
    NASensor_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: NASensor_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  NASensor_DM_STRONG     Strong Drive 
*  NASensor_DM_OD_HI      Open Drain, Drives High 
*  NASensor_DM_OD_LO      Open Drain, Drives Low 
*  NASensor_DM_RES_UP     Resistive Pull Up 
*  NASensor_DM_RES_DWN    Resistive Pull Down 
*  NASensor_DM_RES_UPDWN  Resistive Pull Up/Down 
*  NASensor_DM_DIG_HIZ    High Impedance Digital 
*  NASensor_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void NASensor_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(NASensor__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: NASensor_Read
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
*  Macro NASensor_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 NASensor_Read(void) 
{
    return (uint8)((NASensor_PS & NASensor_MASK) >> NASensor_SHIFT);
}


/*******************************************************************************
* Function Name: NASensor_ReadDataReg
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
uint8 NASensor_ReadDataReg(void) 
{
    return (uint8)((NASensor_DR & NASensor_MASK) >> NASensor_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(NASensor_INTSTAT) 

    /*******************************************************************************
    * Function Name: NASensor_ClearInterrupt
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
    uint8 NASensor_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(NASensor_INTSTAT & NASensor_MASK);
		NASensor_INTSTAT = maskedStatus;
        return maskedStatus >> NASensor_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
