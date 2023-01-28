#include "common.h"

EvtScript N(EVS_SetGateCameraZones) = {
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(SetZoneEnabled, ZONE_north, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_west, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_south, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_east, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_higashi, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_nishi, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_minami, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_kita, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_stage, FALSE)
            EVT_SET(LVar1, 0)
        EVT_CASE_EQ(1)
            EVT_CALL(SetZoneEnabled, ZONE_north, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_west, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_south, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_east, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_higashi, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_nishi, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_minami, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_kita, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_stage, TRUE)
            EVT_SET(LVar1, 1)
        EVT_CASE_EQ(2)
            EVT_CALL(SetZoneEnabled, ZONE_north, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_west, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_south, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_east, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_higashi, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_nishi, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_minami, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_kita, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_stage, FALSE)
            EVT_SET(LVar1, 2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InitializeGates) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_monn, MODEL_n1)
    EVT_CALL(RotateGroup, MODEL_monn, LVar2, 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_monn)
    EVT_CALL(ParentColliderToModel, COLLIDER_mons, MODEL_s1)
    EVT_CALL(RotateGroup, MODEL_mons, LVar2, 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_mons)
    EVT_CALL(ParentColliderToModel, COLLIDER_mone, MODEL_e1)
    EVT_CALL(RotateGroup, MODEL_mone, LVar2, 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_mone)
    EVT_CALL(ParentColliderToModel, COLLIDER_monw, MODEL_w1)
    EVT_CALL(RotateGroup, MODEL_monw, LVar2, 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_monw)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ResetGates) = {
    EVT_CALL(RotateGroup, MODEL_monn, 0, 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_monn)
    EVT_CALL(RotateGroup, MODEL_mons, 0, 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_mons)
    EVT_CALL(RotateGroup, MODEL_mone, 0, 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_mone)
    EVT_CALL(RotateGroup, MODEL_monw, 0, 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_monw)
    EVT_RETURN
    EVT_END
};
