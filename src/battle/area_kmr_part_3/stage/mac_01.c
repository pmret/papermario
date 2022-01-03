#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_3_mac_01

ApiStatus func_80219D60_4491A0(Evt* script, s32 isInitialCall);
INCLUDE_ASM(s32, "battle/area_kmr_part_3/448E80", func_80219D60_4491A0);

EvtSource N(80233AF0) = {
    EVT_SET(LW(10), LW(0))
    EVT_LABEL(0)
    EVT_CALL(func_80219D60_4491A0, 0)
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
    EVT_WAIT_FRAMES(1)
    EVT_LOOP(0)
        EVT_CALL(func_80219D60_4491A0, 1)
        EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
        EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(11), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -7, 0, 0, 1)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -27, 0, 0, 1)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -5, 0, 0, 1)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
    EVT_WAIT_FRAMES(5)
    EVT_LOOP(0)
        EVT_CALL(func_80219D60_4491A0, 2)
        EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
        EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(11), 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(RandInt, 80, LW(11))
    EVT_ADD(LW(11), 30)
    EVT_LOOP(LW(11))
        EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
        EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(RandInt, 5, LW(0))
    EVT_IF_NE(LW(0), 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(func_80219D60_4491A0, 3)
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
    EVT_WAIT_FRAMES(1)
    EVT_LOOP(0)
        EVT_CALL(func_80219D60_4491A0, 1)
        EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
        EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(11), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -7, 0, 0, 1)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -27, 0, 0, 1)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -5, 0, 0, 1)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
    EVT_WAIT_FRAMES(5)
    EVT_LOOP(0)
        EVT_CALL(func_80219D60_4491A0, 2)
        EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
        EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(11), 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(RandInt, 80, LW(11))
    EVT_ADD(LW(11), 30)
    EVT_LOOP(LW(11))
        EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), LW(2))
        EVT_CALL(RotateModel, LW(10), -20, 0, 0, 1)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80234180) = {
    EVT_SET(LW(10), LW(0))
    EVT_LOOP(0)
        EVT_CALL(TranslateModel, LW(10), 1, 0, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 1, 0, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 1, -1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 2, -1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 2, -1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 2, -1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 3, -2, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 3, -2, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 3, -3, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 3, -3, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 3, -3, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 3, -2, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 2, -2, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 2, -1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 1, 0, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 1, 1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, 1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), -1, 1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), -1, 1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), -1, 0, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), -1, 0, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
        EVT_WAIT_FRAMES(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

s32 N(intTable_80234524)[] = {
    0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFD, 0xFFFFFFFB, 0xFFFFFFF8,
    0xFFFFFFF8, 0xFFFFFFF9, 0xFFFFFFFA, 0xFFFFFFFC, 0xFFFFFFFE, 0xFFFFFFFF, 0x00000000, 0x000000FF,
};

EvtSource N(80234564) = {
    EVT_SET(LW(10), LW(0))
    EVT_SET(LW(11), LW(1))
    EVT_SET(LW(5), 5)
    EVT_USE_BUF(EVT_ADDR(N(intTable_80234524)))
    EVT_LABEL(0)
    EVT_BUF_READ1(LW(1))
    EVT_IF_EQ(LW(1), 255)
        EVT_USE_BUF(EVT_ADDR(N(intTable_80234524)))
        EVT_BUF_READ1(LW(1))
    EVT_END_IF
    EVT_SET(LW(0), LW(5))
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), 0)
    EVT_WAIT_FRAMES(1)
    EVT_ADD(LW(5), 1)
    EVT_SET(LW(12), LW(11))
    EVT_SUB(LW(12), 20)
    EVT_IF_GT(LW(5), LW(12))
        EVT_GOTO(1)
    EVT_END_IF
    EVT_SET(LW(0), LW(5))
    EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), 0)
    EVT_WAIT_FRAMES(1)
    EVT_ADD(LW(5), 1)
    EVT_SET(LW(12), LW(11))
    EVT_SUB(LW(12), 20)
    EVT_IF_GT(LW(5), LW(12))
        EVT_GOTO(1)
    EVT_END_IF
    EVT_GOTO(0)
    EVT_LABEL(1)
    EVT_SET(LW(2), 0)
    EVT_LOOP(20)
        EVT_ADD(LW(5), 1)
        EVT_SUB(LW(1), 2)
        EVT_SET(LW(0), LW(5))
        EVT_CALL(TranslateModel, LW(10), LW(0), LW(1), 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_SUB(LW(5), 280)
    EVT_SET(LW(1), 0)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtSource N(802347D0) = {
    EVT_SET(LW(10), LW(0))
    EVT_LOOP(0)
        EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, -1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, -1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, -1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, -1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, -2, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, -2, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, -3, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, -3, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, -3, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, -2, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, -2, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, -1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, 1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, 1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, 1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, 1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
        EVT_WAIT_FRAMES(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(beforeBattle_80234B74) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_THREAD
        EVT_SET(LW(0), 44)
        EVT_EXEC(N(80234180))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), 47)
        EVT_EXEC(N(80234180))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), 46)
        EVT_EXEC(N(80234180))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), 45)
        EVT_EXEC(N(80234180))
    EVT_END_THREAD
    EVT_SET(LW(0), 40)
    EVT_EXEC(N(80233AF0))
    EVT_RETURN
    EVT_END
};

EvtSource N(afterBattle_80234C70) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "mac_tex",
    .shape = "mac_bt01_shape",
    .hit = "mac_bt01_hit",
    .bg = "nok_bg",
    .preBattle = N(beforeBattle_80234B74),
    .postBattle = N(afterBattle_80234C70),
};
