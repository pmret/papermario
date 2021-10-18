#include "shooting_star.h"
#include "effects.h"

#include "ItemRefund.inc.c"

#ifdef NON_MATCHING
ApiStatus N(func_802A123C_71D9AC)(Evt* script, s32 isInitialCall) {
    s32 c8 = 200;
    s32 temp_s1 = 100 + rand_int(c8);
    s32 temp_s0 = rand_int(40);
    s32 phi_a0;
    s32 phi_v0;
    s32 rand;
    f32 temp_f20;
    f32 temp_f22;
    f32 test;

    if (script->varTable[0] & 3) {
        rand = rand_int(100);
        rand += c8;
        temp_f22 = temp_s1 - rand;
        rand = rand_int(100);
        rand -= 50;
        temp_f20 = temp_s0 - rand;
        phi_v0 = rand_int(10);
        phi_a0 = 2;
    } else {
        rand = rand_int(100);
        rand += 200;
        temp_f22 = temp_s1 - rand;
        rand = rand_int(100);
        rand -= 50;
        temp_f20 = temp_s0 - rand;
        phi_v0 = rand_int(10);
        phi_a0 = 3;
    }

    do {
        playFX_0F(phi_a0, temp_s1, c8, temp_s0, temp_f22, 0, temp_f20, phi_v0 + 7);
        if (temp_f20) {
            temp_f20 -= rand;
        }
    } while (0);

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(ApiStatus, "battle/item/shooting_star", battle_item_shooting_star_func_802A123C_71D9AC,
            Evt* script, s32 isInitialCall);
#endif

ApiStatus N(func_802A1388_71DAF8)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

    playFX_18(2, a, b, c, 0, -1.0f, 0, 5);

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

EvtSource N(main) = {
    EVT_SET_CONST(EVT_VAR(10), 0x00000083)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(UseBattleCamPreset, 2)
        EVT_CALL(MoveBattleCamOver, 20)
    EVT_END_THREAD
    EVT_CALL(N(func_802A1444_71DBB4))
    EVT_THREAD
        EVT_SET(EVT_VAR(0), 0)
        EVT_LOOP(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_UNKNOWN_259)
            EVT_CALL(N(func_802A123C_71D9AC))
            EVT_ADD(EVT_VAR(0), 1)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_UNKNOWN_25A)
            EVT_CALL(N(func_802A123C_71D9AC))
            EVT_ADD(EVT_VAR(0), 1)
            EVT_WAIT_FRAMES(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(EVT_VAR(0), 0)
        EVT_WAIT_FRAMES(50)
        EVT_LOOP(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_UNKNOWN_25C)
            EVT_ADD(EVT_VAR(0), 1)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_UNKNOWN_25D)
            EVT_ADD(EVT_VAR(0), 1)
            EVT_WAIT_FRAMES(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(5)
            EVT_WAIT_FRAMES(15)
            EVT_CALL(StartRumble, 8)
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FIXED(1.0))
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(90)
    EVT_CALL(UseBattleCamPreset, 3)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, EVT_VAR(0), 268435456, 0, EVT_VAR(0), 0)
    EVT_IF_EQ(EVT_VAR(0), 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(N(func_802A1388_71DAF8), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetItemPower, ITEM_SHOOTING_STAR, EVT_VAR(0), EVT_VAR(1))
    EVT_CALL(ItemDamageEnemy, EVT_VAR(0), 939524352, 0, EVT_VAR(0), 32)
    EVT_LABEL(1)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(ChooseNextTarget, 0, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT_FRAMES(20)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_THREAD
        EVT_CALL(N(func_802A14D4_71DC44))
    EVT_END_THREAD
    EVT_WAIT_FRAMES(30)
    EVT_RETURN
    EVT_END
};
