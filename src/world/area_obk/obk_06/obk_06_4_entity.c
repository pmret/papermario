#include "obk_06.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_OBK06_Item_BoosPortrait, FALSE)
        EVT_CALL(MakeItemEntity, ITEM_BOO_PORTRAIT, 230, 125, -215, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OBK06_Item_BoosPortrait)
        EVT_THREAD
            EVT_LOOP(0)
                EVT_IF_NE(GF_OBK06_Item_BoosPortrait, FALSE)
                    EVT_SET(GB_StoryProgress, STORY_CH3_GOT_BOO_PORTRAIT)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), -110, 30, 50, 0, -1, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), -110, 0, 50, 0, ITEM_STAR_PIECE, MAKE_ENTITY_END)
    EVT_CALL(AssignCrateFlag, GF_OBK06_Crate_StarPiece)
    EVT_RETURN
    EVT_END
};
