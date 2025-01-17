/**
 ******************************************************************************
 *This file contains general configurations for ameba platform
 ******************************************************************************
*/

#ifndef __PLATFORM_OPTS_H__
#define __PLATFORM_OPTS_H__

#define TCP_MSL 1000

/*For MP mode setting*/
#define SUPPORT_MP_MODE		1

/**
 * For AT cmd Log service configurations
 */
#define SUPPORT_LOG_SERVICE	0
#if SUPPORT_LOG_SERVICE
#define LOG_SERVICE_BUFLEN     100 //can't larger than UART_LOG_CMD_BUFLEN(127)
#define CONFIG_LOG_HISTORY	0
#if CONFIG_LOG_HISTORY
#define LOG_HISTORY_LEN    5
#endif
#define CONFIG_LOG_SERVICE_LOCK		0
#define CONFIG_ATCMD_MP				0 //support MP AT command
#define USE_MODE                    1 //for test
#endif

/**
 * For FreeRTOS tickless configurations
 */
#define FREERTOS_PMU_TICKLESS_PLL_RESERVED   0   // In sleep mode, 0: close PLL clock, 1: reserve PLL clock
#define FREERTOS_PMU_TICKLESS_SUSPEND_SDRAM  1   // In sleep mode, 1: suspend SDRAM, 0: no act

/******************************************************************************/

/**
* For common flash usage
*/
#define FLASH_BAKEUP_SECTOR		(0x3000)
//#define FAST_RECONNECT_DATA		(0x200000 - 0x1000)
//#define BT_FTL_PHY_ADDR0		(0x200000 - 0x2000)
//#define BT_FTL_PHY_ADDR1		(0x200000 - 0x3000)
//#define BT_FTL_BKUP_ADDR		(0x200000 - 0x4000)
//#define UART_SETTING_SECTOR		(0x200000 - 0x5000)
//#define DCT_BEGIN_ADDR			(0x200000 - 0x29000) /*!< DCT begin address of flash, ex: 0x200000 = 2M, the default size of DCT is 24K; ; if backup enabled, the size is 48k; if wear leveling enabled, the size is 144k*/
//#define FLASH_APP_BASE			(0x200000 - 0xA9000) /*!< FATFS begin address, default size used is 512KB (can be adjusted based on user requirement)*/
//#define BT_WHITELIST_BASE_1		(0x200000 - 0xA000)
//#define BT_WHITELIST_PAGE_SIZE		(0x1000)
//#define BT_WHITELIST_BASE_2		(BT_WHITELIST_BASE_1 + BT_WHITELIST_PAGE_SIZE)
/**
 * For Wlan configurations
 */
#define CONFIG_WLAN		1
#if CONFIG_WLAN
#define CONFIG_LWIP_LAYER	1
#define LWIP_NETIF_HOSTNAME 1
#define CONFIG_INIT_NET		1 //init lwip layer when start up
#define CONFIG_WIFI_IND_USE_THREAD	0	// wifi indicate worker thread
#define CONFIG_ENABLE_AP_POLLING_CLIENT_ALIVE 0 // on or off AP POLLING CLIENT; Not enabled in lib by default
#define CONFIG_AP_SECURITY  0//on or off to set AP security to WEP, default is open or WPA2 AES

//on/off relative commands in log service
#define CONFIG_SSL_CLIENT	0
#define CONFIG_OTA_UPDATE	1
#define CONFIG_BSD_TCP		0//NOTE : Enable CONFIG_BSD_TCP will increase about 11KB code size
#define CONFIG_UART_SOCKET	0
#define CONFIG_UART_YMODEM	0//support uart ymodem upgrade or not
#define CONFIG_TRANSPORT	0//on or off the at command for transport socket

/* For WPS */
#define CONFIG_ENABLE_WPS		0
#if CONFIG_ENABLE_WPS
#define CONFIG_ENABLE_WPS_DISCOVERY	1
#endif

/*For fast reconnection*/
#ifdef PLATFORM_OHOS
#define CONFIG_EXAMPLE_WLAN_FAST_CONNECT	0
#else
#define CONFIG_EXAMPLE_WLAN_FAST_CONNECT	0
#endif
#if CONFIG_EXAMPLE_WLAN_FAST_CONNECT
#define CONFIG_FAST_DHCP 1
#else
#define CONFIG_FAST_DHCP 0
#endif

#endif //end of #if CONFIG_WLAN
/*******************************************************************************/

/* For SSL/TLS */
#define CONFIG_MBEDTLS_VERSION3	0
#define CONFIG_SSL_CLIENT_PRIVATE_IN_TZ 1

/* For Bridge Mode */
#define CONFIG_BRIDGE                 0

/* For LWIP configuration */
#define CONFIG_LWIP_DHCP_COARSE_TIMER 60

/*Enable CONFIG_LWIP_DHCP_FINE_TIMEOUT if lease time is less than or equal to CONFIG_LWIP_DHCP_COARSE_TIMER
* replace dhcp_coarse_tmr with dhcp_fine_tmr to manage and check for lease timeout
*/
#define CONFIG_LWIP_DHCP_FINE_TIMEOUT 0

/* For Azure Examples */
#define CONFIG_USE_AZURE_EMBEDDED_C        0
#if CONFIG_USE_AZURE_EMBEDDED_C
/* For Azure embedded iot examples*/
#define CONFIG_EXAMPLE_AZURE   0
#if CONFIG_EXAMPLE_AZURE
#undef WAIT_FOR_ACK
#define WAIT_FOR_ACK
#endif
#else
/* For Azure iot hub telemetry example*/
#define CONFIG_EXAMPLE_AZURE_IOTHUB_TELEMETRY      0
/* For Azure iot hub x509 example*/
#define CONFIG_EXAMPLE_AZURE_IOTHUB_X509     0
#endif

#if CONFIG_ENABLE_TLS
#define ENABLE_EAP_SSL_VERIFY_CLIENT	1
#else
#define ENABLE_EAP_SSL_VERIFY_CLIENT	0
#endif

#if CONFIG_ENABLE_WPS
#define WPS_CONNECT_RETRY_COUNT		4
#define WPS_CONNECT_RETRY_INTERVAL	5000 // in ms
#endif

#define AUTO_RECONNECT_COUNT	8
#define AUTO_RECONNECT_INTERVAL	5 // in sec

/* For UART Module AT command example */
#define CONFIG_EXAMPLE_UART_ATCMD			0
#if (defined(CONFIG_EXAMPLE_UART_ATCMD) && CONFIG_EXAMPLE_UART_ATCMD)
#define UART_SETTING_BACKUP_SECTOR			(FLASH_BAKEUP_SECTOR)
#undef CONFIG_OTA_UPDATE
#define CONFIG_OTA_UPDATE					1
#undef CONFIG_TRANSPORT
#define CONFIG_TRANSPORT					1
#undef LOG_SERVICE_BUFLEN
#define LOG_SERVICE_BUFLEN					1600
#undef CONFIG_LOG_SERVICE_LOCK
#define CONFIG_LOG_SERVICE_LOCK				1
#undef CONFIG_EXAMPLE_WLAN_FAST_CONNECT
#define CONFIG_EXAMPLE_WLAN_FAST_CONNECT	0
#endif

#define CONFIG_EXAMPLE_MBEDTLS_ECDHE		0

#endif

#if defined(CONFIG_MATTER) && CONFIG_MATTER
#include "platform_opts_matter.h"
#endif /* CONFIG_MATTER */

#if defined(CONFIG_AMAZON_FREERTOS) && CONFIG_AMAZON_FREERTOS
#include "platform_opts_amazon.h"
#endif /* CONFIG_AMAZON */
