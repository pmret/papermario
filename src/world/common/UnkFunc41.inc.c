#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc41)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerData* playerData = &gPlayerData;
    NpcID npcID = get_variable(script, *args++);
    PartnerID partnerID = get_variable(script, *args++);
    Npc* npc = get_npc_safe(npcID);

    if (isInitialCall) {
        if (gPlayerData.currentPartner == PARTNER_NONE) {
            script->functionTemp[0] = 2;
        } else {
            script->functionTemp[0] = 0;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            switch_to_partner(0);
            script->functionTemp[1] = 30;
            script->functionTemp[0] = 1;
            break;
        case 1:
            script->functionTemp[1]--;
            if (script->functionTemp[1] == -1) {
                script->functionTemp[0] = 2;
            }
            break;
        case 2:
            playerData->currentPartner = partnerID;
            playerData->partners[partnerID].enabled = TRUE;
            partner_clear_player_tracking(npc);
            func_800EB2A4(playerData->currentPartner);
            script->functionTemp[0] = 3;
            break;
        case 3:
            set_npc_yaw(get_npc_safe(NPC_PARTNER), npc->yaw);
            npc->flags &= ~4;
            disable_npc_shadow(npc);
            npc->pos.y = -1000.0f;
            return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
