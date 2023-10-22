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
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(GB_ARN_Tubba_MapID, 1)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittne, SOUND_CREAKY_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 80, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o300, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o301, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim0A)
    EVT_CALL(SetNpcPos, NPC_SELF, 520, 420, 0)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_CALL(NpcMoveTo, NPC_SELF, 390, 0, 30)
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim07)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(MakeLerp, 80, 0, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o300, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_o301, LVar0, 0, -1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittne, SOUND_CREAKY_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Tubba, ANIM_WorldTubba_Anim10, ANIM_WorldTubba_Anim06, 0, MSG_CH3_0101)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim19)
        EVT_WAIT(4)
        EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim1A)
        EVT_WAIT(17)
        EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim1B)
        EVT_WAIT(11)
        EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim1C)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim1D)
    EVT_END_THREAD
    EVT_WAIT(4)
    EVT_CALL(SetNpcJumpscale, NPC_Tubba, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_Tubba, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Tubba, LVar0, LVar1, LVar2, 30)
    EVT_CALL(PlaySoundAtNpc, NPC_Tubba, SOUND_LARGE_NPC_IMPACT, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySound, SOUND_LOOP_DGB_COLLAPSE)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 15, EVT_FLOAT(4.0))
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 15, EVT_FLOAT(2.0))
    EVT_CALL(SetSelfVar, 0, 3)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Tubba_Floor3) = {
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Tubba_Floor3)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Tubba_Floor2) = {
    EVT_CALL(N(UnkFunc1))
    EVT_CALL(GotoMap, EVT_PTR("dgb_08"), dgb_08_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Tubba_Floor2) = {
    EVT_IF_NE(GB_ARN_Tubba_MapID, 1)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_TUBBA_CHASED_MARIO_IN_HALL)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_Tubba, 137, 244, 35)
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Tubba_Floor2)))
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(2.0))
            EVT_WAIT(5)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 2, EVT_FLOAT(1.0))
            EVT_WAIT(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Tubba_Floor1) = {
    EVT_CALL(AwaitPlayerApproach, 0, 420, 400)
    EVT_SET(GB_ARN_Tubba_MapID, 1)
    EVT_SET(GB_StoryProgress, STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittse, SOUND_CREAKY_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 80, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o167, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o168, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_SELF, 555, 0, 0)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim0A)
    EVT_CALL(NpcMoveTo, NPC_SELF, 426, 0, 30)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(MakeLerp, 80, 0, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o167, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_o168, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittse, SOUND_CREAKY_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
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
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, 259, 167, 0)
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(AISettings_Tubba_Patrol)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Tubba_Floor1) = {
    EVT_CALL(N(UnkFunc1))
    EVT_CALL(GotoMap, EVT_PTR("dgb_00"), dgb_00_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Tubba_Floor1) = {
    EVT_IF_NE(GB_ARN_Tubba_MapID, 1)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Tubba_Floor1)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 136, 0, -330)
    EVT_END_IF
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Tubba_Floor1)))
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Sentinel_01) = {
    EVT_SET(LVar0, GB_StoryProgress)
    EVT_IF_GE(LVar0, STORY_CH3_TUBBA_WOKE_UP)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
        EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Sentinel_Anim01)
        EVT_CALL(SetNpcPos, NPC_SELF, -33, -3, 8)
        EVT_CALL(SetNpcRotation, NPC_SELF, -50, 30, 10)
        EVT_CALL(BindNpcIdle, NPC_SELF, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Sentinel_02) = {
    EVT_SET(LVar0, GB_StoryProgress)
    EVT_IF_GE(LVar0, STORY_CH3_TUBBA_WOKE_UP)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
        EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Sentinel_Anim01)
        EVT_CALL(SetNpcPos, NPC_SELF, -486, 182, 28)
        EVT_CALL(SetNpcRotation, NPC_SELF, -10, 50, 0)
        EVT_CALL(BindNpcIdle, NPC_SELF, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Sentinel_03) = {
    EVT_SET(LVar0, GB_StoryProgress)
    EVT_IF_GE(LVar0, STORY_CH3_TUBBA_WOKE_UP)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
        EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Sentinel_Anim01)
        EVT_CALL(SetNpcPos, NPC_SELF, -201, 0, -143)
        EVT_CALL(SetNpcRotation, NPC_SELF, -50, 0, 0)
        EVT_CALL(BindNpcIdle, NPC_SELF, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Sentinel_04) = {
    EVT_SET(LVar0, GB_StoryProgress)
    EVT_IF_GE(LVar0, STORY_CH3_TUBBA_WOKE_UP)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
        EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Sentinel_Anim01)
        EVT_CALL(SetNpcPos, NPC_SELF, -305, -1, -80)
        EVT_CALL(SetNpcRotation, NPC_SELF, -65, -30, 0)
        EVT_CALL(BindNpcIdle, NPC_SELF, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
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
