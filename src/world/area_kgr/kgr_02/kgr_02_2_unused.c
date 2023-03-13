#include "kgr_02.h"
#include "nu/nusys.h"

extern s32 N(D_80240970_8AADC0);

void N(func_80240160_8AA5B0)(s32 x1, s32 y1, s32 x2, s32 y2, s32 arg4) {
    s32 i;
    f32 f0;
    s32 n, m;
    u16* img;

    N(D_80240970_8AADC0) += 5;

    if (x1 >= x2 || y1 >= y2) {
        return;
    }

    if (x1 < 0) {
        x1 = 0;
    }
    if (y1 < 0) {
        y1 = 0;
    }
    if (x2 < 0) {
        x2 = 0;
    }
    if (y2 < 0) {
        y2 = 0;
    }

    if (x1 >= SCREEN_WIDTH) {
        x1 = SCREEN_WIDTH - 1;
    }
    if (y1 >= SCREEN_HEIGHT) {
        y1 = SCREEN_HEIGHT - 1;
    }
    if (x2 >= SCREEN_WIDTH) {
        x2 = SCREEN_WIDTH - 1;
    }
    if (y2 >= SCREEN_HEIGHT) {
        y2 = SCREEN_HEIGHT - 1;
    }

    if (x1 == x2 || y1 == y2) {
        return;
    }

    x1 = x1 / 4 * 4;
    x2 = x2 / 4 * 4 + 4;

    gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, 255);

    n = (y2 - y1) / 6;
    m = (y2 - y1) % 6;
    img = nuGfxCfb_ptr;

    for (i = 0; i < n; i++) {
        gDPLoadTextureTile(gMainGfxPos++, osVirtualToPhysical(img), G_IM_FMT_RGBA, G_IM_SIZ_16b,
                           SCREEN_WIDTH, 6,
                           x1, y1 + 6 * i, x2 - 1, y1 + 6 * i + 5, 0,
                           G_TX_WRAP, G_TX_WRAP, 9, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        f0 = sin_deg(N(D_80240970_8AADC0) + i * 30);
        gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, (x1 + 512) * 4 + arg4 * (s32)(f0 * 4),
                                                          (y1 + i * 6) * 4,
                                                          (x1 + 512) * 4 + arg4 * (s32)(f0 * 4) + 512 * 4,
                                                          (y1 + i * 6) * 4 + 5 * 4);
        gSPTextureRectangle(gMainGfxPos++, x1 * 4, (y1 + i * 6) * 4, x2 * 4, (y1 + i * 6 + 6) * 4,
                            G_TX_RENDERTILE, x1 * 32, (y1 + i * 6) * 32, 1024, 1024);
    }

    if (m != 0) {
        gDPLoadTextureTile(gMainGfxPos++, osVirtualToPhysical(img), G_IM_FMT_RGBA, G_IM_SIZ_16b,
                           SCREEN_WIDTH, m,
                           x1, y1 + i * 6, x2 - 1, y1 + i * 6 + m - 1, 0,
                           G_TX_WRAP, G_TX_WRAP, 9, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gMainGfxPos++, x1 * 4, (y1 + i * 6) * 4, x2 * 4, (y1 + i * 6 + m) * 4,
                            G_TX_RENDERTILE, x1 * 32, (y1 + i * 6) * 32, 1024, 1024);
    }
}

