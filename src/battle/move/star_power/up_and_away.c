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

    script->varTable[0] = false;

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
        script->varTable[0] = true;
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_UsePower) = {
    ExecWait(N(EVS_StarPower_WishForSpirit))
    SetConst(LVar0, ANIM_BattleKalmar_Idle)
    ExecWait(N(EVS_StarPower_SpiritSummoned))
    Call(SetNpcAnimation, NPC_BTL_SPIRIT, ANIM_BattleKalmar_Shout)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Wait(20)
    Call(SetMotionBlurParams, 0, 0, 0, 320, 240, 128, 10)
    Call(N(DarkenBackground))
    Call(PlaySound, SOUND_UP_AND_AWAY_CAST)
    PlayEffect(EFFECT_ENERGY_SHOCKWAVE, 0, 0, 20, 0, Float(1.0), 90)
    Wait(30)
    Thread
        PlayEffect(EFFECT_SHIMMER_WAVE, 0, 0, 50, 0, 300, 100, 10, 40)
    EndThread
    PlayEffect(EFFECT_ENERGY_SHOCKWAVE, 0, 0, 20, 0, Float(1.0), 90)
    Wait(75)
    Call(SetMotionBlurParams, 0, 0, 0, 320, 240, 0, 10)
    Call(InitTargetIterator)
    Label(0)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(N(ShouldTargetBeCaptured))
        Set(LFlag0, false)
        Call(ItemCheckHit, LVar1, 0, 0, 0, 0)
        IfEq(LVar1, HIT_RESULT_MISS)
            Set(LVar0, 0)
            Set(LFlag0, true)
        EndIf
        Switch(LVar0)
            CaseGt(0)
                Call(GetOwnerTarget, LVar0, LVar1)
                Call(DispatchEvent, LVar0, EVENT_UP_AND_AWAY)
                Call(SetActorRotationOffset, LVar0, 0, 10, 0)
                Thread
                    Call(GetOwnerTarget, LVarB, LVar1)
                    Wait(10)
                    Call(CreateVirtualEntity, LVarA, Ref(EMS_StarIcon))
                    Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
                    Set(LVarD, LVar0)
                    Set(LVarE, LVar1)
                    Set(LVarF, LVar2)
                    Call(SetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
                    SetF(LVar0, Float(0.2))
                    Call(SetVirtualEntityScale, LVarA, LVar0, LVar0, LVar0)
                    Loop(4)
                        AddF(LVar0, Float(0.2))
                        Call(SetVirtualEntityScale, LVarA, LVar0, LVar0, LVar0)
                        Wait(1)
                    EndLoop
                    Set(LVar0, 0)
                    Loop(5)
                        Add(LVar0, 72)
                        Call(SetVirtualEntityRotation, LVarA, 0, LVar0, 0)
                        Wait(1)
                    EndLoop
                    Call(PlaySound, SOUND_UP_AND_AWAY_SEND_AWAY)
                    Set(LVar0, LVarD)
                    Set(LVar1, LVarE)
                    Set(LVar2, LVarF)
                    Set(LVar3, 0)
                    Loop(50)
                        Call(SetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
                        Call(SetVirtualEntityRotation, LVarA, 0, LVar3, 0)
                        Add(LVar1, 6)
                        Add(LVar3, 45)
                        Wait(1)
                    EndLoop
                EndThread
                Thread
                    Call(PlaySound, SOUND_UP_AND_AWAY_CAPTURE)
                    Call(GetOwnerTarget, LVarA, LVar1)
                    Call(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_SHADOW, true)
                    SetF(LVar0, Float(1.0))
                    Loop(18)
                        SubF(LVar0, Float(0.05))
                        Call(SetActorScale, LVarA, LVar0, LVar0, LVar0)
                        Wait(1)
                    EndLoop
                    Call(SetActorPos, LVarA, NPC_DISPOSE_LOCATION)
                    Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                    Loop(10)
                        PlayEffect(EFFECT_SPARKLES, FX_SPARKLES_1, LVar0, LVar1, LVar2, 20, 0)
                        Add(LVar1, 30)
                        Wait(5)
                    EndLoop
                    Call(SetBattleFlagBits, BS_FLAGS1_STAR_POINTS_DROPPED, true)
                    Call(RemoveActor, LVarA)
                EndThread
            CaseDefault
                IfEq(LFlag0, false)
                    Call(PlayerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 0, BS_FLAGS1_FORCE_IMMUNE_HIT | BS_FLAGS1_TRIGGER_EVENTS)
                EndIf
        EndSwitch
        Wait(5)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Wait(70)
    Call(N(RestoreBackground))
    ExecWait(N(EVS_StarPower_SpiritDeparts))
    Call(PlayerYieldTurn)
    ExecWait(N(EVS_StarPower_EndWish))
    Return
    End
};
