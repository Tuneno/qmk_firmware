#pragma once
#include "tuneno.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x12_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

#define QWERTY_L1        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define QWERTY_L2        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define QWERTY_L3        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define QWERTY_R1        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define QWERTY_R2        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define QWERTY_R3        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define NUMBERS_L        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define NUMBERS_R        KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define __BLANK__        _______, _______, _______, _______, _______


#define LOWER_L1_        SWAP_L,  SWAP_R,  SNAP_L,  SNAP_R,  SWAP_R
#define LOWER_L2_        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT
#define LOWER_L3_        KC_HOME, MIN,     MAX,     KC_END,  _______

#define LOWER_R1_        _______, KC_P7,   KC_P8,   KC_P9,  KC_PPLS
#define LOWER_R2_        _______, KC_P4,   KC_P5,   KC_P6,  KC_PPLS
#define LOWER_R3_        _______, KC_P1,   KC_P2,   KC_P3,  KC_ENT


#define RAISE_L1_        KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC
#define RAISE_L2_        KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5
#define RAISE_L3_        KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11

#define RAISE_R1_        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define RAISE_R2_        KC_F6,   KC_MINS, KC_KC_EQL, KC_LBRC, KC_RBRC
#define RAISE_R3_        KC_F12,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR

// clang-format on
