#include "common.h"

INCLUDE_ASM(s32, "code_1f580_len_1940", SetEncounterStatusFlags, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_800441F0(ScriptInstance* script, s32 isInitialCall) {
    Bytecode arg1 = *script->ptrReadPos;

    set_variable(script, arg1, func_80044148());
    return ApiStatus_DONE2;
}

ApiStatus func_80044238(ScriptInstance* script, s32 isInitialCall) {
    func_80072BCC(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus LoadDemoBattle(ScriptInstance* script, s32 isInitialCall) {
    load_demo_battle(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus func_80044290(ScriptInstance* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1f580_len_1940", MakeNpcs, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", RemoveNpc, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", RemoveEncounter, ScriptInstance* script, s32 isInitialCall);

ApiStatus GetBattleOutcome(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gCurrentEncounter.battleOutcome);
    return ApiStatus_DONE2;
}

ApiStatus func_800445A8(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, script->ownerActorID->unk_C4);
    return ApiStatus_DONE2;
}

ApiStatus func_800445D4(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, script->ownerActorID->unk_C8);
    return ApiStatus_DONE2;
}

ApiStatus GetOwnerEncounterTrigger(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, script->ownerActorID->encountered);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1f580_len_1940", DoNpcDefeat, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", start_battle);

ApiStatus StartBattle(ScriptInstance* script, s32 isInitialCall) {
    start_battle(script, -1);
    return ApiStatus_DONE1;
}

ApiStatus StartBattleWith(ScriptInstance* script, s32 isInitialCall) {
    start_battle(script, get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE1;
}

INCLUDE_ASM(s32, "code_1f580_len_1940", StartBossBattle, ScriptInstance* script, s32 isInitialCall);

ApiStatus SetBattleMusic(ScriptInstance* script, s32 isInitialCall) {
    Bytecode songID = get_variable(script, *script->ptrReadPos);
    EncounterStatus* currentEncounter = &gCurrentEncounter;

    currentEncounter->allowFleeing = 1;
    currentEncounter->songID = songID;
    currentEncounter->unk_18 = -1;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1f580_len_1940", BindNpcAI, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", BindNpcIdle, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", RestartNpcAI, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", EnableNpcAI, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", SetNpcAux, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", BindNpcAux, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", RestartNpcAux, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", EnableNpcAux, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", BindNpcInteract, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", BindNpcHit, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", BindNpcDefeat, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", SetSelfVar, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", GetSelfVar, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", SetNpcVar, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", GetNpcVar, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", SetSelfRotation, ScriptInstance* script, s32 isInitialCall);

ApiStatus SetSelfEnemyFlags(ScriptInstance* script, s32 isInitialCall) {
    script->ownerActorID->flags = *script->ptrReadPos;
    return ApiStatus_DONE2;
}

ApiStatus SetSelfEnemyFlagBits(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    Enemy* owner = script->ownerActorID;
    s32 bits = thisPos[0];

    if (get_variable(script, thisPos[1])) {
        owner->flags |= bits;
    } else {
        owner->flags &= ~bits;
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1f580_len_1940", func_80045580);

ApiStatus GetSelfNpcID(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, script->ownerActorID->npcID);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1f580_len_1940", ClearDefeatedEnemies, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_1f580_len_1940", SetEnemyFlagBits, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_8004572C(ScriptInstance* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1f580_len_1940", GetSelfAnimationFromTable, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_80045798(ScriptInstance* script, s32 isInitialCall) {
    D_8010EF08 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus func_800457C4(ScriptInstance* script, s32 isInitialCall) {
    Enemy* ownerActor = script->ownerActorID;

    ownerActor->unk_B5 = get_variable(script, *script->ptrReadPos);
    return 2;
}

ApiStatus func_800457F8(ScriptInstance* script, s32 isInitialCall) {
    gCurrentEncounter.unk_12 = 1;
    return ApiStatus_DONE2;
}

ApiStatus func_8004580C(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gCurrentEncounter.hitTier);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1f580_len_1940", func_80045838);

ApiStatus func_800458CC(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, script->ownerActorID->npcSettings->unkFlags & 8);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1f580_len_1940", func_80045900);

INCLUDE_ASM(s32, "code_1f580_len_1940", func_80045A58);
