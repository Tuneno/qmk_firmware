
#include QMK_KEYBOARD_H
#pragma once

// #include "wrappers.h"

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
  GLOVIA,
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

#define TAPPING_TERM 200

enum {
  CAPS= 0,
  EXIT  
};

qk_tap_dance_action_t tap_dance_actions[] = 
{
  [CAPS]=ACTION_TAP_DANCE_DOUBLE(KC_TAB,KC_CAPS),
  [EXIT]= ACTION_TAP_DANCE_DOUBLE(KC_ESC,CLOSE)
};


// Macros
// Macro Establishment
bool process_record_user(uint16_t keycode, keyrecord_t *record) 
{
	switch (keycode) 
	{
		case RIP:
			if (record->event.pressed) 
			{
				// when keycode RIP is pressed
				SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_A) SS_UP(X_LCTRL) SS_TAP(X_DELETE));
			} 
			break;

		case PREONIC:
			if (record->event.pressed)
			{
				// when keycode PREONIC is pressed
				SEND_STRING("cd /c/qmk_firmware/qmk_firmware/" SS_TAP(X_ENTER) "make preonic/rev3:nickjschaeffer" SS_TAP(X_ENTER));
			}
			break;

		case HIDEOUT:
			if (record->event.pressed)
			{
				// when keycode HIDEOUT is pressed
				SEND_STRING(SS_TAP(X_ENTER) "/hideout" SS_TAP(X_ENTER));
			}
			break;

		case FLASK:
			if (record->event.pressed)
			{
				// when keycode PREONIC is pressed
				SEND_STRING(SS_TAP(X_Q) SS_TAP(X_W) SS_TAP(X_E) SS_TAP(X_R) SS_TAP(X_T));
			}
			break;
		case TRADE:
			if (record->event.pressed)
			{
				// when keycode PREONIC is pressed
				SEND_STRING(SS_TAP(X_ENTER) SS_DOWN(X_LCTRL) SS_TAP(X_V) SS_UP(X_LCTRL) SS_TAP(X_ENTER));
			}
			break;
		case REMAINING:
			if (record->event.pressed)
			{
				// when keycode HIDEOUT is pressed
				SEND_STRING(SS_TAP(X_ENTER) "/remaining" SS_TAP(X_ENTER));
			}
			break;
		case GLOVIA:
			if (record->event.pressed)
			{
				// when keycode HIDEOUT is pressed
				SEND_STRING("nschaef" SS_TAP(X_TAB) "Gunner2!" SS_TAP(X_ENTER));
			}
			break;
	}
	return true;
};