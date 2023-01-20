#include "nok_11.h"

EvtScript N(D_80242010_9F6A50) = {
    EVT_IF_EQ(GB_KootFavor_State, 2)
        EVT_SET(GF_KootFavor_LeftKoopaArea, TRUE)
    EVT_END_IF
    EVT_CALL(UseExitHeading, 60, nok_11_ENTRY_0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("mac_01"), mac_01_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242088_9F6AC8) = {
    EVT_CALL(UseExitHeading, 60, nok_11_ENTRY_1)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("nok_12"), nok_12_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802420D8_9F6B18) = {
    EVT_CALL(SetTexPanner, MODEL_hana2, 0)
    EVT_CALL(SetTexPanner, MODEL_hana3, 0)
    EVT_CALL(SetTexPanner, MODEL_hana4, 0)
    EVT_CALL(SetTexPanner, MODEL_hana5, 0)
    EVT_CALL(SetTexPanner, MODEL_hana6, 0)
    EVT_CALL(SetTexPanner, MODEL_hana7, 0)
    EVT_CALL(SetTexPanner, MODEL_hana8, 0)
    EVT_CALL(SetTexPanner, MODEL_hana9, 0)
    EVT_CALL(SetTexPanner, MODEL_hana10, 0)
    EVT_CALL(SetTexPanner, MODEL_hanahana, 0)
    EVT_LABEL(10)
    EVT_LOOP(12)
        EVT_CALL(SetTexPanOffset, 0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(12)
        EVT_CALL(SetTexPanOffset, 0, 0, 0x00004000, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242240_9F6C80) = {
    EVT_THREAD
        EVT_CALL(SetTexPanner, MODEL_suimen1, 1)
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LABEL(10)
        EVT_CALL(SetTexPanOffset, 1, 0, LVar0, 0)
        EVT_CALL(SetTexPanOffset, 1, 1, LVar1, LVar2)
        EVT_SUB(LVar0, 100)
        EVT_SUB(LVar1, 400)
        EVT_ADD(LVar1, 1000)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_kabemizu, 2)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_LABEL(20)
    EVT_CALL(SetTexPanOffset, 2, 0, LVar0, 0)
    EVT_CALL(SetTexPanOffset, 2, 1, LVar1, LVar2)
    EVT_SUB(LVar0, 100)
    EVT_ADD(LVar1, 800)
    EVT_SUB(LVar1, 400)
    EVT_WAIT(1)
    EVT_GOTO(20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(D_80242010_9F6A50)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiri1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(D_80242088_9F6AC8)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PLEASANT_PATH)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_SET(GF_MAP_PleasantPath, TRUE)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_ELSE
        EVT_IF_GE(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
            EVT_IF_EQ(GF_NOK11_Defeated_KentC, FALSE)
                EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup1)))
            EVT_ELSE
                EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup3)))
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup3)))
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(D_802420D8_9F6B18))
    EVT_EXEC(N(D_80242240_9F6C80))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(PlaySound, SOUND_8000005B)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
