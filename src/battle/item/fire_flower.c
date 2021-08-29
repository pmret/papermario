#include "fire_flower.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_716E9C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

    playFX_3F(0, a, b, c, 0);

    return ApiStatus_DONE2;
}

#include "common/FadeBackgroundToBlack.inc.c"

ApiStatus N(func_802A1378_716FD8)(Evt* script, s32 isInitialCall) {
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
    EVT_VAR(10) = (const) ITEM_FIRE_FLOWER;
    await N(UseItemWithEffect);
    N(FadeBackgroundToBlack)();
    PlaySound(SOUND_UNKNOWN_377);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_PLANT);
    spawn {
        sleep 50;
        SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    }
    sleep 35;
    UseBattleCamPreset(2);
    MoveBattleCamOver(20);
    sleep 10;
    GetActorPos(ACTOR_PLAYER, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5));
    EVT_VAR(0) = 40;
    MultiplyByActorScale(EVT_VAR(0));
    EVT_VAR(3) += EVT_VAR(0);
    spawn {
        GetActorPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        EVT_VAR(0) -= 10;
        SetActorSpeed(ACTOR_PLAYER, 2.0);
        SetAnimation(ACTOR_PLAYER, 0, ANIM_RUNNING);
        SetGoalPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        PlayerRunToGoal(ACTOR_PLAYER);
        SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    }
    spawn {
        N(func_802A123C_716E9C)(EVT_VAR(3), EVT_VAR(4), EVT_VAR(5));
        sleep 25;
        loop 12 {
            sleep 1;
            PlaySound(SOUND_UNKNOWN_202C);
            sleep 2;
            PlaySound(SOUND_UNKNOWN_202D);
            sleep 1;
        }
    }
    sleep 80;
    UseBattleCamPreset(3);
    MoveBattleCamOver(20);
    InitTargetIterator();
0:
    SetGoalToTarget(ACTOR_SELF);
    ItemCheckHit(EVT_VAR(0), 0x10000000, 0, EVT_VAR(0), 0);
    if (EVT_VAR(0) == 6) {
        goto 1;
    }
    GetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    GetItemPower(ITEM_FIRE_FLOWER, EVT_VAR(0), EVT_VAR(1));
    ItemDamageEnemy(EVT_VAR(0), 0x38000002, 0, EVT_VAR(0), 32);
1:
    sleep 5;
    ChooseNextTarget(0, EVT_VAR(0));
    if (EVT_VAR(0) != -1) {
        goto 0;
    }
    N(func_802A1378_716FD8)();
    sleep 30;
    await N(PlayerGoHome);
});
