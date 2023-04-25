#include "common.h"

extern u8 D_8024A400[];
extern u8 D_8024B400[];

WindowStyleCustom filemenu_windowStyles[] = {
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .size1 = { .x = 0, .y = 0},
            .size2 = { .x = 0, .y = 0},
            .size3 = { .x = 0, .y = 0},
            .size4 = { .x = 0, .y = 0},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_7, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_4, G_CC_PASS2),
        .color1 = { 64, 92, 246, 255 },
        .color2 = { 0, 0, 0, 0 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_I,
            .bitDepth = G_IM_SIZ_4b,
            .width = 16,
            .height = 16,
            .unk_07 = { 0, 0, 0, 0},
            .size = 128
        },
        .corners = {
            .imgData = NULL,
            .fmt = G_IM_FMT_IA,
            .bitDepth = G_IM_SIZ_8b,
            .size1 = { .x = 8, .y = 8},
            .size2 = { .x = 8, .y = 8},
            .size3 = { .x = 8, .y = 8},
            .size4 = { .x = 8, .y = 8},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPNoOp(),
        .transparentCombineMode = gsDPNoOp(),
        .color1 = { 0, 255, 0, 0 },
        .color2 = { 0, 0, 0, 0 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .size1 = { .x = 0, .y = 0},
            .size2 = { .x = 0, .y = 0},
            .size3 = { .x = 0, .y = 0},
            .size4 = { .x = 0, .y = 0},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPNoOp(),
        .transparentCombineMode = gsDPNoOp(),
        .color1 = { 0, 0, 0, 0 },
        .color2 = { 0, 0, 0, 0 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024A400,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_32b,
            .size1 = { .x = 16, .y = 16},
            .size2 = { .x = 16, .y = 16},
            .size3 = { .x = 16, .y = 16},
            .size4 = { .x = 16, .y = 16},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_5, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_6, G_CC_PASS2),
        .color1 = { 0, 0, 0, 255 },
        .color2 = { 0, 0, 0, 0 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024B400,
            .fmt = G_IM_FMT_IA,
            .bitDepth = G_IM_SIZ_8b,
            .size1 = { .x = 16, .y = 8},
            .size2 = { .x = 16, .y = 8},
            .size3 = { .x = 16, .y = 8},
            .size4 = { .x = 16, .y = 8},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
        .color1 = { 215, 140, 150, 255 },
        .color2 = { 125, 45, 35, 255 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024B400,
            .fmt = G_IM_FMT_IA,
            .bitDepth = G_IM_SIZ_8b,
            .size1 = { .x = 16, .y = 8},
            .size2 = { .x = 16, .y = 8},
            .size3 = { .x = 16, .y = 8},
            .size4 = { .x = 16, .y = 8},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
        .color1 = { 215, 140, 150, 255 },
        .color2 = { 125, 45, 35, 255 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024B400,
            .fmt = G_IM_FMT_IA,
            .bitDepth = G_IM_SIZ_8b,
            .size1 = { .x = 16, .y = 8},
            .size2 = { .x = 16, .y = 8},
            .size3 = { .x = 16, .y = 8},
            .size4 = { .x = 16, .y = 8},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
        .color1 = { 215, 140, 150, 255 },
        .color2 = { 125, 45, 35, 255 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024B400,
            .fmt = G_IM_FMT_IA,
            .bitDepth = G_IM_SIZ_8b,
            .size1 = { .x = 16, .y = 8},
            .size2 = { .x = 16, .y = 8},
            .size3 = { .x = 16, .y = 8},
            .size4 = { .x = 16, .y = 8},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
        .color1 = { 200, 200, 200, 255 },
        .color2 = { 130, 130, 101, 255 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024B400,
            .fmt = G_IM_FMT_IA,
            .bitDepth = G_IM_SIZ_8b,
            .size1 = { .x = 16, .y = 8},
            .size2 = { .x = 16, .y = 8},
            .size3 = { .x = 16, .y = 8},
            .size4 = { .x = 16, .y = 8},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
        .color1 = { 200, 200, 200, 255 },
        .color2 = { 130, 130, 101, 255 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024B400,
            .fmt = G_IM_FMT_IA,
            .bitDepth = G_IM_SIZ_8b,
            .size1 = { .x = 16, .y = 8},
            .size2 = { .x = 16, .y = 8},
            .size3 = { .x = 16, .y = 8},
            .size4 = { .x = 16, .y = 8},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
        .color1 = { 200, 200, 200, 255 },
        .color2 = { 130, 130, 101, 255 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024B400,
            .fmt = G_IM_FMT_IA,
            .bitDepth = G_IM_SIZ_8b,
            .size1 = { .x = 16, .y = 8},
            .size2 = { .x = 16, .y = 8},
            .size3 = { .x = 16, .y = 8},
            .size4 = { .x = 16, .y = 8},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
        .color1 = { 200, 200, 200, 255 },
        .color2 = { 130, 130, 101, 255 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024B400,
            .fmt = G_IM_FMT_IA,
            .bitDepth = G_IM_SIZ_8b,
            .size1 = { .x = 16, .y = 8},
            .size2 = { .x = 16, .y = 8},
            .size3 = { .x = 16, .y = 8},
            .size4 = { .x = 16, .y = 8},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
        .color1 = { 88, 92, 68, 255 },
        .color2 = { 152, 143, 130, 255 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024B400,
            .fmt = G_IM_FMT_IA,
            .bitDepth = G_IM_SIZ_8b,
            .size1 = { .x = 16, .y = 8},
            .size2 = { .x = 16, .y = 8},
            .size3 = { .x = 16, .y = 8},
            .size4 = { .x = 16, .y = 8},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
        .color1 = { 88, 92, 68, 255 },
        .color2 = { 152, 143, 130, 255 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024B400,
            .fmt = G_IM_FMT_IA,
            .bitDepth = G_IM_SIZ_8b,
            .size1 = { .x = 16, .y = 8},
            .size2 = { .x = 16, .y = 8},
            .size3 = { .x = 16, .y = 8},
            .size4 = { .x = 16, .y = 8},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
        .color1 = { 88, 92, 68, 255 },
        .color2 = { 152, 143, 130, 255 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024B400,
            .fmt = G_IM_FMT_IA,
            .bitDepth = G_IM_SIZ_8b,
            .size1 = { .x = 16, .y = 8},
            .size2 = { .x = 16, .y = 8},
            .size3 = { .x = 16, .y = 8},
            .size4 = { .x = 16, .y = 8},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
        .color1 = { 88, 92, 68, 255 },
        .color2 = { 152, 143, 130, 255 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024B400,
            .fmt = G_IM_FMT_IA,
            .bitDepth = G_IM_SIZ_8b,
            .size1 = { .x = 16, .y = 8},
            .size2 = { .x = 16, .y = 8},
            .size3 = { .x = 16, .y = 8},
            .size4 = { .x = 16, .y = 8},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
        .color1 = { 200, 200, 200, 255 },
        .color2 = { 130, 130, 101, 255 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024B400,
            .fmt = G_IM_FMT_IA,
            .bitDepth = G_IM_SIZ_8b,
            .size1 = { .x = 16, .y = 8},
            .size2 = { .x = 16, .y = 8},
            .size3 = { .x = 16, .y = 8},
            .size4 = { .x = 16, .y = 8},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
        .color1 = { 255, 255, 255, 255 },
        .color2 = { 200, 200, 170, 255 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024B400,
            .fmt = G_IM_FMT_IA,
            .bitDepth = G_IM_SIZ_8b,
            .size1 = { .x = 16, .y = 8},
            .size2 = { .x = 16, .y = 8},
            .size3 = { .x = 16, .y = 8},
            .size4 = { .x = 16, .y = 8},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
        .color1 = { 88, 92, 68, 255 },
        .color2 = { 152, 143, 130, 255 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024B400,
            .fmt = G_IM_FMT_IA,
            .bitDepth = G_IM_SIZ_8b,
            .size1 = { .x = 16, .y = 8},
            .size2 = { .x = 16, .y = 8},
            .size3 = { .x = 16, .y = 8},
            .size4 = { .x = 16, .y = 8},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
        .color1 = { 255, 238, 106, 255 },
        .color2 = { 146, 100, 26, 255 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024A400,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_32b,
            .size1 = { .x = 16, .y = 16},
            .size2 = { .x = 16, .y = 16},
            .size3 = { .x = 16, .y = 16},
            .size4 = { .x = 16, .y = 16},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_5, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_6, G_CC_PASS2),
        .color1 = { 0, 0, 0, 255 },
        .color2 = { 0, 0, 0, 0 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024A400,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_32b,
            .size1 = { .x = 16, .y = 16},
            .size2 = { .x = 16, .y = 16},
            .size3 = { .x = 16, .y = 16},
            .size4 = { .x = 16, .y = 16},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_5, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_6, G_CC_PASS2),
        .color1 = { 0, 0, 0, 255 },
        .color2 = { 0, 0, 0, 0 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024A400,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_32b,
            .size1 = { .x = 16, .y = 16},
            .size2 = { .x = 16, .y = 16},
            .size3 = { .x = 16, .y = 16},
            .size4 = { .x = 16, .y = 16},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_5, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_6, G_CC_PASS2),
        .color1 = { 0, 0, 0, 255 },
        .color2 = { 0, 0, 0, 0 },
    },
    {
        .background = {
            .imgData = NULL,
            .fmt = G_IM_FMT_RGBA,
            .bitDepth = G_IM_SIZ_4b,
            .width = 0,
            .height = 0,
            .unk_07 = { 0, 0, 0, 0},
            .size = 0
        },
        .corners = {
            .imgData = D_8024B400,
            .fmt = G_IM_FMT_IA,
            .bitDepth = G_IM_SIZ_8b,
            .size1 = { .x = 16, .y = 8},
            .size2 = { .x = 16, .y = 8},
            .size3 = { .x = 16, .y = 8},
            .size4 = { .x = 16, .y = 8},
            .unk_0D = { 0, 0, 0}
        },
        .unk_1C = { 0, 0, 0, 0},
        .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
        .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
        .color1 = { 255, 255, 255, 255 },
        .color2 = { 200, 200, 170, 255 },
    },
};
