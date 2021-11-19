#include QMK_KEYBOARD_H
#include "idle.h"

/*
 * Manual OLED and RGB idle behavior. QMK's idle logic is buggy :(
 */
uint32_t idle_timer = 0;

void init_idle(void) {
  idle_timer = timer_read32();
}

void idle_process_record(keyrecord_t *record) {
  if (record->event.pressed) {
    idle_timer = timer_read32();
  }
}

bool check_and_apply_idle(void) {
  if (!is_keyboard_master()) {
    return false; // Master controls RGB and OLED state (and syncs to slave)
  }
  if (timer_elapsed32(idle_timer) > IDLE_TIMEOUT_RGB_OLED) {
    oled_off();
    rgb_matrix_set_suspend_state(true);
    return true;
  } else {
    oled_on();
    rgb_matrix_set_suspend_state(false);
    return false;
  }
}
