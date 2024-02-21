#include "kkj_14.h"
#include "sprite/player.h"

EvtScript N(EVS_Scene_Chapter5) = {
    Call(DisablePlayerInput, TRUE)
    Call(InterpPlayerYaw, 270, 0)
    Call(DisablePartnerAI, 0)
    Call(SetNpcPos, NPC_PARTNER, -170, 40, -5)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, -140, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -140, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Call(SetCamDistance, CAM_DEFAULT, Float(275.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.6 / DT))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndThread
    Loop(2)
        Call(PlayerMoveTo, -110, 0, 25 * DT)
        Wait(5 * DT)
        Call(PlayerMoveTo, -130, 0, 25 * DT)
        Wait(5 * DT)
    EndLoop
    Call(PlayerMoveTo, -110, 0, 25 * DT)
    Call(InterpPlayerYaw, 270, 5)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_00EB)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00EC)
    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_00ED)
    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00EE)
    Thread
        Call(NpcFlyTo, NPC_PARTNER, -140, 55, 0, 30 * DT, -5, EASING_LINEAR)
        Call(EnablePartnerAI)
    EndThread
    Call(ResetCam, CAM_DEFAULT, Float(2.0 / DT))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
