/*******************************************************************************
* File Name: ESensor.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ESensor_H) /* Pins ESensor_H */
#define CY_PINS_ESensor_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ESensor_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ESensor_Write(uint8 value) ;
void    ESensor_SetDriveMode(uint8 mode) ;
uint8   ESensor_ReadDataReg(void) ;
uint8   ESensor_Read(void) ;
uint8   ESensor_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ESensor_DRIVE_MODE_BITS        (3)
#define ESensor_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ESensor_DRIVE_MODE_BITS))

#define ESensor_DM_ALG_HIZ         (0x00u)
#define ESensor_DM_DIG_HIZ         (0x01u)
#define ESensor_DM_RES_UP          (0x02u)
#define ESensor_DM_RES_DWN         (0x03u)
#define ESensor_DM_OD_LO           (0x04u)
#define ESensor_DM_OD_HI           (0x05u)
#define ESensor_DM_STRONG          (0x06u)
#define ESensor_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define ESensor_MASK               ESensor__MASK
#define ESensor_SHIFT              ESensor__SHIFT
#define ESensor_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ESensor_PS                     (* (reg32 *) ESensor__PS)
/* Port Configuration */
#define ESensor_PC                     (* (reg32 *) ESensor__PC)
/* Data Register */
#define ESensor_DR                     (* (reg32 *) ESensor__DR)
/* Input Buffer Disable Override */
#define ESensor_INP_DIS                (* (reg32 *) ESensor__PC2)


#if defined(ESensor__INTSTAT)  /* Interrupt Registers */

    #define ESensor_INTSTAT                (* (reg32 *) ESensor__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define ESensor_DRIVE_MODE_SHIFT       (0x00u)
#define ESensor_DRIVE_MODE_MASK        (0x07u << ESensor_DRIVE_MODE_SHIFT)


#endif /* End Pins ESensor_H */


/* [] END OF FILE */
