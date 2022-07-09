#include "common.h"
#include "effects.h"
#include "entity_script.h"
#include "animation_script.h"
#include "ld_addrs.h"

extern EntityBlueprint D_802BCC44_E2F574;
extern EntityBlueprint D_802BCC68_E2F598;
extern EntityBlueprint D_802BCC8C_E2F5BC;
extern EntityBlueprint D_802BCCB0_E2F5E0;
extern EntityBlueprint D_802BCCD4_E2F604;
extern EntityBlueprint D_802BCCF8_E2F628;
extern EntityBlueprint D_802BCD1C_E2F64C;
extern EntityBlueprint D_802BCD40_E2F670;

extern EntityModelScript D_802E9830;

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

// size unknown
typedef struct structE2E5F0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s8 unk_04[0x8];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
} structE2E5F0;

typedef struct TrumpetPlantData {
    /* 0x0 */ s32 numCoins;
} TrumpetPlantData; // size = 0x4

void entity_BellbellPlant_idle(Entity* entity) {
    if ((gPlayerStatus.animFlags & PLAYER_STATUS_ANIM_FLAGS_INTERACT_PROMPT_AVAILABLE) &&
        (entity->collisionFlags & (ENTITY_COLLISION_PLAYER_HAMMER | ENTITY_COLLISION_PLAYER_TOUCH_WALL))) {
        exec_entity_commandlist(entity);
        play_model_animation(entity->virtualModelIndex, Entity_BellbellPlant_AnimationUse);
    }
}

void entity_TrumpetPlant_idle(Entity* entity) {
    if ((gPlayerStatus.animFlags & PLAYER_STATUS_ANIM_FLAGS_INTERACT_PROMPT_AVAILABLE) &&
        (entity->collisionFlags & (ENTITY_COLLISION_PLAYER_HAMMER | ENTITY_COLLISION_PLAYER_TOUCH_WALL))) {
        exec_entity_commandlist(entity);
        play_model_animation(entity->virtualModelIndex, Entity_TrumpetPlant_AnimationUse);
    }
}

void entity_TrumpetPlant_create_effect(Entity* entity) {
    f32 xOffset, zOffset, angle;

    angle = clamp_angle(entity->rotation.y) * TAU / 360.0f;
    xOffset = -26.0 * cos_rad(angle);
    zOffset = 6.0 * sin_rad(angle);
    fx_stars_burst(0, entity->position.x + xOffset, entity->position.y + 62.0f, entity->position.z + zOffset, clamp_angle(entity->rotation.y - 90.0), 54.0f, 2);
}

void entity_TrumpetPlant_spawn_coin(Entity* entity) {
    TrumpetPlantData* data = entity->dataBuf.any;

    entity_TrumpetPlant_create_effect(entity);
    if (data->numCoins < 3) {
        f32 xOffset, zOffset, angle;

        angle = clamp_angle(entity->rotation.y) * TAU / 360.0f;
        xOffset = -26.0 * cos_rad(angle);
        zOffset = 6.0 * sin_rad(angle);

        if (rand_int(32) > 16) {
            f32 facingAngle = entity->rotation.y - 110.0f + (data->numCoins % 3) * 30;
            data->numCoins++;
            make_item_entity(ITEM_COIN,
                             entity->position.x + xOffset,
                             entity->position.y + 62.0f,
                             entity->position.z + zOffset,
                             ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0,
                             facingAngle, 0);
        }
    }
}

void entity_Munchlesia_init(Entity* entity) {
    make_item_entity_nodelay(ITEM_COIN, entity->position.x, entity->position.y + 30.0f, entity->position.z, ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS_NEVER_VANISH, 0);
}

void func_802BC050_E2E980(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
        Entity* resetMunchlesia;
        gPlayerStatus.animFlags |= 4;
        func_800EF300();
        resetMunchlesia = get_entity_by_index(entity->dataBuf.unk[0]);
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
    structE2E5F0* data = (structE2E5F0*)entity->dataBuf.unk;
    data->unk_18 = fabs(dist2D(entity->position.x, entity->position.z, gPlayerStatus.position.x, gPlayerStatus.position.z) * 0.25);
    data->unk_14 = atan2(gPlayerStatus.position.x, gPlayerStatus.position.z, entity->position.x, entity->position.z);
}

void func_802BC17C_E2EAAC(Entity* entity) {
    structE2E5F0* data = (structE2E5F0*)entity->dataBuf.unk;

    gCameras[CAM_DEFAULT].targetPos.x = gPlayerStatus.position.x;
    gCameras[CAM_DEFAULT].targetPos.y = gPlayerStatus.position.y;
    gCameras[CAM_DEFAULT].targetPos.z = gPlayerStatus.position.z;
    add_vec2D_polar(&gPlayerStatus.position.x, &gPlayerStatus.position.z, data->unk_18, data->unk_14);
}

s32 entity_Munchlesia_create_child(Entity* entity, EntityBlueprint* EntityBlueprint) {
    return create_entity(EntityBlueprint, (s32)entity->position.x, (s32)entity->position.y, (s32)entity->position.z, (s32)entity->rotation.y);
}

void func_802BC220_E2EB50(Entity* entity) {
    structE2E5F0* data = (structE2E5F0*)entity->dataBuf.unk;
    data->unk_00 = entity_Munchlesia_create_child(entity, &D_802BCC44_E2F574);
}

void func_802BC250_E2EB80(Entity* entity) {
    entity_Munchlesia_create_child(entity, &D_802BCC68_E2F598);
}

void func_802BC274_E2EBA4(Entity* entity) {
    subtract_hp(1);
    entity_Munchlesia_create_child(entity, &D_802BCC8C_E2F5BC);
    set_action_state(ACTION_STATE_USE_SPRING);
}

void func_802BC2B4_E2EBE4(Entity* entity) {
    entity_Munchlesia_create_child(entity, &D_802BCCB0_E2F5E0);
    gPlayerStatus.prevActionState = 0;
    gPlayerStatus.actionState = 0;
    gPlayerStatus.flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
    suggest_player_anim_setUnkFlag(0x8001F);
}

void func_802BC308_E2EC38(Entity* entity) {
    entity_Munchlesia_create_child(entity, &D_802BCCD4_E2F604);
}

void func_802BC32C_E2EC5C(Entity* entity) {
    entity_Munchlesia_create_child(entity, &D_802BCCF8_E2F628);
    enable_partner_ai();
}

void entity_Munchlesia_create_child_reset1(Entity* entity) {
    entity_Munchlesia_create_child(entity, &D_802BCD1C_E2F64C);
}

void entity_Munchlesia_create_child_reset2(Entity* entity) {
    entity_Munchlesia_create_child(entity, &D_802BCD40_E2F670);
}

void func_802BC3A0_E2ECD0(void) {
    enable_player_input();
    enable_player_shadow();
    set_action_state(ACTION_STATE_USE_MUNCHLESIA);
}

void func_802BC3CC_E2ECFC(Entity* entity) {
    structE2E5F0* data = (structE2E5F0*)entity->dataBuf.unk;
    data->unk_0C = gPlayerStatus.position.y;
    data->unk_10 = 0;
}

void func_802BC3E4_E2ED14(Entity* entity) {
    structE2E5F0* data = (structE2E5F0*)entity->dataBuf.unk;
    gPlayerStatus.position.y = data->unk_0C + (sin_rad((data->unk_10 * TAU) / 360.0f) * 3.0f);

    data->unk_10 += 24.0f;
    if (data->unk_10 > 360.0f) {
        data->unk_10 -= 360.0f;
    }
    if (data->unk_10 == 96.0f) {
        sfx_play_sound(SOUND_392);
    }
}

EntityScript Entity_BellbellPlant_Script = {
    es_SetCallback(entity_BellbellPlant_idle, 0)
    es_ClearFlags(ENTITY_FLAGS_SHOWS_INSPECT_PROMPT)
    es_PlaySound(SOUND_F1)
    es_SetCallback(NULL, 60)
    es_SetFlags(ENTITY_FLAGS_SHOWS_INSPECT_PROMPT)
    es_Restart
    es_End
};

EntityScript Entity_TrumpetPlant_Script = {
    es_SetCallback(entity_TrumpetPlant_idle, 0)
    es_ClearFlags(ENTITY_FLAGS_SHOWS_INSPECT_PROMPT)
    es_PlaySound(SOUND_F3)
    es_SetCallback(NULL, 15)
    es_Call(entity_TrumpetPlant_create_effect)
    es_SetCallback(NULL, 3)
    es_Call(entity_TrumpetPlant_create_effect)
    es_SetCallback(NULL, 2)
    es_Call(entity_TrumpetPlant_spawn_coin)
    es_SetCallback(NULL, 3)
    es_Call(entity_TrumpetPlant_create_effect)
    es_SetCallback(NULL, 2)
    es_Call(entity_TrumpetPlant_create_effect)
    es_SetCallback(NULL, 3)
    es_Call(entity_TrumpetPlant_create_effect)
    es_SetCallback(NULL, 32)
    es_SetFlags(ENTITY_FLAGS_SHOWS_INSPECT_PROMPT)
    es_Restart
    es_End
};

EntityScript Entity_Munchlesia_Script = {
    es_Call(func_802BC220_E2EB50)
    es_Label(1)
        es_SetCallback(func_802BC050_E2E980, 0)
        es_SetCallback(NULL, 80)
    es_Goto(1)
    es_End
};

EntityScript Entity_MunchlesiaReset_Script = {
    es_SetCallback(NULL, 0)
    es_Call(func_802BC0B8_E2E9E8)
    es_SetCallback(NULL, 7)
    es_Call(func_802BC250_E2EB80)
    es_PlaySound(SOUND_209B)
    es_SetFlags(ENTITY_FLAGS_HIDDEN)
    es_SetCallback(NULL, 3)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript Entity_MunchlesiaGrab_Script = {
    es_SetCallback(NULL, 3)
    es_Call(func_802BC0F0_E2EA20)
    es_SetCallback(func_802BC17C_E2EAAC, 4)
    es_Call(func_802BC274_E2EBA4)
    es_SetFlags(ENTITY_FLAGS_HIDDEN)
    es_SetCallback(NULL, 3)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript Entity_MunchlesiaEnvelop_Script = {
    es_SetCallback(NULL, 7)
    es_Call(func_802BC2B4_E2EBE4)
    es_SetFlags(ENTITY_FLAGS_HIDDEN)
    es_SetCallback(NULL, 3)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript Entity_MunchlesiaBeginChew_Script = {
    es_SetCallback(NULL, 8)
    es_Call(func_802BC308_E2EC38)
    es_SetFlags(ENTITY_FLAGS_HIDDEN)
    es_SetCallback(NULL, 3)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript Entity_MunchlesiaChewing_Script = {
    es_SetCallback(NULL, 1)
    es_SetCallback(func_802BC3E4_E2ED14, 44)
    es_SetCallback(NULL, 13)
    es_Call(func_802BC32C_E2EC5C)
    es_SetFlags(ENTITY_FLAGS_HIDDEN)
    es_SetCallback(NULL, 3)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript Entity_MunchlesiaSpitOut_Script = {
    es_SetCallback(NULL, 4)
    es_Call(func_802BC3A0_E2ECD0)
    es_PlaySound(SOUND_393)
    es_SetCallback(NULL, 4)
    es_Call(entity_Munchlesia_create_child_reset1)
    es_SetFlags(ENTITY_FLAGS_HIDDEN)
    es_SetCallback(NULL, 3)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript Entity_MunchlesiaReset1_Script = {
    es_SetCallback(NULL, 8)
    es_Call(entity_Munchlesia_create_child_reset2)
    es_SetFlags(ENTITY_FLAGS_HIDDEN)
    es_SetCallback(NULL, 3)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript Entity_MunchlesiaReset2_Script = {
    es_SetCallback(NULL, 9)
    es_Call(func_802BC220_E2EB50)
    es_SetFlags(ENTITY_FLAGS_HIDDEN)
    es_SetCallback(NULL, 10)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};

s32 Entity_MunchlesiaReset_dma[] = {
    entity_model_MunchlesiaReset_gfx_ROM_START, entity_model_MunchlesiaReset_gfx_ROM_END,
    entity_model_MunchlesiaReset_anim_ROM_START, entity_model_MunchlesiaReset_anim_ROM_END
};
s32 Entity_MunchlesiaGrab_dma[] = {
    entity_model_MunchlesiaGrab_gfx_ROM_START, entity_model_MunchlesiaGrab_gfx_ROM_END,
    entity_model_MunchlesiaGrab_anim_ROM_START, entity_model_MunchlesiaGrab_anim_ROM_END
};
s32 Entity_MunchlesiaEnvelop_dma[] = {
    0x00E7B0E0, 0x00E811D0, 0x00E811D0, 0x00E815F0
};
s32 D_802BCB78_E2F4A8[] = {
    0x00E815F0, 0x00E88030, 0x00E88030, 0x00E884A0
};
s32 D_802BCB88_E2F4B8[] = {
    0x00E884A0, 0x00E8A410, 0x00E8A410, 0x00E8A9E0
};
s32 D_802BCB98_E2F4C8[] = {
    0x00E8A9E0, 0x00E91420, 0x00E91420, 0x00E91890
};
s32 D_802BCBA8_E2F4D8[] = {
    0x00E91890, 0x00E982D0, 0x00E982D0, 0x00E98740
};
s32 Entity_BellbellPlant_dma[] = {
    entity_model_BellbellPlant_gfx_ROM_START, entity_model_BellbellPlant_gfx_ROM_END,
    entity_model_BellbellPlant_anim_ROM_START, entity_model_BellbellPlant_anim_ROM_END
};
s32 Entity_TrumpetPlant_dma[] = {
    entity_model_TrumpetPlant_gfx_ROM_START, entity_model_TrumpetPlant_gfx_ROM_END,
    entity_model_TrumpetPlant_anim_ROM_START, entity_model_TrumpetPlant_anim_ROM_END
};

EntityBlueprint D_802BCBD8_E2F508 = {
    .flags = ENTITY_FLAGS_SHOWS_INSPECT_PROMPT | ENTITY_FLAGS_SQUARE_SHADOW | ENTITY_FLAGS_400 | ENTITY_FLAGS_SET_SHADOW_FLAG200 | ENTITY_FLAGS_HAS_ANIMATED_MODEL,
    .typeDataSize = 0,
    .renderCommandList = Entity_BellbellPlant_AnimationIdle,
    .modelAnimationNodes = Entity_BellbellPlant_Mesh,
    .fpInit = NULL,
    .updateEntityScript = Entity_BellbellPlant_Script,
    .fpHandleCollision = NULL,
    {{ Entity_BellbellPlant_dma, 0 }},
    .entityType = ENTITY_TYPE_BELLBELL_PLANT,
    .aabbSize = { 30, 40, 30 }
};

EntityBlueprint D_802BCBFC_E2F52C = {
    .flags = ENTITY_FLAGS_SHOWS_INSPECT_PROMPT | ENTITY_FLAGS_HAS_ANIMATED_MODEL,
    .typeDataSize = 4,
    .renderCommandList = Entity_TrumpetPlant_AnimationIdle,
    .modelAnimationNodes = Entity_TrumpetPlant_Mesh,
    .fpInit = NULL,
    .updateEntityScript = Entity_TrumpetPlant_Script,
    .fpHandleCollision = NULL,
    {{ Entity_TrumpetPlant_dma, 0 }},
    .entityType = ENTITY_TYPE_TRUMPET_PLANT,
    .aabbSize = { 30, 40, 30 }
};

EntityBlueprint D_802BCC20_E2F550 = {
    .flags = ENTITY_FLAGS_SQUARE_SHADOW | ENTITY_FLAGS_400 | ENTITY_FLAGS_SET_SHADOW_FLAG200,
    .typeDataSize = 0x1C,
    .renderCommandList = D_802E9830,
    .modelAnimationNodes = 0,
    .fpInit = entity_Munchlesia_init,
    .updateEntityScript = Entity_Munchlesia_Script,
    .fpHandleCollision = NULL,
    {{ 0, 0 }},
    .entityType = ENTITY_TYPE_MUNCHLESIA,
    .aabbSize = { 45, 20, 45 }
};

EntityBlueprint D_802BCC44_E2F574 = {
    .flags = ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_HAS_ANIMATED_MODEL,
    .typeDataSize = 0x1C,
    .renderCommandList = Entity_MunchlesiaReset_AnimationIdle,
    .modelAnimationNodes = Entity_MunchlesiaReset_Mesh,
    .fpInit = NULL,
    .updateEntityScript = Entity_MunchlesiaReset_Script,
    .fpHandleCollision = NULL,
    {{ Entity_MunchlesiaReset_dma, 0 }},
    .entityType = ENTITY_TYPE_RESET_MUNCHLESIA,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint D_802BCC68_E2F598 = {
    .flags = ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_HAS_ANIMATED_MODEL,
    .typeDataSize = 0x1C,
    .renderCommandList = Entity_MunchlesiaGrab_Animation,
    .modelAnimationNodes = Entity_MunchlesiaGrab_Mesh,
    .fpInit = NULL,
    .updateEntityScript = Entity_MunchlesiaGrab_Script,
    .fpHandleCollision = NULL,
    {{ Entity_MunchlesiaGrab_dma, 0 }},
    .entityType = ENTITY_TYPE_MUNCHLESIA_GRAB,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint D_802BCC8C_E2F5BC = {
    .flags = ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_HAS_ANIMATED_MODEL,
    .typeDataSize = 0x1C,
    .renderCommandList = 0,
    .modelAnimationNodes = 0x3FC,
    .fpInit = NULL,
    .updateEntityScript = Entity_MunchlesiaEnvelop_Script,
    .fpHandleCollision = NULL,
    {{ Entity_MunchlesiaEnvelop_dma, 0 }},
    .entityType = ENTITY_TYPE_MUNCHLESIA_ENVELOP,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint D_802BCCB0_E2F5E0 = {
    .flags = ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_HAS_ANIMATED_MODEL,
    .typeDataSize = 0x1C,
    .renderCommandList = 0,
    .modelAnimationNodes = 0x444,
    .fpInit = NULL,
    .updateEntityScript = Entity_MunchlesiaBeginChew_Script,
    .fpHandleCollision = NULL,
    {{ D_802BCB78_E2F4A8, 0 }},
    .entityType = ENTITY_TYPE_MUNCHLESIA_BEGIN_CHEW,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint D_802BCCD4_E2F604 = {
    .flags = ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_HAS_ANIMATED_MODEL,
    .typeDataSize = 0x1C,
    .renderCommandList = 0x34,
    .modelAnimationNodes = 0x2C,
    .fpInit = func_802BC3CC_E2ECFC,
    .updateEntityScript = Entity_MunchlesiaChewing_Script,
    .fpHandleCollision = NULL,
    {{ D_802BCB88_E2F4B8, 0 }},
    .entityType = ENTITY_TYPE_MUNCHLESIA_CHEWING,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint D_802BCCF8_E2F628 = {
    .flags = ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_HAS_ANIMATED_MODEL,
    .typeDataSize = 0x1C,
    .renderCommandList = 0,
    .modelAnimationNodes = 0x444,
    .fpInit = NULL,
    .updateEntityScript = Entity_MunchlesiaSpitOut_Script,
    .fpHandleCollision = NULL,
    {{ D_802BCB98_E2F4C8, 0 }},
    .entityType = ENTITY_TYPE_MUNCHLESIA_SPIT_OUT,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint D_802BCD1C_E2F64C = {
    .flags = ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_HAS_ANIMATED_MODEL,
    .typeDataSize = 0x1C,
    .renderCommandList = 0,
    .modelAnimationNodes = 0x444,
    .fpInit = NULL,
    .updateEntityScript = Entity_MunchlesiaReset1_Script,
    .fpHandleCollision = NULL,
    {{ D_802BCBA8_E2F4D8, 0 }},
    .entityType = ENTITY_TYPE_MUNCHLESIA_RESET1,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint D_802BCD40_E2F670 = {
    .flags = ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_HAS_ANIMATED_MODEL,
    .typeDataSize = 0x1C,
    .renderCommandList = Entity_MunchlesiaReset_AnimationIdle,
    .modelAnimationNodes = Entity_MunchlesiaReset_Mesh,
    .fpInit = NULL,
    .updateEntityScript = Entity_MunchlesiaReset2_Script,
    .fpHandleCollision = NULL,
    {{ Entity_MunchlesiaReset_dma, 0 }},
    .entityType = ENTITY_TYPE_MUNCHLESIA_RESET2,
    .aabbSize = { 40, 20, 40 }
};
