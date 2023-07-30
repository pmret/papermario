#include "common.h"
#include "effects_internal.h"

void whirlwind_init(EffectInstance* effect);
void whirlwind_update(EffectInstance* effect);
void whirlwind_render(EffectInstance* effect);
void whirlwind_appendGfx(void* effect);

extern Gfx D_09000400_3D3D30[];

EffectInstance* whirlwind_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance *effect;
    WhirlwindFXData* part;
    s32 numParts;
    s32 i;

    bp.init = whirlwind_init;
    bp.update = whirlwind_update;
    bp.renderWorld = whirlwind_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_WHIRLWIND;

    numParts = 1;
    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data.whirlwind = general_heap_malloc(effect->numParts * sizeof(*part));
    ASSERT(part != NULL);

    part->unk_00 = arg0;
    part->unk_14 = 0;
    if (arg5 <= 0) {
        part->unk_10 = 1000;
    } else {
        part->unk_10 = arg5;
    }
    part->primAlpha = 0;
    part->pos.x = arg1;
    part->pos.y = arg2;
    part->pos.z = arg3;
    part->unk_34 = arg4;

    part->primR = 255;
    part->primG = 255;
    part->primB = 255;

    part->envR = 255;
    part->envG = 255;
    part->envB = 235;

    for(i = 0; i < MAX_WHIRLWIND_SEGMENTS; i++) {
        part->unk_38[i] = arg1;
        part->unk_58[i] = arg2;
        part->unk_78[i] = arg3;
        part->unk_98[i] = i * 0.2 + 1.0;
        part->unk_B8[i] = rand_int(360);
        part->unk_D8[i] = rand_int(100) * 0.1 + 2.0;
        part->unk_F8[i] = rand_int(30) * 0.1;
        part->unk_118[i] = 0;
    }
    part->unk_138 = 0;
    part->unk_13C = 0;
    part->unk_140 = 0;

    return effect;
}

void whirlwind_init(EffectInstance* effect) {
}

void whirlwind_update(EffectInstance* effect) {
    s32 temp_a2;
    s32 temp_v1_3;
    WhirlwindFXData* part;
    s32 i;
    f32 temp;

    part = effect->data.whirlwind;
    if ((effect->flags & FX_INSTANCE_FLAG_DISMISS)) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        part->unk_10 = 16;
    }
    if (part->unk_10 < 1000) {
        part->unk_10--;
    }
    part->unk_14++;
    if (part->unk_10 < 0) {
        remove_effect(effect);
        return;
    }
    temp = part->unk_34;
    temp_v1_3 = part->unk_10;
    temp_a2 = part->unk_14;
    if (temp_v1_3 < 0x10) {
        part->primAlpha = temp_v1_3 * 16;
    }

    if (temp_a2 < 0x10) {
        part->primAlpha = temp_a2 * 16 + 15;
    }
    part->unk_38[0] = part->pos.x;
    part->unk_58[0] = part->pos.y;
    part->unk_78[0] = part->pos.z;

    for (i = MAX_WHIRLWIND_SEGMENTS - 1; i > 0; i--) {
        part->unk_118[i] = (part->unk_38[i - 1] - part->unk_38[i]) * 4.0f;
        part->unk_38[i] = part->unk_38[i - 1];
        part->unk_58[i] = part->unk_58[i - 1] + temp * 5.0f;
        part->unk_78[i] = part->unk_78[i - 1];
        if (part->unk_118[i] > 90.0f) {
            part->unk_118[i] = 90.0f;
        } else if (part->unk_118[i] < -90.0f) {
            part->unk_118[i] = -90.0f;
        }
    }

    part->unk_138 += 10.0f;
    part->unk_13C += 12.96;
    part->unk_140 += 17.28;
    if (part->unk_13C > 64.0f) {
        part->unk_13C -= 64.0f;
    }
    if (part->unk_140 > 64.0f) {
        part->unk_140 -= 64.0f;
    }
    for(i = 0; i < MAX_WHIRLWIND_SEGMENTS; i++) {
        part->unk_B8[i] += part->unk_D8[i];
    }
}

void whirlwind_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* queuedTask;

    renderTask.appendGfx = whirlwind_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    queuedTask = queue_render_task(&renderTask);
    queuedTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00CE470(void) {
}

void whirlwind_appendGfx(void* effect) {
    Matrix4f sp20;
    Matrix4f sp60;
    s32 spA0;
    s32 primAlpha;
    Gfx* triangleDisplayList;
    Vtx* vertexBuffer;
    s32 spB0;
    s32 spB4;
    f32 spB8;
    Gfx* whirlwindMainDisplayList;
    Gfx* savedPos;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 var_f4;
    f32 f22;
    s32 i;
    EffectInstance* eff = (EffectInstance*)effect;
    WhirlwindFXData* data = eff->data.whirlwind;

    spA0 = data->unk_10;
    primAlpha = data->primAlpha >> 1;
    spB8 = data->unk_34;
    spB0 = data->unk_13C * 4.0f;
    spB4 = data->unk_140 * 4.0f;
    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, OS_K0_TO_PHYSICAL(eff->graphics->data));

    guTranslateF(sp20, 0.0f, 0.0f, 0.0f);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_09000400_3D3D30);

    // Reserve 0x208 bytes (65 commands) for a vertex buffer (2x16 Vtx + space for the current command)
    gSPBranchList(gMainGfxPos, &gMainGfxPos[65]);
    vertexBuffer = (Vtx*)(gMainGfxPos + 1);

    // set the current position we're writing gfx commands to past the vertex buffer
    gMainGfxPos = &gMainGfxPos[65];

    // fill the vertex buffer; 2 sets of 16 verticies
    for (i = 0; i <= (360 / 24); i++) {
        Vtx* vtx = &vertexBuffer[i];
        vtx->v.ob[0] = cos_deg(i * (360 / 15)) * 100.0f;
        vtx->v.ob[1] = 0;
        vtx->v.ob[2] = sin_deg(i * (360 / 15)) * 100.0f;
        vtx->v.tc[0] = i * 128;
        vtx->v.tc[1] = 0;

        vtx = &vertexBuffer[i + (360 / 24 + 1)];
        vtx->v.ob[0] = cos_deg(i * (360 / 15)) * 100.0f;
        vtx->v.ob[1] = 0;
        vtx->v.ob[2] = sin_deg(i * (360 / 15)) * 100.0f;
        vtx->v.tc[0] = i * 512;
        vtx->v.tc[1] = 1024;
    }

    // Reserve 0x88 bytes (17 commands, including this one) for a separate dynamically generated display list
    gSPBranchList(gMainGfxPos, &gMainGfxPos[17]);

    // Get a reference to the dynamically generated display list
    triangleDisplayList = ++gMainGfxPos;

    // Generate display list
    for (i = 0; i < 15; i++) {
        gSP2Triangles(gMainGfxPos++, i + 0x10, i + 1, i, 0, i + 0x10, i + 0x11, i + 1, 0);
    }

    // This marks the end of our dynamically generated display list, return control back to the main display list
    gSPEndDisplayList(gMainGfxPos++);

    guScaleF(sp20, 0.1f, 0.1f, 0.1f);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    // Save position to later insert a branch around the commands that follow this
    savedPos = gMainGfxPos++;

    // Save position of main display list
    whirlwindMainDisplayList = gMainGfxPos;

    // Generate main display list
    for(i = 0; i < (MAX_WHIRLWIND_SEGMENTS - 1); i++) {
        guPositionF(sp20, 0.0f, 0.0f, data->unk_118[i], 1.0f, data->unk_38[i] * 10.0f, data->unk_58[i] * 10.0f, data->unk_78[i] * 10.0f);
        guRotateF(sp60, data->unk_138 + i * i, -0.03f, 1.0f, 0.1f);
        guMtxCatF(sp60, sp20, sp20);
        var_f4 = data->unk_98[i] * spB8;
        if (spA0 < 0x10) {
            var_f4 += (127 - primAlpha) * 0.02f;
        }
        guScaleF(sp60, var_f4, spB8, var_f4);
        guMtxCatF(sp60, sp20, sp20);
        temp_f20_2 = data->unk_F8[i] * 10.0f;
        f22 = data->unk_B8[i];
        guTranslateF(sp60, temp_f20_2 * sin_deg(f22), 0.0f, temp_f20_2 * cos_deg(f22));
        guMtxCatF(sp60, sp20, sp20);
        guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPVertex(gMainGfxPos++, vertexBuffer, 16, 0);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);

        guPositionF(sp20, 0.0f, 0.0f, data->unk_118[i + 1], 1.0f, data->unk_38[i + 1] * 10.0f, data->unk_58[i + 1] * 10.0f, data->unk_78[i + 1] * 10.0f);
        guRotateF(sp60, data->unk_138 + i * i, 0.03f, 1.0f, 0.0f);
        guMtxCatF(sp60, sp20, sp20);
        guScaleF(sp60, data->unk_98[i + 1] * spB8, spB8, data->unk_98[i + 1] * spB8);
        guMtxCatF(sp60, sp20, sp20);
        temp_f20_3 = data->unk_F8[i] * 10.0f;
        guTranslateF(sp60, temp_f20_3 * sin_deg(data->unk_B8[i]), 0.0f, temp_f20_3 * cos_deg(data->unk_B8[i]));
        guMtxCatF(sp60, sp20, sp20);
        guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPVertex(gMainGfxPos++, &vertexBuffer[16], 16, 16);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);

        gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, spB0 + i * 16, 0, (spB0 + i * 16 + 63) << 2, 31 << 2);
        gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE + 1, spB4 + i * 8, 0, (spB4 + i * 8 + 63) << 2, 31 << 2);

        // Call the display list to create triangles from the verticies
        gSPDisplayList(gMainGfxPos++, triangleDisplayList);
    }

    gSPEndDisplayList(gMainGfxPos++);

    // Now that the length of our display list is known, insert a branch at the previously saved location
    gSPBranchList(savedPos, gMainGfxPos);
    gSPClearGeometryMode(gMainGfxPos++, G_CULL_BOTH);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->primR, data->primG, data->primB, primAlpha);
    gDPSetEnvColor(gMainGfxPos++, data->envR, data->envG, data->envB, 32);

    // Call the main display list
    gSPDisplayList(gMainGfxPos++, whirlwindMainDisplayList);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
