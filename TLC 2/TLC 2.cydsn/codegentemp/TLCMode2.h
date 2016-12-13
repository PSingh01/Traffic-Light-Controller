/*******************************************************************************
* File Name: TLCMode2.h  
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

#if !defined(CY_PINS_TLCMode2_H) /* Pins TLCMode2_H */
#define CY_PINS_TLCMode2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "TLCMode2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    TLCMode2_Write(uint8 value) ;
void    TLCMode2_SetDriveMode(uint8 mode) ;
uint8   TLCMode2_ReadDataReg(void) ;
uint8   TLCMode2_Read(void) ;
uint8   TLCMode2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TLCMode2_DRIVE_MODE_BITS        (3)
#define TLCMode2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - TLCMode2_DRIVE_MODE_BITS))

#define TLCMode2_DM_ALG_HIZ         (0x00u)
#define TLCMode2_DM_DIG_HIZ         (0x01u)
#define TLCMode2_DM_RES_UP          (0x02u)
#define TLCMode2_DM_RES_DWN         (0x03u)
#define TLCMode2_DM_OD_LO           (0x04u)
#define TLCMode2_DM_OD_HI           (0x05u)
#define TLCMode2_DM_STRONG          (0x06u)
#define TLCMode2_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define TLCMode2_MASK               TLCMode2__MASK
#define TLCMode2_SHIFT              TLCMode2__SHIFT
#define TLCMode2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TLCMode2_PS                     (* (reg32 *) TLCMode2__PS)
/* Port Configuration */
#define TLCMode2_PC                     (* (reg32 *) TLCMode2__PC)
/* Data Register */
#define TLCMode2_DR                     (* (reg32 *) TLCMode2__DR)
/* Input Buffer Disable Override */
#define TLCMode2_INP_DIS                (* (reg32 *) TLCMode2__PC2)


#if defined(TLCMode2__INTSTAT)  /* Interrupt Registers */

    #define TLCMode2_INTSTAT                (* (reg32 *) TLCMode2__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define TLCMode2_DRIVE_MODE_SHIFT       (0x00u)
#define TLCMode2_DRIVE_MODE_MASK        (0x07u << TLCMode2_DRIVE_MODE_SHIFT)


#endif /* End Pins TLCMode2_H */


/* [] END OF FILE */
