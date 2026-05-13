#include QMK_KEYBOARD_H
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define _NAV 0
#define _CODER 1

		[_NAV] = LAYOUT_pad(
			KC_HOME, KC_UP,   KC_END,
			KC_LEFT, KC_DOWN, KC_RGHT,
            KC_LCTL, TG(1), KC_RSFT
		),
		[_CODER] = LAYOUT_pad(
			KC_F5, KC_UP, KC_F10,
			KC_LEFT, KC_DOWN, KC_RGHT,
			KC_LCTL, TG(1), KC_RSFT
		)
	};

bool oled_task_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _CODER:
            oled_write_P(PSTR("Coder\n"), false);
            break;
    }
    return true;
}
