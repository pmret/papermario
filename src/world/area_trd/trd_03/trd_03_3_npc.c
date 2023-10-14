#include "trd_03.h"

extern EvtScript N(EVS_StartKoopaBrosTheme);
extern EvtScript N(EVS_EndKoopaBrosTheme);
extern EvtScript N(EVS_EnterMap);

#include "world/common/enemy/KoopaTroopa_Wander.inc.c"

NpcSettings N(NpcSettings_KoopaBros) = {
    .height = 34,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#include "world/common/enemy/Bobomb_Wander.inc.c"

EvtScript N(EVS_Scene_GreenKoopaBros) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC(N(EVS_StartKoopaBrosTheme))
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -720, 0, 75)
    EVT_CALL(SetPlayerPos, -700, 0, 80)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_IdleCrouch)
    EVT_CALL(SetNpcPos, NPC_KoopaBros, -570, 0, -57)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros, 270, 0)
    EVT_THREAD
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -607, 0, 80)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 320)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -607, 0, 80)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Idle)
    EVT_WAIT(15 * DT)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros, 90, 0)
    EVT_WAIT(3 * DT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Run)
    EVT_CALL(SetNpcSpeed, NPC_KoopaBros, EVT_FLOAT(2.6 / DT))
    EVT_CALL(NpcMoveTo, NPC_KoopaBros, -555, 20, 0)
    EVT_CALL(InterpNpcYaw, NPC_KoopaTroopa_01, 270, 0)
    EVT_WAIT(15 * DT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Idle)
    EVT_WAIT(2 * DT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Talk)
    EVT_WAIT(25 * DT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Idle)
    EVT_CALL(SetNpcAnimation, NPC_KoopaTroopa_01, ANIM_KoopaTroopa_Salute)
    EVT_WAIT(25 * DT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaTroopa_01, ANIM_KoopaTroopa_Idle)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_ori1, SOUND_LARGE_GATE_OPEN, SOUND_SPACE_DEFAULT)
        EVT_CALL(MakeLerp, 100, 0, 40 * DT, EASING_QUADRATIC_IN)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_0ri, 0, LVar0, -1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(PlaySoundAtCollider, COLLIDER_ori1, SOUND_LARGE_GATE_CLOSE, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
        EVT_WAIT(10 * DT)
    EVT_END_THREAD
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Run)
    EVT_CALL(SetNpcSpeed, NPC_KoopaBros, EVT_FLOAT(2.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_KoopaBros, -550, 70, 0)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Idle)
    EVT_WAIT(15 * DT)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_KoopaBros, ANIM_KoopaBros_Green_Talk, ANIM_KoopaBros_Green_Idle, 5, MSG_CH1_00D3)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_WAIT(10 * DT)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_ttw, SOUND_METAL_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 80, 10, EASING_LINEAR)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_d1, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_d2, LVar0, 0, 1, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(SetPlayerPos, -647, 0, 80)
    EVT_EXEC_WAIT(N(EVS_EnterMap))
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros, 270, 5)
    EVT_CALL(SetNpcImgFXParams, NPC_KoopaBros, IMGFX_SET_ANIM, IMGFX_ANIM_STARTLE, 2, 1, 0)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Shock)
    EVT_WAIT(12 * DT)
    EVT_CALL(SetNpcImgFXParams, NPC_KoopaBros, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_KoopaBros, ANIM_KoopaBros_Green_Talk, ANIM_KoopaBros_Green_Idle, 0, MSG_CH1_00D4)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Walk)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros, 45, 2)
    EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros, SOUND_RUN_AWAY_BUILDUP, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Run)
    EVT_CALL(SetNpcJumpscale, NPC_KoopaBros, EVT_FLOAT(0.8))
    EVT_CALL(GetNpcPos, NPC_KoopaBros, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_KoopaBros, LVar0, LVar1, LVar2, 8 * DT)
    EVT_WAIT(8 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros, SOUND_RUN_AWAY, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcSpeed, NPC_KoopaBros, EVT_FLOAT(8.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_KoopaBros, -300, 70, 0)
    EVT_SET(GB_StoryProgress, STORY_CH1_KOOPA_BROS_HID_KEY)
    EVT_CALL(RemoveNpc, NPC_KoopaBros)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_EXEC(N(EVS_EndKoopaBrosTheme))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaBros) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_KOOPA_BROS_HID_KEY)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_KoopaTroopa_01) = {
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPA_BROS_HID_KEY)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaTroopa_Walk)
    EVT_WAIT(10)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_KoopaTroopa_Wander)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaTroopa_01) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KoopaTroopa_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_KoopaTroopa_02) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_IF_LT(LVar0, -150)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaTroopa_Salute)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 15)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaTroopa_Walk)
    EVT_LABEL(1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_IF_LT(LVar0, -100)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaTroopa_Run)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(7.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, 35, -130, 0)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_CALL(NpcMoveTo, NPC_SELF, 90, -130, 0)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(NpcMoveTo, NPC_SELF, 105, 10, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaTroopa_Walk)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_KoopaTroopa_Wander)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaTroopa_02) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KoopaTroopa_02)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_KoopaBros) = {
    .id = NPC_KoopaBros,
    .pos = { -569.0f, 0.0f, -57.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_KoopaBros),
    .settings = &N(NpcSettings_KoopaBros),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_KoopaBros_Green_Idle,
        .walk   = ANIM_KoopaBros_Green_Walk,
        .run    = ANIM_KoopaBros_Green_Run,
        .chase  = ANIM_KoopaBros_Green_Run,
        .anim_4 = ANIM_KoopaBros_Green_Idle,
        .anim_5 = ANIM_KoopaBros_Green_Idle,
        .death  = ANIM_KoopaBros_Green_HurtStill,
        .hit    = ANIM_KoopaBros_Green_HurtStill,
        .anim_8 = ANIM_KoopaBros_Green_Run,
        .anim_9 = ANIM_KoopaBros_Green_Run,
        .anim_A = ANIM_KoopaBros_Green_Run,
        .anim_B = ANIM_KoopaBros_Green_Run,
        .anim_C = ANIM_KoopaBros_Green_Run,
        .anim_D = ANIM_KoopaBros_Green_Run,
        .anim_E = ANIM_KoopaBros_Green_Run,
        .anim_F = ANIM_KoopaBros_Green_Run,
    },
};

NpcData N(NpcData_KoopaTroopa_01) = {
    .id = NPC_KoopaTroopa_01,
    .pos = { -520.0f, 0.0f, 15.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -520, 0, 15 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -520, 0, 15 },
            .detectSize = { 350 },
        }
    },
    .init = &N(EVS_NpcInit_KoopaTroopa_01),
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = KOOPA_TROOPA_TRD_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_KoopaTroopa_02) = {
    .id = NPC_KoopaTroopa_02,
    .pos = { -52.0f, 0.0f, -21.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -52, 0, -21 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -52, 0, -21 },
            .detectSize = { 350 },
        }
    },
    .init = &N(EVS_NpcInit_KoopaTroopa_02),
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = KOOPA_TROOPA_TRD_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_KoopaTroopa_03) = {
    .id = NPC_KoopaTroopa_03,
    .pos = { 375.0f, 0.0f, 15.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 375, 0, 15 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 375, 0, 15 },
            .detectSize = { 350 },
        }
    },
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = KOOPA_TROOPA_TRD_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaBros), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_01),
    NPC_GROUP(N(NpcData_KoopaTroopa_01), BTL_TRD_1_FORMATION_03, BTL_TRD_1_STAGE_01),
    NPC_GROUP(N(NpcData_KoopaTroopa_02), BTL_TRD_1_FORMATION_04, BTL_TRD_1_STAGE_01),
    NPC_GROUP(N(NpcData_KoopaTroopa_03), BTL_TRD_1_FORMATION_03, BTL_TRD_1_STAGE_01),
    {}
};
