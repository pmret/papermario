#include "nok_13.h"
#include "entity.h"
#include "effects.h"

EvtScript N(EVS_BreakBlock_First) = {
    IfEq(AB_NOK_1, 0)
        Set(AB_NOK_1, 1)
    EndIf
    Return
    End
};

EvtScript N(EVS_BreakBlock_Second) = {
    IfEq(AB_NOK_1, 1)
        Set(AB_NOK_1, 2)
    EndIf
    Return
    End
};

EvtScript N(EVS_BreakBlock_Third) = {
    IfEq(AB_NOK_1, 2)
        Call(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
        Call(PlaySoundAt, SOUND_SPAWN_BLOCK, SOUND_SPACE_DEFAULT, 40, 60, -285)
        Set(AB_NOK_1, 3)
        PlayEffect(EFFECT_SPARKLES, 0, 40, 73, -285, 10)
        Call(MakeEntity, Ref(Entity_RedBlock), 40, 60, -285, 90, ITEM_ATTACK_FX_B, MAKE_ENTITY_END)
        Call(AssignBlockFlag, GF_NOK13_BadgeBlock_AttackFXB)
    EndIf
    Return
    End
};

EvtScript N(EVS_ReadSign_Directions) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(DisablePlayerInput, true)
    Call(ShowMessageAtScreenPos, MSG_Menus_0178, 160, 40)
    Call(DisablePlayerInput, false)
    Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Signpost), -430, 150, -75, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_ReadSign_Directions)))
    IfEq(GF_NOK13_BadgeBlock_AttackFXB, false)
        Set(AB_NOK_1, 0)
        Call(MakeEntity, Ref(Entity_BrickBlock), 70, 0, -250, 90, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_BreakBlock_First)))
        Call(MakeEntity, Ref(Entity_BrickBlock), 70, 0, -320, 90, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_BreakBlock_Second)))
        Call(MakeEntity, Ref(Entity_BrickBlock), -10, 0, -285, 90, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_BreakBlock_Third)))
    Else
        Call(MakeEntity, Ref(Entity_BrickBlock), 70, 0, -250, 90, MAKE_ENTITY_END)
        Call(MakeEntity, Ref(Entity_BrickBlock), 70, 0, -320, 90, MAKE_ENTITY_END)
        Call(MakeEntity, Ref(Entity_BrickBlock), -10, 0, -285, 90, MAKE_ENTITY_END)
        Call(MakeEntity, Ref(Entity_RedBlock), 40, 60, -285, 90, ITEM_ATTACK_FX_B, MAKE_ENTITY_END)
        Call(AssignBlockFlag, GF_NOK13_BadgeBlock_AttackFXB)
    EndIf
    Call(MakeEntity, Ref(Entity_HiddenPanel), -255, 150, -100, 90, MODEL_jimen_u, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_NOK13_HiddenPanel)
    Call(MakeItemEntity, ITEM_HONEY_SYRUP, -155, 150, -130, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK13_Item_HoneySyrup)
    Return
    End
};
