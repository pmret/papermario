#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc29)(ScriptInstance *script, s32 isInitialCall) {
    s32 i;

    if (isInitialCall) {
        set_background_color_blend(0, 0, 0, 0xFF);
        script->functionTemp[0].s = 0xFF;
        script->functionTemp[1].s = 0;
    }

    script->functionTemp[0].s -= 8;
    if (script->functionTemp[0].s < 0) {
        script->functionTemp[0].s = 0;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0].s);
    if ((script->functionTemp[0].s == 0) && (script->functionTemp[1].s == 0)) {
        script->functionTemp[1].s = 1;
    } else if (script->functionTemp[1].s == 1) {
        func_8011D82C(0);
        *D_801512F0 = 0;

        for (i = 0; i < 64; i++) {
            Npc* npc = get_npc_by_index(i);
            if (npc != NULL && npc->flags != 0) {
                if (npc->npcID != -4 && npc->npcID != UNK_ALPHA_FUNC_NPC) {
                    npc->flags &= 0xFF7FFFFF;
                }
            }
        }

        for (i = 0; i < 256; i++) {
            Entity* entity = get_item_entity(i);
            if (entity != NULL && (entity->flags & 0x10)) {
                entity->flags &= 0xF7FFFFFF;
            }
        }

        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
