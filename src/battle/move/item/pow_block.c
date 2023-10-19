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
    EVT_SET_CONST(LVarA, ITEM_POW_BLOCK)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_WAIT(10)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_PowBlock), -40, 60, 0, 0, MAKE_ENTITY_END)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(N(AdjustPOWBlockEntityScale))
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, -40, 60, 20, 0, 0, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, -30, 65, 20, 0, 0, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, -40, 60, 20, 0, 0, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, -40, 55, 20, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_WAIT(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_BLOCK)
        EVT_CALL(N(ForceTriggerPOWBlockEntity))
        EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, -40, 60, 20, 0, 0, 0)
        EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, -30, 65, 20, 0, 0, 0)
        EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, -40, 60, 20, 0, 0, 0)
        EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, -40, 55, 20, 0, 0, 0)
        EVT_CALL(StartRumble, BTL_RUMBLE_HIT_HEAVY)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(6.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(5.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(4.0))
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_POW_BLOCK)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_WAIT(5)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.6))
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 20, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(ItemCheckHit, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, LVar0, 0)
        EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(GetItemPower, ITEM_POW_BLOCK, LVar3, LVar4)
        EVT_CALL(ApplyShrinkFromOwner, LVar3)
        EVT_CALL(SetDamageSource, DMG_SRC_POW_BLOCK)
        EVT_CALL(ItemDamageEnemy, LVar0, DAMAGE_TYPE_POW | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, LVar3, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_LABEL(1)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, -70, 60, 20, 0, 0, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, -60, 65, 20, 0, 0, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, -70, 60, 20, 0, 0, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, -70, 55, 20, 0, 0, 0)
    EVT_CALL(N(DeletePOWBlockEntity))
    EVT_WAIT(30)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
