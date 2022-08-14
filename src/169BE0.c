#include "common.h"

extern u8* gFileMenuMessages[35];

extern s32 D_8024B74C[];
extern Gfx D_8024B760[];
extern Gfx* D_8024B7C8; // some gfx pos
extern s32 D_8024B7CC;
extern s32 D_8024B7D0;
extern s32 D_8024B7D4;
extern MessageCharset* gMsgCharsets[5];
extern UnkMsgStruct8 D_802F4560[];

s32 filemenu_draw_char(s32 c, s32 x, s32 y, s32 flag1, s32 color, s32 flag2) {
    MessageCharset* charset;
    s32 texSizeX;
    s32 texSizeY;
    s32 charRasterSize;
    MessageCharData* charData;
    u8* raster;
    s32 charWidth;

    if (flag1 != D_8024B7CC) {
        D_8024B7CC = flag1;
        D_8024B7D0 = 0;
    }

    charset = gMsgCharsets[D_8024B7CC];
    texSizeX = charset->texSize.x;
    texSizeY = charset->texSize.y;
    charRasterSize = charset->charRasterSize;
    charData = &charset->rasters[D_8024B7D0];
    charWidth = charData->monospaceWidth;
    raster = charData->raster;

    if (c < 0xA2) {
        charWidth = charData->charWidthTable[c];
        if (gMasterGfxPos != D_8024B7C8) {
            gSPDisplayList(gMasterGfxPos++, D_8024B760);
            D_8024B7D4 = -1;
        }

        if (D_8024B7D4 != color) {
            D_8024B7D4 = color;
            gDPLoadTLUT_pal16(gMasterGfxPos++, 0, &D_802F4560[color]);
        }

        if (texSizeX >= 16 && texSizeX % 16 == 0) {
            gDPLoadTextureBlock_4b(gMasterGfxPos++, &raster[charRasterSize * c], G_IM_FMT_CI,
                                texSizeX, texSizeY, 0,
                                G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        } else {
            gDPLoadTextureTile_4b(gMasterGfxPos++, &raster[charRasterSize * c], G_IM_FMT_CI,
                                texSizeX, texSizeY,
                                0, 0, texSizeX - 1, texSizeY - 1, 0,
                                G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        }

        if (flag2) {
            gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
            gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
            mainmenu_draw_rect((x + 2) * 4, (y + 2) * 4, (2 + x + texSizeX) * 4, (2 + y + texSizeY) * 4, 0, 0, 0, 0x400, 0x400);
            gDPPipeSync(gMasterGfxPos++);
            gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            gDPSetRenderMode(gMasterGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
        }

        mainmenu_draw_rect(x * 4, y * 4, (x + texSizeX) * 4, (y + texSizeY) * 4, 0, 0, 0, 0x400, 0x400);
        D_8024B7C8 = gMasterGfxPos;
        return charWidth;
    }

    if (c == 0xF7) {
        return charWidth - 6;
    }

    switch (c) {
        case 0xF3:
            D_8024B7D0 = 0;
            break;
        case 0xF4:
            D_8024B7D0 = 1;
            break;
        case 0xF5:
            D_8024B7D0 = 2;
            break;
        case 0xF6:
            D_8024B7D0 = 3;
            break;
    }
    return 0;
}

// issue with the second filemenu_draw_char arg order
#ifdef NON_MATCHING
void filemenu_draw_message(u8* message, s32 x, s32 y, s32 alpha, s32 color, u32 flags) {
    s32 flag1 = flags & 1;
    s32 flag2 = flags >> 3;

    flag2 &= 1;
    if (flag1 == 1) {
        y -= 2;
    }

    if (message < 0x100) {
        if (message - 0xA2 >= 0x4E) {
            filemenu_draw_char(message, x, y, flag1, color, flag2);
            return;
        }
        if ((s32) message >= 0xC6) {
            message = D_8024B74C[(s32) message - 0xC6];
        }
    }

    if ((s32) message < 0) {
        filemenu_draw_char(0xF3, x, y, flag1, color, flag2);
        while (*message != 0xFD) {
            x += filemenu_draw_char(*message++, x, y, flag1, color, flag2);
        }
    }
}
#else
INCLUDE_ASM(s32, "169BE0", filemenu_draw_message);
#endif

// data migration
#ifdef NON_MATCHING
u8* filemenu_get_menu_message(s32 idx) {
    return gFileMenuMessages[idx];
}
#else
INCLUDE_ASM(s32, "169BE0", filemenu_get_menu_message);
#endif

void filemenu_draw_file_name(u8* filename, s32 length, s32 x, s32 y, s32 alpha, s32 arg5, s32 arg6, s32 charWidth) {
    s32 i;

    for (i = 0; i < length; i++) {
        u32 c = filename[i];

        if (c != 0xF7) {
            filemenu_draw_message(c, x + (i * charWidth), y, alpha, arg5, arg6);
        }
    }
}
