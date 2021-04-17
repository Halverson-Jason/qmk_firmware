#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK_LINUX 0
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 16

// Custom codes
#define KC_CAPP LSFT(KC_PSCR)
#define KC_LWBK LT(_LOWER,KC_BSPC)

enum custom_keycodes {
  COLEMAK_LINUX = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

// Macros
enum {
  M_EMAIL
};

//Tap Dance Declarations
enum {
  TD_ESC_CAPS = 0,
  TD_MIN_UNDER = 1,
  TD_SCOL_COL = 2,
  TD_COMM_LT = 3,
  TD_DOT_GT = 4,
  TD_SLSH_BSLS = 5
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_MIN_UNDER] = ACTION_TAP_DANCE_DOUBLE(KC_KP_MINUS, LSFT(KC_MINUS)),
    [TD_SCOL_COL] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN)),
    [TD_COMM_LT] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, LSFT(KC_COMM)),
    [TD_DOT_GT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, LSFT(KC_DOT)),
    [TD_SLSH_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Lw/Esc|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | GUI  | Alt  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK_LINUX] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y, TD(TD_SCOL_COL), KC_DEL, \
  KC_LWBK, KC_A,   KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  TD(TD_ESC_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M, TD(TD_COMM_LT), TD(TD_DOT_GT),  TD(TD_SLSH_BSLS), KC_ENT , \
  ADJUST,  KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      | up   |      |      |      |  +   |  =   |  [   |  ]   | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |      |  left| down | right|      |      | - _  |   $  |  (   |  )   |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  _   |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Enter |      |      |PG Up | PG Dn | home| end  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, \
  _______, _______, _______,  KC_UP , _______, _______, _______, KC_KP_PLUS,  KC_EQL, KC_LBRC, KC_RBRC, KC_DEL, \
  KC_ESC , _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, TD(TD_MIN_UNDER),  KC_DLR, KC_LPRN, KC_RPRN, KC_PIPE, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______,  KC_ENT, _______, _______, KC_PGUP, KC_PGDOWN, KC_HOME, KC_END \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   f1 |  f2  |  f3  |  f4  |  f5  |  f6  |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  f7  |  f8  |  f9  | f10  | f11  | f12  |      |   7  |   8  |   9  |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      |      |      |      |      |   4  |   5  |   6  |   0  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  1   |  2   |  3   |   .  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             | Raise| Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, _______, KC_BSPC, \
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,    KC_7,    KC_8,    KC_9, _______, KC_DEL, \
  KC_DEL,  _______, _______, _______, _______, _______, _______,    KC_4,    KC_5,    KC_6,  KC_0, KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______,    KC_1,    KC_2,    KC_3, KC_DOT, KC_ENT, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|Sat Up|Sat Dn|Val Up|Val Dn|      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  Caps  |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_CAPP, _______, KC_PSCR, M_EMAIL, _______, _______, _______, _______, _______, _______, _______ \
)


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK_LINUX:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLEMAK_LINUX);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case M_EMAIL:
      if (record->event.pressed) {
        SEND_STRING("jason.halverson@clearcapital.com");
      }
      return false;
      break;
  }
  return true;
}
