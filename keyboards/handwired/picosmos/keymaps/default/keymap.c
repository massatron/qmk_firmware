#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum layers {
    _BASE,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        // Left half
        // Row 0 (GP21) - 4 keys: col 2,3,7,8
        KC_LBRC, KC_RBRC, KC_ENT,  KC_LALT,
        // Row 1 (GP20) - 8 keys: col 0,1,2,3,4,5,7,8
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LEFT, KC_LGUI,
        // Row 2 (GP19) - 8 keys: col 0,1,2,3,4,5,6,7
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_EQL,  KC_RGHT,
        // Row 3 (GP18) - 7 keys: col 0,1,2,3,4,5,6
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_END,
        // Row 4 (GP17) - 7 keys: col 0,1,2,3,4,5,6
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME,
        // Row 5 (GP16) - 4 keys: col 3,4,5,6
        KC_F2,   KC_F5,   KC_F10,  KC_F11,

        // Right half
        // Row 6 (GP21 mirror) - 4 keys: col 2,3,7,8
        KC_QUOT, KC_DQUO, KC_SPC,  KC_DOWN,
        // Row 7 (GP20 mirror) - 8 keys: col 0,1,2,3,4,5,7,8
        KC_RCTL, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    KC_UP,   TG(_FN),
        // Row 8 (GP19 mirror) - 8 keys: col 0,1,2,3,4,5,6,7
        KC_BSLS, KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,    KC_MINS, KC_PSCR,
        // Row 9 (GP18 mirror) - 7 keys: col 0,1,2,3,4,5,6
        KC_BSPC, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,    KC_GRV,
        // Row 10 (GP17 mirror) - 7 keys: col 0,1,2,3,4,5,6
        KC_DEL,  KC_0,    KC_9,    KC_8,    KC_7,    KC_6,    KC_LGUI,
        // Row 11 (GP16 mirror) - 4 keys: col 3,4,5,6
        KC_GRV,  SE_ODIA, SE_ADIA, SE_ARNG
    ),

    [_FN] = LAYOUT(
        // Left half
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        // Right half
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(_FN),
        KC_TRNS, KC_TRNS, KC_RIGHT, KC_DOWN, KC_LEFT, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};