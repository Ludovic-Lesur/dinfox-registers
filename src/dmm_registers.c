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

const UNA_register_t DMM_REGISTER[DMM_REGISTER_ADDRESS_LAST] = {
    COMMON_REGISTER
    /* CONFIGURATION_0 */
    {
        UNA_REGISTER_ACCESS_READ_WRITE,
        DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS,
        UNA_REGISTER_RESET_VALUE_NVM,
        (uint32_t) ((UNA_TIME_ERROR_VALUE << 16) | (UNA_TIME_ERROR_VALUE << 8) | (UNA_TIME_ERROR_VALUE << 0))
    },
    /* STATUS_1 */
    {
        UNA_REGISTER_ACCESS_READ_ONLY,
        DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS,
        UNA_REGISTER_RESET_VALUE_STATIC,
        0x00000000
    },
    /* CONTROL_1 */
    {
        UNA_REGISTER_ACCESS_READ_WRITE,
        300000,
        UNA_REGISTER_RESET_VALUE_STATIC,
        0x00000000
    },
    /* ANALOG_DATA_1 */
    {
        UNA_REGISTER_ACCESS_READ_ONLY,
        DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS,
        UNA_REGISTER_RESET_VALUE_STATIC,
        (uint32_t) ((UNA_VOLTAGE_ERROR_VALUE << 16) | (UNA_VOLTAGE_ERROR_VALUE << 0))
    },
    /* ANALOG_DATA_2 */
    {
        UNA_REGISTER_ACCESS_READ_ONLY,
        DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS,
        UNA_REGISTER_RESET_VALUE_STATIC,
        (uint32_t) (UNA_VOLTAGE_ERROR_VALUE << 0)
    }
};
