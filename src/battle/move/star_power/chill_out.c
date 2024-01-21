#include "common.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleMuskular.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_chill_out

BSS b32 DidChillOutHit;

#include "battle/common/move/StarPowerSupport.inc.c"

API_CALLABLE(N(InitHitCheck)) {
    DidChillOutHit = FALSE;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DidMoveHit)) {
    script->varTable[0] = DidChillOutHit;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpawnChillOutFX)) {
    f32 x = rand_int(200) - 25;
    f32 y = rand_int(120) + 7;
    f32 z = rand_int(50) - 25;

    fx_cold_breath(2, x, y, z, 2.0f, 20);

    x = rand_int(200) - 25;
    y = rand_int(120) + 7;
    z = rand_int(50) - 25;

    fx_sparkles(FX_SPARKLES_4, x, y, z, 40.0f);
    
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CanChillOutHit)) {
    Actor* actor = get_actor(script->owner1.actorID);
    Actor* target = get_actor(actor->targetActorID);
    ActorPart* part = get_actor_part(target, actor->targetPartID);

    script->varTable[0] = FALSE;

    if (target->flags & ACTOR_FLAG_TARGET_ONLY) {
        return ApiStatus_DONE2;
    }

    if (target->flags & ACTOR_FLAG_NO_DMG_APPLY) {
        return ApiStatus_DONE2;
    }

    if (target->flags & ACTOR_FLAG_DAMAGE_IMMUNE) {
        return ApiStatus_DONE2;
    }

    if (part->eventFlags & ACTOR_EVENT_FLAG_ENCHANTED) {
        return ApiStatus_DONE2;
    }

    if (part->eventFlags & ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED) {
        return ApiStatus_DONE2;
    }

    script->varTable[0] = TRUE;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(InflictChillOutHit)) {
    Actor* enemy = get_actor(script->owner1.enemyID);
    Actor* target = get_actor(enemy->targetActorID);
    ActorPart* targetPart = get_actor_part(target, enemy->targetPartID);
    f32 x, y, z;

    if (target->flags & ACTOR_FLAG_TARGET_ONLY) {
        return ApiStatus_DONE2;
    }

    if (target->flags & ACTOR_FLAG_NO_DMG_APPLY) {
        return ApiStatus_DONE2;
    }

    if (target->flags & ACTOR_FLAG_DAMAGE_IMMUNE) {
        return ApiStatus_DONE2;
    }

    if (targetPart->eventFlags & ACTOR_EVENT_FLAG_ENCHANTED) {
        return ApiStatus_DONE2;
    }

    if (targetPart->eventFlags & ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED) {
        return ApiStatus_DONE2;
    }

    target->chillOutTurns = 4;
    target->chillOutAmount = 3;

    dispatch_damage_event_actor_0(target, 0, EVENT_HIT);

    x = target->curPos.x + target->headOffset.x + (target->size.x / 2);
    if (target->flags & ACTOR_FLAG_UPSIDE_DOWN) {
        y = target->curPos.y + target->headOffset.y - target->size.y;
    } else if (!(target->flags & ACTOR_FLAG_HALF_HEIGHT)) {
        y = target->curPos.y + target->headOffset.y + target->size.y;
    } else {
        y = target->curPos.y + target->headOffset.y + target->size.y * 2;
    }
    z = target->curPos.z + target->headOffset.z + 5.0f;

    fx_stat_change(5, x, y, z, 1.0f, 60);
    sfx_play_sound(SOUND_INFLICT_CHILL_OUT);
    DidChillOutHit = TRUE;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_UsePower) = {
    Call(N(InitHitCheck))
    ExecWait(N(EVS_StarPower_WishForSpirit))
    SetConst(LVar0, ANIM_BattleMuskular_Idle)
    ExecWait(N(EVS_StarPower_SpiritSummoned))
    Call(SetNpcAnimation, NPC_BTL_SPIRIT, ANIM_BattleMuskular_Shout)
    Wait(16)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Call(PlaySound, SOUND_CHILL_OUT)
    Call(InitTargetIterator)
    Label(10)
        Call(ItemCheckHit, LVar0, 0, 0, 0, 0)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(11)
        EndIf
        Call(N(CanChillOutHit))
        IfEq(LVar0, TRUE)
            Call(GetOwnerTarget, LVarA, LVarB)
            Thread
                Loop(5)
                    Call(SetActorScaleModifier, LVarA, Float(1.0), Float(1.0), Float(1.0))
                    Wait(1)
                    Call(SetActorScaleModifier, LVarA, Float(1.1), Float(1.0), Float(1.0))
                    Wait(1)
                    Call(SetActorScaleModifier, LVarA, Float(1.2), Float(0.95), Float(1.0))
                    Wait(1)
                    Call(SetActorScaleModifier, LVarA, Float(1.3), Float(0.9), Float(1.0))
                    Wait(1)
                    Call(SetActorScaleModifier, LVarA, Float(1.35), Float(0.85), Float(1.0))
                    Wait(1)
                    Call(SetActorScaleModifier, LVarA, Float(1.38), Float(0.8), Float(1.0))
                    Wait(1)
                    Call(SetActorScaleModifier, LVarA, Float(1.4), Float(0.8), Float(1.0))
                    Wait(1)
                    Call(SetActorScaleModifier, LVarA, Float(1.3), Float(0.85), Float(1.0))
                    Wait(1)
                    Call(SetActorScaleModifier, LVarA, Float(1.2), Float(0.9), Float(1.0))
                    Wait(1)
                    Call(SetActorScaleModifier, LVarA, Float(1.1), Float(0.95), Float(1.0))
                    Wait(1)
                EndLoop
                Call(SetActorScaleModifier, LVarA, Float(1.0), Float(1.0), Float(1.0))
            EndThread
        EndIf
        Label(11)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(10)
        EndIf
    Loop(30)
        Call(N(SpawnChillOutFX))
        Wait(2)
    EndLoop
    Call(ChooseNextTarget, ITER_FIRST, 0)
    Label(0)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(ItemCheckHit, LVar0, 0, 0, 0, 0)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(1)
        EndIf
        Call(N(CanChillOutHit))
        IfEq(LVar0, TRUE)
            Call(N(InflictChillOutHit))
        Else
            Call(PlayerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 0, BS_FLAGS1_FORCE_IMMUNE_HIT | BS_FLAGS1_TRIGGER_EVENTS)
        EndIf
        Label(1)
        Wait(5)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Wait(5)
    Call(N(DidMoveHit))
    IfEq(LVar0, TRUE)
        Call(ShowMessageBox, BTL_MSG_CHILL_OUT_BEGIN, 60)
    EndIf
    Call(PlayerYieldTurn)
    ExecWait(N(EVS_StarPower_SpiritDeparts))
    ExecWait(N(EVS_StarPower_EndWish))
    Call(N(DidMoveHit))
    IfEq(LVar0, TRUE)
        Call(WaitForMessageBoxDone)
    EndIf
    Return
    End
};
