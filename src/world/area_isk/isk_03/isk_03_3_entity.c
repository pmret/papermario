#include "isk_03.h"
#include "effects.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_RUINS_KEY, 467, -170, 218, ITEM_SPAWN_MODE_KEY, GF_ISK03_Item_RuinsKey)
    EVT_PLAY_EFFECT(EFFECT_FLAME, 1, 358, -123, 358, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, 1, 457, -123, 214, EVT_FLOAT(0.3), LVar0)
    EVT_RETURN
    EVT_END
};
