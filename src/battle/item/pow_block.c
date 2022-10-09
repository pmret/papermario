#include "pow_block.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_718A8C)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (player->scalingFactor == 1.0) {
        s32 var = script->varTable[10];
        get_entity_by_index(var);
        collisionStatus->currentCeiling = var | COLLISION_WITH_ENTITY_BIT;
        playerStatus->flags |= PS_FLAGS_JUMPING;
        update_entities();
        collisionStatus->currentCeiling = -1;
        playerStatus->flags &= ~PS_FLAGS_JUMPING;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A12E4_718B34)(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(script->varTable[10]);

    entity->flags |= ENTITY_FLAGS_PENDING_INSTANCE_DELETE;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1318_718B68)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Entity* entity = get_entity_by_index(script->varTable[10]);

    entity->scale.x = player->scalingFactor;
    entity->scale.y = player->scalingFactor;
    entity->scale.z = player->scalingFactor;
    if (player->scalingFactor != 1.0) {
        entity->position.y -= 10.0f;
    }

    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

EvtScript N(main) = {
    EVT_SET_CONST(LVarA, 0x00000090)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_WAIT(10)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_PowBlock), -40, 60, 0, 0, MAKE_ENTITY_END)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(N(func_802A1318_718B68))
    EVT_CALL(PlayEffect, 0x7, 2, -40, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 2, -30, 65, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 2, -40, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 2, -40, 55, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_WAIT(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_BLOCK)
        EVT_CALL(N(func_802A123C_718A8C))
        EVT_CALL(PlayEffect, 0x7, 2, -40, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlayEffect, 0x7, 2, -30, 65, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlayEffect, 0x7, 2, -40, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlayEffect, 0x7, 2, -40, 55, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(StartRumble, 4)
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(6.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(5.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(4.0))
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2030)
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Running)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_WAIT(5)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_AnimMidairStill, ANIM_Mario_AnimMidair, ANIM_Mario_10009)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.6))
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 20, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, LVar0, 268435456, 0, LVar0, 0)
    EVT_IF_EQ(LVar0, 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetItemPower, ITEM_POW_BLOCK, LVar3, LVar4)
    EVT_CALL(ApplyShrinkFromOwner, LVar3)
    EVT_CALL(func_80269EAC, 22)
    EVT_CALL(ItemDamageEnemy, LVar0, 939525120, 0, LVar3, 32)
    EVT_LABEL(1)
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlayEffect, 0x7, 2, -70, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 2, -60, 65, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 2, -70, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 2, -70, 55, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(N(func_802A12E4_718B34))
    EVT_WAIT(30)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
