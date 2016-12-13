/*******************************************************************************
* File Name: NASensor.h  
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

#if !defined(CY_PINS_NASensor_H) /* Pins NASensor_H */
#define CY_PINS_NASensor_H

#include "cytypes.h"
#include "cyfitter.h"
#include "NASensor_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    NASensor_Write(uint8 value) ;
void    NASensor_SetDriveMode(uint8 mode) ;
uint8   NASensor_ReadDataReg(void) ;
uint8   NASensor_Read(void) ;
uint8   NASensor_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define NASensor_DRIVE_MODE_BITS        (3)
#define NASensor_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - NASensor_DRIVE_MODE_BITS))

#define NASensor_DM_ALG_HIZ         (0x00u)
#define NASensor_DM_DIG_HIZ         (0x01u)
#define NASensor_DM_RES_UP          (0x02u)
#define NASensor_DM_RES_DWN         (0x03u)
#define NASensor_DM_OD_LO           (0x04u)
#define NASensor_DM_OD_HI           (0x05u)
#define NASensor_DM_STRONG          (0x06u)
#define NASensor_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define NASensor_MASK               NASensor__MASK
#define NASensor_SHIFT              NASensor__SHIFT
#define NASensor_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NASensor_PS                     (* (reg32 *) NASensor__PS)
/* Port Configuration */
#define NASensor_PC                     (* (reg32 *) NASensor__PC)
/* Data Register */
#define NASensor_DR                     (* (reg32 *) NASensor__DR)
/* Input Buffer Disable Override */
#define NASensor_INP_DIS                (* (reg32 *) NASensor__PC2)


#if defined(NASensor__INTSTAT)  /* Interrupt Registers */

    #define NASensor_INTSTAT                (* (reg32 *) NASensor__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define NASensor_DRIVE_MODE_SHIFT       (0x00u)
#define NASensor_DRIVE_MODE_MASK        (0x07u << NASensor_DRIVE_MODE_SHIFT)


#endif /* End Pins NASensor_H */


/* [] END OF FILE */
