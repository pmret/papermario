#include "end_00.h"

typedef struct End18 {
    /* 0x00 */ s32 initialAnim;
    /* 0x04 */ s32** animList;
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ f32 yaw;
} End18; // size = 0x18

extern s32 spr_allocateBtlComponentsOnWorldHeap;
extern End18 D_80244D74_DFB774[];

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80240020_DF6A20);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80240270_DF6C70);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80240540_DF6F40);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_8024081C_DF721C);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80240AE8_DF74E8);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80240EB0_DF78B0);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80240FEC_DF79EC);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_802411CC_DF7BCC);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80241294_DF7C94);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_802414CC_DF7ECC);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80241768_DF8168);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_802419F8_DF83F8);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80241B34_DF8534);

static char* N(exit_str_0) = "end_01";

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_802421D8_DF8BD8);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80242358_DF8D58);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80242500_DF8F00);

ApiStatus func_80242558_DF8F58(Evt* script, s32 isInitialCall) {
    func_80242500_DF8F00();
    load_font(1);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80242580_DF8F80);

ApiStatus func_80242680_DF9080(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    End18* end18 = &D_80244D74_DFB774[npcID];
    NpcBlueprint bp;
    Npc* npc;

    bp.flags = 0x100;
    bp.initialAnim = end18->initialAnim;
    bp.onUpdate = NULL;
    bp.onRender = NULL;

    spr_allocateBtlComponentsOnWorldHeap = 1;

    npc = get_npc_by_index(_create_npc_standard(&bp, end18->animList));
    npc->npcID = npcID;
    npc->flags &= ~NPC_FLAG_PARTICLE;
    npc->pos.x = end18->pos.x;
    npc->pos.y = end18->pos.y;
    npc->pos.z = end18->pos.z;
    set_npc_yaw(npc, end18->yaw);
    return ApiStatus_DONE2;
}

ApiStatus func_80242744_DF9144(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 a1 = *args++;

    evt_set_variable(script, a1, _heap_malloc(&gSpriteHeapPtr, var1));
    return ApiStatus_DONE2;
}

ApiStatus func_802427A4_DF91A4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    _heap_free(&gSpriteHeapPtr, evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus func_802427D8_DF91D8(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    camera->unk_506 = 1;
    camera->movePos.x += 0.6666667f;
    return ApiStatus_DONE2;
}

ApiStatus N(SetNpcShadowScale)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    f32 newShadowScale = evt_get_float_variable(script, *args++);

    resolve_npc(script, npcID)->shadowScale = newShadowScale;
    return ApiStatus_DONE2;
}

ApiStatus func_80242898_DF9298(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc** npc = (Npc**)&script->functionTemp[1];

    if (isInitialCall) {
        *npc = get_npc_unsafe(evt_get_variable(script, *args++));
    }

    (*npc)->pos.x += 0.6666667f;

    return ApiStatus_BLOCK;
}
