#include "isk_13.h"
#include "entity.h"
#include "effects.h"

EvtScript N(EVS_OnSmash_Block) = {
    EVT_SET(GF_ISK13_Hammer2Block, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_LUNAR_STONE, 460, -568, -342, ITEM_SPAWN_MODE_KEY, GF_ISK13_Item_LunarStone)
    EVT_IF_EQ(GF_ISK13_Hammer2Block, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer2Block_WideX), 568, -650, -302, 25, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnSmash_Block)))
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, 415, -453, -291, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, 415, -583, -291, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, 489, -453, -131, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, 489, -583, -131, EVT_FLOAT(0.3), LVar0)
    EVT_RETURN
    EVT_END
};
