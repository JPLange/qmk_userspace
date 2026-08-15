BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = no        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE = no       # Disable per key RGB
SWAP_HANDS_ENABLE = no      # Enable one-hand tying
# OLED_ENABLE= yes     		# OLED display
QUANTUM_PAINTER_ENABLE = yes	# modern replacement for OLED_ENABLE
QUANTUM_PAINTER_DRIVERS += sh1106_i2c
QUANTUM_PAINTER_LOADERS += qgf
QUANTUM_PAINTER_NUM_IMAGES = 6
ENCODER_ENABLE = no

# If you want to change the display of OLED, you need to change here
SRC +=  /home/lange/Projects/keyboard/qmk_userspace/gfx/jpl_logo.qpa/jpl_logo_sw_64x32.qgf.c
	# ./lib/layer_state_reader.c \
	# ./lib/logo_reader.c \
	# ./lib/keylogger.c \
	# ./lib/mode_icon_reader.c \
	# ./lib/timelogger.c
        # ./lib/host_led_state_reader.c \
	# ./lib/rgb_state_reader.c \
