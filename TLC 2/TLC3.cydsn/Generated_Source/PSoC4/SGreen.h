/*******************************************************************************
* File Name: SGreen.h  
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

#if !defined(CY_PINS_SGreen_H) /* Pins SGreen_H */
#define CY_PINS_SGreen_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SGreen_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SGreen_Write(uint8 value) ;
void    SGreen_SetDriveMode(uint8 mode) ;
uint8   SGreen_ReadDataReg(void) ;
uint8   SGreen_Read(void) ;
uint8   SGreen_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SGreen_DRIVE_MODE_BITS        (3)
#define SGreen_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SGreen_DRIVE_MODE_BITS))

#define SGreen_DM_ALG_HIZ         (0x00u)
#define SGreen_DM_DIG_HIZ         (0x01u)
#define SGreen_DM_RES_UP          (0x02u)
#define SGreen_DM_RES_DWN         (0x03u)
#define SGreen_DM_OD_LO           (0x04u)
#define SGreen_DM_OD_HI           (0x05u)
#define SGreen_DM_STRONG          (0x06u)
#define SGreen_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SGreen_MASK               SGreen__MASK
#define SGreen_SHIFT              SGreen__SHIFT
#define SGreen_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SGreen_PS                     (* (reg32 *) SGreen__PS)
/* Port Configuration */
#define SGreen_PC                     (* (reg32 *) SGreen__PC)
/* Data Register */
#define SGreen_DR                     (* (reg32 *) SGreen__DR)
/* Input Buffer Disable Override */
#define SGreen_INP_DIS                (* (reg32 *) SGreen__PC2)


#if defined(SGreen__INTSTAT)  /* Interrupt Registers */

    #define SGreen_INTSTAT                (* (reg32 *) SGreen__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SGreen_DRIVE_MODE_SHIFT       (0x00u)
#define SGreen_DRIVE_MODE_MASK        (0x07u << SGreen_DRIVE_MODE_SHIFT)


#endif /* End Pins SGreen_H */


/* [] END OF FILE */
