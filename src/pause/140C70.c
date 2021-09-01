#include "common.h"

#define pause_map_tab_places_desc_string_id 0x1D00F2

typedef struct Pause8024D930 {
    /* 0x00 */ s16 xPos;
    /* 0x02 */ s16 yPos;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[0x2];
    /* 0x08 */ Vec2b* unk_08;
} Pause8024D930; // Similar to PauseMapSpaces

void func_8024D930(Pause8024D930* arg0) {
    Vec2b* unk_08 = arg0->unk_08;
    s32 limit = arg0->unk_05;
    s32 x1 = D_802502B8[arg0->unk_04].xPos;
    s32 y1 = D_802502B8[arg0->unk_04].yPos;
    s32 x2 = arg0->xPos;
    s32 y2 = arg0->yPos;
    s32 xThingPrev = 0;
    s32 yThingPrev = 0;
    s32 i;

    for (i = 0; i < limit; i++) {
        s32 xThing = ((x1 - x2) * (i + 1)) / (limit + 1);
        s32 yThing = ((y1 - y2) * (i + 1)) / (limit + 1);

        unk_08[i].x = xThing - xThingPrev;
        unk_08[i].y = yThing - yThingPrev;
        xThingPrev = xThing;
        yThingPrev = yThing;
    }
}

void pause_map_draw_border_arrows(s32 imageIndex, s32 x, s32 y) {
    s32 size = 16;

    switch (imageIndex) {
        case 0:
            pause_draw_rect(x * 4, y * 4, (x + size) * 4, (y + size) * 4, 0, 0, 0, 0x400, 0x400);
            break;
        case 1:
            pause_draw_rect(x * 4, y * 4, (x + size) * 4, (y + size) * 4, 0, 0, 0x200, 0x400, 0x400);
            break;
        case 2:
            pause_draw_rect(x * 4, y * 4, (x + size) * 4, (y + size) * 4, 0, 0, 0x400, 0x400, 0x400);
            break;
        default:
            pause_draw_rect(x * 4, y * 4, (x + size) * 4, (y + size) * 4, 0, 0, 0x600, 0x400, 0x400);
            break;
    }
}

INCLUDE_ASM(s32, "pause/140C70", pause_map_draw_contents);

void pause_map_draw_title(s32* arg1, s32 arg2, s32 textOffsetY, s32 textOffsetX) {
    s32 stringWidth;
    s32 stringID;

    if (gPauseMenuCurrentTab == 6) {
        if (pause_map_cursorCurrentOption != -1) {
            stringWidth = get_string_width(pause_map_tab_places_desc_string_id + (pause_map_cursorCurrentOption * 3), 0);
            stringID = pause_map_tab_places_desc_string_id + (pause_map_cursorCurrentOption * 3);
            draw_string(stringID, arg2 + ((textOffsetX - stringWidth) >> 1), textOffsetY + 1, 255, 0, 0);
        }
    }
}

void pause_map_init(MenuPanel* tab) {
    s32 tempVar;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80270700); i++) {
        D_80270700[i] = create_hud_element(D_8024FA30[i]);
        set_hud_element_flags(D_80270700[i], 0x80);
    }

    for (i = 0; i < ARRAY_COUNT(pause_map_windowBlueprints); i++) {
        pause_map_windowBlueprints[i].tab = tab;
    }

    setup_pause_menu_tab(pause_map_windowBlueprints, ARRAY_COUNT(pause_map_windowBlueprints));
    pause_map_cursorCurrentOption = -1;
    D_80270724 = 0;
    pause_map_cursorCurrentOptionCopy = -1;
    tempVar = evt_get_variable(0, EVT_SAVE_VAR(425));

    for (i = 0; i < EVT_SAVE_FLAG_PLACES_VISITED_TOTAL; i++) {
        if (D_802502B8[i].tabIndex == tempVar) {
            break;
        }
    }

    if (i < EVT_SAVE_FLAG_PLACES_VISITED_TOTAL) {
        pause_map_marioX = D_802502B8[i].xPos;
        pause_map_marioY = D_802502B8[i].yPos;
    } else {
        pause_map_marioX = 0;
        pause_map_marioY = 0;
    }
    pause_map_cursorX = pause_map_marioX;
    pause_map_cursorY = pause_map_marioY;

    pause_map_cameraX = 0.0f;
    pause_map_cameraY = 0.0f;
    pause_map_cameraX -= (s32)(pause_map_cursorX + pause_map_cameraX - D_80270080);
    pause_map_cameraY -= (s32)(pause_map_cursorY + pause_map_cameraY - D_80270088);

    if (pause_map_cameraX > 0)  {
        pause_map_cameraX = 0;
    }
    if (pause_map_cameraY > 0) {
        pause_map_cameraY = 0;
    }

    if (pause_map_cameraX <= -86.0f) {
        pause_map_cameraX = -85.0f;
    }
    if (pause_map_cameraY <= -210.0f) {
        pause_map_cameraY = -209.0f;
    }

    tab->initialized = 1;
}

void pause_map_handle_input(void) {
    f32 xMovement = gGameStatusPtr->stickX * 0.05f;
    f32 yMovement = -gGameStatusPtr->stickY * 0.05f;
    f32 pause_map_cursorYPosTemp = pause_map_cursorY;
    f32 pause_map_cursorXPosTemp = pause_map_cursorX;
    s32 xTemp;
    s32 yTemp;

    if (xMovement == 0.0f && yMovement == 0.0f && pause_map_cursorCurrentOption != -1) {
        PauseMapSpaces* mapSpace = &D_802502B8[pause_map_cursorCurrentOption];

        xMovement = mapSpace->xPos - pause_map_cursorXPosTemp;
        yMovement = mapSpace->yPos - pause_map_cursorYPosTemp;

        xMovement *= D_80270090;
        yMovement *= D_80270090;
    }

    pause_map_cursorX += xMovement;
    pause_map_cursorY += yMovement;

    if (pause_map_cursorX < 16.0f) {
        pause_map_cursorX = 16.0f;
    }

    if (pause_map_cursorY < 8.0f) {
        pause_map_cursorY = 8.0f;
    }

    if (pause_map_cursorX >= 316.0f) {
        pause_map_cursorX = 315.0f;
    }

    if (pause_map_cursorY >= 308.0f) {
        pause_map_cursorY = 307.0f;
    }

    xTemp = pause_map_cursorX + pause_map_cameraX - D_80270098;
    yTemp = pause_map_cursorY + pause_map_cameraY - D_802700A0;

    if (D_802700A8 <= xTemp) {
        pause_map_cameraX = pause_map_cameraX - (xTemp - D_802700A8);
    }

    if (D_802700B0 >= xTemp) {
        pause_map_cameraX = pause_map_cameraX - (xTemp + D_802700B8);
    }

    if (yTemp >= 15.0) {
        pause_map_cameraY -= yTemp - 15.0;
    }

    if (yTemp <= -15.0) {
        pause_map_cameraY -= yTemp + 15.0;
    }

    if (pause_map_cameraX > 0.0f) {
        pause_map_cameraX = 0.0f;
    }

    if (pause_map_cameraY > 0.0f) {
        pause_map_cameraY = 0.0f;
    }

    if (pause_map_cameraX < -86.0f) {
        pause_map_cameraX = -86.0f;
    }

    if (pause_map_cameraY < -210.0f) {
        pause_map_cameraY = -210.0f;
    }

    if (gPauseMenuPressedButtons & B_BUTTON) {
        sfx_play_sound(0xCA);
        gPauseMenuCurrentTab = 0;
        return;
    }

    gPauseMenuCurrentDescIconScript = 0;
    if (pause_map_cursorCurrentOption == -1) {
        gPauseMenuCurrentDescString = 0;
        return;
    }

    gPauseMenuCurrentDescString = pause_map_tab_places_desc_string_id + 1 + (pause_map_cursorCurrentOption * 3);
    if (evt_get_variable(0, EVT_STORY_PROGRESS) >= D_802502B8[pause_map_cursorCurrentOption].unk_0C) {
        gPauseMenuCurrentDescString++;
    }
}

void pause_map_update(void) {
    PauseMapSpaces* mapSpace = &D_802502B8[0];
    f32 lowestSqSum = 10000.0f;
    f32 cursorOption = -1.0f;
    s32 i;

    pause_map_cursorCurrentOption = -1;
    D_80270724 = 0;

    for (i = 0; i < EVT_SAVE_FLAG_PLACES_VISITED_TOTAL; i++, mapSpace++) {
        if (evt_get_variable(0, EVT_SAVE_FLAG_PLACES_VISITED + i) != 0) {
            f32 deltaX = pause_map_cursorX - mapSpace->xPos;
            f32 deltaY = pause_map_cursorY - mapSpace->yPos;
            f32 sqSum = SQ(deltaX) + SQ(deltaY);

            if (sqSum < 400.0f) {
                D_80270724++;
            }

            if (sqSum < lowestSqSum && sqSum < 200.0f) {
                lowestSqSum = sqSum;
                cursorOption = i;
            }
        }
    }

    pause_map_cursorCurrentOption = cursorOption;
    pause_map_cursorCurrentOptionCopy = cursorOption;
}

void pause_map_cleanup(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80270700); i++) {
        free_hud_element(D_80270700[i]);
    }
}
