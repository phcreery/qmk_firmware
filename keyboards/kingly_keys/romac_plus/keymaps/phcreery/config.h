#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001

#undef MANUFACTURER
#undef PRODUCT
#undef DESCRIPTION
#define MANUFACTURER    phcreery
#define PRODUCT         Peytons KeyPad
#define DESCRIPTION     A twelve-key macropad with upgraded features
/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 3

/* key matrix pins */
#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#define MATRIX_ROW_PINS { F6, F5, F4, F1 }
#define MATRIX_COL_PINS { C6, D7, E6 }
#define UNUSED_PINS

#undef ENCODERS_PAD_A
#undef ENCODERS_PAD_B
#define ENCODERS_PAD_A { D2 }
#define ENCODERS_PAD_B { D3 }

#define ENCODER_RESOLUTION 4

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#undef OLED_FONT_H
#define OLED_FONT_H "helixfont.c"

