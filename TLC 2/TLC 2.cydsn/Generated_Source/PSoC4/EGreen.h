/*******************************************************************************
* File Name: EGreen.h  
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

#if !defined(CY_PINS_EGreen_H) /* Pins EGreen_H */
#define CY_PINS_EGreen_H

#include "cytypes.h"
#include "cyfitter.h"
#include "EGreen_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    EGreen_Write(uint8 value) ;
void    EGreen_SetDriveMode(uint8 mode) ;
uint8   EGreen_ReadDataReg(void) ;
uint8   EGreen_Read(void) ;
uint8   EGreen_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EGreen_DRIVE_MODE_BITS        (3)
#define EGreen_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - EGreen_DRIVE_MODE_BITS))

#define EGreen_DM_ALG_HIZ         (0x00u)
#define EGreen_DM_DIG_HIZ         (0x01u)
#define EGreen_DM_RES_UP          (0x02u)
#define EGreen_DM_RES_DWN         (0x03u)
#define EGreen_DM_OD_LO           (0x04u)
#define EGreen_DM_OD_HI           (0x05u)
#define EGreen_DM_STRONG          (0x06u)
#define EGreen_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define EGreen_MASK               EGreen__MASK
#define EGreen_SHIFT              EGreen__SHIFT
#define EGreen_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EGreen_PS                     (* (reg32 *) EGreen__PS)
/* Port Configuration */
#define EGreen_PC                     (* (reg32 *) EGreen__PC)
/* Data Register */
#define EGreen_DR                     (* (reg32 *) EGreen__DR)
/* Input Buffer Disable Override */
#define EGreen_INP_DIS                (* (reg32 *) EGreen__PC2)


#if defined(EGreen__INTSTAT)  /* Interrupt Registers */

    #define EGreen_INTSTAT                (* (reg32 *) EGreen__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define EGreen_DRIVE_MODE_SHIFT       (0x00u)
#define EGreen_DRIVE_MODE_MASK        (0x07u << EGreen_DRIVE_MODE_SHIFT)


#endif /* End Pins EGreen_H */


/* [] END OF FILE */
