#include "kmr_09.h"
#include "entity.h"

#include "world/common/enemy/complete/Goomba_Wander.inc.c"
#include "world/common/enemy/complete/Paragoomba_Wander.inc.c"

StaticNpc N(NpcData_Goomba_01) = {
    .id = NPC_Goomba_01,
    .settings = &N(NpcSettings_Goomba_Wander),
    .pos = { 200.0f, 0.0f, 24.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .drops = GOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 200, 0, 24 },
            .wanderSize = { 30, 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 200, 0, 24 },
            .detectSize = { 250 },
        }
    },
    .animations = GOOMBA_ANIMS,
};

StaticNpc N(NpcData_Goomba_02) = {
    .id = NPC_Goomba_02,
    .settings = &N(NpcSettings_Goomba_Wander),
    .pos = { 250.0f, 0.0f, 35.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .drops = GOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 250, 0, 35 },
            .wanderSize = { 30, 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 250, 0, 35 },
            .detectSize = { 250 },
        }
    },
    .animations = GOOMBA_ANIMS,
};

API_CALLABLE(N(GetAmbushEnemy)) {
    script->varTablePtr[0] = get_enemy_safe(NPC_Goomba_Ambush);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_OnReadBillboard) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Sign_BewareOfGoombas, 160, 40)
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_SET(LocalFlag(0), FALSE)
    EVT_CALL(N(GetAmbushEnemy))
    EVT_IF_NE(LVar0, NULL)
        EVT_CALL(GetNpcVar, NPC_Goomba_Ambush, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(SetNpcVar, NPC_Goomba_Ambush, 0, 1)
            EVT_SET(LocalFlag(0), TRUE)
            EVT_WAIT(10)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_IF_EQ(LocalFlag(0), TRUE)
        EVT_UNBIND
    EVT_END_IF
    EVT_END
    EVT_RETURN //@bug wrong order for END/RETURN
};

EvtScript N(EVS_NpcIdle_Goomba_Ambush) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Goomba_Still)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, 1)
    EVT_LABEL(0)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_F8, SOUND_SPACE_MODE_0)
    EVT_CALL(func_802CFE2C, NPC_SELF, 0x00002000)
    EVT_CALL(func_802CFD30, NPC_SELF, FOLD_TYPE_5, 6, 1, 1, 0)
    EVT_WAIT(15)
    EVT_CALL(func_802CFE2C, NPC_SELF, 0x00002000)
    EVT_CALL(func_802CFD30, NPC_SELF, FOLD_TYPE_3, 0, 0, 0, 0)
    EVT_THREAD
        EVT_WAIT(2)
        EVT_SETF(LVar0, EVT_FLOAT(0.0))
        EVT_LOOP(20)
            EVT_ADDF(LVar0, EVT_FLOAT(18.0))
            EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, SOUND_SPACE_MODE_0)
    EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.6))
    EVT_CALL(NpcJump0, NPC_SELF, -35, 0, 25, 23)
    EVT_CALL(func_802CFD30, NPC_SELF, FOLD_TYPE_NONE, 0, 0, 0, 0)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_20, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, 0)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_40000000, 1)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnReadBillboard)), TRIGGER_WALL_PRESS_A, COLLIDER_kan, 1, 0)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Goomba_Wander)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goomba_Ambush) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Goomba_Ambush)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Goomba_Ambush) = {
    .id = NPC_Goomba_Ambush,
    .settings = &N(NpcSettings_Goomba_Wander),
    .pos = { -34.0f, 29.0f, -32.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Goomba_Ambush),
    .drops = GOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { -20, 0, 10 },
            .wanderSize = { 30, 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -20, 0, 10 },
            .detectSize = { 250 },
        }
    },
    .animations = GOOMBA_ANIMS,
};

StaticNpc N(NpcData_Paragoomba) = {
    .id = NPC_Paragoomba,
    .settings = &N(NpcSettings_Paragoomba_Wander),
    .pos = { 670.0f, 60.0f, 20.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = PARAGOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 670, 60, 20 },
            .wanderSize = { 30, 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 670, 60, 20 },
            .detectSize = { 250 },
        }
    },
    .animations = PARAGOOMBA_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Goomba_01), BTL_KMR_PART_1_FORMATION_01, BTL_KMR_PART_1_STAGE_02),
    NPC_GROUP(N(NpcData_Goomba_02), BTL_KMR_PART_1_FORMATION_01, BTL_KMR_PART_1_STAGE_02),
    NPC_GROUP(N(NpcData_Goomba_Ambush), BTL_KMR_PART_1_FORMATION_00, BTL_KMR_PART_1_STAGE_02),
    NPC_GROUP(N(NpcData_Paragoomba), BTL_KMR_PART_1_FORMATION_08, BTL_KMR_PART_1_STAGE_02),
    {}
};
