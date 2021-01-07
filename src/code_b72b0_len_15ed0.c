#include "common.h"

extern s32** D_80154370; // probably entities of some sort
extern s32 D_80154378; // entity fog enabled
extern s32 D_8015437C; // entity fog red
extern s32 D_80154380; // entity fog green
extern s32 D_80154384; // entity fog blue
extern s32 D_80154388; // entity fog alpha
extern s32 D_8015438C; // entity fog dist min
extern s32 D_80154390; // entity fog dist max

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", clear_virtual_models);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", init_virtual_models);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", load_virtual_model);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80120DE4);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80120F04);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80120FB8);

void func_80121140(Matrix4f* arg0) {
    guMtxIdentF(arg0->mtx);
    arg0->mtx[0][0] = 1.0f;
    arg0->mtx[1][1] = 1.0f;
    arg0->mtx[2][2] = -1.0f;
    arg0->mtx[3][3] = 1.0f;
}

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80121184);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80121CE8);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80121EB8);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80122088);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80122188);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80122288);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80122D7C);

s32 func_80122DDC(s32 arg0) {
    return D_80154370[arg0 & ~0x800];
}

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80122DFC);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80122E94);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80122EE8);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80122F24);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80122F64);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80122F8C);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80122FB8);

void enable_entity_fog(void) {
    D_80154378 = 1;
}

void disable_entity_fog(void) {
    D_80154378 = 0;
}

void set_entity_fog_dist(s32 min, s32 max) {
    D_8015438C = min;
    D_80154390 = max;
}

void set_entity_fog_color(s32 r, s32 g, s32 b, s32 a) {
    D_8015437C = r;
    D_80154380 = g;
    D_80154384 = b;
    D_80154388 = a;
}

s32 is_entity_fog_enabled(void) {
    return D_80154378;
}

void get_entity_fog_distance(s32* start, s32* end) {
    *start = D_8015438C;
    *end = D_80154390;
}

void get_entity_fog_color(s32* r, s32* g, s32* b, s32* a) {
    *r = D_8015437C;
    *g = D_80154380;
    *b = D_80154384;
    *a = D_80154388;
}

void stub_dynamic_entity_delegate(void) {
}

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", clear_dynamic_entity_list);

void init_dynamic_entity_list(void) {
    if (!GAME_STATUS->isBattle) {
        gCurrentDynamicEntityListPtr = gWorldDynamicEntityList;
    } else {
        gCurrentDynamicEntityListPtr = gBattleDynamicEntityList;
    }
}

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", bind_dynamic_entity_3);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", bind_dynamic_entity_7);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", bind_dynamic_entity_B);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", update_dynamic_entities);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", render_dynamic_entities);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_801234E0);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80123550);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_801235C0);

s32 get_dynamic_entity(s32 arg0) {
    return (*gCurrentDynamicEntityListPtr)[arg0 & ~0x800];
}
