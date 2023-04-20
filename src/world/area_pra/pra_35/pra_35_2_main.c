#include "pra_35.h"

#include "../common/GlassShimmer.inc.c"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"

s32 N(LeftDoorModelsL)[] = { MODEL_o772, MODEL_o844, -1 };
s32 N(LeftDoorModelsR)[] = { MODEL_o768, MODEL_o846, -1 };

s32 N(RightDoorModelsL)[] = { MODEL_o861, MODEL_o862, -1 };
s32 N(RightDoorModelsR)[] = { MODEL_o859, MODEL_o860, -1 };

EvtScript N(EVS_ExitWalk_pra_33_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_35_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittsw)
    EVT_SET(LVar2, EVT_PTR(N(LeftDoorModelsL)))
    EVT_SET(LVar3, EVT_PTR(N(LeftDoorModelsR)))
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_33"), pra_33_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_pra_19_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_35_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_deilittsw)
    EVT_SET(LVar2, EVT_PTR(N(RightDoorModelsL)))
    EVT_SET(LVar3, EVT_PTR(N(RightDoorModelsR)))
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_19"), pra_19_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_pra_33_2) = EVT_EXIT_WALK(60, pra_35_ENTRY_2, "pra_33", pra_33_ENTRY_2);

EvtScript N(EVS_Unused) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_pra_33_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_pra_19_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_pra_33_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilinw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(pra_35_ENTRY_0)
            EVT_SET(LVar2, EVT_PTR(N(LeftDoorModelsL)))
            EVT_SET(LVar3, EVT_PTR(N(LeftDoorModelsR)))
            EVT_EXEC_WAIT(BaseEnterDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(pra_35_ENTRY_1)
            EVT_SET(LVar2, EVT_PTR(N(RightDoorModelsL)))
            EVT_SET(LVar3, EVT_PTR(N(RightDoorModelsR)))
            EVT_EXEC_WAIT(BaseEnterDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(pra_35_ENTRY_2)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

BombTrigger N(D_802432A8_D904F8) = {
    .pos = { 13.0f, 0.0f, -80.0f },
    .radius = 0.0f
};

EvtScript N(D_802432B8_D90508) = {
    EVT_CALL(EnableGroup, MODEL_g297, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittnw, COLLIDER_FLAGS_UPPER_MASK)
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
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_SET(LVar0, 64)
    EVT_SET(LVar1, 65)
    EVT_SET(LVar2, 0)
    EVT_EXEC(N(EVS_GlassShimmer))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_IF_EQ(GF_PRA33_BombedWall, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(D_802432B8_D90508)), TRIGGER_POINT_BOMB, EVT_PTR(N(D_802432A8_D904F8)), 1, 0)
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_g297, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittnw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, GF_PRA_BrokeIllusion)
    EVT_EXEC(N(EVS_SetupReflections))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
