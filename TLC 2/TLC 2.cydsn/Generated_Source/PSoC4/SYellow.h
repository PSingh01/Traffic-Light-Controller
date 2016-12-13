/*******************************************************************************
* File Name: SYellow.h  
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

#if !defined(CY_PINS_SYellow_H) /* Pins SYellow_H */
#define CY_PINS_SYellow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SYellow_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SYellow_Write(uint8 value) ;
void    SYellow_SetDriveMode(uint8 mode) ;
uint8   SYellow_ReadDataReg(void) ;
uint8   SYellow_Read(void) ;
uint8   SYellow_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SYellow_DRIVE_MODE_BITS        (3)
#define SYellow_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SYellow_DRIVE_MODE_BITS))

#define SYellow_DM_ALG_HIZ         (0x00u)
#define SYellow_DM_DIG_HIZ         (0x01u)
#define SYellow_DM_RES_UP          (0x02u)
#define SYellow_DM_RES_DWN         (0x03u)
#define SYellow_DM_OD_LO           (0x04u)
#define SYellow_DM_OD_HI           (0x05u)
#define SYellow_DM_STRONG          (0x06u)
#define SYellow_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SYellow_MASK               SYellow__MASK
#define SYellow_SHIFT              SYellow__SHIFT
#define SYellow_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SYellow_PS                     (* (reg32 *) SYellow__PS)
/* Port Configuration */
#define SYellow_PC                     (* (reg32 *) SYellow__PC)
/* Data Register */
#define SYellow_DR                     (* (reg32 *) SYellow__DR)
/* Input Buffer Disable Override */
#define SYellow_INP_DIS                (* (reg32 *) SYellow__PC2)


#if defined(SYellow__INTSTAT)  /* Interrupt Registers */

    #define SYellow_INTSTAT                (* (reg32 *) SYellow__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SYellow_DRIVE_MODE_SHIFT       (0x00u)
#define SYellow_DRIVE_MODE_MASK        (0x07u << SYellow_DRIVE_MODE_SHIFT)


#endif /* End Pins SYellow_H */


/* [] END OF FILE */
