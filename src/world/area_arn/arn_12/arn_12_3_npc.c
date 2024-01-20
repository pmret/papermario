#include "arn_12.h"

#include "world/common/npc/TubbasHeart.inc.c"
#include "world/common/enemy/HyperGoomba_Wander.inc.c"

EvtScript N(EVS_NpcIdle_TubbasHeart) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_TubbasHeart_Anim13)
    Call(SetNpcJumpscale, NPC_SELF, Float(3.0))
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 30)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 8)
    Call(SetNpcAnimation, NPC_SELF, ANIM_TubbasHeart_Anim14)
    Wait(1)
    Call(SetNpcAnimation, NPC_SELF, ANIM_TubbasHeart_Anim13)
    Sub(LVar0, 80)
    Call(SetNpcJumpscale, NPC_SELF, Float(2.5))
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 12)
    Call(SetNpcAnimation, NPC_SELF, ANIM_TubbasHeart_Anim14)
    Wait(1)
    Call(SetNpcAnimation, NPC_SELF, ANIM_TubbasHeart_Anim13)
    Sub(LVar0, 80)
    Call(SetNpcJumpscale, NPC_SELF, Float(2.5))
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 12)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Set(GB_StoryProgress, STORY_UNUSED_FFFFFFEC)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_HyperGoomba) = {
    Set(GF_ARN12_Defeated_Goomba, TRUE)
    Call(DoNpcDefeat)
    Return
    End
};

EvtScript N(EVS_NpcInit_TubbasHeart) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_TubbasHeart)))
    IfNe(GB_StoryProgress, STORY_UNUSED_FFFFFFEB)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_HyperGoomba) = {
    IfLt(GB_StoryProgress, STORY_CH4_FRYING_PAN_STOLEN)
        IfEq(GF_ARN12_Defeated_Goomba, TRUE)
            Call(RemoveNpc, NPC_SELF)
            Return
        EndIf
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_HyperGoomba)))
    EndIf
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_HyperGoomba)))
    Return
    End
};

NpcData N(NpcData_TubbasHeart) = {
    .id = NPC_TubbasHeart,
    .pos = { 80.0f, 50.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_TubbasHeart),
    .settings = &N(NpcSettings_TubbasHeart),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = TUBBAS_HEART_ANIMS,
};

NpcData N(NpcData_HyperGoomba) = {
    .id = NPC_HyperGoomba,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 150 },
        }
    },
    .init = &N(EVS_NpcInit_HyperGoomba),
    .settings = &N(NpcSettings_HyperGoomba),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = HYPER_GOOMBA_DROPS,
    .animations = HYPER_GOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_TubbasHeart)),
    NPC_GROUP(N(NpcData_HyperGoomba), BTL_ARN_FORMATION_01, BTL_ARN_STAGE_04),
    {}
};
