#include "common.h"
#include "battle/battle.h"
#include "mapfs/hos_bt01_shape.h"

#define NAMESPACE b_area_hos_hos_01

u16 D_80224BB0_48BC60[16] = { };

void func_802184C0_47F570(s32 arg0) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    arg0--;
    mdl_get_copied_vertices(arg0, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        Vtx* vtx = &copiedVertices[i];
        s16 temp1 = (sins(D_80224BB0_48BC60[arg0] * (i % 3 + 1) + i) + 0x8000) / 2;
        s32 temp2 = temp1 * 155;
        vtx->v.cn[0] = temp2 / 0x8000 + 100;
        vtx->v.cn[1] = temp2 / 0x8000 + 100;

        temp3 = sins(D_80224BB0_48BC60[arg0] / 0x8000 * (((i / 2) % 3 + 1) << 15)  + D_80224BB0_48BC60[arg0] / 0x4000 * 0x8000 + i) + 0x8000;
        vtx->v.cn[2] = vtx->v.cn[0] * temp3 / 0x10000;
    }

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(arg0));
    D_80224BB0_48BC60[arg0] += 0x253;
}

void func_802186B8_47F768(s32 arg0) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    arg0--;
    mdl_get_copied_vertices(arg0, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(D_80224BB0_48BC60[arg0] * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 48.62745098039216;
        colors[1] = temp1 * 155 / 0x8000 + 89.41176470588236;

        temp3 = sins(D_80224BB0_48BC60[arg0] / 0x8000 * (((i / 2) % 3 + 1) << 15)  + D_80224BB0_48BC60[arg0] / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000 + 99.6078431372549;
    }

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(arg0));
    D_80224BB0_48BC60[arg0] += 0x253;
}

void func_802189D0_47FA80(s32 arg0) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    arg0--;
    mdl_get_copied_vertices(arg0, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(D_80224BB0_48BC60[arg0] * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 67.45098039215686;
        colors[1] = temp1 * 155 / 0x8000 + 100.0;

        temp3 = sins(D_80224BB0_48BC60[arg0] / 0x8000 * (((i / 2) % 3 + 1) << 15)  + D_80224BB0_48BC60[arg0] / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000 + 59.21568627450981;
    }

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(arg0));
    D_80224BB0_48BC60[arg0] += 0x253;
}

void func_80218CEC_47FD9C(s32 arg0) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    arg0--;
    mdl_get_copied_vertices(arg0, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(D_80224BB0_48BC60[arg0] * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 100.0;
        colors[1] = temp1 * 155 / 0x8000 + 80.3921568627451;

        temp3 = sins(D_80224BB0_48BC60[arg0] / 0x8000 * (((i / 2) % 3 + 1) << 15)  + D_80224BB0_48BC60[arg0] / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000 + 96.07843137254902;
    }

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(arg0));
    D_80224BB0_48BC60[arg0] += 0x253;
}

EvtScript N(beforeBattle_80224BD0) = {
    EVT_CALL(SetSpriteShading, -1)

    EVT_CALL(MakeLocalVertexCopy, 0, MODEL_o345, 1)
    EVT_CALL(SetCustomGfxBuilders, 1, EVT_PTR(func_802184C0_47F570), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o345, 1, -1)
    EVT_CALL(SetModelFlags, MODEL_o345, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 1, MODEL_o338, 1)
    EVT_CALL(SetCustomGfxBuilders, 2, EVT_PTR(func_802184C0_47F570), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o338, 2, -1)
    EVT_CALL(SetModelFlags, MODEL_o338, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 2, MODEL_o344, 1)
    EVT_CALL(SetCustomGfxBuilders, 3, EVT_PTR(func_802184C0_47F570), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o344, 3, -1)
    EVT_CALL(SetModelFlags, MODEL_o344, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 3, MODEL_o354, 1)
    EVT_CALL(SetCustomGfxBuilders, 4, EVT_PTR(func_802184C0_47F570), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o354, 4, -1)
    EVT_CALL(SetModelFlags, MODEL_o354, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 4, MODEL_o341, 1)
    EVT_CALL(SetCustomGfxBuilders, 5, EVT_PTR(func_802184C0_47F570), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o341, 5, -1)
    EVT_CALL(SetModelFlags, MODEL_o341, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 5, MODEL_o352, 1)
    EVT_CALL(SetCustomGfxBuilders, 6, EVT_PTR(func_802186B8_47F768), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o352, 6, -1)
    EVT_CALL(SetModelFlags, MODEL_o352, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 6, MODEL_o346, 1)
    EVT_CALL(SetCustomGfxBuilders, 7, EVT_PTR(func_802186B8_47F768), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o346, 7, -1)
    EVT_CALL(SetModelFlags, MODEL_o346, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 7, MODEL_o349, 1)
    EVT_CALL(SetCustomGfxBuilders, 8, EVT_PTR(func_802189D0_47FA80), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o349, 8, -1)
    EVT_CALL(SetModelFlags, MODEL_o349, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 8, MODEL_o353, 1)
    EVT_CALL(SetCustomGfxBuilders, 9, EVT_PTR(func_802189D0_47FA80), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o353, 9, -1)
    EVT_CALL(SetModelFlags, MODEL_o353, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 9, MODEL_o347, 1)
    EVT_CALL(SetCustomGfxBuilders, 10, EVT_PTR(func_80218CEC_47FD9C), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o347, 10, -1)
    EVT_CALL(SetModelFlags, MODEL_o347, 128, 1)

    EVT_THREAD
        EVT_CALL(SetTexPanner, MODEL_o332, 0)
        EVT_CALL(SetTexPanner, MODEL_o334, 0)
        EVT_CALL(SetTexPanner, MODEL_o333, 0)
        EVT_CALL(SetTexPanner, MODEL_o336, 0)
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 0)
        EVT_LOOP(0)
            EVT_ADD(LVar0, 80)
            EVT_ADD(LVar1, -150)
            EVT_IF_GT(LVar0, 32768)
                EVT_ADD(LVar0, -32768)
            EVT_END_IF
            EVT_IF_LT(LVar1, -32768)
                EVT_ADD(LVar1, 32768)
            EVT_END_IF
            EVT_ADD(LVar2, -50)
            EVT_ADD(LVar3, 100)
            EVT_IF_LT(LVar2, -32768)
                EVT_ADD(LVar2, 32768)
            EVT_END_IF
            EVT_IF_GT(LVar3, 32768)
                EVT_ADD(LVar3, -32768)
            EVT_END_IF
            EVT_CALL(SetTexPanOffset, 0, 0, LVar0, LVar1)
            EVT_CALL(SetTexPanOffset, 0, 1, LVar2, LVar3)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LABEL(2)
        EVT_CALL(MakeLerp, -7, 7, 30, 10)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o357, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o344, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o361, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o354, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o341, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o362, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(MakeLerp, 7, -7, 30, 10)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o357, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o344, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o361, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o354, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o341, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o362, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_GOTO(2)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LABEL(3)
        EVT_CALL(MakeLerp, 7, -7, 30, 10)
        EVT_LABEL(4)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o363, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o343, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o355, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o338, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(4)
        EVT_END_IF
        EVT_CALL(MakeLerp, -7, 7, 30, 10)
        EVT_LABEL(5)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o363, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o343, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o355, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o338, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(5)
        EVT_END_IF
        EVT_GOTO(3)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80225598) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_802255A8)[] = {
    MODEL_o345, 0,
};

Stage NAMESPACE = {
    .texture = "hos_tex\0",
    .shape = "hos_bt01_shape",
    .hit = "hos_bt01_hit",
    .bg = "hos_bg",
    .preBattle = &N(beforeBattle_80224BD0),
    .postBattle = &N(afterBattle_80225598),
    .foregroundModelList = N(foregroundModelList_802255A8),
};
