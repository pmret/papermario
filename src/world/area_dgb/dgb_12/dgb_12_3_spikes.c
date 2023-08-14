#include "dgb_12.h"

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o200, .pos = { -503.0,    0.0,  -63.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_SetupSpikes) = {
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o202, SURFACE_TYPE_SPIKES)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o215, SURFACE_TYPE_SPIKES)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o216, SURFACE_TYPE_SPIKES)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
    EVT_END_THREAD
    EVT_WAIT(50)
    EVT_CALL(TranslateModel, MODEL_o190, 0, 0, 0)
    EVT_CALL(ParentColliderToModel, COLLIDER_o202, MODEL_o190)
    EVT_LOOP(0)
        EVT_THREAD
            EVT_WAIT(2)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o215, COLLIDER_FLAGS_UPPER_MASK)
        EVT_END_THREAD
        EVT_CALL(MakeLerp, 0, -35, 15, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, MODEL_o190, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o202)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(60)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o215, SOUND_SPIKES_EXTEND, SOUND_SPACE_DEFAULT)
        EVT_THREAD
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o215, COLLIDER_FLAGS_UPPER_MASK)
        EVT_END_THREAD
        EVT_CALL(MakeLerp, -35, 0, 4, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, MODEL_o190, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_o202)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(35)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
