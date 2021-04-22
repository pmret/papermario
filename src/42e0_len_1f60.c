#include "common.h"
#include "nu/nusys.h"

// TODO: replace nustuff with defines

u16 D_80074260 = 0;
s32 D_80074264 = 0;

void reset_max_rumble_duration(void);

void poll_rumble(void) {
    nuContRmbCheck(0);
    nuContRmbModeSet(0, 2);
}

void start_rumble(s32 freq, s32 frame) {
    if (gGameStatusPtr->demoState == 0) {
        u16* sym = &D_80074260;

        if (*sym != 0) {
            s32 symx2 = *sym * 2;

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
    s32* sym = &D_80074264;
    u16* sym2;

    if (*sym != gGameStatusPtr->currentButtons) {
        *sym = gGameStatusPtr->currentButtons;
        reset_max_rumble_duration();
    }

    sym2 = &D_80074260;
    if (*sym2 != 0) {
        (*sym2)--;
    }
}

void reset_max_rumble_duration(void) {
    D_80074260 = 300;
}
