#include "pra_33.h"
#include "effects.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"
#include "../common/GlassShimmer.inc.c"

s32 N(RightDoorModelsL)[] = { MODEL_o874, -1 };
s32 N(RightDoorModelsR)[] = { MODEL_o876, -1 };

s32 N(LeftDoorModelsL)[] = { MODEL_o859, -1 };
s32 N(LeftDoorModelsR)[] = { MODEL_o861, -1 };

EvtScript N(EVS_ExitDoors_pra_35_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_33_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittse)
    EVT_SET(LVar2, EVT_PTR(N(RightDoorModelsL)))
    EVT_SET(LVar3, EVT_PTR(N(RightDoorModelsR)))
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_35"), pra_35_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_18_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_33_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_deilittnw)
    EVT_SET(LVar2, EVT_PTR(N(LeftDoorModelsL)))
    EVT_SET(LVar3, EVT_PTR(N(LeftDoorModelsR)))
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_18"), pra_18_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_pra_35_2) = EVT_EXIT_WALK(60, pra_33_ENTRY_2, "pra_35", pra_35_ENTRY_2);

EvtScript N(EVS_Unused) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_35_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_18_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_pra_35_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(pra_33_ENTRY_0)
            EVT_SET(LVar2, EVT_PTR(N(RightDoorModelsL)))
            EVT_SET(LVar3, EVT_PTR(N(RightDoorModelsR)))
            EVT_EXEC_WAIT(BaseEnterDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(pra_33_ENTRY_1)
            EVT_SET(LVar2, EVT_PTR(N(LeftDoorModelsL)))
            EVT_SET(LVar3, EVT_PTR(N(LeftDoorModelsR)))
            EVT_EXEC_WAIT(BaseEnterDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(pra_33_ENTRY_2)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

BombTrigger N(BombPos_Wall) = {
    .pos = { 487.0f, 0.0f, -80.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BlastWall) = {
    EVT_SET(GF_PRA33_BombedWall, TRUE)
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 2, 34, 1, 10, 30)
    EVT_CALL(EnableGroup, MODEL_g267, FALSE)
    EVT_CALL(EnableGroup, MODEL_g270, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
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
    EVT_IF_EQ(GF_PRA33_BombedWall, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BlastWall)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Wall)), 1, 0)
        EVT_CALL(EnableGroup, MODEL_g270, FALSE)
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_g267, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_SET(LVar0, MODEL_o945)
    EVT_SET(LVar1, MODEL_o987)
    EVT_SET(LVar2, TEX_PANNER_0)
    EVT_EXEC(N(EVS_GlassShimmer))
    EVT_SET(LVar0, REFLECTION_WALL_ONLY)
    EVT_SET(LVar1, GF_PRA_BrokeIllusion)
    EVT_EXEC(N(EVS_SetupReflections))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
