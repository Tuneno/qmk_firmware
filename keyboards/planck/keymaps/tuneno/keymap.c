// Cryptor Planck

#include "Tuneno.h"
#include "single_encoder_planck.h"

#define LAYOUT_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_wrapper(
QWERTY_L_R4, QWERTY_R_R4,
QWERTY_L_R3, QWERTY_R_R3,
QWERTY_L_R2, QWERTY_R_R2,
QWERTY_L_R1, QWERTY_R_R1),

[_LOWER] = LAYOUT_wrapper(
LOWER_L_R4, LOWER_R_R4,
LOWER_L_R3, LOWER_R_R3,
LOWER_L_R2, LOWER_R_R2,
LOWER_L_R1, LOWER_R_R1),

[_RAISE] = LAYOUT_wrapper(
RAISE_L_R4, RAISE_R_R4,
RAISE_L_R3, RAISE_R_R3,
RAISE_L_R2, RAISE_R_R2,
RAISE_L_R1, RAISE_R_R1),

};              
