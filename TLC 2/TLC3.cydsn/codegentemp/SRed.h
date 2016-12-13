/*******************************************************************************
* File Name: SRed.h  
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

#if !defined(CY_PINS_SRed_H) /* Pins SRed_H */
#define CY_PINS_SRed_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SRed_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SRed_Write(uint8 value) ;
void    SRed_SetDriveMode(uint8 mode) ;
uint8   SRed_ReadDataReg(void) ;
uint8   SRed_Read(void) ;
uint8   SRed_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SRed_DRIVE_MODE_BITS        (3)
#define SRed_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SRed_DRIVE_MODE_BITS))

#define SRed_DM_ALG_HIZ         (0x00u)
#define SRed_DM_DIG_HIZ         (0x01u)
#define SRed_DM_RES_UP          (0x02u)
#define SRed_DM_RES_DWN         (0x03u)
#define SRed_DM_OD_LO           (0x04u)
#define SRed_DM_OD_HI           (0x05u)
#define SRed_DM_STRONG          (0x06u)
#define SRed_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SRed_MASK               SRed__MASK
#define SRed_SHIFT              SRed__SHIFT
#define SRed_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SRed_PS                     (* (reg32 *) SRed__PS)
/* Port Configuration */
#define SRed_PC                     (* (reg32 *) SRed__PC)
/* Data Register */
#define SRed_DR                     (* (reg32 *) SRed__DR)
/* Input Buffer Disable Override */
#define SRed_INP_DIS                (* (reg32 *) SRed__PC2)


#if defined(SRed__INTSTAT)  /* Interrupt Registers */

    #define SRed_INTSTAT                (* (reg32 *) SRed__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SRed_DRIVE_MODE_SHIFT       (0x00u)
#define SRed_DRIVE_MODE_MASK        (0x07u << SRed_DRIVE_MODE_SHIFT)


#endif /* End Pins SRed_H */


/* [] END OF FILE */
