// qmk flash --keyboard crkbd --keymap iser2

#include QMK_KEYBOARD_H
#include "idle.h"
#include "luna.h"
#include "rgb_config.h"
#include "kc_layout.h"

/*********************************************************************************************/
/* KEYMAP */
/*********************************************************************************************/
// Layers & Thumbs
#define KC_MOVSP LT(L_MOVE, KC_SPC)
#define KC_FN MO(L_FN)
#define KC_SHIFT OSM(MOD_LSFT)
#define KC_ADJST TO(L_ADJUST)
#define KC_BASE TO(L_BASE)

// Combos
#define KC_BCK LGUI(KC_LBRC)
#define KC_FWD LGUI(KC_RBRC)
#define KC_UNDO LGUI(KC_Z)
#define KC_COPY LGUI(KC_C)
#define KC_CUT LGUI(KC_X)
#define KC_PASTE LGUI(KC_V)

enum custom_keycodes {
  KC_SYMBS = SAFE_RANGE,
  KC_CMDEN,
};

enum layers {
  L_BASE,
  L_MOVE,
  L_NUMSYM,
  L_FN,
  L_ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = KC_LAYOUT(
    // ------ ------ ------ ------ ------ ------      ------ ------ ------ ------ ------ ------
       GESC,  Q,     W,     F,     P,     B,          J,     L,     U,     Y,     MINS,  ____,
       TAB,   A,     R,     S,     T,     G,          M,     N,     E,     I,     O,     QUOT,
       LCTL,  Z,     X,     C,     D,     V,          K,     H,     COMM,  DOT,   SLSH,  FN,
                            ____,  MOVSP, CMDEN,      SYMBS, SHIFT, LALT
    // ------ ------ ------ ------ ------ ------      ------ ------ ------ ------ ------ ------
  ),
  [L_MOVE] = KC_LAYOUT(
    // ------ ------ ------ ------ ------ ------      ------ ------ ------ ------ ------ ------
       ____,  ESC,   BCK,   FWD,   XXXX,  XXXX,       PGUP,  XXXX,  UP,    XXXX,  XXXX,  ____,
       ____,  LSFT,  LCTL,  LOPT,  LCMD,  XXXX,       PGDN,  LEFT,  DOWN,  RIGHT, XXXX,  ____,
       ____,  UNDO,  CUT,   COPY,  XXXX,  PASTE,      DEL,   BSPC,  XXXX,  XXXX,  XXXX,  ____,
                            ____,  ____,  ____,       BSPC,  ENTER, ____
    // ------ ------ ------ ------ ------ ------      ------ ------ ------ ------ ------ ------
  ),
  [L_NUMSYM] = KC_LAYOUT(
    // ------ ------ ------ ------ ------ ------      ------ ------ ------ ------ ------ ------
       ____,  GRV,   7,     8,     9,     MINS,       XXXX,  XXXX,  LCBR,  RCBR,  UNDS,  ____,
       ____,  SCLN,  4,     5,     6,     EQUAL,      XXXX,  RCMD,  LPRN,  RPRN,  RSFT,  DQUO,
       ____,  0,     1,     2,     3,     BSLS,       DEL,   BSPC,  LBRC,  RBRC,  XXXX,  ____,
                            ____,  ____,  ____,       ____,  ____,  ____
    // ------ ------ ------ ------ ------ ------      ------ ------ ------ ------ ------ ------
  ),
  [L_FN] = KC_LAYOUT(
    // ------ ------ ------ ------ ------ ------      ------ ------ ------ ------ ------ ------
       ____,  XXXX,  F7,    F8,    F9,    XXXX,       XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  ADJST,
       ____,  XXXX,  F4,    F5,    F6,    XXXX,       XXXX,  RCMD,  ROPT,  RCTL,  RSFT,  ____,
       ____,  XXXX,  F1,    F2,    F3,    XXXX,       XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  ____,
                            ____,  ____,  ____,       ____,  ____,  ____
    // ------ ------ ------ ------ ------ ------      ------ ------ ------ ------ ------ ------
  ),
  [L_ADJUST] = KC_LAYOUT(
    // ------ ------ ------ ------ ------ ------      ------ ------ ------ ------ ------ ------
       BASE,  XXXX,  XXXX,  XXXX,  XXXX,  LTOG,       XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,
       ____,  LRMOD, LHUI,  LSAI,  LVAI,  LSPI,       XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,
       ____,  LMOD,  LHUD,  LSAD,  LVAD,  LSPD,       XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,
                            ____,  ____,  ____,       ____,  ____,  ____
    // ------ ------ ------ ------ ------ ------      ------ ------ ------ ------ ------ ------
 ),
};

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

/*********************************************************************************************/
/* Main */
/*********************************************************************************************/
void keyboard_post_init_user(void) {
  init_idle();
}

void suspend_wakeup_init_user(void) {
  idle_suspend_wakeup_init();
}

void suspend_power_down_user(void) {
  idle_suspend_power_down();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    luna_set_sneaking(layer_state_cmp(state, _MOVE));
    toggle_rgb_config(layer_state_cmp(state, _ADJUST));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static bool symbs_pressed = false;
  static uint16_t symbs_time = 0;
  static bool cmden_pressed = false;
  static uint16_t cmden_time = 0;

  idle_process_record(record);

  if (symbs_pressed && record->event.pressed) {
    layer_on(L_NUMSYM);
    symbs_pressed = false;
  }
  if (cmden_pressed && record->event.pressed) {
    cmden_pressed = false;
  }

  switch (keycode) {
    case KC_BSPC:
      if (record->event.pressed) {
        luna_bark();
      }
      break;
    case KC_MOVSP:
    case KC_SPACE:
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
    case KC_SYMBS:
      if (record->event.pressed) {
        symbs_pressed = true;
        symbs_time = record->event.time;
      } else {
        if (symbs_pressed) {
          if (TIMER_DIFF_16(record->event.time, symbs_time) < TAPPING_TERM) {
            register_code(KC_BSPC);
            unregister_code(KC_BSPC);
          }
          symbs_pressed = false;
        } else {
          layer_off(L_NUMSYM);
        }
      }
      break;
    case KC_CMDEN:
      if (record->event.pressed) {
        cmden_pressed = true;
        cmden_time = record->event.time;
        register_code(KC_LGUI);
      } else {
        unregister_code(KC_LGUI);
        if (cmden_pressed) {
          if (TIMER_DIFF_16(record->event.time, cmden_time) < TAPPING_TERM) {
            register_code(KC_ENTER);
            unregister_code(KC_ENTER);
          }
          cmden_pressed = false;
        }
      }
      break;
  }
  if (keycode != CMD_TAB && keycode != CMD_GRV) {
    maybe_clear_sticky_command(record, keycode);
  }
  return true;
}
