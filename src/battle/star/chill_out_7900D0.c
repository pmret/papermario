#include "common.h"

extern s32 D_802A2CC0;

INCLUDE_ASM(s32, "battle/star/chill_out_7900D0", func_802A1000_7900D0);

INCLUDE_ASM(s32, "battle/star/chill_out_7900D0", func_802A10AC_79017C);

INCLUDE_ASM(s32, "battle/star/chill_out_7900D0", func_802A116C_79023C);

INCLUDE_ASM(s32, "battle/star/chill_out_7900D0", func_802A1218_7902E8);

#define NAMESPACE battle_star_chill_out
#include "common/FadeBackgroundToBlack.inc.c"

INCLUDE_ASM(s32, "battle/star/chill_out_7900D0", func_802A137C_79044C);

INCLUDE_ASM(s32, "battle/star/chill_out_7900D0", func_802A1414_7904E4);

INCLUDE_ASM(s32, "battle/star/chill_out_7900D0", func_802A1494_790564);

ApiStatus func_802A14E8_7905B8(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(100);

    npc->collisionHeight = 32;
    npc->collisionRadius = 32;
    return ApiStatus_DONE2;
}

ApiStatus func_802A1518_7905E8(ScriptInstance* script, s32 isInitialCall) {
    D_802A2CC0 = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_802A1528_7905F8(ActorPart* actorPart, ScriptInstance* script, s32 isInitialCall) {
    actorPart->unk_84 = D_802A2CC0;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/star/chill_out_7900D0", func_802A153C_79060C);

INCLUDE_ASM(s32, "battle/star/chill_out_7900D0", func_802A163C_79070C);

INCLUDE_ASM(s32, "battle/star/chill_out_7900D0", func_802A16F4_7907C4);
