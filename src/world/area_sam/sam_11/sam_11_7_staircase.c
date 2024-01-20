#include "sam_11.h"

EvtScript N(EVS_LowerStaircase) = {
    Call(EnableModel, MODEL_ana, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ana, COLLIDER_FLAGS_UPPER_MASK)
    Call(TranslateModel, MODEL_o733, 0, 0, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o525, COLLIDER_FLAGS_UPPER_MASK)
    Thread
        Call(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        Wait(11)
        Call(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        Wait(1)
        Call(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        Wait(11)
        Call(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        Wait(1)
        Call(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        Wait(11)
        Call(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        Wait(1)
        Call(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        Wait(11)
        Call(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        Wait(1)
        Call(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        Wait(11)
        Call(PlaySoundAtCollider, COLLIDER_o525, SOUND_SAM_DROP_STAIR, 0)
        Wait(1)
    EndThread
    Thread
        Call(MakeLerp, 25, 0, 12, EASING_LINEAR)
        Label(0)
            Call(UpdateLerp)
            Call(TranslateModel, MODEL_o769, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(0)
            EndIf
    EndThread
    Thread
        Call(MakeLerp, 50, 0, 24, EASING_LINEAR)
        Label(1)
            Call(UpdateLerp)
            Call(TranslateModel, MODEL_o729, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
    EndThread
    Thread
        Call(MakeLerp, 75, 0, 36, EASING_LINEAR)
        Label(2)
            Call(UpdateLerp)
            Call(TranslateModel, MODEL_o730, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(2)
            EndIf
    EndThread
    Thread
        Call(MakeLerp, 100, 0, 48, EASING_LINEAR)
        Label(3)
            Call(UpdateLerp)
            Call(TranslateModel, MODEL_o731, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(3)
            EndIf
    EndThread
    Wait(1)
    Call(MakeLerp, 125, 0, 60, EASING_LINEAR)
    Label(4)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o732, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(4)
        EndIf
    Return
    End
};

EvtScript N(EVS_SetupStaircase) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_SPOKE_WITH_HERRINGWAY)
            Call(TranslateModel, MODEL_o769, 0, 25, 0)
            Call(TranslateModel, MODEL_o729, 0, 50, 0)
            Call(TranslateModel, MODEL_o730, 0, 75, 0)
            Call(TranslateModel, MODEL_o731, 0, 100, 0)
            Call(TranslateModel, MODEL_o732, 0, 125, 0)
            Call(TranslateModel, MODEL_o733, NPC_DISPOSE_LOCATION)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o525, COLLIDER_FLAGS_UPPER_MASK)
        CaseGe(STORY_CH7_SPOKE_WITH_HERRINGWAY)
            Call(EnableModel, MODEL_ana, FALSE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ana, COLLIDER_FLAGS_UPPER_MASK)
    EndSwitch
    Return
    End
};
