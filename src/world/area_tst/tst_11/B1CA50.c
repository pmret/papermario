#include "tst_11.h"

// TODO: nonmatchings in this file are very similar to matched funcs in src/world/common/reflection.inc.c

void func_8024003C_B1CA8C(void);
void func_80240100_B1CB50(void);
void func_802402F4_B1CD44(void);
void N(SetPartnerFlagsA0000)(void);

ApiStatus func_80240000_B1CA50(ScriptInstance* script, s32 isInitialCall) {
    script->array[0] = (s32) create_dynamic_entity_frontUI(NULL, func_8024003C_B1CA8C);
    return ApiStatus_DONE2;
}

void func_8024003C_B1CA8C(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    EntityModel* entityModel;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    s32 screenX;
    s32 screenY;
    s32 screenZ;

    if (playerStatus->flags & 1) {
        entityModel = get_entity_model(get_shadow_by_index(playerStatus->shadowID)->unk_08);
        entityModel->flags |= 0x200;

        get_screen_coords(gCurrentCamID, playerStatus->position.x, playerStatus->position.y, -playerStatus->position.z,
                          &screenX, &screenY, &screenZ);

        renderTask.renderMode = playerStatus->renderMode;
        renderTask.appendGfxArg = playerStatus;
        renderTask.appendGfx = func_80240100_B1CB50;
        renderTask.distance = -screenZ;
        queue_render_task(renderTaskPtr);
    }
}

INCLUDE_ASM(void, "world/area_tst/tst_11/B1CA50", func_80240100_B1CB50, void);

ApiStatus func_802402B8_B1CD08(ScriptInstance* script, s32 isInitialCall) {
    script->array[0] = (s32) create_dynamic_entity_frontUI(NULL, func_802402F4_B1CD44);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(void, "world/area_tst/tst_11/B1CA50", func_802402F4_B1CD44, void);

INCLUDE_ASM(s32, "world/area_tst/tst_11/B1CA50", func_802403B8_B1CE08);

ApiStatus func_802406D4_B1D124(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc;

    script->array[1] = create_dynamic_entity_world(N(SetPartnerFlagsA0000), NULL);

    npc = get_npc_safe(NPC_PARTNER);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->flags |= NPC_FLAG_REFLECT_WALL | NPC_FLAG_REFLECT_FLOOR;

    return ApiStatus_DONE2;
}

void N(SetPartnerFlagsA0000)(void) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    if (partner != NULL) {
        partner->flags |= NPC_FLAG_REFLECT_WALL | NPC_FLAG_REFLECT_FLOOR;
    }
}
