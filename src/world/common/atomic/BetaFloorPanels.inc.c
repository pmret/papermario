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
    UseBuf(LVar0)
    MallocArray(6, LVarA)
    BufRead1(LVar0) // modelID
    Set(ArrayVar(0), LVar0)
    BufRead1(LVar0) // colliderID
    Set(ArrayVar(1), LVar0)
    BufRead1(LVar0) // posX
    Set(ArrayVar(2), LVar0)
    BufRead1(LVar0) // posZ
    Set(ArrayVar(3), LVar0)
    BufRead1(LVar0) // radius
    Set(ArrayVar(4), LVar0)
    BufRead1(LVar0) // callback event
    Set(ArrayVar(5), LVar0)
    Set(LVar0, LVarA)
    BindTrigger(Ref(N(EVS_BetaBreakFloor_Touch)), TRIGGER_FLOOR_TOUCH, ArrayVar(0), 1, 0)
    Return
    End
};

EvtScript N(EVS_BetaBreakFloor_Touch) = {
    UseArray(LVar0)
    Call(N(CheckShouldBreakFloor))
    IfEq(LVar0, 0)
        Return
    EndIf
    Loop(5)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, ArrayVar(0), COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, ArrayVar(1), true)
        Wait(1)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, ArrayVar(0), COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, ArrayVar(1), false)
        Wait(1)
    EndLoop
    IfNe(ArrayVar(5), 0)
        ExecWait(ArrayVar(5))
    EndIf
    Return
    End
};

// flippable panels
EvtScript N(EVS_BetaPanel_Setup) = {
    UseBuf(LVar0)
    MallocArray(6, LVar9)
    BufRead1(LVar1) // modelID
    Set(ArrayVar(0), LVar1)
    BufRead1(LVar1) // colliderID
    Set(ArrayVar(1), LVar1)
    BufRead1(LVar1) // posX
    Set(ArrayVar(2), LVar1)
    BufRead1(LVar1) // posY
    Set(ArrayVar(3), LVar1)
    BufRead1(LVar1) // posZ
    Set(ArrayVar(4), LVar1)
    BufRead1(LVar1) // itemID
    Set(ArrayVar(5), LVar1)
    Call(ParentColliderToModel, ArrayVar(1), ArrayVar(0))
    Label(0)
        Label(1)
            Call(GetPlayerActionState, LVarA)
            IfEq(LVarA, ACTION_STATE_SPIN_JUMP)
                Goto(2)
            EndIf
            IfEq(LVarA, ACTION_STATE_TORNADO_JUMP)
                Goto(2)
            EndIf
            Wait(1)
            Goto(0)
        Label(2)
            Call(GetPlayerPos, LVar1, LVar2, LVar3)
            Wait(1)
            IfNe(LVar2, ArrayVar(3))
                Goto(2)
            EndIf
        Call(N(CheckShouldFlipFloor))
        IfEq(LVar0, 1)
            ExecWait(N(EVS_BetaPanel_PoundAtop))
        EndIf
        IfEq(LVar0, 2)
            ExecWait(N(EVS_BetaPanel_PoundNearby))
        EndIf
        Label(3)
            Call(GetPlayerActionState, LVar0)
            Wait(1)
            IfEq(LVar0, ACTION_STATE_SPIN_JUMP)
                Goto(3)
            EndIf
            IfEq(LVar0, ACTION_STATE_TORNADO_JUMP)
                Goto(3)
            EndIf
        Goto(0)
    Return
    End
};

EvtScript N(EVS_BetaPanel_PoundAtop) = {
    UseArray(LVar9)
    Call(GetPlayerPos, LVar2, LVar3, LVar4)
    Call(MakeLerp, 0, 5, 3, EASING_QUADRATIC_IN)
    Label(2)
        Call(UpdateLerp)
        Call(TranslateModel, ArrayVar(0), 0, LVar0, 0)
        Set(LVar5, LVar3)
        Add(LVar5, LVar0)
        Call(SetPlayerPos, LVar2, LVar5, LVar4)
        Call(UpdateColliderTransform, ArrayVar(1))
        Wait(1)
        IfEq(LVar1, 1)
            Goto(2)
        EndIf
    Call(MakeLerp, 5, 0, 3, EASING_QUADRATIC_IN)
    Label(3)
        Call(UpdateLerp)
        Call(TranslateModel, ArrayVar(0), 0, LVar0, 0)
        Set(LVar5, LVar3)
        Add(LVar5, LVar0)
        Call(SetPlayerPos, LVar2, LVar5, LVar4)
        Call(UpdateColliderTransform, ArrayVar(1))
        Wait(1)
        IfEq(LVar1, 1)
            Goto(3)
        EndIf
    Return
    End
};

EvtScript N(EVS_BetaPanel_PoundNearby) = {
    UseArray(LVar9)
    Call(MakeItemEntity, ArrayVar(5), ArrayVar(2), ArrayVar(3), ArrayVar(4), ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
    Set(LVar2, 0)
    Call(MakeLerp, 0, 150, 19, EASING_QUADRATIC_OUT)
    Label(2)
        Call(UpdateLerp)
        Call(TranslateModel, ArrayVar(0), 0, LVar0, 0)
        Add(LVar2, 45)
        Call(RotateModel, ArrayVar(0), LVar2, 1, 0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(2)
        EndIf
    Call(MakeLerp, 150, 0, 19, EASING_QUADRATIC_OUT)
    Label(3)
        Call(UpdateLerp)
        Call(TranslateModel, ArrayVar(0), 0, LVar0, 0)
        Add(LVar2, 45)
        Call(RotateModel, ArrayVar(0), LVar2, 1, 0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(3)
        EndIf
    Return
    End
};
