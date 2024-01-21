#include "dgb_01.h"

#define AI_SENTINEL_FIRST_NPC NPC_Sentinel_01
#define AI_SENTINEL_LAST_NPC  NPC_Tubba
#include "world/common/enemy/Sentinel.inc.c"

#include "world/common/enemy/Clubba.h"
#include "world/common/enemy/TubbaBlubba_Patrol.inc.c"
#include "world/common/enemy/TubbaBlubba.inc.c"
#include "world/common/npc/Yakkey.inc.c"

#include "world/common/todo/UnkFunc1.inc.c"

EvtScript N(EVS_NpcIdle_Tubba_Floor3) = {
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Set(GB_ARN_Tubba_MapID, 1)
    Call(PlaySoundAtCollider, COLLIDER_deilittne, SOUND_CREAKY_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 80, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o300, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o301, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim0A)
    Call(SetNpcPos, NPC_SELF, 520, 420, 0)
    Call(SetNpcYaw, NPC_SELF, 270)
    Call(NpcMoveTo, NPC_SELF, 390, 0, 30)
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim07)
    Thread
        Wait(20)
        Call(MakeLerp, 80, 0, 10, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o300, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_o301, LVar0, 0, -1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySoundAtCollider, COLLIDER_deilittne, SOUND_CREAKY_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EndThread
    Call(SpeakToPlayer, NPC_Tubba, ANIM_WorldTubba_Anim10, ANIM_WorldTubba_Anim06, 0, MSG_CH3_0101)
    Thread
        Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim19)
        Wait(4)
        Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim1A)
        Wait(17)
        Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim1B)
        Wait(11)
        Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim1C)
        Wait(30)
        Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim1D)
    EndThread
    Wait(4)
    Call(SetNpcJumpscale, NPC_Tubba, Float(1.0))
    Call(GetNpcPos, NPC_Tubba, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_Tubba, LVar0, LVar1, LVar2, 30)
    Call(PlaySoundAtNpc, NPC_Tubba, SOUND_LARGE_NPC_IMPACT, SOUND_SPACE_DEFAULT)
    Call(PlaySound, SOUND_LOOP_DGB_COLLAPSE)
    Call(ShakeCam, CAM_DEFAULT, 0, 15, Float(4.0))
    Call(ShakeCam, CAM_DEFAULT, 0, 15, Float(2.0))
    Call(SetSelfVar, 0, 3)
    Return
    End
};

EvtScript N(EVS_NpcInit_Tubba_Floor3) = {
    Call(SetNpcScale, NPC_SELF, Float(1.25), Float(1.25), Float(1.25))
    Call(SetSelfVar, 0, 0)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Tubba_Floor3)))
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Tubba_Floor2) = {
    Call(N(UnkFunc1))
    Call(GotoMap, Ref("dgb_08"), dgb_08_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_NpcInit_Tubba_Floor2) = {
    IfNe(GB_ARN_Tubba_MapID, 1)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
        Return
    EndIf
    IfGe(GB_StoryProgress, STORY_CH3_TUBBA_CHASED_MARIO_IN_HALL)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
        Return
    EndIf
    Call(SetNpcPos, NPC_Tubba, 137, 244, 35)
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Tubba_Floor2)))
    Call(SetNpcScale, NPC_SELF, Float(1.25), Float(1.25), Float(1.25))
    Thread
        Loop(0)
            Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(2.0))
            Wait(5)
            Call(ShakeCam, CAM_DEFAULT, 0, 2, Float(1.0))
            Wait(8)
        EndLoop
    EndThread
    Return
    End
};

EvtScript N(EVS_NpcIdle_Tubba_Floor1) = {
    Call(AwaitPlayerApproach, 0, 420, 400)
    Set(GB_ARN_Tubba_MapID, 1)
    Set(GB_StoryProgress, STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
    Call(PlaySoundAtCollider, COLLIDER_deilittse, SOUND_CREAKY_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 80, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o167, LVar0, 0, -1, 0)
        Call(RotateModel, MODEL_o168, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcPos, NPC_SELF, 555, 0, 0)
    Call(SetNpcYaw, NPC_SELF, 270)
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim0A)
    Call(NpcMoveTo, NPC_SELF, 426, 0, 30)
    Thread
        Wait(20)
        Call(MakeLerp, 80, 0, 10, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o167, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_o168, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySoundAtCollider, COLLIDER_deilittse, SOUND_CREAKY_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EndThread
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
    Call(SetNpcSpeed, NPC_SELF, Float(5.0))
    Call(NpcMoveTo, NPC_SELF, 259, 167, 0)
    Call(N(PatrolNoAttackAI_Main), Ref(N(AISettings_Tubba_Patrol)))
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Tubba_Floor1) = {
    Call(N(UnkFunc1))
    Call(GotoMap, Ref("dgb_00"), dgb_00_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_NpcInit_Tubba_Floor1) = {
    IfNe(GB_ARN_Tubba_MapID, 1)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Tubba_Floor1)))
    Else
        Call(SetNpcPos, NPC_SELF, 136, 0, -330)
    EndIf
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Tubba_Floor1)))
    Call(SetNpcScale, NPC_SELF, Float(1.25), Float(1.25), Float(1.25))
    Return
    End
};

EvtScript N(EVS_NpcInit_Sentinel_01) = {
    Set(LVar0, GB_StoryProgress)
    IfGe(LVar0, STORY_CH3_TUBBA_WOKE_UP)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
        Call(EnableNpcShadow, NPC_SELF, FALSE)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Sentinel_Anim01)
        Call(SetNpcPos, NPC_SELF, -33, -3, 8)
        Call(SetNpcRotation, NPC_SELF, -50, 30, 10)
        Call(BindNpcIdle, NPC_SELF, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Sentinel_02) = {
    Set(LVar0, GB_StoryProgress)
    IfGe(LVar0, STORY_CH3_TUBBA_WOKE_UP)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
        Call(EnableNpcShadow, NPC_SELF, FALSE)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Sentinel_Anim01)
        Call(SetNpcPos, NPC_SELF, -486, 182, 28)
        Call(SetNpcRotation, NPC_SELF, -10, 50, 0)
        Call(BindNpcIdle, NPC_SELF, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Sentinel_03) = {
    Set(LVar0, GB_StoryProgress)
    IfGe(LVar0, STORY_CH3_TUBBA_WOKE_UP)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
        Call(EnableNpcShadow, NPC_SELF, FALSE)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Sentinel_Anim01)
        Call(SetNpcPos, NPC_SELF, -201, 0, -143)
        Call(SetNpcRotation, NPC_SELF, -50, 0, 0)
        Call(BindNpcIdle, NPC_SELF, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Sentinel_04) = {
    Set(LVar0, GB_StoryProgress)
    IfGe(LVar0, STORY_CH3_TUBBA_WOKE_UP)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
        Call(EnableNpcShadow, NPC_SELF, FALSE)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Sentinel_Anim01)
        Call(SetNpcPos, NPC_SELF, -305, -1, -80)
        Call(SetNpcRotation, NPC_SELF, -65, -30, 0)
        Call(BindNpcIdle, NPC_SELF, 0)
    EndIf
    Return
    End
};

NpcData N(NpcData_Sentinel_01) = {
    .id = NPC_Sentinel_01,
    .pos = { -180.0f, 100.0f, 230.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -180, 100, 230 },
            .wanderSize = { 35 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 450, 1000 },
        }
    },
    .init = &N(EVS_NpcInit_Sentinel_01),
    .settings = &N(NpcSettings_Sentinel),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = SENTINEL_ANIMS,
};

NpcData N(NpcData_Sentinel_02) = {
    .id = NPC_Sentinel_02,
    .pos = { 180.0f, 100.0f, 230.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 180, 100, 230 },
            .wanderSize = { 35 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 450, 1000 },
        }
    },
    .init = &N(EVS_NpcInit_Sentinel_02),
    .settings = &N(NpcSettings_Sentinel),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = SENTINEL_ANIMS,
};

NpcData N(NpcData_Sentinel_03) = {
    .id = NPC_Sentinel_03,
    .pos = { -180.0f, 100.0f, -230.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -180, 100, -230 },
            .wanderSize = { 35 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 450, 1000 },
        }
    },
    .init = &N(EVS_NpcInit_Sentinel_03),
    .settings = &N(NpcSettings_Sentinel),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = SENTINEL_ANIMS,
};

NpcData N(NpcData_Sentinel_04) = {
    .id = NPC_Sentinel_04,
    .pos = { 180.0f, 100.0f, -230.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 180, 100, -230 },
            .wanderSize = { 35 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 450, 1000 },
        }
    },
    .init = &N(EVS_NpcInit_Sentinel_04),
    .settings = &N(NpcSettings_Sentinel),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = SENTINEL_ANIMS,
};

AnimID N(ExtraAnims_Tubba)[] = {
    ANIM_WorldTubba_Anim06,
    ANIM_WorldTubba_Anim10,
    ANIM_WorldTubba_Anim09,
    ANIM_WorldTubba_Anim07,
    ANIM_WorldTubba_Anim0A,
    ANIM_WorldTubba_Anim0D,
    ANIM_WorldTubba_Anim19,
    ANIM_WorldTubba_Anim1A,
    ANIM_WorldTubba_Anim1B,
    ANIM_WorldTubba_Anim1C,
    ANIM_WorldTubba_Anim1D,
    ANIM_LIST_END
};

NpcData N(NpcData_Tubba_Floor3) = {
    .id = NPC_Tubba,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Tubba_Floor3),
    .settings = &N(NpcSettings_TubbaBlubba),
    .flags = ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = TUBBA_ANIMS,
    .extraAnimations = N(ExtraAnims_Tubba),
};

NpcData N(NpcData_Tubba_Floor2) = {
    .id = NPC_Tubba,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points  = {
                { 320, 210, 0 },
                { 370, 210, 0 },
            },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 350, 210, 0 },
            .detectSize = { 1000, 250 },
        }
    },
    .init = &N(EVS_NpcInit_Tubba_Floor2),
    .settings = &N(NpcSettings_TubbaBlubba_Patrol),
    .flags = ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = CLUBBA_DROPS,
    .animations = TUBBA_ANGRY_ANIMS,
    .extraAnimations = N(ExtraAnims_Tubba),
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Tubba_Floor1) = {
    .id = NPC_Tubba,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 8,
            .points  = {
                { 156, 0, 187 },
                { -36, 0, 290 },
                { -159, 0, 50 },
                { -80, 0, -218 },
                { 66, 0, -362 },
                { 196, 0, -268 },
                { 280, 0, -124 },
                { 250, 0, 100 },
            },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 250, 0, 100 },
            .detectSize = { 1000, 250 },
        }
    },
    .init = &N(EVS_NpcInit_Tubba_Floor1),
    .settings = &N(NpcSettings_TubbaBlubba_Patrol),
    .flags = ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = CLUBBA_DROPS,
    .animations = TUBBA_ANGRY_ANIMS,
    .extraAnimations = N(ExtraAnims_Tubba),
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Sentinel_01)),
    NPC_GROUP(N(NpcData_Sentinel_02)),
    NPC_GROUP(N(NpcData_Sentinel_03)),
    NPC_GROUP(N(NpcData_Sentinel_04)),
    {}
};

NpcGroupList N(ThirdFloorEscapeNPCs) = {
    NPC_GROUP(N(NpcData_Sentinel_01)),
    NPC_GROUP(N(NpcData_Sentinel_02)),
    NPC_GROUP(N(NpcData_Sentinel_03)),
    NPC_GROUP(N(NpcData_Sentinel_04)),
    NPC_GROUP(N(NpcData_Tubba_Floor3), BTL_DGB_FORMATION_04),
    {}
};

NpcGroupList N(SecondFloorEscapeNPCs) = {
    NPC_GROUP(N(NpcData_Sentinel_01)),
    NPC_GROUP(N(NpcData_Sentinel_02)),
    NPC_GROUP(N(NpcData_Sentinel_03)),
    NPC_GROUP(N(NpcData_Sentinel_04)),
    NPC_GROUP(N(NpcData_Tubba_Floor2), BTL_DGB_FORMATION_04, BTL_DGB_STAGE_00),
    {}
};

NpcGroupList N(FirstFloorEscapeNPCs) = {
    NPC_GROUP(N(NpcData_Sentinel_01)),
    NPC_GROUP(N(NpcData_Sentinel_02)),
    NPC_GROUP(N(NpcData_Sentinel_03)),
    NPC_GROUP(N(NpcData_Sentinel_04)),
    NPC_GROUP(N(NpcData_Tubba_Floor1), BTL_DGB_FORMATION_04, BTL_DGB_STAGE_00),
    {}
};
