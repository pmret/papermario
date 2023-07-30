#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "entity.h"
#include "sprite/player.h"

#define NAMESPACE battle_item_super_soda

extern EntityModelScript EMS_StarIcon;

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(func_802A123C_724F1C)) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    ItemEntity* item = get_item_entity(script->varTable[14]);

    item->pos.x = a;
    item->pos.y = b;
    item->pos.z = c;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802A12EC_724FCC)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    Bytecode* args = script->ptrReadPos;

    if (partner->koDuration == 0) {
        return ApiStatus_DONE2;
    }

    partner->koDuration -= evt_get_variable(script, *args++);
    if (partner->koDuration < 0) {
        partner->koDuration = 0;
    }
    if (partner->koDuration > 0) {
        partner->disableEffect->data.disableX->koDuration = partner->koDuration;
    } else {
        partner->koStatus = 0;
        dispatch_event_partner(EVENT_RECOVER_FROM_KO);
        partner->disableEffect->data.disableX->koDuration = 0;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802A1378_725058)) {
    s32 actorId = evt_get_variable(script, *script->ptrReadPos);
    Actor* actor = get_actor(actorId);
    s32 actorClass = actor->actorID & ACTOR_CLASS_MASK;

    if (actor->debuff != 0) {
        actor->debuffDuration = 0;
        actor->debuff = 0;
        remove_status_debuff(actor->hudElementDataIndex);
    }

    if (actor->koStatus != 0) {
        actor->koDuration = 0;
        actor->koStatus = 0;

        switch (actorClass) {
            case ACTOR_CLASS_PLAYER:
                break;
            case ACTOR_CLASS_PARTNER:
                dispatch_event_partner(EVENT_RECOVER_STATUS);
                break;
        }

        actor->disableEffect->data.disableX->koDuration = 0;
    }

    btl_update_ko_status();

    return ApiStatus_DONE2;
}

API_CALLABLE(N(ShowFlowerRecoveryFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(1, a, b, c, d);
    return ApiStatus_DONE2;
}

#include "common/AddFP.inc.c"

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseOnPartner) = {
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 180)
    EVT_WAIT(10)
    EVT_SET(LVar1, LVarF)
    EVT_EXEC_WAIT(N(UseItem))
    EVT_SET(LVarE, LVarA)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Throw)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_END_THREAD
    EVT_CALL(CreateVirtualEntity, LVarA, EVT_PTR(EMS_StarIcon))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 0)
    EVT_ADD(LVar1, 30)
    EVT_ADD(LVar2, 5)
    EVT_CALL(SetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(SetVirtualEntityFlags, LVarA, 32)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 45)
        EVT_CALL(MakeItemEntity, LVarE, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(LVarE, LVar0)
        EVT_LOOP(25)
            EVT_CALL(GetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
            EVT_CALL(N(func_802A123C_724F1C), LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(RemoveItemEntity, LVarE)
    EVT_END_THREAD
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, -125, 1, 0)
    EVT_CALL(SetBattleCamOffsetZ, 41)
    EVT_CALL(SetBattleCamZoom, 248)
    EVT_CALL(MoveBattleCamOver, 25)
    EVT_CALL(SetVirtualEntityJumpGravity, LVarA, EVT_FLOAT(0.4))
    EVT_ADD(LVar2, 5)
    EVT_CALL(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 25)
    EVT_CALL(AddBattleCamZoom, 100)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, LVarB)
    EVT_IF_GT(LVarB, 0)
        EVT_CALL(N(func_802A12EC_724FCC), LVarB)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(ShowRecoveryShimmer, LVar0, LVar1, LVar2, LVarB)
    EVT_WAIT(20)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseItem) = {
    EVT_SET_CONST(LVarA, ITEM_SUPER_SODA)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_IF_EQ(LVar0, ACTOR_PLAYER)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2095)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Drink)
        EVT_WAIT(45)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 0)
        EVT_ADD(LVar1, 35)
        EVT_CALL(N(ShowFlowerRecoveryFX), LVar0, LVar1, LVar2, 5)
        EVT_CALL(N(AddFP), 5)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 25)
        EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, 5)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_ThumbsUp)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(ShowRecoveryShimmer, LVar0, LVar1, LVar2, 5)
        EVT_CALL(InitTargetIterator)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(N(func_802A1378_725058), 0)
        EVT_WAIT(20)
    EVT_ELSE
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_SET(LVarF, 0)
        EVT_EXEC_WAIT(N(EVS_UseOnPartner))
    EVT_END_IF
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
