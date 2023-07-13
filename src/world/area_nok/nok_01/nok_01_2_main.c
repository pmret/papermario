#include "nok_01.h"

EvtScript N(EVS_ExitWalk_nok_13_1) = {
    EVT_IF_EQ(GB_KootFavor_State, KOOT_FAVOR_STATE_2)
        EVT_SET(GF_KootFavor_LeftKoopaVillage, TRUE)
    EVT_END_IF
    EVT_CALL(N(func_802428B8_9C7C98))
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_CALL(UseExitHeading, 60, nok_01_ENTRY_0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("nok_13"), nok_13_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_nok_02_0) = {
    EVT_CALL(N(func_802428B8_9C7C98))
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_CALL(UseExitHeading, 60, nok_01_ENTRY_1)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("nok_02"), nok_02_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_nok_13_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_nok_02_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SET(LFlag0, FALSE)
    EVT_IF_EQ(LVar0, nok_01_ENTRY_0)
        EVT_IF_LT(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
            EVT_SET(LFlag0, TRUE)
            EVT_THREAD
                EVT_WAIT(30)
                EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_END_THREAD
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Flowers) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_o298, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o320, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o402, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o396, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o397, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o398, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o399, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o400, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o401, TEX_PANNER_0)
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

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_KOOPA_VILLAGE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
#if VERSION_PAL
    EVT_CALL(GetLanguage, LVar0)
    EVT_CALL(SetModelTexVariant, MODEL_o340, LVar0)
#endif
    EVT_SET(GF_MAP_KoopaVillage, TRUE)
    EVT_SET(AF_NOK01_Dialogue_RelaxedKoopa, FALSE)
    EVT_SET(AF_NOK01_Dialogue_Bobomb_01_Crisis, FALSE)
    EVT_SET(AF_NOK01_Dialogue_Bobomb_02, FALSE)
    EVT_SET(AF_NOK_0E, FALSE)
    EVT_SET(GF_NOK01_Bush4_KoopaLeaf, FALSE)
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_SET(GF_NOK01_RecoveredShellA, TRUE)
        EVT_SET(GF_NOK01_RecoveredBlockShell, TRUE)
        EVT_SET(GF_NOK01_RecoveredTreeShell, TRUE)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(CrisisNPCs)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NormalNPCs)))
    EVT_END_IF
    EVT_CALL(ClearDefeatedEnemies)
    EVT_EXEC(N(EVS_SetupShop))
    EVT_EXEC(N(EVS_SetupRadio))
    EVT_EXEC(N(EVS_TexPan_Flowers))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_MakeRooms))
    EVT_WAIT(1)
    EVT_EXEC_WAIT(N(EVS_SetupFoliage))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_SET(AB_NOK_0, 0)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
