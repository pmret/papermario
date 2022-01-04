#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_hos_hos_01

s32 D_80224BB0_48BC60[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

s32 func_802184C0_47F570(void);
INCLUDE_ASM(s32, "battle/area_hos/47F570", func_802184C0_47F570);

s32 func_802186B8_47F768(void);
INCLUDE_ASM(s32, "battle/area_hos/47F570", func_802186B8_47F768);

s32 func_802189D0_47FA80(void);
INCLUDE_ASM(s32, "battle/area_hos/47F570", func_802189D0_47FA80);

s32 func_80218CEC_47FD9C(void);
INCLUDE_ASM(s32, "battle/area_hos/47F570", func_80218CEC_47FD9C);

EvtSource N(beforeBattle_80224BD0) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(MakeLocalVertexCopy, 0, 5, 1)
    EVT_CALL(SetCustomGfxBuilders, 1, EVT_ADDR(func_802184C0_47F570), 0)
    EVT_CALL(SetModelCustomGfx, 5, 1, -1)
    EVT_CALL(SetModelFlags, 5, 128, 1)
    EVT_CALL(MakeLocalVertexCopy, 1, 16, 1)
    EVT_CALL(SetCustomGfxBuilders, 2, EVT_ADDR(func_802184C0_47F570), 0)
    EVT_CALL(SetModelCustomGfx, 16, 2, -1)
    EVT_CALL(SetModelFlags, 16, 128, 1)
    EVT_CALL(MakeLocalVertexCopy, 2, 19, 1)
    EVT_CALL(SetCustomGfxBuilders, 3, EVT_ADDR(func_802184C0_47F570), 0)
    EVT_CALL(SetModelCustomGfx, 19, 3, -1)
    EVT_CALL(SetModelFlags, 19, 128, 1)
    EVT_CALL(MakeLocalVertexCopy, 3, 28, 1)
    EVT_CALL(SetCustomGfxBuilders, 4, EVT_ADDR(func_802184C0_47F570), 0)
    EVT_CALL(SetModelCustomGfx, 28, 4, -1)
    EVT_CALL(SetModelFlags, 28, 128, 1)
    EVT_CALL(MakeLocalVertexCopy, 4, 31, 1)
    EVT_CALL(SetCustomGfxBuilders, 5, EVT_ADDR(func_802184C0_47F570), 0)
    EVT_CALL(SetModelCustomGfx, 31, 5, -1)
    EVT_CALL(SetModelFlags, 31, 128, 1)
    EVT_CALL(MakeLocalVertexCopy, 5, 7, 1)
    EVT_CALL(SetCustomGfxBuilders, 6, EVT_ADDR(func_802186B8_47F768), 0)
    EVT_CALL(SetModelCustomGfx, 7, 6, -1)
    EVT_CALL(SetModelFlags, 7, 128, 1)
    EVT_CALL(MakeLocalVertexCopy, 6, 37, 1)
    EVT_CALL(SetCustomGfxBuilders, 7, EVT_ADDR(func_802186B8_47F768), 0)
    EVT_CALL(SetModelCustomGfx, 37, 7, -1)
    EVT_CALL(SetModelFlags, 37, 128, 1)
    EVT_CALL(MakeLocalVertexCopy, 7, 9, 1)
    EVT_CALL(SetCustomGfxBuilders, 8, EVT_ADDR(func_802189D0_47FA80), 0)
    EVT_CALL(SetModelCustomGfx, 9, 8, -1)
    EVT_CALL(SetModelFlags, 9, 128, 1)
    EVT_CALL(MakeLocalVertexCopy, 8, 25, 1)
    EVT_CALL(SetCustomGfxBuilders, 9, EVT_ADDR(func_802189D0_47FA80), 0)
    EVT_CALL(SetModelCustomGfx, 25, 9, -1)
    EVT_CALL(SetModelFlags, 25, 128, 1)
    EVT_CALL(MakeLocalVertexCopy, 9, 22, 1)
    EVT_CALL(SetCustomGfxBuilders, 10, EVT_ADDR(func_80218CEC_47FD9C), 0)
    EVT_CALL(SetModelCustomGfx, 22, 10, -1)
    EVT_CALL(SetModelFlags, 22, 128, 1)
    EVT_THREAD
        EVT_CALL(SetTexPanner, 4, 0)
        EVT_CALL(SetTexPanner, 12, 0)
        EVT_CALL(SetTexPanner, 13, 0)
        EVT_CALL(SetTexPanner, 14, 0)
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
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LABEL(2)
        EVT_CALL(MakeLerp, -7, 7, 30, 10)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, 18, 0, LW(0), 0)
        EVT_CALL(TranslateModel, 19, 0, LW(0), 0)
        EVT_CALL(TranslateModel, 27, 0, LW(0), 0)
        EVT_CALL(TranslateModel, 28, 0, LW(0), 0)
        EVT_CALL(TranslateModel, 31, 0, LW(0), 0)
        EVT_CALL(TranslateModel, 30, 0, LW(0), 0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(MakeLerp, 7, -7, 30, 10)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, 18, 0, LW(0), 0)
        EVT_CALL(TranslateModel, 19, 0, LW(0), 0)
        EVT_CALL(TranslateModel, 27, 0, LW(0), 0)
        EVT_CALL(TranslateModel, 28, 0, LW(0), 0)
        EVT_CALL(TranslateModel, 31, 0, LW(0), 0)
        EVT_CALL(TranslateModel, 30, 0, LW(0), 0)
        EVT_WAIT_FRAMES(1)
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
        EVT_CALL(TranslateModel, 33, 0, LW(0), 0)
        EVT_CALL(TranslateModel, 34, 0, LW(0), 0)
        EVT_CALL(TranslateModel, 15, 0, LW(0), 0)
        EVT_CALL(TranslateModel, 16, 0, LW(0), 0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(4)
        EVT_END_IF
        EVT_CALL(MakeLerp, -7, 7, 30, 10)
        EVT_LABEL(5)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, 33, 0, LW(0), 0)
        EVT_CALL(TranslateModel, 34, 0, LW(0), 0)
        EVT_CALL(TranslateModel, 15, 0, LW(0), 0)
        EVT_CALL(TranslateModel, 16, 0, LW(0), 0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(5)
        EVT_END_IF
        EVT_GOTO(3)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtSource N(afterBattle_80225598) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_802255A8)[] = {
    0x00000005, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "hos_tex\0",
    .shape = "hos_bt01_shape",
    .hit = "hos_bt01_hit",
    .bg = "hos_bg",
    .preBattle = N(beforeBattle_80224BD0),
    .postBattle = N(afterBattle_80225598),
    .foregroundModelList = N(foregroundModelList_802255A8),
};
