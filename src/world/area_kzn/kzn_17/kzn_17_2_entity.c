#include "kzn_17.h"
#include "entity.h"

s32 N(Unused_80243610_3610)[] = {
    0x01010101, 0x01010101, 0x01010101, 0x01010101,
    0x01010101, 0x01010101, 0x01010101, 0x01010101,
    0x01010101, 0x01010101, 0x01010101, 0x01010101,
    0x01010101, 0x01010101, 0x01010000,
};

EvtScript N(EVS_OnBreakBlockA) = {
    EVT_SET(GF_KZN17_Hammer3BlockA, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnBreakBlockB) = {
    EVT_SET(GF_KZN17_Hammer3BlockB, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnBreakBlockC) = {
    EVT_SET(GF_KZN17_Hammer3BlockC, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnBreakBlockD) = {
    EVT_SET(GF_KZN17_Hammer3BlockD, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnBreakBlockE) = {
    EVT_SET(GF_KZN17_Hammer3BlockE, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnBreakBlockF) = {
    EVT_SET(GF_KZN17_Hammer3BlockF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnBreakBlockG) = {
    EVT_SET(GF_KZN17_Hammer3BlockG, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_KZN17_Hammer3BlockA, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), -195, 50, 27, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnBreakBlockA)))
    EVT_END_IF
    EVT_IF_EQ(GF_KZN17_Hammer3BlockB, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), -245, 60, 27, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnBreakBlockB)))
    EVT_END_IF
    EVT_IF_EQ(GF_KZN17_Hammer3BlockC, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), -295, 70, 27, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnBreakBlockC)))
    EVT_END_IF
    EVT_IF_EQ(GF_KZN17_Hammer3BlockD, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), -345, 80, 27, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnBreakBlockD)))
    EVT_END_IF
    EVT_IF_EQ(GF_KZN17_Hammer3BlockE, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), -395, 90, 27, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnBreakBlockE)))
    EVT_END_IF
    EVT_IF_EQ(GF_KZN17_Hammer3BlockF, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), -445, 100, 27, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnBreakBlockF)))
    EVT_END_IF
    EVT_IF_EQ(GF_KZN17_Hammer3BlockG, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), -495, 110, 27, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnBreakBlockG)))
    EVT_END_IF
    EVT_CALL(CreatePushBlockGrid, 0, 29, 2, -119, -3, 5, 0)
    EVT_CALL(SetPushBlock, 0, 28, 1, PUSH_GRID_BLOCK)
    EVT_RETURN
    EVT_END
};
