#include "common.h"

#define NAMESPACE battle_star_chill_out

extern s32 D_8029C890;
extern s32 D_802A2CC0;

#include "common/UnkStarFuncs.inc.c"

#include "common/FadeBackgroundToBlack.inc.c"

#include "common/UnkBackgroundFunc2.inc.c"

#include "common/UnkBackgroundFunc.inc.c"

INCLUDE_ASM(s32, "battle/star/chill_out/7900D0", func_802A1494_790564);

#include "common/SetNpcCollision32.inc.c"

ApiStatus func_802A1518_7905E8(ScriptInstance* script, s32 isInitialCall) {
    D_802A2CC0 = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_802A1528_7905F8(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = D_802A2CC0;
    return ApiStatus_DONE2;
}

ApiStatus func_802A153C_79060C(ScriptInstance* script, s32 isInitialCall) {
    f32 a = rand_int(200) - 25;
    f32 b = rand_int(120) + 7;
    f32 c = rand_int(50) - 25;

    playFX_6F(2, a, b, c, 2.0f, 20);

    a = rand_int(200) - 25;
    b = rand_int(120) + 7;
    c = rand_int(50) - 25;

    playFX_11(4, a, b, c, 40.0f);
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
        (part->eventFlags & 0x40000) || (part->eventFlags & flag2)) {
        return ApiStatus_DONE2;
    }

    script->varTable[0] = 1;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/star/chill_out/7900D0", func_802A16F4_7907C4);
