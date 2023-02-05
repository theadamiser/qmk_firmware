#include QMK_KEYBOARD_H
#include "sticky_command.h"

bool sticky_cmd_active = false;

void process_sticky_command(keyrecord_t *record, uint16_t keycode) {
  if (record->event.pressed) {
    if (!sticky_cmd_active && get_mods() == 0) {
      sticky_cmd_active = true;
      register_code(KC_LGUI);
    }
    register_code(keycode);
  } else {
    unregister_code(keycode);
  }
}

void maybe_clear_sticky_command(keyrecord_t *record, uint16_t keycode) {
  if (sticky_cmd_active && !IS_MOD(keycode)) {
    unregister_code(KC_LGUI);
    sticky_cmd_active = false;
  }
}
