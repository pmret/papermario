#include "dead.h"
#include "common.h"

#define NAMESPACE EC9D00

extern s32 D_800A15A8;
extern s32 D_80094900[]; // Probably a struct 0x10 big.
extern s8 D_80117160[];
extern u8 D_80117840[];
extern s8 D_80117852;
void func_80075E30(s32, f32, f32, f32, f32, s8);
s32 func_800769D0(s32, f32, f32, f32, f32, s8);
void func_800F2D5C(s32);
Entity* func_80118BB0(s32);
void func_80130C74(void*, s32);
void func_802F3B00(s32);

ApiStatus func_80240000_EC9D00(Evt* script, s32 isInitialCall) {
    D_800A15A8 |= 0x40;
    return ApiStatus_DONE2;
}

ApiStatus func_8024001C_EC9D1C(Evt* script, s32 isInitialCall) {
    D_800A15A8 &= ~0x40;
    return ApiStatus_DONE2;
}

ApiStatus func_8024003C_EC9D3C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    func_802F3B00(evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus func_80240068_EC9D68(Evt* script, s32 isInitialCall) {
    Bytecode args2;
    s8 temp_a2;
    u8* temp_v0;
    Bytecode* args = script->ptrReadPos;

    temp_v0 = &D_80117840[evt_get_variable(script, *args++) * 8];
    temp_a2 = temp_v0[0x15] + 1;
    args2 = *args++;
    temp_v0[0x15] = temp_a2;
    evt_set_variable(script, args2, temp_a2);
    return ApiStatus_DONE2;
}

s8 func_802400D4_EC9DD4(s32 arg0, s16 arg1) {
    s8 ret;
    u8* temp_a0;

    temp_a0 = &D_80117840[arg0 * 8];
    if (temp_a0[0x14] == 0 || (ret = temp_a0[0x15], ret > arg1 != 0)) {
        return -1;
    }
    return ret;
}

INCLUDE_ASM(s32, "EC9D00", func_80240120_EC9E20);

INCLUDE_ASM(s32, "EC9D00", func_802401CC_EC9ECC);

ApiStatus func_8024041C_ECA11C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    func_800F2D5C(evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus func_80240448_ECA148(Evt* script, s32 isInitialCall) {
    func_80130C74(D_80094900[D_80117852 * 0x4], 0);
    return ApiStatus_DONE2;
}

ApiStatus func_80240480_ECA180(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Entity* entity = func_80118BB0(evt_get_variable(script, *args++));
    Bytecode arg2 = *args++;

    evt_set_variable(script, arg2, func_800769D0(0, entity->position.x, entity->position.y + 12.5f, entity->position.z, 0.7f, 0));
    return ApiStatus_DONE2;
}

ApiStatus func_80240510_ECA210(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* tmp = (s32*)evt_get_variable(script, *args++);

    *tmp |= 0x10;
    return ApiStatus_DONE2;
}

ApiStatus func_80240544_ECA244(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Entity* entity = func_80118BB0(evt_get_variable(script, *args++));

    func_80075E30(4, entity->position.x, entity->position.y + 12.5f, entity->position.z, 1.0f, 0x4B);
    return ApiStatus_DONE2;
}

ApiStatus func_802405A8_ECA2A8(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_safe(-4);

    func_80075E30(9, npc->pos.x, npc->pos.y + 12.5f, npc->pos.z, 1.0f, 0x1E);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "EC9D00", func_80240600_ECA300);

INCLUDE_ASM(s32, "EC9D00", func_80240B38_ECA838);

#include "world/common/DeadUnkPartnerPosFuncs.inc.c"

ApiStatus func_80240D08_ECAA08(Evt* script, s32 isInitialCall) {
    script->varTable[0] = FALSE;
    if (D_80117160[0] != 0 && D_80117160[3] == 3) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}
