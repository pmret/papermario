#include "mac_01.h"

EvtScript N(EVS_ExitWalk_mac_00_1) = EVT_EXIT_WALK(60, mac_01_ENTRY_0, "mac_00", mac_00_ENTRY_1);

EvtScript N(EVS_ExitWalk_nok_11_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(UseExitHeading, 60, mac_01_ENTRY_1)
    Exec(ExitWalk)
    IfEq(GF_StartedChapter1, FALSE)
        Set(GF_StartedChapter1, TRUE)
        Call(FadeOutMusic, 0, 1500)
        Call(GotoMapSpecial, Ref("kmr_22"), kmr_22_ENTRY_1, TRANSITION_BEGIN_OR_END_CHAPTER)
        Wait(100)
        Return
    EndIf
    Call(GotoMap, Ref("nok_11"), nok_11_ENTRY_0)
    Wait(100)
    Return
    End
};

s32 N(Models_CastleGateL)[] = {
    MODEL_o306,
    MODEL_o307,
    -1
};

s32 N(Models_CastleGateR)[] = {
    MODEL_o308,
    MODEL_o309,
    -1
};

EvtScript N(EVS_ExitDoors_osr_01_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
    Set(LVar0, 2)
    Set(LVar1, 5)
    Set(LVar2, Ref(N(Models_CastleGateL)))
    Set(LVar3, Ref(N(Models_CastleGateR)))
    Exec(BaseExitDoor)
    Wait(17)
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH0_WAKE_UP, STORY_CH8_REACHED_PEACHS_CASTLE)
            Call(GotoMap, Ref("osr_01"), osr_01_ENTRY_0)
        CaseDefault
            Call(GotoMap, Ref("osr_00"), osr_00_ENTRY_0)
    EndSwitch
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_mac_02_2) = EVT_EXIT_WALK(60, mac_01_ENTRY_3, "mac_02", mac_02_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_mac_00_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_osr_01_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitn, 1, 0)
    IfGe(GB_StoryProgress, STORY_EPILOGUE)
        Return
    EndIf
    BindTrigger(Ref(N(EVS_ExitWalk_nok_11_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_mac_02_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    BindTrigger(Ref(N(EVS_ExitFlowerGate)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitf, 1, 0)
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
        CaseEq(mac_01_ENTRY_2)
            Call(DisablePlayerInput, TRUE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitn, COLLIDER_FLAGS_UPPER_MASK)
            Call(RotateGroup, MODEL_east_gate, 80, 0, 1, 0)
            Call(RotateGroup, MODEL_west_gate, 80, 0, -1, 0)
            Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            ExecWait(EnterWalk)
            Call(MakeLerp, 80, 0, 10, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Call(RotateGroup, MODEL_east_gate, LVar0, 0, 1, 0)
                Call(RotateGroup, MODEL_west_gate, LVar0, 0, -1, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(PlaySoundAtCollider, COLLIDER_deilitn, SOUND_LARGE_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilitn, COLLIDER_FLAGS_UPPER_MASK)
            Call(DisablePlayerInput, FALSE)
        CaseEq(mac_01_ENTRY_4)
            Exec(N(EVS_Scene_IntroWalking))
        CaseEq(mac_01_ENTRY_5)
            ExecWait(N(EVS_EnterFlowerGate))
            Exec(N(EVS_BindExitTriggers))
        CaseDefault
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 90, 4096) // note: unusually large near clip dist: 90 vs 16
    Call(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamEnabled, CAM_DEFAULT, TRUE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
#if VERSION_PAL
    Call(GetLanguage, LVar0)
    Call(SetModelTexVariant, MODEL_k11, LVar0)
#endif
    Set(AF_MAC_0E, FALSE)
    Set(AF_MAC_0F, FALSE)
    Set(AF_MAC_10, FALSE)
    Set(AF_MAC_11, FALSE)
    Set(AF_MAC_12, FALSE)
    Set(AF_MAC_13, FALSE)
    Set(AF_MAC_14, FALSE)
    Set(AF_MAC_15, FALSE)
    IfLt(GB_StoryProgress, STORY_EPILOGUE)
        Exec(N(EVS_SetupBadgeShop))
    Else
        Call(EnableGroup, MODEL_jutan1, FALSE)
    EndIf
    Switch(GB_StoryProgress)
        CaseEq(STORY_INTRO)
            Call(MakeNpcs, FALSE, Ref(N(IntroNPCs)))
        CaseGe(STORY_EPILOGUE)
            Call(MakeNpcs, FALSE, Ref(N(EpilogueNPCs)))
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Call(MakeNpcs, FALSE, Ref(N(Chapter0NPCs)))
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Call(MakeNpcs, FALSE, Ref(N(Chapter1NPCs)))
        CaseEq(STORY_CH1_DEFEATED_JR_TROOPA)
            Call(MakeNpcs, FALSE, Ref(N(TwinkMeetingNPCs)))
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            Call(MakeNpcs, FALSE, Ref(N(Chapter4NPCs)))
        CaseEq(STORY_CH6_RETURNED_TO_TOAD_TOWN)
            Call(MakeNpcs, FALSE, Ref(N(NinjiMeetingNPCs)))
        CaseDefault
            Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    EndSwitch
    IfGe(GB_StoryProgress, STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Exec(N(EVS_SetupFlowerModels))
    Exec(N(EVS_MakeEntities))
    Exec(N(EVS_SetupRooms))
    Exec(N(EVS_SetupBulletinBoard))
    Exec(N(EVS_SetupCrystalBallGfx))
    Exec(N(EVS_SetupMusic))
    Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
    Call(UseRoomDoorSounds, DOOR_SOUNDS_BASIC)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Call(EnableTexPanning, MODEL_hikari, TRUE)
    Thread
        SetGroup(EVT_GROUP_00)
        Set(LVar0, 0)
        Set(LVar1, 0)
        Label(0)
            Add(LVar0, -100)
            Add(LVar1, -200)
            IfLt(LVar0, 0)
                Add(LVar0, 0x10000)
            EndIf
            IfLt(LVar1, 0)
                Add(LVar0, 0x10000)
            EndIf
            Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, LVar0, 0)
            Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_AUX, LVar1, LVar1)
            Wait(1)
            Goto(0)
    EndThread
    BindTrigger(Ref(N(EVS_Merlon_GiveHint)), TRIGGER_WALL_PRESS_A, COLLIDER_o335, 1, 0)
    Exec(N(EVS_SetupQuickChangeTrigger))
    Exec(N(EVS_SetupFoliage))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Return
    End
};
