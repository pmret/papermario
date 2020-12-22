#include "kmr_03.h"
#include "../../partners.h"

Script M(Main);

ApiStatus func_80240000_8C7F90(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerData* playerData = PLAYER_DATA;
    NpcId npcID = get_variable(script, *args++);
    PartnerID partnerID = get_variable(script, *args++);
    Npc* npc = get_npc_safe(npcID);

    if (isInitialCall) {
        if (gPlayerData.currentPartner == PartnerID_NONE) {
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

// 8C85E0
Vec4f M(entryList)[] = {
    { -340.0f, 0.0f, 348.0f, 48.0f },
    { 480.0f, 0.0f, 0.0f, 270.0f },
    { -310.0f, 20.0f, -80.0f, 135.0f },
};

MapConfig M(config) = {
    .main = M(Main),
    .entryList = M(entryList),
    .entryCount = ENTRY_COUNT(M(entryList)),
    .background = &gBackgroundImage,
    .tattle = MessageID_TATTLE_KMR_03,
};

Script M(Script_802406C0) = SCRIPT({
    SetMusicTrack(0, 17, 0, 8)
});
