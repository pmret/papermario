#include "common.h"

ApiStatus func_80282880(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = PLAYER_STATUS;

    playerStatus->position.x += (script->varTable[0] - playerStatus->position.x) / 2;
    playerStatus->position.z += (script->varTable[2] - playerStatus->position.z) / 2;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/script_api/7E3700", func_802828DC);

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80282C40);

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80282E30);

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80283080);

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80283174);

ApiStatus CheckActionState(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode a0 = *args++;
    s32 var = get_float_variable(script, *args);

    set_variable(script, a0, gPlayerActionState == var);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80283240);

INCLUDE_ASM(s32, "world/script_api/7E3700", CreatePushBlockGrid);

INCLUDE_ASM(s32, "world/script_api/7E3700", SetPushBlock);

INCLUDE_ASM(s32, "world/script_api/7E3700", GetPushBlock);

INCLUDE_ASM(s32, "world/script_api/7E3700", GetGridIndexFromPos);

INCLUDE_ASM(s32, "world/script_api/7E3700", SetPushBlockFallEffect);

ApiStatus func_80283810(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = PLAYER_STATUS;

    script->varTable[10] = 0;
    if (partner_get_ride_script() != NULL) {
        if (D_8010EBB0[0] == 0) {
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
    PlayerStatus* playerStatus = PLAYER_STATUS;
    PlayerStatus* playerStatus2 = PLAYER_STATUS;
    Npc* partner;

    if (PLAYER_DATA->currentPartner == PartnerId_NONE) {
        return ApiStatus_DONE2;
    }

    partner = get_npc_unsafe(NpcId_PARTNER);
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
    PlayerStatus* playerStatus = PLAYER_STATUS;
    PlayerStatus* playerStatus2 = PLAYER_STATUS;
    Camera* camera = CURRENT_CAM;
    s8 currentPartner = PLAYER_DATA->currentPartner;

    playerStatus->position.x = GAME_STATUS->savedPos.x;
    playerStatus->position.y = GAME_STATUS->savedPos.y;
    playerStatus->position.z = GAME_STATUS->savedPos.z;

    if (currentPartner != PartnerId_NONE) {
        Npc* partner = get_npc_unsafe(NpcId_PARTNER);
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
INCLUDE_ASM(s32, "world/script_api/7E3700", func_80283908);
#endif

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80283A50);

ApiStatus func_80283B88(ScriptInstance* script, s32 isInitialCall) {
    func_800EF394(20.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_80283BB0(ScriptInstance* script, s32 isInitialCall) {
    func_800EF3A4();
    return ApiStatus_DONE2;
}

ApiStatus func_80283BD0(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = PLAYER_STATUS;

    if (isInitialCall) {
        script->functionTemp[0].s = get_variable(script, *args++);
        move_player(script->functionTemp[0].s, playerStatus->targetYaw, playerStatus->runSpeed);
    }

    script->functionTemp[0].s--;
    return script->functionTemp[0].s < 0;
}

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80283C34);

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80283D00);

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80283D6C);

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80283DF0);

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80283E2C);
