#include "omo_04.h"

EvtScript N(EVS_ExitWalk_omo_03_1) = EVT_EXIT_WALK(60, omo_04_ENTRY_0, "omo_03", omo_03_ENTRY_1);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_03_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_IF_EQ(GF_OMO04_SpawnedPeachChoice1, FALSE)
        EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(KammySceneNPCs)))
    EVT_ELSE
        EVT_IF_EQ(GF_OMO04_Item_Mushroom, FALSE)
            EVT_SWITCH(GB_OMO_PeachChoice1)
                EVT_CASE_EQ(0)
                    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(GoombaAmbushNPCs)))
                EVT_CASE_EQ(1)
                    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(ClubbaAmbushNPCs)))
                EVT_CASE_EQ(2)
                    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
                    EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, 1100, 0, 0, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO04_Item_Mushroom)
            EVT_END_SWITCH
        EVT_ELSE
            EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupGizmos))
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_IF_EQ(GF_OMO04_SpawnedPeachChoice1, FALSE)
        EVT_EXEC(N(EVS_Scene_KammySetAmbush))
    EVT_ELSE
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
        EVT_WAIT(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
