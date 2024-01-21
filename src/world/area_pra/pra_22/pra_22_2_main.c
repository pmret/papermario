#include "pra_22.h"
#include "sprite/player.h"

#include "world/common/todo/UnkFunc11.inc.c"

API_CALLABLE(N(PreventFalling)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x, y, z, hitDepth;

    playerStatus->pos.x = script->varTable[0];
    x = playerStatus->pos.x;
    y = playerStatus->pos.y + 10.0f;
    z = playerStatus->pos.z;
    hitDepth = 300.0f;
    npc_raycast_down_around(0, &x, &y, &z, &hitDepth, 270.0f, playerStatus->colliderDiameter);

    playerStatus->pos.x = x;
    playerStatus->pos.z = z;
    script->varTable[10] = FALSE;
    if (playerStatus->pos.y != y) {
        playerStatus->pos.y = 0.0f;
        script->varTable[3]++;
        if (script->varTable[3] >= 30) {
            // player may now fall
            script->varTable[10] = TRUE;
        }
    }
    return ApiStatus_DONE2;
}

s32 N(DoorModelsL)[] = { MODEL_o1001, -1 };
s32 N(DoorModelsR)[] = { MODEL_o1002, -1 };

EvtScript N(EVS_ExitDoors_pra_20_4) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, pra_22_ENTRY_0)
    Set(LVar1, COLLIDER_deilittssw)
    Set(LVar2, MODEL_o1085)
    Set(LVar3, DOOR_SWING_OUT)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_20"), pra_20_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_37_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, pra_22_ENTRY_1)
    Set(LVar1, COLLIDER_deilittsse)
    Set(LVar2, Ref(N(DoorModelsL)))
    Set(LVar3, Ref(N(DoorModelsR)))
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_37"), pra_37_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_pra_20_4)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittssw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_37_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsse, 1, 0)
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
        CaseEq(pra_22_ENTRY_0)
            Set(LVar2, MODEL_o1085)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
        CaseEq(pra_22_ENTRY_1)
            Set(LVar2, Ref(N(DoorModelsL)))
            Set(LVar3, Ref(N(DoorModelsR)))
            ExecWait(BaseEnterDoor)
    EndSwitch
    Exec(N(EVS_BindExitTriggers))
    Return
    End
};

EvtScript N(EVS_PushRightStatue_Impl) = {
    Loop(30)
        Call(GetPartnerInUse, LVarA)
        IfNe(LVarA, PARTNER_NONE)
            Set(LVar8, -1)
            Return
        EndIf
        Call(N(UnkFunc11), LVar9)
        IfEq(LVar0, 0)
            Set(LVar8, -1)
            Return
        Else
            Call(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
        EndIf
        Wait(1)
    EndLoop
    Call(GetPartnerInUse, LVarA)
    IfNe(LVarA, PARTNER_NONE)
        Set(LVar8, -1)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 100, Float(0.6))
    EndThread
    Thread
        IfGe(LVar6, LVar7)
            Call(InterpPlayerYaw, 270, 0)
        Else
            Call(InterpPlayerYaw, 90, 0)
        EndIf
        Call(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Set(LVar1, LVar0)
        Set(LVar2, LVar7)
        Sub(LVar2, LVar6)
        Add(LVar1, LVar2)
        Call(MakeLerp, LVar0, LVar1, 100, EASING_LINEAR)
        Set(LVar3, 0)
        Loop(0)
            Call(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
            Call(UpdateLerp)
            Call(N(PreventFalling))
            IfEq(LVarA, TRUE)
                BreakLoop
            EndIf
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetPlayerActionState, ACTION_STATE_IDLE)
        Wait(1)
        IfEq(LVarA, 1)
            Call(DisablePlayerPhysics, TRUE)
            Wait(1)
            Call(SetPlayerAnimation, ANIM_MarioW2_TouchedLava)
            Wait(15)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
            Wait(1)
            Call(DisablePlayerPhysics, FALSE)
            Call(SetPlayerActionState, ACTION_STATE_FALLING)
            Wait(1)
        EndIf
        Call(DisablePlayerInput, FALSE)
    EndThread
    Call(MakeLerp, LVar6, LVar7, 100, EASING_LINEAR)
    Call(PlaySoundAtCollider, COLLIDER_o1064, SOUND_LOOP_MOVE_STATUE, SOUND_SPACE_DEFAULT)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o1005, LVar0, 0, 0)
        Call(TranslateModel, MODEL_o1006, LVar0, 0, 0)
        Call(TranslateModel, MODEL_o1007, LVar0, 0, 0)
        Call(TranslateModel, MODEL_o1008, LVar0, 0, 0)
        Call(TranslateModel, MODEL_o1009, LVar0, 0, 0)
        Call(UpdateColliderTransform, COLLIDER_o1064)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(StopSound, SOUND_LOOP_MOVE_STATUE)
    Return
    End
};

EvtScript N(EVS_PushStatue) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLe(LVar0, 337)
        Set(LVar6, 0)
        Set(LVar7, 50)
        Set(LVar8, 2)
    EndIf
    IfGe(LVar0, 413)
        Set(LVar6, 0)
        Set(LVar7, -50)
        Set(LVar8, 1)
    Else
        Return
    EndIf
    Set(LVar9, COLLIDER_o1064)
    ExecWait(N(EVS_PushRightStatue_Impl))
    IfNe(LVar8, -1)
        Set(GB_StoryProgress, STORY_CH7_FOUND_HIDDEN_ROOM_UNDER_STATUE)
        Set(GB_PRA_TwinStatueState, LVar8)
        Thread
            Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(1.0))
        EndThread
        Unbind
    EndIf
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_CRYSTAL_PALACE)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    Call(SetCamBGColor, CAM_DEFAULT, 24, 24, 40)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(SetCamEnabled, CAM_DEFAULT, TRUE)
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    IfLt(GB_StoryProgress, STORY_CH7_FOUND_HIDDEN_ROOM_UNDER_STATUE)
        BindTrigger(Ref(N(EVS_PushStatue)), TRIGGER_WALL_PUSH, COLLIDER_o1064, 1, 0)
        Set(LVar0, 0)
    Else
        Switch(GB_PRA_TwinStatueState)
            CaseEq(0)
                Set(LVar0, -50)
            CaseEq(1)
                Set(LVar0, -50)
            CaseEq(2)
                Set(LVar0, 50)
        EndSwitch
    EndIf
    Call(ParentColliderToModel, COLLIDER_o1064, MODEL_o1005)
    Call(TranslateModel, MODEL_o1005, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o1006, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o1007, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o1008, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o1009, LVar0, 0, 0)
    Call(UpdateColliderTransform, COLLIDER_o1064)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
