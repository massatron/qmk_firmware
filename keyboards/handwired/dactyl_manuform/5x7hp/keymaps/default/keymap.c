#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN     1

// Some basic macros
// #define TASK   LCTL(LSFT(KC_ESC))
// #define TAB_R  LCTL(KC_TAB)
// #define TAB_L  LCTL(LSFT(KC_TAB))
// #define TAB_RO LCTL(LSFT(KC_T))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x7(
        // left hand
        QK_GESC,        KC_1,    KC_2,    KC_3,     KC_4,   KC_5,   KC_SLSH,
        KC_TAB,         KC_Q,    KC_W,    KC_E,     KC_R,   KC_T,   KC_HOME,
        KC_LALT,  KC_A,    KC_S,    KC_D,     KC_F,   KC_G,   KC_EQL,
        KC_LCTL,        KC_Z,    KC_X,    KC_C,     KC_V,   KC_B,
                                 KC_LBRC, KC_RBRC,
                                                            KC_ENT, KC_LSFT,
                                                                     KC_LEFT, KC_PGUP,
                                                                     KC_RGHT, KC_PGDN,
        // right hand
                KC_LGUI,        KC_6,    KC_7,    KC_8,     KC_9,   KC_0,   KC_DEL,
                KC_END,         KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,   KC_BSPC,
                KC_MINS,        KC_H,    KC_J,    KC_K,     KC_L,   KC_SCLN,KC_BSLS,
                                KC_N,    KC_M,    KC_COMMA, KC_DOT, KC_SLSH,KC_RCTL,
                                                  KC_QUOT,  KC_GRV,
                KC_RSFT,        KC_SPACE,
       KC_PSCR, KC_UP,
       TG(1), KC_DOWN
    ),

    [_FN] = LAYOUT_5x7(
        // left hand
        KC_TRNS,   KC_F1,     KC_F2,      KC_F3,    KC_F4,     KC_F5,    KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
        QK_BOOT,   KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,   KC_TRNS,
                              KC_TRNS,    KC_TRNS,
                                                                KC_TRNS, KC_TRNS,
                                                                         KC_TRNS, KC_TRNS,
                                                                                  KC_TRNS, KC_TRNS,
        // right hand
        KC_TRNS,   KC_F6,      KC_F7,      KC_F8,     KC_F9,     KC_F10,   KC_F11,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_F12,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,
                   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,  QK_BOOT,
                                         KC_TRNS,   KC_TRNS,
            KC_DEL,  KC_F5,
        KC_INS, KC_F10,
        TG(1), KC_F11
    ),
};
