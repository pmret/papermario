#include "isk_06.h"
#include "effects.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_STAR_PIECE, 335, -130, -550, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_ISK06_Item_StarPiece)
    Call(MakeItemEntity, ITEM_RUINS_KEY, 304, -270, -434, ITEM_SPAWN_MODE_KEY, GF_ISK06_Item_RuinsKey)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 415, -253, -291, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 291, -253, -415, Float(0.3), LVar0)
    Return
    End
};
