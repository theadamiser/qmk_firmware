// qmk flash --keyboard sofle/keyhive --keymap emilyiser

#include QMK_KEYBOARD_H
#include "idle.h"
#include "luna.h"
#include "rgb_config.h"

/*********************************************************************************************/
/* KEYMAP */
/*********************************************************************************************/
#define C_MOVE MO(_MOVE)
#define C_ADJST TO(_ADJUST)
#define C_BASE TO(_BASE)
#define C_SYMBOL MO(_SYMBOL) 

#define M_BCK LGUI(KC_LBRC)
#define M_FWD LGUI(KC_RBRC)

#define M_DESKTOP_RIGHT RCTL(KC_RIGHT)
#define M_DESKTOP_LEFT RCTL(KC_LEFT)

#define M_UNDO LGUI(KC_Z)
#define M_COPY LGUI(KC_C)
#define M_CUT LGUI(KC_X)
#define M_PASTE LGUI(KC_V)

enum layers {
  _BASE,
  _MOVE,
  _ADJUST,
  _SYMBOL
};

bool paste_cmd_active = false;

// https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,  \
    C_SYMBOL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,  _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS, \
                      KC_LCTL, KC_LOPT, C_MOVE,  KC_SPC,  KC_BSPC,  OSM(MOD_LSFT), KC_ENTER, _______, _______, _______ \
    ),

  [_MOVE] = LAYOUT( \
    C_ADJST, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______,                       _______, KC_HOME, KC_UP,   KC_END,  _______, _______,\
    _______, _______, _______, _______, KC_RSFT, _______,                       _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,\
    _______, _______, _______, _______, KC_ENTER, _______, _______,     _______, KC_F1,   KC_F2,   KC_F4,   KC_F3, _______, _______,\
                        _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______\
    ),
    [_SYMBOL] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, KC_LCBR, KC_RCBR, _______,                       _______, _______, _______, _______,  _______, _______,\
    _______, _______, _______, KC_LPRN, KC_RPRN, _______,                       _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______,     _______, _______, _______, _______, _______, _______, _______,\
                        _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______\
    ),
  [_ADJUST] = LAYOUT( \
    C_BASE,  _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, RGB_TOG,                       _______, _______, _______, _______, _______, _______,\
    _______, RGB_RMOD,RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,                       _______, _______, _______, _______, _______, _______,\
    _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______,     _______, _______, _______, _______, _______, _______, _______,\
                        _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______\
    ),
};

/*********************************************************************************************/
/* OLED */
/*********************************************************************************************/
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return is_keyboard_master() ? OLED_ROTATION_270 : OLED_ROTATION_0;
}

static void oled_render_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
  };
  oled_write_P(qmk_logo, false);
}

void oled_task_user(void) {
  if (check_and_apply_idle()) {
    return;
  }
  if (is_keyboard_master()) {
    if (render_rgb_config()) {
      return;
    }
    luna_render(0, 13);
  } else {
    oled_render_logo();
  }
}


/*********************************************************************************************/
/* Roatary Encoder */
/*********************************************************************************************/
void process_encoder_paste_command(uint8_t direction) {
    if (!paste_cmd_active) {
      paste_cmd_active = true;
      register_code(KC_LGUI);
      register_code(KC_LSFT);
      register_code(KC_V);
    } else {
      tap_code(direction);
    }
}

bool maybe_clear_paste_command(uint8_t keycode) {
  if (paste_cmd_active) {
    if (keycode != KC_ENTER) {
      tap_code(KC_ESC);
    }
    unregister_code(KC_V);
    unregister_code(KC_LSFT);
    unregister_code(KC_LGUI);
    paste_cmd_active = false;
    if (keycode == KC_ENTER) {
      return false;
    }
  }
  return true;
}

/*********************************************************************************************/
/* Main Hooks */
/*********************************************************************************************/
void keyboard_post_init_user(void) {
  init_idle();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    luna_set_sneaking(layer_state_cmp(state, _MOVE));
    toggle_rgb_config(layer_state_cmp(state, _ADJUST));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  idle_process_record(record);
  switch (keycode) {
    case KC_ENTER:
      if (record->event.pressed) {
        luna_bark();
        return maybe_clear_paste_command(KC_ENTER);
      }
      break;
    case KC_SPC:
      if (record->event.pressed) {
        luna_jump();
      }
      break;
  }
  maybe_clear_paste_command(keycode);
  return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (clockwise) {
      tap_code16(M_DESKTOP_RIGHT);
    } else {
      tap_code16(M_DESKTOP_LEFT);
    }
  } else if (index == 1) {
    if (clockwise) {
      process_encoder_paste_command(KC_LEFT);
    } else {
      process_encoder_paste_command(KC_RIGHT);
    }
  }
  return true;
}