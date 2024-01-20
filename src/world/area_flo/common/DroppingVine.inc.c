#include "common.h"
#include "effects.h"

API_CALLABLE(N(CheckVineTriggerDist)) {
    f32 var1 = script->varTable[0] - script->varTable[3];
    f32 var2 = script->varTable[1] - script->varTable[4];
    f32 var3 = script->varTable[2] - script->varTable[5];

    script->varTable[0] = SQ(var1) + SQ(var2) + SQ(var3) < SQ(60.0f);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_DroppingVine) = {
    Set(LVar9, LVar6)
    Set(LVar8, LVar5)
    Set(LVar7, LVar4)
    Set(LVar6, LVar3)
    Set(LVar5, LVar2)
    Set(LVar4, LVar1)
    Set(LVar3, LVar0)
    Call(EnableModel, LVar6, FALSE)
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(N(CheckVineTriggerDist))
        IfEq(LVar0, 0)
            Wait(1)
            Goto(0)
        EndIf
    Thread
        Wait(5)
        Call(EnableModel, LVar6, TRUE)
    EndThread
    IfNe(LVarA, 0)
        Thread
            Wait(5)
            Set(LVar0, LVar3)
            Set(LVar1, LVar4)
            Set(LVar2, LVar5)
            Add(LVar1, 10)
            Add(LVar2, 8)
            PlayEffect(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 15)
            Wait(15)
            Sub(LVar1, 10)
            Call(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_FALL, 0)
        EndThread
    EndIf
    Thread
        Wait(10)
        Call(PlaySoundAt, SOUND_FLIP_PAGE, SOUND_SPACE_DEFAULT, LVar3, LVar4, LVar5)
    EndThread
    Call(MakeLerp, 0, 180, 20, EASING_CUBIC_IN)
    Label(1)
        Call(UpdateLerp)
        Call(RotateModel, LVar8, LVar0, 1, 0, 0)
        Call(RotateModel, LVar9, LVar0, 1, 0, 0)
        IfEq(LVar1, 1)
            Wait(1)
            Goto(1)
        EndIf
    Call(EnableModel, LVar7, FALSE)
    Return
    End
};

#define EVT_DROPPING_VINE(itemID, modelUpperAfter, modelLowerBefore, modelLowerAfter, modelUpperBefore) \
    Call(GetModelCenter, modelUpperAfter) \
    Set(LVar3, modelUpperAfter) \
    Set(LVar4, modelLowerBefore) \
    Set(LVar5, modelLowerAfter) \
    Set(LVar6, modelUpperBefore) \
    Set(LVarA, itemID) \
    Exec(N(EVS_DroppingVine))
