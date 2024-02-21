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
    Call(DisablePlayerInput, TRUE)
    Exec(N(EVS_StartKoopaBrosTheme))
    Call(DisablePartnerAI, 0)
    Call(SetNpcPos, NPC_PARTNER, -720, 0, 75)
    Call(SetPlayerPos, -700, 0, 80)
    Call(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_IdleCrouch)
    Call(SetNpcPos, NPC_KoopaBros, -570, 0, -57)
    Call(InterpNpcYaw, NPC_KoopaBros, 270, 0)
    Thread
        Call(UseSettingsFrom, CAM_DEFAULT, -607, 0, 80)
        Call(SetCamDistance, CAM_DEFAULT, 320)
        Call(SetPanTarget, CAM_DEFAULT, -607, 0, 80)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Idle)
    Wait(15 * DT)
    Call(InterpNpcYaw, NPC_KoopaBros, 90, 0)
    Wait(3 * DT)
    Call(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Run)
    Call(SetNpcSpeed, NPC_KoopaBros, Float(2.6 / DT))
    Call(NpcMoveTo, NPC_KoopaBros, -555, 20, 0)
    Call(InterpNpcYaw, NPC_KoopaTroopa_01, 270, 0)
    Wait(15 * DT)
    Call(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Idle)
    Wait(2 * DT)
    Call(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Talk)
    Wait(25 * DT)
    Call(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Idle)
    Call(SetNpcAnimation, NPC_KoopaTroopa_01, ANIM_KoopaTroopa_Salute)
    Wait(25 * DT)
    Call(SetNpcAnimation, NPC_KoopaTroopa_01, ANIM_KoopaTroopa_Idle)
    Thread
        Call(PlaySoundAtCollider, COLLIDER_ori1, SOUND_LARGE_GATE_OPEN, SOUND_SPACE_DEFAULT)
        Call(MakeLerp, 100, 0, 40 * DT, EASING_QUADRATIC_IN)
        Label(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_0ri, 0, LVar0, -1)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
        Call(PlaySoundAtCollider, COLLIDER_ori1, SOUND_LARGE_GATE_CLOSE, SOUND_SPACE_DEFAULT)
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
        Wait(10 * DT)
    EndThread
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Run)
    Call(SetNpcSpeed, NPC_KoopaBros, Float(2.0 / DT))
    Call(NpcMoveTo, NPC_KoopaBros, -550, 70, 0)
    Call(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Idle)
    Wait(15 * DT)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_KoopaBros, ANIM_KoopaBros_Green_Talk, ANIM_KoopaBros_Green_Idle, 5, MSG_CH1_00D3)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Wait(10 * DT)
    Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_METAL_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 80, 10, EASING_LINEAR)
    Label(10)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_d1, LVar0, 0, -1, 0)
    Call(RotateModel, MODEL_d2, LVar0, 0, 1, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Call(EnablePartnerAI)
    Call(SetPlayerPos, -647, 0, 80)
    ExecWait(N(EVS_EnterMap))
    Call(InterpNpcYaw, NPC_KoopaBros, 270, 5)
    Call(SetNpcImgFXParams, NPC_KoopaBros, IMGFX_SET_ANIM, IMGFX_ANIM_STARTLE, 2, 1, 0)
    Call(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Shock)
    Wait(12 * DT)
    Call(SetNpcImgFXParams, NPC_KoopaBros, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Idle)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_KoopaBros, ANIM_KoopaBros_Green_Talk, ANIM_KoopaBros_Green_Idle, 0, MSG_CH1_00D4)
    Call(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Walk)
    Call(InterpNpcYaw, NPC_KoopaBros, 45, 2)
    Call(PlaySoundAtNpc, NPC_KoopaBros, SOUND_RUN_AWAY_BUILDUP, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_KoopaBros, ANIM_KoopaBros_Green_Run)
    Call(SetNpcJumpscale, NPC_KoopaBros, Float(0.8))
    Call(GetNpcPos, NPC_KoopaBros, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_KoopaBros, LVar0, LVar1, LVar2, 8 * DT)
    Wait(8 * DT)
    Call(PlaySoundAtNpc, NPC_KoopaBros, SOUND_RUN_AWAY, SOUND_SPACE_DEFAULT)
    Call(SetNpcSpeed, NPC_KoopaBros, Float(8.0 / DT))
    Call(NpcMoveTo, NPC_KoopaBros, -300, 70, 0)
    Set(GB_StoryProgress, STORY_CH1_KOOPA_BROS_HID_KEY)
    Call(RemoveNpc, NPC_KoopaBros)
    Call(DisablePlayerInput, FALSE)
    Exec(N(EVS_EndKoopaBrosTheme))
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopaBros) = {
    IfGe(GB_StoryProgress, STORY_CH1_KOOPA_BROS_HID_KEY)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcIdle_KoopaTroopa_01) = {
    Label(0)
    Wait(1)
    IfLt(GB_StoryProgress, STORY_CH1_KOOPA_BROS_HID_KEY)
        Goto(0)
    EndIf
    Wait(10)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaTroopa_Walk)
    Wait(10)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_KoopaTroopa_Wander)))
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopaTroopa_01) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_KoopaTroopa_01)))
    Return
    End
};

EvtScript N(EVS_NpcIdle_KoopaTroopa_02) = {
    Label(0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Wait(1)
    IfLt(LVar0, -150)
        Goto(0)
    EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaTroopa_Salute)
    Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 15)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaTroopa_Walk)
    Label(1)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Wait(1)
    IfLt(LVar0, -100)
        Goto(1)
    EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaTroopa_Run)
    Call(SetNpcSpeed, NPC_SELF, Float(7.0))
    Call(NpcMoveTo, NPC_SELF, 35, -130, 0)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Call(NpcMoveTo, NPC_SELF, 90, -130, 0)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(NpcMoveTo, NPC_SELF, 105, 10, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaTroopa_Walk)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_KoopaTroopa_Wander)))
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopaTroopa_02) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_KoopaTroopa_02)))
    Return
    End
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
