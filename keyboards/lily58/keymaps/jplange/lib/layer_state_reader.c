#include QMK_KEYBOARD_H
#include <stdio.h>

// Modernized from old bitwise flags (1<<1) to raw layer indexes
#define L_BASE 0
#define L_LOWER 1
#define L_RAISE 2

char layer_state_str[24];

const char *read_layer_state(void) {
  // Evaluates the actual active layer index securely
  switch (get_highest_layer(layer_state))
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    break;
  case L_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%d", get_highest_layer(layer_state));
  }

  return layer_state_str;
}
