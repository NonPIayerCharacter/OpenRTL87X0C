/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/******************************************************************************
	See http://www.freertos.org/a00110.html for an explanation of the
	definitions contained in this file.
******************************************************************************/

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 * http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
#include <stdint.h>
extern uint32_t SystemCoreClock;
#endif

/* Cortex M33 port configuration. */
#define configENABLE_MPU								0

#ifdef __ARMVFP__
#define configENABLE_FPU								1
#else
#define configENABLE_FPU								0
#endif

#if defined(CONFIG_BUILD_SECURE) || defined(CONFIG_BUILD_NONSECURE)
#define configENABLE_TRUSTZONE							1
#else
#define configENABLE_TRUSTZONE							0
#endif

/* Constants related to the behaviour or the scheduler. */
#define configUSE_PORT_OPTIMISED_TASK_SELECTION			0
#define configUSE_PREEMPTION						1
#define configUSE_TIME_SLICING							1
#define configTICK_RATE_HZ							( ( uint32_t ) 1000 )
#define configMAX_PRIORITIES						( 11 )
#define configIDLE_SHOULD_YIELD						1
#define configUSE_16_BIT_TICKS						0 /* Only for 8 and 16-bit hardware. */

/* Constants that describe the hardware and memory usage. */
#define configCPU_CLOCK_HZ							( SystemCoreClock )
#define configMINIMAL_STACK_SIZE					( ( unsigned short ) 70 ) //number of double word
#define configMINIMAL_SECURE_STACK_SIZE			( ( unsigned short ) configMINIMAL_STACK_SIZE*4 ) //number of byte
#define configMAX_TASK_NAME_LEN					( 10 )
#define configTOTAL_HEAP_SIZE						( ( size_t ) ( 180 * 1024 ) )
#define configAPPLICATION_ALLOCATED_HEAP			0

/* Constants that build features in or out. */
#define configUSE_MUTEXES							1
#define configUSE_APPLICATION_TASK_TAG				0
#define configUSE_NEWLIB_REENTRANT					0
#define configUSE_CO_ROUTINES						0
#define configUSE_COUNTING_SEMAPHORES				1
#define configUSE_RECURSIVE_MUTEXES					1
#define configUSE_QUEUE_SETS						1
#define configUSE_TASK_NOTIFICATIONS				1
#define configUSE_TRACE_FACILITY					1

/* Constants that define which hook (callback) functions should be used. */
#define configUSE_IDLE_HOOK							0
#define configUSE_TICK_HOOK							0
#define configUSE_MALLOC_FAILED_HOOK				1
#define secureconfigUSE_MALLOC_FAILED_HOOK			1

/* Constants provided for debugging and optimisation assistance. */
#define configCHECK_FOR_STACK_OVERFLOW				2
#define configRECORD_STACK_HIGH_ADDRESS				1

/* Software timer definitions. */
#define configUSE_TIMERS							1
#define configTIMER_TASK_PRIORITY					( configMAX_PRIORITIES - 1 )
#define configTIMER_QUEUE_LENGTH					( 10 + 64 )
#define configTIMER_TASK_STACK_DEPTH				( 512 )

/* Set the following definitions to 1 to include the API function, or zero
 * to exclude the API function.  NOTE:  Setting an INCLUDE_ parameter to 0 is
 * only necessary if the linker does not automatically remove functions that are
 * not referenced anyway. */
#define INCLUDE_vTaskPrioritySet					1
#define INCLUDE_uxTaskPriorityGet					1
#define INCLUDE_vTaskDelete							1
#define INCLUDE_vTaskSuspend						1
#define INCLUDE_vTaskDelayUntil						1
#define INCLUDE_vTaskDelay							1
#define INCLUDE_pcTaskGetTaskName					1
#define INCLUDE_uxTaskGetStackSize					1
#define INCLUDE_uxTaskGetFreeStackSize				1
#define INCLUDE_uxTaskGetStackHighWaterMark			0
#define INCLUDE_xTaskGetIdleTaskHandle				0
#define INCLUDE_eTaskGetState						1
#define INCLUDE_xTaskResumeFromISR					0
#define INCLUDE_xTaskGetCurrentTaskHandle			1
#define INCLUDE_xTaskGetSchedulerState				1
#define INCLUDE_xSemaphoreGetMutexHolder			1
#define INCLUDE_xTimerPendFunctionCall				1

/* This demo makes use of one or more example stats formatting functions.  These
 * format the raw data provided by the uxTaskGetSystemState() function in to
 * human readable ASCII form.  See the notes in the implementation of vTaskList()
 * within FreeRTOS/Source/tasks.c for limitations. */
#define configUSE_STATS_FORMATTING_FUNCTIONS			1

/* Dimensions a buffer that can be used by the FreeRTOS+CLI command interpreter.
 * See the FreeRTOS+CLI documentation for more information:
 * http://www.FreeRTOS.org/FreeRTOS-Plus/FreeRTOS_Plus_CLI/ */
#define configCOMMAND_INT_MAX_OUTPUT_SIZE				2048

/* Interrupt priority configuration follows...................... */

/* Use the system definition, if there is one. */

#ifdef __NVIC_PRIO_BITS
/* __NVIC_PRIO_BITS will be specified when CMSIS is being used. */
#if __NVIC_PRIO_BITS != 3
#error "__NVIC_PRIO_BITS is NOT correct for RTL8710C"
#endif
#define configPRIO_BITS       		__NVIC_PRIO_BITS
#else
#define configPRIO_BITS       		3        /* 8 priority levels */
//#error "__NVIC_PRIO_BITS must be defined!"
#endif

/* The lowest interrupt priority that can be used in a call to a "set priority"
 * function. */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY			7

/* The highest interrupt priority that can be used by any interrupt service
 * routine that makes calls to interrupt safe FreeRTOS API functions.  DO NOT
 * CALL INTERRUPT SAFE FREERTOS API FUNCTIONS FROM ANY INTERRUPT THAT HAS A
 * HIGHER PRIORITY THAN THIS! (higher priorities are lower numeric values). */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY	2

/* Interrupt priorities used by the kernel port layer itself.  These are generic
 * to all Cortex-M ports, and do not rely on any particular library functions. */
#define configKERNEL_INTERRUPT_PRIORITY					( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << ( 8 - configPRIO_BITS ) )

/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
 * See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY			( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << ( 8 - configPRIO_BITS ) )


/* Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
standard names - or at least those used in the unmodified vector table. */
#define vPortSVCHandler SVC_Handler
#define xPortPendSVHandler PendSV_Handler
#define xPortSysTickHandler SysTick_Handler

/* The #ifdef guards against the file being included from IAR assembly files. */
#if !defined(__IASMARM__)

/* Constants related to the generation of run time stats. */
#define configGENERATE_RUN_TIME_STATS				0
#if configGENERATE_RUN_TIME_STATS
#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS()
#define portGET_RUN_TIME_COUNTER_VALUE() xTickCount
#undef configUSE_TRACE_FACILITY
#define configUSE_TRACE_FACILITY 1
#define portCONFIGURE_STATS_PEROID_VALUE	1000 //unit Ticks
#endif

#include "diag.h"
#if defined(CONFIG_BUILD_SECURE) && (CONFIG_BUILD_SECURE == 1)
#define configASSERT(x) do { \
							if( (x) == 0 ) { \
								char *pcAssertTask = "ISR"; \
								if(__get_IPSR() == 0) \
								{ \
									pcAssertTask = "TSK"; \
								} \
								dbg_printf("\n\r[%s]Assert(" #x ") failed on line %d in file %s\r\n", pcAssertTask, __LINE__, __FILE__); \
								__disable_irq(); for(;;);} \
							} while(0)
#else
#define configASSERT(x) do { \
							if( (x) == 0 ) { \
								char *pcAssertTask = "ISR"; \
								if( (__get_IPSR() == 0) && (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED) ) \
								{ \
									pcAssertTask = pcTaskGetName( NULL ); \
								} \
								dbg_printf("\n\r[%s]Assert(" #x ") failed on line %d in file %s\r\n", pcAssertTask, __LINE__, __FILE__); \
								taskDISABLE_INTERRUPTS(); ota_platform_reset();} \
							} while(0)
#endif
#define configPRINTF( x ) dbg_printf( x )

#endif /* __IASMARM__ */

/* use the low power tickless mode */
#define configUSE_TICKLESS_IDLE                 0
#if defined(configUSE_TICKLESS_IDLE) && configUSE_TICKLESS_IDLE
#if !defined(__IASMARM__) || (__IASMARM__ != 1)
#if !defined(CONFIG_BUILD_SECURE) || (CONFIG_BUILD_SECURE == 0)
/* At least n further complete tick periods will pass before the kernel is due to transition an application task out of the Blocked state */
#define configEXPECTED_IDLE_TIME_BEFORE_SLEEP   2
/* use realtek customized low power tickless mode */
#define configUSE_CUSTOMIZED_TICKLESS_IDLE                 0
#if defined(configUSE_CUSTOMIZED_TICKLESS_IDLE) && configUSE_CUSTOMIZED_TICKLESS_IDLE
extern void freertos_pre_sleep_processing(unsigned int *expected_idle_time);
extern void freertos_post_sleep_processing(unsigned int *expected_idle_time);
extern int  freertos_ready_to_sleep(void);
extern void freertos_suppress_ticks_and_sleep(unsigned int xExpectedIdleTime);

/* configEXPECTED_IDLE_TIME_BEFORE_SLEEP is used for native tickless support
configEXPECTED_IDLE_TIME_BEFORE_CUSTOMIZED_SLEEP is used for realtek customized low power tickless mode
if xExpectedIdleTime < configEXPECTED_IDLE_TIME_BEFORE_CUSTOMIZED_SLEEP, system will go for native tickless mode
if xExpectedIdleTime >= configEXPECTED_IDLE_TIME_BEFORE_CUSTOMIZED_SLEEP, system will got for realtek customized tickless mode
In wlan usage, this value is suggested to use value less than 80 milliseconds */
#define configEXPECTED_IDLE_TIME_BEFORE_CUSTOMIZED_SLEEP   2
#if configEXPECTED_IDLE_TIME_BEFORE_CUSTOMIZED_SLEEP < configEXPECTED_IDLE_TIME_BEFORE_SLEEP
#error configEXPECTED_IDLE_TIME_BEFORE_CUSTOMIZED_SLEEP must not be less than configEXPECTED_IDLE_TIME_BEFORE_SLEEP
#endif

/* Enable tickless power saving. */
#define configPRE_SUPPRESS_TICKS_AND_SLEEP_PROCESSING( x )  do { \
                                                                                                                       if (freertos_ready_to_sleep() == FALSE)  {\
                                                                                                                           x = 0;\
                                                                                                                       }\
                                                                                                             } while(0)

#define portSUPPRESS_TICKS_AND_SLEEP( xExpectedIdleTime )  do { \
                                                                                                                 freertos_suppress_ticks_and_sleep(xExpectedIdleTime); \
                                                                                                             } while(0)

/* It's magic trick that let us can use our own sleep function */
#define configPRE_SLEEP_PROCESSING( x )        do { \
                                                                                freertos_pre_sleep_processing((unsigned int *)&x);  \
                                                                             } while(0)

#define configPOST_SLEEP_PROCESSING( x )        do { \
                                                                                freertos_post_sleep_processing((unsigned int *)&x);  \
                                                                             } while(0)

/* It's magic trick that let us can enable/disable tickless dynamically */
#define traceLOW_POWER_IDLE_BEGIN()            do {

#define traceLOW_POWER_IDLE_END()              } while (0)

/* It's FreeRTOS related feature but it's not included in FreeRTOS design. */
#define configUSE_WAKELOCK_PMU                  1

#undef configMINIMAL_STACK_SIZE
#define configMINIMAL_STACK_SIZE		( ( unsigned short ) 192 )
#undef configASSERT
#endif //#if defined(configUSE_CUSTOMIZED_TICKLESS_IDLE) && configUSE_CUSTOMIZED_TICKLESS_IDLE
#endif // #if !defined(CONFIG_BUILD_SECURE) || (CONFIG_BUILD_SECURE == 0)
#endif // #if !defined(__IASMARM__) || (__IASMARM__ != 1)
#endif // #if defined(configUSE_TICKLESS_IDLE) && configUSE_TICKLESS_IDLE

/* Add by Realtek to re-arrange the FreeRTOS priority*/
#define PRIORITIE_OFFSET				( 4 )

/*Add by Realtek for support LWIP_NETCONN_SEM_PER_THREAD Test*/
// #define configNUM_THREAD_LOCAL_STORAGE_POINTERS 1

#if defined(__ICCARM__)
/* Keep below compiler pragma, below 10.2.0 remove them from portmacro.h
which will generate compiler warnings.
*/
/* Suppress warnings that are generated by the IAR tools, but cannot be fixed in
the source code because to do so would cause other compilers to generate
warnings. */
#pragma diag_suppress=Pe191
#pragma diag_suppress=Pa082
#endif

#endif /* FREERTOS_CONFIG_H */
