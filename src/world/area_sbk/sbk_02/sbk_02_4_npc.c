#include "sbk_02.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/npc/StarSpirit.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"

#include "world/common/complete/NormalItemChoice.inc.c"

#include "world/common/complete/GiveReward.inc.c"

EvtScript N(EVS_NpcIdle_Mamar) = {
    EVT_LOOP(0)
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(UpgradeStarPowerCh2)) {
    set_max_star_power(2);
    gPlayerData.curHP = gPlayerData.curMaxHP;
    gPlayerData.curFP = gPlayerData.curMaxFP;
    sync_status_bar();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_RescuedMamar) = {
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar0)
    EVT_ADD(LVar3, -50)
    EVT_SET(LVar4, LVar1)
    EVT_ADD(LVar4, 26)
    EVT_CALL(SetNpcPos, NPC_Mamar, LVar3, LVar4, LVar2)
    EVT_CALL(PlayerFaceNpc, NPC_Mamar, FALSE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 600)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Mamar, ANIM_WorldMamar_TalkHappy, ANIM_WorldMamar_Idle, SPEECH_FLAG_200, MSG_CH2_00EB)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 18, -9)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(MakeLerp, 0, 360, 10 * DT, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_Mamar, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableNpcAI, NPC_Mamar, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Leap)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_UsePower)
    EVT_CALL(PlaySoundAtPlayer, SOUND_RECEIVE_STAR_POWER, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar1)
    EVT_ADD(LVar1, 50)
    EVT_ADD(LVar2, 10)
    EVT_ADD(LVar3, 30)
    EVT_LOOP(5)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 20)
        EVT_WAIT(6 * DT)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 1, LVar0, LVar3, LVar2, 20)
        EVT_WAIT(6 * DT)
    EVT_END_LOOP
    EVT_WAIT(20 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_GET_STAR_POWER_WAVE, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 30)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Idle)
    EVT_CALL(EnableNpcAI, NPC_Mamar, TRUE)
    EVT_CALL(N(UpgradeStarPowerCh2))
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0192, 160, 40)
    EVT_WAIT(10 * DT)
    EVT_CALL(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Mamar, ANIM_WorldMamar_TalkHappy, ANIM_WorldMamar_Idle, SPEECH_FLAG_200, MSG_CH2_00EC)
    EVT_WAIT(10 * DT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Mamar, LVar3, LVar4, LVar5)
    EVT_ADD(LVar0, LVar3)
    EVT_DIV(LVar0, 2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Mamar, ANIM_WorldMamar_TalkHappy, ANIM_WorldMamar_Idle, SPEECH_FLAG_200, MSG_CH2_00ED)
    EVT_CALL(SetNpcFlagBits, NPC_Mamar, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    EVT_THREAD
        EVT_LOOP(25)
            EVT_CALL(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 20, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(4 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 1800)
        EVT_CALL(MakeLerp, LVar2, LVar3, 100, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_Mamar, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Mamar, LVar2, LVar3, LVar4)
        EVT_SET(LVar5, LVar3)
        EVT_ADD(LVar5, 180)
        EVT_CALL(MakeLerp, LVar3, LVar5, 100 * DT, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, NPC_Mamar, LVar2, LVar0, LVar4)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, NPC_Mamar, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Mamar, SOUND_STAR_SPIRIT_DEPART_1, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_WAIT(90 * DT)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_SET(GB_StoryProgress, STORY_CH2_STAR_SPRIT_DEPARTED)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Mamar) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, sbk_02_ENTRY_5)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Mamar)))
        EVT_EXEC(N(EVS_Scene_RescuedMamar))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(CheckTradeEventTime)) {
    s32 timeElapsed = (gPlayerData.frameCounter - gPlayerData.tradeEventStartTime) / 3600;
    script->varTable[0] = timeElapsed < script->varTable[0];
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetTradeEventItemCount)) {
    script->varTable[0] = get_item_count();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInteract_TradingToad) = {
    EVT_SET(LVar0, 5)
    EVT_CALL(N(CheckTradeEventTime))
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_CH2_00EE)
        EVT_WAIT(10)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
        EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_SET(GF_TradingEvent2_Active, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(GetTradeEventItemCount))
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_CH2_00EF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_CH2_00F0)
    EVT_CHOOSE_ANY_CONSUMABLE(2)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_CH2_00F4)
            EVT_RETURN
        EVT_CASE_EQ(ITEM_NUTTY_CAKE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_CH2_00F1)
            EVT_GIVE_CONSUMABLE_REWARD(ITEM_MAPLE_SUPER)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_CH2_00F2)
            EVT_WAIT(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_SET(GF_TradingEvent2_Active, FALSE)
            EVT_ADD(GB_TradingEvent_Count, 1)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_CH2_00F3)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TradingToad) = {
    EVT_IF_NE(GF_TradingEvent2_Active, FALSE)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_TradingToad)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Mamar) = {
    .id = NPC_Mamar,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Mamar),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = MAMAR_ANIMS,
};

NpcData N(NpcData_TradingToad) = {
    .id = NPC_TradingToad,
    .pos = { 0.0f, 2.0f, 150.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_TradingToad),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Toad_Pink_Idle,
        .walk   = ANIM_Toad_Pink_Walk,
        .run    = ANIM_Toad_Pink_Run,
        .chase  = ANIM_Toad_Pink_Run,
        .anim_4 = ANIM_Toad_Pink_Idle,
        .anim_5 = ANIM_Toad_Pink_Idle,
        .death  = ANIM_Toad_Pink_Idle,
        .hit    = ANIM_Toad_Pink_Disappointed,
        .anim_8 = ANIM_Toad_Pink_Run,
        .anim_9 = ANIM_Toad_Pink_Run,
        .anim_A = ANIM_Toad_Pink_Run,
        .anim_B = ANIM_Toad_Pink_Run,
        .anim_C = ANIM_Toad_Pink_Run,
        .anim_D = ANIM_Toad_Pink_Run,
        .anim_E = ANIM_Toad_Pink_Run,
        .anim_F = ANIM_Toad_Pink_Run,
    },
    .tattle = MSG_NpcTattle_PrizeToad,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Mamar)),
    NPC_GROUP(N(NpcData_TradingToad)),
    {}
};
