#include "common.h"

typedef struct struct802E1400 {
    /* 0x000 */ Vec3f unk_00;
    /* 0x00C */ char unk_0C[4];
    /* 0x010 */ s8 unk_10;
    /* 0x011 */ s8 unk_11;
    /* 0x014 */ Vec3f unk_14;
    /* 0x020 */ u16 unk_20;
    /* 0x022 */ s16 unk_22;
    /* 0x024 */ char unk_24[4];
    /* 0x028 */ Entity* attachedEntity;
    /* 0x02C */ char unk_2C[12];
    /* 0x038 */ f32 unk_38;
} struct802E1400;

void func_802E246C(Entity* entity, void* arg1, void* arg2);

void func_802E1400(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    struct802E1400* temp = (struct802E1400*)entity->dataBuf;

    if (entity->unk_06 & 1) {
        if ((playerStatus->actionState == ActionState_GROUND_POUND) || (playerStatus->actionState == ActionState_ULTRA_POUND)) {
            func_8010FD68(entity);
            temp->unk_22 = 8;
        }
    }
}

void func_802E1460(Entity* entity) {
    struct802E1400* temp = (struct802E1400*)entity->dataBuf;
    u16 temp2 = temp->unk_22--;

    if (temp2) {
        entity->position.y -= D_802EB000;
        return;
    }
    func_80110678(entity);
    func_8010FD68(entity);
    temp->unk_22 = 8;
}

void func_802E14D8(Entity* entity) {
    struct802E1400* temp = (struct802E1400*)entity->dataBuf;
    u16 temp2 = temp->unk_22--;

    if (temp2) {
        entity->position.y += D_802EB008;
        return;
    }
    func_8010FD68(entity);
    temp->unk_22 = 8;
}

INCLUDE_ASM(s32, "code_102c80", func_802E153C);

void func_802E1614(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (entity->unk_06 & 1) {
        if ((playerStatus->actionState == ActionState_GROUND_POUND)
            || (playerStatus->actionState == ActionState_ULTRA_POUND)) {
            func_8010FD68(entity);
        }
    }
}

void func_802E1660(Entity* entity) {
    struct802E1400* temp = (struct802E1400*)entity->dataBuf;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s8* temp2 = D_8010EBB0;

    func_802E153C(entity);

    if (entity->unk_06 & 0x40) {
        if (playerStatus->actionState == ActionState_HAMMER) {
            if (gPlayerData.hammerLevel < 0) {
                return;
            }
            func_8010FD68(entity);

            if (temp->attachedEntity == NULL) {
                return;
            }

            func_8010FD68(temp->attachedEntity);
            return;
        }
    }

    if (playerStatus->actionState == ActionState_SPIN_JUMP) {
        return;
    }

    if (temp2[3] == 4) {
        if (temp2[0] != 0) {
            return;
        }
    }

    if (!(entity->unk_06 & 1)) {
        if (!(entity->unk_06 & 0x80)) {
            return;
        }
    }

    func_8010FD68(entity);

    if (temp->attachedEntity == NULL) {
        return;
    }

    func_8010FD68(temp->attachedEntity);
}

void func_802E1740(Entity* entity) {
    if (!(entity->unk_06 & 1)) {
        func_8010FD68(entity);
    }
}

void func_802E176C(Entity* entity) {
    struct802E1400* temp = (struct802E1400*)entity->dataBuf;

    temp->unk_00.x = 1.0f;
    temp->unk_00.y = 0.1f;
    temp->unk_00.z = -0.1f;
    temp->unk_10 = 0;
    temp->unk_11 = 0;
}

INCLUDE_ASM(s32, "code_102c80", func_802E17A8);

void func_802E1EA8(Entity* entity) {
    struct802E1400* temp = (struct802E1400*)entity->dataBuf;
    set_area_flag(temp->unk_20);
    func_80110678(entity);
}

INCLUDE_ASM(s32, "code_102c80", func_802E1EDC);

void func_802E234C(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    struct802E1400* temp = (struct802E1400*)entity->dataBuf;

    playerStatus->animFlags |= 0x1000000;
    temp->unk_14.x = 1.0f;
    temp->unk_14.y = 1.0f;
    temp->unk_14.z = 1.0f;
}

void entity_init_BlueSwitch(Entity* entity) {
    Entity* temp_v0_2;
    struct802E1400* temp = (struct802E1400*)entity->dataBuf;

    func_802E234C(entity);
    if (D_8015C7D0 == 2) {
        D_802EB3A0 = entity;
        return;
    }

    if (D_8015C7D0 == 1) {
        if (D_802EB3A0 != NULL) {
            temp->attachedEntity = D_802EB3A0;
            entity->flags |= 1;
            return;
        }
    } else {
        D_802EB3A0 = NULL;
    }
}

void entity_init_HugeBlueSwitch(Entity* entity) {
    struct802E1400* temp;

    func_802E234C(entity);
    temp = (struct802E1400*)entity->dataBuf;
    entity->scale.x = 3.0f;
    entity->scale.y = 3.0f;
    entity->scale.z = 3.0f;
    temp->unk_14.x = 3.0f;
    temp->unk_14.y = 3.0f;
    temp->unk_14.z = 3.0f;
}

void func_802E2450(Entity* entity) {
    func_802E3650(entity);
}


INCLUDE_ASM(void, "code_102c80", func_802E246C, Entity* entity, void* arg1, void* arg2);

INCLUDE_ASM(s32, "code_102c80", func_802E263C);

INCLUDE_ASM(s32, "code_102c80", func_802E2BA4);

#ifdef NON_MATCHING
// Needs rodata support
void func_802E2EB0(Entity* entity) {
    u32 type;
    void* a2 = NULL;
    void* a1 = NULL;

    ((struct802E1400*)entity->dataBuf)->unk_38 = entity->position.y;
    type = get_entity_type((u8)entity->listIndex);

    if ((type - 24) < 3) {
        entity->scale.x = 0.5f;
        entity->scale.y = 0.5f;
        entity->scale.z = 0.5f;
    }

    switch (type) {
        case 21:
        case 24:
            a1 = &D_0A0031E0;
            a2 = &D_0A001508;
            break;
        case 22:
        case 25:
            a1 = &D_0A0031B0;
            a2 = &D_0A0014D8;
            break;
        case 23:
        case 26:
            a1 = &D_0A002F78;
            a2 = &D_0A001218;
            break;
        case 13:
            play_sound_at_position(0x158, 0, entity->position.x, entity->position.y, entity->position.z);
            a1 = &D_0A003F70;
            a2 = &D_0A002318;
            break;
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            break;
    }

    if (a2 == NULL) {
        return;
    }

    func_802E246C(entity, a1, a2);
}
#else
INCLUDE_ASM(void, "code_102c80", func_802E2EB0, Entity* entity);
#endif

#ifdef NON_MATCHING
//Needs rodata support
void func_802E2FD0(Entity* entity) {
    u32 type;
    void* addr = NULL;

    type = get_entity_type(entity->listIndex);

    switch (type) {
        case 21:
            addr = &D_802E9C8C;
            break;
        case 24:
            addr = &D_802E9CF8;
            break;
        case 22:
            addr = &D_802E9CB0;
            break;
        case 25:
            addr = &D_802E9D1C;
            break;
        case 23:
            addr = &D_802E9CD4;
            break;
        case 26:
            addr = &D_802E9D40;
            break;
        case 13:
            addr = &D_802E9D64;
            break;
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            break;
    }

    if (addr == NULL) {
        return;
    }

    create_entity(addr, entity->position.x, entity->position.y, entity->position.z, 0, 0x80000000);
}
#else
INCLUDE_ASM(s32, "code_102c80", func_802E2FD0);
#endif
