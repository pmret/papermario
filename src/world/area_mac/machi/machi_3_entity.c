#include "machi.h"
#include "entity.h"

API_CALLABLE(N(DoNothing1)) {
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DoNothing2)) {
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DoNothing3)) {
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_80240048_7E73E8)) {
    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 0;
        gOverrideFlags |= GLOBAL_OVERRIDES_MESSAGES_OVER_FRONTUI;
    }

    set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, script->functionTemp[1]);

    if (script->functionTemp[1] == 255) {
        return ApiStatus_DONE2;
    }

    script->functionTemp[1] += 10;
    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_802400C8_7E7468)) {
    gPlayerData.partners[script->varTable[0] + 1].level++;
    script->varTable[0] = PARTNER_NONE;
    if (gPlayerData.partners[PARTNER_GOOMBARIO].level > PARTNER_RANK_ULTRA) {
        gPlayerData.partners[PARTNER_GOOMBARIO].level = PARTNER_RANK_ULTRA;
        script->varTable[0] = PARTNER_GOOMBARIO;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240114_7E74B4)) {
    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 255;
        gOverrideFlags |= GLOBAL_OVERRIDES_MESSAGES_OVER_FRONTUI;
    }

    set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, script->functionTemp[1]);

    if (script->functionTemp[1] == 0) {
        gOverrideFlags &= ~GLOBAL_OVERRIDES_MESSAGES_OVER_FRONTUI;
        return ApiStatus_DONE2;
    }

    script->functionTemp[1] -= 10;
    if (script->functionTemp[1] < 0) {
        script->functionTemp[1] = 0;
    }

    return ApiStatus_BLOCK;
}

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HugeBlueSwitch), 278, 0, -318, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_GreenStompSwitch), 68, 0, -92, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), 119, 0, -166, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_RedSwitch), 169, 0, -166, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 0, 60, -326, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 40, 60, -326, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 80, 100, -326, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 120, 104, -326, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 160, 108, -326, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 200, 110, -326, 0, ITEM_MUSHROOM, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 240, 100, -326, 0, ITEM_MUSHROOM, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_GiantChest), -206, 0, -373, 0, ITEM_SUPER_HAMMER, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), -131, 0, -359, 0, 6, MAKE_ENTITY_END)
    EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, 70, 0, 0, ITEM_SPAWN_MODE_KEY, 1)
    EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, 94, 0, 0, ITEM_SPAWN_MODE_KEY, 1)
    EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, 118, 0, 0, ITEM_SPAWN_MODE_KEY, 1)
    EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, 142, 0, 0, ITEM_SPAWN_MODE_KEY, 1)
    EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, 166, 0, 0, ITEM_SPAWN_MODE_KEY, 1)
    EVT_RETURN
    EVT_END
};
