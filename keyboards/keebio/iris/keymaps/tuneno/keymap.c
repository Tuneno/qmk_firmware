// Mega Iris Layout

#include "Cryptor1.h"
#include "dual_encoder.h"

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_wrapper(
   QWERTY_L_R5,                        QWERTY_R_R5,
   QWERTY_L_R4,                        QWERTY_R_R4,
   QWERTY_L_R3,                        QWERTY_R_R3,
   QWERTY_L_R2,  IRIS,    _______,     QWERTY_R_R2,
   ALT_TAB, LOWER, KC_SPC,   KC_BSPC, RAISE, _______),

[_RAISE] = LAYOUT_wrapper(
   RAISE_L_R5,                           RAISE_R_R5,
   RAISE_L_R4,                           RAISE_R_R4,
   RAISE_L_R3,                           RAISE_R_R3,
   RAISE_L_R2,       _______,   _______, RAISE_R_R2,
   _______, _______, _______,   _______, KC_TRNS, _______),

[_LOWER] = LAYOUT_wrapper(
   LOWER_L_R5,                         LOWER_R_R5,
   LOWER_L_R4,                         LOWER_R_R4,
   LOWER_L_R3,                         LOWER_R_R3,
   LOWER_L_R2,       _______, _______, LOWER_R_R2,
   _______, KC_TRNS, _______, _______, KC_P0, KC_PDOT),

  [_DRAW] = LAYOUT_wrapper(
     TG(_DRAW), _______, _______, _______,  _______, KC_DEL,                            _______,  _______, _______, _______, _______, _______,
     _______,   _______,  KC_7,    KC_8,    KC_9,    KC_BSPC,                           _______,  _______, _______, _______, _______, _______,
     KC_LALT,   SAVE,     KC_4,    KC_5,    KC_6,    KC_ENT,                            _______,  _______, _______, _______, _______, _______,
     KC_LSFT,   REGEN,    KC_1,    KC_2,    KC_3,    _______, _______,         _______, _______, _______, _______, _______, _______, _______,
                                          KC_0,      KC_PDOT, KC_LCTL,                      _______, _______, _______)



};


      
