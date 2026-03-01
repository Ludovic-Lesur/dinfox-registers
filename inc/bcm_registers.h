/*
 * bcm_registers.h
 *
 *  Created on: 27 mar. 2025
 *      Author: Ludo
 */

#ifndef __BCM_REGISTERS_H__
#define __BCM_REGISTERS_H__

#ifndef DINFOX_REGISTERS_DISABLE_FLAGS_FILE
#include "dinfox_registers_flags.h"
#endif
#include "common_registers.h"
#include "types.h"
#include "una.h"

/*** BCM REGISTERS structures ***/

/*!******************************************************************
 * \enum BCM_register_address_t
 * \brief BCM registers map.
 *******************************************************************/
typedef enum {
    BCM_REGISTER_ADDRESS_FLAGS_1 = COMMON_REGISTER_ADDRESS_LAST,
    BCM_REGISTER_ADDRESS_CONFIGURATION_0,
    BCM_REGISTER_ADDRESS_CONFIGURATION_1,
    BCM_REGISTER_ADDRESS_CONFIGURATION_2,
    BCM_REGISTER_ADDRESS_STATUS_1,
    BCM_REGISTER_ADDRESS_CONTROL_1,
    BCM_REGISTER_ADDRESS_ANALOG_DATA_1,
    BCM_REGISTER_ADDRESS_ANALOG_DATA_2,
    BCM_REGISTER_ADDRESS_LAST,
} BCM_register_address_t;

/*** BCM REGISTERS macros ***/

#define BCM_NUMBER_OF_SPECIFIC_REGISTERS                            (BCM_REGISTER_ADDRESS_LAST - COMMON_REGISTER_ADDRESS_LAST)

#define BCM_REGISTER_FLAGS_1_MASK_CCFH                              0x00000001
#define BCM_REGISTER_FLAGS_1_MASK_CSFH                              0x00000002
#define BCM_REGISTER_FLAGS_1_MASK_CLFH                              0x00000004
#define BCM_REGISTER_FLAGS_1_MASK_BKFH                              0x00000008
#define BCM_REGISTER_FLAGS_1_MASK_SHUNT_RESISTOR                    0x0000FF00

#define BCM_REGISTER_CONFIGURATION_0_MASK_CHARGE_SOURCE_VOLTAGE_TH  0x0000FFFF
#define BCM_REGISTER_CONFIGURATION_0_MASK_CHARGE_TOGGLE_PERIOD      0x00FF0000

#define BCM_REGISTER_CONFIGURATION_1_MASK_LVF_STORAGE_VOLTAGE_THL   0x0000FFFF
#define BCM_REGISTER_CONFIGURATION_1_MASK_LVF_STORAGE_VOLTAGE_THH   0xFFFF0000

#define BCM_REGISTER_CONFIGURATION_2_MASK_CVF_STORAGE_VOLTAGE_THL   0x0000FFFF
#define BCM_REGISTER_CONFIGURATION_2_MASK_CVF_STORAGE_VOLTAGE_THH   0xFFFF0000

#define BCM_REGISTER_STATUS_1_MASK_BKCS                         0x00000003
#define BCM_REGISTER_STATUS_1_MASK_CHCS                         0x0000000C
#define BCM_REGISTER_STATUS_1_MASK_CHST0                        0x00000030
#define BCM_REGISTER_STATUS_1_MASK_CHST1                        0x000000C0
#define BCM_REGISTER_STATUS_1_MASK_LVF                          0x00000100
#define BCM_REGISTER_STATUS_1_MASK_CVF                          0x00000200

#define BCM_REGISTER_CONTROL_1_MASK_BKEN                        0x00000001
#define BCM_REGISTER_CONTROL_1_MASK_CHMD                        0x00000002
#define BCM_REGISTER_CONTROL_1_MASK_CHEN                        0x00000004

#define BCM_REGISTER_ANALOG_DATA_1_MASK_SOURCE_VOLTAGE          0x0000FFFF
#define BCM_REGISTER_ANALOG_DATA_1_MASK_STORAGE_VOLTAGE         0xFFFF0000

#define BCM_REGISTER_ANALOG_DATA_2_MASK_BACKUP_VOLTAGE          0x0000FFFF
#define BCM_REGISTER_ANALOG_DATA_2_MASK_CHARGE_CURRENT          0xFFFF0000

/*** BCM REGISTERS global variables ***/

extern const UNA_register_t BCM_REGISTER[BCM_REGISTER_ADDRESS_LAST];

#endif /* __BCM_REGISTERS_H__ */
