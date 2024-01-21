#include "common.h"
#include "script_api/battle.h"
#include "entity.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_item_pow_block

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(ForceTriggerPOWBlockEntity)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (player->scalingFactor == 1.0) {
        s32 entityID = script->varTable[10];
        get_entity_by_index(entityID);
        collisionStatus->curCeiling = entityID | COLLISION_WITH_ENTITY_BIT;
        playerStatus->flags |= PS_FLAG_JUMPING;
        update_entities();
        collisionStatus->curCeiling = -1;
        playerStatus->flags &= ~PS_FLAG_JUMPING;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(DeletePOWBlockEntity)) {
    Entity* entity = get_entity_by_index(script->varTable[10]);

    entity->flags |= ENTITY_FLAG_PENDING_INSTANCE_DELETE;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(AdjustPOWBlockEntityScale)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Entity* entity = get_entity_by_index(script->varTable[10]);

    entity->scale.x = player->scalingFactor;
    entity->scale.y = player->scalingFactor;
    entity->scale.z = player->scalingFactor;
    if (player->scalingFactor != 1.0) {
        entity->pos.y -= 10.0f;
    }

    return ApiStatus_DONE2;
}

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    SetConst(LVarA, ITEM_POW_BLOCK)
    ExecWait(N(UseItemWithEffect))
    Wait(10)
    Call(MakeEntity, Ref(Entity_PowBlock), -40, 60, 0, 0, MAKE_ENTITY_END)
    Set(LVarA, LVar0)
    Call(N(AdjustPOWBlockEntityScale))
    PlayEffect(EFFECT_WALKING_DUST, 2, -40, 60, 20, 0, 0, 0)
    PlayEffect(EFFECT_WALKING_DUST, 2, -30, 65, 20, 0, 0, 0)
    PlayEffect(EFFECT_WALKING_DUST, 2, -40, 60, 20, 0, 0, 0)
    PlayEffect(EFFECT_WALKING_DUST, 2, -40, 55, 20, 0, 0, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Wait(20)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Thread
        Wait(15)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_BLOCK)
        Call(N(ForceTriggerPOWBlockEntity))
        PlayEffect(EFFECT_WALKING_DUST, 2, -40, 60, 20, 0, 0, 0)
        PlayEffect(EFFECT_WALKING_DUST, 2, -30, 65, 20, 0, 0, 0)
        PlayEffect(EFFECT_WALKING_DUST, 2, -40, 60, 20, 0, 0, 0)
        PlayEffect(EFFECT_WALKING_DUST, 2, -40, 55, 20, 0, 0, 0)
        Call(StartRumble, BTL_RUMBLE_HIT_HEAVY)
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(3.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(6.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(5.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(4.0))
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_POW_BLOCK)
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(3.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(2.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.2))
    EndThread
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(4.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(PlayerRunToGoal, 0)
    Wait(5)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(0.6))
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(func_80273444, 20, 0, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Call(MoveBattleCamOver, 20)
    Call(InitTargetIterator)
    Label(0)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(ItemCheckHit, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, LVar0, 0)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(1)
        EndIf
        Call(GetItemPower, ITEM_POW_BLOCK, LVar3, LVar4)
        Call(ApplyShrinkFromOwner, LVar3)
        Call(SetDamageSource, DMG_SRC_POW_BLOCK)
        Call(ItemDamageEnemy, LVar0, DAMAGE_TYPE_POW | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, LVar3, BS_FLAGS1_TRIGGER_EVENTS)
        Label(1)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    PlayEffect(EFFECT_WALKING_DUST, 2, -70, 60, 20, 0, 0, 0)
    PlayEffect(EFFECT_WALKING_DUST, 2, -60, 65, 20, 0, 0, 0)
    PlayEffect(EFFECT_WALKING_DUST, 2, -70, 60, 20, 0, 0, 0)
    PlayEffect(EFFECT_WALKING_DUST, 2, -70, 55, 20, 0, 0, 0)
    Call(N(DeletePOWBlockEntity))
    Wait(30)
    ExecWait(N(PlayerGoHome))
    Return
    End
};
