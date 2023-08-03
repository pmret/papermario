#include "nok_13.h"
#include "entity.h"
#include "effects.h"

EvtScript N(EVS_BreakBlock_First) = {
    EVT_IF_EQ(AB_NOK_1, 0)
        EVT_SET(AB_NOK_1, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BreakBlock_Second) = {
    EVT_IF_EQ(AB_NOK_1, 1)
        EVT_SET(AB_NOK_1, 2)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BreakBlock_Third) = {
    EVT_IF_EQ(AB_NOK_1, 2)
        EVT_CALL(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
        EVT_CALL(PlaySoundAt, SOUND_2108, 0, 40, 60, -285)
        EVT_SET(AB_NOK_1, 3)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 40, 73, -285, 10)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_RedBlock), 40, 60, -285, 90, ITEM_ATTACK_FX_B, MAKE_ENTITY_END)
        EVT_CALL(AssignBlockFlag, GF_NOK13_BadgeBlock_AttackFXB)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReadSign_Directions) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0178, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Signpost), -430, 150, -75, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_ReadSign_Directions)))
    EVT_IF_EQ(GF_NOK13_BadgeBlock_AttackFXB, FALSE)
        EVT_SET(AB_NOK_1, 0)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 70, 0, -250, 90, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_BreakBlock_First)))
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 70, 0, -320, 90, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_BreakBlock_Second)))
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -10, 0, -285, 90, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_BreakBlock_Third)))
    EVT_ELSE
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 70, 0, -250, 90, MAKE_ENTITY_END)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 70, 0, -320, 90, MAKE_ENTITY_END)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -10, 0, -285, 90, MAKE_ENTITY_END)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_RedBlock), 40, 60, -285, 90, ITEM_ATTACK_FX_B, MAKE_ENTITY_END)
        EVT_CALL(AssignBlockFlag, GF_NOK13_BadgeBlock_AttackFXB)
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), -255, 150, -100, 90, MODEL_jimen_u, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_NOK13_HiddenPanel)
    EVT_CALL(MakeItemEntity, ITEM_HONEY_SYRUP, -155, 150, -130, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK13_Item_HoneySyrup)
    EVT_RETURN
    EVT_END
};
