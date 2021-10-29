#include "common.h"
#include "effects.h"

typedef struct Effect6FData {
    /* 0x00 */ EffectInstanceDataThing* unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3i rotation;
    /* 0x1C */ Vec3i scale;
    /* 0x28 */ Vec3i color;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ char unk_40[0x4];
} Effect6FData; // size = 0x4

typedef struct Effect6FInstance {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 effectIndex;
    /* 0x08 */ s32 numParts;
    /* 0x0C */ Effect6FData* data;
    /* 0x10 */ struct EffectGraphics* effect;
} Effect6FInstance;

#define NAMESPACE b_area_jan2

#define NAMESPACE dup_b_area_jan2
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_jan2

ApiStatus func_802180CC_584A0C(Evt* script, s32 isInitialCall) {
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
