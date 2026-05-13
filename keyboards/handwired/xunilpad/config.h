/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


#define TAPPING_TERM 400
#define TAPPING_TOGGLE 2

// ROWS: Top to bottom, COLS: Left to right

#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5}
#define MATRIX_COL_PINS { F4, F5, F6, F7 }

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


#define ENCODERS_PAD_A { D3, B2 }
#define ENCODERS_PAD_B { D2, B6 }
#define ENCODER_RESOLUTION 1

#define DIP_SWITCH_PINS { B3, B1 }

#define OLED_DISPLAY_ADDRESS 0x3C
#define OLED_BRIGHTNESS 128
#define OLED_IC OLED_IC_SSD1306
#define OLED_DISPLAY_WIDTH 128
#define OLED_DISPLAY_HEIGHT 32
#define OLED_TIMEOUT 31000

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN D4
#define RGBLIGHT_LIMIT_VAL 100
#define RGBLIGHT_HUE_STEP 5
#define RGBLIGHT_SAT_STEP 5
#define RGBLIGHT_VAL_STEP 5
#define RGBLIGHT_SLEEP
#define RGBLIGHT_BREATHING
#define RGBLED_NUM 18

#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_TWINKLE

#define TAP_CODE_DELAY 10
