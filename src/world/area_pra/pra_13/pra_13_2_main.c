#include "pra_13.h"
#include "effects.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"

#include "../common/GlassShimmer.inc.c"

s32 N(NearLeftDoorModelsL)[] = { MODEL_o772, MODEL_o844, -1 };
s32 N(NearLeftDoorModelsR)[] = { MODEL_o768, MODEL_o846, -1 };

s32 N(FarLeftDoorModelsL)[] = { MODEL_o859, MODEL_o860, -1 };
s32 N(FarLeftDoorModelsR)[] = { MODEL_o861, MODEL_o862, -1 };

s32 N(BothLeftDoorModelsL)[] = { MODEL_o772, MODEL_o844, MODEL_o859, MODEL_o860, -1 };
s32 N(BothLeftDoorModelsR)[] = { MODEL_o768, MODEL_o846, MODEL_o861, MODEL_o862, -1 };

EvtScript N(EVS_ExitDoors_pra_02_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 20)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(BothLeftDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(BothLeftDoorModelsR)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(NearLeftDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(NearLeftDoorModelsR)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_02"), pra_02_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_pra_14_0) = EVT_EXIT_WALK(60, pra_13_ENTRY_1, "pra_14", pra_14_ENTRY_0);

EvtScript N(EVS_Unused_1) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_pra_14_1) = EVT_EXIT_WALK(60, pra_13_ENTRY_2, "pra_14", pra_14_ENTRY_1);

EvtScript N(EVS_Unused_2) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_02_3) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, 3)
    EVT_SET(LVar1, 24)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(BothLeftDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(BothLeftDoorModelsR)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(FarLeftDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(FarLeftDoorModelsR)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_02"), pra_02_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_02_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_pra_14_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_pra_14_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_02_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(pra_13_ENTRY_0)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(BothLeftDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BothLeftDoorModelsR)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(NearLeftDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(NearLeftDoorModelsR)))
            EVT_END_IF
            EVT_EXEC_WAIT(BaseEnterDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(pra_13_ENTRY_1)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(pra_13_ENTRY_2)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(pra_13_ENTRY_3)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(BothLeftDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BothLeftDoorModelsR)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(FarLeftDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(FarLeftDoorModelsR)))
            EVT_END_IF
            EVT_EXEC_WAIT(BaseEnterDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

BombTrigger N(BombPos_NearWall) = {
    .pos = { 487.0f, 0.0f, 80.0f },
    .radius = 0.0f
};

BombTrigger N(BombPos_FarWall) = {
    .pos = { 487.0f, 0.0f, -80.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BlastWall_Near) = {
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 50, 34, 1, 10, 30)
    EVT_CALL(EnableModel, MODEL_g260, FALSE)
    EVT_CALL(EnableModel, MODEL_g265, FALSE)
    EVT_CALL(EnableModel, MODEL_o952, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittse, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_PRA13_BombedWallA, TRUE)
    EVT_SET(GF_PRA_BrokeIllusion, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BlastWall_Far) = {
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 65, 34, 1, 10, 30)
    EVT_CALL(EnableModel, MODEL_g289, FALSE)
    EVT_CALL(EnableModel, MODEL_g290, FALSE)
    EVT_CALL(EnableModel, MODEL_o1009, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
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
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_SET(LVar0, MODEL_o945)
    EVT_SET(LVar1, MODEL_o947)
    EVT_SET(LVar2, 0)
    EVT_EXEC(N(EVS_GlassShimmer))
    EVT_SET(LVar0, REFLECTION_FLOOR_WALL)
    EVT_SET(LVar1, GF_PRA_BrokeIllusion)
    EVT_EXEC(N(EVS_SetupReflections))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_IF_EQ(GF_PRA13_BombedWallA, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BlastWall_Near)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_NearWall)), 1, 0)
        EVT_CALL(EnableModel, MODEL_o952, FALSE)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_g260, FALSE)
        EVT_CALL(EnableModel, MODEL_g265, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittse, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_PRA13_BombedWallB, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BlastWall_Far)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_FarWall)), 1, 0)
        EVT_CALL(EnableModel, MODEL_o1009, FALSE)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_g289, FALSE)
        EVT_CALL(EnableModel, MODEL_g290, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
