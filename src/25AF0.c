#include "common.h"
#include "map.h"

void func_8004A6F0(ScriptInstance* script) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[0].s = script->functionTemp[1].s;
    }
}

void func_8004A73C(ScriptInstance* script) {
    Enemy* enemy = script->owner1.enemy;

    get_npc_unsafe(enemy->npcID);
    if (enemy->unk_B4 == 0) {
        script->functionTemp[0].s = script->functionTemp[1].s;
    }
}

INCLUDE_ASM(s32, "25AF0", func_8004A784);
