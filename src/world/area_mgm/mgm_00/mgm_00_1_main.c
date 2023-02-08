#include "mgm_00.h"

// probably a blank EVS_SetupMusic
EvtScript N(D_80241850_E0FFF0) = {
    EVT_RETURN
    EVT_END
};

#include "world/common/entity/Pipe.inc.c"

EvtScript N(EVS_GotoMap_ToadTown) = {
    EVT_CALL(GotoMap, EVT_PTR("mac_03"), mac_03_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnEnterPipe_ToadTown) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_SET(LVarA, mgm_00_ENTRY_0)
    EVT_SET(LVarB, COLLIDER_deili1)
    EVT_SET(LVarC, EVT_PTR(N(EVS_GotoMap_ToadTown)))
    EVT_EXEC_WAIT(N(EVS_Pipe_ExitHorizontal))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_JumpAttack) = {
    EVT_CALL(GotoMap, EVT_PTR("mgm_01"), mgm_01_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnEnterPipe_JumpAttack) = EVT_EXIT_PIPE_VERTICAL(
    mgm_00_ENTRY_1, COLLIDER_deili2, N(EVS_GotoMap_JumpAttack));

EvtScript N(EVS_GotoMap_SmashAttack) = {
    EVT_CALL(GotoMap, EVT_PTR("mgm_02"), mgm_02_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1, unk);

EvtScript N(EVS_OnEnterPipe_SmashAttack) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_SET(LVarA, mgm_00_ENTRY_2)
    EVT_SET(LVarB, COLLIDER_deili3)
    EVT_SET(LVarC, EVT_PTR(N(EVS_GotoMap_SmashAttack)))
    EVT_EXEC_WAIT(N(EVS_Pipe_ExitVertical))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnEnterPipe_ToadTown)), TRIGGER_WALL_PUSH, COLLIDER_deili1, 1, 0)
    EVT_IF_EQ(GF_MGM_Unlocked_JumpAttack, TRUE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnEnterPipe_JumpAttack)), TRIGGER_FLOOR_TOUCH, COLLIDER_deili2, 1, 0)
    EVT_END_IF
    EVT_IF_EQ(GF_MGM_Unlocked_SmashAttack, TRUE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnEnterPipe_SmashAttack)), TRIGGER_FLOOR_TOUCH, COLLIDER_deili3, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_IF_EQ(GF_MGM_Unlocked_JumpAttack, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o5, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deili2, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, MODEL_o5, FALSE)
    EVT_END_IF
    EVT_IF_EQ(GF_MGM_Unlocked_SmashAttack, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o9, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deili3, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, MODEL_o9, FALSE)
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(mgm_00_ENTRY_0)
            EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_SET(LVarB, 1)
            EVT_EXEC(N(EVS_Pipe_EnterHorizontal))
        EVT_CASE_EQ(mgm_00_ENTRY_1)
            EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(N(EVS_Pipe_EnterVertical))
        EVT_CASE_EQ(mgm_00_ENTRY_2)
            EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(N(EVS_Pipe_EnterVertical))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_EXEC_WAIT(N(D_80243C40_E123E0))
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(D_80241850_E0FFF0))
    EVT_EXEC(N(EVS_BindInteractTriggers))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
