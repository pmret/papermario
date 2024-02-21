#include "isk_07.h"
#include "entity.h"
#include "effects.h"

EvtScript N(EVS_HitBlock_Trigger) = {
    Set(GF_ISK07_OpenedSarcophagi, TRUE)
    Return
    End
};

EvtScript N(EVS_SmashBlock_Stone) = {
    Set(GF_ISK07_Hammer2Block, TRUE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_ISK07_UnlockedDoor, FALSE)
        Call(MakeEntity, Ref(Entity_Padlock), -300, -380, 530, 50, MAKE_ENTITY_END)
        Set(MV_LockEntityID, LVar0)
    EndIf
    IfEq(GF_ISK07_Hammer2Block, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer2Block_WideX), 470, -250, 270, 150, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_SmashBlock_Stone)))
    EndIf
    IfEq(GF_ISK07_OpenedSarcophagi, FALSE)
        Call(MakeEntity, Ref(Entity_TriggerBlock), -250, -330, 545, -25, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_HitBlock_Trigger)))
    EndIf
    IfEq(GF_ISK07_Defeated_Mummies, TRUE)
        Call(MakeItemEntity, ITEM_RUINS_KEY, -250, -390, 545, ITEM_SPAWN_MODE_KEY, GF_ISK07_Item_RuinsKey)
    EndIf
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 415, -193, 291, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 291, -193, 415, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 131, -193, 489, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -44, -193, 505, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -214, -193, 459, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 415, -323, 291, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 291, -323, 415, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 131, -323, 489, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -44, -323, 505, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -214, -323, 459, Float(0.3), LVar0)
    Call(MakeItemEntity, ITEM_ARTIFACT, 490, -250, 215, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_ISK07_Item_Artifact)
    Return
    End
};
