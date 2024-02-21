#include "dgb_12.h"

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o200, .pos = { -503.0,    0.0,  -63.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_SetupSpikes) = {
    SetGroup(EVT_GROUP_EF)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o202, SURFACE_TYPE_SPIKES)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o215, SURFACE_TYPE_SPIKES)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o216, SURFACE_TYPE_SPIKES)
    Thread
        Call(ResetFromLava, Ref(N(SafeFloorColliders)))
    EndThread
    Wait(50)
    Call(TranslateModel, MODEL_o190, 0, 0, 0)
    Call(ParentColliderToModel, COLLIDER_o202, MODEL_o190)
    Loop(0)
        Thread
            Wait(2)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o215, COLLIDER_FLAGS_UPPER_MASK)
        EndThread
        Call(MakeLerp, 0, -35, 15, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateModel, MODEL_o190, 0, LVar0, 0)
            Call(UpdateColliderTransform, COLLIDER_o202)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(60)
        Call(PlaySoundAtCollider, COLLIDER_o215, SOUND_SPIKES_EXTEND, SOUND_SPACE_DEFAULT)
        Thread
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o215, COLLIDER_FLAGS_UPPER_MASK)
        EndThread
        Call(MakeLerp, -35, 0, 4, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateModel, MODEL_o190, 0, LVar0, 0)
            Call(UpdateColliderTransform, COLLIDER_o202)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(35)
    EndLoop
    Return
    End
};
