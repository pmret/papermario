#include "isk_05.h"
#include "effects.h"
#include "entity.h"

EvtScript N(D_80242210_97FCE0) = {
    EVT_SET(GF_ISK05_Hammer2Block, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_PYRAMID_STONE, 316, 82, -481, ITEM_SPAWN_MODE_KEY, GF_ISK05_Item_PyramidStone)
    EVT_IF_EQ(GF_ISK05_Hammer2Block, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer2Block_WideX), 431, 0, -478, 45, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(D_80242210_97FCE0)))
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, 415, 196, -290, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, 290, 196, -411, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, 415, 66, -290, EVT_FLOAT(0.3), LVar0)
    EVT_RETURN
    EVT_END
};
