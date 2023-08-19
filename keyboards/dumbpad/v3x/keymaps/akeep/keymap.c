/*
Copyright 2022 imchipwood && deveth0

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

enum custom_keycodes {
    KC_PD0 = SAFE_RANGE, // Double 0
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
            BASE LAYER - Num Pad
    /-----------------------------------------------------`
    |             |    7    |    8    |    9    |    -    |
    |             |---------|---------|---------|---------|
    |             |    4    |    5    |    6    |    +    |
    |             |---------|---------|---------|---------|
    |             |    1    |    2    |    3    |  Enter  |
    |-------------|---------|---------|---------|---------|
    |    Mute     |    0    |   00    |    .    |  TO(1)  |
    \-----------------------------------------------------'
    */
    [0] = LAYOUT(
                    KC_P7,      KC_P8,    KC_P9,             KC_PMNS,
                    KC_P4,      KC_P5,    KC_P6,             KC_PPLS,
                    KC_P1,      KC_P2,    KC_P3,             KC_PENT,
        KC_MUTE,    KC_P0,      KC_SPC,   KC_PDOT,           TO(1)
    ),
    /*
            BASE LAYER - Num Pad
    /-----------------------------------------------------`
    |             |   Home  |    ^    |   PgUp  |    /    |
    |             |---------|---------|---------|---------|
    |             |    <    |         |    >    |    *    |
    |             |---------|---------|---------|---------|
    |             |   End   |    v    |   PgDn  |  TO(0)  |
    |-------------|---------|---------|---------|---------|
    |             |   Ins   |   Tab   |   BkSp  |  TO(2)  |
    \-----------------------------------------------------'
    */
    [1] = LAYOUT(
                    KC_HOME,    KC_UP,    KC_PGUP,           KC_PSLS,
                    KC_LEFT,    KC_NO,    KC_RIGHT,          KC_PAST,
                    KC_END,     KC_DOWN,  KC_PGDN,           TO(0),
        _______,    KC_INS,     KC_TAB,   KC_BSPC,           TO(2)
    ),
    /*
            SUB LAYER  - RGB controls, Modes on encoder
    /-----------------------------------------------------`
    |             | On/Off  | Bright- | Bright+ |  Reset  |
    |             |---------|---------|---------|---------|
    |             |         | Hue-    | Hue+    |         |
    |             |---------|---------|---------|---------|
    |             |         | Sat-    | Sat+    |  TO(1)  |
    |-------------|---------|---------|---------|---------|
    |             |         | Effect- | Effect+ |  TO(0)  |
    \-----------------------------------------------------'
    */
    [2] = LAYOUT(
                    RGB_TOG,    RGB_VAD,     RGB_VAI,      QK_BOOT,
                    KC_NO,      RGB_HUD,     RGB_HUI,      KC_NO,
                    KC_NO,      RGB_SAD,     RGB_SAI,      TO(1),
        KC_NO,      _______,    RGB_SPD,     RGB_SPI,      TO(0)
    ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case KC_PD0:
        if (record->event.pressed) {
          // when keycode KC_PD0 is pressed
          SEND_STRING("00");
        } else {
          // when keycode KC_PD0 is released
        }
        break;
    }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            // main layer, volume
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        default:
            // rgb control layer, effects
            if (clockwise) {
                rgblight_step();
            } else {
                rgblight_step_reverse();
            }
            break;
    }
    return false;
}
