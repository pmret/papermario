#include "kkj_14.h"

EvtScript N(EVS_Scene_Chapter1) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_THREAD
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(0.5), 20, 300, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_END_THREAD
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -200, 93, -17)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_THREAD
        EVT_WAIT(120)
        EVT_CALL(NpcFlyTo, NPC_PARTNER, -100, 40, 0, 60, 40, EASING_LINEAR)
        EVT_WAIT(5)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 5)
    EVT_END_THREAD
    EVT_LOOP(3)
        EVT_CALL(PlayerMoveTo, -110, 0, 30)
        EVT_CALL(PlayerMoveTo, -140, 0, 30)
    EVT_END_LOOP
    EVT_WAIT(5)
    EVT_CALL(InterpPlayerYaw, 90, 5)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach_D0004, ANIM_Peach_A0001, 5, MSG_Peach_0033)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0034)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach_D0004, ANIM_Peach_A0001, 5, MSG_Peach_0035)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0036)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach_C000D)
    EVT_CALL(PlaySoundAtPlayer, SOUND_262, 0)
    EVT_CALL(ShowEmote, NPC_Bowser, EMOTE_EXCLAMATION, 0, 30, FALSE, 0, 0, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach_A0001)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach_C0000)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach_C0026)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach_C0001, ANIM_Peach_C0026, 5, MSG_Peach_0037)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach_C0002)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach_A0001)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0038)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
