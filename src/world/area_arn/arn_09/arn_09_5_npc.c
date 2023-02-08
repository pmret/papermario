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
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_TubbasHeart_Anim13)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.5))
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20C8, SOUND_SPACE_MODE_0)
    EVT_CALL(NpcJump0, NPC_SELF, 0, 25, -10, 6)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2086, SOUND_SPACE_MODE_0)
    EVT_CALL(N(PlaySpringAnimation))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_TubbasHeart_Anim13)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.5))
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20C8, SOUND_SPACE_MODE_0)
    EVT_CALL(NpcJump0, NPC_SELF, 0, 200, 0, 15)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_SET(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WELL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TubbasHeart) = {
    EVT_IF_NE(GB_StoryProgress, STORY_CH3_HEART_FLED_SECOND_TUNNEL)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_ELSE
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TubbasHeart)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_TubbasHeart) = {
    .id = NPC_TubbasHeart,
    .settings = &N(NpcSettings_TubbasHeart),
    .pos = { 0.0f, 25.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_TubbasHeart),
    .drops = TUBBAS_HEART_DROPS,
    .animations = TUBBAS_HEART_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_TubbasHeart)),
    {}
};
