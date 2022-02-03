#include "pause_common.h"
#include "message_ids.h"

void pause_map_init(MenuPanel* tab);
void pause_map_handle_input(MenuPanel* tab);
void pause_map_update(MenuPanel* tab);
void pause_map_cleanup(MenuPanel* tab);

extern Gfx gPauseDLWorldMap[];
extern s32 D_802510B0[];
extern Gfx D_8026F1B8[];
extern Gfx gPauseDLArrows[];

HudScript* D_8024FA30[] = { HudScript_MapWalk0 };
s32 D_8024FA34 = -1;
Vec2b D_8024FA38[][32] = {
    { { 1, -10 }, { 1, -8 }, { -9, -2 }, { -8, 0 }, { -8, 0 }, { -7, -3 }, { -5, -3 }, },
	{ { -1, 24 }, { 1, -8 }, { 2, -7 } },
	{ { -3, 7 }, { -7, 4 }, { -8, 2 } },
	{ },
	{ },
	{ { -8, -3 }, { -7, 0 }, { -8, 1 }, { -7, 2 } },
	{ { -9, 0 }, { -6, -1 }, { -7, 0 }, { -8, 1 }, { -1, 8 } },
	{ { 1, 6 }, { -3, 6 } },
	{ { -7, 1 }, { -7, 3 }, { -7, 3 }, { -7, 3 }, { -7, 1 }, { -7, 2 }, { -7, 0 } },
	{ { -9, 3 }, { -8, 0 }, { -8, 0 }, { -9, -2 }, { -7, -4 }, { -7, -4 }, { -6, -5 }, { -5, -6 }, { -1, -7 }, { -3, -6 }, { -3, -6 }, { -7, -4 }, { -7, 0 }, { -8, 0 }, { -8, 0 }, { -8, 0 }, { -8, 0 }, { 0, -6 }, { 0, -6 } },
	{ { -6, 5 }, { -6, 3 }, { -8, 0 }, { -8, -4 }, { -5, -5 }, { -8, -3 }, { -8, 1 }, { -5, 5 }, { -2, 7 }, { 2, 7 }, { 5, 5 }, { 6, 5 }, { 6, 3 } },
	{ { -2, 6 }, { -4, 4 } },
	{ { 4, 6 }, { 4, 5 } },
	{ { -8, -1 }, { -10, -2 }, { -8, -2 }, { -9, -1 }, { -8, -1 }, { -10, 0 }, { -9, 0 } },
	{ { 8, 6 } },
	{ { -7, 4 }, { -7, 5 }, { -7, 4 }, { -7, 5 } },
	{ { -8, 2 }, { -8, 3 }, { -8, 3 }, { -8, 3 } },
	{ { 10, -1 } },
	{ { 6, 6 }, { 6, 6 }, { 8, 2 }, { 7, -1 } },
	{ { 11, 2 }, { 11, 0 }, { 11, -2 }, { 10, -3 }, { 7, -7 }, { 3, -8 }, { 0, -9 }, { -4, -7 }, { -9, -3 }, { -10, -2 }, { -9, -2 }, { -7, -6 }, { -2, -9 }, { 1, -9 }, { 0, -9 }, { -8, -5 }, { -9, -2 }, { 1, -8 }, { 9, -2 }, { 9, -2 }, { 8, -5 } },
	{ { -9, 3 }, { -5, 5 } },
	{ { -5, 6 }, { -2, 9 }, { 2, 8 }, { 7, 6 }, { 7, 4 } },
	{ },
	{ { -3, 6 }, { 0, 7 }, { 5, 6 }, { 1, 7 } },
	{ },
	{ { -9, -2 } },
	{ { -11, 1 }, { -9, -2 } },
	{ { -7, 3 }, { -6, 5 } },
	{ { 0, 7 } },
	{ { -9, 3 }, { -8, 1 }, { -7, 1 }, { -7, 4 }, { 2, 6 }, { 8, 3 } },
	{ { -3, 6 }, { 2, 6 }, { 8, 3 }, { 6, 5 }, { -2, 6 }, { -6, 3 } },
	{ { -6, 5 }, { -2, 7 }, { 2, 7 }, { 6, 6 }, { 8, 3 }, { 8, 0 }, { 8, -3 }, { 8, -5 }, { 6, -5 }, { 7, -4 }, { 8, -1 }, { 8, 3 }, { 2, 8 } },
	{ { -3, 7 }, { 0, 6 }, { 4, 7 } },
    {}
};
PauseMapSpace pause_map_spaces[] = {
    { .pos = { .x = 0x74, .y = 0xb9 }, .parent = 0, .pathLength = 7, .unk_06 = 0, .path = D_8024FA38[0], .afterRequirement = 0x60, .id = 1 },
    { .pos = { .x = 0x76, .y = 0x97 }, .parent = 0, .pathLength = 3, .unk_06 = 0, .path = D_8024FA38[1], .afterRequirement = 0x60, .id = 0x19 },
    { .pos = { .x = 0x8F, .y = 0x86 }, .parent = 1, .pathLength = 3, .unk_06 = 0, .path = D_8024FA38[2], .afterRequirement = -0x69, .id = 0x1B },
    { .pos = { .x = 0x64, .y = 0xAE }, .parent = 0, .pathLength = 0, .unk_06 = 0, .path = D_8024FA38[3], .afterRequirement = 0x61, .id = 2 },
    { .pos = { .x = 0x24, .y = 0x9D }, .parent = 5, .pathLength = 0, .unk_06 = 0, .path = D_8024FA38[4], .afterRequirement = -0x73, .id = 0x1E },
    { .pos = { .x = 0x4A, .y = 0x9A }, .parent = 0, .pathLength = 4, .unk_06 = 0, .path = D_8024FA38[5], .afterRequirement = -0x6B, .id = 0x1F },
    { .pos = { .x = 0x94, .y = 0xA7 }, .parent = 0, .pathLength = 5, .unk_06 = 0, .path = D_8024FA38[6], .afterRequirement = -0x4B, .id = 0x20 },
    { .pos = { .x = 0x9A, .y = 0x94 }, .parent = 6, .pathLength = 2, .unk_06 = 0, .path = D_8024FA38[7], .afterRequirement = -0x5C, .id = 0x21 },
    { .pos = { .x = 0xCD, .y = 0x98 }, .parent = 6, .pathLength = 7, .unk_06 = 0, .path = D_8024FA38[8], .afterRequirement = -0x4B, .id = 7 },
    { .pos = { .x = 0xE3, .y = 0xF3 }, .parent = 0, .pathLength = 19, .unk_06 = 0, .path = D_8024FA38[9], .afterRequirement = 0x61, .id = 8 },
    { .pos = { .x = 0x10A, .y = 0xCE }, .parent = 9, .pathLength = 13, .unk_06 = 0, .path = D_8024FA38[10], .afterRequirement = -0x3E, .id = 10 },
    { .pos = { .x = 0x118, .y = 0xBF }, .parent = 10, .pathLength = 2, .unk_06 = 0, .path = D_8024FA38[11], .afterRequirement = 0x61, .id = 9 },
    { .pos = { .x = 0xFC, .y = 0xBC }, .parent = 10, .pathLength = 2, .unk_06 = 0, .path = D_8024FA38[12], .afterRequirement = -0x36, .id = 11 },
    { .pos = { .x = 0xBB, .y = 0xC1 }, .parent = 0, .pathLength = 7, .unk_06 = 0, .path = D_8024FA38[13], .afterRequirement = -0x30, .id = 12 },
    { .pos = { .x = 0xAA, .y = 0xB4 }, .parent = 13, .pathLength = 1, .unk_06 = 0, .path = D_8024FA38[14], .afterRequirement = -0x23, .id = 13 },
    { .pos = { .x = 0xDF, .y = 0xAA }, .parent = 13, .pathLength = 4, .unk_06 = 0, .path = D_8024FA38[15], .afterRequirement = -0xE, .id = 0x22 },
    { .pos = { .x = 0x107, .y = 0x9C }, .parent = 15, .pathLength = 4, .unk_06 = 0, .path = D_8024FA38[16], .afterRequirement = -0xE, .id = 15 },
    { .pos = { .x = 0xCB, .y = 0xAB }, .parent = 15, .pathLength = 1, .unk_06 = 0, .path = D_8024FA38[17], .afterRequirement = -0xE, .id = 0x23 },
    { .pos = { .x = 0x4F, .y = 0xAD }, .parent = 0, .pathLength = 4, .unk_06 = 0, .path = D_8024FA38[18], .afterRequirement = 7, .id = 16 },
    { .pos = { .x = 0x42, .y = 0x121 }, .parent = 0, .pathLength = 21, .unk_06 = 0, .path = D_8024FA38[19], .afterRequirement = 0x18, .id = 0x24 },
    { .pos = { .x = 0x54, .y = 0x112 }, .parent = 19, .pathLength = 2, .unk_06 = 0, .path = D_8024FA38[20], .afterRequirement = 0x61, .id = 0x25 },
    { .pos = { .x = 0x2F, .y = 0xFC }, .parent = 19, .pathLength = 5, .unk_06 = 0, .path = D_8024FA38[21], .afterRequirement = 0x26, .id = 0x12 },
    { .pos = { .x = 0x3B, .y = 0x7E }, .parent = 0, .pathLength = 0, .unk_06 = 0, .path = D_8024FA38[22], .afterRequirement = 0x3A, .id = 0x26 },
    { .pos = { .x = 0x3A, .y = 0x5C }, .parent = 22, .pathLength = 4, .unk_06 = 0, .path = D_8024FA38[23], .afterRequirement = 0x3A, .id = 0x27 },
    { .pos = { .x = 0xB7, .y = 0x7D }, .parent = 3, .pathLength = 0, .unk_06 = 0, .path = D_8024FA38[24], .afterRequirement = 0x43, .id = 0x28 },
    { .pos = { .x = 0xCB, .y = 0x7E }, .parent = 24, .pathLength = 1, .unk_06 = 0, .path = D_8024FA38[25], .afterRequirement = 0x45, .id = 0x29 },
    { .pos = { .x = 0xEA, .y = 0x80 }, .parent = 25, .pathLength = 2, .unk_06 = 0, .path = D_8024FA38[26], .afterRequirement = 0x48, .id = 0x2A },
    { .pos = { .x = 0xDC, .y = 0x70 }, .parent = 25, .pathLength = 2, .unk_06 = 0, .path = D_8024FA38[27], .afterRequirement = 0x59, .id = 0x2B },
    { .pos = { .x = 0xDF, .y = 0x63 }, .parent = 27, .pathLength = 1, .unk_06 = 0, .path = D_8024FA38[28], .afterRequirement = 0x59, .id = 0x15 },
    { .pos = { .x = 0x9E, .y = 0x6E }, .parent = 2, .pathLength = 6, .unk_06 = 0, .path = D_8024FA38[29], .afterRequirement = 0x61, .id = 0x1C },
    { .pos = { .x = 0xA3, .y = 0x4E }, .parent = 29, .pathLength = 6, .unk_06 = 0, .path = D_8024FA38[30], .afterRequirement = 0x61, .id = 0x1D },
    { .pos = { .x = 0x60, .y = 0x31 }, .parent = 30, .pathLength = 13, .unk_06 = 0, .path = D_8024FA38[31], .afterRequirement = 0x60, .id = 0x16 },
    { .pos = { .x = 0x58, .y = 0x16 }, .parent = 31, .pathLength = 3, .unk_06 = 0, .path = D_8024FA38[32], .afterRequirement = 0x60, .id = 0x1A },
    { .pos = { .x = 0x62, .y = 0x93 }, .parent = 0, .pathLength = 0, .unk_06 = 0, .path = D_8024FA38[33], .afterRequirement = 0x61, .id = 0x2C }
};
s32 D_80250560[] = { 0, 2, 3, 3, 4, 4, 4, 4, 3, 2, 1, 0 };
MenuWindowBP pause_map_windowBlueprints[] = { { .windowID = WINDOW_ID_41,
                                         .unk_01 = 0,
                                         .pos = { .x = 3,
                                                  .y = 16 },
                                         .width = 289,
                                         .height = 154,
                                         .unk_0A = { 1, 0},
                                         .fpDrawContents = &pause_map_draw_contents,
                                         .tab = NULL,
                                         .parentID = WINDOW_ID_PAUSE_MAIN,
                                         .fpUpdate = { 2 },
                                         .unk_1C = 0,
                                         .style = &gPauseWS_26 },

                                              { .windowID = WINDOW_ID_42,
                                         .unk_01 = 0,
                                         .pos = { .x = 0x38,
                                                  .y = 0x7C },
                                         .width = 180,
                                         .height = 20,
                                         .unk_0A = { 0, 0},
                                         .fpDrawContents = &pause_map_draw_title,
                                         .tab = NULL,
                                         .parentID = WINDOW_ID_41,
                                         .fpUpdate = { 1 },
                                         .unk_1C = 0,
                                         .style = &gPauseWS_28 },
                                         {},
                                         {},
                                         {},
                                         {},
                                         {} };
MenuPanel gPausePanelMap = { .initialized = FALSE, .col = 0, .row = 0, .selected = 0,
                         .page = 0,
                         .numCols = 0,
                         .numRows = 0,
                         .numPages = 0,
                         .gridData = NULL,
                         .fpInit = &pause_map_init,
                         .fpHandleInput = &pause_map_handle_input,
                         .fpUpdate = &pause_map_update,
                         .fpCleanup = &pause_map_cleanup };

void func_8024D930(PauseMapSpace* space) {
    Vec2b* path = space->path;
    s32 pathLength = space->pathLength;
    s32 x1 = pause_map_spaces[space->parent].pos.x;
    s32 y1 = pause_map_spaces[space->parent].pos.y;
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
    s32 cameraX = pause_map_cameraX;
    s32 cameraY = pause_map_cameraY;
    s32 i, j;
    s32 t5;
    s32 x1, y1, x2, y2;
    s32 x1a, y1a, x2a, y2a;
    s32 posX, posY;
    s32 q;
    PauseMapSpace* mapSpace;
    s32 camX, camY;
    s32 pathX, pathY;
    s32 currentTab;
    s32 offset, offset0, offset1, offset2, offset3;
    s32 bX, bY;
    s32 cX, cY;
    Vec2b* path;
    s32 pathLength;


    gSPDisplayList(gMasterGfxPos++, gPauseDLWorldMap);
    q = -cameraX * 32;
    for (i = 0; i < 60; i++) {
        if (4 * i + 4 < 0x6F) {
            t5 = 4;
        } else {
            t5 = 0x6F - 4 * i;
        }

        gDPLoadTextureTile(gMasterGfxPos++, &D_802510B0, G_IM_FMT_CI, G_IM_SIZ_8b, 320, 0,
                        0, i * 4 - cameraY, 319, i * 4 + t5 - 1 - cameraY, 0,
                        G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        pause_draw_rect((baseX + 0x1A) * 4, (baseY + 0x16 + 4 * i) * 4, (baseX + 0x104) * 4,
        (baseY + 0x16 + i * 4 + t5) * 4, 0, q, (-cameraY + i * 4) * 32, 0x400, 0x400);
        gDPPipeSync(gMasterGfxPos++);

        if (4 * i + 4 >= 0x6E) {
            break;
        }
    }

    gSPDisplayList(gMasterGfxPos++, D_8026F1B8);

    x1 = baseX + 0x1A;
    y1 = baseY + 0x16;
    x2 = baseX + 0x104;
    y2 = baseY + 0x84;

    if (x1 <= 0) {
        x1 = 1;
    }
    if (y1 <= 0) {
        y1 = 1;
    }

    if (x2 <= 0 || y2 <= 0 || x1 >= 319 || y1 >= 239) {
        return;
    }

    if (x2 >= 319) {
        x2 = 319;
    }
    if (y2 >= 239) {
        y2 = 239;
    }

    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);

    mapSpace = pause_map_spaces;
    camX = cameraX + baseX;
    camY = cameraY + baseY;
    for (i = 0; i < 34; i++, mapSpace++) {
        posX = mapSpace->pos.x;
        posY = mapSpace->pos.y;


        if (evt_get_variable(NULL, EVT_SAVE_FLAG(1962 + i)) == 0) {
            continue;
        }

        if (i != pause_map_cursorCurrentOption) {
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0xDC, 0x50, 0x1E, 0xFF);
        } else {
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, (gGameStatusPtr->frameCounter * 10) % 120 + 0x78,
                                                   (gGameStatusPtr->frameCounter * 10) % 120 + 0x78,
                                                   (gGameStatusPtr->frameCounter * 10) % 120, 0xFF);
        }

        cX = camX + 0x1A + posX;
        cY = camY + 0x16 + posY;
        pause_draw_rect((cX - 8) * 4, (cY - 8) * 4, (cX + 8) * 4, (cY + 8) * 4, 0, 0, 0, 0x400, 0x400);
        gDPPipeSync(gMasterGfxPos++);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0xE6, 0xBE, 0xB4, 0xFF);

        pathLength = mapSpace->pathLength;
        path = mapSpace->path;
        if (path) {
            pathX = 0;
            pathY = 0;
            for (j = 0; j < pathLength; j++, path++) {
                pathX += path->x;
                pathY += path->y;
                pause_draw_rect((camX + 0x1A + posX + pathX - 8) * 4, (camY + 0x16 + posY + pathY - 8) * 4, (camX + 0x1A + posX + pathX + 8) * 4, (camY + 0x16 + posY + pathY + 8) * 4, 1, 0, 0, 0x400, 0x400);
            }
        }
    }

    bX = baseX + 0x1A + cameraX;
    bY = baseY + 0x16 + cameraY;
    set_hud_element_render_pos(D_80270700[0], bX + pause_map_marioX, bY + pause_map_marioY - 7);
    draw_hud_element_3(D_80270700[0]);

    currentTab = gPauseMenuCurrentTab;
    if (currentTab == 6) {
        pause_set_cursor_pos(0x29, bX + pause_map_targetX - 8.0f, bY + pause_map_targetY);

        if (gPauseMenuCurrentTab == currentTab) {
            offset = D_80250560[gGameStatusPtr->frameCounter % 12];
            offset0 = offset;
            offset1 = offset;
            offset2 = offset;
            offset3 = offset;

            gSPDisplayList(gMasterGfxPos++, gPauseDLArrows);

            if (!(pause_map_cameraX < 0.0f)) {
                offset0 = 0;
            }
            pause_map_draw_border_arrows(0, baseX + 0x1A - offset0, baseY + height / 2 - 8);

            if (!(pause_map_cameraX > -86.0f)) {
                offset1 = 0;
            }
            pause_map_draw_border_arrows(1, baseX + width - 0x32 + offset1, baseY + height / 2 - 8);

            if (!(pause_map_cameraY < 0.0f)) {
                offset2 = 0;
            }
            pause_map_draw_border_arrows(2, baseX + width / 2 - 8, baseY + 0x18 - offset2);

            if (!(pause_map_cameraY > -210.0f)) {
                offset3 = 0;
            }
            pause_map_draw_border_arrows(3, baseX + width / 2 - 8, baseY + height - 0x2C + offset3);
        }
    }

    x1a = baseX + 0x12;
    y1a = baseY + 0xE;
    x2a = baseX + 0x10C;
    y2a = baseY + 0x8C;

    if (x1a <= 0) {
        x1a = 1;
    }
    if (y1a <= 0) {
        y1a = 1;
    }

    if (x2a <= 0 || y2a <= 0 || x1a >= 319 || y1a >= 239) {
        return;
    }

    if (x2a >= 319) {
        x2a = 319;
    }
    if (y2a >= 239) {
        y2a = 239;
    }

    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, x1a, y1a, x2a, y2a);
    draw_box(0, &gPauseWS_27, baseX + 0x12, baseY + 0xE, 0, 0xFA, 0x7E, opacity, darkening, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, width, height, 0);
}

void pause_map_draw_title(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 msgWidth;
    s32 msgID;

    if (gPauseMenuCurrentTab == 6) {
        if (pause_map_cursorCurrentOption != -1) {
            msgWidth = get_msg_width(MSG_pause_map_location_0_name + (pause_map_cursorCurrentOption * 3), 0);
            msgID = MSG_pause_map_location_0_name + (pause_map_cursorCurrentOption * 3);
            draw_msg(msgID, baseX + ((width - msgWidth) >> 1), baseY + 1, 255, 0, 0);
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
        pause_map_marioX = pause_map_spaces[i].pos.x;
        pause_map_marioY = pause_map_spaces[i].pos.y;
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

    tab->initialized = TRUE;
}

void pause_map_handle_input(MenuPanel* tab) {
    f32 xMovement = gGameStatusPtr->stickX * 0.05f;
    f32 yMovement = -gGameStatusPtr->stickY * 0.05f;
    f32 pause_map_targetYPosTemp = pause_map_targetY;
    f32 pause_map_targetXPosTemp = pause_map_targetX;
    s32 xTemp;
    s32 yTemp;

    if (xMovement == 0.0f && yMovement == 0.0f && pause_map_cursorCurrentOption != -1) {
        PauseMapSpace* mapSpace = &pause_map_spaces[pause_map_cursorCurrentOption];

        xMovement = mapSpace->pos.x - pause_map_targetXPosTemp;
        yMovement = mapSpace->pos.y - pause_map_targetYPosTemp;

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

    if (gPausePressedButtons & B_BUTTON) {
        sfx_play_sound(0xCA);
        gPauseMenuCurrentTab = 0;
        return;
    }

    gPauseCurrentDescIconScript = 0;
    if (pause_map_cursorCurrentOption == -1) {
        gPauseCurrentDescMsg = 0;
        return;
    }

    gPauseCurrentDescMsg = MSG_pause_map_location_0_before_desc + (pause_map_cursorCurrentOption * 3);

    // If the story has progressed enough, show the "after" description
    if (evt_get_variable(0, EVT_STORY_PROGRESS) >= pause_map_spaces[pause_map_cursorCurrentOption].afterRequirement) {
        gPauseCurrentDescMsg++;
    }
}

void pause_map_update(MenuPanel* tab) {
    PauseMapSpace* mapSpace = &pause_map_spaces[0];
    f32 lowestSqSum = 10000.0f;
    f32 cursorOption = -1.0f;
    s32 i;

    pause_map_cursorCurrentOption = -1;
    pause_map_spacesInSnapRange = 0;

    for (i = 0; i < ARRAY_COUNT(pause_map_spaces); i++, mapSpace++) {
        if (evt_get_variable(0, EVT_SAVE_FLAG_PLACES_VISITED + i) != 0) {
            f32 deltaX = pause_map_targetX - mapSpace->pos.x;
            f32 deltaY = pause_map_targetY - mapSpace->pos.y;
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

void pause_map_cleanup(MenuPanel* tab) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80270700); i++) {
        free_hud_element(D_80270700[i]);
    }
}
