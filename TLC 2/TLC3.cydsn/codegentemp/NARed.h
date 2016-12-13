/*******************************************************************************
* File Name: NARed.h  
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

#if !defined(CY_PINS_NARed_H) /* Pins NARed_H */
#define CY_PINS_NARed_H

#include "cytypes.h"
#include "cyfitter.h"
#include "NARed_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    NARed_Write(uint8 value) ;
void    NARed_SetDriveMode(uint8 mode) ;
uint8   NARed_ReadDataReg(void) ;
uint8   NARed_Read(void) ;
uint8   NARed_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define NARed_DRIVE_MODE_BITS        (3)
#define NARed_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - NARed_DRIVE_MODE_BITS))

#define NARed_DM_ALG_HIZ         (0x00u)
#define NARed_DM_DIG_HIZ         (0x01u)
#define NARed_DM_RES_UP          (0x02u)
#define NARed_DM_RES_DWN         (0x03u)
#define NARed_DM_OD_LO           (0x04u)
#define NARed_DM_OD_HI           (0x05u)
#define NARed_DM_STRONG          (0x06u)
#define NARed_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define NARed_MASK               NARed__MASK
#define NARed_SHIFT              NARed__SHIFT
#define NARed_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NARed_PS                     (* (reg32 *) NARed__PS)
/* Port Configuration */
#define NARed_PC                     (* (reg32 *) NARed__PC)
/* Data Register */
#define NARed_DR                     (* (reg32 *) NARed__DR)
/* Input Buffer Disable Override */
#define NARed_INP_DIS                (* (reg32 *) NARed__PC2)


#if defined(NARed__INTSTAT)  /* Interrupt Registers */

    #define NARed_INTSTAT                (* (reg32 *) NARed__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define NARed_DRIVE_MODE_SHIFT       (0x00u)
#define NARed_DRIVE_MODE_MASK        (0x07u << NARed_DRIVE_MODE_SHIFT)


#endif /* End Pins NARed_H */


/* [] END OF FILE */
