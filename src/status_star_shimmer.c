#include "common.h"
#include "include_asset.h"

INCLUDE_IMG("ui/status/shimmer_particle.png", ui_status_shimmer_particle_png);

Vp ShimmerViewport = {
    .vp = {
        .vscale = { 640, 480, 511, 0 },
        .vtrans = { 640, 480, 511, 0 }
    }
};

#include "A2B70.vtx.inc.c" // Vtx_StatusShimmer_Particle

#include "A2BC0.gfx.inc.c" // Gfx_StatusShimmer_SetupTex
#include "A2C88.gfx.inc.c" // Gfx_StatusShimmer_DrawParticle

#define NUM_PARTICLES 56

u8 AnimatedScale[] = {
    40, 90, 81, 72, 65, 59, 53, 47, 43, 38, 34, 31, 28, 25, 22, 20, 18, 16, 15, 13, 12, 10, 9, 8, 7, 7, 6, 5, 5, 4
};

Vec2b InitialVelocities[NUM_PARTICLES] = {
    { 247, 105 }, { 239, 87 }, { 17, 87 }, { 9, 105 }, { 0, 122 }, { 230, 69 }, { 26, 69 }, { 221, 52 }, { 35, 52 },
    { 202, 49 }, { 186, 255 }, { 200, 241 }, { 0, 200 }, { 56, 241 }, { 70, 255 }, { 54, 49 }, { 196, 222 },
    { 239, 191 }, { 17, 191 }, { 60, 222 }, { 85, 13 }, { 74, 46 }, { 99, 27 }, { 93, 43 }, { 12, 33 }, { 12, 22 },
    { 24, 22 }, { 24, 33 }, { 12, 10 }, { 24, 10 }, { 24, 45 }, { 232, 33 }, { 232, 22 }, { 232, 45 }, { 113, 40 },
    { 193, 203 }, { 190, 183 }, { 182, 46 }, { 163, 43 }, { 35, 182 }, { 52, 173 }, { 12, 45 }, { 244, 22 },
    { 244, 33 }, { 232, 10 }, { 244, 10 }, { 244, 45 }, { 204, 173 }, { 221, 182 }, { 186, 164 }, { 171, 13 },
    { 157, 27 }, { 143, 40 }, { 63, 203 }, { 66, 183 }, { 70, 164 }
};

typedef struct ShimmerParticle {
    /* 0x00 */ u8 alive;
    /* 0x01 */ s8 timeLeft;
    /* 0x02 */ u8 lifetime;
    /* 0x03 */ Color_RGBA8 rgba;
    /* 0x07 */ s8 animTime;
    /* 0x08 */ Vec2f pos;
    /* 0x10 */ Vec2f vel;
    /* 0x18 */ f32 scale;
} ShimmerParticle; // size = 0x1C

typedef struct ShimmerEmitter {
    /* 0x00 */ ShimmerParticle particles[1 + NUM_PARTICLES]; // one dummy master + 56 actually visible ones
} ShimmerEmitter;

BSS ShimmerEmitter ShimmerEmitters[1];

void star_power_shimmer_start(s32 emitterIdx, f32 x, f32 y, f32 scale) {
    ShimmerEmitter* emitter = &ShimmerEmitters[emitterIdx];
    ShimmerParticle* particle = &emitter->particles[0];
    s32 numParticles = ARRAY_COUNT(emitter->particles);
    s32 j;

    if (emitterIdx < ARRAY_COUNT(ShimmerEmitters)) {
        particle->alive = true;
        particle->pos.x = x;
        particle->pos.y = y;
        particle->scale = scale;
        particle->timeLeft = 40;
        particle->lifetime = 0;
        particle = &emitter->particles[1];

        for (j = 1; j < numParticles; j++, particle++) {
            particle->animTime = (s32) (-((f32) j) * 0.0f) - 1;
        }
    }
}

void star_power_shimmer_init(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(ShimmerEmitters); i++) {
        ShimmerEmitters[i].particles[0].alive = false;
    }
}

void star_power_shimmer_update(void) {
    ShimmerEmitter* emitter;
    ShimmerParticle* particle;
    s32 emitterTimeLeft;
    f32 emitterX;
    f32 emitterY;
    s32 i, j;

    for (i = 0; i < ARRAY_COUNT(ShimmerEmitters); i++, emitter++) {
        emitter = &ShimmerEmitters[i];

        if (!emitter->particles[0].alive) {
            continue;
        }

        emitter->particles[0].timeLeft--;
        emitter->particles[0].lifetime++;

        if (emitter->particles[0].timeLeft < 0) {
            emitter->particles[0].alive = false;
            continue;
        }

        emitterTimeLeft = emitter->particles[0].timeLeft;
        emitterX = emitter->particles[0].pos.x;
        emitterY = emitter->particles[0].pos.y;

        particle = &emitter->particles[1];
        for (j = 1; j < ARRAY_COUNT(emitter->particles); j++, particle++) {
            particle->animTime++;
            if (particle->animTime >= ARRAY_COUNT(AnimatedScale)) {
                if (emitterTimeLeft < 30) {
                    particle->animTime = -31;
                } else {
                    particle->animTime = 0;
                }
            }

            if (particle->animTime < 0) {
                continue;
            }

            if (particle->animTime == 0) {
                f32 initialVelX = InitialVelocities[j - 1].x;
                f32 initialVelY = InitialVelocities[j - 1].y;
                s8 t = 127;

                particle->vel.x = initialVelX * 0.1;
                particle->vel.y = -initialVelY * 0.1;
                particle->pos.x = emitterX;
                particle->pos.y = emitterY;
                particle->scale = 1.0f;
                particle->rgba.r = rand_int(t);
                particle->rgba.g = rand_int(t - particle->rgba.r);
                particle->rgba.b = rand_int(t - particle->rgba.g - particle->rgba.r);
                particle->rgba.a = 255;
                particle->rgba.r += 128;
                particle->rgba.g += 128;
                particle->rgba.b += 128;
            }

            particle->pos.x += particle->vel.x;
            particle->pos.y += particle->vel.y;
            particle->vel.x *= 0.92;
            particle->vel.y *= 0.92;
            particle->scale = (f32) AnimatedScale[particle->animTime] * 0.04;
        }
    }
}

// draws small diamond shaped shimmer particles over the star power bar
void star_power_shimmer_draw(void) {
    Matrix4f viewMtx, transformMtx;
    ShimmerEmitter* emitter;
    ShimmerParticle* particle;
    f32 emitterScale;
    s32 i, j;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x00, 0x00000000);
    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gSPViewport(gMainGfxPos++, &ShimmerViewport);

    guOrthoF(viewMtx, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, -100.0f, 100.0f, 1.0f);
    guMtxF2L(viewMtx, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(gMainGfxPos++, D_80109710); // setup texture
    gDPSetEnvColor(gMainGfxPos++, 127, 127, 127, 127);

    for (i = 0; i < ARRAY_COUNT(ShimmerEmitters); i++, emitter++) {
        emitter = &ShimmerEmitters[i];

        if (emitter->particles[0].alive) {
            emitterScale = emitter->particles[0].scale;

            particle = &emitter->particles[1];
            for (j = 1; j < ARRAY_COUNT(emitter->particles); j++, particle++) {
                if (particle->animTime >= 0) {
                    guPositionF(transformMtx, 0.0f, 0.0f, gGameStatusPtr->frameCounter * 10, particle->scale * emitterScale,
                                particle->pos.x, particle->pos.y, 0.0f);
                    guMtxF2L(transformMtx, &gDisplayContext->matrixStack[gMatrixListPos]);

                    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                              G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                    gDPSetPrimColor(gMainGfxPos++, 0, 80 - particle->animTime, particle->rgba.r, particle->rgba.g, particle->rgba.b, particle->rgba.a);
                    gSPDisplayList(gMainGfxPos++, D_801097D8); // draw particle
                    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
                }
            }
        }
    }
}
