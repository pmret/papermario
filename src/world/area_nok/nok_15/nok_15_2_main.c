#include "nok_15.h"
#include "effects.h"

#include "world/common/entity/Pipe.inc.c"

EvtScript N(EVS_ExitWalk_nok_14_1) = EVT_EXIT_WALK_NOK(60, nok_15_ENTRY_0, "nok_14", nok_14_ENTRY_1);
EvtScript N(EVS_ExitWalk_trd_00_0) = EVT_EXIT_WALK_NOK(60, nok_15_ENTRY_1, "trd_00", trd_00_ENTRY_0);
EvtScript N(EVS_ExitWalk_trd_00_4) = EVT_EXIT_WALK_NOK(60, nok_15_ENTRY_2, "trd_00", trd_00_ENTRY_4);

BombTrigger N(BombPos_Wall) = {
    .pos = { -26.0f, 0.0f, -531.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BlastWall) = {
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 60, 61, 1, 10, 30)
    Set(GF_NOK15_BombedWall, TRUE)
    Call(EnableModel, MODEL_bomb_ato, TRUE)
    Call(EnableModel, MODEL_bomb_1, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    Unbind
    Return
    End
};

EvtScript N(EVS_TexPan_Water) = {
    Thread
        Call(SetTexPanner, MODEL_suimen1, TEX_PANNER_1)
        Set(LVar0, 0)
        Set(LVar1, 0)
        Set(LVar2, 0)
        Label(10)
            Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
            Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_AUX, LVar1, LVar2)
            Sub(LVar0, 100)
            Sub(LVar1, 400)
            Add(LVar1, 1000)
            Wait(1)
            Goto(10)
    EndThread
    Call(SetTexPanner, MODEL_kabemizu1, TEX_PANNER_2)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Set(LVar2, 0)
    Label(20)
        Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar0, 0)
        Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_AUX, LVar1, LVar2)
        Sub(LVar0, 100)
        Add(LVar1, 800)
        Sub(LVar2, 400)
        Wait(1)
        Goto(20)
    Return
    End
};

EvtScript N(EVS_GotoMap_nok_15_4) = {
    Call(GotoMap, Ref("nok_15"), nok_15_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_GotoMap_nok_15_3) = {
    Call(GotoMap, Ref("nok_15"), nok_15_ENTRY_3)
    Wait(100)
    Return
    End
};

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_ExitPipe) = {
    Set(LVarA, LVar0)
    Set(LVarB, LVar1)
    Set(LVarC, LVar2)
    ExecWait(N(EVS_Pipe_ExitVertical))
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_nok_14_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_trd_00_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_trd_00_4)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    Set(LVar0, nok_15_ENTRY_3)
    Set(LVar1, COLLIDER_o680)
    Set(LVar2, Ref(N(EVS_GotoMap_nok_15_4)))
    BindTrigger(Ref(N(EVS_ExitPipe)), TRIGGER_FLOOR_TOUCH, LVar1, 1, 0)
    Set(LVar0, nok_15_ENTRY_4)
    Set(LVar1, COLLIDER_o679)
    Set(LVar2, Ref(N(EVS_GotoMap_nok_15_3)))
    BindTrigger(Ref(N(EVS_ExitPipe)), TRIGGER_FLOOR_TOUCH, LVar1, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PLEASANT_PATH)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupFoliage))
    Exec(N(EVS_TexPan_Water))
    IfEq(GF_NOK15_BombedWall, FALSE)
        Call(EnableModel, MODEL_bomb_ato, FALSE)
        BindTrigger(Ref(N(EVS_BlastWall)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Wall)), 1, 0)
    Else
        Call(EnableModel, MODEL_bomb_1, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Exec(N(EVS_SetupMusic))
    Call(GetEntryID, LVar0)
    IfLe(LVar0, nok_15_ENTRY_2)
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
    Else
        Set(LVarA, Ref(N(EVS_BindExitTriggers)))
        Exec(N(EVS_Pipe_EnterVertical))
    EndIf
    Wait(1)
    Return
    End
};
