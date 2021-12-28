#include "common.h"

#define NAMESPACE b_area_mac

INCLUDE_ASM(s32, "battle/area_mac/464560", func_802180D0_464560);

INCLUDE_ASM(s32, "battle/area_mac/464560", func_80218100_464590);

INCLUDE_ASM(s32, "battle/area_mac/464560", func_80218300_464790);

#include "common/ActorJumpToPos.inc.c"

#include "common/UnkActorSizeFunc.inc.c"

#include "common/UnkEffect6CFunc.inc.c"

ApiStatus func_80218DF4_465284(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkStruct0* unkStruct0 = (UnkStruct0*)evt_get_variable(script, *args++);

    unkStruct0->unk_0C->unk_08 = -1000.0f;
    return ApiStatus_DONE2;
}

ApiStatus func_80218E2C_4652BC(Evt* script, s32 isInitialCall) {
    UnkStruct0* unkStruct0 = (UnkStruct0*) evt_get_variable(script, *script->ptrReadPos);

    unkStruct0->unk_0C->unk_08 = 144.0f;
    unkStruct0->flags |= 0x10;
    return ApiStatus_DONE2;
}

#define NAMESPACE dup_b_area_mac
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_mac

#include "common/UnkActorPosFunc.inc.c"

#define NAMESPACE dup_b_area_mac
#include "common/UnkActorPosFunc.inc.c"
#define NAMESPACE b_area_mac

INCLUDE_ASM(s32, "battle/area_mac/464560", func_80219188_465618);

ApiStatus func_80219604_465A94(Evt* script, s32 isInitialCall) {
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.actorID)->state.varTable[3];

    unkDuplighost->flags = 0;

    if (unkDuplighost->effect1 != NULL) {
        unkDuplighost->effect1->flags |= EFFECT_INSTANCE_FLAGS_10;
    }

    if (unkDuplighost->effect2 != NULL) {
        unkDuplighost->effect2->flags |= EFFECT_INSTANCE_FLAGS_10;
    }
    
    return ApiStatus_DONE2;
}

ApiStatus func_80219658_465AE8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.enemyID)->state.varTable[3];

    unkDuplighost->unk_04 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_802196A4_465B34(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.enemyID)->state.varTable[3];

    unkDuplighost->unk_0C = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_802196F0_465B80(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.enemyID)->state.varTable[3];

    unkDuplighost->unk_10 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

ApiStatus func_802197B8_465C48(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    evt_set_variable(script, *args++, gPlayerData.currentPartner);
    evt_set_variable(script, *args++, gPlayerData.partners[gPlayerData.currentPartner].level);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/area_mac/464560", func_80219824_465CB4);
