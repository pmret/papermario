#include "common.h"
#include "filemenu.h"

extern MessageCharset* gMsgCharsets[5];
extern unsigned char D_802F4560[80][16];

u8 filemenu_msg_C6[] = { 0x33, 0x30, 0x21, 0x23, 0x25, 0xFD };   // SPACE[End]
u8 filemenu_msg_C7[] = { 0xFD };                                 // [End]
u8 filemenu_msg_C8[] = { 0xFD };                                 // [End]
u8 filemenu_msg_C9[] = { 0x22, 0x21, 0x23, 0x2B, 0xFD };         // BACK[End]
u8 filemenu_msg_CA[] = { 0x25, 0x2E, 0x24, 0xFD };               // END[End]
s32 filemenu_specialSymbols[] = { (s32)filemenu_msg_C6, (s32)filemenu_msg_C7, (s32)filemenu_msg_C8, (s32)filemenu_msg_C9, (s32)filemenu_msg_CA };

Gfx filemenu_dl_draw_char_init[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetRenderMode(G_RM_TEX_EDGE, G_RM_TEX_EDGE2),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetPrimColor(0, 0, 40, 40, 40, 72),
    gsSPEndDisplayList(),
};

Gfx* filemenu_savedGfxPos = NULL;
s32 filemenu_charset = 0;
s32 filemenu_charset_raster_id = 0;
s32 filemenu_char_color = -1;

u8 filemenu_msg_01[] = { 0x33, 0x45, 0x4C, 0x45, 0x43, 0x54, 0xF7, 0x46, 0x49, 0x4C, 0x45, 0xF7, 0x54, 0x4F, 0xF7, 0x53,
                    0x54, 0x41, 0x52, 0x54, 0x1A, 0xFD };
u8 filemenu_msg_02[] = { 0x33, 0x45, 0x4C, 0x45, 0x43, 0x54, 0xF7, 0x46, 0x49, 0x4C, 0x45, 0xF7, 0x54, 0x4F, 0xF7, 0x44,
                    0x45, 0x4C, 0x45, 0x54, 0x45, 0x1A, 0xFD };
u8 filemenu_msg_03[] = { 0x33, 0x45, 0x4C, 0x45, 0x43, 0x54, 0xF7, 0x46, 0x49, 0x4C, 0x45, 0xF7, 0x54, 0x4F, 0xF7, 0x53,
                    0x41, 0x56, 0x45, 0xFD };
u8 filemenu_msg_04[] = { 0x23, 0x4F, 0x50, 0x59, 0xF7, 0x57, 0x48, 0x49, 0x43, 0x48, 0xF7, 0x46, 0x49, 0x4C, 0x45, 0x1F,
                    0xFD };
u8 filemenu_msg_05[] = { 0x23, 0x4F, 0x50, 0x59, 0xF7, 0x54, 0x4F, 0xF7, 0x57, 0x48, 0x49, 0x43, 0x48, 0xF7, 0x46, 0x49,
                    0x4C, 0x45, 0x1F, 0xFD };
u8 filemenu_msg_06[] = { 0x2E, 0x25, 0x37, 0xFD };
u8 filemenu_msg_07[] = { 0x2C, 0x45, 0x56, 0x45, 0x4C, 0xFD };
u8 filemenu_msg_08[] = { 0x30, 0x4C, 0x41, 0x59, 0xF7, 0x34, 0x49, 0x4D, 0x45, 0xFD };
u8 filemenu_msg_09[] = { 0x24, 0x45, 0x4C, 0x45, 0x54, 0x45, 0xF7, 0x26, 0x49, 0x4C, 0x45, 0xFD };
u8 filemenu_msg_10[] = { 0x23, 0x41, 0x4E, 0x43, 0x45, 0x4C, 0xFD };
u8 filemenu_msg_11[] = { 0x23, 0x4F, 0x50, 0x59, 0xF7, 0x26, 0x49, 0x4C, 0x45, 0xFD };
u8 filemenu_msg_12[] = { 0x26, 0x49, 0x52, 0x53, 0x54, 0xF7, 0x30, 0x4C, 0x41, 0x59, 0xFD };
u8 filemenu_msg_13[] = { 0x0E, 0xFD };
u8 filemenu_msg_14[] = { 0x39, 0x45, 0x53, 0xFD };
u8 filemenu_msg_15[] = { 0x2E, 0x4F, 0xFD };
u8 filemenu_msg_16[] = { 0x24, 0x45, 0x4C, 0x45, 0x54, 0x45, 0xFD };
u8 filemenu_msg_17[] = { 0x2F, 0x56, 0x45, 0x52, 0x52, 0x49, 0x44, 0x45, 0xF7, 0x54, 0x4F, 0xF7, 0x2E, 0x45, 0x57, 0xF7,
                    0x24, 0x41, 0x54, 0x41, 0xFD };
u8 filemenu_msg_18[] = { 0x33, 0x41, 0x56, 0x45, 0xF7, 0x2F, 0x2B, 0x1F, 0xFD };
u8 filemenu_msg_19[] = { 0x26, 0x49, 0x4C, 0x45, 0xF7, 0x4E, 0x41, 0x4D, 0x45, 0xF7, 0x49, 0x53, 0xF7, 0x1A, 0xFD };
u8 filemenu_msg_20[] = { 0x0E, 0xFD };
u8 filemenu_msg_21[] = { 0x2F, 0x2B, 0x1F, 0xFD };
u8 filemenu_msg_22[] = { 0x26, 0x49, 0x4C, 0x45, 0xFD };
u8 filemenu_msg_23[] = { 0x57, 0x49, 0x4C, 0x4C, 0xF7, 0x42, 0x45, 0xF7, 0x44, 0x45, 0x4C, 0x45, 0x54, 0x45, 0x44, 0x0E,
                    0xFD };
u8 filemenu_msg_24[] = { 0x2F, 0x2B, 0xF7, 0x54, 0x4F, 0xF7, 0x43, 0x4F, 0x50, 0x59, 0xF7, 0x54, 0x4F, 0xF7, 0x54, 0x48,
                    0x49, 0x53, 0xF7, 0x46, 0x49, 0x4C, 0x45, 0x1F, 0xFD };
u8 filemenu_msg_25[] = { 0x33, 0x54, 0x41, 0x52, 0x54, 0xF7, 0x47, 0x41, 0x4D, 0x45, 0xF7, 0x57, 0x49, 0x54, 0x48, 0xFD };
u8 filemenu_msg_26[] = { 0x26, 0x49, 0x4C, 0x45, 0xFD };
u8 filemenu_msg_27[] = { 0x48, 0x41, 0x53, 0xF7, 0x42, 0x45, 0x45, 0x4E, 0xF7, 0x44, 0x45, 0x4C, 0x45, 0x54, 0x45, 0x44,
                    0x0E, 0xFD };
u8 filemenu_msg_28[] = { 0xFD };
u8 filemenu_msg_29[] = { 0x23, 0x4F, 0x50, 0x59, 0xF7, 0x46, 0x52, 0x4F, 0x4D, 0xFD };
u8 filemenu_msg_30[] = { 0x54, 0x4F, 0xFD };
u8 filemenu_msg_31[] = { 0x48, 0x41, 0x53, 0xF7, 0x42, 0x45, 0x45, 0x4E, 0xF7, 0x43, 0x52, 0x45, 0x41, 0x54, 0x45, 0x44,
                    0x0E, 0xFD };
u8 filemenu_msg_32[] = { 0x25, 0x4E, 0x54, 0x45, 0x52, 0xF7, 0x41, 0xF7, 0x46, 0x49, 0x4C, 0x45, 0xF7, 0x4E, 0x41, 0x4D,
                    0x45, 0x01, 0xFD };
u8 filemenu_createfile_gridData[] = { 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D,
                                  0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A,
                                  0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D,
                                  0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A,
                                  0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x10, 0x0E, 0x0D, 0xF7,
                                  0x00, 0x90, 0x91, 0x20, 0xC6, 0xF7, 0xF7, 0xC9, 0xF7, 0xF7, 0xCA, 0xF7, 0xF7
};
u8 filemenu_msg_33[] = { 0x1F, 0xFD };
u8 filemenu_msg_34[] = { 0x0E, 0xFD };

s32 gFileMenuMessages[] = {
    0x00000000, (s32)filemenu_msg_01, (s32)filemenu_msg_02, (s32)filemenu_msg_03, (s32)filemenu_msg_04,
    (s32)filemenu_msg_05, (s32)filemenu_msg_06, (s32)filemenu_msg_07, (s32)filemenu_msg_08, (s32)filemenu_msg_09,
    (s32)filemenu_msg_10, (s32)filemenu_msg_11, (s32)filemenu_msg_12, (s32)filemenu_msg_13, (s32)filemenu_msg_14,
    (s32)filemenu_msg_15, (s32)filemenu_msg_16, (s32)filemenu_msg_17, (s32)filemenu_msg_18, (s32)filemenu_msg_19,
    (s32)filemenu_msg_20, (s32)filemenu_msg_21, (s32)filemenu_msg_22, (s32)filemenu_msg_23, (s32)filemenu_msg_24,
    (s32)filemenu_msg_25, (s32)filemenu_msg_26, (s32)filemenu_msg_27, (s32)filemenu_msg_28, (s32)filemenu_msg_29,
    (s32)filemenu_msg_30, (s32)filemenu_msg_31, (s32)filemenu_msg_32, (s32)filemenu_msg_33, (s32)filemenu_msg_34
};

s32 filemenu_draw_char(s32 c, s32 x, s32 y, s32 flag1, s32 color, s32 flag2) {
    MessageCharset* charset;
    s32 texSizeX;
    s32 texSizeY;
    s32 charRasterSize;
    MessageCharData* charData;
    u8* raster;
    s32 charWidth;

    if (flag1 != filemenu_charset) {
        filemenu_charset = flag1;
        filemenu_charset_raster_id = 0;
    }

    charset = gMsgCharsets[filemenu_charset];
    texSizeX = charset->texSize.x;
    texSizeY = charset->texSize.y;
    charRasterSize = charset->charRasterSize;
    charData = &charset->rasters[filemenu_charset_raster_id];
    charWidth = charData->monospaceWidth;
    raster = charData->raster;

    if (c < 0xA2) {
        charWidth = charData->charWidthTable[c];
        if (gMasterGfxPos != filemenu_savedGfxPos) {
            gSPDisplayList(gMasterGfxPos++, filemenu_dl_draw_char_init);
            filemenu_char_color = -1;
        }

        if (filemenu_char_color != color) {
            filemenu_char_color = color;
            gDPLoadTLUT_pal16(gMasterGfxPos++, 0, D_802F4560[color]);
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
            filemenu_draw_rect((x + 2) * 4, (y + 2) * 4, (2 + x + texSizeX) * 4, (2 + y + texSizeY) * 4, 0, 0, 0, 0x400, 0x400);
            gDPPipeSync(gMasterGfxPos++);
            gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            gDPSetRenderMode(gMasterGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
        }

        filemenu_draw_rect(x * 4, y * 4, (x + texSizeX) * 4, (y + texSizeY) * 4, 0, 0, 0, 0x400, 0x400);
        filemenu_savedGfxPos = gMasterGfxPos;
        return charWidth;
    }

    if (c == 0xF7) {
        return charWidth - 6;
    }

    switch (c) {
        case 0xF3:
            filemenu_charset_raster_id = 0;
            break;
        case 0xF4:
            filemenu_charset_raster_id = 1;
            break;
        case 0xF5:
            filemenu_charset_raster_id = 2;
            break;
        case 0xF6:
            filemenu_charset_raster_id = 3;
            break;
    }
    return 0;
}

void filemenu_draw_message(u8* message, s32 x, s32 y, s32 alpha, s32 color, u32 flags) {
    s32 flag1 = flags & 1;
    s32 flag2 = flags >> 3;

    flag2 &= 1;
    if (flag1 == 1) {
        y -= 2;
    }

    if ((u32)message < 0x100) {
        if ((u32)message - 0xA2 >= 0x4E) {
            filemenu_draw_char((s32)message, x, y, flag1, color, flag2);
            return;
        }
        if ((s32) message >= 0xC6) {
            message = (u8*)filemenu_specialSymbols[(s32) message - 0xC6];
        }
    }

    if ((s32) message < 0) {
        u8* tmp;
        filemenu_draw_char(0xF3, x, y, flag1, color, flag2);
        tmp = message;
        while (*tmp != 0xFD) {
            x += filemenu_draw_char(*tmp, x, y, flag1, color, flag2);
            tmp++;
        }
    }
}

u8* filemenu_get_menu_message(s32 idx) {
    return (u8*)gFileMenuMessages[idx];
}

void filemenu_draw_file_name(u8* filename, s32 length, s32 x, s32 y, s32 alpha, s32 arg5, s32 arg6, s32 charWidth) {
    s32 i;

    for (i = 0; i < length; i++) {
        u32 c = filename[i];

        if (c != 0xF7) {
            filemenu_draw_message((u8*)c, x + (i * charWidth), y, alpha, arg5, arg6);
        }
    }
}
