#include "trd_04.h"

extern EvtScript N(EVS_DropSwitch);

#include "world/common/enemy/KoopaTroopa_Wander.inc.c"
#include "world/common/enemy/KoopaTroopa_Patrol.inc.c"
#include "world/common/enemy/Paratroopa.inc.c"

EvtScript N(EVS_NpcDefeat_KoopaTroopa) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(GB_StoryProgress, STORY_CH1_DEFEATED_BASEMENT_GUARD)
            EVT_THREAD
                EVT_CALL(DoNpcDefeat)
            EVT_END_THREAD
            EVT_EXEC_WAIT(N(EVS_DropSwitch))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaTroopa) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_DEFEATED_BASEMENT_GUARD)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_KoopaTroopa)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_KoopaTroopa_Wander) = {
    .id = NPC_KoopaTroopa,
    .pos = { 0.0f, 0.0f, 125.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 125 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 125 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = KOOPA_TROOPA_TRD_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_KoopaTroopa_Patrol) = {
    .id = NPC_KoopaTroopa,
    .pos = { 220.0f, 0.0f, 30.0f },
    .yaw = 90,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points  = {
                { 220, 0, 30 },
                { 240, 0, 160 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 220, 0, 30 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_KoopaTroopa),
    .settings = &N(NpcSettings_KoopaTroopa_Patrol),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_ParaTroopa) = {
    .id = NPC_ParaTroopa,
    .pos = { -5.0f, 237.0f, 157.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -5, 237, 157 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -5, 237, 157 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_ParaTroopa),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = PARATROOPA_DROPS,
    .animations = PARATROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(NpcGroupAfter) = {
    NPC_GROUP(N(NpcData_KoopaTroopa_Wander), BTL_TRD_1_FORMATION_05, BTL_TRD_1_STAGE_0C),
    NPC_GROUP(N(NpcData_ParaTroopa), BTL_TRD_1_FORMATION_0D, BTL_TRD_1_STAGE_05),
    {}
};

NpcGroupList N(NpcGroupBefore) = {
    NPC_GROUP(N(NpcData_KoopaTroopa_Patrol), BTL_TRD_1_FORMATION_05, BTL_TRD_1_STAGE_0C),
    NPC_GROUP(N(NpcData_ParaTroopa), BTL_TRD_1_FORMATION_0D, BTL_TRD_1_STAGE_05),
    {}
};
