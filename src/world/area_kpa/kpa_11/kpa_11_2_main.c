#include "kpa_11.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_kpa_62_1) = EVT_EXIT_WALK(60, kpa_11_ENTRY_0, "kpa_62", kpa_62_ENTRY_1);
EvtScript N(EVS_ExitWalk_kpa_12_0) = EVT_EXIT_WALK(60, kpa_11_ENTRY_1, "kpa_12", kpa_12_ENTRY_0);
EvtScript N(EVS_ExitWalk_kpa_17_1) = EVT_EXIT_WALK(60, kpa_11_ENTRY_2, "kpa_17", kpa_17_ENTRY_1);
EvtScript N(EVS_ExitWalk_kpa_62_2) = EVT_EXIT_WALK(60, kpa_11_ENTRY_3, "kpa_62", kpa_62_ENTRY_2);
EvtScript N(EVS_ExitWalk_kpa_12_2) = EVT_EXIT_WALK(60, kpa_11_ENTRY_4, "kpa_12", kpa_12_ENTRY_2);

MAP_RODATA_PAD(1, strings);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_62_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_12_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_17_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_62_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_12_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    Return
    End
};

EvtScript N(D_80240F04_A537C4) = {
    Call(GetLoadType, LVar0)
    IfEq(LVar0, 1)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Return
    End
};

EvtScript N(D_80240F84_A53844) = {
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP( -400,    0, -800,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_o1871, 0)
    Call(SetTexPanner, MODEL_o1815, 0)
    Call(SetTexPanner, MODEL_o1816, 0)
    Call(SetTexPanner, MODEL_o1817, 0)
    Call(SetTexPanner, MODEL_o1818, 0)
    Call(SetTexPanner, MODEL_o1819, 0)
    Call(SetTexPanner, MODEL_o1820, 0)
    Call(SetTexPanner, MODEL_o1821, 0)
    Call(SetTexPanner, MODEL_o1822, 0)
    Call(SetTexPanner, MODEL_o1823, 0)
    Call(SetTexPanner, MODEL_o1824, 0)
    Call(SetTexPanner, MODEL_o1825, 0)
    Call(SetTexPanner, MODEL_o1826, 0)
    Call(SetTexPanner, MODEL_o1827, 0)
    Call(SetTexPanner, MODEL_o1828, 0)
    Call(SetTexPanner, MODEL_o1829, 0)
    Return
    End
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o1234, .pos = { 1400.0,   30.0, -325.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(D_80240F84_A53844))
    IfEq(GF_KPA17_BombedWall, TRUE)
        Call(EnableGroup, MODEL_g301, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Exec(N(D_80240F04_A537C4))
    Exec(N(EVS_SetupMusic))
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Thread
            Wait(2)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1266, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1265, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1264, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1263, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1262, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1261, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1260, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1253, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1254, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1255, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1256, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1257, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1258, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1259, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilise, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilisw, SURFACE_TYPE_LAVA)
            Thread
                Call(ResetFromLava, Ref(N(SafeFloorColliders)))
            EndThread
        EndThread
    EndIf
    Return
    End
};
