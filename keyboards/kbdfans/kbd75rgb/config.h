/* Copyright 2021 DZTECH <moyi4681@Live.cn>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once


#define MATRIX_ROW_PINS { F0, F1, B0, B1, B2, C6 }
#define MATRIX_COL_PINS { F7, F6, F5, F4, E6, B3, B7, D0, D1, D2, D3, D5, D4, D6, D7}

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define USB_SUSPEND_WAKEUP_DELAY 5000
#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES


#define RGB_DI_PIN C7
#define RGBLED_NUM 84
#define RGB_MATRIX_LED_COUNT RGBLED_NUM


//#define ENABLE_RGB_MATRIX_CYCLE_ALL


#define ENABLE_RGB_MATRIX_STAR_LIGHT
#define ENABLE_RGB_MATRIX_HOME_ROW_TWINKLE




#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspendedz

#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
//#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_ALL
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10
