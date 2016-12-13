/*******************************************************************************
* File Name: NRed.h  
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

#if !defined(CY_PINS_NRed_H) /* Pins NRed_H */
#define CY_PINS_NRed_H

#include "cytypes.h"
#include "cyfitter.h"
#include "NRed_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    NRed_Write(uint8 value) ;
void    NRed_SetDriveMode(uint8 mode) ;
uint8   NRed_ReadDataReg(void) ;
uint8   NRed_Read(void) ;
uint8   NRed_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define NRed_DRIVE_MODE_BITS        (3)
#define NRed_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - NRed_DRIVE_MODE_BITS))

#define NRed_DM_ALG_HIZ         (0x00u)
#define NRed_DM_DIG_HIZ         (0x01u)
#define NRed_DM_RES_UP          (0x02u)
#define NRed_DM_RES_DWN         (0x03u)
#define NRed_DM_OD_LO           (0x04u)
#define NRed_DM_OD_HI           (0x05u)
#define NRed_DM_STRONG          (0x06u)
#define NRed_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define NRed_MASK               NRed__MASK
#define NRed_SHIFT              NRed__SHIFT
#define NRed_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NRed_PS                     (* (reg32 *) NRed__PS)
/* Port Configuration */
#define NRed_PC                     (* (reg32 *) NRed__PC)
/* Data Register */
#define NRed_DR                     (* (reg32 *) NRed__DR)
/* Input Buffer Disable Override */
#define NRed_INP_DIS                (* (reg32 *) NRed__PC2)


#if defined(NRed__INTSTAT)  /* Interrupt Registers */

    #define NRed_INTSTAT                (* (reg32 *) NRed__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define NRed_DRIVE_MODE_SHIFT       (0x00u)
#define NRed_DRIVE_MODE_MASK        (0x07u << NRed_DRIVE_MODE_SHIFT)


#endif /* End Pins NRed_H */


/* [] END OF FILE */
