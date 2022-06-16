#include "common.h"
#include "ld_addrs.h"

void entity_shattering_block_init(Entity* entity);

extern UNK_TYPE D_802E9170;
extern UNK_TYPE D_802E91F0;
extern UNK_TYPE D_802E9270;
extern UNK_TYPE D_802E92B0;

extern UNK_TYPE D_0A001218;
extern UNK_TYPE D_0A0014D8;
extern UNK_TYPE D_0A001508;
extern UNK_TYPE D_0A002318;
extern UNK_TYPE D_0A002F78;
extern UNK_TYPE D_0A0031B0;
extern UNK_TYPE D_0A0031E0;
extern UNK_TYPE D_0A003F70;

void entity_shattering_block_init(Entity* entity);

extern Gfx D_802E9828[];

s32 D_802E9C40[12] = {
    0x00000007, 0x00000020, 0x00000003, 0x00000000,
    entity_shattering_idle, 0x00000007, 0x00000001, 0x00000007,
    0x20000000, 0x00000000, 0x00000000, 0x00000000
};

s32 D_802E9C70[7] = {
    0x00000004, 0x00000011, 0x00000001, 0x0000003C,
    (s32) &D_802E9828, 0x00000002, 0x00000000
};

EntityBlueprint Entity_ShatteringHammer1Block = {
    0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, entity_shattering_block_init, &D_802E9C40, NULL, E32420_ROM_START, E32420_ROM_END, ENTITY_TYPE_HAMMER1_BLOCK, {0x10, 0x10, 0x10}
};
EntityBlueprint Entity_ShatteringHammer2Block = {
    0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, entity_shattering_block_init, &D_802E9C40, NULL, E35670_ROM_START, E35670_ROM_END, ENTITY_TYPE_HAMMER2_BLOCK, {0x10, 0x10, 0x10}
};
EntityBlueprint Entity_ShatteringHammer3Block = {
    0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, entity_shattering_block_init, &D_802E9C40, NULL, E38890_ROM_START, E38890_ROM_END, ENTITY_TYPE_HAMMER3_BLOCK, {0x10, 0x10, 0x10}
};
EntityBlueprint Entity_ShatteringHammer1BlockTiny = {
    0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, entity_shattering_block_init, &D_802E9C40, NULL, E32420_ROM_START, E32420_ROM_END, ENTITY_TYPE_HAMMER1_BLOCK_TINY, {0x08, 0x08, 0x08}
};
EntityBlueprint Entity_ShatteringHammer2BlockTiny = {
    0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, entity_shattering_block_init, &D_802E9C40, NULL, E35670_ROM_START, E35670_ROM_END, ENTITY_TYPE_HAMMER2_BLOCK_TINY, {0x08, 0x08, 0x08}
};
EntityBlueprint Entity_ShatteringHammer3BlockTiny = {
    0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, entity_shattering_block_init, &D_802E9C40, NULL, E38890_ROM_START, E38890_ROM_END, ENTITY_TYPE_HAMMER3_BLOCK_TINY, {0x08, 0x08, 0x08}
};
EntityBlueprint Entity_ShatteringBrickBlock = {
    0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, entity_shattering_block_init, &D_802E9C40, NULL, E3E260_ROM_START, E3E260_ROM_END, ENTITY_TYPE_BRICK_BLOCK, {0x08, 0x08, 0x08}
};

void entity_shattering_block_init(Entity* entity) {
    u32 type;
    void* a2 = NULL;
    void* a1 = NULL;

    //TODO must be HAMMER BLOCK TYPE!
    entity->dataBuf.swtch->unk_38 = entity->position.y;
    type = get_entity_type((u8)entity->listIndex);

    if (type == ENTITY_TYPE_HAMMER1_BLOCK_TINY ||
        type == ENTITY_TYPE_HAMMER2_BLOCK_TINY ||
        type == ENTITY_TYPE_HAMMER3_BLOCK_TINY)
    {
        entity->scale.x = 0.5f;
        entity->scale.y = 0.5f;
        entity->scale.z = 0.5f;
    }

    switch (type) {
        case ENTITY_TYPE_HAMMER1_BLOCK:
        case ENTITY_TYPE_HAMMER1_BLOCK_TINY:
            a1 = &D_0A0031E0;
            a2 = &D_0A001508;
            break;
        case ENTITY_TYPE_HAMMER2_BLOCK:
        case ENTITY_TYPE_HAMMER2_BLOCK_TINY:
            a1 = &D_0A0031B0;
            a2 = &D_0A0014D8;
            break;
        case ENTITY_TYPE_HAMMER3_BLOCK:
        case ENTITY_TYPE_HAMMER3_BLOCK_TINY:
            a1 = &D_0A002F78;
            a2 = &D_0A001218;
            break;
        case ENTITY_TYPE_BRICK_BLOCK:
            sfx_play_sound_at_position(SOUND_158, 0, entity->position.x, entity->position.y, entity->position.z);
            a1 = &D_0A003F70;
            a2 = &D_0A002318;
            break;
        case ENTITY_TYPE_MULTI_COIN_BRICK:
        case ENTITY_TYPE_YELLOW_BLOCK:
        case ENTITY_TYPE_SINGLE_TRIGGER_BLOCK:
        case ENTITY_TYPE_HIDDEN_YELLOW_BLOCK:
        case ENTITY_TYPE_HIDDEN_RED_BLOCK:
        case ENTITY_TYPE_INACTIVE_BLOCK:
            break;
    }

    if (a2 == NULL) {
        return;
    }

    entity_shattering_init_pieces(entity, a1, a2);
}

void entity_breakable_block_create_shattering_entity(Entity* entity) {
    EntityBlueprint* bp = NULL;

    switch (get_entity_type(entity->listIndex)) {
        case ENTITY_TYPE_HAMMER1_BLOCK:
            bp = &Entity_ShatteringHammer1Block;
            break;
        case ENTITY_TYPE_HAMMER1_BLOCK_TINY:
            bp = &Entity_ShatteringHammer1BlockTiny;
            break;
        case ENTITY_TYPE_HAMMER2_BLOCK:
            bp = &Entity_ShatteringHammer2Block;
            break;
        case ENTITY_TYPE_HAMMER2_BLOCK_TINY:
            bp = &Entity_ShatteringHammer2BlockTiny;
            break;
        case ENTITY_TYPE_HAMMER3_BLOCK:
            bp = &Entity_ShatteringHammer3Block;
            break;
        case ENTITY_TYPE_HAMMER3_BLOCK_TINY:
            bp = &Entity_ShatteringHammer3BlockTiny;
            break;
        case ENTITY_TYPE_BRICK_BLOCK:
            bp = &Entity_ShatteringBrickBlock;
            break;
        case ENTITY_TYPE_MULTI_COIN_BRICK:
        case ENTITY_TYPE_YELLOW_BLOCK:
        case ENTITY_TYPE_SINGLE_TRIGGER_BLOCK:
        case ENTITY_TYPE_HIDDEN_YELLOW_BLOCK:
        case ENTITY_TYPE_HIDDEN_RED_BLOCK:
        case ENTITY_TYPE_INACTIVE_BLOCK:
            break;
    }

    if (bp == NULL) {
        return;
    }

    create_entity(bp, entity->position.x, entity->position.y, entity->position.z, 0, MAKE_ENTITY_END);
}
