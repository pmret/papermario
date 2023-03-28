#include "pause_common.h"
#include "message_ids.h"

extern Gfx gPauseDLWorldMap[];
extern u8 pause_world_map_png[];
extern Gfx gPauseDLPathPoints[];
extern Gfx gPauseDLArrows[];

void pause_map_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_map_draw_title(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_map_init(MenuPanel* tab);
void pause_map_handle_input(MenuPanel* tab);
void pause_map_update(MenuPanel* tab);
void pause_map_cleanup(MenuPanel* tab);

static s32 gPauseMapIconIDs[1];
static f32 gPauseMapCameraX;
static f32 gPauseMapCameraY;
static s32 gPauseMapMarioX;
static s32 gPauseMapMarioY;
static f32 gPauseMapTargetX;
static f32 gPauseMapTargetY;
static s32 gPauseMapCursorCurrentOption;
static s32 gPauseMapCursorCurrentOptionCopy;
static s32 gPauseMapSpacesInSnapRange;

HudScript* gPauseMapIconScripts[] = { &HES_MapWalk0 };
s32 D_8024FA34 = -1;
Vec2b gPauseMapPaths[][32] = {
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
PauseMapSpace gPauseMapSpaces[] = {
    { .pos = { .x = 116, .y = 185 }, .parent =  0, .pathLength =  7, .path = gPauseMapPaths[ 0], .afterRequirement = STORY_EPILOGUE,                    .id = LOCATION_TOAD_TOWN },
    { .pos = { .x = 118, .y = 151 }, .parent =  0, .pathLength =  3, .path = gPauseMapPaths[ 1], .afterRequirement = STORY_EPILOGUE,                    .id = LOCATION_PEACH_CASTLE_GROUNDS },
    { .pos = { .x = 143, .y = 134 }, .parent =  1, .pathLength =  3, .path = gPauseMapPaths[ 2], .afterRequirement = STORY_CH0_BEGAN_PEACH_MISSION,     .id = LOCATION_SHOOTING_STAR_SUMMIT },
    { .pos = { .x = 100, .y = 174 }, .parent =  0, .pathLength =  0, .path = gPauseMapPaths[ 3], .afterRequirement = STORY_61,                          .id = LOCATION_TOAD_TOWN_TUNNELS },
    { .pos = { .x =  36, .y = 157 }, .parent =  5, .pathLength =  0, .path = gPauseMapPaths[ 4], .afterRequirement = STORY_CH0_GOOMBARIO_JOINED_PARTY,  .id = LOCATION_GOOMBA_VILLAGE },
    { .pos = { .x =  74, .y = 154 }, .parent =  0, .pathLength =  4, .path = gPauseMapPaths[ 5], .afterRequirement = STORY_CH0_ARRIVED_AT_TOAD_TOWN,    .id = LOCATION_GOOMBA_ROAD },
    { .pos = { .x = 148, .y = 167 }, .parent =  0, .pathLength =  5, .path = gPauseMapPaths[ 6], .afterRequirement = STORY_CH1_STAR_SPRIT_DEPARTED,     .id = LOCATION_PLEASANT_PATH },
    { .pos = { .x = 154, .y = 148 }, .parent =  6, .pathLength =  2, .path = gPauseMapPaths[ 7], .afterRequirement = STORY_CH1_KOOPER_JOINED_PARTY,     .id = LOCATION_KOOPA_VILLAGE },
    { .pos = { .x = 205, .y = 152 }, .parent =  6, .pathLength =  7, .path = gPauseMapPaths[ 8], .afterRequirement = STORY_CH1_STAR_SPRIT_DEPARTED,     .id = LOCATION_KOOPA_BROS_FORTRESS },
    { .pos = { .x = 227, .y = 243 }, .parent =  0, .pathLength = 19, .path = gPauseMapPaths[ 9], .afterRequirement = STORY_61,                          .id = LOCATION_MT_RUGGED },
    { .pos = { .x = 266, .y = 206 }, .parent =  9, .pathLength = 13, .path = gPauseMapPaths[10], .afterRequirement = STORY_CH2_UNCOVERED_DRY_DRY_RUINS, .id = LOCATION_DRY_DRY_DESERT },
    { .pos = { .x = 280, .y = 191 }, .parent = 10, .pathLength =  2, .path = gPauseMapPaths[11], .afterRequirement = STORY_61,                          .id = LOCATION_DRY_DRY_OUTPOST },
    { .pos = { .x = 252, .y = 188 }, .parent = 10, .pathLength =  2, .path = gPauseMapPaths[12], .afterRequirement = STORY_CH2_BEGAN_PEACH_MISSION,     .id = LOCATION_DRY_DRY_RUINS },
    { .pos = { .x = 187, .y = 193 }, .parent =  0, .pathLength =  7, .path = gPauseMapPaths[13], .afterRequirement = STORY_CH3_ARRIVED_AT_BOOS_MANSION, .id = LOCATION_FOREVER_FOREST },
    { .pos = { .x = 170, .y = 180 }, .parent = 13, .pathLength =  1, .path = gPauseMapPaths[14], .afterRequirement = STORY_CH3_UNLOCKED_GUSTY_GULCH,    .id = LOCATION_BOOS_MANSION },
    { .pos = { .x = 223, .y = 170 }, .parent = 13, .pathLength =  4, .path = gPauseMapPaths[15], .afterRequirement = STORY_CH3_BEGAN_PEACH_MISSION,     .id = LOCATION_GUSTY_GULCH },
    { .pos = { .x = 263, .y = 156 }, .parent = 15, .pathLength =  4, .path = gPauseMapPaths[16], .afterRequirement = STORY_CH3_BEGAN_PEACH_MISSION,     .id = LOCATION_TUBBAS_MANOR },
    { .pos = { .x = 203, .y = 171 }, .parent = 15, .pathLength =  1, .path = gPauseMapPaths[17], .afterRequirement = STORY_CH3_BEGAN_PEACH_MISSION,     .id = LOCATION_WINDY_MILL },
    { .pos = { .x =  79, .y = 173 }, .parent =  0, .pathLength =  4, .path = gPauseMapPaths[18], .afterRequirement = STORY_CH4_STAR_SPRIT_DEPARTED,     .id = LOCATION_SHY_GUYS_TOYBOX },
    { .pos = { .x =  66, .y = 289 }, .parent =  0, .pathLength = 21, .path = gPauseMapPaths[19], .afterRequirement = STORY_CH5_ZIP_LINE_READY,          .id = LOCATION_JADE_JUNGLE },
    { .pos = { .x =  84, .y = 274 }, .parent = 19, .pathLength =  2, .path = gPauseMapPaths[20], .afterRequirement = STORY_61,                          .id = LOCATION_YOSHIS_VILLAGE },
    { .pos = { .x =  47, .y = 252 }, .parent = 19, .pathLength =  5, .path = gPauseMapPaths[21], .afterRequirement = STORY_CH5_BEGAN_PEACH_MISSION,     .id = LOCATION_MT_LAVALAVA },
    { .pos = { .x =  59, .y = 126 }, .parent =  0, .pathLength =  0, .path = gPauseMapPaths[22], .afterRequirement = STORY_CH6_BEGAN_PEACH_MISSION,     .id = LOCATION_FLOWER_FIELDS },
    { .pos = { .x =  58, .y =  92 }, .parent = 22, .pathLength =  4, .path = gPauseMapPaths[23], .afterRequirement = STORY_CH6_BEGAN_PEACH_MISSION,     .id = LOCATION_CLOUDY_CLIMB },
    { .pos = { .x = 183, .y = 125 }, .parent =  3, .pathLength =  0, .path = gPauseMapPaths[24], .afterRequirement = STORY_CH7_MAYOR_MURDER_SOLVED,     .id = LOCATION_SHIVER_CITY },
    { .pos = { .x = 203, .y = 126 }, .parent = 24, .pathLength =  1, .path = gPauseMapPaths[25], .afterRequirement = STORY_CH7_DEFEATED_MONSTAR,        .id = LOCATION_SHIVER_SNOWFIELD },
    { .pos = { .x = 234, .y = 128 }, .parent = 25, .pathLength =  2, .path = gPauseMapPaths[26], .afterRequirement = STORY_CH7_GOT_SNOWMAN_SCARF,       .id = LOCATION_STARBORN_VALLEY },
    { .pos = { .x = 220, .y = 112 }, .parent = 25, .pathLength =  2, .path = gPauseMapPaths[27], .afterRequirement = STORY_CH7_STAR_SPRIT_DEPARTED,     .id = LOCATION_SHIVER_MOUNTAIN },
    { .pos = { .x = 223, .y =  99 }, .parent = 27, .pathLength =  1, .path = gPauseMapPaths[28], .afterRequirement = STORY_CH7_STAR_SPRIT_DEPARTED,     .id = LOCATION_CRYSTAL_PALACE },
    { .pos = { .x = 158, .y = 110 }, .parent =  2, .pathLength =  6, .path = gPauseMapPaths[29], .afterRequirement = STORY_61,                          .id = LOCATION_STAR_WAY },
    { .pos = { .x = 163, .y =  78 }, .parent = 29, .pathLength =  6, .path = gPauseMapPaths[30], .afterRequirement = STORY_61,                          .id = LOCATION_STAR_HAVEN },
    { .pos = { .x =  96, .y =  49 }, .parent = 30, .pathLength = 13, .path = gPauseMapPaths[31], .afterRequirement = STORY_EPILOGUE,                    .id = LOCATION_BOWSERS_CASTLE },
    { .pos = { .x =  88, .y =  22 }, .parent = 31, .pathLength =  3, .path = gPauseMapPaths[32], .afterRequirement = STORY_EPILOGUE,                    .id = LOCATION_PEACHS_CASTLE },
    { .pos = { .x =  98, .y = 147 }, .parent =  0, .pathLength =  0, .path = gPauseMapPaths[33], .afterRequirement = STORY_61,                          .id = LOCATION_MARIOS_HOUSE }
};
s32 gPauseMapArrowWobble[] = { 0, 2, 3, 3, 4, 4, 4, 4, 3, 2, 1, 0 };
MenuWindowBP gPauseMapWindowBPs[] = {
    {
        .windowID = WINDOW_ID_PAUSE_MAP,
        .unk_01 = 0,
        .pos = { .x = 3, .y = 16 },
        .width = 289,
        .height = 154,
        .priority = WINDOW_PRIORITY_1,
        .fpDrawContents = &pause_map_draw_contents,
        .tab = NULL,
        .parentID = WINDOW_ID_PAUSE_MAIN,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { .customStyle = &gPauseWS_26 }
    },
    {
        .windowID = WINDOW_ID_PAUSE_MAP_TITLE,
        .unk_01 = 0,
        .pos = { .x = 56, .y = 124 },
        .width = 180,
        .height = 20,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &pause_map_draw_title,
        .tab = NULL,
        .parentID = WINDOW_ID_PAUSE_MAP,
        .fpUpdate = { WINDOW_UPDATE_SHOW },
        .extraFlags = 0,
        .style = { .customStyle = &gPauseWS_28 }
    },
    { },
    { },
    { },
    { },
    { }
};
MenuPanel gPausePanelMap = {
    .initialized = FALSE,
    .col = 0,
    .row = 0,
    .selected = 0,
    .page = 0,
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
    s32 x1 = gPauseMapSpaces[space->parent].pos.x;
    s32 y1 = gPauseMapSpaces[space->parent].pos.y;
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
    s32 cameraX = gPauseMapCameraX;
    s32 cameraY = gPauseMapCameraY;
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

    gSPDisplayList(gMainGfxPos++, gPauseDLWorldMap);
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

    gSPDisplayList(gMainGfxPos++, gPauseDLPathPoints);

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

    mapSpace = gPauseMapSpaces;
    camX = cameraX + baseX;
    camY = cameraY + baseY;
    for (i = 0; i < ARRAY_COUNT(gPauseMapSpaces); i++, mapSpace++) {
        posX = mapSpace->pos.x;
        posY = mapSpace->pos.y;


        if (evt_get_variable(NULL, GF_MAP_ToadTown + i) == 0) {
            continue;
        }

        if (i != gPauseMapCursorCurrentOption) {
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
    hud_element_set_render_pos(gPauseMapIconIDs[0], mapULX + gPauseMapMarioX, mapULY + gPauseMapMarioY - 7);
    hud_element_draw_without_clipping(gPauseMapIconIDs[0]);

    currentTab = gPauseMenuCurrentTab;
    if (currentTab == 6) {
        pause_set_cursor_pos(WINDOW_ID_PAUSE_MAP, mapULX + gPauseMapTargetX - 8.0f, mapULY + gPauseMapTargetY);

        if (gPauseMenuCurrentTab == currentTab) {
            offset = gPauseMapArrowWobble[gGameStatusPtr->frameCounter % 12];
            offsetLeft = offset;
            offsetRight = offset;
            offsetUp = offset;
            offsetDown = offset;

            gSPDisplayList(gMainGfxPos++, gPauseDLArrows);

            if (!(gPauseMapCameraX < 0.0f)) {
                offsetLeft = 0;
            }
            pause_map_draw_border_arrows(0, baseX + 26 - offsetLeft, baseY + height / 2 - 8);

            if (!(gPauseMapCameraX > -86.0f)) {
                offsetRight = 0;
            }
            pause_map_draw_border_arrows(1, baseX + width - 50 + offsetRight, baseY + height / 2 - 8);

            if (!(gPauseMapCameraY < 0.0f)) {
                offsetUp = 0;
            }
            pause_map_draw_border_arrows(2, baseX + width / 2 - 8, baseY + 24 - offsetUp);

            if (!(gPauseMapCameraY > -210.0f)) {
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
        if (gPauseMapCursorCurrentOption != -1) {
            msgWidth = get_msg_width(MSG_Menus_00F2 + (gPauseMapCursorCurrentOption * 3), 0);
            msgID = MSG_Menus_00F2 + (gPauseMapCursorCurrentOption * 3);
            draw_msg(msgID, baseX + ((width - msgWidth) >> 1), baseY + 1, 255, MSG_PAL_WHITE, 0);
        }
    }
}

void pause_map_init(MenuPanel* tab) {
    s32 currentLocation;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPauseMapIconScripts); i++) {
        gPauseMapIconIDs[i] = hud_element_create(gPauseMapIconScripts[i]);
        hud_element_set_flags(gPauseMapIconIDs[i], HUD_ELEMENT_FLAG_80);
    }

    for (i = 0; i < ARRAY_COUNT(gPauseMapWindowBPs); i++) {
        gPauseMapWindowBPs[i].tab = tab;
    }

    setup_pause_menu_tab(gPauseMapWindowBPs, ARRAY_COUNT(gPauseMapWindowBPs));
    gPauseMapCursorCurrentOption = -1;
    gPauseMapSpacesInSnapRange = 0;
    gPauseMapCursorCurrentOptionCopy = -1;
    currentLocation = evt_get_variable(0, GB_WorldLocation);

    for (i = 0; i < ARRAY_COUNT(gPauseMapSpaces); i++) {
        if (gPauseMapSpaces[i].id == currentLocation) {
            break;
        }
    }

    if (i < ARRAY_COUNT(gPauseMapSpaces)) {
        gPauseMapMarioX = gPauseMapSpaces[i].pos.x;
        gPauseMapMarioY = gPauseMapSpaces[i].pos.y;
    } else {
        gPauseMapMarioX = 0;
        gPauseMapMarioY = 0;
    }
    gPauseMapTargetX = gPauseMapMarioX;
    gPauseMapTargetY = gPauseMapMarioY;

    gPauseMapCameraX = 0.0f;
    gPauseMapCameraY = 0.0f;
    gPauseMapCameraX -= (s32)(gPauseMapTargetX + gPauseMapCameraX - 117.0);
    gPauseMapCameraY -= (s32)(gPauseMapTargetY + gPauseMapCameraY - 55.0);

    if (gPauseMapCameraX > 0)  {
        gPauseMapCameraX = 0;
    }
    if (gPauseMapCameraY > 0) {
        gPauseMapCameraY = 0;
    }

    if (gPauseMapCameraX <= -86.0f) {
        gPauseMapCameraX = -85.0f;
    }
    if (gPauseMapCameraY <= -210.0f) {
        gPauseMapCameraY = -209.0f;
    }

    tab->initialized = TRUE;
}

void pause_map_handle_input(MenuPanel* tab) {
    f32 xMovement = gGameStatusPtr->stickX[0] * 0.05f;
    f32 yMovement = -gGameStatusPtr->stickY[0] * 0.05f;
    f32 gPauseMapTargetYPosTemp = gPauseMapTargetY;
    f32 gPauseMapTargetXPosTemp = gPauseMapTargetX;
    s32 xTemp;
    s32 yTemp;

    if (xMovement == 0.0f && yMovement == 0.0f && gPauseMapCursorCurrentOption != -1) {
        PauseMapSpace* mapSpace = &gPauseMapSpaces[gPauseMapCursorCurrentOption];

        xMovement = mapSpace->pos.x - gPauseMapTargetXPosTemp;
        yMovement = mapSpace->pos.y - gPauseMapTargetYPosTemp;

        xMovement *= 0.32;
        yMovement *= 0.32;
    }

    gPauseMapTargetX += xMovement;
    gPauseMapTargetY += yMovement;

    if (gPauseMapTargetX < 16.0f) {
        gPauseMapTargetX = 16.0f;
    }

    if (gPauseMapTargetY < 8.0f) {
        gPauseMapTargetY = 8.0f;
    }

    if (gPauseMapTargetX >= 316.0f) {
        gPauseMapTargetX = 315.0f;
    }

    if (gPauseMapTargetY >= 308.0f) {
        gPauseMapTargetY = 307.0f;
    }

    xTemp = gPauseMapTargetX + gPauseMapCameraX - 117.0;
    yTemp = gPauseMapTargetY + gPauseMapCameraY - 55.0;

    if (xTemp >= 53.0) {
        gPauseMapCameraX -= xTemp - 53.0;
    }

    if (xTemp <= -37.0) {
        gPauseMapCameraX -= xTemp + 37.0;
    }

    if (yTemp >= 15.0) {
        gPauseMapCameraY -= yTemp - 15.0;
    }

    if (yTemp <= -15.0) {
        gPauseMapCameraY -= yTemp + 15.0;
    }

    if (gPauseMapCameraX > 0.0f) {
        gPauseMapCameraX = 0.0f;
    }

    if (gPauseMapCameraY > 0.0f) {
        gPauseMapCameraY = 0.0f;
    }

    if (gPauseMapCameraX < -86.0f) {
        gPauseMapCameraX = -86.0f;
    }

    if (gPauseMapCameraY < -210.0f) {
        gPauseMapCameraY = -210.0f;
    }

    if (gPausePressedButtons & BUTTON_B) {
        sfx_play_sound(SOUND_MENU_BACK);
        gPauseMenuCurrentTab = 0;
        return;
    }

    gPauseCurrentDescIconScript = 0;
    if (gPauseMapCursorCurrentOption == -1) {
        gPauseCurrentDescMsg = MSG_NONE;
        return;
    }

    gPauseCurrentDescMsg = MSG_Menus_00F3 + (gPauseMapCursorCurrentOption * 3);

    // If the story has progressed enough, show the "after" description
    if (evt_get_variable(0, GB_StoryProgress) >= gPauseMapSpaces[gPauseMapCursorCurrentOption].afterRequirement) {
        gPauseCurrentDescMsg++;
    }
}

void pause_map_update(MenuPanel* tab) {
    PauseMapSpace* mapSpace = &gPauseMapSpaces[0];
    f32 lowestSqSum = 10000.0f;
    f32 cursorOption = -1.0f;
    s32 i;

    gPauseMapCursorCurrentOption = -1;
    gPauseMapSpacesInSnapRange = 0;

    for (i = 0; i < ARRAY_COUNT(gPauseMapSpaces); i++, mapSpace++) {
        if (evt_get_variable(0, GF_MAP_ToadTown + i) != 0) {
            f32 deltaX = gPauseMapTargetX - mapSpace->pos.x;
            f32 deltaY = gPauseMapTargetY - mapSpace->pos.y;
            f32 sqSum = SQ(deltaX) + SQ(deltaY);

            if (sqSum < 400.0f) {
                gPauseMapSpacesInSnapRange++;
            }

            if (sqSum < lowestSqSum && sqSum < 200.0f) {
                lowestSqSum = sqSum;
                cursorOption = i;
            }
        }
    }

    gPauseMapCursorCurrentOption = cursorOption;
    gPauseMapCursorCurrentOptionCopy = cursorOption;
}

void pause_map_cleanup(MenuPanel* tab) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPauseMapIconIDs); i++) {
        hud_element_free(gPauseMapIconIDs[i]);
    }
}
