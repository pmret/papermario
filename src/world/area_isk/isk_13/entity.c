#include "isk_13.h"
#include "entity.h"
#include "effects.h"

EvtScript N(EVS_OnSmash_Block) = {
    Set(GF_ISK13_Hammer2Block, true)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_LUNAR_STONE, 460, -568, -342, ITEM_SPAWN_MODE_KEY, GF_ISK13_Item_LunarStone)
    IfEq(GF_ISK13_Hammer2Block, false)
        Call(MakeEntity, Ref(Entity_Hammer2BlockWideX), 568, -650, -302, 25, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnSmash_Block)))
    EndIf
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 415, -453, -291, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 415, -583, -291, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 489, -453, -131, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 489, -583, -131, Float(0.3), LVar0)
    Return
    End
};
