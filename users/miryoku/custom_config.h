// Copyright 2023 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once


#if defined (MIRYOKU_MAPPING_SHIFTED_ROWS)
#define MIRYOKU_MAPPING( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
LAYOUT_voyager( \
XXX, K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, XXX, \
XXX, K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, XXX, \
XXX, K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, XXX, \
XXX, XXX, XXX, XXX, K32, XXX,      XXX, K37, XXX, XXX, XXX, XXX, \
                    K33, K34,      K35, K36 \
)
#else
#define MIRYOKU_MAPPING( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
LAYOUT_voyager( \
XXX, XXX, XXX, XXX, XXX, XXX,      XXX, XXX, XXX, XXX, XXX, XXX, \
XXX, K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, XXX, \
XXX, K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, XXX, \
XXX, K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, XXX, \
                    K33, K34,      K35, K36 \
)
#endif

#define MIRYOKU_LAYER_GAME \
KC_ESC,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    TO(U_BASE), \
KC_LALT,        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT, \
KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT, \
MO(U_GAMENUM),  U_NP,    U_NP,    U_NP,    KC_LCTL, U_NP,        U_NP,    U_NP,    U_NP,     U_NP,    U_NP,    MO(U_GAMENUM), \
                                           KC_SPC,  KC_TAB,      KC_ENT,  KC_BSPC 

#define MIRYOKU_LAYER_GAMENUM \
U_NP,           U_NP,    KC_7,    KC_8,    KC_9,   U_NP,        U_NP,    U_NP,    U_NP,     U_NP,    U_NP,    U_NP, \
U_NP,           U_NP,    KC_4,    KC_5,    KC_6,   U_NP,        KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT, U_NP,    U_NP, \
U_NP,           U_NP,    KC_1,    KC_2,    KC_3,   U_NP,        U_NP,    U_NP,    U_NP,     U_NP,    U_NP,    U_NP, \
U_NP,           KC_LGUI, U_NP,    U_NP,    U_NP,   U_NP,        U_NP,    U_NP,    U_NP,     U_NP,    U_NP,    U_NP, \
                                           KC_0,   U_NP,        U_NP,    U_NP


// Custom base layer with Game layer switch
#define MIRYOKU_LAYERMAPPING_BASE( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
LAYOUT_voyager( \
XXX, K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, TO(U_GAME), \
XXX, K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, XXX, \
XXX, K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, XXX, \
XXX, XXX, XXX, XXX, K32, XXX,      XXX, K37, XXX, XXX, XXX, XXX, \
                    K33, K34,      K35, K36 \
)

// Custom game layer with Base layer switch
#define MIRYOKU_LAYERMAPPING_GAME( \
     K00, K01, K02, K03, K04, K05,      K06, K07, K08, K09, K10, K11, \
     K12, K13, K14, K15, K16, K17,      K18, K19, K20, K21, K22, K23, \
     K24, K25, K26, K27, K28, K29,      K30, K31, K32, K33, K34, K35, \
     K36, K37, K38, K39, K40, K41,      K42, K43, K44, K45, K46, K47, \
                         K48, K49,      K50, K51 \
) \
LAYOUT_voyager( \
K00, K01, K02, K03, K04, K05,      K06, K07, K08, K09, K10, K11, \
K12, K13, K14, K15, K16, K17,      K18, K19, K20, K21, K22, K23, \
K24, K25, K26, K27, K28, K29,      K30, K31, K32, K33, K34, K35, \
K36, K37, K38, K39, K40, K41,      K42, K43, K44, K45, K46, K47, \
                    K48, K49,      K50, K51 \
)

// Custom game layer with Base layer switch
#define MIRYOKU_LAYERMAPPING_GAMENUM( \
     K00, K01, K02, K03, K04, K05,      K06, K07, K08, K09, K10, K11, \
     K12, K13, K14, K15, K16, K17,      K18, K19, K20, K21, K22, K23, \
     K24, K25, K26, K27, K28, K29,      K30, K31, K32, K33, K34, K35, \
     K36, K37, K38, K39, K40, K41,      K42, K43, K44, K45, K46, K47, \
                         K48, K49,      K50, K51 \
) \
LAYOUT_voyager( \
K00, K01, K02, K03, K04, K05,      K06, K07, K08, K09, K10, K11, \
K12, K13, K14, K15, K16, K17,      K18, K19, K20, K21, K22, K23, \
K24, K25, K26, K27, K28, K29,      K30, K31, K32, K33, K34, K35, \
K36, K37, K38, K39, K40, K41,      K42, K43, K44, K45, K46, K47, \
                    K48, K49,      K50, K51 \
)


#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(BASE,    "Base") \
MIRYOKU_X(EXTRA,   "Extra") \
MIRYOKU_X(TAP,     "Tap") \
MIRYOKU_X(BUTTON,  "Button") \
MIRYOKU_X(NAV,     "Nav") \
MIRYOKU_X(MOUSE,   "Mouse") \
MIRYOKU_X(MEDIA,   "Media") \
MIRYOKU_X(NUM,     "Num") \
MIRYOKU_X(SYM,     "Sym") \
MIRYOKU_X(FUN,     "Fun") \
MIRYOKU_X(GAME,    "Game") \
MIRYOKU_X(GAMENUM, "GameNum") \

#undef TAPPING_TERM
#define TAPPING_TERM 220
#define PERMISSIVE_HOLD
#define ACHORDION_STREAK

// Disable all RGB animations to save memory and ensure clean layer transitions
#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_BAND_SAT
#undef ENABLE_RGB_MATRIX_BAND_VAL
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#undef ENABLE_RGB_MATRIX_HUE_BREATHING
#undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#undef ENABLE_RGB_MATRIX_HUE_WAVE
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN
