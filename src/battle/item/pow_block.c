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
        collisionStatus->currentCeiling = var | 0x4000;
        playerStatus->flags |= 2;
        update_entities();
        collisionStatus->currentCeiling = -1;
        playerStatus->flags &= ~2;
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

EvtSource N(main) = {
    EVT_SET_CONST(EVT_VAR(10), 0x00000090)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_WAIT_FRAMES(10)
    EVT_CALL(MakeEntity, 0x802EA2E0, -40, 60, 0, 0, MAKE_ENTITY_END)
    EVT_SET(EVT_VAR(10), EVT_VAR(0))
    EVT_CALL(N(func_802A1318_718B68))
    EVT_CALL(PlayEffect, 0x7, 2, -40, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 2, -30, 65, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 2, -40, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 2, -40, 55, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_THREAD
        EVT_WAIT_FRAMES(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_BLOCK)
        EVT_CALL(N(func_802A123C_718A8C))
        EVT_CALL(PlayEffect, 0x7, 2, -40, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlayEffect, 0x7, 2, -30, 65, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlayEffect, 0x7, 2, -40, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlayEffect, 0x7, 2, -40, 55, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(StartRumble, 4)
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(1.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(3.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(6.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(5.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(4.0))
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2030)
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(3.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(2.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(1.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(0.5))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(0.2))
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 30)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FIXED(4.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_10009)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FIXED(0.6))
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(func_80273444, 20, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_CALL(UseBattleCamPreset, 3)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, EVT_VAR(0), 268435456, 0, EVT_VAR(0), 0)
    EVT_IF_EQ(EVT_VAR(0), 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetItemPower, ITEM_P_O_W_BLOCK, EVT_VAR(3), EVT_VAR(4))
    EVT_CALL(ApplyShrinkFromOwner, EVT_VAR(3))
    EVT_CALL(func_80269EAC, 22)
    EVT_CALL(ItemDamageEnemy, EVT_VAR(0), 939525120, 0, EVT_VAR(3), 32)
    EVT_LABEL(1)
    EVT_CALL(ChooseNextTarget, 0, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlayEffect, 0x7, 2, -70, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 2, -60, 65, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 2, -70, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 2, -70, 55, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(N(func_802A12E4_718B34))
    EVT_WAIT_FRAMES(30)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
