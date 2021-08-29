#include "common.h"

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
    f32 temp_f0 = *D_8015C7D0;
    structE2EDE0* data = (structE2EDE0*)entity->dataBuf;

    data->unk_04 = temp_f0;
    data->unk_08 = temp_f0;
    entity->renderSetupFunc = &func_802BC4B0_E2EDE0;
}

void func_802BC658_E2EF88(Entity* entity) {
    if (!(gPlayerStatus.animFlags & 1) && (entity->collisionFlags & 8)) {
        entity_start_script(entity);
    }
}
