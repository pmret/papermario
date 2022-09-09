#include "common.h"
#include "battle/battle.h"
#include "mapfs/hos_bt01_shape.h"

#define NAMESPACE b_area_hos_hos_01

s32 func_802184C0_47F570(void);
INCLUDE_ASM(s32, "battle/area_hos/47F570", func_802184C0_47F570);

s32 func_802186B8_47F768(void);
INCLUDE_ASM(s32, "battle/area_hos/47F570", func_802186B8_47F768);

s32 func_802189D0_47FA80(void);
INCLUDE_ASM(s32, "battle/area_hos/47F570", func_802189D0_47FA80);

s32 func_80218CEC_47FD9C(void);
INCLUDE_ASM(s32, "battle/area_hos/47F570", func_80218CEC_47FD9C);

s32 D_80224BB0_48BC60[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(beforeBattle_80224BD0) = {
    EVT_CALL(SetSpriteShading, -1)

    EVT_CALL(MakeLocalVertexCopy, 0, MODEL_o345, 1)
    EVT_CALL(SetCustomGfxBuilders, 1, EVT_ADDR(func_802184C0_47F570), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o345, 1, -1)
    EVT_CALL(SetModelFlags, MODEL_o345, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 1, MODEL_o338, 1)
    EVT_CALL(SetCustomGfxBuilders, 2, EVT_ADDR(func_802184C0_47F570), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o338, 2, -1)
    EVT_CALL(SetModelFlags, MODEL_o338, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 2, MODEL_o344, 1)
    EVT_CALL(SetCustomGfxBuilders, 3, EVT_ADDR(func_802184C0_47F570), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o344, 3, -1)
    EVT_CALL(SetModelFlags, MODEL_o344, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 3, MODEL_o354, 1)
    EVT_CALL(SetCustomGfxBuilders, 4, EVT_ADDR(func_802184C0_47F570), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o354, 4, -1)
    EVT_CALL(SetModelFlags, MODEL_o354, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 4, MODEL_o341, 1)
    EVT_CALL(SetCustomGfxBuilders, 5, EVT_ADDR(func_802184C0_47F570), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o341, 5, -1)
    EVT_CALL(SetModelFlags, MODEL_o341, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 5, MODEL_o352, 1)
    EVT_CALL(SetCustomGfxBuilders, 6, EVT_ADDR(func_802186B8_47F768), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o352, 6, -1)
    EVT_CALL(SetModelFlags, MODEL_o352, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 6, MODEL_o346, 1)
    EVT_CALL(SetCustomGfxBuilders, 7, EVT_ADDR(func_802186B8_47F768), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o346, 7, -1)
    EVT_CALL(SetModelFlags, MODEL_o346, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 7, MODEL_o349, 1)
    EVT_CALL(SetCustomGfxBuilders, 8, EVT_ADDR(func_802189D0_47FA80), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o349, 8, -1)
    EVT_CALL(SetModelFlags, MODEL_o349, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 8, MODEL_o353, 1)
    EVT_CALL(SetCustomGfxBuilders, 9, EVT_ADDR(func_802189D0_47FA80), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o353, 9, -1)
    EVT_CALL(SetModelFlags, MODEL_o353, 128, 1)

    EVT_CALL(MakeLocalVertexCopy, 9, MODEL_o347, 1)
    EVT_CALL(SetCustomGfxBuilders, 10, EVT_ADDR(func_80218CEC_47FD9C), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o347, 10, -1)
    EVT_CALL(SetModelFlags, MODEL_o347, 128, 1)

    EVT_THREAD
        EVT_CALL(SetTexPanner, MODEL_o332, 0)
        EVT_CALL(SetTexPanner, MODEL_o334, 0)
        EVT_CALL(SetTexPanner, MODEL_o333, 0)
        EVT_CALL(SetTexPanner, MODEL_o336, 0)
        EVT_SET(LW(0), 0)
        EVT_SET(LW(1), 0)
        EVT_SET(LW(2), 0)
        EVT_SET(LW(3), 0)
        EVT_LOOP(0)
            EVT_ADD(LW(0), 80)
            EVT_ADD(LW(1), -150)
            EVT_IF_GT(LW(0), 32768)
                EVT_ADD(LW(0), -32768)
            EVT_END_IF
            EVT_IF_LT(LW(1), -32768)
                EVT_ADD(LW(1), 32768)
            EVT_END_IF
            EVT_ADD(LW(2), -50)
            EVT_ADD(LW(3), 100)
            EVT_IF_LT(LW(2), -32768)
                EVT_ADD(LW(2), 32768)
            EVT_END_IF
            EVT_IF_GT(LW(3), 32768)
                EVT_ADD(LW(3), -32768)
            EVT_END_IF
            EVT_CALL(SetTexPanOffset, 0, 0, LW(0), LW(1))
            EVT_CALL(SetTexPanOffset, 0, 1, LW(2), LW(3))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LABEL(2)
        EVT_CALL(MakeLerp, -7, 7, 30, 10)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o357, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o344, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o361, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o354, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o341, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o362, 0, LW(0), 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(MakeLerp, 7, -7, 30, 10)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o357, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o344, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o361, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o354, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o341, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o362, 0, LW(0), 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_GOTO(2)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LABEL(3)
        EVT_CALL(MakeLerp, 7, -7, 30, 10)
        EVT_LABEL(4)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o363, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o343, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o355, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o338, 0, LW(0), 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(4)
        EVT_END_IF
        EVT_CALL(MakeLerp, -7, 7, 30, 10)
        EVT_LABEL(5)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o363, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o343, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o355, 0, LW(0), 0)
        EVT_CALL(TranslateModel, MODEL_o338, 0, LW(0), 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LW(1), 1)
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
