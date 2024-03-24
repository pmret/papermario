#include "kzn_17.h"
#include "entity.h"

s32 N(Unused_80243610_3610)[] = {
    0x01010101, 0x01010101, 0x01010101, 0x01010101,
    0x01010101, 0x01010101, 0x01010101, 0x01010101,
    0x01010101, 0x01010101, 0x01010101, 0x01010101,
    0x01010101, 0x01010101, 0x01010000,
};

EvtScript N(EVS_OnBreakBlockA) = {
    Set(GF_KZN17_Hammer3BlockA, TRUE)
    Return
    End
};

EvtScript N(EVS_OnBreakBlockB) = {
    Set(GF_KZN17_Hammer3BlockB, TRUE)
    Return
    End
};

EvtScript N(EVS_OnBreakBlockC) = {
    Set(GF_KZN17_Hammer3BlockC, TRUE)
    Return
    End
};

EvtScript N(EVS_OnBreakBlockD) = {
    Set(GF_KZN17_Hammer3BlockD, TRUE)
    Return
    End
};

EvtScript N(EVS_OnBreakBlockE) = {
    Set(GF_KZN17_Hammer3BlockE, TRUE)
    Return
    End
};

EvtScript N(EVS_OnBreakBlockF) = {
    Set(GF_KZN17_Hammer3BlockF, TRUE)
    Return
    End
};

EvtScript N(EVS_OnBreakBlockG) = {
    Set(GF_KZN17_Hammer3BlockG, TRUE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_KZN17_Hammer3BlockA, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer3Block), -195, 50, 27, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnBreakBlockA)))
    EndIf
    IfEq(GF_KZN17_Hammer3BlockB, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer3Block), -245, 60, 27, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnBreakBlockB)))
    EndIf
    IfEq(GF_KZN17_Hammer3BlockC, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer3Block), -295, 70, 27, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnBreakBlockC)))
    EndIf
    IfEq(GF_KZN17_Hammer3BlockD, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer3Block), -345, 80, 27, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnBreakBlockD)))
    EndIf
    IfEq(GF_KZN17_Hammer3BlockE, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer3Block), -395, 90, 27, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnBreakBlockE)))
    EndIf
    IfEq(GF_KZN17_Hammer3BlockF, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer3Block), -445, 100, 27, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnBreakBlockF)))
    EndIf
    IfEq(GF_KZN17_Hammer3BlockG, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer3Block), -495, 110, 27, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnBreakBlockG)))
    EndIf
    Call(CreatePushBlockGrid, 0, 29, 2, -119, -3, 5, 0)
    Call(SetPushBlock, 0, 28, 1, PUSH_GRID_BLOCK)
    Return
    End
};
