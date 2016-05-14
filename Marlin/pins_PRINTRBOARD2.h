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
 * Printrboard pin assignments (AT90USB1286)
 * Requires the Teensyduino software with Teensy++ 2.0 selected in Arduino IDE!
 * http://www.pjrc.com/teensy/teensyduino.html
 * See http://reprap.org/wiki/Printrboard for more info
 */

#ifndef __AVR_AT90USB1286__
  #error Oops!  Make sure you have 'Teensy++ 2.0' selected from the 'Tools -> Boards' menu.
#endif

//#ifdef AT90USBxx_TEENSYPP_ASSIGNMENTS  // use Teensyduino Teensy++2.0 pin assignments instead of Marlin traditional.
//  #error These Printrboard assignments depend on traditional Marlin assignments, not AT90USBxx_TEENSYPP_ASSIGNMENTS in fastio.h
//#endif

#define AT90USB 1286  // Disable MarlinSerial etc.

#define LARGE_FLASH        true

#define X_STEP_PIN          28//0
#define X_DIR_PIN           29//1
#define X_ENABLE_PIN        19//39

#define Y_STEP_PIN          30//2
#define Y_DIR_PIN           31//3
#define Y_ENABLE_PIN        18//38

#define Z_STEP_PIN          32//4
#define Z_DIR_PIN           33//5
#define Z_ENABLE_PIN        17//23

#define E0_STEP_PIN         34//6
#define E0_DIR_PIN          35//7
#define E0_ENABLE_PIN       13//19

#define HEATER_0_PIN       15//21  // Extruder
#define HEATER_1_PIN       -1
#define HEATER_2_PIN       -1
#define HEATER_BED_PIN     14//20  // Bed            
#define FAN_PIN            16//22//Fan
 #if FAN_PIN == 16
  #define FAN_SOFT_PWM
#endif
// You may need to change FAN_PIN to 16 because Marlin isn't using fastio.h
// for the fan and Teensyduino uses a different pin mapping.

#if MB(TEENSYLU)  // Teensylu
  #define X_STOP_PIN         13
  #define Y_STOP_PIN         14
  #define Z_STOP_PIN         15
  #define TEMP_0_PIN          7  // Extruder / Analog pin numbering
  #define TEMP_BED_PIN        6  // Bed / Analog pin numbering
#else  // Printrboard
  #define X_STOP_PIN         47//35
  #define Y_STOP_PIN         20//8
  //#define Y_STOP_PIN         36
  //#define Z_MAX_PIN          37//E-STOP
  #define Z_MIN_PIN          36//autolevel Z probe
  #define TEMP_0_PIN          1  // Extruder / Analog pin numbering
  #define TEMP_BED_PIN        0  // Bed / Analog pin numbering
  #ifdef FILAMENT_SENSOR
   #define FILWIDTH_PIN        2
  #endif //FILAMENT_SENSOR
#endif

#define TEMP_1_PIN         -1
#define TEMP_2_PIN         -1

#define SDPOWER            -1
#define SDSS               26//8
#define LED_PIN            -1
#define PS_ON_PIN          -1
#define KILL_PIN           -1
#define ALARM_PIN          -1

#ifndef SDSUPPORT
// these pins are defined in the SD library if building with SD support
  #define SCK_PIN          21//9
  #define MISO_PIN         22//11
  #define MOSI_PIN         23//10
#endif

#ifdef ULTRA_LCD
   #ifdef NEWPANEL
     //now no buzzer installed
     #define BEEPER -1
     //LCD Pins option 1 works with rs-micro.com LCD option 2 works with Panelolu the easy way
                           //option 1 //option 2   
     #define LCD_PINS_RS        9     //8
     #define LCD_PINS_ENABLE    8     //9
     #define LCD_PINS_D4        7     //4
     #define LCD_PINS_D5        6     //5
     #define LCD_PINS_D6        5     //6
     #define LCD_PINS_D7        4     //7

     //The encoder and click button
     #define BTN_EN1 10// must be a hardware interrupt pin
     #define BTN_EN2 11// must be hardware interrupt pin
     #define BTN_ENC 12// the click
     //not connected to a pin currently
     #define SDCARDDETECT -1

     //from the same bit in the RAMPS Newpanel define
     //encoder rotation values
     #define encrot0 0
     #define encrot1 2
     #define encrot2 3
     #define encrot3 1

     #define BLEN_C 2
     #define BLEN_B 1
     #define BLEN_A 0

   #endif //Newpanel
 #endif //Ultipanel

#ifdef NUM_SERVOS
#define SERVO0_PIN 1
#endif