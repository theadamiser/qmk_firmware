#pragma once

#ifndef IDLE_TIMEOUT_RGB_OLED
#    define IDLE_TIMEOUT_RGB_OLED 120000
#endif

void init_idle(void);
void idle_process_record(keyrecord_t *record);
bool check_and_apply_idle(void);
