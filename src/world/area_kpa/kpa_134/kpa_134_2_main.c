#include "kpa_134.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_kpa_133_1) = EVT_EXIT_WALK(40, kpa_134_ENTRY_0, "kpa_133", kpa_133_ENTRY_1);
EvtScript N(EVS_ExitDoors_kpa_130_0) = EVT_EXIT_DOUBLE_DOOR(kpa_134_ENTRY_1, "kpa_130", kpa_130_ENTRY_0, COLLIDER_nno, MODEL_o408, MODEL_o409);
EvtScript N(EVS_ExitWalk_kpa_133_2) = EVT_EXIT_WALK(40, kpa_134_ENTRY_2, "kpa_133", kpa_133_ENTRY_2);
EvtScript N(EVS_ExitWalk_kpa_133_3) = EVT_EXIT_WALK(40, kpa_134_ENTRY_3, "kpa_133", kpa_133_ENTRY_3);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_133_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_exitw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_133_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilite, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_133_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_g98, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_134_ENTRY_0)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(kpa_134_ENTRY_1)
            Set(LVar0, 1)
            Set(LVar2, MODEL_o408)
            Set(LVar3, MODEL_o409)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_134_ENTRY_2)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(kpa_134_ENTRY_3)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupChains))
    IfEq(GF_KPA134_BlueSwitch, FALSE)
        BindTrigger(Ref(N(EVS_FlipWallPanels)), TRIGGER_AREA_FLAG_SET, AF_KPA134_HitWaterSwitch, 1, 0)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o383, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o384, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_sikake, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, MODEL_o384, FALSE)
        Call(EnableModel, MODEL_o383, FALSE)
        Call(EnableModel, MODEL_o378, FALSE)
        Call(EnableModel, MODEL_o379, FALSE)
        Call(EnableModel, MODEL_o380, FALSE)
        Call(EnableModel, MODEL_o381, FALSE)
        Call(EnableModel, MODEL_o382, FALSE)
        Call(EnableModel, MODEL_o377, FALSE)
        Call(EnableModel, MODEL_o376, FALSE)
        Call(EnableModel, MODEL_o375, FALSE)
        Call(EnableModel, MODEL_o374, FALSE)
        Call(EnableModel, MODEL_o373, FALSE)
        Call(EnableModel, MODEL_o372, FALSE)
        Call(EnableModel, MODEL_o371, FALSE)
    EndIf
    IfEq(GF_KPA133_Item_BombedWall, TRUE)
        Call(EnableModel, MODEL_o503, FALSE)
        Call(EnableModel, MODEL_o502, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o358, COLLIDER_FLAGS_UPPER_MASK)
    Else
        Call(EnableModel, MODEL_o400, FALSE)
    EndIf
    Call(EnableTexPanning, MODEL_move, TRUE)
    Call(EnableTexPanning, MODEL_s_sui, TRUE)
    Call(EnableTexPanning, MODEL_o385, TRUE)
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
