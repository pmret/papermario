#include "kzn_17.h"

#include "world/common/enemy/PiranhaPlantAI.inc.c"
#include "world/common/enemy/TackleAI.inc.c"

#include "world/common/AwaitPlayerNearNpc.inc.c"

extern EvtScript D_800936DC;

NpcSettings N(NpcSettings_Kolorado) = {
    .height = 40,
    .radius = 24,
    .level = 99,
};

EvtScript N(EVS_NpcDefeat_PiranhaHitbox) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_CALL(func_80045900, 1)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAGS_10, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

MobileAISettings N(AISettings_Piranha) = {
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 150.0f,
    .playerSearchInterval = 1,
};

EvtScript N(EVS_NpcAI_Piranha) = {
    EVT_CALL(SetSelfVar, 7, 1)
    EVT_CALL(SetSelfVar, 8, 10)
    EVT_CALL(SetSelfVar, 9, 9)
    EVT_CALL(SetSelfVar, 10, 12)
    EVT_CALL(SetSelfVar, 11, 7)
    EVT_CALL(SetSelfVar, 12, 30)
    EVT_CALL(SetSelfVar, 13, 15)
    EVT_CALL(SetSelfVar, 14, 18)
    EVT_CALL(SetSelfVar, 15, 15)
    EVT_CALL(N(PiranhaPlantAI_Main), EVT_PTR(N(AISettings_Piranha)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Piranha) = {
    .height = 50,
    .radius = 36,
    .level = 17,
    .ai = &N(EVS_NpcAI_Piranha),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(EVS_NpcAI_PiranhaHitbox) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetSelfVar, 0, 14)
    EVT_CALL(SetSelfVar, 1, 28)
    EVT_CALL(SetSelfVar, 4, 3)
    EVT_CALL(SetSelfVar, 15, SOUND_20DE)
    EVT_CALL(N(MeleeHitbox_Main))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80243C38) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_NONE)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_CALL(GetSelfAnimationFromTable, 7, LVar0)
            EVT_EXEC_WAIT(D_800936DC)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_PiranhaHitbox) = {
    .height = 20,
    .radius = 28,
    .level = 17,
    .ai = &N(EVS_NpcAI_PiranhaHitbox),
    .onDefeat = &N(EVS_NpcDefeat_PiranhaHitbox),
};

MobileAISettings N(AISettings_Unused1) = {
    .moveSpeed = 1.0f,
    .moveTime = 60,
    .waitTime = 60,
    .alertRadius = 90.0f,
    .alertOffsetDist = 40.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 4.5f,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 40.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Unused1) = {
    EVT_CALL(SetSelfVar, 2, 5)
    EVT_CALL(SetSelfVar, 3, 2)
    EVT_CALL(SetSelfVar, 5, 5)
    EVT_CALL(SetSelfVar, 7, 2)
    EVT_CALL(N(TackleAI_Main), EVT_PTR(N(AISettings_Unused1)))
    EVT_RETURN
    EVT_END
};

MobileAISettings N(AISettings_SpikeTop) = {
    .moveSpeed = 1.0f,
    .moveTime = 60,
    .waitTime = 60,
    .alertRadius = 90.0f,
    .alertOffsetDist = 40.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 7.0f,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 40.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_SpikeTop) = {
    EVT_CALL(SetSelfVar, 2, 4)
    EVT_CALL(SetSelfVar, 3, 10)
    EVT_CALL(SetSelfVar, 5, 4)
    EVT_CALL(SetSelfVar, 7, 3)
    EVT_CALL(N(TackleAI_Main), EVT_PTR(N(AISettings_SpikeTop)))
    EVT_RETURN
    EVT_END
};

MobileAISettings N(AISettings_Unused3) = {
    .moveSpeed = 1.0f,
    .moveTime = 20,
    .waitTime = 5,
    .alertRadius = 120.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 6.0f,
    .chaseRadius = 150.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Unused3) = {
    EVT_CALL(SetSelfVar, 2, 3)
    EVT_CALL(SetSelfVar, 3, 8)
    EVT_CALL(SetSelfVar, 5, 6)
    EVT_CALL(SetSelfVar, 7, 6)
    EVT_CALL(N(TackleAI_Main), EVT_PTR(N(AISettings_Unused3)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Unused2) = {
    EVT_CALL(N(func_80240814_97BE44))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_BuzzyBeetle_Anim0F)
    EVT_CALL(N(AwaitPlayerNearNpc))
    EVT_CALL(SelfEnemyOverrideSyncPos, 1)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_BuzzyBeetle_Anim00)
    EVT_CALL(N(func_802408B4_97BEE4))
    EVT_CALL(SelfEnemyOverrideSyncPos, 0)
    EVT_CALL(SetSelfVar, 2, 5)
    EVT_CALL(SetSelfVar, 3, 2)
    EVT_CALL(SetSelfVar, 5, 5)
    EVT_CALL(SetSelfVar, 7, 2)
    EVT_CALL(N(TackleAI_Main), EVT_PTR(N(AISettings_Unused1)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Unused1) = {
    .height = 20,
    .radius = 22,
    .level = 10,
    .ai = &N(EVS_NpcAI_Unused1),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_Unused2) = {
    .height = 20,
    .radius = 22,
    .level = 10,
    .ai = &N(EVS_NpcAI_Unused2),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_SpikeTop) = {
    .height = 20,
    .radius = 22,
    .level = 17,
    .ai = &N(EVS_NpcAI_SpikeTop),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_Unused3) = {
    .height = 24,
    .radius = 24,
    .level = 25,
    .ai = &N(EVS_NpcAI_Unused3),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#include "world/common/atomic/LetterChoice.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER25,
    ITEM_NONE 
};

EvtScript N(EVS_Kolorado_LetterDelivery1) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
        ITEM_LETTER25, 0,
        MSG_CH5_00E4, MSG_CH5_00E5, MSG_CH5_00E6, MSG_CH5_00E7,
        EVT_PTR(N(LetterList)))
    EVT_EXEC_WAIT(N(DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Kolorado_LetterDelivery2) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
        ITEM_LETTER25, 0,
        MSG_CH5_00E8, MSG_CH5_00E9, MSG_CH5_00EA, MSG_CH5_00EB,
        EVT_PTR(N(LetterList)))
    EVT_EXEC_WAIT(N(DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Kolorado_LetterReward) = {
    EVT_IF_EQ(LVarC, 2)
        EVT_SET(LVar0, ITEM_STAR_PIECE)
        EVT_SET(LVar1, 3)
        EVT_EXEC_WAIT(N(Delivery_ShowGotStarPiece))
        EVT_CALL(AddStarPieces, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

Vec3f N(D_80244A8C_C8A53C)[] = {
    {  447.0,     0.0,   39.0 },
    {  432.0,     5.0,   47.0 },
    {  427.0,    20.0,   55.0 },
    {  432.0,     5.0,   62.0 },
    {  447.0,     0.0,   70.0 },
};

EvtScript N(D_80244AC8_C8A578) = {
    EVT_CALL(SetNpcPos, NPC_Kolorado, 447, 0, 39)
    EVT_CALL(SetNpcYaw, NPC_Kolorado, 270)
    EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Panic)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244B1C_C8A5CC) = {
    EVT_CALL(SetEnemyFlagBits, NPC_Kolorado, ENEMY_FLAGS_400000, 1)
    EVT_CALL(func_802CDE68, 0, 13)
    EVT_CALL(SetNpcRotation, NPC_Kolorado, 0, 0, 250)
    EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_HurtStill)
    EVT_CALL(func_802CFD30, 0, 4, EVT_FLOAT(3.0), EVT_FLOAT(3.0), 0, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_Kolorado, SOUND_HIT_PLAYER_NORMAL, 0)
    EVT_THREAD
        EVT_CALL(SetNpcCollisionSize, NPC_Kolorado, 20, 24)
        EVT_CALL(LoadPath, 30, EVT_PTR(N(D_80244A8C_C8A53C)), ARRAY_COUNT(N(D_80244A8C_C8A53C)), EASING_LINEAR)
        EVT_LABEL(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Kolorado, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_HurtStill, ANIM_Kolorado_HurtStill, 5, MSG_CH5_00F9)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Kolorado_HurtInit) = {
    EVT_CALL(SetNpcPos, NPC_Kolorado, 447, 0, 70)
    EVT_CALL(SetNpcYaw, NPC_Kolorado, 270)
    EVT_CALL(SetEnemyFlagBits, NPC_Kolorado, ENEMY_FLAGS_400000, 1)
    EVT_CALL(func_802CDE68, 0, 13)
    EVT_CALL(SetNpcRotation, NPC_Kolorado, 0, 0, 250)
    EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_HurtStill)
    EVT_CALL(func_802CFD30, 0, 4, EVT_FLOAT(3.0), EVT_FLOAT(3.0), 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Kolorado) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, 605)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_00F7, 160, 40)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcPos, NPC_SELF, 290, 0, 30)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    EVT_CALL(NpcMoveTo, NPC_SELF, 640, 80, 0)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Yell)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_00F8)
    EVT_SET(GB_StoryProgress, STORY_CH5_KOLORADO_AT_DEAD_END)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_HIDDEN_PASSAGE_OPEN)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_00FC)
        EVT_EXEC_WAIT(N(EVS_Kolorado_LetterDelivery1))
        EVT_EXEC_WAIT(N(EVS_Kolorado_LetterReward))
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_HurtStill, 5, MSG_CH5_00FA)
        EVT_EXEC_WAIT(N(EVS_Kolorado_LetterDelivery2))
        EVT_EXEC_WAIT(N(EVS_Kolorado_LetterReward))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_KOLORADO_AT_DEAD_END)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kolorado)))
            EVT_RETURN
        EVT_CASE_LT(STORY_CH5_HIDDEN_PASSAGE_OPEN)
            EVT_CALL(SetNpcPos, NPC_SELF, 640, 0, 80)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Yell)
            EVT_RETURN
        EVT_CASE_EQ(STORY_CH5_HIDDEN_PASSAGE_OPEN)
            EVT_CALL(SetNpcCollisionSize, NPC_Kolorado, 20, 24)
            EVT_EXEC(N(EVS_Kolorado_HurtInit))
            EVT_RETURN
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .settings = &N(NpcSettings_Kolorado),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_DIRTY_SHADOW | NPC_FLAG_MOTION_BLUR | NPC_FLAG_400000,
    .init = &N(EVS_NpcInit_Kolorado),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Kolorado_Idle,
        .walk   = ANIM_Kolorado_Walk,
        .run    = ANIM_Kolorado_Run,
        .chase  = ANIM_Kolorado_Run,
        .anim_4 = ANIM_Kolorado_Idle,
        .anim_5 = ANIM_Kolorado_Idle,
        .death  = ANIM_Kolorado_Idle,
        .hit    = ANIM_Kolorado_Idle,
        .anim_8 = ANIM_Kolorado_Idle,
        .anim_9 = ANIM_Kolorado_Idle,
        .anim_A = ANIM_Kolorado_Idle,
        .anim_B = ANIM_Kolorado_Idle,
        .anim_C = ANIM_Kolorado_Idle,
        .anim_D = ANIM_Kolorado_Idle,
        .anim_E = ANIM_Kolorado_Idle,
        .anim_F = ANIM_Kolorado_Idle,
    },
    .tattle = MSG_NpcTattle_Kolorado,
};

StaticNpc N(NpcData_Piranha)[] = {
    {
        .id = NPC_Piranha,
        .settings = &N(NpcSettings_Piranha),
        .pos = { -325.0f, 0.0f, 150.0f },
        .yaw = 270,
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_SUPER_SHROOM, 10, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 3,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -325, 0, 150 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { -390, 0, 130 },
                .detectSize = { 270, 130 },
            }
        },
        .animations = {
            .idle   = ANIM_LargePiranha_Putrid_Anim01,
            .walk   = ANIM_LargePiranha_Putrid_Anim02,
            .run    = ANIM_LargePiranha_Putrid_Anim03,
            .chase  = ANIM_LargePiranha_Putrid_Anim03,
            .anim_4 = ANIM_LargePiranha_Putrid_Anim01,
            .anim_5 = ANIM_LargePiranha_Putrid_Anim01,
            .death  = ANIM_LargePiranha_Putrid_Anim0E,
            .hit    = ANIM_LargePiranha_Putrid_Anim0E,
            .anim_8 = ANIM_LargePiranha_Putrid_Anim18,
            .anim_9 = ANIM_LargePiranha_Putrid_Anim17,
            .anim_A = ANIM_LargePiranha_Putrid_Anim05,
            .anim_B = ANIM_LargePiranha_Putrid_Anim06,
            .anim_C = ANIM_LargePiranha_Putrid_Anim07,
            .anim_D = ANIM_LargePiranha_Putrid_Anim01,
            .anim_E = ANIM_LargePiranha_Putrid_Anim01,
            .anim_F = ANIM_LargePiranha_Putrid_Anim01,
        },
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_Piranha_Hitbox,
        .settings = &N(NpcSettings_PiranhaHitbox),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_LargePiranha_Putrid_Anim01,
            .walk   = ANIM_LargePiranha_Putrid_Anim02,
            .run    = ANIM_LargePiranha_Putrid_Anim03,
            .chase  = ANIM_LargePiranha_Putrid_Anim03,
            .anim_4 = ANIM_LargePiranha_Putrid_Anim01,
            .anim_5 = ANIM_LargePiranha_Putrid_Anim01,
            .death  = ANIM_LargePiranha_Putrid_Anim0E,
            .hit    = ANIM_LargePiranha_Putrid_Anim0E,
            .anim_8 = ANIM_LargePiranha_Putrid_Anim18,
            .anim_9 = ANIM_LargePiranha_Putrid_Anim17,
            .anim_A = ANIM_LargePiranha_Putrid_Anim05,
            .anim_B = ANIM_LargePiranha_Putrid_Anim06,
            .anim_C = ANIM_LargePiranha_Putrid_Anim07,
            .anim_D = ANIM_LargePiranha_Putrid_Anim01,
            .anim_E = ANIM_LargePiranha_Putrid_Anim01,
            .anim_F = ANIM_LargePiranha_Putrid_Anim01,
        },
    },
};

StaticNpc N(NpcData_SpikeTop) = {
    .id = NPC_SpikeTop,
    .settings = &N(NpcSettings_SpikeTop),
    .pos = { -450.0f, 0.0f, 100.0f },
    .yaw = 270,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_SUPER_SODA, 10, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(4),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 2,
        .maxCoinBonus = 3,
    },
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -450, 0, 100 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { -450, 0, 100 },
            .detectSize = { 270, 130 },
        }
    },
    .animations = {
        .idle   = ANIM_SpikeTop_Anim03,
        .walk   = ANIM_SpikeTop_Anim06,
        .run    = ANIM_SpikeTop_Anim08,
        .chase  = ANIM_SpikeTop_Anim08,
        .anim_4 = ANIM_SpikeTop_Anim03,
        .anim_5 = ANIM_SpikeTop_Anim03,
        .death  = ANIM_SpikeTop_Anim13,
        .hit    = ANIM_SpikeTop_Anim13,
        .anim_8 = ANIM_SpikeTop_Anim0B,
        .anim_9 = ANIM_SpikeTop_Anim0A,
        .anim_A = ANIM_SpikeTop_Anim0C,
        .anim_B = ANIM_SpikeTop_Anim03,
        .anim_C = ANIM_SpikeTop_Anim03,
        .anim_D = ANIM_SpikeTop_Anim03,
        .anim_E = ANIM_SpikeTop_Anim03,
        .anim_F = ANIM_SpikeTop_Anim03,
    },
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_Piranha), BTL_KZN_FORMATION_14, BTL_KZN_STAGE_00),
    NPC_GROUP(N(NpcData_SpikeTop), BTL_KZN_FORMATION_0D, BTL_KZN_STAGE_00),
    {}
};
