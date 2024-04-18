#include "isk_11.h"
#include "entity.h"
#include "effects.h"

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_ISK11_UnlockedDoor, FALSE)
        Call(MakeEntity, Ref(Entity_Padlock), 355, -460, 430, -40, MAKE_ENTITY_END)
        Set(MV_LockEntityID, LVar0)
    EndIf
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -131, -453, 489, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 131, -453, 489, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 291, -453, 415, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -44, -583, 505, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 131, -583, 489, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -44, -713, 505, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 131, -713, 489, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -44, -843, 505, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 131, -843, 489, Float(0.3), LVar0)
    Call(MakeEntity, Ref(Entity_HeartBlock), -75, -720, 625, 0, MAKE_ENTITY_END)
    Return
    End
};
