#include "kzn_03.h"
#include "entity.h"

#include "../common/SmokeTexPanners.inc.c"

EvtScript N(EVS_ExitWalk_kzn_02_1) = EVT_EXIT_WALK(60, kzn_03_ENTRY_0, "kzn_02", kzn_02_ENTRY_1);
EvtScript N(EVS_ExitWalk_kzn_04_0) = EVT_EXIT_WALK(60, kzn_03_ENTRY_1, "kzn_04", kzn_04_ENTRY_0);
EvtScript N(EVS_ExitWalk_kzn_09_0) = EVT_EXIT_WALK(60, kzn_03_ENTRY_2, "kzn_09", kzn_09_ENTRY_0);
EvtScript N(EVS_ExitWalk_kzn_05_1) = EVT_EXIT_WALK(60, kzn_03_ENTRY_3, "kzn_05", kzn_05_ENTRY_1);
EvtScript N(EVS_ExitWalk_kzn_09_2) = EVT_EXIT_WALK(60, kzn_03_ENTRY_4, "kzn_09", kzn_09_ENTRY_2);

EvtScript N(EVS_BindTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kzn_02_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kzn_04_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kzn_09_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kzn_05_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili4, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kzn_09_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili5, 1, 0)
    Return
    End
};

EvtScript N(EVS_StartTexPanners_Lava) = {
    SetGroup(EVT_GROUP_00)
    Call(EnableTexPanning, MODEL_o112, TRUE)
    Call(EnableTexPanning, MODEL_o151, TRUE)
    Call(EnableTexPanning, MODEL_toro, TRUE)
    Call(EnableTexPanning, MODEL_poko, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  400,    0,  800,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_5)
        TEX_PAN_PARAMS_STEP(  300, -500,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        // animate lava bubbles (real ones, not the enemies)
        Set(LVar0, 0)
        Loop(0)
            Call(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, LVar0, 0)
            Add(LVar0, 0x8000)
            Wait(6)
        EndLoop
    EndThread
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    Call(SetSpriteShading, SHADING_KZN_03)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindTriggers))
    Else
        Set(LVar0, Ref(N(EVS_BindTriggers)))
        Exec(EnterWalk)
    EndIf
    Wait(1)
    Call(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    Call(PlayAmbientSounds, AMBIENT_LAVA_1)
    Exec(N(EVS_StartTexPanners_Lava))
    Set(LVar0, MODEL_kem1)
    Exec(N(EVS_StartTexPanner_SmokeLeft))
    Set(LVar0, MODEL_kem2)
    Exec(N(EVS_StartTexPanner_SmokeRight))
    ExecWait(N(EVS_SetupZiplines))
    Return
    End
};
