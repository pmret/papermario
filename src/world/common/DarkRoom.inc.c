#include "common.h"

ApiStatus N(DarkRoomUpdate)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;

    if (isInitialCall) {
        script->functionTemp[0] = 255;
        script->functionTemp[1] = 0;
    }
    
    set_screen_overlay_center_worldpos(1, 1, playerStatus->position.x, playerStatus->position.y + 8.0f, playerStatus->position.z);
    
    if (gPartnerActionStatus.actionState.b[0] != 0) {
        if (playerData->currentPartner == PARTNER_WATT) {
            if (script->functionTemp[1] == 0) {
                script->functionTemp[1] = 1;
                sfx_play_sound(SOUND_WATT_REPEL_DARKNESS);
            }
            script->functionTemp[0] -= 8;
            if (script->functionTemp[0] < 90) {
                script->functionTemp[0] = 90;
            }
        }
    } else if (playerData->currentPartner == PARTNER_WATT) {
        if (script->functionTemp[1] != 0) {
            script->functionTemp[1] = 0;
            if (script->functionTemp[0] < 255) {
                sfx_play_sound(SOUND_WATT_RESUME_DARKNESS);
            }
        }
        script->functionTemp[0] += 8;
        if (script->functionTemp[0] >= 255) {
            script->functionTemp[0] = 255;
        }
    } else {
        script->functionTemp[0] = 255;
    }
    
    set_screen_overlay_alpha(1, script->functionTemp[0]);
    set_screen_overlay_params_back(0xB, 255.0f);
    
    return ApiStatus_BLOCK;
}
