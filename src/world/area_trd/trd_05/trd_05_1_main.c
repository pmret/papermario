#include "trd_05.h"
#include "effects.h"

extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_KoopaBros_SetTrap);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

API_CALLABLE(N(SetMapChangeFadeRate)) {
    set_map_change_fade_rate(5);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitDoors_trd_04_1) = EVT_EXIT_DOUBLE_DOOR(trd_05_ENTRY_0, "trd_04", trd_04_ENTRY_1, COLLIDER_ttw, MODEL_doa2, MODEL_doa1);
EvtScript N(EVS_ExitDoors_trd_00_2) = EVT_EXIT_DOUBLE_DOOR(trd_05_ENTRY_1, "trd_00", trd_00_ENTRY_2, COLLIDER_ttse, MODEL_doa4, MODEL_doa6);
EvtScript N(EVS_ExitWalk_trd_00_3) = EVT_EXIT_WALK(60, trd_05_ENTRY_2, "trd_00", trd_00_ENTRY_3);
EvtScript N(EVS_ExitDoors_trd_04_3) = EVT_EXIT_DOUBLE_DOOR(trd_05_ENTRY_3, "trd_04", trd_04_ENTRY_3, COLLIDER_ttw2, MODEL_doa7, MODEL_doa8);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_trd_04_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_trd_00_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_trd_00_2)), TRIGGER_WALL_PRESS_A, COLLIDER_ttse, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_trd_04_3)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw2, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    SetGroup(EVT_GROUP_00)
    SuspendGroup(EVT_GROUP_01)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(trd_05_ENTRY_0)
            Set(LVar2, MODEL_doa2)
            Set(LVar3, MODEL_doa1)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(trd_05_ENTRY_1)
            Set(LVar2, MODEL_doa4)
            Set(LVar3, MODEL_doa6)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(trd_05_ENTRY_2)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(trd_05_ENTRY_3)
            Set(LVar2, MODEL_doa7)
            Set(LVar3, MODEL_doa8)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
    ResumeGroup(EVT_GROUP_01)
    Return
    End
};

BombTrigger N(BombPos_Wall) = {
    .pos = { 300.0f, 0.0f, 0.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BombWall) = {
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 29, 0, 1, 10, 30)
    SetGroup(EVT_GROUP_00)
    SuspendGroup(EVT_GROUP_01)
    Call(SetGroupVisibility, MODEL_ana2, MODEL_GROUP_VISIBLE)
    Loop(10)
        Call(SetGroupVisibility, MODEL_ana3, MODEL_GROUP_VISIBLE)
        Wait(1)
        Call(SetGroupVisibility, MODEL_ana3, MODEL_GROUP_HIDDEN)
        Wait(1)
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tte, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_TRD05_BombedWall, TRUE)
    ResumeGroup(EVT_GROUP_01)
    Unbind
    Return
    End
};

EvtScript N(EVS_TexPan_Water) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, MODEL_suimen, TEX_PANNER_1)
    Set(LVar0, 0)
    Set(LVar1, 0)
        Label(10)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_AUX, LVar1, 0)
        Add(LVar0, 100)
        Sub(LVar1, 100)
        Wait(1)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_KOOPA_BROS_FORTRESS)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    IfEq(GF_TRD05_BombedWall, FALSE)
        Call(SetGroupVisibility, MODEL_ana2, MODEL_GROUP_HIDDEN)
        BindTrigger(Ref(N(EVS_BombWall)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Wall)), 1, 0)
    Else
        Call(SetGroupVisibility, MODEL_ana3, MODEL_GROUP_HIDDEN)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tte, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_TexPan_Water))
    Call(EnableModel, MODEL_o95, FALSE)
    Call(EnableModel, MODEL_o96, FALSE)
    Call(SetGroupVisibility, MODEL_kesu, MODEL_GROUP_HIDDEN)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o103, COLLIDER_FLAGS_UPPER_MASK)
    IfLt(GB_StoryProgress, STORY_CH1_KOOPA_BROS_SET_TRAP)
        Wait(10)
        Call(N(SetMapChangeFadeRate))
        Exec(N(EVS_KoopaBros_SetTrap))
    Else
        Exec(N(EVS_EnterMap))
    EndIf
    Wait(1)
    Return
    End
};
