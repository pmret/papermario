#include "kkj_14.h"
#include "sprite/player.h"

EvtScript N(EVS_Scene_Chapter6) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -140, 25, 0)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -100, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -100, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_012F)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0130)
    EVT_THREAD
        EVT_CALL(NpcFlyTo, NPC_PARTNER, -90, 55, 0, 30 * DT, -5, EASING_LINEAR)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
