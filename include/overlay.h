#ifndef _OVERLAY_H_
#define _OVERLAY_H_

#include "common.h"

typedef struct ScreenOverlay {
    /* 0x00 */ Color_RGB8 color;
    /* 0x03 */ char unk_03;
    /* 0x04 */ s32 screenPos[2][2];
    /* 0x14 */ f32 alpha;
} ScreenOverlay; // size = 0x18

void _render_transition_stencil(u8, f32, ScreenOverlay*);
void appendGfx_screen_transition_stencil(s32, s32, f32, s32, s32, s32, s32, s32);
void appendGfx_darkness_stencil(s32, s32, s32, f32, f32);

#endif
