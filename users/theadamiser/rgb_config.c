#include QMK_KEYBOARD_H
#include "rgb_config.h"

bool is_showing = false;
bool was_showing = false;

void write_val(int value) {
    char str[4];
    if (value > 999) {
      value = 999;
    }
    itoa(value, str, 10);
    oled_write(str, false);
    if (value < 100) {
      oled_advance_page(true);
    }
}

void write_horizontal_line(uint8_t y) {
  for (uint8_t x = 0; x < OLED_DISPLAY_WIDTH; ++x) {
    oled_write_pixel(x, y, true);
  }
}

void toggle_rgb_config(bool show) {
  is_showing = show;
}

bool render_rgb_config(void) {
  // Clear oled on enter and exit
  if (is_showing != was_showing) {
    oled_clear();
    was_showing = is_showing;
  }
  if (is_showing) {
    oled_set_cursor(0, 0);
    oled_write_P(PSTR("SETUP"), false);
    write_horizontal_line(9);
    oled_set_cursor(0, 3);
    oled_write_P(PSTR("m:"), false);
    write_val(rgb_matrix_config.mode);
    oled_set_cursor(0, 5);
    oled_write_P(PSTR("h:"), false);
    write_val(rgb_matrix_config.hsv.h);
    oled_write_P(PSTR("s:"), false);
    write_val(rgb_matrix_config.hsv.s);
    oled_write_P(PSTR("v:"), false);
    write_val(rgb_matrix_config.hsv.v);
    oled_set_cursor(0, 9);
    oled_write_P(PSTR("s:"), false);
    write_val(rgb_matrix_config.speed);
  }
  return is_showing;
}
