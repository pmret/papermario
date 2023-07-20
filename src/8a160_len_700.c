#include "common.h"

#include "A2960.png.inc.c"

Vp D_801096B0 = {
    .vp = {
        .vscale = { 640, 480, 511, 0 },
        .vtrans = { 640, 480, 511, 0 }
    }
};

#include "A2B70.vtx.inc.c"

#include "A2BC0.gfx.inc.c"
#include "A2C88.gfx.inc.c"

u8 D_80109800[32] = {
    40, 90, 81, 72, 65, 59, 53, 47, 43, 38, 34, 31, 28, 25, 22, 20, 18, 16, 15, 13, 12, 10, 9, 8, 7, 7, 6, 5, 5, 4, 0, 0
};

Vec2b D_80109820[56] = {
    { 247, 105 }, { 239, 87 }, { 17, 87 }, { 9, 105 }, { 0, 122 }, { 230, 69 }, { 26, 69 }, { 221, 52 }, { 35, 52 },
    { 202, 49 }, { 186, 255 }, { 200, 241 }, { 0, 200 }, { 56, 241 }, { 70, 255 }, { 54, 49 }, { 196, 222 },
    { 239, 191 }, { 17, 191 }, { 60, 222 }, { 85, 13 }, { 74, 46 }, { 99, 27 }, { 93, 43 }, { 12, 33 }, { 12, 22 },
    { 24, 22 }, { 24, 33 }, { 12, 10 }, { 24, 10 }, { 24, 45 }, { 232, 33 }, { 232, 22 }, { 232, 45 }, { 113, 40 },
    { 193, 203 }, { 190, 183 }, { 182, 46 }, { 163, 43 }, { 35, 182 }, { 52, 173 }, { 12, 45 }, { 244, 22 },
    { 244, 33 }, { 232, 10 }, { 244, 10 }, { 244, 45 }, { 204, 173 }, { 221, 182 }, { 186, 164 }, { 171, 13 },
    { 157, 27 }, { 143, 40 }, { 63, 203 }, { 66, 183 }, { 70, 164 }
};

typedef struct Unk8a160 {
    /* 0x00 */ u8 alive;
    /* 0x01 */ s8 timeLeft;
    /* 0x02 */ u8 lifetime;
    /* 0x03 */ Color_RGBA8 rgba;
    /* 0x07 */ s8 lodVal;
    /* 0x08 */ f32 x;
    /* 0x0C */ f32 y;
    /* 0x10 */ Vec2f vel;
    /* 0x18 */ f32 scale;
} Unk8a160; // size = 0x1C

typedef struct Unk8a160Outer {
    /* 0x00 */ Unk8a160 subs[57]; // one base + 56 others?
} Unk8a160Outer;

SHIFT_BSS Unk8a160Outer D_8010D000[1];

void func_800F0CB0(s32 arg0, f32 x, f32 y, f32 scale) {
    Unk8a160Outer* outer = &D_8010D000[arg0];
    Unk8a160* sub = &outer->subs[0];
    s32 numSubstructs = ARRAY_COUNT(outer->subs);
    s32 i;

    if (arg0 <= 0) {
        sub->alive = TRUE;
        sub->x = x;
        sub->y = y;
        sub->scale = scale;
        sub->timeLeft = 40;
        sub->lifetime = 0;
        sub = &outer->subs[1];

        for (i = 1; i < numSubstructs; i++, sub++) {
            sub->lodVal = (s32) (-((f32) i) * 0.0f) - 1;
        }
    }
}

void func_800F0D5C(void) {
    Unk8a160Outer* outer = &D_8010D000[0];
    s32 i;

    for (i = 0; i < 1; i++) {
        outer[i].subs[0].alive = FALSE;
    }
}

void func_800F0D80(void) {
    Unk8a160Outer* outer;
    s32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(D_8010D000); i++, outer++) {
        outer = &D_8010D000[i];

        if (outer->subs[0].alive) {
            outer->subs[0].timeLeft--;
            outer->subs[0].lifetime++;

            if (outer->subs[0].timeLeft < 0) {
                outer->subs[0].alive = FALSE;
            } else {
                Unk8a160* sub = &outer->subs[0];
                s32 baseTimeLeft = sub->timeLeft;
                f32 baseX = sub->x;
                f32 baseY = sub->y;

                sub++;
                for (j = 1; j < ARRAY_COUNT(outer->subs); j++, sub++) {
                    sub->lodVal++;
                    if (sub->lodVal >= 30) {
                        if (baseTimeLeft < 30) {
                            sub->lodVal = -31;
                        } else {
                            sub->lodVal = 0;
                        }
                    }

                    if (sub->lodVal >= 0) {
                        if (sub->lodVal == 0) {
                            f32 tx = D_80109820[j - 1].x;
                            f32 ty = D_80109820[j - 1].y;
                            u8 t = 127;

                            sub->vel.x = tx * 0.1;
                            sub->vel.y = -ty * 0.1;
                            sub->x = baseX;
                            sub->y = baseY;
                            sub->scale = 1.0f;
                            sub->rgba.r = rand_int(t);
                            sub->rgba.g = rand_int(t - sub->rgba.r);
                            sub->rgba.b = rand_int(t - sub->rgba.g - sub->rgba.r);
                            sub->rgba.a = 255;
                            sub->rgba.r += 128;
                            sub->rgba.g += 128;
                            sub->rgba.b += 128;
                        }
                        sub->x += sub->vel.x;
                        sub->y += sub->vel.y;
                        sub->vel.x *= 0.92;
                        sub->vel.y *= 0.92;
                        sub->scale = (f32) D_80109800[sub->lodVal] * 0.04;
                    }
                }
            }
        }
    }
}

void func_800F102C(void) {
    Matrix4f sp20, sp60;
    Unk8a160Outer* outer;
    s32 i;
    s32 j;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x00, 0x00000000);
    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gSPViewport(gMainGfxPos++, &D_801096B0);

    guOrthoF(sp20, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, -100.0f, 100.0f, 1.0f);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(gMainGfxPos++, D_80109710);
    gDPSetEnvColor(gMainGfxPos++, 127, 127, 127, 127);

    for (i = 0; i < ARRAY_COUNT(D_8010D000); i++, outer++) {
        outer = &D_8010D000[i];

        if (outer->subs[0].alive) {
            Unk8a160* it = &outer->subs[0];
            f32 baseScale = it->scale;

            it++;
            for (j = 1; j < ARRAY_COUNT(outer->subs); j++, it++) {
                if (it->lodVal >= 0) {
                    guPositionF(sp60, 0.0f, 0.0f, gGameStatusPtr->frameCounter * 10, it->scale * baseScale,
                                it->x, it->y, 0.0f);
                    guMtxF2L(sp60, &gDisplayContext->matrixStack[gMatrixListPos]);

                    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                              G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                    gDPSetPrimColor(gMainGfxPos++, 0, 80 - it->lodVal, it->rgba.r, it->rgba.g, it->rgba.b, it->rgba.a);
                    gSPDisplayList(gMainGfxPos++, D_801097D8);
                    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
                }
            }
        }
    }
}
