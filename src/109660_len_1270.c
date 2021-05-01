#include "common.h"
#include "map.h"

typedef struct struct802E7DE0 {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ s32 unk_004;
    /* 0x008 */ u8* unk_008;
    /* 0x00C */ s32 unk_00C;
    /* 0x010 */ u8 unk_010[36];
    /* 0x034 */ s8 unk_034[36];
    /* 0x058 */ u8 unk_058[36];
    /* 0x07C */ u8 unk_07C[36];
    /* 0x0A0 */ u8 unk_0A0[36];
    /* 0x0C4 */ f32 unk_0C4[36];
    /* 0x154 */ f32 unk_154[36];
    /* 0x1E4 */ f32 unk_1E4[36];
    /* 0x274 */ f32 unk_274[36];
    /* 0x304 */ f32 unk_304[36];
} struct802E7DE0;

INCLUDE_ASM(s32, "109660_len_1270", func_802E7DE0);

typedef struct struct802E7F40 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ char unk_06[6];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ char unk_10[4];
    /* 0x14 */ s32 unk_14;
} struct802E7F40;

void func_802E7F40(Entity* entity) {
    struct802E7F40* temp = entity->dataBuf;

    entity->scale.y = 0.85714287f;
    temp->unk_00 = D_8015C7D0[0];
    temp->unk_04 = 0xFFFF;
}

void func_802E7F6C(Entity* entity) {
    struct802E7F40* temp = entity->dataBuf;

    temp->unk_0C = entity->position.y;
    func_802E7DE0(entity, &D_0A004350, &D_0A0026F0);
}

INCLUDE_ASM(s32, "109660_len_1270", func_802E7FA0);

INCLUDE_ASM(s32, "109660_len_1270", func_802E854C);

s32 func_802E8858(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 phi_a0 = FALSE;

    if (entity->collisionFlags & 1) {
        if ((playerStatus->actionState == ACTION_STATE_GROUND_POUND) || (playerStatus->actionState == ACTION_STATE_ULTRA_POUND)) {
            set_action_state(ACTION_STATE_FALLING);
            phi_a0 = TRUE;
        }
    }

    if (phi_a0) {
        func_802E7F6C(entity);
        func_80110BCC(entity, &D_802EAE7C);
        func_80110678(entity);
        exec_entity_updatecmd(entity);
        sfx_play_sound(0x20AE);
    }
}

f32 func_800E546C(void);

void func_802E88EC(Entity* entity, f32 arg1) {
    struct802E7F40* temp = entity->dataBuf;

    if (temp->unk_00 != -1) {
        s32 flag = FALSE;

        // can't do || here, or gcc realizes it can reuse the temp->unk_04 load
        if (temp->unk_04 == 0xFFFF) {
            flag = TRUE;
        } else if (!get_global_flag(temp->unk_04)) {
            flag = TRUE;
        }

        if (flag) {
            make_item_entity(temp->unk_00, entity->position.x, entity->position.y + 33.0, entity->position.z, 0xA, 0,
                             func_800E546C(), temp->unk_04);
        }
    }
}
