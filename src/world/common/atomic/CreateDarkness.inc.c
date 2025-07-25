#include "common.h"

API_CALLABLE(N(DarkRoomUpdate)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;

    if (isInitialCall) {
        script->functionTemp[0] = 255;
        script->functionTemp[1] = false;
    }

    set_screen_overlay_center_worldpos(SCREEN_LAYER_BACK, 1, playerStatus->pos.x, playerStatus->pos.y + 8.0f, playerStatus->pos.z);

    if (gPartnerStatus.partnerActionState != PARTNER_ACTION_NONE) {
        if (playerData->curPartner == PARTNER_WATT) {
            if (!script->functionTemp[1]) {
                script->functionTemp[1] = true;
                sfx_play_sound(SOUND_WATT_REPEL_DARKNESS);
            }
            script->functionTemp[0] -= 8;
            if (script->functionTemp[0] < 90) {
                script->functionTemp[0] = 90;
            }
        }
    } else if (playerData->curPartner == PARTNER_WATT) {
        if (script->functionTemp[1]) {
            script->functionTemp[1] = false;
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

    set_screen_overlay_alpha(SCREEN_LAYER_BACK, script->functionTemp[0]);
    set_screen_overlay_params_back(OVERLAY_WORLD_DARKNESS, 255.0f);

    return ApiStatus_BLOCK;
}

EvtScript N(EVS_CreateDarkness) = {
    Thread
        Call(N(DarkRoomUpdate))
    EndThread
    Return
    End
};
