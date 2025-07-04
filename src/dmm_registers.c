/*
 * dmm_registers.c
 *
 *  Created on: 15 dec. 2024
 *      Author: Ludo
 */

#include "dmm_registers.h"

#include "common_registers.h"
#include "types.h"
#include "una.h"

/*** DMM REGISTERS global variables ***/

#ifdef DINFOX_REGISTERS_ACCESS
const UNA_register_access_t DMM_REGISTER_ACCESS[DMM_REGISTER_ADDRESS_LAST] = {
    COMMON_REGISTER_ACCESS
    UNA_REGISTER_ACCESS_READ_WRITE,
    UNA_REGISTER_ACCESS_READ_ONLY,
    UNA_REGISTER_ACCESS_READ_WRITE,
    UNA_REGISTER_ACCESS_READ_ONLY,
    UNA_REGISTER_ACCESS_READ_ONLY
};
#endif
#ifdef DINFOX_REGISTERS_ACCESS_TIMEOUT
const uint32_t DMM_REGISTER_ACCESS_TIMEOUT_MS[DMM_REGISTER_ADDRESS_LAST] = {
    COMMON_REGISTER_ACCESS_TIMEOUT_MS
    DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS,
    DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS,
    DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS,
    DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS,
    DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS
};
#endif
#ifdef DINFOX_REGISTERS_ERROR_VALUE
const uint32_t DMM_REGISTER_ERROR_VALUE[DMM_REGISTER_ADDRESS_LAST] = {
    COMMON_REGISTER_ERROR_VALUE
    ((UNA_TIME_ERROR_VALUE << 16) | (UNA_TIME_ERROR_VALUE << 8) | (UNA_TIME_ERROR_VALUE << 0)),
    0x00000000,
    0x00000000,
    (uint32_t) ((UNA_VOLTAGE_ERROR_VALUE << 16) | (UNA_VOLTAGE_ERROR_VALUE << 0)),
    (UNA_VOLTAGE_ERROR_VALUE << 0)
};
#endif
