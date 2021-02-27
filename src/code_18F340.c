#include "common.h"

INCLUDE_ASM(s32, "code_18F340", func_80260A60);

ApiStatus func_80260AD4(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    s32 isStopped = playerActor->debuff == Debuff_FEAR
        || playerActor->debuff == Debuff_DIZZY
        || playerActor->debuff == Debuff_PARALYZE
        || playerActor->debuff == Debuff_SLEEP
        || playerActor->debuff == Debuff_FROZEN
        || playerActor->debuff == Debuff_STOP;

    if (playerActor->stoneStatus == 12) {
        isStopped = TRUE;
    }

    script->varTable[0] = isStopped;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_18F340", activate_defend_command);

INCLUDE_ASM(s32, "code_18F340", func_80260B70);

INCLUDE_ASM(s32, "code_18F340", func_80260BF4);

ApiStatus func_80260DB8(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= 0x40000;
    return ApiStatus_DONE2;
}

ApiStatus func_80260DD8(ScriptInstance* script, s32 isInitialCall) {
    Actor* player = gBattleStatus.playerActor;
    s32 var;

    if (gPlayerData.hasActionCommands) {
        return ApiStatus_DONE2;
    }

    var = player->varTable[0];
    if (var >= rand_int(100)) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80260E38(ScriptInstance* script, s32 isInitialCall) {
    show_battle_message(0x31, 60);
    return ApiStatus_DONE2;
}

ApiStatus func_80260E5C(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.flags1 &= ~0x8000;
    gBattleStatus.flags1 &= ~0x2000;
    gBattleStatus.flags1 &= ~0x4000;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_18F340", func_80260E90);

INCLUDE_ASM(s32, "code_18F340", func_80261064);

INCLUDE_ASM(s32, "code_18F340", func_802610CC);

INCLUDE_ASM(s32, "code_18F340", func_80261164);

INCLUDE_ASM(s32, "code_18F340", func_802611E8);

INCLUDE_ASM(s32, "code_18F340", func_8026127C);

ApiStatus func_80261388(ScriptInstance* script, s32 isInitialCall) {
    s32 partnerActorExists = gBattleStatus.partnerActor != NULL;

    script->varTable[0] = FALSE;
    if (partnerActorExists) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802613A8(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.selectedItemID = ItemId_LIFE_SHROOM;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_18F340", func_802613BC);

INCLUDE_ASM(s32, "code_18F340", func_80261478);

INCLUDE_ASM(s32, "code_18F340", func_80261530);

INCLUDE_ASM(s32, "code_18F340", func_802615C8);

INCLUDE_ASM(s32, "code_18F340", func_80261648);

INCLUDE_ASM(s32, "code_18F340", func_802616B4);

INCLUDE_ASM(s32, "code_18F340", func_802616F4);

INCLUDE_ASM(s32, "code_18F340", func_802619B4);

ApiStatus HasMerleeCastsLeft(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[0] = FALSE;
    if (playerData->merleeCastsLeft > 0) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_18F340", func_802619E8);

INCLUDE_ASM(s32, "code_18F340", func_80261B40);

INCLUDE_ASM(s32, "code_18F340", FXRecoverHP);

INCLUDE_ASM(s32, "code_18F340", FXRecoverFP);

ApiStatus IncrementPlayerHP(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->curHP++;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }
    return ApiStatus_DONE2;
}

ApiStatus IncrementPlayerFP(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->curFP++;
    if (playerData->curFP > playerData->curMaxFP) {
        playerData->curFP = playerData->curMaxFP;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80261D98(ScriptInstance* script, s32 isInitialCall) {
    inflict_status_set_duration(get_actor(script->owner1.actorID), 4, 0, 1);
    func_8026777C();
    return ApiStatus_DONE2;
}

ApiStatus func_80261DD4(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[11] = playerData->bootsLevel;
    script->varTable[12] = playerData->hammerLevel;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_18F340", func_80261DF4);

INCLUDE_ASM(s32, "code_18F340", func_80261FB4);

INCLUDE_ASM(s32, "code_18F340", func_802620F8);
