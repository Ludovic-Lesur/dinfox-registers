/*
 * uhfm_registers.h
 *
 *  Created on: 31 mar. 2022
 *      Author: Ludo
 */

#ifndef __UHFM_REGISTERS_H__
#define __UHFM_REGISTERS_H__

#ifndef DINFOX_REGISTERS_DISABLE_FLAGS_FILE
#include "dinfox_registers_flags.h"
#endif
#include "common_registers.h"
#include "types.h"
#include "una.h"

/*** UHFM REGISTERS structures ***/

/*!******************************************************************
 * \enum UHFM_register_address_t
 * \brief UHFM registers map.
 *******************************************************************/
typedef enum {
    UHFM_REGISTER_ADDRESS_CONFIGURATION_0 = COMMON_REGISTER_ADDRESS_LAST,
    UHFM_REGISTER_ADDRESS_CONFIGURATION_1,
    UHFM_REGISTER_ADDRESS_STATUS_1,
    UHFM_REGISTER_ADDRESS_CONTROL_1,
    UHFM_REGISTER_ADDRESS_CONTROL_2,
    UHFM_REGISTER_ADDRESS_ANALOG_DATA_1,
    UHFM_REGISTER_ADDRESS_SIGFOX_EP_ID,
    UHFM_REGISTER_ADDRESS_SIGFOX_UL_PAYLOAD_0,
    UHFM_REGISTER_ADDRESS_SIGFOX_UL_PAYLOAD_1,
    UHFM_REGISTER_ADDRESS_SIGFOX_UL_PAYLOAD_2,
    UHFM_REGISTER_ADDRESS_SIGFOX_DL_PAYLOAD_0,
    UHFM_REGISTER_ADDRESS_SIGFOX_DL_PAYLOAD_1,
    UHFM_REGISTER_ADDRESS_LAST,
} UHFM_register_address_t;

/*!******************************************************************
 * \enum UHFM_ul_message_type_t
 * \brief Uplink message types.
 *******************************************************************/
typedef enum {
    UHFM_UL_MESSAGE_TYPE_EMPTY = 0,
    UHFM_UL_MESSAGE_TYPE_BIT0,
    UHFM_UL_MESSAGE_TYPE_BIT1,
    UHFM_UL_MESSAGE_TYPE_BYTE_ARRAY,
    UHFM_UL_MESSAGE_TYPE_LAST
} UHFM_ul_message_type_t;

/*!******************************************************************
 * \union UHFM_ul_message_status_t
 * \brief Uplink message status bitfield.
 *******************************************************************/
typedef union {
    struct {
        unsigned ul_frame_1 :1;
        unsigned ul_frame_2 :1;
        unsigned ul_frame_3 :1;
        unsigned dl_frame :1;
        unsigned dl_conf_frame :1;
        unsigned network_error :1;
        unsigned execution_error :1;
    } field;
    unsigned all;
} UHFM_ul_message_status_t;

/*** UHFM REGISTERS macros ***/

#define UHFM_EP_ID_SIZE_BYTES                               4
#define UHFM_UL_PAYLOAD_MAX_SIZE_BYTES                      12
#define UHFM_DL_PAYLOAD_SIZE_BYTES                          8

#define UHFM_NUMBER_OF_SPECIFIC_REGISTERS                   (UHFM_REGISTER_ADDRESS_LAST - COMMON_REGISTER_ADDRESS_LAST)

#define UHFM_REGISTER_CONFIGURATION_0_MASK_SIGFOX_TX_POWER  0x000000FF
#define UHFM_REGISTER_CONFIGURATION_0_MASK_RLBY             0x00000100
#define UHFM_REGISTER_CONFIGURATION_0_MASK_RFBY             0x00000200
#define UHFM_REGISTER_CONFIGURATION_0_MASK_SIGFOX_RC        0x00001C00
#define UHFM_REGISTER_CONFIGURATION_0_MASK_SBR              0x00002000
#define UHFM_REGISTER_CONFIGURATION_0_MASK_SNFR             0x0000C000

#define UHFM_REGISTER_CONFIGURATION_1_MASK_SIGFOX_T_IFU     0x0000FFFF
#define UHFM_REGISTER_CONFIGURATION_1_MASK_SIGFOX_T_CONF    0xFFFF0000

#define UHFM_REGISTER_STATUS_1_MASK_SIGFOX_MESSAGE_STATUS   0x000000FF
#define UHFM_REGISTER_STATUS_1_MASK_SIGFOX_DL_RSSI          0x0000FF00
#define UHFM_REGISTER_STATUS_1_MASK_SIGFOX_BIDIRECTIONAL_MC 0x0FFF0000

#define UHFM_REGISTER_CONTROL_1_MASK_STRG                   0x00000001
#define UHFM_REGISTER_CONTROL_1_MASK_SCMF                   0x00000002
#define UHFM_REGISTER_CONTROL_1_MASK_SIGFOX_MSGT            0x0000001C
#define UHFM_REGISTER_CONTROL_1_MASK_SBF                    0x00000020
#define UHFM_REGISTER_CONTROL_1_MASK_SIGFOX_UL_PAYLOAD_SIZE 0x000007C0
#define UHFM_REGISTER_CONTROL_1_MASK_TTRG                   0x00000800
#define UHFM_REGISTER_CONTROL_1_MASK_SIGFOX_RFP_TEST_MODE   0x0000F000
#define UHFM_REGISTER_CONTROL_1_MASK_CWEN                   0x00010000
#define UHFM_REGISTER_CONTROL_1_MASK_CW_TX_POWER            0x01FE0000

#define UHFM_REGISTER_CONTROL_2_MASK_CW_RF_FREQUENCY        UNA_REGISTER_MASK_ALL

#define UHFM_REGISTER_ANALOG_DATA_1_MASK_VRF_TX             0x0000FFFF
#define UHFM_REGISTER_ANALOG_DATA_1_MASK_VRF_RX             0xFFFF0000

/*** UHFM REGISTERS global variables ***/

#ifdef DINFOX_REGISTERS_ACCESS
extern const UNA_register_access_t UHFM_REGISTER_ACCESS[UHFM_REGISTER_ADDRESS_LAST];
#endif
#ifdef DINFOX_REGISTERS_ACCESS_TIMEOUT
extern const uint32_t UHFM_REGISTER_ACCESS_TIMEOUT_MS[UHFM_REGISTER_ADDRESS_LAST];
#endif
#ifdef DINFOX_REGISTERS_ERROR_VALUE
extern const uint32_t UHFM_REGISTER_ERROR_VALUE[UHFM_REGISTER_ADDRESS_LAST];
#endif

#endif /* __UHFM_REGISTERS_H__ */
