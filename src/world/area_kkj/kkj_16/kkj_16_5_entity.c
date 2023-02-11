#include "kkj_16.h"
#include "entity.h"

// immediately remove the item from Peach's inventory, keeping only the flag
EvtScript N(EVS_AutoRemovePowerRush) = {
    EVT_LOOP(0)
        EVT_IF_EQ(GF_KKJ16_Item_PowerRush, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(RemoveBadge, ITEM_POWER_RUSH)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_LIFE_SHROOM, -840, 110, 10, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KKJ16_Item_LifeShroom)
    EVT_CALL(MakeItemEntity, ITEM_POWER_RUSH, -550, 0, -120, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KKJ16_Item_PowerRush)
    EVT_IF_LT(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        EVT_IF_EQ(GF_KKJ16_Item_PowerRush, FALSE)
            EVT_EXEC(N(EVS_AutoRemovePowerRush))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
