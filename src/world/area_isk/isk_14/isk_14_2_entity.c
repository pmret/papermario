#include "isk_14.h"
#include "entity.h"
#include "effects.h"

EvtScript N(EVS_OnSmash_Block) = {
    EVT_SET(GF_ISK14_Hammer2Block, TRUE)
    EVT_CALL(SetNpcVar, NPC_StoneChomp, 1, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_DIAMOND_STONE, -389, -698, -424, ITEM_SPAWN_MODE_KEY, GF_ISK14_Item_DiamondStone)
    EVT_IF_EQ(GF_ISK14_Hammer2Block, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer2Block_WideX), -507, -780, -396, 143, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnSmash_Block)))
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -459, -583, -214, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -358, -583, -358, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -459, -713, -214, EVT_FLOAT(0.3), LVar0)
    EVT_RETURN
    EVT_END
};
