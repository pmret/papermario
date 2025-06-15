#include "common.h"

extern s8 ui_box_bg_tile_png[];
extern s8 ui_box_corners4_png[];
extern s8 pause_image_1439F0_png[];
extern s8 pause_image_143BF0_png[];
extern s8 pause_image_143FF0_png[];

//TODO replace with array when pause_stats_draw_contents is matched
WindowStyleCustom gPauseWS_0 = {
    .background = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_I,
        .bitDepth = G_IM_SIZ_8b,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_RGBA,
        .bitDepth = G_IM_SIZ_4b,
        .size1 = { .x = 0, .y = 0},
        .size2 = { .x = 0, .y = 0},
        .size3 = { .x = 0, .y = 0},
        .size4 = { .x = 0, .y = 0},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_CONST_0, PM_CC_CONST_0),
    .transparentCombineMode =  gsDPSetCombineMode(PM_CC_WINDOW_4, G_CC_PASS2),
    .color1 = { 64, 92, 246, 255 },
    .color2 = { 0, 0, 0, 0 },
};
WindowStyleCustom gPauseWS_1 = {
    .background = {
        .imgData = ui_box_bg_tile_png,
        .fmt = G_IM_FMT_I,
        .bitDepth = G_IM_SIZ_4b,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0},
        .size = 128
    },
    .corners = {
        .imgData = ui_box_corners4_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 8, .y = 8},
        .size2 = { .x = 8, .y = 8},
        .size3 = { .x = 8, .y = 8},
        .size4 = { .x = 8, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_2, PM_CC_WINDOW_1),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_3, PM_CC_WINDOW_1),
    .color1 = { 226, 225, 216, 255 },
    .color2 = { 217, 208, 201, 0 },
};
WindowStyleCustom gPauseWS_2 = {
    .background = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_I,
        .bitDepth = G_IM_SIZ_4b,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 128
    },
    .corners = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 8, .y = 8 },
        .size2 = { .x = 8, .y = 8 },
        .size3 = { .x = 8, .y = 8 },
        .size4 = { .x = 8, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_2, PM_CC_WINDOW_1),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_3, PM_CC_WINDOW_1),
    .color1 = { 226, 225, 216, 255 },
    .color2 = { 217, 208, 201, 0 },
};
WindowStyleCustom gPauseWS_3 = {
    .background = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_RGBA,
        .bitDepth = G_IM_SIZ_4b,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 0
    },
    .corners = {
        .imgData = pause_image_1439F0_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 16, .y = 8 },
        .size2 = { .x = 16, .y = 8 },
        .size3 = { .x = 16, .y = 8 },
        .size4 = { .x = 16, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
    .color1 = { 240, 199, 78, 255 },
    .color2 = { 127, 86, 23, 0 },
};
WindowStyleCustom gPauseWS_4 = {
    .background = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_RGBA,
        .bitDepth = G_IM_SIZ_4b,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 0
    },
    .corners = {
        .imgData = pause_image_1439F0_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 16, .y = 8 },
        .size2 = { .x = 16, .y = 8 },
        .size3 = { .x = 16, .y = 8 },
        .size4 = { .x = 16, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
    .color1 = { 0xFD, 0x74, 0x4A, 0xFF },
    .color2 = { 0x74, 0x30, 0x1B, 0x00 },
};
WindowStyleCustom gPauseWS_5 = {
    .background = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_RGBA,
        .bitDepth = G_IM_SIZ_4b,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 0
    },
    .corners = {
        .imgData = pause_image_1439F0_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 16, .y = 8 },
        .size2 = { .x = 16, .y = 8 },
        .size3 = { .x = 16, .y = 8 },
        .size4 = { .x = 16, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
    .color1 = { 39, 72, 225, 255 },
    .color2 = { 9, 26, 102, 0 },
};
WindowStyleCustom gPauseWS_6 = {
    .background = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_RGBA,
        .bitDepth = G_IM_SIZ_4b,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 0
    },
    .corners = {
        .imgData = pause_image_1439F0_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 16, .y = 8 },
        .size2 = { .x = 16, .y = 8 },
        .size3 = { .x = 16, .y = 8 },
        .size4 = { .x = 16, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
    .color1 = { 34, 238, 201, 255 },
    .color2 = { 7, 109, 90, 0 },
};
WindowStyleCustom gPauseWS_7 = {
    .background = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_RGBA,
        .bitDepth = G_IM_SIZ_4b,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 0
    },
    .corners = {
        .imgData = pause_image_1439F0_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 16, .y = 8 },
        .size2 = { .x = 16, .y = 8 },
        .size3 = { .x = 16, .y = 8 },
        .size4 = { .x = 16, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
    .color1 = { 104, 255, 81, 255 },
    .color2 = { 42, 121, 30, 0 },
};
WindowStyleCustom gPauseWS_8 = {
    .background = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_RGBA,
        .bitDepth = G_IM_SIZ_4b,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 0
    },
    .corners = {
        .imgData = pause_image_1439F0_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 16, .y = 8 },
        .size2 = { .x = 16, .y = 8 },
        .size3 = { .x = 16, .y = 8 },
        .size4 = { .x = 16, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
    .color1 = { 173, 114, 194, 255 },
    .color2 = { 76, 47, 87, 0 },
};
WindowStyleCustom gPauseWS_9 = {
    .background = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_RGBA,
        .bitDepth = G_IM_SIZ_4b,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 0
    },
    .corners = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_RGBA,
        .bitDepth = G_IM_SIZ_4b,
        .size1 = { .x = 0, .y = 0 },
        .size2 = { .x = 0, .y = 0 },
        .size3 = { .x = 0, .y = 0 },
        .size4 = { .x = 0, .y = 0 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPNoOp(),
    .transparentCombineMode = gsDPNoOp(),
    .color1 = { 0, 0, 0, 0 },
    .color2 = { 0, 0, 0, 0 },
};
WindowStyleCustom gPauseWS_10 = {
    .background = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_RGBA,
        .bitDepth = G_IM_SIZ_4b,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 0
    },
    .corners = {
        .imgData = pause_image_1439F0_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 16, .y = 8 },
        .size2 = { .x = 16, .y = 8 },
        .size3 = { .x = 16, .y = 8 },
        .size4 = { .x = 16, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
    .color1 = { 240, 199, 78, 255 },
    .color2 = { 127, 86, 23, 0 },
};
WindowStyleCustom gPauseWS_11 = {
    .background = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_RGBA,
        .bitDepth = G_IM_SIZ_4b,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 0
    },
    .corners = {
        .imgData = pause_image_1439F0_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 16, .y = 8 },
        .size2 = { .x = 16, .y = 8 },
        .size3 = { .x = 16, .y = 8 },
        .size4 = { .x = 16, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
    .color1 = { 213, 165, 116, 255 },
    .color2 = { 96, 72, 48, 96 },
};
WindowStyleCustom gPauseWS_12 = {
    .background = {
        .imgData = ui_box_bg_tile_png,
        .fmt = G_IM_FMT_I,
        .bitDepth = G_IM_SIZ_4b,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 128
    },
    .corners = {
        .imgData = ui_box_corners4_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 8, .y = 8 },
        .size2 = { .x = 8, .y = 8 },
        .size3 = { .x = 8, .y = 8 },
        .size4 = { .x = 8, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_2, PM_CC_WINDOW_1),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_3, PM_CC_WINDOW_1),
    .color1 = { 226, 216, 179, 255 },
    .color2 = { 210, 192, 144, 0 },
};
WindowStyleCustom gPauseWS_13 = {
    .background = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_RGBA,
        .bitDepth = G_IM_SIZ_4b,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 0
    },
    .corners = {
        .imgData = pause_image_143BF0_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 16, .y = 16 },
        .size2 = { .x = 16, .y = 16 },
        .size3 = { .x = 16, .y = 16 },
        .size4 = { .x = 16, .y = 16 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
    .color1 = { 253, 116, 74, 255 },
    .color2 = { 116, 48, 27, 0 },
};
WindowStyleCustom gPauseWS_14 = {
    .background = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_RGBA,
        .bitDepth = G_IM_SIZ_4b,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 0
    },
    .corners = {
        .imgData = pause_image_1439F0_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 16, .y = 8 },
        .size2 = { .x = 16, .y = 8 },
        .size3 = { .x = 16, .y = 8 },
        .size4 = { .x = 16, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
    .color1 = { 245, 185, 160, 255 },
    .color2 = { 203, 153, 128, 255 },
};
WindowStyleCustom gPauseWS_15 = {
    .background = {
        .imgData = ui_box_bg_tile_png,
        .fmt = G_IM_FMT_I,
        .bitDepth = G_IM_SIZ_4b,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 128
    },
    .corners = {
        .imgData = ui_box_corners4_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 8, .y = 8 },
        .size2 = { .x = 8, .y = 8 },
        .size3 = { .x = 8, .y = 8 },
        .size4 = { .x = 8, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_2, PM_CC_WINDOW_1),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_3, PM_CC_WINDOW_1),
    .color1 = { 216, 191, 182, 255 },
    .color2 = { 225, 209, 209, 0 },
};
WindowStyleCustom gPauseWS_16 = {
    .background = {
        .imgData = ui_box_bg_tile_png,
        .fmt = G_IM_FMT_I,
        .bitDepth = G_IM_SIZ_4b,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 128
    },
    .corners = {
        .imgData = ui_box_corners4_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 8, .y = 8 },
        .size2 = { .x = 8, .y = 8 },
        .size3 = { .x = 8, .y = 8 },
        .size4 = { .x = 8, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_2, PM_CC_WINDOW_1),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_3, PM_CC_WINDOW_1),
    .color1 = { 202, 170, 165, 255 },
    .color2 = { 226, 200, 200, 0 },
};
WindowStyleCustom gPauseWS_17 = {
    .background = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_RGBA,
        .bitDepth = G_IM_SIZ_4b,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 0
    },
    .corners = {
        .imgData = pause_image_143BF0_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 16, .y = 16 },
        .size2 = { .x = 16, .y = 16 },
        .size3 = { .x = 16, .y = 16 },
        .size4 = { .x = 16, .y = 16 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
    .color1 = { 39, 72, 225, 255 },
    .color2 = { 9, 26, 102, 0 },
};
WindowStyleCustom gPauseWS_18 = {
    .background = {
        .imgData = ui_box_bg_tile_png,
        .fmt = G_IM_FMT_I,
        .bitDepth = G_IM_SIZ_4b,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 128
    },
    .corners = {
        .imgData = ui_box_corners4_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 8, .y = 8 },
        .size2 = { .x = 8, .y = 8 },
        .size3 = { .x = 8, .y = 8 },
        .size4 = { .x = 8, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_2, PM_CC_WINDOW_1),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_3, PM_CC_WINDOW_1),
    .color1 = { 198, 207, 222, 255 },
    .color2 = { 214, 223, 236, 0 },
};
WindowStyleCustom gPauseWS_19 = {
    .background = {
        .imgData = ui_box_bg_tile_png,
        .fmt = G_IM_FMT_I,
        .bitDepth = G_IM_SIZ_4b,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 128
    },
    .corners = {
        .imgData = ui_box_corners4_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 8, .y = 8 },
        .size2 = { .x = 8, .y = 8 },
        .size3 = { .x = 8, .y = 8 },
        .size4 = { .x = 8, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_2, PM_CC_WINDOW_1),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_3, PM_CC_WINDOW_1),
    .color1 = { 207, 210, 242, 255 },
    .color2 = { 184, 190, 217, 0 },
};
WindowStyleCustom gPauseWS_20 = {
    .background = {
        .imgData = ui_box_bg_tile_png,
        .fmt = G_IM_FMT_I,
        .bitDepth = G_IM_SIZ_4b,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 128
    },
    .corners = {
        .imgData = ui_box_corners4_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 8, .y = 8 },
        .size2 = { .x = 8, .y = 8 },
        .size3 = { .x = 8, .y = 8 },
        .size4 = { .x = 8, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_2, PM_CC_WINDOW_1),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_3, PM_CC_WINDOW_1),
    .color1 = { 202, 217, 214, 255 },
    .color2 = { 176, 206, 206, 0 },
};
WindowStyleCustom gPauseWS_21 = {
    .background = {
        .imgData = ui_box_bg_tile_png,
        .fmt = G_IM_FMT_I,
        .bitDepth = G_IM_SIZ_4b,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 128
    },
    .corners = {
        .imgData = pause_image_143FF0_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 16, .y = 16 },
        .size2 = { .x = 16, .y = 16 },
        .size3 = { .x = 16, .y = 16 },
        .size4 = { .x = 16, .y = 16 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_2, PM_CC_WINDOW_1),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_3, PM_CC_WINDOW_1),
    .color1 = { 222, 237, 234, 255 },
    .color2 = { 196, 226, 226, 0 },
};
WindowStyleCustom gPauseWS_22 = {
    .background = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_RGBA,
        .bitDepth = G_IM_SIZ_4b,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 0
    },
    .corners = {
        .imgData = pause_image_1439F0_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 16, .y = 8 },
        .size2 = { .x = 16, .y = 8 },
        .size3 = { .x = 16, .y = 8 },
        .size4 = { .x = 16, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
    .color1 = { 14, 218, 181, 255 },
    .color2 = { 127, 127, 127, 0 },
};
WindowStyleCustom gPauseWS_23 = {
    .background = {
        .imgData = ui_box_bg_tile_png,
        .fmt = G_IM_FMT_I,
        .bitDepth = G_IM_SIZ_4b,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 128
    },
    .corners = {
        .imgData = ui_box_corners4_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 8, .y = 8 },
        .size2 = { .x = 8, .y = 8 },
        .size3 = { .x = 8, .y = 8 },
        .size4 = { .x = 8, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_2, PM_CC_WINDOW_1),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_3, PM_CC_WINDOW_1),
    .color1 = { 193, 225, 193, 255 },
    .color2 = { 169, 215, 169, 0 },
};
WindowStyleCustom gPauseWS_24 = {
    .background = {
        .imgData = 0x00000000,
        .fmt = G_IM_FMT_RGBA,
        .bitDepth = G_IM_SIZ_4b,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 0
    },
    .corners = {
        .imgData = pause_image_1439F0_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 16, .y = 8 },
        .size2 = { .x = 16, .y = 8 },
        .size3 = { .x = 16, .y = 8 },
        .size4 = { .x = 16, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
    .color1 = { 104, 255, 81, 255 },
    .color2 = { 42, 121, 30, 0 },
};
WindowStyleCustom gPauseWS_25 = {
    .background = {
        .imgData = ui_box_bg_tile_png,
        .fmt = G_IM_FMT_I,
        .bitDepth = G_IM_SIZ_4b,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 128
    },
    .corners = {
        .imgData = pause_image_143FF0_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 16, .y = 16 },
        .size2 = { .x = 16, .y = 16 },
        .size3 = { .x = 16, .y = 16 },
        .size4 = { .x = 16, .y = 16 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_2, PM_CC_WINDOW_1),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_3, PM_CC_WINDOW_1),
    .color1 = { 207, 250, 200, 255 },
    .color2 = { 206, 239, 192, 0 },
};
WindowStyleCustom gPauseWS_26 = {
    .background = {
        .imgData = ui_box_bg_tile_png,
        .fmt = G_IM_FMT_I,
        .bitDepth = G_IM_SIZ_4b,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 128
    },
    .corners = {
        .imgData = ui_box_corners4_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 8, .y = 8 },
        .size2 = { .x = 8, .y = 8 },
        .size3 = { .x = 8, .y = 8 },
        .size4 = { .x = 8, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_2, PM_CC_WINDOW_1),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_3, PM_CC_WINDOW_1),
    .color1 = { 216, 202, 219, 255 },
    .color2 = { 205, 180, 209, 0 },
};
WindowStyleCustom gPauseWS_27 = {
    .background = {
        .imgData = ui_box_bg_tile_png,
        .fmt = G_IM_FMT_I,
        .bitDepth = G_IM_SIZ_4b,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 128
    },
    .corners = {
        .imgData = pause_image_143FF0_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 16, .y = 16 },
        .size2 = { .x = 16, .y = 16 },
        .size3 = { .x = 16, .y = 16 },
        .size4 = { .x = 16, .y = 16 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_2, PM_CC_WINDOW_1),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_WINDOW_3, PM_CC_WINDOW_1),
    .color1 = { 236, 222, 239, 255 },
    .color2 = { 225, 200, 229, 0 },
};
WindowStyleCustom gPauseWS_28 = {
    .background = {
        .imgData = nullptr,
        .fmt = G_IM_FMT_RGBA,
        .bitDepth = G_IM_SIZ_4b,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0 },
        .size = 0
    },
    .corners = {
        .imgData = pause_image_1439F0_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { .x = 16, .y = 8 },
        .size2 = { .x = 16, .y = 8 },
        .size3 = { .x = 16, .y = 8 },
        .size4 = { .x = 16, .y = 8 },
        .unk_0D = { 0, 0, 0 },
    },
    .unk_1C = { 0, 0, 0, 0 },
    .opaqueCombineMode = gsDPSetCombineMode(PM_CC_15, G_CC_PASS2),
    .transparentCombineMode = gsDPSetCombineMode(PM_CC_14, G_CC_PASS2),
    .color1 = { 173, 114, 194, 255 },
    .color2 = { 76, 47, 87, 0 },
};
