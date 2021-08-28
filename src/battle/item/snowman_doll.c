#include "snowman_doll.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_71C06C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);

    playFX_11(2, a, b, c, 30.0f);
    playFX_11(2, a, b, c, 30.0f);

    return ApiStatus_DONE2;
}

#include "common/FadeBackgroundToBlack.inc.c"

ApiStatus N(func_802A13B8_71C1E8)(Evt* script, s32 isInitialCall) {
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
    EVT_VAR(10) = (const) ITEM_SNOWMAN_DOLL;
    await N(UseItemWithEffect);
    N(FadeBackgroundToBlack)();
    PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_363);
    spawn {
        loop 45 {
            RandInt(300, EVT_VAR(0));
            EVT_VAR(0) -= 150;
            EVT_VAR(1) = 170;
            RandInt(50, EVT_VAR(2));
            EVT_VAR(2) -= 25;
            PlayEffect(0xE, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 60, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            sleep 2;
        }
    }
    sleep 10;
    UseBattleCamPreset(3);
    MoveBattleCamOver(50);
    sleep 50;
    PlayEffect(0x60, 0, 0, 0, 20, 1.0, 160, 0, 0, 0, 0, 0, 0, 0);
    spawn {
        sleep 17;
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_202E);
        StartRumble(9);
        ShakeCam(1, 0, 5, 1.0);
        sleep 46;
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_202E);
        StartRumble(9);
        ShakeCam(1, 0, 5, 1.0);
        sleep 25;
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_202E);
        StartRumble(9);
        ShakeCam(1, 0, 5, 1.0);
        sleep 25;
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_202E);
        StartRumble(9);
        ShakeCam(1, 0, 5, 1.0);
    }
    sleep 15;
    StartRumble(10);
    ShakeCam(1, 0, 5, 1.0);
    ShakeCam(1, 0, 10, 2.0);
    ShakeCam(1, 0, 5, 1.0);
    sleep 110;
    InitTargetIterator();
0:
    SetGoalToTarget(ACTOR_SELF);
    ItemCheckHit(EVT_VAR(0), 0x10000000, 0, EVT_VAR(0), 0);
    if (EVT_VAR(0) == 6) {
        goto 1;
    }
    GetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    N(func_802A123C_71C06C)(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    GetItemPower(ITEM_SNOWMAN_DOLL, EVT_VAR(0), EVT_VAR(1));
    ItemDamageEnemy(EVT_VAR(0), 0x38000008, 0, EVT_VAR(0), 32);
    sleep 5;
1:
    ChooseNextTarget(0, EVT_VAR(0));
    if (EVT_VAR(0) != -1) {
        goto 0;
    }
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    sleep 30;
    N(func_802A13B8_71C1E8)();
    await N(PlayerGoHome);
});
