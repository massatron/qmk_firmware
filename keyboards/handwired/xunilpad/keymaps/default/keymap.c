#include QMK_KEYBOARD_H
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
* ,-------------------.
* | NL | /  | *  | NA |
* |----|----|----|----|
* | 7  | 8  | 9  | NA |
* |----|----|----|----|
* | 4  | 5  | 6  |  - |
* |----|----|----|----|
* | 1  | 2  | 3  |  + |
* |----|----|----|----|
* | 0  | .  |ENTR|TG 1|
* `-------------------'
*/
#define _FN 0
#define _NUMPAD 1
#define _NAV 2
#define _MEDIA  3
#define _LED 4

     [_FN] = LAYOUT_pad(
        KC_F10, KC_F11, KC_F12,
        KC_F7,   KC_F8,   KC_F9,
        KC_F4,   KC_F5,   KC_F6, KC_UP,
        KC_F1,   KC_F2,   KC_F3, KC_DOWN,
        KC_LEFT, KC_RGHT ,KC_PENT, TG(1)
    ),

    [_NUMPAD] = LAYOUT_pad(
        KC_CALC,  KC_PSLS, KC_PAST,
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,   KC_PMNS,
        KC_P1,   KC_P2,   KC_P3,   KC_PPLS,
        KC_P0,   KC_PDOT, KC_PENT, TG(2)
    ),
	[_NAV] = LAYOUT_pad(
        _______, _______, _______,
        KC_HOME, KC_UP,   KC_PGUP,
        KC_LEFT, XXXXXXX, KC_RGHT, _______,
        KC_END,  KC_DOWN, KC_PGDN, _______,
        _______, KC_INS,  KC_DEL,  TG(3)
    ),
	[_MEDIA] = LAYOUT_pad(
        KC_F10, KC_F11, KC_F12,
        KC_F7,   KC_F8,   KC_F9,
        KC_F4,   KC_F5,   KC_F6, KC_VOLU,
        KC_F1,   KC_F2,   KC_F3, KC_VOLD,
        KC_MPRV, KC_MNXT ,RGB_TOG, TG(4)
    ),
	[_LED] = LAYOUT_pad(
        RGB_MODE_RGBTEST, RGB_MOD, RGB_RMOD,
        RGB_MODE_PLAIN,   RGB_MODE_BREATHE,   RGB_MODE_RAINBOW,
        RGB_MODE_SWIRL,   RGB_MODE_SNAKE,   RGB_MODE_KNIGHT, RGB_MOD,
        RGB_MODE_KNIGHT,   RGB_MODE_GRADIENT,   KC_NO, RGB_RMOD,
        KC_NO, KC_NO, KC_NO, TG(0)
    )
};


bool encoder_update_user(uint8_t index, bool clockwise) {

	if (index == 1) { /* First encoder */

		switch (get_highest_layer(layer_state)) {
			case _NUMPAD:
				if (clockwise) {

				}
				else {

				}
				break;
			case _FN:
				if (clockwise) {
					tap_code(KC_F11);
				}
				else {
					tap_code(KC_F10);
				}
			break;
			case _MEDIA:
				if (clockwise) {
					tap_code(KC_VOLU);
				}
				else {
					tap_code(KC_VOLD);
				}

				break;
			case _LED:
				if (clockwise) {
					oled_write_P(PSTR("SHIFT IT UP"), false);
				}
				else {
					oled_write_P(PSTR("CRAPPENING"), false);
				}

				break;
			case _NAV:
				if (clockwise) {
					oled_write_P(PSTR("->"), false);
					tap_code(KC_RIGHT);
				}
				else {
					oled_write_P(PSTR("<-"), false);
					tap_code(KC_LEFT);
				}

		}
	}
	else if (index == 0) { /* Second encoder */

	}


	return false;

}


bool oled_task_user(void) {

    switch (get_highest_layer(layer_state)) {
        case _NUMPAD:
            oled_write_P(PSTR("Numbers     \n"), false);
            break;
        case _FN:;
			oled_write_P(PSTR("F Keys     \n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation    \n"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media      \n"), false);
            break;
        case _LED:
            oled_write_P(PSTR("LED       \n"), false);
            break;
    }

    // Host Keyboard LED Status
    // led_t led_state = host_keyboard_led_state();
    // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    return false;
}


bool dip_switch_update_user(uint8_t index, bool active)
{

	switch (index) {
        case 0:		//ENC0_SW
			if(active) //ENC0 pressed
			{

			}
			else //ENC0 released
            {
			//do nothing/////**
			}
            break;
        case 1:		//ENC1_SW
			if(active) //ENC1 pressed
			{
				switch (get_highest_layer(layer_state)) {
					case _NUMPAD:
						layer_on(_FN);
                        layer_off(_MEDIA);
                        layer_off(_LED);
                        layer_off(_NUMPAD);
                        layer_off(_NAV);
						break;
					case _FN:
						layer_on(_MEDIA);
                        layer_off(_FN);
                        layer_off(_LED);
                        layer_off(_NUMPAD);
                        layer_off(_NAV);
						break;
					case _MEDIA:
						layer_on(_LED);
                        layer_off(_FN);
                        layer_off(_MEDIA);
                        layer_off(_NUMPAD);
                        layer_off(_NAV);
						break;
					case _LED:
						layer_on(_NUMPAD);
                        layer_off(_MEDIA);
                        layer_off(_LED);
                        layer_off(_FN);
                        layer_off(_NAV);
						break;
					case _NAV:
						layer_on(_NAV);
                        layer_off(_MEDIA);
                        layer_off(_LED);
                        layer_off(_FN);
                        layer_off(_NUMPAD);
						break;
                    }
			}
			else //ENC0 released
            {
			//do nothing/////**
			}
            break;
	}
	return false;
}


#ifdef RGBLIGHT_ENABLE

	// How long (in milliseconds) to wait between animation steps for each of the "Solid color breathing" animations
	const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {30, 20, 10, 5};

	// How long (in milliseconds) to wait between animation steps for each of the "Cycling rainbow" animations
	const uint8_t RGBLED_RAINBOW_MOOD_INTERVALS[] PROGMEM = {120, 60, 30};

	// How long (in milliseconds) to wait between animation steps for each of the "Swirling rainbow" animations
	const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 20};

	// How long (in milliseconds) to wait between animation steps for each of the "Snake" animations
	const uint8_t RGBLED_SNAKE_INTERVALS[] PROGMEM = {100, 50, 20};

	// How long (in milliseconds) to wait between animation steps for each of the "Knight" animations
	const uint8_t RGBLED_KNIGHT_INTERVALS[] PROGMEM = {127, 63, 31};

	// How long (in milliseconds) to wait between animation steps for each of the "Twinkle" animations
	const uint8_t RGBLED_TWINKLE_INTERVALS[] PROGMEM = {50, 25, 10};

	// These control which hues are selected for each of the "Static gradient" modes
	const uint8_t RGBLED_GRADIENT_RANGES[] PROGMEM = {255, 170, 127, 85, 64};
/*
	const rgblight_segment_t PROGMEM default_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{1, 3, HSV_BLUE},
		{4, 3, HSV_RED},
		{7, 4, HSV_PURPLE},
		{11, 4, HSV_GREEN},
		{15, 4, HSV_YELLOW}
	);
	// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
	const rgblight_segment_t PROGMEM media_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{9, 2, HSV_CYAN}
	);
	// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
	const rgblight_segment_t PROGMEM fn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{11, 2, HSV_PURPLE}
	);
	// Light LEDs 13 & 14 in green when keyboard layer 3 is active
	const rgblight_segment_t PROGMEM led_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{13, 2, HSV_GREEN}
	);

	// Now define the array of layers. Later layers take precedence
	const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
		default_layer,
		media_layer,    // Overrides caps lock layer
		fn_layer,    // Overrides other layers
		led_layer     // Overrides other layers
	);

	void keyboard_post_init_user(void) {
		// Enable the LED layers
		rgblight_layers = my_rgb_layers;
	}


	bool led_update_user(led_t led_state) {
		rgblight_set_layer_state(0, led_state.caps_lock);
		return true;
	}

	layer_state_t default_layer_state_set_user(layer_state_t state) {
		rgblight_set_layer_state(1, layer_state_cmp(state, _NUMPAD));
		return state;
	}

	layer_state_t layer_state_set_user(layer_state_t state) {
		rgblight_set_layer_state(2, layer_state_cmp(state, _FN));
		rgblight_set_layer_state(3, layer_state_cmp(state, _MEDIA));
		rgblight_set_layer_state(4, layer_state_cmp(state, _LED));
		return state;
	}
	*/
#endif

#ifdef RGB_MATRIX_ENABLE
// const is31_led PROGMEM g_is31_leds[RGB_MATRIX_LED_COUNT] = {
//     { 0, K_14, J_14, L_14 },
//     { 0, K_13, J_13, L_13 },
//     { 0, K_12, J_12, L_12 },
//     { 0, K_11, J_11, L_11 },
//     { 0, K_10, J_10, L_10 },
//     { 0, K_9,  J_9,  L_9 },
//     { 0, K_8,  J_8,  L_8 },
//     { 0, K_7,  J_7,  L_7 },
//     { 0, K_6,  J_6,  L_6 },
//     { 0, K_5,  J_5,  L_5 },
//     { 0, K_4,  J_4,  L_4 },
//     { 0, K_3,  J_3,  L_3 },
//     { 0, K_2,  J_2,  L_2 },
//     { 0, K_1,  J_1,  L_1 },
//     { 0, H_14, G_14, I_14 },
//     { 0, H_13, G_13, I_13 },
//     { 0, H_12, G_12, I_12 },    { 0, H_11, G_11, I_11 }}

// led_config_t g_led_config = {
//     {
//         { 13, 12, 11,     10,      9,  8,      7,      6,  5,  4,  3,  2,      1,  0 },
//         { 27, 26, 25,     24,     23, 22,     21,     20, 19, 18, 17, 16,     15, 14 },
//         { 40, 39, 38,     37,     36, 35,     34,     33, 32, 31, 30, 29, NO_LED, 28 },
//         { 53, 52, 51,     50,     49, 48,     47,     46, 45, 44, 43, 42, NO_LED, 41 },
//         { 62, 61, 60, NO_LED, NO_LED, 59, NO_LED, NO_LED, 58, 57, 56, 55, NO_LED, 54 }
//     }, {
//         { 216,   0 }, { 192,   0 }, { 176,   0 }, { 160,   0 }, { 144,   0 }, { 128,   0 }, { 112,   0 }, {  96,   0 }, {  80,   0 }, {  64,   0 }, {  48,   0 }, {  32,   0 }, {  16,   0 }, {   0,   0 },
//         { 220,  16 }, { 200,  16 }, { 184,  16 }, { 168,  16 }, { 152,  16 }, { 136,  16 }, { 120,  16 }, { 104,  16 }, {  88,  16 }, {  72,  16 }, {  56,  16 }, {  40,  16 }, {  24,  16 }, {   4,  16 },
//         { 214,  32 }, { 188,  32 }, { 172,  32 }, { 156,  32 }, { 140,  32 }, { 124,  32 }, { 108,  32 }, {  92,  32 }, {  76,  32 }, {  60,  32 }, {  44,  32 }, {  28,  32 },               {   6,  32 },
//         { 224,  48 },               { 208,  48 }, { 186,  48 }, { 164,  48 }, { 148,  48 }, { 132,  48 }, { 116,  48 }, { 100,  48 }, {  84,  48 }, {  68,  48 }, {  52,  48 }, {  36,  48 }, {   9,  48 },
//         { 224,  64 }, { 208,  64 }, { 192,  64 },                                           { 176,  64 },                             { 160,  64 }, { 102,  64 }, {  42,  64 }, {  22,  64 }, {   2,  64 }
//     }, {
//         1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
//         4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
//         1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1,
//         1,    1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
//         1, 1, 1,          1,       1, 4, 1, 1, 1
//     }
// };

// bool rgb_matrix_indicators_kb(void) {
//     if (!rgb_matrix_indicators_user()) {
//         return false;
//     }
//     if (host_keyboard_led_state().caps_lock) {
//         rgb_matrix_set_color(40, 0xFF, 0xFF, 0xFF);
//     }
//     return true;
// }
/*
key codes

RGB_TOG		Toggle RGB lighting on or off
RGB_MODE_FORWARD	RGB_MOD	Cycle through modes, reverse direction when Shift is held
RGB_MODE_REVERSE	RGB_RMOD	Cycle through modes in reverse, forward direction when Shift is held
RGB_HUI		Increase hue, decrease hue when Shift is held
RGB_HUD		Decrease hue, increase hue when Shift is held
RGB_SAI		Increase saturation, decrease saturation when Shift is held
RGB_SAD		Decrease saturation, increase saturation when Shift is held
RGB_VAI		Increase value (brightness), decrease value when Shift is held
RGB_VAD		Decrease value (brightness), increase value when Shift is held
RGB_MODE_PLAIN	RGB_M_P 	Static (no animation) mode
RGB_MODE_BREATHE	RGB_M_B	Breathing animation mode
RGB_MODE_RAINBOW	RGB_M_R	Rainbow animation mode
RGB_MODE_SWIRL	RGB_M_SW	Swirl animation mode
RGB_MODE_SNAKE	RGB_M_SN	Snake animation mode
RGB_MODE_KNIGHT	RGB_M_K	"Knight Rider" animation mode
RGB_MODE_XMAS	RGB_M_X	Christmas animation mode
RGB_MODE_GRADIENT	RGB_M_G	Static gradient animation mode
RGB_MODE_RGBTEST	RGB_M_T	Red, Green, Blue test animation mode
RGB_MODE_TWINKLE	RGB_M_TW	Twinkle animation mode

animations:
RGBLIGHT_MODE_STATIC_LIGHT	None	Solid color (this mode is always enabled)
RGBLIGHT_MODE_BREATHING	0,1,2,3	Solid color breathing
RGBLIGHT_MODE_RAINBOW_MOOD	0,1,2	Cycling rainbow
RGBLIGHT_MODE_RAINBOW_SWIRL	0,1,2,3,4,5	Swirling rainbow
RGBLIGHT_MODE_SNAKE	0,1,2,3,4,5	Snake
RGBLIGHT_MODE_KNIGHT	0,1,2	Knight
RGBLIGHT_MODE_CHRISTMAS	None	Christmas
RGBLIGHT_MODE_STATIC_GRADIENT	0,1,..,9	Static gradient
RGBLIGHT_MODE_RGB_TEST	None	RGB Test
RGBLIGHT_MODE_ALTERNATING	None	Alternating
RGBLIGHT_MODE_TWINKLE	0,1,2,3,4,5	Twinkle

*/
#endif
