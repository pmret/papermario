#include "trd_02.h"
#include "effects.h"

extern EvtScript N(D_80242890_9A3870);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

EvtScript N(EVS_ExitDoors_trd_01_1) = EVT_EXIT_DOUBLE_DOOR(trd_02_ENTRY_0, "trd_01", trd_01_ENTRY_1, COLLIDER_ttw, MODEL_o6, MODEL_o7);
EvtScript N(EVS_ExitDoors_trd_03_0) = EVT_EXIT_DOUBLE_DOOR(trd_02_ENTRY_1, "trd_03", trd_03_ENTRY_0, COLLIDER_tte, MODEL_o9, MODEL_o8);
EvtScript N(EVS_ExitDoors_trd_01_2) = EVT_EXIT_DOUBLE_DOOR(trd_02_ENTRY_2, "trd_01", trd_01_ENTRY_2, COLLIDER_ttw2, MODEL_o13, MODEL_o12);
EvtScript N(EVS_ExitDoors_trd_03_2) = EVT_EXIT_DOUBLE_DOOR(trd_02_ENTRY_3, "trd_03", trd_03_ENTRY_2, COLLIDER_tte2, MODEL_o10, MODEL_o11);
EvtScript N(EVS_ExitWalk_trd_03_4) = EVT_EXIT_WALK(40, trd_02_ENTRY_4, "trd_03", trd_03_ENTRY_4);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_trd_03_4)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilia, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    SetGroup(EVT_GROUP_00)
    SuspendGroup(EVT_GROUP_01)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(trd_02_ENTRY_0)
            Set(LVar2, MODEL_o6)
            Set(LVar3, MODEL_o7)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(trd_02_ENTRY_1)
            Set(LVar2, MODEL_o9)
            Set(LVar3, MODEL_o8)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(trd_02_ENTRY_2)
            Set(LVar2, MODEL_o13)
            Set(LVar3, MODEL_o12)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(trd_02_ENTRY_3)
            Set(LVar2, MODEL_o10)
            Set(LVar3, MODEL_o11)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(trd_02_ENTRY_4)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    ResumeGroup(EVT_GROUP_01)
    Return
    End
};

EvtScript N(EVS_Scene_LowerStairs) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, 0)
    SuspendGroup(EVT_GROUP_01)
    Call(DisablePlayerInput, TRUE)
    Wait(30)
    Call(SetGroupVisibility, MODEL_move_saku, MODEL_GROUP_HIDDEN)
    Call(PlaySound, SOUND_LOOP_TRD_02_LOWER_STAIRS)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(0.7))
        Call(ShakeCam, CAM_DEFAULT, 0, 320, Float(1.0))
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(0.7))
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(0.4))
    EndThread
    Wait(20)
    Thread
        Loop(5)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Add(LVar1, 150)
            PlayEffect(EFFECT_DUST, 0, LVar0, LVar1, LVar2, 40)
            Call(RandInt, 20, LVar0)
            Add(LVar0, 20)
            Wait(LVar0)
        EndLoop
    EndThread
    Thread
        Loop(7)
            Call(GetPlayerPos, LVar1, LVar2, LVar3)
            Call(RandInt, 200, LVar4)
            Sub(LVar4, 100)
            Call(RandInt, 200, LVar5)
            Sub(LVar5, 100)
            Add(LVar1, LVar4)
            Add(LVar2, 200)
            Add(LVar3, LVar5)
            PlayEffect(EFFECT_SHATTERING_STONES, 0, LVar1, LVar2, LVar3, 187)
            Call(RandInt, 30, LVar0)
            Add(LVar0, 30)
            Wait(LVar0)
        EndLoop
    EndThread
    Wait(20)
    Call(MakeLerp, 187, 0, 300, EASING_COS_IN_OUT)
    Label(0)
    Call(UpdateLerp)
    Call(TranslateModel, MODEL_dan, 0, LVar0, 0)
    Call(TranslateModel, MODEL_k_soku, 0, LVar0, 0)
    Call(TranslateModel, MODEL_kusari, 0, LVar0, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(0)
    EndIf
    Call(UpdateColliderTransform, COLLIDER_o54)
    Call(UpdateColliderTransform, COLLIDER_o55)
    Call(UpdateColliderTransform, COLLIDER_o65)
    Call(StopSound, SOUND_LOOP_TRD_02_LOWER_STAIRS)
    Call(PlaySound, SOUND_TRD_02_STAIRS_LOWERED)
    Set(GB_StoryProgress, STORY_CH1_LOWERED_SECOND_STAIRS)
    Call(DisablePlayerInput, FALSE)
    Call(SetTimeFreezeMode, 0)
    ResumeGroup(EVT_GROUP_01)
    Unbind
    Return
    End
};

BombTrigger N(D_8024240C_9A33EC) = {
    .pos = { 255.0f, 50.0f, -80.0f },
    .radius = 0.0f
};

EvtScript N(D_8024241C_9A33FC) = {
    SetGroup(EVT_GROUP_00)
    SuspendGroup(EVT_GROUP_01)
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 17, 11, 1, 10, 30)
    Call(EnableModel, MODEL_anaaki, TRUE)
    Loop(10)
        Call(SetGroupVisibility, MODEL_g14, MODEL_GROUP_VISIBLE)
        Wait(1)
        Call(SetGroupVisibility, MODEL_g14, MODEL_GROUP_HIDDEN)
        Wait(1)
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tta, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_TRD02_BombedWall, TRUE)
    ResumeGroup(EVT_GROUP_01)
    Unbind
    Return
    End
};

s32 N(D_8024252C_9A350C)[] = {
    ITEM_KOOPA_FORTRESS_KEY,
    ITEM_NONE
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_KOOPA_BROS_FORTRESS)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    BindTrigger(Ref(N(EVS_ExitDoors_trd_01_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_trd_03_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    IfEq(GF_TRD02_UnlockedDoor, FALSE)
        BindPadlock(Ref(N(D_80242890_9A3870)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), Ref(N(D_8024252C_9A350C)), 0, 1)
    Else
        BindTrigger(Ref(N(EVS_ExitDoors_trd_01_2)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw2, 1, 0)
    EndIf
    BindTrigger(Ref(N(EVS_ExitDoors_trd_03_2)), TRIGGER_WALL_PRESS_A, COLLIDER_tte2, 1, 0)
    IfEq(GF_TRD02_BombedWall, FALSE)
        Call(EnableModel, MODEL_anaaki, FALSE)
        BindTrigger(Ref(N(D_8024241C_9A33FC)), TRIGGER_POINT_BOMB, Ref(N(D_8024240C_9A33EC)), 1, 0)
    Else
        Call(SetGroupVisibility, MODEL_g14, MODEL_GROUP_HIDDEN)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tta, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Exec(N(EVS_SetupMusic))
    Set(AF_TRD02_LowerStairs, FALSE)
    Call(ParentColliderToModel, COLLIDER_o55, MODEL_dan)
    Call(ParentColliderToModel, COLLIDER_o54, MODEL_k_soku)
    Call(ParentColliderToModel, COLLIDER_o65, MODEL_kusari)
    IfLt(GB_StoryProgress, STORY_CH1_LOWERED_SECOND_STAIRS)
        Call(TranslateModel, MODEL_dan, 0, 187, 0)
        Call(TranslateModel, MODEL_k_soku, 0, 187, 0)
        Call(TranslateModel, MODEL_kusari, 0, 187, 0)
        Call(UpdateColliderTransform, COLLIDER_o55)
        Call(UpdateColliderTransform, COLLIDER_o54)
        Call(UpdateColliderTransform, COLLIDER_o65)
        BindTrigger(Ref(N(EVS_Scene_LowerStairs)), TRIGGER_AREA_FLAG_SET, AF_TRD02_LowerStairs, 1, 0)
    Else
        Call(UpdateColliderTransform, COLLIDER_o55)
        Call(UpdateColliderTransform, COLLIDER_o54)
        Call(UpdateColliderTransform, COLLIDER_o65)
        Call(SetGroupVisibility, MODEL_move_saku, MODEL_GROUP_HIDDEN)
    EndIf
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
