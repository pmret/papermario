#include "tik_06.h"
#include "entity.h"

EvtScript N(EVS_MonitorPlayerFallDown) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        IfGt(LVar0, -230)
            Goto(0)
        EndIf
        IfGe(LVar1, -10)
            Goto(0)
        EndIf
    Call(func_802CA988, CAM_DEFAULT, LVar2, LVar3, LVar4, LVar5)
    Label(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        IfGt(LVar1, -70)
            Goto(1)
        EndIf
    Call(GotoMap, Ref("tik_08"), tik_08_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_OnPound_BoardedFloor) = {
    Set(GF_TIK02_BoardedFloor, TRUE)
    Exec(N(EVS_MonitorPlayerFallDown))
    Return
    End
};

EvtScript N(EVS_OnSmash_Block1) = {
    Set(GF_TIK02_Hammer1Block, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o93, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_OnSmash_Block2) = {
    Set(GF_TIK02_Hammer2Block, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o90, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), 120, 50, -75, 0, MAKE_ENTITY_END)
    Call(EnableModel, MODEL_o49, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o49, COLLIDER_FLAGS_UPPER_MASK)
    IfEq(GF_TIK02_BoardedFloor, FALSE)
        Call(MakeEntity, Ref(Entity_BoardedFloor), -359, -10, -9, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnPound_BoardedFloor)))
    Else
        Exec(N(EVS_MonitorPlayerFallDown))
    EndIf
    IfEq(GF_TIK02_Hammer1Block, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer1Block), 190, -10, 0, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnSmash_Block1)))
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o93, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfEq(GF_TIK02_Hammer2Block, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer2Block), -540, -10, 0, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnSmash_Block2)))
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o90, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};
