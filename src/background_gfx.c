#include "common.h"
#include "nu/nusys.h"
#include "ld_addrs.h"
#include "hud_element.h"
#include "sprite.h"
#include "overlay.h"

extern s32 gPauseBackgroundFade;

Vp D_80074200 = {
    .vp = {
        .vscale = {640, 480, 511, 0},
        .vtrans = {640, 480, 511, 0},
    }
};

Gfx D_80074210[] = {
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetColorDither(G_CD_BAYER),
    gsSPEndDisplayList(),
};

Gfx D_80074230[] = {
    gsSPViewport(&D_80074200),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPEndDisplayList(),
};

//extern s32 timeFreezeMode; // TODO bss

void gfx_init_state(void) {
    gSPSegment(gMainGfxPos++, 0x00, 0x0);
    gSPDisplayList(gMainGfxPos++, OS_K0_TO_PHYSICAL(D_80074230));
    gSPDisplayList(gMainGfxPos++, OS_K0_TO_PHYSICAL(D_80074210));
}

s32 gfx_frame_filter_pass_0(const u16* frameBuffer0, const u16* frameBuffer1, s32 y, s32 x, Color_RGBA8* out) {
    s32 pixel = SCREEN_WIDTH * y + x;

    out->a = (frameBuffer1[pixel] >> 2) & 0xF;
    out->r = UNPACK_PAL_R(frameBuffer0[pixel]);
    out->g = UNPACK_PAL_G(frameBuffer0[pixel]);
    out->b = UNPACK_PAL_B(frameBuffer0[pixel]);
}

void gfx_frame_filter_pass_1(Color_RGBA8* filterBuf0, Color_RGBA8 filterBuf1, u16* out) {
    Color_RGBA8 sp0;
    Color_RGBA8 sp8;
    Color_RGBA8 final;
    u8 rs[0x20];
    u8 gs[0x20];
    u8 bs[0x20];
    s32 i;

    sp8 = filterBuf1;
    sp0 = filterBuf1;

    for (i = 0; i < ARRAY_COUNT(rs); i++) {
        rs[i] = 0;
        gs[i] = 0;
        bs[i] = 0;
    }

    for (i = 0; i < 6; i++) {
        if (filterBuf0[i].a == 8) {
            rs[filterBuf0[i].r]++;
            gs[filterBuf0[i].g]++;
            bs[filterBuf0[i].b]++;
        }
    }

    for (i = 0; i < ARRAY_COUNT(rs); i++) {
        if (rs[i] != 0) {
            rs[i]--;
            break;
        }
    }
    for (; i < ARRAY_COUNT(rs); i++) {
        if (rs[i] != 0) {
            break;
        }
    }
    if (sp0.r > i) {
        sp0.r = i;
    }

    for (i = 0; i < ARRAY_COUNT(gs); i++) {
        if (gs[i] != 0) {
            gs[i]--;
            break;
        }
    }
    for (; i < ARRAY_COUNT(gs); i++) {
        if (gs[i] != 0) {
            break;
        }
    }
    if (sp0.g > i) {
        sp0.g = i;
    }

    for (i = 0; i < ARRAY_COUNT(bs); i++) {
        if (bs[i] != 0) {
            bs[i]--;
            break;
        }
    }
    for (; i < ARRAY_COUNT(bs); i++) {
        if (bs[i] != 0) {
            break;
        }
    }
    if (sp0.b > i) {
        sp0.b = i;
    }

    for (i = ARRAY_COUNT(rs) - 1; i >= 0; i--) {
        if (rs[i] != 0) {
            break;
        }
    }
    if (sp8.r < i) {
        sp8.r = i;
    }

    for (i = ARRAY_COUNT(gs) - 1; i >= 0; i--) {
        if (gs[i] != 0) {
            break;
        }
    }
    if (sp8.g < i) {
        sp8.g = i;
    }

    for (i = ARRAY_COUNT(bs) - 1; i >= 0; i--) {
        if (bs[i] != 0) {
            break;
        }
    }
    if (sp8.b < i) {
        sp8.b = i;
    }

    final.r = (sp8.r + sp0.r) - filterBuf1.r;
    final.g = (sp8.g + sp0.g) - filterBuf1.g;
    final.b = (sp8.b + sp0.b) - filterBuf1.b;

    final.r = ((filterBuf1.r * filterBuf1.a) + (final.r * (8 - filterBuf1.a))) >> 3;
    final.g = ((filterBuf1.g * filterBuf1.a) + (final.g * (8 - filterBuf1.a))) >> 3;
    final.b = ((filterBuf1.b * filterBuf1.a) + (final.b * (8 - filterBuf1.a))) >> 3;

    *out = (final.r << 11) + (final.g << 6) + (final.b << 1) + 1;
}

void func_80027600(Color_RGBA8* arg0, s16* out) {
    Color_RGBA8 final;
    u8 rs[0x20];
    u8 gs[0x20];
    u8 bs[0x20];
    s32 i;
    s32 sum;

    for (i = 0; i < ARRAY_COUNT(rs); i++) {
        rs[i] = 0;
        gs[i] = 0;
        bs[i] = 0;
    }

    for (i = 0; i < 9; i++) {
        rs[arg0[i].r]++;
        gs[arg0[i].g]++;
        bs[arg0[i].b]++;
    }

    sum = 0;
    for (i = 0; i < ARRAY_COUNT(rs); i++) {
        sum += rs[i];
        if (sum >= 5) {
            break;
        }
    }
    final.r = i;

    sum = 0;
    for (i = 0; i < ARRAY_COUNT(gs); i++) {
        sum += gs[i];
        if (sum >= 5) {
            break;
        }
    }
    final.g = i;

    sum = 0;
    for (i = 0; i < ARRAY_COUNT(bs); i++) {
        sum += bs[i];
        if (sum >= 5) {
            break;
        }
    }
    final.b = i;

    *out = (final.r << 11) + (final.g << 6) + (final.b << 1) + 1;
}

void func_80027774(u16* frameBuffer0, u16* frameBuffer1, u16* zBuffer) {
    Color_RGBA8 filterBuf0[9];
    s32 x, y;

    for (y = 1; y < SCREEN_HEIGHT - 1; y++) {
        for (x = 1; x < SCREEN_WIDTH - 1; x++) {

            /*
            The application of gfx_frame_filter_pass_0 is done to the following pixels, where x is the current pixel.
               ...
               .x.
               ...
            */
            if (
                (((frameBuffer1[(SCREEN_WIDTH * y) + x - 1] >> 2) & 0xF) < 8) ||
                (((frameBuffer1[(SCREEN_WIDTH * y) + x + 0] >> 2) & 0xF) < 8) ||
                (((frameBuffer1[(SCREEN_WIDTH * y) + x + 1] >> 2) & 0xF) < 8))
            {
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y - 1, x - 1, &filterBuf0[0]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y - 1, x,     &filterBuf0[1]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y - 1, x + 1, &filterBuf0[2]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y    , x - 1, &filterBuf0[3]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y    , x,     &filterBuf0[4]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y    , x + 1, &filterBuf0[5]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y + 1, x - 1, &filterBuf0[6]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y + 1, x,     &filterBuf0[7]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y + 1, x + 1, &filterBuf0[8]);
                func_80027600(filterBuf0, &zBuffer[(SCREEN_WIDTH * y) + x]);
            } else {
                zBuffer[(SCREEN_WIDTH * y) + x] = frameBuffer0[(SCREEN_WIDTH * y) + x] | 1;
            }
        }
    }
}

// transfers the framebuffer into the depth buffer and applies filters
void gfx_transfer_frame_to_depth(u16* frameBuffer0, u16* frameBuffer1, u16* zBuffer) {
    Color_RGBA8 filterBuf0[6];
    Color_RGBA8 filterBuf1;
    s32 y;
    s32 x;

    for (y = 1; y < SCREEN_HEIGHT - 1; y++) {
        for (x = 2; x < SCREEN_WIDTH - 2; x++) {
            s32 pixel = SCREEN_WIDTH * y + x;

            /*
            The application of gfx_frame_filter_pass_0 is done to the following pixels, where x is the current pixel.
               . .
              . x .
               . .
            */
            if (((frameBuffer1[pixel] >> 2) & 0xF) < 8) {
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y - 1, x - 1, &filterBuf0[0]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y - 1, x + 1, &filterBuf0[1]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y,     x - 2, &filterBuf0[2]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y,     x + 2, &filterBuf0[3]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y + 1, x - 1, &filterBuf0[4]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y + 1, x + 1, &filterBuf0[5]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y,     x,     &filterBuf1);
                gfx_frame_filter_pass_1(filterBuf0, filterBuf1, &zBuffer[pixel]);
            } else {
                // Don't apply any filters to the edges of the screen
                zBuffer[pixel] = frameBuffer0[pixel] | 1;
            }
        }
    }
}

void func_80027BAC(s32 arg0, s32 arg1) {
    s32 i;
    s32 temp = 24; // todo figure out why this is needed and can't be used elsewhere

    gDPPipeSync(gMainGfxPos++);
    gSPTexture(gMainGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, arg1);
    gDPSetCycleType(gMainGfxPos++, G_CYC_COPY);
    gDPSetTexturePersp(gMainGfxPos++, G_TP_NONE);
    gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
    gDPSetRenderMode(gMainGfxPos++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);

    for (i = 0; i < 40; i++) {
        gDPLoadTextureTile(gMainGfxPos++, arg0 + (0xF00 * i), G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                           SCREEN_HEIGHT, 0, 0, SCREEN_WIDTH - 1, 5, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gMainGfxPos++, 0, i * temp, 0x04FC, (i * 24) + 20, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
        gDPPipeSync(gMainGfxPos++);
    }
}

/// Logic for the drawing the scene background. In normal operation, it draws the regular background.
/// While opening pause menu, it does the following:
///  * Extracts coverage from the current framebuffer and saves it to nuGfxCfb[1] on the first frame.
///  * Copies the current framebuffer to the depth buffer to save it and applies a filter on the
///    saved framebuffer based on the saved coverage values one frame later.
///  * Draws the saved framebuffer to the current framebuffer while the pause screen is opened, fading it in over time.
void gfx_draw_background(void) {
    Camera* camera;
    s32 bgRenderState;
    s32 backgroundMinX;
    s32 backgroundMaxX;
    s32 backgroundMinY;
    s32 backgroundMaxY;
    s32 viewportStartX;
    s32 i;
    s32 a = SCREEN_COPY_TILE_HEIGHT << 2;

    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    camera = &gCameras[gCurrentCameraID];
    bgRenderState = gGameStatusPtr->backgroundFlags & BACKGROUND_RENDER_STATE_MASK;

    switch (bgRenderState) {
        case BACKGROUND_RENDER_STATE_BEGIN_PAUSED:
            // Save coverage to nunGfxCfb[1] using the VISCVG render mode
            gDPPipeSync(gMainGfxPos++);
            gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, nuGfxCfb[1]);
            gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
            gDPSetBlendColor(gMainGfxPos++, 0x80, 0x80, 0x80, 0xFF);
            gDPSetPrimDepth(gMainGfxPos++, 0xFFFF, 0xFFFF);
            gDPSetDepthSource(gMainGfxPos++, G_ZS_PRIM);
            gDPSetRenderMode(gMainGfxPos++, G_RM_VISCVG, G_RM_VISCVG2);
            gDPFillRectangle(gMainGfxPos++, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            gDPPipeSync(gMainGfxPos++);
            gDPSetDepthSource(gMainGfxPos++, G_ZS_PIXEL);
            gGameStatusPtr->backgroundFlags &= ~BACKGROUND_RENDER_STATE_MASK;
            gGameStatusPtr->backgroundFlags |= BACKGROUND_RENDER_STATE_FILTER_PAUSED;
            break;
        case BACKGROUND_RENDER_STATE_FILTER_PAUSED:
            // Save the framebuffer into the depth buffer and run a filter on it based on the saved coverage values
            gfx_transfer_frame_to_depth(nuGfxCfb[0], nuGfxCfb[1], nuGfxZBuffer); // applies filters to the framebuffer
            gPauseBackgroundFade = 0;
            gGameStatusPtr->backgroundFlags &= ~BACKGROUND_RENDER_STATE_MASK;
            gGameStatusPtr->backgroundFlags |= BACKGROUND_RENDER_STATE_SHOW_PAUSED;
            // fallthrough
        case BACKGROUND_RENDER_STATE_SHOW_PAUSED:
            // Draw the saved framebuffer to the background, fading in at a rate of 16 opacity per frame until reaching 128 opacity
            gPauseBackgroundFade += 16;
            if (gPauseBackgroundFade > 128) {
                gPauseBackgroundFade = 128;
            }

            gDPPipeSync(gMainGfxPos++);
            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            gDPSetCycleType(gMainGfxPos++, G_CYC_FILL);
            gDPSetRenderMode(gMainGfxPos++, G_RM_NOOP, G_RM_NOOP2);
            gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, nuGfxCfb_ptr);
            gDPSetFillColor(gMainGfxPos++, PACK_FILL_COLOR(0, 0, 0, 1));
            gDPFillRectangle(gMainGfxPos++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
            gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
            gDPSetTexturePersp(gMainGfxPos++, G_TP_NONE);
            gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
            gDPSetRenderMode(gMainGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
            /// @bug In 1-cycle mode, the two combiner cycles should be identical. Using Texel1 here in the second cycle,
            /// which is the actual cycle of the combiner used on hardware in 1-cycle mode, actually samples the next
            /// pixel's texel value instead of the current pixel's. This results in a one-pixel offset.
            gDPSetCombineMode(gMainGfxPos++, PM_CC_43, PM_CC_44);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 40, 40, 40, gPauseBackgroundFade);
            gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);

            for (i = 0; i < 40; i++) {
                gDPLoadTextureTile(gMainGfxPos++, nuGfxZBuffer + (i * SCREEN_WIDTH * SCREEN_COPY_TILE_HEIGHT), G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                                   SCREEN_HEIGHT, 0, 0, SCREEN_WIDTH - 1, SCREEN_COPY_TILE_HEIGHT - 1, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                   G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                /// @bug Due to the previous issue with the incorrect second cycle combiner, the devs added a 1-pixel offset to texture coordinates
                /// in this texrect to compensate for the combiner error.
                gSPTextureRectangle(gMainGfxPos++,
                                    // ulx, uly, lrx, lry
                                    0 << 2, i * a, SCREEN_WIDTH << 2, a + (i * (SCREEN_COPY_TILE_HEIGHT << 2)),
                                    // tile
                                    G_TX_RENDERTILE,
                                    // s, t, dsdx, dtdy
                                    -1 << 5, 0 << 5, 1 << 10, 1 << 10);
                gDPPipeSync(gMainGfxPos++);
            }
            break;
        default:
            // Draw the scene's background as normal
            if (gOverrideFlags & GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME) {
                gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));
                return;
            }

            gDPSetDepthImage(gMainGfxPos++, OS_K0_TO_PHYSICAL(nuGfxZBuffer));
            gDPSetCycleType(gMainGfxPos++, G_CYC_FILL);
            gDPSetRenderMode(gMainGfxPos++, G_RM_NOOP, G_RM_NOOP2);
            gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_K0_TO_PHYSICAL(nuGfxZBuffer));
            gDPSetFillColor(gMainGfxPos++, PACK_FILL_DEPTH(G_MAXFBZ, 0));
            gDPFillRectangle(gMainGfxPos++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
            gDPPipeSync(gMainGfxPos++);
            gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));
            gDPSetFillColor(gMainGfxPos++, PACK_FILL_COLOR(camera->bgColor[0], camera->bgColor[1], camera->bgColor[2], 1));

            backgroundMinX = gGameStatusPtr->backgroundMinX;
            backgroundMaxX = backgroundMinX + gGameStatusPtr->backgroundMaxX;
            backgroundMinY = gGameStatusPtr->backgroundMinY;
            backgroundMaxY = backgroundMinY + gGameStatusPtr->backgroundMaxY;
            viewportStartX = camera->viewportStartX;

            if (backgroundMinX < viewportStartX) {
                backgroundMinX = viewportStartX;
            }

            if (backgroundMinY < camera->viewportStartY) {
                backgroundMinY = camera->viewportStartY;
            }

            if (backgroundMaxX > viewportStartX + camera->viewportW) {
                backgroundMaxX = viewportStartX + camera->viewportW;
            }

            if (backgroundMaxY > camera->viewportStartY + camera->viewportH) {
                backgroundMaxY = camera->viewportStartY + camera->viewportH;
            }

            if (backgroundMinX < 0) {
                backgroundMinX = 0;
            }

            if (backgroundMinY < 0) {
                backgroundMinY = 0;
            }

            if (backgroundMaxX < 1) {
                backgroundMaxX = 1;
            }

            if (backgroundMaxY < 1) {
                backgroundMaxY = 1;
            }

            if (backgroundMinX > SCREEN_WIDTH - 1) {
                backgroundMinX = SCREEN_WIDTH - 1;
            }

            if (backgroundMinY > SCREEN_HEIGHT - 1) {
                backgroundMinY = SCREEN_HEIGHT - 1;
            }

            if (backgroundMaxX > SCREEN_WIDTH) {
                backgroundMaxX = SCREEN_WIDTH;
            }

            if (backgroundMaxY > SCREEN_HEIGHT) {
                backgroundMaxY = SCREEN_HEIGHT;
            }

            if (!(gGameStatusPtr->backgroundFlags & BACKGROUND_FLAG_TEXTURE)) {
                gDPFillRectangle(gMainGfxPos++, backgroundMinX, backgroundMinY, backgroundMaxX - 1, backgroundMaxY - 1);
            } else {
                appendGfx_background_texture();
            }

            gDPPipeSync(gMainGfxPos++);
            gDPSetCycleType(gMainGfxPos++, G_CYC_FILL);
            gDPSetRenderMode(gMainGfxPos++, G_RM_NOOP, G_RM_NOOP2);
            gDPSetFillColor(gMainGfxPos++, PACK_FILL_COLOR(0, 0, 0, 1));
            gDPPipeSync(gMainGfxPos++);

            if (backgroundMinY > 0) {
                gDPFillRectangle(gMainGfxPos++, 0, 0, SCREEN_WIDTH - 1, backgroundMinY - 1);
                gDPNoOp(gMainGfxPos++);
            }

            if (backgroundMinX > 0) {
                gDPFillRectangle(gMainGfxPos++, 0, backgroundMinY, backgroundMinX - 1, backgroundMaxY - 1);
                gDPNoOp(gMainGfxPos++);
            }

            if (backgroundMaxX < SCREEN_WIDTH) {
                gDPFillRectangle(gMainGfxPos++, backgroundMaxX, backgroundMinY, SCREEN_WIDTH - 1, backgroundMaxY - 1);
                gDPNoOp(gMainGfxPos++);
            }

            if (backgroundMaxY < SCREEN_HEIGHT) {
                gDPFillRectangle(gMainGfxPos++, 0, backgroundMaxY, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
                gDPNoOp(gMainGfxPos++);
            }
            break;
    }
    gDPPipeSync(gMainGfxPos++);
}
