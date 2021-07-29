#include "common.h"
#include "map.h"

s32 N(UnkFunc28)(Npc* npc);

ApiStatus N(UnkFunc31)(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);

    npc->onRender = N(UnkFunc28);
    npc->blurBuf = heap_malloc(8);
    *((s32*)npc->blurBuf) = 0;

    return ApiStatus_DONE1;
}

ApiStatus N(GetNpcUnsafeOwner2)(ScriptInstance* script, s32 isInitialCall) {
    get_npc_unsafe(script->owner2.npcID);
    return ApiStatus_BLOCK;
}

s32 N(UnkFunc28)(Npc* npc) {
    Camera* camera = &gCameras[gCurrentCamID];

    if (*((s32*)npc->blurBuf) & 1) {
        clamp_angle(-camera->currentYaw);
    }
}

ApiStatus N(UnkAlphaFunc)(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        s32 i;

        mdl_set_all_fog_mode(1);
        D_801512F0[0] = 1;
        set_background_color_blend(0, 0, 0, 0);

        for (i = 0; i < MAX_NPCS; i++) {
            Npc* npc = get_npc_by_index(i);

            if (npc != NULL && npc->flags != 0 && npc->npcID != NPC_PARTNER && npc->npcID != UNK_ALPHA_FUNC_NPC) {
                npc->flags |= 0x800000;
            }
        }

        for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
            ItemEntity* itemEntity = get_item_entity(i);

            if (itemEntity != NULL && itemEntity->flags & 0x10) {
                itemEntity->flags |= 0x8000000;
            }
        }

        script->functionTemp[0] = 0;
    }

    script->functionTemp[0] += 8;
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0]);
    return (script->functionTemp[0] == 255) * ApiStatus_DONE2;
}

ApiStatus N(UnkFunc29)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (isInitialCall) {
        set_background_color_blend(0, 0, 0, 255);
        script->functionTemp[0] = 255;
        script->functionTemp[1] = 0;
    }

    script->functionTemp[0] -= 8;
    if (script->functionTemp[0] < 0) {
        script->functionTemp[0] = 0;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0]);
    if (script->functionTemp[0] == 0 && script->functionTemp[1] == 0) {
        script->functionTemp[1] = 1;
    } else if (script->functionTemp[1] == 1) {
        mdl_set_all_fog_mode(0);
        *D_801512F0 = 0;

        for (i = 0; i < MAX_NPCS; i++) {
            Npc* npc = get_npc_by_index(i);
            if (npc != NULL && npc->flags != 0) {
                if (npc->npcID != NPC_PARTNER && npc->npcID != UNK_ALPHA_FUNC_NPC) {
                    npc->flags &= ~0x00800000;
                }
            }
        }

        for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
            Entity* entity = get_item_entity(i);
            if (entity != NULL && entity->flags & 0x10) {
                entity->flags &= ~0x08000000;
            }
        }

        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
