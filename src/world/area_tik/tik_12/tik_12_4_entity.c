#include "tik_12.h"
#include "entity.h"

// begin incomplete Chest include
//#include "world/common/entity/Chest.inc.c"

#include "world/common/todo/StashVars.inc.c"
#include "world/common/todo/GetItemName.inc.c"
#include "world/common/todo/SomeItemEntityFunc.inc.c"
#include "world/common/todo/IsItemBadge.inc.c"

s32** N(varStash) = NULL;

EvtScript N(EVS_Chest_ShowGotItem) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_FULL)
    EVT_WAIT(40)
    EVT_CALL(ShowGotItem, LVar0, FALSE, 0)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1,unk);

// end incomplete Chest include

#define SUPER_BLOCK_MAPVAR MV_SuperBlock
#define SUPER_BLOCK_GAMEFLAG GF_TIK02_SuperBlock
#include "world/common/entity/SuperBlock.inc.c"

EvtScript N(EVS_SmashBlockA) = {
    EVT_SET(GF_TIK12_Hammer3BlockA, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SmashBlockB) = {
    EVT_SET(GF_TIK12_Hammer3BlockB, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_MAKE_SUPER_BLOCK(240, 0, -40, 0)
    EVT_IF_EQ(GF_TIK12_Hammer3BlockA, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), 140, -135, 55, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_SmashBlockA)))
    EVT_END_IF
    EVT_IF_EQ(GF_TIK12_Hammer3BlockB, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), 140, -135, 105, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_SmashBlockB)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
