#include "common.h"
#include "hud_element.h"

#define NAMESPACE battle_star_refresh

#include "common/StarPower.inc.c"

INCLUDE_ASM(s32, "battle/star/refresh/78B600", func_802A1518_78BB18);

ApiStatus func_802A17D4_78BDD4(Evt* script, s32 isInitialCall) {
    Actor* actor = gBattleStatus.playerActor;

    if (actor->debuff != STATUS_END) {
        actor->debuffDuration = 0;
        actor->debuff = 0;
        remove_status_debuff(actor->hudElementDataIndex);
    }

    if (actor->koStatus != 0) {
        actor->koDuration = 0;
        actor->koStatus = 0;
        actor->ptrDefuffIcon->ptrPropertyList[15] = 0;
    }

    btl_update_ko_status();
    return ApiStatus_DONE2;
}

#include "common/AddHP.inc.c"

#include "common/AddFP.inc.c"

ApiStatus func_802A18E8_78BEE8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);

    playFX_40(0, var1, var2, var3, var4);

    return ApiStatus_DONE2;
}

ApiStatus func_802A19A8_78BFA8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);

    playFX_40(1, var1, var2, var3, var4);

    return ApiStatus_DONE2;
}
