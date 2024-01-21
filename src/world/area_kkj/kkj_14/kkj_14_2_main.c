#include "kkj_14.h"

#include "world/common/atomic/TexturePan.inc.c"
#include "../common/RestoreFromPeachState.inc.c"

API_CALLABLE(N(EnableParasol)) {
    gGameStatusPtr->peachFlags |= PEACH_FLAG_HAS_PARASOL;
    return ApiStatus_DONE2;
}

Gfx N(setup_gfx_candle_lights)[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetPrimColor(0, 0, 75, 31, 19, 255),
    gsDPSetEnvColor(255, 118, 77, 0),
    gsDPSetCombineMode(PM_CC_CANDLE_1, PM_CC_CANDLE_2),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

EvtScript N(EVS_EndPeachChapter7) = {
    Set(LVar0, GB_KKJ_LastPartner)
    Call(N(RestoreFromPeachState))
    Call(PlaySound, SOUND_SLIDE_WHISTLE_OUT)
    Call(GotoMapSpecial, Ref("pra_01"), pra_01_ENTRY_4, TRANSITION_END_PEACH_INTERLUDE)
    Wait(100)
};

EvtScript N(EVS_ExitDoor_GrandHall) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(AF_KKJ_13, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, kkj_14_ENTRY_0)
    Set(LVar1, COLLIDER_ttw)
    Set(LVar2, MODEL_o4)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    IfEq(GB_StoryProgress, STORY_INTRO)
        Call(GotoMap, Ref("kkj_01"), kkj_01_ENTRY_4)
    Else
        Call(GotoMap, Ref("kkj_11"), kkj_11_ENTRY_4)
    EndIf
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_Balcony) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(AF_KKJ_13, FALSE)
    Call(UseDoorSounds, DOOR_SOUNDS_DOOR)
    Set(LVar0, kkj_14_ENTRY_1)
    Set(LVar1, COLLIDER_tte)
    Set(LVar2, MODEL_o83)
    Set(LVar3, MODEL_o85)
    Set(LVar4, MODEL_o84)
    Set(LVar5, MODEL_o86)
    Exec(ExitSplitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_26"), kkj_26_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_SecretPassage) = {
    SetGroup(EVT_GROUP_1B)
    Set(AF_KKJ_13, FALSE)
    Call(UseExitHeading, 60, kkj_14_ENTRY_2)
    Exec(ExitWalk)
    IfEq(GF_KKJ14_SkipSecretPassage, FALSE)
        Call(GotoMap, Ref("kkj_27"), kkj_27_ENTRY_0)
    Else
        Call(GotoMap, Ref("kkj_15"), kkj_15_ENTRY_1)
    EndIf
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ShowMessage_CantOpen) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_DoesntOpen, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    IfEq(GB_StoryProgress, STORY_INTRO)
        BindTrigger(Ref(N(EVS_ShowMessage_CantOpen)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    Else
        BindTrigger(Ref(N(EVS_ExitDoors_Balcony)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
        BindTrigger(Ref(N(EVS_ExitWalk_SecretPassage)), TRIGGER_FLOOR_ABOVE, COLLIDER_o119, 1, 0)
    EndIf
    BindTrigger(Ref(N(EVS_ExitDoor_GrandHall)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kkj_14_ENTRY_0)
            Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
            Set(LVar2, MODEL_o4)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSingleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kkj_14_ENTRY_1)
            Call(UseDoorSounds, DOOR_SOUNDS_DOOR)
            Set(LVar2, MODEL_o83)
            Set(LVar3, MODEL_o85)
            Set(LVar4, MODEL_o84)
            Set(LVar5, MODEL_o86)
            ExecWait(EnterSplitDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kkj_14_ENTRY_2)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(kkj_14_ENTRY_3)
            Exec(N(EVS_Scene_Chapter0))
        CaseEq(kkj_14_ENTRY_4)
            Exec(N(EVS_Scene_Chapter1))
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kkj_14_ENTRY_5)
            Exec(N(EVS_Scene_Chapter2))
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kkj_14_ENTRY_6)
            Exec(N(EVS_Scene_Chapter3))
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kkj_14_ENTRY_7)
            Exec(N(EVS_Scene_Chapter4))
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kkj_14_ENTRY_8)
            Exec(N(EVS_Scene_Chapter5))
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kkj_14_ENTRY_9)
            Exec(N(EVS_Scene_Chapter6))
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kkj_14_ENTRY_A)
            Exec(N(EVS_Scene_Chapter7))
        CaseEq(kkj_14_ENTRY_B)
            Exec(N(EVS_Scene_TossedBackInRoom))
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Call(GetEntryID, LVar0)
    IfGe(LVar0, kkj_14_ENTRY_3)
        IfNe(LVar0, kkj_14_ENTRY_B)
            Set(GF_KKJ14_RevealedButton, FALSE)
            Set(GF_KKJ14_OpenedPassage, FALSE)
        EndIf
        Switch(LVar0)
            CaseEq(kkj_14_ENTRY_3)
                Set(GB_StoryProgress, STORY_CH0_BEGAN_PEACH_MISSION)
                Set(GB_KKJ_CaughtCount, 0)
                Set(GF_KKJ14_SkipSecretPassage, FALSE)
                Call(MakeNpcs, FALSE, Ref(N(Chapter0NPCs)))
            CaseEq(kkj_14_ENTRY_4)
                Set(GB_StoryProgress, STORY_CH1_BEGAN_PEACH_MISSION)
                Set(GB_KKJ_CaughtCount, 0)
                Set(GF_KKJ14_SkipSecretPassage, FALSE)
            CaseEq(kkj_14_ENTRY_5)
                Set(GB_StoryProgress, STORY_CH2_BEGAN_PEACH_MISSION)
                Set(GB_KKJ_CaughtCount, 0)
                Set(GF_KKJ14_SkipSecretPassage, FALSE)
                Set(AF_KKJ_06, FALSE)
                Call(MakeNpcs, FALSE, Ref(N(Chapter2NPCs)))
            CaseEq(kkj_14_ENTRY_6)
                Set(GB_StoryProgress, STORY_CH3_BEGAN_PEACH_MISSION)
                Set(GB_KKJ_CaughtCount, 0)
                Set(GF_KKJ14_SkipSecretPassage, FALSE)
            CaseEq(kkj_14_ENTRY_7)
                Set(GB_StoryProgress, STORY_CH4_BEGAN_PEACH_MISSION)
                Set(GB_KKJ_CaughtCount, 0)
                Set(GF_KKJ14_SkipSecretPassage, TRUE)
            CaseEq(kkj_14_ENTRY_8)
                Set(GB_StoryProgress, STORY_CH5_BEGAN_PEACH_MISSION)
                Set(GB_KKJ_CaughtCount, 0)
                Set(GF_KKJ14_SkipSecretPassage, TRUE)
            CaseEq(kkj_14_ENTRY_9)
                Call(N(EnableParasol))
                Set(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
                Set(GB_KKJ_CaughtCount, 0)
                Set(GF_KKJ14_SkipSecretPassage, TRUE)
            CaseEq(kkj_14_ENTRY_A)
                Call(MakeNpcs, FALSE, Ref(N(Chapter7NPCs)))
            CaseEq(kkj_14_ENTRY_B)
                Add(GB_KKJ_CaughtCount, 1)
                Call(MakeNpcs, FALSE, Ref(N(TossBackNPCs)))
        EndSwitch
    EndIf
    Exec(N(EVS_SetupInteractables))
    Call(GetEntryID, LVar0)
    IfNe(LVar0, kkj_14_ENTRY_5)
        Exec(N(EVS_SetupMusic))
    EndIf
    Exec(N(EVS_EnterMap))
    Call(SetTexPanner, MODEL_o154, TEX_PANNER_0)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(    0,    0,   40,  900)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetModelCustomGfx, MODEL_o154, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetCustomGfx, CUSTOM_GFX_0, Ref(N(setup_gfx_candle_lights)), NULL)
    Return
    End
};
