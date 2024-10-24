#include "pause_common.h"
#include "message_ids.h"

#if VERSION_PAL
#define MAP_TITLE_X 36
#define MAP_TITLE_WIDTH 220
#else
#define MAP_TITLE_X 56
#define MAP_TITLE_WIDTH 180
#endif

extern Gfx PauseGfxWorldMap[];
extern Gfx PauseGfxPathPoints[];
extern Gfx PauseGfxArrows[];
extern u8 pause_world_map_png[];

void pause_map_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_map_draw_title(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_map_init(MenuPanel* tab);
void pause_map_handle_input(MenuPanel* tab);
void pause_map_update(MenuPanel* tab);
void pause_map_cleanup(MenuPanel* tab);

static HudElemID PauseMapHIDs[1];
static f32 PauseMapCameraX;
static f32 PauseMapCameraY;
static s32 PauseMapMarioX;
static s32 PauseMapMarioY;
static f32 PauseMapTargetX;
static f32 PauseMapTargetY;
static s32 PauseMapCursorCurrentOption;
static s32 PauseMapCursorCurrentOptionCopy;
static s32 PauseMapSpacesInSnapRange;

HudScript* PauseMapHudScripts[] = { &HES_MapWalk0 };
s32 D_8024FA34 = -1;

#include "world_map.inc.c"

s32 PauseMapArrowWobble[] = { 0, 2, 3, 3, 4, 4, 4, 4, 3, 2, 1, 0 };
MenuWindowBP PauseMapWindowBPs[] = {
    {
        .windowID = WIN_PAUSE_MAP,
        .unk_01 = 0,
        .pos = { .x = 3, .y = 16 },
        .width = 289,
        .height = 154,
        .priority = WINDOW_PRIORITY_1,
        .fpDrawContents = &pause_map_draw_contents,
        .tab = NULL,
        .parentID = WIN_PAUSE_MAIN,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { .customStyle = &gPauseWS_26 }
    },
    {
        .windowID = WIN_PAUSE_MAP_TITLE,
        .unk_01 = 0,
        .pos = { .x = MAP_TITLE_X, .y = 124 },
        .width = MAP_TITLE_WIDTH,
        .height = 20,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &pause_map_draw_title,
        .tab = NULL,
        .parentID = WIN_PAUSE_MAP,
        .fpUpdate = { WINDOW_UPDATE_SHOW },
        .extraFlags = 0,
        .style = { .customStyle = &gPauseWS_28 }
    },
    {},
    {},
    {},
    {},
    {}
};
MenuPanel gPausePanelMap = {
    .initialized = FALSE,
    .col = 0,
    .row = 0,
    .selected = 0,
    .state = 0,
    .numCols = 0,
    .numRows = 0,
    .numPages = 0,
    .gridData = NULL,
    .fpInit = &pause_map_init,
    .fpHandleInput = &pause_map_handle_input,
    .fpUpdate = &pause_map_update,
    .fpCleanup = &pause_map_cleanup
};

void pause_map_calc_path_points(PauseMapSpace* space) {
    Vec2b* path = space->path;
    s32 pathLength = space->pathLength;
    s32 x1 = PauseMapSpaces[space->parent].pos.x;
    s32 y1 = PauseMapSpaces[space->parent].pos.y;
    s32 x2 = space->pos.x;
    s32 y2 = space->pos.y;
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

void pause_map_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 cameraX = PauseMapCameraX;
    s32 cameraY = PauseMapCameraY;
    s32 i, j;
    s32 tileHeight;
    s32 x1, y1, x2, y2;
    s32 x1a, y1a, x2a, y2a;
    s32 posX, posY;
    s32 ult;
    PauseMapSpace* mapSpace;
    s32 camX, camY;
    s32 pathX, pathY;
    s32 currentTab;
    s32 offset, offsetLeft, offsetRight, offsetUp, offsetDown;
    s32 mapULX, mapULY;
    s32 bigPointX, bigPointY;
    Vec2b* path;
    s32 pathLength;

    gSPDisplayList(gMainGfxPos++, PauseGfxWorldMap);
    ult = -cameraX * 32;
    for (i = 0; i < 60; i++) {
        if (4 * i + 4 < 111) {
            tileHeight = 4;
        } else {
            tileHeight = 111 - 4 * i;
        }

        gDPLoadTextureTile(gMainGfxPos++, pause_world_map_png, G_IM_FMT_CI, G_IM_SIZ_8b, 320, 320,
                        0, i * 4 - cameraY, 319, i * 4 + tileHeight - 1 - cameraY, 0,
                        G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        pause_draw_rect((baseX + 26) * 4, (baseY + 22 + 4 * i) * 4, (baseX + 260) * 4,
        (baseY + 22 + i * 4 + tileHeight) * 4, 0, ult, (-cameraY + i * 4) * 32, 0x400, 0x400);
        gDPPipeSync(gMainGfxPos++);

        if (4 * i + 4 >= 110) {
            break;
        }
    }

    gSPDisplayList(gMainGfxPos++, PauseGfxPathPoints);

    x1 = baseX + 26;
    y1 = baseY + 22;
    x2 = baseX + 260;
    y2 = baseY + 132;

    if (x1 <= 0) {
        x1 = 1;
    }
    if (y1 <= 0) {
        y1 = 1;
    }

    if (x2 <= 0 || y2 <= 0 || x1 >= SCREEN_WIDTH - 1 || y1 >= SCREEN_HEIGHT - 1) {
        return;
    }

    if (x2 >= SCREEN_WIDTH - 1) {
        x2 = SCREEN_WIDTH - 1;
    }
    if (y2 >= SCREEN_HEIGHT - 1) {
        y2 = SCREEN_HEIGHT - 1;
    }

    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);

    mapSpace = PauseMapSpaces;
    camX = cameraX + baseX;
    camY = cameraY + baseY;
    for (i = 0; i < ARRAY_COUNT(PauseMapSpaces); i++, mapSpace++) {
        posX = mapSpace->pos.x;
        posY = mapSpace->pos.y;

        if (evt_get_variable(NULL, GF_MAP_ToadTown + i) == 0) {
            continue;
        }

        if (i != PauseMapCursorCurrentOption) {
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 220, 80, 30, 255);
        } else {
            gDPSetPrimColor(gMainGfxPos++, 0, 0, (gGameStatusPtr->frameCounter * 10) % 120 + 120,
                                                   (gGameStatusPtr->frameCounter * 10) % 120 + 120,
                                                   (gGameStatusPtr->frameCounter * 10) % 120, 255);
        }

        bigPointX = camX + 26 + posX;
        bigPointY = camY + 22 + posY;
        pause_draw_rect((bigPointX - 8) * 4, (bigPointY - 8) * 4, (bigPointX + 8) * 4, (bigPointY + 8) * 4, 0, 0, 0, 0x400, 0x400);
        gDPPipeSync(gMainGfxPos++);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 230, 190, 180, 255);

        pathLength = mapSpace->pathLength;
        path = mapSpace->path;
        if (path) {
            pathX = 0;
            pathY = 0;
            for (j = 0; j < pathLength; j++, path++) {
                pathX += path->x;
                pathY += path->y;
                pause_draw_rect((camX + 26 + posX + pathX - 8) * 4, (camY + 22 + posY + pathY - 8) * 4, (camX + 26 + posX + pathX + 8) * 4, (camY + 22 + posY + pathY + 8) * 4, 1, 0, 0, 0x400, 0x400);
            }
        }
    }

    mapULX = baseX + 26 + cameraX;
    mapULY = baseY + 22 + cameraY;
    hud_element_set_render_pos(PauseMapHIDs[0], mapULX + PauseMapMarioX, mapULY + PauseMapMarioY - 7);
    hud_element_draw_without_clipping(PauseMapHIDs[0]);

    currentTab = gPauseMenuCurrentTab;
    if (currentTab == 6) {
        pause_set_cursor_pos(WIN_PAUSE_MAP, mapULX + PauseMapTargetX - 8.0f, mapULY + PauseMapTargetY);

        if (gPauseMenuCurrentTab == currentTab) {
            offset = PauseMapArrowWobble[gGameStatusPtr->frameCounter % 12];
            offsetLeft = offset;
            offsetRight = offset;
            offsetUp = offset;
            offsetDown = offset;

            gSPDisplayList(gMainGfxPos++, PauseGfxArrows);

            if (!(PauseMapCameraX < 0.0f)) {
                offsetLeft = 0;
            }
            pause_map_draw_border_arrows(0, baseX + 26 - offsetLeft, baseY + height / 2 - 8);

            if (!(PauseMapCameraX > -86.0f)) {
                offsetRight = 0;
            }
            pause_map_draw_border_arrows(1, baseX + width - 50 + offsetRight, baseY + height / 2 - 8);

            if (!(PauseMapCameraY < 0.0f)) {
                offsetUp = 0;
            }
            pause_map_draw_border_arrows(2, baseX + width / 2 - 8, baseY + 24 - offsetUp);

            if (!(PauseMapCameraY > -210.0f)) {
                offsetDown = 0;
            }
            pause_map_draw_border_arrows(3, baseX + width / 2 - 8, baseY + height - 44 + offsetDown);
        }
    }
    {
        s32 x1, y1, x2, y2;

        x1 = baseX + 18;
        y1 = baseY + 14;
        x2 = baseX + 268;
        y2 = baseY + 140;

        if (x1 <= 0) {
            x1 = 1;
        }
        if (y1 <= 0) {
            y1 = 1;
        }

        if (x2 <= 0 || y2 <= 0 || x1 >= SCREEN_WIDTH - 1 || y1 >= SCREEN_HEIGHT - 1) {
            return;
        }

        if (x2 >= SCREEN_WIDTH - 1) {
            x2 = SCREEN_WIDTH - 1;
        }
        if (y2 >= SCREEN_HEIGHT - 1) {
            y2 = SCREEN_HEIGHT - 1;
        }

        gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);
    }
    draw_box(0, &gPauseWS_27, baseX + 18, baseY + 14, 0, 250, 126, opacity, darkening, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, width, height, 0);
}

void pause_map_draw_title(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 msgWidth;
    s32 msgID;

    if (gPauseMenuCurrentTab == 6) {
        if (PauseMapCursorCurrentOption != -1) {
            msgWidth = get_msg_width(MSG_Menus_00F2 + (PauseMapCursorCurrentOption * 3), 0);
            msgID = MSG_Menus_00F2 + (PauseMapCursorCurrentOption * 3);
            draw_msg(msgID, baseX + ((width - msgWidth) >> 1), baseY + 1, 255, MSG_PAL_WHITE, 0);
        }
    }
}

void pause_map_init(MenuPanel* tab) {
    s32 currentLocation;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(PauseMapHudScripts); i++) {
        PauseMapHIDs[i] = hud_element_create(PauseMapHudScripts[i]);
        hud_element_set_flags(PauseMapHIDs[i], HUD_ELEMENT_FLAG_80);
    }

    for (i = 0; i < ARRAY_COUNT(PauseMapWindowBPs); i++) {
        PauseMapWindowBPs[i].tab = tab;
    }

    setup_pause_menu_tab(PauseMapWindowBPs, ARRAY_COUNT(PauseMapWindowBPs));
    PauseMapCursorCurrentOption = -1;
    PauseMapSpacesInSnapRange = 0;
    PauseMapCursorCurrentOptionCopy = -1;
    currentLocation = evt_get_variable(0, GB_WorldLocation);

    for (i = 0; i < ARRAY_COUNT(PauseMapSpaces); i++) {
        if (PauseMapSpaces[i].id == currentLocation) {
            break;
        }
    }

    if (i < ARRAY_COUNT(PauseMapSpaces)) {
        PauseMapMarioX = PauseMapSpaces[i].pos.x;
        PauseMapMarioY = PauseMapSpaces[i].pos.y;
    } else {
        PauseMapMarioX = 0;
        PauseMapMarioY = 0;
    }
    PauseMapTargetX = PauseMapMarioX;
    PauseMapTargetY = PauseMapMarioY;

    PauseMapCameraX = 0.0f;
    PauseMapCameraY = 0.0f;
    PauseMapCameraX -= (s32)(PauseMapTargetX + PauseMapCameraX - 117.0);
    PauseMapCameraY -= (s32)(PauseMapTargetY + PauseMapCameraY - 55.0);

    if (PauseMapCameraX > 0)  {
        PauseMapCameraX = 0;
    }
    if (PauseMapCameraY > 0) {
        PauseMapCameraY = 0;
    }

    if (PauseMapCameraX <= -86.0f) {
        PauseMapCameraX = -85.0f;
    }
    if (PauseMapCameraY <= -210.0f) {
        PauseMapCameraY = -209.0f;
    }

    tab->initialized = TRUE;
}

void pause_map_handle_input(MenuPanel* tab) {
    f32 xMovement = gGameStatusPtr->stickX[0] * 0.05f;
    f32 yMovement = -gGameStatusPtr->stickY[0] * 0.05f;
    f32 PauseMapTargetYPosTemp = PauseMapTargetY;
    f32 PauseMapTargetXPosTemp = PauseMapTargetX;
    s32 xTemp;
    s32 yTemp;

    if (xMovement == 0.0f && yMovement == 0.0f && PauseMapCursorCurrentOption != -1) {
        PauseMapSpace* mapSpace = &PauseMapSpaces[PauseMapCursorCurrentOption];

        xMovement = mapSpace->pos.x - PauseMapTargetXPosTemp;
        yMovement = mapSpace->pos.y - PauseMapTargetYPosTemp;

        xMovement *= 0.32;
        yMovement *= 0.32;
    }

    PauseMapTargetX += xMovement;
    PauseMapTargetY += yMovement;

    if (PauseMapTargetX < 16.0f) {
        PauseMapTargetX = 16.0f;
    }

    if (PauseMapTargetY < 8.0f) {
        PauseMapTargetY = 8.0f;
    }

    if (PauseMapTargetX >= 316.0f) {
        PauseMapTargetX = 315.0f;
    }

    if (PauseMapTargetY >= 308.0f) {
        PauseMapTargetY = 307.0f;
    }

    xTemp = PauseMapTargetX + PauseMapCameraX - 117.0;
    yTemp = PauseMapTargetY + PauseMapCameraY - 55.0;

    if (xTemp >= 53.0) {
        PauseMapCameraX -= xTemp - 53.0;
    }

    if (xTemp <= -37.0) {
        PauseMapCameraX -= xTemp + 37.0;
    }

    if (yTemp >= 15.0) {
        PauseMapCameraY -= yTemp - 15.0;
    }

    if (yTemp <= -15.0) {
        PauseMapCameraY -= yTemp + 15.0;
    }

    if (PauseMapCameraX > 0.0f) {
        PauseMapCameraX = 0.0f;
    }

    if (PauseMapCameraY > 0.0f) {
        PauseMapCameraY = 0.0f;
    }

    if (PauseMapCameraX < -86.0f) {
        PauseMapCameraX = -86.0f;
    }

    if (PauseMapCameraY < -210.0f) {
        PauseMapCameraY = -210.0f;
    }

    if (gPausePressedButtons & BUTTON_B) {
        sfx_play_sound(SOUND_MENU_BACK);
        gPauseMenuCurrentTab = 0;
        return;
    }

    gPauseCurrentDescIconScript = 0;
    if (PauseMapCursorCurrentOption == -1) {
        gPauseCurrentDescMsg = MSG_NONE;
        return;
    }

    gPauseCurrentDescMsg = MSG_Menus_00F3 + (PauseMapCursorCurrentOption * 3);

    // If the story has progressed enough, show the "after" description
    if (evt_get_variable(0, GB_StoryProgress) >= PauseMapSpaces[PauseMapCursorCurrentOption].afterRequirement) {
        gPauseCurrentDescMsg++;
    }
}

void pause_map_update(MenuPanel* tab) {
    PauseMapSpace* mapSpace = &PauseMapSpaces[0];
    f32 lowestSqSum = 10000.0f;
    f32 cursorOption = -1.0f;
    s32 i;

    PauseMapCursorCurrentOption = -1;
    PauseMapSpacesInSnapRange = 0;

    for (i = 0; i < ARRAY_COUNT(PauseMapSpaces); i++, mapSpace++) {
        if (evt_get_variable(0, GF_MAP_ToadTown + i) != 0) {
            f32 deltaX = PauseMapTargetX - mapSpace->pos.x;
            f32 deltaY = PauseMapTargetY - mapSpace->pos.y;
            f32 sqSum = SQ(deltaX) + SQ(deltaY);

            if (sqSum < 400.0f) {
                PauseMapSpacesInSnapRange++;
            }

            if (sqSum < lowestSqSum && sqSum < 200.0f) {
                lowestSqSum = sqSum;
                cursorOption = i;
            }
        }
    }

    PauseMapCursorCurrentOption = cursorOption;
    PauseMapCursorCurrentOptionCopy = cursorOption;
}

void pause_map_cleanup(MenuPanel* tab) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(PauseMapHIDs); i++) {
        hud_element_free(PauseMapHIDs[i]);
    }
}
