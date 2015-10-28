// Phantom ANSI
static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP_ANSI(\
        ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,       PSCR,SLCK,EJCT, \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,      INS, HOME,PGUP, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,      DEL, END, PGDN, \
        FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,       FN1, FN2, FN3,  \
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,      FN4, UP, F20,   \
        LCTL,LALT,LGUI,               SPC,                RGUI,RALT,RCTL, APP,      LEFT,DOWN,RGHT),
    /* 1: media keys */
    KEYMAP_ANSI(\
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,SLEP, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,MUTE,VOLD,VOLU,TRNS,      TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,MSTP,MPLY,MPRV,MNXT,MSEL,      TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,      FN6, FN7, FN8,  \
        TRNS,     TRNS,TRNS,CALC,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     CAPS,      FN9,TRNS, FN10, \
        TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS),
};

enum macro_id {
    LIGHTROOM_EXPORT,
    LIGHTROOM_TOGGLE_LIB_DEV
};

static const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),

    [2] = ACTION_MACRO(LIGHTROOM_EXPORT),              // Macro: Lightroom Export
    [1] = ACTION_MACRO(LIGHTROOM_TOGGLE_LIB_DEV),       // Macro: Lightroom Develop Library Toggle

};

/*
 * Macro definition
 */
bool lightroom_toggle_ld;
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case LIGHTROOM_EXPORT:
            return (record->event.pressed ?
                    MACRO( D(LGUI), D(LSFT), D(E), END ) :
                    MACRO( U(LGUI), U(LSFT), U(E), END ) );
        case LIGHTROOM_TOGGLE_LIB_DEV:
            if (lightroom_toggle_ld){
                // GO TO LIBRARY
                if(record->event.pressed){
                    return MACRO( D(LGUI), D(LALT), D(1), END );
                }else{
                    lightroom_toggle_ld = false;
                    return MACRO( U(LGUI), U(LALT), U(1), END );
                }
            }else{
                // GO TO DEVELOP
                if(record->event.pressed){
                    return MACRO( D(LGUI), D(LALT), D(2), END );
                }else{
                    lightroom_toggle_ld = true;
                    return MACRO( U(LGUI), U(LALT), U(2), END );
                }
            }
    }
    return MACRO_NONE;
}
