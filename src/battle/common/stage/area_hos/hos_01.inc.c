#include "battle/battle.h"
#include "mapfs/hos_bt01_shape.h"

#define NAMESPACE A(hos_01)

u16 N(StarPhaseAngles)[16] = {};

void N(build_gfx_yellow_stars)(s32 index) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    index--;
    mdl_get_copied_vertices(index, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        Vtx* vtx = &copiedVertices[i];
        s16 temp1 = (sins(N(StarPhaseAngles)[index] * (i % 3 + 1) + i) + 0x8000) / 2;
        s32 temp2 = temp1 * 155;
        vtx->v.cn[0] = temp2 / 0x8000 + 100;
        vtx->v.cn[1] = temp2 / 0x8000 + 100;

        temp3 = sins(N(StarPhaseAngles)[index] / 0x8000 * (((i / 2) % 3 + 1) << 15)  + N(StarPhaseAngles)[index] / 0x4000 * 0x8000 + i) + 0x8000;
        vtx->v.cn[2] = vtx->v.cn[0] * temp3 / 0x10000;
    }

    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(index));
    N(StarPhaseAngles)[index] += (s32)RAD_TO_BINANG(25.1898);
}

void N(build_gfx_blue_stars)(s32 index) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    index--;
    mdl_get_copied_vertices(index, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(N(StarPhaseAngles)[index] * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 48.62745098039216;
        colors[1] = temp1 * 155 / 0x8000 + 89.41176470588236;

        temp3 = sins(N(StarPhaseAngles)[index] / 0x8000 * (((i / 2) % 3 + 1) << 15)  + N(StarPhaseAngles)[index] / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000 + 99.6078431372549;
    }

    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(index));
    N(StarPhaseAngles)[index] += (s32)RAD_TO_BINANG(25.1898);
}

void N(build_gfx_green_stars)(s32 index) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    index--;
    mdl_get_copied_vertices(index, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(N(StarPhaseAngles)[index] * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 67.45098039215686;
        colors[1] = temp1 * 155 / 0x8000 + 100.0;

        temp3 = sins(N(StarPhaseAngles)[index] / 0x8000 * (((i / 2) % 3 + 1) << 15)  + N(StarPhaseAngles)[index] / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000 + 59.21568627450981;
    }

    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(index));
    N(StarPhaseAngles)[index] += (s32)RAD_TO_BINANG(25.1898);
}

void N(build_gfx_pink_stars)(s32 index) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    index--;
    mdl_get_copied_vertices(index, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(N(StarPhaseAngles)[index] * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 100.0;
        colors[1] = temp1 * 155 / 0x8000 + 80.3921568627451;

        temp3 = sins(N(StarPhaseAngles)[index] / 0x8000 * (((i / 2) % 3 + 1) << 15)  + N(StarPhaseAngles)[index] / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000 + 96.07843137254902;
    }

    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(index));
    N(StarPhaseAngles)[index] += (s32)RAD_TO_BINANG(25.1898);
}

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)

    Call(MakeLocalVertexCopy, VTX_COPY_0, MODEL_o345, TRUE)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_1, Ref(N(build_gfx_yellow_stars)), NULL)
    Call(SetModelCustomGfx, MODEL_o345, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetModelFlags, MODEL_o345, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)

    Call(MakeLocalVertexCopy, VTX_COPY_1, MODEL_o338, TRUE)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_2, Ref(N(build_gfx_yellow_stars)), NULL)
    Call(SetModelCustomGfx, MODEL_o338, CUSTOM_GFX_2, ENV_TINT_UNCHANGED)
    Call(SetModelFlags, MODEL_o338, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)

    Call(MakeLocalVertexCopy, VTX_COPY_2, MODEL_o344, TRUE)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_3, Ref(N(build_gfx_yellow_stars)), NULL)
    Call(SetModelCustomGfx, MODEL_o344, CUSTOM_GFX_3, ENV_TINT_UNCHANGED)
    Call(SetModelFlags, MODEL_o344, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)

    Call(MakeLocalVertexCopy, VTX_COPY_3, MODEL_o354, TRUE)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_4, Ref(N(build_gfx_yellow_stars)), NULL)
    Call(SetModelCustomGfx, MODEL_o354, CUSTOM_GFX_4, ENV_TINT_UNCHANGED)
    Call(SetModelFlags, MODEL_o354, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)

    Call(MakeLocalVertexCopy, VTX_COPY_4, MODEL_o341, TRUE)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_5, Ref(N(build_gfx_yellow_stars)), NULL)
    Call(SetModelCustomGfx, MODEL_o341, CUSTOM_GFX_5, ENV_TINT_UNCHANGED)
    Call(SetModelFlags, MODEL_o341, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)

    Call(MakeLocalVertexCopy, VTX_COPY_5, MODEL_o352, TRUE)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_6, Ref(N(build_gfx_blue_stars)), NULL)
    Call(SetModelCustomGfx, MODEL_o352, CUSTOM_GFX_6, ENV_TINT_UNCHANGED)
    Call(SetModelFlags, MODEL_o352, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)

    Call(MakeLocalVertexCopy, VTX_COPY_6, MODEL_o346, TRUE)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_7, Ref(N(build_gfx_blue_stars)), NULL)
    Call(SetModelCustomGfx, MODEL_o346, CUSTOM_GFX_7, ENV_TINT_UNCHANGED)
    Call(SetModelFlags, MODEL_o346, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)

    Call(MakeLocalVertexCopy, VTX_COPY_7, MODEL_o349, TRUE)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_8, Ref(N(build_gfx_green_stars)), NULL)
    Call(SetModelCustomGfx, MODEL_o349, CUSTOM_GFX_8, ENV_TINT_UNCHANGED)
    Call(SetModelFlags, MODEL_o349, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)

    Call(MakeLocalVertexCopy, VTX_COPY_8, MODEL_o353, TRUE)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_9, Ref(N(build_gfx_green_stars)), NULL)
    Call(SetModelCustomGfx, MODEL_o353, CUSTOM_GFX_9, ENV_TINT_UNCHANGED)
    Call(SetModelFlags, MODEL_o353, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)

    Call(MakeLocalVertexCopy, VTX_COPY_9, MODEL_o347, TRUE)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_A, Ref(N(build_gfx_pink_stars)), NULL)
    Call(SetModelCustomGfx, MODEL_o347, CUSTOM_GFX_A, ENV_TINT_UNCHANGED)
    Call(SetModelFlags, MODEL_o347, MODEL_FLAG_HAS_LOCAL_VERTEX_COPY, TRUE)

    Thread
        Call(SetTexPanner, MODEL_o332, TEX_PANNER_0)
        Call(SetTexPanner, MODEL_o334, TEX_PANNER_0)
        Call(SetTexPanner, MODEL_o333, TEX_PANNER_0)
        Call(SetTexPanner, MODEL_o336, TEX_PANNER_0)
        Set(LVar0, 0)
        Set(LVar1, 0)
        Set(LVar2, 0)
        Set(LVar3, 0)
        Loop(0)
            Add(LVar0, 80)
            Add(LVar1, -150)
            IfGt(LVar0, 0x8000)
                Add(LVar0, -0x8000)
            EndIf
            IfLt(LVar1, -0x8000)
                Add(LVar1, 0x8000)
            EndIf
            Add(LVar2, -50)
            Add(LVar3, 100)
            IfLt(LVar2, -0x8000)
                Add(LVar2, 0x8000)
            EndIf
            IfGt(LVar3, 0x8000)
                Add(LVar3, -0x8000)
            EndIf
            Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, LVar0, LVar1)
            Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_AUX, LVar2, LVar3)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Label(2)
        Call(MakeLerp, -7, 7, 30, EASING_COS_IN_OUT)
        Label(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o357, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o344, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o361, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o354, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o341, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o362, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
        Call(MakeLerp, 7, -7, 30, EASING_COS_IN_OUT)
        Label(1)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o357, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o344, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o361, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o354, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o341, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o362, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
        Goto(2)
    EndThread
    Thread
        Label(3)
        Call(MakeLerp, 7, -7, 30, EASING_COS_IN_OUT)
        Label(4)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o363, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o343, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o355, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o338, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(4)
        EndIf
        Call(MakeLerp, -7, 7, 30, EASING_COS_IN_OUT)
        Label(5)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o363, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o343, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o355, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o338, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(5)
        EndIf
        Goto(3)
    EndThread
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

s32 N(ForegroundModels)[] = {
    MODEL_o345,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "hos_tex\0",
    .shape = "hos_bt01_shape",
    .hit = "hos_bt01_hit",
    .bg = "hos_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
