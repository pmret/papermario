#include "common.h"
#include "hud_element.h"
#include "nu/nusys.h"
#include "ld_addrs.h"

s32 fold_appendGfx_component(s32 idx, FoldImageRecPart* image, u32 flagBits, Matrix4f mtx);

void func_801413F8(void);

typedef struct UnkHudElementStruct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} UnkHudElementStruct; // size = 0x08;

extern HudElementList* gHudElements;

s32 D_8014EFC0 = 0;
s32 D_8014EFC4 = 0x11000;

HudScript hud_element_defaultAnim = {
    he_End,
};

typedef struct HudElementSize {
    s16 width;
    s16 height;
    s16 size;
} HudElementSize;

HudElementSize gHudElementSizes[26] = {
    { 8, 8, 32 },
    { 16, 16, 128 },
    { 24, 24, 288 },
    { 32, 32, 512 },
    { 48, 48, 1152 },
    { 64, 64, 2048 },
    { 8, 16, 64 },
    { 16, 8, 64 },
    { 16, 24, 192 },
    { 16, 32, 256 },
    { 64, 32, 1024 },
    { 32, 16, 256 },
    { 12, 12, 72 },
    { 48, 24, 576 },
    { 32, 8, 128 },
    { 24, 8, 96 },
    { 64, 16, 512 },
    { 16, 64, 512 },
    { 192, 32, 3072 },
    { 40, 40, 800 },
    { 24, 16, 192 },
    { 32, 40, 640 },
    { 40, 16, 320 },
    { 40, 24, 480 },
    { 32, 24, 384 },
    { 20, 32, 0 }
};

s32 D_8014F068[] = {
    0x00220020, 0x00000028, 0x002803C8, 0x00000000
};
Gfx D_8014F078[] = {
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT),
    gsDPPipeSync(),
    gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18, G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPEndDisplayList()
};
Gfx D_8014F0A0[] = {
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT),
    gsDPPipeSync(),
    gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18, G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPEndDisplayList()
};

Vtx D_8014F0C8[] = {
    {
        .v = {
            .ob = { -12, 0, 0},
            .flag = 0,
            .tc = { 0x800, 0x800 },
            .cn = { 0, 0, 0, 255}
        }
    },
    {
        .v = {
            .ob = { 51, 0, 0},
            .flag = 0,
            .tc = { 0, 0x800 },
            .cn = { 0, 0, 0, 255}
        }
    },
    {
        .v = {
            .ob = { 51, 63, 0},
            .flag = 0,
            .tc = { 0, 0 },
            .cn = { 0, 0, 0, 255}
        }
    },
    {
        .v = {
            .ob = { -12, 63, 0},
            .flag = 0,
            .tc = { 0x800, 0 },
            .cn = { 0, 0, 0, 255}
        }
    }
};

Lights1 D_8014F108 = {
    .a = {
        .l = {
            .col = { 255, 255, 255 },
            .colc = { 255, 255, 255 },
        }
    },
    .l = {
        {
            .l = {
                .col = { 0, 0, 0 },
                .colc = { 0, 0, 0 },
                .dir = { 0, 0, 0},
            }
        }
    }
};

extern s32 D_801512B4; // no of hud elements?
extern s32 D_80159180;
extern HudElementList D_80156F60;
extern HudElementList D_80157460;
extern s32* D_8015133C;
extern void* D_80157968;
extern UnkHudElementStruct** D_801512C8;
extern UnkHudElementStruct** D_801512D0;
extern UnkHudElementStruct D_80157970[];

extern UnkHudElementStruct D_80157F70[];
extern void* D_80158574;
extern UnkHudElementStruct D_80158580[];
extern UnkHudElementStruct D_80158B80[];
extern s32* D_80157964;
extern s32* D_80158570;
extern s32* D_80151314;

void load_hud_element(HudElement* hudElement, const HudScript* anim) {
    s32* ptr = anim;
    s32 raster;
    s32 palette;
    s32 s3;
    Vec3s* size;
    UnkHudElementStruct* uhl;
    s32 i;
    s32 x;

    if (ptr == NULL) {
        return;
    }

    s3 = 0;

    while (TRUE) {
        switch (*ptr++) {
            case HUD_ELEMENT_OP_End:
                return;
            case HUD_ELEMENT_OP_SetCI:
                ptr += 3;
                break;

            case HUD_ELEMENT_OP_SetTileSize:
                s3 = *ptr++;
                hudElement->drawSizePreset = hudElement->tileSizePreset = s3;
                break;

            case HUD_ELEMENT_OP_SetSizesAutoScale:
            case HUD_ELEMENT_OP_SetSizesFixedScale:
                s3 = *ptr;
                ptr += 2;
                hudElement->drawSizePreset = hudElement->tileSizePreset = s3;
                break;

            case HUD_ELEMENT_OP_SetCustomSize:
                hudElement->customDrawSize.x = hudElement->customImageSize.x = *ptr++;
                hudElement->customDrawSize.y = hudElement->customImageSize.y = *ptr++;
                hudElement->flags |= 0x100000;
                break;

            case HUD_ELEMENT_OP_AddTexelOffsetX:
            case HUD_ELEMENT_OP_AddTexelOffsetY:
            case HUD_ELEMENT_OP_SetScale:
            case HUD_ELEMENT_OP_SetAlpha:
            case HUD_ELEMENT_OP_op_15:
            case HUD_ELEMENT_OP_RandomBranch:
            case HUD_ELEMENT_OP_SetFlags:
            case HUD_ELEMENT_OP_ClearFlags:
            case HUD_ELEMENT_OP_PlaySound:
                ptr++;
                break;

            case HUD_ELEMENT_OP_SetRGBA:
            case HUD_ELEMENT_OP_AddTexelOffset:
            case HUD_ELEMENT_OP_RandomDelay:
            case HUD_ELEMENT_OP_RandomRestart:
            case HUD_ELEMENT_OP_op_1B:
                ptr += 2;
                break;

            case HUD_ELEMENT_OP_SetImage:
                ptr++;
                raster = *ptr++;
                palette = *ptr++;

                //size = &gHudElementSizes[s3];
                i = 0;
                uhl = D_801512C8;
                while (TRUE) {
                    if (uhl->unk_00 == -1) {
                        uhl->unk_00 = raster;
                        uhl->unk_04 = (s32)(D_80151314) + (s32)(*D_8015133C);
                        if (!gGameStatusPtr->isBattle) {
                            x = D_8014EFC4;
                        } else {
                            x = D_8014EFC4 / 2;
                        }
                        ASSERT(x > *D_8015133C + gHudElementSizes[s3].size);
                        nuPiReadRom(icon_present_VRAM + raster, uhl->unk_04, gHudElementSizes[s3].size);
                        *D_8015133C += gHudElementSizes[s3].size;
                        if (!gGameStatusPtr->isBattle) {
                            *ptr = i;
                        } else {
                            *ptr = (u16)(*ptr) | (i << 16);
                        }
                        i++;
                        break;
                    } else if (uhl->unk_00 == raster) {
                        if (!gGameStatusPtr->isBattle) {
                            *ptr = i;
                        } else {
                            *ptr = (u16)(*ptr) | (i << 16);
                        }
                        break;
                    }
                    uhl++;
                    i++;
                }

                ptr++;
                ASSERT(i < 192);

                uhl = D_801512D0;
                i = 0;
                while (TRUE) {
                    if (uhl->unk_00 == -1) {
                        uhl->unk_00 = palette;
                        uhl->unk_04 = (s32)(D_80151314) + (s32)(*D_8015133C);
                        if (!gGameStatusPtr->isBattle) {
                            x = D_8014EFC4;
                        } else {
                            x = D_8014EFC4 / 2;
                        }
                        ASSERT(x > *D_8015133C + 32);
                        nuPiReadRom(icon_present_VRAM + palette, uhl->unk_04, 32);
                        *D_8015133C += 32;
                        if (!gGameStatusPtr->isBattle) {
                            *ptr = i;
                        } else {
                            *ptr = (u16)(*ptr) | (i << 16);
                        }
                        i++;
                        break;
                    } else if (uhl->unk_00 == palette) {
                        if (!gGameStatusPtr->isBattle) {
                            *ptr = i;
                        } else {
                            *ptr = (u16)(*ptr) | (i << 16);
                        }
                        break;
                    }
                    uhl++;
                    i++;
                }

                ptr++;
                ASSERT(i < 192);

                break;
        }
    }
}
/*
INCLUDE_ASM(void, "hud_element", draw_rect_hud_element,
    HudElement* hudElement,
    s32 texSizeX,
    s32 texSizeY,
    s32 drawSizeX,
    s32 drawSizeY,
    s32 offsetX,
    s32 offsetY,
    s32 clamp,
    s32 dropShadow
)*/

void draw_rect_hud_element(HudElement* hudElement, s16 texSizeX, s16 texSizeY, s16 drawSizeX, s16 drawSizeY,
                           s16 offsetX, s16 offsetY, s32 clamp, s32 dropShadow) {
    u32 temp_a0;
    u32 temp_a1;
    s32 sp0;
    s32 sp4;
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;

    u32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    s32 sp30;
    s32 sp34;
    s32 sp38;
    s32 sp40;
    s32 sp48;
    s32 sp4C;
    s32 sp50;
    s32 sp54;
    s32 sp58;
    s32 sp5C;
    s32 sp64;
    s32 sp68;
    s32 nv2;
    s32 sp6C;
    s32 sp88;
    s32 sp8C;
    s32 sp8C_2;

    u32 nv;
    u8* imageAddr;
    u8* paletteAddr;
    s16 t2, t5;
    s32 t0, t1;
    s32 a1, t4;
    s32 t3;
    s32 temp;
    s32 texSizeX2;
    s32 temp1, temp3;
    s32 temp11;
    u32 temp5, temp6;
    u16 wpX, wpY;
    s32 qqq;
    s16 temp2, temp4;
    imageAddr = hudElement->imageAddr;
    paletteAddr = hudElement->paletteAddr;

    sp8C = hudElement->screenPosOffset.x * 1024;
    sp8C_2 = hudElement->screenPosOffset.y * 1024;
    spC = hudElement->widthScale;
    sp8C /= spC;
    sp10 = hudElement->heightScale;
    sp8C_2 /= sp10;

    wpX = hudElement->worldPosOffset.x;
    wpY = hudElement->worldPosOffset.y;
    wpX += hudElement->renderPosX + sp8C;
    wpY += hudElement->renderPosY + sp8C_2;
    temp2 = offsetX;
    temp4 = offsetY;
    temp2 += wpX;
    temp4 += wpY;


    t5 = temp2;
    t2 = temp4;

    if (dropShadow) {
        t5 = temp2 + 2;
        t2 = temp4 + 2;
    }

    sp8 = 0;
    temp5 = (hudElement->flags & 0x4000);
    temp_a0 = temp5 != 0;
    temp5 = (hudElement->flags & 0x80000);
    temp_a1 = temp5 != 0;
    temp5 = (hudElement->flags & 0x1000);
    sp0 = temp5 != 0;
    temp6 = (hudElement->flags & 0x2000);
    sp4 = temp6 != 0;

    if (temp_a0 == TRUE) {
        sp8 = temp_a1 < TRUE;
    }
    if (temp_a0 == 0 && temp_a1 == 1U) {
        sp8 = 2;
    }
    if ((temp_a0 == 1) && (temp_a1 == temp_a0)) {
        sp8 = 2;
    }
    sp34 = 6;
    sp38 = 5;

    if ((hudElement->flags & 0x10) == 0) { // 1a4 -> 24c
        switch (drawSizeX) {
            case 8:
                sp34 = 3;
                break;
            case 16:
                sp34 = 4;
                break;
            case 32:
                sp34 = 5;
                break;
        }

        switch (drawSizeY) {
            case 8:
                sp38 = 3;
                break;
            case 16:
                sp38 = 4;
                break;
            case 32:
                sp38 = 5;
                break;
        }
    }
    // 250
    switch (sp8) {
        // 1 -> 28c
        // < 2 -> 278
        // 2 -> 3ec
        // default -> 430
        case 0:
            gDPSetRenderMode(gMasterGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
            gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
            break;

        case 1:
            if ((hudElement->flags & 0x20) == 0) {
                if ((hudElement->flags & 0x800000) == 0) {
                    gDPSetRenderMode(gMasterGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
                } else {
                    gDPSetRenderMode(gMasterGfxPos++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
                }
            } else {
                if ((hudElement->flags & 0x800000) == 0) {
                    gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
                } else {
                    gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF | AA_EN, G_RM_CLD_SURF2 | AA_EN);
                }
            }
            gDPSetTextureLUT(gMasterGfxPos++, G_TT_RGBA16);
            gDPLoadTLUT_pal16(gMasterGfxPos++, 0, paletteAddr);
            break;

        case 2:
            gDPSetRenderMode(gMasterGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
            gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
            break;
    }

    if (hudElement->flags & 0x8000) {
        gDPSetTextureFilter(gMasterGfxPos++, G_TF_AVERAGE);
    } else {
        gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);
    }

    //sp40 = t2;
    //sp28 = t2;
    //sp48 = texSizeY <= 16;
    sp24 = 0;
    sp20 = FALSE;
    //sp4C = drawSizeY;
    //sp54 = t5 << 16;
    //sp5C = t5;
    //sp50 = t2 + drawSizeY;
    //sp64 = texSizeX;
    //sp64 = sp64 <= 16;
    //sp68 = drawSizeX;
    // 51c
    sp28 = t2;
    while (TRUE) { // loop_51
        sp2C = sp28 + 1024.0 / sp10 * 32.0;
        a1 = sp24 + 31;
        if (sp4) {
            sp18 = texSizeY;
        } else {
            sp18 = 0;
        }

        if (sp2C < 0 || sp28 > SCREEN_HEIGHT) {
            break;
        }

        if (sp2C >= SCREEN_HEIGHT) {
            s32 temp1 = sp24 + 271;
            temp1 -= t2 + a1;
            a1 = temp1 - 1;

            sp2C = SCREEN_HEIGHT;
            sp20 = TRUE;
        }

        if (a1 + 1 >= texSizeY) {
            a1 = texSizeY - 1;
            if (texSizeY > 16) {
                sp2C = t2 + drawSizeY - 1;
            } else {
                sp2C = t2 + drawSizeY;
            }
            sp20 = TRUE;
        }
        sp1C = FALSE;
        //sp6C = t5 + drawSizeX;
        t4 = 0;
        sp30 = t5;
        while (TRUE) { // loop_63
            sp88 = sp30 + 1024.0 / spC * 64.0;
            t3 = t4 + 63;
            if (sp0) {
                sp14 = texSizeX;
            } else {
                sp14 = 0;
            }

            if (sp88 < 0  || sp30 > SCREEN_WIDTH) {
                break;
            }

            if (sp88 >= SCREEN_WIDTH) {
                s32 temp1 = t4 + 383;
                temp1 -= t5 + t3;
                t3 = temp1 - 1;

                sp88 = SCREEN_WIDTH;
                sp1C = TRUE;
            }

            if (t3 + 1 >= texSizeX) {
                t3 = texSizeX - 1;
                if (texSizeX > 16) {
                    sp88 = t5 + drawSizeX - 1;
                } else {
                    sp88 = t5 + drawSizeX;
                }
                sp1C = TRUE;
            }

            gDPPipeSync(gMasterGfxPos++);

            if (sp1C ) {
                t1 = !sp20;
            }
            if (!sp1C && !sp20) {
                t1 = 0;
            }
            if (!sp1C && sp20) {
                t1 = 2;
            }
            if (sp1C && sp20) {
                t1 = 3;
            }

            switch (sp8) {
                case 0:
                    gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                    if ((hudElement->flags & 0x20) == 0) {
                        gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                    } else {
                        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
                    }

                    if (hudElement->flags & (nv = 0x20)) {
                        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, hudElement->opacity);
                    }

                    if (!sp0 && !sp4) {
                        gDPLoadTextureTile(gMasterGfxPos++, imageAddr, G_IM_FMT_RGBA, G_IM_SIZ_32b, texSizeX, texSizeY, t4, sp24, t3, a1, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, sp34, sp38, G_TX_NOLOD, G_TX_NOLOD);
                    } else {
                        gDPLoadTextureTile(gMasterGfxPos++, imageAddr, G_IM_FMT_RGBA, G_IM_SIZ_32b, texSizeX, texSizeY, t4, sp24, t3, a1, 0,
                                            G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, sp34, sp38, G_TX_NOLOD, G_TX_NOLOD);
                    }
                    break;

                case 1:
                    if (!dropShadow) {
                        gDPSetCombineLERP(gMasterGfxPos++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, TEXEL0, 0, PRIMITIVE, 0);
                        do {} while (0);
                        if (hudElement->flags & nv) {
                            gDPSetPrimColor(gMasterGfxPos++, 0, 0, hudElement->tint.r, hudElement->tint.g, hudElement->tint.b, hudElement->opacity);
                        } else {
                            gDPSetPrimColor(gMasterGfxPos++, 0, 0, hudElement->tint.r, hudElement->tint.g, hudElement->tint.b, 255);
                        }
                    } else {
                        gDPSetRenderMode(gMasterGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
                        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
                        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 40, 40, 40, 72);
                    }

                    if (!sp0 && !sp4) {

                        if (!clamp) {
                            gDPLoadTextureTile_4b(gMasterGfxPos++, imageAddr, G_IM_FMT_CI, texSizeX, texSizeY, t4, sp24, t3, a1, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, sp34, sp38, G_TX_NOLOD, G_TX_NOLOD);
                        } else {
                            switch (t1) {
                                case 0:
                                    gDPLoadTextureTile_4b(gMasterGfxPos++, imageAddr, G_IM_FMT_CI, texSizeX, texSizeY, t4, sp24, t3, a1, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, sp34, sp38, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                                case 1:
                                    gDPLoadTextureTile_4b(gMasterGfxPos++, imageAddr, G_IM_FMT_CI, texSizeX, texSizeY, t4, sp24, t3, a1, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, sp34, sp38, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                                case 2:
                                    gDPLoadTextureTile_4b(gMasterGfxPos++, imageAddr, G_IM_FMT_CI, texSizeX, texSizeY, t4, sp24, t3, a1, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, sp34, sp38, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                                case 3:
                                    gDPLoadTextureTile_4b(gMasterGfxPos++, imageAddr, G_IM_FMT_CI, texSizeX, texSizeY, t4, sp24, t3, a1, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, sp34, sp38, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                            }
                        }
                    } else {
                        gDPLoadTextureTile_4b(gMasterGfxPos++, imageAddr, G_IM_FMT_CI, texSizeX, texSizeY, t4, sp24, t3, a1, 0,
                                            G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, sp34, sp38, G_TX_NOLOD, G_TX_NOLOD);
                    }
                    break;

                case 2:
                    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, 0, TEXEL0, 0, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, 0, TEXEL0, 0);
                    gDPSetPrimColor(gMasterGfxPos++, 0, 0, hudElement->tint.r, hudElement->tint.g, hudElement->tint.b, hudElement->opacity);

                    if (!sp0 && !sp4) {
                        if (!clamp) {
                            switch (t1) {
                                case 0:
                                    gDPLoadTextureTile(gMasterGfxPos++, imageAddr, G_IM_FMT_IA, G_IM_SIZ_8b, texSizeX, texSizeY, t4, sp24, t3, a1, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, sp34, sp38, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                                case 1:
                                    gDPLoadTextureTile(gMasterGfxPos++, imageAddr, G_IM_FMT_IA, G_IM_SIZ_8b, texSizeX, texSizeY, t4, sp24, t3, a1, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, sp34, sp38, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                                case 2:
                                    gDPLoadTextureTile(gMasterGfxPos++, imageAddr, G_IM_FMT_IA, G_IM_SIZ_8b, texSizeX, texSizeY, t4, sp24, t3, a1, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, sp34, sp38, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                                case 3:
                                    gDPLoadTextureTile(gMasterGfxPos++, imageAddr, G_IM_FMT_IA, G_IM_SIZ_8b, texSizeX, texSizeY, t4, sp24, t3, a1, 0,
                                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, sp34, sp38, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                            }
                        } else {
                            gDPLoadTextureTile(gMasterGfxPos++, imageAddr, G_IM_FMT_IA, G_IM_SIZ_8b, texSizeX, texSizeY, t4, sp24, t3, a1, 0,
                                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, sp34, sp38, G_TX_NOLOD, G_TX_NOLOD);
                        }
                    } else {
                        gDPLoadTextureTile(gMasterGfxPos++, imageAddr, G_IM_FMT_IA, G_IM_SIZ_8b, texSizeX, texSizeY, t4, sp24, t3, a1, 0,
                                            G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, sp34, sp38, G_TX_NOLOD, G_TX_NOLOD);
                    }
                    break;
            }

            if (hudElement->flags & 0x8000) {
                gSPScisTextureRectangle(gMasterGfxPos++, sp30 * 4, sp28 * 4, sp88 * 4, sp2C * 4, 0, sp14 * 32 + 16, sp18 * 32 + 16, spC, sp10);
            } else {
                gSPScisTextureRectangle(gMasterGfxPos++, sp30 * 4, sp28 * 4, sp88 * 4, sp2C * 4, 0, sp14 * 32, sp18 * 32, spC, sp10);
            }
            if (sp1C) {
                break;
            }
            sp30 += 1024.0 / spC * 64.0;
            t4 += 64;
        }

        if (sp20) {
            break;
        }

        sp24 += 32;
        sp28 += 1024.0 / sp10 * 32.0;
    }

    gDPPipeSync(gMasterGfxPos++);
}

void clear_hud_element_cache(void) {
    s32 i;
    UnkHudElementStruct* p1;
    UnkHudElementStruct* p2;

    if (!gGameStatusPtr->isBattle) {
        gHudElements = &D_80156F60;
        D_8015133C = &D_80157968;
        D_801512C8 = &D_80157970;
        D_801512D0 = &D_80157F70;
    } else {
        gHudElements = &D_80157460;
        D_8015133C = &D_80158574;
        D_801512C8 = &D_80158580;
        D_801512D0 = &D_80158B80;
    }

    if (!gGameStatusPtr->isBattle) {
        D_80151314 = general_heap_malloc(D_8014EFC4);
        ASSERT(D_80151314);
        D_80157964 = D_80151314;
        *D_8015133C = 0;
        p1 = D_801512C8;
        p2 = D_801512D0;
        for (i = 0; i < 192; i++) {
            p1[i].unk_00 = -1;
            p2[i].unk_00 = -1;
        }
    } else {
        if (D_8014EFC0 == 0) {
            D_80151314 = general_heap_malloc(D_8014EFC4 / 2);
            ASSERT(D_80151314);
        } else {
            D_80151314 = D_8014EFC0;
        }
        D_80158570 = D_80151314;
        *D_8015133C = 0;
        p1 = D_801512C8;
        p2 = D_801512D0;
        for (i = 0; i < 192; i++) {
            p1[i].unk_00 = -1;
            p2[i].unk_00 = -1;
        }
    }

    for (i = 0; i < 320; i++) {
        (*gHudElements)[i] = NULL;
    }

    D_801512B4 = 0;
    D_80159180 = 0;
    func_801413F8();
}

void init_hud_element_list(void) {
    if (!gGameStatusPtr->isBattle) {
        if (D_80158570 != NULL) {
            general_heap_free(D_80158570);
            D_80158570 = NULL;
        }

        gHudElements = &D_80156F60;
        D_8015133C = &D_80157968;
        D_801512C8 = &D_80157970;
        D_801512D0 = &D_80157F70;
        D_80151314 = D_80157964;
    } else {
        gHudElements = &D_80157460;
        D_8015133C = &D_80158574;
        D_801512C8 = &D_80158580;
        D_801512D0 = &D_80158B80;
        D_80151314 = D_80158570;
    }

    D_801512B4 = 0;
    D_80159180 = 0;
}

void func_801413F8(void) {
    set_cam_viewport(3, 0, 0, 0x13F, 0xEF);
    gCameras[CAM_CAM3].updateMode = 2;
    gCameras[CAM_CAM3].unk_06 = 1;
    gCameras[CAM_CAM3].unk_20 = 0x3CBF;
    gCameras[CAM_CAM3].nearClip = 0x10;
    gCameras[CAM_CAM3].unk_1C = 0;
    gCameras[CAM_CAM3].unk_1E = 0;
    gCameras[CAM_CAM3].unk_22 = 0;
    gCameras[CAM_CAM3].unk_5C = 0;
    gCameras[CAM_CAM3].farClip = 0x4000;
    gCameras[CAM_CAM3].bgColor[0] = 0;
    gCameras[CAM_CAM3].bgColor[1] = 0;
    gCameras[CAM_CAM3].bgColor[2] = 0;
    gCameras[CAM_CAM3].unk_54 = 160.0f;
    gCameras[CAM_CAM3].unk_58 = -120.0f;
    gCameras[CAM_CAM3].vfov = 1.0f;
    gCameras[CAM_CAM3].flags &= ~0x6;
}

s32 create_hud_element(const HudScript* anim) {
    HudElement* hudElement;
    s32 id;

    for (id = 0; id < ARRAY_COUNT(*gHudElements); id++) {
        if ((*gHudElements)[id] == NULL) {
            break;
        }
    }

    ASSERT(id < ARRAY_COUNT(*gHudElements));

    (*gHudElements)[id] = hudElement = heap_malloc(sizeof(HudElement));
    D_801512B4 += 1;

    ASSERT(hudElement != NULL);

    hudElement->flags = 1;
    hudElement->readPos = anim;
    if (anim == NULL) {
        hudElement->readPos = &hud_element_defaultAnim;
    }
    hudElement->updateTimer = 1;
    hudElement->drawSizePreset = -1;
    hudElement->tileSizePreset = -1;
    hudElement->renderPosX = 0;
    hudElement->renderPosY = 0;
    hudElement->ptrPropertyList = (s32*) anim; // TODO: what
    hudElement->widthScale = X10(1.0f);
    hudElement->heightScale = X10(1.0f);
    hudElement->anim = hudElement->readPos;
    hudElement->uniformScale = 1.0f;
    hudElement->screenPosOffset.x = 0;
    hudElement->screenPosOffset.y = 0;
    hudElement->worldPosOffset.x = 0;
    hudElement->worldPosOffset.y = 0;
    hudElement->worldPosOffset.z = 0;
    hudElement->opacity = 255;
    hudElement->tint.r = 255;
    hudElement->tint.g = 255;
    hudElement->tint.b = 255;

    if (gGameStatusPtr->isBattle) {
        hudElement->flags |= 0x400;
        id |= 0x800;
    }

    load_hud_element(hudElement, hudElement->readPos);
    while (hud_element_update(hudElement) != 0);

    return id;
}

// TODO not ideal match - should be able to put loop iterator in the loop def, but can't
void update_hud_elements(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gHudElements);) {
        HudElement* elem = (*gHudElements)[i];

        if (elem != NULL && (elem->flags != 0) && !(elem->flags & 2)) {
            if (elem->flags & 0x40000) {
                free_hud_element(i);
                i++;
            } else if (elem->readPos != 0) {
                elem->updateTimer--;
                if (elem->updateTimer == 0) {
                    while (hud_element_update(elem) != 0);
                }
                if (elem->flags & 0x100) {
                    elem->unkImgScale[0] += elem->unk_20;
                    elem->unkImgScale[1] += elem->unk_24;
                }
                i++;
            } else {
                break;
            }
        } else {
            i++;
        }
    }
}

s32 hud_element_update(HudElement* hudElement) {
    UnkHudElementStruct* a1;
    UnkHudElementStruct* a3;
    s32 i;
    s32 drawSizePreset;
    s32 tileSizePreset;
    u8 sizePreset;
    f32 xScaled, yScaled;
    s32 imageWidth, imageHeight, drawWidth, drawHeight;
    u32 min, max;
    u32 flags;
    f32 scale1, scale2;
    s32 raster, palette;
    s32 s1, s2;
    s32 arg1, arg2;
    f32 uniformScale;
    s32* newReadPos;

    HudTransform* hudTransform = hudElement->hudTransform;
    s32* nextPos = hudElement->readPos;

    switch (*nextPos++) {
        case HUD_ELEMENT_OP_End:
            hudElement->updateTimer = 60;
            flags = hudElement->flags;
            do { hudElement->flags = flags | 0x4; } while (0);
            return FALSE;

        case HUD_ELEMENT_OP_Delete:
            hudElement->updateTimer = 60;
            do {
                hudElement->flags |= 0x40000;
            } while (0);
            return FALSE;

        case HUD_ELEMENT_OP_UseIA8:
            hudElement->readPos = nextPos;
            hudElement->flags |= 0x80000;
            return TRUE;

        case HUD_ELEMENT_OP_SetVisible:
            hudElement->readPos = nextPos;
            hudElement->flags |= 0x4000;
            return TRUE;

        case HUD_ELEMENT_OP_SetHidden:
            hudElement->readPos = nextPos;
            hudElement->flags &= ~0x4000;
            return TRUE;

        case HUD_ELEMENT_OP_SetFlags:
            s1 = *nextPos++;
            hudElement->readPos = nextPos;
            hudElement->flags |= s1;
            return TRUE;

        case HUD_ELEMENT_OP_ClearFlags:
            s1 = *nextPos++;
            hudElement->readPos = nextPos;
            hudElement->flags &= ~s1;
            return TRUE;

        case HUD_ELEMENT_OP_SetRGBA:
            hudElement->updateTimer = *nextPos++;
            hudElement->imageAddr = *nextPos++;
            hudElement->readPos = nextPos;

            if (hudElement->flags & 0x400000) {
                hudElement->imageAddr += hudElement->memOffset;
            }

            if (hudElement->flags & 0x100) {
                if ((hudElement->flags & 0x100000) == 0) {
                    tileSizePreset = hudElement->tileSizePreset;
                    drawSizePreset = hudElement->drawSizePreset;
                    imageWidth = gHudElementSizes[tileSizePreset].width;
                    imageHeight = gHudElementSizes[tileSizePreset].height;
                    drawWidth = gHudElementSizes[drawSizePreset].width;
                    drawHeight = gHudElementSizes[drawSizePreset].height;
                } else {
                    imageWidth = hudElement->customImageSize.x;
                    imageHeight = hudElement->customImageSize.y;
                    drawWidth = hudElement->customDrawSize.x;
                    drawHeight = hudElement->customDrawSize.y;
                }

                if ((hudElement->flags & 0x200) == 0) {
                    hudElement->flags |= 0x200;
                    hudElement->unkImgScale[0] = imageWidth;
                    hudElement->unkImgScale[1] = imageHeight;
                    hudElement->unk_20 = ((f32)drawWidth - (f32)imageWidth) / (f32)hudElement->updateTimer;
                    hudElement->unk_24 = ((f32)drawHeight - (f32)imageHeight) / (f32)hudElement->updateTimer;
                } else {
                    hudElement->flags &= ~0x200;
                    hudElement->unkImgScale[0] = drawWidth;
                    hudElement->unkImgScale[1] = drawHeight;
                    hudElement->unk_20 = ((f32)imageWidth - (f32)drawWidth) / (f32)hudElement->updateTimer;
                    hudElement->unk_24 = ((f32)imageHeight - (f32)drawHeight) / (f32)hudElement->updateTimer;
                }
            }
            return FALSE;

        case HUD_ELEMENT_OP_SetCI:
            hudElement->updateTimer = *nextPos++;
            hudElement->imageAddr = *nextPos++;
            hudElement->paletteAddr = *nextPos++;
            hudElement->readPos = nextPos;

            if (hudElement->flags & 0x400000) {
                hudElement->imageAddr += hudElement->memOffset;
                hudElement->paletteAddr += hudElement->memOffset;
            }

            if (hudElement->flags & 0x100) {
                if ((hudElement->flags & 0x100000) == 0) {
                    tileSizePreset = hudElement->tileSizePreset;
                    drawSizePreset = hudElement->drawSizePreset;
                    imageWidth = gHudElementSizes[tileSizePreset].width;
                    imageHeight = gHudElementSizes[tileSizePreset].height;
                    drawWidth = gHudElementSizes[drawSizePreset].width;
                    drawHeight = gHudElementSizes[drawSizePreset].height;
                } else {
                    imageWidth = hudElement->customImageSize.x;
                    imageHeight = hudElement->customImageSize.y;
                    drawWidth = hudElement->customDrawSize.x;
                    drawHeight = hudElement->customDrawSize.y;
                }

                if ((hudElement->flags & 0x200) == 0) {
                    hudElement->flags |= 0x200;
                    hudElement->unkImgScale[0] = imageWidth;
                    hudElement->unkImgScale[1] = imageHeight;
                    hudElement->unk_20 = ((f32)drawWidth - (f32)imageWidth) / (f32)hudElement->updateTimer;
                    hudElement->unk_24 = ((f32)drawHeight - (f32)imageHeight) / (f32)hudElement->updateTimer;
                } else {
                    hudElement->flags &= ~0x200;
                    hudElement->unkImgScale[0] = drawWidth;
                    hudElement->unkImgScale[1] = drawHeight;
                    hudElement->unk_20 = ((f32)imageWidth - (f32)drawWidth) / (f32)hudElement->updateTimer;
                    hudElement->unk_24 = ((f32)imageHeight - (f32)drawHeight) / (f32)hudElement->updateTimer;
                }
            }
            return FALSE;

        case HUD_ELEMENT_OP_SetImage:
            hudElement->updateTimer = *nextPos++;

            if ((hudElement->flags & 0x400) == 0) {
                a1 = D_80157970;
                a3 = D_80157F70;
            } else {
                a1 = D_80158580;
                a3 = D_80158B80;
            }

            i = 0;
            while (TRUE) {
                if (a1[i].unk_00 == *nextPos) {
                    break;
                }
                ASSERT(++i < 192);
            }

            nextPos++;
            hudElement->imageAddr = a1[i].unk_04;

            i = 0;
            while (TRUE) {
                if (a3[i].unk_00 == *nextPos) {
                    break;
                }
                ASSERT(++i < 192);
            }
            hudElement->paletteAddr = a3[i].unk_04;
            nextPos += 3;
            hudElement->readPos = nextPos;


            if (hudElement->flags & 0x100) {
                if ((hudElement->flags & 0x100000) == 0) {
                    tileSizePreset = hudElement->tileSizePreset;
                    drawSizePreset = hudElement->drawSizePreset;
                    imageWidth = gHudElementSizes[tileSizePreset].width;
                    imageHeight = gHudElementSizes[tileSizePreset].height;
                    drawWidth = gHudElementSizes[drawSizePreset].width;
                    drawHeight = gHudElementSizes[drawSizePreset].height;
                } else {
                    imageWidth = hudElement->customImageSize.x;
                    imageHeight = hudElement->customImageSize.y;
                    drawWidth = hudElement->customDrawSize.x;
                    drawHeight = hudElement->customDrawSize.y;
                }

                if ((hudElement->flags & 0x200) == 0) {
                    hudElement->flags |= 0x200;
                    hudElement->unkImgScale[0] = imageWidth;
                    hudElement->unkImgScale[1] = imageHeight;
                    hudElement->unk_20 = ((f32)drawWidth - (f32)imageWidth) / (f32)hudElement->updateTimer;
                    hudElement->unk_24 = ((f32)drawHeight - (f32)imageHeight) / (f32)hudElement->updateTimer;
                } else {
                    hudElement->flags &= ~0x200;
                    hudElement->unkImgScale[0] = drawWidth;
                    hudElement->unkImgScale[1] = drawHeight;
                    hudElement->unk_20 = ((f32)imageWidth - (f32)drawWidth) / (f32)hudElement->updateTimer;
                    hudElement->unk_24 = ((f32)imageHeight - (f32)drawHeight) / (f32)hudElement->updateTimer;
                }
            }
            return FALSE;

        case HUD_ELEMENT_OP_Restart:
            hudElement->readPos = hudElement->ptrPropertyList;
            return TRUE;

        case HUD_ELEMENT_OP_Loop:
            hudElement->ptrPropertyList = nextPos;
            hudElement->readPos = nextPos;
            return TRUE;

        case HUD_ELEMENT_OP_RandomRestart:
            s1 = *nextPos++;
            s2 = *nextPos++;
            if (rand_int(s1) < s2) {
                hudElement->readPos = hudElement->ptrPropertyList;
            } else {
                hudElement->readPos = nextPos;
            }
            return TRUE;

        case HUD_ELEMENT_OP_SetTileSize:
            sizePreset = *nextPos++;
            hudElement->widthScale = X10(1);
            hudElement->heightScale = X10(1);
            hudElement->readPos = nextPos;
            hudElement->drawSizePreset = sizePreset;
            hudElement->tileSizePreset = sizePreset;
            hudElement->flags &= ~0x100;
            hudElement->flags &= ~0x800;
            return TRUE;

        case HUD_ELEMENT_OP_SetSizesAutoScale:
            tileSizePreset = *nextPos++;
            arg2 = *nextPos++;

            hudElement->readPos = nextPos;
            hudElement->tileSizePreset = tileSizePreset;
            hudElement->drawSizePreset = arg2;

            imageWidth = gHudElementSizes[tileSizePreset].width;
            imageHeight = gHudElementSizes[tileSizePreset].height;
            drawWidth = gHudElementSizes[arg2].width;
            drawHeight = gHudElementSizes[arg2].height;

            xScaled = (f32) drawWidth / (f32) imageWidth;
            yScaled = (f32) drawHeight / (f32) imageHeight;

            xScaled = 1.0f / xScaled;
            yScaled = 1.0f / yScaled;

            hudElement->widthScale = X10(xScaled);
            hudElement->heightScale = X10(yScaled);

            hudElement->flags &= ~0x100;
            hudElement->flags |= 0x800;
            return TRUE;

        case HUD_ELEMENT_OP_SetSizesFixedScale:
            tileSizePreset = *nextPos++;
            drawSizePreset = *nextPos++;

            hudElement->widthScale = X10(1);
            hudElement->heightScale = X10(1);
            hudElement->readPos = nextPos;
            hudElement->tileSizePreset = tileSizePreset;
            hudElement->drawSizePreset = drawSizePreset;
            hudElement->flags |= 0x100;
            hudElement->flags &= ~0x800;
            hudElement->flags &= ~0x200;
            return TRUE;

        case HUD_ELEMENT_OP_AddTexelOffsetX:
            s1 = *nextPos++;
            hudElement->readPos = nextPos;
            hudElement->screenPosOffset.x += s1;
            return TRUE;

        case HUD_ELEMENT_OP_AddTexelOffsetY:
            s2 = *nextPos++;
            if ((hudElement->flags & 0x2000) == 0) {
                hudElement->screenPosOffset.y += s2;
            } else {
                hudElement->screenPosOffset.y -= s2;
            }
            hudElement->readPos = nextPos;
            return TRUE;

        case HUD_ELEMENT_OP_AddTexelOffset:
            s1 = *nextPos++;
            s2 = *nextPos++;
            hudElement->screenPosOffset.x = s1;
            if ((hudElement->flags & 0x2000) == 0) {
                hudElement->screenPosOffset.y = s2;
            } else {
                hudElement->screenPosOffset.y = -s2;
            }
            hudElement->readPos = nextPos;
            return TRUE;

        case HUD_ELEMENT_OP_SetScale:
            uniformScale = (f32)*nextPos++;
            uniformScale /= 65536;
            hudElement->uniformScale = uniformScale;
            if ((hudElement->flags & 0x100000) == 0) {
                imageWidth = gHudElementSizes[hudElement->tileSizePreset].width;
                imageHeight = gHudElementSizes[hudElement->tileSizePreset].height;
                drawWidth = gHudElementSizes[hudElement->drawSizePreset].width;
                drawHeight = gHudElementSizes[hudElement->drawSizePreset].height;
            } else {
                imageWidth = hudElement->customImageSize.x;
                imageHeight = hudElement->customImageSize.y;
                drawWidth = hudElement->customDrawSize.x;
                drawHeight = hudElement->customDrawSize.y;
            }

            hudElement->sizeX = drawWidth * uniformScale;
            hudElement->sizeY = drawHeight * uniformScale;

            xScaled = (f32) drawWidth / (f32) imageWidth * uniformScale;
            yScaled = (f32) drawHeight / (f32) imageHeight * uniformScale;

            xScaled = 1.0f / xScaled;
            yScaled = 1.0f / yScaled;

            hudElement->widthScale = X10(xScaled);
            hudElement->heightScale = X10(yScaled);

            hudElement->readPos = nextPos;
            hudElement->flags &= ~0x100;
            hudElement->flags |= 0x800 | 0x10;
            return TRUE;

        case HUD_ELEMENT_OP_SetAlpha:
            s1 = *nextPos++;
            hudElement->opacity = s1;
            hudElement->flags |= 0x20;
            if (hudElement->opacity == 255) {
                hudElement->flags &= ~0x20;
            }
            hudElement->readPos = nextPos;
            return TRUE;

        case HUD_ELEMENT_OP_RandomDelay:
            s1 = *nextPos++;
            s2 = *nextPos++;
            hudElement->updateTimer = rand_int(s2 - s1) + s1;
            hudElement->readPos = nextPos;
            do {} while(0);
            return FALSE;

        case HUD_ELEMENT_OP_SetCustomSize:
            hudElement->customDrawSize.x = hudElement->customImageSize.x = *nextPos++;
            hudElement->customDrawSize.y = hudElement->customImageSize.y = *nextPos++;
            hudElement->readPos = nextPos;
            hudElement->widthScale = X10(1);
            hudElement->heightScale = X10(1);
            hudElement->drawSizePreset = 0;
            hudElement->tileSizePreset = 0;
            hudElement->flags &= ~0x100;
            hudElement->flags &= ~0x800;
            hudElement->flags |= 0x100000;
            return TRUE;

        case HUD_ELEMENT_OP_op_15:
            s1 = *nextPos++;
            hudElement->readPos = nextPos;
            hudElement->flags &= ~0x0F000000;
            hudElement->flags |= s1 << 24;
            return TRUE;

        case HUD_ELEMENT_OP_RandomBranch:
            s1 = *nextPos++;
            newReadPos = nextPos[rand_int(s1 - 1)];
            hudElement->readPos = newReadPos;
            load_hud_element(hudElement, newReadPos);
            return TRUE;

        case HUD_ELEMENT_OP_PlaySound:
            arg2 = *nextPos++;
            sfx_play_sound(arg2);
            hudElement->readPos = nextPos;
            return TRUE;

        case HUD_ELEMENT_OP_op_1B:
            arg1 = *nextPos++;
            arg2 = *nextPos++;
            hudElement->readPos = nextPos;
            if (hudElement->flags & 0x10000) {
                hudTransform->pivot.x = arg1;
                do {
                    hudTransform->pivot.y = arg2;
                } while (0);
            }
            return TRUE;

        case HUD_ELEMENT_OP_op_16:
            return FALSE;
    }

    return FALSE;
}

void render_hud_elements_backUI(void) {
    s32 i, count, j;
    s32 sortedElements[320];
    s32 el1, el2;
    s32 texSizeX, texSizeY;
    s32 drawSizeX, drawSizeY, offsetX, offsetY;
    HudElement* hudElement;

    D_80159180++;
    if (D_80159180 > 2) {
        D_80159180 = 0;
    }
    gSPDisplayList(gMasterGfxPos++, VIRTUAL_TO_PHYSICAL(D_8014F078));

    count = 0;
    for (i = 0; i < 320; i++) {
        hudElement = (*gHudElements)[i];
        if (hudElement != NULL) {
            s32 flags = hudElement->flags;
            if (flags != 0 && (flags & 2) == 0) {
                if ((flags & 0x50210080) == 0) {
                    if ((flags & 0x40) == 0 && hudElement->drawSizePreset >= 0) {
                        sortedElements[count++] = i;
                    }
                }
            }
        }
    }

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            el1 = sortedElements[i];
            el2 = sortedElements[j];
            if ((*gHudElements)[el1]->worldPosOffset.z < (*gHudElements)[el2]->worldPosOffset.z) {
                sortedElements[i] = el2;
                sortedElements[j] = el1;
            }
        }
    }

    for (i = 0; i < count; i++) {
        hudElement = (*gHudElements)[sortedElements[i]];

        if (hudElement->readPos == NULL) {
            break;
        }

        if ((hudElement->flags & 0x100) == 0) {
            if ((hudElement->flags & 0x100000) == 0) {
                texSizeX = gHudElementSizes[hudElement->tileSizePreset].width;
                texSizeY = gHudElementSizes[hudElement->tileSizePreset].height;
            } else {
                texSizeX = hudElement->customImageSize.x;
                texSizeY = hudElement->customImageSize.y;
            }

            if ((hudElement->flags & 0x10) == 0) {
                if ((hudElement->flags & 0x100000) == 0) {
                    drawSizeX = gHudElementSizes[hudElement->drawSizePreset].width;
                    drawSizeY = gHudElementSizes[hudElement->drawSizePreset].height;
                    offsetX = -drawSizeX / 2;
                    offsetY = -drawSizeY / 2;
                } else {
                    // TODO find better match
                    do {
                    drawSizeX = hudElement->customDrawSize.x;
                    drawSizeY = hudElement->customDrawSize.y;
                    offsetX = -drawSizeX / 2;
                    } while (0);
                    offsetY = -drawSizeY / 2;

                }
            } else {
                drawSizeX = hudElement->sizeX;
                drawSizeY = hudElement->sizeY;
                offsetX = -drawSizeX / 2;
                offsetY = -drawSizeY / 2;
            }

            if ((hudElement->flags & 0x800) == 0) {
                if ((hudElement->flags & 0x20000000) != 0) {
                    draw_rect_hud_element(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, TRUE, TRUE);
                }
                draw_rect_hud_element(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, TRUE, FALSE);
            } else {
                if ((hudElement->flags & 0x20000000) != 0) {
                    draw_rect_hud_element(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, TRUE);
                }
                draw_rect_hud_element(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, FALSE);
            }
        } else {
            f32 xScaled, yScaled;

            if ((hudElement->flags & 0x100000) == 0) {
                texSizeX = gHudElementSizes[hudElement->tileSizePreset].width;
                texSizeY = gHudElementSizes[hudElement->tileSizePreset].height;
            } else {
                texSizeX = hudElement->customImageSize.x;
                texSizeY = hudElement->customImageSize.y;
            }

            drawSizeX = hudElement->unkImgScale[0];
            drawSizeY = hudElement->unkImgScale[1];

            offsetX = -hudElement->unkImgScale[0] / 2;
            offsetY = -hudElement->unkImgScale[1] / 2;

            xScaled = (f32) drawSizeX / (f32) texSizeX;
            yScaled = (f32) drawSizeY / (f32) texSizeY;

            xScaled = 1.0f / xScaled;
            yScaled = 1.0f / yScaled;

            hudElement->widthScale = X10(xScaled);
            hudElement->heightScale = X10(yScaled);

            if ((hudElement->flags & 0x20000000) != 0) {
                draw_rect_hud_element(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, TRUE);
            }
            draw_rect_hud_element(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, FALSE);
        }
    }
}

void render_hud_elements_frontUI(void) {
    s32 i, count, j;
    s32 sortedElements[320];
    s32 el1, el2;
    s32 texSizeX, texSizeY;
    s32 drawSizeX, drawSizeY, offsetX, offsetY;
    HudElement* hudElement;

    gSPDisplayList(gMasterGfxPos++, VIRTUAL_TO_PHYSICAL(D_8014F0A0));

    count = 0;
    for (i = 0; i < 320; i++) {
        hudElement = (*gHudElements)[i];
        if (hudElement != NULL) {
            s32 flags = hudElement->flags;
            if (flags != 0 && (flags & 2) == 0) {
                if ((flags & 0x10210080) == 0) {
                    if ((flags & 0x40) != 0 && hudElement->drawSizePreset >= 0) {
                        sortedElements[count++] = i;
                    }
                }
            }
        }
    }

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            el1 = sortedElements[i];
            el2 = sortedElements[j];
            if ((*gHudElements)[el1]->worldPosOffset.z < (*gHudElements)[el2]->worldPosOffset.z) {
                sortedElements[i] = el2;
                sortedElements[j] = el1;
            }
        }
    }

    for (i = 0; i < count; i++) {
        hudElement = (*gHudElements)[sortedElements[i]];
        if ((hudElement->flags & 0x100) == 0) {
            if ((hudElement->flags & 0x100000) == 0) {
                texSizeX = gHudElementSizes[hudElement->tileSizePreset].width;
                texSizeY = gHudElementSizes[hudElement->tileSizePreset].height;
            } else {
                texSizeX = hudElement->customImageSize.x;
                texSizeY = hudElement->customImageSize.y;
            }

            if ((hudElement->flags & 0x10) == 0) {
                if ((hudElement->flags & 0x100000) == 0) {
                    drawSizeX = gHudElementSizes[hudElement->drawSizePreset].width;
                    drawSizeY = gHudElementSizes[hudElement->drawSizePreset].height;
                    offsetX = -drawSizeX / 2;
                    offsetY = -drawSizeY / 2;
                } else {
                    // TODO find better match
                    do {
                    drawSizeX = hudElement->customDrawSize.x;
                    drawSizeY = hudElement->customDrawSize.y;
                    offsetX = -drawSizeX / 2;
                    } while (0);
                    offsetY = -drawSizeY / 2;

                }
            } else {
                drawSizeX = hudElement->sizeX;
                drawSizeY = hudElement->sizeY;
                offsetX = -drawSizeX / 2;
                offsetY = -drawSizeY / 2;
            }

            if ((hudElement->flags & 0x800) == 0) {
                if ((hudElement->flags & 0x20000000) != 0) {
                    draw_rect_hud_element(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, TRUE, TRUE);
                }
                draw_rect_hud_element(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, TRUE, FALSE);
            } else {
                if ((hudElement->flags & 0x20000000) != 0) {
                    draw_rect_hud_element(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, TRUE);
                }
                draw_rect_hud_element(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, FALSE);
            }
        } else {
            f32 xScaled, yScaled;

            if ((hudElement->flags & 0x100000) == 0) {
                texSizeX = gHudElementSizes[hudElement->drawSizePreset].width;
                texSizeY = gHudElementSizes[hudElement->drawSizePreset].height;
            } else {
                texSizeX = hudElement->customImageSize.x;
                texSizeY = hudElement->customImageSize.y;
            }

            drawSizeX = hudElement->unkImgScale[0];
            drawSizeY = hudElement->unkImgScale[1];

            offsetX = -hudElement->unkImgScale[0] / 2;
            offsetY = -hudElement->unkImgScale[1] / 2;

            xScaled = (f32) drawSizeX / (f32) texSizeX;
            yScaled = (f32) drawSizeY / (f32) texSizeY;

            xScaled = 1.0f / xScaled;
            yScaled = 1.0f / yScaled;

            hudElement->widthScale = X10(xScaled);
            hudElement->heightScale = X10(yScaled);

            if ((hudElement->flags & 0x20000000) != 0) {
                draw_rect_hud_element(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, TRUE);
            }
            draw_rect_hud_element(hudElement, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, FALSE);
        }
    }
}

#ifdef NON_EQUIVALENT
void render_hud_element(HudElement* hudElement) {
    Matrix4f sp20;
    Matrix4f sp60;
    Matrix4f spA0;
    Matrix4f spE0;
    Matrix4f sp120;
    Matrix4f sp160;
    Matrix4f sp1A0;
    Matrix4f sp1E0;
    Matrix4f sp220;
    Matrix4f sp260;
    FoldImageRecPart sp2A0;
    f32 phi_f24, phi_f20;
    s32 height, width;
    HudTransform* transform;
    HudTransform *new_var;
    VtxRect* ums;
    s32 mode;
    u32 flags;
    u8* raster;
    u8* palette;
    u32 a0, v1;
    int nv2;
    s32 nv;
    s32 ulx, uly, lrx, lry;
    Vtx* vtx;

    if (hudElement->flags & 0x8000) {
        gDPSetTextureFilter(gMasterGfxPos++, G_TF_AVERAGE);
    } else {
        gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);
    }

    if ((hudElement->flags & 0x100) == 0) {
        phi_f24 = 1.0f;
        phi_f20 = 1.0f;
    } else {
        if ((hudElement->flags & 0x100000) == 0) {
            phi_f24 = gHudElementSizes[hudElement->tileSizePreset].width;
            phi_f20 = gHudElementSizes[hudElement->tileSizePreset].height;
        } else {
            phi_f24 = hudElement->customImageSize.x;
            phi_f20 = hudElement->customImageSize.y;
        }
        phi_f24 /= hudElement->unkImgScale[0];
        phi_f24 = 1.0f / phi_f24;
        phi_f20 /= hudElement->unkImgScale[1];
        phi_f20 = 1.0f / phi_f20;
    }

    if ((hudElement->flags & 0x100000) == 0) {
        width = gHudElementSizes[hudElement->tileSizePreset].width;
        height = gHudElementSizes[hudElement->tileSizePreset].height;
    } else {
        width = hudElement->customImageSize.x;
        height = hudElement->customImageSize.y;
    }

    transform = hudElement->hudTransform;

    guTranslateF(sp1E0, transform->pivot.x, -transform->pivot.y, 0.0f);
    guTranslateF(sp220, -transform->pivot.x, transform->pivot.y, 0.0f);
    guTranslateF(sp1A0, hudElement->renderPosX + hudElement->screenPosOffset.x + hudElement->worldPosOffset.x + transform->position.x,
                        -hudElement->renderPosY - hudElement->screenPosOffset.y + hudElement->worldPosOffset.y + transform->position.y,
                        - (hudElement->worldPosOffset.z / 10.0) + transform->position.z);
    guScaleF(sp260, hudElement->uniformScale * phi_f24 * transform->scale.x,
                    hudElement->uniformScale * phi_f20 * transform->scale.y,
                    transform->scale.z);
    guRotateF(sp120, transform->rotation.y, 0.0f, 1.0f, 0.0f);
    guRotateF(sp160, transform->rotation.z, 0.0f, 0.0f, 1.0f);
    nv = 0x4000;
    guRotateF(spE0, transform->rotation.x, 1.0f, 0.0f, 0.0f);
    guMtxCatF(sp160, spE0, sp20);
    guMtxCatF(sp20, sp120, spA0);
    guMtxCatF(sp260, sp1E0, sp20);
    guMtxCatF(sp20, spA0, sp60);
    guMtxCatF(sp60, sp220, sp20);
    new_var = transform;
    guMtxCatF(sp20, sp1A0, sp60);
    guMtxF2L(sp60, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    mode = 0;
    a0 = mode;
    a0 = (hudElement->flags & nv) > a0;
    v1 = mode < (hudElement->flags & 0x80000);

    if (a0 == TRUE) {
        mode = (v1 < 1);
    }
    if (a0 == FALSE) {
        if (v1 == TRUE) {
            mode = 2;
        }
    }

    if (a0 == TRUE) {
        if (v1 == a0) {
            mode = 2;
        }
    }

    switch (mode) {
        case 1:
            if ((hudElement->flags & 0x20000) != 0) {
                if ((hudElement->flags & 0x20) != 0) {
                    fold_update(0, 7, 255, 255, 255, hudElement->opacity, 0);
                } else {
                    fold_update(0, 0, 0, 0, 0, 0, 0);
                }
            } else {
                if ((hudElement->flags & 0x20) != 0) {
                    fold_update(transform->unk_00, 7, 255, 255, 255, hudElement->opacity, 0);
                } else {
                    fold_update(transform->unk_00, 0, 0, 0, 0, 0, 0);
                }
            }

            sp2A0.raster = hudElement->imageAddr;
            palette = hudElement->paletteAddr;
            sp2A0.xOffset = -width / 2;
            sp2A0.yOffset = height / 2;
            sp2A0.width = width;
            sp2A0.unk_10 = 255;
            sp2A0.height = height;
            sp2A0.palette = palette;

            if ((hudElement->flags & 0x20000) != 0) {
                if ((hudElement->flags & 0x800000) != 0) {
                    fold_appendGfx_component(0, &sp2A0, 0x40, sp60);
                } else {
                    fold_appendGfx_component(0, &sp2A0, 0x40, sp60);
                }
            } else {
                fold_appendGfx_component(transform->unk_00, &sp2A0, 0x40, sp60);
            }
            break;

        case 2:
            vtx = transform->unk_30[D_80159180].vtx;
            memcpy(&transform->unk_30[D_80159180].vtx[0], &D_8014F0C8[0], sizeof(Vtx));
            memcpy(&transform->unk_30[D_80159180].vtx[1], &D_8014F0C8[1], sizeof(Vtx));
            memcpy(&transform->unk_30[D_80159180].vtx[2], &D_8014F0C8[2], sizeof(Vtx));
            memcpy(&transform->unk_30[D_80159180].vtx[3], &D_8014F0C8[3], sizeof(Vtx));

            vtx[0].v.ob[0] = -width / 2;
            vtx[0].v.ob[1] = -height / 2;
            vtx[0].v.ob[2] = 0;
            vtx[0].v.tc[0] = 0;
            vtx[0].v.tc[1] = height * 32;

            vtx[1].v.ob[0] = width / 2 - 1;
            vtx[1].v.ob[1] = -height / 2;
            vtx[1].v.ob[2] = 0;
            vtx[1].v.tc[0] = width * 32;
            vtx[1].v.tc[1] = height * 32;

            vtx[2].v.ob[0] = width / 2 - 1;
            vtx[2].v.ob[1] = height / 2 - 1;
            vtx[2].v.ob[2] = 0;
            vtx[2].v.tc[0] = width * 32;
            vtx[2].v.tc[1] = 0;

            vtx[3].v.ob[0] = -width / 2;
            vtx[3].v.ob[1] = height / 2 - 1;
            vtx[3].v.ob[2] = 0;
            vtx[3].v.tc[0] = 0;
            vtx[3].v.tc[1] = 0;

            gDPPipeSync(gMasterGfxPos++);
            gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, 0, TEXEL0, 0, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, 0, TEXEL0, 0);
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, hudElement->tint.r, hudElement->tint.g, hudElement->tint.b, hudElement->opacity);

            if ((hudElement->flags & 0x20) == 0) {
                if ((hudElement->flags & 0x800000) == 0) {
                    gDPSetRenderMode(gMasterGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
                } else {
                    gDPSetRenderMode(gMasterGfxPos++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
                }
            } else {
                if ((hudElement->flags & 0x800000) == 0) {
                    gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
                } else {
                    gDPSetRenderMode(gMasterGfxPos++, AA_EN | G_RM_CLD_SURF, AA_EN | G_RM_CLD_SURF2);
                }
            }

            #define G_IM_SIZ_8b_SHIFTL (8)

            gDPLoadTextureBlock(gMasterGfxPos++, hudElement->imageAddr, G_IM_FMT_IA, G_IM_SIZ_8b , width, height, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
            gSPVertex(gMasterGfxPos++, &transform->unk_30[D_80159180], 4, 0);
            gSP1Triangle(gMasterGfxPos++, 0, 1, 2, 0);
            gSP1Triangle(gMasterGfxPos++, 0, 2, 3, 0);
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMasterGfxPos++);
}
#else
INCLUDE_ASM(void, "hud_element", render_hud_element, HudElement* hudElement);
#endif


void render_hud_elements_world(void) {
    s32 i, count, j;
    s32 sortedElements[320];
    s32 el1, el2;
    HudElement* hudElement;
    s16 newvar;

    // awful match
    do { do {
        count = 0;
        if (gCurrentCamID == CAM_CAM3) {
            for (i = 0; i < 320; i++) {
                hudElement = (*gHudElements)[i];
                if (hudElement != NULL) {
                    s32 flags = hudElement->flags;
                    if (flags != 0 && (flags & 2) == 0) {
                        if ((flags & 0x10200000) == 0) {
                            if ((flags & 0x10000) != 0) {
                                if ((flags & 0x40000000) == 0) {
                                    if ((flags & 0x40) == 0 && hudElement->drawSizePreset >= 0 && (flags & 0x80) == 0) {
                                        sortedElements[count++] = i;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if (count != 0) {
                for (i = 0; i < count - 1; i++) {
                    for (j = i + 1; j < count; j++) {
                        el1 = sortedElements[i];
                        el2 = sortedElements[j];
                        newvar = (*gHudElements)[el1]->worldPosOffset.z;
                        do {} while(0);
                        if (newvar < (*gHudElements)[el2]->worldPosOffset.z) {
                            sortedElements[i] = el2;
                            sortedElements[j] = el1;
                        }
                    }
                }

                gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 12, 20, 308, 220);
                gDPPipeSync(gMasterGfxPos++);
                gSPClearGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
                gSPSetGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
                gSPNumLights(gMasterGfxPos++, 1);
                gSPLight(gMasterGfxPos++, &D_8014F108.l, 1);
                gSPLight(gMasterGfxPos++, &D_8014F108.a, 2);
                gSPTexture(gMasterGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
                gDPSetAlphaCompare(gMasterGfxPos++, G_AC_NONE);
                gSPSetOtherMode(gMasterGfxPos++, G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18, G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_1CYCLE);

                for (i = 0; i < count; i++) {
                    render_hud_element((*gHudElements)[sortedElements[i]]);
                }
            }
        }
        count = 0;
        if (gCurrentCamID == CAM_BATTLE) {
            for (i = 0; i < 320; i++) {
                hudElement = (*gHudElements)[i];
                if (hudElement != NULL) {
                    s32 flags = hudElement->flags;
                    if (flags != 0 && (flags & 2) == 0) {
                        if ((flags & 0x10200000) == 0) {
                            if ((flags & 0x10000) != 0) {
                                if ((flags & 0x40000000) != 0) {
                                    if ((flags & 0x40) == 0 && hudElement->drawSizePreset >= 0 && (flags & 0x80) == 0) {
                                        sortedElements[count++] = i;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if (count != 0) {
                for (i = 0; i < count - 1; i++) {
                    for (j = i + 1; j < count; j++) {
                        el1 = sortedElements[i];
                        el2 = sortedElements[j];
                        newvar = (*gHudElements)[el1]->worldPosOffset.z;
                        do {} while(0);
                        if ((*gHudElements)[el1]->worldPosOffset.z < (*gHudElements)[el2]->worldPosOffset.z) {
                            sortedElements[i] = el2;
                            sortedElements[j] = el1;
                        }
                    }
                }

                gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 12, 20, 308, 220);
                gDPPipeSync(gMasterGfxPos++);
                gSPClearGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
                gSPSetGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
                gSPNumLights(gMasterGfxPos++, 1);
                gSPLight(gMasterGfxPos++, &D_8014F108.l, 1);
                gSPLight(gMasterGfxPos++, &D_8014F108.a, 2);
                gSPTexture(gMasterGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
                gDPSetAlphaCompare(gMasterGfxPos++, G_AC_NONE);
                gSPSetOtherMode(gMasterGfxPos++, G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18, G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_1CYCLE);

                for (i = 0; i < count; i++) {
                    render_hud_element((*gHudElements)[sortedElements[i]]);
                }
            }
        }
    } while (0); } while (0);
}

void func_80143C48(s32 elemID, s32 arg1, s32 camID) {
    Camera* camera = &gCameras[camID];

    if (arg1 > 0) {
        if (camera->flags == 0 || (camera->flags & 2)) {
            return;
        }

        gCurrentCamID = camID;

        gSPViewport(gMasterGfxPos++, &camera->vp);
        gSPClearGeometryMode(gMasterGfxPos++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                                G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
        gSPTexture(gMasterGfxPos++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
        gDPPipelineMode(gMasterGfxPos++, G_PM_NPRIMITIVE);
        gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
        gDPSetTextureFilter(gMasterGfxPos++, G_TF_BILERP);
        gDPSetCombineMode(gMasterGfxPos++, G_CC_SHADE, G_CC_SHADE);
        gDPSetRenderMode(gMasterGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gSPClipRatio(gMasterGfxPos++, FRUSTRATIO_2);
        gDPPipeSync(gMasterGfxPos++);
        gDPSetCycleType(gMasterGfxPos++, G_CYC_FILL);
        gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxZBuffer));
        gDPSetFillColor(gMasterGfxPos++, 0xFFFCFFFC);
        gDPFillRectangle(gMasterGfxPos++, camera->viewportStartX, camera->viewportStartY,
                         camera->viewportStartX + camera->viewportW - 1,
                         camera->viewportStartY + camera->viewportH - 1);
        gDPPipeSync(gMasterGfxPos++);
        gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));
        gDPPipeSync(gMasterGfxPos++);

        guOrthoF(camera->perspectiveMatrix, 0.0f, 320.0f, -240.0f, 0.0f, -1000.0f, 1000.0f, 1.0f);
        guMtxF2L(camera->perspectiveMatrix, &gDisplayContext->camPerspMatrix[gCurrentCamID]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCamID], G_MTX_NOPUSH | G_MTX_LOAD |
                                                                                    G_MTX_PROJECTION);
        gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 12, 20, 308, 220);
        gDPPipeSync(gMasterGfxPos++);
        gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
        gSPClearGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                                G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
        gSPSetGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
        gSPSetLights1(gMasterGfxPos++, D_8014F108);
        gSPTexture(gMasterGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
        gDPSetTextureLOD(gMasterGfxPos++, G_TL_TILE);
        gDPSetTexturePersp(gMasterGfxPos++, G_TP_PERSP);
        gDPSetColorDither(gMasterGfxPos++, G_CD_DISABLE);
        gDPSetTextureDetail(gMasterGfxPos++, G_TD_CLAMP);
        gDPSetTextureConvert(gMasterGfxPos++, G_TC_FILT);
        gDPSetCombineKey(gMasterGfxPos++, G_CK_NONE);
        gDPSetAlphaCompare(gMasterGfxPos++, G_AC_NONE);
    }

    if (elemID >= 0) {
        HudElement* elem;

        elemID &= ~0x800;
        elem = (*gHudElements)[elemID];

        if (elem != NULL) {
            if (elem->flags != 0 && !(elem->flags & 2)) {
                if (!(elem->flags & 0x10200000)) {
                    if (elem->flags & 0x10000) {
                        if (!(elem->flags & 0x40) && (elem->drawSizePreset >= 0) && (elem->flags & 0x80)) {
                            render_hud_element(elem);
                        }
                    }
                }
            }
        }
    }
}

void func_80144218(s32 arg0) {
    func_80143C48(arg0, 1, CAM_CAM3);
}

void func_80144238(s32 arg0) {
    func_80143C48(arg0, 0, CAM_CAM3);
}

void func_80144258(s32 arg0) {
    func_80143C48(arg0, 1, CAM_BATTLE);
}

void func_80144278(s32 arg0) {
    func_80143C48(arg0, 0, CAM_BATTLE);
}

void draw_hud_element(s32 id, s32 clipMode) {
    HudElement* elem = (*gHudElements)[id & ~0x800];
    s32 texSizeX, texSizeY;
    s32 drawSizeX, drawSizeY;
    s32 offsetX, offsetY;
    s32 preset;

    if ((elem->flags != 0) && !(elem->flags & 2)) {
        if (!(elem->flags & 0x10200000) && (elem->drawSizePreset >= 0)) {
            if (clipMode != 1) {
                if (clipMode == 0) {
                    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 12, 20, 308, 220);
                }
                gDPPipeSync(gMasterGfxPos++);
                gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
                gDPSetTexturePersp(gMasterGfxPos++, G_TP_NONE);
                gDPSetTextureLOD(gMasterGfxPos++, G_TL_TILE);
                gDPSetTextureDetail(gMasterGfxPos++, G_TD_CLAMP);
                gDPSetTextureConvert(gMasterGfxPos++, G_TC_FILT);
                gDPSetCombineKey(gMasterGfxPos++, G_CK_NONE);
                gDPSetAlphaCompare(gMasterGfxPos++, G_AC_NONE);
                gDPNoOp(gMasterGfxPos++);
                gDPSetColorDither(gMasterGfxPos++, G_CD_DISABLE);
                gDPSetAlphaDither(gMasterGfxPos++, G_AD_DISABLE);
                gSPTexture(gMasterGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
            }

            if (!(elem->flags & 0x100)) {
                if (!(elem->flags & 0x100000)) {
                    preset = elem->tileSizePreset;
                    texSizeX = gHudElementSizes[preset].width;
                    texSizeY = gHudElementSizes[preset].height;
                } else {
                    texSizeX = elem->customImageSize.x;
                    texSizeY = elem->customImageSize.y;
                }

                if (!(elem->flags & 0x10)) {
                    if (!(elem->flags & 0x100000)) {
                        drawSizeX = gHudElementSizes[elem->drawSizePreset].width;
                        drawSizeY = gHudElementSizes[elem->drawSizePreset].height;
                    } else {
                        drawSizeX = elem->customDrawSize.x;
                        drawSizeY = elem->customDrawSize.y;
                    }
                } else {
                    drawSizeX = elem->sizeX;
                    drawSizeY = elem->sizeY;
                }

                do {
                    offsetX = -drawSizeX / 2;
                    offsetY = -drawSizeY / 2;
                } while (0); // TODO required to match

                if (!(elem->flags & 0x800)) {
                    if (elem->flags & 0x20000000) {
                        draw_rect_hud_element(elem, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, TRUE, TRUE);
                    }
                    draw_rect_hud_element(elem, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, TRUE, FALSE);
                } else {
                    if (elem->flags & 0x20000000) {
                        draw_rect_hud_element(elem, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, TRUE);
                    }
                    draw_rect_hud_element(elem, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, FALSE);
                }
            } else {
                f32 xScaled, yScaled;

                if (!(elem->flags & 0x100000)) {
                    preset = elem->tileSizePreset;
                    texSizeX = gHudElementSizes[preset].width;
                    texSizeY = gHudElementSizes[preset].height;
                } else {
                    texSizeX = elem->customImageSize.x;
                    texSizeY = elem->customImageSize.y;
                }

                drawSizeX = elem->unkImgScale[0];
                drawSizeY = elem->unkImgScale[1];

                offsetX = -elem->unkImgScale[0] / 2;
                offsetY = -elem->unkImgScale[1] / 2;

                xScaled = (f32) drawSizeX / (f32) texSizeX;
                yScaled = (f32) drawSizeY / (f32) texSizeY;

                xScaled = 1.0f / xScaled;
                yScaled = 1.0f / yScaled;

                elem->widthScale = X10(xScaled);
                elem->heightScale = X10(yScaled);

                if (elem->flags & 0x20000000) {
                    draw_rect_hud_element(elem, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, TRUE);
                }
                draw_rect_hud_element(elem, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, FALSE);
            }
        }
    }
}

void draw_hud_element_clipped(s32 id) {
    draw_hud_element(id, 0);
}

void draw_hud_element_2(s32 id) {
    draw_hud_element(id, 1);
}

void draw_hud_element_3(s32 id) {
    draw_hud_element(id, 2);
}

void set_hud_element_anim(s32 id, const HudScript* anim) {
    HudElement* hudElement = (*gHudElements)[id & ~0x800];

    if (anim == NULL) {
        anim = &hud_element_defaultAnim;
    }

    hudElement->updateTimer = 1;
    hudElement->widthScale = 1024;
    hudElement->heightScale = 1024;
    hudElement->readPos = anim;
    hudElement->anim = anim;
    hudElement->ptrPropertyList = (s32*)anim;
    hudElement->screenPosOffset.x = 0;
    hudElement->screenPosOffset.y = 0;
    hudElement->worldPosOffset.x = 0;
    hudElement->worldPosOffset.y = 0;
    hudElement->flags &= ~4;
    hudElement->uniformScale = 1.0f;
    hudElement->flags &= ~0x930;
    load_hud_element(hudElement, anim);

    while (hud_element_update(hudElement) != 0) {}
}

HudScript* get_hud_element_anim(s32 id) {
    return (*gHudElements)[id & ~0x800]->anim;
}

HudElement* get_hud_element(s32 id) {
    return (*gHudElements)[id & ~0x800];
}

void free_hud_element(s32 id) {
    if ((*gHudElements)[id & ~0x800]->flags & 0x10000) {
        free_hud_element_transform(id & ~0x800);
    }

    heap_free((*gHudElements)[id & ~0x800]);
    (*gHudElements)[id & ~0x800] = NULL;
    D_801512B4--;
}

void set_hud_element_render_pos(s32 id, s32 x, s32 y) {
    HudElement* hudElement = (*gHudElements)[id & ~0x800];

    hudElement->renderPosX = x;
    hudElement->renderPosY = y;
}

void get_hud_element_render_pos(s32 id, s32* x, s32* y) {
    HudElement* hudElement = (*gHudElements)[id & ~0x800];

    *x = hudElement->renderPosX;
    *y = hudElement->renderPosY;
}

void set_hud_element_render_depth(s32 id, s32 z) {
    (*gHudElements)[id & ~0x800]->worldPosOffset.z = z;
}

void set_hud_element_flags(s32 id, s32 flags) {
    (*gHudElements)[id & ~0x800]->flags |= flags;
}

void clear_hud_element_flags(s32 id, s32 flags) {
    (*gHudElements)[id & ~0x800]->flags &= ~flags;
}

void ALT_clear_hud_element_cache(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        heap_free(D_80151314);
        D_80151314 = heap_malloc(D_8014EFC4);
        ASSERT(D_80151314);
        D_80157964 = D_80151314;
        *D_8015133C = 0;
        D_8015133C = &D_80157968;
        D_801512C8 = &D_80157970;
        D_801512D0 = &D_80157F70;
        D_80151314 = D_80157964;

        for (i = 0; i < 192; i++) {
            D_80157970[i].unk_00 = -1;
            D_80157F70[i].unk_00 = -1;
        }
    } else {
        if (D_8014EFC0 == 0) {
            heap_free(D_80151314);
            D_80151314 = heap_malloc(D_8014EFC4 / 2);
            ASSERT(D_80151314);
        } else {
            D_80151314 = D_8014EFC0;
        }
        D_80158570 = D_80151314;
        *D_8015133C = 0;
        D_8015133C = &D_80158574;
        D_801512C8 = &D_80158580;
        D_801512D0 = &D_80158B80;
        D_80151314 = D_80158570;

        for (i = 0; i < 192; i++) {
            D_80158580[i].unk_00 = -1;
            D_80158B80[i].unk_00 = -1;
        }
    }
}

void set_hud_element_scale(s32 index, f32 scale) {
    HudElement* elem = (*gHudElements)[index & ~0x800];
    s32 drawSizeX;
    s32 drawSizeY;
    s32 imgSizeX;
    s32 imgSizeY;
    f32 xScaled, yScaled;

    elem->uniformScale = scale;
    if (!(elem->flags & 0x100000)) {
        imgSizeX = gHudElementSizes[elem->tileSizePreset].width;
        imgSizeY = gHudElementSizes[elem->tileSizePreset].height;
        drawSizeX = gHudElementSizes[elem->drawSizePreset].width;
        drawSizeY = gHudElementSizes[elem->drawSizePreset].height;
    } else {
        imgSizeX = elem->customImageSize.x;
        imgSizeY = elem->customImageSize.y;
        drawSizeX = elem->customDrawSize.x;
        drawSizeY = elem->customDrawSize.y;
    }
    elem->sizeX = drawSizeX * scale;
    elem->sizeY = drawSizeY * scale;
    elem->flags &= ~0x100;
    elem->flags |= 0x800 | 0x10;

    xScaled = ((f32) drawSizeX / (f32) imgSizeX) * scale;
    yScaled = ((f32) drawSizeY / (f32) imgSizeY) * scale;

    xScaled = 1.0f / xScaled;
    yScaled = 1.0f / yScaled;

    elem->widthScale = X10(xScaled);
    elem->heightScale = X10(yScaled);
}

void set_hud_element_size(s32 id, s8 size) {
    HudElement* hudElement = (*gHudElements)[id & ~0x800];

    hudElement->widthScale = 1024;
    hudElement->heightScale = 1024;
    hudElement->tileSizePreset = size;
    hudElement->drawSizePreset = size;
    hudElement->uniformScale = 1.0f;
    hudElement->flags &= ~0x100;
    hudElement->flags &= ~0x810;
}

s32 func_80144E4C(s32 id) {
    return ((*gHudElements)[id & ~0x800]->flags >> 24) & 0xF;
}

void func_80144E74(s32 id, s32 arg1) {
    HudElement* hudElement = (*gHudElements)[id & ~0x800];

    hudElement->flags &= ~0xF000000;
    hudElement->flags |= arg1 << 24;
}

void set_hud_element_alpha(s32 id, s32 opacity) {
    HudElement* hudElement = (*gHudElements)[id & ~0x800];

    hudElement->flags |= 0x20;
    hudElement->opacity = opacity;

    if (opacity == 255) {
        hudElement->flags &= ~0x20;
    }
}

void set_hud_element_tint(s32 id, s32 r, s32 g, s32 b) {
    HudElement* hudElement = (*gHudElements)[id & ~0x800];

    hudElement->tint.r = r;
    hudElement->tint.g = g;
    hudElement->tint.b = b;
}

void create_hud_element_transform_A(s32 id) {
    HudElement* element = (*gHudElements)[id & ~0x800];
    HudTransform* transform = general_heap_malloc(sizeof(HudTransform));

    element->hudTransform = transform;
    ASSERT(transform != NULL);
    element->flags |= 0x10000;
    transform->unk_00 = func_8013A704(1);
    transform->position.x = 0.0f;
    transform->position.y = 0.0f;
    transform->position.z = 0.0f;
    transform->rotation.x = 0.0f;
    transform->rotation.y = 0.0f;
    transform->rotation.z = 0.0f;
    transform->scale.x = 1.0f;
    transform->scale.y = 1.0f;
    transform->scale.z = 1.0f;
    transform->pivot.x = 0;
    transform->pivot.y = 0;
    func_801413F8();
}

void create_hud_element_transform_B(s32 id) {
    HudElement* element = (*gHudElements)[id & ~0x800];
    HudTransform* transform = general_heap_malloc(sizeof(HudTransform));

    element->hudTransform = transform;
    ASSERT(transform != NULL);
    element->flags |= 0x30000;
    transform->unk_00 = 0;
    transform->position.x = 0.0f;
    transform->position.y = 0.0f;
    transform->position.z = 0.0f;
    transform->rotation.x = 0.0f;
    transform->rotation.y = 0.0f;
    transform->rotation.z = 0.0f;
    transform->scale.x = 1.0f;
    transform->scale.y = 1.0f;
    transform->scale.z = 1.0f;
    func_801413F8();
}

void create_hud_element_transform_C(s32 id) {
    HudElement* element = (*gHudElements)[id & ~0x800];
    HudTransform* transform = general_heap_malloc(sizeof(HudTransform));

    element->hudTransform = transform;
    ASSERT(transform != NULL);
    element->flags |= 0x40030000;
    transform->unk_00 = 0;
    transform->position.x = 0.0f;
    transform->position.y = 0.0f;
    transform->position.z = 0.0f;
    transform->rotation.x = 0.0f;
    transform->rotation.y = 0.0f;
    transform->rotation.z = 0.0f;
    transform->scale.x = 1.0f;
    transform->scale.y = 1.0f;
    transform->scale.z = 1.0f;
    func_801413F8();
}

void free_hud_element_transform(s32 id) {
    HudElement* hudElement = (*gHudElements)[id & ~0x800];
    HudTransform* hudTransform = hudElement->hudTransform;

    if (!(hudElement->flags & 0x20000)) {
        func_8013A854(hudTransform->unk_00);
    }

    heap_free(hudElement->hudTransform);
    hudElement->hudTransform = NULL;
    hudElement->flags &= ~(0x40000000 | 0x20000 | 0x10000);
}

void set_hud_element_transform_pos(s32 id, f32 x, f32 y, f32 z) {
    HudElement* element = (*gHudElements)[id & ~0x800];
    HudTransform* transform = element->hudTransform;

    if (element->flags & 0x10000) {
        transform->position.x = x;
        transform->position.y = y;
        transform->position.z = z;
    }
}

void set_hud_element_transform_scale(s32 id, f32 x, f32 y, f32 z) {
    HudElement* element = (*gHudElements)[id & ~0x800];
    HudTransform* transform = element->hudTransform;

    if (element->flags & 0x10000) {
        transform->scale.x = x;
        transform->scale.y = y;
        transform->scale.z = z;
    }
}

void set_hud_element_transform_rotation(s32 id, f32 x, f32 y, f32 z) {
    HudElement* element = (*gHudElements)[id & ~0x800];
    HudTransform* transform = element->hudTransform;

    if (element->flags & 0x10000) {
        transform->rotation.x = x;
        transform->rotation.y = y;
        transform->rotation.z = z;
    }
}

void set_hud_element_transform_rotation_pivot(s32 id, s32 dx, s32 dy) {
    HudElement* element = (*gHudElements)[id & ~0x800];
    HudTransform* transform = element->hudTransform;

    if (element->flags & 0x10000) {
        transform->pivot.x = dx;
        transform->pivot.y = dy;
    }
}

void copy_world_hud_element_ref_to_battle(s32 worldID, s32 battleID) {
    D_80157460[battleID & ~0x800] = D_80156F60[worldID & ~0x800];
}

void set_hud_element_nonworld_cache(void* base, s32 size) {
    D_8014EFC0 = (s32)base;
    if (base == NULL) {
        D_8014EFC4 = 0x11000;
    } else {
        D_8014EFC4 = size;
    }
}
