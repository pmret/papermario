#include "common.h"

#define NAMESPACE battle_star_chill_out

extern s32 D_802A2CC0;

ApiStatus func_802A1000_7900D0(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);

    func_8006FEF0(0, a, b, c, 40.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_802A10AC_79017C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);

    func_80070550(5, a, b, c, 50.0f, 50.0f, 40, 30);
    return ApiStatus_DONE2;
}

ApiStatus func_802A116C_79023C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);

    func_8006FEF0(0, a, b, c, 30.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_802A1218_7902E8(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);

    func_80072350(4, var1, var2, get_variable(script, *args++), 20.0f, 20.0f, 1.0f, 0xA, 0xF);
    return ApiStatus_DONE2;
}

#include "common/FadeBackgroundToBlack.inc.c"

ApiStatus func_802A137C_79044C(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        func_8011D82C(1);
        *D_801512F0 = 1;
        set_background_color_blend(0, 0, 0, 0);
        script->functionTemp[0].s = 0;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0].s);
    script->functionTemp[0].s += 10;

    if (script->functionTemp[0].s >= 230) {
        set_background_color_blend(0, 0, 0, 230);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_802A1414_7904E4(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0].s = 20;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0].s * 10);
    script->functionTemp[0].s -= 1;

    if (script->functionTemp[0].s == 0) {
        set_background_color_blend(0, 0, 0, 0);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "battle/star/chill_out_7900D0", func_802A1494_790564);

#include "common/SetNpcCollision32.inc.c"

ApiStatus func_802A1518_7905E8(ScriptInstance* script, s32 isInitialCall) {
    D_802A2CC0 = 0;
    return ApiStatus_DONE2;
}

s32 func_802A1528_7905F8(ActorPart* actorPart) {
    actorPart->unk_84 = D_802A2CC0;
    return 2;
}

ApiStatus func_802A153C_79060C(ScriptInstance* script, s32 isInitialCall) {
    f32 a = rand_int(200) - 25;
    f32 b = rand_int(120) + 7;
    f32 c = rand_int(50) - 25;

    func_80072230(2, a, b, c, 2.0f, 20);

    a = rand_int(200) - 25;
    b = rand_int(120) + 7;
    c = rand_int(50) - 25;

    func_8006FEF0(4, a, b, c, 40.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_802A163C_79070C(ScriptInstance* script, s32 isInitialCall) {
    Actor* actor = get_actor(script->owner1.actorID);
    Actor* target = get_actor(actor->targetActorID);
    ActorPart* part = get_actor_part(target, actor->targetPartIndex);
    s32 flag1 = 0x400000; // these manual flag ones are necessary to match. once we figure out flags, we can add more
    s32 flag2 = 0x80000;

    script->varTable[0] = 0;

    if ((target->flags & 0x4000) || (target->flags & flag1) || (target->flags & 0x2000) ||
        (part->eventFlags & 0x40000) || (part->eventFlags & flag2))
    {
        return ApiStatus_DONE2;
    }

    script->varTable[0] = 1;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/star/chill_out_7900D0", func_802A16F4_7907C4);
