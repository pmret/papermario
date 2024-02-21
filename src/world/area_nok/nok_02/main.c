#include "nok_02.h"

#include "world/common/entity/Pipe.inc.c"

#define NAME_SUFFIX _Unused
#include "world/common/complete/GiveReward.inc.c"

#include "world/common/complete/KeyItemChoice.inc.c"
#define NAME_SUFFIX

EvtScript N(EVS_ExitWalk_nok_01_1) = {
    Call(UseExitHeading, 60, nok_02_ENTRY_0)
    Exec(ExitWalk)
    Call(GotoMap, Ref("nok_01"), nok_01_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_nok_03_0) = {
    IfEq(GB_KootFavor_State, KOOT_FAVOR_STATE_2)
        Set(GF_KootFavor_LeftKoopaVillage, TRUE)
    EndIf
    Call(UseExitHeading, 60, nok_02_ENTRY_1)
    Exec(ExitWalk)
    Call(GotoMap, Ref("nok_03"), nok_03_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_nok_01_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_nok_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    Return
    End
};

EvtScript N(EVS_TexPan_Flowers) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, MODEL_o312, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o460, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o461, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o462, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o454, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o455, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o456, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o457, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o458, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o459, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o314, TEX_PANNER_0)
    Label(10)
        Loop(12)
            Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, 0)
            Wait(1)
        EndLoop
        Loop(12)
            Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0x4000, 0)
            Wait(1)
        EndLoop
        Goto(10)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(nok_02_ENTRY_2)
            IfEq(GF_NOK02_WarpPipe, FALSE)
                Call(DisablePlayerInput, TRUE)
                Call(DisablePlayerPhysics, TRUE)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                Call(SetPlayerPos, LVar0, NPC_DISPOSE_POS_Y, LVar2)
                Wait(30)
                Call(PlaySound, SOUND_GROW)
                Set(GF_NOK02_WarpPipe, TRUE)
                Wait(30)
                Call(SetPlayerActionState, ACTION_STATE_IDLE)
                Call(SetPlayerPos, LVar0, LVar1, LVar2)
                Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                Call(DisablePlayerPhysics, FALSE)
                Call(DisablePlayerInput, FALSE)
            EndIf
            Set(LVarA, Ref(N(EVS_BindExitTriggers)))
            ExecWait(N(EVS_Pipe_EnterVertical))
        CaseEq(nok_02_ENTRY_4)
        CaseDefault
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_KOOPA_VILLAGE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(GetEntryID, LVar0)
    IfEq(LVar0, nok_02_ENTRY_3)
        Call(MakeNpcs, FALSE, Ref(N(EpilogueNPCs)))
        ExecWait(N(EVS_MakeEntities))
        Exec(N(EVS_TexPan_Flowers))
        Exec(N(EVS_Scene_Epilogue))
        Call(FadeInMusic, 0, SONG_KOOPA_VILLAGE, 0, 3000, 0, 127)
        Wait(1)
        Return
    EndIf
    Set(AF_NOK_0F, FALSE)
    Set(AF_NOK_10, FALSE)
    Set(AF_NOK_12, FALSE)
    Set(GF_NOK02_Bush1_KoopaLeaf, FALSE)
    Set(AF_NOK_13, FALSE)
    IfGe(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Set(GF_NOK02_RecoveredShellA, TRUE)
        Set(GF_NOK02_RecoveredShellB, TRUE)
    EndIf
    IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Call(MakeNpcs, FALSE, Ref(N(CrisisNPCs)))
    Else
        Call(MakeNpcs, FALSE, Ref(N(NormalNPCs)))
    EndIf
    Call(ClearDefeatedEnemies)
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupFoliage))
    Exec(N(EVS_TexPan_Flowers))
    BindTrigger(Ref(N(EVS_Setup_Bookshelf)), TRIGGER_WALL_PRESS_A, COLLIDER_o236, 1, 0)
    ExecWait(N(EVS_SetupRooms))
    Call(GetDemoState, LVar0)
    IfNe(LVar0, DEMO_STATE_NONE)
        ExecWait(N(EVS_SetupDemo))
        Return
    EndIf
    Exec(N(EVS_SetupMusic))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitn, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
