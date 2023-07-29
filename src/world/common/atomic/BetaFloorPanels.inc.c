#include "common.h"

// unused early(?) versions of both flippable and breakable floor panels.
// unlike those fpund in the final game, models and colliders for these panels must be
// manually set up by the map author. a usable flip panel example is found in tst_13.

extern EvtScript N(EVS_BetaBreakFloor_Touch);
extern EvtScript N(EVS_BetaPanel_PoundAtop);
extern EvtScript N(EVS_BetaPanel_PoundNearby);

API_CALLABLE(N(CheckShouldBreakFloor)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32* array = script->array;
    f32 distance = dist2D(playerStatus->pos.x, playerStatus->pos.z, array[2], array[3]);

    script->varTable[0] = 1;
    if ((playerStatus->actionState != ACTION_STATE_SPIN_POUND)
            && (playerStatus->actionState != ACTION_STATE_TORNADO_POUND)) {
        script->varTable[0] = 0;
    }
    if (script->array[4] <= distance) {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(CheckShouldFlipFloor)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 distance = dist2D(
        playerStatus->pos.x, playerStatus->pos.z,
        script->array[2], script->array[4]);

    script->varTable[0] = 0;
    if (distance < 112.5f) {
        script->varTable[0] = 2;
    }
    if (distance < 37.5f) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

// breakable panels
EvtScript N(EVS_BetaBreakFloor_Setup) = {
    EVT_USE_BUF(LVar0)
    EVT_MALLOC_ARRAY(6, LVarA)
    EVT_BUF_READ1(LVar0) // modelID
    EVT_SET(ArrayVar(0), LVar0)
    EVT_BUF_READ1(LVar0) // colliderID
    EVT_SET(ArrayVar(1), LVar0)
    EVT_BUF_READ1(LVar0) // posX
    EVT_SET(ArrayVar(2), LVar0)
    EVT_BUF_READ1(LVar0) // posZ
    EVT_SET(ArrayVar(3), LVar0)
    EVT_BUF_READ1(LVar0) // radius
    EVT_SET(ArrayVar(4), LVar0)
    EVT_BUF_READ1(LVar0) // callback event
    EVT_SET(ArrayVar(5), LVar0)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BetaBreakFloor_Touch)), TRIGGER_FLOOR_TOUCH, ArrayVar(0), 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BetaBreakFloor_Touch) = {
    EVT_USE_ARRAY(LVar0)
    EVT_CALL(N(CheckShouldBreakFloor))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_LOOP(5)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, ArrayVar(0), COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, ArrayVar(1), TRUE)
        EVT_WAIT(1)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, ArrayVar(0), COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, ArrayVar(1), FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_IF_NE(ArrayVar(5), 0)
        EVT_EXEC_WAIT(ArrayVar(5))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

// flippable panels
EvtScript N(EVS_BetaPanel_Setup) = {
    EVT_USE_BUF(LVar0)
    EVT_MALLOC_ARRAY(6, LVar9)
    EVT_BUF_READ1(LVar1) // modelID
    EVT_SET(ArrayVar(0), LVar1)
    EVT_BUF_READ1(LVar1) // colliderID
    EVT_SET(ArrayVar(1), LVar1)
    EVT_BUF_READ1(LVar1) // posX
    EVT_SET(ArrayVar(2), LVar1)
    EVT_BUF_READ1(LVar1) // posY
    EVT_SET(ArrayVar(3), LVar1)
    EVT_BUF_READ1(LVar1) // posZ
    EVT_SET(ArrayVar(4), LVar1)
    EVT_BUF_READ1(LVar1) // itemID
    EVT_SET(ArrayVar(5), LVar1)
    EVT_CALL(ParentColliderToModel, ArrayVar(1), ArrayVar(0))
    EVT_LABEL(0)
        EVT_LABEL(1)
            EVT_CALL(GetPlayerActionState, LVarA)
            EVT_IF_EQ(LVarA, ACTION_STATE_SPIN_JUMP)
                EVT_GOTO(2)
            EVT_END_IF
            EVT_IF_EQ(LVarA, ACTION_STATE_TORNADO_JUMP)
                EVT_GOTO(2)
            EVT_END_IF
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_LABEL(2)
            EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_NE(LVar2, ArrayVar(3))
                EVT_GOTO(2)
            EVT_END_IF
        EVT_CALL(N(CheckShouldFlipFloor))
        EVT_IF_EQ(LVar0, 1)
            EVT_EXEC_WAIT(N(EVS_BetaPanel_PoundAtop))
        EVT_END_IF
        EVT_IF_EQ(LVar0, 2)
            EVT_EXEC_WAIT(N(EVS_BetaPanel_PoundNearby))
        EVT_END_IF
        EVT_LABEL(3)
            EVT_CALL(GetPlayerActionState, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, ACTION_STATE_SPIN_JUMP)
                EVT_GOTO(3)
            EVT_END_IF
            EVT_IF_EQ(LVar0, ACTION_STATE_TORNADO_JUMP)
                EVT_GOTO(3)
            EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BetaPanel_PoundAtop) = {
    EVT_USE_ARRAY(LVar9)
    EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
    EVT_CALL(MakeLerp, 0, 5, 3, EASING_QUADRATIC_IN)
    EVT_LABEL(2)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, ArrayVar(0), 0, LVar0, 0)
        EVT_SET(LVar5, LVar3)
        EVT_ADD(LVar5, LVar0)
        EVT_CALL(SetPlayerPos, LVar2, LVar5, LVar4)
        EVT_CALL(UpdateColliderTransform, ArrayVar(1))
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_CALL(MakeLerp, 5, 0, 3, EASING_QUADRATIC_IN)
    EVT_LABEL(3)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, ArrayVar(0), 0, LVar0, 0)
        EVT_SET(LVar5, LVar3)
        EVT_ADD(LVar5, LVar0)
        EVT_CALL(SetPlayerPos, LVar2, LVar5, LVar4)
        EVT_CALL(UpdateColliderTransform, ArrayVar(1))
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(3)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BetaPanel_PoundNearby) = {
    EVT_USE_ARRAY(LVar9)
    EVT_CALL(MakeItemEntity, ArrayVar(5), ArrayVar(2), ArrayVar(3), ArrayVar(4), ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
    EVT_SET(LVar2, 0)
    EVT_CALL(MakeLerp, 0, 150, 19, EASING_QUADRATIC_OUT)
    EVT_LABEL(2)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, ArrayVar(0), 0, LVar0, 0)
        EVT_ADD(LVar2, 45)
        EVT_CALL(RotateModel, ArrayVar(0), LVar2, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_CALL(MakeLerp, 150, 0, 19, EASING_QUADRATIC_OUT)
    EVT_LABEL(3)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, ArrayVar(0), 0, LVar0, 0)
        EVT_ADD(LVar2, 45)
        EVT_CALL(RotateModel, ArrayVar(0), LVar2, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(3)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};
