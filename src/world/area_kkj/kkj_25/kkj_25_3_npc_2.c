#include "kkj_25.h"

#define NAME_SUFFIX _Npc2

NpcSettings N(NpcSettings_Bowser_02) = {
    .height = 75,
    .radius = 72,
    .level = 99,
};

NpcSettings N(NpcSettings_BattleKooper_01) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_BattleKammy_03) = {
    .height = 34,
    .radius = 24,
    .level = 26,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_Eldstar) = {
    .height = 26,
    .radius = 24,
    .level = 99,
};

s32 N(missing_80242940_2940)[] = {
    0x00000000, 0x00140014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x00160018, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 
};

EvtScript N(EVS_NpcIdle_Bowser_02) = {
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

EvtScript N(EVS_NpcDefeat_Bowser_02) = {
    EVT_CALL(SetEncounterStatusFlags, 2, TRUE)
    EVT_CALL(N(UnkFunc1))
    EVT_SET(GF_KKJ25_Defeated_Bowser, TRUE)
    EVT_CALL(GotoMap, EVT_PTR("kkj_25"), kkj_25_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(D_80242B64_B09564)[] = {
    1, 2, 3, 2, 1, -1, -2, -3, 
    -2, -1, 
};

EvtScript N(EVS_NpcAux_BattleKammy_03) = {
    EVT_LABEL(0)
    EVT_USE_BUF(EVT_PTR(N(D_80242B64_B09564)))
    EVT_LOOP(10)
        EVT_BUF_READ1(LVar1)
        EVT_CALL(GetNpcPos, NPC_BattleKammy_03, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, LVar1)
        EVT_CALL(SetNpcPos, NPC_BattleKammy_03, LVar2, LVar3, LVar4)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_BattleKooper_01) = {
    EVT_CALL(SetNpcPos, NPC_BattleKooper_01, 475, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_BattleKooper_01, ANIM_BattleKooper_StillHappy)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bowser_02) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Bowser_02)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Bowser_02)))
    EVT_CALL(SetNpcScale, NPC_Bowser_02, EVT_FLOAT(1.5), EVT_FLOAT(1.5), EVT_FLOAT(1.5))
    EVT_CALL(SetNpcPos, NPC_Bowser_02, 200, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_02, ANIM_WorldBowser_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_BattleKammy_03) = {
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_BattleKammy_03)))
    EVT_CALL(SetNpcPos, NPC_BattleKammy_03, 540, 10, -50)
    EVT_CALL(SetNpcAnimation, NPC_BattleKammy_03, ANIM_BattleKammy_Anim0C)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_BattleKammy_04) = {
    EVT_CALL(SetNpcPos, NPC_BattleKammy_04, 550, 0, -40)
    EVT_CALL(SetNpcAnimation, NPC_BattleKammy_04, ANIM_BattleKammy_Anim03)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Twink_01) = {
    EVT_CALL(InterpNpcYaw, NPC_BattleKooper_01, 270, 0)
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

s32 N(D_802430A4_B09AA4)[] = {
    ANIM_WorldBowser_Idle,
    ANIM_WorldBowser_Walk,
    ANIM_WorldBowser_Talk,
    ANIM_WorldBowser_Shock,
    ANIM_WorldBowser_RearUpLaugh,
    -1
};

s32 N(D_802430BC_B09ABC)[] = {
    ANIM_BattleKooper_StillHappy,
    ANIM_BattleKooper_StillSad,
    ANIM_BattleParakarry_Still,
    ANIM_BattleParakarry_PostDive,
    0x000C001E,
    ANIM_BattleBow_FanSmackLoop,
    0x000C0026,
    ANIM_BattleBow_Laugh,
    -1
};

s32 N(D_802430E0_B09AE0)[] = {
    ANIM_BattleKammy_Anim04,
    ANIM_BattleKammy_Anim06,
    ANIM_BattleKammy_Anim0C,
    ANIM_BattleKammy_Anim03,
    -1
};

s32 N(D_802430F4_B09AF4)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Talk,
    -1
};

s32 N(D_80243100_B09B00)[] = {
    ANIM_WorldEldstar_Idle,
    ANIM_WorldEldstar_Wave,
    -1
};

s32 N(D_8024310C_B09B0C)[] = {
    ANIM_WorldMamar_Idle,
    -1
};

s32 N(D_80243114_B09B14)[] = {
    ANIM_WorldSkolar_Idle,
    -1
};

s32 N(D_8024311C_B09B1C)[] = {
    ANIM_WorldMuskular_Idle,
    -1
};

s32 N(D_80243124_B09B24)[] = {
    ANIM_WorldMisstar_Idle,
    -1
};

s32 N(D_8024312C_B09B2C)[] = {
    ANIM_WorldKlevar_Idle,
    -1
};

s32 N(D_80243134_B09B34)[] = {
    ANIM_WorldKalmar_Idle,
    -1
};

StaticNpc N(NpcData_Bowser) = {
    .id = NPC_Bowser_02,
    .settings = &N(NpcSettings_Bowser_02),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .init = &N(EVS_NpcInit_Bowser_02),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_WorldBowser_Idle,
        .walk   = ANIM_WorldBowser_Idle,
        .run    = ANIM_WorldBowser_Idle,
        .chase  = ANIM_WorldBowser_Idle,
        .anim_4 = ANIM_WorldBowser_Idle,
        .anim_5 = ANIM_WorldBowser_Idle,
        .death  = ANIM_WorldBowser_Idle,
        .hit    = ANIM_WorldBowser_Idle,
        .anim_8 = ANIM_WorldBowser_Idle,
        .anim_9 = ANIM_WorldBowser_Idle,
        .anim_A = ANIM_WorldBowser_Idle,
        .anim_B = ANIM_WorldBowser_Idle,
        .anim_C = ANIM_WorldBowser_Idle,
        .anim_D = ANIM_WorldBowser_Idle,
        .anim_E = ANIM_WorldBowser_Idle,
        .anim_F = ANIM_WorldBowser_Idle,
    },
    .extraAnimations = N(D_802430A4_B09AA4),
};

StaticNpc N(NpcData_Kooper) = {
    .id = NPC_BattleKooper_01,
    .settings = &N(NpcSettings_BattleKooper_01),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_20000,
    .init = &N(EVS_NpcInit_BattleKooper_01),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_BattleKooper_Still,
        .walk   = ANIM_BattleKooper_Still,
        .run    = ANIM_BattleKooper_Still,
        .chase  = ANIM_BattleKooper_Still,
        .anim_4 = ANIM_BattleKooper_Still,
        .anim_5 = ANIM_BattleKooper_Still,
        .death  = ANIM_BattleKooper_Still,
        .hit    = ANIM_BattleKooper_Still,
        .anim_8 = ANIM_BattleKooper_Still,
        .anim_9 = ANIM_BattleKooper_Still,
        .anim_A = ANIM_BattleKooper_Still,
        .anim_B = ANIM_BattleKooper_Still,
        .anim_C = ANIM_BattleKooper_Still,
        .anim_D = ANIM_BattleKooper_Still,
        .anim_E = ANIM_BattleKooper_Still,
        .anim_F = ANIM_BattleKooper_Still,
    },
    .extraAnimations = N(D_802430BC_B09ABC),
};

StaticNpc N(NpcData_Kammy)[] = {
    {
        .id = NPC_BattleKammy_03,
        .settings = &N(NpcSettings_BattleKammy_03),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
        .init = &N(EVS_NpcInit_BattleKammy_03),
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
        .extraAnimations = N(D_802430E0_B09AE0),
    },
    {
        .id = NPC_BattleKammy_04,
        .settings = &N(NpcSettings_BattleKammy_03),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_BattleKammy_04),
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
        .extraAnimations = N(D_802430E0_B09AE0),
    },
};

StaticNpc N(NpcData_Twink) = {
    .id = NPC_Twink_01,
    .settings = &N(NpcSettings_BattleKooper_01),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Twink_01),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Twink_Idle,
        .walk   = ANIM_Twink_Fly,
        .run    = ANIM_Twink_Angry,
        .chase  = ANIM_Twink_Angry,
        .anim_4 = ANIM_Twink_Idle,
        .anim_5 = ANIM_Twink_Idle,
        .death  = ANIM_Twink_Idle,
        .hit    = ANIM_Twink_Idle,
        .anim_8 = ANIM_Twink_Idle,
        .anim_9 = ANIM_Twink_Idle,
        .anim_A = ANIM_Twink_Idle,
        .anim_B = ANIM_Twink_Idle,
        .anim_C = ANIM_Twink_Idle,
        .anim_D = ANIM_Twink_Idle,
        .anim_E = ANIM_Twink_Idle,
        .anim_F = ANIM_Twink_Idle,
    },
    .extraAnimations = N(D_802430F4_B09AF4),
};

StaticNpc N(NpcData_Eldstar) = {
    .id = NPC_Eldstar,
    .settings = &N(NpcSettings_Eldstar),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Eldstar),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_WorldEldstar_Idle,
        .walk   = ANIM_WorldEldstar_Idle,
        .run    = ANIM_WorldEldstar_Idle,
        .chase  = ANIM_WorldEldstar_Idle,
        .anim_4 = ANIM_WorldEldstar_Idle,
        .anim_5 = ANIM_WorldEldstar_Idle,
        .death  = ANIM_WorldEldstar_Idle,
        .hit    = ANIM_WorldEldstar_Idle,
        .anim_8 = ANIM_WorldEldstar_Still,
        .anim_9 = ANIM_WorldEldstar_Idle,
        .anim_A = ANIM_WorldEldstar_Idle,
        .anim_B = ANIM_WorldEldstar_Idle,
        .anim_C = ANIM_WorldEldstar_Idle,
        .anim_D = ANIM_WorldEldstar_Idle,
        .anim_E = ANIM_WorldEldstar_Idle,
        .anim_F = ANIM_WorldEldstar_Idle,
    },
    .extraAnimations = N(D_80243100_B09B00),
};

StaticNpc N(NpcData_Mamar) = {
    .id = NPC_Mamar,
    .settings = &N(NpcSettings_Eldstar),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Mamar),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_WorldMamar_Idle,
        .walk   = ANIM_WorldMamar_Idle,
        .run    = ANIM_WorldMamar_Idle,
        .chase  = ANIM_WorldMamar_Idle,
        .anim_4 = ANIM_WorldMamar_Idle,
        .anim_5 = ANIM_WorldMamar_Idle,
        .death  = ANIM_WorldMamar_Idle,
        .hit    = ANIM_WorldMamar_Idle,
        .anim_8 = ANIM_WorldMamar_Still,
        .anim_9 = ANIM_WorldMamar_Idle,
        .anim_A = ANIM_WorldMamar_Idle,
        .anim_B = ANIM_WorldMamar_Idle,
        .anim_C = ANIM_WorldMamar_Idle,
        .anim_D = ANIM_WorldMamar_Idle,
        .anim_E = ANIM_WorldMamar_Idle,
        .anim_F = ANIM_WorldMamar_Idle,
    },
    .extraAnimations = N(D_8024310C_B09B0C),
};

StaticNpc N(NpcData_Skolar) = {
    .id = NPC_Skolar,
    .settings = &N(NpcSettings_Eldstar),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Skolar),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_WorldSkolar_Idle,
        .walk   = ANIM_WorldSkolar_Idle,
        .run    = ANIM_WorldSkolar_Idle,
        .chase  = ANIM_WorldSkolar_Idle,
        .anim_4 = ANIM_WorldSkolar_Idle,
        .anim_5 = ANIM_WorldSkolar_Idle,
        .death  = ANIM_WorldSkolar_Idle,
        .hit    = ANIM_WorldSkolar_Idle,
        .anim_8 = ANIM_WorldSkolar_Still,
        .anim_9 = ANIM_WorldSkolar_Idle,
        .anim_A = ANIM_WorldSkolar_Idle,
        .anim_B = ANIM_WorldSkolar_Idle,
        .anim_C = ANIM_WorldSkolar_Idle,
        .anim_D = ANIM_WorldSkolar_Idle,
        .anim_E = ANIM_WorldSkolar_Idle,
        .anim_F = ANIM_WorldSkolar_Idle,
    },
    .extraAnimations = N(D_80243114_B09B14),
};

StaticNpc N(NpcData_Muskular) = {
    .id = NPC_Muskular,
    .settings = &N(NpcSettings_Eldstar),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Muskular),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_WorldMuskular_Idle,
        .walk   = ANIM_WorldMuskular_Idle,
        .run    = ANIM_WorldMuskular_Idle,
        .chase  = ANIM_WorldMuskular_Idle,
        .anim_4 = ANIM_WorldMuskular_Idle,
        .anim_5 = ANIM_WorldMuskular_Idle,
        .death  = ANIM_WorldMuskular_Idle,
        .hit    = ANIM_WorldMuskular_Idle,
        .anim_8 = ANIM_WorldMuskular_Still,
        .anim_9 = ANIM_WorldMuskular_Idle,
        .anim_A = ANIM_WorldMuskular_Idle,
        .anim_B = ANIM_WorldMuskular_Idle,
        .anim_C = ANIM_WorldMuskular_Idle,
        .anim_D = ANIM_WorldMuskular_Idle,
        .anim_E = ANIM_WorldMuskular_Idle,
        .anim_F = ANIM_WorldMuskular_Idle,
    },
    .extraAnimations = N(D_8024311C_B09B1C),
};

StaticNpc N(NpcData_Misstar) = {
    .id = NPC_Misstar,
    .settings = &N(NpcSettings_Eldstar),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Misstar),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_WorldMisstar_Idle,
        .walk   = ANIM_WorldMisstar_Idle,
        .run    = ANIM_WorldMisstar_Idle,
        .chase  = ANIM_WorldMisstar_Idle,
        .anim_4 = ANIM_WorldMisstar_Idle,
        .anim_5 = ANIM_WorldMisstar_Idle,
        .death  = ANIM_WorldMisstar_Idle,
        .hit    = ANIM_WorldMisstar_Idle,
        .anim_8 = ANIM_WorldMisstar_Still,
        .anim_9 = ANIM_WorldMisstar_Idle,
        .anim_A = ANIM_WorldMisstar_Idle,
        .anim_B = ANIM_WorldMisstar_Idle,
        .anim_C = ANIM_WorldMisstar_Idle,
        .anim_D = ANIM_WorldMisstar_Idle,
        .anim_E = ANIM_WorldMisstar_Idle,
        .anim_F = ANIM_WorldMisstar_Idle,
    },
    .extraAnimations = N(D_80243124_B09B24),
};

StaticNpc N(NpcData_Klevar) = {
    .id = NPC_Klevar,
    .settings = &N(NpcSettings_Eldstar),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Klevar),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_WorldKlevar_Idle,
        .walk   = ANIM_WorldKlevar_Idle,
        .run    = ANIM_WorldKlevar_Idle,
        .chase  = ANIM_WorldKlevar_Idle,
        .anim_4 = ANIM_WorldKlevar_Idle,
        .anim_5 = ANIM_WorldKlevar_Idle,
        .death  = ANIM_WorldKlevar_Idle,
        .hit    = ANIM_WorldKlevar_Idle,
        .anim_8 = ANIM_WorldKlevar_Still,
        .anim_9 = ANIM_WorldKlevar_Idle,
        .anim_A = ANIM_WorldKlevar_Idle,
        .anim_B = ANIM_WorldKlevar_Idle,
        .anim_C = ANIM_WorldKlevar_Idle,
        .anim_D = ANIM_WorldKlevar_Idle,
        .anim_E = ANIM_WorldKlevar_Idle,
        .anim_F = ANIM_WorldKlevar_Idle,
    },
    .extraAnimations = N(D_8024312C_B09B2C),
};

StaticNpc N(NpcData_Kalmar) = {
    .id = NPC_Kalmar,
    .settings = &N(NpcSettings_Eldstar),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Kalmar),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_WorldKalmar_Idle,
        .walk   = ANIM_WorldKalmar_Idle,
        .run    = ANIM_WorldKalmar_Idle,
        .chase  = ANIM_WorldKalmar_Idle,
        .anim_4 = ANIM_WorldKalmar_Idle,
        .anim_5 = ANIM_WorldKalmar_Idle,
        .death  = ANIM_WorldKalmar_Idle,
        .hit    = ANIM_WorldKalmar_Idle,
        .anim_8 = ANIM_WorldKalmar_Still,
        .anim_9 = ANIM_WorldKalmar_Idle,
        .anim_A = ANIM_WorldKalmar_Idle,
        .anim_B = ANIM_WorldKalmar_Idle,
        .anim_C = ANIM_WorldKalmar_Idle,
        .anim_D = ANIM_WorldKalmar_Idle,
        .anim_E = ANIM_WorldKalmar_Idle,
        .anim_F = ANIM_WorldKalmar_Idle,
    },
    .extraAnimations = N(D_80243134_B09B34),
};

#define NAME_SUFFIX

NpcGroupList N(NpcGroup1) = {
    NPC_GROUP(N(NpcData_Bowser_Npc2), BTL_KPA2_FORMATION_04),
    NPC_GROUP(N(NpcData_Kooper_Npc2)),
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
