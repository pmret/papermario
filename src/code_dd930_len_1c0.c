#include "common.h"

// TODO: most likely part of the MusicPlayer struct
typedef struct {
    /* 0x0 */ s16 fadeFlags;
    /* 0x2 */ s16 fadeState;
    /* 0x4 */ s32 fadeOutTime;
    /* 0x8 */ s32 fadeInTime;
    /* 0xC */ s32 unkC;
} struct_80147230;

extern struct_80147230 D_8014F140;
extern struct_80147230 D_8015C7C0;

void reset_ambient_sounds(void) {
    D_8015C7C0 = D_8014F140;
}

void update_ambient_sounds(void) {
    struct_80147230* temp = &D_8015C7C0;

    switch (temp->fadeState) {
        case 0: // idle
            break;
        case 1: // fading out
            if (temp->fadeFlags & 1) {
                s32 phi_v0;
                if (temp->fadeOutTime < 250) {
                    phi_v0 = func_800554A4(0, temp->fadeOutTime);
                } else {
                    phi_v0 = func_800554E8(0, temp->fadeOutTime);
                }

                if (phi_v0 != 0) {
                    return;
                }
            }
            temp->fadeState = 2;
            break;
        case 2: // fading in
            if (temp->fadeFlags & 1) {
                if (func_800555E4(0) != 0) {
                    return;
                }
                temp->fadeFlags &= ~1;
            }
            if (temp->fadeInTime < 0) {
                temp->fadeState = 0;
            } else if (func_80055448(temp->fadeInTime) == 0) {
                if (func_80055464(0, 0) == 0) {
                    temp->fadeState = 0;
                    temp->fadeFlags |= 1;
                }
            }
            break;
    }
}

s32 play_ambient_sounds(s32 fadeInTime, s32 fadeOutTime) {
    struct_80147230* temp1 = &D_8015C7C0;
    struct_80147230* temp2 = &D_8015C7C0;

    if (!(*gGameStatusPtr)->musicEnabled) {
        func_800554A4(temp1->fadeInTime, fadeOutTime);
        temp1->fadeFlags &= ~1;
        return 1;
    }

    if (temp1->fadeInTime == fadeInTime) {
        return 2;
    }

    temp2->fadeInTime = fadeInTime;
    temp2->fadeOutTime = fadeOutTime;
    temp2->fadeState = 1;
    return 1;
}
