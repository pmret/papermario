#include "kzn_05.h"
#include "world/entrances.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    { -430.0, -259.0,   10.0,   90.0 },  /* kzn_05_ENTRY_0 */
    {  450.0,    0.0,   10.0,  270.0 },  /* kzn_05_ENTRY_1 */
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_05 },
};

#include "world/common/atomic/TexturePan.inc.c"
#include "world/common/atomic/TexturePan.data.inc.c"

EvtScript N(EVS_StartTexPanner3) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, TEX_PANNER_3)
    EVT_THREAD
        EVT_SET(LVar0, TEX_PANNER_3)
        EVT_SET(LVar1, -200)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 600)
        EVT_SET(LVar4, -400)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, 1)
        EVT_SET(LVar8, 1)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartTexPanner4) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, TEX_PANNER_4)
    EVT_THREAD
        EVT_SET(LVar0, TEX_PANNER_4)
        EVT_SET(LVar1, 500)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, -400)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 1)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_kzn_06) = EXIT_WALK_SCRIPT(60,  kzn_05_ENTRY_0, "kzn_06",  kzn_06_ENTRY_0);

EvtScript N(EVS_ExitWalk_kzn_03) = EXIT_WALK_SCRIPT(60,  kzn_05_ENTRY_1, "kzn_03",  kzn_03_ENTRY_3);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_06), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_03), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_05)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_UNDER_SEA1)
    EVT_SET(LVar0, MODEL_kem1)
    EVT_EXEC(N(EVS_StartTexPanner3))
    EVT_RETURN
    EVT_END
};
