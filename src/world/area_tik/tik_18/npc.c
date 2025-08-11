#include "tik_18.h"

#include "world/common/enemy/Gloomba_Wander.inc.c"
#include "world/common/enemy/SpikedGloomba_Wander.inc.c"

EvtScript N(EVS_NpcIdle_SpikedGloomba) = {
    // wait for activation from block breaking
    Label(0)
        Call(GetSelfVar, 0, LVar0)
        IfFalse(LVar0)
            Wait(1)
            Goto(0)
        EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_SpikedGoomba_Dark_Sleep)
    Thread
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_AI_FOUND_PLAYER_JUMP, SOUND_SPACE_DEFAULT)
        Call(MakeLerp, -90, 0, 10, EASING_LINEAR)
        Label(1)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_SELF, LVar0, 0, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
        Call(GetNpcPos, NPC_SELF, LVarA, LVarB, LVarC)
        Call(MakeLerp, 0, 360, 15, EASING_LINEAR)
        Label(2)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(2)
            EndIf
        Call(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EndThread
    Call(SetNpcJumpscale, NPC_SELF, Float(0.7))
    Call(NpcJump0, NPC_SELF, 190, -10, -10, 25)
    Call(SetNpcAnimation, NPC_SELF, ANIM_SpikedGoomba_Dark_Laugh)
    Wait(20)
    Call(SetNpcAnimation, NPC_SELF, ANIM_SpikedGoomba_Dark_Idle)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_SpikedGloomba_Wander)))
    Return
    End
};

EvtScript N(EVS_NpcInit_SpikedGloomba) = {
    Call(SetNpcPos, NPC_SELF, 150, 76, -63)
    Call(SetNpcRotation, NPC_SELF, -85, 0, 0)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_SpikedGloomba)))
    Return
    End
};

NpcData N(NpcData_Gloomba) = {
    .id = NPC_Gloomba,
    .pos = { -60.0f, -10.0f, -30.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = true,
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
            .isFlying = true,
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
