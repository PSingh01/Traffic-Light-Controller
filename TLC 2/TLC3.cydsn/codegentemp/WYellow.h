/*******************************************************************************
* File Name: WYellow.h  
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

#if !defined(CY_PINS_WYellow_H) /* Pins WYellow_H */
#define CY_PINS_WYellow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "WYellow_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    WYellow_Write(uint8 value) ;
void    WYellow_SetDriveMode(uint8 mode) ;
uint8   WYellow_ReadDataReg(void) ;
uint8   WYellow_Read(void) ;
uint8   WYellow_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define WYellow_DRIVE_MODE_BITS        (3)
#define WYellow_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - WYellow_DRIVE_MODE_BITS))

#define WYellow_DM_ALG_HIZ         (0x00u)
#define WYellow_DM_DIG_HIZ         (0x01u)
#define WYellow_DM_RES_UP          (0x02u)
#define WYellow_DM_RES_DWN         (0x03u)
#define WYellow_DM_OD_LO           (0x04u)
#define WYellow_DM_OD_HI           (0x05u)
#define WYellow_DM_STRONG          (0x06u)
#define WYellow_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define WYellow_MASK               WYellow__MASK
#define WYellow_SHIFT              WYellow__SHIFT
#define WYellow_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define WYellow_PS                     (* (reg32 *) WYellow__PS)
/* Port Configuration */
#define WYellow_PC                     (* (reg32 *) WYellow__PC)
/* Data Register */
#define WYellow_DR                     (* (reg32 *) WYellow__DR)
/* Input Buffer Disable Override */
#define WYellow_INP_DIS                (* (reg32 *) WYellow__PC2)


#if defined(WYellow__INTSTAT)  /* Interrupt Registers */

    #define WYellow_INTSTAT                (* (reg32 *) WYellow__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define WYellow_DRIVE_MODE_SHIFT       (0x00u)
#define WYellow_DRIVE_MODE_MASK        (0x07u << WYellow_DRIVE_MODE_SHIFT)


#endif /* End Pins WYellow_H */


/* [] END OF FILE */
