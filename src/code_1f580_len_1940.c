#include "common.h"

INCLUDE_API_ASM("code_1f580_len_1940", SetEncounterStatusFlags);

INCLUDE_ASM(s32, "code_1f580_len_1940", func_800441F0);

INCLUDE_ASM(s32, "code_1f580_len_1940", func_80044238);

ApiStatus LoadDemoBattle(ScriptInstance* script, s32 isInitialCall) {
    load_demo_battle(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

// ???
ApiStatus func_80044290(ScriptInstance* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

INCLUDE_API_ASM("code_1f580_len_1940", MakeNpcs);

INCLUDE_API_ASM("code_1f580_len_1940", RemoveNpc);

INCLUDE_API_ASM("code_1f580_len_1940", RemoveEncounter);

INCLUDE_API_ASM("code_1f580_len_1940", GetBattleOutcome);

INCLUDE_ASM(s32, "code_1f580_len_1940", func_800445A8);

INCLUDE_ASM(s32, "code_1f580_len_1940", func_800445D4);

ApiStatus GetOwnerEncountered(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, script->ownerActorID->encountered);
    return ApiStatus_DONE2;
}

INCLUDE_API_ASM("code_1f580_len_1940", DoNpcDefeat);

INCLUDE_ASM(s32, "code_1f580_len_1940", start_battle);

ApiStatus StartBattle(ScriptInstance* script, s32 isInitialCall) {
    start_battle(script, -1);
    return ApiStatus_DONE1;
}

ApiStatus StartBattleWith(ScriptInstance* script, s32 isInitialCall) {
    start_battle(script, get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE1;
}

INCLUDE_API_ASM("code_1f580_len_1940", StartBossBattle);

ApiStatus SetBattleMusic(ScriptInstance* script, s32 isInitialCall) {
    Bytecode songID = get_variable(script, *script->ptrReadPos);
    EncounterStatus* currentEncounter = &gCurrentEncounter;

    currentEncounter->allowFleeing = 1;
    currentEncounter->songID = songID;
    currentEncounter->unk_18 = -1;
    return ApiStatus_DONE2;
}

INCLUDE_API_ASM("code_1f580_len_1940", BindNpcAI);

INCLUDE_API_ASM("code_1f580_len_1940", BindNpcIdle);

INCLUDE_API_ASM("code_1f580_len_1940", RestartNpcAI);

INCLUDE_API_ASM("code_1f580_len_1940", EnableNpcAI);

INCLUDE_API_ASM("code_1f580_len_1940", SetNpcAux);

INCLUDE_API_ASM("code_1f580_len_1940", BindNpcAux);

INCLUDE_API_ASM("code_1f580_len_1940", RestartNpcAux);

INCLUDE_API_ASM("code_1f580_len_1940", EnableNpcAux);

INCLUDE_API_ASM("code_1f580_len_1940", BindNpcInteract);

INCLUDE_API_ASM("code_1f580_len_1940", BindNpcHit);

INCLUDE_API_ASM("code_1f580_len_1940", BindNpcDefeat);

INCLUDE_API_ASM("code_1f580_len_1940", SetSelfVar);

INCLUDE_API_ASM("code_1f580_len_1940", GetSelfVar);

INCLUDE_API_ASM("code_1f580_len_1940", SetNpcVar);

INCLUDE_API_ASM("code_1f580_len_1940", GetNpcVar);

INCLUDE_API_ASM("code_1f580_len_1940", SetSelfRotation);

ApiStatus SetSelfEnemyFlags(ScriptInstance* script, s32 isInitialCall) {
    script->ownerActorID->flags = *script->ptrReadPos;
    return ApiStatus_DONE2;
}

INCLUDE_API_ASM("code_1f580_len_1940", SetSelfEnemyFlagBits);

INCLUDE_ASM(s32, "code_1f580_len_1940", func_80045580);

ApiStatus GetSelfNpcID(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, script->ownerActorID->npcID);
    return ApiStatus_DONE2;
}

INCLUDE_API_ASM("code_1f580_len_1940", ClearDefeatedEnemies);

INCLUDE_API_ASM("code_1f580_len_1940", SetEnemyFlagBits);

INCLUDE_ASM(s32, "code_1f580_len_1940", func_8004572C);

INCLUDE_API_ASM("code_1f580_len_1940", GetSelfAnimationFromTable);

INCLUDE_ASM(s32, "code_1f580_len_1940", func_80045798);

INCLUDE_ASM(s32, "code_1f580_len_1940", func_800457C4);

INCLUDE_ASM(s32, "code_1f580_len_1940", func_800457F8);

INCLUDE_ASM(s32, "code_1f580_len_1940", func_8004580C);

INCLUDE_ASM(s32, "code_1f580_len_1940", func_80045838);

INCLUDE_ASM(s32, "code_1f580_len_1940", func_800458CC);

INCLUDE_ASM(s32, "code_1f580_len_1940", func_80045900);

INCLUDE_ASM(s32, "code_1f580_len_1940", func_80045A58);
