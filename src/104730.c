#include "common.h"
#include "ld_addrs.h"

void entity_shattering_block_init(Entity* entity);

extern UNK_TYPE D_802E9170;
extern UNK_TYPE D_802E91F0;
extern UNK_TYPE D_802E9270;
extern UNK_TYPE D_802E92B0;

extern UNK_TYPE D_0A000740;
extern UNK_TYPE D_0A000EE8;
extern UNK_TYPE D_0A000EF8;
extern UNK_TYPE D_0A001218;
extern UNK_TYPE D_0A0014D8;
extern UNK_TYPE D_0A001508;
extern UNK_TYPE D_0A002318;
extern UNK_TYPE D_0A002F78;
extern UNK_TYPE D_0A0031B0;
extern UNK_TYPE D_0A0031E0;
extern UNK_TYPE D_0A003508;
extern UNK_TYPE D_0A003F70;

Gfx D_802E96F0[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

Gfx D_802E9738[] = {
    gsSPDisplayList(D_802E96F0),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureTile_4b(&D_802E9170, G_IM_FMT_I, 16, 0, 0, 0, 15, 15, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSPEndDisplayList(),
};

Gfx D_802E9788[] = {
    gsSPDisplayList(D_802E96F0),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureTile_4b(&D_802E91F0, G_IM_FMT_I, 16, 0, 0, 0, 15, 15, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSPEndDisplayList(),
};

Gfx D_802E97B0[] = {
    gsSPDisplayList(D_802E9738),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&D_802E92B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_802E97D8[] = {
    gsSPDisplayList(D_802E9788),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&D_802E9270, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_802E9828[] = {
    gsSPEndDisplayList(),
};

// Entity "script" data; unknown if it's used or not.
s32 D_802E9830[8] = {
    0x00000001, 0x0000003C, (s32)D_802E9828, 0x00000002,
    0x00000000, 0x00000000, 0x00000000, 0x00000000
};

s32 D_802E9850[9] = {
    0x00000005, 0x00000800, 0x00000004, 0x00000020,
    0x00000001, 0x0000003C, (s32)D_802E97D8, 0x00000002,
    0x00000000
};

s32 D_802E9874[9] = {
    0x00000005, 0x00000800, 0x00000004, 0x00000020,
    0x00000001, 0x0000003C, (s32)D_802E97D8, 0x00000002,
    0x00000000
};
s32 D_802E9898[9] = {
    0x00000005, 0x00000800, 0x00000004, 0x00000020,
    0x00000001, 0x0000003C, (s32)D_802E97B0, 0x00000002,
    0x00000000,
};

StaticShadowData D_802E98BC = {
    .flags = SHADOW_FLAGS_20,
    .unk_04 = D_802E9850,
    .animModelNode =  NULL,
    .onCreateCallback = entity_Shadow_init,
    .unk_20 = 0x01190A19,
};

StaticShadowData D_802E98E0 = {
    .flags = SHADOW_FLAGS_20,
    .unk_04 = D_802E9874,
    .animModelNode =  NULL,
    .onCreateCallback = entity_Shadow_init,
    .unk_20 = 0x01190A19,
};

StaticShadowData D_802E9904 = {
    .flags = SHADOW_FLAGS_20,
    .unk_04 = D_802E9898,
    .animModelNode =  NULL,
    .onCreateCallback = entity_Shadow_init,
    .unk_20 = 0x01190A19,
};

s32 D_802E9928[2] = {
    0x00000000, 0x00000000
};

s32 D_802E9930[51] = {
    0x00000003, 0x00000000, (s32)entity_SaveBlock_idle, 0x00000009,
    0x0000014E, 0x00000002, (s32)entity_SaveBlock_pause_game, 0x00000002,
    (s32)entity_block_hit_init_scale, 0x00000003, 0x00000006, (s32)entity_block_hit_animate_scale,
    0x00000003, 0x00000002, 0x00000000, 0x00000002,
    (s32)entity_SaveBlock_show_tutorial_message, 0x00000003, 0x00000000, (s32)entity_SaveBlock_wait_for_close_tutorial,
    0x00000003, 0x0000000E, 0x00000000, 0x00000002,
    (s32)entity_SaveBlock_show_choice_message, 0x00000003, 0x00000000, (s32)entity_SaveBlock_wait_for_close_choice,
    0x00000002, (s32)entity_SaveBlock_save_data, 0x00000002, (s32)entity_SaveBlock_show_result_message,
    0x00000003, 0x00000000, (s32)entity_SaveBlock_wait_for_close_result, 0x00000002,
    (s32)entity_SaveBlock_resume_game, 0x00000003, 0x0000000C, 0x00000000,
    0x00000004, 0x00000000, 0x00000000, 0x00000002,
    (s32)entity_SaveBlock_resume_game, 0x00000003, 0x00000002, 0x00000000,
    0x00000001, (s32)D_802E9930, 0x00000000,
};

s32 D_802E99FC[7] = {
    0x00000004, 0x00000022, 0x00000001, 0x0000003C,
    &D_0A003508, 0x00000002, 0x00000000,
};

StaticEntityData Entity_SavePoint = { 0x4200, 0x0020, &D_802E99FC, {0, 0, 0, 0}, entity_SaveBlock_init, &D_802E9930, entity_block_handle_collision, E4B2E0_ROM_START, E4B2E0_ROM_END, 32, {0x19, 0x19, 0x19}};

// potential file split(?)
s32 D_802E9A3C[1] = {
    0x00000000
};

s32 D_802E9A40[18] = {
    0x00000003, 0x00000000, (s32)entity_small_switch_idle, 0x00000009,
    0x00000152, 0x00000002, (s32)entity_base_switch_start_bound_script, 0x00000002,
    (s32)entity_base_switch_anim_init, 0x00000003, 0x00000000, (s32)entity_RedSwitch_animate_scale,
    0x00000003, 0x00000000, (s32)entity_RedSwitch_wait_and_reset, 0x00000004,
    0x00000000, 0x00000000,
};

s32 D_802E9A88[15] = {
    0x00000003, 0x00000000, (s32)entity_HugeBlueSwitch_idle, 0x00000009,
    0x00000152, 0x00000002, (s32)entity_base_switch_start_bound_script, 0x00000002,
    (s32)entity_base_switch_anim_init, 0x00000003, 0x00000000, (s32)entity_base_switch_animate_scale,
    0x00000007, 0x20000000, 0x00000000
};

s32 D_802E9AC4[15] = {
    0x00000003, 0x00000000, (s32)entity_small_switch_idle, 0x00000009,
    0x00000152, 0x00000002, (s32)entity_base_switch_start_bound_script, 0x00000002,
    (s32)entity_base_switch_anim_init, 0x00000003, 0x00000000, (s32)entity_base_switch_animate_scale,
    0x00000007, 0x20000000, 0x00000000
};

s32 D_802E9B00[16] = {
    0x00000003, 0x00000000, (s32)entity_GreenStompSwitch_idle, 0x00000003,
    0x00000000, (s32)entity_GreenStompSwitch_retract, 0x00000009, 0x00000152,
    0x00000003, 0x00000080, 0x00000000, 0x00000003,
    0x00000000, (s32)entity_GreenStompSwitch_extend, 0x00000004, 0x00000000,
};

s32 D_802E9B40[7] = {
    0x00000004, 0x00000011, 0x00000001, 0x0000003C,
    &D_0A000EF8, 0x00000002, 0x00000000,
};

s32 D_802E9B5C[7] = {
    0x00000004, 0x00000011, 0x00000001, 0x0000003C,
    (s32) &D_0A000EF8, 0x00000002, 0x00000000,
};

s32 D_802E9B78[7] = {
    0x00000004, 0x00000011, 0x00000001, 0x0000003C,
    (s32) &D_0A000EE8, 0x00000002, 0x00000000
};

s32 D_802E9B94[7] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C,
    (s32) &D_0A000740, 0x00000002, 0x00000000,
};

StaticEntityData Entity_RedSwitch = { 0xA000, 0x002C, &D_802E9B78, {0, 0, 0, 0}, entity_base_switch_init,    &D_802E9A40, NULL, E62AC0_ROM_START, E62AC0_ROM_END, ENTITY_TYPE_RED_SWITCH, {0x16, 0x17, 0x16} };
StaticEntityData Entity_BlueSwitch = { 0xAA04, 0x002C, &D_802E9B40, {0, 0, 0, 0}, entity_BlueSwitch_init,     &D_802E9AC4, NULL, E639C0_ROM_START, E639C0_ROM_END, ENTITY_TYPE_BLUE_SWITCH, {0x16, 0x17, 0x16} };
StaticEntityData Entity_HugeBlueSwitch = { 0xAA04, 0x002C, &D_802E9B5C, {0, 0, 0, 0}, entity_HugeBlueSwitch_init, &D_802E9A88, NULL, E639C0_ROM_START, E639C0_ROM_END, ENTITY_TYPE_HUGE_BLUE_SWITCH, {0x42, 0x4B, 0x42} };
StaticEntityData Entity_GreenStompSwitch = { 0xC000, 0x002C, &D_802E9B94, {0, 0, 0, 0}, entity_base_switch_init,    &D_802E9B00, NULL, E62370_ROM_START, E62370_ROM_END, ENTITY_TYPE_GREEN_STOMP_SWITCH, {0x32, 0x0F, 0x32} };

s32 D_802E9C40[12] = {
    0x00000007, 0x00000020, 0x00000003, 0x00000000,
    entity_shattering_idle, 0x00000007, 0x00000001, 0x00000007,
    0x20000000, 0x00000000, 0x00000000, 0x00000000
};

s32 D_802E9C70[7] = {
    0x00000004, 0x00000011, 0x00000001, 0x0000003C,
    (s32) &D_802E9828, 0x00000002, 0x00000000
};

StaticEntityData Entity_ShatteringHammer1Block = { 0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, entity_shattering_block_init, &D_802E9C40, NULL, E32420_ROM_START, E32420_ROM_END, ENTITY_TYPE_HAMMER1_BLOCK, {0x10, 0x10, 0x10}};
StaticEntityData Entity_ShatteringHammer2Block = { 0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, entity_shattering_block_init, &D_802E9C40, NULL, E35670_ROM_START, E35670_ROM_END, ENTITY_TYPE_HAMMER2_BLOCK, {0x10, 0x10, 0x10}};
StaticEntityData Entity_ShatteringHammer3Block = { 0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, entity_shattering_block_init, &D_802E9C40, NULL, E38890_ROM_START, E38890_ROM_END, ENTITY_TYPE_HAMMER3_BLOCK, {0x10, 0x10, 0x10}};
StaticEntityData Entity_ShatteringHammer1BlockTiny = { 0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, entity_shattering_block_init, &D_802E9C40, NULL, E32420_ROM_START, E32420_ROM_END, ENTITY_TYPE_HAMMER1_BLOCK_TINY, {0x08, 0x08, 0x08}};
StaticEntityData Entity_ShatteringHammer2BlockTiny = { 0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, entity_shattering_block_init, &D_802E9C40, NULL, E35670_ROM_START, E35670_ROM_END, ENTITY_TYPE_HAMMER2_BLOCK_TINY, {0x08, 0x08, 0x08}};
StaticEntityData Entity_ShatteringHammer3BlockTiny = { 0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, entity_shattering_block_init, &D_802E9C40, NULL, E38890_ROM_START, E38890_ROM_END, ENTITY_TYPE_HAMMER3_BLOCK_TINY, {0x08, 0x08, 0x08}};
StaticEntityData Entity_ShatteringBrickBlock = { 0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, entity_shattering_block_init, &D_802E9C40, NULL, E3E260_ROM_START, E3E260_ROM_END, ENTITY_TYPE_BRICK_BLOCK, {0x08, 0x08, 0x08}};

void entity_shattering_block_init(Entity* entity) {
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
            sfx_play_sound_at_position(0x158, 0, entity->position.x, entity->position.y, entity->position.z);
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
    u32 type;
    StaticEntityData* addr = NULL;

    type = get_entity_type(entity->listIndex);

    switch (type) {
        case ENTITY_TYPE_HAMMER1_BLOCK:
            addr = &Entity_ShatteringHammer1Block;
            break;
        case ENTITY_TYPE_HAMMER1_BLOCK_TINY:
            addr = &Entity_ShatteringHammer1BlockTiny;
            break;
        case ENTITY_TYPE_HAMMER2_BLOCK:
            addr = &Entity_ShatteringHammer2Block;
            break;
        case ENTITY_TYPE_HAMMER2_BLOCK_TINY:
            addr = &Entity_ShatteringHammer2BlockTiny;
            break;
        case ENTITY_TYPE_HAMMER3_BLOCK:
            addr = &Entity_ShatteringHammer3Block;
            break;
        case ENTITY_TYPE_HAMMER3_BLOCK_TINY:
            addr = &Entity_ShatteringHammer3BlockTiny;
            break;
        case ENTITY_TYPE_BRICK_BLOCK:
            addr = &Entity_ShatteringBrickBlock;
            break;
        case ENTITY_TYPE_MULTI_COIN_BRICK:
        case ENTITY_TYPE_YELLOW_BLOCK:
        case ENTITY_TYPE_SINGLE_TRIGGER_BLOCK:
        case ENTITY_TYPE_HIDDEN_YELLOW_BLOCK:
        case ENTITY_TYPE_HIDDEN_RED_BLOCK:
        case ENTITY_TYPE_INACTIVE_BLOCK:
            break;
    }

    if (addr == NULL) {
        return;
    }

    create_entity(addr, entity->position.x, entity->position.y, entity->position.z, 0, 0x80000000);
}
