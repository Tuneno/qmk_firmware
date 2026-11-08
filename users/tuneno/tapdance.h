// Cryptor1 Tap Dance Definition

// Tap Dancing
#define TAPPING_TERM 200

enum {
  CAPS= 0,
  EXIT,
  TD_1,
  TD_2,
  TD_3
};

tap_dance_action_t tap_dance_actions[] = 
{
  [CAPS]=ACTION_TAP_DANCE_DOUBLE(KC_TAB,KC_CAPS),
  [EXIT]= ACTION_TAP_DANCE_DOUBLE(KC_ESC,CLOSE),
  [TD_1]=ACTION_TAP_DANCE_DOUBLE(KC_1,KC_4),
  [TD_2]=ACTION_TAP_DANCE_DOUBLE(KC_2,KC_5),
  [TD_3]=ACTION_TAP_DANCE_DOUBLE(KC_3,KC_6)
};