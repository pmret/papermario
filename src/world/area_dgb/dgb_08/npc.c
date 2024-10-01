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
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGe(LVar0, -350)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Set(GB_ARN_Tubba_MapID, 8)
    Set(GB_StoryProgress, STORY_CH3_TUBBA_CHASED_MARIO_IN_HALL)
    Call(PlaySoundAtCollider, COLLIDER_deilittne, SOUND_CREAKY_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 80, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o140, LVar0, 0, -1, 0)
        Call(RotateModel, MODEL_o141, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim0A)
    Call(SetNpcPos, NPC_SELF, -665, 210, 180)
    Call(SetNpcYaw, NPC_SELF, 90)
    Call(NpcMoveTo, NPC_SELF, -530, 180, 30)
    Thread
        Wait(20)
        Call(MakeLerp, 80, 0, 10, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o140, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_o141, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySoundAtCollider, COLLIDER_deilittne, SOUND_CREAKY_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EndThread
    Call(NpcMoveTo, NPC_SELF, -500, 80, 10)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_Tubba)))
    Return
    End
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
        enemy->aiFlags |= AI_FLAG_80;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetPatrolAfterWaiting) = {
    Label(10)
    Call(GetNpcPos, NPC_Tubba, LVar0, LVar1, LVar2)
    IfGt(LVar1, 0)
        Wait(1)
        Goto(10)
    EndIf
    Call(N(SetTubbaPatrolTerritory))
    Return
    End
};

EvtScript N(EVS_NpcAI_Tubba) = {
    Call(N(SetTubbaPatrolMode))
    Exec(N(EVS_SetPatrolAfterWaiting))
    Thread
        Loop(0)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_HEAVY_NPC_STEP_C, SOUND_PARAM_QUIET)
            Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(2.0))
            Wait(5)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_HEAVY_NPC_STEP_C, SOUND_PARAM_QUIET)
            Call(ShakeCam, CAM_DEFAULT, 0, 2, Float(1.0))
            Wait(8)
        EndLoop
    EndThread
    Call(N(PatrolNoAttackAI_Main), Ref(N(AISettings_Tubba_Patrol)))
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Tubba) = {
    Call(N(UnkFunc1))
    Call(GotoMap, Ref("dgb_01"), dgb_01_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_NpcInit_Tubba) = {
    IfLt(GB_StoryProgress, STORY_CH3_TUBBA_SMASHED_THE_BRIDGES)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
        Return
    EndIf
    IfGe(GB_StoryProgress, STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
        Return
    EndIf
    Call(SetNpcScale, NPC_SELF, Float(1.25), Float(1.25), Float(1.25))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Tubba)))
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(dgb_08_ENTRY_0)
            IfNe(GB_ARN_Tubba_MapID, 8)
                Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
            Else
                Call(SetNpcPos, NPC_SELF, -130, 0, 200)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcAI_Tubba)))
            EndIf
        CaseEq(dgb_08_ENTRY_1)
            IfNe(GB_ARN_Tubba_MapID, 8)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Tubba)))
            Else
                Call(SetNpcPos, NPC_SELF, -130, 210, 80)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcAI_Tubba)))
            EndIf
    EndSwitch
    Return
    End
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
    Label(0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim07)
        Wait(30)
        Loop(15)
            Call(N(PlayAlertSound))
            Wait(60)
        EndLoop
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim0C)
        Wait(20)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim07)
        Wait(30)
        Loop(5)
            Call(N(PlayAlertSound))
            Wait(60)
        EndLoop
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim0C)
        Wait(15)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_LastClubba) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim08)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_SNAP_AWAKE_A, SOUND_SPACE_DEFAULT)
    Wait(10)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim02)
    Wait(20)
    Call(GetNpcYaw, NPC_SELF, LVar0)
    Add(LVar0, 180)
    Call(InterpNpcYaw, NPC_SELF, LVar0, 0)
    Wait(10)
    Call(GetNpcYaw, NPC_SELF, LVar0)
    Add(LVar0, 180)
    Call(InterpNpcYaw, NPC_SELF, LVar0, 0)
    Wait(25)
    Call(GetNpcYaw, NPC_SELF, LVar0)
    Add(LVar0, 180)
    Call(InterpNpcYaw, NPC_SELF, LVar0, 0)
    Wait(15)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldClubba_Anim05, ANIM_WorldClubba_Anim02, 0, MSG_CH3_00F2)
    Wait(10)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim06)
    Wait(10)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim07)
    Return
    End
};

EvtScript N(EVS_NpcInit_LastClubba) = {
    Call(SetNpcCollisionSize, NPC_SELF, 36, 30)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Anim07)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_LastClubba)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_LastClubba)))
    Return
    End
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
    Return
    End
};

EvtScript N(EVS_NpcInit_Clubba_Unused) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Clubba_Unused)))
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Return
    End
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
