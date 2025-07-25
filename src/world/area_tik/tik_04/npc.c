#include "tik_04.h"

#include "world/common/enemy/SpikedGloomba_Wander.inc.c"

EvtScript N(EVS_NpcIdle_SpikedGloomba) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(tik_04_ENTRY_0)
            Call(SetNpcPos, NPC_SELF, 280, -10, 0)
        CaseEq(tik_04_ENTRY_1)
            Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_SpikedGloomba_Wander)))
            Return
        CaseEq(tik_04_ENTRY_2)
            Call(SetNpcPos, NPC_SELF, 280, -10, 0)
        CaseEq(tik_04_ENTRY_3)
            Call(SetNpcPos, NPC_SELF, 360, -10, 0)
    EndSwitch
    Label(100)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLt(LVar0, -30)
        Wait(1)
        Goto(100)
    EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_SpikedGoomba_Dark_Run)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING | NPC_FLAG_NO_SHADOW_RAYCAST, false)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, true)
    Call(SetNpcSpeed, NPC_SELF, 2)
    Call(GetSelfNpcID, LVar0)
    IfEq(LVar0, 0)
        Call(NpcMoveTo, NPC_SELF, 55, 0, 0)
    Else
        Wait(14)
        Call(NpcMoveTo, NPC_SELF, 60, 0, 0)
    EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_SpikedGoomba_Dark_Idle)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_SpikedGloomba_Wander)))
    Return
    End
};

EvtScript N(EVS_NpcInit_SpikedGloomba) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_SpikedGloomba)))
    Return
    End
};

NpcData N(NpcData_SpikedGloomba_01) = {
    .id = NPC_SpikedGoomba_01,
    .pos = { 40.0f, -135.0f, 10.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 40, -135, 10 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 40, -135, 10 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_SpikedGloomba),
    .settings = &N(NpcSettings_SpikedGloomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = SPIKED_GLOOMBA_DROPS,
    .animations = SPIKED_GLOOMBA_ANIMS,
};

NpcData N(NpcData_SpikedGloomba_02) = {
    .id = NPC_SpikedGoomba_02,
    .pos = { 141.0f, -135.0f, 85.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 141, -135, 85 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 141, -135, 85 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_SpikedGloomba),
    .settings = &N(NpcSettings_SpikedGloomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = SPIKED_GLOOMBA_DROPS,
    .animations = SPIKED_GLOOMBA_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_SpikedGloomba_01), BTL_TIK_FORMATION_0F, BTL_TIK_STAGE_01),
    NPC_GROUP(N(NpcData_SpikedGloomba_02), BTL_TIK_FORMATION_0E, BTL_TIK_STAGE_01),
    {}
};
