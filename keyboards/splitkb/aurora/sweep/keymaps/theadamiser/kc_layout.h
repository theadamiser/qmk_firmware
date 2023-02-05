// Shorthand layout; Prefix all keys with KC_.
#define KC_LAYOUT( \
    L00, L01, L02, L03, L04, R00, R01, R02, R03, R04, \
    L10, L11, L12, L13, L14, R10, R11, R12, R13, R14, \
    L20, L21, L22, L23, L24, R20, R21, R22, R23, R24, \
    L30, L31, R30, R31 \
    ) \
    LAYOUT( \
        KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, \
        KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, \
        KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, \
        KC_##L30, KC_##L31, KC_##R30, KC_##R31 \
    )

// 1:1 aliases for keys without a KC_ prefix.
#define KC_____ _______
#define KC_XXXX XXXXXXX
#define KC_LTOG RGB_TOG
#define KC_LRMOD RGB_RMOD
#define KC_LHUI RGB_HUI
#define KC_LSAI RGB_SAI
#define KC_LVAI RGB_VAI
#define KC_LSPI RGB_SPI
#define KC_LMOD RGB_MOD
#define KC_LHUD RGB_HUD
#define KC_LSAD RGB_SAD
#define KC_LVAD RGB_VAD
#define KC_LSPD RGB_SPD
