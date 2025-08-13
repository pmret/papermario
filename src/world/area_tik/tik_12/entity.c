#include "tik_12.h"
#include "entity.h"

// begin incomplete Chest include
//#include "world/common/entity/Chest.inc.c"

#include "world/common/todo/StashVars.inc.c"
#include "world/common/todo/GetItemName.inc.c"
#include "world/common/todo/SomeItemEntityFunc.inc.c"
#include "world/common/todo/IsItemBadge.inc.c"

s32** N(varStash) = nullptr;

EvtScript N(EVS_Chest_ShowGotItem) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_FULL)
    Wait(40)
    Call(ShowGotItem, LVar0, false, 0)
    Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
    Return
    Return
    End
};

MAP_RODATA_PAD(1,unk);

// end incomplete Chest include

#define SUPER_BLOCK_MAPVAR MV_SuperBlock
#define SUPER_BLOCK_GAMEFLAG GF_TIK02_SuperBlock
#include "world/common/entity/SuperBlock.inc.c"

EvtScript N(EVS_SmashBlockA) = {
    Set(GF_TIK12_Hammer3BlockA, true)
    Return
    End
};

EvtScript N(EVS_SmashBlockB) = {
    Set(GF_TIK12_Hammer3BlockB, true)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    EVT_MAKE_SUPER_BLOCK(240, 0, -40, 0)
    IfEq(GF_TIK12_Hammer3BlockA, false)
        Call(MakeEntity, Ref(Entity_Hammer3Block), 140, -135, 55, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_SmashBlockA)))
    EndIf
    IfEq(GF_TIK12_Hammer3BlockB, false)
        Call(MakeEntity, Ref(Entity_Hammer3Block), 140, -135, 105, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_SmashBlockB)))
    EndIf
    Return
    End
};
