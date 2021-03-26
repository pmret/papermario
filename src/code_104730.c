#include "common.h"

void func_802E2EB0(Entity* entity);

extern UNK_TYPE D_802E9170;
extern UNK_TYPE D_802E91F0;
extern UNK_TYPE D_802E9270;
extern UNK_TYPE D_802E92B0;

extern UNK_TYPE D_0A003508;
extern UNK_TYPE D_00E4B2E0;
extern UNK_TYPE D_00E4E7F0;
extern UNK_TYPE D_0A000EF8;
extern UNK_TYPE D_0A000EF8;
extern UNK_TYPE D_0A000EE8;
extern UNK_TYPE D_0A000740;

extern UNK_TYPE D_00E62AC0;
extern UNK_TYPE D_00E639C0;
extern UNK_TYPE D_00E639C0;
extern UNK_TYPE D_00E648D0;
extern UNK_TYPE D_00E639C0;
extern UNK_TYPE D_00E648D0;
extern UNK_TYPE D_00E62370;
extern UNK_TYPE D_00E62AC0;

extern UNK_TYPE D_0A0031E0;
extern UNK_TYPE D_0A001508;
extern UNK_TYPE D_0A0031B0;
extern UNK_TYPE D_0A0014D8;
extern UNK_TYPE D_0A002F78;
extern UNK_TYPE D_0A001218;
extern UNK_TYPE D_0A003F70;
extern UNK_TYPE D_0A002318;

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
    gsSPDisplayList(&D_802E96F0),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureTile_4b(&D_802E9170, G_IM_FMT_I, 16, 0, 0, 0, 15, 15, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSPEndDisplayList(),
};

Gfx D_802E9788[] = {
    gsSPDisplayList(&D_802E96F0),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureTile_4b(&D_802E91F0, G_IM_FMT_I, 16, 0, 0, 0, 15, 15, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSPEndDisplayList(),
};

Gfx D_802E97B0[] = {
    gsSPDisplayList(&D_802E9738),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&D_802E92B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_802E97D8[] = {
    gsSPDisplayList(&D_802E9788),
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
    0x00000001, 0x0000003C, (s32) &D_802E9828, 0x00000002,
    0x00000000, 0x00000000, 0x00000000, 0x00000000
};

s32 D_802E9850[9] = {
    0x00000005, 0x00000800, 0x00000004, 0x00000020,
    0x00000001, 0x0000003C, (s32) &D_802E97D8, 0x00000002,
    0x00000000
};

s32 D_802E9874[9] = {
    0x00000005, 0x00000800, 0x00000004, 0x00000020,
    0x00000001, 0x0000003C, (s32) &D_802E97D8, 0x00000002,
    0x00000000
};
s32 D_802E9898[9] = {
    0x00000005, 0x00000800, 0x00000004, 0x00000020,
    0x00000001, 0x0000003C, &D_802E97B0, 0x00000002,
    0x00000000,
};

s32 D_802E98BC[8] = {
    0x00200000, (s32) &D_802E9850, 0x00000000, (s32)create_shadow_callback,
    0x00000000, 0x00000000, 0x00000000, 0x00000000
};

s32 D_802E98DC[9] = {
    0x01190A19, 0x00200000, (s32) &D_802E9874, 0x00000000,
    (s32)create_shadow_callback, 0x00000000, 0x00000000, 0x00000000,
    0x00000000
};

s32 D_802E9900[9] = {
    0x01190A19, 0x00200000, (s32) &D_802E9898, 0x00000000,
    (s32)create_shadow_callback, 0x00000000, 0x00000000, 0x00000000,
    0x00000000,
};

s32 D_802E9924[3] = {
    0x01190A19, 0x00000000, 0x00000000
};

s32 D_802E9930[51] = {
    0x00000003, 0x00000000, (s32)func_802E10F4, 0x00000009,
    0x0000014E, 0x00000002, (s32)func_802E114C, 0x00000002,
    (s32)func_802E31EC, 0x00000003, 0x00000006, (s32)func_802E328C,
    0x00000003, 0x00000002, 0x00000000, 0x00000002,
    (s32)func_802E1204, 0x00000003, 0x00000000, (s32)func_802E1270,
    0x00000003, 0x0000000E, 0x00000000, 0x00000002,
    (s32)func_802E1298, 0x00000003, 0x00000000, (s32)func_802E1350,
    0x00000002, (s32)save_game_at_player_position, 0x00000002, (s32)func_802E12F8,
    0x00000003, 0x00000000, (s32)func_802E1328, 0x00000002,
    (s32)func_802E117C, 0x00000003, 0x0000000C, 0x00000000,
    0x00000004, 0x00000000, 0x00000000, 0x00000002,
    (s32)func_802E117C, 0x00000003, 0x00000002, 0x00000000,
    0x00000001, (s32)D_802E9930, 0x00000000,
};

s32 D_802E99FC[7] = {

    0x00000004, 0x00000022, 0x00000001, 0x0000003C,
    &D_0A003508, 0x00000002, 0x00000000,
};

StaticEntityData D_802E9A18 = { 0x4200, 0x0020, &D_802E99FC, {0, 0, 0, 0}, func_802E13B8, &D_802E9930, func_802E3BA4, &D_00E4B2E0, &D_00E4E7F0, 32, {0x19, 0x19, 0x19}};

// potential file split(?)
s32 D_802E9A3C[1] = {
    0x00000000
};

s32 D_802E9A40[18] = {
    0x00000003, 0x00000000, (s32)func_802E1660, 0x00000009,
    0x00000152, 0x00000002, (s32)func_802E1EA8, 0x00000002,
    (s32)func_802E176C, 0x00000003, 0x00000000, (s32)func_802E17A8,
    0x00000003, 0x00000000, (s32)func_802E1740, 0x00000004,
    0x00000000, 0x00000000,
};

s32 D_802E9A88[15] = {
    0x00000003, 0x00000000, (s32)func_802E1614, 0x00000009,
    0x00000152, 0x00000002, (s32)func_802E1EA8, 0x00000002,
    (s32)func_802E176C, 0x00000003, 0x00000000, (s32)func_802E1EDC,
    0x00000007, 0x20000000, 0x00000000
};

s32 D_802E9AC4[15] = {
    0x00000003, 0x00000000, (s32)func_802E1660, 0x00000009,
    0x00000152, 0x00000002, (s32)func_802E1EA8, 0x00000002,
    (s32)func_802E176C, 0x00000003, 0x00000000, (s32)func_802E1EDC,
    0x00000007, 0x20000000, 0x00000000
};

s32 D_802E9B00[16] = {
    0x00000003, 0x00000000, (s32)func_802E1400, 0x00000003,
    0x00000000, (s32)func_802E1460, 0x00000009, 0x00000152,
    0x00000003, 0x00000080, 0x00000000, 0x00000003,
    0x00000000, (s32)func_802E14D8, 0x00000004, 0x00000000,
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

StaticEntityData D_802E9BB0 = { 0xA000, 0x002C, &D_802E9B78, {0, 0, 0, 0}, func_802E234C,              &D_802E9A40, NULL, &D_00E62AC0, &D_00E639C0,  8, {0x16, 0x17, 0x16} };
StaticEntityData D_802E9BD4 = { 0xAA04, 0x002C, &D_802E9B40, {0, 0, 0, 0}, entity_init_BlueSwitch,     &D_802E9AC4, NULL, &D_00E639C0, &D_00E648D0,  7, {0x16, 0x17, 0x16} };
StaticEntityData D_802E9BF8 = { 0xAA04, 0x002C, &D_802E9B5C, {0, 0, 0, 0}, entity_init_HugeBlueSwitch, &D_802E9A88, NULL, &D_00E639C0, &D_00E648D0,  9, {0x42, 0x4B, 0x42} };
StaticEntityData D_802E9C1C = { 0xC000, 0x002C, &D_802E9B94, {0, 0, 0, 0}, func_802E234C,              &D_802E9B00, NULL, &D_00E62370, &D_00E62AC0, 10, {0x32, 0x0F, 0x32} };

s32 D_802E9C40[12] = {
    0x00000007, 0x00000020, 0x00000003, 0x00000000,
    func_802E263C, 0x00000007, 0x00000001, 0x00000007,
    0x20000000, 0x00000000, 0x00000000, 0x00000000
};

s32 D_802E9C70[7] = {
    0x00000004, 0x00000011, 0x00000001, 0x0000003C,
    (s32) &D_802E9828, 0x00000002, 0x00000000
};

extern UNK_TYPE D_00E32420;
extern UNK_TYPE D_00E35670;
extern UNK_TYPE D_00E38890;
extern UNK_TYPE D_00E3B870;
extern UNK_TYPE D_00E3E260;
extern UNK_TYPE D_00E42240;

StaticEntityData D_802E9C8C = { 0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, func_802E2EB0, &D_802E9C40, NULL, &D_00E32420, &D_00E35670, 21, {0x10, 0x10, 0x10}};
StaticEntityData D_802E9CB0 = { 0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, func_802E2EB0, &D_802E9C40, NULL, &D_00E35670, &D_00E38890, 22, {0x10, 0x10, 0x10}};
StaticEntityData D_802E9CD4 = { 0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, func_802E2EB0, &D_802E9C40, NULL, &D_00E38890, &D_00E3B870, 23, {0x10, 0x10, 0x10}};
StaticEntityData D_802E9CF8 = { 0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, func_802E2EB0, &D_802E9C40, NULL, &D_00E32420, &D_00E35670, 24, {0x08, 0x08, 0x08}};
StaticEntityData D_802E9D1C = { 0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, func_802E2EB0, &D_802E9C40, NULL, &D_00E35670, &D_00E38890, 25, {0x08, 0x08, 0x08}};
StaticEntityData D_802E9D40 = { 0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, func_802E2EB0, &D_802E9C40, NULL, &D_00E38890, &D_00E3B870, 26, {0x08, 0x08, 0x08}};
StaticEntityData D_802E9D64 = { 0x0000, 0x0250, &D_802E9C70, {0, 0, 0, 0}, func_802E2EB0, &D_802E9C40, NULL, &D_00E3E260, &D_00E42240, 13, {0x08, 0x08, 0x08}};

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
            sfx_play_sound_at_position(0x158, 0, entity->position.x, entity->position.y, entity->position.z);
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
