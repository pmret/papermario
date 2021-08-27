#include "common.h"
#include "effects.h"

// size unknown
typedef struct structE307C0 {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ s8 unk_04;
    /* 0x05 */ s8 unk_05;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
} structE307C0;

extern u8 D_802BCAA0_E313F0[];

s32 func_802BBE70_E307C0(void);
INCLUDE_ASM(s32, "entity/sbk_omo/E307C0", func_802BBE70_E307C0);

void func_802BC2BC_E30C0C(Entity* entity) {
    u16 currentFloor = gCollisionStatus.currentFloor;
    structE307C0* data = (structE307C0*)entity->dataBuf;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 actionState = playerStatus->actionState;
    f32 x,y,z,sp2C;
    s32 result = 0;

    if (((currentFloor & 0x4000) != 0) && ((currentFloor & 0xFF) == entity->listIndex) && (actionState == 0x12)) {
        x = playerStatus->position.x;
        y = playerStatus->position.y + 5.0f;
        z = playerStatus->position.z;
        sp2C = 10.0f;

        add_vec2D_polar(&x, &z, 10.0f, func_800E5348());
        if (npc_raycast_down_sides(0x10000, &x, &y, &z, &sp2C) != 0) {
            if ((D_8010C978 & 0x4000) != 0) {
                result = get_entity_type(D_8010C978) == 0x31;
            }
        }
    } else if (((entity->collisionFlags & 1) != 0) && ((actionState == 0xE) || (actionState == 0x10))) {
        result = 1;
    } else if ((entity->collisionFlags & 0x40) != 0) {
        result = -1;
    }

    if (result != 0) {
        data->unk_02 &= 0xFE;
        playFX_18(3, entity->position.x, entity->position.y + 35.0f, entity->position.z, 0, -1.0f, 0, 3);
        if (result > 0) {
            data->unk_02 |= 1;
        }
        entity->position.y -= 2.0f;
        exec_entity_commandlist(entity);
        data->unk_01 = 4;
        disable_player_static_collisions();
        playerStatus->unk_C5 = 5;
    }
}

void func_802BC4B8_E30E08(Entity* entity) {
    structE307C0* data = (structE307C0*)entity->dataBuf;
    s32 i;

    data->unk_04--;
    if (data->unk_04 <= 0) {
        i = data->unk_03;
        if (D_802BCAA0_E313F0[i] != 0xFF) {
            data->unk_05 = D_802BCAA0_E313F0[i++];
            data->unk_04 = D_802BCAA0_E313F0[i++];
            data->unk_03 = i;
        }
    }
}

void func_802BC514_E30E64(Entity* entity) {
    structE307C0* data = (structE307C0*)entity->dataBuf;
    entity->position.x = data->unk_08 + (data->unk_01 & 1 ? 1.0f : -1.0f);
    data->unk_01 -= 1;
}

void func_802BC558_E30EA8(Entity* entity) {
    structE307C0* data = (structE307C0*)entity->dataBuf;
    entity->position.x = data->unk_08;
    entity->position.z = data->unk_0C;
}

INCLUDE_ASM(s32, "entity/sbk_omo/E307C0", func_802BC570_E30EC0);

void func_802BC99C_E312EC(Entity* entity) {
    if ((entity->flags & 0x2000000) == 0) {
        exec_entity_commandlist(entity);
    }
}

void func_802BC9CC_E3131C(Entity* entity) {
    structE307C0* data = (structE307C0*)entity->dataBuf;
    if ((data->unk_02 & 1) != 0) {
        entity_start_script(entity);
    }
}

void func_802BC9FC_E3134C(Entity* entity) {
    structE307C0* data = (structE307C0*)entity->dataBuf;
    entity->renderSetupFunc = &func_802BBE70_E307C0;
    data->unk_08 = entity->position.x;
    data->unk_10 = entity->position.y;
    data->unk_0C = entity->position.z;
}
