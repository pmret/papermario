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
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);

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

EvtSource N(main) = SCRIPT({
    SI_VAR(10) = (const) ITEM_SHOOTING_STAR;
    await N(UseItemWithEffect);
    spawn {
        sleep 5;
        UseBattleCamPreset(2);
        MoveBattleCamOver(20);
    }
    N(func_802A1444_71DBB4)();
    spawn {
        SI_VAR(0) = 0;
        loop 10 {
            PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_259);
            N(func_802A123C_71D9AC)();
            SI_VAR(0) += 1;
            sleep 5;
            PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_25A);
            N(func_802A123C_71D9AC)();
            SI_VAR(0) += 1;
            sleep 5;
        }
    }
    spawn {
        SI_VAR(0) = 0;
        sleep 50;
        loop 10 {
            PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_25C);
            SI_VAR(0) += 1;
            sleep 5;
            PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_25D);
            SI_VAR(0) += 1;
            sleep 5;
        }
    }
    spawn {
        loop 5 {
            sleep 15;
            StartRumble(8);
            ShakeCam(1, 0, 5, 1.0);
        }
    }
    sleep 90;
    UseBattleCamPreset(3);
    MoveBattleCamOver(20);
    InitTargetIterator();
0:
    SetGoalToTarget(ACTOR_SELF);
    ItemCheckHit(SI_VAR(0), 0x10000000, 0, SI_VAR(0), 0);
    if (SI_VAR(0) == 6) {
        goto 1;
    }
    GetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    N(func_802A1388_71DAF8)(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    GetItemPower(ITEM_SHOOTING_STAR, SI_VAR(0), SI_VAR(1));
    ItemDamageEnemy(SI_VAR(0), 0x38000100, 0, SI_VAR(0), 32);
1:
    sleep 10;
    ChooseNextTarget(0, SI_VAR(0));
    if (SI_VAR(0) != -1) {
        goto 0;
    }
    sleep 20;
    UseBattleCamPreset(2);
    MoveBattleCamOver(20);
    await N(PlayerGoHome);
    spawn {
        N(func_802A14D4_71DC44)();
    }
    sleep 30;
});
