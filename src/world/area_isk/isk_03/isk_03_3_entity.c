#include "isk_03.h"
#include "effects.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_RUINS_KEY, 467, -170, 218, ITEM_SPAWN_MODE_KEY, GF_ISK03_Item_RuinsKey)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 358, -123, 358, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 457, -123, 214, Float(0.3), LVar0)
    Return
    End
};
