#include "common.h"

typedef struct EntityModel {
    /* 0x00 */ s32 flags;
    /* 0x04 */ u8 renderMode;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ f32 nextFrameTime; ///< Set to 1.0 after each update
    /* 0x0C */ f32 timeScale; ///< Default is 1.0
    /* 0x10 */ s32* cmdListReadPos;
    /* 0x14 */ Gfx* displayList;
    /* 0x18 */ Matrix4s transform;
    /* 0x58 */ s32 cmdListSavedPos;
    /* 0x5C */ Vtx* vertexArray;
    /* 0x60 */ UNK_FUN_PTR(fpSetupGfxCallback);
    /* 0x64 */ s32 setupGfxCallbackArg0;
} EntityModel; // size = 0x68

extern EntityModel** gCurrentEntityModelList;
extern s32 D_80154378; // entity fog enabled
extern s32 D_8015437C; // entity fog red
extern s32 D_80154380; // entity fog green
extern s32 D_80154384; // entity fog blue
extern s32 D_80154388; // entity fog alpha
extern s32 D_8015438C; // entity fog dist min
extern s32 D_80154390; // entity fog dist max

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", clear_entity_models);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", init_entity_models);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", load_entity_model);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", ALT_load_entity_model);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", update_entity_rendercmd);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", step_entity_rendercmd);

void make_mtx_flipZ(Matrix4f mtx) {
    guMtxIdentF(*mtx);
    mtx[0][0] = 1.0f;
    mtx[1][1] = 1.0f;
    mtx[2][2] = -1.0f;
    mtx[3][3] = 1.0f;
}

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", appendGfx_entity_model);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", draw_entity_model_shadow);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", draw_entity_model_main);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", draw_entity_model_extra1);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", draw_entity_model_extra2);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", draw_entity_model_extra3);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80122D7C);

EntityModel* get_entity_model(s32 listIndex) {
    return gCurrentEntityModelList[listIndex & ~0x800];
}

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", free_entity_model_by_index);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", free_entity_model_by_ref);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", set_entity_model_flags);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", clear_entity_model_flags);

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
    if (!gGameStatusPtr->isBattle) {
        gCurrentDynamicEntityListPtr = gWorldDynamicEntityList;
    } else {
        gCurrentDynamicEntityListPtr = gBattleDynamicEntityList;
    }
}

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", bind_dynamic_entity_3);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", bind_dynamic_entity_7, s32* updateFunc, void (*drawFunc)(void));

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", bind_dynamic_entity_B);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", update_dynamic_entities);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", render_dynamic_entities);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_801234E0);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_80123550);

INCLUDE_ASM(s32, "code_b72b0_len_15ed0", func_801235C0);

s32 get_dynamic_entity(s32 arg0) {
    return (*gCurrentDynamicEntityListPtr)[arg0 & ~0x800];
}
