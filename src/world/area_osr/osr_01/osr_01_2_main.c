
#include "osr_01.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_mac_01_2) = EVT_EXIT_WALK(60, osr_01_ENTRY_0, "mac_01", mac_01_ENTRY_2);
EvtScript N(EVS_ExitWalk_hos_00_0) = EVT_EXIT_WALK(60, osr_01_ENTRY_1, "hos_00", hos_00_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mac_01_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_hos_00_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Fountain) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_o501, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_w2, TEX_PANNER_2)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(    0, -200,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(    0,    0,    0,  300)
        TEX_PAN_PARAMS_FREQ(    0,    0,    0,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PEACH_CASTLE_GROUNDS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_SET(AF_OSR_01, FALSE)
    EVT_SET(GF_MAP_PeachCastleGrounds, TRUE)
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_PlaySong_Starship))
    EVT_EXEC(N(EVS_TexPan_Fountain))
    EVT_CALL(PlaySoundAtF, SOUND_LOOP_OSR_FOUNTAIN_BROKEN, SOUND_SPACE_WITH_DEPTH, 300, 2, 399)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(osr_01_ENTRY_3)
            EVT_CALL(EnableModel, MODEL_o492, FALSE)
            EVT_EXEC(N(EVS_Scene_Wishing))
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
