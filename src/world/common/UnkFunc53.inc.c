#include "common.h"
#include "battle/battle.h"

ApiStatus N(UnkFunc53)(Evt* script, s32 isInitialCall) {
    NpcBlueprint bp;
    NpcBlueprint* bpPtr = &bp;
    NPCBlurUnk* unkIt;
    Npc* npc;
    Npc* newNpc;
    s32 i;

    npc = get_npc_safe(script->owner2.npcID);
    unkIt = heap_malloc(8 * sizeof(*unkIt));
    npc->blurBuf = (BlurBuffer*) unkIt; //TODO union?

    bp.flags = 0x8000 | 0x100 | 0x40 | 0x8 | 0x2;
    bp.initialAnim = 0x350002;
    bp.onUpdate = NULL;
    bp.onRender = NULL;

    for (i = 0; i < 8; i++, unkIt++) {
        unkIt->unk_00 = newNpc = get_npc_by_index(_create_npc_basic(bpPtr));
        newNpc->pos.x = npc->pos.x;
        newNpc->pos.y = npc->pos.y;
        newNpc->pos.z = npc->pos.z;
        newNpc->yaw = npc->yaw;
        newNpc->verticalRenderOffset = 3;
        disable_npc_shadow(newNpc);
        unkIt->offset.x = 0.0f;
        unkIt->offset.y = 0.0f;
        unkIt->offset.z = 0.0f;
    }
    return ApiStatus_DONE2;
}
