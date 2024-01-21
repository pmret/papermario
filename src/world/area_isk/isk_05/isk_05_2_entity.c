#include "isk_05.h"
#include "effects.h"
#include "entity.h"

EvtScript N(D_80242210_97FCE0) = {
    Set(GF_ISK05_Hammer2Block, TRUE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_PYRAMID_STONE, 316, 82, -481, ITEM_SPAWN_MODE_KEY, GF_ISK05_Item_PyramidStone)
    IfEq(GF_ISK05_Hammer2Block, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer2Block_WideX), 431, 0, -478, 45, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(D_80242210_97FCE0)))
    EndIf
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 415, 196, -290, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 290, 196, -411, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 415, 66, -290, Float(0.3), LVar0)
    Return
    End
};
