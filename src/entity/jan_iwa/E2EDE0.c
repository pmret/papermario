#include "common.h"
#include "entity_script.h"

typedef struct structE2EDE0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
} structE2EDE0;

s32 func_802BC4B0_E2EDE0(void);
INCLUDE_ASM(s32, "entity/jan_iwa/E2EDE0", func_802BC4B0_E2EDE0);

void func_802BC628_E2EF58(void) {
}

void func_802BC630_E2EF60(Entity* entity) {
    f32 temp_f0 = CreateEntityVarArgBuffer[0];
    structE2EDE0* data = (structE2EDE0*)entity->dataBuf.unk;

    data->unk_04 = temp_f0;
    data->unk_08 = temp_f0;
    entity->renderSetupFunc = func_802BC4B0_E2EDE0;
}

void func_802BC658_E2EF88(Entity* entity) {
    if (!(gPlayerStatus.animFlags & 1) && (entity->collisionFlags & 8)) {
        entity_start_script(entity);
    }
}

EntityScript D_802BCD70_E2F6A0 = {
    es_SetCallback(func_802BC628_E2EF58, 0)
    es_End
};

EntityModelScript D_802BCD80_E2F6B0 = STANDARD_ENTITY_MODEL_SCRIPT(0x0A000C40, RENDER_MODE_SURFACE_OPA);

EntityBlueprint D_802BCD9C_E2F6CC = {
    .flags = ENTITY_FLAGS_SQUARE_SHADOW | ENTITY_FLAGS_400 | ENTITY_FLAGS_SET_SHADOW_FLAG200,
    .typeDataSize = 0x10,
    .renderCommandList = D_802BCD80_E2F6B0,
    .modelAnimationNodes = 0,
    .fpInit = func_802BC630_E2EF60,
    .updateEntityScript = D_802BCD70_E2F6A0,
    .fpHandleCollision = func_802BC658_E2EF88,
    {{ 0x00E59F00, 0x00E5AB50 }},
    .entityType = ENTITY_TYPE_RED_ARROW_SIGNS,
    .aabbSize = { 18, 50, 10 }
};
