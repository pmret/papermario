#include "kmr_09.h"
#include "entity.h"

#include "world/common/enemy/Goomba_Wander.inc.c"
#include "world/common/enemy/Paragoomba_Wander.inc.c"

NpcData N(NpcData_Goomba_01) = {
    .id = NPC_Goomba_01,
    .pos = { 200.0f, 0.0f, 24.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 200, 0, 24 },
            .wanderSize = { 30, 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 200, 0, 24 },
            .detectSize = { 250 },
        }
    },
    .settings = &N(NpcSettings_Goomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = GOOMBA_DROPS,
    .animations = GOOMBA_ANIMS,
};

NpcData N(NpcData_Goomba_02) = {
    .id = NPC_Goomba_02,
    .pos = { 250.0f, 0.0f, 35.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 250, 0, 35 },
            .wanderSize = { 30, 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 250, 0, 35 },
            .detectSize = { 250 },
        }
    },
    .settings = &N(NpcSettings_Goomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = GOOMBA_DROPS,
    .animations = GOOMBA_ANIMS,
};

API_CALLABLE(N(GetAmbushEnemy)) {
    script->varTablePtr[0] = get_enemy_safe(NPC_Goomba_Ambush);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_OnReadBillboard) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    SuspendGroup(EVT_GROUP_FLAG_INTERACT)
    Call(DisablePlayerInput, true)
    Call(ShowMessageAtScreenPos, MSG_Menus_Sign_BewareOfGoombas, 160, 40)
    ResumeGroup(EVT_GROUP_FLAG_INTERACT)
    Set(LFlag0, false)
    Call(N(GetAmbushEnemy))
    IfNe(LVar0, NULL)
        Call(GetNpcVar, NPC_Goomba_Ambush, 0, LVar0)
        IfEq(LVar0, 0)
            Call(SetNpcVar, NPC_Goomba_Ambush, 0, 1)
            Set(LFlag0, true)
            Wait(10)
        EndIf
    EndIf
    Call(DisablePlayerInput, false)
    IfEq(LFlag0, true)
        Unbind
    EndIf
    End
    Return //@bug wrong order for END/RETURN
};

EvtScript N(EVS_NpcIdle_Goomba_Ambush) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_Goomba_Still)
    Call(EnableNpcShadow, NPC_SELF, false)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, true)
    Label(0)
    Call(GetSelfVar, 0, LVar0)
    IfEq(LVar0, 0)
        Wait(1)
        Goto(0)
    EndIf
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_FLIP_PAGE, SOUND_SPACE_DEFAULT)
    Call(SetNpcImgFXFlags, NPC_SELF, IMGFX_FLAG_2000)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_ANIM, IMGFX_ANIM_UNFURL, 1, 1, 0)
    Wait(15)
    Call(SetNpcImgFXFlags, NPC_SELF, IMGFX_FLAG_2000)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_RESET, 0, 0, 0, 0)
    Thread
        Wait(2)
        SetF(LVar0, Float(0.0))
        Loop(20)
            AddF(LVar0, Float(18.0))
            Call(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
            Wait(1)
        EndLoop
        Call(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EndThread
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(EnableNpcShadow, NPC_SELF, true)
    Call(SetNpcJumpscale, NPC_SELF, Float(0.6))
    Call(NpcJump0, NPC_SELF, -35, 0, 25, 23)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_NO_SHADOW_RAYCAST, true)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, false)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, true)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, false)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, true)
    BindTrigger(Ref(N(EVS_OnReadBillboard)), TRIGGER_WALL_PRESS_A, COLLIDER_kan, 1, 0)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_Goomba_Wander)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Goomba_Ambush) = {
    Call(EnableNpcShadow, NPC_SELF, false)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Goomba_Ambush)))
    Return
    End
};

NpcData N(NpcData_Goomba_Ambush) = {
    .id = NPC_Goomba_Ambush,
    .pos = { -34.0f, 29.0f, -32.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { -20, 0, 10 },
            .wanderSize = { 30, 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -20, 0, 10 },
            .detectSize = { 250 },
        }
    },
    .init = &N(EVS_NpcInit_Goomba_Ambush),
    .settings = &N(NpcSettings_Goomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = GOOMBA_DROPS,
    .animations = GOOMBA_ANIMS,
};

NpcData N(NpcData_Paragoomba) = {
    .id = NPC_Paragoomba,
    .pos = { 670.0f, 60.0f, 20.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 670, 60, 20 },
            .wanderSize = { 30, 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 670, 60, 20 },
            .detectSize = { 250 },
        }
    },
    .settings = &N(NpcSettings_Paragoomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = PARAGOOMBA_DROPS,
    .animations = PARAGOOMBA_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Goomba_01), BTL_KMR_1_FORMATION_01, BTL_KMR_1_STAGE_02),
    NPC_GROUP(N(NpcData_Goomba_02), BTL_KMR_1_FORMATION_01, BTL_KMR_1_STAGE_02),
    NPC_GROUP(N(NpcData_Goomba_Ambush), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_02),
    NPC_GROUP(N(NpcData_Paragoomba), BTL_KMR_1_FORMATION_08, BTL_KMR_1_STAGE_02),
    {}
};
