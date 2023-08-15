#include "sam_11.h"

EvtScript N(EVS_LowerStaircase) = {
    EVT_CALL(EnableModel, MODEL_ana, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ana, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(TranslateModel, MODEL_o733, 0, 0, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o525, COLLIDER_FLAGS_UPPER_MASK)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        EVT_WAIT(11)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        EVT_WAIT(11)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        EVT_WAIT(11)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        EVT_WAIT(11)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        EVT_WAIT(11)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        EVT_WAIT(1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 25, 0, 12, EASING_LINEAR)
        EVT_LABEL(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, MODEL_o769, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(0)
            EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 50, 0, 24, EASING_LINEAR)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, MODEL_o729, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 75, 0, 36, EASING_LINEAR)
        EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, MODEL_o730, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(2)
            EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 100, 0, 48, EASING_LINEAR)
        EVT_LABEL(3)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, MODEL_o731, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(3)
            EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(MakeLerp, 125, 0, 60, EASING_LINEAR)
    EVT_LABEL(4)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o732, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(4)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupStaircase) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_SPOKE_WITH_HERRINGWAY)
            EVT_CALL(TranslateModel, MODEL_o769, 0, 25, 0)
            EVT_CALL(TranslateModel, MODEL_o729, 0, 50, 0)
            EVT_CALL(TranslateModel, MODEL_o730, 0, 75, 0)
            EVT_CALL(TranslateModel, MODEL_o731, 0, 100, 0)
            EVT_CALL(TranslateModel, MODEL_o732, 0, 125, 0)
            EVT_CALL(TranslateModel, MODEL_o733, NPC_DISPOSE_LOCATION)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o525, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CASE_GE(STORY_CH7_SPOKE_WITH_HERRINGWAY)
            EVT_CALL(EnableModel, MODEL_ana, FALSE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ana, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
