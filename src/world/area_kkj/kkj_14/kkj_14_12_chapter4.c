#include "kkj_14.h"
#include "sprite/player.h"

EvtScript N(EVS_Scene_Chapter4) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -60, 30, 0)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(90.0), -20, 250, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_0097)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0098)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_0099)
    EVT_THREAD
        EVT_CALL(NpcFlyTo, NPC_PARTNER, -30, 55, 30, 30, -5, EASING_LINEAR)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(2.0 * DT))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
