#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001500_3918D0[];
extern Gfx D_090015A8_391978[];
extern Gfx D_09001610_3919E0[];
extern Gfx D_09001658_391A28[];
extern Gfx D_090016A0_391A70[];
extern Gfx D_090016E8_391AB8[];
extern Gfx D_09001730_391B00[];
extern Gfx D_090018B8_391C88[];
extern Gfx D_090018D8_391CA8[];
extern Gfx D_090018F8_391CC8[];
extern Gfx D_09001918_391CE8[];
extern Gfx D_09001938_391D08[];

Gfx* D_E0090A40[5] = { D_09001658_391A28, D_09001610_3919E0, D_090016A0_391A70, D_090016E8_391AB8, D_09001730_391B00 };
Gfx* D_E0090A54[5] = { D_090018D8_391CA8, D_090018B8_391C88, D_090018F8_391CC8, D_09001918_391CE8, D_09001938_391D08 };

u8 D_E0090A68[8] = { 10, 40, 80, 120, 125, 100, 90, 100 };
u8 D_E0090A70[8] = { 60, 80, 100, 110, 112, 95, 100, 0 };

s8 D_E0090A78[5][6] = {
    { 255, 255, 255, 254, 159, 15 },
    { 215, 86, 0, 254, 207, 15 },
    { 254, 159, 15, 229, 21, 0 },
    { 0, 107, 42, 255, 217, 69 },
    { 0, 0, 215, 151, 255, 255 },
};

void attack_result_text_init(EffectInstance* effect);
void attack_result_text_update(EffectInstance* effect);
void attack_result_text_render(EffectInstance* effect);
void func_E0090428(EffectInstance* effect);
void func_E0090444(EffectInstance* effect);

EffectInstance* attack_result_text_main(s32 type, f32 posX, f32 posY, f32 posZ, f32 appearVel, s32 duration) {
    EffectBlueprint bp;
    EffectInstance* effect;
    AttackResultTextFXData* data;
    s32 numParts = 1;

    bp.unk_00 = 0;
    bp.init = attack_result_text_init;
    bp.update = attack_result_text_update;
    bp.renderWorld = attack_result_text_render;
    bp.renderUI = func_E0090428;
    bp.effectID = EFFECT_ATTACK_RESULT_TEXT;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;

    data = effect->data.attackResultText = general_heap_malloc(effect->numParts * sizeof(*data));

    ASSERT(data != NULL);

    data->isVisible = TRUE;
    data->unk_20 = 0;
    data->type = type;
    data->lifetime = 0;
    data->unk_04 = type % 5;

    if (duration <= 0) {
        data->timeLeft = 100;
    } else {
        data->timeLeft = duration;
    }

    data->alpha = 0xFF;

    if (type < 5) {
        data->pos.x = posX;
        data->pos.y = posY;
        data->pos.z = posZ;
        data->vel.x = 2.0f * (-sin_deg(30.0f) * appearVel);
        data->vel.y = 2.0f * (cos_deg(30.0f) * appearVel);
    } else {
        data->pos.x = -100.0f;
        data->pos.y = 40.0f;
        data->pos.z = 0.0f;
        data->vel.x = 115.0f;
        data->vel.y = 0.0f;
    }

    return effect;
}

void attack_result_text_init(EffectInstance* effect) {
}

void attack_result_text_update(EffectInstance* effect) {
    AttackResultTextFXData* data = effect->data.attackResultText;
    s32 type = data->type;
    s32 prevTime;
    s32 curTime;
    s32 timeLeft;
    u32 temp1C;

    if (data->timeLeft < 100) {
        data->timeLeft--;
    }

    prevTime = data->lifetime;
    data->lifetime++;
    curTime = data->lifetime;

    if (data->timeLeft < 0) {
        data->isVisible = FALSE;
        data->timeLeft = -1;
        remove_effect(effect);
        return;
    }

    timeLeft = data->timeLeft;

    if (type < 5) {
        if (data->lifetime < 9) {
            data->scale = (f32) D_E0090A68[prevTime] * 0.01;
        }

        temp1C = prevTime - 100;
        if (curTime == 10) {
            data->lifetime = 9;
        }

        if (temp1C < 7) {
            data->scale = (f32) D_E0090A70[temp1C] * 0.01;
        }

        if (curTime == 109) {
            data->lifetime = 108;
        }
        if (curTime > 1000) {
            data->lifetime = 1000;
        }
        if (timeLeft >= 6) {
            data->vel.x *= 0.75;
            data->vel.y *= 0.75;
        }
        if (timeLeft < 5) {
            data->vel.x *= 0.7;
            data->vel.y *= 0.7;
        }
    } else {
        if (timeLeft >= 6) {
            data->vel.x *= 0.7;
            data->vel.y *= 0.7;
        }
        if (timeLeft < 5) {
            data->vel.x *= 0.6;
            data->vel.y *= 0.6;
        }
    }

    data->pos.x += data->vel.x;
    data->pos.y += data->vel.y;
    if (data->unk_20 != 0) {
        data->unk_20 = 0;
        data->lifetime = 100;
        data->unk_04++;
        if (data->unk_04 > 2) {
            data->unk_04 = 2;
        }
    }
}

void attack_result_text_render(EffectInstance* effect) {
}

void func_E0090428(EffectInstance* effect) {
    func_E0090444(effect);
}

void func_E0090444(EffectInstance* effect) {
    AttackResultTextFXData* data = effect->data.attackResultText;
    s32 type = data->type;
    s32 unk_1C = data->lifetime;
    Matrix4f mtxA;
    Matrix4f mtxB;
    s32 z;
    f32 scale;

    if (data->isVisible) {
        scale = data->scale;
        gDPPipeSync(gMainGfxPos++);
        gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effect->graphics->data));
        gDPSetDepthSource(gMainGfxPos++, G_ZS_PRIM);
        z = 200 - unk_1C;
        if (z < 0) {
            z = 0;
        }
        gDPSetPrimDepth(gMainGfxPos++, z, 0);

        if (type < 5) {
            guTranslateF(mtxA, data->pos.x, data->pos.y, data->pos.z);
            guRotateF(mtxB, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
            guMtxCatF(mtxB, mtxA, mtxA);
            guScaleF(mtxB, scale, scale, 1.0f);
            guMtxCatF(mtxB, mtxA, mtxA);
            guMtxF2L(mtxA, &gDisplayContext->matrixStack[gMatrixListPos]);
            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, data->alpha);
            gSPDisplayList(gMainGfxPos++, D_090015A8_391978);
            gSPDisplayList(gMainGfxPos++, D_E0090A40[data->unk_04]);
            gSPDisplayList(gMainGfxPos++, D_E0090A54[data->unk_04]);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        } else {
            type -= 5;
            gDPSetPrimColor(gMainGfxPos++, 0, 0, D_E0090A78[type][0], D_E0090A78[type][1], D_E0090A78[type][2], data->alpha);
            gDPSetEnvColor(gMainGfxPos++, D_E0090A78[type][3], D_E0090A78[type][4], D_E0090A78[type][5], 0);
            gSPDisplayList(gMainGfxPos++, D_09001500_3918D0);
            gSPDisplayList(gMainGfxPos++, D_E0090A40[data->unk_04]);

            gSPScisTextureRectangle(gMainGfxPos++,
                data->pos.x * 4.0f,
                data->pos.y * 4.0f,
                (data->pos.x + 128.0f) * 4.0f,
                (data->pos.y + 64.0f) * 4.0f,
                G_TX_RENDERTILE, 0, 1024, 512, 65024);
        }
        gDPPipeSync(gMainGfxPos++);
        gDPSetDepthSource(gMainGfxPos++, G_ZS_PIXEL);
        gDPPipeSync(gMainGfxPos++);
    }
}
