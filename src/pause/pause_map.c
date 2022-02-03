#include "pause_common.h"
#include "message_ids.h"

void pause_map_draw_contents(MenuPanel* panel, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void pause_map_draw_title(s32* arg1, s32 arg2, s32 textOffsetY, s32 textOffsetX);
void pause_map_init(MenuPanel* tab);
void pause_map_handle_input(MenuPanel* tab);
void pause_map_update(MenuPanel* tab);
void pause_map_cleanup(MenuPanel* tab);
void pause_set_cursor_pos(s32 windowID, s32 posX, s32 posY);

extern Gfx gPauseDLWorldMap[];
extern s32 D_802510B0[];
extern Gfx D_8026F1B8[];
extern Gfx gPauseDLArrows[];

s32 D_8024FA30[] = { 0x80242644, 0xFFFFFFFF };
s32 D_8024FA38[] = { 0x01F601F8, 0xF7FEF800, 0xF800F9FD, 0xFBFD0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FA78[] = { 0xFF1801F8, 0x02F90000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FAB8[] = { 0xFD07F904, 0xF8020000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FAF8[] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FB38[] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FB78[] = { 0xF8FDF900, 0xF801F902, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FBB8[] = { 0xF700FAFF, 0xF900F801, 0xFF080000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FBF8[] = { 0x0106FD06, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FC38[] = { 0xF901F903, 0xF903F903, 0xF901F902, 0xF9000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FC78[] = { 0xF703F800, 0xF800F7FE, 0xF9FCF9FC, 0xFAFBFBFA, 0xFFF9FDFA, 0xFDFAF9FC, 0xF900F800, 0xF800F800, 0xF80000FA, 0x00FA0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FCB8[] = { 0xFA05FA03, 0xF800F8FC, 0xFBFBF8FD, 0xF801FB05, 0xFE070207, 0x05050605, 0x06030000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FCF8[] = { 0xFE06FC04, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FD38[] = { 0x04060405, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FD78[] = { 0xF8FFF6FE, 0xF8FEF7FF, 0xF8FFF600, 0xF7000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FDB8[] = { 0x08060000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FDF8[] = { 0xF904F905, 0xF904F905, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FE38[] = { 0xF802F803, 0xF803F803, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FE78[] = { 0x0AFF0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FEB8[] = { 0x06060606, 0x080207FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FEF8[] = { 0x0B020B00, 0x0BFE0AFD, 0x07F903F8, 0x00F7FCF9, 0xF7FDF6FE, 0xF7FEF9FA, 0xFEF701F7, 0x00F7F8FB, 0xF7FE01F8, 0x09FE09FE, 0x08FB0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FF38[] = { 0xF703FB05, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FF78[] = { 0xFB06FE09, 0x02080706, 0x07040000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FFB8[] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_8024FFF8[] = { 0xFD060007, 0x05060107, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_80250038[] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_80250078[] = { 0xF7FE0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_802500B8[] = { 0xF501F7FE, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_802500F8[] = { 0xF903FA05, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_80250138[] = { 0x00070000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_80250178[] = { 0xF703F801, 0xF901F904, 0x02060803, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_802501B8[] = { 0xFD060206, 0x08030605, 0xFE06FA03, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_802501F8[] = { 0xFA05FE07, 0x02070606, 0x08030800, 0x08FD08FB, 0x06FB07FC, 0x08FF0803, 0x02080000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_80250238[] = { 0xFD070006, 0x04070000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
s32 D_80250278[] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
PauseMapSpace pause_map_spaces[] = {
    { .pos = { .x = 0x74, .y = 0xb9 }, .parent = 0, .pathLength = 7, .unk_06 = 0, .path = D_8024FA38, .afterRequirement = 0x60, .id = 1 },
    { .pos = { .x = 0x76, .y = 0x97 }, .parent = 0, .pathLength = 3, .unk_06 = 0, .path = D_8024FA78, .afterRequirement = 0x60, .id = 0x19 },
    { .pos = { .x = 0x8F, .y = 0x86 }, .parent = 1, .pathLength = 3, .unk_06 = 0, .path = D_8024FAB8, .afterRequirement = -0x69, .id = 0x1B },
    { .pos = { .x = 0x64, .y = 0xAE }, .parent = 0, .pathLength = 0, .unk_06 = 0, .path = D_8024FAF8, .afterRequirement = 0x61, .id = 2 },
    { .pos = { .x = 0x24, .y = 0x9D }, .parent = 5, .pathLength = 0, .unk_06 = 0, .path = D_8024FB38, .afterRequirement = -0x73, .id = 0x1E },
    { .pos = { .x = 0x4A, .y = 0x9A }, .parent = 0, .pathLength = 4, .unk_06 = 0, .path = D_8024FB78, .afterRequirement = -0x6B, .id = 0x1F },
    { .pos = { .x = 0x94, .y = 0xA7 }, .parent = 0, .pathLength = 5, .unk_06 = 0, .path = D_8024FBB8, .afterRequirement = -0x4B, .id = 0x20 },
    { .pos = { .x = 0x9A, .y = 0x94 }, .parent = 6, .pathLength = 2, .unk_06 = 0, .path = D_8024FBF8, .afterRequirement = -0x5C, .id = 0x21 },
    { .pos = { .x = 0xCD, .y = 0x98 }, .parent = 6, .pathLength = 7, .unk_06 = 0, .path = D_8024FC38, .afterRequirement = -0x4B, .id = 7 },
    { .pos = { .x = 0xE3, .y = 0xF3 }, .parent = 0, .pathLength = 19, .unk_06 = 0, .path = D_8024FC78, .afterRequirement = 0x61, .id = 8 },
    { .pos = { .x = 0x10A, .y = 0xCE }, .parent = 9, .pathLength = 13, .unk_06 = 0, .path = D_8024FCB8, .afterRequirement = -0x3E, .id = 10 },
    { .pos = { .x = 0x118, .y = 0xBF }, .parent = 10, .pathLength = 2, .unk_06 = 0, .path = D_8024FCF8, .afterRequirement = 0x61, .id = 9 },
    { .pos = { .x = 0xFC, .y = 0xBC }, .parent = 10, .pathLength = 2, .unk_06 = 0, .path = D_8024FD38, .afterRequirement = -0x36, .id = 11 },
    { .pos = { .x = 0xBB, .y = 0xC1 }, .parent = 0, .pathLength = 7, .unk_06 = 0, .path = D_8024FD78, .afterRequirement = -0x30, .id = 12 },
    { .pos = { .x = 0xAA, .y = 0xB4 }, .parent = 13, .pathLength = 1, .unk_06 = 0, .path = D_8024FDB8, .afterRequirement = -0x23, .id = 13 },
    { .pos = { .x = 0xDF, .y = 0xAA }, .parent = 13, .pathLength = 4, .unk_06 = 0, .path = D_8024FDF8, .afterRequirement = -0xE, .id = 0x22 },
    { .pos = { .x = 0x107, .y = 0x9C }, .parent = 15, .pathLength = 4, .unk_06 = 0, .path = D_8024FE38, .afterRequirement = -0xE, .id = 15 },
    { .pos = { .x = 0xCB, .y = 0xAB }, .parent = 15, .pathLength = 1, .unk_06 = 0, .path = D_8024FE78, .afterRequirement = -0xE, .id = 0x23 },
    { .pos = { .x = 0x4F, .y = 0xAD }, .parent = 0, .pathLength = 4, .unk_06 = 0, .path = D_8024FEB8, .afterRequirement = 7, .id = 16 },
    { .pos = { .x = 0x42, .y = 0x121 }, .parent = 0, .pathLength = 21, .unk_06 = 0, .path = D_8024FEF8, .afterRequirement = 0x18, .id = 0x24 },
    { .pos = { .x = 0x54, .y = 0x112 }, .parent = 19, .pathLength = 2, .unk_06 = 0, .path = D_8024FF38, .afterRequirement = 0x61, .id = 0x25 },
    { .pos = { .x = 0x2F, .y = 0xFC }, .parent = 19, .pathLength = 5, .unk_06 = 0, .path = D_8024FF78, .afterRequirement = 0x26, .id = 0x12 },
    { .pos = { .x = 0x3B, .y = 0x7E }, .parent = 0, .pathLength = 0, .unk_06 = 0, .path = D_8024FFB8, .afterRequirement = 0x3A, .id = 0x26 },
    { .pos = { .x = 0x3A, .y = 0x5C }, .parent = 22, .pathLength = 4, .unk_06 = 0, .path = D_8024FFF8, .afterRequirement = 0x3A, .id = 0x27 },
    { .pos = { .x = 0xB7, .y = 0x7D }, .parent = 3, .pathLength = 0, .unk_06 = 0, .path = D_80250038, .afterRequirement = 0x43, .id = 0x28 },
    { .pos = { .x = 0xCB, .y = 0x7E }, .parent = 24, .pathLength = 1, .unk_06 = 0, .path = D_80250078, .afterRequirement = 0x45, .id = 0x29 },
    { .pos = { .x = 0xEA, .y = 0x80 }, .parent = 25, .pathLength = 2, .unk_06 = 0, .path = D_802500B8, .afterRequirement = 0x48, .id = 0x2A },
    { .pos = { .x = 0xDC, .y = 0x70 }, .parent = 25, .pathLength = 2, .unk_06 = 0, .path = D_802500F8, .afterRequirement = 0x59, .id = 0x2B },
    { .pos = { .x = 0xDF, .y = 0x63 }, .parent = 27, .pathLength = 1, .unk_06 = 0, .path = D_80250138, .afterRequirement = 0x59, .id = 0x15 },
    { .pos = { .x = 0x9E, .y = 0x6E }, .parent = 2, .pathLength = 6, .unk_06 = 0, .path = D_80250178, .afterRequirement = 0x61, .id = 0x1C },
    { .pos = { .x = 0xA3, .y = 0x4E }, .parent = 29, .pathLength = 6, .unk_06 = 0, .path = D_802501B8, .afterRequirement = 0x61, .id = 0x1D },
    { .pos = { .x = 0x60, .y = 0x31 }, .parent = 30, .pathLength = 13, .unk_06 = 0, .path = D_802501F8, .afterRequirement = 0x60, .id = 0x16 },
    { .pos = { .x = 0x58, .y = 0x16 }, .parent = 31, .pathLength = 3, .unk_06 = 0, .path = D_80250238, .afterRequirement = 0x60, .id = 0x1A },
    { .pos = { .x = 0x62, .y = 0x93 }, .parent = 0, .pathLength = 0, .unk_06 = 0, .path = D_80250278, .afterRequirement = 0x61, .id = 0x2C }
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

void pause_map_draw_contents(MenuPanel* panel, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
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
        pause_draw_rect((arg1 + 0x1A) * 4, (arg2 + 0x16 + 4 * i) * 4, (arg1 + 0x104) * 4,
        (arg2 + 0x16 + i * 4 + t5) * 4, 0, q, (-cameraY + i * 4) * 32, 0x400, 0x400);
        gDPPipeSync(gMasterGfxPos++);

        if (4 * i + 4 >= 0x6E) {
            break;
        }
    }

    gSPDisplayList(gMasterGfxPos++, D_8026F1B8);

    x1 = arg1 + 0x1A;
    y1 = arg2 + 0x16;
    x2 = arg1 + 0x104;
    y2 = arg2 + 0x84;

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
    camX = cameraX + arg1;
    camY = cameraY + arg2;
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

    bX = arg1 + 0x1A + cameraX;
    bY = arg2 + 0x16 + cameraY;
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
            pause_map_draw_border_arrows(0, arg1 + 0x1A - offset0, arg2 + arg4 / 2 - 8);

            if (!(pause_map_cameraX > -86.0f)) {
                offset1 = 0;
            }
            pause_map_draw_border_arrows(1, arg1 + arg3 -0x32 + offset1, arg2 + arg4 / 2 - 8);

            if (!(pause_map_cameraY < 0.0f)) {
                offset2 = 0;
            }
            pause_map_draw_border_arrows(2, arg1 + arg3 / 2 - 8, arg2 + 0x18 - offset2);

            if (!(pause_map_cameraY > -210.0f)) {
                offset3 = 0;
            }
            pause_map_draw_border_arrows(3, arg1 + arg3 / 2 - 8, arg2 + arg4 - 0x2C + offset3);
        }
    }

    x1a = arg1 + 0x12;
    y1a = arg2 + 0xE;
    x2a = arg1 + 0x10C;
    y2a = arg2 + 0x8C;

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
    draw_box(0, &gPauseWS_27, arg1 + 0x12, arg2 + 0xE, 0, 0xFA, 0x7E, arg5, arg6, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, arg3, arg4, 0);
}

void pause_map_draw_title(s32* arg1, s32 arg2, s32 textOffsetY, s32 textOffsetX) {
    s32 msgWidth;
    s32 msgID;

    if (gPauseMenuCurrentTab == 6) {
        if (pause_map_cursorCurrentOption != -1) {
            msgWidth = get_msg_width(MSG_pause_map_location_0_name + (pause_map_cursorCurrentOption * 3), 0);
            msgID = MSG_pause_map_location_0_name + (pause_map_cursorCurrentOption * 3);
            draw_msg(msgID, arg2 + ((textOffsetX - msgWidth) >> 1), textOffsetY + 1, 255, 0, 0);
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
