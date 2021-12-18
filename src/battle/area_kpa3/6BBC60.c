#include "common.h"

#define NAMESPACE b_area_kpa3

INCLUDE_ASM(s32, "battle/area_kpa3/6BBC60", func_802180D0_6BBC60);

#include "common/ActorJumpToPos.inc.c"

#include "common/UnkActorSizeFunc.inc.c"

#include "common/UnkEffect6CFunc.inc.c"

typedef struct UnkDuplighost {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ ActorPart* actorPart1;
    /* 0x18 */ ActorPart* actorPart2;
    /* 0x1C */ char unk_1C[4];
} UnkDuplighost;

typedef struct UnkStruct1 {
    /* 0x00 */ char unk_00[8];
    /* 0x08 */ f32 unk_08;
} UnkStruct1;

typedef struct UnkStruct0 {
    /* 0x00 */ s32 flags;
    /* 0x04 */ char unk_04[8];
    /* 0x0C */ UnkStruct1* unk_0C;
} UnkStruct0;

ApiStatus func_80218BC4_6BC754(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkStruct0* unkStruct0 = evt_get_variable(script, *args++);

    unkStruct0->unk_0C->unk_08 = -1000.0f;
    return ApiStatus_DONE2;
}

ApiStatus func_80218BFC_6BC78C(Evt* script, s32 isInitialCall) {
    UnkStruct0* unkStruct0 = evt_get_variable(script, *script->ptrReadPos);

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
    UnkDuplighost* unkDuplighost;

    unkDuplighost = get_actor(script->owner1.actor)->state.varTable[2];
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
    UnkDuplighost* unkDuplighost = get_actor(script->owner1.actor)->state.varTable[2];

    unkDuplighost->unk_04 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_80219474_6BD004(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkDuplighost* unkDuplighost = get_actor(script->owner1.enemyID)->state.varTable[2];

    unkDuplighost->unk_0C = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_802194C0_6BD050(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkDuplighost* unkDuplighost = get_actor(script->owner1.enemyID)->state.varTable[2];

    unkDuplighost->unk_10 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

//INCLUDE_ASM(s32, "battle/area_kpa3/6BBC60", func_80219588_6BD118);
ApiStatus func_80219588_6BD118(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    evt_set_variable(script, *args++, gPlayerData.currentPartner);
    evt_set_variable(script, *args++, gPlayerData.partners[gPlayerData.currentPartner].level);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/area_kpa3/6BBC60", func_802195F4_6BD184);
