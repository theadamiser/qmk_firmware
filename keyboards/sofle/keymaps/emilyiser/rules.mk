USER_NAME := theadamiser
SRC += \
  $(USER_PATH)/idle.c \
  $(USER_PATH)/luna.c \
  $(USER_PATH)/rgb_config.c \

# Elite-C bootloader
BOOTLOADER = qmk-dfu

# Features
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE  = yes
RGB_MATRIX_DRIVER = WS2812
WPM_ENABLE = yes
MOUSEKEY_ENABLE = yes
