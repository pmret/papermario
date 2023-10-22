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
    EVT_EXEC_WAIT(N(EVS_StarPower_WishForSpirit))
    EVT_SET_CONST(LVar0, ANIM_BattleSkolar_Idle)
    EVT_EXEC_WAIT(N(EVS_StarPower_SpiritSummoned))
    EVT_CALL(SetNpcAnimation, NPC_BTL_SPIRIT, ANIM_BattleSkolar_Shout)
    EVT_WAIT(16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_CALL(PlaySound, SOUND_SHOOTING_STAR_FALL_A)
            EVT_CALL(N(SpawnShootingStarFX))
            EVT_WAIT(5)
            EVT_ADD(LVar0, 1)
            EVT_CALL(PlaySound, SOUND_SHOOTING_STAR_FALL_B)
            EVT_CALL(N(SpawnShootingStarFX))
            EVT_WAIT(5)
            EVT_ADD(LVar0, 1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_WAIT(50)
        EVT_LOOP(10)
            EVT_CALL(PlaySound, SOUND_STAR_BOUNCE_A)
            EVT_ADD(LVar0, 1)
            EVT_WAIT(5)
            EVT_CALL(PlaySound, SOUND_STAR_BOUNCE_B)
            EVT_ADD(LVar0, 1)
            EVT_WAIT(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(10)
            EVT_WAIT(7)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
            EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(90)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(ItemCheckHit, LVar0, 0, 0, 0, 0)
        EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(N(SpawnDamageStarsFX), LVar0, LVar1, LVar2)
        EVT_CALL(ItemDamageEnemy, LVar0, DAMAGE_TYPE_COSMIC | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 7, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_LABEL(1)
        EVT_WAIT(10)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_WAIT(20)
    EVT_EXEC_WAIT(N(EVS_StarPower_SpiritDeparts))
    EVT_CALL(PlayerYieldTurn)
    EVT_EXEC_WAIT(N(EVS_StarPower_EndWish))
    EVT_RETURN
    EVT_END
};
