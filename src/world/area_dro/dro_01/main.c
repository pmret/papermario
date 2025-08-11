#include "dro_01.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/ApplyTint.inc.c"

EvtScript N(EVS_ExitWalk_sbk_36_1) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Set(GF_DRO01_HeardHintAboutSpinningRoof, 0)
    Call(UseExitHeading, 60, 0)
    Exec(ExitWalk)
    Call(GotoMap, Ref("sbk_36"), 1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_dro_02_0) = EVT_EXIT_WALK(60, dro_01_ENTRY_1, "dro_02", dro_02_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(N(EVS_ExitWalk_sbk_36_1), TRIGGER_FLOOR_ABOVE, 1, 1, 0)
    BindTrigger(N(EVS_ExitWalk_dro_02_0), TRIGGER_FLOOR_ABOVE, 5, 1, 0)
    Return
    End
};

EvtScript N(EVS_Scene_RuinsRising) = {
    Call(PlaySound, SOUND_LOOP_SBK_RUINS_RISING_DISTANT)
    Call(UseSettingsFrom, CAM_DEFAULT, 175, 0, -201)
    Call(SetPanTarget, CAM_DEFAULT, 175, 0, -201)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(N(SetModelTintMode), APPLY_TINT_BG, nullptr, ENV_TINT_REMAP)
    Call(N(SetModelTintMode), APPLY_TINT_GROUPS, -1, ENV_TINT_REMAP)
    Call(N(SetModelTintParams), ENV_TINT_REMAP, 44, 32, 177, 0, 0, 0, 0, 0, 0)
    Call(DisablePlayerInput, true)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 300, Float(0.2))
    EndThread
    Thread
        Wait(60)
        Call(GetEntryID, LVar0)
        IfEq(LVar0, dro_01_ENTRY_3)
            Call(GotoMap, Ref("dro_02"), dro_02_ENTRY_2)
        Else
            Call(GotoMap, Ref("dro_02"), dro_02_ENTRY_3)
        EndIf
        Wait(100)
    EndThread
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(dro_01_ENTRY_2)
            IfEq(GF_DRO01_WarpPipe, false)
                Call(DisablePlayerInput, true)
                Call(DisablePlayerPhysics, true)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                Call(SetPlayerPos, LVar0, NPC_DISPOSE_POS_Y, LVar2)
                Wait(30)
                Call(PlaySound, SOUND_GROW)
                Set(GF_DRO01_WarpPipe, true)
                Wait(30)
                Call(SetPlayerActionState, ACTION_STATE_IDLE)
                Call(SetPlayerPos, LVar0, LVar1, LVar2)
                Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                Call(DisablePlayerPhysics, false)
                Call(DisablePlayerInput, false)
            EndIf
            Set(LVarA, Ref(N(EVS_BindExitTriggers)))
            ExecWait(N(EVS_Pipe_EnterVertical))
        CaseOrEq(dro_01_ENTRY_3)
        CaseOrEq(dro_01_ENTRY_4)
            ExecWait(N(EVS_Scene_RuinsRising))
        EndCaseGroup
        CaseEq(dro_01_ENTRY_A)
            Exec(EnterPostPipe)
            Exec(N(EVS_BindExitTriggers))
        CaseDefault
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Wait(1)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_DRY_DRY_OUTPOST)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Set(GF_MAP_DryDryOutpost, true)
    IfLt(GB_StoryProgress, STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
        Set(GB_StoryProgress, STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
    EndIf
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH2_STAR_SPRIT_DEPARTED, STORY_CH4_BEGAN_PEACH_MISSION)
            Call(MakeNpcs, false, Ref(N(Chapter3NPCs)))
        CaseDefault
            Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    EndSwitch
    Call(InitVirtualEntityList)
    ExecWait(N(EVS_MakeEntities))
    Call(MakeShop, Ref(N(Shop_ItemPositions)), Ref(N(Shop_Inventory)), Ref(N(Shop_PriceList)), 0)
    Call(MakeShopOwner, Ref(N(Shop_Owner)))
    ExecWait(N(EVS_SetupRooms))
    Exec(N(EVS_SwingSign_Shop))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupFoliage))
    Return
    End
};
