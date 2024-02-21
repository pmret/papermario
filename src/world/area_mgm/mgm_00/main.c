#include "mgm_00.h"

// probably a blank EVS_SetupMusic
EvtScript N(D_80241850_E0FFF0) = {
    Return
    End
};

#include "world/common/entity/Pipe.inc.c"

EvtScript N(EVS_GotoMap_ToadTown) = {
    Call(GotoMap, Ref("mac_03"), mac_03_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_OnEnterPipe_ToadTown) = {
    SetGroup(EVT_GROUP_1B)
    Set(LVarA, mgm_00_ENTRY_0)
    Set(LVarB, COLLIDER_deili1)
    Set(LVarC, Ref(N(EVS_GotoMap_ToadTown)))
    ExecWait(N(EVS_Pipe_ExitHorizontal))
    Return
    End
};

EvtScript N(EVS_GotoMap_JumpAttack) = {
    Call(GotoMap, Ref("mgm_01"), mgm_01_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_OnEnterPipe_JumpAttack) = EVT_EXIT_PIPE_VERTICAL(
    mgm_00_ENTRY_1, COLLIDER_deili2, N(EVS_GotoMap_JumpAttack));

EvtScript N(EVS_GotoMap_SmashAttack) = {
    Call(GotoMap, Ref("mgm_02"), mgm_02_ENTRY_0)
    Wait(100)
    Return
    End
};

MAP_RODATA_PAD(1, unk);

EvtScript N(EVS_OnEnterPipe_SmashAttack) = {
    SetGroup(EVT_GROUP_1B)
    Set(LVarA, mgm_00_ENTRY_2)
    Set(LVarB, COLLIDER_deili3)
    Set(LVarC, Ref(N(EVS_GotoMap_SmashAttack)))
    ExecWait(N(EVS_Pipe_ExitVertical))
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_OnEnterPipe_ToadTown)), TRIGGER_WALL_PUSH, COLLIDER_deili1, 1, 0)
    IfEq(GF_MGM_Unlocked_JumpAttack, TRUE)
        BindTrigger(Ref(N(EVS_OnEnterPipe_JumpAttack)), TRIGGER_FLOOR_TOUCH, COLLIDER_deili2, 1, 0)
    EndIf
    IfEq(GF_MGM_Unlocked_SmashAttack, TRUE)
        BindTrigger(Ref(N(EVS_OnEnterPipe_SmashAttack)), TRIGGER_FLOOR_TOUCH, COLLIDER_deili3, 1, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    IfEq(GF_MGM_Unlocked_JumpAttack, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o5, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deili2, COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, MODEL_o5, FALSE)
    EndIf
    IfEq(GF_MGM_Unlocked_SmashAttack, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o9, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deili3, COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, MODEL_o9, FALSE)
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(mgm_00_ENTRY_0)
            Set(LVarA, Ref(N(EVS_BindExitTriggers)))
            Set(LVarB, 1)
            Exec(N(EVS_Pipe_EnterHorizontal))
        CaseEq(mgm_00_ENTRY_1)
            Set(LVarA, Ref(N(EVS_BindExitTriggers)))
            Exec(N(EVS_Pipe_EnterVertical))
        CaseEq(mgm_00_ENTRY_2)
            Set(LVarA, Ref(N(EVS_BindExitTriggers)))
            Exec(N(EVS_Pipe_EnterVertical))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    SetUP_CAMERA_NO_LEAD()
    ExecWait(N(D_80243C40_E123E0))
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(D_80241850_E0FFF0))
    Exec(N(EVS_BindInteractTriggers))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
