#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_sam

INCLUDE_ASM(s32, "battle/area_sam/623BA0", func_80218000_623BA0);

#include "common/ActorJumpToPos.inc.c"

#include "common/UnkActorSizeFunc.inc.c"

#include "common/UnkEffect6CFunc.inc.c"

ApiStatus func_80218AF4_624694(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkStruct0* unkStruct0 = (UnkStruct0*)evt_get_variable(script, *args++);

    unkStruct0->unk_0C->unk_08 = -1000.0f;
    return ApiStatus_DONE2;
}

ApiStatus func_80218B2C_6246CC(Evt* script, s32 isInitialCall) {
    UnkStruct0* unkStruct0 = (UnkStruct0*)evt_get_variable(script, *script->ptrReadPos);

    unkStruct0->unk_0C->unk_08 = 144.0f;
    unkStruct0->flags |= 0x10;
    return ApiStatus_DONE2;
}

#include "common/UnkBattleFunc1.inc.c"

#include "common/UnkActorPosFunc.inc.c"

#define NAMESPACE dup_b_area_sam
#include "common/UnkActorPosFunc.inc.c"
#define NAMESPACE b_area_sam

INCLUDE_ASM(s32, "battle/area_sam/623BA0", func_80218E88_624A28);

ApiStatus func_80219304_624EA4(Evt* script, s32 isInitialCall) {
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.actorID)->state.varTable[2];

    unkDuplighost->flags = 0;

    if (unkDuplighost->effect1 != NULL) {
        unkDuplighost->effect1->flags |= EFFECT_INSTANCE_FLAGS_10;
    }

    if (unkDuplighost->effect2 != NULL) {
        unkDuplighost->effect2->flags |= EFFECT_INSTANCE_FLAGS_10;
    }
    
    return ApiStatus_DONE2;
}

ApiStatus func_80219358_624EF8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.actorID)->state.varTable[2];

    unkDuplighost->unk_04 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_802193A4_624F44(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.enemyID)->state.varTable[2];

    unkDuplighost->unk_0C = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_802193F0_624F90(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.enemyID)->state.varTable[2];

    unkDuplighost->unk_10 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

ApiStatus func_802194B8_625058(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    evt_set_variable(script, *args++, gPlayerData.currentPartner);
    evt_set_variable(script, *args++, gPlayerData.partners[gPlayerData.currentPartner].level);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/area_sam/623BA0", func_80219524_6250C4);

#define NAMESPACE dup_b_area_sam
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_sam

#include "common/UnkEffect6FFunc.inc.c"
