#include "common.h"

#define pause_map_tab_places_desc_string_id 0x1D00F2

void func_8024D930(PauseMapSpace* space) {
    Vec2b* path = space->path;
    s32 pathLength = space->pathLength;
    s32 x1 = pause_map_spaces[space->parent].xPos;
    s32 y1 = pause_map_spaces[space->parent].yPos;
    s32 x2 = space->xPos;
    s32 y2 = space->yPos;
    s32 xThingPrev = 0;
    s32 yThingPrev = 0;
    s32 i;

    for (i = 0; i < pathLength; i++) {
        s32 xThing = ((x1 - x2) * (i + 1)) / (pathLength + 1);
        s32 yThing = ((y1 - y2) * (i + 1)) / (pathLength + 1);

        path[i].x = xThing - xThingPrev;
        path[i].y = yThing - yThingPrev;
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
    pause_map_spacesInSnapRange = 0;
    pause_map_cursorCurrentOptionCopy = -1;
    tempVar = evt_get_variable(0, EVT_SAVE_VAR(425));

    for (i = 0; i < ARRAY_COUNT(pause_map_spaces); i++) {
        if (pause_map_spaces[i].id == tempVar) {
            break;
        }
    }

    if (i < ARRAY_COUNT(pause_map_spaces)) {
        pause_map_marioX = pause_map_spaces[i].xPos;
        pause_map_marioY = pause_map_spaces[i].yPos;
    } else {
        pause_map_marioX = 0;
        pause_map_marioY = 0;
    }
    pause_map_targetX = pause_map_marioX;
    pause_map_targetY = pause_map_marioY;

    pause_map_cameraX = 0.0f;
    pause_map_cameraY = 0.0f;
    pause_map_cameraX -= (s32)(pause_map_targetX + pause_map_cameraX - 117.0);
    pause_map_cameraY -= (s32)(pause_map_targetY + pause_map_cameraY - 55.0);

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
    f32 pause_map_targetYPosTemp = pause_map_targetY;
    f32 pause_map_targetXPosTemp = pause_map_targetX;
    s32 xTemp;
    s32 yTemp;

    if (xMovement == 0.0f && yMovement == 0.0f && pause_map_cursorCurrentOption != -1) {
        PauseMapSpace* mapSpace = &pause_map_spaces[pause_map_cursorCurrentOption];

        xMovement = mapSpace->xPos - pause_map_targetXPosTemp;
        yMovement = mapSpace->yPos - pause_map_targetYPosTemp;

        xMovement *= 0.32;
        yMovement *= 0.32;
    }

    pause_map_targetX += xMovement;
    pause_map_targetY += yMovement;

    if (pause_map_targetX < 16.0f) {
        pause_map_targetX = 16.0f;
    }

    if (pause_map_targetY < 8.0f) {
        pause_map_targetY = 8.0f;
    }

    if (pause_map_targetX >= 316.0f) {
        pause_map_targetX = 315.0f;
    }

    if (pause_map_targetY >= 308.0f) {
        pause_map_targetY = 307.0f;
    }

    xTemp = pause_map_targetX + pause_map_cameraX - 117.0;
    yTemp = pause_map_targetY + pause_map_cameraY - 55.0;

    if (xTemp >= 53.0) {
        pause_map_cameraX -= xTemp - 53.0;
    }

    if (xTemp <= -37.0) {
        pause_map_cameraX -= xTemp + 37.0;
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
    if (evt_get_variable(0, EVT_STORY_PROGRESS) >= pause_map_spaces[pause_map_cursorCurrentOption].description) {
        gPauseMenuCurrentDescString++;
    }
}

void pause_map_update(void) {
    PauseMapSpace* mapSpace = &pause_map_spaces[0];
    f32 lowestSqSum = 10000.0f;
    f32 cursorOption = -1.0f;
    s32 i;

    pause_map_cursorCurrentOption = -1;
    pause_map_spacesInSnapRange = 0;

    for (i = 0; i < ARRAY_COUNT(pause_map_spaces); i++, mapSpace++) {
        if (evt_get_variable(0, EVT_SAVE_FLAG_PLACES_VISITED + i) != 0) {
            f32 deltaX = pause_map_targetX - mapSpace->xPos;
            f32 deltaY = pause_map_targetY - mapSpace->yPos;
            f32 sqSum = SQ(deltaX) + SQ(deltaY);

            if (sqSum < 400.0f) {
                pause_map_spacesInSnapRange++;
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
