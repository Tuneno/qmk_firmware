#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_MUTE,    TO(1),              _______,
        LALT(KC_Z), LSFT(LALT(KC_F10)), LALT(KC_F10),
        KC_MPRV,    KC_MPLY,            KC_MNXT
    ),

    [1] = LAYOUT(
        RESET  , TO(0),   _______,
        KC_F1,   KC_F2,   KC_F3,
        KC_F4,   KC_F4,   KC_F5
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (IS_LAYER_ON(1))
        {
            if (clockwise) {
                tap_code(KC_WH_U);
            } else {
                tap_code(KC_WH_D);
            }
        }
        else
        {
            if (clockwise)
            {
            register_code(KC_LCTL);
            register_code(KC_UP);
            unregister_code(KC_LCTL);
            unregister_code(KC_UP);
            } 
            else 
            {
            register_code(KC_LCTL);
            register_code(KC_DOWN);
            unregister_code(KC_LCTL);
            unregister_code(KC_DOWN);
            }
        }
    }
};