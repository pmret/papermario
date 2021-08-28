#include "stop_watch.h"

#include "ItemRefund.inc.c"

#include "common/FadeBackgroundToBlack.inc.c"

ApiStatus N(func_802A12D4_7270A4)(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 20;
    }

    set_background_color_blend(0, 0, 0, (script->functionTemp[0] * 10) & 254);

    script->functionTemp[0]--;
    if (script->functionTemp[0] == 0) {
        set_background_color_blend(0, 0, 0, 0);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

#include "UseItem.inc.c"

EvtSource N(main) = SCRIPT({
    EVT_VAR(10) = (const) ITEM_STOP_WATCH;
    await N(UseItemWithEffect);
    spawn {
        sleep 5;
        UseBattleCamPreset(2);
        MoveBattleCamOver(20);
    }
    N(FadeBackgroundToBlack)();
    PlayEffect(0x62, 0, 0, 0, 0, 1.0, 200, 0, 0, 0, 0, 0, 0, 0);
    PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_246);
    sleep 200;
    UseBattleCamPreset(3);
    MoveBattleCamOver(20);
    InitTargetIterator();
0:
    SetGoalToTarget(ACTOR_SELF);
    ItemCheckHit(EVT_VAR(0), 0x10000000, 0, EVT_VAR(0), 0);
    if (EVT_VAR(0) == 6) {
        goto 1;
    }
    GetItemPower(ITEM_STOP_WATCH, EVT_VAR(0), EVT_VAR(1));
    MakeStatusField(EVT_VAR(0), 0x200000, 100, EVT_VAR(0));
    func_80252B3C(EVT_VAR(0), 0x50000000, EVT_VAR(0), 0, 32);
1:
    sleep 5;
    ChooseNextTarget(0, EVT_VAR(0));
    if (EVT_VAR(0) != -1) {
        goto 0;
    }
    N(func_802A12D4_7270A4)();
    await N(PlayerGoHome);
});
