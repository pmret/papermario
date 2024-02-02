#include "omo_07.h"

EvtScript N(EVS_ExitWalk_omo_06_4) = EVT_EXIT_WALK(60, omo_07_ENTRY_0, "omo_06", omo_06_ENTRY_4);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_omo_06_4)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    IfEq(GF_OMO07_SpawnedPeachChoice2, FALSE)
        Call(MakeNpcs, TRUE, Ref(N(KammySceneNPCs)))
    Else
        IfEq(GF_OMO07_Item_ThunderRage, FALSE)
            Switch(GB_OMO_PeachChoice2)
                CaseEq(0)
                    Call(MakeNpcs, TRUE, Ref(N(FuzzyAmbushNPCs)))
                CaseEq(1)
                    Call(MakeNpcs, TRUE, Ref(N(HammerBrosAmbushNPCs)))
                CaseEq(2)
                    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
                    Call(MakeItemEntity, ITEM_THUNDER_RAGE, 1080, 0, 0, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO07_Item_ThunderRage)
            EndSwitch
        Else
            Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
        EndIf
    EndIf
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupGizmos))
    ExecWait(N(EVS_SetupMusic))
    Exec(N(EVS_SetupShyGuyPool))
    IfEq(GF_OMO07_SpawnedPeachChoice2, FALSE)
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
