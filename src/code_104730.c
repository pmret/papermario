#include "common.h"

extern UNK_TYPE D_0A0031E0;
extern UNK_TYPE D_0A001508;
extern UNK_TYPE D_0A0031B0;
extern UNK_TYPE D_0A0014D8;
extern UNK_TYPE D_0A002F78;
extern UNK_TYPE D_0A001218;
extern UNK_TYPE D_0A003F70;
extern UNK_TYPE D_0A002318;

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

//ROM addrs; todo
extern UNK_TYPE D_00E32420;
extern UNK_TYPE D_00E35670;
extern UNK_TYPE D_00E38890;
extern UNK_TYPE D_00E3B870;
extern UNK_TYPE D_00E3E260;
extern UNK_TYPE D_00E42240;

extern StaticEntityData D_802E9C8C;
extern StaticEntityData D_802E9CB0;
extern StaticEntityData D_802E9CD4;
extern StaticEntityData D_802E9CF8;
extern StaticEntityData D_802E9D1C;
extern StaticEntityData D_802E9D40;
extern StaticEntityData D_802E9D64;

void func_802E2FD0(Entity* entity) {
    u32 type;
    StaticEntityData* addr = NULL;

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