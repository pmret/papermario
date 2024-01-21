#include "trd_07.h"

extern EvtScript N(EVS_SetupMagicDoors);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_trd_08_0) = EVT_EXIT_WALK(60, trd_07_ENTRY_1, "trd_08", trd_08_ENTRY_0);
EvtScript N(EVS_ExitWalk_trd_04_4) = EVT_EXIT_WALK(60, trd_07_ENTRY_0, "trd_04", trd_04_ENTRY_4);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_trd_08_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_trd_04_4)), TRIGGER_FLOOR_ABOVE, COLLIDER_tte, 1, 0)
    Return
    End
};

EvtScript N(EVS_TexPan_1) = {
    SetGroup(EVT_GROUP_00)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Label(10)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_AUX, LVar1, 0)
        Add(LVar0, 100)
        Sub(LVar1, 100)
        Wait(1)
        Goto(10)
        Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_KOOPA_BROS_FORTRESS)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_TexPan_1))
    ExecWait(N(EVS_SetupMagicDoors))
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    ExecGetTID(EnterWalk, MV_EnterWalkScriptID)
    Wait(1)
    Call(EnableTexPanning, MODEL_suimen2, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(    0,   90,  -60,  -70)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};
