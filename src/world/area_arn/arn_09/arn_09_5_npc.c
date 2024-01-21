#include "arn_09.h"
#include "entity.h"
#include "animation_script.h"

extern AnimScript Entity_ScriptSpring_AnimLaunch;

#include "world/common/npc/TubbasHeart.inc.c"

API_CALLABLE(N(PlaySpringAnimation)) {
    Entity* entity = get_entity_by_index(0);

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, Entity_ScriptSpring_AnimLaunch);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_TubbasHeart) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_TubbasHeart_Anim13)
    Call(SetNpcJumpscale, NPC_SELF, Float(2.5))
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, 0, 25, -10, 6 * DT)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_SPRING, SOUND_SPACE_DEFAULT)
    Call(N(PlaySpringAnimation))
    Call(SetNpcAnimation, NPC_SELF, ANIM_TubbasHeart_Anim13)
    Call(SetNpcJumpscale, NPC_SELF, Float(2.5))
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, 0, 200, 0, 15 * DT)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Set(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WELL)
    Return
    End
};

EvtScript N(EVS_NpcInit_TubbasHeart) = {
    IfNe(GB_StoryProgress, STORY_CH3_HEART_FLED_SECOND_TUNNEL)
        Call(RemoveNpc, NPC_SELF)
    Else
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_TubbasHeart)))
    EndIf
    Return
    End
};

NpcData N(NpcData_TubbasHeart) = {
    .id = NPC_TubbasHeart,
    .pos = { 0.0f, 25.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_TubbasHeart),
    .settings = &N(NpcSettings_TubbasHeart),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = TUBBAS_HEART_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_TubbasHeart)),
    {}
};
