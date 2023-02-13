#include "kkj_25.h"

#define NAME_SUFFIX _Npc3

NpcSettings N(NpcSettings_Bowser_03) = {
    .height = 75,
    .radius = 72,
    .level = 99,
};

NpcSettings N(NpcSettings_BattleKooper_02) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_BattleKammy_05) = {
    .height = 34,
    .radius = 24,
    .level = 26,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(EVS_NpcAuxAI_StarRod) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_StarRod) = {
    .height = 24,
    .radius = 24,
    .level = 99,
    .otherAI = &N(EVS_NpcAuxAI_StarRod),
};

s32 N(D_802449D0_B0B3D0)[] = {
    1, 2, 3, 2, 1, -1, -2, -3, 
    -2, -1, 
};

EvtScript N(EVS_NpcAux_BattleKammy_05) = {
    EVT_LABEL(0)
    EVT_USE_BUF(EVT_PTR(N(D_802449D0_B0B3D0)))
    EVT_LOOP(10)
        EVT_BUF_READ1(LVar1)
        EVT_CALL(GetNpcPos, NPC_BattleKammy_05, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, LVar1)
        EVT_CALL(SetNpcPos, NPC_BattleKammy_05, LVar2, LVar3, LVar4)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StarRod) = {
    EVT_CALL(SetNpcPos, NPC_StarRod, 270, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bowser_03) = {
    EVT_CALL(SetNpcAnimation, NPC_Bowser_03, ANIM_WorldBowser_DefeatedIdle)
    EVT_CALL(SetNpcPos, NPC_Bowser_03, 300, 0, 50)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_BattleKooper_02) = {
    EVT_CALL(SetNpcCollisionSize, NPC_BattleKooper_02, 48, 24)
    EVT_CALL(SetNpcPos, NPC_BattleKooper_02, 400, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_BattleKooper_02, ANIM_BattleKooper_StillHappy)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_BattleKammy_05) = {
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_BattleKammy_05)))
    EVT_CALL(SetNpcPos, NPC_BattleKammy_05, 525, 10, 0)
    EVT_CALL(SetNpcAnimation, NPC_BattleKammy_05, ANIM_BattleKammy_Anim04)
    EVT_CALL(InterpNpcYaw, NPC_BattleKammy_05, 270, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Twink_02) = {
    EVT_CALL(SetNpcPos, NPC_Twink_02, 430, 30, 0)
    EVT_RETURN
    EVT_END
};

s32 N(D_80244BFC_B0B5FC)[] = {
    ANIM_WorldBowser_Idle,
    ANIM_WorldBowser_Walk,
    ANIM_WorldBowser_Talk,
    ANIM_WorldBowser_Shock,
    ANIM_WorldBowser_DefeatedIdle,
    -1
};

s32 N(D_80244C14_B0B614)[] = {
    ANIM_BattleKooper_StillHappy,
    ANIM_BattleKooper_StillSad,
    ANIM_BattleParakarry_Still,
    ANIM_BattleParakarry_PostDive,
    -1
};

s32 N(D_80244C28_B0B628)[] = {
    ANIM_BattleKammy_Anim04,
    ANIM_BattleKammy_Anim06,
    -1
};

s32 N(D_80244C34_B0B634)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Talk,
    ANIM_Twink_Cringe,
    -1
};

StaticNpc N(NpcData_Bowser) = {
    .id = NPC_Bowser_03,
    .settings = &N(NpcSettings_Bowser_03),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .init = &N(EVS_NpcInit_Bowser_03),
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
    .extraAnimations = N(D_80244BFC_B0B5FC),
};

StaticNpc N(NpcData_Kooper) = {
    .id = NPC_BattleKooper_02,
    .settings = &N(NpcSettings_BattleKooper_02),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_20000 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .init = &N(EVS_NpcInit_BattleKooper_02),
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
    .extraAnimations = N(D_80244C14_B0B614),
};

StaticNpc N(NpcData_Kammy) = {
    .id = NPC_BattleKammy_05,
    .settings = &N(NpcSettings_BattleKammy_05),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .init = &N(EVS_NpcInit_BattleKammy_05),
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
    .extraAnimations = N(D_80244C28_B0B628),
};

StaticNpc N(NpcData_Twink) = {
    .id = NPC_Twink_02,
    .settings = &N(NpcSettings_BattleKooper_02),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Twink_02),
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
    .extraAnimations = N(D_80244C34_B0B634),
};

StaticNpc N(NpcData_StarRod) = {
    .id = NPC_StarRod,
    .settings = &N(NpcSettings_StarRod),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_StarRod),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_StarRod_Still,
        .walk   = ANIM_StarRod_Still,
        .run    = ANIM_StarRod_Still,
        .chase  = ANIM_StarRod_Still,
        .anim_4 = ANIM_StarRod_Still,
        .anim_5 = ANIM_StarRod_Still,
        .death  = ANIM_StarRod_Still,
        .hit    = ANIM_StarRod_Still,
        .anim_8 = ANIM_StarRod_Still,
        .anim_9 = ANIM_StarRod_Still,
        .anim_A = ANIM_StarRod_Still,
        .anim_B = ANIM_StarRod_Still,
        .anim_C = ANIM_StarRod_Still,
        .anim_D = ANIM_StarRod_Still,
        .anim_E = ANIM_StarRod_Still,
        .anim_F = ANIM_StarRod_Still,
    },
};

#define NAME_SUFFIX

NpcGroupList N(NpcGroup2) = {
    NPC_GROUP(N(NpcData_Bowser_Npc3), BTL_KPA2_FORMATION_03),
    NPC_GROUP(N(NpcData_Kooper_Npc3)),
    NPC_GROUP(N(NpcData_Kammy_Npc3), BTL_KKJ_FORMATION_00),
    NPC_GROUP(N(NpcData_Twink_Npc3)),
    NPC_GROUP(N(NpcData_StarRod_Npc3)),
    {}
};
