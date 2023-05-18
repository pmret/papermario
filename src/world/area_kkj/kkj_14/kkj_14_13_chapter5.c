#include "kkj_14.h"
#include "sprite/player.h"

EvtScript N(EVS_Scene_Chapter5) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -170, 40, -5)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -140, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -140, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(275.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.6 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_LOOP(2)
        EVT_CALL(PlayerMoveTo, -110, 0, 25 * DT)
        EVT_WAIT(5 * DT)
        EVT_CALL(PlayerMoveTo, -130, 0, 25 * DT)
        EVT_WAIT(5 * DT)
    EVT_END_LOOP
    EVT_CALL(PlayerMoveTo, -110, 0, 25 * DT)
    EVT_CALL(InterpPlayerYaw, 270, 5)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_00EB)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00EC)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_00ED)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_00EE)
    EVT_THREAD
        EVT_CALL(NpcFlyTo, NPC_PARTNER, -140, 55, 0, 30 * DT, -5, EASING_LINEAR)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
