#include "common.h"

extern u8 D_8024A400[];
extern u8 D_8024B400[];

WindowStyleCustom D_8024BA60 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
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
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, 1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, PRIMITIVE, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 64, 92, 246, 255 },
    .color2 = { 0, 0, 0, 0 },
};
WindowStyleCustom D_8024BA98 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0x40,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0},
        .size = 128
    },
    .corners = {
        .imgData = NULL,
        .packedTileFormat = 0x31,
        .size1 = { .x = 8, .y = 8},
        .size2 = { .x = 8, .y = 8},
        .size3 = { .x = 8, .y = 8},
        .size4 = { .x = 8, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPNoOp(),
    .transparentCombineMode =  gsDPNoOp(),
    .color1 = { 0, 255, 0, 0 },
    .color2 = { 0, 0, 0, 0 },
};
WindowStyleCustom D_8024BAD0 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
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
    .opaqueCombineMode = gsDPNoOp(),
    .transparentCombineMode =  gsDPNoOp(),
    .color1 = { 0, 0, 0, 0 },
    .color2 = { 0, 0, 0, 0 },
};
WindowStyleCustom D_8024BB08 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024A400,
        .packedTileFormat = 0x03,
        .size1 = { .x = 16, .y = 16},
        .size2 = { .x = 16, .y = 16},
        .size3 = { .x = 16, .y = 16},
        .size4 = { .x = 16, .y = 16},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(0, 0, 0, TEXEL1, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(0, 0, 0, TEXEL1, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 0, 0, 0, 255 },
    .color2 = { 0, 0, 0, 0 },
};
WindowStyleCustom D_8024BB40 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024B400,
        .packedTileFormat = 0x31,
        .size1 = { .x = 16, .y = 8},
        .size2 = { .x = 16, .y = 8},
        .size3 = { .x = 16, .y = 8},
        .size4 = { .x = 16, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 215, 140, 150, 255 },
    .color2 = { 125, 45, 35, 255 },
};
WindowStyleCustom D_8024BB78 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024B400,
        .packedTileFormat = 0x31,
        .size1 = { .x = 16, .y = 8},
        .size2 = { .x = 16, .y = 8},
        .size3 = { .x = 16, .y = 8},
        .size4 = { .x = 16, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 215, 140, 150, 255 },
    .color2 = { 125, 45, 35, 255 },
};
WindowStyleCustom D_8024BBB0 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024B400,
        .packedTileFormat = 0x31,
        .size1 = { .x = 16, .y = 8},
        .size2 = { .x = 16, .y = 8},
        .size3 = { .x = 16, .y = 8},
        .size4 = { .x = 16, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 215, 140, 150, 255 },
    .color2 = { 125, 45, 35, 255 },
};
WindowStyleCustom D_8024BBE8 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024B400,
        .packedTileFormat = 0x31,
        .size1 = { .x = 16, .y = 8},
        .size2 = { .x = 16, .y = 8},
        .size3 = { .x = 16, .y = 8},
        .size4 = { .x = 16, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 200, 200, 200, 255 },
    .color2 = { 130, 130, 101, 255 },
};
WindowStyleCustom D_8024BC20 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024B400,
        .packedTileFormat = 0x31,
        .size1 = { .x = 16, .y = 8},
        .size2 = { .x = 16, .y = 8},
        .size3 = { .x = 16, .y = 8},
        .size4 = { .x = 16, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 200, 200, 200, 255 },
    .color2 = { 130, 130, 101, 255 },
};
WindowStyleCustom D_8024BC58 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024B400,
        .packedTileFormat = 0x31,
        .size1 = { .x = 16, .y = 8},
        .size2 = { .x = 16, .y = 8},
        .size3 = { .x = 16, .y = 8},
        .size4 = { .x = 16, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 200, 200, 200, 255 },
    .color2 = { 130, 130, 101, 255 },
};
WindowStyleCustom D_8024BC90 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024B400,
        .packedTileFormat = 0x31,
        .size1 = { .x = 16, .y = 8},
        .size2 = { .x = 16, .y = 8},
        .size3 = { .x = 16, .y = 8},
        .size4 = { .x = 16, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 200, 200, 200, 255 },
    .color2 = { 130, 130, 101, 255 },
};
WindowStyleCustom D_8024BCC8 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024B400,
        .packedTileFormat = 0x31,
        .size1 = { .x = 16, .y = 8},
        .size2 = { .x = 16, .y = 8},
        .size3 = { .x = 16, .y = 8},
        .size4 = { .x = 16, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 88, 92, 68, 255 },
    .color2 = { 152, 143, 130, 255 },
};
WindowStyleCustom D_8024BD00 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024B400,
        .packedTileFormat = 0x31,
        .size1 = { .x = 16, .y = 8},
        .size2 = { .x = 16, .y = 8},
        .size3 = { .x = 16, .y = 8},
        .size4 = { .x = 16, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 88, 92, 68, 255 },
    .color2 = { 152, 143, 130, 255 },
};
WindowStyleCustom D_8024BD38 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024B400,
        .packedTileFormat = 0x31,
        .size1 = { .x = 16, .y = 8},
        .size2 = { .x = 16, .y = 8},
        .size3 = { .x = 16, .y = 8},
        .size4 = { .x = 16, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 88, 92, 68, 255 },
    .color2 = { 152, 143, 130, 255 },
};
WindowStyleCustom D_8024BD70 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024B400,
        .packedTileFormat = 0x31,
        .size1 = { .x = 16, .y = 8},
        .size2 = { .x = 16, .y = 8},
        .size3 = { .x = 16, .y = 8},
        .size4 = { .x = 16, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 88, 92, 68, 255 },
    .color2 = { 152, 143, 130, 255 },
};
WindowStyleCustom D_8024BDA8 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024B400,
        .packedTileFormat = 0x31,
        .size1 = { .x = 16, .y = 8},
        .size2 = { .x = 16, .y = 8},
        .size3 = { .x = 16, .y = 8},
        .size4 = { .x = 16, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 200, 200, 200, 255 },
    .color2 = { 130, 130, 101, 255 },
};
WindowStyleCustom D_8024BDE0 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024B400,
        .packedTileFormat = 0x31,
        .size1 = { .x = 16, .y = 8},
        .size2 = { .x = 16, .y = 8},
        .size3 = { .x = 16, .y = 8},
        .size4 = { .x = 16, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 255, 255, 255, 255 },
    .color2 = { 200, 200, 170, 255 },
};
WindowStyleCustom D_8024BE18 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024B400,
        .packedTileFormat = 0x31,
        .size1 = { .x = 16, .y = 8},
        .size2 = { .x = 16, .y = 8},
        .size3 = { .x = 16, .y = 8},
        .size4 = { .x = 16, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 88, 92, 68, 255 },
    .color2 = { 152, 143, 130, 255 },
};
WindowStyleCustom D_8024BE50 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024B400,
        .packedTileFormat = 0x31,
        .size1 = { .x = 16, .y = 8},
        .size2 = { .x = 16, .y = 8},
        .size3 = { .x = 16, .y = 8},
        .size4 = { .x = 16, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 255, 238, 106, 255 },
    .color2 = { 146, 100, 26, 255 },
};
WindowStyleCustom D_8024BE88 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024A400,
        .packedTileFormat = 0x03,
        .size1 = { .x = 16, .y = 16},
        .size2 = { .x = 16, .y = 16},
        .size3 = { .x = 16, .y = 16},
        .size4 = { .x = 16, .y = 16},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(0, 0, 0, TEXEL1, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(0, 0, 0, TEXEL1, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 0, 0, 0, 255 },
    .color2 = { 0, 0, 0, 0 },
};
WindowStyleCustom D_8024BEC0 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024A400,
        .packedTileFormat = 0x03,
        .size1 = { .x = 16, .y = 16},
        .size2 = { .x = 16, .y = 16},
        .size3 = { .x = 16, .y = 16},
        .size4 = { .x = 16, .y = 16},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(0, 0, 0, TEXEL1, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(0, 0, 0, TEXEL1, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 0, 0, 0, 255 },
    .color2 = { 0, 0, 0, 0 },
};
WindowStyleCustom D_8024BEF8 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024A400,
        .packedTileFormat = 0x03,
        .size1 = { .x = 16, .y = 16},
        .size2 = { .x = 16, .y = 16},
        .size3 = { .x = 16, .y = 16},
        .size4 = { .x = 16, .y = 16},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(0, 0, 0, TEXEL1, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(0, 0, 0, TEXEL1, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 0, 0, 0, 255 },
    .color2 = { 0, 0, 0, 0 },
};
WindowStyleCustom D_8024BF30 = {
    .background = {
        .imgData = NULL,
        .packedTileFormat = 0,
        .width = 0,
        .height = 0,
        .unk_07 = { 0, 0, 0, 0},
        .size = 0
    },
    .corners = {
        .imgData = D_8024B400,
        .packedTileFormat = 0x31,
        .size1 = { .x = 16, .y = 8},
        .size2 = { .x = 16, .y = 8},
        .size3 = { .x = 16, .y = 8},
        .size4 = { .x = 16, .y = 8},
        .unk_0D = { 0, 0, 0}
    },
    .unk_1C = { 0, 0, 0, 0},
    .opaqueCombineMode = gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .transparentCombineMode =  gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL1, ENVIRONMENT, PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    .color1 = { 255, 255, 255, 255 },
    .color2 = { 200, 200, 170, 255 },
};
