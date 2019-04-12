/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Arduino Mega with RAMPS v1.4 (or v1.3) pin assignments
 *
 * Applies to the following boards:
 *
 *  ZRIB_V1 (X-MOT, Y-MOT, Z-MOT, E0-MOT, E1-MOT, Hotend0, Hotend1, Fan, Bed)
 *  ZRIB_V2 (X-MOT, Y-MOT, Z-MOT, E0-MOT, E1-MOT, Hotend0, Hotend1, Fan, Fan2, Bed)
 *  ZRIB_V3 (X-MOT, Y-MOT, Z-MOT, E0-MOT, E1-MOT, Hotend0, Hotend1, Fan, Fan2, Bed)
 *  ZRIB_V5 (X-MOT, Y-MOT, Z-MOT, E0-MOT, E1-MOT, E2-MOT, Hotend0, Hotend1, Fan, Fan2, Bed)
 */

#if !defined(__AVR_ATmega2560__)
  #error "Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu."
#endif

#define IS_ZRIB_V5

#ifndef BOARD_NAME
  #define BOARD_NAME "ZONESTAR ZRIBV5"
#endif

#define LARGE_FLASH true

//
// Limit Switches
//
#define X_MIN_PIN           3
#define X_MAX_PIN         	2

#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

//
// Z Probe (when not Z_MIN_PIN)
//
#if ENABLED(Z_MIN_PROBE_ENDSTOP) 
#if ENABLED(BLTOUCH)
//#define	Z_MIN_PROBE_PIN		65
#define	Z_MIN_PROBE_PIN		19
#elif ENABLED(Z_DUAL_STEPPER_DRIVERS)
#define	Z_MIN_PROBE_PIN		2	//X+
#else
#define Z_MIN_PROBE_PIN  	19	//Z+
#endif
#endif
//
// Steppers
//
#if ENABLED(COREXY_SWAPXY_MOTOR)
#define X_STEP_PIN         60
#define X_DIR_PIN          61
#define X_ENABLE_PIN       56

#define Y_STEP_PIN         54
#define Y_DIR_PIN          55
#define Y_ENABLE_PIN       38
#else
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#endif

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62

#define E0_STEP_PIN        26
#define E0_DIR_PIN         28
#define E0_ENABLE_PIN      24

#define E1_STEP_PIN        36
#define E1_DIR_PIN         34
#define E1_ENABLE_PIN      30

#if ENABLED(IS_ZRIB_V5)
#if ENABLED(Z_DUAL_STEPPER_DRIVERS)
#define Z2_STEP_PIN        4
#define Z2_DIR_PIN         5
#define Z2_ENABLE_PIN      22
#else
#define E2_STEP_PIN        4
#define E2_DIR_PIN         5
#define E2_ENABLE_PIN      22
#endif
#endif

#if ENABLED(Z_MOTOR_USE_E2_MOT)
#undef Z_STEP_PIN
#undef Z_DIR_PIN
#undef Z_ENABLE_PIN
#undef E2_STEP_PIN
#undef E2_DIR_PIN
#undef E2_ENABLE_PIN
#define	Z_STEP_PIN			4
#define	Z_DIR_PIN			5
#define	Z_ENABLE_PIN		22
#endif

//
// Temperature Sensors
//
#define TEMP_0_PIN         13   // Analog Input
#define TEMP_BED_PIN       14   // Analog Input
#define TEMP_1_PIN         15   // Analog Input

//
// Heaters / Fans
//
#define HEATER_0_PIN    	10
#define HEATER_BED_PIN		8

#if ENABLED(USE_DUAL_HEATBED_PINS)
#define HEATER_BED2_PIN		7
#else
#define HEATER_1_PIN 		7
#endif

#if ENABLED(HEATERS_PARALLEL) && ENABLED(USE_DUAL_HEATBED_PINS)
  #error "HEATER_1_PIN has been repeated distribution!!"
#endif

#define FAN_PIN        		9
#define FAN1_PIN        	6

//
// Misc. Functions
//
#define SDSS               53
#define LED_PIN            13
#define SD_DETECT_PIN 	   49

//Filament run out detection
#define FILWIDTH_PIN	   -1  // Analog Input
#if ENABLED(IS_ZRIB_V5)
 #define FIL_RUNOUT_PIN     15	//Y_MAX_PIN
 #if DISABLED(Z_DUAL_STEPPER_DRIVERS)
 #define FIL_RUNOUT2_PIN 	2	//X_MAX_PIN
 #endif
#endif

//Power control pin
#define PS_ON_PIN        	12

//
// Servos
//
#if ENABLED(IS_ZRIB_V5)
#define SERVO0_PIN       42	//XS1(AUX3) Pin1
#define SERVO1_PIN       -1	//XS1(AUX3) Pin3
#define SERVO2_PIN       -1	//XS1(AUX3) Pin5
#define SERVO3_PIN       -1	//XS1(AUX3) Pin7
#endif

//================================================================================
// 							Spindle & Laser control
//================================================================================
#if ENABLED(SPINDLE_LASER_ENABLE)
#define SPINDLE_LASER_ENABLE_PIN	HEATER_0_PIN
#endif

//================================================================================
// 							LCD / Controller
//================================================================================
//================================================================================
//LCD 2004
//================================================================================
#if ENABLED(ZONESTAR_LCD2004_ADCKEY) || ENABLED(ZONESTAR_LCD2004_KNOB)
#define	LCDSCREEN_NAME	"LCD 2004"
#define LCD_PINS_RS 	16
#define LCD_PINS_ENABLE 17
#define LCD_PINS_D4 	23
#define LCD_PINS_D5 	25
#define LCD_PINS_D6 	27
#define LCD_PINS_D7 	29
#endif

//================================================================================
//	KEYPAD
//================================================================================
#if ENABLED(ZONESTAR_LCD2004_ADCKEY)
#define	LCDSCREEN_NAME	"LCD2004 ADCKEY"
#define	ADC_KEYPAD_PIN	10			//A10 for ADCKEY
#endif

#if ENABLED(REPRAP_DISCOUNT_SMART_CONTROLLER)
#if ENABLED(ZONESTAR_LCD12864) 
#define BTN_EN1 		25
#define BTN_EN2 		27
#define BTN_ENC 		29
#define BEEPER_PIN 		37
#define KILL_PIN 		35
#elif ENABLED(ZONESTAR_OLED12864)
#define BTN_EN1 		25
#define BTN_EN2 		27
#define BTN_ENC 		29
#define BEEPER_PIN 		-1
#define KILL_PIN 		-1
#elif ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
#define BTN_EN1 		31
#define BTN_EN2 		33
#define BTN_ENC 		35
#define BEEPER_PIN 		37
#define KILL_PIN 		41
#elif ENABLED(ZONESTAR_LCD2004_KNOB) 
#define BTN_EN1 		31
#define BTN_EN2 		33
#define BTN_ENC 		35
#define BEEPER_PIN 		37
#define KILL_PIN 		41
#endif
#elif ENABLED(MKS_MINI_12864)
#define BTN_EN1 		31
#define BTN_EN2 		33
#define BTN_ENC 		35
#define BEEPER_PIN 		37
#define KILL_PIN 		41
#endif
//================================================================================
// End of LCD / Controller
//================================================================================
