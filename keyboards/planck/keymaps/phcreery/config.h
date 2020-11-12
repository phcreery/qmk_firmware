#pragma once

// #ifndef CONFIG_H
#define CONFIG_H

// #include "config_common.h"

/* USB Device descriptor parameter */
// #define VENDOR_ID       0xFEED
// #define PRODUCT_ID      0x6060
// #define MANUFACTURER    OLKB
// #define PRODUCT         Planck
// #define DESCRIPTION     A compact ortholinear keyboard

/* key matrix size */
#undef MATRIX_ROWS
#undef MATRIX_COLS
#define MATRIX_ROWS 5
#define MATRIX_COLS 12

/* Planck PCB default pin-out */
// ROWS: Top to bottom, COLS: Left to right
#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#undef UNUSED_PINS

#define MATRIX_ROW_PINS { F6, F5, F4, F1, F0 }
#define MATRIX_COL_PINS { D2, D3, E6, B7, C7, C6, D4, D6, D7, B4, D0, D1 }
#define UNUSED_PINS

#undef QMK_ESC_OUTPUT
#undef QMK_ESC_INPUT
#undef QMK_LED
#undef QMK_SPEAKER

// #undef __AVR__

// #define QMK_ESC_OUTPUT F1
// #define QMK_ESC_INPUT D5
// #define QMK_LED     E6
// #define QMK_SPEAKER C6

#undef AUDIO_VOICES
#undef C6_AUDIO

// #define AUDIO_VOICES
// #define C6_AUDIO

#undef BACKLIGHT_PIN

// #define BACKLIGHT_PIN B7

/* COL2ROW or ROW2COL */
// #define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
// #define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
// #define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
// #define LOCKING_RESYNC_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

/* WS2812B RGB Underglow LED */
#define RGB_DI_PIN B0   // See readme.md for wiring your led's
#define RGBLIGHT_ANIMATIONS       
#define RGBLED_NUM 4         // Number of LEDs. Change this to match your use case.
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

