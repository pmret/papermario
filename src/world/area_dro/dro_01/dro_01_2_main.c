#include "dro_01.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/ApplyTint.inc.c"

EvtScript N(EVS_ExitWalk_sbk_36_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_SET(GF_DRO01_HeardHintAboutSpinningRoof, 0)
    EVT_CALL(UseExitHeading, 60, 0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("sbk_36"), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_dro_02_0) = EVT_EXIT_WALK(60, dro_01_ENTRY_1, "dro_02", dro_02_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_sbk_36_1), TRIGGER_FLOOR_ABOVE, 1, 1, 0)
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_dro_02_0), TRIGGER_FLOOR_ABOVE, 5, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_RuinsRising) = {
    EVT_CALL(PlaySound, SOUND_LOOP_SBK_RUINS_RISING_DISTANT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 175, 0, -201)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 175, 0, -201)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(N(SetModelTintMode), APPLY_TINT_BG, NULL, ENV_TINT_REMAP)
    EVT_CALL(N(SetModelTintMode), APPLY_TINT_GROUPS, -1, ENV_TINT_REMAP)
    EVT_CALL(N(SetModelTintParams), ENV_TINT_REMAP, 44, 32, 177, 0, 0, 0, 0, 0, 0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 300, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(60)
        EVT_CALL(GetEntryID, LVar0)
        EVT_IF_EQ(LVar0, dro_01_ENTRY_3)
            EVT_CALL(GotoMap, EVT_PTR("dro_02"), dro_02_ENTRY_2)
        EVT_ELSE
            EVT_CALL(GotoMap, EVT_PTR("dro_02"), dro_02_ENTRY_3)
        EVT_END_IF
        EVT_WAIT(100)
    EVT_END_THREAD
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
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(dro_01_ENTRY_2)
            EVT_IF_EQ(GF_DRO01_WarpPipe, FALSE)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(DisablePlayerPhysics, TRUE)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                EVT_CALL(SetPlayerPos, LVar0, NPC_DISPOSE_POS_Y, LVar2)
                EVT_WAIT(30)
                EVT_CALL(PlaySound, SOUND_GROW)
                EVT_SET(GF_DRO01_WarpPipe, TRUE)
                EVT_WAIT(30)
                EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
                EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                EVT_CALL(DisablePlayerPhysics, FALSE)
                EVT_CALL(DisablePlayerInput, FALSE)
            EVT_END_IF
            EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC_WAIT(N(EVS_Pipe_EnterVertical))
        EVT_CASE_OR_EQ(dro_01_ENTRY_3)
        EVT_CASE_OR_EQ(dro_01_ENTRY_4)
            EVT_EXEC_WAIT(N(EVS_Scene_RuinsRising))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(dro_01_ENTRY_A)
            EVT_EXEC(EnterPostPipe)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_DRY_DRY_OUTPOST)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_SET(GF_MAP_DryDryOutpost, TRUE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
        EVT_SET(GB_StoryProgress, STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH2_STAR_SPRIT_DEPARTED, STORY_CH4_BEGAN_PEACH_MISSION)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(Chapter3NPCs)))
        EVT_CASE_DEFAULT
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_END_SWITCH
    EVT_CALL(InitVirtualEntityList)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(MakeShop, EVT_PTR(N(Shop_ItemPositions)), EVT_PTR(N(Shop_Inventory)), EVT_PTR(N(Shop_PriceList)), 0)
    EVT_CALL(MakeShopOwner, EVT_PTR(N(Shop_Owner)))
    EVT_EXEC_WAIT(N(EVS_SetupRooms))
    EVT_EXEC(N(EVS_SwingSign_Shop))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_RETURN
    EVT_END
};
