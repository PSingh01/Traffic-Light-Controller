/*******************************************************************************
* File Name: EYellow.h  
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

#if !defined(CY_PINS_EYellow_H) /* Pins EYellow_H */
#define CY_PINS_EYellow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "EYellow_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    EYellow_Write(uint8 value) ;
void    EYellow_SetDriveMode(uint8 mode) ;
uint8   EYellow_ReadDataReg(void) ;
uint8   EYellow_Read(void) ;
uint8   EYellow_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EYellow_DRIVE_MODE_BITS        (3)
#define EYellow_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - EYellow_DRIVE_MODE_BITS))

#define EYellow_DM_ALG_HIZ         (0x00u)
#define EYellow_DM_DIG_HIZ         (0x01u)
#define EYellow_DM_RES_UP          (0x02u)
#define EYellow_DM_RES_DWN         (0x03u)
#define EYellow_DM_OD_LO           (0x04u)
#define EYellow_DM_OD_HI           (0x05u)
#define EYellow_DM_STRONG          (0x06u)
#define EYellow_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define EYellow_MASK               EYellow__MASK
#define EYellow_SHIFT              EYellow__SHIFT
#define EYellow_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EYellow_PS                     (* (reg32 *) EYellow__PS)
/* Port Configuration */
#define EYellow_PC                     (* (reg32 *) EYellow__PC)
/* Data Register */
#define EYellow_DR                     (* (reg32 *) EYellow__DR)
/* Input Buffer Disable Override */
#define EYellow_INP_DIS                (* (reg32 *) EYellow__PC2)


#if defined(EYellow__INTSTAT)  /* Interrupt Registers */

    #define EYellow_INTSTAT                (* (reg32 *) EYellow__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define EYellow_DRIVE_MODE_SHIFT       (0x00u)
#define EYellow_DRIVE_MODE_MASK        (0x07u << EYellow_DRIVE_MODE_SHIFT)


#endif /* End Pins EYellow_H */


/* [] END OF FILE */
