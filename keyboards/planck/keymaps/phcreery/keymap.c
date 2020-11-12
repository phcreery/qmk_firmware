// make planck/rev5:phcreery
// C:\Progra~2\Arduino\hardware\tools\avr\bin\avrdude -C"C:\Program Files (x86)\Arduino\hardware\tools\avr/etc/avrdude.conf" -v -patmega32u4 -cavr109 -PCOM6 -b57600 -D -Uflash:w:"C:\Users\phcre\Documents\MK\qmk_firmware\kingly_keys_romac_plus_phcreery.hex":i

#include QMK_KEYBOARD_H 

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _SPECIAL 3
#define _CALC 4
#define _NAV 5
#define _ADJUST 6

// #define LOWER MO(_LOWER)
// #define RAISE MO(_RAISE)
#define LOWER LT(_LOWER, KC_MINUS)
#define RAISE LT(_RAISE, KC_EQUAL)
#define SPECIAL MO(_SPECIAL)


// #define LPSFT SFT_T(KC_RPRN)
// #define LCCTL CTL_T(KC_LCBR)
// #define RCCTL MT(MOD_RCTL,KC_RCBR)
// #define RPSFT MT(MOD_RSFT,KC_LPRN)

// #define SCOLNAV LT(_NAV,KC_SCLN)
// #define TABCALC LT(_CALC, KC_TAB)
// #define QUOCALC LT(_CALC, KC_QUOT)
// #define LBRACK LT(_SPECIAL,KC_LBRC)
// #define RBRACK LT(_SPECIAL,KC_RBRC)

#define LOCK RGUI(KC_L)

enum custom_keycodes {
  CTLALTD = SAFE_RANGE,
  VIMSAVE,
  VIMWQ
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(record->event.pressed) {
    switch(keycode) {
      case CTLALTD:
        SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LALT)SS_DOWN(X_DELETE)SS_UP(X_DELETE)SS_UP(X_LALT)SS_UP(X_LCTRL));
        return false;
      case VIMSAVE:
        SEND_STRING(":w");
        return false;
    }
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,----------------------------------------------------------------------------------------------------.
 * |   ESC    |   Q      |   W   |   E  |   R  |   T  |   Y  |   U  |   I  |   O   |   P      |  BACKSP |
 * |----------+----------+-------+------+------+-------------+------+------+-------+----------+---------|
 * |   TAB    |   A      |   S   |   D  |   F  |   G  |   H  |   J  |   K  |   L   |   ;      | Enter   |
 * |----------+----------+-------+------+------+------|------+------+------+-------+----------+---------|
 * |  LSHIFT  |   Z      |   X   |   C  |   V  |   B  |   N  |   M  |   ,  |   .   |   UP     | RSHIFT  |
 * |----------+----------+-------+------+------+------+------+------+------+-------+----------+---------|
 * |   CTRL   |   GUI    |  ALT  |Specal|Lower-| SPC  | SPC  |Raise+| \    | LEFT  |   DOWN   |  RIGHT  |
 * `----------------------------------------------------------------------------------------------------'
 *                                          |   -  | SPC  |  -   |
 *                                          `--------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x12(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,    KC_BSPC,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K,     KC_L,    KC_SCLN, KC_ENT ,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_UP  , KC_RSFT,
  KC_LCTL, KC_LGUI, KC_RALT, SPECIAL, LOWER,   KC_SPC,  KC_SPC, RAISE,   KC_BSLS,  KC_LEFT, KC_DOWN, KC_RGHT,
  _______, _______, _______, _______, _______, _______, KC_SPC, _______, _______, _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | PGUP | HOME |  UP  | END  |      | DEL  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |      |      |      |      |      | PGDN | LEFT | DOWN | RIGHT|      | "/'  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |  /   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *                                 |   -  | SPC  |  -   |
 *                                 `--------------------'
 */
[_LOWER] = LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______, KC_PGUP, KC_HOME, KC_UP  , KC_END , _______, KC_DEL ,
  KC_CAPS, _______, _______, _______, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_QUOT,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_SPC , _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   | DEL  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   F7 |   F8 |   F9 |  F10 |  F11 | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *                                 |   -  | SPC  |  -   |
 *                                 `--------------------'
 */
[_RAISE] = LAYOUT_ortho_5x12(
  KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL ,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 ,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_SPC , _______, _______, _______, _______, _______
),

/* Special
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | WUP  |  M1  | MUP  |  M2  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |WDOWN |MLEFT |MDOWN |MRIGHT|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | MUTE | VOL- | VOL+ |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | PREV | PLAY | NEXT |
 * `-----------------------------------------------------------------------------------'
 *                                |   -  | SPC  |  -   |
 *                                `--------------------'
 */
[_SPECIAL] = LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_SPC , _______, _______, KC_MPRV, KC_MPLY, KC_MNXT
),

/* Calc
 * ,-----------------------------------------------------------------------------------.
 * |      |   F7 |  F8  |  F9  |      |      |  *   |   7  |  8   |  9   |  /   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   F4 |  F5  |  F6  |      |      |  +   |   4  |  5   |  6   |  -   |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   F1 |  F2  |  F3  |      |      |      |   1  |  2   |  3   |  =   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  F11 |  F12 |      | DEL  | Bksp |  0   |      |      |      | RET  |
 * `-----------------------------------------------------------------------------------'
 *                                |   -  | SPC  |  -   |
 *                                `--------------------'
 */
[_CALC] = LAYOUT_ortho_5x12(
  KC_TRNS, KC_F7,   KC_F8,   KC_F9,   _______, _______, KC_ASTR, KC_7,    KC_8,    KC_9,    KC_BSLS, KC_TRNS,
  _______, KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_PLUS, KC_4,    KC_5,    KC_6,    KC_MINS, KC_BSLS,
  _______, KC_F1,   KC_F2,   KC_F3,   _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_EQL,  _______,
  _______, _______, KC_F11,  KC_F12,  _______, KC_DEL,  KC_BSPC, KC_0,    _______, _______, KC_ENT,  _______,
  _______, _______, _______, _______, _______,_______, KC_SPC ,_______, _______, _______, _______, _______
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | HOME | PGUP | PGDN | END  | LEFT | DOWN |  UP  |RIGHT |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *                                 |   -  | SPC  |  -   |
 *                                 `--------------------'
 */
[_NAV] = LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,_______, KC_SPC ,_______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-------------------------------------------------------------------------------------------.
 * |Reset |      |      |RGB_TOG|RGB_MOD|RGB_HUI|RGB_HUD|RGB_SAI|RGB_SAD|RGB_VAI|RGB_VAD|  Del |
 * |------+------+------+-------+-------+-------+-------+-------+-------+-------+-------+------|
 * |      |      |      |       |       |AGnorm |AGswap |       |       |       |       |      |
 * |------+------+------+-------+-------+-------+-------+-------+-------+-------+-------+------|
 * |      |      |      |       |       |       |       |TERMon |TERMof |       |       |      |
 * |------+------+------+-------+-------+-------+-------+-------+-------+-------+-------+------|
 * |      |      |      |       |       |               |       |       |       |       |      |
 * `-------------------------------------------------------------------------------------------'
 *                                    |   -  | SPC  |  -   |
 *                                    `--------------------'
 */
[_ADJUST] = LAYOUT_ortho_5x12(
  RESET  , _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
  _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, _______,
  _______, _______, _______, _______, _______, KC_TRNS, KC_TRNS, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,_______, KC_SPC ,_______, _______, _______, _______, _______
)


};


uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
};


