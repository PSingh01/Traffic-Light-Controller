/*******************************************************************************
* File Name: TLCMode.h  
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

#if !defined(CY_PINS_TLCMode_H) /* Pins TLCMode_H */
#define CY_PINS_TLCMode_H

#include "cytypes.h"
#include "cyfitter.h"
#include "TLCMode_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    TLCMode_Write(uint8 value) ;
void    TLCMode_SetDriveMode(uint8 mode) ;
uint8   TLCMode_ReadDataReg(void) ;
uint8   TLCMode_Read(void) ;
uint8   TLCMode_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TLCMode_DRIVE_MODE_BITS        (3)
#define TLCMode_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - TLCMode_DRIVE_MODE_BITS))

#define TLCMode_DM_ALG_HIZ         (0x00u)
#define TLCMode_DM_DIG_HIZ         (0x01u)
#define TLCMode_DM_RES_UP          (0x02u)
#define TLCMode_DM_RES_DWN         (0x03u)
#define TLCMode_DM_OD_LO           (0x04u)
#define TLCMode_DM_OD_HI           (0x05u)
#define TLCMode_DM_STRONG          (0x06u)
#define TLCMode_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define TLCMode_MASK               TLCMode__MASK
#define TLCMode_SHIFT              TLCMode__SHIFT
#define TLCMode_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TLCMode_PS                     (* (reg32 *) TLCMode__PS)
/* Port Configuration */
#define TLCMode_PC                     (* (reg32 *) TLCMode__PC)
/* Data Register */
#define TLCMode_DR                     (* (reg32 *) TLCMode__DR)
/* Input Buffer Disable Override */
#define TLCMode_INP_DIS                (* (reg32 *) TLCMode__PC2)


#if defined(TLCMode__INTSTAT)  /* Interrupt Registers */

    #define TLCMode_INTSTAT                (* (reg32 *) TLCMode__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define TLCMode_DRIVE_MODE_SHIFT       (0x00u)
#define TLCMode_DRIVE_MODE_MASK        (0x07u << TLCMode_DRIVE_MODE_SHIFT)


#endif /* End Pins TLCMode_H */


/* [] END OF FILE */
