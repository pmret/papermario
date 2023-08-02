#include "common.h"
#include "map.h"
#include "npc.h"

void func_800EB2A4(s32 arg0);

API_CALLABLE(N(ChangeNpcToPartner)) {
    Bytecode* args = script->ptrReadPos;
    PlayerData* playerData = &gPlayerData;
    s32 npcID = evt_get_variable(script, *args++);
    s8 partnerID = evt_get_variable(script, *args++);
    Npc* npc = get_npc_safe(npcID);

    if (isInitialCall) {
        if (gPlayerData.curPartner == PARTNER_NONE) {
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
            playerData->curPartner = partnerID;
            playerData->partners[partnerID].enabled = TRUE;
            partner_clear_player_tracking(npc);
            func_800EB2A4(playerData->curPartner);
            script->functionTemp[0] = 3;
            break;
        case 3:
            set_npc_yaw(get_npc_safe(NPC_PARTNER), npc->yaw);
            npc->flags &= ~NPC_FLAG_INACTIVE;
            disable_npc_shadow(npc);
            npc->pos.y = NPC_DISPOSE_POS_Y;
            return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
