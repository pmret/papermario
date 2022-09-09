#include "shooting_star.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus battle_item_shooting_star_func_802A123C_71D9AC(Evt* script, s32 isInitialCall) {
    s32 t1 = 200;
    s32 r1 = rand_int(t1) + 100; // 100-299
    s32 r2 = rand_int(40); // 0-39
    f32 var_f22;

    if ((script->varTable[0] % 4) != 0) {
        var_f22 = r1 - (rand_int(100) + t1);
        fx_star(2, r1, t1, r2, var_f22, 0.0f, r2 + 50 - rand_int(100), rand_int(10) + 7);
    } else {
        var_f22 = r1 - (rand_int(100) + t1);
        fx_star(3, r1, t1, r2, var_f22, 0.0f, r2 + 50 - rand_int(100), rand_int(10) + 7);
    }
    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1388_71DAF8)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

    fx_damage_stars(2, a, b, c, 0, -1.0f, 0, 5);

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1444_71DBB4)(Evt* script, s32 isInitialCall) {
    s32 ret;

    if (isInitialCall) {
        mdl_set_all_fog_mode(1);
        *D_801512F0 = 1;
        set_background_color_blend(0, 0, 0, 0);
        script->functionTemp[0] = 10;
    }

    set_background_color_blend(0, 0, 0, ((10 - script->functionTemp[0]) * 16) & 240);
    script->functionTemp[0]--;
    do {} while (0);
    return (script->functionTemp[0] == 0) * ApiStatus_DONE2;
}

ApiStatus N(func_802A14D4_71DC44)(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 10;
    }
    set_background_color_blend(0, 0, 0, (script->functionTemp[0] * 16) & 240);
    script->functionTemp[0]--;
    if (script->functionTemp[0] == 0) {
        set_background_color_blend(0, 0, 0, 0);

        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

#include "UseItem.inc.c"

EvtScript N(main) = {
    EVT_SET_CONST(LocalVar(10), 0x00000083)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 20)
    EVT_END_THREAD
    EVT_CALL(N(func_802A1444_71DBB4))
    EVT_THREAD
        EVT_SET(LocalVar(0), 0)
        EVT_LOOP(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_259)
            EVT_CALL(N(func_802A123C_71D9AC))
            EVT_ADD(LocalVar(0), 1)
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_25A)
            EVT_CALL(N(func_802A123C_71D9AC))
            EVT_ADD(LocalVar(0), 1)
            EVT_WAIT(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LocalVar(0), 0)
        EVT_WAIT(50)
        EVT_LOOP(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_25C)
            EVT_ADD(LocalVar(0), 1)
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_25D)
            EVT_ADD(LocalVar(0), 1)
            EVT_WAIT(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(5)
            EVT_WAIT(15)
            EVT_CALL(StartRumble, 8)
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(90)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, LocalVar(0), 268435456, 0, LocalVar(0), 0)
    EVT_IF_EQ(LocalVar(0), 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(N(func_802A1388_71DAF8), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(GetItemPower, ITEM_SHOOTING_STAR, LocalVar(0), LocalVar(1))
    EVT_CALL(ItemDamageEnemy, LocalVar(0), 939524352, 0, LocalVar(0), 32)
    EVT_LABEL(1)
    EVT_WAIT(10)
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_THREAD
        EVT_CALL(N(func_802A14D4_71DC44))
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};
