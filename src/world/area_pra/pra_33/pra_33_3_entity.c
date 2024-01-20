#include "pra_33.h"
#include "entity.h"

API_CALLABLE(N(CheckPlayerOnDais)) {
    script->varTable[10] = 0;
    if (gCollisionStatus.curFloor == COLLIDER_o1045) {
        script->varTable[10] = 1;
    }
    if (gCollisionStatus.lastTouchedFloor == COLLIDER_o1045) {
        script->varTable[10] = 1;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetDaisRelativePlayerPos)) {
    script->varTable[6] = dist2D(200.0f, 0.0f, gPlayerStatus.pos.x, gPlayerStatus.pos.z);
    script->varTable[7] = atan2(200.0f, 0.0f, gPlayerStatus.pos.x, gPlayerStatus.pos.z);
    script->varTable[7] = clamp_angle(script->varTable[7]);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UpdateDaisPlayerPos)) {
    f32 sinTheta, cosTheta;

    sin_cos_deg(script->varTable[7], &sinTheta, &cosTheta);
    gPlayerStatus.pos.x = (script->varTable[6] * sinTheta) + 200.0f;
    gPlayerStatus.pos.z = (script->varTable[6] * -cosTheta) + 0.0f;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ActivateSwitch) = {
    IfEq(AF_PRA33_FlippingWall, TRUE)
        Return
    EndIf
    Set(AF_PRA33_FlippingWall, TRUE)
    // set wall orientation
    IfEq(MV_WallFlipped, FALSE)
        Set(MV_WallFlipped, TRUE)
    Else
        Set(MV_WallFlipped, FALSE)
    EndIf
    Call(PlaySoundAtCollider, COLLIDER_o1063, SOUND_PRA_FLIP_WALL, SOUND_SPACE_DEFAULT)
    Call(N(CheckPlayerOnDais))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1063, COLLIDER_FLAGS_UPPER_MASK)
    Call(N(GetDaisRelativePlayerPos))
    // prepare the lerp
    IfEq(MV_WallFlipped, FALSE)
        Set(LVar2, 180)
        Call(MakeLerp, 180, 360, 15, EASING_LINEAR)
    Else
        Set(LVar2, 0)
        Call(MakeLerp, 0, 180, 15, EASING_LINEAR)
    EndIf
    // spin the dais and move the player if necessary
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_g260, LVar0, 0, 1, 0)
        Call(UpdateColliderTransform, COLLIDER_o1045)
        Call(N(CheckPlayerOnDais))
        IfEq(LVarA, TRUE)
            Set(LVar3, LVar2)
            Sub(LVar3, LVar0)
            Set(LVar2, LVar0)
            Add(LVar7, LVar3)
            Call(N(UpdateDaisPlayerPos))
        EndIf
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Set(AF_PRA33_FlippingWall, FALSE)
    Call(N(CheckPlayerOnDais))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1063, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Set(GF_PRA33_Unused, FALSE)
    Set(AF_PRA33_FlippingWall, FALSE)
    Call(MakeEntity, Ref(Entity_RedSwitch), 310, 0, 110, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_ActivateSwitch)))
    Call(MakeEntity, Ref(Entity_RedSwitch), 310, 0, -110, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_ActivateSwitch)))
    Call(ParentColliderToModel, COLLIDER_o1045, MODEL_o990)
    Call(ParentColliderToModel, COLLIDER_o1063, MODEL_o990)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1063, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};
