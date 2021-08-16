#include "common.h"

s32 gPauseMenuHeldButtons BSS;
s32 gPauseMenuPressedButtons BSS;
s32 gPauseMenuCurrentDescString BSS;
s32* gPauseMenuCurrentDescIconScript BSS;
s32 D_802700D0 BSS;
s8 gPauseMenuCurrentTab BSS;
char D_802700D[8] BSS;
s32 D_802700E0 BSS;
#define BSS_END 0x802700E4

// TODO this is the bss for the whole segment - break it up
static char bss[0x80278640 - BSS_END];

// Need data segment and vars declared above
#ifdef NON_MATCHING
void pause_set_cursor_opacity(s32 val) {
    gPauseMenuCursorTargetOpacity = val;
}
#else
INCLUDE_ASM(s32, "pause/135EE0", pause_set_cursor_opacity);
#endif

INCLUDE_ASM(s32, "pause/135EE0", func_80242BAC);

INCLUDE_ASM(s32, "pause/135EE0", func_80242D04);

// Delay slot issue with gPauseMenuCursorTargetOpacity (needs .data)
#ifdef NON_MATCHING
void pause_interp_cursor(void) {
    s32* posX = &gPauseMenuCursorPosX;
    s32* posY = &gPauseMenuCursorPosY;
    s32* targetPosX = &gPauseMenuTargetPosX;
    s32* targetPosY = &gPauseMenuTargetPosY;
    s32 xDelta;
    s32 yDelta;
    s32* opacity;

    xDelta = (*targetPosX - *posX) * 0.5;
    yDelta = (*targetPosY - *posY) * 0.5;

    if ((*targetPosX != *posX) || (*targetPosY != *posY)) {
        if ((xDelta == 0) && (yDelta == 0)) {
            *posX = *targetPosX;
            *posY = *targetPosY;
        }
    }

    // Macros? something strange
    {
        s32* posX = &gPauseMenuCursorPosX;
        *posX += xDelta;
    }

    {
        s32* posY = &gPauseMenuCursorPosY;
        *posY += yDelta;
    }

    if (gPauseMenuCursorTargetOpacity == 0) {
        opacity = &gPauseMenuCursorOpacity;

        *opacity -= 128;
        if (*opacity < 0) {
            *opacity = 0;
        }
    } else {
        opacity = &gPauseMenuCursorOpacity;

        *opacity += 32;
        if (*opacity > 255) {
            *opacity = 255;
        }
    }
    gPauseMenuCursorTargetOpacity = 255;
}
#else
INCLUDE_ASM(s32, "pause/135EE0", pause_interp_cursor);
#endif

INCLUDE_ASM(s32, "pause/135EE0", func_80242F90);

INCLUDE_ASM(s32, "pause/135EE0", func_80242FBC);

INCLUDE_ASM(s32, "pause/135EE0", func_80242FF4);

INCLUDE_ASM(s32, "pause/135EE0", func_80243090);

INCLUDE_ASM(s32, "pause/135EE0", func_802430E4);

INCLUDE_ASM(s32, "pause/135EE0", func_8024313C);

INCLUDE_ASM(s32, "pause/135EE0", func_80243188);

INCLUDE_ASM(s32, "pause/135EE0", func_80243238);

INCLUDE_ASM(s32, "pause/135EE0", func_802432E8);

INCLUDE_ASM(s32, "pause/135EE0", func_80243388);

INCLUDE_ASM(s32, "pause/135EE0", pause_interp_text_scroll);

s32 pause_interp_vertical_scroll(s32 deltaBefore) {
    s32 val;
    s32 db = abs(deltaBefore);
    s32 s = sign(deltaBefore);

    if (db >= 16) {
        val = db / 2;
        if (val > 20) {
            val = 20;
        }
    } else {
        val = gPauseMenuPageScrollInterpEasingLUT[db];
    }

    return val * s;
}

void pause_update_cursor(s32 arg0, s32 offsetX, s32 offsetY) {
    s32 opacity;

    pause_interp_cursor();
    opacity = gPauseMenuCursorOpacity;
    if (opacity > 0) {
        if (opacity > 255) {
            opacity = 255;
        }
        set_hud_element_alpha(gPauseMenuCommonIconIDs[0], opacity);
        set_hud_element_render_pos(gPauseMenuCommonIconIDs[0], offsetX + gPauseMenuCursorPosX, offsetY + gPauseMenuCursorPosY);
        draw_icon_2(gPauseMenuCommonIconIDs[0]);
    }
}

void func_80243568(void) {
}

INCLUDE_ASM(s32, "pause/135EE0", pause_textbox_draw_contents);

INCLUDE_ASM(s32, "pause/135EE0", pause_tutorial_draw_contents);

INCLUDE_ASM(s32, "pause/135EE0", pause_init);

INCLUDE_ASM(s32, "pause/135EE0", pause_tutorial_input);

INCLUDE_ASM(s32, "pause/135EE0", pause_handle_input);

INCLUDE_ASM(s32, "pause/135EE0", pause_cleanup);

INCLUDE_ASM(s32, "pause/135EE0", pause_get_total_equipped_bp_cost);

INCLUDE_ASM(void, "pause/135EE0", pause_draw_rect, s32 ulx, s32 uly, s32 lrx, s32 lry, s32 tileDescriptor, s32 uls,
            s32 ult, s32 dsdx, s32 dtdy);

INCLUDE_ASM(s32, "pause/135EE0", pause_sort_item_list);
