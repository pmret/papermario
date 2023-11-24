#include "sbk_30.h"

#include "world/common/atomic/ApplyTint.inc.c"

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_99_1) = EVT_EXIT_WALK(60, sbk_30_ENTRY_0, "sbk_99", sbk_99_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_31_0) = EVT_EXIT_WALK(60, sbk_30_ENTRY_1, "sbk_31", sbk_31_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_20_3) = EVT_EXIT_WALK(60, sbk_30_ENTRY_2, "sbk_20", sbk_20_ENTRY_3);
EvtScript N(EVS_ExitWalk_sbk_40_2) = EVT_EXIT_WALK(60, sbk_30_ENTRY_3, "sbk_40", sbk_40_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_99_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_31_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_20_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_40_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(sbk_30_ENTRY_0)
            EVT_IF_EQ(GF_SBK30_Visited, FALSE)
                EVT_SET(GF_SBK30_Visited, TRUE)
                EVT_SET(GB_StoryProgress, STORY_CH2_ARRIVED_AT_DRY_DRY_DESERT)
            EVT_END_IF
        EVT_CASE_EQ(sbk_30_ENTRY_1)
        EVT_CASE_EQ(sbk_30_ENTRY_2)
        EVT_CASE_EQ(sbk_30_ENTRY_3)
        EVT_CASE_EQ(sbk_30_ENTRY_4)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_RuinsRising) = {
    EVT_CALL(PlaySound, SOUND_LOOP_SBK_RUINS_RISING_DISTANT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 193, 0, -237)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 193, 0, -237)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(N(SetModelTintMode), APPLY_TINT_BG, NULL, ENV_TINT_REMAP)
    EVT_CALL(N(SetModelTintMode), APPLY_TINT_GROUPS, -1, ENV_TINT_REMAP)
    EVT_CALL(N(SetModelTintParams), ENV_TINT_REMAP, 44, 32, 177, 0, 0, 0, 0, 0, 0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 300, EVT_FLOAT(0.25))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(60)
        EVT_CALL(GetEntryID, LVar0)
        EVT_IF_EQ(LVar0, sbk_30_ENTRY_4)
            EVT_CALL(GotoMap, EVT_PTR("dro_01"), dro_01_ENTRY_3)
        EVT_ELSE
            EVT_CALL(GotoMap, EVT_PTR("dro_01"), dro_01_ENTRY_4)
        EVT_END_IF
        EVT_WAIT(100)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1, exits); // can be fixed with subalign 16 for this map

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_DRY_DRY_DESERT)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH2_GOT_PULSE_STONE)
        EVT_CALL(DisablePulseStone, FALSE)
    EVT_END_IF
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_IF_LT(GB_StoryProgress, STORY_UNUSED_FFFFFFCC)
        EVT_CALL(EnableGroup, MODEL_g28, FALSE)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_g23, FALSE)
        EVT_CALL(EnableGroup, MODEL_sakji_tent, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_Default, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(SetZoneEnabled, ZONE_o25, FALSE)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(sbk_30_ENTRY_4)
        EVT_CASE_OR_EQ(sbk_30_ENTRY_5)
            EVT_EXEC_WAIT(N(EVS_Scene_RuinsRising))
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(N(SpawnSunEffect))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
