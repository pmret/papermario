#include "common.h"
#include "effects_internal.h"

void lil_oink_appendGfx(void* effect);
void lil_oink_init(EffectInstance* effect);
void lil_oink_update(EffectInstance* effect);
void lil_oink_render(EffectInstance* effect);

extern Gfx D_09002D70[];
extern Gfx D_09002DD8[];
extern Gfx D_09002E70[];
extern Gfx D_09002E98[];
extern Gfx D_09002F30[];
extern Gfx D_09002FC8[];
extern Gfx D_09003060[];
extern Gfx D_090030F8[];
extern Gfx D_09003190[];
extern Gfx D_09003228[];
extern Gfx D_090032C0[];
extern Gfx D_09003358[];
extern Gfx D_09003370[];
extern Gfx D_09003388[];

Gfx* D_E01146A0[] = {
    D_09003358, D_09003370, D_09003388,
    D_09003358, D_09003370, D_09003388,
    D_09003358, D_09003370, D_09003388,
    D_09003358, D_09003370, D_09003388,
    D_09003358, D_09003370, D_09003388,
    D_09003358, D_09003370, D_09003388,
    D_09003358, D_09003370, D_09003388,
    D_09003358, D_09003370, D_09003388,
    D_09003358, D_09003370, D_09003388,
    D_09003358, D_09003370, D_09003388
};

Gfx* D_E0114718[] = {
     D_09002DD8, D_09002E70, D_09002E98, D_09002F30, D_09002FC8, D_09003060, D_090030F8, D_09003190, D_09003228,
     D_090032C0
};

s8 D_E0114740[] = { 1, 2, 1, 0 };

EffectInstance* lil_oink_main(void) {
    EffectBlueprint bp;
    EffectInstance* effect;
    LilOinkFXData* data;
    s32 numParts = 1;
    s32 i;

    bp.unk_00 = 0;
    bp.init = lil_oink_init;
    bp.update = lil_oink_update;
    bp.renderWorld = lil_oink_render;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_LIL_OINK;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.lilOink = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->unk_04 = 0;
    data->unk_00 = 1000;

    for (i = 0; i < MAX_LIL_OINKS; i++) {
        data->x[i] = 0.0f;
        data->y[i] = 0.0f;
        data->z[i] = 0.0f;
        data->rot[i] = 0.0f;
        data->flags[i] = 0;
        data->unk_FA[i] = 1;
        data->unk_105[i] = 1;
        data->jumpOffset[i] = 0.0f;
        data->unk_13C[i] = 0;
    }

    return effect;
}

void lil_oink_init(EffectInstance* effect) {
}

void lil_oink_update(EffectInstance* effect) {
    LilOinkFXData* data = effect->data.lilOink;
    s32 i;

    data->unk_04++;

    for (i = 0; i < MAX_LIL_OINKS; i++) {
        s32 tmp13C = data->unk_13C[i];
        s32 cond = FALSE;

        switch (data->unk_FA[i]) {
            case 0:
                cond = TRUE;
                break;
            case 1:
                data->unk_105[i] = 1;
                cond = TRUE;
                break;
            case 3:
                data->unk_105[i] = D_E0114740[tmp13C % ARRAY_COUNT(D_E0114740)];
                data->rot[i] = data->rot[i] + shim_sin_deg(tmp13C * 10);
                if (tmp13C >= 36) {
                    cond = TRUE;
                    data->unk_13C[i] = 0;
                }
                break;
            case 2:
                data->unk_105[i] = D_E0114740[tmp13C % ARRAY_COUNT(D_E0114740)];
                data->jumpOffset[i] = shim_sin_deg(tmp13C * 20) * 2.0f;
                cond = TRUE;
                if (tmp13C >= 9) {
                    data->jumpOffset[i] = 0.0f;
                    data->unk_13C[i] = 0;
                }
                break;
            case 4:
                data->unk_105[i] = D_E0114740[tmp13C % ARRAY_COUNT(D_E0114740)];
                data->jumpOffset[i] = shim_sin_deg(tmp13C * 20) * 4.0f;
                if (!(tmp13C < 9)) {
                    cond = TRUE;
                    data->jumpOffset[i] = 0.0f;
                    data->unk_13C[i] = 0;
                }
                break;
            case 5:
            default:
                data->unk_105[i] = D_E0114740[tmp13C % ARRAY_COUNT(D_E0114740)];
                data->jumpOffset[i] = shim_sin_deg(tmp13C * 5) * 12.0f;
                if (!(tmp13C < 36)) {
                    cond = TRUE;
                    data->jumpOffset[i] = 0.0f;
                    data->unk_13C[i] = 0;
                }
                break;
        }
        data->unk_13C[i]++;
        if (cond) {
            if (data->flags[i] & 2) {
                data->flags[i] &= ~2;
                data->unk_13C[i] = 0;
                data->unk_FA[i] = data->unk_EF[i];
            }
        }
    }
}

void lil_oink_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = lil_oink_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void lil_oink_appendGfx(void* effect) {
    Matrix4f sp20;
    EffectInstance* eff = effect;
    LilOinkFXData* data = eff->data.lilOink;
    s32 var_s4 = data->unk_04 * 30;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x9, VIRTUAL_TO_PHYSICAL(eff->graphics->data));

    gSPDisplayList(gMasterGfxPos++, D_09002D70);
    gSPLookAt(gMasterGfxPos++, &gDisplayContext->lookAt);

    for (i = 0; i < MAX_LIL_OINKS; i++) {
        if (data->flags[i] & 1) {
            shim_guPositionF(sp20, 0.0f, 180.0f - data->rot[i], 0.0f, 1.0f,
                             data->x[i], data->y[i] + data->jumpOffset[i], data->z[i]);
            shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, D_E0114718[data->type[i]]);
            if (data->type[i] == 8 || data->type[i] == 9) {
                f32 temp_f0 = shim_sin_deg(var_s4) * 63.0f;
                s32 primColor = (s32)(temp_f0 + 63.0f) & 0xFF;

                gDPSetPrimColor(gMasterGfxPos++, 0, 0, primColor, primColor, primColor, 0);
            }
            gSPDisplayList(gMasterGfxPos++, D_E01146A0[(data->type[i] * 3) + data->unk_105[i]]);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }
        var_s4 += 20;
    }
}
