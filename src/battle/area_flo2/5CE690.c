#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_flo2

typedef struct Flo02Struct {
    /* 0x00 */ Vec3f actorPos;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ Vec3f enemyPos;
} Flo02Struct; // size = 0x24

typedef struct Flo02Struct3 {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ Vec3f pos;
} Flo02Struct3; // size = 0x10

typedef struct Flo02Struct2 {
    /* 0x00 */ char unk_00[12];
    /* 0x0C */ Flo02Struct3* unk_0C;
} Flo02Struct2; // size = 0x10

extern s32 D_8021A35C_5D09EC;
extern s32 D_8021A378_5D0A08;
extern Flo02Struct D_80235E00[];

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

ApiStatus func_80218620_5CECB0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Flo02Struct* temp_s1 = &D_80235E00[evt_get_variable(script, *args++)];

    temp_s1->actorPos.x = evt_get_variable(script, *args++);
    temp_s1->actorPos.y = evt_get_variable(script, *args++);
    temp_s1->actorPos.z = evt_get_variable(script, *args++);
    temp_s1->unk_0C = -rand_int(20);
    temp_s1->unk_10 = rand_int(40) + 60;
    temp_s1->unk_14 = 0;
    temp_s1->enemyPos.x = evt_get_variable(script, *args++);
    temp_s1->enemyPos.y = evt_get_variable(script, *args++);
    temp_s1->enemyPos.z = evt_get_variable(script, *args++);

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
    EffectInstance* effect = playFX_6E(var1, var2, var3, var4, var5, var6, var7, var8);

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

    script->varTable[0] = playFX_57(0, var1, var2, var3, var4 * 2.5f, 0);
    return ApiStatus_DONE2;
}

ApiStatus func_802189FC_5CF08C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Flo02Struct2* temp_s2 = evt_get_variable(script, *args++);
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posY = evt_get_float_variable(script, *args++);
    f32 posZ = evt_get_float_variable(script, *args++);

    temp_s2->unk_0C->pos.x = posX;
    temp_s2->unk_0C->pos.y = posY;
    temp_s2->unk_0C->pos.z = posZ;
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
