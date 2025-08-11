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
    PlayEffect(EFFECT_75, 1, -1105, -86, 230, 1, -1)
    Set(MV_StarBeamEffect, LVarF)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(hos_02_ENTRY_0)
            Call(N(func_80240F68_A17188), MV_StarBeamEffect)
        CaseEq(hos_02_ENTRY_1)
            Call(N(func_80240EF4_A17114), MV_StarBeamEffect)
    EndSwitch
    Call(EnableTexPanning, MODEL_o380, true)
    Call(EnableTexPanning, MODEL_o395, true)
    Call(EnableTexPanning, MODEL_o549, true)
    Call(EnableTexPanning, MODEL_o552, true)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   80, -200,  -50,  100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    // custom gfx for lantern glow halos, flags for the entire lamp posts
    Call(SetModelCustomGfx, MODEL_o414, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o415, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o399, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o398, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o347, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o348, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_0, Ref(N(build_gfx_lamp_halos)), nullptr)
    Call(SetModelFlags, MODEL_o414, MODEL_FLAG_BILLBOARD, true)
    Call(SetModelFlags, MODEL_o415, MODEL_FLAG_BILLBOARD, true)
    Call(SetModelFlags, MODEL_o399, MODEL_FLAG_BILLBOARD, true)
    Call(SetModelFlags, MODEL_o398, MODEL_FLAG_BILLBOARD, true)
    Call(SetModelFlags, MODEL_o347, MODEL_FLAG_BILLBOARD, true)
    Call(SetModelFlags, MODEL_o348, MODEL_FLAG_BILLBOARD, true)
    Call(SetModelFlags, MODEL_o407, MODEL_FLAG_BILLBOARD, true)
    Call(SetModelFlags, MODEL_o408, MODEL_FLAG_BILLBOARD, true)
    Call(SetModelFlags, MODEL_o413, MODEL_FLAG_BILLBOARD, true)
    Call(SetModelFlags, MODEL_o446, MODEL_FLAG_BILLBOARD, true)
    Call(SetModelFlags, MODEL_o447, MODEL_FLAG_BILLBOARD, true)
    Call(SetModelFlags, MODEL_o448, MODEL_FLAG_BILLBOARD, true)
    Call(SetModelFlags, MODEL_o456, MODEL_FLAG_BILLBOARD, true)
    Call(SetModelFlags, MODEL_o457, MODEL_FLAG_BILLBOARD, true)
    Call(SetModelFlags, MODEL_o458, MODEL_FLAG_BILLBOARD, true)
    // yellow stars
    Call(MakeLocalVertexCopy, VTX_COPY_0, MODEL_o466, true)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_1, Ref(N(build_gfx_yellow_stars)), nullptr)
    Call(SetModelCustomGfx, MODEL_o466, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o467, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o468, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o469, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o470, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o471, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o472, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o541, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o542, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o545, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o548, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetModelFlags, MODEL_o466, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, true)
    Call(SetModelFlags, MODEL_o467, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, true)
    Call(SetModelFlags, MODEL_o468, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, true)
    Call(SetModelFlags, MODEL_o469, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, true)
    Call(SetModelFlags, MODEL_o470, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, true)
    Call(SetModelFlags, MODEL_o471, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, true)
    Call(SetModelFlags, MODEL_o472, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, true)
    Call(SetModelFlags, MODEL_o541, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, true)
    Call(SetModelFlags, MODEL_o542, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, true)
    Call(SetModelFlags, MODEL_o545, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, true)
    Call(SetModelFlags, MODEL_o548, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, true)
    // blue stars
    Call(MakeLocalVertexCopy, VTX_COPY_1, MODEL_o466, true)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_2, Ref(N(build_gfx_blue_stars)), nullptr)
    Call(SetModelCustomGfx, MODEL_o543, CUSTOM_GFX_2, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o539, CUSTOM_GFX_2, ENV_TINT_UNCHANGED)
    Call(SetModelFlags, MODEL_o543, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, true)
    Call(SetModelFlags, MODEL_o539, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, true)
    // green stars
    Call(MakeLocalVertexCopy, VTX_COPY_2, MODEL_o466, true)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_3, Ref(N(build_gfx_green_stars)), nullptr)
    Call(SetModelCustomGfx, MODEL_o546, CUSTOM_GFX_3, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o540, CUSTOM_GFX_3, ENV_TINT_UNCHANGED)
    Call(SetModelFlags, MODEL_o546, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, true)
    Call(SetModelFlags, MODEL_o540, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, true)
    // pink stars
    Call(MakeLocalVertexCopy, VTX_COPY_3, MODEL_o466, true)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_4, Ref(N(build_gfx_pink_stars)), nullptr)
    Call(SetModelCustomGfx, MODEL_o544, CUSTOM_GFX_4, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o547, CUSTOM_GFX_4, ENV_TINT_UNCHANGED)
    Call(SetModelFlags, MODEL_o544, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, true)
    Call(SetModelFlags, MODEL_o547, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, true)
    Thread
        Loop(0)
            Call(MakeLerp, -13, 13, 20, EASING_COS_IN_OUT)
            Loop(0)
                Call(UpdateLerp)
                Call(TranslateModel, MODEL_o466, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o470, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o471, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o472, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o541, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o543, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o545, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o547, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o539, 0, LVar0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(MakeLerp, 13, -13, 20, EASING_COS_IN_OUT)
            Loop(0)
                Call(UpdateLerp)
                Call(TranslateModel, MODEL_o466, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o470, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o471, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o472, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o541, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o543, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o545, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o547, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o539, 0, LVar0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndLoop
    EndThread
    Thread
        Loop(0)
            Call(MakeLerp, 13, -13, 20, EASING_COS_IN_OUT)
            Loop(0)
                Call(UpdateLerp)
                Call(TranslateModel, MODEL_o467, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o468, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o469, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o542, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o544, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o546, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o548, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o540, 0, LVar0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(MakeLerp, -13, 13, 20, EASING_COS_IN_OUT)
            Loop(0)
                Call(UpdateLerp)
                Call(TranslateModel, MODEL_o467, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o468, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o469, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o542, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o544, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o546, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o548, 0, LVar0, 0)
                Call(TranslateModel, MODEL_o540, 0, LVar0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndLoop
    EndThread
    Thread
        Loop(0)
            Call(MakeLerp, 0, 360, 50, EASING_COS_IN_OUT)
            Loop(0)
                Call(UpdateLerp)
                Call(RotateModel, MODEL_o466, LVar0, 0, 1, 0)
                Call(RotateModel, MODEL_o470, LVar0, 0, 1, 0)
                Call(RotateModel, MODEL_o471, LVar0, 0, 1, 0)
                Call(RotateModel, MODEL_o472, LVar0, 0, 1, 0)
                Call(RotateModel, MODEL_o541, LVar0, 0, 1, 0)
                Call(RotateModel, MODEL_o543, LVar0, 0, 1, 0)
                Call(RotateModel, MODEL_o545, LVar0, 0, 1, 0)
                Call(RotateModel, MODEL_o547, LVar0, 0, 1, 0)
                Call(RotateModel, MODEL_o539, LVar0, 0, 1, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndLoop
    EndThread
    Loop(0)
        Call(MakeLerp, 360, 0, 44, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o467, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_o468, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_o469, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_o542, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_o544, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_o546, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_o548, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_o540, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndLoop
    Return
    End
};
