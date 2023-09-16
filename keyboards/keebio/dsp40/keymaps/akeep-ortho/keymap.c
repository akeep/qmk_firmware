/* Copyright 2021 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum custom_layer {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default Layer
     * ,-------------------------------------------------------------------------------------------.
     * | Esc   |     Q |    W |     E |     R |     T |     Y |     U |    I |    O |    P |    BS |
     * |-------------------------------------------------------------------------------------------|
     * | Tab   |     A |    S |     D |     F |     G |     H |     J |    K |    L |    ; | Enter |
     * |-------------------------------------------------------------------------------------------|
     * | Shift |     Z |    X |     C |     V |     B |     N |     M |    , |    . |    ? | Shift |
     * |-------------------------------------------------------------------------------------------|
     * | Spr   | LCtrl | LAlt |  LCmd | Raise | Space | Space | Lower | Left |   Up | Down | Right |
     * `-------------------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_4x12(
        KC_ESC,      KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,   KC_Y,   KC_U,       KC_I,    KC_O,   KC_P,    KC_BSPC,
        KC_TAB,      KC_A,    KC_S,    KC_D,    KC_F,       KC_G,   KC_H,   KC_J,       KC_K,    KC_L,   KC_SCLN, KC_ENT,
        KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,   KC_N,   KC_M,       KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        MO(_ADJUST), KC_LCTL, KC_LOPT, KC_LGUI, MO(_LOWER), KC_SPC, KC_SPC, MO(_RAISE), KC_LEFT, KC_UP,  KC_DOWN, KC_RGHT
    ),

    /* Lower Layer
     * ,------------------------------------------------------------------------------------------.
     * | ~     |     ! |     @ |     # |     $ |     % |     ^ |     & |    * |    ( |  ) |    BS |
     * |------------------------------------------------------------------------------------------|
     * | Tab   | BrtDn | BrtUp |  Mctl |  LPad | RGB I |     _ |     + |    { |    } |  | | Enter |
     * |------------------------------------------------------------------------------------------|
     * | Shift | RGB D |   Rwd |  Play |  FFwd |  Mute | VolUp | VolDn | SLEP |  Pwr |  " | Shift |
     * |------------------------------------------------------------------------------------------|
     * | Spr   | LCtrl |  LAlt |  LCmd |       | Space | Space |       | Left | Down | Up | Right |
     * `------------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ortho_4x12(
        KC_TILD,     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        KC_TAB,      KC_BRMD, KC_BRMU, KC_MCTL, KC_LPAD,  RGB_VAI, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_ENT,
        KC_LSFT,     RGB_VAD, KC_MRWD, KC_MPLY, KC_MFFD,  KC_MUTE, KC_VOLD, KC_VOLU, KC_SLEP, KC_PWR,  KC_DQUO, KC_RSFT,
        MO(_ADJUST), KC_LCTL, KC_LOPT, KC_LGUI, _______,  KC_SPC,   KC_SPC, _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    /* Lower Layer
     * ,------------------------------------------------------------------------------------------.
     * | `     |     1 |     2 |     3 |     4 |     5 |     6 |     7 |    8 |    9 |  0 |    BS |
     * |------------------------------------------------------------------------------------------|
     * | Tab   |    F1 |    F2 |    F3 |    F4 |    F5 |     - |     = |    [ |    ] |  \ | Enter |
     * |------------------------------------------------------------------------------------------|
     * | Shift |    F6 |    F7 |    F8 |    F9 |   F10 |   F11 |   F12 |  F13 |  F14 |  ' | Shift |
     * |------------------------------------------------------------------------------------------|
     * | Spr   | LCtrl |  LAlt |  LCmd |       | Space | Space |       | Left | Down | Up | Right |
     * `------------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_4x12(
        KC_GRV,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_ENT,
        KC_LSFT,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_QUOT, KC_RSFT,
        MO(_ADJUST), KC_LCTL, KC_LOPT, KC_LGUI, _______, KC_SPC,  KC_SPC,  _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    [_ADJUST] = LAYOUT_ortho_4x12(
        _______,    QK_BOOT, _______, _______, _______,      _______, _______, _______,      _______, _______, _______, KC_DEL,
        _______,    _______, _______, AU_ON,   AU_OFF,       AG_NORM, AG_SWAP, _______,      _______, _______, _______, KC_ENT,
        _______,    _______, _______, _______, _______,      _______, _______, _______,      _______, _______, _______, KC_RSFT,
        _______,    _______, _______, _______, _______,  KC_SPC,  KC_SPC,  _______,   KC_LEFT, KC_UP, KC_DOWN,   KC_RGHT
    )
};
