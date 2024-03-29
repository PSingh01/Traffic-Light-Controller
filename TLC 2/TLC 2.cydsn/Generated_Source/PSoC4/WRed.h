/*******************************************************************************
* File Name: WRed.h  
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

#if !defined(CY_PINS_WRed_H) /* Pins WRed_H */
#define CY_PINS_WRed_H

#include "cytypes.h"
#include "cyfitter.h"
#include "WRed_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    WRed_Write(uint8 value) ;
void    WRed_SetDriveMode(uint8 mode) ;
uint8   WRed_ReadDataReg(void) ;
uint8   WRed_Read(void) ;
uint8   WRed_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define WRed_DRIVE_MODE_BITS        (3)
#define WRed_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - WRed_DRIVE_MODE_BITS))

#define WRed_DM_ALG_HIZ         (0x00u)
#define WRed_DM_DIG_HIZ         (0x01u)
#define WRed_DM_RES_UP          (0x02u)
#define WRed_DM_RES_DWN         (0x03u)
#define WRed_DM_OD_LO           (0x04u)
#define WRed_DM_OD_HI           (0x05u)
#define WRed_DM_STRONG          (0x06u)
#define WRed_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define WRed_MASK               WRed__MASK
#define WRed_SHIFT              WRed__SHIFT
#define WRed_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define WRed_PS                     (* (reg32 *) WRed__PS)
/* Port Configuration */
#define WRed_PC                     (* (reg32 *) WRed__PC)
/* Data Register */
#define WRed_DR                     (* (reg32 *) WRed__DR)
/* Input Buffer Disable Override */
#define WRed_INP_DIS                (* (reg32 *) WRed__PC2)


#if defined(WRed__INTSTAT)  /* Interrupt Registers */

    #define WRed_INTSTAT                (* (reg32 *) WRed__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define WRed_DRIVE_MODE_SHIFT       (0x00u)
#define WRed_DRIVE_MODE_MASK        (0x07u << WRed_DRIVE_MODE_SHIFT)


#endif /* End Pins WRed_H */


/* [] END OF FILE */
