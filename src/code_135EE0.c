#include "common.h"

// Need data segment and vars declared above
#ifdef NON_MATCHING
void pause_set_cursor_opacity(s32 val) {
    gPauseMenuCursorTargetOpacity = val;
}
#else
INCLUDE_ASM(s32, "code_135EE0", pause_set_cursor_opacity);
#endif

INCLUDE_ASM(s32, "code_135EE0", func_80242BAC);

INCLUDE_ASM(s32, "code_135EE0", func_80242D04);

INCLUDE_ASM(s32, "code_135EE0", pause_interp_cursor);
// void pause_interp_cursor(void) {
//     s32 targetPosX;
//     s32 posX;
//     s32 targetPosY;
//     s32 posY;
//     s32 xDelta;
//     s32 yDelta;
//     s32 temp_v0;
//     s32 temp_v0_2;

//     targetPosX = gPauseMenuTargetPos[0];
//     posX = gPauseMenuCursorPos[0];
//     targetPosY = gPauseMenuTargetPos[1];
//     posY = gPauseMenuCursorPos[1];
//     xDelta = (targetPosX - posX) * 0.5;
//     yDelta = (targetPosY - posY) * 0.5;

//     if ((targetPosX != posX) || (targetPosY != posY)) {
//         if ((xDelta == 0) && (yDelta == 0)) {
//             gPauseMenuCursorPos[0] = targetPosX;
//             gPauseMenuCursorPos[1] = targetPosY;
//         }
//     }

//     gPauseMenuCursorPos[0] += xDelta;
//     gPauseMenuCursorPos[1] += yDelta;

//     if (gPauseMenuCursorTargetOpacity == 0) {
//         gPauseMenuCursorOpacity -= 128;
//         if (gPauseMenuCursorOpacity < 0) {
//             gPauseMenuCursorOpacity = 0;
//         }
//     } else {
//         gPauseMenuCursorOpacity += 32;
//         if (gPauseMenuCursorOpacity > 255) {
//             gPauseMenuCursorOpacity = 255;
//         }
//     }
//     gPauseMenuCursorTargetOpacity = 255;
// }

INCLUDE_ASM(s32, "code_135EE0", func_80242F90);

INCLUDE_ASM(s32, "code_135EE0", func_80242FBC);

INCLUDE_ASM(s32, "code_135EE0", func_80242FF4);

INCLUDE_ASM(s32, "code_135EE0", func_80243090);

INCLUDE_ASM(s32, "code_135EE0", func_802430E4);

INCLUDE_ASM(s32, "code_135EE0", func_8024313C);

INCLUDE_ASM(s32, "code_135EE0", func_80243188);

INCLUDE_ASM(s32, "code_135EE0", func_80243238);

INCLUDE_ASM(s32, "code_135EE0", func_802432E8);

INCLUDE_ASM(s32, "code_135EE0", func_80243388);

INCLUDE_ASM(s32, "code_135EE0", pause_interp_text_scroll);

// Slight ordering issue with the sign flip at the beginning
#ifdef NON_MATCHING
s32 pause_interp_vertical_scroll(s32 deltaBefore) {
    s32 val;
    s32 s;
    s32 db;

    db = deltaBefore;
    if (deltaBefore < 0) {
        db = -deltaBefore;
    }

    s = sign(deltaBefore);

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
#else
INCLUDE_ASM(s32, "code_135EE0", pause_interp_vertical_scroll);
#endif

INCLUDE_ASM(s32, "code_135EE0", pause_update_cursor);
/*void pause_update_cursor(s32 arg0, s32 offsetX, s32 offsetY) {
    s32 opacity;

    pause_interp_cursor();
    opacity = gPauseMenuCursorOpacity;
    if (opacity > 0) {
        if (opacity > 255) {
            opacity = 255;
        }
        icon_set_opacity(gPauseMenuCommonIconIDs[0], opacity);
        set_icon_render_pos(gPauseMenuCommonIconIDs[0], offsetX + gPauseMenuCursorPos[0], offsetY + gPauseMenuCursorPos[1]);
        draw_icon_2(gPauseMenuCommonIconIDs[0]);
    }
}*/

void func_80243568(void) {
}

INCLUDE_ASM(s32, "code_135EE0", pause_textbox_draw_contents);

INCLUDE_ASM(s32, "code_135EE0", pause_tutorial_draw_contents);

INCLUDE_ASM(s32, "code_135EE0", pause_init);

INCLUDE_ASM(s32, "code_135EE0", pause_tutorial_input);

INCLUDE_ASM(s32, "code_135EE0", pause_handle_input);

INCLUDE_ASM(s32, "code_135EE0", pause_cleanup);

INCLUDE_ASM(s32, "code_135EE0", pause_get_total_equipped_bp_cost);

INCLUDE_ASM(s32, "code_135EE0", pause_draw_rect);

INCLUDE_ASM(s32, "code_135EE0", pause_sort_item_list);

void pause_tabs_draw_invis(void) {
}

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_draw_stats);

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_draw_badges);

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_draw_items);

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_draw_party);

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_draw_spirits);

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_draw_map);

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_init);

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_handle_input);

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_update);

void pause_tabs_cleanup(void) {
    s32* iconIDs = gPauseMenuTabIconIDs;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPauseMenuTabIconIDs); i++) {
        free_icon(iconIDs[i]);
    }
}
