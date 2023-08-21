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
    EVT_SET(LVar9, LVar6)
    EVT_SET(LVar8, LVar5)
    EVT_SET(LVar7, LVar4)
    EVT_SET(LVar6, LVar3)
    EVT_SET(LVar5, LVar2)
    EVT_SET(LVar4, LVar1)
    EVT_SET(LVar3, LVar0)
    EVT_CALL(EnableModel, LVar6, FALSE)
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(N(CheckVineTriggerDist))
        EVT_IF_EQ(LVar0, 0)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(EnableModel, LVar6, TRUE)
    EVT_END_THREAD
    EVT_IF_NE(LVarA, 0)
        EVT_THREAD
            EVT_WAIT(5)
            EVT_SET(LVar0, LVar3)
            EVT_SET(LVar1, LVar4)
            EVT_SET(LVar2, LVar5)
            EVT_ADD(LVar1, 10)
            EVT_ADD(LVar2, 8)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 15)
            EVT_WAIT(15)
            EVT_SUB(LVar1, 10)
            EVT_CALL(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_FALL, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAt, SOUND_FLIP_PAGE, SOUND_SPACE_DEFAULT, LVar3, LVar4, LVar5)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 180, 20, EASING_CUBIC_IN)
    EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, LVar8, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, LVar9, LVar0, 1, 0, 0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(EnableModel, LVar7, FALSE)
    EVT_RETURN
    EVT_END
};

#define EVT_DROPPING_VINE(itemID, modelUpperAfter, modelLowerBefore, modelLowerAfter, modelUpperBefore) \
    EVT_CALL(GetModelCenter, modelUpperAfter) \
    EVT_SET(LVar3, modelUpperAfter) \
    EVT_SET(LVar4, modelLowerBefore) \
    EVT_SET(LVar5, modelLowerAfter) \
    EVT_SET(LVar6, modelUpperBefore) \
    EVT_SET(LVarA, itemID) \
    EVT_EXEC(N(EVS_DroppingVine))
