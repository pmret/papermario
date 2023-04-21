#include "pra_09.h"
#include "effects.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"

EvtScript N(EVS_ExitDoors_pra_03_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_09_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittsw)
    EVT_SET(LVar2, MODEL_o772)
    EVT_SET(LVar3, MODEL_o768)
    EVT_SET(LVar4, MODEL_o844)
    EVT_SET(LVar5, MODEL_o846)
    EVT_EXEC(ExitSplitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_03"), pra_03_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_pra_11_0) = EVT_EXIT_WALK(60, pra_09_ENTRY_1, "pra_11", pra_11_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_03_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_BOMBETTE_DUPLIGHOSTS)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_pra_11_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(pra_09_ENTRY_0)
            EVT_SET(LVar2, MODEL_o772)
            EVT_SET(LVar3, MODEL_o768)
            EVT_SET(LVar4, MODEL_o844)
            EVT_SET(LVar5, MODEL_o846)
            EVT_EXEC_WAIT(EnterSplitDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(pra_09_ENTRY_1)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

BombTrigger N(BombPos_Wall) = {
    .pos = { 487.0f, 0.0f, 80.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BlastWall) = {
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 38, 30, 1, 10, 30)
    EVT_CALL(EnableModel, MODEL_g260, FALSE)
    EVT_CALL(EnableModel, MODEL_g265, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittse, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(EnableModel, MODEL_o952, TRUE)
    EVT_SET(GF_PRA09_BombedWall, TRUE)
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
    EVT_IF_EQ(GF_PRA09_BombedWall, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BlastWall)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Wall)), 1, 0)
        EVT_CALL(EnableModel, MODEL_o952, FALSE)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_g260, FALSE)
        EVT_CALL(EnableModel, MODEL_g265, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittse, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_SET(LVar0, 1)
    EVT_SET(LVar1, GF_PRA_BrokeIllusion)
    EVT_EXEC(N(EVS_SetupReflections))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
