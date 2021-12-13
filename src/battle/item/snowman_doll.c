#include "snowman_doll.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_71C06C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

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

EvtSource N(main) = {
    EVT_SET_CONST(EVT_VAR(10), 0x00000081)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_363)
    EVT_THREAD
        EVT_LOOP(45)
            EVT_CALL(RandInt, 300, EVT_VAR(0))
            EVT_SUB(EVT_VAR(0), 150)
            EVT_SET(EVT_VAR(1), 170)
            EVT_CALL(RandInt, 50, EVT_VAR(2))
            EVT_SUB(EVT_VAR(2), 25)
            EVT_CALL(PlayEffect, 0xE, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 60, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(10)
    EVT_CALL(UseBattleCamPreset, 3)
    EVT_CALL(MoveBattleCamOver, 50)
    EVT_WAIT_FRAMES(50)
    EVT_CALL(PlayEffect, 0x60, 0, 0, 0, 20, EVT_FIXED(1.0), 160, 0, 0, 0, 0, 0, 0, 0)
    EVT_THREAD
        EVT_WAIT_FRAMES(17)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_202E)
        EVT_CALL(StartRumble, 9)
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(46)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_202E)
        EVT_CALL(StartRumble, 9)
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(25)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_202E)
        EVT_CALL(StartRumble, 9)
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(25)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_202E)
        EVT_CALL(StartRumble, 9)
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FIXED(1.0))
    EVT_END_THREAD
    EVT_WAIT_FRAMES(15)
    EVT_CALL(StartRumble, 10)
    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FIXED(1.0))
    EVT_CALL(ShakeCam, 1, 0, 10, EVT_FIXED(2.0))
    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FIXED(1.0))
    EVT_WAIT_FRAMES(110)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, EVT_VAR(0), 268435456, 0, EVT_VAR(0), 0)
    EVT_IF_EQ(EVT_VAR(0), 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(N(func_802A123C_71C06C), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetItemPower, ITEM_SNOWMAN_DOLL, EVT_VAR(0), EVT_VAR(1))
    EVT_CALL(ItemDamageEnemy, EVT_VAR(0), 939524104, 0, EVT_VAR(0), 32)
    EVT_WAIT_FRAMES(5)
    EVT_LABEL(1)
    EVT_CALL(ChooseNextTarget, 0, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(N(func_802A13B8_71C1E8))
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
