#include "common.h"
#include "battle/battle.h"
#include "sprite/npc/stone_chomp.h"

ApiStatus N(UnkFunc53)(Evt* script, s32 isInitialCall) {
    NpcBlueprint bp;
    NpcBlueprint* bpPtr = &bp;
    NpcSimpleBlur* blurData;
    Npc* npc;
    Npc* newNpc;
    s32 i;

    npc = get_npc_safe(script->owner2.npcID);
    blurData = heap_malloc(8 * sizeof(*blurData));
    npc->blur.fixed = blurData;

    bp.flags = NPC_FLAG_8000 | NPC_FLAG_100 | NPC_FLAG_40
        | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_2;
    bp.initialAnim = NPC_ANIM_stone_chomp_Palette_00_Anim_2;
    bp.onUpdate = NULL;
    bp.onRender = NULL;

    for (i = 0; i < 8; i++, blurData++) {
        blurData->unk_00 = newNpc = get_npc_by_index(_create_npc_basic(bpPtr));
        newNpc->pos.x = npc->pos.x;
        newNpc->pos.y = npc->pos.y;
        newNpc->pos.z = npc->pos.z;
        newNpc->yaw = npc->yaw;
        newNpc->verticalRenderOffset = 3;
        disable_npc_shadow(newNpc);
        blurData->offset.x = 0.0f;
        blurData->offset.y = 0.0f;
        blurData->offset.z = 0.0f;
    }
    return ApiStatus_DONE2;
}
