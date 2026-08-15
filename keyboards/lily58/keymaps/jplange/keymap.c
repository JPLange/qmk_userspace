#include QMK_KEYBOARD_H
#include "qp.h"
#include "gfx/jpl_logo.qpa/jpl_logo_sw_64x32.qgf.h"

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   <   |    |    >  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LABK,  KC_RABK,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   <   |    |    >  |------+------+------+------+------+------|
 * |AltGr+A|AltGr+O|AltGr+U|AltGr+S|  | DEL  |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 *
 * AltGr+A/O/U/S produce ä/ö/ü/ß via the host "usde" xkb layout (~/.config/xkb/symbols/usde).
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  RALT(KC_A), RALT(KC_O), RALT(KC_U), RALT(KC_S), XXXXXXX, KC_DEL, KC_LABK, KC_RABK, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------| Left | Down |  Up  |Right | HOME | END  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |AltGr | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_END,  
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                             KC_ALGR, _______, _______,  _______, _______,  _______, _______, _______
  )
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

// QUANTUM Painter
// Make sure to have qp enabled and the i2c driver added in rules.mk
static painter_device_t display = NULL;
static painter_image_handle_t logo_gfx = NULL;

void keyboard_post_init_kb(void) {
	// --- TEMPORARY -----------------------------------------------------
	// The right-hand OLED is currently desoldered (loose pads, awaiting
	// replacement). If we still try to init/write it every scan cycle,
	// the I2C writes on that half stall (or error out) on every loop and
	// eat the matrix-scan time budget -> dropped keystrokes, and can also
	// trip a hard fault/watchdog reset (the "flashes black like the reset
	// button" symptom). So: skip all display handling on the slave half
	// until the new display is soldered back in.
	// TODO: remove this guard (and re-test offsets) once the right OLED
	// is reinstalled.
	if (is_keyboard_master()) return;

	// Physical panel is 128 wide x 64 tall (SH1106, addr 0x3C). Pass the
	// PHYSICAL (un-rotated) size here - rotation is applied separately
	// below via qp_init(). Passing already-rotated dimensions here (as
	// before) double-applies the rotation and corrupts the page/column
	// addressing sent to the panel, which is what produced the "snow" +
	// solid white bar.
	display = qp_sh1106_make_i2c_device(128, 64, 0x3C);
	if (display == NULL) return; // init failed - don't touch it further

	// Apply 90-degree rotation -> 64-pixel wide, 128-pixel high logical canvas
	qp_init(display, QP_ROTATION_90);

	// SH1106 has 132 columns of internal RAM but only 128 are wired to the
	// glass, so most modules need a small column offset or the image (and
	// anything drawn near the edge) shows corrupted/shifted. Try 0, 2, 4
	// and use whichever removes the garbage on your specific panel.
	qp_set_viewport_offsets(display, 0, 0);

	qp_power(display, true);
}

void keyboard_post_init_user(void) {
	if (display == NULL) return; // slave half (or failed init) - nothing to do

	// Load converted QPA image from flash
	logo_gfx = qp_load_image_mem(gfx_jpl_logo);
}

static uint32_t last_draw = 0;
void housekeeping_task_user(void) {
	if (display == NULL) return; // slave half (or failed init) - nothing to do

	// Throttle to ~30fps. IMPORTANT: qp_clear()/qp_flush() must stay inside
	// this throttle block. Calling them unthrottled (every single call to
	// housekeeping_task_user, i.e. every main loop pass) floods the I2C bus
	// with full-frame writes and was the main cause of missed keystrokes.
	if (timer_elapsed32(last_draw) > 33) {
		last_draw = timer_read32();

		qp_clear(display);

		if (logo_gfx != NULL) {
			uint16_t w, h;
			qp_get_geometry(display, &w, &h, NULL, NULL, NULL);
			qp_drawimage(display, (w - logo_gfx->width) / 2, (h - logo_gfx->height) / 2, logo_gfx);
		}

		qp_flush(display);
	}
}


// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
// #ifdef OLED_ENABLE
//     set_keylog(keycode, record);
// #endif
//     // set_timelog();
//   }
//   return true;
// }
