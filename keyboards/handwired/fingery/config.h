#pragma once
#define BOOTMAGIC_LITE
#define BOOTMAGIC_LITE_ROW 0    // Change to the row of your desired key
#define BOOTMAGIC_LITE_COLUMN 0 // Change to the column of your desired key
#define TAPPING_TERM 400
#define TAPPING_TOGGLE 2

// ROWS: Top to bottom, COLS: Left to right
#define MATRIX_ROWS 3
#define MATRIX_COLS 3
#define MATRIX_ROW_PINS { C6, E6, B5 }
#define MATRIX_COL_PINS { F4, F5, F6 }

#define OLED_DISPLAY_ADDRESS 0x3C
#define OLED_BRIGHTNESS 128
#define OLED_IC OLED_IC_SSD1306
#define OLED_DISPLAY_WIDTH 128
#define OLED_DISPLAY_HEIGHT 32
#define OLED_TIMEOUT 31000

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define TAP_CODE_DELAY 10
