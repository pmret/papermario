#include "common.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleSkolar.h"

#define NAMESPACE battle_move_star_storm

#include "battle/common/move/StarPowerSupport.inc.c"

API_CALLABLE(N(SpawnShootingStarFX)) {
    s32 x = -50 - rand_int(200);
    s32 y = 200;
    s32 z = rand_int(40);

    if (script->varTable[0] % 4 != 0) {
        fx_star(FX_STAR_LARGE_BOUNCING, x, y, z, x + (rand_int(50) + y), 0, z, rand_int(10) + 7);
    } else {
        fx_star(FX_STAR_SMALL_BOUNCING, x, y, z, x + (rand_int(50) + y), 0, z, rand_int(10) + 7);
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

EvtScript N(EVS_UsePower) = {
    ExecWait(N(EVS_StarPower_WishForSpirit))
    SetConst(LVar0, ANIM_BattleSkolar_Idle)
    ExecWait(N(EVS_StarPower_SpiritSummoned))
    Call(SetNpcAnimation, NPC_BTL_SPIRIT, ANIM_BattleSkolar_Shout)
    Wait(16)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Thread
        Set(LVar0, 0)
        Loop(10)
            Call(PlaySound, SOUND_SHOOTING_STAR_FALL_A)
            Call(N(SpawnShootingStarFX))
            Wait(5)
            Add(LVar0, 1)
            Call(PlaySound, SOUND_SHOOTING_STAR_FALL_B)
            Call(N(SpawnShootingStarFX))
            Wait(5)
            Add(LVar0, 1)
        EndLoop
    EndThread
    Thread
        Set(LVar0, 0)
        Wait(50)
        Loop(10)
            Call(PlaySound, SOUND_STAR_BOUNCE_A)
            Add(LVar0, 1)
            Wait(5)
            Call(PlaySound, SOUND_STAR_BOUNCE_B)
            Add(LVar0, 1)
            Wait(5)
        EndLoop
    EndThread
    Thread
        Loop(10)
            Wait(7)
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
            Call(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
        EndLoop
    EndThread
    Wait(90)
    Call(InitTargetIterator)
    Label(0)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(ItemCheckHit, LVar0, 0, 0, 0, 0)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(1)
        EndIf
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(N(SpawnDamageStarsFX), LVar0, LVar1, LVar2)
        Call(ItemDamageEnemy, LVar0, DAMAGE_TYPE_COSMIC | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 7, BS_FLAGS1_TRIGGER_EVENTS)
        Label(1)
        Wait(10)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Wait(20)
    ExecWait(N(EVS_StarPower_SpiritDeparts))
    Call(PlayerYieldTurn)
    ExecWait(N(EVS_StarPower_EndWish))
    Return
    End
};
