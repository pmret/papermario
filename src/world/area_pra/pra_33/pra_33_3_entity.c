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
    EVT_IF_EQ(AF_PRA33_FlippingWall, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(AF_PRA33_FlippingWall, TRUE)
    // set wall orientation
    EVT_IF_EQ(MV_WallFlipped, FALSE)
        EVT_SET(MV_WallFlipped, TRUE)
    EVT_ELSE
        EVT_SET(MV_WallFlipped, FALSE)
    EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o1063, SOUND_PRA_FLIP_WALL, SOUND_SPACE_DEFAULT)
    EVT_CALL(N(CheckPlayerOnDais))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1063, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(N(GetDaisRelativePlayerPos))
    // prepare the lerp
    EVT_IF_EQ(MV_WallFlipped, FALSE)
        EVT_SET(LVar2, 180)
        EVT_CALL(MakeLerp, 180, 360, 15, EASING_LINEAR)
    EVT_ELSE
        EVT_SET(LVar2, 0)
        EVT_CALL(MakeLerp, 0, 180, 15, EASING_LINEAR)
    EVT_END_IF
    // spin the dais and move the player if necessary
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g260, LVar0, 0, 1, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o1045)
        EVT_CALL(N(CheckPlayerOnDais))
        EVT_IF_EQ(LVarA, TRUE)
            EVT_SET(LVar3, LVar2)
            EVT_SUB(LVar3, LVar0)
            EVT_SET(LVar2, LVar0)
            EVT_ADD(LVar7, LVar3)
            EVT_CALL(N(UpdateDaisPlayerPos))
        EVT_END_IF
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(AF_PRA33_FlippingWall, FALSE)
    EVT_CALL(N(CheckPlayerOnDais))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1063, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_SET(GF_PRA33_Unused, FALSE)
    EVT_SET(AF_PRA33_FlippingWall, FALSE)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_RedSwitch), 310, 0, 110, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_ActivateSwitch)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_RedSwitch), 310, 0, -110, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_ActivateSwitch)))
    EVT_CALL(ParentColliderToModel, COLLIDER_o1045, MODEL_o990)
    EVT_CALL(ParentColliderToModel, COLLIDER_o1063, MODEL_o990)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1063, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};
