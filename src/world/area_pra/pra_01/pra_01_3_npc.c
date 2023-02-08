#include "pra_01.h"
#include "effects.h"

#include "world/common/npc/StarSpirit.inc.c"

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/NormalItemChoice.inc.c"

API_CALLABLE(N(UpgradeStarPowerCh7)) {
    set_max_SP(7);
    gPlayerData.curHP = gPlayerData.curMaxHP;
    gPlayerData.curFP = gPlayerData.curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_Kalmar) = {
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

EvtScript N(EVS_Scene_RescuedKalmar) = {
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar0)
    EVT_ADD(LVar3, -50)
    EVT_SET(LVar4, LVar1)
    EVT_ADD(LVar4, 26)
    EVT_CALL(SetNpcPos, NPC_Kalmar, LVar3, LVar4, LVar2)
    EVT_CALL(PlayerFaceNpc, NPC_Kalmar, FALSE)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Kalmar, 0)
    EVT_ADD(LVar0, -25)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(575.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 18, -5)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(40)
    EVT_CALL(SpeakToPlayer, NPC_Kalmar, ANIM_WorldKalmar_Talk, ANIM_WorldKalmar_Idle, 512, MSG_CH7_016D)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 18, -6)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(MakeLerp, 0, 360, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_Kalmar, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableNpcAI, NPC_Kalmar, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Leap)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_GotItem)
    EVT_CALL(PlaySoundAtPlayer, SOUND_139, SOUND_SPACE_MODE_0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar1)
    EVT_ADD(LVar1, 50)
    EVT_ADD(LVar2, 10)
    EVT_ADD(LVar3, 30)
    EVT_LOOP(5)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 20)
        EVT_WAIT(6)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 1, LVar0, LVar3, LVar2, 20)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtPlayer, SOUND_188, SOUND_SPACE_MODE_0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 30)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Idle)
    EVT_CALL(EnableNpcAI, NPC_Kalmar, TRUE)
    EVT_CALL(N(UpgradeStarPowerCh7))
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0197, 160, 40)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Kalmar, ANIM_WorldKalmar_Talk, ANIM_WorldKalmar_Idle, 512, MSG_CH7_016E)
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -25)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Kalmar, ANIM_WorldKalmar_Talk, ANIM_WorldKalmar_Idle, 512, MSG_CH7_016F)
    EVT_CALL(SetNpcFlagBits, NPC_Kalmar, NPC_FLAG_40000, TRUE)
    EVT_THREAD
        EVT_LOOP(25)
            EVT_CALL(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 20)
            EVT_WAIT(4)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 1800)
        EVT_CALL(MakeLerp, LVar2, LVar3, 100, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_Kalmar, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Kalmar, LVar2, LVar3, LVar4)
        EVT_SET(LVar5, LVar3)
        EVT_ADD(LVar5, 180)
        EVT_CALL(MakeLerp, LVar3, LVar5, 100, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, NPC_Kalmar, LVar2, LVar0, LVar4)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, NPC_Kalmar, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtNpc, NPC_Kalmar, SOUND_2045, SOUND_SPACE_MODE_0)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_WAIT(90)
    EVT_CALL(ResetCam, CAM_DEFAULT, 3)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_SET(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kalmar) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kalmar)))
    EVT_EXEC(N(EVS_Scene_RescuedKalmar))
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Kalmar) = {
    .id = NPC_Kalmar,
    .settings = &N(NpcSettings_StarSpirit),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_200000 | ENEMY_FLAG_400000,
    .init = &N(EVS_NpcInit_Kalmar),
    .drops = NPC_NO_DROPS,
    .animations = KALMAR_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kalmar), BTL_PRA3_FORMATION_01, BTL_PRA3_STAGE_00),
    {}
};
