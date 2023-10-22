#include "pra_32.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/enemy/CrystalKing.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

EvtScript N(EVS_AnimateCam_CrystalKing) = {
    EVT_SET(MV_CamDistance, 400)
    EVT_THREAD
        EVT_CALL(MakeLerp, 400, 300, 200 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(MV_CamDistance, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 200, 100, 200 * DT, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcPos, NPC_CrystalKing_01, 588, LVar0, 116)
        EVT_SET(LVar5, LVar0)
        EVT_ADD(LVar5, -30)
        EVT_IF_GE(LVar5, 100)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 588, LVar5, 116)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, MV_CamDistance)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_CrystalKingAppears) = {
    EVT_CALL(EnableNpcShadow, NPC_CrystalKing_01, FALSE)
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_IF_LT(LVar0, 377)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterruptUsePartner)
    EVT_CALL(SetMusicTrack, 0, SONG_CRYSTAL_KING_THEME, 0, 8)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH7_016A, 160, 40)
    EVT_CALL(SetNpcPos, NPC_CrystalKing_01, 588, 200, 116)
    EVT_CALL(SetNpcImgFXParams, NPC_CrystalKing_01, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    EVT_CALL(GetNpcPos, NPC_CrystalKing_01, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, -30)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(12.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
    EVT_CALL(SetPlayerPos, 475, 100, 116)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(PartnerIsFlying, LVar4)
    EVT_IF_EQ(LVar4, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 452, 116, 120)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_PARTNER, 452, 100, 120)
    EVT_END_IF
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_CrystalKing_01, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 10)
        EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 0, LVar0, LVar1, LVar2, 50, 50, 1, 40, 50)
        EVT_WAIT(20 * DT)
        EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 0, LVar0, LVar1, LVar2, 50, 50, 1, 40, 50)
        EVT_WAIT(20 * DT)
        EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 0, LVar0, LVar1, LVar2, 50, 50, 1, 40, 50)
        EVT_WAIT(20 * DT)
        EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 1, LVar0, LVar1, LVar2, 50, 50, 1, 20, 40)
        EVT_WAIT(20 * DT)
        EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 1, LVar0, LVar1, LVar2, 50, 50, 1, 20, 40)
        EVT_WAIT(20 * DT)
        EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 1, LVar0, LVar1, LVar2, 50, 50, 1, 20, 40)
        EVT_WAIT(20 * DT)
        EVT_PLAY_EFFECT(EFFECT_BIG_SNOWFLAKES, 0, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 2, LVar0, LVar1, LVar2, 10)
        EVT_WAIT(20 * DT)
        EVT_PLAY_EFFECT(EFFECT_BIG_SNOWFLAKES, 0, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 7)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 255, 120 * DT, EASING_LINEAR)
    EVT_LABEL(5)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetNpcImgFXParams, NPC_CrystalKing_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(5)
    EVT_END_IF
    EVT_CALL(EnableNpcShadow, NPC_CrystalKing_01, TRUE)
    EVT_WAIT(30 * DT)
    EVT_EXEC_WAIT(N(EVS_AnimateCam_CrystalKing))
    EVT_WAIT(20 * DT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_CrystalKing_01, LVar3, LVar4, LVar5)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar3, LVar4, LVar2)
    EVT_ADD(LVar0, LVar3)
    EVT_DIV(LVar0, 2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_CrystalKing_01, ANIM_CrystalKing_Anim09, ANIM_CrystalKing_Anim09, 0, MSG_CH7_016B)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Run)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.5 / DT))
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1309, 0)
        EVT_CALL(PlayerMoveTo, 564, 116, 0)
    EVT_END_THREAD
    EVT_CALL(StartBossBattle, SONG_CRYSTAL_KING_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BossDefeated) = {
    EVT_THREAD
        EVT_WAIT(2)
        EVT_CALL(FadeOutMusic, 0, 500)
    EVT_END_THREAD
    EVT_CALL(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_1, TRUE)
    EVT_CALL(SetPlayerPos, 475, 100, 116)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetNpcPos, NPC_CrystalKing_01, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(12.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_CrystalKing_01, ANIM_CrystalKing_Anim09, ANIM_CrystalKing_Anim09, 0, MSG_CH7_016C)
    EVT_THREAD
        EVT_CALL(SetNpcRotationPivot, NPC_CrystalKing_01, 30)
        EVT_CALL(MakeLerp, 0, 19 * 360, 210 * DT, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_CrystalKing_01, 0, 0, LVar0)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 100, 200, 210 * DT, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVarA, LVar0)
            EVT_MULF(LVarA, EVT_FLOAT(0.01))
            EVT_CALL(SetNpcScale, NPC_CrystalKing_01, LVarA, LVarA, 1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 255, 122, 30 * DT, EASING_COS_IN_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcImgFXParams, NPC_CrystalKing_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_CrystalKing_01, SOUND_CRYSTAL_KING_DISAPPEAR, SOUND_SPACE_DEFAULT)
        EVT_CALL(GetNpcPos, NPC_CrystalKing_01, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SHIMMER_BURST, 0, LVar0, LVar1, LVar2, 1, 130)
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_CALL(MakeLerp, 120, 0, 30 * DT, EASING_COS_IN_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcImgFXParams, NPC_CrystalKing_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcImgFXParams, NPC_CrystalKing_01, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    EVT_CALL(GetNpcPos, NPC_CrystalKing_01, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 1, LVar0, LVar1, LVar2, 40)
    EVT_CALL(SetNpcPos, NPC_CrystalKing_01, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_WAIT(75 * DT)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1309, SURFACE_TYPE_SNOW)
    EVT_WAIT(25)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_EXEC(N(EVS_SpawnStarCard))
    EVT_SET(GB_StoryProgress, STORY_CH7_DEFEATED_CRYSTAL_KING)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_CrystalKing) = {
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_Scene_BossDefeated)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_DEFEATED_CRYSTAL_KING)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_Scene_CrystalKingAppears)))
        EVT_CASE_EQ(STORY_CH7_DEFEATED_CRYSTAL_KING)
            EVT_EXEC(N(EVS_RespawnStarCard))
        EVT_CASE_GT(STORY_CH7_DEFEATED_CRYSTAL_KING)
    EVT_END_SWITCH
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, FALSE)
    EVT_CALL(SetNpcYaw, NPC_CrystalKing_01, 270)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_CrystalKing_Aux) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kalmar) = {
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_CrystalKing_01)[] = {
    {
        .id = NPC_CrystalKing_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_CrystalKing_Aux),
        .settings = &N(NpcSettings_CrystalKing),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = CRYSTAL_KING_ANIMS,
    },
    {
        .id = NPC_CrystalKing_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .settings = &N(NpcSettings_CrystalKing),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = CRYSTAL_KING_ANIMS,
    },
    {
        .id = NPC_Kalmar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Kalmar),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KALMAR_ANIMS,
    },
    {
        .id = NPC_CrystalKing_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_CrystalKing),
        .settings = &N(NpcSettings_CrystalKing),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = CRYSTAL_KING_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_CrystalKing_01), BTL_PRA2_FORMATION_00),
    {}
};

