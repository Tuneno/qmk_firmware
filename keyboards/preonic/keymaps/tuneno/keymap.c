 // MEGA Preonic Layout
 

#include QMK_KEYBOARD_H

// Layer Names
enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _POE
};

// Macro Names
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
  TEST
};

// Macro Definition
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


// Encoder Stuff
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_grid( \
  POE,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    RIP, \
  TD(EXIT),KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,  \
  TD(CAPS),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
  _______, KC_MNXT, KC_MPLY, KC_LGUI, LOWER,   KC_SPC,  KC_LCTL,  RAISE,   TSKMNGR, _______,KC_LCTL, KC_LALT  \
),


[_LOWER] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______, \
  CLOSE,   SWAP_L,  SNAP_L,  SNAP_R,  SWAP_R,  _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_TRNS,  \
  WINCLS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,  _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, \
  MINALL,  KC_HOME, MIN,     MAX,     KC_END,  _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_ENT,  _______, \
  _______, _______, _______, _______, KC_TRNS, _______, KC_LSFT, KC_P0,   KC_P0,   KC_PDOT, KC_ENT,  _______ \
),


[_RAISE] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_TRNS, _______, _______, PREONIC, RESET    \
),


[_POE] = LAYOUT_preonic_grid( \
  KC_TRNS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, REMAINING, TRADE, HIDEOUT, RALT(KC_D), _______, _______, _______, _______, _______, _______, _______,  \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, _______, _______, _______, _______, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, KC_LCTL,   FLASK, _______, _______, _______, _______, _______, _______ \
)

};


// Encoder
void encoder_update_user(uint8_t index, bool clockwise) 
{
	if (get_mods() & MODS_ALT_MASK) 
	{
			if (clockwise)
			{
				register_code(KC_TAB);
				unregister_code(KC_TAB);
			} 
			else 
			{
				register_code(KC_LSFT);
				register_code(KC_TAB);
				unregister_code(KC_LSFT);
				unregister_code(KC_TAB);
			}
	} 
		else 
		{
			if (get_mods() & MODS_CTRL_MASK) 
			{
				if (clockwise) 
				{
					register_code(KC_TAB);
					unregister_code(KC_TAB);
				} 
				else 
				{
					register_code(KC_LSFT);
					register_code(KC_TAB);
					unregister_code(KC_LSFT);
					unregister_code(KC_TAB);
				}
			}
		else
		{
			if (get_mods() & MODS_GUI_MASK)
			{
				if (clockwise)
				{
					register_code(KC_LCTL);
					register_code(KC_RGHT);
					unregister_code(KC_LCTL);
					unregister_code(KC_RGHT);
				}
				else
				{
					register_code(KC_LCTL);
					register_code(KC_LEFT);
					unregister_code(KC_LCTL);
					unregister_code(KC_LEFT);
				}
			} 
			else 
			{
				if (IS_LAYER_ON(_LOWER))
				{
					if (clockwise) 
					{
						tap_code(KC_VOLU);
					}
					else
					{
						tap_code(KC_VOLD);
					}
				}
/*				else
					{
					if(IS_LAYER_ON(_LR))
					{
						if (clockwise)
						{
						register_code(KC_EQL);
						unregister_code(KC_EQL);
					}
					else
					{
						register_code(KC_MINS);
						unregister_code(KC_MINS);
					}
				} */
					else
					{
						if (clockwise)
						{
							register_code(KC_PGDN);
							unregister_code(KC_PGDN);
						}
						else
						{
							register_code(KC_PGUP);
							unregister_code(KC_PGUP);
						}
					}
				}
			}
		}
}


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
	}
	return true;
};

// SEND_STRING(SS_TAP(SGUI(KC_TAB)) SS_TAP(SGUI(KC_ENT)));

