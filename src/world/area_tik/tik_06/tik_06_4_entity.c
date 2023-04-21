#include "tik_06.h"
#include "entity.h"

EvtScript N(EVS_MonitorPlayerFallDown) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_IF_GT(LVar0, -230)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_IF_GE(LVar1, -10)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(func_802CA988, CAM_DEFAULT, LVar2, LVar3, LVar4, LVar5)
    EVT_LABEL(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_IF_GT(LVar1, -70)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("tik_08"), tik_08_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnPound_BoardedFloor) = {
    EVT_SET(GF_TIK02_BoardedFloor, TRUE)
    EVT_EXEC(N(EVS_MonitorPlayerFallDown))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnSmash_Block1) = {
    EVT_SET(GF_TIK02_Hammer1Block, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o93, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnSmash_Block2) = {
    EVT_SET(GF_TIK02_Hammer2Block, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o90, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 120, 50, -75, 0, MAKE_ENTITY_END)
    EVT_CALL(EnableModel, MODEL_o49, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o49, COLLIDER_FLAGS_UPPER_MASK)
    EVT_IF_EQ(GF_TIK02_BoardedFloor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BoardedFloor), -359, -10, -9, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnPound_BoardedFloor)))
    EVT_ELSE
        EVT_EXEC(N(EVS_MonitorPlayerFallDown))
    EVT_END_IF
    EVT_IF_EQ(GF_TIK02_Hammer1Block, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer1Block), 190, -10, 0, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnSmash_Block1)))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o93, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_TIK02_Hammer2Block, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer2Block), -540, -10, 0, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnSmash_Block2)))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o90, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
