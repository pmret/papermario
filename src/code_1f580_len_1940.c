#include "common.h"

INCLUDE_ASM(code_1f580_len_1940, SetEncounterStatusFlags);

s32 LoadDemoBattle(ScriptInstance* script) {
    load_demo_battle(get_variable(script, *script->ptrReadPos));
    return 2;
}

// ???
s32 func_80044290(ScriptInstance* script) {
    return 2;
}

INCLUDE_ASM(code_1f580_len_1940, MakeNpcs);

INCLUDE_ASM(code_1f580_len_1940, RemoveNpc);

INCLUDE_ASM(code_1f580_len_1940, RemoveEncounter);

INCLUDE_ASM(code_1f580_len_1940, GetBattleOutcome);

s32 GetOwnerEncountered(ScriptInstance* script) {
    set_variable(script, *script->ptrReadPos, script->ownerActorID->encountered);
    return 2;
}

INCLUDE_ASM(code_1f580_len_1940, DoNpcDefeat);

INCLUDE_ASM(code_1f580_len_1940, start_battle);

s32 StartBattle(ScriptInstance* script) {
    start_battle(script, -1);
    return 1;
}

s32 StartBattleWith(ScriptInstance* script) {
    start_battle(script, get_variable(script, *script->ptrReadPos));
    return 1;
}

INCLUDE_ASM(code_1f580_len_1940, StartBossBattle);

INCLUDE_ASM(code_1f580_len_1940, SetBattleMusic);

INCLUDE_ASM(code_1f580_len_1940, BindNpcAI);

INCLUDE_ASM(code_1f580_len_1940, BindNpcIdle);

INCLUDE_ASM(code_1f580_len_1940, RestartNpcAI);

INCLUDE_ASM(code_1f580_len_1940, EnableNpcAI);

INCLUDE_ASM(code_1f580_len_1940, SetNpcAux);

INCLUDE_ASM(code_1f580_len_1940, BindNpcAux);

INCLUDE_ASM(code_1f580_len_1940, RestartNpcAux);

INCLUDE_ASM(code_1f580_len_1940, EnableNpcAux);

INCLUDE_ASM(code_1f580_len_1940, BindNpcInteract);

INCLUDE_ASM(code_1f580_len_1940, BindNpcHit);

INCLUDE_ASM(code_1f580_len_1940, BindNpcDefeat);

INCLUDE_ASM(code_1f580_len_1940, SetSelfVar);

INCLUDE_ASM(code_1f580_len_1940, GetSelfVar);

INCLUDE_ASM(code_1f580_len_1940, SetNpcVar);

INCLUDE_ASM(code_1f580_len_1940, GetNpcVar);

INCLUDE_ASM(code_1f580_len_1940, SetSelfRotation);

s32 SetSelfEnemyFlags(ScriptInstance* script) {
    script->ownerActorID->flags = *script->ptrReadPos;
    return 2;
}

INCLUDE_ASM(code_1f580_len_1940, SetSelfEnemyFlagBits);

s32 GetSelfNpcID(ScriptInstance* script) {
    set_variable(script, *script->ptrReadPos, script->ownerActorID->npcID);
    return 2;
}

INCLUDE_ASM(code_1f580_len_1940, ClearDefeatedEnemies);

INCLUDE_ASM(code_1f580_len_1940, SetEnemyFlagBits);

INCLUDE_ASM(code_1f580_len_1940, GetSelfAnimationFromTable);
