#include "kzn_04.h"

#include "../common/SmokeTexPanners.inc.c"

EvtScript N(EVS_ExitWalk_kzn_03_1) = EVT_EXIT_WALK(60, kzn_04_ENTRY_0, "kzn_03", kzn_03_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kzn_03_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    Call(SetSpriteShading, SHADING_KZN_04)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Call(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    Call(PlayAmbientSounds, AMBIENT_LAVA_1)
    Set(LVar0, MODEL_kem1)
    Exec(N(EVS_StartTexPanner_SmokeLeft))
    Set(LVar0, MODEL_kem2)
    Exec(N(EVS_StartTexPanner_SmokeRight))
    Return
    End
};

