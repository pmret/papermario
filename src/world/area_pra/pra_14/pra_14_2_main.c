#include "pra_14.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"
#include "../common/GlassShimmer.inc.c"

EvtScript N(EVS_ExitWalk_pra_13_1) = EVT_EXIT_WALK(60, pra_14_ENTRY_0, "pra_13", pra_13_ENTRY_1);
EvtScript N(EVS_ExitWalk_pra_13_2) = EVT_EXIT_WALK(60, pra_14_ENTRY_1, "pra_13", pra_13_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_pra_13_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_pra_13_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilinw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};

BombTrigger N(BombPos_WallA) = {
    .pos = { 13.0f, 0.0f, 70.0f },
    .radius = 0.0f
};

BombTrigger N(BombPos_WallB) = {
    .pos = { 13.0f, 0.0f, -70.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BlastWallA) = {
    EVT_CALL(EnableModel, MODEL_g289, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittsw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_PRA13_BombedWallA, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BlastWallB) = {
    EVT_CALL(EnableModel, MODEL_g260, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittnw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_PRA13_BombedWallB, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_CRYSTAL_PALACE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 24, 24, 40)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_SET(LVar0, 40)
    EVT_SET(LVar1, 40)
    EVT_SET(LVar2, TEX_PANNER_0)
    EVT_EXEC(N(EVS_GlassShimmer))
    EVT_SET(LVar0, REFLECTION_WALL_ONLY)
    EVT_SET(LVar1, TRUE) // always disable reflections in this room
    EVT_EXEC(N(EVS_SetupReflections))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_IF_EQ(GF_PRA13_BombedWallA, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BlastWallA)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_WallA)), 1, 0)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_g289, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittsw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_PRA13_BombedWallB, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BlastWallB)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_WallB)), 1, 0)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_g260, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittnw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
