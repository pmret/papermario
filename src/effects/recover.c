#include "common.h"
#include "effects_internal.h"

extern Gfx D_09003200_385000[];
extern Gfx D_09003298_385098[];
extern Gfx D_09003330_385130[];
extern Gfx D_090033D0_3851D0[];
extern Gfx D_090033F0_3851F0[];
extern Gfx D_09003410_385210[];
extern Gfx D_09003430_385230[];
extern Gfx D_09003450_385250[];
extern Gfx D_09003470_385270[];
extern Gfx D_09003490_385290[];
extern Gfx D_090034B0_3852B0[];
extern Gfx D_090034D0_3852D0[];
extern Gfx D_09003540_385340[];
extern Gfx D_09003580_385380[];
extern Gfx D_090035C0_3853C0[];
extern Gfx D_09003600_385400[];
extern Gfx D_09003640_385440[];
extern Gfx D_09003680_385480[];
extern Gfx D_090036C0_3854C0[];
extern Gfx D_09003700_385500[];
extern Gfx D_09003740_385540[];
extern Gfx D_09003780_385580[];
extern Gfx D_090037C0_3855C0[];
extern Gfx D_09003800_385600[];

Gfx* D_E0080AC0[] = { D_09003540_385340, D_09003580_385380, D_090035C0_3853C0,
                      D_09003600_385400, D_09003640_385440, D_09003680_385480,
                      D_090036C0_3854C0, D_09003700_385500, D_09003740_385540,
                      D_09003780_385580, D_090037C0_3855C0, D_09003800_385600 };

f32 D_E0080AF0[] = { 0.25f, 0.5f, 0.75f, 1.0f, 0.9f, 1.1f, 1.0f };

f32 D_E0080B0C[] = { 0.25f, 0.5f, 0.75f, 1.0f, 1.2f, 0.9f, 1.0f };

void recover_init(EffectInstance* effect);
void recover_update(EffectInstance* effect);
void recover_render(EffectInstance* effect);
void func_E008042C(EffectInstance* effect);
void func_E0080448(EffectInstance* effect);

EffectInstance* recover_main(s32 type, f32 posX, f32 posY, f32 posZ, s32 duration) {
    EffectBlueprint bp;
    EffectInstance* effect;
    RecoverFXData* part;
    s32 numParts = 2;
    s32 i;

    bp.init = recover_init;
    bp.update = recover_update;
    bp.renderWorld = recover_render;
    bp.renderUI = func_E008042C;
    bp.unk_00 = 0;
    bp.effectID = EFFECT_RECOVER;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    part = effect->data.recover = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.recover != NULL);

    part->type = type;
    part->pos.x = posX;
    part->pos.y = posY;
    part->pos.z = posZ;
    part->timeLeft = 46;
    part->lifetime = 0;
    if (duration < 0) {
        part->unk_44 = 1;
        duration = -duration;
    } else {
        part->unk_44 = 0;
    }
    part->unk_40 = duration;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        part->pos.x = 0.0f;
        part->pos.y = 0.0f;
        part->pos.z = 0.0f;
        part->offsetX = 0;
        part->vel.x = 0;
        part->vel.z = 0;
        part->unk_20 = 0;
        part->angle = 0;
        if (i == 1) {
            part->pos.x = 0.0f;
            part->unk_34 = 0;
            part->scaleX = 0.0f;
            part->scaleY = 0.0f;
            part->vel.y = 1.4f;
        } else {
            part->vel.y = 1.4f;
            part->unk_34 = i + 10;
            part->scaleX = 0.0f;
            part->scaleY = 0.0f;
            part->pos.x = ((i & 1) * 2 - 1) * ((i - 1) >> 1) * 4;
        }
        part->timeLeft = 0;
        part->alpha = 255;
    }

    return effect;
}

void recover_init(EffectInstance* effect) {
}

void recover_update(EffectInstance* effect) {
    RecoverFXData* part = effect->data.recover;
    s32 time;
    s32 i;

    part->timeLeft--;
    part->lifetime++;

    if (part->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    time = part->timeLeft;

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        s32 unk_2C_2 = part->timeLeft;

        if (part->unk_34 <= 0 || --part->unk_34 <= 0) {
            if (unk_2C_2 >= 7) {
                part->scaleY = 1.0f;
                part->scaleX = 1.0f;
            } else {
                part->scaleX = D_E0080AF0[unk_2C_2];
                part->scaleY = D_E0080B0C[unk_2C_2];
            }

            part->pos.x += part->vel.x;
            part->pos.y += part->vel.y;
            part->pos.z += part->vel.z;
            part->angle = sin_deg(i * 38 + time * 12) * -30.0f;
            part->offsetX = cos_deg(i * 38 + time * 12) * 8.0f;

            if (time < 20) {
                part->offsetX *= (f32) time * 0.05;
                part->angle *= (f32) time * 0.05;
            }

            if (time < 10) {
                part->alpha = time * 25;
                part->vel.y *= 0.9;
            }

            part->timeLeft++;
        }
    }
}

void recover_render(EffectInstance* effect) {
}

void func_E008042C(EffectInstance* effect) {
    func_E0080448(effect);
}

void func_E0080448(EffectInstance* effect) {
    RecoverFXData* part = ((EffectInstance*)effect)->data.recover;
    s32 i;
    s32 type;
    s32 unk_40;
    s32 unk_44 = part->unk_44;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(sp18, part->pos.x, part->pos.y, part->pos.z);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp98);
    guMtxF2L(sp98, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    type = part->type;
    unk_40 = part->unk_40;

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        if (part->unk_34 <= 0) {
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, part->alpha);

            if (part->alpha == 255) {
                gDPSetRenderMode(gMainGfxPos++, AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM));
                gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA);
            } else {
                gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
                gDPSetCombineMode(gMainGfxPos++, PM_CC_49, PM_CC_49);
            }

            gSPDisplayList(gMainGfxPos++, (type == 0 || type == 2) ?
                (unk_44 == 0 ? D_09003200_385000 : D_09003298_385098) :
                D_09003330_385130);

            guTranslateF(sp18, part->pos.x + part->offsetX, part->pos.y, part->pos.z);
            guScaleF(sp58, part->scaleX, part->scaleY, 1.0f);
            guMtxCatF(sp58, sp18, sp18);
            guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            guRotateF(sp18, part->angle, 0.0f, 0.0f, 1.0f);
            guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            if (i == 1 && type != 2) {
                gSPDisplayList(gMainGfxPos++, D_090033D0_3851D0);
                gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
                gSPDisplayList(gMainGfxPos++, D_090034D0_3852D0);

                if (unk_40 < 10 && unk_44 == 0) {
                    gSPDisplayList(gMainGfxPos++, D_E0080AC0[unk_40]);
                    gSPDisplayList(gMainGfxPos++, type == 0 ? D_09003410_385210 : D_09003470_385270);
                } else {
                    s32 ones = unk_40 % 10;
                    s32 tens = unk_44 == 0 ? (unk_40 / 10) : 10;

                    gSPDisplayList(gMainGfxPos++, D_E0080AC0[ones]);
                    gSPDisplayList(gMainGfxPos++, type == 0 ? D_09003450_385250 : D_090034B0_3852B0);
                    gSPDisplayList(gMainGfxPos++, D_E0080AC0[tens]);
                    gSPDisplayList(gMainGfxPos++, type == 0 ? D_09003430_385230 : D_09003490_385290);
                }
            } else {
                gSPDisplayList(gMainGfxPos++, D_090033F0_3851F0);
                gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
            }

            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
