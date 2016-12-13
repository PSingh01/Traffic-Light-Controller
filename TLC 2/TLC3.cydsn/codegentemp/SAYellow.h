/*******************************************************************************
* File Name: SAYellow.h  
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

#if !defined(CY_PINS_SAYellow_H) /* Pins SAYellow_H */
#define CY_PINS_SAYellow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SAYellow_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SAYellow_Write(uint8 value) ;
void    SAYellow_SetDriveMode(uint8 mode) ;
uint8   SAYellow_ReadDataReg(void) ;
uint8   SAYellow_Read(void) ;
uint8   SAYellow_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SAYellow_DRIVE_MODE_BITS        (3)
#define SAYellow_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SAYellow_DRIVE_MODE_BITS))

#define SAYellow_DM_ALG_HIZ         (0x00u)
#define SAYellow_DM_DIG_HIZ         (0x01u)
#define SAYellow_DM_RES_UP          (0x02u)
#define SAYellow_DM_RES_DWN         (0x03u)
#define SAYellow_DM_OD_LO           (0x04u)
#define SAYellow_DM_OD_HI           (0x05u)
#define SAYellow_DM_STRONG          (0x06u)
#define SAYellow_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SAYellow_MASK               SAYellow__MASK
#define SAYellow_SHIFT              SAYellow__SHIFT
#define SAYellow_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SAYellow_PS                     (* (reg32 *) SAYellow__PS)
/* Port Configuration */
#define SAYellow_PC                     (* (reg32 *) SAYellow__PC)
/* Data Register */
#define SAYellow_DR                     (* (reg32 *) SAYellow__DR)
/* Input Buffer Disable Override */
#define SAYellow_INP_DIS                (* (reg32 *) SAYellow__PC2)


#if defined(SAYellow__INTSTAT)  /* Interrupt Registers */

    #define SAYellow_INTSTAT                (* (reg32 *) SAYellow__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SAYellow_DRIVE_MODE_SHIFT       (0x00u)
#define SAYellow_DRIVE_MODE_MASK        (0x07u << SAYellow_DRIVE_MODE_SHIFT)


#endif /* End Pins SAYellow_H */


/* [] END OF FILE */
