#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_3_mac_01

ApiStatus func_80219D60_4491A0(Evt* script, s32 isInitialCall);
INCLUDE_ASM(s32, "battle/area_kmr_part_3/448E80", func_80219D60_4491A0);

// ApiStatus func_80219D60_4491A0(Evt* script, s32 isInitialCall) {
//     Bytecode* args = script->ptrReadPos;
//     f32 out0;
//     f32 out1;
//     f32 out2;
//     f32 sp18;
//     f32 temp_f28;
//     f32 temp_f30;
//     f64 temp_f20;

//     script->functionTemp[0] = evt_get_variable(script, *args++);
//     switch (script->functionTemp[0]) {
//         case 0:
//             out0 = 142.0f;
//             out1 = 0.0f;
//             out2 = -118.0f;
//             script->varTable[3] = 142;
//             script->varTable[4] = 0;
//             script->varTable[5] = -118;
//             script->varTable[6] = 44;
//             script->varTable[7] = -118;
//             script->varTable[8] = 3;
//             script->varTable[9] = 0;
//             script->varTable[11] = 0;
//             script->functionTemp[0] = 1;
//             break;
//         case 3:
//             out0 = 91.0f;
//             out1 = 0.0f;
//             out2 = -118.0f;
//             script->varTable[3] = 91;
//             script->varTable[4] = 0;
//             script->varTable[5] = -118;
//             script->varTable[6] = 91;
//             script->varTable[7] = -118;
//             script->varTable[8] = 3;
//             script->varTable[9] = 0;
//             script->varTable[11] = 0;
//             script->functionTemp[0] = 1;
//             break;
//         case 1:
//             script->varTable[9] += script->varTable[8];
//             if (script->varTable[9] > 45) {
//                 script->varTable[9] = 45;
//             }
//             out0 = script->varTable[3];
//             out1 = script->varTable[4];
//             temp_f30 = script->varTable[5];
//             temp_f28 = script->varTable[6];
//             sp18 = script->varTable[7];

//             temp_f20 = out0 * (1.0 - sin_rad(script->varTable[9] * TAU / 360.0f));
//             out0 = (temp_f20 + (temp_f28 * sin_rad(script->varTable[9] * TAU / 360.0f)));
//             out1 += sin_rad(((script->varTable[9] * 2) * TAU) / 360.0f) * 90.0f;
//             temp_f20 = temp_f30 * (1.0 - sin_rad(script->varTable[9] * TAU / 360.0f));
//             out2 = temp_f20 + (sp18 * sin_rad(script->varTable[9] * TAU / 360.0f));
//             if (script->varTable[9] == 45) {
//                 script->varTable[11] = 1;
//             }
//             break;
//         case 2:
//             script->varTable[9] += script->varTable[8];
//             if (script->varTable[9] > 90) {
//                 script->varTable[9] = 90;
//             }
//             out0 = script->varTable[3];
//             out1 = script->varTable[4];
//             temp_f30 = script->varTable[5];
//             temp_f28 = script->varTable[6];
//             sp18 = script->varTable[7];

//             temp_f20 = out0 * (1.0 - sin_rad(script->varTable[9] * TAU / 360.0f));
//             out0 = (temp_f20 + (temp_f28 * sin_rad(script->varTable[9] * TAU / 360.0f)));
//             out1 += sin_rad(((script->varTable[9] * 2) * TAU) / 360.0f) * 90.0f;
//             temp_f20 = (temp_f30 * (1.0 - sin_rad(script->varTable[9] * TAU / 360.0f)));
//             out2 = temp_f20 + (sp18 * sin_rad(script->varTable[9] * TAU / 360.0f));
//             if (script->varTable[9] == 90) {
//                 script->varTable[11] = 2;
//             }
//             break;
//     }
//     script->varTable[0] = out0;
//     script->varTable[1] = out1;
//     script->varTable[2] = out2;
//     return ApiStatus_DONE2;
// }

EvtScript N(80233AF0) = {
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

EvtScript N(80234180) = {
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

EvtScript N(80234564) = {
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

EvtScript N(802347D0) = {
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

EvtScript N(beforeBattle_80234B74) = {
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

EvtScript N(afterBattle_80234C70) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "mac_tex",
    .shape = "mac_bt01_shape",
    .hit = "mac_bt01_hit",
    .bg = "nok_bg",
    .preBattle = &N(beforeBattle_80234B74),
    .postBattle = &N(afterBattle_80234C70),
};
