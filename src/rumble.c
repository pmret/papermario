#include "common.h"
#include "nu/nusys.h"

// TODO: replace nustuff with defines

u16 RumbleMaxDuration = 0;
s32 RumbleButtons = 0;

void reset_max_rumble_duration(void);

void poll_rumble(void) {
    nuContRmbCheck(0);
    nuContRmbModeSet(0, 2);
}

void start_rumble(s32 freq, s32 nframes) {
    if (gGameStatusPtr->demoState == 0) {
        if (RumbleMaxDuration != 0) {
            s32 maxFrames = RumbleMaxDuration * 2;

            if (nframes > maxFrames) {
                nframes = maxFrames;
            }

            if (nuContRmbCheck(0) == 0) {
                nuContRmbModeSet(0, 2);
                nuContRmbStart(0, freq, nframes);
            }
        }
    }
}

void update_max_rumble_duration(void) {
    if (RumbleButtons != gGameStatusPtr->currentButtons) {
        RumbleButtons = gGameStatusPtr->currentButtons;
        reset_max_rumble_duration();
    }

    if (RumbleMaxDuration != 0) {
        RumbleMaxDuration--;
    }
}

void reset_max_rumble_duration(void) {
    RumbleMaxDuration = 300;
}
