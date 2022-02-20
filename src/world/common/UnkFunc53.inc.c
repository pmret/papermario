#include "common.h"
#include "battle/battle.h"

typedef struct UnkNPC {
    /* 0x00 */ Npc* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} UnkNPC; // size = 0x10;

ApiStatus N(UnkFunc53)(Evt* script, s32 isInitialCall) {
    NpcBlueprint bp;
    NpcBlueprint* bpPtr = &bp;
    UnkNPC* unkIt;
    Npc* npc;
    Npc* newNpc;
    s32 i;

    npc = get_npc_safe(script->owner2.npcID);
    npc->blurBuf = unkIt = heap_malloc(8 * sizeof(*unkIt));

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
        newNpc->unk_AB = 3;
        disable_npc_shadow(newNpc);
        unkIt->unk_04 = 0;
        unkIt->unk_08 = 0;
        unkIt->unk_0C = 0;
    }
    return ApiStatus_DONE2;
}
