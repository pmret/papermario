#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_flo2

typedef struct SuctionPath {
    /* 0x00 */ Vec3f start;
    /* 0x0C */ Vec3f mid;
    /* 0x18 */ Vec3f end;
} SuctionPath; // size = 0x24

extern s32 D_8021A35C_5D09EC;
extern s32 D_8021A378_5D0A08;
extern SuctionPath D_80235E00[];

#include "common/StartRumbleWithParams.inc.c"

ApiStatus func_80218058_5CE6E8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(ACTOR_ENEMY0);

    actor->healthBarPosition.x = actor->homePos.x + evt_get_variable(script, *args++);
    actor->healthBarPosition.y = actor->homePos.y + evt_get_variable(script, *args++);
    actor->healthBarPosition.z = actor->homePos.z;
    return ApiStatus_DONE2;
}

#include "common/UnkFloatFunc.inc.c"

ApiStatus func_802182A4_5CE934(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    void* outVar1 = *args++;
    f32 x = evt_get_float_variable(script, outVar1);
    void* outVar2 = *args++;
    f32 y = evt_get_float_variable(script, outVar2);
    void* outVar3 = *args++;
    f32 z = evt_get_float_variable(script, outVar3);
    f32 temp_f26 = evt_get_float_variable(script, *args++);
    f32 temp_f24 = evt_get_float_variable(script, *args++);
    f32 factor = evt_get_float_variable(script, *args++);

    temp_f24 -= 15.0f;
    x += factor * cos_deg(temp_f26) * cos_deg(temp_f24);
    y += factor * sin_deg(temp_f26);
    z -= factor * cos_deg(temp_f26) * sin_deg(temp_f24);

    evt_set_float_variable(script, outVar1, x);
    evt_set_float_variable(script, outVar2, y);
    evt_set_float_variable(script, outVar3, z);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/area_flo2/5CE690", func_80218440_5CEAD0);

ApiStatus func_802185D4_5CEC64(Evt* script, s32 isInitialCall) {
    s32* actorID = &script->owner1.actorID;
    D_8021A35C_5D09EC = (s8) get_actor(*actorID)->turnPriority;
    D_8021A378_5D0A08 = (s8) get_actor(*actorID)->turnPriority;
    return ApiStatus_DONE2;
}

ApiStatus N(MakeSuctionPath)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    SuctionPath* path = &D_80235E00[evt_get_variable(script, *args++)];

    path->start.x = evt_get_variable(script, *args++);
    path->start.y = evt_get_variable(script, *args++);
    path->start.z = evt_get_variable(script, *args++);
    path->mid.x = -rand_int(20);
    path->mid.y = rand_int(40) + 60;
    path->mid.z = 0;
    path->end.x = evt_get_variable(script, *args++);
    path->end.y = evt_get_variable(script, *args++);
    path->end.z = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

ApiStatus func_80218774_5CEE04(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    f32 var2 = evt_get_float_variable(script, *args++);
    f32 var3 = evt_get_float_variable(script, *args++);
    f32 var4 = evt_get_float_variable(script, *args++);
    f32 var5 = evt_get_float_variable(script, *args++);
    f32 var6 = evt_get_float_variable(script, *args++);
    f32 var7 = evt_get_float_variable(script, *args++);
    s32 var8 = evt_get_variable(script, *args++);
    EffectInstance* effect = fx_huff_puff_breath(var1, var2, var3, var4, var5, var6, var7, var8);

    evt_set_variable(script, *args++, effect);
    return ApiStatus_DONE2;
}

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

ApiStatus func_80218924_5CEFB4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    f32 var4 = evt_get_float_variable(script, *args++);

    script->varTable[0] = fx_snaking_static(0, var1, var2, var3, var4 * 2.5f, 0);
    return ApiStatus_DONE2;
}

ApiStatus func_802189FC_5CF08C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = evt_get_variable(script, *args++);
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posY = evt_get_float_variable(script, *args++);
    f32 posZ = evt_get_float_variable(script, *args++);

    effect->data.snakingStatic->pos.x = posX;
    effect->data.snakingStatic->pos.y = posY;
    effect->data.snakingStatic->pos.z = posZ;
    return ApiStatus_DONE2;
}

ApiStatus func_80218AA0_5CF130(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* var1 = *args++;
    f32 var2 = evt_get_float_variable(script, *args++);
    f32 var3 = evt_get_float_variable(script, *args++);
    f32 var4 = evt_get_float_variable(script, *args++);
    f32 var5 = evt_get_float_variable(script, *args++);

    evt_set_float_variable(script, var1, atan2(var2, var3, var4, var5));
    return ApiStatus_DONE2;
}

ApiStatus func_80218B60_5CF1F0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 temp_s3 = evt_get_variable(script, *args++);
    f32 temp_f22 = evt_get_float_variable(script, *args++);
    f32 temp_f20 = evt_get_float_variable(script, *args++);
    s32 temp_s2 = evt_get_variable(script, *args++);
    s32 temp_s4 = evt_get_variable(script, *args++);

    evt_set_float_variable(script, *args++, update_lerp(temp_s3, temp_f22, temp_f20, temp_s2, temp_s4));
    return ApiStatus_DONE2;
}
