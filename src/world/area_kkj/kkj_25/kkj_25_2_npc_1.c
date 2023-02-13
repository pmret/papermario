#include "kkj_25.h"

#define NAME_SUFFIX _Npc1

#include "world/common/npc/Bowser.inc.c"
#include "world/common/npc/Dummy.inc.c"
#include "world/common/enemy/complete/Kammy_Flying.inc.c"

#include "world/common/npc/Peach.h"
#include "world/common/npc/Twink.h"

EvtScript N(EVS_NpcIdle_Bowser_01) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Bowser_01, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -75)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 1000)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(ModifyGlobalOverrideFlags, 1, 0x00020000)
    EVT_CALL(StopSound, SOUND_22C)
    EVT_CALL(StartBossBattle, SONG_BOWSER_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Bowser_01) = {
    #define NAME_SUFFIX
    EVT_CALL(PlaySound, SOUND_22D)
    EVT_EXEC(N(EVS_80247AAC))
    EVT_RETURN
    EVT_END
    #define NAME_SUFFIX _Npc1
};

EvtScript N(EVS_NpcInit_Bowser_01) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Bowser_01)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Bowser_01)))
    EVT_CALL(SetNpcPos, NPC_Bowser_01, 350, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_BattleKammy_01) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(func_802D286C, 0x00002000)
    EVT_CALL(func_802D2520, 0x00010002, 8, 0, 0, 0, 0)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_WAIT(1)
    EVT_CALL(GetNpcPos, NPC_BattleKooper_01, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(ModifyGlobalOverrideFlags, 1, 0x00020000)
    EVT_CALL(StopSound, SOUND_22D)
    EVT_CALL(StartBossBattle, SONG_BOWSER_BATTLE)
    EVT_CALL(EnablePartnerAI)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(func_80240020_B06A20)) {
    increment_status_menu_disabled();
    set_screen_overlay_params_back(0, 255.0f);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcDefeat_BattleKammy_01) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_CALL(N(func_80240020_B06A20))
    EVT_SET(GF_KKJ25_Defeated_Kammy, TRUE)
    EVT_CALL(GotoMap, EVT_PTR("kkj_25"), kkj_25_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_BattleKammy_01) = {
    EVT_SET(LVar3, 1)
    EVT_LOOP(0)
        EVT_LOOP(5)
            EVT_CALL(GetNpcPos, NPC_BattleKammy_01, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, LVar3)
            EVT_CALL(SetNpcPos, NPC_BattleKammy_01, LVar0, LVar1, LVar2)
            EVT_WAIT(2)
        EVT_END_LOOP
        EVT_MUL(LVar3, -1)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_BattleKammy_01) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_BattleKammy_01)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_BattleKammy_01)))
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_BattleKammy_01)))
    EVT_CALL(SetNpcPos, NPC_BattleKammy_01, 460, 10, 0)
    EVT_CALL(SetNpcYaw, NPC_BattleKammy_01, 270)
    EVT_CALL(SetNpcAnimation, NPC_BattleKammy_01, ANIM_BattleKammy_Anim04)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_BattleKammy_02) = {
    EVT_CALL(SetNpcPos, NPC_BattleKammy_02, 300, -100, 0)
    EVT_CALL(SetNpcAnimation, NPC_BattleKammy_02, ANIM_BattleKammy_Anim02)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_BattleKooper_01) = {
    EVT_CALL(SetNpcPos, NPC_BattleKooper_01, 400, 0, -30)
    EVT_CALL(SetNpcYaw, NPC_BattleKooper_01, 270)
    EVT_CALL(SetNpcAnimation, NPC_BattleKooper_01, 0x000C001E)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Twink_01) = {
    EVT_CALL(SetNpcAnimation, NPC_Twink_01, ANIM_Twink_Idle)
    EVT_CALL(EnableNpcShadow, NPC_Twink_01, FALSE)
    EVT_CALL(SetNpcPos, NPC_Twink_01, 300, -100, 0)
    EVT_RETURN
    EVT_END
};

s32 N(D_80241E14_B08814)[] = {
    ANIM_WorldBowser_Idle,
    ANIM_WorldBowser_Walk,
    ANIM_WorldBowser_Talk,
    ANIM_WorldBowser_Shock,
    ANIM_WorldBowser_RearUpLaugh,
    ANIM_WorldBowser_Tantrum,
    ANIM_WorldBowser_Jump,
    ANIM_WorldBowser_Land,
    -1
};

s32 N(ExtraAnims_Peach)[] = {
    0x000C001D,
    ANIM_BattleKooper_StillHappy,
    ANIM_BattleKooper_StillSad,
    ANIM_BattleParakarry_Still,
    ANIM_BattleParakarry_PostDive,
    0x000C001E,
    ANIM_BattleBow_FanSmackLoop,
    ANIM_BattleBow_FanSmackOnce,
    ANIM_BattleBow_FanSmackBack,
    0x000C0026,
    ANIM_BattleBow_Laugh,
    -1
};

s32 N(ExtraAnims_Kammy)[] = {
    ANIM_BattleKammy_Anim00,
    ANIM_BattleKammy_Anim01,
    ANIM_BattleKammy_Anim04,
    ANIM_BattleKammy_Anim06,
    ANIM_BattleKammy_Anim07,
    ANIM_BattleKammy_Anim08,
    ANIM_BattleKammy_Anim02,
    ANIM_BattleKammy_Anim0C,
    ANIM_BattleKammy_Anim03,
    -1
};

s32 N(ExtraAnims_Twink)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Sad,
    ANIM_Twink_Back,
    ANIM_Twink_Talk,
    -1
};

StaticNpc N(NpcData_Bowser) = {
    .id = NPC_Bowser_01,
    .settings = &N(NpcSettings_Bowser),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .init = &N(EVS_NpcInit_Bowser_01),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = BOWSER_ANIMS,
    .extraAnimations = N(D_80241E14_B08814),
};

StaticNpc N(NpcData_Peach) = {
    .id = NPC_BattleKooper_01,
    .settings = &N(NpcSettings_Dummy),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_20000,
    .init = &N(EVS_NpcInit_BattleKooper_01),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = PEACH_ANIMS,
    .extraAnimations = N(ExtraAnims_Peach),
};

StaticNpc N(NpcData_Kammy)[] = {
    {
        .id = NPC_BattleKammy_01,
        .settings = &N(NpcSettings_Kammy_Flying),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
        .init = &N(EVS_NpcInit_BattleKammy_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_BattleKammy_Anim00,
            .walk   = ANIM_BattleKammy_Anim00,
            .run    = ANIM_BattleKammy_Anim00,
            .chase  = ANIM_BattleKammy_Anim00,
            .anim_4 = ANIM_BattleKammy_Anim00,
            .anim_5 = ANIM_BattleKammy_Anim00,
            .death  = ANIM_BattleKammy_Anim00,
            .hit    = ANIM_BattleKammy_Anim00,
            .anim_8 = ANIM_BattleKammy_Anim00,
            .anim_9 = ANIM_BattleKammy_Anim00,
            .anim_A = ANIM_BattleKammy_Anim00,
            .anim_B = ANIM_BattleKammy_Anim00,
            .anim_C = ANIM_BattleKammy_Anim00,
            .anim_D = ANIM_BattleKammy_Anim00,
            .anim_E = ANIM_BattleKammy_Anim00,
            .anim_F = ANIM_BattleKammy_Anim00,
        },
        .extraAnimations = N(ExtraAnims_Kammy),
    },
    {
        .id = NPC_BattleKammy_02,
        .settings = &N(NpcSettings_Kammy_Flying),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
        .init = &N(EVS_NpcInit_BattleKammy_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_BattleKammy_Anim00,
            .walk   = ANIM_BattleKammy_Anim00,
            .run    = ANIM_BattleKammy_Anim00,
            .chase  = ANIM_BattleKammy_Anim00,
            .anim_4 = ANIM_BattleKammy_Anim00,
            .anim_5 = ANIM_BattleKammy_Anim00,
            .death  = ANIM_BattleKammy_Anim00,
            .hit    = ANIM_BattleKammy_Anim00,
            .anim_8 = ANIM_BattleKammy_Anim00,
            .anim_9 = ANIM_BattleKammy_Anim00,
            .anim_A = ANIM_BattleKammy_Anim00,
            .anim_B = ANIM_BattleKammy_Anim00,
            .anim_C = ANIM_BattleKammy_Anim00,
            .anim_D = ANIM_BattleKammy_Anim00,
            .anim_E = ANIM_BattleKammy_Anim00,
            .anim_F = ANIM_BattleKammy_Anim00,
        },
        .extraAnimations = N(ExtraAnims_Kammy),
    },
};

StaticNpc N(NpcData_Twink) = {
    .id = NPC_Twink_01,
    .settings = &N(NpcSettings_Dummy),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .init = &N(EVS_NpcInit_Twink_01),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = TWINK_ANIMS,
    .extraAnimations = N(ExtraAnims_Twink),
};

#define NAME_SUFFIX

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Bowser_Npc1), BTL_KPA2_FORMATION_03),
    NPC_GROUP(N(NpcData_Peach_Npc1)),
    NPC_GROUP(N(NpcData_Kammy_Npc1), BTL_KKJ_FORMATION_00),
    NPC_GROUP(N(NpcData_Twink_Npc1)),
    {}
};
