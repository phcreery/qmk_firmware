// cd /mnt/c/Users/phcre/Documents/MK/qmk_firmware
// make tada68:phcreery68


#include QMK_KEYBOARD_H
#include "mousekey.h"
#include "pointing_device.h"
#include "report.h"

bool jiggling = false;
int8_t jsize = 10;
//uint8_t nowtime = 0;
static uint16_t start;
static uint16_t jtime = 10000;
static uint16_t presstime = 100;
//static uint16_t jtime2 = 100;

report_mouse_t currentReport = {};

enum custom_keycodes {
    PAS_1 = SAFE_RANGE,
    PAS_2,
    PAS_3,
    PAS_4,
    PAS_5,
    DYNAMIC_MACRO_RANGE,
    KC_MS_JIGGLER
};

#include "dynamic_macro.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
        return false;
  }

  switch (keycode) {
    case PAS_1:{
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("a0487637");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    }
    case PAS_2:{
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("4Jar8BkY");
      } else {
        // when keycode QMKURL is released
      }
      break;
    }
    case PAS_3:{
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("-Peyton");
      } else {
        // when keycode QMKURL is released
      }
      break;
    }
    case PAS_4:{
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("Thank you," SS_TAP(X_ENTER) "Peyton Creery");
      } else {
        // when keycode QMKURL is released
      }
      break;
    }
    case PAS_5:{
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_DELETE))));
        _delay_ms(1000);
        SEND_STRING("4Jar8BkY");
        SEND_STRING(SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
    }
    case KC_MS_JIGGLER:{
      //currentReport = pointing_device_get_report();
      //mousekey_on(KC_MS_L);
      //mousekey_off(KC_MS_L);
      if (record->event.pressed){
        //currentReport.x = currentReport.x - jsize;
        if (jiggling == false){
          jiggling = true;
          start = timer_read();
          mousekey_on(KC_MS_U);
        } else {
          jiggling = false;
          mousekey_on(KC_MS_D);
        }
      } else {
        mousekey_off(KC_MS_U);
        mousekey_off(KC_MS_D);
      }
      //pointing_device_set_report(currentReport);
      break;
    }
  }
  return true;
};


void matrix_scan_user(void){
  if (jiggling == true){
    if (timer_elapsed(start) > jtime) {
      //currentReport = pointing_device_get_report();
      //currentReport.x = currentReport.x + jsize;
      //pointing_device_set_report(currentReport);
      if (jsize > 0){
        mousekey_on(KC_MS_R);
        //mousekey_off(KC_MS_R);
      } else {
        
        mousekey_on(KC_MS_L);
        //mousekey_off(KC_MS_L);
      }
      
      //start = timer_read();
    }
    if (timer_elapsed(start) > jtime + presstime) {
      mousekey_off(KC_MS_R);
      mousekey_off(KC_MS_L);
      start = timer_read();
      jsize = -jsize;

    }
    //nowtime = nowtime + 1;
    
  }
}


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc2| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Del |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Home|
   * |----------------------------------------------------------------|
   * |CAP,MO1|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |End |
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|MO2 |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt|MO1|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[0] = LAYOUT_ansi(LT(2, KC_ESC), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL,\
 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME,\
  LT(1, KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_END,\
   KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, MO(2),\
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
 
  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * | `~| F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Backsp |Ins |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |Sft|   |PgU|Hom|Up |End|   |VOL-|VOL+|MUT|PgUp|
   * |----------------------------------------------------------------|
   * |      |<- |Dn | ->|Ctl|   |PgD|<- |Dn |-> |   |   |        |PgDn|
   * |----------------------------------------------------------------|
   * |        |    |   |   |   |   |BLs|BLb|BL-|BL+|BLT|  McL|MsU|McR |
   * |----------------------------------------------------------------|
   * |DMR1|DMS1|DMP1|                        |   |   |MsJ|MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */
[1] = LAYOUT_ansi(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_BSPC, KC_INS, \
	KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_LSFT, KC_TRNS, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_PGUP, \
	KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_LCTL, KC_TRNS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, \
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_STEP, BL_BRTG, BL_DEC, BL_INC, BL_TOGG, KC_BTN1, KC_MS_U, KC_BTN2,\
	 DYN_REC_START1, DYN_REC_STOP, DYN_MACRO_PLAY1, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_JIGGLER, KC_MS_L, KC_MS_D, KC_MS_R),


  /* Keymap _CM: Command Layer
   * ,----------------------------------------------------------------.
   * |   |PS1|PS2|PS5|PS3|PS4|   |   |   |   |   |   |   |       |RST |
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |    |    |   |    |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |         |   |
   * |----------------------------------------------------------------|
   * |        |    |   |   |   |   |   |   |   |   |   |     |   |    |
   * |----------------------------------------------------------------|
   * |DMR2|DMS2|DMP2|                        |   |   |   |   |   |    |
   * `----------------------------------------------------------------'
   */
[2] = LAYOUT_ansi(KC_TRNS, PAS_1, PAS_2, PAS_5,  PAS_3,   PAS_4, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
   DYN_REC_START2, DYN_REC_STOP, DYN_MACRO_PLAY2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};



