#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleKalmar.h"
#include "entity.h"
#include "model.h"
#include "sprite/player.h"

extern EntityModelScript EMS_StarIcon;

#define NAMESPACE battle_move_up_and_away

#include "battle/common/move/StarPowerSupport.inc.c"

API_CALLABLE(N(DarkenBackground)) {
    if (isInitialCall) {
        mdl_set_all_tint_type(ENV_TINT_SHROUD);
        *gBackgroundTintModePtr = ENV_TINT_SHROUD;
        mdl_set_shroud_tint_params(0, 0, 0, 0);
        script->functionTemp[0] = 200;
    }

    mdl_set_shroud_tint_params(0, 0, 0, script->functionTemp[0]);
    script->functionTemp[0] += 2;

    if (script->functionTemp[0] >= 254) {
        mdl_set_shroud_tint_params(0, 0, 0, 254);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(RestoreBackground)) {
    if (isInitialCall) {
        script->functionTemp[0] = 254;
    }

    mdl_set_shroud_tint_params(0, 0, 0, script->functionTemp[0]);
    script->functionTemp[0] -= 5;

    if (script->functionTemp[0] <= 200) {
        mdl_set_shroud_tint_params(0, 0, 0, 200);

        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(ShouldTargetBeCaptured)) {
    Actor* targetActor = get_actor(get_actor(script->owner1.actorID)->targetActorID);

    script->varTable[0] = FALSE;

    if (targetActor->flags & ACTOR_FLAG_TARGET_ONLY) {
        return ApiStatus_DONE2;
    }

    if (targetActor->flags & ACTOR_FLAG_NO_DMG_APPLY) {
        return ApiStatus_DONE2;
    }

    if (targetActor->flags & ACTOR_FLAG_DAMAGE_IMMUNE) {
        return ApiStatus_DONE2;
    }

    if (targetActor->actorBlueprint->upAndAwayChance != 0
        && rand_int(100) <= targetActor->actorBlueprint->upAndAwayChance
    ) {
        script->varTable[0] = TRUE;
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_UsePower) = {
    EVT_EXEC_WAIT(N(EVS_StarPower_WishForSpirit))
    EVT_SET_CONST(LVar0, ANIM_BattleKalmar_Idle)
    EVT_EXEC_WAIT(N(EVS_StarPower_SpiritSummoned))
    EVT_CALL(SetNpcAnimation, NPC_BTL_SPIRIT, ANIM_BattleKalmar_Shout)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(20)
    EVT_CALL(SetMotionBlurParams, 0, 0, 0, 320, 240, 128, 10)
    EVT_CALL(N(DarkenBackground))
    EVT_CALL(PlaySound, SOUND_UP_AND_AWAY_CAST)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_SHOCKWAVE, 0, 0, 20, 0, EVT_FLOAT(1.0), 90)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_PLAY_EFFECT(EFFECT_SHIMMER_WAVE, 0, 0, 50, 0, 300, 100, 10, 40)
    EVT_END_THREAD
    EVT_PLAY_EFFECT(EFFECT_ENERGY_SHOCKWAVE, 0, 0, 20, 0, EVT_FLOAT(1.0), 90)
    EVT_WAIT(75)
    EVT_CALL(SetMotionBlurParams, 0, 0, 0, 320, 240, 0, 10)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(N(ShouldTargetBeCaptured))
        EVT_SET(LFlag0, FALSE)
        EVT_CALL(ItemCheckHit, LVar1, 0, 0, 0, 0)
        EVT_IF_EQ(LVar1, HIT_RESULT_MISS)
            EVT_SET(LVar0, 0)
            EVT_SET(LFlag0, TRUE)
        EVT_END_IF
        EVT_SWITCH(LVar0)
            EVT_CASE_GT(0)
                EVT_CALL(GetOwnerTarget, LVar0, LVar1)
                EVT_CALL(DispatchEvent, LVar0, EVENT_UP_AND_AWAY)
                EVT_CALL(SetActorRotationOffset, LVar0, 0, 10, 0)
                EVT_THREAD
                    EVT_CALL(GetOwnerTarget, LVarB, LVar1)
                    EVT_WAIT(10)
                    EVT_CALL(CreateVirtualEntity, LVarA, EVT_PTR(EMS_StarIcon))
                    EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
                    EVT_SET(LVarD, LVar0)
                    EVT_SET(LVarE, LVar1)
                    EVT_SET(LVarF, LVar2)
                    EVT_CALL(SetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
                    EVT_SETF(LVar0, EVT_FLOAT(0.2))
                    EVT_CALL(SetVirtualEntityScale, LVarA, LVar0, LVar0, LVar0)
                    EVT_LOOP(4)
                        EVT_ADDF(LVar0, EVT_FLOAT(0.2))
                        EVT_CALL(SetVirtualEntityScale, LVarA, LVar0, LVar0, LVar0)
                        EVT_WAIT(1)
                    EVT_END_LOOP
                    EVT_SET(LVar0, 0)
                    EVT_LOOP(5)
                        EVT_ADD(LVar0, 72)
                        EVT_CALL(SetVirtualEntityRotation, LVarA, 0, LVar0, 0)
                        EVT_WAIT(1)
                    EVT_END_LOOP
                    EVT_CALL(PlaySound, SOUND_UP_AND_AWAY_SEND_AWAY)
                    EVT_SET(LVar0, LVarD)
                    EVT_SET(LVar1, LVarE)
                    EVT_SET(LVar2, LVarF)
                    EVT_SET(LVar3, 0)
                    EVT_LOOP(50)
                        EVT_CALL(SetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
                        EVT_CALL(SetVirtualEntityRotation, LVarA, 0, LVar3, 0)
                        EVT_ADD(LVar1, 6)
                        EVT_ADD(LVar3, 45)
                        EVT_WAIT(1)
                    EVT_END_LOOP
                EVT_END_THREAD
                EVT_THREAD
                    EVT_CALL(PlaySound, SOUND_UP_AND_AWAY_CAPTURE)
                    EVT_CALL(GetOwnerTarget, LVarA, LVar1)
                    EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_SHADOW, TRUE)
                    EVT_SETF(LVar0, EVT_FLOAT(1.0))
                    EVT_LOOP(18)
                        EVT_SUBF(LVar0, EVT_FLOAT(0.05))
                        EVT_CALL(SetActorScale, LVarA, LVar0, LVar0, LVar0)
                        EVT_WAIT(1)
                    EVT_END_LOOP
                    EVT_CALL(SetActorPos, LVarA, NPC_DISPOSE_LOCATION)
                    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                    EVT_LOOP(10)
                        EVT_PLAY_EFFECT(EFFECT_SPARKLES, FX_SPARKLES_1, LVar0, LVar1, LVar2, 20, 0)
                        EVT_ADD(LVar1, 30)
                        EVT_WAIT(5)
                    EVT_END_LOOP
                    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_STAR_POINTS_DROPPED, TRUE)
                    EVT_CALL(RemoveActor, LVarA)
                EVT_END_THREAD
            EVT_CASE_DEFAULT
                EVT_IF_EQ(LFlag0, FALSE)
                    EVT_CALL(PlayerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 0, BS_FLAGS1_FORCE_IMMUNE_HIT | BS_FLAGS1_TRIGGER_EVENTS)
                EVT_END_IF
        EVT_END_SWITCH
        EVT_WAIT(5)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_WAIT(70)
    EVT_CALL(N(RestoreBackground))
    EVT_EXEC_WAIT(N(EVS_StarPower_SpiritDeparts))
    EVT_CALL(PlayerYieldTurn)
    EVT_EXEC_WAIT(N(EVS_StarPower_EndWish))
    EVT_RETURN
    EVT_END
};
