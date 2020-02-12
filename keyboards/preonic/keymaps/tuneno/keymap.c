// Absolutely MEGA Preonic Layout
 

#include "tuneno.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_grid( \
  POE,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    RIP, \
  TD(EXIT),KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,  \
  TD(CAPS),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
  _______, KC_MNXT, KC_MPLY, KC_LGUI, LOWER,   KC_SPC,  KC_LCTL,  RAISE,   TSKMNGR, _______,KC_LCTL, KC_LALT  \
),


[_LOWER] = LAYOUT_preonic_grid( \
  _______, GLOVIA,  _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______, \
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
				register_code(KC_LSFT);
				register_code(KC_TAB);
				unregister_code(KC_LSFT);
				unregister_code(KC_TAB);
			} 
			else 
			{
				register_code(KC_TAB);
				unregister_code(KC_TAB);
			}
	} 
		else 
		{
			if (get_mods() & MODS_CTRL_MASK) 
			{
				if (clockwise) 
				{
					register_code(KC_LSFT);
					register_code(KC_TAB);
					unregister_code(KC_LSFT);
					unregister_code(KC_TAB);
				} 
				else 
				{
					register_code(KC_TAB);
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
					register_code(KC_LEFT);
					unregister_code(KC_LCTL);
					unregister_code(KC_LEFT);
				}
				else
				{
					register_code(KC_LCTL);
					register_code(KC_RGHT);
					unregister_code(KC_LCTL);
					unregister_code(KC_RGHT);
				}
			} 
			else 
			{
				if (IS_LAYER_ON(_LOWER))
				{
					if (clockwise) 
					{
						tap_code(KC_VOLD);
					}
					else
					{
						tap_code(KC_VOLU);
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
							register_code(KC_PGUP);
							unregister_code(KC_PGUP);
						}
						else
						{
							register_code(KC_PGDN);
							unregister_code(KC_PGDN);
						}
					}
				}
			}
		}
};


