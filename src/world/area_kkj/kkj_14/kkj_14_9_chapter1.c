#include "kkj_14.h"
#include "sprite/player.h"

EvtScript N(EVS_Scene_Chapter1) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_THREAD
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(0.5 / DT), 20, 300, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_END_THREAD
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -200, 93, -17)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_THREAD
        EVT_WAIT(120 * DT)
        EVT_CALL(NpcFlyTo, NPC_PARTNER, -100, 40, 0, 60 * DT, 40, EASING_LINEAR)
        EVT_WAIT(5 * DT)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 5)
    EVT_END_THREAD
    EVT_LOOP(3)
        EVT_CALL(PlayerMoveTo, -110, 0, 30 * DT)
        EVT_CALL(PlayerMoveTo, -140, 0, 30 * DT)
    EVT_END_LOOP
    EVT_WAIT(5 * DT)
    EVT_CALL(InterpPlayerYaw, 90, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_0033)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0034)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_0035)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0036)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Startle)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0037)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0038)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
