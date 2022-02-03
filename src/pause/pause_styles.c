#include "common.h"

extern s8 D_8010B460[];
extern s8 D_8010B360[];
extern s8 pause_image_1439F0_png[];
extern s8 pause_image_143BF0_png[];
extern s8 pause_image_143FF0_png[];

//TODO replace with array when pause_stats_draw_contents is matched
WindowStyleCustom gPauseWS_0 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0x41,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .size1 = { .x = 0, .y = 0},
        .size2 = { .x = 0, .y = 0},
        .size3 = { .x = 0, .y = 0},
        .size4 = { .x = 0, .y = 0},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, PRIMITIVE, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 0x40, 0x5C, 0xF6, 0xFF},
    .color2 = { 0x00, 0x00, 0x00, 0x00},
};
WindowStyleCustom gPauseWS_1 = {
    .background = {
        .imgData = D_8010B460,
        .packedTileFormat = 0x40,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0},
        .size = 128
    },
    .corners = {
        .imgData = D_8010B360,
        .packedTileFormat = 0x31,
        .size1 = { .x = 8, .y = 8},
        .size2 = { .x = 8, .y = 8},
        .size3 = { .x = 8, .y = 8},
        .size4 = { .x = 8, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL1, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
    .transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
    .color1 = { 0xE2, 0xE1, 0xD8, 0xFF },
    .color2 = { 0xD9, 0xD0, 0xC9, 0x00 },
};
WindowStyleCustom gPauseWS_2 = {
	.background = {
		.imgData = NULL,
		.packedTileFormat = 0x40,
		.width = 16,
		.height = 16,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 128
	},
	.corners = {
		.imgData = NULL,
		.packedTileFormat = 0x31,
		.size1 = { .x = 8, .y = 8 },
		.size2 = { .x = 8, .y = 8 },
		.size3 = { .x = 8, .y = 8 },
		.size4 = { .x = 8, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL1, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.color1 = { 0xE2, 0xE1, 0xD8, 0xFF },
	.color2 = { 0xD9, 0xD0, 0xC9, 0x00 },
};
WindowStyleCustom gPauseWS_3 = {
	.background = {
		.imgData = NULL,
		.packedTileFormat = 0x00,
		.width = 0,
		.height = 0,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 0
	},
	.corners = {
		.imgData = pause_image_1439F0_png,
		.packedTileFormat = 0x31,
		.size1 = { .x = 16, .y = 8 },
		.size2 = { .x = 16, .y = 8 },
		.size3 = { .x = 16, .y = 8 },
		.size4 = { .x = 16, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.color1 = { 0xF0, 0xC7, 0x4E, 0xFF },
	.color2 = { 0x7F, 0x56, 0x17, 0x00 },
};
WindowStyleCustom gPauseWS_4 = {
	.background = {
		.imgData = NULL,
		.packedTileFormat = 0x00,
		.width = 0,
		.height = 0,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 0
	},
	.corners = {
		.imgData = pause_image_1439F0_png,
		.packedTileFormat = 0x31,
		.size1 = { .x = 16, .y = 8 },
		.size2 = { .x = 16, .y = 8 },
		.size3 = { .x = 16, .y = 8 },
		.size4 = { .x = 16, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.color1 = { 0xFD, 0x74, 0x4A, 0xFF },
	.color2 = { 0x74, 0x30, 0x1B, 0x00 },
};
WindowStyleCustom gPauseWS_5 = {
	.background = {
		.imgData = NULL,
		.packedTileFormat = 0x00,
		.width = 0,
		.height = 0,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 0
	},
	.corners = {
		.imgData = pause_image_1439F0_png,
		.packedTileFormat = 0x31,
		.size1 = { .x = 16, .y = 8 },
		.size2 = { .x = 16, .y = 8 },
		.size3 = { .x = 16, .y = 8 },
		.size4 = { .x = 16, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.color1 = { 0x27, 0x48, 0xE1, 0xFF },
	.color2 = { 0x09, 0x1A, 0x66, 0x00 },
};
WindowStyleCustom gPauseWS_6 = {
	.background = {
		.imgData = NULL,
		.packedTileFormat = 0x00,
		.width = 0,
		.height = 0,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 0
	},
	.corners = {
		.imgData = pause_image_1439F0_png,
		.packedTileFormat = 0x31,
		.size1 = { .x = 16, .y = 8 },
		.size2 = { .x = 16, .y = 8 },
		.size3 = { .x = 16, .y = 8 },
		.size4 = { .x = 16, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.color1 = { 0x22, 0xEE, 0xC9, 0xFF },
	.color2 = { 0x07, 0x6D, 0x5A, 0x00 },
};
WindowStyleCustom gPauseWS_7 = {
	.background = {
		.imgData = NULL,
		.packedTileFormat = 0x00,
		.width = 0,
		.height = 0,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 0
	},
	.corners = {
		.imgData = pause_image_1439F0_png,
		.packedTileFormat = 0x31,
		.size1 = { .x = 16, .y = 8 },
		.size2 = { .x = 16, .y = 8 },
		.size3 = { .x = 16, .y = 8 },
		.size4 = { .x = 16, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.color1 = { 0x68, 0xFF, 0x51, 0xFF },
	.color2 = { 0x2A, 0x79, 0x1E, 0x00 },
};
WindowStyleCustom gPauseWS_8 = {
	.background = {
		.imgData = NULL,
		.packedTileFormat = 0x00,
		.width = 0,
		.height = 0,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 0
	},
	.corners = {
		.imgData = pause_image_1439F0_png,
		.packedTileFormat = 0x31,
		.size1 = { .x = 16, .y = 8 },
		.size2 = { .x = 16, .y = 8 },
		.size3 = { .x = 16, .y = 8 },
		.size4 = { .x = 16, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.color1 = { 0xAD, 0x72, 0xC2, 0xFF },
	.color2 = { 0x4C, 0x2F, 0x57, 0x00 },
};
WindowStyleCustom gPauseWS_9 = {
	.background = {
		.imgData = NULL,
		.packedTileFormat = 0x00,
		.width = 0,
		.height = 0,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 0
	},
	.corners = {
		.imgData = NULL,
		.packedTileFormat = 0x00,
		.size1 = { .x = 0, .y = 0 },
		.size2 = { .x = 0, .y = 0 },
		.size3 = { .x = 0, .y = 0 },
		.size4 = { .x = 0, .y = 0 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPNoOp(),
	.transparentCombineMode = gsDPNoOp(),
	.color1 = { 0x00, 0x00, 0x00, 0x00 },
	.color2 = { 0x00, 0x00, 0x00, 0x00 },
};
WindowStyleCustom gPauseWS_10 = {
	.background = {
		.imgData = NULL,
		.packedTileFormat = 0x00,
		.width = 0,
		.height = 0,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 0
	},
	.corners = {
		.imgData = pause_image_1439F0_png,
		.packedTileFormat = 0x31,
		.size1 = { .x = 16, .y = 8 },
		.size2 = { .x = 16, .y = 8 },
		.size3 = { .x = 16, .y = 8 },
		.size4 = { .x = 16, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.color1 = { 0xF0, 0xC7, 0x4E, 0xFF },
	.color2 = { 0x7F, 0x56, 0x17, 0x00 },
};
WindowStyleCustom gPauseWS_11 = {
	.background = {
		.imgData = NULL,
		.packedTileFormat = 0x00,
		.width = 0,
		.height = 0,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 0
	},
	.corners = {
		.imgData = pause_image_1439F0_png,
		.packedTileFormat = 0x31,
		.size1 = { .x = 16, .y = 8 },
		.size2 = { .x = 16, .y = 8 },
		.size3 = { .x = 16, .y = 8 },
		.size4 = { .x = 16, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.color1 = { 0xD5, 0xA5, 0x74, 0xFF },
	.color2 = { 0x60, 0x48, 0x30, 0x60 },
};
WindowStyleCustom gPauseWS_12 = {
	.background = {
		.imgData = D_8010B460,
		.packedTileFormat = 0x40,
		.width = 16,
		.height = 16,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 128
	},
	.corners = {
		.imgData = D_8010B360,
		.packedTileFormat = 0x31,
		.size1 = { .x = 8, .y = 8 },
		.size2 = { .x = 8, .y = 8 },
		.size3 = { .x = 8, .y = 8 },
		.size4 = { .x = 8, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL1, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.color1 = { 0xE2, 0xD8, 0xB3, 0xFF },
	.color2 = { 0xD2, 0xC0, 0x90, 0x00 },
};
WindowStyleCustom gPauseWS_13 = {
	.background = {
		.imgData = NULL,
		.packedTileFormat = 0x00,
		.width = 0,
		.height = 0,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 0
	},
	.corners = {
		.imgData = pause_image_143BF0_png,
		.packedTileFormat = 0x31,
		.size1 = { .x = 16, .y = 16 },
		.size2 = { .x = 16, .y = 16 },
		.size3 = { .x = 16, .y = 16 },
		.size4 = { .x = 16, .y = 16 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.color1 = { 0xFD, 0x74, 0x4A, 0xFF },
	.color2 = { 0x74, 0x30, 0x1B, 0x00 },
};
WindowStyleCustom gPauseWS_14 = {
	.background = {
		.imgData = NULL,
		.packedTileFormat = 0x00,
		.width = 0,
		.height = 0,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 0
	},
	.corners = {
		.imgData = pause_image_1439F0_png,
		.packedTileFormat = 0x31,
		.size1 = { .x = 16, .y = 8 },
		.size2 = { .x = 16, .y = 8 },
		.size3 = { .x = 16, .y = 8 },
		.size4 = { .x = 16, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.color1 = { 0xF5, 0xB9, 0xA0, 0xFF },
	.color2 = { 0xCB, 0x99, 0x80, 0xFF },
};
WindowStyleCustom gPauseWS_15 = {
	.background = {
		.imgData = D_8010B460,
		.packedTileFormat = 0x40,
		.width = 16,
		.height = 16,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 128
	},
	.corners = {
		.imgData = D_8010B360,
		.packedTileFormat = 0x31,
		.size1 = { .x = 8, .y = 8 },
		.size2 = { .x = 8, .y = 8 },
		.size3 = { .x = 8, .y = 8 },
		.size4 = { .x = 8, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL1, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.color1 = { 0xD8, 0xBF, 0xB6, 0xFF },
	.color2 = { 0xE1, 0xD1, 0xD1, 0x00 },
};
WindowStyleCustom gPauseWS_16 = {
	.background = {
		.imgData = D_8010B460,
		.packedTileFormat = 0x40,
		.width = 16,
		.height = 16,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 128
	},
	.corners = {
		.imgData = D_8010B360,
		.packedTileFormat = 0x31,
		.size1 = { .x = 8, .y = 8 },
		.size2 = { .x = 8, .y = 8 },
		.size3 = { .x = 8, .y = 8 },
		.size4 = { .x = 8, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL1, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.color1 = { 0xCA, 0xAA, 0xA5, 0xFF },
	.color2 = { 0xE2, 0xC8, 0xC8, 0x00 },
};
WindowStyleCustom gPauseWS_17 = {
	.background = {
		.imgData = NULL,
		.packedTileFormat = 0x00,
		.width = 0,
		.height = 0,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 0
	},
	.corners = {
		.imgData = pause_image_143BF0_png,
		.packedTileFormat = 0x31,
		.size1 = { .x = 16, .y = 16 },
		.size2 = { .x = 16, .y = 16 },
		.size3 = { .x = 16, .y = 16 },
		.size4 = { .x = 16, .y = 16 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.color1 = { 0x27, 0x48, 0xE1, 0xFF },
	.color2 = { 0x09, 0x1A, 0x66, 0x00 },
};
WindowStyleCustom gPauseWS_18 = {
	.background = {
		.imgData = D_8010B460,
		.packedTileFormat = 0x40,
		.width = 16,
		.height = 16,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 128
	},
	.corners = {
		.imgData = D_8010B360,
		.packedTileFormat = 0x31,
		.size1 = { .x = 8, .y = 8 },
		.size2 = { .x = 8, .y = 8 },
		.size3 = { .x = 8, .y = 8 },
		.size4 = { .x = 8, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL1, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.color1 = { 0xC6, 0xCF, 0xDE, 0xFF },
	.color2 = { 0xD6, 0xDF, 0xEC, 0x00 },
};
WindowStyleCustom gPauseWS_19 = {
	.background = {
		.imgData = D_8010B460,
		.packedTileFormat = 0x40,
		.width = 16,
		.height = 16,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 128
	},
	.corners = {
		.imgData = D_8010B360,
		.packedTileFormat = 0x31,
		.size1 = { .x = 8, .y = 8 },
		.size2 = { .x = 8, .y = 8 },
		.size3 = { .x = 8, .y = 8 },
		.size4 = { .x = 8, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL1, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.color1 = { 0xCF, 0xD2, 0xF2, 0xFF },
	.color2 = { 0xB8, 0xBE, 0xD9, 0x00 },
};
WindowStyleCustom gPauseWS_20 = {
	.background = {
		.imgData = D_8010B460,
		.packedTileFormat = 0x40,
		.width = 16,
		.height = 16,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 128
	},
	.corners = {
		.imgData = D_8010B360,
		.packedTileFormat = 0x31,
		.size1 = { .x = 8, .y = 8 },
		.size2 = { .x = 8, .y = 8 },
		.size3 = { .x = 8, .y = 8 },
		.size4 = { .x = 8, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL1, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.color1 = { 0xCA, 0xD9, 0xD6, 0xFF },
	.color2 = { 0xB0, 0xCE, 0xCE, 0x00 },
};
WindowStyleCustom gPauseWS_21 = {
	.background = {
		.imgData = D_8010B460,
		.packedTileFormat = 0x40,
		.width = 16,
		.height = 16,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 128
	},
	.corners = {
		.imgData = pause_image_143FF0_png,
		.packedTileFormat = 0x31,
		.size1 = { .x = 16, .y = 16 },
		.size2 = { .x = 16, .y = 16 },
		.size3 = { .x = 16, .y = 16 },
		.size4 = { .x = 16, .y = 16 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL1, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.color1 = { 0xDE, 0xED, 0xEA, 0xFF },
	.color2 = { 0xC4, 0xE2, 0xE2, 0x00 },
};
WindowStyleCustom gPauseWS_22 = {
	.background = {
		.imgData = NULL,
		.packedTileFormat = 0x00,
		.width = 0,
		.height = 0,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 0
	},
	.corners = {
		.imgData = pause_image_1439F0_png,
		.packedTileFormat = 0x31,
		.size1 = { .x = 16, .y = 8 },
		.size2 = { .x = 16, .y = 8 },
		.size3 = { .x = 16, .y = 8 },
		.size4 = { .x = 16, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.color1 = { 0x0E, 0xDA, 0xB5, 0xFF },
	.color2 = { 0x7F, 0x7F, 0x7F, 0x00 },
};
WindowStyleCustom gPauseWS_23 = {
	.background = {
		.imgData = D_8010B460,
		.packedTileFormat = 0x40,
		.width = 16,
		.height = 16,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 128
	},
	.corners = {
		.imgData = D_8010B360,
		.packedTileFormat = 0x31,
		.size1 = { .x = 8, .y = 8 },
		.size2 = { .x = 8, .y = 8 },
		.size3 = { .x = 8, .y = 8 },
		.size4 = { .x = 8, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL1, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.color1 = { 0xC1, 0xE1, 0xC1, 0xFF },
	.color2 = { 0xA9, 0xD7, 0xA9, 0x00 },
};
WindowStyleCustom gPauseWS_24 = {
	.background = {
		.imgData = 0x00000000,
		.packedTileFormat = 0x00,
		.width = 0,
		.height = 0,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 0
	},
	.corners = {
		.imgData = pause_image_1439F0_png,
		.packedTileFormat = 0x31,
		.size1 = { .x = 16, .y = 8 },
		.size2 = { .x = 16, .y = 8 },
		.size3 = { .x = 16, .y = 8 },
		.size4 = { .x = 16, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.color1 = { 0x68, 0xFF, 0x51, 0xFF },
	.color2 = { 0x2A, 0x79, 0x1E, 0x00 },
};
WindowStyleCustom gPauseWS_25 = {
	.background = {
		.imgData = D_8010B460,
		.packedTileFormat = 0x40,
		.width = 16,
		.height = 16,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 128
	},
	.corners = {
		.imgData = pause_image_143FF0_png,
		.packedTileFormat = 0x31,
		.size1 = { .x = 16, .y = 16 },
		.size2 = { .x = 16, .y = 16 },
		.size3 = { .x = 16, .y = 16 },
		.size4 = { .x = 16, .y = 16 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL1, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.color1 = { 0xCF, 0xFA, 0xC8, 0xFF },
	.color2 = { 0xCE, 0xEF, 0xC0, 0x00 },
};
WindowStyleCustom gPauseWS_26 = {
	.background = {
		.imgData = D_8010B460,
		.packedTileFormat = 0x40,
		.width = 16,
		.height = 16,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 128
	},
	.corners = {
		.imgData = D_8010B360,
		.packedTileFormat = 0x31,
		.size1 = { .x = 8, .y = 8 },
		.size2 = { .x = 8, .y = 8 },
		.size3 = { .x = 8, .y = 8 },
		.size4 = { .x = 8, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL1, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.color1 = { 0xD8, 0xCA, 0xDB, 0xFF },
	.color2 = { 0xCD, 0xB4, 0xD1, 0x00 },
};
WindowStyleCustom gPauseWS_27 = {
	.background = {
		.imgData = D_8010B460,
		.packedTileFormat = 0x40,
		.width = 16,
		.height = 16,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 128
	},
	.corners = {
		.imgData = pause_image_143FF0_png,
		.packedTileFormat = 0x31,
		.size1 = { .x = 16, .y = 16 },
		.size2 = { .x = 16, .y = 16 },
		.size3 = { .x = 16, .y = 16 },
		.size4 = { .x = 16, .y = 16 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL1, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, COMBINED, 0, TEXEL0, 0, 0, 0, 0, COMBINED),
	.color1 = { 0xEC, 0xDE, 0xEF, 0xFF },
	.color2 = { 0xE1, 0xC8, 0xE5, 0x00 },
};
WindowStyleCustom gPauseWS_28 = {
	.background = {
		.imgData = NULL,
		.packedTileFormat = 0x00,
		.width = 0,
		.height = 0,
		.unk_07 = { 0, 0, 0, 0 },
		.size = 0
	},
	.corners = {
		.imgData = pause_image_1439F0_png,
		.packedTileFormat = 0x31,
		.size1 = { .x = 16, .y = 8 },
		.size2 = { .x = 16, .y = 8 },
		.size3 = { .x = 16, .y = 8 },
		.size4 = { .x = 16, .y = 8 },
		.unk_0D = { 0, 0, 0 },
	},
	.unk_1C = { 0, 0, 0, 0 },
	.opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.transparentCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	.color1 = { 0xAD, 0x72, 0xC2, 0xFF },
	.color2 = { 0x4C, 0x2F, 0x57, 0x00 },
};
