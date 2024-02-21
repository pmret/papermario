#include "kkj_14.h"
#include "sprite/player.h"

EvtScript N(EVS_Scene_Chapter4) = {
    Call(DisablePlayerInput, TRUE)
    Call(InterpPlayerYaw, 270, 0)
    Call(DisablePartnerAI, 0)
    Call(SetNpcPos, NPC_PARTNER, -60, 30, 0)
    Call(SetNpcYaw, NPC_PARTNER, 90)
    Call(AdjustCam, CAM_DEFAULT, Float(90.0), -20, 250, Float(17.0), Float(-11.0))
    Wait(30 * DT)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_0097)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0098)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_0099)
    Thread
        Call(NpcFlyTo, NPC_PARTNER, -30, 55, 30, 30, -5, EASING_LINEAR)
        Call(EnablePartnerAI)
    EndThread
    Call(ResetCam, CAM_DEFAULT, Float(2.0 * DT))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
