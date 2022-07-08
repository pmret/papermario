#include "common.h"
#include "effects.h"
#include "entity_script.h"

extern EntityBlueprint D_802BCC44_E2F574;
extern EntityBlueprint D_802BCC68_E2F598;
extern EntityBlueprint D_802BCC8C_E2F5BC;
extern EntityBlueprint D_802BCCB0_E2F5E0;
extern EntityBlueprint D_802BCCD4_E2F604;
extern EntityBlueprint D_802BCCF8_E2F628;
extern EntityBlueprint D_802BCD1C_E2F64C;
extern EntityBlueprint D_802BCD40_E2F670;

extern EntityModelScript D_802E9830;

// size unknown
typedef struct structE2E5F0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s8 unk_04[0x8];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
} structE2E5F0;

INCLUDE_ASM(s32, "entity/jan_iwa/E2E5F0", func_802BBCC0_E2E5F0);
void func_802BBCC0_E2E5F0(Entity*);

INCLUDE_ASM(s32, "entity/jan_iwa/E2E5F0", func_802BBD1C_E2E64C);
void func_802BBD1C_E2E64C(Entity*);

void func_802BBD78_E2E6A8(Entity* entity) {
    f32 xOffset, zOffset, angle;

    angle = (clamp_angle(entity->rotation.y) * TAU) / 360.0f;
    xOffset = cos_rad(angle) * -26.0;
    zOffset = sin_rad(angle) * 6.0;
    fx_stars_burst(0, entity->position.x + xOffset, entity->position.y + 62.0f, entity->position.z + zOffset, clamp_angle(entity->rotation.y - 90.0), 54.0f, 2);
}

INCLUDE_ASM(s32, "entity/jan_iwa/E2E5F0", func_802BBE8C_E2E7BC);
void func_802BBE8C_E2E7BC(Entity*);

void func_802BC00C_E2E93C(Entity* entity) {
    make_item_entity_nodelay(ITEM_COIN, entity->position.x, entity->position.y + 30.0f, entity->position.z, 0x13, 0);
}

void func_802BC050_E2E980(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (entity->collisionFlags & 1) {
        Entity* other;
        gPlayerStatus.animFlags |= 4;
        func_800EF300();
        other = get_entity_by_index(entity->dataBuf.unk[0]);
        exec_entity_commandlist(entity);
        exec_entity_commandlist(other);
    }
}

#ifdef NON_EQUIVALENT // play_model_animation weirdness
void func_802BC0B8_E2E9E8(Entity* entity) {
    play_model_animation(entity->virtualModelIndex, 0x60);
    disable_player_input();
    disable_player_shadow();
}
#else
INCLUDE_ASM(s32, "entity/jan_iwa/E2E5F0", func_802BC0B8_E2E9E8);
void func_802BC0B8_E2E9E8(Entity*);
#endif

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

s32 func_802BC1D0_E2EB00(Entity* entity, EntityBlueprint* EntityBlueprint) {
    return create_entity(EntityBlueprint, (s32)entity->position.x, (s32)entity->position.y, (s32)entity->position.z, (s32)entity->rotation.y);
}

void func_802BC220_E2EB50(Entity* entity) {
    structE2E5F0* data = (structE2E5F0*)entity->dataBuf.unk;
    data->unk_00 = func_802BC1D0_E2EB00(entity, &D_802BCC44_E2F574);
}

void func_802BC250_E2EB80(Entity* entity) {
    func_802BC1D0_E2EB00(entity, &D_802BCC68_E2F598);
}

void func_802BC274_E2EBA4(Entity* entity) {
    subtract_hp(1);
    func_802BC1D0_E2EB00(entity, &D_802BCC8C_E2F5BC);
    set_action_state(ACTION_STATE_USE_SPRING);
}

void func_802BC2B4_E2EBE4(Entity* entity) {
    func_802BC1D0_E2EB00(entity, &D_802BCCB0_E2F5E0);
    gPlayerStatus.prevActionState = 0;
    gPlayerStatus.actionState = 0;
    gPlayerStatus.flags &= ~0x80000000;
    suggest_player_anim_setUnkFlag(0x8001F);
}

void func_802BC308_E2EC38(Entity* entity) {
    func_802BC1D0_E2EB00(entity, &D_802BCCD4_E2F604);
}

void func_802BC32C_E2EC5C(Entity* entity) {
    func_802BC1D0_E2EB00(entity, &D_802BCCF8_E2F628);
    enable_partner_ai();
}

void func_802BC358_E2EC88(Entity* entity) {
    func_802BC1D0_E2EB00(entity, &D_802BCD1C_E2F64C);
}

void func_802BC37C_E2ECAC(Entity* entity) {
    func_802BC1D0_E2EB00(entity, &D_802BCD40_E2F670);
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

EntityScript D_802BC820_E2F150 = {
    es_SetCallback(func_802BBCC0_E2E5F0, 0)
    es_ClearFlags(ENTITY_FLAGS_SHOWS_INSPECT_PROMPT)
    es_PlaySound(SOUND_F1)
    es_SetCallback(NULL, 60)
    es_SetFlags(ENTITY_FLAGS_SHOWS_INSPECT_PROMPT)
    es_Restart
    es_End
};

EntityScript D_802BC85C_E2F18C = {
    es_SetCallback(func_802BBD1C_E2E64C, 0)
    es_ClearFlags(ENTITY_FLAGS_SHOWS_INSPECT_PROMPT)
    es_PlaySound(SOUND_F3)
    es_SetCallback(NULL, 15)
    es_Call(func_802BBD78_E2E6A8)
    es_SetCallback(NULL, 3)
    es_Call(func_802BBD78_E2E6A8)
    es_SetCallback(NULL, 2)
    es_Call(func_802BBE8C_E2E7BC)
    es_SetCallback(NULL, 3)
    es_Call(func_802BBD78_E2E6A8)
    es_SetCallback(NULL, 2)
    es_Call(func_802BBD78_E2E6A8)
    es_SetCallback(NULL, 3)
    es_Call(func_802BBD78_E2E6A8)
    es_SetCallback(NULL, 32)
    es_SetFlags(ENTITY_FLAGS_SHOWS_INSPECT_PROMPT)
    es_Restart
    es_End
};

EntityScript D_802BC910_E2F240 = {
    es_Call(func_802BC220_E2EB50)
    es_Label(1)
        es_SetCallback(func_802BC050_E2E980, 0)
        es_SetCallback(NULL, 80)
    es_Goto(1)
    es_End
};

EntityScript D_802BC944_E2F274 = {
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

EntityScript D_802BC994_E2F2C4 = {
    es_SetCallback(NULL, 3)
    es_Call(func_802BC0F0_E2EA20)
    es_SetCallback(func_802BC17C_E2EAAC, 4)
    es_Call(func_802BC274_E2EBA4)
    es_SetFlags(ENTITY_FLAGS_HIDDEN)
    es_SetCallback(NULL, 3)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript D_802BC9DC_E2F30C = {
    es_SetCallback(NULL, 7)
    es_Call(func_802BC2B4_E2EBE4)
    es_SetFlags(ENTITY_FLAGS_HIDDEN)
    es_SetCallback(NULL, 3)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript D_802BCA10_E2F340 = {
    es_SetCallback(NULL, 8)
    es_Call(func_802BC308_E2EC38)
    es_SetFlags(ENTITY_FLAGS_HIDDEN)
    es_SetCallback(NULL, 3)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript D_802BCA44_E2F374 = {
    es_SetCallback(NULL, 1)
    es_SetCallback(func_802BC3E4_E2ED14, 44)
    es_SetCallback(NULL, 13)
    es_Call(func_802BC32C_E2EC5C)
    es_SetFlags(ENTITY_FLAGS_HIDDEN)
    es_SetCallback(NULL, 3)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript D_802BCA90_E2F3C0 = {
    es_SetCallback(NULL, 4)
    es_Call(func_802BC3A0_E2ECD0)
    es_PlaySound(SOUND_393)
    es_SetCallback(NULL, 4)
    es_Call(func_802BC358_E2EC88)
    es_SetFlags(ENTITY_FLAGS_HIDDEN)
    es_SetCallback(NULL, 3)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript D_802BCAE0_E2F410 = {
    es_SetCallback(NULL, 8)
    es_Call(func_802BC37C_E2ECAC)
    es_SetFlags(ENTITY_FLAGS_HIDDEN)
    es_SetCallback(NULL, 3)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};

EntityScript D_802BCB14_E2F444 = {
    es_SetCallback(NULL, 9)
    es_Call(func_802BC220_E2EB50)
    es_SetFlags(ENTITY_FLAGS_HIDDEN)
    es_SetCallback(NULL, 10)
    es_SetFlags(ENTITY_FLAGS_PENDING_INSTANCE_DELETE)
    es_End
};

s32 D_802BCB48_E2F478[] = {
0x00E6E660, 0x00E74750, 0x00E74750, 0x00E74BD0
};

s32 D_802BCB58_E2F488[] = {
0x00E74BD0, 0x00E7ACC0, 0x00E7ACC0, 0x00E7B0E0
};

s32 D_802BCB68_E2F498[] = {
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
s32 D_802BCBB8_E2F4E8[] = {
0x00E6B1B0, 0x00E6C440, 0x00E6C440, 0x00E6D390
};
s32 D_802BCBC8_E2F4F8[] = {
0x00E6D390, 0x00E6E2D0, 0x00E6E2D0, 0x00E6E660,
};

EntityBlueprint D_802BCBD8_E2F508 = {
    .flags = ENTITY_FLAGS_SHOWS_INSPECT_PROMPT | ENTITY_FLAGS_SQUARE_SHADOW | ENTITY_FLAGS_400 | ENTITY_FLAGS_SET_SHADOW_FLAG200 | ENTITY_FLAGS_HAS_ANIMATED_MODEL,
    .typeDataSize = 0,
    .renderCommandList = 0xEA4,
    .modelAnimationNodes = 0xDC,
    .fpInit = NULL,
    .updateEntityScript = D_802BC820_E2F150,
    .fpHandleCollision = NULL,
    {{ D_802BCBB8_E2F4E8, 0 }},
    .entityType = ENTITY_TYPE_BELLBELL_PLANT,
    .aabbSize = { 30, 40, 30 }
};

EntityBlueprint D_802BCBFC_E2F52C = {
    .flags = ENTITY_FLAGS_SHOWS_INSPECT_PROMPT | ENTITY_FLAGS_HAS_ANIMATED_MODEL,
    .typeDataSize = 4,
    .renderCommandList = 0x340,
    .modelAnimationNodes = 0x58,
    .fpInit = NULL,
    .updateEntityScript = D_802BC85C_E2F18C,
    .fpHandleCollision = NULL,
    {{ D_802BCBC8_E2F4F8, 0 }},
    .entityType = ENTITY_TYPE_TRUMPET_PLANT,
    .aabbSize = { 30, 40, 30 }
};

EntityBlueprint D_802BCC20_E2F550 = {
    .flags = ENTITY_FLAGS_SQUARE_SHADOW | ENTITY_FLAGS_400 | ENTITY_FLAGS_SET_SHADOW_FLAG200,
    .typeDataSize = 0x1C,
    .renderCommandList = D_802E9830,
    .modelAnimationNodes = 0,
    .fpInit = func_802BC00C_E2E93C,
    .updateEntityScript = D_802BC910_E2F240,
    .fpHandleCollision = NULL,
    {{ 0, 0 }},
    .entityType = ENTITY_TYPE_MUNCHLESIA,
    .aabbSize = { 45, 20, 45 }
};

EntityBlueprint D_802BCC44_E2F574 = {
    .flags = ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_HAS_ANIMATED_MODEL,
    .typeDataSize = 0x1C,
    .renderCommandList = 0,
    .modelAnimationNodes = 0x45C,
    .fpInit = NULL,
    .updateEntityScript = D_802BC944_E2F274,
    .fpHandleCollision = NULL,
    {{ D_802BCB48_E2F478, 0 }},
    .entityType = ENTITY_TYPE_RESET_MUNCHLESIA,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint D_802BCC68_E2F598 = {
    .flags = ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_HAS_ANIMATED_MODEL,
    .typeDataSize = 0x1C,
    .renderCommandList = 0,
    .modelAnimationNodes = 0x3FC,
    .fpInit = NULL,
    .updateEntityScript = D_802BC994_E2F2C4,
    .fpHandleCollision = NULL,
    {{ D_802BCB58_E2F488, 0 }},
    .entityType = ENTITY_TYPE_MUNCHLESIA_GRAB,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint D_802BCC8C_E2F5BC = {
    .flags = ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_HAS_ANIMATED_MODEL,
    .typeDataSize = 0x1C,
    .renderCommandList = 0,
    .modelAnimationNodes = 0x3FC,
    .fpInit = NULL,
    .updateEntityScript = D_802BC9DC_E2F30C,
    .fpHandleCollision = NULL,
    {{ D_802BCB68_E2F498, 0 }},
    .entityType = ENTITY_TYPE_MUNCHLESIA_ENVELOP,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint D_802BCCB0_E2F5E0 = {
    .flags = ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_HAS_ANIMATED_MODEL,
    .typeDataSize = 0x1C,
    .renderCommandList = 0,
    .modelAnimationNodes = 0x444,
    .fpInit = NULL,
    .updateEntityScript = D_802BCA10_E2F340,
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
    .updateEntityScript = D_802BCA44_E2F374,
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
    .updateEntityScript = D_802BCA90_E2F3C0,
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
    .updateEntityScript = D_802BCAE0_E2F410,
    .fpHandleCollision = NULL,
    {{ D_802BCBA8_E2F4D8, 0 }},
    .entityType = ENTITY_TYPE_MUNCHLESIA_RESET1,
    .aabbSize = { 40, 20, 40 }
};

EntityBlueprint D_802BCD40_E2F670 = {
    .flags = ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX | ENTITY_FLAGS_HAS_ANIMATED_MODEL,
    .typeDataSize = 0x1C,
    .renderCommandList = 0,
    .modelAnimationNodes = 0x45C,
    .fpInit = NULL,
    .updateEntityScript = D_802BCB14_E2F444,
    .fpHandleCollision = NULL,
    {{ D_802BCB48_E2F478, 0 }},
    .entityType = ENTITY_TYPE_MUNCHLESIA_RESET2,
    .aabbSize = { 40, 20, 40 }
};
