/*
 * lvrm_registers.c
 *
 *  Created on: 15 dec. 2024
 *      Author: Ludo
 */

#include "lvrm_registers.h"

#include "common_registers.h"
#include "types.h"
#include "una.h"

/*** LVRM REGISTERS global variables ***/

const UNA_register_t LVRM_REGISTER[LVRM_REGISTER_ADDRESS_LAST] = {
    COMMON_REGISTER
    /* FLAGS_1 */
    {
        UNA_REGISTER_ACCESS_READ_ONLY,
        DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS,
        UNA_REGISTER_RESET_VALUE_STATIC,
        0x00000000
    },
    /* CONFIGURATION_0 */
    {
        UNA_REGISTER_ACCESS_READ_WRITE,
        DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS,
        UNA_REGISTER_RESET_VALUE_NVM,
        (uint32_t) ((UNA_VOLTAGE_ERROR_VALUE << 16) | (UNA_VOLTAGE_ERROR_VALUE << 0))
    },
    /* CONFIGURATION_1 */
    {
        UNA_REGISTER_ACCESS_READ_WRITE,
        DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS,
        UNA_REGISTER_RESET_VALUE_NVM,
        (uint32_t) (UNA_CURRENT_ERROR_VALUE << 0)
    },
    /* STATUS_1 */
    {
        UNA_REGISTER_ACCESS_READ_ONLY,
        DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS,
        UNA_REGISTER_RESET_VALUE_STATIC,
        (uint32_t) (UNA_BIT_ERROR << 0),
    },
    /* CONTROL_1 */
    {
        UNA_REGISTER_ACCESS_READ_WRITE,
        5000,
        UNA_REGISTER_RESET_VALUE_STATIC,
        0x00000000
    },
    /* ANALOG_DATA_1 */
    {
        UNA_REGISTER_ACCESS_READ_ONLY,
        DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS,
        UNA_REGISTER_RESET_VALUE_STATIC,
        (uint32_t) ((UNA_VOLTAGE_ERROR_VALUE << 16) | (UNA_VOLTAGE_ERROR_VALUE << 0)),
    },
    /* ANALOG_DATA_2 */
    {
        UNA_REGISTER_ACCESS_READ_ONLY,
        DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS,
        UNA_REGISTER_RESET_VALUE_STATIC,
        (uint32_t) (UNA_CURRENT_ERROR_VALUE << 0)
    }
};
