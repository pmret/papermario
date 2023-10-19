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
    EVT_CALL(N(InitHitCheck))
    EVT_EXEC_WAIT(N(EVS_StarPower_WishForSpirit))
    EVT_SET_CONST(LVar0, ANIM_BattleMuskular_Idle)
    EVT_EXEC_WAIT(N(EVS_StarPower_SpiritSummoned))
    EVT_CALL(SetNpcAnimation, NPC_BTL_SPIRIT, ANIM_BattleMuskular_Shout)
    EVT_WAIT(16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(PlaySound, SOUND_CHILL_OUT)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(10)
        EVT_CALL(ItemCheckHit, LVar0, 0, 0, 0, 0)
        EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
            EVT_GOTO(11)
        EVT_END_IF
        EVT_CALL(N(CanChillOutHit))
        EVT_IF_EQ(LVar0, TRUE)
            EVT_CALL(GetOwnerTarget, LVarA, LVarB)
            EVT_THREAD
                EVT_LOOP(5)
                    EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.1), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.2), EVT_FLOAT(0.95), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.3), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.35), EVT_FLOAT(0.85), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.38), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.4), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.3), EVT_FLOAT(0.85), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.2), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                    EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.1), EVT_FLOAT(0.95), EVT_FLOAT(1.0))
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorScaleModifier, LVarA, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_END_THREAD
        EVT_END_IF
        EVT_LABEL(11)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_LOOP(30)
        EVT_CALL(N(SpawnChillOutFX))
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_CALL(ChooseNextTarget, ITER_FIRST, 0)
    EVT_LABEL(0)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(ItemCheckHit, LVar0, 0, 0, 0, 0)
        EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(N(CanChillOutHit))
        EVT_IF_EQ(LVar0, TRUE)
            EVT_CALL(N(InflictChillOutHit))
        EVT_ELSE
            EVT_CALL(PlayerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 0, BS_FLAGS1_FORCE_IMMUNE_HIT | BS_FLAGS1_TRIGGER_EVENTS)
        EVT_END_IF
        EVT_LABEL(1)
        EVT_WAIT(5)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(N(DidMoveHit))
    EVT_IF_EQ(LVar0, TRUE)
        EVT_CALL(ShowMessageBox, BTL_MSG_CHILL_OUT_BEGIN, 60)
    EVT_END_IF
    EVT_CALL(PlayerYieldTurn)
    EVT_EXEC_WAIT(N(EVS_StarPower_SpiritDeparts))
    EVT_EXEC_WAIT(N(EVS_StarPower_EndWish))
    EVT_CALL(N(DidMoveHit))
    EVT_IF_EQ(LVar0, TRUE)
        EVT_CALL(WaitForMessageBoxDone)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
