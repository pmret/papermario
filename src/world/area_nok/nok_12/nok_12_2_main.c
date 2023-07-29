#include "nok_12.h"

API_CALLABLE(N(UpdateEnounterStages)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    EncounterStatus* encounterStatus = &gCurrentEncounter;
    Bytecode* args = script->ptrReadPos;
    s32 xMin = evt_get_variable(script, *args++);
    s32 xMax = evt_get_variable(script, *args++);
    s32 zMin = evt_get_variable(script, *args++);
    s32 zMax = evt_get_variable(script, *args++);
    s32 stageWithoutBridge = evt_get_variable(script, *args++);
    s32 stageWithBridge = evt_get_variable(script, *args++);
    s32 stage = stageWithoutBridge;
    s32 i;

    if (xMin <= playerStatus->pos.x && playerStatus->pos.x <= xMax &&
        zMin <= playerStatus->pos.z && playerStatus->pos.z <= zMax)
    {
        stage = stageWithBridge;
    }

    for (i = 0; i < encounterStatus->numEncounters; i++) {
        encounterStatus->encounterList[i]->stage = stage;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_nok_11_1) = EVT_EXIT_WALK_NOK(60, nok_12_ENTRY_0, "nok_11", nok_11_ENTRY_1);
EvtScript N(EVS_ExitWalk_nok_13_0) = EVT_EXIT_WALK_NOK(60, nok_12_ENTRY_1, "nok_13", nok_13_ENTRY_0);

EvtScript N(EVS_UpdateEnounterStages) = {
    EVT_LABEL(0)
        EVT_IF_GE(GB_StoryProgress, STORY_CH1_MADE_FIRST_BRIDGE)
            EVT_CALL(N(UpdateEnounterStages), -380, -170, -100, 999, BTL_NOK_STAGE_00, BTL_NOK_STAGE_02)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Flowers) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_hana1, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_hana2, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_hana3, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_hana4, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_hana5, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_hana6, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_hana7, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_hanahna, TEX_PANNER_0)
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
    EVT_SET_GROUP(EVT_GROUP_00)
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
    EVT_CALL(SetTexPanner, MODEL_kabemizu2, TEX_PANNER_2)
    EVT_CALL(SetTexPanner, MODEL_kabemizu3, TEX_PANNER_2)
    EVT_CALL(SetTexPanner, MODEL_kabemizu4, TEX_PANNER_2)
    EVT_CALL(SetTexPanner, MODEL_kabemizu5, TEX_PANNER_2)
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
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_nok_11_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_nok_13_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PLEASANT_PATH)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SET(AF_NOK12_HitSwitch, FALSE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(GetDemoState, LVar0)
    EVT_IF_EQ(LVar0, DEMO_STATE_NONE)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_ELSE
        EVT_CALL(GetEntryID, LVar0)
        EVT_IF_EQ(LVar0, nok_12_ENTRY_2)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DemoNPCs)))
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupFoliage))
    EVT_EXEC(N(EVS_TexPan_Flowers))
    EVT_EXEC(N(EVS_TexPan_Water))
    EVT_EXEC(N(EVS_SetupBridge))
    EVT_CALL(GetDemoState, LVar0)
    EVT_IF_NE(LVar0, DEMO_STATE_NONE)
        EVT_CALL(GetEntryID, LVar0)
        EVT_IF_EQ(LVar0, nok_12_ENTRY_2)
            EVT_EXEC_WAIT(N(EVS_PlayDemoScene1))
        EVT_ELSE
            EVT_EXEC_WAIT(N(EVS_PlayDemoScene2))
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC(N(EVS_UpdateEnounterStages))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_SET(GF_MAC01_RowfBadgesChosen, FALSE)
    EVT_RETURN
    EVT_END
};
