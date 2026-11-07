//Cryptor1 Function for 1 Encoder (Planck / Preonic)

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] =   { ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_LOWER] =    { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [_RAISE] =    { ENCODER_CCW_CW(S(KC_TAB), KC_TAB)},
    [_GMG] =      { ENCODER_CCW_CW(_______, _______)},
};
#endif                                              