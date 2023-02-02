#include "sam_10.h"
#include "entity.h"

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

API_CALLABLE(N(SetStarStoneItemScale)) {
    get_item_entity(script->varTable[0])->scale = 0.8f;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_RedBlock), 775, 540, -50, 0, ITEM_MEGA_JUMP, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SAM10_BadgeBlock_MegaJump)
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, -160, 300, -110, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM10_Item_StarPiece)
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_RAISED_FROZEN_STAIRS)
        EVT_CALL(DropResizableItemEntity, ITEM_STAR_STONE, NPC_DISPOSE_LOCATION, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_CALL(N(SetStarStoneItemScale))
        EVT_SET(MV_StarStoneItemID, LVar0)
    EVT_ELSE
        EVT_CALL(DropResizableItemEntity, ITEM_STAR_STONE, -117, 179, -55, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_CALL(N(SetStarStoneItemScale))
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -250, 870, -210, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), 770, 1200, -225, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
