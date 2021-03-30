#include "common.h"
#include "../partners.h"

ApiStatus func_80283810(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    script->varTable[10] = 0;
    if (partner_get_ride_script() != NULL) {
        if (D_8010EBB0.unk_00 == 0) {
            script->varTable[10] = 0;
        } else {
            script->varTable[10] = 1;
            script->varTable[11] = partner_get_ride_script();
            script->varTable[13] = playerStatus->targetYaw;
        }
    }

    return ApiStatus_DONE2;
}

ApiStatus TeleportPartnerToPlayer(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerStatus* playerStatus2 = &gPlayerStatus;
    Npc* partner;

    if (gPlayerData.currentPartner == NO_PARTNER) {
        return ApiStatus_DONE2;
    }

    partner = get_npc_unsafe(NPC_PARTNER);
    partner->pos.x = playerStatus->position.x;
    partner->pos.z = playerStatus->position.z;

    if (is_current_partner_flying()) {
        partner->pos.y = playerStatus->position.y;
    }

    set_npc_yaw(partner, playerStatus2->targetYaw);
    clear_partner_move_history(partner);
    return ApiStatus_DONE2;
}

// currentPartner is being loaded as unsigned instead of signed
#ifdef NON_MATCHING
ApiStatus func_80283908(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerStatus* playerStatus2 = &gPlayerStatus;
    Camera* camera = CURRENT_CAM;
    s8 currentPartner = gPlayerData.currentPartner;

    playerStatus->position.x = gGameStatusPtr->savedPos.x;
    playerStatus->position.y = gGameStatusPtr->savedPos.y;
    playerStatus->position.z = gGameStatusPtr->savedPos.z;

    if (currentPartner != NO_PARTNER) {
        Npc* partner = get_npc_unsafe(NPC_PARTNER);
        f32 angle = clamp_angle((playerStatus2->spriteFacingAngle < 180.0f) ? (90.0f) : (-90.0f));
        partner->pos.x = playerStatus2->position.x;
        partner->pos.y = playerStatus2->position.y;
        partner->pos.z = playerStatus2->position.z;
        add_vec2D_polar(&partner->pos.x, &partner->pos.z, playerStatus2->colliderDiameter + 5, angle);
        enable_partner_ai();
    }

    camera->unk_08 = 1;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/script_api/7E4690", func_80283908);
#endif

INCLUDE_ASM(s32, "world/script_api/7E4690", func_80283A50);

ApiStatus func_80283B88(ScriptInstance* script, s32 isInitialCall) {
    set_parter_tether_distance(20.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_80283BB0(ScriptInstance* script, s32 isInitialCall) {
    reset_parter_tether_distance();
    return ApiStatus_DONE2;
}

ApiStatus func_80283BD0(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        script->functionTemp[0].s = get_variable(script, *args++);
        move_player(script->functionTemp[0].s, playerStatus->targetYaw, playerStatus->runSpeed);
    }

    script->functionTemp[0].s--;
    return script->functionTemp[0].s < 0;
}

INCLUDE_ASM(s32, "world/script_api/7E4690", func_80283C34);

INCLUDE_ASM(s32, "world/script_api/7E4690", func_80283D00);

INCLUDE_ASM(s32, "world/script_api/7E4690", func_80283D6C);

INCLUDE_ASM(s32, "world/script_api/7E4690", func_80283DF0);

INCLUDE_ASM(s32, "world/script_api/7E4690", func_80283E2C);
