#include "tik_21.h"

#include "world/common/atomic/TexturePan.inc.c"

#include "world/common/entity/Pipe.inc.c"

EvtScript N(EVS_ExitWalk_tik_20_1) = EVT_EXIT_WALK(60, tik_21_ENTRY_0, "tik_20", tik_20_ENTRY_1);

EvtScript N(EVS_ExitDoors_tik_22_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, tik_21_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_tte)
    EVT_SET(LVar2, MODEL_o46)
    EVT_SET(LVar3, MODEL_o47)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("tik_22"), tik_22_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_tik_14_0) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_14"), tik_14_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitPipe_tik_14_0) = EVT_EXIT_PIPE_VERTICAL(tik_21_ENTRY_2, COLLIDER_o49, N(EVS_GotoMap_tik_14_0));

EvtScript N(EVS_ShowMessage_DoorLocked) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0177, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tik_20_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_INVITED_TO_STARBORN_VALLEY)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_tik_22_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShowMessage_DoorLocked)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_tik_14_0)), TRIGGER_FLOOR_TOUCH, COLLIDER_o49, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(tik_21_ENTRY_0)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(tik_21_ENTRY_1)
            EVT_SET(LVar2, MODEL_o46)
            EVT_SET(LVar3, MODEL_o47)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(tik_21_ENTRY_2)
            EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

#define DROPLET_MODEL MODEL_sizuku
#include "../common/DripVolumes.inc.c"

DripVolumeList N(DripVolumes) = {
    .count = 2,
    .volumes = {
        {
            .minPos = { -320,  -19 },
            .maxPos = {   60,   46 },
            .startY = 200,
            .endY   = -20,
            .duration = 60,
            .density  = 2,
        },
        {
            .minPos = {  233, -100 },
            .maxPos = {   45,  235 },
            .startY = 200,
            .endY   = -20,
            .duration = 60,
            .density  = 1,
        }
    }
};

EvtScript N(EVS_SetupDrips) = {
    EVT_SET(LVar0, EVT_PTR(N(DripVolumes)))
    EVT_EXEC(N(EVS_CreateDripVolumes))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    EVT_CALL(SetSpriteShading, SHADING_TIK_21)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_EXEC(N(EVS_SetupDrips))
    EVT_CALL(SetTexPanner, MODEL_mizu, 0)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(    0, -200, -100, -500)
        TEX_PAN_PARAMS_FREQ(    0,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
