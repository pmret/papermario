#include "kmr_03.h"

ApiStatus func_80240000_8C7F90(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerData* playerData = PLAYER_DATA;
    NpcId npcID = get_variable(script, *args++);
    PartnerId partnerID = get_variable(script, *args++);
    Npc* npc = get_npc_safe(npcID);

    if (isInitialCall) {
        if (gPlayerData.currentPartner == PartnerId_NONE) {
            script->functionTemp[0].s = 2;
        } else {
            script->functionTemp[0].s = 0;
        }
    }

    switch (script->functionTemp[0].s) {
        case 0:
            func_800EB168(0);
            script->functionTemp[1].s = 30;
            script->functionTemp[0].s = 1;
            break;
        case 1:
            script->functionTemp[1].s--;
            if (script->functionTemp[1].s == -1) {
                script->functionTemp[0].s = 2;
            }
            break;
        case 2:
            playerData->currentPartner = partnerID;
            playerData->partners[partnerID].enabled = TRUE;
            clear_partner_move_history(npc);
            func_800EB2A4(playerData->currentPartner);
            script->functionTemp[0].s = 3;
            break;
        case 3:
            set_npc_yaw(get_npc_safe(NpcId_PARTNER), npc->yaw);
            npc->flags &= ~4;
            disable_npc_shadow(npc);
            npc->pos.y = -1000.0f;
            return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

#include "world/common/CheckPartnerFlags1000.inc.c"

ApiStatus func_802401B0_8C8140(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(0);

    script->varTable[1] = func_800E0088(npc->pos.x, npc->pos.z) / npc->moveSpeed * 0.8f;
    return ApiStatus_DONE2;
}

#include "world/common/UnkPositionFunc.inc.c"
