#include "kmr_20.h"
#include "effects.h"
#include "animation_script.h"

extern AnimScript Entity_SimpleSpring_AnimLaunch;

NpcSettings N(NpcSettings_Luigi) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_ShyGuy) = {
    .height = 23,
    .radius = 22,
    .level = 14,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

#include "world/common/complete/GiveReward.inc.c"

API_CALLABLE(N(PlaySpringLaunchAnimation)) {
    Entity* entity = get_entity_by_index(0);

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, Entity_SimpleSpring_AnimLaunch);
    return ApiStatus_DONE2;
}

#include "world/common/atomic/MarioSalute.inc.c"

EvtScript N(EVS_KootFavorCheck_Luigi) = {
    EVT_IF_NE(GB_KootFavor_Current, KOOT_FAVOR_CH3_1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(GF_KMR20_Gift_LuigisAutograph, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    EVT_EXEC_WAIT(N(EVS_MarioSalute))
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_0103)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_NodYes)
    EVT_WAIT(40)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_0104)
    EVT_CALL(GetNpcYaw, NPC_SELF, LVar0)
    EVT_SET(LVar1, LVar0)
    EVT_ADD(LVar1, 180)
    EVT_CALL(InterpNpcYaw, NPC_SELF, LVar1, 5)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_IdleBack)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 5)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_0105)
    EVT_WAIT(10)
    EVT_SET(LVar0, ITEM_KOOT_MERLUVLEE_AUTOGRAPH)
    EVT_SET(LVar1, 1)
    EVT_EXEC_WAIT(N(GiveItemReward))
    EVT_CALL(AddKeyItem, LVar0)
    EVT_SET(GF_KMR20_Gift_LuigisAutograph, TRUE)
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_IF_LT(GB_StoryProgress, STORY_CH4_DEFEATED_GENERAL_GUY)
            EVT_CALL(GetSelfVar, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Run)
                EVT_WAIT(1)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_LuigiWaitingAround) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_IdleSit)
    EVT_CALL(SetNpcPos, NPC_Luigi_1, 379, 20, -60)
    EVT_CALL(InterpNpcYaw, NPC_Luigi_1, 39, 0)
    EVT_CALL(SetNpcCollisionSize, NPC_Luigi_1, 43, 24)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 495, 30, -115)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 495, 0, -115)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(620.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 25)
        EVT_ADD(LVar2, 2)
        EVT_LOOP(3)
            EVT_PLAY_EFFECT(EFFECT_MUSIC_NOTE, 2, LVar0, LVar1, LVar2)
            EVT_WAIT(13)
            EVT_PLAY_EFFECT(EFFECT_MUSIC_NOTE, 2, LVar0, LVar1, LVar2)
            EVT_WAIT(22)
        EVT_END_LOOP
        EVT_PLAY_EFFECT(EFFECT_MUSIC_NOTE, 2, LVar0, LVar1, LVar2)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(3)
            EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_IdleSit)
            EVT_WAIT(10)
            EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_TalkSit)
            EVT_WAIT(25)
        EVT_END_LOOP
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_IdleSit)
    EVT_END_THREAD
    EVT_WAIT(70)
    EVT_CALL(GetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(80)
    EVT_CALL(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_TalkSit, ANIM_Luigi_IdleSit, 5, MSG_CH0_00DB)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtNpc, NPC_Luigi_1, SOUND_263, SOUND_SPACE_MODE_0)
    EVT_CALL(ShowEmote, NPC_Luigi_1, EMOTE_QUESTION, -30, 40, TRUE, 0, 0, 0, 0)
    EVT_WAIT(25)
    EVT_THREAD
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 495, 30, -115)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 495, 0, -115)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(620.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_SET(MF_ReadyForPlayerEntry, TRUE)
    EVT_WAIT(15)
    EVT_CALL(SetNpcFlagBits, NPC_Luigi_1, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Luigi_1, NPC_FLAG_8, FALSE)
    EVT_CALL(PlaySoundAtNpc, NPC_Luigi_1, SOUND_262, SOUND_SPACE_MODE_0)
    EVT_CALL(ShowEmote, NPC_Luigi_1, EMOTE_EXCLAMATION, -30, 20, TRUE, 0, 0, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Jump)
    EVT_CALL(GetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Luigi_1, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    EVT_WAIT(15)
    EVT_CALL(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00DC)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Run)
        EVT_CALL(NpcMoveTo, NPC_Luigi_1, 531, -128, 50)
        EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 1, LVar0, LVar1, LVar2, 0, 0)
            EVT_WAIT(6)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_CALL(PlayerMoveTo, 556, -158, 30)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_WAIT(15)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, 554, -195, 28)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 495, 30, -115)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 495, 0, -115)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(620.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(15)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 564, 0, -176)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 556, 0, -158)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(270.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(40)
    EVT_CALL(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00DD)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_StillBack)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtNpc, NPC_Luigi_1, SOUND_263, SOUND_SPACE_MODE_0)
    EVT_CALL(ShowEmote, NPC_Luigi_1, EMOTE_QUESTION, -30, 30, TRUE, 0, 0, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Run)
    EVT_CALL(NpcMoveTo, NPC_Luigi_1, 524, -152, 10)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    EVT_WAIT(15)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 39, 0)
        EVT_WAIT(45)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 219, 0)
    EVT_END_THREAD
    EVT_CALL(ShowEmote, NPC_Luigi_1, EMOTE_ELLIPSIS, 20, 85, TRUE, 0, 0, 0, 0)
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtNpc, NPC_PARTNER, SOUND_263, SOUND_SPACE_MODE_0)
    EVT_CALL(ShowEmote, NPC_PARTNER, EMOTE_QUESTION, -20, 70, TRUE, 0, 0, 0, 0)
    EVT_WAIT(110)
    EVT_CALL(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00DE)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH0_00DF)
        EVT_CASE_EQ(PARTNER_KOOPER)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH0_00E0)
        EVT_CASE_EQ(PARTNER_BOMBETTE)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH0_00E1)
        EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 5, MSG_CH0_00E2)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_STILL, PARTNER_ANIM_HURT, 5, MSG_CH0_00DB)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00E3)
    EVT_CALL(SetNpcFlagBits, NPC_Luigi_1, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Luigi_1, NPC_FLAG_8, TRUE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_WAIT(15)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_Luigi_WhistleAtopObstacle) = {
    EVT_LABEL(20)
        EVT_CALL(GetNpcVar, NPC_SELF, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(21)
        EVT_END_IF
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_IdleSit)
        EVT_CALL(GetNpcPos, NPC_SELF, LVarA, LVarB, LVarC)
        EVT_ADD(LVarB, 25)
        EVT_ADD(LVarC, 2)
        EVT_PLAY_EFFECT(EFFECT_MUSIC_NOTE, 2, LVarA, LVarB, LVarC)
        EVT_WAIT(13)
        EVT_CALL(GetNpcVar, NPC_SELF, 0, LVar0)
        EVT_CALL(GetNpcPos, NPC_SELF, LVarA, LVarB, LVarC)
        EVT_ADD(LVarB, 25)
        EVT_ADD(LVarC, 2)
        EVT_PLAY_EFFECT(EFFECT_MUSIC_NOTE, 2, LVarA, LVarB, LVarC)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(21)
        EVT_END_IF
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_TalkSit)
        EVT_WAIT(22)
        EVT_GOTO(20)
    EVT_LABEL(21)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Luigi_InBasement) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    EVT_LABEL(10)
        EVT_WAIT(1)
        EVT_IF_EQ(MF_Unk_0C, FALSE)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_LABEL(20)
        EVT_IF_EQ(MF_Unk_0C, FALSE)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetNpcVar, NPC_SELF, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(21)
        EVT_END_IF
        EVT_CALL(GetNpcPos, NPC_SELF, LVarA, LVarB, LVarC)
        EVT_ADD(LVarA, 6)
        EVT_ADD(LVarB, 58)
        EVT_ADD(LVarC, 2)
        EVT_PLAY_EFFECT(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        EVT_WAIT(20)
        EVT_CALL(GetNpcPos, NPC_SELF, LVarA, LVarB, LVarC)
        EVT_SUB(LVarA, 4)
        EVT_ADD(LVarB, 55)
        EVT_SUB(LVarC, 1)
        EVT_PLAY_EFFECT(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        EVT_IF_EQ(MF_Unk_0C, FALSE)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetNpcVar, NPC_SELF, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(21)
        EVT_END_IF
        EVT_WAIT(28)
        EVT_GOTO(20)
    EVT_LABEL(21)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Luigi_InBedroom) = {
    EVT_LABEL(10)
        EVT_SET(LVar0, MF_Unk_0C)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(SetNpcFlagBits, NPC_Luigi_0, NPC_FLAG_2, FALSE)
        EVT_ELSE
            EVT_CALL(SetNpcFlagBits, NPC_Luigi_0, NPC_FLAG_2, TRUE)
        EVT_END_IF
        EVT_WAIT(3)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_CaughtLuigiInBasement) = {
    EVT_SET(GF_KMR20_CaughtLuigiInBasement, TRUE)
    EVT_SET(AF_KMR_0C, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_0, ANIM_Luigi_Idle)
    EVT_CALL(SetNpcVar, NPC_Luigi_0, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(2)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(GetNpcPos, NPC_SELF, LVarA, LVarB, LVarC)
        EVT_ADD(LVarB, 45)
        EVT_ADD(LVarC, 1)
        EVT_PLAY_EFFECT(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        EVT_WAIT(25)
        EVT_PLAY_EFFECT(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        EVT_WAIT(25)
        EVT_PLAY_EFFECT(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        EVT_WAIT(25)
        EVT_PLAY_EFFECT(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        EVT_WAIT(25)
        EVT_PLAY_EFFECT(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        EVT_WAIT(25)
        EVT_PLAY_EFFECT(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        EVT_WAIT(25)
        EVT_PLAY_EFFECT(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        EVT_WAIT(25)
        EVT_PLAY_EFFECT(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
        EVT_WAIT(25)
        EVT_PLAY_EFFECT(EFFECT_MUSIC_NOTE, 0, LVarA, LVarB, LVarC)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Luigi_0, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.5))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_WAIT(25)
    EVT_CALL(SpeakToPlayer, NPC_Luigi_0, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00E9)
    EVT_WAIT(15)
    EVT_CALL(InterpNpcYaw, NPC_Luigi_0, 270, 0)
    EVT_WAIT(25)
    EVT_CALL(InterpNpcYaw, NPC_Luigi_0, 90, 0)
    EVT_WAIT(6)
    EVT_CALL(InterpNpcYaw, NPC_Luigi_0, 270, 0)
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Luigi_0, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Luigi_0, LVar0, LVar1, LVar2, 9)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Luigi_0, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00EA)
    EVT_CALL(InterpNpcYaw, NPC_Luigi_0, 90, 0)
    EVT_WAIT(5)
    EVT_CALL(EnableModel, MODEL_o200, FALSE)
    EVT_CALL(InterpNpcYaw, NPC_Luigi_0, 270, 0)
    EVT_WAIT(5)
    EVT_CALL(SpeakToPlayer, NPC_Luigi_0, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00EB)
    EVT_WAIT(3)
    EVT_CALL(SetNpcFlagBits, NPC_Luigi_0, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_0, ANIM_Luigi_Run)
    EVT_CALL(NpcMoveTo, NPC_Luigi_0, -130, -17, 15)
    EVT_CALL(NpcJump0, NPC_Luigi_0, -145, -54, -45, 10)
    EVT_CALL(PlaySoundAtNpc, NPC_Luigi_0, SOUND_2086, SOUND_SPACE_MODE_0)
    EVT_CALL(N(PlaySpringLaunchAnimation))
    EVT_THREAD
        EVT_WAIT(3)
        EVT_EXEC(N(EVS_SecretPanel_Flip))
    EVT_END_THREAD
    EVT_CALL(NpcJump0, NPC_Luigi_0, -145, 30, -45, 20)
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Luigi_0, NPC_FLAG_100, FALSE)
        EVT_CALL(NpcMoveTo, NPC_Luigi_0, 20, -80, 15)
        EVT_CALL(SetNpcAnimation, NPC_Luigi_0, ANIM_Luigi_Idle)
        EVT_CALL(SetNpcPos, NPC_Luigi_0, 48, 30, -5)
        EVT_CALL(InterpNpcYaw, NPC_Luigi_0, 270, 0)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Luigi_ReadingMail) = {
    EVT_LABEL(10)
    EVT_IF_EQ(MF_Unk_0C, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2, TRUE)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2, FALSE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_GT(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(GF_KMR20_CaughtLuigiReadingLetter, TRUE)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_262, SOUND_SPACE_MODE_0)
    EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, -30, 15, TRUE, 0, 0, 0, 0)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    EVT_WAIT(10)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, 37, -72, 16)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(NpcMoveTo, NPC_SELF, 42, -6, 10)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Luigi) = {
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Run)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_LABEL(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, 635, -108, 0)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, 528, 20, 0)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, 635, -108, 0)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, 528, 20, 0)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_GOTO(10)
    EVT_LABEL(100)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 39, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Luigi) = {
    EVT_IF_EQ(MF_LuigiWaiting, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00E5)
    EVT_ELSE
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00E6)
            EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00E7)
            EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00E8)
            EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00ED)
            EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
                EVT_IF_EQ(GF_KMR20_ChasedOffShyGuy, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00EE)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00EF)
                EVT_END_IF
            EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00F0)
            EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00F1)
            EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00F2)
            EVT_CASE_LT(STORY_EPILOGUE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 16, MSG_CH0_00F3)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_KootFavorCheck_Luigi))
    EVT_IF_NE(MF_LuigiWaiting, TRUE)
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_END_CASE_GROUP
            EVT_CASE_LT(STORY_EPILOGUE)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 39, 5)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Luigi_0) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    EVT_CALL(SetNpcCollisionSize, NPC_SELF, 45, 24)
    EVT_IF_EQ(MF_LuigiWaiting, TRUE)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Luigi)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, -145, 30, -50)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Luigi_InBedroom)))
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_IF_EQ(GF_KMR20_CaughtLuigiInBasement, FALSE)
                EVT_CALL(SetNpcPos, NPC_SELF, -83, -80, -54)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Luigi_InBasement)))
                EVT_SET(MF_LuigiInBasement, TRUE)
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_Luigi_0, 48, 30, -5)
                EVT_CALL(InterpNpcYaw, NPC_Luigi_0, 90, 0)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_KMR20_CaughtLuigiReadingLetter, FALSE)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_ReadLetter)
                EVT_CALL(SetNpcPos, NPC_SELF, -102, 30, -85)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Luigi_ReadingMail)))
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_SELF, 42, 30, -6)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Luigi_1) = {
    EVT_CALL(SetNpcVar, NPC_SELF, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    EVT_CALL(SetNpcCollisionSize, NPC_SELF, 45, 24)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Luigi)))
    EVT_IF_EQ(MF_LuigiWaiting, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_CALL(SetNpcPos, NPC_SELF, 500, 0, -200)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, 300, 50, 150)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_IdleSit)
            EVT_CALL(SetNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Luigi_WhistleAtopObstacle)))
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, 560, 0, -75)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Luigi)))
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_CALL(SetNpcPos, NPC_SELF, 300, 50, 150)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_IdleSit)
            EVT_CALL(SetNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Luigi_WhistleAtopObstacle)))
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, 300, 115, 150)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_IdleSit)
            EVT_CALL(SetNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Luigi_WhistleAtopObstacle)))
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_CALL(SetNpcPos, NPC_SELF, 306, 30, -145)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 39, 0)
            EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_400000, 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Luigi_0) = {
    .id = NPC_Luigi_0,
    .settings = &N(NpcSettings_Luigi),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Luigi_0),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Luigi_Still,
        .walk   = ANIM_Luigi_Still,
        .run    = ANIM_Luigi_Still,
        .chase  = ANIM_Luigi_Still,
        .anim_4 = ANIM_Luigi_Still,
        .anim_5 = ANIM_Luigi_Still,
        .death  = ANIM_Luigi_Still,
        .hit    = ANIM_Luigi_Still,
        .anim_8 = ANIM_Luigi_Still,
        .anim_9 = ANIM_Luigi_Still,
        .anim_A = ANIM_Luigi_Still,
        .anim_B = ANIM_Luigi_Still,
        .anim_C = ANIM_Luigi_Still,
        .anim_D = ANIM_Luigi_Still,
        .anim_E = ANIM_Luigi_Still,
        .anim_F = ANIM_Luigi_Still,
    },
    .tattle = MSG_NpcTattle_Luigi,
};

StaticNpc N(NpcData_Luigi_1) = {
    .id = NPC_Luigi_1,
    .settings = &N(NpcSettings_Luigi),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Luigi_1),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Luigi_Still,
        .walk   = ANIM_Luigi_Still,
        .run    = ANIM_Luigi_Still,
        .chase  = ANIM_Luigi_Still,
        .anim_4 = ANIM_Luigi_Still,
        .anim_5 = ANIM_Luigi_Still,
        .death  = ANIM_Luigi_Still,
        .hit    = ANIM_Luigi_Still,
        .anim_8 = ANIM_Luigi_Still,
        .anim_9 = ANIM_Luigi_Still,
        .anim_A = ANIM_Luigi_Still,
        .anim_B = ANIM_Luigi_Still,
        .anim_C = ANIM_Luigi_Still,
        .anim_D = ANIM_Luigi_Still,
        .anim_E = ANIM_Luigi_Still,
        .anim_F = ANIM_Luigi_Still,
    },
    .tattle = MSG_NpcTattle_Luigi,
};

EvtScript N(EVS_NpcIdle_ShyGuy) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 500, 0, -195)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, SOUND_SPACE_MODE_0)
        EVT_CALL(NpcJump0, NPC_SELF, 482, 0, -286, 15)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, SOUND_SPACE_MODE_0)
        EVT_CALL(NpcJump0, NPC_SELF, 726, 0, -153, 15)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, SOUND_SPACE_MODE_0)
        EVT_CALL(NpcJump0, NPC_SELF, 603, 0, 0, 15)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, SOUND_SPACE_MODE_0)
        EVT_CALL(NpcJump0, NPC_SELF, 557, 0, 130, 15)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, SOUND_SPACE_MODE_0)
        EVT_CALL(NpcJump0, NPC_SELF, 357, 0, 87, 15)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, SOUND_SPACE_MODE_0)
        EVT_CALL(NpcJump0, NPC_SELF, 344, 30, -8, 15)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, SOUND_SPACE_MODE_0)
        EVT_CALL(NpcJump0, NPC_SELF, 276, 138, 22, 15)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, SOUND_SPACE_MODE_0)
        EVT_CALL(NpcJump0, NPC_SELF, 360, 61, -117, 15)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, SOUND_SPACE_MODE_0)
        EVT_CALL(NpcJump0, NPC_SELF, 427, 55, -182, 15)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_ShyGuy) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim0C)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_203F, SOUND_SPACE_MODE_0)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, SOUND_SPACE_MODE_0)
    EVT_CALL(NpcJump0, NPC_SELF, 495, 0, -108, 15)
    EVT_WAIT(3)
    EVT_CALL(NpcMoveTo, NPC_SELF, 550, -170, 15)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, SOUND_SPACE_MODE_0)
    EVT_CALL(NpcJump0, NPC_SELF, 594, 30, -220, 15)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_ENTER_PIPE, SOUND_SPACE_MODE_0)
    EVT_CALL(func_802CFE2C, NPC_SELF, 0x00000800)
    EVT_CALL(func_802CFD30, NPC_SELF, FOLD_TYPE_5, 2, 1, 1, 0)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 10)
    EVT_LOOP(30)
        EVT_SUB(LVar1, 1)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_ShyGuy) = {
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_203E, SOUND_SPACE_MODE_0)
    EVT_SET(GF_KMR20_ChasedOffShyGuy, TRUE)
    EVT_CALL(SetNpcVar, NPC_Luigi_1, 0, 1)
    EVT_WAIT(2)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_8000000 | ENEMY_FLAG_10000000, 1)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_ShyGuy)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH4_DEFEATED_GENERAL_GUY)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(GF_KMR20_ChasedOffShyGuy, FALSE)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ShyGuy)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_ShyGuy)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_ShyGuy) = {
    .id = NPC_ShyGuy,
    .settings = &N(NpcSettings_ShyGuy),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_100000 | ENEMY_FLAG_200000 | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_10000000,
    .init = &N(EVS_NpcInit_ShyGuy),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_ShyGuy_Red_Anim01,
        .walk   = ANIM_ShyGuy_Red_Anim02,
        .run    = ANIM_ShyGuy_Red_Anim03,
        .chase  = ANIM_ShyGuy_Red_Anim03,
        .anim_4 = ANIM_ShyGuy_Red_Anim01,
        .anim_5 = ANIM_ShyGuy_Red_Anim01,
        .death  = ANIM_ShyGuy_Red_Anim0C,
        .hit    = ANIM_ShyGuy_Red_Anim0C,
        .anim_8 = ANIM_ShyGuy_Red_Anim15,
        .anim_9 = ANIM_ShyGuy_Red_Anim12,
        .anim_A = ANIM_ShyGuy_Red_Anim11,
        .anim_B = ANIM_ShyGuy_Red_Anim10,
        .anim_C = ANIM_ShyGuy_Red_Anim05,
        .anim_D = ANIM_ShyGuy_Red_Anim01,
        .anim_E = ANIM_ShyGuy_Red_Anim01,
        .anim_F = ANIM_ShyGuy_Red_Anim01,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Luigi_0)),
    NPC_GROUP(N(NpcData_Luigi_1)),
    NPC_GROUP(N(NpcData_ShyGuy)),
    {}
};
