SRC += \
  $(USER_PATH)/idle.c \
  $(USER_PATH)/luna.c \
  $(USER_PATH)/rgb_config.c \
  $(USER_PATH)/sticky_command.c \

# Elite-C bootloader
BOOTLOADER = qmk-dfu

# Features
EXTRAKEY_ENABLE = no
BOOTMAGIC_ENABLE = no
MOUSEKEY_ENABLE = no
OLED_ENABLE = yes
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
WPM_ENABLE = yes

# Reduces firmware size
LTO_ENABLE = yes
