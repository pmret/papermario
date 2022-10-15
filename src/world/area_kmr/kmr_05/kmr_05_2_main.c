#include "kmr_05.h"

EvtScript N(EVS_ExitWalk_kmr_03_1) = EVT_EXIT_WALK(60, kmr_05_ENTRY_0, "kmr_03", kmr_03_ENTRY_1);
EvtScript N(EVS_ExitWalk_kmr_02_2) = EVT_EXIT_WALK(60, kmr_05_ENTRY_1, "kmr_02", kmr_02_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kmr_03_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kmr_02_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_GOOMBA_VILLAGE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_IF_EQ(GF_KMR02_ReturnedWithGoompa, FALSE)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcsBefore)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcsAfter)))
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC_WAIT(N(EVS_SetupFoliage))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilit1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilit2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kmr_05_ENTRY_0)
        EVT_IF_EQ(GF_KMR05_EnemyWarning, FALSE)
            EVT_EXEC(N(EVS_GoompaRemark))
            EVT_SET(GF_KMR05_EnemyWarning, TRUE)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
