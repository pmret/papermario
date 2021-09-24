#include "common.h"
#include "effects.h"

extern s32 D_8029FB78;
s32* virtual_entity_get_by_index(s32);

ApiStatus func_8025DEB0(Evt* script, s32 isInitialCall) {
    script->varTable[0] = (s8)gBattleStatus.totalStarPoints;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "18C790", func_8025DEC4);

ApiStatus func_8025E030(Evt* script, s32 isInitialCall) {
    return D_8029FB78 != 0 ? ApiStatus_DONE2 : 0;
}

ApiStatus func_8025E044(Evt* script, s32 isInitialCall) {
    EntityModel* model;

    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[6]));
    model->flags &= 0xFFFF000F;
    model->flags |= 0x8;
    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[7]));
    model->flags &= 0xFFFF000F;
    model->flags |= 0x8;
    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[8]));
    model->flags &= 0xFFFF000F;
    model->flags |= 0x8;
    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[9]));
    model->flags &= 0xFFFF000F;
    model->flags |= 0x8;

    return ApiStatus_DONE2;
}

ApiStatus func_8025E108(Evt* script, s32 isInitialCall) {
    EntityModel* model = get_entity_model(*virtual_entity_get_by_index(script->varTable[9]));
    model->flags &= 0xFFFF000F;
    model->flags |= 0x8;

    return ApiStatus_DONE2;
}

ApiStatus func_8025E14C(Evt* script, s32 isInitialCall) {
    playFX_44(3, 0.0f, 100.0f, 0.0f, 1.0f, 0x78);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "18C790", btl_state_update_celebration);

INCLUDE_ASM(s32, "18C790", btl_draw_upgrade_windows);

INCLUDE_ASM(s32, "18C790", btl_state_draw_celebration);

INCLUDE_ASM(s32, "18C790", func_80260948);

void func_80260A20(s64 posX, s32 posY) {
    draw_msg(0x1D00AB, posX + 11, posY + 6, 0xFF, 0xF, 0);
}
