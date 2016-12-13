/*******************************************************************************
* File Name: NAYellow.h  
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

#if !defined(CY_PINS_NAYellow_H) /* Pins NAYellow_H */
#define CY_PINS_NAYellow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "NAYellow_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    NAYellow_Write(uint8 value) ;
void    NAYellow_SetDriveMode(uint8 mode) ;
uint8   NAYellow_ReadDataReg(void) ;
uint8   NAYellow_Read(void) ;
uint8   NAYellow_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define NAYellow_DRIVE_MODE_BITS        (3)
#define NAYellow_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - NAYellow_DRIVE_MODE_BITS))

#define NAYellow_DM_ALG_HIZ         (0x00u)
#define NAYellow_DM_DIG_HIZ         (0x01u)
#define NAYellow_DM_RES_UP          (0x02u)
#define NAYellow_DM_RES_DWN         (0x03u)
#define NAYellow_DM_OD_LO           (0x04u)
#define NAYellow_DM_OD_HI           (0x05u)
#define NAYellow_DM_STRONG          (0x06u)
#define NAYellow_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define NAYellow_MASK               NAYellow__MASK
#define NAYellow_SHIFT              NAYellow__SHIFT
#define NAYellow_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NAYellow_PS                     (* (reg32 *) NAYellow__PS)
/* Port Configuration */
#define NAYellow_PC                     (* (reg32 *) NAYellow__PC)
/* Data Register */
#define NAYellow_DR                     (* (reg32 *) NAYellow__DR)
/* Input Buffer Disable Override */
#define NAYellow_INP_DIS                (* (reg32 *) NAYellow__PC2)


#if defined(NAYellow__INTSTAT)  /* Interrupt Registers */

    #define NAYellow_INTSTAT                (* (reg32 *) NAYellow__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define NAYellow_DRIVE_MODE_SHIFT       (0x00u)
#define NAYellow_DRIVE_MODE_MASK        (0x07u << NAYellow_DRIVE_MODE_SHIFT)


#endif /* End Pins NAYellow_H */


/* [] END OF FILE */
