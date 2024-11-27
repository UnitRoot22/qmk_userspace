// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "features/achordion.h"


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }
  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Also allow same-hand holds when the other key is in the rows outside the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboards are split.
  uint8_t row = other_record->event.key.row % (MATRIX_ROWS / 2);
  if (!(1 <= row && row <= 3)) { return true; }

  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    default:
      return 800;  // Use a timeout of 800 ms.
  }
}

uint16_t achordion_streak_chord_timeout(
    uint16_t tap_hold_keycode, uint16_t next_keycode) {

  const uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
  if ((mod & MOD_LSFT) != 0) {
    return 100;  // A short streak timeout for Shift mod-tap keys.
  } else {
    return 220;  // A longer timeout otherwise.
  }
}

// Define Miryoku layers
enum layers {
    BASE = 0,    // Base layer
    NAV = 4,     // Navigation layer
    MOUSE = 5,   // Mouse layer
    MEDIA = 6,   // Media layer
    NUM = 7,     // Number layer
    SYM = 8,     // Symbol layer
    FUN = 9,     // Function layer
    GAME = 10,   // Game layer
    GAMENUM = 11 // GameNum layer
};

#define BASE_COLOR        0XFF, 0X00, 0X00
#define NAV_COLOR         0xFF, 0x7F, 0x00
#define MOUSE_COLOR       0xFF, 0x20, 0xB4
#define MEDIA_COLOR       0x00, 0X7F, 0x00
#define NUM_COLOR         0x00, 0x00, 0X7F
#define SYM_COLOR         0x00, 0X7F, 0x7F
#define FUN_COLOR         0x40, 0x00, 0x40
#define GAME_COLOR        0xFF, 0x80, 0x00
#define GAMENUM_COLOR     0x40, 0x00, 0x40


void keyboard_post_init_user(void) {
  // Call the post init code.
  rgblight_enable_noeeprom(); // enables Rgb, without saving settings
  rgblight_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  uint8_t current_layer = get_highest_layer(layer_state|default_layer_state);
  switch(current_layer) {
    case BASE:
        rgb_matrix_set_color_all(BASE_COLOR);
        break;
    case NAV:
        rgb_matrix_set_color_all(NAV_COLOR);
        break;
    case MOUSE:
        rgb_matrix_set_color_all(MOUSE_COLOR);
        break;
    case MEDIA:
        rgb_matrix_set_color_all(MEDIA_COLOR);
        break;
    case NUM:
        rgb_matrix_set_color_all(NUM_COLOR);
        break;
    case SYM:
        rgb_matrix_set_color_all(SYM_COLOR);
        break;
    case FUN:
        rgb_matrix_set_color_all(FUN_COLOR);
        break;
    case GAME:
        rgb_matrix_set_color_all(GAME_COLOR);
        break;
    case GAMENUM:
        rgb_matrix_set_color_all(GAMENUM_COLOR);
        break;
    }
    return false;
}
