#include "pra_14.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"
#include "../common/GlassShimmer.inc.c"

EvtScript N(EVS_ExitWalk_pra_13_1) = EVT_EXIT_WALK(60, pra_14_ENTRY_0, "pra_13", pra_13_ENTRY_1);
EvtScript N(EVS_ExitWalk_pra_13_2) = EVT_EXIT_WALK(60, pra_14_ENTRY_1, "pra_13", pra_13_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_pra_13_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_pra_13_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilinw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Return
    End
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
    Call(EnableModel, MODEL_g289, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittsw, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_PRA13_BombedWallA, TRUE)
    Unbind
    Return
    End
};

EvtScript N(EVS_BlastWallB) = {
    Call(EnableModel, MODEL_g260, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittnw, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_PRA13_BombedWallB, TRUE)
    Unbind
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_CRYSTAL_PALACE)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    Call(SetCamBGColor, CAM_DEFAULT, 24, 24, 40)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(SetCamEnabled, CAM_DEFAULT, TRUE)
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Set(LVar0, 40)
    Set(LVar1, 40)
    Set(LVar2, TEX_PANNER_0)
    Exec(N(EVS_GlassShimmer))
    Set(LVar0, REFLECTION_WALL_ONLY)
    Set(LVar1, TRUE) // always disable reflections in this room
    Exec(N(EVS_SetupReflections))
    Exec(N(EVS_EnterMap))
    Wait(1)
    IfEq(GF_PRA13_BombedWallA, FALSE)
        BindTrigger(Ref(N(EVS_BlastWallA)), TRIGGER_POINT_BOMB, Ref(N(BombPos_WallA)), 1, 0)
    Else
        Call(EnableModel, MODEL_g289, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittsw, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfEq(GF_PRA13_BombedWallB, FALSE)
        BindTrigger(Ref(N(EVS_BlastWallB)), TRIGGER_POINT_BOMB, Ref(N(BombPos_WallB)), 1, 0)
    Else
        Call(EnableModel, MODEL_g260, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittnw, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};
