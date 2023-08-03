#include "sbk_20.h"
#include "effects.h"
#include "entity.h"

EvtScript N(EVS_OnHitInertBlock) = {
    EVT_ADD(MV_BlockHitCounter, 1)
    EVT_SWITCH(MV_BlockHitCounter)
        EVT_CASE_EQ(1)
            EVT_IF_EQ(GF_SBK20_ItemBlock_Mushroom, FALSE)
                EVT_CALL(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
                EVT_CALL(PlaySoundAt, SOUND_2108, SOUND_SPACE_MODE_0, -80, 60, -200)
                EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, -80, 73, -200, 10)
                EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -80, 60, -200, 0, ITEM_MUSHROOM, MAKE_ENTITY_END)
                EVT_CALL(AssignBlockFlag, GF_SBK20_ItemBlock_Mushroom)
            EVT_END_IF
        EVT_CASE_EQ(10)
            EVT_IF_EQ(GF_SBK20_ItemBlock_SuperShroom, FALSE)
                EVT_CALL(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
                EVT_CALL(PlaySoundAt, SOUND_2108, SOUND_SPACE_MODE_0, -180, 60, -200)
                EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, -180, 73, -200, 10)
                EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -180, 60, -200, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
                EVT_CALL(AssignBlockFlag, GF_SBK20_ItemBlock_SuperShroom)
            EVT_END_IF
        EVT_CASE_EQ(100)
            EVT_IF_EQ(GF_SBK20_ItemBlock_UltraShroom, FALSE)
                EVT_CALL(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
                EVT_CALL(PlaySoundAt, SOUND_2108, SOUND_SPACE_MODE_0, -130, 60, -150)
                EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, -130, 73, -150, 10)
                EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -130, 60, -150, 0, ITEM_ULTRA_SHROOM, MAKE_ENTITY_END)
                EVT_CALL(AssignBlockFlag, GF_SBK20_ItemBlock_UltraShroom)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_InertYellowBlock), -130, 0, -200, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnHitInertBlock)))
    EVT_IF_EQ(GF_SBK20_ItemBlock_Mushroom, TRUE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -80, 60, -200, 0, ITEM_MUSHROOM, MAKE_ENTITY_END)
        EVT_CALL(AssignBlockFlag, GF_SBK20_ItemBlock_Mushroom)
    EVT_END_IF
    EVT_IF_EQ(GF_SBK20_ItemBlock_SuperShroom, TRUE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -180, 60, -200, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
        EVT_CALL(AssignBlockFlag, GF_SBK20_ItemBlock_SuperShroom)
    EVT_END_IF
    EVT_IF_EQ(GF_SBK20_ItemBlock_UltraShroom, TRUE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -130, 60, -150, 0, ITEM_ULTRA_SHROOM, MAKE_ENTITY_END)
        EVT_CALL(AssignBlockFlag, GF_SBK20_ItemBlock_UltraShroom)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
