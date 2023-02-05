// qmk compile -e CONVERT_TO=promicro_rp2040 -kb splitkb/aurora/sweep -km theadamiser
#include QMK_KEYBOARD_H
#include "kc_layout.h"
#include "sticky_command.h"

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
  KC_CMDTB,
  KC_CMDGV,
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
    // ------ ------ ------ ------ ------      ------ ------ ------ ------ ------
       Q,     W,     F,     P,     B,          J,     L,     U,     Y,     QUOT,
       A,     R,     S,     T,     G,          M,     N,     E,     I,     O,
       Z,     X,     C,     D,     V,          K,     H,     COMM,  DOT,   SLSH,
                            MOVSP, CMDEN,      SYMBS, SHIFT
    // ------ ------ ------ ------ ------      ------ ------ ------ ------ ------
  ),
  [L_MOVE] = KC_LAYOUT( // BCK,   FWD
    // ------ ------ ------ ------ ------      ------ ------ ------ ------ ------
       ESC,   CMDGV, CMDTB, BCK,   FWD,        XXXX,  PGUP,  UP,    PGDN,  XXXX,
       LSFT,  LCTL,  LOPT,  LCMD,  XXXX,       TAB,   LEFT,  DOWN,  RIGHT, XXXX,
       UNDO,  CUT,   COPY,  XXXX,  PASTE,      DEL,   BSPC,  XXXX,  XXXX,  XXXX,
                            ____,  ____,       BSPC,  ENTER
    // ------ ------ ------ ------ ------      ------ ------ ------ ------ ------
  ),
  [L_NUMSYM] = KC_LAYOUT(
    // ------ ------ ------ ------ ------      ------ ------ ------ ------ ------
       GRV,   7,     8,     9,     MINS,       XXXX,  XXXX,  LCBR,  RCBR,  DQUO,
       SCLN,  4,     5,     6,     EQUAL,      TAB,   RCMD,  LPRN,  RPRN,  RSFT,
       0,     1,     2,     3,     BSLS,       DEL,   BSPC,  LBRC,  RBRC,  XXXX,
                            ____,  ____,       ____,  ____
    // ------ ------ ------ ------ ------      ------ ------ ------ ------ ------
  ),
  [L_FN] = KC_LAYOUT(
    // ------ ------ ------ ------ ------      ------ ------ ------ ------ ------
       XXXX,  F7,    F8,    F9,    XXXX,       XXXX,  XXXX,  XXXX,  XXXX,  ADJST,
       XXXX,  F4,    F5,    F6,    XXXX,       XXXX,  RCMD,  ROPT,  RCTL,  RSFT,
       XXXX,  F1,    F2,    F3,    XXXX,       XXXX,  XXXX,  XXXX,  XXXX,  XXXX,
                            ____,  ____,       ____,  ____
    // ------ ------ ------ ------ ------      ------ ------ ------ ------ ------
  ),
  [L_ADJUST] = KC_LAYOUT(
    // ------ ------ ------ ------ ------      ------ ------ ------ ------ ------
       BASE,  XXXX,  XXXX,  XXXX,  LTOG,       XXXX,  XXXX,  XXXX,  XXXX,  XXXX,
       LRMOD, LHUI,  LSAI,  LVAI,  LSPI,       XXXX,  XXXX,  XXXX,  XXXX,  XXXX,
       LMOD,  LHUD,  LSAD,  LVAD,  LSPD,       XXXX,  XXXX,  XXXX,  XXXX,  XXXX,
                            ____,  ____,       ____,  ____
    // ------ ------ ------ ------ ------      ------ ------ ------ ------ ------
 ),
};

/*********************************************************************************************/
/* OLED */
/*********************************************************************************************/
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//   return is_keyboard_master() ? OLED_ROTATION_270 : OLED_ROTATION_0;
// }

// void oled_task_user(void) {
//   if (check_and_apply_idle()) {
//     return;
//   }
//   if (is_keyboard_master()) {
//     if (render_rgb_config()) {
//       return;
//     }
//     if (true) luna_render(0, 13);
//     if (false) oled_render_saucer();
//   } else {
//    // oled_render_logo();
//   }
// }

/*********************************************************************************************/
/* Main */
/*********************************************************************************************/
void keyboard_pre_init_user(void) {
  // Turn off Liatris power LED
  setPinOutput(24);
  writePinHigh(24);
}

void keyboard_post_init_user(void) {
  // init_idle();
}

void suspend_wakeup_init_user(void) {
  // idle_suspend_wakeup_init();
}

void suspend_power_down_user(void) {
  // idle_suspend_power_down();
}

layer_state_t layer_state_set_user(layer_state_t state) {
  //  luna_set_sneaking(layer_state_cmp(state, L_MOVE));
  //  toggle_rgb_config(layer_state_cmp(state, L_ADJUST));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static bool symbs_pressed = false;
  static uint16_t symbs_time = 0;
  static bool cmden_pressed = false;
  static uint16_t cmden_time = 0;

  // idle_process_record(record);

  if (symbs_pressed && record->event.pressed) {
    layer_on(L_NUMSYM);
    symbs_pressed = false;
  }
  if (cmden_pressed && record->event.pressed) {
    cmden_pressed = false;
  }

  switch (keycode) {
    // case KC_BSPC:
    //   if (record->event.pressed) {
    //     luna_bark();
    //   }
    //   break;
    // case KC_MOVSP:
    // case KC_SPACE:
    //   if (!record->event.pressed) {
    //     luna_jump();
    //   }
    //   break;
    case KC_CMDTB:
      process_sticky_command(record, KC_TAB);
      break;
    case KC_CMDGV:
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
  if (keycode != KC_CMDTB && keycode != KC_CMDGV) {
    maybe_clear_sticky_command(record, keycode);
  }
  return true;
}
