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
    Call(DisablePlayerInput, true)
    Call(InterpPlayerYaw, 270, 0)
    Call(DisablePartnerAI, 0)
    Call(SetNpcPos, NPC_PARTNER, -40, 90, 0)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Call(AdjustCam, CAM_DEFAULT, Float(90.0), -20, 250, Float(17.0), Float(-11.0))
    Call(LoadPath, 24 * DT, Ref(N(TwinkPacingPath1)), ARRAY_COUNT(N(TwinkPacingPath1)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(NpcFacePlayer, NPC_PARTNER, 5)
    Wait(20 * DT)
    Call(LoadPath, 30 * DT, Ref(N(TwinkPacingPath2)), ARRAY_COUNT(N(TwinkPacingPath2)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(NpcFacePlayer, NPC_PARTNER, 5)
    Wait(20 * DT)
    Call(LoadPath, 10 * DT, Ref(N(TwinkPacingPath3)), ARRAY_COUNT(N(TwinkPacingPath3)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(NpcFacePlayer, NPC_PARTNER, 5)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_007E)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_007F)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0080)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_0081)
    Call(ResetCam, CAM_DEFAULT, Float(2.0 / DT))
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, false)
    Return
    End
};
