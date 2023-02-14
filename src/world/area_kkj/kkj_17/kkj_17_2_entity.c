#include "kkj_17.h"

// immediately remove the item from Peach's inventory, keeping only the flag
EvtScript N(EVS_AutoRemoveDeepFocus) = {
    EVT_LOOP(0)
        EVT_IF_EQ(GF_KKJ17_Item_DeepFocus, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(RemoveBadge, ITEM_DEEP_FOCUS1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_DEEP_FOCUS1, 100, 0, -30, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KKJ17_Item_DeepFocus)
    EVT_IF_LT(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        EVT_IF_EQ(GF_KKJ17_Item_DeepFocus, FALSE)
            EVT_EXEC(N(EVS_AutoRemoveDeepFocus))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
