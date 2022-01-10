#include "common.h"
#include "hud_element.h"
#include "nu/nusys.h"

extern HudElementList* gHudElements;

s32 D_8014EFC0[] = { 0x00000000, };
s32 D_8014EFC4[] = { 0x00011000, };

HudElementAnim hud_element_defaultAnim = {
    he_End,
};

Vec3s gHudElementSizes[26] = {
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

s32 D_8014F062[] = {
    0x00220020, 0x00000028, 0x002803C8, 0x00000000, 0xED000000, 0x005003C0, 0xE7000000,
    0x00000000, 0xE3000A11, 0x00002CF0, 0xE2001E01, 0x00000000, 0xDF000000, 0x00000000, 0xED000000, 0x005003C0,
    0xE7000000, 0x00000000, 0xE3000A11, 0x00002CF0, 0xE2001E01, 0x00000000, 0xDF000000, 0x00000000,
};

s32 D_8014F0C8[] = {
    0xFFF40000, 0x00000000, 0x08000800, 0x000000FF, 0x00330000, 0x00000000, 0x00000800, 0x000000FF,
    0x0033003F, 0x00000000, 0x00000000, 0x000000FF, 0xFFF4003F, 0x00000000, 0x08000000, 0x000000FF,
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
extern void* D_8015133C;
extern void* D_80157968;
extern void* D_801512C8;
extern void* D_80157970;
extern void* D_801512D0;
extern void* D_80157F70;
extern void* D_80158574;
extern void* D_80158580;
extern void* D_80158B80;
extern s32* D_80157964;
extern s32* D_80158570;
extern s32* D_80151314;

INCLUDE_ASM(void, "hud_element", load_hud_element, HudElement* hudElement, const HudElementAnim* anim);

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
)

INCLUDE_ASM(void, "hud_element", clear_hud_element_cache, void);

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
    gCameras[3].updateMode = 2;
    gCameras[3].unk_06 = 1;
    gCameras[3].unk_20 = 0x3CBF;
    gCameras[3].nearClip = 0x10;
    gCameras[3].unk_1C = 0;
    gCameras[3].unk_1E = 0;
    gCameras[3].unk_22 = 0;
    gCameras[3].unk_5C = 0;
    gCameras[3].farClip = 0x4000;
    gCameras[3].bgColor[0] = 0;
    gCameras[3].bgColor[1] = 0;
    gCameras[3].bgColor[2] = 0;
    gCameras[3].unk_54 = 160.0f;
    gCameras[3].unk_58 = -120.0f;
    gCameras[3].vfov = 1.0f;
    gCameras[3].flags &= ~0x6;
}

s32 create_hud_element(const HudElementAnim* anim) {
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

    hudElement->flags.as_word = 1;
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
        hudElement->flags.as_word |= 0x400;
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

        if (elem != NULL && (elem->flags.as_word != 0) && !(elem->flags.as_word & 2)) {
            if (elem->flags.as_word & 0x40000) {
                free_hud_element(i);
                i++;
            } else if (elem->readPos != 0) {
                elem->updateTimer--;
                if (elem->updateTimer == 0) {
                    while (hud_element_update(elem) != 0);
                }
                if (elem->flags.as_word & 0x100) {
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

INCLUDE_ASM(s32, "hud_element", hud_element_update, HudElement* hudElement);

INCLUDE_ASM(void, "hud_element", render_hud_elements_backUI, void);

INCLUDE_ASM(void, "hud_element", render_hud_elements_frontUI, void);

INCLUDE_ASM(void, "hud_element", render_hud_element, HudElement* hudElement);

INCLUDE_ASM(void, "hud_element", render_hud_elements_world, void);

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
            if (elem->flags.as_word != 0 && !(elem->flags.as_word & 2)) {
                if (!(elem->flags.as_word & 0x10200000)) {
                    if (elem->flags.as_word & 0x10000) {
                        if (!(elem->flags.as_word & 0x40) && (elem->drawSizePreset >= 0) && (elem->flags.as_word & 0x80)) {
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

    if ((elem->flags.as_word != 0) && !(elem->flags.as_word & 2)) {
        if (!(elem->flags.as_word & 0x10200000) && (elem->drawSizePreset >= 0)) {
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

            if (!(elem->flags.as_word & 0x100)) {
                if (!(elem->flags.as_word & 0x100000)) {
                    preset = elem->tileSizePreset;
                    texSizeX = gHudElementSizes[preset].x;
                    texSizeY = gHudElementSizes[preset].y;
                } else {
                    texSizeX = elem->customImageSize.x;
                    texSizeY = elem->customImageSize.y;
                }

                if (!(elem->flags.as_word & 0x10)) {
                    if (!(elem->flags.as_word & 0x100000)) {
                        drawSizeX = gHudElementSizes[elem->drawSizePreset].x;
                        drawSizeY = gHudElementSizes[elem->drawSizePreset].y;
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

                if (!(elem->flags.as_word & 0x800)) {
                    if (elem->flags.as_word & 0x20000000) {
                        draw_rect_hud_element(elem, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, TRUE, TRUE);
                    }
                    draw_rect_hud_element(elem, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, TRUE, FALSE);
                } else {
                    if (elem->flags.as_word & 0x20000000) {
                        draw_rect_hud_element(elem, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, TRUE);
                    }
                    draw_rect_hud_element(elem, texSizeX, texSizeY, drawSizeX, drawSizeY, offsetX, offsetY, FALSE, FALSE);
                }
            } else {
                f32 xScaled, yScaled;

                if (!(elem->flags.as_word & 0x100000)) {
                    preset = elem->tileSizePreset;
                    texSizeX = gHudElementSizes[preset].x;
                    texSizeY = gHudElementSizes[preset].y;
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

                if (elem->flags.as_word & 0x20000000) {
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

void set_hud_element_anim(s32 id, const HudElementAnim* anim) {
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
    hudElement->flags.as_word &= ~4;
    hudElement->uniformScale = 1.0f;
    hudElement->flags.as_word &= ~0x930;
    load_hud_element(hudElement, anim);

    while (hud_element_update(hudElement) != 0) {}
}

HudElementAnim* get_hud_element_anim(s32 id) {
    return (*gHudElements)[id & ~0x800]->anim;
}

HudElement* get_hud_element(s32 id) {
    return (*gHudElements)[id & ~0x800];
}

void free_hud_element(s32 id) {
    if ((*gHudElements)[id & ~0x800]->flags.as_word & 0x10000) {
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
    (*gHudElements)[id & ~0x800]->flags.as_word |= flags;
}

void clear_hud_element_flags(s32 id, s32 flags) {
    (*gHudElements)[id & ~0x800]->flags.as_word &= ~flags;
}

INCLUDE_ASM(void, "hud_element", ALT_clear_hud_element_cache, void);

void set_hud_element_scale(s32 index, f32 scale) {
    HudElement* elem = (*gHudElements)[index & ~0x800];
    s32 drawSizeX;
    s32 drawSizeY;
    s32 imgSizeX;
    s32 imgSizeY;
    f32 xScaled, yScaled;

    elem->uniformScale = scale;
    if (!(elem->flags.as_word & 0x100000)) {
        imgSizeX = gHudElementSizes[elem->tileSizePreset].x;
        imgSizeY = gHudElementSizes[elem->tileSizePreset].y;
        drawSizeX = gHudElementSizes[elem->drawSizePreset].x;
        drawSizeY = gHudElementSizes[elem->drawSizePreset].y;
    } else {
        imgSizeX = elem->customImageSize.x;
        imgSizeY = elem->customImageSize.y;
        drawSizeX = elem->customDrawSize.x;
        drawSizeY = elem->customDrawSize.y;
    }
    elem->sizeX = drawSizeX * scale;
    elem->sizeY = drawSizeY * scale;
    elem->flags.as_word &= ~0x100;
    elem->flags.as_word |= 0x800 | 0x10;

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
    hudElement->flags.as_word &= ~0x100;
    hudElement->flags.as_word &= ~0x810;
}

s32 func_80144E4C(s32 id) {
    return (*gHudElements)[id & ~0x800]->flags.as_bitfields.f4;
}

void func_80144E74(s32 id, s32 arg1) {
    HudElement* hudElement = (*gHudElements)[id & ~0x800];

    hudElement->flags.as_word &= ~0xF000000;
    hudElement->flags.as_word |= arg1 << 24;
}

void set_hud_element_alpha(s32 id, s32 opacity) {
    HudElement* hudElement = (*gHudElements)[id & ~0x800];

    hudElement->flags.as_word |= 0x20;
    hudElement->opacity = opacity;

    if (opacity == 255) {
        hudElement->flags.as_word &= ~0x20;
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
    HudTransform* transform = general_heap_malloc(sizeof(*transform));

    element->hudTransform = transform;
    ASSERT(transform != NULL);
    element->flags.as_word |= 0x10000;
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
    HudTransform* transform = general_heap_malloc(sizeof(*transform));

    element->hudTransform = transform;
    ASSERT(transform != NULL);
    element->flags.as_word |= 0x30000;
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
    HudTransform* transform = general_heap_malloc(sizeof(*transform));

    element->hudTransform = transform;
    ASSERT(transform != NULL);
    element->flags.as_word |= 0x40030000;
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

    if (!(hudElement->flags.as_word & 0x20000)) {
        func_8013A854(hudTransform->unk_00);
    }

    heap_free(hudElement->hudTransform);
    hudElement->hudTransform = NULL;
    hudElement->flags.as_word &= ~(0x40000000 | 0x20000 | 0x10000);
}

void set_hud_element_transform_pos(s32 id, f32 x, f32 y, f32 z) {
    HudElement* element = (*gHudElements)[id & ~0x800];
    HudTransform* transform = element->hudTransform;

    if (element->flags.as_word & 0x10000) {
        transform->position.x = x;
        transform->position.y = y;
        transform->position.z = z;
    }
}

void set_hud_element_transform_scale(s32 id, f32 x, f32 y, f32 z) {
    HudElement* element = (*gHudElements)[id & ~0x800];
    HudTransform* transform = element->hudTransform;

    if (element->flags.as_word & 0x10000) {
        transform->scale.x = x;
        transform->scale.y = y;
        transform->scale.z = z;
    }
}

void set_hud_element_transform_rotation(s32 id, f32 x, f32 y, f32 z) {
    HudElement* element = (*gHudElements)[id & ~0x800];
    HudTransform* transform = element->hudTransform;

    if (element->flags.as_word & 0x10000) {
        transform->rotation.x = x;
        transform->rotation.y = y;
        transform->rotation.z = z;
    }
}

void set_hud_element_transform_rotation_pivot(s32 id, s32 dx, s32 dy) {
    HudElement* element = (*gHudElements)[id & ~0x800];
    HudTransform* transform = element->hudTransform;

    if (element->flags.as_word & 0x10000) {
        transform->pivot.x = dx;
        transform->pivot.y = dy;
    }
}

void copy_world_hud_element_ref_to_battle(s32 worldID, s32 battleID) {
    D_80157460[battleID & ~0x800] = D_80156F60[worldID & ~0x800];
}

void set_hud_element_nonworld_cache(void* base, s32 size) {
    D_8014EFC0[0] = (s32)base;
    if (base == NULL) {
        D_8014EFC4[0] = 0x11000;
    } else {
        D_8014EFC4[0] = size;
    }
}
