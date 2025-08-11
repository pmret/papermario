#include "tik_06.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_tik_01_0) = EVT_EXIT_WALK(60, tik_06_ENTRY_0, "tik_01", tik_01_ENTRY_0);
EvtScript N(EVS_ExitWalk_tik_18_0) = EVT_EXIT_WALK(60, tik_06_ENTRY_1, "tik_18", tik_18_ENTRY_0);

EvtScript N(EVS_GotoMap_mac_02_4) = {
    Call(GotoMap, Ref("mac_02"), mac_02_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_OnEnterPipe_Upward) = EVT_EXIT_PIPE_HORIZONTAL(tik_06_ENTRY_3,
    COLLIDER_o89, N(EVS_GotoMap_mac_02_4));

EvtScript N(EVS_GotoMap_tik_08_3) = {
    Call(GotoMap, Ref("tik_08"), tik_08_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_OnEnterPipe_Downward) = EVT_EXIT_PIPE_VERTICAL(tik_06_ENTRY_2,
    COLLIDER_o57, N(EVS_GotoMap_tik_08_3));

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_tik_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_tik_18_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_OnEnterPipe_Upward)), TRIGGER_WALL_PUSH, COLLIDER_o89, 1, 0)
    BindTrigger(Ref(N(EVS_OnEnterPipe_Downward)), TRIGGER_FLOOR_TOUCH, COLLIDER_o57, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(tik_06_ENTRY_2)
            Set(LVarA, Ref(N(EVS_BindExitTriggers)))
            Exec(N(EVS_Pipe_EnterVertical))
        CaseEq(tik_06_ENTRY_3)
            Set(LVarA, Ref(N(EVS_BindExitTriggers)))
            Set(LVarB, COLLIDER_o89)
            Exec(N(EVS_Pipe_EnterHorizontal))
        CaseDefault
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    Call(SetSpriteShading, SHADING_TIK_06)
    SetUP_CAMERA_NO_LEAD()
    Set(GF_MAP_ToadTownTunnels, true)
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Call(PlaySound, SOUND_LOOP_TIK06_WATER)
    Call(PlaySoundAtF, SOUND_LOOP_TIK06_FLOW2, SOUND_SPACE_WITH_DEPTH, -85, -180, 120)
    Call(PlaySoundAtF, SOUND_LOOP_TIK06_FLOW3, SOUND_SPACE_WITH_DEPTH, -25, -140, -130)
    Call(PlaySoundAtF, SOUND_LOOP_TIK06_FLOW4, SOUND_SPACE_WITH_DEPTH, -35, -180, 130)
    Exec(N(EVS_SetupDrips))
    Call(EnableTexPanning, MODEL_nagare1, true)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   50,  200,  110,  500)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(EnableTexPanning, MODEL_mizu, true)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(    0, -200, -100, -500)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(EnableTexPanning, MODEL_mizu2, true)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(    0, -250, -100, -500)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(EnableTexPanning, MODEL_taki, true)
    Call(EnableTexPanning, MODEL_o72, true)
    Call(EnableTexPanning, MODEL_o73, true)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(  -50, -900,  -70,-1200)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Set(GF_MAC01_RowfBadgesChosen, false)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
