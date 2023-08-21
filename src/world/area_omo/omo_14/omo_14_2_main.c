#include "omo_14.h"

#include "world/common/atomic/CreateDarkness.inc.c"

EvtScript N(EVS_ExitWalk_omo_02_1) = EVT_EXIT_WALK(60, omo_14_ENTRY_0, "omo_02", omo_02_ENTRY_1);
EvtScript N(EVS_ExitWalk_omo_15_0) = EVT_EXIT_WALK(60, omo_14_ENTRY_1, "omo_15", omo_15_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_02_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_15_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_OPENED_GENERAL_GUY_ROOM)
        EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_LOOP_SHY_GUY_CROWD_1, SOUND_SPACE_DEFAULT)
    EVT_END_IF
    EVT_EXEC(N(EVS_CreateDarkness))
    EVT_IF_GE(GB_StoryProgress, STORY_CH4_OPENED_GENERAL_GUY_ROOM)
        EVT_CALL(EnableModel, MODEL_o823, FALSE)
        EVT_CALL(EnableModel, MODEL_o828, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
