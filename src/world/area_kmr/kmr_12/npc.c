#include "kmr_12.h"
#include "entity.h"

#include "world/common/enemy/Goomba_Wander.inc.c"

API_CALLABLE(N(GetAmbushEnemy)) {
    script->varTablePtr[0] = get_enemy_safe(NPC_Goomba_Ambush);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_OnReadBillboard) = {
    SetGroup(EVT_GROUP_00)
    SuspendGroup(EVT_GROUP_01)
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Menus_Sign_EatMushroomsTrap, 160, 40)
    ResumeGroup(EVT_GROUP_01)
    Set(LFlag0, FALSE)
    Call(N(GetAmbushEnemy))
    IfNe(LVar0, NULL)
        Call(GetNpcVar, NPC_Goomba_Ambush, 0, LVar0)
        IfEq(LVar0, 0)
            Call(SetNpcVar, NPC_Goomba_Ambush, 0, 1)
            Set(LFlag0, TRUE)
            Wait(10)
        EndIf
    EndIf
    Call(DisablePlayerInput, FALSE)
    IfEq(LFlag0, TRUE)
        Unbind
    EndIf
    End
    Return //@bug wrong order for END/RETURN
};

EvtScript N(EVS_NpcIdle_Goomba) = {
    Wait(1)
    Call(SetSelfVar, 0, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Goomba_FakeMushroom)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, 1)
    Label(0)
        Call(GetSelfVar, 0, LVar0)
        Wait(1)
        IfEq(LVar0, 0)
            Goto(0)
        EndIf
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_CAMERA_FOR_YAW | NPC_FLAG_FLIP_INSTANTLY, TRUE)
    Wait(3)
    SetF(LVar0, Float(0.0))
    Loop(9)
        AddF(LVar0, Float(10.0))
        Call(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(SetNpcAnimation, NPC_SELF, ANIM_Goomba_Still)
    Loop(9)
        AddF(LVar0, Float(10.0))
        Call(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(SetNpcAnimation, NPC_SELF, ANIM_Goomba_Dizzy)
    Wait(20)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Goomba_Idle)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_FLIP_PAGE, SOUND_SPACE_DEFAULT)
    Call(SetNpcImgFXFlags, NPC_SELF, IMGFX_FLAG_2000)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_ANIM, IMGFX_ANIM_UNFURL, 1, 1, 0)
    Wait(12)
    Wait(5)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(EnableNpcShadow, NPC_SELF, TRUE)
    Call(SetNpcJumpscale, NPC_SELF, Float(0.6))
    Call(NpcJump0, NPC_SELF, -35, 0, 30, 23)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_CAMERA_FOR_YAW | NPC_FLAG_FLIP_INSTANTLY, FALSE)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, 0)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, 1)
    BindTrigger(Ref(N(EVS_OnReadBillboard)), TRIGGER_WALL_PRESS_A, COLLIDER_o78, 1, 0)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_Goomba_Wander)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Goomba) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Goomba)))
    Return
    End
};

NpcData N(NpcData_Goomba) = {
    .id = NPC_Goomba_Ambush,
    .pos = { -33.0f, 30.0f, -25.0f },
    .yaw = 90,
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
    .init = &N(EVS_NpcInit_Goomba),
    .settings = &N(NpcSettings_Goomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = GOOMBA_DROPS,
    .animations = GOOMBA_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Goomba), BTL_KMR_1_FORMATION_01, BTL_KMR_1_STAGE_02),
    {}
};
