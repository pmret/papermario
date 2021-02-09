#include "common.h"

INCLUDE_ASM(s32, "world/script_api/7E0E80", func_80280000);

INCLUDE_ASM(s32, "world/script_api/7E0E80", func_80280088);

INCLUDE_ASM(s32, "world/script_api/7E0E80", func_8028017C);

INCLUDE_ASM(s32, "world/script_api/7E0E80", func_80280208);

INCLUDE_ASM(s32, "world/script_api/7E0E80", func_802802D0);

INCLUDE_ASM(s32, "world/script_api/7E0E80", func_8028035C);

ApiStatus func_802803C8(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = PLAYER_STATUS;

    script->varTable[2] = FALSE;

    if (playerStatus->actionState == ActionState_BOUNCE ||
        playerStatus->actionState == ActionState_FALLING) {
        return ApiStatus_DONE2;
    }

    if ((playerStatus->flags & 0x100)) {
        return ApiStatus_DONE2;
    }

    script->varTable[2] = TRUE;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/script_api/7E0E80", func_80280410);

INCLUDE_ASM(s32, "world/script_api/7E0E80", func_8028051C);

INCLUDE_ASM(s32, "world/script_api/7E0E80", func_80280954);

INCLUDE_ASM(s32, "world/script_api/7E0E80", func_80280AC4);

void func_80280B44(void) {
    func_800F1538();
    func_800E9900();
    func_800E98C4();
    close_status_menu();
}

INCLUDE_ASM(s32, "world/script_api/7E0E80", func_80280B78);

INCLUDE_ASM(s32, "world/script_api/7E0E80", func_80280BD0);

INCLUDE_ASM(s32, "world/script_api/7E0E80", func_80281434);

INCLUDE_ASM(s32, "world/script_api/7E0E80", func_802814D0);

INCLUDE_ASM(s32, "world/script_api/7E0E80", draw_shop_items);

INCLUDE_ASM(s32, "world/script_api/7E0E80", MakeShop);

ApiStatus MakeShopOwner(ScriptInstance* script, s32 isInitialCall) {
    Shop* mapShop = GAME_STATUS->mapShop;

    mapShop->owner = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
