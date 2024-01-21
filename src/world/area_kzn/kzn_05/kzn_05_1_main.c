#include "kzn_05.h"

#include "../common/SmokeTexPanners.inc.c"

EvtScript N(EVS_ExitWalk_kzn_06_0) = EVT_EXIT_WALK(60, kzn_05_ENTRY_0, "kzn_06", kzn_06_ENTRY_0);
EvtScript N(EVS_ExitWalk_kzn_03_1) = EVT_EXIT_WALK(60, kzn_05_ENTRY_1, "kzn_03", kzn_03_ENTRY_3);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(N(EVS_ExitWalk_kzn_06_0), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(N(EVS_ExitWalk_kzn_03_1), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    Call(SetSpriteShading, SHADING_KZN_05)
    SetUP_CAMERA_DEFAULT()
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Call(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    Call(PlayAmbientSounds, AMBIENT_LAVA_1)
    Set(LVar0, MODEL_kem1)
    Exec(N(EVS_StartTexPanner_SmokeLeft))
    Return
    End
};
