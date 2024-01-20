#include "kkj_14.h"
#include "sprite/player.h"

EvtScript N(EVS_Scene_Chapter1) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Thread
        Call(AdjustCam, CAM_DEFAULT, Float(0.5 / DT), 20, 300, Float(17.0), Float(-11.0))
    EndThread
    Call(DisablePartnerAI, 0)
    Call(SetNpcPos, NPC_PARTNER, -200, 93, -17)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Thread
        Wait(120 * DT)
        Call(NpcFlyTo, NPC_PARTNER, -100, 40, 0, 60 * DT, 40, EASING_LINEAR)
        Wait(5 * DT)
        Call(InterpNpcYaw, NPC_PARTNER, 270, 5)
    EndThread
    Loop(3)
        Call(PlayerMoveTo, -110, 0, 30 * DT)
        Call(PlayerMoveTo, -140, 0, 30 * DT)
    EndLoop
    Wait(5 * DT)
    Call(InterpPlayerYaw, 90, 5)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_0033)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0034)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_0035)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0036)
    Call(SetPlayerAnimation, ANIM_Peach2_Startle)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0037)
    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0038)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
