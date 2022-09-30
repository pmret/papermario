#include "common.h"

#define NAMESPACE b_area_kzn2

enum {
    VINE_0      = 0,
    VINE_1      = 1,
    VINE_2      = 2,
    VINE_3      = 3,
    NUM_VINES   = 4
};

enum {
    VINE_0_BASE  = 0x80200000,
    VINE_1_BASE  = 0x80204000,
    VINE_2_BASE  = 0x80207000,
    VINE_3_BASE  = 0x8020A000,
};

typedef struct LavaPiranhaVine {
    /* 0x000 */ Vec3f bonePos[9];
    /* 0x06C */ f32 boneRot[9];
    /* 0x090 */ s32 boneCount;
    /* 0x094 */ f32 boneLength;
    /* 0x098 */ Vec3f points[27];
    /* 0x1DC */ s32 numPoints;
} LavaPiranhaVine;

typedef struct LavaPiranhaVineSet {
    LavaPiranhaVine vines[NUM_VINES];
} LavaPiranhaVineSet; // size = 0x780

#include "common/StartRumbleWithParams.inc.c"

extern LavaPiranhaVineSet* D_8022ADD0;
extern s32 N(VineRenderState); // TODO static

// N(make_vine_interpolation)
INCLUDE_ASM(s32, "battle/area_kzn2/59E6E0", func_80218058_59E738);

// N(SetVineBonePos)
INCLUDE_ASM(s32, "battle/area_kzn2/59E6E0", func_8021812C_59E80C);

// N(SetVineBoneRot)
INCLUDE_ASM(s32, "battle/area_kzn2/59E6E0", func_80218224_59E904);

// N(SetVineBoneScale)
INCLUDE_ASM(s32, "battle/area_kzn2/59E6E0", func_802182E4_59E9C4);

void func_8021835C_59EA3C(void* data);

// N(appendGfx_piranha_vines)
INCLUDE_ASM(s32, "battle/area_kzn2/59E6E0", func_8021835C_59EA3C);

void N(worker_render_piranha_vines)(void) {
    RenderTask renderTask;

    renderTask.appendGfx = &func_8021835C_59EA3C;
    renderTask.appendGfxArg = 0;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_OPA;

    queue_render_task(&renderTask);
}

API_CALLABLE(N(MarkVineInterpolationDirty)) {
    N(VineRenderState) = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CreateVineRenderer)) {
    N(VineRenderState) = -1;
    create_generic_entity_world(NULL, &N(worker_render_piranha_vines));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/area_kzn2/59E6E0", func_80218930_59F010);

INCLUDE_ASM(s32, "battle/area_kzn2/59E6E0", func_80218A98_59F178);

INCLUDE_ASM(s32, "battle/area_kzn2/59E6E0", func_80218B38_59F218);

INCLUDE_ASM(s32, "battle/area_kzn2/59E6E0", func_80218B90_59F270);

INCLUDE_ASM(s32, "battle/area_kzn2/59E6E0", func_80218BE8_59F2C8);
