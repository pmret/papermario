#include "hos_02.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

u16 N(HaloScalePhaseAngle) = 0;

void N(build_gfx_lamp_halos)(void) {
    f32 scale = ((sins(N(HaloScalePhaseAngle)) * (1.0f / 0x8000)) * 0.5 * 0.5) + 1.05;

    N(HaloScalePhaseAngle) += (s32)RAD_TO_BINANG(25.1720);
    guScale(&gDisplayContext->matrixStack[gMatrixListPos], scale, scale, scale);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
}

u16 N(YellowStarPhaseAngle) = 0;

void N(build_gfx_yellow_stars)(void) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    mdl_get_copied_vertices(VTX_COPY_0, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(N(YellowStarPhaseAngle) * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 100;
        colors[1] = temp1 * 155 / 0x8000 + 100;

        temp3 = sins(N(YellowStarPhaseAngle) / 0x8000 * (((i / 2) % 3 + 1) << 15) + N(YellowStarPhaseAngle) / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000;
    }

    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(VTX_COPY_0));
    N(YellowStarPhaseAngle) += (s32)RAD_TO_BINANG(25.1898);
}

u16 N(BlueStarPhaseAngle) = 0;

void N(build_gfx_blue_stars)(void) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    mdl_get_copied_vertices(VTX_COPY_1, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(N(BlueStarPhaseAngle) * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 48.62745098039216;
        colors[1] = temp1 * 155 / 0x8000 + 89.41176470588236;

        temp3 = sins(N(BlueStarPhaseAngle) / 0x8000 * (((i / 2) % 3 + 1) << 15) + N(BlueStarPhaseAngle) / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000 + 99.6078431372549;
    }

    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(VTX_COPY_1));
    N(BlueStarPhaseAngle) += (s32)RAD_TO_BINANG(25.1898);
}

u16 N(GreenStarPhaseAngle) = 0;

void N(build_gfx_green_stars)(void) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    mdl_get_copied_vertices(VTX_COPY_2, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(N(GreenStarPhaseAngle) * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 67.45098039215686;
        colors[1] = temp1 * 155 / 0x8000 + 100.0;

        temp3 = sins(N(GreenStarPhaseAngle) / 0x8000 * (((i / 2) % 3 + 1) << 15) + N(GreenStarPhaseAngle) / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000 + 59.21568627450981;
    }

    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(VTX_COPY_2));
    N(GreenStarPhaseAngle) += (s32)RAD_TO_BINANG(25.1898);
}

u16 N(PinkStarPhaseAngle) = 0;

void N(build_gfx_pink_stars)(void) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    mdl_get_copied_vertices(VTX_COPY_3, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(N(PinkStarPhaseAngle) * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 100.0;
        colors[1] = temp1 * 155 / 0x8000 + 80.3921568627451;

        temp3 = sins(N(PinkStarPhaseAngle) / 0x8000 * (((i / 2) % 3 + 1) << 15)  + N(PinkStarPhaseAngle) / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000 + 96.07843137254902;
    }

    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(VTX_COPY_3));
    N(PinkStarPhaseAngle) += (s32)RAD_TO_BINANG(25.1898);
}

API_CALLABLE(N(func_80240EF4_A17114)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    effect->data.unk_75->unk_78 = 190.0f;
    effect->data.unk_75->unk_7C = 220.0f;
    effect->data.unk_75->unk_68 = 0.7f;
    effect->data.unk_75->masterAlpha = 255;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240F68_A17188)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    effect->data.unk_75->unk_78 = 170.0f;
    effect->data.unk_75->unk_7C = 170.0f;
    effect->data.unk_75->unk_68 = 2.0f;
    effect->data.unk_75->masterAlpha = 255;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupModelFX) = {
    EVT_PLAY_EFFECT(EFFECT_75, 1, -1105, -86, 230, 1, -1)
    EVT_SET(MV_StarBeamEffect, LVarF)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(hos_02_ENTRY_0)
            EVT_CALL(N(func_80240F68_A17188), MV_StarBeamEffect)
        EVT_CASE_EQ(hos_02_ENTRY_1)
            EVT_CALL(N(func_80240EF4_A17114), MV_StarBeamEffect)
    EVT_END_SWITCH
    EVT_CALL(EnableTexPanning, MODEL_o380, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o395, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o549, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o552, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   80, -200,  -50,  100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    // custom gfx for lantern glow halos, flags for the entire lamp posts
    EVT_CALL(SetModelCustomGfx, MODEL_o414, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o415, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o399, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o398, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o347, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o348, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_0, EVT_PTR(N(build_gfx_lamp_halos)), NULL)
    EVT_CALL(SetModelFlags, MODEL_o414, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o415, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o399, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o398, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o347, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o348, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o407, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o408, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o413, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o446, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o447, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o448, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o456, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o457, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o458, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    // yellow stars
    EVT_CALL(MakeLocalVertexCopy, VTX_COPY_0, MODEL_o466, TRUE)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_1, EVT_PTR(N(build_gfx_yellow_stars)), NULL)
    EVT_CALL(SetModelCustomGfx, MODEL_o466, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o467, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o468, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o469, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o470, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o471, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o472, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o541, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o542, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o545, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o548, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelFlags, MODEL_o466, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o467, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o468, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o469, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o470, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o471, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o472, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o541, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o542, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o545, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o548, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
    // blue stars
    EVT_CALL(MakeLocalVertexCopy, VTX_COPY_1, MODEL_o466, TRUE)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_2, EVT_PTR(N(build_gfx_blue_stars)), NULL)
    EVT_CALL(SetModelCustomGfx, MODEL_o543, CUSTOM_GFX_2, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o539, CUSTOM_GFX_2, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelFlags, MODEL_o543, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o539, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
    // green stars
    EVT_CALL(MakeLocalVertexCopy, VTX_COPY_2, MODEL_o466, TRUE)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_3, EVT_PTR(N(build_gfx_green_stars)), NULL)
    EVT_CALL(SetModelCustomGfx, MODEL_o546, CUSTOM_GFX_3, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o540, CUSTOM_GFX_3, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelFlags, MODEL_o546, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o540, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
    // pink stars
    EVT_CALL(MakeLocalVertexCopy, VTX_COPY_3, MODEL_o466, TRUE)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_4, EVT_PTR(N(build_gfx_pink_stars)), NULL)
    EVT_CALL(SetModelCustomGfx, MODEL_o544, CUSTOM_GFX_4, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o547, CUSTOM_GFX_4, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelFlags, MODEL_o544, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
    EVT_CALL(SetModelFlags, MODEL_o547, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(MakeLerp, -13, 13, 20, EASING_COS_IN_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(TranslateModel, MODEL_o466, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o470, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o471, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o472, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o541, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o543, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o545, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o547, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o539, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(MakeLerp, 13, -13, 20, EASING_COS_IN_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(TranslateModel, MODEL_o466, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o470, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o471, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o472, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o541, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o543, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o545, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o547, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o539, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(MakeLerp, 13, -13, 20, EASING_COS_IN_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(TranslateModel, MODEL_o467, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o468, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o469, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o542, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o544, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o546, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o548, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o540, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(MakeLerp, -13, 13, 20, EASING_COS_IN_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(TranslateModel, MODEL_o467, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o468, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o469, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o542, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o544, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o546, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o548, 0, LVar0, 0)
                EVT_CALL(TranslateModel, MODEL_o540, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(MakeLerp, 0, 360, 50, EASING_COS_IN_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(RotateModel, MODEL_o466, LVar0, 0, 1, 0)
                EVT_CALL(RotateModel, MODEL_o470, LVar0, 0, 1, 0)
                EVT_CALL(RotateModel, MODEL_o471, LVar0, 0, 1, 0)
                EVT_CALL(RotateModel, MODEL_o472, LVar0, 0, 1, 0)
                EVT_CALL(RotateModel, MODEL_o541, LVar0, 0, 1, 0)
                EVT_CALL(RotateModel, MODEL_o543, LVar0, 0, 1, 0)
                EVT_CALL(RotateModel, MODEL_o545, LVar0, 0, 1, 0)
                EVT_CALL(RotateModel, MODEL_o547, LVar0, 0, 1, 0)
                EVT_CALL(RotateModel, MODEL_o539, LVar0, 0, 1, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, 360, 0, 44, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o467, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_o468, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_o469, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_o542, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_o544, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_o546, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_o548, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_o540, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
