#include "sam_10.h"
#include "entity.h"

#include "world/common/todo/StashVars.inc.c"
#include "world/common/todo/GetItemName.inc.c"
#include "world/common/todo/SomeItemEntityFunc.inc.c"
#include "world/common/todo/IsItemBadge.inc.c"

s32** N(varStash) = NULL;

EvtScript N(EVS_Chest_ShowGotItem) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_FULL)
    Wait(40)
    Call(ShowGotItem, LVar0, FALSE, 0)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Return
    Return
    End
};

API_CALLABLE(N(SetStarStoneItemScale)) {
    get_item_entity(script->varTable[0])->scale = 0.8f;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_RedBlock), 775, 540, -50, 0, ITEM_MEGA_JUMP, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SAM10_BadgeBlock_MegaJump)
    Call(MakeItemEntity, ITEM_STAR_PIECE, -160, 300, -110, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM10_Item_StarPiece)
    IfLt(GB_StoryProgress, STORY_CH7_RAISED_FROZEN_STAIRS)
        Call(DropResizableItemEntity, ITEM_STAR_STONE, NPC_DISPOSE_LOCATION, ITEM_SPAWN_MODE_DECORATION, 0)
        Call(N(SetStarStoneItemScale))
        Set(MV_StarStoneItemID, LVar0)
    Else
        Call(DropResizableItemEntity, ITEM_STAR_STONE, -117, 179, -55, ITEM_SPAWN_MODE_DECORATION, 0)
        Call(N(SetStarStoneItemScale))
    EndIf
    Call(MakeEntity, Ref(Entity_SavePoint), -250, 870, -210, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HeartBlock), 770, 1200, -225, 0, MAKE_ENTITY_END)
    Return
    End
};
