#include "isk_04.h"
#include "entity.h"
#include "effects.h"

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_ISK04_UnlockedDoor, FALSE)
        Call(MakeEntity, Ref(Entity_Padlock), 600, -330, 100, 160, MAKE_ENTITY_END)
        Set(MV_RuinsLockEntityID, LVar0)
    EndIf
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 504, -193, 43, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 486, -193, -128, Float(0.3), LVar0)
    Return
    End
};
