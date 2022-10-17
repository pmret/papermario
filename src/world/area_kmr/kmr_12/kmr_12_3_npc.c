#include "kmr_12.h"
#include "entity.h"

#include "world/common/enemy/complete/Goomba_Wander.inc.c"

API_CALLABLE(N(GetAmbushEnemy)) {
    script->varTablePtr[0] = get_enemy_safe(NPC_Goomba_Ambush);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_OnReadBillboard) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Sign_EatMushroomsTrap, 160, 40)
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

EvtScript N(EVS_NpcIdle_Goomba) = {
    EVT_WAIT(1)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Goomba_FakeMushroom)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_20, 1)
    EVT_LABEL(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40000 | NPC_FLAG_200000, TRUE)
    EVT_WAIT(3)
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_LOOP(9)
        EVT_ADDF(LVar0, EVT_FLOAT(10.0))
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Goomba_Still)
    EVT_LOOP(9)
        EVT_ADDF(LVar0, EVT_FLOAT(10.0))
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Goomba_Dizzy)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Goomba_Idle)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_F8, 0)
    EVT_CALL(func_802CFE2C, NPC_SELF, 0x00002000)
    EVT_CALL(func_802CFD30, NPC_SELF, 5, 6, 1, 1, 0)
    EVT_WAIT(12)
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
    EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.6))
    EVT_CALL(NpcJump0, NPC_SELF, -35, 0, 30, 23)
    EVT_CALL(func_802CFD30, NPC_SELF, 0, 0, 0, 0, 0)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40000 | NPC_FLAG_200000, FALSE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_20, 0)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_40000000, 1)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnReadBillboard)), TRIGGER_WALL_PRESS_A, COLLIDER_o78, 1, 0)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Goomba_Wander)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goomba) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Goomba)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Goomba) = {
    .id = NPC_Goomba_Ambush,
    .settings = &N(NpcSettings_Goomba_Wander),
    .pos = { -33.0f, 30.0f, -25.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(EVS_NpcInit_Goomba),
    .drops = GOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { -33, 0, 30 },
            .wanderSize = { 40, 20 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 200, 0, 0 },
            .detectSize = { 400, 60 },
        }
    },
    .animations = GOOMBA_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Goomba), BTL_KMR_PART_1_FORMATION_01, BTL_KMR_PART_1_STAGE_02),
    {}
};
