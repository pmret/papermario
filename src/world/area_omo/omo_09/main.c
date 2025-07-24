#include "omo_09.h"

EvtScript N(EVS_ExitWalk_omo_08_0) = EVT_EXIT_WALK(60, omo_09_ENTRY_0, "omo_08", omo_08_ENTRY_0);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_omo_08_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    IfGe(GB_StoryProgress, STORY_CH4_DEFEATED_GENERAL_GUY)
        Set(GF_OMO09_SpawnedPeachChoice3, true)
    EndIf
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
#if VERSION_PAL
    Call(GetLanguage, LVar0)
    IfEq(LVar0, LANGUAGE_ES)
        Set(LVar0, LANGUAGE_FR)
    EndIf
    Call(SetModelTexVariant, MODEL_s1, LVar0)
    Call(SetModelTexVariant, MODEL_s2, LVar0)
#endif
    IfEq(GF_OMO09_SpawnedPeachChoice3, false)
        Call(MakeNpcs, true, Ref(N(KammySceneNPCs)))
    Else
        IfEq(GF_OMO09_Item_SuperSoda, false)
            Switch(GB_OMO_PeachChoice3)
                CaseEq(0)
                    Call(MakeNpcs, true, Ref(N(PokeyAmbushNPCs)))
                CaseEq(1)
                    Call(MakeNpcs, true, Ref(N(KoopatrolAmbushNPCs)))
                CaseEq(2)
                    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
                    Call(MakeItemEntity, ITEM_SUPER_SODA, 1900, 150, 0, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO09_Item_SuperSoda)
            EndSwitch
        Else
            Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
        EndIf
    EndIf
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupGizmos))
    ExecWait(N(EVS_SetupMusic))
    ExecWait(N(EVS_SetupConveyors))
    ExecWait(N(EVS_SetupSlotMachine))
    IfEq(GF_OMO09_SpawnedPeachChoice3, false)
        Exec(N(EVS_Scene_KammySetAmbush))
        Wait(2)
    Else
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
        Wait(1)
    EndIf
    Return
    End
};
