#include "dro_01.h"
#include "sprite/player.h"

s32 N(LyricsList)[] = {
    ITEM_LYRICS,
    ITEM_NONE,
};

EvtScript N(EVS_NpcInteract_Composer) = {
    EVT_IF_EQ(GF_DRO01_Gift_Melody, TRUE)
        EVT_CALL(FindKeyItem, ITEM_MELODY, LVar0)
        EVT_IF_NE(LVar0, -1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0084)
            EVT_RETURN
        EVT_ELSE
            EVT_IF_EQ(GF_DRO01_Gift_ToldComposerAboutMelody, FALSE)
                EVT_IF_LT(GB_StoryProgress, STORY_CH7_BEGAN_PEACH_MISSION)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0085)
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
                    EVT_WAIT(30)
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0086)
                    EVT_SET(GF_DRO01_Gift_ToldComposerAboutMelody, TRUE)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_DRO_DialogueToggle_Composer, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_007C)
                EVT_SET(AF_DRO_DialogueToggle_Composer, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_007D)
                EVT_SET(AF_DRO_DialogueToggle_Composer, FALSE)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_DRO_DialogueToggle_Composer, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_007E)
                EVT_SET(AF_DRO_DialogueToggle_Composer, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_007F)
                EVT_SET(AF_DRO_DialogueToggle_Composer, FALSE)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(AF_DRO_DialogueToggle_Composer, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0080)
                EVT_SET(AF_DRO_DialogueToggle_Composer, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0081)
                EVT_SET(AF_DRO_DialogueToggle_Composer, FALSE)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_SET(LVar0, EVT_PTR(N(LyricsList)))
    EVT_SET(LVar1, 5)
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0082)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Musician_Composer_Write)
            EVT_WAIT(60)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Musician_Composer_Idle)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 0, MSG_CH2_0083)
            EVT_GIVE_KEY_REWARD(ITEM_MELODY)
            EVT_SET(GF_DRO01_Gift_Melody, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Composer) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Composer)))
    EVT_RETURN
    EVT_END
};
