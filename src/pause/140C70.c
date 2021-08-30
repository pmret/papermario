#include "common.h"

#define pause_map_tab_places_description_string_id 0x1D00F2

INCLUDE_ASM(s32, "pause/140C70", func_8024D930);

void pause_map_draw_border_arrows(s32 arg0, s32 arg1, s32 arg2) {
    s32 phi_a0;
    s32 phi_a1;
    s32 phi_a2;
    s32 phi_a3;
    s32 temp = 0x10;

    switch (arg0) {
        case 0:
            phi_a0 = arg1 * 4;
            phi_a1 = arg2 * 4;
            phi_a2 = (arg1 + 16) * 4;
            phi_a3 = (arg2 + 16) * 4;
            pause_draw_rect(phi_a0, phi_a1, phi_a2, phi_a3, 0, 0, 0, 0x400, 0x400);
            break;
        case 1:
            phi_a0 = arg1 * 4;
            phi_a1 = arg2 * 4;
            phi_a2 = (arg1 + 16) * 4;
            phi_a3 = (arg2 + 16) * 4;
            pause_draw_rect(phi_a0, phi_a1, phi_a2, phi_a3, 0, 0, 0x200, 0x400, 0x400);
            break;
        case 2:
            phi_a0 = arg1 * 4;
            phi_a1 = arg2 * 4;
            phi_a2 = (arg1 + 16) * 4;
            phi_a3 = (arg2 + 16) * 4;
            pause_draw_rect(phi_a0, phi_a1, phi_a2, phi_a3, 0, 0, 0x400, 0x400, 0x400);
            break;
        default:
            phi_a0 = arg1 * 4;
            phi_a1 = arg2 * 4;
            phi_a2 = (arg1 + temp) * 4;
            phi_a3 = (arg2 + temp) * 4;
            pause_draw_rect(phi_a0, phi_a1, phi_a2, phi_a3, 0, 0, 0x600, 0x400, 0x400);
            break;
    }
}

INCLUDE_ASM(s32, "pause/140C70", pause_map_draw_contents);

void pause_map_draw_title(s32* arg1, s32 arg2, s32 textOffsetY, s32 textOffsetX) {
    s32 stringWidth;
    s32 stringID;
    s32 xPos;
    s32 yPos;

    if (gPauseMenuCurrentTab == 6) {
        if (mapCursorCurrentOption != -1) {
            stringWidth = get_string_width((mapCursorCurrentOption * 3) + pause_map_tab_places_description_string_id, 0);
            stringID = (mapCursorCurrentOption * 3) + pause_map_tab_places_description_string_id;
            xPos = arg2 + ((textOffsetX - stringWidth) >> 1);
            yPos = textOffsetY + 1;
            draw_string(stringID, xPos, yPos, 0xFF, 0, 0);
        }
    }
}

#ifdef NON_MATCHING
void pause_map_init(s8* arg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f6;
    s32 i;
    s32* phi_s2;
    HudElement* hudElement;
    s32 phi_s0_2;
    s32 phi_v0_2;
    s32 phi_s0_4 = 0;
    PauseMapSpaces* map_spaces;
    Pause80250668* phi_v0;
    s32* hudElementPtr = &D_80270700;
    s32* phi_s1 = &D_8024FA30;
    
    
    for (i = 0; i <= 0; i++) {
        hudElementPtr[i] = create_hud_element(phi_s1[0]);
        set_hud_element_flags(hudElementPtr[i], 0x80);
        phi_s1++;
    }
    
    i = 6;
    phi_v0 = &D_80250668;
    

    for (i; i >= 0; i--) {
        phi_v0->unk_10 = arg0;
        phi_v0--;
    }

    setup_pause_menu_tab(&D_80250590, 7);
    mapCursorCurrentOption = -1;
    D_80270724 = 0;
    mapCursorCurrentOptionCopy = -1;

    for (i = 0; i < EVT_SAVE_FLAG_PLACES_VISITED_TOTAL; i++) {
        if (map_spaces->tabIndex != evt_get_variable(0, 0xF5DE0329)) {
            map_spaces++;
            phi_s0_4 = 1;
        } else {
            break;
        }
    }

    if (map_spaces->tabIndex != 0) {
        map_spaces = phi_s0_4 * sizeof(pause_map_spaces) + &D_802502B8;
        mapMarioXPos = map_spaces->xPos;
        mapMarioYPos = map_spaces->yPos;
    } else {
        mapMarioXPos = 0;
        mapMarioYPos = 0;
    }
    
    temp_f2 = mapMarioXPos;
    mapCursorXPos = temp_f2;
    D_80270704 = 0.0f;
    temp_f6 = D_80270704;
    temp_f0 = mapMarioYPos;
    mapCursorYPos = temp_f0;
    temp_f2_2 = temp_f6 - (f32) (s32) ((f64) (temp_f2 + temp_f6) - D_80270080);
    temp_f0_2 = temp_f6 - (f32) (s32) ((f64) (temp_f0 + temp_f6) - D_80270088);
    D_80270708 = 0.0f;
    D_80270704 = temp_f2_2;
    D_80270708 = temp_f0_2;
    if (temp_f6 < temp_f2_2) {
        D_80270704 = temp_f6;
    }
    if (temp_f6 < temp_f0_2) {
        D_80270708 = temp_f6;
    }
    if (D_80270704 <= -86.0f) {
        D_80270704 = -85.0f;
    }
    if (D_80270708 <= -210.0f) {
        D_80270708 = -209.0f;
    }
    *arg0 = 1;
}
#else
INCLUDE_ASM(s32, "pause/140C70", pause_map_init);
#endif

void pause_map_handle_input(void) {
    GameStatus* gameStatus = gGameStatusPtr;
    PauseMapSpaces* map_spaces;
    f64 temp_f4_2;
    s32 temp_f12;
    f32 phi_f8;
    f32 phi_f6;
    f32 mapCursorYPosTemp = mapCursorYPos;
    f32 mapCursorXPosTemp = mapCursorXPos;

    phi_f8 = (f32) gameStatus->stickX * 0.05f;
    phi_f6 = (f32) -(s32) gameStatus->stickY * 0.05f;
    if ((phi_f8 == 0.0f) && (phi_f6 == 0.0f)) {
        if (mapCursorCurrentOption != -1) {
            map_spaces = (PauseMapSpaces*)&D_802502B8 + mapCursorCurrentOption;
            phi_f8 = map_spaces->xPos - mapCursorXPosTemp;
            phi_f8 = phi_f8 * D_80270090;
            phi_f6 = map_spaces->yPos - mapCursorYPosTemp;
            phi_f6 = phi_f6 * D_80270090;
        }
    }

    mapCursorXPos += phi_f8;
    mapCursorYPos += phi_f6;
    if (mapCursorXPos < 16.0f) {
        mapCursorXPos = 16.0f;
    }

    if (mapCursorYPos < 8.0f) {
        mapCursorYPos = 8.0f;
    }

    if (mapCursorXPos >= 316.0f) {
        mapCursorXPos = 315.0f;
    }

    if (mapCursorYPos >= 308.0f) {
        mapCursorYPos = 307.0f;
    }

    temp_f4_2 = (s32) (mapCursorXPos + D_80270704 - D_80270098);
    temp_f12 = mapCursorYPos + D_80270708 - D_802700A0;
    if (D_802700A8 <= temp_f4_2) {
        D_80270704 = D_80270704 - (temp_f4_2 - D_802700A8);
    }

    if (temp_f4_2 <= D_802700B0) {
        D_80270704 = D_80270704 - (temp_f4_2 + D_802700B8);
    }

    temp_f12 = temp_f12;
    if (temp_f12 >= 15.0) {
        D_80270708 = D_80270708 - (temp_f12 - 15.0);
    }

    if (temp_f12 <= -15.0) {
        D_80270708 =  D_80270708 - (temp_f12 + 15.0);
    }

    if (D_80270704 > 0.0f) {
        D_80270704 = 0.0f;
    }

    if (D_80270708 > 0.0f) {
        D_80270708 = 0.0f;
    }

    if (D_80270704 < -86.0f) {
        D_80270704 = -86.0f;
    }

    if (D_80270708 < -210.0f) {
        D_80270708 = -210.0f;
    }

    if (gPauseMenuPressedButtons & B_BUTTON) {
        sfx_play_sound(0xCA);
        gPauseMenuCurrentTab = 0;
        return;
    }

    gPauseMenuCurrentDescIconScript = 0;
    if (mapCursorCurrentOption == -1) {
        gPauseMenuCurrentDescString = 0;
        return;
    }

    gPauseMenuCurrentDescString = (mapCursorCurrentOption * 3) + 0x1D00F3;
    if (evt_get_variable(0, EVT_STORY_PROGRESS) >= (s32)*(D_802502B8 + (mapCursorCurrentOption * ARRAY_COUNT(D_802502B8) + 3))) {
        gPauseMenuCurrentDescString++;
    }
}

void pause_map_update(void) {
    PauseMapSpaces* mapSpace;
    f32 deltaY;
    f32 deltaX;
    f32 temp_f4_2;
    s32 i;
    f32 phi_f20;
    f32 phi_f22;

    mapCursorCurrentOption = -1;
    D_80270724 = 0;
    mapSpace = (PauseMapSpaces*)&D_802502B8;
    phi_f20 = 10000.0f;
    phi_f22 = -1.0f;
    
    for (i = 0; i < EVT_SAVE_FLAG_PLACES_VISITED_TOTAL; i++) {
        if (evt_get_variable(0, i + EVT_SAVE_FLAG_PLACES_VISITED) != 0) {
            deltaX = mapCursorXPos - mapSpace->xPos;
            deltaY = mapCursorYPos - mapSpace->yPos;
            temp_f4_2 = SQ(deltaX) + SQ(deltaY);
            if (temp_f4_2 < 400.0f) {
                D_80270724++;
            }

            if ((temp_f4_2 < phi_f20) && (temp_f4_2 < 200.0f)) {
                phi_f20 = temp_f4_2;
                phi_f22 = i;
            }
        }

        mapSpace++;
    }
    
    mapCursorCurrentOption = phi_f22;
    mapCursorCurrentOptionCopy = phi_f22;
}

void pause_map_cleanup(void) {
    s32 i;

    for (i = 0; i < 1; i++) {
        free_hud_element(D_80270700[i]);
    }
}
