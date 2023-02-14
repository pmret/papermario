#include "kpa_11.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_kpa_62_1) = EVT_EXIT_WALK(60, kpa_11_ENTRY_0, "kpa_62", kpa_62_ENTRY_1);
EvtScript N(EVS_ExitWalk_kpa_12_0) = EVT_EXIT_WALK(60, kpa_11_ENTRY_1, "kpa_12", kpa_12_ENTRY_0);
EvtScript N(EVS_ExitWalk_kpa_17_1) = EVT_EXIT_WALK(60, kpa_11_ENTRY_2, "kpa_17", kpa_17_ENTRY_1);
EvtScript N(EVS_ExitWalk_kpa_62_2) = EVT_EXIT_WALK(60, kpa_11_ENTRY_3, "kpa_62", kpa_62_ENTRY_2);
EvtScript N(EVS_ExitWalk_kpa_12_2) = EVT_EXIT_WALK(60, kpa_11_ENTRY_4, "kpa_12", kpa_12_ENTRY_2);

MAP_RODATA_PAD(1, strings);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_62_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_12_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_17_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_62_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_12_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240F04_A537C4) = {
    EVT_CALL(GetLoadType, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240F84_A53844) = {
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP( -400,    0, -800,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_o1871, 0)
    EVT_CALL(SetTexPanner, MODEL_o1815, 0)
    EVT_CALL(SetTexPanner, MODEL_o1816, 0)
    EVT_CALL(SetTexPanner, MODEL_o1817, 0)
    EVT_CALL(SetTexPanner, MODEL_o1818, 0)
    EVT_CALL(SetTexPanner, MODEL_o1819, 0)
    EVT_CALL(SetTexPanner, MODEL_o1820, 0)
    EVT_CALL(SetTexPanner, MODEL_o1821, 0)
    EVT_CALL(SetTexPanner, MODEL_o1822, 0)
    EVT_CALL(SetTexPanner, MODEL_o1823, 0)
    EVT_CALL(SetTexPanner, MODEL_o1824, 0)
    EVT_CALL(SetTexPanner, MODEL_o1825, 0)
    EVT_CALL(SetTexPanner, MODEL_o1826, 0)
    EVT_CALL(SetTexPanner, MODEL_o1827, 0)
    EVT_CALL(SetTexPanner, MODEL_o1828, 0)
    EVT_CALL(SetTexPanner, MODEL_o1829, 0)
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o1234, .pos = { 1400.0,   30.0, -325.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(D_80240F84_A53844))
    EVT_IF_EQ(GF_KPA17_BombedWall, TRUE)
        EVT_CALL(EnableGroup, MODEL_g301, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_EXEC(N(D_80240F04_A537C4))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_THREAD
            EVT_WAIT(2)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1266, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1265, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1264, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1263, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1262, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1261, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1260, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1253, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1254, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1255, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1256, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1257, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1258, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1259, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilise, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilisw, SURFACE_TYPE_LAVA)
            EVT_THREAD
                EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
            EVT_END_THREAD
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
