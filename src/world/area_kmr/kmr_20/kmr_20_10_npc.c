#include "kmr_20.h"
#include "effects.h"
#include "animation_script.h"

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

extern AnimScript Entity_SimpleSpring_AnimLaunch;

API_CALLABLE(N(func_80241738_8ED558)) {
    Entity* entity = get_entity_by_index(0);

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, Entity_SimpleSpring_AnimLaunch);
    return ApiStatus_DONE2;
}

NpcSettings N(NpcSettings_Parakarry) = {
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

s32** N(varStash) = {
    NULL
};

EvtScript N(D_8024A90C_8F672C) = {
    EVT_CALL(ShowGotItem, LVar0, TRUE, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024A93C) = {
    EVT_CALL(ShowGotItem, LVar0, TRUE, 16)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024A96C_8F678C) = {
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_80007)
    EVT_WAIT(20)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024A9B4_8F67D4) = {
    EVT_IF_NE(GB_KootFavor_Current, 5)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(GF_KMR20_Gift_LuigisAutograph, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    EVT_EXEC_WAIT(N(D_8024A96C_8F678C))
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
    EVT_SET(LVar0, 111)
    EVT_SET(LVar1, 1)
    EVT_EXEC_WAIT(N(D_8024A90C_8F672C))
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

EvtScript N(EVS_8024AC34) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_IdleSit)
    EVT_CALL(SetNpcPos, NPC_Luigi, 379, 20, -60)
    EVT_CALL(InterpNpcYaw, NPC_Luigi, 39, 0)
    EVT_CALL(SetNpcCollisionSize, NPC_Luigi, 43, 24)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 495, 30, -115)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 495, 0, -115)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(620.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Luigi, LVar0, LVar1, LVar2)
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
            EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_IdleSit)
            EVT_WAIT(10)
            EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_TalkSit)
            EVT_WAIT(25)
        EVT_END_LOOP
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_IdleSit)
    EVT_END_THREAD
    EVT_WAIT(70)
    EVT_CALL(GetNpcPos, NPC_Luigi, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(80)
    EVT_CALL(SpeakToPlayer, NPC_Luigi, ANIM_Luigi_TalkSit, ANIM_Luigi_IdleSit, 5, MSG_CH0_00DB)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtNpc, NPC_Luigi, SOUND_263, 0)
    EVT_CALL(ShowEmote, NPC_Luigi, EMOTE_QUESTION, -30, 40, TRUE, 0, 0, 0, 0)
    EVT_WAIT(25)
    EVT_THREAD
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 495, 30, -115)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 495, 0, -115)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(620.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_SET(MF_Unk_0B, TRUE)
    EVT_WAIT(15)
    EVT_CALL(SetNpcFlagBits, NPC_Luigi, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Luigi, NPC_FLAG_ENABLE_HIT_SCRIPT, FALSE)
    EVT_CALL(PlaySoundAtNpc, NPC_Luigi, SOUND_262, 0)
    EVT_CALL(ShowEmote, NPC_Luigi, EMOTE_EXCLAMATION, -30, 20, TRUE, 0, 0, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Jump)
    EVT_CALL(GetNpcPos, NPC_Luigi, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Luigi, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Idle)
    EVT_WAIT(15)
    EVT_CALL(SpeakToPlayer, NPC_Luigi, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH0_00DC)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Run)
        EVT_CALL(NpcMoveTo, NPC_Luigi, 531, -128, 50)
        EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_Luigi, LVar0, LVar1, LVar2)
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
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x00000102)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, 554, -195, 28)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x00000106)
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
    EVT_CALL(SpeakToPlayer, NPC_Luigi, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00DD)
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Idle)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_StillBack)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtNpc, NPC_Luigi, SOUND_263, 0)
    EVT_CALL(ShowEmote, NPC_Luigi, EMOTE_QUESTION, -30, 30, TRUE, 0, 0, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Run)
    EVT_CALL(NpcMoveTo, NPC_Luigi, 524, -152, 10)
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Idle)
    EVT_WAIT(15)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 39, 0)
        EVT_WAIT(45)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 219, 0)
    EVT_END_THREAD
    EVT_CALL(ShowEmote, NPC_Luigi, EMOTE_ELLIPSIS, 20, 85, TRUE, 0, 0, 0, 0)
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtNpc, NPC_PARTNER, SOUND_263, 0)
    EVT_CALL(ShowEmote, NPC_PARTNER, EMOTE_QUESTION, -20, 70, TRUE, 0, 0, 0, 0)
    EVT_WAIT(110)
    EVT_CALL(SpeakToPlayer, NPC_Luigi, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00DE)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, 0x00000108, 0x00000106, 5, MSG_CH0_00DF)
        EVT_CASE_EQ(PARTNER_KOOPER)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, 0x00000108, 0x00000106, 5, MSG_CH0_00E0)
        EVT_CASE_EQ(PARTNER_BOMBETTE)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, 0x00000108, 0x00000106, 5, MSG_CH0_00E1)
        EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, 0x00000108, 0x00000106, 5, MSG_CH0_00E2)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, 0x00000101, 0x00000109, 5, MSG_CH0_00DB)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Luigi, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00E3)
    EVT_CALL(SetNpcFlagBits, NPC_Luigi, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Luigi, NPC_FLAG_ENABLE_HIT_SCRIPT, TRUE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_WAIT(15)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B844_8F7664) = {
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

EvtScript N(EVS_NpcIdle_Parakarry_A) = {
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

EvtScript N(EVS_NpcIdle_Parakarry_B) = {
    EVT_LABEL(10)
    EVT_SET(LVar0, MF_Unk_0C)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_2, FALSE)
    EVT_ELSE
        EVT_CALL(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_2, TRUE)
    EVT_END_IF
    EVT_WAIT(3)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024BD40) = {
    EVT_SET(GF_KMR20_CaughtLuigiInBasement, TRUE)
    EVT_SET(AF_KMR_0C, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_Luigi_Idle)
    EVT_CALL(SetNpcVar, NPC_Parakarry, 0, 1)
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
        EVT_CALL(GetNpcPos, NPC_Parakarry, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.5))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_WAIT(25)
    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00E9)
    EVT_WAIT(15)
    EVT_CALL(InterpNpcYaw, NPC_Parakarry, 270, 0)
    EVT_WAIT(25)
    EVT_CALL(InterpNpcYaw, NPC_Parakarry, 90, 0)
    EVT_WAIT(6)
    EVT_CALL(InterpNpcYaw, NPC_Parakarry, 270, 0)
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Parakarry, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Parakarry, LVar0, LVar1, LVar2, 9)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00EA)
    EVT_CALL(InterpNpcYaw, NPC_Parakarry, 90, 0)
    EVT_WAIT(5)
    EVT_CALL(EnableModel, MODEL_o200, FALSE)
    EVT_CALL(InterpNpcYaw, NPC_Parakarry, 270, 0)
    EVT_WAIT(5)
    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 5, MSG_CH0_00EB)
    EVT_WAIT(3)
    EVT_CALL(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_Luigi_Run)
    EVT_CALL(NpcMoveTo, NPC_Parakarry, -130, -17, 15)
    EVT_CALL(NpcJump0, NPC_Parakarry, -145, -54, -45, 10)
    EVT_CALL(PlaySoundAtNpc, NPC_Parakarry, SOUND_2086, 0)
    EVT_CALL(N(func_80241738_8ED558))
    EVT_THREAD
        EVT_WAIT(3)
        EVT_EXEC(N(D_80245374_8F1194))
    EVT_END_THREAD
    EVT_CALL(NpcJump0, NPC_Parakarry, -145, 30, -45, 20)
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_100, FALSE)
        EVT_CALL(NpcMoveTo, NPC_Parakarry, 20, -80, 15)
        EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_Luigi_Idle)
        EVT_CALL(SetNpcPos, NPC_Parakarry, 48, 30, -5)
        EVT_CALL(InterpNpcYaw, NPC_Parakarry, 270, 0)
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

EvtScript N(EVS_NpcIdle_Parakarry_C) = {
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
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_262, 0)
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

EvtScript N(EVS_NpcInteract_Parakarry) = {
    EVT_IF_EQ(MF_Unk_0A, TRUE)
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
    EVT_EXEC_WAIT(N(D_8024A9B4_8F67D4))
    EVT_IF_NE(MF_Unk_0A, TRUE)
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

EvtScript N(EVS_NpcInit_Parakarry) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    EVT_CALL(SetNpcCollisionSize, NPC_SELF, 45, 24)
    EVT_IF_EQ(MF_Unk_0A, TRUE)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Parakarry)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, -145, 30, -50)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Parakarry_B)))
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_IF_EQ(GF_KMR20_CaughtLuigiInBasement, FALSE)
                EVT_CALL(SetNpcPos, NPC_SELF, -83, -80, -54)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Parakarry_A)))
                EVT_SET(MF_Unk_0D, TRUE)
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_Parakarry, 48, 30, -5)
                EVT_CALL(InterpNpcYaw, NPC_Parakarry, 90, 0)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_KMR20_CaughtLuigiReadingLetter, FALSE)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_ReadLetter)
                EVT_CALL(SetNpcPos, NPC_SELF, -102, 30, -85)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Parakarry_C)))
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_SELF, 42, 30, -6)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Luigi) = {
    EVT_CALL(SetNpcVar, NPC_SELF, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Idle)
    EVT_CALL(SetNpcCollisionSize, NPC_SELF, 45, 24)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Parakarry)))
    EVT_IF_EQ(MF_Unk_0A, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_CALL(SetNpcPos, NPC_SELF, 500, 0, -200)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, 300, 50, 150)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_IdleSit)
            EVT_CALL(SetNpcAux, NPC_SELF, EVT_PTR(N(D_8024B844_8F7664)))
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, 560, 0, -75)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Luigi)))
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_CALL(SetNpcPos, NPC_SELF, 300, 50, 150)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_IdleSit)
            EVT_CALL(SetNpcAux, NPC_SELF, EVT_PTR(N(D_8024B844_8F7664)))
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, 300, 115, 150)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_IdleSit)
            EVT_CALL(SetNpcAux, NPC_SELF, EVT_PTR(N(D_8024B844_8F7664)))
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_CALL(SetNpcPos, NPC_SELF, 306, 30, -145)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 39, 0)
            EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_400000, 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Parakarry) = {
    .id = NPC_Parakarry,
    .settings = &N(NpcSettings_Parakarry),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .init = &N(EVS_NpcInit_Parakarry),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
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

StaticNpc N(NpcData_Luigi) = {
    .id = NPC_Luigi,
    .settings = &N(NpcSettings_Parakarry),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .init = &N(EVS_NpcInit_Luigi),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
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
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, 482, 0, -286, 15)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, 726, 0, -153, 15)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, 603, 0, 0, 15)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, 557, 0, 130, 15)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, 357, 0, 87, 15)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, 344, 30, -8, 15)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, 276, 138, 22, 15)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, 360, 61, -117, 15)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
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
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_203F, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
    EVT_CALL(NpcJump0, NPC_SELF, 495, 0, -108, 15)
    EVT_WAIT(3)
    EVT_CALL(NpcMoveTo, NPC_SELF, 550, -170, 15)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
    EVT_CALL(NpcJump0, NPC_SELF, 594, 30, -220, 15)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_ENTER_PIPE, 0)
    EVT_CALL(func_802CFE2C, -1, 0x00000800)
    EVT_CALL(func_802CFD30, -1, 5, 2, 1, 1, 0)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 10)
    EVT_LOOP(30)
        EVT_SUB(LVar1, 1)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_ShyGuy) = {
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_203E, 0)
    EVT_SET(GF_KMR20_ChasedOffShyGuy, TRUE)
    EVT_CALL(SetNpcVar, NPC_Luigi, 0, 1)
    EVT_WAIT(2)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_10000000, 1)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_ShyGuy)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH4_DEFEATED_GENERAL_GUY)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(GF_KMR20_ChasedOffShyGuy, FALSE)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
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
    .flags = ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_100000 | ENEMY_FLAGS_200000 | ENEMY_FLAGS_400000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_10000000,
    .init = &N(EVS_NpcInit_ShyGuy),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
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

NpcGroupList N(NpcGroup1) = {
    NPC_GROUP(N(NpcData_Parakarry)),
    NPC_GROUP(N(NpcData_Luigi)),
    NPC_GROUP(N(NpcData_ShyGuy)),
    {}
};
