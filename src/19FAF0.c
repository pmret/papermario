#include "common.h"
#include "battle/battle.h"

ApiStatus func_80271210(ScriptInstance* script, s32 isInitialCall) {
    func_80070AF0(0, script->varTable[0], script->varTable[1], script->varTable[2]);
    return ApiStatus_DONE2;
}

ApiStatus func_80271258(ScriptInstance* script, s32 isInitialCall) {
    func_80070AF0(1, script->varTable[0], script->varTable[1], script->varTable[2]);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "19FAF0", func_802712A0);

INCLUDE_ASM(s32, "19FAF0", func_80271328);

INCLUDE_ASM(s32, "19FAF0", func_802713B0);

ApiStatus func_8027143C(ScriptInstance* script, s32 isInitialCall) {
    func_80070A90(0, script->varTable[0], script->varTable[1], script->varTable[2]);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "19FAF0", func_80271484);

INCLUDE_ASM(s32, "19FAF0", func_80271588);

INCLUDE_ASM(s32, "19FAF0", dispatch_event_player);

INCLUDE_ASM(s32, "19FAF0", dispatch_event_player_continue_turn);

INCLUDE_ASM(s32, "19FAF0", calc_player_test_enemy);

INCLUDE_ASM(s32, "19FAF0", calc_player_damage_enemy);

INCLUDE_ASM(s32, "19FAF0", dispatch_damage_event_player);

void dispatch_damage_event_player_0(s32 damageAmount, Event event) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->currentAttackElement = ELEMENT_END;
    battleStatus->unk_19A = 0;
    dispatch_damage_event_player(damageAmount, event, FALSE);
}

void dispatch_damage_event_player_1(s32 damageAmount, Event event) {
    dispatch_damage_event_player(damageAmount, event, TRUE);
}

INCLUDE_ASM(s32, "19FAF0", GetMenuSelection);

INCLUDE_ASM(s32, "19FAF0", func_80273444);

INCLUDE_ASM(s32, "19FAF0", PlayerFallToGoal);

INCLUDE_ASM(s32, "19FAF0", PlayerLandJump);

INCLUDE_ASM(s32, "19FAF0", PlayerRunToGoal);

INCLUDE_ASM(s32, "19FAF0", CancelablePlayerRunToGoal);

ApiStatus GetPlayerHP(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gPlayerData.curHP);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "19FAF0", PlayerDamageEnemy);

INCLUDE_ASM(s32, "19FAF0", PlayerPowerBounceEnemy);

INCLUDE_ASM(s32, "19FAF0", PlayerTestEnemy);

INCLUDE_ASM(s32, "19FAF0", DispatchDamagePlayerEvent);

INCLUDE_ASM(s32, "19FAF0", EnablePlayerBlur);

ApiStatus func_802749D8(ScriptInstance* script, s32 isInitialCall) {
    func_802549A0();
    return ApiStatus_DONE2;
}

ApiStatus func_802749F8(ScriptInstance* script, s32 isInitialCall) {
    func_802549C0();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "19FAF0", func_80274A18);

INCLUDE_ASM(s32, "19FAF0", func_802752AC);

INCLUDE_ASM(s32, "19FAF0", func_80275F00);

INCLUDE_ASM(s32, "19FAF0", DidActionSucceed);

ApiStatus func_80276EFC(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= 0x200000;
    return ApiStatus_DONE2;
}

ApiStatus func_80276F1C(ScriptInstance* script, s32 isInitialCall) {
    dispatch_event_player(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
