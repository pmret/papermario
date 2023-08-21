#include "trd_01.h"

MAP_RODATA_PAD(1, pad);

extern EvtScript N(EVS_FocusCamOnLock);

#include "world/common/enemy/KoopaTroopa_Wander.inc.c"
#include "world/common/enemy/Bobomb_Guard.inc.c"

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
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
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
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, FALSE)
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
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_KoopaTroopa_Wander)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaTroopa_02) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_RAISED_SUBMERGED_STAIRS)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KoopaTroopa_02)))
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaTroopa_Floating)
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
            EVT_CALL(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
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

NpcData N(NpcData_KoopaTroopa_01) = {
    .id = NPC_KoopaTroopa_01,
    .pos = { 260.0f, 0.0f, 30.0f },
    .yaw = 0,
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
    .init = &N(EVS_NpcInit_KoopaTroopa_01),
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_KoopaTroopa_02) = {
    .id = NPC_KoopaTroopa_02,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
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
    .init = &N(EVS_NpcInit_KoopaTroopa_02),
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = KOOPA_TROOPA_TRD_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_KoopaTroopa_03) = {
    .id = NPC_KoopaTroopa_03,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 90,
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
    .init = &N(EVS_NpcInit_KoopaTroopa_02),
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = KOOPA_TROOPA_TRD_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Bobomb) = {
    .id = NPC_Bobomb,
    .pos = { -255.0f, 640.0f, 35.0f },
    .yaw = 180,
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
    .settings = &N(NpcSettings_Bobomb_Guard),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = BOBOMB_DROPS,
    .animations = BOBOMB_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaTroopa_01), BTL_TRD_1_FORMATION_03, BTL_TRD_1_STAGE_02),
    NPC_GROUP(N(NpcData_KoopaTroopa_02), BTL_TRD_1_FORMATION_01, BTL_TRD_1_STAGE_07),
    NPC_GROUP(N(NpcData_KoopaTroopa_03), BTL_TRD_1_FORMATION_00, BTL_TRD_1_STAGE_07),
    NPC_GROUP(N(NpcData_Bobomb), BTL_TRD_1_FORMATION_10, BTL_TRD_1_STAGE_07),
    {}
};
