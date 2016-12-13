/*******************************************************************************
* File Name: NAGreen.h  
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

#if !defined(CY_PINS_NAGreen_H) /* Pins NAGreen_H */
#define CY_PINS_NAGreen_H

#include "cytypes.h"
#include "cyfitter.h"
#include "NAGreen_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    NAGreen_Write(uint8 value) ;
void    NAGreen_SetDriveMode(uint8 mode) ;
uint8   NAGreen_ReadDataReg(void) ;
uint8   NAGreen_Read(void) ;
uint8   NAGreen_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define NAGreen_DRIVE_MODE_BITS        (3)
#define NAGreen_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - NAGreen_DRIVE_MODE_BITS))

#define NAGreen_DM_ALG_HIZ         (0x00u)
#define NAGreen_DM_DIG_HIZ         (0x01u)
#define NAGreen_DM_RES_UP          (0x02u)
#define NAGreen_DM_RES_DWN         (0x03u)
#define NAGreen_DM_OD_LO           (0x04u)
#define NAGreen_DM_OD_HI           (0x05u)
#define NAGreen_DM_STRONG          (0x06u)
#define NAGreen_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define NAGreen_MASK               NAGreen__MASK
#define NAGreen_SHIFT              NAGreen__SHIFT
#define NAGreen_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NAGreen_PS                     (* (reg32 *) NAGreen__PS)
/* Port Configuration */
#define NAGreen_PC                     (* (reg32 *) NAGreen__PC)
/* Data Register */
#define NAGreen_DR                     (* (reg32 *) NAGreen__DR)
/* Input Buffer Disable Override */
#define NAGreen_INP_DIS                (* (reg32 *) NAGreen__PC2)


#if defined(NAGreen__INTSTAT)  /* Interrupt Registers */

    #define NAGreen_INTSTAT                (* (reg32 *) NAGreen__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define NAGreen_DRIVE_MODE_SHIFT       (0x00u)
#define NAGreen_DRIVE_MODE_MASK        (0x07u << NAGreen_DRIVE_MODE_SHIFT)


#endif /* End Pins NAGreen_H */


/* [] END OF FILE */
