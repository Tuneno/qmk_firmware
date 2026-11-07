//Cryptor1 Definition for Dual Encoder (Iris)

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] =    { ENCODER_CCW_CW(KC_PGUP, KC_PGDN),        ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_LOWER]  =    { ENCODER_CCW_CW(_______, _______),        ENCODER_CCW_CW(C(KC_Z), C(KC_Y)) },
    [_RAISE]  =    { ENCODER_CCW_CW(S(KC_TAB), (KC_TAB)),     ENCODER_CCW_CW(_______, _______)  },
    [_DRAW]   =    { ENCODER_CCW_CW(C(KC_Z), C(KC_Y)),        ENCODER_CCW_CW(_______, _______)  },
};
#endif
