/*******************************************************************************
* File Name: NGreen.h  
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

#if !defined(CY_PINS_NGreen_H) /* Pins NGreen_H */
#define CY_PINS_NGreen_H

#include "cytypes.h"
#include "cyfitter.h"
#include "NGreen_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    NGreen_Write(uint8 value) ;
void    NGreen_SetDriveMode(uint8 mode) ;
uint8   NGreen_ReadDataReg(void) ;
uint8   NGreen_Read(void) ;
uint8   NGreen_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define NGreen_DRIVE_MODE_BITS        (3)
#define NGreen_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - NGreen_DRIVE_MODE_BITS))

#define NGreen_DM_ALG_HIZ         (0x00u)
#define NGreen_DM_DIG_HIZ         (0x01u)
#define NGreen_DM_RES_UP          (0x02u)
#define NGreen_DM_RES_DWN         (0x03u)
#define NGreen_DM_OD_LO           (0x04u)
#define NGreen_DM_OD_HI           (0x05u)
#define NGreen_DM_STRONG          (0x06u)
#define NGreen_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define NGreen_MASK               NGreen__MASK
#define NGreen_SHIFT              NGreen__SHIFT
#define NGreen_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NGreen_PS                     (* (reg32 *) NGreen__PS)
/* Port Configuration */
#define NGreen_PC                     (* (reg32 *) NGreen__PC)
/* Data Register */
#define NGreen_DR                     (* (reg32 *) NGreen__DR)
/* Input Buffer Disable Override */
#define NGreen_INP_DIS                (* (reg32 *) NGreen__PC2)


#if defined(NGreen__INTSTAT)  /* Interrupt Registers */

    #define NGreen_INTSTAT                (* (reg32 *) NGreen__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define NGreen_DRIVE_MODE_SHIFT       (0x00u)
#define NGreen_DRIVE_MODE_MASK        (0x07u << NGreen_DRIVE_MODE_SHIFT)


#endif /* End Pins NGreen_H */


/* [] END OF FILE */
