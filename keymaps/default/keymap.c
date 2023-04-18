#include QMK_KEYBOARD_H

#define _DVORAK 0
#define _SYMNUM 1

enum custom_keycodes {
    QMKSO = SAFE_RANGE,
    QMKPC,
    QMKPD,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_DVORAK] = LAYOUT_kinesis(
  KC_ESC,         KC_1,           KC_2,           KC_3,           KC_4,          KC_5,           KC_6,           KC_7,           KC_8,          KC_9,           KC_0,            KC_SLSH,
  KC_TAB,         KC_QUOT,        KC_COMM,        KC_DOT,         KC_P,          KC_Y,           KC_F,           KC_G,           KC_C,          KC_R,           KC_L,            KC_BSLS,
  KC_GRV,         KC_A,           KC_O,           KC_E,           KC_U,          KC_I,           KC_D,           KC_H,           KC_T,          KC_N,           KC_S,            KC_MINS,
  KC_LSFT,        KC_SCLN,        KC_Q,           KC_J,           KC_K,          KC_X,           KC_B,           KC_M,           KC_W,          KC_V,           KC_Z,            KC_RSFT,
  KC_NO,          KC_LALT,        KC_LGUI,        KC_LEFT,        KC_RIGHT,      KC_SPC,         KC_BSPC,        KC_UP,          KC_DOWN,       KC_LBRC,        KC_EQL,          KC_NO,
  KC_NO,          KC_DEL,         KC_PGUP,        KC_PGDN,        KC_DEL,        LT(_SYMNUM, KC_BSPC),KC_UP,     KC_DOWN,        KC_ENTER,      KC_SPC,         KC_NO,           KC_NO,
  KC_NO,          KC_DEL,         KC_PGUP,        KC_PGDN,        KC_DEL,        KC_ENTER,       KC_UP,          KC_DOWN,        KC_ENTER,      KC_SPC,         KC_NO,           KC_NO,
  KC_NO,          KC_DEL,         KC_PGUP,        KC_PGDN,        KC_DEL,        KC_ENTER,       KC_UP,          KC_DOWN,        KC_ENTER,      KC_SPC,         KC_NO,           KC_NO
 ),

 [_SYMNUM] = LAYOUT_kinesis(
  KC_F11,         KC_F1,          KC_F2,          KC_F3,          KC_F4,         KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F12,
  KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_AMPR,       KC_TRNS,        KC_PERC,        KC_EQL,         KC_LT,          KC_GT,          KC_EXLM,        KC_TRNS,
  KC_TRNS,        KC_LCBR,        KC_LBRC,        KC_LPRN,        KC_0,          KC_MINS,        KC_PLUS,        KC_1,           KC_RPRN,        KC_RBRC,        KC_RCBR,        KC_TRNS,
  CW_TOGG,        KC_6,           KC_7,           KC_8,           KC_9,          KC_SLSH,        KC_ASTR,        KC_2,           KC_3,           KC_4,           KC_5,           KC_TRNS,
  KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
  KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
  KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
  KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
 ),
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QMKSO:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("Sample string...\n");
        } else {
            // when keycode QMKBEST is released
        }
        break;

    case QMKPC:
        if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING(SS_LGUI("d"));
            wait_ms(20);
            SEND_STRING("piactl connect\n");
        } else {
            // when keycode QMKURL is released
        }
        break;
    case QMKPD:
        if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING(SS_LGUI("d"));
            wait_ms(20);
            SEND_STRING("piactl disconnect\n");
        } else {
            // when keycode QMKURL is released
        }
        break;


    }
    return true;
};
