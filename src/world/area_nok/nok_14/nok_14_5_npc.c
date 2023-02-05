#include "nok_14.h"

#include "world/common/enemy/complete/KoopaTroopa_Wander.inc.c"
#include "world/common/enemy/complete/SpikedGoomba_Wander.inc.c"
#include "world/common/enemy/complete/Paratroopa.inc.c"
#include "world/common/enemy/complete/KoopaTroopa_Stationary.inc.c"

EvtScript N(EVS_NpcIdle_KoopaTroopa_01) = {
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(AwaitPlayerApproach, -650, -35, 100)
    EVT_CALL(PlaySoundAt, SOUND_SEARCH_BUSH, SOUND_SPACE_MODE_0, -650, 75, -120)
    EVT_THREAD
        EVT_LOOP(5)
            EVT_CALL(TranslateModel, MODEL_o122, 2, 0, 0)
            EVT_WAIT(1)
            EVT_CALL(TranslateModel, MODEL_o122, -2, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40 | NPC_FLAG_40000 | NPC_FLAG_200000, TRUE)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 360, 20, EASING_LINEAR)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.6))
    EVT_CALL(NpcJump0, NPC_SELF, -650, 75, -30, 20)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40 | NPC_FLAG_40000 | NPC_FLAG_200000, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_KoopaTroopa_Wander)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaTroopa_01) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcPos, NPC_SELF, -650, 75, -150)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KoopaTroopa_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaTroopa_02) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, FALSE)
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_KoopaTroopa_01) = {
    .id = NPC_KoopaTroopa_01,
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .pos = { -667.0f, 75.0f, -50.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_2000,
    .init = &N(EVS_NpcInit_KoopaTroopa_01),
    .drops = KOOPA_TROOPA_NOK_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -690, 75, -50 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -670, 75, -112 },
            .detectSize = { 500 },
        }
    },
    .animations = KOOPA_TROOPA_ANIMS,
};

StaticNpc N(NpcData_ParaTroopa) = {
    .id = NPC_ParaTroopa,
    .settings = &N(NpcSettings_ParaTroopa),
    .pos = { 184.0f, 50.0f, -100.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = PARATROOPA_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 184, 50, -100 },
            .wanderSize = { 65, 40 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 238, 50, -100 },
            .detectSize = { 200 },
        }
    },
    .animations = PARATROOPA_ANIMS,
};

StaticNpc N(NpcData_SpikedGoomba) = {
    .id = NPC_SpikedGoomba,
    .settings = &N(NpcSettings_SpikedGoomba_Wander),
    .pos = { -257.0f, 0.0f, -47.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .drops = SPIKED_GOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -257, 0, -47 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -257, 0, -47 },
            .detectSize = { 200 },
        }
    },
    .animations = SPIKED_GOOMBA_ANIMS,
};

StaticNpc N(NpcData_KoopaTroopa_02) = {
    .id = NPC_KoopaTroopa_02,
    .settings = &N(NpcSettings_KoopaTroopa_Stationary),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAG_1 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_4000,
    .init = &N(EVS_NpcInit_KoopaTroopa_02),
    .drops = KOOPA_TROOPA_NOK_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaTroopa_01), BTL_NOK_FORMATION_0B, BTL_NOK_STAGE_00),
    NPC_GROUP(N(NpcData_ParaTroopa), BTL_NOK_FORMATION_11, BTL_NOK_STAGE_02),
    NPC_GROUP(N(NpcData_SpikedGoomba), BTL_NOK_FORMATION_06, BTL_NOK_STAGE_00),
    NPC_GROUP(N(NpcData_KoopaTroopa_02), BTL_NOK_FORMATION_0C, BTL_NOK_STAGE_00),
    {}
};
