/* Copyright 2015-2017 Jack Humbert
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

enum unicode_names {
    RNG_A_S, // å
    RNG_A_B,
    UML_A_S, // ä
    UML_A_B,
    UML_O_S, // ö
    UML_O_B,
};

const uint32_t PROGMEM unicode_map[] = {
    [RNG_A_S] = 0xe5,
    [RNG_A_B] = 0xc5,
    [UML_A_S] = 0xe4,
    [UML_A_B] = 0xc4,
    [UML_O_S] = 0xf6,
    [UML_O_B] = 0xd6,
};

#define RNG_A XP(RNG_A_S, RNG_A_B)
#define UML_A XP(UML_A_S, UML_A_B)
#define UML_O XP(UML_O_S, UML_O_B)

enum planck_layers {
    _DVORAK,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _EXTRA,
};

#define EXTRA MO(_EXTRA)

enum planck_keycodes {
    DVORAK = SAFE_RANGE,
    QWERTY,
    BACKLIT,
    SEQ_UNDO,
    SEQ_CUT,
    SEQ_COPY,
    SEQ_PASTE,
    CUS_UNI,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   p  |   y  |   f  |   g  |   c  |   r  |   l  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   a  |   o  |   e  |   u  |   i  |   d  |   h  |   t  |   n  |   s  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   q  |   j  |   k  |   x  |   b  |   m  |   w  |   v  |   z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Extra| Win  | Alt  |Lower | Spac |      |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
    KC_LCTL, EXTRA,   KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Extra| Win  | Alt  |Lower | Spac | Bksp |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, EXTRA,   KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |      |      |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    _______, _______, _______,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    _______, _______, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ä  |   å  |   (  |   )  |      |      |   -  |   =  |      |   ö  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   {  |   }  |      |      |   [  |   ]  |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, UML_A,   RNG_A,   KC_LPRN, KC_RPRN, _______, _______, KC_MINS, KC_EQL,  _______, UML_O,   KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_LCBR, KC_RCBR, _______, _______, KC_LBRC, KC_RBRC, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Dvorak|Qwerty|LX/WIN|CUSUNI|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, _______,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, DVORAK,  QWERTY,   UC_MOD,  CUS_UNI, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Extra
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   7  |   8  |   9  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  cut | copy | paste|      |      |      |   1  |   2  |   3  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  |   .  |   ,  |   +  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_EXTRA] = LAYOUT_planck_grid(
    _______, _______,  _______, _______,  _______,   _______, _______, KC_7,    KC_8,    KC_9,    KC_SLSH, _______,
    _______, _______,  _______, _______,  _______,   _______, _______, KC_4,    KC_5,    KC_6,    KC_ASTR, _______,
    _______, SEQ_UNDO, SEQ_CUT, SEQ_COPY, SEQ_PASTE, _______, _______, KC_1,    KC_2,    KC_3,    KC_MINS, _______,
    _______, _______,  _______, _______,  _______,   _______, _______, KC_0,    KC_DOT,  KC_COMM, KC_PLUS, _______
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool shift_is_pressed = false;
bool use_custom_unicode = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                /* print("mode just switched to qwerty and this is a huge string\n"); */
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
        case KC_LSHIFT:
            shift_is_pressed = record->event.pressed;
            return true;
            break;
        case SEQ_UNDO:
            if (record->event.pressed) tap_code16(C(KC_Z));
            return false;
        case SEQ_CUT:
            if (record->event.pressed) tap_code16(C(KC_X));
            return false;
        case SEQ_COPY:
            if (record->event.pressed) tap_code16(C(KC_C));
            return false;
        case SEQ_PASTE:
            if (record->event.pressed) tap_code16(C(KC_V));
            return false;
        case CUS_UNI:
            if (record->event.pressed) use_custom_unicode = !use_custom_unicode;
            return false;
        case RNG_A:
            if (use_custom_unicode) {
                if (record->event.pressed)
                    register_code16(RALT(KC_W));
                else
                    unregister_code16(RALT(KC_W));
                return false;
            }
            return true;
        case UML_A:
            if (use_custom_unicode) {
                if (record->event.pressed)
                    register_code16(RALT(KC_Q));
                else
                    unregister_code16(RALT(KC_Q));
                return false;
            }
            return true;
        case UML_O:
            if (use_custom_unicode) {
                if (record->event.pressed)
                    register_code16(RALT(KC_P));
                else
                    unregister_code16(RALT(KC_P));
                return false;
            }
            return true;
        default:
            return true;
    }
}

void encoder_update(bool clockwise) {
    if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_DOWN);
        #else
            tap_code(KC_PGDN);
        #endif
    } else {
        #ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_UP);
        #else
            tap_code(KC_PGUP);
        #endif
    }
}
