/*******************************************************************************
* File Name: NYellow.h  
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

#if !defined(CY_PINS_NYellow_H) /* Pins NYellow_H */
#define CY_PINS_NYellow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "NYellow_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    NYellow_Write(uint8 value) ;
void    NYellow_SetDriveMode(uint8 mode) ;
uint8   NYellow_ReadDataReg(void) ;
uint8   NYellow_Read(void) ;
uint8   NYellow_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define NYellow_DRIVE_MODE_BITS        (3)
#define NYellow_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - NYellow_DRIVE_MODE_BITS))

#define NYellow_DM_ALG_HIZ         (0x00u)
#define NYellow_DM_DIG_HIZ         (0x01u)
#define NYellow_DM_RES_UP          (0x02u)
#define NYellow_DM_RES_DWN         (0x03u)
#define NYellow_DM_OD_LO           (0x04u)
#define NYellow_DM_OD_HI           (0x05u)
#define NYellow_DM_STRONG          (0x06u)
#define NYellow_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define NYellow_MASK               NYellow__MASK
#define NYellow_SHIFT              NYellow__SHIFT
#define NYellow_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NYellow_PS                     (* (reg32 *) NYellow__PS)
/* Port Configuration */
#define NYellow_PC                     (* (reg32 *) NYellow__PC)
/* Data Register */
#define NYellow_DR                     (* (reg32 *) NYellow__DR)
/* Input Buffer Disable Override */
#define NYellow_INP_DIS                (* (reg32 *) NYellow__PC2)


#if defined(NYellow__INTSTAT)  /* Interrupt Registers */

    #define NYellow_INTSTAT                (* (reg32 *) NYellow__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define NYellow_DRIVE_MODE_SHIFT       (0x00u)
#define NYellow_DRIVE_MODE_MASK        (0x07u << NYellow_DRIVE_MODE_SHIFT)


#endif /* End Pins NYellow_H */


/* [] END OF FILE */
