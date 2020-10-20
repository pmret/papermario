#include "common.h"
#include "map.h"

ApiStatus SetEncounterStatusFlags(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    EncounterStatus* currentEncounter2 = &gCurrentEncounter;
    s32 a0 = *args++;

    if (get_variable(script, *args)) {
        currentEncounter->flags |= a0;
    } else {
        currentEncounter2->flags &= ~a0;
    }

    return ApiStatus_DONE2;
}

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
    set_variable(script, *script->ptrReadPos, script->owner1.enemy->unk_C4);
    return ApiStatus_DONE2;
}

ApiStatus func_800445D4(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, script->owner1.enemy->unk_C8);
    return ApiStatus_DONE2;
}

ApiStatus GetOwnerEncounterTrigger(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, script->owner1.enemy->encountered);
    return ApiStatus_DONE2;
}

ApiStatus DoNpcDefeat(ScriptInstance* script, s32 isInitialCall) {
    Enemy* owner = script->owner1.enemy;
    Npc* temp_s1 = get_npc_unsafe(owner->npcID);
    ScriptInstance* newScript;

    kill_script(script);
    temp_s1->currentAnim = owner->animList[6];
    newScript = start_script(&SCRIPT_NpcDefeat, 10, 0);
    owner->defeatScript = newScript;
    owner->defeatScriptID = newScript->id;
    newScript->owner1.enemy = owner;
    newScript->owner2.npcID = owner->npcID;
    newScript->groupFlags = owner->scriptGroup;

    return ApiStatus_FINISH;
}

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

ApiStatus BindNpcIdle(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* owner = script->owner1.enemy;
    NpcId npcID = get_variable(script, *args++);
    Bytecode* aiBytecode = (Bytecode*)get_variable(script, *args);

    if (npcID == NpcId_SELF) {
        npcID = owner->npcID;
    }

    owner = get_enemy(npcID);
    owner->aiBytecode = aiBytecode;

    return ApiStatus_DONE2;
}

ApiStatus RestartNpcAI(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    NpcId npcId = get_variable(script, *args++);
    ScriptInstance* newScript;
    s32 groupFlags;

    if (npcId == NpcId_SELF) {
        npcId = npc->npcID;
    }

    npc = get_enemy(npcId);

    if (npc->flags & 1) {
        groupFlags = 10;
    } else {
        groupFlags = 11;
    }

    if (npc->aiScript != NULL) {
        kill_script_by_ID(npc->aiScriptID);
    }

    npc->unk_C8 = 100;
    newScript = start_script(npc->aiBytecode, 10, 0);
    npc->aiScript = newScript;
    npc->aiScriptID = newScript->id;
    newScript->owner1.enemy = npc;
    newScript->owner2.npc = script->owner2.npc;
    newScript->groupFlags = groupFlags;

    return ApiStatus_DONE2;
}

ApiStatus EnableNpcAI(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    NpcId npcId = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args);

    if (npcId == NpcId_SELF) {
        npcId = npc->npcID;
    }

    npc = get_enemy(npcId);

    if (var2 != 0) {
        if (npc->aiScript != NULL) {
            resume_all_script(npc->aiScriptID);
        }
    } else if (npc->aiScript != NULL) {
        suspend_all_script(npc->aiScriptID);
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1f580_len_1940", SetNpcAux, ScriptInstance* script, s32 isInitialCall);

ApiStatus BindNpcAux(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    NpcId npcId = get_variable(script, *args++);
    Bytecode* auxBytecode = (Bytecode*)get_variable(script, *args);

    if (npcId == NpcId_SELF) {
        npcId = npc->npcID;
    }

    npc = get_enemy(npcId);
    npc->auxBytecode = auxBytecode;

    return ApiStatus_DONE2;
}

ApiStatus RestartNpcAux(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    NpcId npcID = get_variable(script, *args++);
    ScriptInstance* newScript;
    s32 groupFlags;

    if (npcID == NpcId_SELF) {
        npcID = npc->npcID;
    }

    npc = get_enemy(npcID);

    if (npc->flags & 1) {
        groupFlags = 10;
    } else {
        groupFlags = 11;
    }

    if (npc->auxScript != NULL) {
        kill_script_by_ID(npc->auxScriptID);
    }

    newScript = start_script(npc->auxBytecode, 10, 0);
    npc->auxScript = newScript;
    npc->auxScriptID = newScript->id;
    newScript->owner1.enemy = npc;
    newScript->owner2.npcID = npcID;
    newScript->groupFlags = groupFlags;

    return ApiStatus_DONE2;
}

ApiStatus EnableNpcAux(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    NpcId npcId = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args);

    if (npcId == NpcId_SELF) {
        npcId = npc->npcID;
    }

    npc = get_enemy(npcId);

    if (var2 != 0) {
        if (npc->auxScript != NULL) {
            resume_all_script(npc->auxScriptID);
        }
    } else if (npc->auxScript != NULL) {
        suspend_all_script(npc->auxScriptID);
    }

    return ApiStatus_DONE2;
}

ApiStatus BindNpcInteract(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    NpcId npcId = get_variable(script, *args++);
    Bytecode* interactBytecode = (Bytecode*)get_variable(script, *args);

    if (npcId == NpcId_SELF) {
        npcId = npc->npcID;
    }

    npc = get_enemy(npcId);

    if (npc->interactScript != NULL) {
        kill_script_by_ID(npc->interactScriptID);
    }
    npc->interactBytecode = interactBytecode;

    return ApiStatus_DONE2;
}

ApiStatus BindNpcHit(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    NpcId npcId = get_variable(script, *args++);
    Bytecode* hitBytecode = (Bytecode*)get_variable(script, *args);

    if (npcId == NpcId_SELF) {
        npcId = npc->npcID;
    }

    npc = get_enemy(npcId);

    if (npc->hitScript != NULL) {
        kill_script_by_ID(npc->hitScriptID);
    }
    npc->hitBytecode = hitBytecode;

    return ApiStatus_DONE2;
}

ApiStatus BindNpcDefeat(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    s32 npcId = get_variable(script, *args++);
    Bytecode* defeatBytecode = (Bytecode*)get_variable(script, *args);

    if (npcId == -1) {
        npcId = npc->npcID;
    }

    npc = get_enemy(npcId);
    npc->defeatBytecode = defeatBytecode;

    return ApiStatus_DONE2;
}

ApiStatus SetSelfVar(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* owner = script->owner1.enemy;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args);

    owner->varTable[var1] = var2;
    return ApiStatus_DONE2;
}

ApiStatus GetSelfVar(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    set_variable(script, *args, script->owner1.enemy->varTable[get_variable(script, *args++)]);
    return ApiStatus_DONE2;
}

ApiStatus SetNpcVar(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    NpcId npcId = get_variable(script, *args++);
    s32 varIdx = get_variable(script, *args++);
    s32 val = get_variable(script, *args);

    if (npcId == NpcId_SELF) {
        npcId = npc->npcID;
    }

    npc = get_enemy(npcId);
    npc->varTable[varIdx] = val;

    return ApiStatus_DONE2;
}

ApiStatus GetNpcVar(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc;
    NpcId npcID;
    s32 varIdx;
    s32 var3;

    npc = script->owner1.enemy;
    npcID = get_variable(script, *args++);
    varIdx = get_variable(script, *args++);
    var3 = *args;

    if (npcID == NpcId_SELF) {
        npcID = npc->npcID;
    }

    npc = get_enemy(npcID);
    set_variable(script, var3, npc->varTable[varIdx]);

    return ApiStatus_DONE2;
}

ApiStatus SetSelfRotation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* self = get_npc_unsafe(script->owner2.npcID);
    s32 rotX = get_variable(script, *args++);
    s32 rotY = get_variable(script, *args++);
    s32 rotZ = get_variable(script, *args++);

    self->rotation.x = rotX;
    self->rotation.y = rotY;
    self->rotation.z = rotZ;

    return ApiStatus_DONE2;
}

ApiStatus SetSelfEnemyFlags(ScriptInstance* script, s32 isInitialCall) {
    script->owner1.enemy->flags = *script->ptrReadPos;
    return ApiStatus_DONE2;
}

ApiStatus SetSelfEnemyFlagBits(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* owner = script->owner1.enemy;
    s32 bits = *args++;

    if (get_variable(script, *args)) {
        owner->flags |= bits;
    } else {
        owner->flags &= ~bits;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80045580(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* owner = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(script->owner2.npcID);

    owner->unk_07 = get_variable(script, *args);
    owner->unk_10.x = npc->pos.x;
    owner->unk_10.y = npc->pos.y;
    owner->unk_10.z = npc->pos.z;

    return ApiStatus_DONE2;
}

ApiStatus GetSelfNpcID(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, script->owner1.enemy->npcID);
    return ApiStatus_DONE2;
}

ApiStatus ClearDefeatedEnemies(ScriptInstance* script, s32 isInitialCall) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < 60; i++) {
        for (j = 0; j < 12; j++) {
            currentEncounter->defeatFlags[i][j] = 0;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus SetEnemyFlagBits(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    NpcId npcId = get_variable(script, *args++);
    s32 bits = *args++;
    s32 var2 = get_variable(script, *args);

    if (npcId == NpcId_SELF) {
        npcId = npc->npcID;
    }

    npc = get_enemy(npcId);

    if (var2 != NULL) {
        npc->flags |= bits;
    } else {
        npc->flags &= ~bits;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_8004572C(ScriptInstance* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

ApiStatus GetSelfAnimationFromTable(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* owner = script->owner1.enemy;

    set_variable(script, *args, owner->animList[get_variable(script, *args++)]);
    return ApiStatus_DONE2;
}

ApiStatus func_80045798(ScriptInstance* script, s32 isInitialCall) {
    D_8010EF08 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus func_800457C4(ScriptInstance* script, s32 isInitialCall) {
    Enemy* ownerActor = script->owner1.enemy;

    ownerActor->unk_B5 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus func_800457F8(ScriptInstance* script, s32 isInitialCall) {
    gCurrentEncounter.unk_12 = 1;
    return ApiStatus_DONE2;
}

ApiStatus func_8004580C(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gCurrentEncounter.hitTier);
    return ApiStatus_DONE2;
}

ApiStatus func_80045838(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args);

    npc = resolve_npc(script, var1);
    if (npc != NULL) {
        func_800494C0(npc, var2, var3);
    }

    return ApiStatus_DONE2;

    do {} while (0); // necessary to match
}

ApiStatus func_800458CC(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, script->owner1.enemy->npcSettings->unk_2A & 8);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1f580_len_1940", func_80045900);

ApiStatus SetTattleString(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcId enemyId = get_variable(script, *args++);
    u32 tattleString = get_variable(script, *args);
    Enemy* npc = get_enemy(enemyId);

    npc->tattleString = tattleString;
    return ApiStatus_DONE2;
}
