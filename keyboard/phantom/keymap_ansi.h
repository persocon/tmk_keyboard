// Phantom ANSI
static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP_ANSI(\
        ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,       PSCR,SLCK,BRK,  \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,      INS, HOME,PGUP, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,      DEL, END, PGDN, \
        FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,       FN1, FN2, FN3,  \
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,      FN4, UP, FN5,   \
        LCTL,LALT,LGUI,               SPC,                RGUI,RALT,RCTL, APP,      LEFT,DOWN,RGHT),
    /* 1: media keys */
    KEYMAP_ANSI(\
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,SLEP, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,MUTE,VOLD,VOLU,TRNS,      TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,MSTP,MPLY,MPRV,MNXT,MSEL,      TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,      TRNS,TRNS,TRNS, \
        TRNS,     TRNS,TRNS,CALC,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     CAPS,      TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS),
    /* 2: custom FN6 to Develop on Lightroom */
    KEYMAP_ANSI(\
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,      TRNS,TRNS,TRNS, \
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,      TRNS,TRNS,FN6, \
        TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS),
    /* 2: custom FN7 to Library on Lightroom */
    KEYMAP_ANSI(\
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,      TRNS,TRNS,TRNS, \
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,      FN7,TRNS,TRNS, \
        TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS)
};

enum macro_id {
    CHUCK,
    LIGHTROOM_DEVELOP,
    LIGHTROOM_LIBRARY
};

static const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [4] = ACTION_LAYER_MOMENTARY(2),
    [5] = ACTION_LAYER_MOMENTARY(3),
    [1] = ACTION_MACRO(CHUCK),                          // Macro: OPEN CHUCK
    [6] = ACTION_MACRO(LIGHTROOM_DEVELOP),              // Macro: Lightroom Develop
    [7] = ACTION_MACRO(LIGHTROOM_LIBRARY),              // Macro: Lightroom Develop
};

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case CHUCK:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(SPC), END ) :
                    MACRO( U(LCTL), U(SPC), END ) );
        case LIGHTROOM_DEVELOP:
            return (record->event.pressed ?
                    MACRO( D(LGUI), D(LALT), D(2), END ) :
                    MACRO( U(LGUI), U(LALT), U(2), END ) );
        case LIGHTROOM_LIBRARY:
            return (record->event.pressed ?
                    MACRO( D(LGUI), D(LALT), D(1), END ) :
                    MACRO( U(LGUI), U(LALT), U(1), END ) );            
    }
    return MACRO_NONE;
}