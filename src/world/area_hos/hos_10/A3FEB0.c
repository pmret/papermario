#include "hos_10.h"
#include "effects.h"

ApiStatus func_80240770_A3FEB0(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    Npc* npc;

    if (isInitialCall) {
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        script->varTable[15] = evt_get_variable(script, *args++);
        script->functionTemp[0] = 0;
        script->functionTemp[3] = 0;
    }

    npc = get_npc_unsafe(script->functionTemp[1]);
    switch (script->functionTemp[0]) {
        case 0:
            npc->pos.x = playerStatus->position.x;
            npc->pos.y = playerStatus->position.y;
            npc->pos.z = playerStatus->position.z;
            npc->moveToPos.x =  script->functionTemp[3] * 3;
            npc->moveToPos.y = 3.0f;
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, 70.0f, npc->moveToPos.x + (script->functionTemp[2] * 51) + 153.0f);
            if (script->functionTemp[3] + script->functionTemp[2] ==
                ((script->functionTemp[3] + script->functionTemp[2]) / 13) * 13)
            {
                fx_sparkles(3, npc->pos.x, npc->pos.y + 10.0f, npc->pos.z, 10.0f);
            }
            if (script->functionTemp[3] > 350) {
                script->functionTemp[0] = 1;
                script->functionTemp[3] = 0;
            }
            break;
        case 1:
            npc->pos.x = playerStatus->position.x;
            npc->pos.y = playerStatus->position.y;
            npc->pos.z = playerStatus->position.z;
            npc->moveToPos.x = script->functionTemp[3] * 3;
            npc->moveToPos.y = 3.0f;
            add_vec2D_polar(
                &npc->pos.x,
                &npc->pos.z,
                (((190 - script->functionTemp[3]) / 190.0f) * 67.0f) + 3.0f,
                npc->moveToPos.x + (script->functionTemp[2] * 51) + 153.0f
            );
            if (script->functionTemp[3] + script->functionTemp[2] ==
                ((script->functionTemp[3] + script->functionTemp[2]) / 13) * 13)
            {
                fx_sparkles(3, npc->pos.x, npc->pos.y + 10.0f, npc->pos.z, 10.0f);
            }
            if (script->functionTemp[3] > 190) {
                return ApiStatus_DONE2;
            }
            break;
    }

    script->functionTemp[3]++;
    npc->moveToPos.x += npc->moveToPos.y;
    return ApiStatus_BLOCK;
}

ApiStatus func_80240A84_A401C4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    f32 x, y, z;

    // TODO could be sparkles, not ending decals - unsure
    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);
    z = evt_get_variable(script, *args++);
    effect->data.endingDecals->pos.x = x;
    effect->data.endingDecals->pos.y = y;
    effect->data.endingDecals->pos.z = z;
    return ApiStatus_DONE2;
}

ApiStatus func_80240B44_A40284(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    // TODO could be sparkles, not ending decals - unsure
    effect->data.endingDecals->unk_10 = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_80240B98_A402D8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    // TODO could be sparkles, not ending decals - unsure
    effect->data.endingDecals->unk_18 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_80240BEC_A4032C(Evt* script, s32 isInitialCall) {
    gPlayerData.currentPartner = PARTNER_NONE;
    return ApiStatus_DONE2;
}

ApiStatus func_80240BFC_A4033C(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    set_screen_overlay_color(0, 208, 208, 208);
    set_screen_overlay_params_front(1, script->functionTemp[1]);

    if (script->functionTemp[1] == 255) {
        return ApiStatus_DONE2;
    }

    script->functionTemp[1] += 7;
    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }

    return ApiStatus_BLOCK;
}
