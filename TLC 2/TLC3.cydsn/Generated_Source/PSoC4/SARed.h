/*******************************************************************************
* File Name: SARed.h  
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

#if !defined(CY_PINS_SARed_H) /* Pins SARed_H */
#define CY_PINS_SARed_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SARed_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SARed_Write(uint8 value) ;
void    SARed_SetDriveMode(uint8 mode) ;
uint8   SARed_ReadDataReg(void) ;
uint8   SARed_Read(void) ;
uint8   SARed_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SARed_DRIVE_MODE_BITS        (3)
#define SARed_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SARed_DRIVE_MODE_BITS))

#define SARed_DM_ALG_HIZ         (0x00u)
#define SARed_DM_DIG_HIZ         (0x01u)
#define SARed_DM_RES_UP          (0x02u)
#define SARed_DM_RES_DWN         (0x03u)
#define SARed_DM_OD_LO           (0x04u)
#define SARed_DM_OD_HI           (0x05u)
#define SARed_DM_STRONG          (0x06u)
#define SARed_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SARed_MASK               SARed__MASK
#define SARed_SHIFT              SARed__SHIFT
#define SARed_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SARed_PS                     (* (reg32 *) SARed__PS)
/* Port Configuration */
#define SARed_PC                     (* (reg32 *) SARed__PC)
/* Data Register */
#define SARed_DR                     (* (reg32 *) SARed__DR)
/* Input Buffer Disable Override */
#define SARed_INP_DIS                (* (reg32 *) SARed__PC2)


#if defined(SARed__INTSTAT)  /* Interrupt Registers */

    #define SARed_INTSTAT                (* (reg32 *) SARed__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SARed_DRIVE_MODE_SHIFT       (0x00u)
#define SARed_DRIVE_MODE_MASK        (0x07u << SARed_DRIVE_MODE_SHIFT)


#endif /* End Pins SARed_H */


/* [] END OF FILE */
