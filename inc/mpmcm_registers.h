/*
 * mpmcm_registers.h
 *
 *  Created on: 03 sep. 2023
 *      Author: Ludo
 */

#ifndef __MPMCM_REGISTERS_H__
#define __MPMCM_REGISTERS_H__

#ifndef DINFOX_REGISTERS_DISABLE_FLAGS_FILE
#include "dinfox_registers_flags.h"
#endif
#include "common_registers.h"
#include "types.h"
#include "una.h"

/*** MPMCM REGISTERS structures ***/

/*******************************************************************/
#define MPMCM_DATA_REGISTERS_SET(channel, data)    \
    MPMCM_REGISTER_ADDRESS_##channel##_##data##_0, \
    MPMCM_REGISTER_ADDRESS_##channel##_##data##_1, \

/*******************************************************************/
#define MPMCM_CHANNEL_REGISTERS_SET(channel)          \
    MPMCM_DATA_REGISTERS_SET(channel, ACTIVE_POWER)   \
    MPMCM_DATA_REGISTERS_SET(channel, RMS_VOLTAGE)    \
    MPMCM_DATA_REGISTERS_SET(channel, RMS_CURRENT)    \
    MPMCM_DATA_REGISTERS_SET(channel, APPARENT_POWER) \
    MPMCM_DATA_REGISTERS_SET(channel, POWER_FACTOR)   \
    MPMCM_REGISTER_ADDRESS_##channel##_ENERGY,        \

/*!******************************************************************
 * \enum MPMCM_register_address_t
 * \brief MPMCM registers map.
 *******************************************************************/
typedef enum {
    MPMCM_REGISTER_ADDRESS_FLAGS_0 = COMMON_REGISTER_ADDRESS_LAST,
    MPMCM_REGISTER_ADDRESS_FLAGS_1,
    MPMCM_REGISTER_ADDRESS_CONFIGURATION_0,
    MPMCM_REGISTER_ADDRESS_CONFIGURATION_1,
    MPMCM_REGISTER_ADDRESS_CONFIGURATION_2,
    MPMCM_REGISTER_ADDRESS_CONFIGURATION_3,
    MPMCM_REGISTER_ADDRESS_STATUS_1,
    MPMCM_REGISTER_ADDRESS_CONTROL_1,
    MPMCM_REGISTER_ADDRESS_MAINS_FREQUENCY_0,
    MPMCM_REGISTER_ADDRESS_MAINS_FREQUENCY_1,
    MPMCM_CHANNEL_REGISTERS_SET(CH1)
    MPMCM_CHANNEL_REGISTERS_SET(CH2)
    MPMCM_CHANNEL_REGISTERS_SET(CH3)
    MPMCM_CHANNEL_REGISTERS_SET(CH4)
    MPMCM_CHANNEL_REGISTERS_SET(TIC)
    MPMCM_REGISTER_ADDRESS_LAST,
} MPMCM_register_address_t;

/*!******************************************************************
 * \enum MPMCM_channel_index_t
 * \brief MPMCM measurement channels list.
 *******************************************************************/
typedef enum {
    MPMCM_CHANNEL_INDEX_ACI0 = 0,
    MPMCM_CHANNEL_INDEX_ACI1,
    MPMCM_CHANNEL_INDEX_ACI2,
    MPMCM_CHANNEL_INDEX_ACI3,
    MPMCM_CHANNEL_INDEX_TIC,
    MPMCM_CHANNEL_INDEX_LAST
} MPMCM_channel_index_t;

/*** MPMCM REGISTERS macros ***/

#define MPMCM_NUMBER_OF_SPECIFIC_REGISTERS                              (MPMCM_REGISTER_ADDRESS_LAST - COMMON_REGISTER_ADDRESS_LAST)
#define MPMCM_NUMBER_OF_REGISTERS_PER_DATA                              (MPMCM_REGISTER_ADDRESS_CH2_ACTIVE_POWER_0 - MPMCM_REGISTER_ADDRESS_CH1_ACTIVE_POWER_0)

/*** MPMCM registers mask ***/

#define MPMCM_REGISTER_FLAGS_0_MASK_AME                                 0x00000001
#define MPMCM_REGISTER_FLAGS_0_MASK_LTE                                 0x00000002
#define MPMCM_REGISTER_FLAGS_0_MASK_LTM                                 0x00000004
#define MPMCM_REGISTER_FLAGS_0_MASK_TRANSFORMER_ATTEN                   0x0000FF00

#define MPMCM_REGISTER_FLAGS_1_MASK_CH1_CURRENT_SENSOR_ATTEN            0x000000FF
#define MPMCM_REGISTER_FLAGS_1_MASK_CH2_CURRENT_SENSOR_ATTEN            0x0000FF00
#define MPMCM_REGISTER_FLAGS_1_MASK_CH3_CURRENT_SENSOR_ATTEN            0x00FF0000
#define MPMCM_REGISTER_FLAGS_1_MASK_CH4_CURRENT_SENSOR_ATTEN            0xFF000000

#define MPMCM_REGISTER_CONFIGURATION_0_MASK_TRANSFORMER_GAIN            0x0000FFFF

#define MPMCM_REGISTER_CONFIGURATION_1_MASK_CH1_CURRENT_SENSOR_GAIN     0x0000FFFF
#define MPMCM_REGISTER_CONFIGURATION_1_MASK_CH2_CURRENT_SENSOR_GAIN     0xFFFF0000

#define MPMCM_REGISTER_CONFIGURATION_2_MASK_CH3_CURRENT_SENSOR_GAIN     0x0000FFFF
#define MPMCM_REGISTER_CONFIGURATION_2_MASK_CH4_CURRENT_SENSOR_GAIN     0xFFFF0000

#define MPMCM_REGISTER_CONFIGURATION_3_MASK_TIC_SAMPLING_PERIOD         0x000000FF

#define MPMCM_REGISTER_STATUS_1_MASK_CH1D                               0x00000001
#define MPMCM_REGISTER_STATUS_1_MASK_CH2D                               0x00000002
#define MPMCM_REGISTER_STATUS_1_MASK_CH3D                               0x00000004
#define MPMCM_REGISTER_STATUS_1_MASK_CH4D                               0x00000008
#define MPMCM_REGISTER_STATUS_1_MASK_TICD                               0x00000010
#define MPMCM_REGISTER_STATUS_1_MASK_MVD                                0x00000020

#define MPMCM_REGISTER_CONTROL_1_MASK_CH1S                              0x00000001
#define MPMCM_REGISTER_CONTROL_1_MASK_CH2S                              0x00000002
#define MPMCM_REGISTER_CONTROL_1_MASK_CH3S                              0x00000004
#define MPMCM_REGISTER_CONTROL_1_MASK_CH4S                              0x00000008
#define MPMCM_REGISTER_CONTROL_1_MASK_TICS                              0x00000010
#define MPMCM_REGISTER_CONTROL_1_MASK_FRQS                              0x00000020

#define MPMCM_REGISTER_MASK_RUN                                         0x0000FFFF
#define MPMCM_REGISTER_MASK_MEAN                                        0xFFFF0000
#define MPMCM_REGISTER_MASK_MIN                                         0x0000FFFF
#define MPMCM_REGISTER_MASK_MAX                                         0xFFFF0000

#define MPMCM_REGISTER_MASK_ACTIVE_ENERGY                               0x0000FFFF
#define MPMCM_REGISTER_MASK_APPARENT_ENERGY                             0xFFFF0000

/*** MPMCM REGISTERS global variables ***/

#ifdef DINFOX_REGISTERS_ACCESS
extern const UNA_register_access_t MPMCM_REGISTER_ACCESS[MPMCM_REGISTER_ADDRESS_LAST];
#endif
#ifdef DINFOX_REGISTERS_ACCESS_TIMEOUT
extern const uint32_t MPMCM_REGISTER_ACCESS_TIMEOUT_MS[MPMCM_REGISTER_ADDRESS_LAST];
#endif
#ifdef DINFOX_REGISTERS_ERROR_VALUE
extern const uint32_t MPMCM_REGISTER_ERROR_VALUE[MPMCM_REGISTER_ADDRESS_LAST];
#endif

#endif /* __MPMCM_REGISTERS_H__ */
