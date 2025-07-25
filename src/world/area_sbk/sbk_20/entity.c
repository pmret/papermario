#include "sbk_20.h"
#include "effects.h"
#include "entity.h"

EvtScript N(EVS_OnHitInertBlock) = {
    Add(MV_BlockHitCounter, 1)
    Switch(MV_BlockHitCounter)
        CaseEq(1)
            IfEq(GF_SBK20_ItemBlock_Mushroom, false)
                Call(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
                Call(PlaySoundAt, SOUND_SPAWN_BLOCK, SOUND_SPACE_DEFAULT, -80, 60, -200)
                PlayEffect(EFFECT_SPARKLES, 0, -80, 73, -200, 10)
                Call(MakeEntity, Ref(Entity_YellowBlock), -80, 60, -200, 0, ITEM_MUSHROOM, MAKE_ENTITY_END)
                Call(AssignBlockFlag, GF_SBK20_ItemBlock_Mushroom)
            EndIf
        CaseEq(10)
            IfEq(GF_SBK20_ItemBlock_SuperShroom, false)
                Call(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
                Call(PlaySoundAt, SOUND_SPAWN_BLOCK, SOUND_SPACE_DEFAULT, -180, 60, -200)
                PlayEffect(EFFECT_SPARKLES, 0, -180, 73, -200, 10)
                Call(MakeEntity, Ref(Entity_YellowBlock), -180, 60, -200, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
                Call(AssignBlockFlag, GF_SBK20_ItemBlock_SuperShroom)
            EndIf
        CaseEq(100)
            IfEq(GF_SBK20_ItemBlock_UltraShroom, false)
                Call(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
                Call(PlaySoundAt, SOUND_SPAWN_BLOCK, SOUND_SPACE_DEFAULT, -130, 60, -150)
                PlayEffect(EFFECT_SPARKLES, 0, -130, 73, -150, 10)
                Call(MakeEntity, Ref(Entity_YellowBlock), -130, 60, -150, 0, ITEM_ULTRA_SHROOM, MAKE_ENTITY_END)
                Call(AssignBlockFlag, GF_SBK20_ItemBlock_UltraShroom)
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_InertYellowBlock), -130, 0, -200, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_OnHitInertBlock)))
    IfEq(GF_SBK20_ItemBlock_Mushroom, true)
        Call(MakeEntity, Ref(Entity_YellowBlock), -80, 60, -200, 0, ITEM_MUSHROOM, MAKE_ENTITY_END)
        Call(AssignBlockFlag, GF_SBK20_ItemBlock_Mushroom)
    EndIf
    IfEq(GF_SBK20_ItemBlock_SuperShroom, true)
        Call(MakeEntity, Ref(Entity_YellowBlock), -180, 60, -200, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
        Call(AssignBlockFlag, GF_SBK20_ItemBlock_SuperShroom)
    EndIf
    IfEq(GF_SBK20_ItemBlock_UltraShroom, true)
        Call(MakeEntity, Ref(Entity_YellowBlock), -130, 60, -150, 0, ITEM_ULTRA_SHROOM, MAKE_ENTITY_END)
        Call(AssignBlockFlag, GF_SBK20_ItemBlock_UltraShroom)
    EndIf
    Return
    End
};
