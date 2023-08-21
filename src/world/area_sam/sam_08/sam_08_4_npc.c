#include "sam_08.h"

NpcSettings N(NpcSettings_Kooper) = {
    .height = 35,
    .radius = 24,
    .level = ACTOR_LEVEL_KOOPA_TROOPA,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_Duplighost) = {
    .height = 30,
    .radius = 45,
    .level = ACTOR_LEVEL_NONE,
};

#define INCLUDE_FROST_CLUBBA_WANDER
#include "world/common/enemy/FrostClubba_Multi.inc.c"

EvtScript N(EVS_NpcInteract_TrueKooperA) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH7_012B)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_TrueKooperB) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_EXEC_WAIT(N(EVS_Scene_HitTrueKooper))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_FakeKooperA) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH7_012A)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_FakeKooperB) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_EXEC_WAIT(N(EVS_Scene_HitFakeKooper))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Duplighost) = {
    EVT_LABEL(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Duplighost) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetNpcFlagBits, NPC_Duplighost, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_CALL(SetNpcSpeed, NPC_Duplighost, EVT_FLOAT(3.0 / DT))
            EVT_CALL(SetNpcJumpscale, NPC_Duplighost, EVT_FLOAT(1.5))
            EVT_CALL(SetNpcAnimation, NPC_Duplighost, ANIM_Duplighost_Anim04)
            EVT_CALL(GetNpcPos, NPC_Duplighost, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 50)
            EVT_CALL(PlaySoundAtNpc, NPC_Duplighost, SOUND_DUPLIGHOST_STEP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_Duplighost, LVar0, LVar1, LVar2, 13 * DT)
            EVT_CALL(InterpPlayerYaw, 90, 0)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
            EVT_ADD(LVar0, 50)
            EVT_CALL(PlaySoundAtNpc, NPC_Duplighost, SOUND_DUPLIGHOST_STEP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_Duplighost, LVar0, LVar1, LVar2, 13 * DT)
            EVT_ADD(LVar0, 50)
            EVT_CALL(PlaySoundAtNpc, NPC_Duplighost, SOUND_DUPLIGHOST_STEP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_Duplighost, LVar0, LVar1, LVar2, 13 * DT)
            EVT_SET(GB_StoryProgress, STORY_CH7_DEFEATED_FIRST_DUPLIGHOST)
            EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_CHANGE_PARTNER | PS_FLAG_NO_PARTNER_USAGE, FALSE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o47, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_ADD(LVar0, 50)
            EVT_CALL(PlaySoundAtNpc, NPC_Duplighost, SOUND_DUPLIGHOST_STEP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_Duplighost, LVar0, LVar1, LVar2, 20 * DT)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TrueKooperA) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_TrueKooperA)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_FIRST_DUPLIGHOST)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_RealKooperA) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_FakeKooperA)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_FIRST_DUPLIGHOST)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Duplighost) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Duplighost)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Duplighost)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_FIRST_DUPLIGHOST)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Ambush)[] = {
    {
        .id = NPC_Kooper_01A,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_TrueKooperA),
        .settings = &N(NpcSettings_Kooper),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldKooper_Idle,
            .walk   = ANIM_WorldKooper_Walk,
            .run    = ANIM_WorldKooper_Walk,
            .chase  = ANIM_WorldKooper_Walk,
            .anim_4 = ANIM_WorldKooper_Walk,
            .anim_5 = ANIM_WorldKooper_Walk,
            .death  = ANIM_WorldKooper_Still,
            .hit    = ANIM_WorldKooper_Still,
            .anim_8 = ANIM_WorldKooper_Still,
            .anim_9 = ANIM_WorldKooper_Still,
            .anim_A = ANIM_WorldKooper_Still,
            .anim_B = ANIM_WorldKooper_Still,
            .anim_C = ANIM_WorldKooper_Still,
            .anim_D = ANIM_WorldKooper_Still,
            .anim_E = ANIM_WorldKooper_Still,
            .anim_F = ANIM_WorldKooper_Still,
        },
    },
    {
        .id = NPC_Kooper_02A,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_RealKooperA),
        .settings = &N(NpcSettings_Kooper),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldKooper_Idle,
            .walk   = ANIM_WorldKooper_Walk,
            .run    = ANIM_WorldKooper_Walk,
            .chase  = ANIM_WorldKooper_Walk,
            .anim_4 = ANIM_WorldKooper_Walk,
            .anim_5 = ANIM_WorldKooper_Walk,
            .death  = ANIM_WorldKooper_Still,
            .hit    = ANIM_WorldKooper_Still,
            .anim_8 = ANIM_WorldKooper_Still,
            .anim_9 = ANIM_WorldKooper_Still,
            .anim_A = ANIM_WorldKooper_Still,
            .anim_B = ANIM_WorldKooper_Still,
            .anim_C = ANIM_WorldKooper_Still,
            .anim_D = ANIM_WorldKooper_Still,
            .anim_E = ANIM_WorldKooper_Still,
            .anim_F = ANIM_WorldKooper_Still,
        },
    },
    {
        .id = NPC_Duplighost,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Duplighost),
        .settings = &N(NpcSettings_Duplighost),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Duplighost_Anim02,
            .walk   = ANIM_Duplighost_Anim03,
            .run    = ANIM_Duplighost_Anim04,
            .chase  = ANIM_Duplighost_Anim04,
            .anim_4 = ANIM_Duplighost_Anim02,
            .anim_5 = ANIM_Duplighost_Anim02,
            .death  = ANIM_Duplighost_Anim0A,
            .hit    = ANIM_Duplighost_Anim0A,
            .anim_8 = ANIM_Duplighost_Anim02,
            .anim_9 = ANIM_Duplighost_Anim02,
            .anim_A = ANIM_Duplighost_Anim02,
            .anim_B = ANIM_Duplighost_Anim02,
            .anim_C = ANIM_Duplighost_Anim02,
            .anim_D = ANIM_Duplighost_Anim02,
            .anim_E = ANIM_Duplighost_Anim02,
            .anim_F = ANIM_Duplighost_Anim02,
        },
    },
};

EvtScript N(EVS_NpcIdle_TrueKooperB) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Kooper_01A, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TrueKooperB) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_PASSIVE, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TrueKooperB)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_TrueKooperB)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_FIRST_DUPLIGHOST)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_FakeKooperB) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Kooper_02A, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_FakeKooperB) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_PASSIVE, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_FakeKooperB)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_FakeKooperB)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_FIRST_DUPLIGHOST)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Hittable)[] = {
    {
        .id = NPC_Kooper_01B,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_TrueKooperB),
        .settings = &N(NpcSettings_Kooper),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldKooper_Idle,
            .walk   = ANIM_WorldKooper_Walk,
            .run    = ANIM_WorldKooper_Walk,
            .chase  = ANIM_WorldKooper_Walk,
            .anim_4 = ANIM_WorldKooper_Walk,
            .anim_5 = ANIM_WorldKooper_Walk,
            .death  = ANIM_WorldKooper_Still,
            .hit    = ANIM_WorldKooper_Still,
            .anim_8 = ANIM_WorldKooper_Still,
            .anim_9 = ANIM_WorldKooper_Still,
            .anim_A = ANIM_WorldKooper_Still,
            .anim_B = ANIM_WorldKooper_Still,
            .anim_C = ANIM_WorldKooper_Still,
            .anim_D = ANIM_WorldKooper_Still,
            .anim_E = ANIM_WorldKooper_Still,
            .anim_F = ANIM_WorldKooper_Still,
        },
    },
    {
        .id = NPC_Kooper_02B,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_FakeKooperB),
        .settings = &N(NpcSettings_Kooper),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldKooper_Idle,
            .walk   = ANIM_WorldKooper_Walk,
            .run    = ANIM_WorldKooper_Walk,
            .chase  = ANIM_WorldKooper_Walk,
            .anim_4 = ANIM_WorldKooper_Walk,
            .anim_5 = ANIM_WorldKooper_Walk,
            .death  = ANIM_WorldKooper_Still,
            .hit    = ANIM_WorldKooper_Still,
            .anim_8 = ANIM_WorldKooper_Still,
            .anim_9 = ANIM_WorldKooper_Still,
            .anim_A = ANIM_WorldKooper_Still,
            .anim_B = ANIM_WorldKooper_Still,
            .anim_C = ANIM_WorldKooper_Still,
            .anim_D = ANIM_WorldKooper_Still,
            .anim_E = ANIM_WorldKooper_Still,
            .anim_F = ANIM_WorldKooper_Still,
        },
    },
};

NpcData N(NpcData_FrostClubba)[] = {
    {
        .id = NPC_Clubba_01,
        .pos = { -450.0f, 0.0f, -90.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -450, 0, -90 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -450, 0, -90 },
                .detectSize = { 200 },
            }
        },
        .settings = &N(NpcSettings_FrostClubba_Wander),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = FROST_CLUBBA_DROPS,
        .animations = FROST_CLUBBA_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    FROST_CLUBBA_MACE_HITBOX(NPC_Clubba_02),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Ambush), BTL_SAM_FORMATION_00, BTL_SAM_STAGE_04),
    NPC_GROUP(N(NpcData_Hittable), BTL_SAM_FORMATION_00, BTL_SAM_STAGE_04),
    NPC_GROUP(N(NpcData_FrostClubba), BTL_SAM_FORMATION_0B, BTL_SAM_STAGE_04),
    {}
};
