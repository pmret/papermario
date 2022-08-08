#include "isk_05.h"

static char* N(exit_str_0) = "isk_04";
static char* N(exit_str_1) = "";

typedef struct UnkIsk14 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ Vec3f pos;
    /* 0x1C */ Vec3f rot;
    /* 0x28 */ Vec3f scale;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ f32 width;
    /* 0x40 */ f32 height;
} UnkIsk14; // size: unknown

extern UnkIsk14 D_80242614_9800E4;

#include "world/common/enemy/StoneChompAI.inc.c"

#include "world/common/UnkFunc53.inc.c"

INCLUDE_ASM(s32, "world/area_isk/isk_05/97DAD0", func_802411F8_97ECC8);

INCLUDE_ASM(s32, "world/area_isk/isk_05/97DAD0", func_802415C0_97F090);

INCLUDE_ASM(s32, "world/area_isk/isk_05/97DAD0", func_80241610_97F0E0);

void func_80241610_97F0E0();

ApiStatus func_80241B28_97F5F8(Evt* script, s32 isInitialCall) {
    SpriteRasterInfo rasterInfo;
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    
    D_80242614_9800E4.unk_08 = 53; //TODO get spriteID for this constant
    D_80242614_9800E4.unk_0C = 0;
    spr_get_npc_raster_info(&rasterInfo, 53, 0); //TODO get spriteID for this constant
    D_80242614_9800E4.width = rasterInfo.width;
    D_80242614_9800E4.height = rasterInfo.height;
    D_80242614_9800E4.pos.x = npc->pos.x;
    D_80242614_9800E4.pos.y = npc->pos.y + (D_80242614_9800E4.height * SPRITE_WORLD_SCALE_D * 0.5);
    D_80242614_9800E4.pos.z = npc->pos.z;
    D_80242614_9800E4.rot.x = 0;
    D_80242614_9800E4.rot.y = 0;
    D_80242614_9800E4.rot.z = 0;
    D_80242614_9800E4.scale.x = SPRITE_WORLD_SCALE;
    D_80242614_9800E4.scale.y = SPRITE_WORLD_SCALE;
    D_80242614_9800E4.scale.z = SPRITE_WORLD_SCALE;
    D_80242614_9800E4.unk_34 = 85.0f;
    D_80242614_9800E4.unk_38 = 0;
    D_80242614_9800E4.unk_00 = 0;
    D_80242614_9800E4.unk_04 = create_generic_entity_frontUI(NULL, func_80241610_97F0E0);
    
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_isk/isk_05/97DAD0", func_80241C34_97F704);

INCLUDE_ASM(s32, "world/area_isk/isk_05/97DAD0", func_80241C5C_97F72C);

INCLUDE_ASM(s32, "world/area_isk/isk_05/97DAD0", func_80241D44_97F814);

INCLUDE_ASM(s32, "world/area_isk/isk_05/97DAD0", func_80241DF8_97F8C8);

INCLUDE_ASM(s32, "world/area_isk/isk_05/97DAD0", func_80241E24_97F8F4);
