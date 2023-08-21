#include "omo_01.h"

#include "world/common/enemy/ShyGuy_AvoidPlayer.inc.c"

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
        EVT_SUB(LVar4, 1)
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

EvtScript N(EVS_NpcDefeat_ShyGuy) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(GF_OMO09_Defeated_CalculatorThief, TRUE)
            EVT_CALL(SetSelfVar, 10, 1)
            EVT_WAIT(2)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(OnPlayerFled, 0)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_CALL(SetSelfVar, 10, 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy) = {
    EVT_IF_EQ(GF_OMO09_Defeated_CalculatorThief, TRUE)
        EVT_IF_EQ(GF_OMO01_Item_Calculator, FALSE)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_ShyGuy)))
    EVT_SET(LVar0, NPC_ShyGuy_01)
    EVT_IF_EQ(GF_OMO01_Item_Calculator, FALSE)
        EVT_SET(LVar1, ITEM_CALCULATOR)
        EVT_SET(LVar2, ITEM_TYPE_KEY)
        EVT_SET_CONST(LVar3, GF_OMO01_Item_Calculator)
    EVT_ELSE
        EVT_SET(LVar1, ITEM_MAPLE_SYRUP)
        EVT_SET(LVar2, ITEM_TYPE_CONSUMABLE)
        EVT_SET(LVar3, 0)
    EVT_END_IF
    EVT_EXEC(N(EVS_ShyGuy_CarryItem))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_ShyGuy_01) = {
    .id = NPC_ShyGuy_01,
    .pos = { -165.0f, 0.0f, -50.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -165, 0, -50 },
            .wanderSize = { 40 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -165, 0, -50 },
            .detectSize = { 300 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy),
    .settings = &N(NpcSettings_ShyGuy_AvoidPlayer),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SHY_GUY_DROPS,
    .animations = RED_AVOID_SHY_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

EvtScript N(EVS_NpcInit_ShyGuy_02) = {
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_ShyGuy)))
    EVT_SET(LVar0, NPC_ShyGuy_02)
    EVT_SET(LVar1, ITEM_CAKE_MIX)
    EVT_SET(LVar2, ITEM_TYPE_CONSUMABLE)
    EVT_SET(LVar3, 0)
    EVT_EXEC(N(EVS_ShyGuy_CarryItem))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_ShyGuy_02) = {
    .id = NPC_ShyGuy_02,
    .pos = { -25.0f, 0.0f, -160.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -25, 0, -160 },
            .wanderSize = { 40 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -25, 0, -160 },
            .detectSize = { 300 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy_02),
    .settings = &N(NpcSettings_ShyGuy_AvoidPlayer),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SHY_GUY_DROPS,
    .animations = YELLOW_AVOID_SHY_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

EvtScript N(EVS_NpcInit_ShyGuy_03) = {
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_ShyGuy)))
    EVT_SET(LVar0, NPC_ShyGuy_03)
    EVT_SET(LVar1, ITEM_CAKE_MIX)
    EVT_SET(LVar2, ITEM_TYPE_CONSUMABLE)
    EVT_SET(LVar3, 0)
    EVT_EXEC(N(EVS_ShyGuy_CarryItem))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_ShyGuy_03) = {
    .id = NPC_ShyGuy_03,
    .pos = { -60.0f, 0.0f, 390.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -60, 0, 390 },
            .wanderSize = { 40 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -60, 0, 390 },
            .detectSize = { 300 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy_03),
    .settings = &N(NpcSettings_ShyGuy_AvoidPlayer),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SHY_GUY_DROPS,
    .animations = YELLOW_AVOID_SHY_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

EvtScript N(EVS_NpcInit_ShyGuy_04) = {
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_ShyGuy)))
    EVT_SET(LVar0, NPC_ShyGuy_04)
    EVT_SET(LVar1, ITEM_MUSHROOM)
    EVT_SET(LVar2, ITEM_TYPE_CONSUMABLE)
    EVT_SET(LVar3, 0)
    EVT_EXEC(N(EVS_ShyGuy_CarryItem))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_ShyGuy_04) = {
    .id = NPC_ShyGuy_04,
    .pos = { 50.0f, 0.0f, 230.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 50, 0, 230 },
            .wanderSize = { 40 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 50, 0, 230 },
            .detectSize = { 300 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy_04),
    .settings = &N(NpcSettings_ShyGuy_AvoidPlayer),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SHY_GUY_DROPS,
    .animations = BLUE_AVOID_SHY_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

EvtScript N(EVS_NpcInit_ShyGuy_05) = {
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_ShyGuy)))
    EVT_SET(LVar0, NPC_ShyGuy_05)
    EVT_SET(LVar1, ITEM_FIRE_FLOWER)
    EVT_SET(LVar2, ITEM_TYPE_CONSUMABLE)
    EVT_SET(LVar3, 0)
    EVT_EXEC(N(EVS_ShyGuy_CarryItem))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_ShyGuy_05) = {
    .id = NPC_ShyGuy_05,
    .pos = { 340.0f, 0.0f, 120.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 340, 0, 120 },
            .wanderSize = { 40 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 340, 0, 120 },
            .detectSize = { 300 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy_05),
    .settings = &N(NpcSettings_ShyGuy_AvoidPlayer),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SHY_GUY_DROPS,
    .animations = GREEN_AVOID_SHY_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_ShyGuy_01), BTL_OMO_FORMATION_00, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_ShyGuy_02), BTL_OMO_FORMATION_02, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_ShyGuy_03), BTL_OMO_FORMATION_02, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_ShyGuy_04), BTL_OMO_FORMATION_01, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_ShyGuy_05), BTL_OMO_FORMATION_05, BTL_OMO_STAGE_00),
    {}
};
