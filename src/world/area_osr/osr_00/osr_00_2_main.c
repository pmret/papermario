#include "osr_00.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(CreateSunshine)) {
    fx_sun(FX_SUN_FROM_RIGHT, 0.0f, 0.0f, 0.0f, 0.0f, 0);
    return ApiStatus_DONE2;
}

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_mac_01_2) = EVT_EXIT_WALK(60, osr_00_ENTRY_0, "mac_01", mac_01_ENTRY_2);
EvtScript N(EVS_ExitDoors_kkj_00_6) = EVT_EXIT_DOUBLE_DOOR(osr_00_ENTRY_2, "kkj_00", kkj_00_ENTRY_6, COLLIDER_deilitn, MODEL_d2, MODEL_d1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mac_01_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_00_6)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitn, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(osr_00_ENTRY_2)
            EVT_SET(LVar2, MODEL_d2)
            EVT_SET(LVar3, MODEL_d1)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(osr_00_ENTRY_3)
            EVT_EXEC(N(EVS_Scene_ShowInvitation))
        EVT_CASE_EQ(osr_00_ENTRY_4)
            EVT_EXEC(N(EVS_Scene_ApproachParty))
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Fountain) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_fw1, TEX_PANNER_1)
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
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_INTRO)
            EVT_CALL(N(CreateSunshine))
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(IntroNPCs)))
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_CALL(N(SpawnSunEffect))
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(EpilogueNPCs)))
    EVT_END_SWITCH
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, osr_00_ENTRY_3)
        EVT_EXEC(N(EVS_SetupMusic))
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, osr_00_ENTRY_3)
        EVT_EXEC(N(EVS_TexPan_Fountain))
        EVT_CALL(PlaySoundAtF, SOUND_LOOP_OSR_FOUNTAIN_INTACT, SOUND_SPACE_WITH_DEPTH, 300, 0, 400)
    EVT_END_IF
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
