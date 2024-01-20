#include "mac_05.h"

#include "world/common/atomic/TexturePan.inc.c"

#define NAMESPACE dup_mac_05
#include "world/common/todo/UnkFloatFunc001.inc.c"
#define NAMESPACE mac_05

API_CALLABLE(N(func_8024047C_8525EC)) {
    gGameStatusPtr->exitTangent = 0.0f;
    return ApiStatus_BLOCK;
}

EvtScript N(D_8024457C_8566EC) = {
    SetGroup(EVT_GROUP_00)
    Set(LVarC, 0)
    Label(0)
        IfGe(LVarC, 60)
            Set(LVarC, 0)
        EndIf
        Call(dup_mac_05_UnkFloatFunc001, LVarC, LVar0, Float(-1.0), Float(1.0), 30, 0, 0)
        Call(ScaleModel, MODEL_kaimen, 1, LVar0, 1)
        Add(LVarC, 1)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(D_80244648_8567B8) = {
    Loop(0)
        Call(MakeLerp, 600, -240, 320, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateModel, MODEL_o177, LVar0, -25, -75)
            Call(RotateModel, MODEL_o177, 0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, -240, 600, 320, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateModel, MODEL_o177, LVar0, -25, -75)
            Call(RotateModel, MODEL_o177, 180, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_ExitWalk_mac_04_1) = EVT_EXIT_WALK(60, mac_05_ENTRY_0, "mac_04", mac_04_ENTRY_1);

EvtScript N(D_80244810_856980) = {
    SetGroup(EVT_GROUP_1B)
    Call(UseExitHeading, 60, mac_05_ENTRY_3)
    Exec(ExitWalk)
    Set(GB_StoryProgress, STORY_CH5_ENTERED_WHALE)
    Call(GotoMap, Ref("kgr_01"), kgr_01_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_mac_04_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    BindTrigger(Ref(N(D_80244810_856980)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilit9, 1, 0)
    Return
    End
};

EvtScript N(D_802448C4_856A34) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(mac_05_ENTRY_0)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(mac_05_ENTRY_1)
            Exec(N(EVS_802496FC))
            Exec(N(EVS_BindExitTriggers))
        CaseEq(mac_05_ENTRY_2)
            Exec(N(EVS_80248878))
            Exec(N(EVS_BindExitTriggers))
        CaseEq(mac_05_ENTRY_3)
            Call(DisablePlayerInput, TRUE)
            Call(DisablePlayerPhysics, TRUE)
            Call(SetPlayerPos, -160, -10, 371)
            Call(SetNpcPos, NPC_PARTNER, -160, -10, 371)
            Call(SetEnemyFlagBits, NPC_Whale, ENEMY_FLAG_CANT_INTERACT, 1)
            Call(DisablePartnerAI, 0)
            Call(InterruptUsePartner)
            Wait(10)
            Thread
                Call(MakeLerp, -160, -220, 30, EASING_LINEAR)
                Loop(0)
                    Call(UpdateLerp)
                    Call(SetPlayerPos, LVar0, -10, 371)
                    Call(SetNpcPos, NPC_PARTNER, LVar0, -10, 371)
                    Wait(1)
                    IfEq(LVar1, 0)
                        BreakLoop
                    EndIf
                EndLoop
            EndThread
            Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Yell)
            Wait(30)
            Call(SetPlayerPos, -280, -10, 371)
            Call(EnablePartnerAI)
            Call(DisablePlayerPhysics, FALSE)
            Call(DisablePlayerInput, FALSE)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            ExecWait(EnterWalk)
            Call(SetNpcPos, NPC_Whale, -220, 10, 372)
            Call(SetEnemyFlagBits, NPC_Whale, ENEMY_FLAG_CANT_INTERACT, 0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, Ref(N(NpcSetA)))
        CaseLt(STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
            Set(LVar0, Ref(N(NpcSetB)))
        CaseLt(STORY_CH5_RETURNED_TO_TOAD_TOWN)
            Call(GetEntryID, LVar1)
            IfEq(LVar1, mac_05_ENTRY_1)
                IfEq(GF_MAC01_Defeated_JrTroopa4, FALSE)
                    Set(LVar0, Ref(N(NpcSetC)))
                Else
                    Set(LVar0, Ref(N(NpcSetB)))
                EndIf
            Else
                Set(LVar0, Ref(N(NpcSetA)))
            EndIf
        CaseLt(STORY_CH6_BEGAN_PEACH_MISSION)
            Set(LVar0, Ref(N(NpcSetA)))
        CaseDefault
            Set(LVar0, Ref(N(NpcSetA)))
    EndSwitch
    Call(MakeNpcs, FALSE, LVar0)
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupWhale))
    Call(GetEntryID, LVar0)
    Exec(N(EVS_SetupRooms))
    Exec(N(EVS_SetupMusic))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitne, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(D_802448C4_856A34))
    Wait(1)
    Exec(N(D_8024457C_8566EC))
    Call(SetTexPanner, MODEL_kaimen, 1)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  100,  100,  -70,  -50)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Exec(N(D_80244648_8567B8))
    Exec(N(EVS_AnimateClub64Sign))
    Return
    End
};
