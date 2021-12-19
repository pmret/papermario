#include "common.h"

#define NAMESPACE b_area_pra3

INCLUDE_ASM(s32, "battle/area_pra3/669D80", func_80218000_669D80);

#include "common/ActorJumpToPos.inc.c"

#include "common/UnkActorSizeFunc.inc.c"

#include "common/UnkEffect6CFunc.inc.c"

ApiStatus func_80218AF4_66A874(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkStruct0* unkStruct0 = (UnkStruct0*)evt_get_variable(script, *args++);

    unkStruct0->unk_0C->unk_08 = -1000.0f;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/area_pra3/669D80", func_80218B2C_66A8AC);

#define NAMESPACE dup2_b_area_pra3
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_pra3

INCLUDE_ASM(s32, "battle/area_pra3/669D80", func_80218C40_66A9C0);

#include "common/UnkActorPosFunc.inc.c"

INCLUDE_ASM(s32, "battle/area_pra3/669D80", func_80218E88_66AC08);

ApiStatus func_80219304_66B084(Evt* script, s32 isInitialCall) {
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.actorID)->state.varTable[2];

    unkDuplighost->flags = 0;

    if (unkDuplighost->actorPart1 != NULL) {
        unkDuplighost->actorPart1->flags |= 0x10;
    }

    if (unkDuplighost->actorPart2 != NULL) {
        unkDuplighost->actorPart2->flags |= 0x10;
    }
    
    return ApiStatus_DONE2;
}

ApiStatus func_80219358_66B0D8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.enemyID)->state.varTable[2];

    unkDuplighost->unk_04 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_802193A4_66B124(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.enemyID)->state.varTable[2];

    unkDuplighost->unk_0C = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/area_pra3/669D80", func_802193F0_66B170);

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

ApiStatus func_802194B8_66B238(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    evt_set_variable(script, *args++, gPlayerData.currentPartner);
    evt_set_variable(script, *args++, gPlayerData.partners[gPlayerData.currentPartner].level);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/area_pra3/669D80", func_80219524_66B2A4);

#define NAMESPACE dup3_b_area_pra3
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_pra3

#include "common/UnkBattleFunc2.inc.c"
