#include "jan_16.h"
#include "effects.h"
#include "sprite/player.h"

EvtScript N(EVS_NpcAuxAI_RaphaelRaven) = {
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.5), EVT_FLOAT(1.5), EVT_FLOAT(1.5))
    EVT_RETURN
    EVT_END
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
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_REACHED_RAPHAELS_TREE)
        EVT_CALL(EnableGroup, MODEL_g38, FALSE)
        EVT_CALL(EnableGroup, MODEL_g54, FALSE)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(SetCamType, CAM_DEFAULT, 1, FALSE)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -269, 94, -8)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -269, 94, -8)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 1000)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 20, 0)
        EVT_CALL(SetCamPosA, CAM_DEFAULT, -410, -85)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_WAIT(10)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, -13, 1)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.45 / DT))
        EVT_CALL(SetCamPosA, CAM_DEFAULT, -207, -85)
        EVT_CALL(PanToTarget, CAM_DEFAULT, EVT_FLOAT(0.8), 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_WAIT(30 * DT)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_SET(GB_StoryProgress, STORY_CH5_REACHED_RAPHAELS_TREE)
    EVT_END_IF
    EVT_CALL(EnableGroup, MODEL_g38, TRUE)
    EVT_CALL(EnableGroup, MODEL_g54, TRUE)
    EVT_CALL(EnableGroup, MODEL_g39, FALSE)
    EVT_CALL(EnableGroup, MODEL_g56, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Raven) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_00E3)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Raven) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_RAPHAEL_LEFT_NEST)
            EVT_GOTO(20)
        EVT_CASE_RANGE(STORY_CH5_RAPHAEL_LEFT_NEST, STORY_CH5_RAPHAEL_MOVED_ROOT)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Raven)))
            EVT_CALL(GetSelfNpcID, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(SetNpcPos, NPC_Raven_01, -450, 0, 26)
                EVT_CALL(SetNpcPos, NPC_Raven_02, -430, 0, 4)
                EVT_CALL(SetNpcPos, NPC_Raven_03, -410, 0, -18)
                EVT_CALL(SetNpcPos, NPC_Raven_04, -390, 0, -40)
                EVT_CALL(SetNpcPos, NPC_Raven_05, -411, 93, -16)
            EVT_END_IF
        EVT_CASE_GT(STORY_CH5_RAPHAEL_MOVED_ROOT)
            EVT_LABEL(20)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o113, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_RaphaelRaven) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o130, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Idle)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 4)
    EVT_WAIT(5 * DT)
    EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(4.5 / DT), LVar0, LVar1, LVar2, 450, EVT_FLOAT(20.0), EVT_FLOAT(-9.5))
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Jump)
        EVT_WAIT(8 * DT)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Fall)
        EVT_WAIT(15 * DT)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeetAngry)
        EVT_WAIT(10 * DT)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeetAngry, ANIM_RaphaelRaven_TalkNoFeetAngry, 5, MSG_CH5_00E1)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_IdleNoFeet)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Idle)
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_SELF, 2)
    EVT_CALL(NpcJump1, NPC_SELF, LVar0, LVar1, LVar2, 30)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_JAN_RAPHAEL_POUND, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 50, EVT_FLOAT(1.0))
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_END_THREAD
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_LOOP(10)
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 115, 0, 355, 0)
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 205, 0, 475, 0)
            EVT_WAIT(2)
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 190, 0, 445, 0)
            EVT_WAIT(2)
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 140, 0, 380, 0)
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 170, 0, 400, 0)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_LOOP(15)
        EVT_CALL(ScaleGroup, MODEL_g40, 1, EVT_FLOAT(1.05), 1)
        EVT_WAIT(2)
        EVT_CALL(ScaleGroup, MODEL_g40, 1, EVT_FLOAT(0.95), 1)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(MakeLerp, 0, 100, 100, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_g40, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 1)
        EVT_LOOP(6)
            EVT_SWITCH(LVar0)
                EVT_CASE_RANGE(1, 4)
                    EVT_CALL(PlaySoundAtCollider, COLLIDER_o97, SOUND_JAN_ROOT_WOBBLE_1, 0)
                EVT_CASE_EQ(5)
                    EVT_CALL(PlaySoundAtCollider, COLLIDER_o97, SOUND_JAN_ROOT_WOBBLE_2, 0)
                EVT_CASE_EQ(6)
                    EVT_CALL(PlaySoundAtCollider, COLLIDER_o97, SOUND_JAN_ROOT_WOBBLE_3, 0)
            EVT_END_SWITCH
            EVT_ADD(LVar0, 1)
            EVT_WAIT(20)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SETF(LVar2, EVT_FLOAT(1.0))
    EVT_SETF(LVar3, EVT_FLOAT(0.25))
    EVT_LOOP(5)
        EVT_LOOP(10)
            EVT_ADDF(LVar2, LVar3)
            EVT_CALL(ScaleGroup, MODEL_g40, 1, LVar2, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 123, 0, 352, 0)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 193, 0, 450, 0)
        EVT_LOOP(10)
            EVT_SUBF(LVar2, LVar3)
            EVT_CALL(ScaleGroup, MODEL_g40, 1, LVar2, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 115, 0, 355, 0)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 205, 0, 475, 0)
        EVT_SUBF(LVar3, EVT_FLOAT(0.05))
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o97, COLLIDER_FLAGS_UPPER_MASK)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_Talk, ANIM_RaphaelRaven_Idle, 0, MSG_CH5_00E2)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Walk)
    EVT_CALL(SetNpcSpeed, NPC_RaphaelRaven, EVT_FLOAT(4.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_SELF, 340, 270, 0)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
#if VERSION_PAL
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5 * DT))
#else
    EVT_CALL(ResetCam, CAM_DEFAULT, 5)
#endif
    EVT_SET(GB_StoryProgress, STORY_CH5_RAPHAEL_MOVED_ROOT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_RaphaelRaven) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_RAPHAEL_LEFT_NEST)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EVT_CALL(SetNpcPos, NPC_SELF, 85, 0, 410)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_RaphaelRaven)))
        EVT_RETURN
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o130, COLLIDER_FLAGS_UPPER_MASK)
        EVT_IF_GE(GB_StoryProgress, STORY_CH5_RAPHAEL_MOVED_ROOT)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o97, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(TranslateGroup, MODEL_g40, 0, 100, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
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
