#include "jan_16.h"
#include "effects.h"
#include "sprite/player.h"

EvtScript N(EVS_NpcAuxAI_RaphaelRaven) = {
    Call(SetNpcScale, NPC_SELF, Float(1.5), Float(1.5), Float(1.5))
    Return
    End
};

NpcSettings N(NpcSettings_RaphaelRaven) = {
    .height = 98,
    .radius = 80,
    .level = ACTOR_LEVEL_NONE,
    .otherAI = &N(EVS_NpcAuxAI_RaphaelRaven),
};

NpcSettings N(NpcSettings_Raven) = {
    .height = 26,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

EvtScript N(D_802412D4_B812D4) = {
    Call(DisablePlayerInput, TRUE)
    IfLt(GB_StoryProgress, STORY_CH5_REACHED_RAPHAELS_TREE)
        Call(EnableGroup, MODEL_g38, FALSE)
        Call(EnableGroup, MODEL_g54, FALSE)
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
        Call(SetCamType, CAM_DEFAULT, 1, FALSE)
        Call(UseSettingsFrom, CAM_DEFAULT, -269, 94, -8)
        Call(SetPanTarget, CAM_DEFAULT, -269, 94, -8)
        Call(SetCamDistance, CAM_DEFAULT, 1000)
        Call(SetCamPitch, CAM_DEFAULT, 20, 0)
        Call(SetCamPosA, CAM_DEFAULT, -410, -85)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Wait(10)
        Call(SetCamDistance, CAM_DEFAULT, 400)
        Call(SetCamPitch, CAM_DEFAULT, -13, 1)
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.45 / DT))
        Call(SetCamPosA, CAM_DEFAULT, -207, -85)
        Call(PanToTarget, CAM_DEFAULT, Float(0.8), 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Wait(30 * DT)
        Call(ResetCam, CAM_DEFAULT, Float(90.0))
        Set(GB_StoryProgress, STORY_CH5_REACHED_RAPHAELS_TREE)
    EndIf
    Call(EnableGroup, MODEL_g38, TRUE)
    Call(EnableGroup, MODEL_g54, TRUE)
    Call(EnableGroup, MODEL_g39, FALSE)
    Call(EnableGroup, MODEL_g56, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Raven) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_00E3)
    Return
    End
};

EvtScript N(EVS_NpcInit_Raven) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_RAPHAEL_LEFT_NEST)
            Goto(20)
        CaseRange(STORY_CH5_RAPHAEL_LEFT_NEST, STORY_CH5_RAPHAEL_MOVED_ROOT)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Raven)))
            Call(GetSelfNpcID, LVar0)
            IfEq(LVar0, 1)
                Call(SetNpcPos, NPC_Raven_01, -450, 0, 26)
                Call(SetNpcPos, NPC_Raven_02, -430, 0, 4)
                Call(SetNpcPos, NPC_Raven_03, -410, 0, -18)
                Call(SetNpcPos, NPC_Raven_04, -390, 0, -40)
                Call(SetNpcPos, NPC_Raven_05, -411, 93, -16)
            EndIf
        CaseGt(STORY_CH5_RAPHAEL_MOVED_ROOT)
            Label(20)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o113, COLLIDER_FLAGS_UPPER_MASK)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_RaphaelRaven) = {
    Call(DisablePlayerInput, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o130, COLLIDER_FLAGS_UPPER_MASK)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Idle)
    Call(NpcFacePlayer, NPC_SELF, 4)
    Wait(5 * DT)
    Call(PlayerFaceNpc, NPC_SELF, FALSE)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(SetCamProperties, CAM_DEFAULT, Float(4.5 / DT), LVar0, LVar1, LVar2, 450, Float(20.0), Float(-9.5))
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Wait(10 * DT)
    Call(InterpPlayerYaw, 90, 0)
    Wait(20 * DT)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Thread
        Call(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Jump)
        Wait(8 * DT)
        Call(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Fall)
        Wait(15 * DT)
        Call(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeetAngry)
        Wait(10 * DT)
        Call(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeetAngry, ANIM_RaphaelRaven_TalkNoFeetAngry, 5, MSG_CH5_00E1)
        Call(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_IdleNoFeet)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Idle)
    EndThread
    Call(SetNpcJumpscale, NPC_SELF, 2)
    Call(NpcJump1, NPC_SELF, LVar0, LVar1, LVar2, 30)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_JAN_RAPHAEL_POUND, SOUND_SPACE_DEFAULT)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 50, Float(1.0))
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    EndThread
    Call(SetPlayerAnimation, ANIM_Mario1_Flail)
    Thread
        Wait(20)
        Loop(10)
            PlayEffect(EFFECT_LANDING_DUST, 1, 115, 0, 355, 0)
            PlayEffect(EFFECT_LANDING_DUST, 1, 205, 0, 475, 0)
            Wait(2)
            PlayEffect(EFFECT_LANDING_DUST, 1, 190, 0, 445, 0)
            Wait(2)
            PlayEffect(EFFECT_LANDING_DUST, 1, 140, 0, 380, 0)
            PlayEffect(EFFECT_LANDING_DUST, 1, 170, 0, 400, 0)
            Wait(2)
        EndLoop
    EndThread
    Loop(15)
        Call(ScaleGroup, MODEL_g40, 1, Float(1.05), 1)
        Wait(2)
        Call(ScaleGroup, MODEL_g40, 1, Float(0.95), 1)
        Wait(2)
    EndLoop
    Thread
        Wait(15)
        Call(MakeLerp, 0, 100, 100, EASING_QUADRATIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_g40, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Set(LVar0, 1)
        Loop(6)
            Switch(LVar0)
                CaseRange(1, 4)
                    Call(PlaySoundAtCollider, COLLIDER_o97, SOUND_JAN_ROOT_WOBBLE_1, 0)
                CaseEq(5)
                    Call(PlaySoundAtCollider, COLLIDER_o97, SOUND_JAN_ROOT_WOBBLE_2, 0)
                CaseEq(6)
                    Call(PlaySoundAtCollider, COLLIDER_o97, SOUND_JAN_ROOT_WOBBLE_3, 0)
            EndSwitch
            Add(LVar0, 1)
            Wait(20)
        EndLoop
    EndThread
    SetF(LVar2, Float(1.0))
    SetF(LVar3, Float(0.25))
    Loop(5)
        Loop(10)
            AddF(LVar2, LVar3)
            Call(ScaleGroup, MODEL_g40, 1, LVar2, 1)
            Wait(1)
        EndLoop
        PlayEffect(EFFECT_LANDING_DUST, 1, 123, 0, 352, 0)
        PlayEffect(EFFECT_LANDING_DUST, 1, 193, 0, 450, 0)
        Loop(10)
            SubF(LVar2, LVar3)
            Call(ScaleGroup, MODEL_g40, 1, LVar2, 1)
            Wait(1)
        EndLoop
        PlayEffect(EFFECT_LANDING_DUST, 1, 115, 0, 355, 0)
        PlayEffect(EFFECT_LANDING_DUST, 1, 205, 0, 475, 0)
        SubF(LVar3, Float(0.05))
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o97, COLLIDER_FLAGS_UPPER_MASK)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_Talk, ANIM_RaphaelRaven_Idle, 0, MSG_CH5_00E2)
    Call(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Walk)
    Call(SetNpcSpeed, NPC_RaphaelRaven, Float(4.0 / DT))
    Call(NpcMoveTo, NPC_SELF, 340, 270, 0)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
#if VERSION_PAL
    Call(ResetCam, CAM_DEFAULT, Float(5 * DT))
#else
    Call(ResetCam, CAM_DEFAULT, 5)
#endif
    Set(GB_StoryProgress, STORY_CH5_RAPHAEL_MOVED_ROOT)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_RaphaelRaven) = {
    IfEq(GB_StoryProgress, STORY_CH5_RAPHAEL_LEFT_NEST)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        Call(SetNpcPos, NPC_SELF, 85, 0, 410)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_RaphaelRaven)))
        Return
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o130, COLLIDER_FLAGS_UPPER_MASK)
        IfGe(GB_StoryProgress, STORY_CH5_RAPHAEL_MOVED_ROOT)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o97, COLLIDER_FLAGS_UPPER_MASK)
            Call(TranslateGroup, MODEL_g40, 0, 100, 0)
        EndIf
    EndIf
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

NpcData N(NpcData_RaphaelRaven)[] = {
    {
        .id = NPC_RaphaelRaven,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RaphaelRaven),
        .settings = &N(NpcSettings_RaphaelRaven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_RaphaelRaven_Idle,
            .walk   = ANIM_RaphaelRaven_Idle,
            .run    = ANIM_RaphaelRaven_Idle,
            .chase  = ANIM_RaphaelRaven_Idle,
            .anim_4 = ANIM_RaphaelRaven_Idle,
            .anim_5 = ANIM_RaphaelRaven_Idle,
            .death  = ANIM_RaphaelRaven_Idle,
            .hit    = ANIM_RaphaelRaven_Idle,
            .anim_8 = ANIM_RaphaelRaven_Idle,
            .anim_9 = ANIM_RaphaelRaven_Idle,
            .anim_A = ANIM_RaphaelRaven_Idle,
            .anim_B = ANIM_RaphaelRaven_Idle,
            .anim_C = ANIM_RaphaelRaven_Idle,
            .anim_D = ANIM_RaphaelRaven_Idle,
            .anim_E = ANIM_RaphaelRaven_Idle,
            .anim_F = ANIM_RaphaelRaven_Idle,
        },
        .tattle = MSG_NpcTattle_RaphaelRaven,
    },
    {
        .id = NPC_Raven_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Raven),
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Raven_Idle,
            .walk   = ANIM_Raven_Idle,
            .run    = ANIM_Raven_Idle,
            .chase  = ANIM_Raven_Idle,
            .anim_4 = ANIM_Raven_Idle,
            .anim_5 = ANIM_Raven_Idle,
            .death  = ANIM_Raven_Idle,
            .hit    = ANIM_Raven_Idle,
            .anim_8 = ANIM_Raven_Idle,
            .anim_9 = ANIM_Raven_Idle,
            .anim_A = ANIM_Raven_Idle,
            .anim_B = ANIM_Raven_Idle,
            .anim_C = ANIM_Raven_Idle,
            .anim_D = ANIM_Raven_Idle,
            .anim_E = ANIM_Raven_Idle,
            .anim_F = ANIM_Raven_Idle,
        },
        .tattle = MSG_NpcTattle_RavenA,
    },
    {
        .id = NPC_Raven_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Raven),
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Raven_Idle,
            .walk   = ANIM_Raven_Idle,
            .run    = ANIM_Raven_Idle,
            .chase  = ANIM_Raven_Idle,
            .anim_4 = ANIM_Raven_Idle,
            .anim_5 = ANIM_Raven_Idle,
            .death  = ANIM_Raven_Idle,
            .hit    = ANIM_Raven_Idle,
            .anim_8 = ANIM_Raven_Idle,
            .anim_9 = ANIM_Raven_Idle,
            .anim_A = ANIM_Raven_Idle,
            .anim_B = ANIM_Raven_Idle,
            .anim_C = ANIM_Raven_Idle,
            .anim_D = ANIM_Raven_Idle,
            .anim_E = ANIM_Raven_Idle,
            .anim_F = ANIM_Raven_Idle,
        },
        .tattle = MSG_NpcTattle_RavenB,
    },
    {
        .id = NPC_Raven_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Raven),
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Raven_Idle,
            .walk   = ANIM_Raven_Idle,
            .run    = ANIM_Raven_Idle,
            .chase  = ANIM_Raven_Idle,
            .anim_4 = ANIM_Raven_Idle,
            .anim_5 = ANIM_Raven_Idle,
            .death  = ANIM_Raven_Idle,
            .hit    = ANIM_Raven_Idle,
            .anim_8 = ANIM_Raven_Idle,
            .anim_9 = ANIM_Raven_Idle,
            .anim_A = ANIM_Raven_Idle,
            .anim_B = ANIM_Raven_Idle,
            .anim_C = ANIM_Raven_Idle,
            .anim_D = ANIM_Raven_Idle,
            .anim_E = ANIM_Raven_Idle,
            .anim_F = ANIM_Raven_Idle,
        },
        .tattle = MSG_NpcTattle_RavenC,
    },
    {
        .id = NPC_Raven_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Raven),
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Raven_Idle,
            .walk   = ANIM_Raven_Idle,
            .run    = ANIM_Raven_Idle,
            .chase  = ANIM_Raven_Idle,
            .anim_4 = ANIM_Raven_Idle,
            .anim_5 = ANIM_Raven_Idle,
            .death  = ANIM_Raven_Idle,
            .hit    = ANIM_Raven_Idle,
            .anim_8 = ANIM_Raven_Idle,
            .anim_9 = ANIM_Raven_Idle,
            .anim_A = ANIM_Raven_Idle,
            .anim_B = ANIM_Raven_Idle,
            .anim_C = ANIM_Raven_Idle,
            .anim_D = ANIM_Raven_Idle,
            .anim_E = ANIM_Raven_Idle,
            .anim_F = ANIM_Raven_Idle,
        },
        .tattle = MSG_NpcTattle_RavenD,
    },
    {
        .id = NPC_Raven_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Raven),
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Raven_Idle,
            .walk   = ANIM_Raven_Idle,
            .run    = ANIM_Raven_Idle,
            .chase  = ANIM_Raven_Idle,
            .anim_4 = ANIM_Raven_Idle,
            .anim_5 = ANIM_Raven_Idle,
            .death  = ANIM_Raven_Idle,
            .hit    = ANIM_Raven_Idle,
            .anim_8 = ANIM_Raven_Idle,
            .anim_9 = ANIM_Raven_Idle,
            .anim_A = ANIM_Raven_Idle,
            .anim_B = ANIM_Raven_Idle,
            .anim_C = ANIM_Raven_Idle,
            .anim_D = ANIM_Raven_Idle,
            .anim_E = ANIM_Raven_Idle,
            .anim_F = ANIM_Raven_Idle,
        },
        .tattle = MSG_NpcTattle_RavenE,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_RaphaelRaven)),
    {}
};
