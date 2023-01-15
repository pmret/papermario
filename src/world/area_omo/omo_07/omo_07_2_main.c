#include "omo_07.h"

EvtScript N(EVS_ExitWalk_omo_06_4) = EVT_EXIT_WALK(60, omo_07_ENTRY_0, "omo_06", omo_06_ENTRY_4);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_06_4)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_IF_EQ(GF_OMO07_SpawnedPeachChoice2, FALSE)
        EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(KammySceneNPCs)))
    EVT_ELSE
        EVT_IF_EQ(GF_OMO07_Item_ThunderRage, FALSE)
            EVT_SWITCH(GB_OMO_PeachChoice2)
                EVT_CASE_EQ(0)
                    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(FuzzyAmbushNPCs)))
                EVT_CASE_EQ(1)
                    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(HammerBrosAmbushNPCs)))
                EVT_CASE_EQ(2)
                    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
                    EVT_CALL(MakeItemEntity, ITEM_THUNDER_RAGE, 1080, 0, 0, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO07_Item_ThunderRage)
            EVT_END_SWITCH
        EVT_ELSE
            EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupGizmos))
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_SetupShyGuyPool))
    EVT_IF_EQ(GF_OMO07_SpawnedPeachChoice2, FALSE)
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
