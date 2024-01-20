#include "kkj_14.h"
#include "sprite/player.h"

EvtScript N(EVS_Scene_Chapter6) = {
    Call(DisablePlayerInput, TRUE)
    Call(InterpPlayerYaw, 270, 0)
    Call(DisablePartnerAI, 0)
    Call(SetNpcPos, NPC_PARTNER, -140, 25, 0)
    Call(SetNpcYaw, NPC_PARTNER, 90)
    Call(UseSettingsFrom, CAM_DEFAULT, -100, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -100, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_012F)
    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0130)
    Thread
        Call(NpcFlyTo, NPC_PARTNER, -90, 55, 0, 30 * DT, -5, EASING_LINEAR)
        Call(EnablePartnerAI)
    EndThread
    Call(ResetCam, CAM_DEFAULT, Float(2.0 / DT))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
