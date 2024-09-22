#include "common.h"
#include "script_api/battle.h"

#include "effects.h"
#include "model.h"

#define NAMESPACE battle_item_shooting_star

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(SpawnShootingStarFX)) {
    s32 x = rand_int(200) + 100;
    s32 y = 200;
    s32 z = rand_int(40);

    if ((script->varTable[0] % 4) != 0) {
        fx_star(FX_STAR_LARGE_BOUNCING, x, y, z,
            x - (rand_int(100) + y),
            0.0f,
            z + 50 - rand_int(100),
            rand_int(10) + 7);
    } else {
        fx_star(FX_STAR_SMALL_BOUNCING, x, y, z,
            x - (rand_int(100) + y),
            0.0f,
            z + 50 - rand_int(100),
            rand_int(10) + 7);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpawnDamageStarsFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    fx_damage_stars(FX_DAMAGE_STARS_2, x, y, z, 0, -1.0f, 0, 5);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(CustomFadeBackgroundDarken)) {
    if (isInitialCall) {
        mdl_set_all_tint_type(ENV_TINT_SHROUD);
        *gBackgroundTintModePtr = ENV_TINT_SHROUD;
        mdl_set_shroud_tint_params(0, 0, 0, 0);
        script->functionTemp[0] = 10;
    }

    mdl_set_shroud_tint_params(0, 0, 0, ((10 - script->functionTemp[0]) * 16) & 240);
    script->functionTemp[0]--;

    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(CustomFadeBackgroundLighten)) {
    if (isInitialCall) {
        script->functionTemp[0] = 10;
    }
    mdl_set_shroud_tint_params(0, 0, 0, (script->functionTemp[0] * 16) & 240);

    script->functionTemp[0]--;
    if (script->functionTemp[0] == 0) {
        mdl_set_shroud_tint_params(0, 0, 0, 0);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    SetConst(LVarA, ITEM_SHOOTING_STAR)
    ExecWait(N(UseItemWithEffect))
    Thread
        Wait(5)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 20)
    EndThread
    Call(N(CustomFadeBackgroundDarken))
    Thread
        Set(LVar0, 0)
        Loop(10)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SHOOTING_STAR_FALL_A)
            Call(N(SpawnShootingStarFX))
            Add(LVar0, 1)
            Wait(5)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SHOOTING_STAR_FALL_B)
            Call(N(SpawnShootingStarFX))
            Add(LVar0, 1)
            Wait(5)
        EndLoop
    EndThread
    Thread
        Set(LVar0, 0)
        Wait(50)
        Loop(10)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_STAR_BOUNCE_A)
            Add(LVar0, 1)
            Wait(5)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_STAR_BOUNCE_B)
            Add(LVar0, 1)
            Wait(5)
        EndLoop
    EndThread
    Thread
        Loop(5)
            Wait(15)
            Call(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
        EndLoop
    EndThread
    Wait(90)
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(MoveBattleCamOver, 20)
    Call(InitTargetIterator)
    Label(0)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(ItemCheckHit, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, LVar0, 0)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(1)
        EndIf
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(N(SpawnDamageStarsFX), LVar0, LVar1, LVar2)
        Call(GetItemPower, ITEM_SHOOTING_STAR, LVar0, LVar1)
        Call(ItemDamageEnemy, LVar0, DAMAGE_TYPE_COSMIC | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
        Label(1)
        Wait(10)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Wait(20)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    ExecWait(N(PlayerGoHome))
    Thread
        Call(N(CustomFadeBackgroundLighten))
    EndThread
    Wait(30)
    Return
    End
};
