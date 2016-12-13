/*******************************************************************************
* File Name: WGreen.h  
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

#if !defined(CY_PINS_WGreen_H) /* Pins WGreen_H */
#define CY_PINS_WGreen_H

#include "cytypes.h"
#include "cyfitter.h"
#include "WGreen_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    WGreen_Write(uint8 value) ;
void    WGreen_SetDriveMode(uint8 mode) ;
uint8   WGreen_ReadDataReg(void) ;
uint8   WGreen_Read(void) ;
uint8   WGreen_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define WGreen_DRIVE_MODE_BITS        (3)
#define WGreen_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - WGreen_DRIVE_MODE_BITS))

#define WGreen_DM_ALG_HIZ         (0x00u)
#define WGreen_DM_DIG_HIZ         (0x01u)
#define WGreen_DM_RES_UP          (0x02u)
#define WGreen_DM_RES_DWN         (0x03u)
#define WGreen_DM_OD_LO           (0x04u)
#define WGreen_DM_OD_HI           (0x05u)
#define WGreen_DM_STRONG          (0x06u)
#define WGreen_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define WGreen_MASK               WGreen__MASK
#define WGreen_SHIFT              WGreen__SHIFT
#define WGreen_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define WGreen_PS                     (* (reg32 *) WGreen__PS)
/* Port Configuration */
#define WGreen_PC                     (* (reg32 *) WGreen__PC)
/* Data Register */
#define WGreen_DR                     (* (reg32 *) WGreen__DR)
/* Input Buffer Disable Override */
#define WGreen_INP_DIS                (* (reg32 *) WGreen__PC2)


#if defined(WGreen__INTSTAT)  /* Interrupt Registers */

    #define WGreen_INTSTAT                (* (reg32 *) WGreen__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define WGreen_DRIVE_MODE_SHIFT       (0x00u)
#define WGreen_DRIVE_MODE_MASK        (0x07u << WGreen_DRIVE_MODE_SHIFT)


#endif /* End Pins WGreen_H */


/* [] END OF FILE */
