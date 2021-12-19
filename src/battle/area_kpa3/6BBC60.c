#include "common.h"

#define NAMESPACE b_area_kpa3

INCLUDE_ASM(s32, "battle/area_kpa3/6BBC60", func_802180D0_6BBC60);

#include "common/ActorJumpToPos.inc.c"

#include "common/UnkActorSizeFunc.inc.c"

#include "common/UnkEffect6CFunc.inc.c"

ApiStatus func_80218BC4_6BC754(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkStruct0* unkStruct0 = (UnkStruct0*)evt_get_variable(script, *args++);

    unkStruct0->unk_0C->unk_08 = -1000.0f;
    return ApiStatus_DONE2;
}

ApiStatus func_80218BFC_6BC78C(Evt* script, s32 isInitialCall) {
    UnkStruct0* unkStruct0 = (UnkStruct0*)evt_get_variable(script, *script->ptrReadPos);

    unkStruct0->unk_0C->unk_08 = 144.0f;
    unkStruct0->flags |= 0x10;
    return ApiStatus_DONE2;
}

#define NAMESPACE dup_b_area_kpa3
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_kpa3

#include "common/UnkActorPosFunc.inc.c"

#define NAMESPACE dup_b_area_kpa3
#include "common/UnkActorPosFunc.inc.c"
#define NAMESPACE b_area_kpa3

INCLUDE_ASM(s32, "battle/area_kpa3/6BBC60", func_80218F58_6BCAE8);

ApiStatus func_802193D4_6BCF64(Evt* script, s32 isInitialCall) {
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

ApiStatus func_80219428_6BCFB8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.actorID)->state.varTable[2];

    unkDuplighost->unk_04 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_80219474_6BD004(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.enemyID)->state.varTable[2];

    unkDuplighost->unk_0C = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_802194C0_6BD050(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.enemyID)->state.varTable[2];

    unkDuplighost->unk_10 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

ApiStatus func_80219588_6BD118(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    evt_set_variable(script, *args++, gPlayerData.currentPartner);
    evt_set_variable(script, *args++, gPlayerData.partners[gPlayerData.currentPartner].level);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/area_kpa3/6BBC60", func_802195F4_6BD184);
/*
ApiStatus func_802195F4_6BD184(Evt* script, s32 isInitialCall) {
    s32 temp_s0 = evt_get_variable(script, *script->ptrReadPos);
    s32* phi_a0 = NULL;
    
    switch (temp_s0) {
    case 1:
        phi_a0 = &D_8021E990_6C2520;
        break;
    case 2:
        phi_a0 = &D_80220644_6C41D4;
        break;
    case 3:
        phi_a0 = &D_802218A4_6C5434;
        break;
    case 4:
        phi_a0 = &D_80222830_6C63C0;
        break;
    case 9:
        phi_a0 = &D_80223C00_6C7790;
        break;
    case 6:
        phi_a0 = &D_80224AFC_6C868C;
        break;
    case 7:
        phi_a0 = &D_80226494_6CA024;
        break;
    case 8:
        phi_a0 = &D_80227734_6CB2C4;
        break;
    }
    phi_a0->unk8 = (s32) get_actor(script->owner1.enemyID)->turnPriority;
    return 2;
}
*/
