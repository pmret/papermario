#include "omo_09.h"

EvtScript N(EVS_ExitWalk_omo_08_0) = EVT_EXIT_WALK(60, omo_09_ENTRY_0, "omo_08", omo_08_ENTRY_0);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_08_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    EVT_IF_GE(GB_StoryProgress, STORY_CH4_DEFEATED_GENERAL_GUY)
        EVT_SET(GF_OMO09_SpawnedPeachChoice3, TRUE)
    EVT_END_IF
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
#if VERSION_PAL
    EVT_CALL(GetLanguage, LVar0)
    EVT_IF_EQ(LVar0, LANGUAGE_ES)
        EVT_SET(LVar0, LANGUAGE_FR)
    EVT_END_IF
    EVT_CALL(SetModelTexVariant, MODEL_s1, LVar0)
    EVT_CALL(SetModelTexVariant, MODEL_s2, LVar0)
#endif
    EVT_IF_EQ(GF_OMO09_SpawnedPeachChoice3, FALSE)
        EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(KammySceneNPCs)))
    EVT_ELSE
        EVT_IF_EQ(GF_OMO09_Item_SuperSoda, FALSE)
            EVT_SWITCH(GB_OMO_PeachChoice3)
                EVT_CASE_EQ(0)
                    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(PokeyAmbushNPCs)))
                EVT_CASE_EQ(1)
                    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(KoopatrolAmbushNPCs)))
                EVT_CASE_EQ(2)
                    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
                    EVT_CALL(MakeItemEntity, ITEM_SUPER_SODA, 1900, 150, 0, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO09_Item_SuperSoda)
            EVT_END_SWITCH
        EVT_ELSE
            EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupGizmos))
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_EXEC_WAIT(N(EVS_SetupConveyors))
    EVT_EXEC_WAIT(N(EVS_SetupSlotMachine))
    EVT_IF_EQ(GF_OMO09_SpawnedPeachChoice3, FALSE)
        EVT_EXEC(N(EVS_Scene_KammySetAmbush))
        EVT_WAIT(2)
    EVT_ELSE
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
        EVT_WAIT(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
