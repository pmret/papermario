#include "kkj_14.h"
#include "sprite/player.h"

Vec3f N(TwinkPacingPath1)[] = {
    {  -40.0,    90.0,    0.0 },
    {  -10.0,    65.0,  -20.0 },
    {   20.0,    70.0,  -10.0 },
};

Vec3f N(TwinkPacingPath2)[] = {
    {   20.0,    70.0,  -10.0 },
    {  -30.0,    45.0,  -20.0 },
    {  -80.0,    50.0,  -10.0 },
};

Vec3f N(TwinkPacingPath3)[] = {
    {  -80.0,    50.0,  -10.0 },
    {  -70.0,    35.0,   -5.0 },
    {  -60.0,    30.0,    0.0 },
};

EvtScript N(EVS_Scene_Chapter3) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -40, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(90.0), -20, 250, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(LoadPath, 24 * DT, EVT_PTR(N(TwinkPacingPath1)), ARRAY_COUNT(N(TwinkPacingPath1)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 5)
    EVT_WAIT(20 * DT)
    EVT_CALL(LoadPath, 30 * DT, EVT_PTR(N(TwinkPacingPath2)), ARRAY_COUNT(N(TwinkPacingPath2)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 5)
    EVT_WAIT(20 * DT)
    EVT_CALL(LoadPath, 10 * DT, EVT_PTR(N(TwinkPacingPath3)), ARRAY_COUNT(N(TwinkPacingPath3)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_007E)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_007F)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0080)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_0081)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
