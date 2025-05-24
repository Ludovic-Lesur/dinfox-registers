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
    UHFM_REGISTER_ADDRESS_ANALOG_DATA_1,
    UHFM_REGISTER_ADDRESS_EP_ID,
    UHFM_REGISTER_ADDRESS_UL_PAYLOAD_0,
    UHFM_REGISTER_ADDRESS_UL_PAYLOAD_1,
    UHFM_REGISTER_ADDRESS_UL_PAYLOAD_2,
    UHFM_REGISTER_ADDRESS_DL_PAYLOAD_0,
    UHFM_REGISTER_ADDRESS_DL_PAYLOAD_1,
    UHFM_REGISTER_ADDRESS_RADIO_TEST_0,
    UHFM_REGISTER_ADDRESS_RADIO_TEST_1,
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

#define UHFM_REGISTER_CONFIGURATION_0_MASK_RC               0x0000000F
#define UHFM_REGISTER_CONFIGURATION_0_MASK_BR               0x00000030
#define UHFM_REGISTER_CONFIGURATION_0_MASK_NFR              0x000000C0
#define UHFM_REGISTER_CONFIGURATION_0_MASK_TX_POWER         0x0000FF00
#define UHFM_REGISTER_CONFIGURATION_0_MASK_CMSG             0x00010000
#define UHFM_REGISTER_CONFIGURATION_0_MASK_MSGT             0x000E0000
#define UHFM_REGISTER_CONFIGURATION_0_MASK_BF               0x00100000
#define UHFM_REGISTER_CONFIGURATION_0_MASK_UL_PAYLOAD_SIZE  0x03E00000
#define UHFM_REGISTER_CONFIGURATION_0_MASK_RFP_TEST_MODE    0x3C000000

#define UHFM_REGISTER_CONFIGURATION_1_MASK_TCONF            0xFFFF0000
#define UHFM_REGISTER_CONFIGURATION_1_MASK_TIFU             0x0000FFFF

#define UHFM_REGISTER_CONTROL_1_MASK_STRG                   0x00000001
#define UHFM_REGISTER_CONTROL_1_MASK_TTRG                   0x00000002
#define UHFM_REGISTER_CONTROL_1_MASK_CWEN                   0x00000004
#define UHFM_REGISTER_CONTROL_1_MASK_RSEN                   0x00000008

#define UHFM_REGISTER_STATUS_1_MASK_MESSAGE_STATUS          0x000000FF
#define UHFM_REGISTER_STATUS_1_MASK_DL_RSSI                 0x0000FF00
#define UHFM_REGISTER_STATUS_1_MASK_BIDIRECTIONAL_MC        0x0FFF0000

#define UHFM_REGISTER_ANALOG_DATA_1_MASK_VRF_TX             0x0000FFFF
#define UHFM_REGISTER_ANALOG_DATA_1_MASK_VRF_RX             0xFFFF0000

#define UHFM_REGISTER_RADIO_TEST_0_MASK_RF_FREQUENCY        UNA_REGISTER_MASK_ALL

#define UHFM_REGISTER_RADIO_TEST_1_MASK_TX_POWER            0x000000FF
#define UHFM_REGISTER_RADIO_TEST_1_MASK_RSSI                0x0000FF00

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
