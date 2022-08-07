#include "common.h"
#include "model.h"
#include "effects_internal.h"

void bombette_breaking_appendGfx(void* effect);
void bombette_breaking_init(EffectInstance* effect);
void bombette_breaking_update(EffectInstance* effect);
void bombette_breaking_render(EffectInstance* effect);

extern Gfx D_090018C0[];
extern Gfx D_09001D00[];
extern Gfx D_09001CC8[];
extern Gfx D_09001C80[];
extern Gfx D_090017D0[];

Gfx* D_E0084E10[] = { D_090018C0, D_090018C0, D_090018C0 };
Gfx* D_E0084E1C[] = { D_09001D00, D_09001CC8, D_09001C80 };
Gfx* D_E0084E28[] = { D_090017D0, D_090017D0, D_090017D0 };

void (*D_E0084E34)(u16, f32*, f32*, f32*, f32*, f32*, f32*) = get_model_center_and_size;
Model* (*D_E0084E38)(s32) = get_model_from_list_index;
s32 (*D_E0084E3C)(s32) = get_model_list_index_from_tree_index;

void func_E0084000(s32 modelID, f32* centerX, f32* centerY, f32* centerZ, f32* sizeX, f32* sizeY, f32* sizeZ) {
    D_E0084E34(modelID, centerX, centerY, centerZ, sizeX, sizeY, sizeZ);
}

Model* func_E008403C(s32 listIndex) {
    return D_E0084E38(listIndex);
}

s32 func_E0084060(s32 listIndex) {
    return D_E0084E3C(listIndex);
}

INCLUDE_ASM(s32, "effects/bombette_breaking", bombette_breaking_main);

void bombette_breaking_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/bombette_breaking", bombette_breaking_update);

void bombette_breaking_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = bombette_breaking_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/bombette_breaking", bombette_breaking_appendGfx);
