#include "dgb_08.h"

#include "world/common/enemy/TubbaBlubba_Patrol.inc.c"
#include "world/common/enemy/TubbaBlubba.inc.c"

NpcSettings N(NpcSettings_Yakkey) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_CLUBBA,
};

#define INCLUDE_CLUBBA_WANDER
#include "world/common/enemy/Clubba_Multi.inc.c"

#define AI_SENTINEL_FIRST_NPC NPC_Sentinel_01
#define AI_SENTINEL_LAST_NPC  NPC_Tubba
#include "world/common/enemy/Sentinel.inc.c"

NpcSettings N(NpcSettings_LastClubba) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

extern EvtScript N(EVS_NpcAI_Tubba);

EvtScript N(EVS_NpcIdle_Tubba) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GE(LVar0, -350)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(GB_ARN_Tubba_MapID, 8)
    EVT_SET(GB_StoryProgress, STORY_CH3_TUBBA_CHASED_MARIO_IN_HALL)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittne, SOUND_CREAKY_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 80, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o140, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o141, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim0A)
    EVT_CALL(SetNpcPos, NPC_SELF, -665, 210, 180)
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_CALL(NpcMoveTo, NPC_SELF, -530, 180, 30)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(MakeLerp, 80, 0, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o140, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_o141, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittne, SOUND_CREAKY_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_SELF, -500, 80, 10)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Tubba)))
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/UnkFunc1.inc.c"

API_CALLABLE(N(SetTubbaPatrolTerritory)) {
    if (get_enemy_safe(NPC_Tubba)) {
        Enemy* enemy = get_enemy(NPC_Tubba);
        enemy->territory->patrol.numPoints = 2;
        enemy->territory->patrol.points[0].x = -450;
        enemy->territory->patrol.points[0].y = 0;
        enemy->territory->patrol.points[0].z = 175;
        enemy->territory->patrol.points[1].x = 300;
        enemy->territory->patrol.points[1].y = 0;
        enemy->territory->patrol.points[1].z = 175;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetTubbaPatrolMode)) {
    if (get_enemy_safe(NPC_Tubba)) {
        Enemy* enemy = get_enemy(NPC_Tubba);
        enemy->aiFlags |= ENEMY_AI_FLAG_80;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetPatrolAfterWaiting) = {
    EVT_LABEL(10)
    EVT_CALL(GetNpcPos, NPC_Tubba, LVar0, LVar1, LVar2)
    EVT_IF_GT(LVar1, 0)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(N(SetTubbaPatrolTerritory))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Tubba) = {
    EVT_CALL(N(SetTubbaPatrolMode))
    EVT_EXEC(N(EVS_SetPatrolAfterWaiting))
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_HEAVY_NPC_STEP_C, SOUND_PARAM_QUIET)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(2.0))
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_HEAVY_NPC_STEP_C, SOUND_PARAM_QUIET)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 2, EVT_FLOAT(1.0))
            EVT_WAIT(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(AISettings_Tubba_Patrol)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Tubba) = {
    EVT_CALL(N(UnkFunc1))
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), dgb_01_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Tubba) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_TUBBA_SMASHED_THE_BRIDGES)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Tubba)))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(dgb_08_ENTRY_0)
            EVT_IF_NE(GB_ARN_Tubba_MapID, 8)
                EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_SELF, -130, 0, 200)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Tubba)))
            EVT_END_IF
        EVT_CASE_EQ(dgb_08_ENTRY_1)
            EVT_IF_NE(GB_ARN_Tubba_MapID, 8)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Tubba)))
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_SELF, -130, 210, 80)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Tubba)))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Tubba) = {
    .id = NPC_Tubba,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 10,
            .points  = {
                { -400, 210, 80 },
                { -100, 210, 80 },
                { 100, 210, 80 },
                { 400, 210, 80 },
                { 820, 100, 80 },
                { 820, 100, 260 },
                { 400, 0, 260 },
                { 100, 0, 200 },
                { -100, 0, 175 },
                { -450, 0, 175 },
            },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 150, 0, 175 },
            .detectSize = { 1450, 200 },
        }
    },
    .init = &N(EVS_NpcInit_Tubba),
    .settings = &N(NpcSettings_TubbaBlubba),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
    .drops = CLUBBA_DROPS,
    .animations = TUBBA_ANGRY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Clubba_01)[] = {
    {
        .id = NPC_Clubba_01,
        .pos = { -250.0f, 0.0f, 135.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -250, 0, 135 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -250, 0, 135 },
                .detectSize = { 250 },
            }
        },
        .settings = &N(NpcSettings_Clubba_Wander),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = CLUBBA_DROPS,
        .animations = CLUBBA_ANIMS,
        .extraAnimations = N(ExtraAnims_Clubba),
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    CLUBBA_MACE_HITBOX(NPC_Clubba_01_Hitbox),
};

NpcData N(NpcData_Clubba_02)[] = {
    {
        .id = NPC_Clubba_02,
        .pos = { 220.0f, 0.0f, 155.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 220, 0, 155 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 220, 0, 155 },
                .detectSize = { 250 },
            }
        },
        .settings = &N(NpcSettings_Clubba_Wander),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = CLUBBA_DROPS,
        .animations = CLUBBA_ANIMS,
        .extraAnimations = N(ExtraAnims_Clubba),
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    CLUBBA_MACE_HITBOX(NPC_Clubba_02_Hitbox),
};

NpcData N(NpcData_Clubba_03)[] = {
    {
        .id = NPC_Clubba_03,
        .pos = { 825.0f, 100.0f, 200.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 825, 100, 200 },
                .wanderSize = { 25 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 825, 100, 200 },
                .detectSize = { 150 },
            }
        },
        .settings = &N(NpcSettings_Clubba_Wander),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = CLUBBA_DROPS,
        .animations = CLUBBA_ANIMS,
        .extraAnimations = N(ExtraAnims_Clubba),
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    CLUBBA_MACE_HITBOX(NPC_Clubba_03_Hitbox),
};

NpcData N(NpcData_Sentinel_01) = {
    .id = NPC_Sentinel_01,
    .pos = { 75.0f, 310.0f, 85.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 75, 310, 85 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 75, 0, 85 },
            .detectSize = { 250, 55 },
        }
    },
    .settings = &N(NpcSettings_Sentinel),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = SENTINEL_ANIMS,
};

NpcData N(NpcData_Sentinel_02) = {
    .id = NPC_Sentinel_02,
    .pos = { -451.0f, 310.0f, 81.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -451, 310, 81 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { -310, 0, 175 },
            .detectSize = { 250, 145 },
        }
    },
    .settings = &N(NpcSettings_Sentinel),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = SENTINEL_ANIMS,
};

API_CALLABLE(N(PlayAlertSound)) {
    ai_enemy_play_sound(get_npc_unsafe(script->owner1.enemy->npcID), SOUND_SNORE_INHALE_A, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_LastClubba) = {
    EVT_LABEL(0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim07)
        EVT_WAIT(30)
        EVT_LOOP(15)
            EVT_CALL(N(PlayAlertSound))
            EVT_WAIT(60)
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim0C)
        EVT_WAIT(20)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim07)
        EVT_WAIT(30)
        EVT_LOOP(5)
            EVT_CALL(N(PlayAlertSound))
            EVT_WAIT(60)
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim0C)
        EVT_WAIT(15)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_LastClubba) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim08)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SNAP_AWAKE_A, SOUND_SPACE_DEFAULT)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim02)
    EVT_WAIT(20)
    EVT_CALL(GetNpcYaw, NPC_SELF, LVar0)
    EVT_ADD(LVar0, 180)
    EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 0)
    EVT_WAIT(10)
    EVT_CALL(GetNpcYaw, NPC_SELF, LVar0)
    EVT_ADD(LVar0, 180)
    EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 0)
    EVT_WAIT(25)
    EVT_CALL(GetNpcYaw, NPC_SELF, LVar0)
    EVT_ADD(LVar0, 180)
    EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 0)
    EVT_WAIT(15)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldClubba_Anim05, ANIM_WorldClubba_Anim02, 0, MSG_CH3_00F2)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim06)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim07)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_LastClubba) = {
    EVT_CALL(SetNpcCollisionSize, NPC_SELF, 36, 30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim07)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_LastClubba)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_LastClubba)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_LastClubba) = {
    .id = NPC_Clubba_Last,
    .pos = { 426.0f, 0.0f, 38.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_NpcInit_LastClubba),
    .settings = &N(NpcSettings_LastClubba),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = CLUBBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    .tattle = MSG_NpcTattle_LastClubba,
};

EvtScript N(EVS_NpcIdle_Clubba_Unused) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Clubba_Unused) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Clubba_Unused)))
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Clubba_Unused) = {
    .id = NPC_Clubba_Unused,
    .pos = { -250.0f, 0.0f, 135.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -250, 0, 135 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -250, 0, 135 },
            .detectSize = { 250 },
        }
    },
    .init = &N(EVS_NpcInit_Clubba_Unused),
    .settings = &N(NpcSettings_Clubba_Wander),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = CLUBBA_DROPS,
    .animations = CLUBBA_ANIMS,
    .extraAnimations = N(ExtraAnims_Clubba),
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(BeforeNPCs) = {
    NPC_GROUP(N(NpcData_Clubba_Unused), BTL_DGB_FORMATION_02, BTL_DGB_STAGE_02),
    NPC_GROUP(N(NpcData_Clubba_01), BTL_DGB_FORMATION_02, BTL_DGB_STAGE_02),
    NPC_GROUP(N(NpcData_Clubba_02), BTL_DGB_FORMATION_02, BTL_DGB_STAGE_02),
    NPC_GROUP(N(NpcData_Clubba_03), BTL_DGB_FORMATION_03, BTL_DGB_STAGE_02),
    NPC_GROUP(N(NpcData_Sentinel_01)),
    NPC_GROUP(N(NpcData_Sentinel_02)),
    {}
};

NpcGroupList N(TubbaNPCs) = {
    NPC_GROUP(N(NpcData_Tubba), BTL_DGB_FORMATION_04, BTL_DGB_STAGE_00),
    {}
};

NpcGroupList N(AfterNPCs) = {
    NPC_GROUP(N(NpcData_LastClubba)),
    {}
};
