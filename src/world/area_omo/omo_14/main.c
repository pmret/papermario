#include "omo_14.h"

#include "world/common/atomic/CreateDarkness.inc.c"

EvtScript N(EVS_ExitWalk_omo_02_1) = EVT_EXIT_WALK(60, omo_14_ENTRY_0, "omo_02", omo_02_ENTRY_1);
EvtScript N(EVS_ExitWalk_omo_15_0) = EVT_EXIT_WALK(60, omo_14_ENTRY_1, "omo_15", omo_15_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_omo_02_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_omo_15_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    Exec(N(EVS_SetupMusic))
    IfLt(GB_StoryProgress, STORY_CH4_OPENED_GENERAL_GUY_ROOM)
        Call(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_LOOP_SHY_GUY_CROWD_1, SOUND_SPACE_DEFAULT)
    EndIf
    Exec(N(EVS_CreateDarkness))
    IfGe(GB_StoryProgress, STORY_CH4_OPENED_GENERAL_GUY_ROOM)
        Call(EnableModel, MODEL_o823, false)
        Call(EnableModel, MODEL_o828, false)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Return
    End
};
