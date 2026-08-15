#include <stdio.h>
#include QMK_KEYBOARD_H

char timelog_str[24] = {};
int last_time = 0;
int elapsed_time = 0;

void set_timelog(void) {
  elapsed_time = timer_elapsed32(last_time);
  last_time = timer_read32();
  snprintf(timelog_str, sizeof(timelog_str), "lt:%5d, et:%5d", last_time, elapsed_time);
}

const char *read_timelog(void) {
  return timelog_str;
}
