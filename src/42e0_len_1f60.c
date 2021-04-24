#include "common.h"
#include "nu/nusys.h"

// TODO: replace nustuff with defines

u16 D_80074260 = 0;
s32 D_80074264 = 0;

void poll_rumble(void) {
    nuContRmbCheck(0);
    nuContRmbModeSet(0, 2);
}

void start_rumble(s32 freq, s32 frame) {
    if (gGameStatusPtr->demoState == 0) {
        if (D_80074260 != 0) {
            s32 symx2 = D_80074260 * 2;

            if (frame > symx2) {
                frame = symx2;
            }

            if (nuContRmbCheck(0) == 0) {
                nuContRmbModeSet(0, 2);
                nuContRmbStart(0, freq, frame);
            }
        }
    }
}

void update_max_rumble_duration(void) {
    if (D_80074264 != gGameStatusPtr->currentButtons) {
        D_80074264 = gGameStatusPtr->currentButtons;
        reset_max_rumble_duration();
    }

    if (D_80074260 != 0) {
        D_80074260--;
    }
}

void reset_max_rumble_duration(void) {
    D_80074260 = 300;
}
