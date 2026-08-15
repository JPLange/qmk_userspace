#ifdef RGBLIGHT_ENABLE

#include QMK_KEYBOARD_H
#include <stdio.h>

char rbf_info_str[24];
const char *read_rgb_info(void) {

  snprintf(rbf_info_str, sizeof(rbf_info_str), "%s %2d h%3d s%3d v%3d",
    rgblight_is_enabled() ? "on" : "- ",
    rgblight_get_mode(),
    rgblight_get_hue(), 
    rgblight_get_sat(),
    rgblight_get_val());
  return rbf_info_str;
}
#endif
