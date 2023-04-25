#include QMK_KEYBOARD_H

#define _DVORAK 0
#define _SYMNUM 1
#define _MOUSE 2
// Compound keycode aliases
#define SCTL(kc)   LSFT(LCTL(kc))  // Modifier keys: SHIFT+CTRL+kc combination.

// Tap
#define LASG_T(kc) MT(MOD_LGUI | MOD_LALT | MOD_LSFT, kc)  // Mod tap: kc when tapped, GUI+ALT+SHIFT when held.
#define LCSG_T(kc) MT(MOD_LGUI | MOD_LSFT | MOD_LCTL, kc)  // Mod tap: kc when tapped, GUI+CTL+SHIFT when held.

#define LCG_T(kc)  MT(MOD_LCTL | MOD_LGUI, kc)  // Mod tap: kc when tapped, CTL+GUI when held.
#define LAS_T(kc)  MT(MOD_LALT | MOD_LSFT, kc)  // Mod tap: kc when tapped, ALT+SHIFT when held.
#define LAG_T(kc)  MT(MOD_LALT | MOD_LGUI, kc)  // Mod tap: kc when tapped, ALT+GUI when held.

// Others
#define COMPOSE    KC_RALT  // Compose key (used to input characters like á, ñ, ü).
enum custom_keycodes {
    QMKSO = SAFE_RANGE,
    QMKPC,
    QMKPD,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_DVORAK] = LAYOUT_kinesis(
  KC_ESC,         KC_1,           KC_2,           KC_3,           KC_4,                 KC_5,                   KC_6,           KC_7,           KC_8,          KC_9,           KC_0,            KC_SLSH,
  KC_TAB,         KC_QUOT,        KC_COMM,        KC_DOT,         KC_P,                 KC_Y,                   KC_F,           KC_G,           KC_C,          KC_R,           KC_L,            KC_BSLS,
  KC_GRV,         KC_A,           KC_O,           KC_E,           KC_U,                 KC_I,                   KC_D,           KC_H,           KC_T,          KC_N,           KC_S,            KC_MINS,
  KC_LSFT,        KC_SCLN,        KC_Q,           KC_J,           KC_K,                 KC_X,                   KC_B,           KC_M,           KC_W,          KC_V,           KC_Z,            KC_RSFT,
  KC_NO,          KC_LCTL,        KC_LGUI,        KC_LEFT,        KC_RIGHT,             KC_RIGHT,               KC_UP,          KC_UP,          KC_DOWN,       KC_LBRC,        KC_RCTL,          KC_NO,
  KC_LALT,        KC_HOME,        LT(_MOUSE,KC_END), KC_LCTL,  LGUI_T(KC_DEL),          LT(_SYMNUM, KC_BSPC),   LT(_SYMNUM, KC_SPACE), LGUI_T(KC_ENTER), KC_LCTL, LT(_MOUSE,KC_PGDN),        KC_PGUP,         KC_RALT,
//  KC_LALT,        KC_HOME,        KC_END,         KC_LGUI,        LT(_MOUSE, KC_DEL), LT(_SYMNUM,  KC_BSPC),               LT(_SYMNUM, KC_SPACE), LT(_MOUSE, KC_ENTER), KC_LGUI,      KC_PGDN,        KC_PGUP,         KC_RALT,
  KC_NO,          KC_NO,         KC_NO,        KC_NO,        KC_NO,               KC_NO,               KC_NO,          KC_NO,        KC_NO,      KC_NO,         KC_NO,           KC_NO,
  KC_NO,          KC_NO,         KC_NO,        KC_NO,        KC_NO,               KC_NO,               KC_NO,          KC_NO,        KC_NO,      KC_NO,         KC_NO,           KC_NO
 ),

 [_SYMNUM] = LAYOUT_kinesis(
  KC_F11,         KC_F1,          KC_F2,          KC_F3,          KC_F4,         KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F12,
  QMKSO,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_AMPR,       KC_TRNS,        KC_PERC,        KC_EQL,         KC_LT,          KC_GT,          KC_EXLM,        QMKPC,
  KC_TRNS,        KC_LCBR,        KC_LBRC,        KC_LPRN,        KC_0,          KC_MINS,        KC_PLUS,        KC_1,           KC_RPRN,        KC_RBRC,        KC_RCBR,        QMKPD,
  CW_TOGG,        KC_6,           KC_7,           KC_8,           KC_9,          KC_SLSH,        KC_ASTR,        KC_2,           KC_3,           KC_4,           KC_5,           KC_TRNS,
  KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
  KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
  KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
  KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
 ),
 
 [_MOUSE] = LAYOUT_kinesis(

   XXXXXXX,       XXXXXXX,        XXXXXXX,        KC_MS_WH_UP,    LCTL(KC_X),  XXXXXXX,         XXXXXXX,        XXXXXXX,       XXXXXXX,        XXXXXXX,         XXXXXXX,       RCS(KC_Y) ,
   LGUI(KC_Z),    LCTL(KC_Z),     KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,   KC_MS_BTN4,      KC_UP,         KC_F7,         KC_F8,          KC_F9,           KC_F10,        LSFT(KC_F9),
   KC_MS_BTN3,    KC_MS_WH_LEFT,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT, KC_MS_WH_RIGHT,  KC_DOWN,        KC_F4,         KC_F5,          KC_F6,           KC_F11,        LSFT(KC_F11), 
   LGUI(KC_Z),    LCTL(KC_Y),     SCTL(KC_V),     KC_MS_WH_DOWN,  LCTL(KC_V),  KC_MS_BTN5,      XXXXXXX,        KC_F1,         KC_F2,          KC_F3,           KC_F12,        RCS(KC_F5), 
   KC_SCRL,       XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,     XXXXXXX,         XXXXXXX,        XXXXXXX,       XXXXXXX,        XXXXXXX,         XXXXXXX,       LSFT(KC_F5), 
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
const uint16_t PROGMEM test_combo1[] = {KC_N, KC_H, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_C, KC_D, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, KC_ESC),
    COMBO(test_combo2, LCTL(KC_Z)), // keycodes with modifiers are possible too!
};