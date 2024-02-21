#include "tik_21.h"

#include "world/common/atomic/TexturePan.inc.c"

#include "world/common/entity/Pipe.inc.c"

EvtScript N(EVS_ExitWalk_tik_20_1) = EVT_EXIT_WALK(60, tik_21_ENTRY_0, "tik_20", tik_20_ENTRY_1);

EvtScript N(EVS_ExitDoors_tik_22_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, tik_21_ENTRY_1)
    Set(LVar1, COLLIDER_tte)
    Set(LVar2, MODEL_o46)
    Set(LVar3, MODEL_o47)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("tik_22"), tik_22_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_GotoMap_tik_14_0) = {
    Call(GotoMap, Ref("tik_14"), tik_14_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitPipe_tik_14_0) = EVT_EXIT_PIPE_VERTICAL(tik_21_ENTRY_2, COLLIDER_o49, N(EVS_GotoMap_tik_14_0));

EvtScript N(EVS_ShowMessage_DoorLocked) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Menus_0177, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_tik_20_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    IfGe(GB_StoryProgress, STORY_CH7_INVITED_TO_STARBORN_VALLEY)
        BindTrigger(Ref(N(EVS_ExitDoors_tik_22_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    Else
        BindTrigger(Ref(N(EVS_ShowMessage_DoorLocked)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EndIf
    BindTrigger(Ref(N(EVS_ExitPipe_tik_14_0)), TRIGGER_FLOOR_TOUCH, COLLIDER_o49, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(tik_21_ENTRY_0)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(tik_21_ENTRY_1)
            Set(LVar2, MODEL_o46)
            Set(LVar3, MODEL_o47)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(tik_21_ENTRY_2)
            EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
    EndSwitch
    Wait(1)
    Return
    End
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
    Set(LVar0, Ref(N(DripVolumes)))
    Exec(N(EVS_CreateDripVolumes))
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    Call(SetSpriteShading, SHADING_TIK_21)
    SetUP_CAMERA_NO_LEAD()
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Exec(N(EVS_SetupDrips))
    Call(SetTexPanner, MODEL_mizu, 0)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(    0, -200, -100, -500)
        TEX_PAN_PARAMS_FREQ(    0,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Wait(1)
    Exec(N(EVS_EnterMap))
    Return
    End
};
