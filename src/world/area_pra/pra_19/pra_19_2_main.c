#include "pra_19.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"
#include "../common/GlassShimmer.inc.c"

s32 N(DoorModelsL)[] = { MODEL_o772, MODEL_o844, -1 };
s32 N(DoorModelsR)[] = { MODEL_o768, MODEL_o846, -1 };

EvtScript N(EVS_ExitDoor_pra_35_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_19_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittsw)
    EVT_SET(LVar2, EVT_PTR(N(DoorModelsL)))
    EVT_SET(LVar3, EVT_PTR(N(DoorModelsR)))
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_35"), pra_35_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_pra_20_0) = EVT_EXIT_WALK(60, pra_19_ENTRY_1, "pra_20", pra_20_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_pra_35_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_KOOPER_DUPLIGHOSTS)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_pra_20_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(pra_19_ENTRY_0)
            EVT_SET(LVar2, EVT_PTR(N(DoorModelsL)))
            EVT_SET(LVar3, EVT_PTR(N(DoorModelsR)))
            EVT_EXEC_WAIT(BaseEnterDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(pra_19_ENTRY_1)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
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
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_KOOPER_DUPLIGHOSTS)
        EVT_CALL(EnableModel, MODEL_o1024, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1054, COLLIDER_FLAGS_UPPER_MASK)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_o1026, FALSE)
    EVT_END_IF
    EVT_SET(LVar0, MODEL_o945)
    EVT_SET(LVar1, MODEL_o947)
    EVT_SET(LVar2, TEX_PANNER_0)
    EVT_EXEC(N(EVS_GlassShimmer))
    EVT_SET(LVar0, REFLECTION_FLOOR_WALL)
    EVT_SET(LVar1, TRUE) // disable reflections in this room
    EVT_EXEC(N(EVS_SetupReflections))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
