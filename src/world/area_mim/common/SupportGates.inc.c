#include "common.h"

EvtScript N(EVS_SetGateCameraZones) = {
    Switch(LVar1)
        CaseEq(0)
            Call(SetZoneEnabled, ZONE_north, TRUE)
            Call(SetZoneEnabled, ZONE_west, TRUE)
            Call(SetZoneEnabled, ZONE_south, TRUE)
            Call(SetZoneEnabled, ZONE_east, TRUE)
            Call(SetZoneEnabled, ZONE_higashi, FALSE)
            Call(SetZoneEnabled, ZONE_nishi, FALSE)
            Call(SetZoneEnabled, ZONE_minami, FALSE)
            Call(SetZoneEnabled, ZONE_kita, FALSE)
            Call(SetZoneEnabled, ZONE_stage, FALSE)
            Set(LVar1, 0)
        CaseEq(1)
            Call(SetZoneEnabled, ZONE_north, FALSE)
            Call(SetZoneEnabled, ZONE_west, FALSE)
            Call(SetZoneEnabled, ZONE_south, FALSE)
            Call(SetZoneEnabled, ZONE_east, FALSE)
            Call(SetZoneEnabled, ZONE_higashi, FALSE)
            Call(SetZoneEnabled, ZONE_nishi, FALSE)
            Call(SetZoneEnabled, ZONE_minami, FALSE)
            Call(SetZoneEnabled, ZONE_kita, FALSE)
            Call(SetZoneEnabled, ZONE_stage, TRUE)
            Set(LVar1, 1)
        CaseEq(2)
            Call(SetZoneEnabled, ZONE_north, FALSE)
            Call(SetZoneEnabled, ZONE_west, FALSE)
            Call(SetZoneEnabled, ZONE_south, FALSE)
            Call(SetZoneEnabled, ZONE_east, FALSE)
            Call(SetZoneEnabled, ZONE_higashi, TRUE)
            Call(SetZoneEnabled, ZONE_nishi, TRUE)
            Call(SetZoneEnabled, ZONE_minami, TRUE)
            Call(SetZoneEnabled, ZONE_kita, TRUE)
            Call(SetZoneEnabled, ZONE_stage, FALSE)
            Set(LVar1, 2)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_InitializeGates) = {
    Call(ParentColliderToModel, COLLIDER_monn, MODEL_n1)
    Call(RotateGroup, MODEL_monn, LVar2, 0, 1, 0)
    Call(UpdateColliderTransform, COLLIDER_monn)
    Call(ParentColliderToModel, COLLIDER_mons, MODEL_s1)
    Call(RotateGroup, MODEL_mons, LVar2, 0, 1, 0)
    Call(UpdateColliderTransform, COLLIDER_mons)
    Call(ParentColliderToModel, COLLIDER_mone, MODEL_e1)
    Call(RotateGroup, MODEL_mone, LVar2, 0, 1, 0)
    Call(UpdateColliderTransform, COLLIDER_mone)
    Call(ParentColliderToModel, COLLIDER_monw, MODEL_w1)
    Call(RotateGroup, MODEL_monw, LVar2, 0, 1, 0)
    Call(UpdateColliderTransform, COLLIDER_monw)
    Return
    End
};

EvtScript N(EVS_ResetGates) = {
    Call(RotateGroup, MODEL_monn, 0, 0, 1, 0)
    Call(UpdateColliderTransform, COLLIDER_monn)
    Call(RotateGroup, MODEL_mons, 0, 0, 1, 0)
    Call(UpdateColliderTransform, COLLIDER_mons)
    Call(RotateGroup, MODEL_mone, 0, 0, 1, 0)
    Call(UpdateColliderTransform, COLLIDER_mone)
    Call(RotateGroup, MODEL_monw, 0, 0, 1, 0)
    Call(UpdateColliderTransform, COLLIDER_monw)
    Return
    End
};
