// Cryptor1 Tap Dance Definition

// Tap Dancing
#define TAPPING_TERM 200

enum {
  CAPS= 0,
  EXIT
};

tap_dance_action_t tap_dance_actions[] = 
{
  [CAPS]=ACTION_TAP_DANCE_DOUBLE(KC_TAB,KC_CAPS),
  [EXIT]= ACTION_TAP_DANCE_DOUBLE(KC_ESC,CLOSE)
};