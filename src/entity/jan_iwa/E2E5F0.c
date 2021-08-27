#include "common.h"
#include "effects.h"

extern StaticEntityData D_802BCC44_E2F574;
extern StaticEntityData D_802BCC68_E2F598;
extern StaticEntityData D_802BCC8C_E2F5BC;
extern StaticEntityData D_802BCCB0_E2F5E0;
extern StaticEntityData D_802BCCD4_E2F604;
extern StaticEntityData D_802BCCF8_E2F628;
extern StaticEntityData D_802BCD1C_E2F64C;
extern StaticEntityData D_802BCD40_E2F670;

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

INCLUDE_ASM(s32, "entity/jan_iwa/E2E5F0", func_802BBD1C_E2E64C);

void func_802BBD78_E2E6A8(Entity* entity) {
    f32 xOffset, zOffset, angle;

    angle = (clamp_angle(entity->rotation.y) * TAU) / 360.0f;
    xOffset = cos_rad(angle) * -26.0;
    zOffset = sin_rad(angle) * 6.0;
    playFX_21(0, entity->position.x + xOffset, entity->position.y + 62.0f, entity->position.z + zOffset, clamp_angle(entity->rotation.y - 90.0), 54.0f, 2);
}

INCLUDE_ASM(s32, "entity/jan_iwa/E2E5F0", func_802BBE8C_E2E7BC);

void func_802BC00C_E2E93C(Entity* entity) {
    make_item_entity_nodelay(ITEM_COIN, entity->position.x, entity->position.y + 30.0f, entity->position.z, 0x13, 0);
}

void func_802BC050_E2E980(Entity* entity) {
    Entity* other;

    PlayerStatus* playerStatus = &gPlayerStatus;

    if ((entity->collisionFlags & 1) != 0) {
        gPlayerStatus.animFlags |= 4;
        func_800EF300();
        other = get_entity_by_index(entity->dataBuf[0]);
        exec_entity_commandlist(entity);
        exec_entity_commandlist(other);
    }
}

#ifdef NON_MATCHING // play_model_animation weirdness
void func_802BC0B8_E2E9E8(Entity* entity) {
    play_model_animation(entity->virtualModelIndex, 0x60);
    disable_player_input();
    disable_player_shadow();
}
#else
INCLUDE_ASM(s32, "entity/jan_iwa/E2E5F0", func_802BC0B8_E2E9E8);
#endif

void func_802BC0F0_E2EA20(Entity* entity) {
    structE2E5F0* data = (structE2E5F0*)entity->dataBuf;
    data->unk_18 = fabs(dist2D(entity->position.x, entity->position.z, gPlayerStatus.position.x, gPlayerStatus.position.z) * 0.25);
    data->unk_14 = atan2(gPlayerStatus.position.x, gPlayerStatus.position.z, entity->position.x, entity->position.z);
}

void func_802BC17C_E2EAAC(Entity* entity) {
    structE2E5F0* data = (structE2E5F0*)entity->dataBuf;

    gCameras[0].targetPos.x = gPlayerStatus.position.x;
    gCameras[0].targetPos.y = gPlayerStatus.position.y;
    gCameras[0].targetPos.z = gPlayerStatus.position.z;
    add_vec2D_polar(&gPlayerStatus.position.x, &gPlayerStatus.position.z, data->unk_18, data->unk_14);
}

s32 func_802BC1D0_E2EB00(Entity* entity, StaticEntityData* staticEntityData) {
    return create_entity(staticEntityData, entity->position.x, entity->position.y, entity->position.z, entity->rotation.y);
}

void func_802BC220_E2EB50(Entity* entity) {
    structE2E5F0* data = (structE2E5F0*)entity->dataBuf;
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
    structE2E5F0* data = (structE2E5F0*)entity->dataBuf;
    data->unk_0C = gPlayerStatus.position.y;
    data->unk_10 = 0;
}

void func_802BC3E4_E2ED14(Entity* entity) {
    structE2E5F0* data = (structE2E5F0*)entity->dataBuf;
    gPlayerStatus.position.y = data->unk_0C + (sin_rad((data->unk_10 * TAU) / 360.0f) * 3.0f);

    data->unk_10 += 24.0f;
    if (data->unk_10 > 360.0f) {
        data->unk_10 -= 360.0f;
    }
    if (data->unk_10 == 96.0f) {
        sfx_play_sound(0x392);
    }
}
