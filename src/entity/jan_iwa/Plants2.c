#include "common.h"
#include "effects.h"
#include "entity.h"
#include "animation_script.h"
#include "ld_addrs.h"
#include "sprite/player.h"

extern EntityBlueprint Entity_MunchlesiaReset;
extern EntityBlueprint Entity_MunchlesiaGrab;
extern EntityBlueprint Entity_MunchlesiaEnvelop;
extern EntityBlueprint Entity_MunchlesiaBeginChew;
extern EntityBlueprint Entity_MunchlesiaChewing;
extern EntityBlueprint Entity_MunchlesiaSpitOut;
extern EntityBlueprint Entity_MunchlesiaReset1;
extern EntityBlueprint Entity_MunchlesiaReset2;

extern EntityModelScript Entity_RenderNone_Script;

extern AnimScript Entity_BellbellPlant_AnimationIdle;
extern AnimScript Entity_BellbellPlant_AnimationUse;
extern StaticAnimatorNode* Entity_BellbellPlant_Mesh[];
extern AnimScript Entity_TrumpetPlant_AnimationIdle;
extern AnimScript Entity_TrumpetPlant_AnimationUse;
extern StaticAnimatorNode* Entity_TrumpetPlant_Mesh[];
extern AnimScript Entity_MunchlesiaReset_AnimationIdle;
extern AnimScript Entity_MunchlesiaReset_AnimationReset;
extern StaticAnimatorNode* Entity_MunchlesiaReset_Mesh[];
extern AnimScript Entity_MunchlesiaGrab_Animation;
extern StaticAnimatorNode* Entity_MunchlesiaGrab_Mesh[];
extern AnimScript Entity_MunchlesiaEnvelop_Animation;
extern StaticAnimatorNode* Entity_MunchlesiaEnvelop_Mesh[];
extern AnimScript Entity_MunchlesiaBeginChew_Animation;
extern StaticAnimatorNode* Entity_MunchlesiaBeginChew_Mesh[];
extern AnimScript Entity_MunchlesiaChewing_Animation;
extern StaticAnimatorNode* Entity_MunchlesiaChewing_Mesh[];
extern AnimScript Entity_MunchlesiaSpitOut_Animation;
extern StaticAnimatorNode* Entity_MunchlesiaSpitOut_Mesh[];
extern AnimScript Entity_MunchlesiaReset1_Animation;
extern StaticAnimatorNode* Entity_MunchlesiaReset1_Mesh[];

void entity_BellbellPlant_idle(Entity* entity) {
    if ((gPlayerStatus.animFlags & PA_FLAG_INTERACT_PROMPT_AVAILABLE) &&
        (entity->collisionFlags & (ENTITY_COLLISION_PLAYER_HAMMER | ENTITY_COLLISION_PLAYER_TOUCH_WALL))) {
        exec_entity_commandlist(entity);
        play_model_animation(entity->virtualModelIndex, Entity_BellbellPlant_AnimationUse);
    }
}

void entity_TrumpetPlant_idle(Entity* entity) {
    if ((gPlayerStatus.animFlags & PA_FLAG_INTERACT_PROMPT_AVAILABLE) &&
        (entity->collisionFlags & (ENTITY_COLLISION_PLAYER_HAMMER | ENTITY_COLLISION_PLAYER_TOUCH_WALL))) {
        exec_entity_commandlist(entity);
        play_model_animation(entity->virtualModelIndex, Entity_TrumpetPlant_AnimationUse);
    }
}

void entity_TrumpetPlant_create_effect(Entity* entity) {
    f32 xOffset, zOffset, angle;

    angle = DEG_TO_RAD(clamp_angle(entity->rot.y));
    xOffset = -26.0 * cos_rad(angle);
    zOffset = 6.0 * sin_rad(angle);
    fx_stars_burst(0, entity->pos.x + xOffset, entity->pos.y + 62.0f, entity->pos.z + zOffset, clamp_angle(entity->rot.y - 90.0), 54.0f, 2);
}

void entity_TrumpetPlant_spawn_coin(Entity* entity) {
    TrumpetPlantData* data = entity->dataBuf.trumpetPlant;

    entity_TrumpetPlant_create_effect(entity);
    if (data->numCoins < 3) {
        f32 xOffset, zOffset, angle;

        angle = DEG_TO_RAD(clamp_angle(entity->rot.y));
        xOffset = -26.0 * cos_rad(angle);
        zOffset = 6.0 * sin_rad(angle);

        if (rand_int(32) > 16) {
            f32 facingAngle = entity->rot.y - 110.0f + (data->numCoins % 3) * 30;
            data->numCoins++;
            make_item_entity(ITEM_COIN,
                             entity->pos.x + xOffset,
                             entity->pos.y + 62.0f,
                             entity->pos.z + zOffset,
                             ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0,
                             facingAngle, 0);
        }
    }
}

void entity_Munchlesia_init(Entity* entity) {
    make_item_entity_nodelay(ITEM_COIN, entity->pos.x, entity->pos.y + 30.0f, entity->pos.z,
        ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS_NEVER_VANISH, 0);
}

void func_802BC050_E2E980(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
        Entity* resetMunchlesia;
        gPlayerStatus.animFlags |= PA_FLAG_INTERRUPT_USE_PARTNER;
        func_800EF300();
        resetMunchlesia = get_entity_by_index(entity->dataBuf.munchlesia->unk_00);
        exec_entity_commandlist(entity);
        exec_entity_commandlist(resetMunchlesia);
    }
}

void func_802BC0B8_E2E9E8(Entity* entity) {
    play_model_animation(entity->virtualModelIndex, Entity_MunchlesiaReset_AnimationReset);
    disable_player_input();
    disable_player_shadow();
}

void func_802BC0F0_E2EA20(Entity* entity) {
    MunchlesiaData* data = entity->dataBuf.munchlesia;
    data->unk_18 = fabs(dist2D(entity->pos.x, entity->pos.z, gPlayerStatus.pos.x, gPlayerStatus.pos.z) * 0.25);
    data->unk_14 = atan2(gPlayerStatus.pos.x, gPlayerStatus.pos.z, entity->pos.x, entity->pos.z);
}

void func_802BC17C_E2EAAC(Entity* entity) {
    MunchlesiaData* data = entity->dataBuf.munchlesia;

    gCameras[CAM_DEFAULT].targetPos.x = gPlayerStatus.pos.x;
    gCameras[CAM_DEFAULT].targetPos.y = gPlayerStatus.pos.y;
    gCameras[CAM_DEFAULT].targetPos.z = gPlayerStatus.pos.z;
    add_vec2D_polar(&gPlayerStatus.pos.x, &gPlayerStatus.pos.z, data->unk_18, data->unk_14);
}

s32 entity_Munchlesia_create_child(Entity* entity, EntityBlueprint* EntityBlueprint) {
    return create_entity(EntityBlueprint, (s32)entity->pos.x, (s32)entity->pos.y, (s32)entity->pos.z, (s32)entity->rot.y);
}

void func_802BC220_E2EB50(Entity* entity) {
    MunchlesiaData* data = entity->dataBuf.munchlesia;
    data->unk_00 = entity_Munchlesia_create_child(entity, &Entity_MunchlesiaReset);
}

void func_802BC250_E2EB80(Entity* entity) {
    entity_Munchlesia_create_child(entity, &Entity_MunchlesiaGrab);
}

void func_802BC274_E2EBA4(Entity* entity) {
    subtract_hp(1);
    entity_Munchlesia_create_child(entity, &Entity_MunchlesiaEnvelop);
    set_action_state(ACTION_STATE_USE_SPRING);
}

void func_802BC2B4_E2EBE4(Entity* entity) {
    entity_Munchlesia_create_child(entity, &Entity_MunchlesiaBeginChew);
    gPlayerStatus.prevActionState = 0;
    gPlayerStatus.actionState = 0;
    gPlayerStatus.flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
    suggest_player_anim_always_forward(ANIM_MarioW2_FlailArms);
}

void func_802BC308_E2EC38(Entity* entity) {
    entity_Munchlesia_create_child(entity, &Entity_MunchlesiaChewing);
}

void func_802BC32C_E2EC5C(Entity* entity) {
    entity_Munchlesia_create_child(entity, &Entity_MunchlesiaSpitOut);
    enable_partner_ai();
}

void entity_Munchlesia_create_child_reset1(Entity* entity) {
    entity_Munchlesia_create_child(entity, &Entity_MunchlesiaReset1);
}

void entity_Munchlesia_create_child_reset2(Entity* entity) {
    entity_Munchlesia_create_child(entity, &Entity_MunchlesiaReset2);
}

void func_802BC3A0_E2ECD0(void) {
    enable_player_input();
    enable_player_shadow();
    set_action_state(ACTION_STATE_USE_MUNCHLESIA);
}

void entity_MunchlesiaChewing_init(Entity* entity) {
    MunchlesiaData* data = entity->dataBuf.munchlesia;
    data->unk_0C = gPlayerStatus.pos.y;
    data->unk_10 = 0;
}

void func_802BC3E4_E2ED14(Entity* entity) {
    MunchlesiaData* data = entity->dataBuf.munchlesia;
    gPlayerStatus.pos.y = data->unk_0C + (sin_rad(DEG_TO_RAD(data->unk_10)) * 3.0f);

    data->unk_10 += 24.0f;
    if (data->unk_10 > 360.0f) {
        data->unk_10 -= 360.0f;
    }
    if (data->unk_10 == 96.0f) {
        sfx_play_sound(SOUND_MUNCHLESIA_CHEW);
    }
}

EntityScript Entity_BellbellPlant_Script = {
    es_SetCallback(entity_BellbellPlant_idle, 0)
    es_ClearFlags(ENTITY_FLAG_SHOWS_INSPECT_PROMPT)
    es_PlaySound(SOUND_PLANTS_BELL)
    es_SetCallback(nullptr, 60)
    es_SetFlags(ENTITY_FLAG_SHOWS_INSPECT_PROMPT)
    es_Restart
    es_End
};

EntityScript Entity_TrumpetPlant_Script = {
    es_SetCallback(entity_TrumpetPlant_idle, 0)
    es_ClearFlags(ENTITY_FLAG_SHOWS_INSPECT_PROMPT)
    es_PlaySound(SOUND_PLANTS_TRUMPET)
    es_SetCallback(nullptr, 15)
    es_Call(entity_TrumpetPlant_create_effect)
    es_SetCallback(nullptr, 3)
    es_Call(entity_TrumpetPlant_create_effect)
    es_SetCallback(nullptr, 2)
    es_Call(entity_TrumpetPlant_spawn_coin)
    es_SetCallback(nullptr, 3)
    es_Call(entity_TrumpetPlant_create_effect)
    es_SetCallback(nullptr, 2)
    es_Call(entity_TrumpetPlant_create_effect)
    es_SetCallback(nullptr, 3)
    es_Call(entity_TrumpetPlant_create_effect)
    es_SetCallback(nullptr, 32)
    es_SetFlags(ENTITY_FLAG_SHOWS_INSPECT_PROMPT)
    es_Restart
    es_End
};

EntityScript Entity_Munchlesia_Script = {
    es_Call(func_802BC220_E2EB50)
    es_Label(1)
        es_SetCallback(func_802BC050_E2E980, 0)
        es_SetCallback(nullptr, 80)
    es_Goto(1)
    es_End
};

EntityScript Entity_MunchlesiaReset_Script = {
    es_SetCallback(nullptr, 0)
    es_Call(func_802BC0B8_E2E9E8)
    es_SetCallback(nullptr, 7)
    es_Call(func_802BC250_E2EB80)
    es_PlaySound(SOUND_MUNCHLESIA_SUCTION)
    es_SetFlags(ENTITY_FLAG_HIDDEN)
    es_SetCallback(nullptr, 3)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript Entity_MunchlesiaGrab_Script = {
    es_SetCallback(nullptr, 3)
    es_Call(func_802BC0F0_E2EA20)
    es_SetCallback(func_802BC17C_E2EAAC, 4)
    es_Call(func_802BC274_E2EBA4)
    es_SetFlags(ENTITY_FLAG_HIDDEN)
    es_SetCallback(nullptr, 3)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript Entity_MunchlesiaEnvelop_Script = {
    es_SetCallback(nullptr, 7)
    es_Call(func_802BC2B4_E2EBE4)
    es_SetFlags(ENTITY_FLAG_HIDDEN)
    es_SetCallback(nullptr, 3)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript Entity_MunchlesiaBeginChew_Script = {
    es_SetCallback(nullptr, 8)
    es_Call(func_802BC308_E2EC38)
    es_SetFlags(ENTITY_FLAG_HIDDEN)
    es_SetCallback(nullptr, 3)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript Entity_MunchlesiaChewing_Script = {
    es_SetCallback(nullptr, 1)
    es_SetCallback(func_802BC3E4_E2ED14, 44)
    es_SetCallback(nullptr, 13)
    es_Call(func_802BC32C_E2EC5C)
    es_SetFlags(ENTITY_FLAG_HIDDEN)
    es_SetCallback(nullptr, 3)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript Entity_MunchlesiaSpitOut_Script = {
    es_SetCallback(nullptr, 4)
    es_Call(func_802BC3A0_E2ECD0)
    es_PlaySound(SOUND_MUNCHLESIA_SPIT)
    es_SetCallback(nullptr, 4)
    es_Call(entity_Munchlesia_create_child_reset1)
    es_SetFlags(ENTITY_FLAG_HIDDEN)
    es_SetCallback(nullptr, 3)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript Entity_MunchlesiaReset1_Script = {
    es_SetCallback(nullptr, 8)
    es_Call(entity_Munchlesia_create_child_reset2)
    es_SetFlags(ENTITY_FLAG_HIDDEN)
    es_SetCallback(nullptr, 3)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript Entity_MunchlesiaReset2_Script = {
    es_SetCallback(nullptr, 9)
    es_Call(func_802BC220_E2EB50)
    es_SetFlags(ENTITY_FLAG_HIDDEN)
    es_SetCallback(nullptr, 10)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};

DmaEntry Entity_MunchlesiaReset_dma[] = { ENTITY_ROM(MunchlesiaReset_gfx), ENTITY_ROM(MunchlesiaReset_anim) };
DmaEntry Entity_MunchlesiaGrab_dma[] = { ENTITY_ROM(MunchlesiaGrab_gfx), ENTITY_ROM(MunchlesiaGrab_anim) };
DmaEntry Entity_MunchlesiaEnvelop_dma[] = { ENTITY_ROM(MunchlesiaEnvelop_gfx), ENTITY_ROM(MunchlesiaEnvelop_anim) };
DmaEntry Entity_MunchlesiaBeginChew_dma[] = { ENTITY_ROM(MunchlesiaBeginChew_gfx), ENTITY_ROM(MunchlesiaBeginChew_anim) };
DmaEntry Entity_MunchlesiaChewing_dma[] = { ENTITY_ROM(MunchlesiaChewing_gfx), ENTITY_ROM(MunchlesiaChewing_anim) };
DmaEntry Entity_MunchlesiaSpitOut_dma[] = { ENTITY_ROM(MunchlesiaSpitOut_gfx), ENTITY_ROM(MunchlesiaSpitOut_anim) };
DmaEntry Entity_MunchlesiaReset1_dma[] = { ENTITY_ROM(MunchlesiaReset1_gfx), ENTITY_ROM(MunchlesiaReset1_anim) };
DmaEntry Entity_BellbellPlant_dma[] = { ENTITY_ROM(BellbellPlant_gfx), ENTITY_ROM(BellbellPlant_anim) };
DmaEntry Entity_TrumpetPlant_dma[] = { ENTITY_ROM(TrumpetPlant_gfx), ENTITY_ROM(TrumpetPlant_anim) };

EntityBlueprint Entity_BellbellPlant = {
    .flags = ENTITY_FLAG_SHOWS_INSPECT_PROMPT | ENTITY_FLAG_CIRCULAR_SHADOW | ENTITY_FLAG_400 | ENTITY_FLAG_FIXED_SHADOW_SIZE | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = 0,
    .renderCommandList = Entity_BellbellPlant_AnimationIdle,
    .modelAnimationNodes = Entity_BellbellPlant_Mesh,
    .fpInit = nullptr,
    .updateEntityScript = Entity_BellbellPlant_Script,
    .fpHandleCollision = nullptr,
    { .dmaList = Entity_BellbellPlant_dma },
    .entityType = ENTITY_TYPE_BELLBELL_PLANT,
    .aabbSize = { 30, 40, 30 }
};

EntityBlueprint Entity_TrumpetPlant = {
    .flags = ENTITY_FLAG_SHOWS_INSPECT_PROMPT | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = sizeof(TrumpetPlantData),
    .renderCommandList = Entity_TrumpetPlant_AnimationIdle,
    .modelAnimationNodes = Entity_TrumpetPlant_Mesh,
    .fpInit = nullptr,
    .updateEntityScript = Entity_TrumpetPlant_Script,
    .fpHandleCollision = nullptr,
    { .dmaList = Entity_TrumpetPlant_dma },
    .entityType = ENTITY_TYPE_TRUMPET_PLANT,
    .aabbSize = { 30, 40, 30 }
};

EntityBlueprint Entity_Munchlesia = {
    .flags = ENTITY_FLAG_CIRCULAR_SHADOW | ENTITY_FLAG_400 | ENTITY_FLAG_FIXED_SHADOW_SIZE,
    .typeDataSize = sizeof(MunchlesiaData),
    .renderCommandList = Entity_RenderNone_Script,
    .modelAnimationNodes = 0,
    .fpInit = entity_Munchlesia_init,
    .updateEntityScript = Entity_Munchlesia_Script,
    .fpHandleCollision = nullptr,
    { .dmaList = nullptr },
    .entityType = ENTITY_TYPE_MUNCHLESIA,
    .aabbSize = { 45, 20, 45 }
};

EntityBlueprint Entity_MunchlesiaReset = {
    .flags = ENTITY_FLAG_DISABLE_COLLISION | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = sizeof(MunchlesiaData),
    .renderCommandList = Entity_MunchlesiaReset_AnimationIdle,
    .modelAnimationNodes = Entity_MunchlesiaReset_Mesh,
    .fpInit = nullptr,
    .updateEntityScript = Entity_MunchlesiaReset_Script,
    .fpHandleCollision = nullptr,
    { .dmaList = Entity_MunchlesiaReset_dma },
    .entityType = ENTITY_TYPE_RESET_MUNCHLESIA,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint Entity_MunchlesiaGrab = {
    .flags = ENTITY_FLAG_DISABLE_COLLISION | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = sizeof(MunchlesiaData),
    .renderCommandList = Entity_MunchlesiaGrab_Animation,
    .modelAnimationNodes = Entity_MunchlesiaGrab_Mesh,
    .fpInit = nullptr,
    .updateEntityScript = Entity_MunchlesiaGrab_Script,
    .fpHandleCollision = nullptr,
    { .dmaList = Entity_MunchlesiaGrab_dma },
    .entityType = ENTITY_TYPE_MUNCHLESIA_GRAB,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint Entity_MunchlesiaEnvelop = {
    .flags = ENTITY_FLAG_DISABLE_COLLISION | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = sizeof(MunchlesiaData),
    .renderCommandList = Entity_MunchlesiaEnvelop_Animation,
    .modelAnimationNodes = Entity_MunchlesiaEnvelop_Mesh,
    .fpInit = nullptr,
    .updateEntityScript = Entity_MunchlesiaEnvelop_Script,
    .fpHandleCollision = nullptr,
    { .dmaList = Entity_MunchlesiaEnvelop_dma },
    .entityType = ENTITY_TYPE_MUNCHLESIA_ENVELOP,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint Entity_MunchlesiaBeginChew = {
    .flags = ENTITY_FLAG_DISABLE_COLLISION | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = sizeof(MunchlesiaData),
    .renderCommandList = Entity_MunchlesiaBeginChew_Animation,
    .modelAnimationNodes = Entity_MunchlesiaBeginChew_Mesh,
    .fpInit = nullptr,
    .updateEntityScript = Entity_MunchlesiaBeginChew_Script,
    .fpHandleCollision = nullptr,
    { .dmaList = Entity_MunchlesiaBeginChew_dma },
    .entityType = ENTITY_TYPE_MUNCHLESIA_BEGIN_CHEW,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint Entity_MunchlesiaChewing = {
    .flags = ENTITY_FLAG_DISABLE_COLLISION | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = sizeof(MunchlesiaData),
    .renderCommandList = Entity_MunchlesiaChewing_Animation,
    .modelAnimationNodes = Entity_MunchlesiaChewing_Mesh,
    .fpInit = entity_MunchlesiaChewing_init,
    .updateEntityScript = Entity_MunchlesiaChewing_Script,
    .fpHandleCollision = nullptr,
    { .dmaList = Entity_MunchlesiaChewing_dma },
    .entityType = ENTITY_TYPE_MUNCHLESIA_CHEWING,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint Entity_MunchlesiaSpitOut = {
    .flags = ENTITY_FLAG_DISABLE_COLLISION | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = sizeof(MunchlesiaData),
    .renderCommandList = Entity_MunchlesiaSpitOut_Animation,
    .modelAnimationNodes = Entity_MunchlesiaSpitOut_Mesh,
    .fpInit = nullptr,
    .updateEntityScript = Entity_MunchlesiaSpitOut_Script,
    .fpHandleCollision = nullptr,
    { .dmaList = Entity_MunchlesiaSpitOut_dma },
    .entityType = ENTITY_TYPE_MUNCHLESIA_SPIT_OUT,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint Entity_MunchlesiaReset1 = {
    .flags = ENTITY_FLAG_DISABLE_COLLISION | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = sizeof(MunchlesiaData),
    .renderCommandList = Entity_MunchlesiaReset1_Animation,
    .modelAnimationNodes = Entity_MunchlesiaReset1_Mesh,
    .fpInit = nullptr,
    .updateEntityScript = Entity_MunchlesiaReset1_Script,
    .fpHandleCollision = nullptr,
    { .dmaList = Entity_MunchlesiaReset1_dma },
    .entityType = ENTITY_TYPE_MUNCHLESIA_RESET1,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint Entity_MunchlesiaReset2 = {
    .flags = ENTITY_FLAG_DISABLE_COLLISION | ENTITY_FLAG_HAS_ANIMATED_MODEL,
    .typeDataSize = sizeof(MunchlesiaData),
    .renderCommandList = Entity_MunchlesiaReset_AnimationIdle,
    .modelAnimationNodes = Entity_MunchlesiaReset_Mesh,
    .fpInit = nullptr,
    .updateEntityScript = Entity_MunchlesiaReset2_Script,
    .fpHandleCollision = nullptr,
    { .dmaList = Entity_MunchlesiaReset_dma },
    .entityType = ENTITY_TYPE_MUNCHLESIA_RESET2,
    .aabbSize = { 40, 20, 40 }
};
