#include "common.h"

#define NAMESPACE battle_star_refresh

#include "common/UnkStarFuncs.inc.c"

#include "common/FadeBackgroundToBlack.inc.c"

#include "common/UnkBackgroundFunc2.inc.c"

#include "common/UnkBackgroundFunc.inc.c"

INCLUDE_ASM(s32, "battle/star/refresh_78B600", func_802A1494_78BA94);

#include "common/SetNpcCollision32.inc.c"

INCLUDE_ASM(s32, "battle/star/refresh_78B600", func_802A1518_78BB18);

ApiStatus func_802A17D4_78BDD4(ScriptInstance* script, s32 isInitialCall) {
    Actor* actor = gBattleStatus.playerActor;

    if (actor->debuff != Debuff_END) {
        actor->debuffDuration = 0;
        actor->debuff = 0;
        func_80047898(actor->unk_436);
    }

    if (actor->koStatus != 0) {
        actor->koDuration = 0;
        actor->koStatus = 0;
        actor->ptrDefuffIcon->ptrPropertyList[15] = 0;
    }

    func_8026777C();
    return ApiStatus_DONE2;
}

#include "common/AddHP.inc.c"

#include "common/AddFP.inc.c"

INCLUDE_ASM(s32, "battle/star/refresh_78B600", func_802A18E8_78BEE8);

INCLUDE_ASM(s32, "battle/star/refresh_78B600", func_802A19A8_78BFA8);
