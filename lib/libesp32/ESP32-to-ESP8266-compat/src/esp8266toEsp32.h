/*
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 */
#pragma once
#ifdef ESP32
// my debug Stuff
#define Serial_Debug1(p) Serial.printf p
#define Serial_DebugX(p)

//
// basics
//
// dummy defines
//#define SPIFFS_END (SPI_FLASH_SEC_SIZE * 200)
//#define SETTINGS_LOCATION SPIFFS_END

#include <Esp.h>

#if CONFIG_IDF_TARGET_ESP32C3
  #define PWM_SUPPORTED_CHANNELS 6
  #define PWM_CHANNEL_OFFSET     1   // Webcam uses channel 0, so we offset standard PWM
#else // other ESP32
  #define PWM_SUPPORTED_CHANNELS 8
  #define PWM_CHANNEL_OFFSET     2   // Webcam uses channel 0, so we offset standard PWM
#endif // CONFIG_IDF_TARGET_ESP32C3 vs ESP32

extern uint8_t _pwm_channel[PWM_SUPPORTED_CHANNELS];
extern uint32_t _pwm_frequency;
extern uint8_t _pwm_bit_num;

void _analogWriteFreqRange(void);
// input range is in full range, ledc needs bits
uint32_t _analogGetResolution(uint32_t x);
void analogWriteRange(uint32_t range);
void analogWriteFreq(uint32_t freq);
bool analogAttach(uint32_t pin);
void analogWrite(uint8_t pin, int val);

// Extended version that also allows to change phase
extern void analogWritePhase(uint8_t pin, uint32_t duty, uint32_t phase = 0);


/*********************************************************************************************/

#define INPUT_PULLDOWN_16 INPUT_PULLUP

typedef double real64_t;

//
// Time and Timer
//
#define ETS_UART_INTR_DISABLE()
#define ETS_UART_INTR_ENABLE()

#define ESPhttpUpdate httpUpdate
#define getFlashChipRealSize() getFlashChipSize()

#define os_delay_us ets_delay_us
// Serial minimal type to hold the config
typedef int SerConfu8;
typedef int SerialConfig;
//#define analogWrite(a, b)

//
// UDP
//
//#define PortUdp_writestr(log_data) PortUdp.write((const uint8_t *)(log_data), strlen(log_data))
#define PortUdp_write(log_data, n) PortUdp.write((const uint8_t *)(log_data), n)

//
#define wifi_forceSleepBegin()

#undef LWIP_IPV6

#define REASON_DEFAULT_RST      0  // "Power on"                normal startup by power on
#define REASON_WDT_RST          1  // "Hardware Watchdog"       hardware watch dog reset
#define REASON_EXCEPTION_RST    2  // "Exception"               exception reset, GPIO status won’t change
#define REASON_SOFT_WDT_RST     3  // "Software Watchdog"       software watch dog reset, GPIO status won’t change
#define REASON_SOFT_RESTART     4  // "Software/System restart" software restart ,system_restart , GPIO status won’t change
#define REASON_DEEP_SLEEP_AWAKE 5  // "Deep-Sleep Wake"         wake up from deep-sleep
#define REASON_EXT_SYS_RST      6  // "External System"         external system reset

// memmove ...
#define memcpy_P memcpy
#define memmove_P memmove
#define strncpy_P strncpy
#define strcmp_P strcmp
#define memccpy_P memccpy
#define snprintf_P snprintf
#define sprintf_P sprintf
#define strncmp_P strncmp

// LWIP STuff

#define STATION_IF 0

#endif
