#include "kpa_133.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitDoors_kpa_51_1) = EVT_EXIT_DOUBLE_DOOR(kpa_133_ENTRY_0, "kpa_51", kpa_51_ENTRY_1, COLLIDER_ttw, MODEL_o486, MODEL_o485);
EvtScript N(EVS_ExitWalk_kpa_134_0) = EVT_EXIT_WALK(40, kpa_133_ENTRY_1, "kpa_134", kpa_134_ENTRY_0);
EvtScript N(EVS_ExitWalk_kpa_134_2) = EVT_EXIT_WALK(40, kpa_133_ENTRY_2, "kpa_134", kpa_134_ENTRY_2);
EvtScript N(EVS_ExitWalk_kpa_134_3) = EVT_EXIT_WALK(40, kpa_133_ENTRY_3, "kpa_134", kpa_134_ENTRY_3);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_51_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_134_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_134_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie2, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_134_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliae, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_133_ENTRY_0)
            Set(LVar0, kpa_133_ENTRY_0)
            Set(LVar2, MODEL_o486)
            Set(LVar3, MODEL_o485)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_133_ENTRY_1)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(kpa_133_ENTRY_2)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(kpa_133_ENTRY_3)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

BombTrigger N(BombPos_Wall) = {
    .pos = { 388.0f, 240.0f, -25.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BlastWall) = {
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 56, 56, 1, 10, 30)
    SetGroup(EVT_GROUP_00)
    SuspendGroup(EVT_GROUP_01)
    Call(EnableModel, MODEL_o235, TRUE)
    Loop(10)
        Call(EnableModel, MODEL_o477, TRUE)
        Call(EnableModel, MODEL_o476, TRUE)
        Wait(1)
        Call(EnableModel, MODEL_o477, FALSE)
        Call(EnableModel, MODEL_o476, FALSE)
        Wait(1)
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttae, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_KPA133_Item_BombedWall, TRUE)
    ResumeGroup(EVT_GROUP_01)
    Unbind
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    IfEq(GF_KPA133_Item_BombedWall, FALSE)
        Call(EnableModel, MODEL_o235, FALSE)
        BindTrigger(Ref(N(EVS_BlastWall)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Wall)), 1, 0)
    Else
        Call(EnableModel, MODEL_o477, FALSE)
        Call(EnableModel, MODEL_o476, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttae, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Exec(N(EVS_SetWaterLevel))
    BindTrigger(Ref(N(D_80241A90_AA8F10)), TRIGGER_AREA_FLAG_SET, AF_KPA133_HitWaterSwitch, 1, 0)
    Call(EnableTexPanning, MODEL_move, TRUE)
    Call(EnableTexPanning, MODEL_s_sui, TRUE)
    Call(EnableTexPanning, MODEL_sui, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( -100,  100,   70,  -70)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(  200, -100,   20,  -20)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
