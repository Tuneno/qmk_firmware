
#include QMK_KEYBOARD_H
#pragma once

#include "wrappers.h"

enum userspace_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _POE,
};

enum custom_keycodes {
  POP=SAFE_RANGE,
  RIP,
  CLOSE,
  SNAP_L,
  SNAP_R,
  MIN,
  MAX,
  WINCLS,
  SWAP_L,
  SWAP_R,
  MINALL,
  RAISE,
  SHFT,
  PREONIC,
  HIDEOUT,
  FLASK,
  TRADE,
  REMAINING,
};

// Key Combo Definitions
#define CLOSE LALT(KC_F4) // Kill application
#define SNAP_L LGUI(KC_LEFT) // Snap window to left side of display
#define SNAP_R LGUI(KC_RGHT) // Snap window to right side of display
#define MIN LGUI(KC_DOWN) // Shrink window
#define MAX LGUI(KC_UP) // Maximize window
#define WINCLS LCTL(KC_W) // Close a single web browser window
#define SWAP_L SGUI(KC_LEFT) // Swap application to left display
#define SWAP_R SGUI(KC_RGHT) // Swap application to right display
#define MINALL LGUI(KC_M) // Minimize all open applications 
#define RAISE MO(_RAISE) // Raise Layer
#define LOWER MO(_LOWER) // Lower Layer
#define POE TG(_POE) // Path of Exile Layer
#define SHFT OSM(MOD_LSFT) //OSM Left Shift
#define CTLENT CTL_T(KC_ENT) // Enter on tap & Control on hold (for split spacebar)
#define BKRAISE LT(_RAISE,KC_BSPC) // Backspace on tap & Raise layer on hold
#define TSKMNGR LCA(KC_DEL) // Control + Alt + Delete = Task Manager

// Encoder Layer asks
#define MODS_ALT_MASK (MOD_BIT(KC_LALT)) // Make ALT layer for encoder use 
#define MODS_CTRL_MASK (MOD_BIT(KC_LCTL)) // Make CTRL layer for encoder use
#define MODS_GUI_MASK (MOD_BIT(KC_LGUI)) // Make GUI alyer for encoder use

// Tap Dancing
enum {
  CAPS= 0,
  EXIT  
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [CAPS]=ACTION_TAP_DANCE_DOUBLE(KC_TAB,KC_CAPS),
  [EXIT]= ACTION_TAP_DANCE_DOUBLE(KC_ESC,CLOSE)
};