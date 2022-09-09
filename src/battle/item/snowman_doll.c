#include "snowman_doll.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_71C06C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

    fx_sparkles(FX_SPARKLES_2, a, b, c, 30.0f);
    fx_sparkles(FX_SPARKLES_2, a, b, c, 30.0f);

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

EvtScript N(main) = {
    EVT_SET_CONST(LocalVar(10), 0x00000081)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_363)
    EVT_THREAD
        EVT_LOOP(45)
            EVT_CALL(RandInt, 300, LocalVar(0))
            EVT_SUB(LocalVar(0), 150)
            EVT_SET(LocalVar(1), 170)
            EVT_CALL(RandInt, 50, LocalVar(2))
            EVT_SUB(LocalVar(2), 25)
            EVT_CALL(PlayEffect, 0xE, LocalVar(0), LocalVar(1), LocalVar(2), 60, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 50)
    EVT_WAIT(50)
    EVT_CALL(PlayEffect, 0x60, 0, 0, 0, 20, EVT_FLOAT(1.0), 160, 0, 0, 0, 0, 0, 0, 0)
    EVT_THREAD
        EVT_WAIT(17)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_202E)
        EVT_CALL(StartRumble, 9)
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_WAIT(46)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_202E)
        EVT_CALL(StartRumble, 9)
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_WAIT(25)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_202E)
        EVT_CALL(StartRumble, 9)
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_WAIT(25)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_202E)
        EVT_CALL(StartRumble, 9)
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(StartRumble, 10)
    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
    EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(2.0))
    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
    EVT_WAIT(110)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, LocalVar(0), 268435456, 0, LocalVar(0), 0)
    EVT_IF_EQ(LocalVar(0), 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(N(func_802A123C_71C06C), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(GetItemPower, ITEM_SNOWMAN_DOLL, LocalVar(0), LocalVar(1))
    EVT_CALL(ItemDamageEnemy, LocalVar(0), 939524104, 0, LocalVar(0), 32)
    EVT_WAIT(5)
    EVT_LABEL(1)
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_WAIT(30)
    EVT_CALL(N(func_802A13B8_71C1E8))
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
