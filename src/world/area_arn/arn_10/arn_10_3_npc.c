#include "arn_10.h"

#include "world/common/npc/TubbasHeart.inc.c"
#include "world/common/enemy/HyperGoomba_Wander.inc.c"

EvtScript N(EVS_NpcIdle_TubbasHeart) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_TubbasHeart_Anim13)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(3.0))
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 30)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 8)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_TubbasHeart_Anim14)
    EVT_WAIT(1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_TubbasHeart_Anim13)
    EVT_SUB(LVar0, 80)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.5))
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 12)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_TubbasHeart_Anim14)
    EVT_WAIT(1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_TubbasHeart_Anim13)
    EVT_SUB(LVar0, 80)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.5))
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 12)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_SET(GB_StoryProgress, STORY_CH3_HEART_FLED_SECOND_TUNNEL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_HyperGoomba) = {
    EVT_SET(GF_ARN10_Defeated_Goomba, TRUE)
    EVT_CALL(DoNpcDefeat)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TubbasHeart) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TubbasHeart)))
    EVT_IF_NE(GB_StoryProgress, STORY_UNUSED_FFFFFFEC)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_HyperGoomba) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_FRYING_PAN_STOLEN)
        EVT_IF_EQ(GF_ARN10_Defeated_Goomba, TRUE)
            EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_HyperGoomba)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
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
    NPC_GROUP(N(NpcData_HyperGoomba), BTL_ARN_FORMATION_00, BTL_ARN_STAGE_04),
    {}
};
