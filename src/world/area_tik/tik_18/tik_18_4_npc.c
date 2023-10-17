#include "tik_18.h"

#include "world/common/enemy/Gloomba_Wander.inc.c"
#include "world/common/enemy/SpikedGloomba_Wander.inc.c"

EvtScript N(EVS_NpcIdle_SpikedGloomba) = {
    // wait for activation from block breaking
    EVT_LABEL(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_FALSE(LVar0)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_SpikedGoomba_Dark_Sleep)
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_AI_FOUND_PLAYER_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(MakeLerp, -90, 0, 10, EASING_LINEAR)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_SELF, LVar0, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(GetNpcPos, NPC_SELF, LVarA, LVarB, LVarC)
        EVT_CALL(MakeLerp, 0, 360, 15, EASING_LINEAR)
        EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(2)
            EVT_END_IF
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.7))
    EVT_CALL(NpcJump0, NPC_SELF, 190, -10, -10, 25)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_SpikedGoomba_Dark_Laugh)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_SpikedGoomba_Dark_Idle)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_SpikedGloomba_Wander)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_SpikedGloomba) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 150, 76, -63)
    EVT_CALL(SetNpcRotation, NPC_SELF, -85, 0, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_SpikedGloomba)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Gloomba) = {
    .id = NPC_Gloomba,
    .pos = { -60.0f, -10.0f, -30.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -60, -10, -30 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -60, -10, -30 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_Gloomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = GLOOMBA_DROPS,
    .animations = GLOOMBA_ANIMS,
};

NpcData N(NpcData_SpikedGloomba) = {
    .id = NPC_SpikedGloomba,
    .pos = { 30.0f, -10.0f, -20.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 30, -10, -20 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 30, -10, -20 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_SpikedGloomba),
    .settings = &N(NpcSettings_SpikedGloomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = SPIKED_GLOOMBA_DROPS,
    .animations = SPIKED_GLOOMBA_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Gloomba), BTL_TIK_FORMATION_0A, BTL_TIK_STAGE_00),
    NPC_GROUP(N(NpcData_SpikedGloomba), BTL_TIK_FORMATION_0E, BTL_TIK_STAGE_00),
    {}
};
