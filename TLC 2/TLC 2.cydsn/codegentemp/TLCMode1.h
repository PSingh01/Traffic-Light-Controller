/*******************************************************************************
* File Name: TLCMode1.h  
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

#if !defined(CY_PINS_TLCMode1_H) /* Pins TLCMode1_H */
#define CY_PINS_TLCMode1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "TLCMode1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    TLCMode1_Write(uint8 value) ;
void    TLCMode1_SetDriveMode(uint8 mode) ;
uint8   TLCMode1_ReadDataReg(void) ;
uint8   TLCMode1_Read(void) ;
uint8   TLCMode1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TLCMode1_DRIVE_MODE_BITS        (3)
#define TLCMode1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - TLCMode1_DRIVE_MODE_BITS))

#define TLCMode1_DM_ALG_HIZ         (0x00u)
#define TLCMode1_DM_DIG_HIZ         (0x01u)
#define TLCMode1_DM_RES_UP          (0x02u)
#define TLCMode1_DM_RES_DWN         (0x03u)
#define TLCMode1_DM_OD_LO           (0x04u)
#define TLCMode1_DM_OD_HI           (0x05u)
#define TLCMode1_DM_STRONG          (0x06u)
#define TLCMode1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define TLCMode1_MASK               TLCMode1__MASK
#define TLCMode1_SHIFT              TLCMode1__SHIFT
#define TLCMode1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TLCMode1_PS                     (* (reg32 *) TLCMode1__PS)
/* Port Configuration */
#define TLCMode1_PC                     (* (reg32 *) TLCMode1__PC)
/* Data Register */
#define TLCMode1_DR                     (* (reg32 *) TLCMode1__DR)
/* Input Buffer Disable Override */
#define TLCMode1_INP_DIS                (* (reg32 *) TLCMode1__PC2)


#if defined(TLCMode1__INTSTAT)  /* Interrupt Registers */

    #define TLCMode1_INTSTAT                (* (reg32 *) TLCMode1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define TLCMode1_DRIVE_MODE_SHIFT       (0x00u)
#define TLCMode1_DRIVE_MODE_MASK        (0x07u << TLCMode1_DRIVE_MODE_SHIFT)


#endif /* End Pins TLCMode1_H */


/* [] END OF FILE */
