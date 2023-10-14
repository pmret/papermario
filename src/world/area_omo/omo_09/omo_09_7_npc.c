#include "omo_09.h"

#include "world/common/enemy/ShyGuy_Wander.inc.c"

MobileAISettings N(AISettings_ShyGuy_Wander_NoReaction) = {
    .moveSpeed = 2.0f,
    .moveTime = 60,
    .waitTime = 15,
    .alertRadius = 100.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 4,
    .chaseSpeed = 4.0f,
    .chaseTurnRate = 6,
    .chaseUpdateInterval = 1,
    .chaseRadius = 140.0f,
    .chaseOffsetDist = 30.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_ShyGuy_Wander_NoReaction) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_ShyGuy_Wander_NoReaction)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_ShyGuy_Wander_NoReaction) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_SHY_GUY,
    .ai = &N(EVS_NpcAI_ShyGuy_Wander_NoReaction),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = 0,
};

#include "world/common/enemy/ShyGuy_Patrol.inc.c"
#include "world/common/enemy/SpyGuy.inc.c"
#include "world/common/enemy/Koopatrol_Stationary.inc.c"
#include "world/common/enemy/Pokey.inc.c"
#include "world/common/enemy/Kammy_Flying.inc.c"

#include "world/common/DisableCameraLeadingPlayer.inc.c"
#include "world/common/EnableCameraLeadingPlayer.inc.c"

EvtScript N(EVS_ShyGuy_CarryItem) = {
    EVT_SET(LVarA, LVar0) // npcID
    EVT_SET(LVarB, LVar1) // itemID
    EVT_SET(LVarD, LVar2) // item type
    EVT_SET(LVarE, LVar3) // pickup flag
    EVT_CALL(SetNpcVar, LVarA, 10, 0)
    EVT_CALL(GetNpcPos, LVarA, LVar2, LVar3, LVar4)
    EVT_ADD(LVar3, 26)
    EVT_CALL(MakeItemEntity, LVarB, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(LVar9, LVar0)
    EVT_WAIT(1)
    EVT_LABEL(10)
        EVT_CALL(GetNpcPos, LVarA, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, 26)
        EVT_CALL(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, LVarA, 10, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(RemoveItemEntity, LVar9)
    EVT_SWITCH(LVarD)
        EVT_CASE_EQ(ITEM_TYPE_CONSUMABLE)
            EVT_CALL(MakeItemEntity, LVarB, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS, LVarE)
        EVT_CASE_EQ(ITEM_TYPE_KEY)
            EVT_CALL(DropItemEntity, LVarB, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, LVarE)
        EVT_CASE_EQ(ITEM_TYPE_BADGE)
            EVT_CALL(DropItemEntity, LVarB, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_FALL, LVarE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};


EvtScript N(EVS_NpcDefeat_ShyGuy_Thief) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(GF_OMO09_Defeated_MysteryNoteThief, TRUE)
            EVT_CALL(SetSelfVar, 10, 1)
            EVT_WAIT(2)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_SET(GF_OMO09_Defeated_MysteryNoteThief, TRUE)
            EVT_CALL(SetSelfVar, 10, 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Pokey) = {
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 1850)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_IF_LT(LVar1, 150)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(DisableCameraLeadingPlayer))
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(5.0), LVar0, LVar1, LVar2, 300, EVT_FLOAT(13.0), EVT_FLOAT(-9.5))
    EVT_IF_EQ(GB_OMO_PeachChoice3, 0)
        EVT_CALL(SpeakToPlayer, NPC_Pokey, ANIM_Pokey_Idle4, ANIM_Pokey_Idle4, 0, MSG_CH4_003E)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Koopatrol, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_CH4_003F)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(N(EnableCameraLeadingPlayer))
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_END_THREAD
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Pokey) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(GF_OMO09_Item_SuperSoda, TRUE)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Pokey) = {
    EVT_IF_EQ(GB_OMO_PeachChoice3, 0)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Pokey)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Pokey)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol) = {
    EVT_IF_EQ(GB_OMO_PeachChoice3, 1)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Pokey)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Pokey)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kammy) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kammy)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_ShyGuy_Jackpot) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetSelfVar, 0, 1)
                    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_ShyGuy_Wander)))
                EVT_END_IF
            EVT_CASE_EQ(2)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_WAIT(25)
                EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
                EVT_CALL(SetSelfVar, 0, 0)
                EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_SWITCH
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_ShyGuy_Jackpot) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetSelfVar, 0, 2)
            EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_ShyGuy_Jackpot)))
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy_Jackpot) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcAI_ShyGuy_Jackpot)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_ShyGuy_Jackpot)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Pokey) = {
    .id = NPC_Pokey,
    .pos = { 1900.0f, 150.0f, -30.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Pokey),
    .settings = &N(NpcSettings_Pokey),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = POKEY_ANIMS,
};

NpcData N(NpcData_Koopatrol) = {
    .id = NPC_Koopatrol,
    .pos = { 1900.0f, 150.0f, -30.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Koopatrol),
    .settings = &N(NpcSettings_Koopatrol_Stationary),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = KOOPATROL_ANIMS,
};

NpcData N(NpcData_ShyGuy_01) = {
    .id = NPC_ShyGuy_Jackpot1,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 460, 0, 50 },
            .wanderSize = { 80 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 460, 0, 50 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy_Jackpot),
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcData N(NpcData_ShyGuy_02) = {
    .id = NPC_ShyGuy_Jackpot2,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 497, 0, 50 },
            .wanderSize = { 80 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 497, 0, 50 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy_Jackpot),
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcData N(NpcData_ShyGuy_03) = {
    .id = NPC_ShyGuy_Jackpot3,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 535, 0, 50 },
            .wanderSize = { 80 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 535, 0, 50 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy_Jackpot),
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcData N(NpcData_ShyGuy_04) = {
    .id = NPC_ShyGuy_Jackpot4,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 573, 0, 50 },
            .wanderSize = { 80 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 573, 0, 50 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy_Jackpot),
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcData N(NpcData_ShyGuy_05) = {
    .id = NPC_ShyGuy_Jackpot5,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 610, 0, 50 },
            .wanderSize = { 80 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 610, 0, 50 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy_Jackpot),
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

AnimID N(ExtraAnims_Kammy)[] = {
    ANIM_WorldKammy_Anim0E,
    ANIM_WorldKammy_Anim0F,
    ANIM_WorldKammy_Anim10,
    ANIM_WorldKammy_Anim13,
    ANIM_WorldKammy_Anim15,
    ANIM_WorldKammy_Anim16,
    ANIM_LIST_END
};

NpcData N(NpcData_Kammy) = {
    .id = NPC_Kammy,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kammy),
    .settings = &N(NpcSettings_Kammy_Flying),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = KAMMY_ANIMS,
    .extraAnimations = N(ExtraAnims_Kammy),
};

EvtScript N(EVS_ShyGuy_Thief) = {
    EVT_IF_EQ(GF_OMO09_Defeated_MysteryNoteThief, TRUE)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_ShyGuy_Thief)))
    EVT_SET(LVar0, NPC_ShyGuy_Thief)
    EVT_SET(LVar1, ITEM_MYSTERY_NOTE)
    EVT_SET(LVar2, ITEM_TYPE_KEY)
    EVT_SET_CONST(LVar3, GF_OMO09_Item_MysteryNote)
    EVT_EXEC(N(EVS_ShyGuy_CarryItem))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_ShyGuy_Thief) = {
    .id = NPC_ShyGuy_Thief,
    .pos = { 155.0f, 10.0f, -96.0f },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points  = {
                { 155, 10, -96 },
                { 90, 10, -96 },
            },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 135, 10, 0 },
            .detectSize = { 105, 140 },
        }
    },
    .init = &N(EVS_ShyGuy_Thief),
    .settings = &N(NpcSettings_ShyGuy_Patrol),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SHY_GUY_DROPS,
    .animations = YELLOW_SHY_GUY_ANIMS,
    .aiFlags = ENEMY_AI_FLAG_1,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_SpyGuy)[] = {
    {
        .id = NPC_SpyGuy,
        .pos = { 850.0f, 0.0f, 0.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 850, 0, 0 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 850, 0, 0 },
                .detectSize = { 200 },
            }
        },
        .settings = &N(NpcSettings_SpyGuy),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = SPY_GUY_DROPS,
        .animations = SPY_GUY_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    SPY_GUY_ROCK_HITBOX(NPC_SpyGuy_Rock1),
    SPY_GUY_ROCK_HITBOX(NPC_SpyGuy_Rock2),
    SPY_GUY_ROCK_HITBOX(NPC_SpyGuy_Rock3),
};

NpcGroupList N(PokeyAmbushNPCs) = {
    NPC_GROUP(N(NpcData_Pokey), BTL_OMO3_FORMATION_08, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_01), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_02), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_03), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_04), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_05), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_Thief), BTL_OMO_FORMATION_09, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_SpyGuy), BTL_OMO_FORMATION_19, BTL_OMO_STAGE_00),
    {}
};

NpcGroupList N(KoopatrolAmbushNPCs) = {
    NPC_GROUP(N(NpcData_Koopatrol), BTL_OMO3_FORMATION_09, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_01), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_02), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_03), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_04), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_05), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_Thief), BTL_OMO_FORMATION_09, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_SpyGuy), BTL_OMO_FORMATION_19, BTL_OMO_STAGE_00),
    {}
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_ShyGuy_01), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_02), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_03), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_04), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_05), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_Thief), BTL_OMO_FORMATION_09, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_SpyGuy), BTL_OMO_FORMATION_19, BTL_OMO_STAGE_00),
    {}
};

NpcGroupList N(KammySceneNPCs) = {
    NPC_GROUP(N(NpcData_Kammy)),
    NPC_GROUP(N(NpcData_Pokey), BTL_OMO3_FORMATION_08, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_Koopatrol), BTL_OMO3_FORMATION_09, BTL_OMO3_STAGE_04),
    {}
};
