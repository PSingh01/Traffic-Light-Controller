/*******************************************************************************
* File Name: SAGreen.h  
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

#if !defined(CY_PINS_SAGreen_H) /* Pins SAGreen_H */
#define CY_PINS_SAGreen_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SAGreen_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SAGreen_Write(uint8 value) ;
void    SAGreen_SetDriveMode(uint8 mode) ;
uint8   SAGreen_ReadDataReg(void) ;
uint8   SAGreen_Read(void) ;
uint8   SAGreen_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SAGreen_DRIVE_MODE_BITS        (3)
#define SAGreen_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SAGreen_DRIVE_MODE_BITS))

#define SAGreen_DM_ALG_HIZ         (0x00u)
#define SAGreen_DM_DIG_HIZ         (0x01u)
#define SAGreen_DM_RES_UP          (0x02u)
#define SAGreen_DM_RES_DWN         (0x03u)
#define SAGreen_DM_OD_LO           (0x04u)
#define SAGreen_DM_OD_HI           (0x05u)
#define SAGreen_DM_STRONG          (0x06u)
#define SAGreen_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SAGreen_MASK               SAGreen__MASK
#define SAGreen_SHIFT              SAGreen__SHIFT
#define SAGreen_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SAGreen_PS                     (* (reg32 *) SAGreen__PS)
/* Port Configuration */
#define SAGreen_PC                     (* (reg32 *) SAGreen__PC)
/* Data Register */
#define SAGreen_DR                     (* (reg32 *) SAGreen__DR)
/* Input Buffer Disable Override */
#define SAGreen_INP_DIS                (* (reg32 *) SAGreen__PC2)


#if defined(SAGreen__INTSTAT)  /* Interrupt Registers */

    #define SAGreen_INTSTAT                (* (reg32 *) SAGreen__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SAGreen_DRIVE_MODE_SHIFT       (0x00u)
#define SAGreen_DRIVE_MODE_MASK        (0x07u << SAGreen_DRIVE_MODE_SHIFT)


#endif /* End Pins SAGreen_H */


/* [] END OF FILE */
