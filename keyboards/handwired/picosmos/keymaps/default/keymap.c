#include QMK_KEYBOARD_H
#include "quantum.h"

enum layers {
    _BASE,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        // LEFT HALF
        // GP16 - Function row (4 keys: col 3,4,5,6)
        KC_F2,   KC_F5,   KC_F10,  KC_F11,
        // GP17 - Number row (7 keys: col 0,1,2,3,4,5,6)
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME,
        // GP18 - QWERTY top (7 keys: col 0,1,2,3,4,5,6)
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_END,
        // GP19 - Home row (8 keys: col 0,1,2,3,4,5,6,7)
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_EQL,  KC_LGUI,
        // GP20 - Bottom row (8 keys: col 0,1,2,3,4,5,7,8)
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT, KC_RGHT,
        // GP21 - Thumb cluster (4 keys: col 2,3,7,8)
        KC_LBRC, KC_RBRC, KC_ENT,  KC_LEFT,

        // RIGHT HALF
        // GP16 - Function row (4 keys: col 3,4,5,6)
        KC_F12, UP(0x00E5, 0x00C5), UP(0x00E4, 0x00C4), UP(0x00F6, 0x00D6),
        // GP17 - Number row (7 keys: col 0,1,2,3,4,5,6)
        KC_VOLU, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        // GP18 - QWERTY top (7 keys: col 0,1,2,3,4,5,6)
        KC_VOLD, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        // GP19 - Home row (8 keys: col 0,1,2,3,4,5,6,7)
        KC_PSCR, KC_MINS, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_BSLS,
        // GP20 - Bottom row (8 keys: col 0,1,2,3,4,5,7,8)
        TG(_FN), KC_UP,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
        // GP21 - Thumb cluster (4 keys: col 2,3,7,8)
        KC_DOWN, KC_SPC,  KC_QUOT, KC_GRV
    ),

        // RIGHT HALF
    [_FN] = LAYOUT(
        // LEFT HALF
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        // RIGHT HALF
        // GP16 - Function row (4 keys: col 3,4,5,6)
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // GP17 - Number row (7 keys: col 0,1,2,3,4,5,6)
        KC_INS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // GP18 - QWERTY top (7 keys: col 0,1,2,3,4,5,6)
        KC_PGUP, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
        // GP19 - Home row (8 keys: col 0,1,2,3,4,5,6,7)
        KC_PGDN, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
        // GP20 - Bottom row (8 keys: col 0,1,2,3,4,5,7,8)
        TG(_FN), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // GP21 - Thumb cluster (4 keys: col 2,3,7,8)
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};