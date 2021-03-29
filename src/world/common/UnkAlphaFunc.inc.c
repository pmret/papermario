#include "common.h"

ApiStatus N(UnkAlphaFunc)(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        s32 i;

        func_8011D82C(1);
        D_801512F0[0] = 1;
        set_background_color_blend(0, 0, 0, 0);

        for (i = 0; i < 64; i++) {
            Npc* npc = get_npc_by_index(i);

            if (npc != NULL && npc->flags != 0 && npc->npcID != NPC_PARTNER && npc->npcID != UNK_ALPHA_FUNC_NPC) {
                npc->flags |= 0x800000;
            }
        }

        for (i = 0; i < 256; i++) {
            ItemEntity* itemEntity = get_item_entity(i);

            if (itemEntity != NULL && itemEntity->flags & 0x10) {
                itemEntity->flags |= 0x8000000;
            }
        }

        script->functionTemp[0].s = 0;
    }

    script->functionTemp[0].s += 8;
    if (script->functionTemp[0].s > 255) {
        script->functionTemp[0].s = 255;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0].s);
    return (script->functionTemp[0].s == 255) * ApiStatus_DONE2;
}
