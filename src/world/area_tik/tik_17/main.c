#include "tik_17.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_GotoMap_sam_02_2) = {
    IfEq(GF_StartedChapter7, FALSE)
        Set(GF_StartedChapter7, TRUE)
        Call(FadeOutMusic, 0, 1500)
        Call(GotoMapSpecial, Ref("kmr_22"), kmr_22_ENTRY_7, TRANSITION_BEGIN_OR_END_CHAPTER)
        Wait(100)
        Return
    EndIf
    Call(GotoMap, Ref("sam_02"), sam_02_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitPipe_sam_02_2) = EVT_EXIT_PIPE_HORIZONTAL(tik_17_ENTRY_1, COLLIDER_o105, N(EVS_GotoMap_sam_02_2));

EvtScript N(EVS_GotoMap_tik_22_1) = {
    Call(GotoMap, Ref("tik_22"), tik_22_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitPipe_tik_22_1) = EVT_EXIT_PIPE_VERTICAL(tik_17_ENTRY_0, COLLIDER_o58, N(EVS_GotoMap_tik_22_1));

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitPipe_sam_02_2)), TRIGGER_WALL_PUSH, COLLIDER_o105, 1, 0)
    BindTrigger(Ref(N(EVS_ExitPipe_tik_22_1)), TRIGGER_FLOOR_TOUCH, COLLIDER_o58, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Wait(1)
    Call(GetEntryID, LVar0)
    IfNe(LVar0, tik_17_ENTRY_0)
        EVT_ENTER_PIPE_HORIZONTAL(COLLIDER_o105, N(EVS_BindExitTriggers))
    Else
        EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
    EndIf
    Wait(1)
    Call(SetTexPanner, MODEL_kiri, TEX_PANNER_1)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( -300,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};
