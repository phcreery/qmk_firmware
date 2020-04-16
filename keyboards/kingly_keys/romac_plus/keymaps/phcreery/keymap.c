// cd /mnt/c/Users/phcre/Documents/MK/qmk_firmware
// make kingly_keys/romac_plus:phcreery
// (Press Reset on Microcontroller to enter DFU mode)
// C:\Progra~2\Arduino\hardware\tools\avr\bin\avrdude -C"C:\Program Files (x86)\Arduino\hardware\tools\avr/etc/avrdude.conf" -v -patmega32u4 -cavr109 -PCOM6 -b57600 -D -Uflash:w:"C:\Users\phcre\Documents\MK\qmk_firmware\kingly_keys_romac_plus_phcreery.hex":i

/* Copyright 2018 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "dynamic_macro.h"

#define WIN10 0
#define NUM 1
#define FN 2
#define ACAD 3
#define INVTR 4


#define NUMBER_OF_LAYERS 5
#define MAX_STRING_SIZE 7

char layer[NUMBER_OF_LAYERS][MAX_STRING_SIZE] =
{ "WIN10",
  "NUM  ",
  "FN   ",
  "ACAD ",
  "INVTR"
};


uint8_t selected_layer = 0;
bool layermacro = false;
bool wintabbing = false;


enum custom_keycodes {
    LASEL = SAFE_RANGE,
    WIN_min, WIN_max, WIN_close,
    WIN_prev, WIN_tab, WIN_next,
    WIN_prevd, WIN_nextd, WIN_notepad,
    ACAD_las, ACAD_line, ACAD_pline, ACAD_circle,
    ACAD_move, ACAD_dim, ACAD_lprop,
    ACAD_undo, ACAD_redo,
    DYNAMIC_MACRO_RANGE
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [WIN10] = LAYOUT(
		WIN_min, WIN_max, WIN_close,
		WIN_prevd, WIN_tab, WIN_nextd,
		WIN_notepad, KC_NO, KC_NO,
		KC_NO, KC_NO, LASEL
	),

	[NUM] = LAYOUT(
		KC_7, KC_8, KC_9,
		KC_4, KC_5, KC_6,
		KC_1, KC_2, KC_3,
		KC_0, KC_DOT, LASEL
	),
  
	[FN] = LAYOUT(
		KC_PSCREEN, KC_SCROLLLOCK, KC_BRK,
		KC_INS, KC_HOME, KC_PGUP,
		KC_DELETE, KC_END, KC_PGDN,
		KC_NO, KC_NO, LASEL
	),

  [ACAD] = LAYOUT(
		KC_ESC, ACAD_las, KC_ENTER,
		ACAD_line, ACAD_pline, ACAD_circle,
		ACAD_move, ACAD_dim, ACAD_lprop,
		ACAD_undo, ACAD_redo, LASEL
	),

  [INVTR] = LAYOUT(
		KC_TRNS, KC_HOME, KC_PGUP,
		KC_TRNS, KC_END, KC_PGDN,
		KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, LASEL
	)
};




// Custom Button


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
        return false;
  }

  switch (keycode) {
    case LASEL:{
      if (record->event.pressed) {
        layermacro = true;
      } else {
        layermacro = false;
        // when keycode is released
      }
      break;
    }
    case WIN_min:{
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(" n"));
      } else {
        // when keycode QMKURL is released
      }
      break;
    }
    case WIN_max:{
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(" x"));
      } else {
        // when keycode QMKURL is released
      }
      break;
    }
    case WIN_close:{
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_F4) SS_UP(X_LALT));
      } else {
        // when keycode QMKURL is released
      }
      break;
    }
    case WIN_prevd:{
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_UP(X_LCTRL));
      } else {      }
      break;
    }
    case WIN_tab:{
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_TAB));
        wintabbing = true;
      } else {
        SEND_STRING(SS_UP(X_LALT));
        wintabbing = false;
      }
      break;
    }
    case WIN_nextd:{
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_UP(X_LCTRL));
      } else { }
      break;
    }
    case WIN_notepad:{
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_R) SS_UP(X_LGUI) SS_DELAY(1000));
        SEND_STRING("notepad");
        SEND_STRING(SS_TAP(X_ENTER));
      } else {  }
      break;
    }
    case ACAD_las:{
      if (record->event.pressed) {
        SEND_STRING("las");
        SEND_STRING(SS_DELAY(500) SS_TAP(X_ENTER));
      } else {  }
      break;
    }
    case ACAD_line:{
      if (record->event.pressed) {
        SEND_STRING("line");
        SEND_STRING(SS_TAP(X_ENTER));
      } else {  }
      break;
    }
    case ACAD_pline:{
      if (record->event.pressed) {
        SEND_STRING("pline");
        SEND_STRING(SS_TAP(X_ENTER));
      } else {  }
      break;
    }
    case ACAD_circle:{
      if (record->event.pressed) {
        SEND_STRING("circle");
        SEND_STRING(SS_TAP(X_ENTER));
      } else {  }
      break;
    }
    case ACAD_move:{
      if (record->event.pressed) {
        SEND_STRING("move");
        SEND_STRING(SS_TAP(X_ENTER));
      } else {  }
      break;
    }
    case ACAD_dim:{
      if (record->event.pressed) {
        SEND_STRING("dim");
        SEND_STRING(SS_TAP(X_ENTER));
      } else {  }
      break;
    }
    case ACAD_lprop:{
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_1) SS_UP(X_LCTRL));
      } else {  }
      break;
    }
    case ACAD_undo:{
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_Z) SS_UP(X_LCTRL));
      } else {  }
      break;
    }
    case ACAD_redo:{
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LSHIFT) SS_TAP(X_Z) SS_UP(X_LSHIFT) SS_UP(X_LCTRL));
      } else {  }
      break;
    }

  }
  return true;
};


static const char PROGMEM winicon[] = {
    0x80, 0x20, 0x81, 0x20, 0x82, 0x00//, 0x82
};

static const char PROGMEM divider[] = {
    0x85, 0x85, 0x85, 0x85, 0x85, 0x00//, 0x82
};
static const char PROGMEM divider2[] = {
    0x83, 0x83, 0x83, 0x83, 0x83, 0x00//, 0x82
};

// https://www.reddit.com/r/olkb/comments/cmyodl/qmk_dbn9_how_to_use_encoders_to_switch_layers/

void encoder_update_user(uint8_t index, bool clockwise) {  
  if (index == 0) { /* First encoder */
    if (layermacro == true) { /* Encoder Pressed in */
      if (clockwise && selected_layer < 4) {
        selected_layer ++;
      } else if (!clockwise && selected_layer > 0){
        selected_layer --;
      }
      layer_clear();
      layer_on(selected_layer);
    } else if (wintabbing == true) { /* WIN+TAB pressed */
      if (clockwise) {
        SEND_STRING( SS_TAP(X_RIGHT) );
      } else if (!clockwise){
        SEND_STRING( SS_TAP(X_LEFT) );
      }
    }
  }
}


static void render_logo(void) {
    oled_write_P(winicon, false);
}



#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
}


void oled_clear_l(void){
  oled_write_ln_P(PSTR("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"), false);
}

// selected_layer
void layermenu(void){
  //oled_clear();
  int spaces = 6 - selected_layer;
  if (spaces >= 1){
    for ( int counter = 0; counter < spaces; counter++ ) {
      oled_write_ln_P(PSTR(""), false);
    }
  }
  
  int start;
  if (spaces >= 0){ start = 0; } else { start = -spaces; }

  for ( int counter = start; counter < selected_layer; counter++ ) {
    //char count[5];
    //itoa(counter, count, 10);
    //char buffer [33];
    //String count = String(counter);
    //oled_write(count, false);
    oled_write(layer[counter], false);
  }

  //oled_write_ln_P(PSTR("\n"), false);
  oled_write_P(divider2, false);
  oled_write(layer[selected_layer], false);
  //oled_write_ln_P(PSTR("\n"), false);
  oled_write_P(divider2, false);
  
  for ( int counter = selected_layer+1; counter < NUMBER_OF_LAYERS; counter++ ) {
    oled_write(layer[counter], false);
  }
  oled_write_ln_P(PSTR("\n\n\n\n\n\n"), false);

}



void oled_task_user(void) {
  // Host Keyboard Layer Status
  // oled_write_P(PSTR("Let's\nbuild\nsome-thing\nto-\nget-\nher!\n"), false);
  if (layermacro == true) {
    layermenu();
  } else {
    switch (get_highest_layer(layer_state)) {
      case WIN10:
        render_logo();
        oled_write_P(PSTR("\n\nPrev\nAltTbNext \nNotes\n\n\n\n\n\n\n"), false);
        break;
      case NUM:
        oled_write_ln_P(PSTR("\n\n7 8 9\n4 5 6\n1 2 3\n0 . \n\n\n\n\n\n"), false);
        break;
      case FN:
        oled_write_ln_P(PSTR("PrtScScLckBreak\nIns  Home PgUp \nDel  End  PgDn\n\n"), false);
        break;
      case ACAD:
        oled_write_ln_P(PSTR("ESC  LAS  Enter\nLine PLineCircl\nMove Dim  Prop.\nUndo Redo \n"), false);
        break;
      case INVTR:
        oled_write_ln_P(PSTR("F4Nav\n\n\n\n\n\n\n\n\n\n\n\n"), false);
        break;
      default:
        // Or use the write_ln shortcut over adding '\n' to the end of your string
        oled_write_ln_P(PSTR("Undef\n\n\n\n\n\n\n\n\n\n"), false);
    }
  }

  //oled_write_ln_P(selected_layer, false);


  // Host Keyboard LED Status
  //uint8_t led_usb_state = host_keyboard_leds();
  //oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NLCK ") : PSTR("     "), false);
  //oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPS ") : PSTR("       "), false);
  //oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLK") : PSTR("       "), false);
}







#endif
