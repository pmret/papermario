#include "trd_01.h"

MAP_RODATA_PAD(1, pad);

extern EvtScript N(EVS_FocusCamOnLock);

#include "world/common/enemy/complete/KoopaTroopa_Wander.inc.c"
#include "world/common/enemy/complete/Bobomb_Stationary.inc.c"

API_CALLABLE(N(SetNewWanderCenterPos)) {
    Enemy* owner1 = script->owner1.enemy;
    Npc* npc = get_npc_safe(script->owner2.npcID);

    owner1->territory->wander.centerPos.x = npc->pos.x;
    owner1->territory->wander.centerPos.y = npc->pos.y;
    owner1->territory->wander.centerPos.z = npc->pos.z;
    owner1->territory->wander.detectPos.x = npc->pos.x;
    owner1->territory->wander.detectPos.y = npc->pos.y;
    owner1->territory->wander.detectPos.z = npc->pos.z;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_KoopaTroopa_02) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_ENABLE_HIT_SCRIPT, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40, TRUE)
    EVT_CALL(GetSelfNpcID, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetNpcPos, NPC_SELF, 45, -30, 20)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, -70, -30, -20)
    EVT_END_IF
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
    EVT_LABEL(0)
    EVT_CALL(MakeLerp, EVT_FLOAT(-2.0), EVT_FLOAT(2.0), 30, EASING_COS_IN_OUT)
    EVT_LABEL(10)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH1_RAISED_SUBMERGED_STAIRS)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(UpdateLerp)
    EVT_SET(LVar5, LVar3)
    EVT_ADD(LVar5, LVar0)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar2, LVar5, LVar4)
    EVT_WAIT(1)
    EVT_IF_NE(LVar1, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(MakeLerp, EVT_FLOAT(2.0), EVT_FLOAT(-2.0), 30, EASING_COS_IN_OUT)
    EVT_LABEL(20)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH1_RAISED_SUBMERGED_STAIRS)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(UpdateLerp)
    EVT_SET(LVar5, LVar3)
    EVT_ADD(LVar5, LVar0)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar2, LVar5, LVar4)
    EVT_WAIT(1)
    EVT_IF_NE(LVar1, 0)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_GOTO(0)
    EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
    EVT_LABEL(100)
    EVT_CALL(GetSelfNpcID, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_IF_EQ(NPC_KoopaTroopa_02_DonePanic, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(100)
        EVT_END_IF
    EVT_ELSE
        EVT_IF_EQ(NPC_KoopaTroopa_03_DonePanic, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(100)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_ENABLE_HIT_SCRIPT, FALSE)
    EVT_CALL(GetSelfNpcID, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0))
        EVT_CALL(NpcMoveTo, NPC_SELF, 190, 20, 0)
        EVT_CALL(NpcMoveTo, NPC_SELF, 245, 75, 0)
    EVT_ELSE
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.6))
        EVT_CALL(NpcMoveTo, NPC_SELF, 210, -20, 0)
        EVT_CALL(NpcMoveTo, NPC_SELF, 260, 25, 0)
    EVT_END_IF
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(1.5))
    EVT_CALL(N(SetNewWanderCenterPos))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_ENABLE_HIT_SCRIPT, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40, FALSE)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_KoopaTroopa_Wander)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaTroopa_02) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_RAISED_SUBMERGED_STAIRS)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KoopaTroopa_02)))
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaTroopa_Anim0E)
    EVT_ELSE
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
        EVT_CALL(GetSelfNpcID, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, 240, 220, 130)
        EVT_ELSE
            EVT_CALL(SetNpcPos, NPC_SELF, 80, 220, 265)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_KoopaTroopa_01) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(GF_TRD01_Defeated_KoopaGuard, TRUE)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(PlaySound, SOUND_B)
            EVT_CALL(MakeItemEntity, ITEM_KOOPA_FORTRESS_KEY, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_TOSS_NEVER_VANISH, GF_TRD01_Item_FortressKey)
            EVT_EXEC(N(EVS_FocusCamOnLock))
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaTroopa_01) = {
    EVT_IF_EQ(GF_TRD01_Defeated_KoopaGuard, TRUE)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_KoopaTroopa_01)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_KoopaTroopa_01) = {
    .id = NPC_KoopaTroopa_01,
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .pos = { 260.0f, 0.0f, 30.0f },
    .yaw = 0,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_NO_DROPS,
    .init = &N(EVS_NpcInit_KoopaTroopa_01),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 260, 0, 40 },
            .wanderSize = { 30, 25 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 260, 0, 40 },
            .detectSize = { 200 },
        }
    },
    .animations = {
        .idle   = ANIM_KoopaTroopa_Anim01,
        .walk   = ANIM_KoopaTroopa_Anim03,
        .run    = ANIM_KoopaTroopa_Anim04,
        .chase  = ANIM_KoopaTroopa_Anim04,
        .anim_4 = ANIM_KoopaTroopa_Anim01,
        .anim_5 = ANIM_KoopaTroopa_Anim01,
        .death  = ANIM_KoopaTroopa_Anim0B,
        .hit    = ANIM_KoopaTroopa_Anim0B,
        .anim_8 = ANIM_KoopaTroopa_Anim07,
        .anim_9 = ANIM_KoopaTroopa_Anim06,
        .anim_A = ANIM_KoopaTroopa_Anim08,
        .anim_B = ANIM_KoopaTroopa_Anim04,
        .anim_C = ANIM_KoopaTroopa_Anim04,
        .anim_D = ANIM_KoopaTroopa_Anim04,
        .anim_E = ANIM_KoopaTroopa_Anim04,
        .anim_F = ANIM_KoopaTroopa_Anim04,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_KoopaTroopa_02) = {
    .id = NPC_KoopaTroopa_02,
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .init = &N(EVS_NpcInit_KoopaTroopa_02),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_MUSHROOM, 5, 0 },
            { ITEM_P_O_W_BLOCK, 5, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 1,
        .maxCoinBonus = 1,
    },
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 240, 220, 130 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 240, 220, 130 },
            .detectSize = { 200 },
        }
    },
    .animations = {
        .idle   = ANIM_KoopaTroopa_Anim01,
        .walk   = ANIM_KoopaTroopa_Anim03,
        .run    = ANIM_KoopaTroopa_Anim04,
        .chase  = ANIM_KoopaTroopa_Anim04,
        .anim_4 = ANIM_KoopaTroopa_Anim01,
        .anim_5 = ANIM_KoopaTroopa_Anim01,
        .death  = ANIM_KoopaTroopa_Anim0B,
        .hit    = ANIM_KoopaTroopa_Anim0B,
        .anim_8 = ANIM_KoopaTroopa_Anim07,
        .anim_9 = ANIM_KoopaTroopa_Anim06,
        .anim_A = ANIM_KoopaTroopa_Anim08,
        .anim_B = ANIM_KoopaTroopa_Anim04,
        .anim_C = ANIM_KoopaTroopa_Anim04,
        .anim_D = ANIM_KoopaTroopa_Anim04,
        .anim_E = ANIM_KoopaTroopa_Anim04,
        .anim_F = ANIM_KoopaTroopa_Anim04,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_KoopaTroopa_03) = {
    .id = NPC_KoopaTroopa_03,
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW,
    .init = &N(EVS_NpcInit_KoopaTroopa_02),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_MUSHROOM, 5, 0 },
            { ITEM_P_O_W_BLOCK, 5, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 1,
        .maxCoinBonus = 1,
    },
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 80, 220, 265 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 80, 220, 265 },
            .detectSize = { 200 },
        }
    },
    .animations = {
        .idle   = ANIM_KoopaTroopa_Anim01,
        .walk   = ANIM_KoopaTroopa_Anim03,
        .run    = ANIM_KoopaTroopa_Anim04,
        .chase  = ANIM_KoopaTroopa_Anim04,
        .anim_4 = ANIM_KoopaTroopa_Anim01,
        .anim_5 = ANIM_KoopaTroopa_Anim01,
        .death  = ANIM_KoopaTroopa_Anim0B,
        .hit    = ANIM_KoopaTroopa_Anim0B,
        .anim_8 = ANIM_KoopaTroopa_Anim07,
        .anim_9 = ANIM_KoopaTroopa_Anim06,
        .anim_A = ANIM_KoopaTroopa_Anim08,
        .anim_B = ANIM_KoopaTroopa_Anim04,
        .anim_C = ANIM_KoopaTroopa_Anim04,
        .anim_D = ANIM_KoopaTroopa_Anim04,
        .anim_E = ANIM_KoopaTroopa_Anim04,
        .anim_F = ANIM_KoopaTroopa_Anim04,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Bombomb) = {
    .id = NPC_Bobomb,
    .settings = &N(NpcSettings_Bombomb_Stationary),
    .pos = { -255.0f, 640.0f, 35.0f },
    .yaw = 180,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_HONEY_SYRUP, 5, 0 },
            { ITEM_FIRE_FLOWER, 5, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 0,
        .maxCoinBonus = 1,
    },
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -255, 640, 35 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -255, 640, 35 },
            .detectSize = { 100 },
        }
    },
    .animations = {
        .idle   = ANIM_Bobomb_Anim02,
        .walk   = ANIM_Bobomb_Anim04,
        .run    = ANIM_Bobomb_Anim06,
        .chase  = ANIM_Bobomb_Anim06,
        .anim_4 = ANIM_Bobomb_Anim02,
        .anim_5 = ANIM_Bobomb_Anim02,
        .death  = ANIM_Bobomb_Anim0E,
        .hit    = ANIM_Bobomb_Anim0E,
        .anim_8 = ANIM_Bobomb_Anim06,
        .anim_9 = ANIM_Bobomb_Anim06,
        .anim_A = ANIM_Bobomb_Anim06,
        .anim_B = ANIM_Bobomb_Anim06,
        .anim_C = ANIM_Bobomb_Anim06,
        .anim_D = ANIM_Bobomb_Anim06,
        .anim_E = ANIM_Bobomb_Anim06,
        .anim_F = ANIM_Bobomb_Anim06,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaTroopa_01), BTL_TRD_PART_1_FORMATION_03, BTL_TRD_PART_1_STAGE_02),
    NPC_GROUP(N(NpcData_KoopaTroopa_02), BTL_TRD_PART_1_FORMATION_01, BTL_TRD_PART_1_STAGE_07),
    NPC_GROUP(N(NpcData_KoopaTroopa_03), BTL_TRD_PART_1_FORMATION_00, BTL_TRD_PART_1_STAGE_07),
    NPC_GROUP(N(NpcData_Bombomb), BTL_TRD_PART_1_FORMATION_10, BTL_TRD_PART_1_STAGE_07),
    {}
};
