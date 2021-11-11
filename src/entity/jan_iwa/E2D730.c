#include "common.h"
#include "sprite.h"

extern StaticEntityData D_802BC7D0_E2F100;
extern f32 D_802BCE20;
// size unknown
typedef struct structE2D730 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ s8 unk_01;
    /* 0x02 */ s8 unk_02;
    /* 0x04 */ union { // might be 2 different structs?
    /*      */   s16 index;
    /*      */   f32 f;
    /*      */ } unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ s8 unk_0C[8];
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s8 unk_18[0x10];
    /* 0x28 */ s16 unk_28;
    /* 0x2A */ s16 unk_2A;
    /* 0x2C */ s16 unk_2C;
} structE2D730;

s32 func_802BAE00_E2D730(void);
INCLUDE_ASM(s32, "entity/jan_iwa/E2D730", func_802BAE00_E2D730);

extern u16 D_802BCE30;
extern u16 D_802BCE32;
extern u16 D_802BCE34;

void func_802BB000_E2D930(Entity* entity) {
    structE2D730* data = (structE2D730*)entity->dataBuf;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if ((entity->collisionFlags & 1) && !is_picking_up_item()) {
        if (playerStatus->actionState == ACTION_STATE_RIDE) {
            playerStatus->animFlags |= 4;
        } else if (playerStatus->actionState != ACTION_STATE_USE_SPINNING_FLOWER) {
            D_802BCE34 = data->unk_28;
            D_802BCE30 = data->unk_2A;
            D_802BCE32 = data->unk_2C;
            set_action_state(ACTION_STATE_USE_SPINNING_FLOWER);
        }
    }
}

INCLUDE_ASM(s32, "entity/jan_iwa/E2D730", func_802BB0A0_E2D9D0);

void func_802BB228_E2DB58(Entity* entity) {
    structE2D730* data = (structE2D730*)entity->dataBuf;

    func_802BB000_E2D930(entity);
    data->unk_14 += 2.0;
    if (data->unk_14 > 40.0f) {
        data->unk_14 = 40.0f;
    }
    data->unk_08 = clamp_angle(data->unk_08 + data->unk_14);
}

void func_802BB298_E2DBC8(Entity* entity) {
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_v1;
    structE2D730* data;
    s32 x, y, z;

    data = (structE2D730*)entity->dataBuf;
    x = D_8015C7D0[0];
    y = D_8015C7D0[1];
    z = D_8015C7D0[2];
    if (!(x | y | z)) {
        x = entity->position.x;
        y = entity->position.y + 100.0f;
        z = entity->position.z;
    }

    data->unk_28 = x;
    data->unk_2A = y;
    data->unk_2C = z;
    data->unk_02 = 0;
    entity->renderSetupFunc = &func_802BAE00_E2D730;
}

void func_802BB314_E2DC44(Entity* entity) {
    sfx_play_sound_at_position(0x8000006A, 0, entity->position.x, entity->position.y, entity->position.z);
}

void func_802BB34C_E2DC7C(void) {
    sfx_play_sound(0x791);
    func_80149A6C(0x391, 1);
}

s32 func_802BB374_E2DCA4(void);
INCLUDE_ASM(s32, "entity/jan_iwa/E2D730", func_802BB374_E2DCA4);

// regalloc, play_model_animation weirdness
#ifdef NON_EQUIVALENT
void func_802BB648_E2DF78(Entity* entity) {
    structE2D730* temp_a1_2;
    structE2D730* data = (structE2D730*)entity->dataBuf;

    if ((gPlayerStatus.animFlags & 0x10) && (entity->collisionFlags & 0x48)) {
        if (entity->flags & ENTITY_FLAGS_SHOWS_INSPECT_PROMPT) {
            entity->flags &= ~ENTITY_FLAGS_SHOWS_INSPECT_PROMPT;
            temp_a1_2 = (structE2D730*)get_entity_by_index(data->unk_04)->dataBuf;
            if (temp_a1_2->unk_00 == 0) {
                temp_a1_2->unk_00 = 1;
                exec_entity_commandlist(entity);
                play_model_animation(entity->virtualModelIndex, 0xF4);
            }
        }
    }
}
#else
INCLUDE_ASM(s32, "entity/jan_iwa/E2D730", func_802BB648_E2DF78);
#endif

void func_802BB6E0_E2E010(Entity* entity) {
    structE2D730* data = (structE2D730*)entity->dataBuf;
    Entity* newEntity;
    s32 entityIndex;

    get_animator_by_index(entity->virtualModelIndex)->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
    entityIndex = create_entity(&D_802BC7D0_E2F100, entity->position.x, entity->position.y, entity->position.z, 0, 0x80000000);
    data->unk_04.index = entityIndex;
    newEntity = get_entity_by_index(entityIndex);
    data = (structE2D730*)newEntity->dataBuf;
    data->unk_04.index = entity->listIndex;
    data->unk_08 = newEntity->rotation.y;
}

void func_802BB778_E2E0A8(Entity* entity) {
    entity->scale.x = 0.0f;
    entity->renderSetupFunc = &func_802BB374_E2DCA4;
}

INCLUDE_ASM(s32, "entity/jan_iwa/E2D730", func_802BB78C_E2E0BC);

void func_802BB8D4_E2E204(Entity* entity) {
    structE2D730* data = (structE2D730*)entity->dataBuf;
    data->unk_08 = fabs(dist2D(entity->position.x - 2.0f, entity->position.z - 2.0f, gPlayerStatus.position.x, gPlayerStatus.position.z) * 0.25);
    data->unk_04.f = atan2(gPlayerStatus.position.x, gPlayerStatus.position.z, entity->position.x - 2.0f, entity->position.z - 2.0f);
}

void func_802BB98C_E2E2BC(Entity* entity) {
    structE2D730* data = (structE2D730*)entity->dataBuf;
    gCameras->targetPos.x = gPlayerStatus.position.x;
    gCameras->targetPos.y = gPlayerStatus.position.y;
    gCameras->targetPos.z = gPlayerStatus.position.z;
    add_vec2D_polar(&gPlayerStatus.position.x, &gPlayerStatus.position.z, data->unk_08, data->unk_04.f);
}

#ifdef NON_EQUIVALENT // play_model_animation weirdness, branch likely in case 0
void func_802BB9E0_E2E310(Entity* entity) {
    structE2D730* data = (structE2D730*)entity->dataBuf;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 temp_f2;
    f32 phi_f4;

    switch (data->unk_00) {
        case 0:
            if (entity->collisionFlags & 1) {
                data->unk_01 = 0;
                if (partnerActionStatus->actionState.b[3] != 0) {
                    playerStatus->animFlags |= 4;
                }
                func_800EF300(partnerActionStatus);
                playerStatus->animFlags |= 0x40000;
                data->unk_02 = 4;
                data->unk_01++;
                data->unk_00++;
                disable_player_input();
                set_action_state(0);
                play_model_animation(entity->virtualModelIndex, 0x214);
                sfx_play_sound(242);
                func_802BB8D4_E2E204(entity);
            }
            break;
        case 1:
            playerStatus->animFlags |= 0x40000;
            data->unk_02--;
            if (data->unk_02 == 0) {
                start_rumble(128, 10);
                data->unk_02 = 30;
                data->unk_00++;
                temp_f2 = playerStatus->spriteFacingAngle;
                playerStatus->spriteFacingAngle = 80.0f;
                playerStatus->flags |= 0x100000;
                D_802BCE20 = temp_f2;
            }
            func_802BB98C_E2E2BC(entity);
            break;
        case 2:
            data->unk_02--;
            if ((data->unk_02) == 0) {
                data->unk_00++;
                func_802DDEE4(0, -1, 0, 0, 0, 0, 0, 0);
                func_802DDFF8(0x10002, 5, 19, 1, 1, 0, 0);
            }
            break;
        case 3:
            data->unk_00++;
            break;
        case 4:
            playerStatus->spriteFacingAngle = D_802BCE20;
            phi_f4 = 270.0f;
            if (D_802BCE20 != 0.0f) {
                phi_f4 = 90.0f;
            }
            playerStatus->targetYaw = phi_f4;
            data->unk_02 = 0x50;
            data->unk_00++;
            break;
        case 5:
            data->unk_02--;
            if ((data->unk_02) == 0) {
                data->unk_00++;
                func_802DDEE4(0, -1, 0, 0, 0, 0, 0, 0);
                enable_player_input();
                playerStatus->flags &= ~0x100000;
            }
            break;
        case 6:
            if (!(entity->collisionFlags & 1) && (partnerActionStatus->actionState.b[0] == 0)) {
                data->unk_00 = 0;
                enable_partner_ai();
                phys_adjust_cam_on_landing();
            }
            break;
    }
}
#else
INCLUDE_ASM(s32, "entity/jan_iwa/E2D730", func_802BB9E0_E2E310);
#endif
