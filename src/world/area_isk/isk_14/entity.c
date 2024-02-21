#include "isk_14.h"
#include "entity.h"
#include "effects.h"

EvtScript N(EVS_OnSmash_Block) = {
    Set(GF_ISK14_Hammer2Block, TRUE)
    Call(SetNpcVar, NPC_StoneChomp, 1, 1)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_DIAMOND_STONE, -389, -698, -424, ITEM_SPAWN_MODE_KEY, GF_ISK14_Item_DiamondStone)
    IfEq(GF_ISK14_Hammer2Block, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer2Block_WideX), -507, -780, -396, 143, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnSmash_Block)))
    EndIf
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -459, -583, -214, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -358, -583, -358, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -459, -713, -214, Float(0.3), LVar0)
    Return
    End
};
