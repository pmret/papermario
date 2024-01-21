#include "kzn_08.h"

// modified DarkRoomUpdate
API_CALLABLE(N(func_80243EE0_C75360)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    u8 primR, primG, primB, primA;
    u8 fogR, fogG, fogB;
    s32 fogStart, fogEnd;
    f32 alpha;

    if (isInitialCall) {
        script->functionTemp[0] = 255;
        script->functionTemp[1] = FALSE;
    }

    set_screen_overlay_center_worldpos(SCREEN_LAYER_BACK, 1,
        playerStatus->pos.x,  playerStatus->pos.y + 8.0f, playerStatus->pos.z);
    mdl_get_depth_tint_params(&primR, &primG, &primB, &primA,
        &fogR, &fogG, &fogB, &fogStart, &fogEnd);

    alpha = (((995 - fogStart) - 70.0f) * 255.0f) / 30.0f;
    if (alpha > 255.0f) {
        alpha = 255.0f;
    }
    if (alpha < 0.0f) {
        alpha = 0.0f;
    }
    if (alpha == 0.0f) {
        set_screen_overlay_alpha(SCREEN_LAYER_BACK, 0.0f);
        set_screen_overlay_params_back(OVERLAY_WORLD_DARKNESS, 0.0f);
        return ApiStatus_BLOCK;
    }

    if (gPartnerStatus.partnerActionState != PARTNER_ACTION_NONE) {
        if (playerData->curPartner == PARTNER_WATT) {
            if (!script->functionTemp[1]) {
                script->functionTemp[1] = TRUE;
                sfx_play_sound(SOUND_WATT_REPEL_DARKNESS);
            }
            script->functionTemp[0] -= 8;
            if (script->functionTemp[0] < 90) {
                script->functionTemp[0] = 90;
            }
        }
    } else if (playerData->curPartner == PARTNER_WATT) {
        if (script->functionTemp[1]) {
            script->functionTemp[1] = FALSE;
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
    set_screen_overlay_params_back(OVERLAY_WORLD_DARKNESS, alpha);
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_802455A0) = {
    Thread
        Call(N(func_80243EE0_C75360))
    EndThread
    Return
    End
};
