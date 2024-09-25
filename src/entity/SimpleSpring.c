#include "common.h"
#include "entity.h"
#include "animation_script.h"
#include "ld_addrs.h"

extern StaticAnimatorNode* Entity_ScriptSpring_Mesh[];
extern AnimScript Entity_ScriptSpring_AnimLaunch;
extern AnimScript Entity_ScriptSpring_AnimIdle;
extern StaticAnimatorNode* Entity_SimpleSpring_Mesh[];
extern AnimScript Entity_SimpleSpring_AnimLaunch;
extern AnimScript Entity_SimpleSpring_AnimIdle;

void entity_ScriptSpring_idle(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->actionState != ACTION_STATE_RIDE && (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR)) {
        playerStatus->camResetDelay = 5;
        playerStatus->flags &= ~PS_FLAG_FALLING;
        playerStatus->flags |= PS_FLAG_SCRIPTED_FALL;
        play_model_animation(entity->virtualModelIndex, Entity_ScriptSpring_AnimLaunch);
        if (entity_start_script(entity)) {
            set_action_state(ACTION_STATE_USE_SPRING);
        }
        exec_entity_commandlist(entity);
        sfx_play_sound_at_position(SOUND_SPRING, SOUND_SPACE_DEFAULT, entity->pos.x, entity->pos.y, entity->pos.z);
    }
}

void entity_SimpleSpring_idle(Entity* entity) {
    SimpleSpringData* data = entity->dataBuf.simpleSpring;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->actionState != ACTION_STATE_RIDE && (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR)) {
        if (data->launchVel >= 70) {
            playerStatus->camResetDelay = 5;
        }
        play_model_animation(entity->virtualModelIndex, Entity_SimpleSpring_AnimLaunch);
        entity_start_script(entity);
        exec_entity_commandlist(entity);
        sfx_play_sound_at_position(SOUND_SPRING, SOUND_SPACE_DEFAULT, entity->pos.x, entity->pos.y, entity->pos.z);
        disable_player_input();
        playerStatus->curSpeed = 0;
    }
}

void entity_SimpleSpring_set_jump_params(Entity* entity) {
    SimpleSpringData* data = entity->dataBuf.simpleSpring;

    set_action_state(ACTION_STATE_LAUNCH);
    gPlayerStatus.gravityIntegrator[0] = 15.0f;
    gPlayerStatus.gravityIntegrator[1] = 0;
    gPlayerStatus.gravityIntegrator[2] = data->launchVel;
    gPlayerStatus.gravityIntegrator[3] = entity->pos.y;
}

void entity_SimpleSpring_enable_player_input(Entity* ent) {
    enable_player_input();
}

void entity_ScriptSpring_init(Entity* entity) {
}

void entity_SimpleSpring_init(Entity* entity) {
    entity->dataBuf.simpleSpring->launchVel = CreateEntityVarArgBuffer[0];
}

EntityScript Entity_ScriptSpring_Script = {
    es_SetCallback(entity_ScriptSpring_idle, 0)
    es_SetCallback(NULL, 10)
    es_Restart
    es_End
};

EntityScript Entity_SimpleSpring_Script = {
    es_SetCallback(entity_SimpleSpring_idle, 0)
    es_SetCallback(NULL, 2)
    es_Call(entity_SimpleSpring_set_jump_params)
    es_SetCallback(NULL, 3)
    es_Call(entity_SimpleSpring_enable_player_input)
    es_SetCallback(NULL, 10)
    es_Restart
    es_End
};

DmaEntry Entity_ScriptSpring_dma[] = { ENTITY_ROM(ScriptSpring_gfx), ENTITY_ROM(ScriptSpring_anim) };

DmaEntry Entity_SimpleSpring_dma[] = { ENTITY_ROM(SimpleSpring_gfx), ENTITY_ROM(SimpleSpring_anim) };

EntityBlueprint Entity_ScriptSpring = {
    .flags = ENTITY_FLAG_ALWAYS_FACE_CAMERA | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = 0,
    .renderCommandList = Entity_ScriptSpring_AnimIdle,
    .modelAnimationNodes = Entity_ScriptSpring_Mesh,
    .fpInit = entity_ScriptSpring_init,
    .updateEntityScript = Entity_ScriptSpring_Script,
    .fpHandleCollision = NULL,
    { .dmaList = Entity_ScriptSpring_dma },
    .entityType = ENTITY_TYPE_SCRIPT_SPRING,
    .aabbSize = {40, 25, 40}
};

EntityBlueprint Entity_SimpleSpring = {
    .flags = ENTITY_FLAG_ALWAYS_FACE_CAMERA | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = sizeof(SimpleSpringData),
    .renderCommandList = Entity_SimpleSpring_AnimIdle,
    .modelAnimationNodes = Entity_SimpleSpring_Mesh,
    .fpInit = entity_SimpleSpring_init,
    .updateEntityScript = Entity_SimpleSpring_Script,
    .fpHandleCollision = NULL,
    { .dmaList = Entity_SimpleSpring_dma },
    .entityType = ENTITY_TYPE_SIMPLE_SPRING,
    .aabbSize = {40, 25, 40}
};
