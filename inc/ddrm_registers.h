/*
 * ddrm_registers.h
 *
 *  Created on: 27 nov. 2022
 *      Author: Ludo
 */

#ifndef __DDRM_REGISTERS_H__
#define __DDRM_REGISTERS_H__

#ifndef DINFOX_REGISTERS_DISABLE_FLAGS_FILE
#include "dinfox_registers_flags.h"
#endif
#include "common_registers.h"
#include "types.h"
#include "una.h"

/*** DDRM REGISTERS structures ***/

/*!******************************************************************
 * \enum DDRM_register_address_t
 * \brief DDRM registers map.
 *******************************************************************/
typedef enum {
    DDRM_REGISTER_ADDRESS_FLAGS_1 = COMMON_REGISTER_ADDRESS_LAST,
    DDRM_REGISTER_ADDRESS_CONFIGURATION_0,
    DDRM_REGISTER_ADDRESS_STATUS_1,
    DDRM_REGISTER_ADDRESS_CONTROL_1,
    DDRM_REGISTER_ADDRESS_ANALOG_DATA_1,
    DDRM_REGISTER_ADDRESS_ANALOG_DATA_2,
    DDRM_REGISTER_ADDRESS_LAST,
} DDRM_register_address_t;

/*** DDRM REGISTERS macros ***/

#define DDRM_NUMBER_OF_SPECIFIC_REGISTERS               (DDRM_REGISTER_ADDRESS_LAST - COMMON_REGISTER_ADDRESS_LAST)

#define DDRM_REGISTER_FLAGS_1_MASK_DDFH                 0x00000001

#define DDRM_REGISTER_CONFIGURATION_0_MASK_IOUT_OFFSET  0x0000FFFF

#define DDRM_REGISTER_STATUS_1_MASK_DDENST              0x00000003

#define DDRM_REGISTER_CONTROL_1_MASK_DDEN               0x00000001

#define DDRM_REGISTER_ANALOG_DATA_1_MASK_VIN            0x0000FFFF
#define DDRM_REGISTER_ANALOG_DATA_1_MASK_VOUT           0xFFFF0000

#define DDRM_REGISTER_ANALOG_DATA_2_MASK_IOUT           0x0000FFFF

/*** DDRM REGISTERS global variables ***/

#ifdef DINFOX_REGISTERS_ACCESS
extern const UNA_register_access_t DDRM_REGISTER_ACCESS[DDRM_REGISTER_ADDRESS_LAST];
#endif
#ifdef DINFOX_REGISTERS_ACCESS_TIMEOUT
extern const uint32_t DDRM_REGISTER_ACCESS_TIMEOUT_MS[DDRM_REGISTER_ADDRESS_LAST];
#endif
#ifdef DINFOX_REGISTERS_ERROR_VALUE
extern const uint32_t DDRM_REGISTER_ERROR_VALUE[DDRM_REGISTER_ADDRESS_LAST];
#endif

#endif /* __DDRM_REGISTERS_H__ */
