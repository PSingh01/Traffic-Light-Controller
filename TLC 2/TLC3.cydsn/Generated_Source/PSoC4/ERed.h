/*******************************************************************************
* File Name: ERed.h  
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

#if !defined(CY_PINS_ERed_H) /* Pins ERed_H */
#define CY_PINS_ERed_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ERed_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ERed_Write(uint8 value) ;
void    ERed_SetDriveMode(uint8 mode) ;
uint8   ERed_ReadDataReg(void) ;
uint8   ERed_Read(void) ;
uint8   ERed_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ERed_DRIVE_MODE_BITS        (3)
#define ERed_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ERed_DRIVE_MODE_BITS))

#define ERed_DM_ALG_HIZ         (0x00u)
#define ERed_DM_DIG_HIZ         (0x01u)
#define ERed_DM_RES_UP          (0x02u)
#define ERed_DM_RES_DWN         (0x03u)
#define ERed_DM_OD_LO           (0x04u)
#define ERed_DM_OD_HI           (0x05u)
#define ERed_DM_STRONG          (0x06u)
#define ERed_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define ERed_MASK               ERed__MASK
#define ERed_SHIFT              ERed__SHIFT
#define ERed_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ERed_PS                     (* (reg32 *) ERed__PS)
/* Port Configuration */
#define ERed_PC                     (* (reg32 *) ERed__PC)
/* Data Register */
#define ERed_DR                     (* (reg32 *) ERed__DR)
/* Input Buffer Disable Override */
#define ERed_INP_DIS                (* (reg32 *) ERed__PC2)


#if defined(ERed__INTSTAT)  /* Interrupt Registers */

    #define ERed_INTSTAT                (* (reg32 *) ERed__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define ERed_DRIVE_MODE_SHIFT       (0x00u)
#define ERed_DRIVE_MODE_MASK        (0x07u << ERed_DRIVE_MODE_SHIFT)


#endif /* End Pins ERed_H */


/* [] END OF FILE */
