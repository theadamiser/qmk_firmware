// qmk flash --keyboard crkbd --keymap iser2

#include QMK_KEYBOARD_H
#include "idle.h"
#include "luna.h"
#include "rgb_config.h"
#include "sticky_command.h"

/*********************************************************************************************/
/* KEYMAP */
/*********************************************************************************************/
#define C_SPACE LT(_MOVE, KC_SPC)
#define C_NMSYM OSL(_NUMSYM)
#define C_FN MO(_FN)
#define C_SHIFT OSM(MOD_LSFT)
#define C_ADJST TO(_ADJUST)
#define C_BASE TO(_BASE)

#define M_BCK LGUI(KC_LBRC)
#define M_FWD LGUI(KC_RBRC)

#define M_UNDO LGUI(KC_Z)
#define M_COPY LGUI(KC_C)
#define M_CUT LGUI(KC_X)
#define M_PASTE LGUI(KC_V)

enum custom_keycodes {
  CMD_TAB = SAFE_RANGE,
  CMD_GRV,
};

enum layers {
  _BASE,
  _MOVE,
  _NUMSYM,
  _FN,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
     KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,         KC_J,    KC_L,    KC_U,    KC_Y,    KC_MINS, _______,
     KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, C_FN,
                                KC_LGUI, C_SPACE, KC_ENTER,     C_NMSYM, C_SHIFT, KC_LALT
  ),
  [_MOVE] = LAYOUT(
     _______, KC_ESC,  CMD_GRV, CMD_TAB, M_BCK,   M_FWD,        KC_PGUP, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, _______,
     _______, KC_LSFT, KC_LCTL, KC_LOPT, KC_LCMD, XXXXXXX,      KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,XXXXXXX, _______,
     _______, M_UNDO,  M_CUT,   M_COPY,  XXXXXXX, M_PASTE,      KC_DEL,  KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                _______, _______, _______,      _______, KC_TAB,  _______
  ),
  [_NUMSYM] = LAYOUT(
     _______, KC_GRV,  KC_7,    KC_8,    KC_9,    KC_MINS,      XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, _______,
     _______, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQUAL,     XXXXXXX, KC_RCMD, KC_LPRN, KC_RPRN, KC_RSFT, KC_DQUO, // KC_ROPT, KC_RCTL
     _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_BSLS,      KC_DEL,  KC_BSPC, KC_LBRC, KC_RBRC, XXXXXXX, _______,
                                _______, _______, _______,      _______, _______, _______
  ),
  [_FN] = LAYOUT(
     _______, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C_ADJST,
     _______, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX,      XXXXXXX, KC_RCMD, KC_ROPT, KC_RCTL, KC_RSFT, _______,
     _______, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                _______, _______, _______,      _______, _______, _______
  ),
  [_ADJUST] = LAYOUT(
     C_BASE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     _______, RGB_RMOD,RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                _______, _______, _______,      _______, _______,_______
  ),
};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case C_SPACE:
      return true; // Favor key press
    default:
      return false; // Favor layer hold
  }
}

/*********************************************************************************************/
/* OLED */
/*********************************************************************************************/
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return is_keyboard_master() ? OLED_ROTATION_270 : OLED_ROTATION_0;
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
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

void suspend_wakeup_init_user(void) {
  idle_suspend_wakeup_init();
}

void suspend_power_down_user(void) {
  idle_suspend_power_down();
}

/*********************************************************************************************/
/* Main */
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
    case KC_BSPC:
      if (record->event.pressed) {
        luna_bark();
      }
      break;
    case C_SPACE:
      if (!record->event.pressed) {
        luna_jump();
      }
      break;
    case CMD_TAB:
      process_sticky_command(record, KC_TAB);
      break;
    case CMD_GRV:
      process_sticky_command(record, KC_GRAVE);
      break;
  }
  if (keycode != CMD_TAB && keycode != CMD_GRV) {
    maybe_clear_sticky_command(record);
  }
  return true;
}
