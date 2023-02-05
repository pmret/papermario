#include "omo_09.h"

#include "world/common/enemy/complete/ShyGuy_Wander.inc.c"

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
    .level = 14,
    .ai = &N(EVS_NpcAI_ShyGuy_Wander_NoReaction),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = 0,
};

#include "world/common/enemy/complete/ShyGuy_Patrol.inc.c"
#include "world/common/enemy/complete/SpyGuy.inc.c"
#include "world/common/enemy/complete/Koopatrol_Stationary.inc.c"
#include "world/common/enemy/complete/Pokey.inc.c"
#include "world/common/enemy/complete/Kammy.inc.c"

#include "world/common/todo/SetCamera0Flag1000.inc.c"
#include "world/common/todo/UnsetCamera0Flag1000.inc.c"

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
    EVT_CALL(N(SetCamera0Flag1000))
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(5.0), LVar0, LVar1, LVar2, 300, EVT_FLOAT(13.0), EVT_FLOAT(-9.5))
    EVT_IF_EQ(GB_OMO_PeachChoice3, 0)
        EVT_CALL(SpeakToPlayer, NPC_Pokey, ANIM_Pokey_Anim04, ANIM_Pokey_Anim04, 0, MSG_CH4_003E)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Koopatrol, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_CH4_003F)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(N(UnsetCamera0Flag1000))
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
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2, FALSE)
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

StaticNpc N(NpcData_Pokey) = {
    .id = NPC_Pokey,
    .settings = &N(NpcSettings_Pokey),
    .pos = { 1900.0f, 150.0f, -30.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_400000,
    .init = &N(EVS_NpcInit_Pokey),
    .drops = NPC_NO_DROPS,
    .animations = POKEY_ANIMS,
};

StaticNpc N(NpcData_Koopatrol) = {
    .id = NPC_Koopatrol,
    .settings = &N(NpcSettings_Koopatrol_Stationary),
    .pos = { 1900.0f, 150.0f, -30.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_400000,
    .init = &N(EVS_NpcInit_Koopatrol),
    .drops = NPC_NO_DROPS,
    .animations = KOOPATROL_ANIMS,
};

StaticNpc N(NpcData_ShyGuy_01) = {
    .id = NPC_ShyGuy_Jackpot1,
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_200000,
    .init = &N(EVS_NpcInit_ShyGuy_Jackpot),
    .drops = NPC_NO_DROPS,
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
    .animations = RED_SHY_GUY_ANIMS,
};

StaticNpc N(NpcData_ShyGuy_02) = {
    .id = NPC_ShyGuy_Jackpot2,
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_200000,
    .init = &N(EVS_NpcInit_ShyGuy_Jackpot),
    .drops = NPC_NO_DROPS,
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
    .animations = RED_SHY_GUY_ANIMS,
};

StaticNpc N(NpcData_ShyGuy_03) = {
    .id = NPC_ShyGuy_Jackpot3,
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_200000,
    .init = &N(EVS_NpcInit_ShyGuy_Jackpot),
    .drops = NPC_NO_DROPS,
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
    .animations = RED_SHY_GUY_ANIMS,
};

StaticNpc N(NpcData_ShyGuy_04) = {
    .id = NPC_ShyGuy_Jackpot4,
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_200000,
    .init = &N(EVS_NpcInit_ShyGuy_Jackpot),
    .drops = NPC_NO_DROPS,
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
    .animations = RED_SHY_GUY_ANIMS,
};

StaticNpc N(NpcData_ShyGuy_05) = {
    .id = NPC_ShyGuy_Jackpot5,
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_200000,
    .init = &N(EVS_NpcInit_ShyGuy_Jackpot),
    .drops = NPC_NO_DROPS,
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
    .animations = RED_SHY_GUY_ANIMS,
};

s32 N(ExtraAnims_Kammy)[] = {
    ANIM_WorldKammy_Anim0E,
    ANIM_WorldKammy_Anim0F,
    ANIM_WorldKammy_Anim10,
    ANIM_WorldKammy_Anim13,
    ANIM_WorldKammy_Anim15,
    ANIM_WorldKammy_Anim16,
    -1
};

StaticNpc N(NpcData_Kammy) = {
    .id = NPC_Kammy,
    .settings = &N(NpcSettings_Kammy),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Kammy),
    .drops = NPC_NO_DROPS,
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

StaticNpc N(NpcData_ShyGuy_Thief) = {
    .id = NPC_ShyGuy_Thief,
    .settings = &N(NpcSettings_ShyGuy_Patrol),
    .pos = { 155.0f, 10.0f, -96.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_ShyGuy_Thief),
    .drops = SHY_GUY_DROPS,
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
    .animations = YELLOW_SHY_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
    .aiFlags = ENEMY_AI_FLAG_1,
};

StaticNpc N(NpcData_SpyGuy)[] = {
    {
        .id = NPC_SpyGuy,
        .settings = &N(NpcSettings_SpyGuy),
        .pos = { 850.0f, 0.0f, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .drops = SPY_GUY_DROPS,
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
