#include "nok_12.h"

#include "world/common/enemy/KoopaTroopa_Wander.inc.c"
#include "world/common/enemy/KoopaTroopa_Patrol.inc.c"
#include "world/common/enemy/Goomba_Wander.inc.c"
#include "world/common/enemy/SpikedGoomba_Wander.inc.c"
#include "world/common/enemy/SpikedGoomba_Patrol.inc.c"

// 'sleep' on top of brick block until it's broken
EvtScript N(EVS_NpcIdle_SpikedGoomba) = {
    EVT_LABEL(0)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_SpikedGoomba_Sleep)
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
    EVT_CALL(NpcJump0, NPC_SELF, -65, 0, -120, 25)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_SpikedGoomba_Hurt)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_SpikedGoomba_Idle)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_SpikedGoomba_Wander)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_SpikedGoomba) = {
    EVT_CALL(SetNpcPos, NPC_SELF, -165, 86, -118)
    EVT_CALL(SetNpcRotation, NPC_SELF, -85, 0, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_SpikedGoomba)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_KoopaTroopa_02) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KoopaTroopa_Demo_MissAttack) = {
    EVT_WAIT(45)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaTroopa_ShellEnter)
    EVT_WAIT(8)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaTroopa_ShellSpin)
    EVT_WAIT(6)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 80)
    EVT_ADD(LVar2, 100)
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 12)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaTroopa_ShellExit)
    EVT_WAIT(8)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaTroopa_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaTroopa_02) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_GE(LVar0, nok_12_ENTRY_2)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KoopaTroopa_02)))
        EVT_CALL(SetNpcPos, NPC_SELF, 310, 0, -165)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaTroopa_02_Demo) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_GE(LVar0, nok_12_ENTRY_2)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_KoopaTroopa_Demo_MissAttack)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_KoopaTroopa_01) = {
    .id = NPC_KoopaTroopa_01,
    .pos = { -370.0f, 0.0f, -25.0f },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points  = {
                { -370, 0, -25 },
                { -455, 0, -25 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -436, 0, -104 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_KoopaTroopa_Patrol),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = KOOPA_TROOPA_NOK_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_KoopaTroopa_02) = {
    .id = NPC_KoopaTroopa_02,
    .pos = { 563.0f, 50.0f, -43.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 563, 50, -43 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 563, 50, -43 },
            .detectSize = { 500 },
        }
    },
    .init = &N(EVS_NpcInit_KoopaTroopa_02),
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = KOOPA_TROOPA_NOK_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_KoopaTroopa_02_Demo) = {
    .id = NPC_KoopaTroopa_02,
    .pos = { 600.0f, 50.0f, -75.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 563, 50, -43 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 563, 50, -43 },
            .detectSize = { 500 },
        }
    },
    .init = &N(EVS_NpcInit_KoopaTroopa_02_Demo),
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = KOOPA_TROOPA_NOK_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Goomba) = {
    .id = NPC_Goomba,
    .pos = { 50.0f, 0.0f, -72.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 50, 0, -72 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 50, 0, -72 },
            .detectSize = { 150, 80 },
        }
    },
    .settings = &N(NpcSettings_Goomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = GOOMBA_DROPS,
    .animations = GOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_SpikedGoomba) = {
    .id = NPC_SpikedGoomba,
    .pos = { -160.0f, 0.0f, -120.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -84, 0, -72 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { -84, 0, -72 },
            .detectSize = { 150, 80 },
        }
    },
    .init = &N(EVS_NpcInit_SpikedGoomba),
    .settings = &N(NpcSettings_SpikedGoomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SPIKED_GOOMBA_DROPS,
    .animations = SPIKED_GOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaTroopa_01), BTL_NOK_FORMATION_09, BTL_NOK_STAGE_00),
    NPC_GROUP(N(NpcData_KoopaTroopa_02), BTL_NOK_FORMATION_0F, BTL_NOK_STAGE_00),
    NPC_GROUP(N(NpcData_Goomba), BTL_NOK_FORMATION_01, BTL_NOK_STAGE_01),
    NPC_GROUP(N(NpcData_SpikedGoomba), BTL_NOK_FORMATION_04, BTL_NOK_STAGE_01),
    {}
};

NpcGroupList N(DemoNPCs) = {
    NPC_GROUP(N(NpcData_KoopaTroopa_01), BTL_NOK_FORMATION_09, BTL_NOK_STAGE_00),
    NPC_GROUP(N(NpcData_KoopaTroopa_02_Demo), BTL_NOK_FORMATION_0F, BTL_NOK_STAGE_00),
    NPC_GROUP(N(NpcData_Goomba), BTL_NOK_FORMATION_01, BTL_NOK_STAGE_01),
    NPC_GROUP(N(NpcData_SpikedGoomba), BTL_NOK_FORMATION_04, BTL_NOK_STAGE_01),
    {}
};
