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

    if (unkDuplighost->actorPart1 != NULL) {
        unkDuplighost->actorPart1->flags |= 0x10;
    }

    if (unkDuplighost->actorPart2 != NULL) {
        unkDuplighost->actorPart2->flags |= 0x10;
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

//INCLUDE_ASM(s32, "battle/area_sam/623BA0", func_802196BC_62525C);
ApiStatus func_802196BC_62525C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Effect6FInstance* effect;
    f32 temp_f20;
    s32 temp_s0_9;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;
    s32 temp_s6;

    evt_get_variable(script, *args++);
    temp_s6 = evt_get_variable(script, *args++);
    temp_s5 = evt_get_variable(script, *args++);
    temp_s4 = evt_get_variable(script, *args++);
    temp_f20 = evt_get_float_variable(script, *args++);
    temp_s2 = evt_get_variable(script, *args++);
    temp_s3 = evt_get_variable(script, *args++);
    temp_s1 = evt_get_variable(script, *args++);
    temp_s0_9 = evt_get_variable(script, *args++);
    effect = playFX_6F(1, temp_s6, temp_s5, temp_s4, temp_f20, temp_s2);
    effect->data->rotation.z = temp_s3;
    effect->data->scale.x = temp_s1;
    effect->data->scale.y = temp_s0_9;
    effect->data->color.x = 255; // red
    effect->data->color.y = 255; // green
    effect->data->color.z = 255; // blue
    return ApiStatus_DONE2;
}
