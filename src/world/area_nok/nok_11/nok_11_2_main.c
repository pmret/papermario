#include "nok_11.h"

EvtScript N(EVS_ExitWalk_mac_01_1) = {
    EVT_IF_EQ(GB_KootFavor_State, KOOT_FAVOR_STATE_2)
        EVT_SET(GF_KootFavor_LeftKoopaArea, TRUE)
    EVT_END_IF
    EVT_CALL(UseExitHeading, 60, nok_11_ENTRY_0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("mac_01"), mac_01_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_nok_12_0) = EVT_EXIT_WALK_NOK(60, nok_11_ENTRY_1, "nok_12", nok_12_ENTRY_0);

EvtScript N(EVS_TexPan_Flowers) = {
    EVT_CALL(SetTexPanner, MODEL_hana2, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_hana3, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_hana4, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_hana5, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_hana6, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_hana7, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_hana8, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_hana9, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_hana10, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_hanahana, TEX_PANNER_0)
    EVT_LABEL(10)
        EVT_LOOP(12)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(12)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0x4000, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Water) = {
    EVT_THREAD
        EVT_CALL(SetTexPanner, MODEL_suimen1, TEX_PANNER_1)
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LABEL(10)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_AUX, LVar1, LVar2)
            EVT_SUB(LVar0, 100)
            EVT_SUB(LVar1, 400)
            EVT_ADD(LVar1, 1000)
            EVT_WAIT(1)
            EVT_GOTO(10)
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_kabemizu, TEX_PANNER_2)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_LABEL(20)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar0, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_AUX, LVar1, LVar2)
        EVT_SUB(LVar0, 100)
        EVT_ADD(LVar1, 800)
        EVT_SUB(LVar1, 400)
        EVT_WAIT(1)
        EVT_GOTO(20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mac_01_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiri1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_nok_12_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PLEASANT_PATH)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_SET(GF_MAP_PleasantPath, TRUE)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(JrTroopaNPCs)))
    EVT_ELSE
        EVT_IF_GE(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
            EVT_IF_EQ(GF_NOK11_Defeated_KentC, FALSE)
                EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(KentCKoopaNPCs)))
            EVT_ELSE
                EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_TexPan_Flowers))
    EVT_EXEC(N(EVS_TexPan_Water))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(PlaySound, SOUND_LOOP_NOK_WATER)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
