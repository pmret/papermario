#include "kzn_09.h"

EvtScript N(EVS_ExitWalk_kzn_03_2) = EVT_EXIT_WALK(60, kzn_09_ENTRY_0, "kzn_03", kzn_03_ENTRY_2);
EvtScript N(EVS_ExitWalk_kzn_10_0) = EVT_EXIT_WALK(60, kzn_09_ENTRY_1, "kzn_10", kzn_10_ENTRY_0);
EvtScript N(EVS_ExitWalk_kzn_03_4) = EVT_EXIT_WALK(60, kzn_09_ENTRY_2, "kzn_03", kzn_03_ENTRY_4);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(N(EVS_ExitWalk_kzn_03_2), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(N(EVS_ExitWalk_kzn_10_0), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    BindTrigger(N(EVS_ExitWalk_kzn_03_4), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    Call(SetSpriteShading, SHADING_KZN_09)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Call(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    Call(PlayAmbientSounds, AMBIENT_LAVA_1)
    Set(LVar0, N(EVS_BindExitTriggers))
    Exec(EnterWalk)
    Wait(1)
    ExecWait(N(EVS_SetupZipline))
    Return
    End
};
