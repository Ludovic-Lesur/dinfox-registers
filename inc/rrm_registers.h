/*
 * rrm_registers.h
 *
 *  Created on: 27 nov. 2022
 *      Author: Ludo
 */

#ifndef __RRM_REGISTERS_H__
#define __RRM_REGISTERS_H__

#ifndef DINFOX_REGISTERS_DISABLE_FLAGS_FILE
#include "dinfox_registers_flags.h"
#endif
#include "common_registers.h"
#include "types.h"
#include "una.h"

/*** RRM REGISTERS structures ***/

/*!******************************************************************
 * \enum RRM_register_address_t
 * \brief RRM registers map.
 *******************************************************************/
typedef enum {
    RRM_REGISTER_ADDRESS_FLAGS_0 = COMMON_REGISTER_ADDRESS_LAST,
    RRM_REGISTER_ADDRESS_CONFIGURATION_0,
    RRM_REGISTER_ADDRESS_STATUS_1,
    RRM_REGISTER_ADDRESS_CONTROL_1,
    RRM_REGISTER_ADDRESS_ANALOG_DATA_1,
    RRM_REGISTER_ADDRESS_ANALOG_DATA_2,
    RRM_REGISTER_ADDRESS_LAST,
} RRM_register_address_t;

/*** RRM REGISTERS macros ***/

#define RRM_NUMBER_OF_SPECIFIC_REGISTERS                (RRM_REGISTER_ADDRESS_LAST - COMMON_REGISTER_ADDRESS_LAST)

#define RRM_REGISTER_FLAGS_0_MASK_RFH                   0x00000001

#define RRM_REGISTER_CONFIGURATION_0_MASK_IOUT_OFFSET   0x0000FFFF

#define RRM_REGISTER_STATUS_1_MASK_RENST                0x00000003

#define RRM_REGISTER_CONTROL_1_MASK_REN                 0x00000001

#define RRM_REGISTER_ANALOG_DATA_1_MASK_VIN             0x0000FFFF
#define RRM_REGISTER_ANALOG_DATA_1_MASK_VOUT            0xFFFF0000

#define RRM_REGISTER_ANALOG_DATA_2_MASK_IOUT            0x0000FFFF

/*** RRM REGISTERS global variables ***/

#ifdef DINFOX_REGISTERS_ACCESS
extern const UNA_register_access_t RRM_REGISTER_ACCESS[RRM_REGISTER_ADDRESS_LAST];
#endif
#ifdef DINFOX_REGISTERS_ACCESS_TIMEOUT
extern const uint32_t RRM_REGISTER_ACCESS_TIMEOUT_MS[RRM_REGISTER_ADDRESS_LAST];
#endif
#ifdef DINFOX_REGISTERS_ERROR_VALUE
extern const uint32_t RRM_REGISTER_ERROR_VALUE[RRM_REGISTER_ADDRESS_LAST];
#endif

#endif /* __RRM_REGISTERS_H__ */
