#include "kkj_25.h"

#define NAME_SUFFIX _Npc2

#include "world/common/npc/Bowser.inc.c"
#include "world/common/npc/Dummy.inc.c"
#include "world/common/enemy/Kammy_Flying.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

#include "world/common/npc/Peach.h"
#include "world/common/npc/Twink.h"

EvtScript N(EVS_NpcIdle_Bowser) = {
    EVT_LABEL(0)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Bowser_02, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -75)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 1000)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(StartBossBattle, SONG_FINAL_BOWSER_BATTLE)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/UnkFunc1.inc.c"

EvtScript N(EVS_NpcDefeat_Bowser) = {
    EVT_CALL(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_2, TRUE)
    EVT_CALL(N(UnkFunc1))
    EVT_SET(GF_KKJ25_Defeated_Bowser, TRUE)
    // reload the map in the 'final' configuration
    EVT_CALL(GotoMap, EVT_PTR("kkj_25"), kkj_25_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(FlyingKammyHoverOffsets)[] = {
    1, 2, 3, 2, 1, -1, -2, -3, -2, -1, 
};

EvtScript N(EVS_NpcAux_Kammy_Broom) = {
    EVT_LABEL(0)
        EVT_USE_BUF(EVT_PTR(N(FlyingKammyHoverOffsets)))
        EVT_LOOP(10)
            EVT_BUF_READ1(LVar1)
            EVT_CALL(GetNpcPos, NPC_Kammy_03, LVar2, LVar3, LVar4)
            EVT_ADD(LVar3, LVar1)
            EVT_CALL(SetNpcPos, NPC_Kammy_03, LVar2, LVar3, LVar4)
            EVT_WAIT(3)
        EVT_END_LOOP
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Peach) = {
    EVT_CALL(SetNpcPos, NPC_Peach_01, 475, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_Peach_01, ANIM_Peach_A0001)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bowser) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Bowser)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Bowser)))
    EVT_CALL(SetNpcScale, NPC_Bowser_02, EVT_FLOAT(1.5), EVT_FLOAT(1.5), EVT_FLOAT(1.5))
    EVT_CALL(SetNpcPos, NPC_Bowser_02, 200, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_02, ANIM_WorldBowser_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kammy_Broom) = {
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Kammy_Broom)))
    EVT_CALL(SetNpcPos, NPC_Kammy_03, 540, 10, -50)
    EVT_CALL(SetNpcAnimation, NPC_Kammy_03, ANIM_BattleKammy_Anim0C)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kammy) = {
    EVT_CALL(SetNpcPos, NPC_Kammy_04, 550, 0, -40)
    EVT_CALL(SetNpcAnimation, NPC_Kammy_04, ANIM_BattleKammy_Anim03)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Twink) = {
    EVT_CALL(InterpNpcYaw, NPC_Peach_01, 270, 0)
    EVT_CALL(SetNpcPos, NPC_Twink_01, 510, 30, 0)
    EVT_CALL(InterpNpcYaw, NPC_Twink_01, 270, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Eldstar) = {
    EVT_CALL(func_802CFD30, 8, 7, 0, 0, 0, 0)
    EVT_CALL(EnableNpcShadow, NPC_Eldstar, FALSE)
    EVT_CALL(SetNpcPos, NPC_Eldstar, 100, 45, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Mamar) = {
    EVT_CALL(func_802CFD30, 9, 7, 0, 0, 0, 0)
    EVT_CALL(EnableNpcShadow, NPC_Mamar, FALSE)
    EVT_CALL(SetNpcPos, NPC_Mamar, 46, 45, -27)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Skolar) = {
    EVT_CALL(func_802CFD30, 10, 7, 0, 0, 0, 0)
    EVT_CALL(EnableNpcShadow, NPC_Skolar, FALSE)
    EVT_CALL(SetNpcPos, NPC_Skolar, 33, 45, -95)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Muskular) = {
    EVT_CALL(func_802CFD30, 11, 7, 0, 0, 0, 0)
    EVT_CALL(EnableNpcShadow, NPC_Muskular, FALSE)
    EVT_CALL(SetNpcPos, NPC_Muskular, 71, 45, -132)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Misstar) = {
    EVT_CALL(func_802CFD30, 12, 7, 0, 0, 0, 0)
    EVT_CALL(EnableNpcShadow, NPC_Misstar, FALSE)
    EVT_CALL(SetNpcPos, NPC_Misstar, 131, 45, -132)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Klevar) = {
    EVT_CALL(func_802CFD30, 13, 7, 0, 0, 0, 0)
    EVT_CALL(EnableNpcShadow, NPC_Klevar, FALSE)
    EVT_CALL(SetNpcPos, NPC_Klevar, 169, 45, -95)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kalmar) = {
    EVT_CALL(func_802CFD30, 14, 7, 0, 0, 0, 0)
    EVT_CALL(EnableNpcShadow, NPC_Kalmar, FALSE)
    EVT_CALL(SetNpcPos, NPC_Kalmar, 156, 45, -27)
    EVT_RETURN
    EVT_END
};

s32 N(ExtraAnims_Bowser)[] = {
    ANIM_WorldBowser_Idle,
    ANIM_WorldBowser_Walk,
    ANIM_WorldBowser_Talk,
    ANIM_WorldBowser_Shock,
    ANIM_WorldBowser_RearUpLaugh,
    -1
};

s32 N(ExtraAnims_Peach)[] = {
    ANIM_Peach_A0001,
    ANIM_Peach_A0002,
    ANIM_Peach_C0000,
    ANIM_Peach_C0006,
    ANIM_Peach_C001E,
    ANIM_Peach_D0009,
    ANIM_Peach_C0026,
    ANIM_Peach_D000F,
    -1
};

s32 N(ExtraAnims_Kammy)[] = {
    ANIM_BattleKammy_Anim04,
    ANIM_BattleKammy_Anim06,
    ANIM_BattleKammy_Anim0C,
    ANIM_BattleKammy_Anim03,
    -1
};

s32 N(ExtraAnims_Twink)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Talk,
    -1
};

s32 N(ExtraAnims_Eldstar)[] = {
    ANIM_WorldEldstar_Idle,
    ANIM_WorldEldstar_Wave,
    -1
};

s32 N(ExtraAnims_Mamar)[] = {
    ANIM_WorldMamar_Idle,
    -1
};

s32 N(ExtraAnims_Skolar)[] = {
    ANIM_WorldSkolar_Idle,
    -1
};

s32 N(ExtraAnims_Muskular)[] = {
    ANIM_WorldMuskular_Idle,
    -1
};

s32 N(ExtraAnims_Misstar)[] = {
    ANIM_WorldMisstar_Idle,
    -1
};

s32 N(ExtraAnims_Klevar)[] = {
    ANIM_WorldKlevar_Idle,
    -1
};

s32 N(ExtraAnims_Kalmar)[] = {
    ANIM_WorldKalmar_Idle,
    -1
};

StaticNpc N(NpcData_Bowser) = {
    .id = NPC_Bowser_02,
    .settings = &N(NpcSettings_Bowser),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .init = &N(EVS_NpcInit_Bowser),
    .drops = NO_DROPS,
    .animations = BOWSER_ANIMS,
    .extraAnimations = N(ExtraAnims_Bowser),
};

StaticNpc N(NpcData_Peach) = {
    .id = NPC_Peach_01,
    .settings = &N(NpcSettings_Dummy),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_20000,
    .init = &N(EVS_NpcInit_Peach),
    .drops = NO_DROPS,
    .animations = PEACH_ANIMS,
    .extraAnimations = N(ExtraAnims_Peach),
};

StaticNpc N(NpcData_Kammy)[] = {
    {
        .id = NPC_Kammy_03,
        .settings = &N(NpcSettings_Kammy_Flying),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
        .init = &N(EVS_NpcInit_Kammy_Broom),
        .drops = NO_DROPS,
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
        .id = NPC_Kammy_04,
        .settings = &N(NpcSettings_Kammy_Flying),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Kammy),
        .drops = NO_DROPS,
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
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Twink),
    .drops = NO_DROPS,
    .animations = TWINK_ANIMS,
    .extraAnimations = N(ExtraAnims_Twink),
};

StaticNpc N(NpcData_Eldstar) = {
    .id = NPC_Eldstar,
    .settings = &N(NpcSettings_StarSpirit),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Eldstar),
    .drops = NO_DROPS,
    .animations = ELDSTAR_ANIMS,
    .extraAnimations = N(ExtraAnims_Eldstar),
};

StaticNpc N(NpcData_Mamar) = {
    .id = NPC_Mamar,
    .settings = &N(NpcSettings_StarSpirit),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Mamar),
    .drops = NO_DROPS,
    .animations = MAMAR_ANIMS,
    .extraAnimations = N(ExtraAnims_Mamar),
};

StaticNpc N(NpcData_Skolar) = {
    .id = NPC_Skolar,
    .settings = &N(NpcSettings_StarSpirit),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Skolar),
    .drops = NO_DROPS,
    .animations = SKOLAR_ANIMS,
    .extraAnimations = N(ExtraAnims_Skolar),
};

StaticNpc N(NpcData_Muskular) = {
    .id = NPC_Muskular,
    .settings = &N(NpcSettings_StarSpirit),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Muskular),
    .drops = NO_DROPS,
    .animations = MUSKULAR_ANIMS,
    .extraAnimations = N(ExtraAnims_Muskular),
};

StaticNpc N(NpcData_Misstar) = {
    .id = NPC_Misstar,
    .settings = &N(NpcSettings_StarSpirit),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Misstar),
    .drops = NO_DROPS,
    .animations = MISSTAR_ANIMS,
    .extraAnimations = N(ExtraAnims_Misstar),
};

StaticNpc N(NpcData_Klevar) = {
    .id = NPC_Klevar,
    .settings = &N(NpcSettings_StarSpirit),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Klevar),
    .drops = NO_DROPS,
    .animations = KLEVAR_ANIMS,
    .extraAnimations = N(ExtraAnims_Klevar),
};

StaticNpc N(NpcData_Kalmar) = {
    .id = NPC_Kalmar,
    .settings = &N(NpcSettings_StarSpirit),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Kalmar),
    .drops = NO_DROPS,
    .animations = KALMAR_ANIMS,
    .extraAnimations = N(ExtraAnims_Kalmar),
};

#define NAME_SUFFIX

NpcGroupList N(MidpointNpcs) = {
    NPC_GROUP(N(NpcData_Bowser_Npc2), BTL_KPA2_FORMATION_04),
    NPC_GROUP(N(NpcData_Peach_Npc2)),
    NPC_GROUP(N(NpcData_Kammy_Npc2), BTL_KKJ_FORMATION_00),
    NPC_GROUP(N(NpcData_Twink_Npc2)),
    NPC_GROUP(N(NpcData_Eldstar_Npc2)),
    NPC_GROUP(N(NpcData_Mamar_Npc2)),
    NPC_GROUP(N(NpcData_Skolar_Npc2)),
    NPC_GROUP(N(NpcData_Muskular_Npc2)),
    NPC_GROUP(N(NpcData_Misstar_Npc2)),
    NPC_GROUP(N(NpcData_Klevar_Npc2)),
    NPC_GROUP(N(NpcData_Kalmar_Npc2)),
    {}
};
