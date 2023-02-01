#include "nok_13.h"

EvtScript N(EVS_ExitWalk_nok_12_1) = {
    EVT_CALL(UseExitHeading, 60, nok_13_ENTRY_0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("nok_12"), nok_12_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_nok_01_0) = {
    EVT_CALL(UseExitHeading, 60, nok_13_ENTRY_1)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("nok_01"), nok_01_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_nok_14_0) = {
    EVT_CALL(UseExitHeading, 60, nok_13_ENTRY_2)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("nok_14"), nok_14_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_TexPan_Flowers) = {
    EVT_CALL(SetTexPanner, MODEL_hana1, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_hana2, TEX_PANNER_0)
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
            EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_AUX,  LVar1, LVar2)
            EVT_SUB(LVar0, 100)
            EVT_SUB(LVar1, 400)
            EVT_ADD(LVar1, 1000)
            EVT_WAIT(1)
            EVT_GOTO(10)
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_kabemizu1, TEX_PANNER_2)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_LABEL(20)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar0, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_AUX,  LVar1, LVar2)
        EVT_SUB(LVar0, 100)
        EVT_ADD(LVar1, 800)
        EVT_SUB(LVar1, 400)
        EVT_WAIT(1)
        EVT_GOTO(20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_nok_12_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_nok_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_nok_14_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PLEASANT_PATH)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_TexPan_Flowers))
    EVT_EXEC(N(EVS_TexPan_Water))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_SetupMusicalHill))
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
