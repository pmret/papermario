#include "mac_03.h"
#include "effects.h"

#include "world/common/npc/TrainToad.inc.c"
#include "world/common/npc/Toad_Wander.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"

NpcSettings N(NpcSettings_ShyGuy) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_SHY_GUY,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

#include "world/common/npc/Dummy.inc.c"

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"
MAP_STATIC_PAD(1,post_quizmo);

#include "world/common/complete/LetterDelivery.inc.c"

API_CALLABLE(N(GetOinkCount)) {
    s32 oinkCount = evt_get_variable(script, GB_MAC03_LilOinkCount);

    if (oinkCount == 0) {
        script->varTable[0] = -1;
    } else {
        script->varTable[0] = evt_get_variable(script, oinkCount + GB_MAC03_LilOinkCount);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241BD8_8333D8)) {
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, MV_LilOinkEffect);
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    f32 x = evt_get_variable(script, *args++);
    f32 y = evt_get_variable(script, *args++);
    f32 z = evt_get_variable(script, *args++);
    f32 yaw = evt_get_variable(script, *args++);

    effect->data.lilOink->x[index] = x;
    effect->data.lilOink->y[index] = y;
    effect->data.lilOink->z[index] = z;
    effect->data.lilOink->rot[index] =  yaw;
    return ApiStatus_DONE2;
}

s32 N(LetterList_A)[] = {
    ITEM_LETTER_CHAIN_DANE_T_1,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_ToadKid1A) = {
    EVT_CALL(N(LetterDelivery_Init), NPC_ToadKid_01,
        ANIM_ToadKid_Red_Talk, ANIM_ToadKid_Red_Idle,
        ITEM_LETTER_CHAIN_DANE_T_1, ITEM_NONE,
        MSG_MAC_Station_0049, MSG_MAC_Station_004A,
        MSG_MAC_Station_004B, MSG_MAC_Station_004C,
        EVT_PTR(N(LetterList_A)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LetterReward_ToadKid1A) = {
    EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED)
        EVT_CALL(SpeakToPlayer, NPC_ToadKid_02, ANIM_ToadKid_Yellow_Talk, ANIM_ToadKid_Yellow_Idle, 0, MSG_MAC_Station_004D)
        EVT_GIVE_KEY_REWARD(ITEM_LETTER_CHAIN_YOSHI_KID)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(LetterList_B)[] = {
    ITEM_LETTER_CHAIN_DANE_T_2,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_ToadKid1B) = {
    EVT_CALL(N(LetterDelivery_Init), NPC_ToadKid_01,
        ANIM_ToadKid_Red_Talk, ANIM_ToadKid_Red_Idle,
        ITEM_LETTER_CHAIN_DANE_T_2, ITEM_NONE,
        MSG_MAC_Station_004E, MSG_MAC_Station_004F,
        MSG_MAC_Station_0050, MSG_MAC_Station_0051,
        EVT_PTR(N(LetterList_B)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LetterReward_ToadKid1B) = {
    EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED)
        EVT_CALL(SpeakToPlayer, NPC_ToadKid_02, ANIM_ToadKid_Yellow_Talk, ANIM_ToadKid_Yellow_Idle, 0, MSG_MAC_Station_0052)
        // EVT_GIVE_KEY_REWARD(ITEM_LETTER_CHAIN_FROST_T), but LVar1/LVar0 are set in wrong order
        EVT_SET(LVar1, 1)
        EVT_SET(LVar0, ITEM_LETTER_CHAIN_FROST_T)
        EVT_EXEC_WAIT(N(GiveItemReward))
        EVT_CALL(AddKeyItem, ITEM_LETTER_CHAIN_FROST_T)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_TrainToad_01) = {
    EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_TrainToad_01, ANIM_TrainToad_White_SadTalk, ANIM_TrainToad_White_SadIdle, 0, MSG_MAC_Station_0000)
        EVT_RETURN
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            EVT_IF_EQ(GF_MAC03_ShyGuyChasedOff, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_TrainToad_01, ANIM_TrainToad_White_SadTalk, ANIM_TrainToad_White_SadIdle, 0, MSG_MAC_Station_0007)
                EVT_RETURN
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, mac_03_ENTRY_1)
        EVT_CALL(SpeakToPlayer, NPC_TrainToad_01, ANIM_TrainToad_White_Talk, ANIM_TrainToad_White_Idle, 0, MSG_MAC_Station_0006)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_MAC03_ShyGuyChasedOff, FALSE)
        EVT_IF_EQ(GF_MAC03_Conductor_ThankYouA, FALSE)
            EVT_SET(GF_MAC03_Conductor_ThankYouA, TRUE)
            EVT_SET(LVar0, MSG_MAC_Station_0001)
        EVT_ELSE
            EVT_SET(LVar0, MSG_MAC_Station_0002)
        EVT_END_IF
    EVT_ELSE
        EVT_IF_EQ(GF_MAC03_Conductor_ThankYouB, FALSE)
            EVT_SET(GF_MAC03_Conductor_ThankYouB, TRUE)
            EVT_SET(LVar0, MSG_MAC_Station_0008)
        EVT_ELSE
            EVT_SET(LVar0, MSG_MAC_Station_0002)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_TrainToad_01, ANIM_TrainToad_White_Talk, ANIM_TrainToad_White_Idle, 0, LVar0)
    EVT_CALL(ShowChoice, MSG_Choice_000C)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ContinueSpeech, NPC_TrainToad_01, ANIM_TrainToad_White_Talk, ANIM_TrainToad_White_Idle, 0, MSG_MAC_Station_0003)
        EVT_EXEC(N(EVS_DepartForMtRugged))
    EVT_ELSE
        EVT_CALL(ContinueSpeech, NPC_TrainToad_01, ANIM_TrainToad_White_Talk, ANIM_TrainToad_White_Idle, 0, MSG_MAC_Station_0004)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TrainToad_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_TrainToad_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Station_000A)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Station_000B)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Station_000C)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_ShyGuyBlockingTracks, FALSE)
                EVT_SET(LVar0, MSG_MAC_Station_000D)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC03_ShyGuyChasedOff, FALSE)
                    EVT_SET(LVar0, MSG_MAC_Station_000E)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Station_000F)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Station_0010)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Station_0011)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Station_0012)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Station_0013)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Station_0014)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Station_0015)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Station_0016)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_01, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toadette_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Station_0017)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Station_0018)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Station_0019)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_ShyGuyBlockingTracks, FALSE)
                EVT_SET(LVar0, MSG_MAC_Station_001A)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC03_ShyGuyChasedOff, FALSE)
                    EVT_SET(LVar0, MSG_MAC_Station_001B)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Station_001C)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Station_001D)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Station_001E)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Station_001F)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Station_0020)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Station_0021)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Station_0022)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Station_0023)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toadette_01, ANIM_Toadette_Purple_Talk, ANIM_Toadette_Purple_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toadette_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toadette_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Station_0024)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Station_0025)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Station_0026)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_ShyGuyBlockingTracks, FALSE)
                EVT_SET(LVar0, MSG_MAC_Station_0027)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC03_ShyGuyChasedOff, FALSE)
                    EVT_SET(LVar0, MSG_MAC_Station_0028)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Station_0029)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Station_002A)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Station_002B)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Station_002C)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Station_002D)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Station_002E)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Station_002F)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Station_0030)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_02, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadKid_02) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_FULL)
    EVT_CALL(EnableNpcAI, NPC_ToadKid_01, FALSE)
    EVT_CALL(EnableNpcAI, NPC_ToadKid_02, FALSE)
    EVT_CALL(GetNpcAnimation, NPC_ToadKid_01, LVar2)
    EVT_CALL(GetNpcAnimation, NPC_ToadKid_02, LVar3)
    EVT_CALL(SetNpcAnimation, NPC_ToadKid_01, ANIM_ToadKid_Red_Idle)
    EVT_CALL(SetNpcAnimation, NPC_ToadKid_02, ANIM_ToadKid_Yellow_Idle)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Station_0031)
                EVT_SET(LVar1, MSG_MAC_Station_0032)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Station_0033)
                EVT_SET(LVar1, MSG_MAC_Station_0034)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Station_0035)
            EVT_SET(LVar1, MSG_MAC_Station_0036)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_ShyGuyBlockingTracks, FALSE)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC03_ShyGuyChasedOff, FALSE)
                    EVT_SET(LVar0, MSG_MAC_Station_0037)
                    EVT_SET(LVar1, MSG_MAC_Station_0038)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Station_0039)
                    EVT_SET(LVar1, MSG_MAC_Station_003A)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Station_003B)
            EVT_SET(LVar1, MSG_MAC_Station_003C)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Station_003D)
            EVT_SET(LVar1, MSG_MAC_Station_003E)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Station_003F)
            EVT_SET(LVar1, MSG_MAC_Station_0040)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Station_0041)
            EVT_SET(LVar1, MSG_MAC_Station_0042)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Station_0043)
            EVT_SET(LVar1, MSG_MAC_Station_0044)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Station_0045)
            EVT_SET(LVar1, MSG_MAC_Station_0046)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Station_0047)
            EVT_SET(LVar1, MSG_MAC_Station_0048)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_ToadKid_01, ANIM_ToadKid_Red_Talk, ANIM_ToadKid_Red_Idle, 0, LVar0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_ToadKid_02, ANIM_ToadKid_Yellow_Talk, ANIM_ToadKid_Yellow_Idle, 0, LVar1)
    EVT_CALL(SetNpcAnimation, NPC_ToadKid_01, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_ToadKid_02, LVar3)
    EVT_CALL(EnableNpcAI, NPC_ToadKid_01, TRUE)
    EVT_CALL(EnableNpcAI, NPC_ToadKid_02, TRUE)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadKid_01) = {
    EVT_EXEC_WAIT(N(EVS_NpcInteract_ToadKid_02))
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_ToadKid1A))
    EVT_EXEC_WAIT(N(EVS_LetterReward_ToadKid1A))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_ToadKid1B))
    EVT_EXEC_WAIT(N(EVS_LetterReward_ToadKid1B))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadKid_01) = {
    EVT_CALL(BindNpcInteract, NPC_ToadKid_01, EVT_PTR(N(EVS_NpcInteract_ToadKid_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadKid_02) = {
    EVT_CALL(BindNpcInteract, NPC_ToadKid_02, EVT_PTR(N(EVS_NpcInteract_ToadKid_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toadette_02) = {
    EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
        EVT_SET(LVar0, MSG_MAC_Station_0061)
        EVT_SET(LVar1, MSG_MAC_Station_0062)
        EVT_SET(LVar2, MSG_MAC_Station_0063)
    EVT_ELSE
        EVT_SET(LVar0, MSG_MAC_Station_0064)
        EVT_SET(LVar1, MSG_MAC_Station_0065)
        EVT_SET(LVar2, MSG_MAC_Station_0066)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Toadette_02, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, LVar0)
    EVT_CALL(SpeakToPlayer, NPC_Toadette_03, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, LVar1)
    EVT_CALL(SpeakToPlayer, NPC_Toadette_04, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toadette_02) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toadette_02)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_03) = {
    EVT_IF_EQ(GB_MAC03_LilOinkCount, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MAC_Station_0053)
        EVT_CALL(ShowChoice, MSG_Choice_000D)
        EVT_IF_EQ(LVar0, 0)
            EVT_SET(LVar0, MSG_MAC_Station_0056)
        EVT_ELSE
            EVT_SET(LVar0, MSG_MAC_Station_0055)
        EVT_END_IF
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
        EVT_SET(MF_Unk_08, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(MF_Unk_07, FALSE)
        EVT_SET(LVar0, MSG_MAC_Station_0054)
    EVT_ELSE
        EVT_CALL(N(GetOinkCount))
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(9)
                EVT_SET(LVar0, MSG_MAC_Station_0058)
            EVT_CASE_EQ(8)
                EVT_SET(LVar0, MSG_MAC_Station_0057)
            EVT_CASE_EQ(0)
                EVT_SET(LVar0, MSG_MAC_Station_0059)
            EVT_CASE_EQ(1)
                EVT_SET(LVar0, MSG_MAC_Station_005A)
            EVT_CASE_EQ(2)
                EVT_SET(LVar0, MSG_MAC_Station_005B)
            EVT_CASE_EQ(3)
                EVT_SET(LVar0, MSG_MAC_Station_005C)
            EVT_CASE_EQ(4)
                EVT_SET(LVar0, MSG_MAC_Station_005D)
            EVT_CASE_EQ(5)
                EVT_SET(LVar0, MSG_MAC_Station_005E)
            EVT_CASE_EQ(6)
                EVT_SET(LVar0, MSG_MAC_Station_005F)
            EVT_CASE_EQ(7)
                EVT_SET(LVar0, MSG_MAC_Station_0060)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 16, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024A7F4_83BFF4) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_SHY_GUY_STEP, SOUND_SPACE_DEFAULT)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_ShyGuy) = {
    EVT_CALL(SetNpcPos, NPC_SELF, -100, 0, -25)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
    EVT_LOOP(0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -250, -25, 30)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_SELF, -250, 0, 30, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, -100, 30, 30)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_SELF, -100, 0, -25, 15)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_ShyGuy) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim0C)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 10)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
    EVT_EXEC_GET_TID(N(D_8024A7F4_83BFF4), LVarA)
    EVT_CALL(NpcMoveTo, NPC_SELF, -100, 0, 0)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(ShowSweat, NPC_SELF, 1, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, -30, 0, 0, 20)
    EVT_CALL(ShowSweat, NPC_SELF, 1, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SHY_GUY_RUN_AWAY, SOUND_SPACE_DEFAULT)
    EVT_EXEC_GET_TID(N(D_8024A7F4_83BFF4), LVarA)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(8.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, 30, -200, 0)
    EVT_CALL(ShowSweat, NPC_SELF, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    EVT_CALL(NpcMoveTo, NPC_SELF, -30, -400, 0)
    EVT_CALL(ShowSweat, NPC_SELF, 1, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
    EVT_CALL(NpcMoveTo, NPC_SELF, 30, -600, 0)
    EVT_CALL(ShowSweat, NPC_SELF, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    EVT_CALL(NpcMoveTo, NPC_SELF, 0, -650, 0)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_WAIT(200)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_ShyGuy) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar1, 1)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar1, 1)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_SET(LVar1, 1)
        EVT_CASE_DEFAULT
            EVT_SET(LVar1, 0)
    EVT_END_SWITCH
    EVT_IF_EQ(LVar1, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SHY_GUY_OUCH, SOUND_SPACE_DEFAULT)
    EVT_SET(GF_MAC03_ShyGuyChasedOff, TRUE)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_ShyGuy)))
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            EVT_CALL(GetEntryID, LVar0)
            EVT_IF_EQ(LVar0, mac_03_ENTRY_1)
                EVT_SET(GF_MAC03_ShyGuyBlockingTracks, TRUE)
                EVT_SET(GF_MAC03_ShyGuyChasedOff, TRUE)
            EVT_END_IF
            EVT_IF_EQ(GF_MAC03_ShyGuyChasedOff, FALSE)
                EVT_SET(GF_MAC03_ShyGuyBlockingTracks, TRUE)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ShyGuy)))
                EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_ShyGuy)))
                EVT_RETURN
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Toad_14) = {
    EVT_LOOP(0)
        EVT_SWITCH(GB_MAC03_LilOinkCapsuleState)
            EVT_CASE_EQ(1)
                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(TranslateModel, MODEL_capsule, LVar0, LVar1, LVar2)
            EVT_CASE_EQ(2)
                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(GetNpcYaw, NPC_SELF, LVar3)
                EVT_CALL(N(func_80241BD8_8333D8), 10, LVar0, LVar1, LVar2, LVar3)
        EVT_END_SWITCH
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_14) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad_14)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_04) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetNpcPos, NPC_SELF, 420, 20, -170)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Toads)[] = {
    {
        .id = NPC_TrainToad_01,
        .pos = { -370.0f, 20.0f, 90.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TrainToad_01),
        .settings = &N(NpcSettings_TrainToad),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TRAIN_TOAD_WHITE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_StationMaster,
    },
    {
        .id = NPC_TrainToad_02,
        .pos = { -424.0f, 74.0f, 2.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_TrainToad),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TRAIN_CONDUCTOR_ANIMS,
        .tattle = MSG_NpcTattle_MAC_StationMaster,
    },
    {
        .id = NPC_Toad_01,
        .pos = { -232.0f, 10.0f, 74.0f },
        .yaw = 75,
        .init = &N(EVS_NpcInit_Toad_01),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_TrainLover,
    },
    {
        .id = NPC_Toadette_01,
        .pos = { 85.0f, 0.0f, 235.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Toadette_01),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOADETTE_PURPLE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_CaringToad,
    },
    {
        .id = NPC_Toad_02,
        .pos = { -255.0f, 20.0f, 400.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toad_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_MAC_DesertTraveler,
    },
    {
        .id = NPC_ToadKid_01,
        .pos = { 260.0f, 20.0f, 410.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 260, 20, 410 },
                .wanderSize = { 40, 20 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 260, 20, 410 },
                .detectSize = { 10, 10 },
            }
        },
        .init = &N(EVS_NpcInit_ToadKid_01),
        .settings = &N(NpcSettings_ToadKid_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_KID_RED_ANIMS,
        .tattle = MSG_NpcTattle_MAC_TravelFan,
    },
    {
        .id = NPC_ToadKid_02,
        .pos = { 320.0f, 20.0f, 410.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 320, 20, 410 },
                .wanderSize = { 40, 20 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 320, 20, 410 },
                .detectSize = { 10, 10 },
            }
        },
        .init = &N(EVS_NpcInit_ToadKid_02),
        .settings = &N(NpcSettings_ToadKid_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_KID_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_MAC_GoodFriends,
    },
    {
        .id = NPC_Toad_03,
        .pos = { 220.0f, 20.0f, -160.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toad_03),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_MAC_LilOinkFan,
    },
};

NpcData N(NpcData_Toadette)[] = {
    {
        .id = NPC_Toadette_02,
        .pos = { -130.0f, 0.0f, 220.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Toadette_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOADETTE_PINK_ANIMS,
        .tattle = MSG_NpcTattle_TravelingMaidA,
    },
    {
        .id = NPC_Toadette_03,
        .pos = { -100.0f, 0.0f, 220.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toadette_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOADETTE_PINK_ANIMS,
        .tattle = MSG_NpcTattle_TravelingMaidB,
    },
    {
        .id = NPC_Toadette_04,
        .pos = { -70.0f, 0.0f, 220.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_Toadette_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOADETTE_PINK_ANIMS,
        .tattle = MSG_NpcTattle_TravelingMaidC,
    },
};

NpcData N(NpcData_ShyGuy) = {
    .id = NPC_ShyGuy,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_ShyGuy),
    .settings = &N(NpcSettings_ShyGuy),
    .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_ShyGuy_Red_Anim01,
        .walk   = ANIM_ShyGuy_Red_Anim02,
        .run    = ANIM_ShyGuy_Red_Anim03,
        .chase  = ANIM_ShyGuy_Red_Anim03,
        .anim_4 = ANIM_ShyGuy_Red_Anim01,
        .anim_5 = ANIM_ShyGuy_Red_Anim01,
        .death  = ANIM_ShyGuy_Red_Anim0C,
        .hit    = ANIM_ShyGuy_Red_Anim0C,
        .anim_8 = ANIM_ShyGuy_Red_Anim15,
        .anim_9 = ANIM_ShyGuy_Red_Anim12,
        .anim_A = ANIM_ShyGuy_Red_Anim11,
        .anim_B = ANIM_ShyGuy_Red_Anim10,
        .anim_C = ANIM_ShyGuy_Red_Anim05,
        .anim_D = ANIM_ShyGuy_Red_Anim01,
        .anim_E = ANIM_ShyGuy_Red_Anim01,
        .anim_F = ANIM_ShyGuy_Red_Anim01,
    },
};

NpcData N(NpcData_LilOinks)[] = {
    {
        .id = NPC_LilOink_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 430, 20, -180 },
                .wanderSize = { 150, 70 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 430, 20, -180 },
                .detectSize = { 150, 70 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_04),
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
    },
    {
        .id = NPC_LilOink_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 430, 20, -180 },
                .wanderSize = { 150, 70 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 430, 20, -180 },
                .detectSize = { 150, 70 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_04),
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
    },
    {
        .id = NPC_LilOink_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 430, 20, -180 },
                .wanderSize = { 150, 70 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 430, 20, -180 },
                .detectSize = { 150, 70 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_04),
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
    },
    {
        .id = NPC_LilOink_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 430, 20, -180 },
                .wanderSize = { 150, 70 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 430, 20, -180 },
                .detectSize = { 150, 70 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_04),
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
    },
    {
        .id = NPC_LilOink_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 430, 20, -180 },
                .wanderSize = { 150, 70 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 430, 20, -180 },
                .detectSize = { 150, 70 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_04),
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
    },
    {
        .id = NPC_LilOink_06,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 430, 20, -180 },
                .wanderSize = { 150, 70 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 430, 20, -180 },
                .detectSize = { 150, 70 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_04),
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
    },
    {
        .id = NPC_LilOink_07,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 430, 20, -180 },
                .wanderSize = { 150, 70 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 430, 20, -180 },
                .detectSize = { 150, 70 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_04),
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
    },
    {
        .id = NPC_LilOink_08,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 430, 20, -180 },
                .wanderSize = { 150, 70 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 430, 20, -180 },
                .detectSize = { 150, 70 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_04),
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
    },
    {
        .id = NPC_LilOink_09,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 430, 20, -180 },
                .wanderSize = { 150, 70 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 430, 20, -180 },
                .detectSize = { 150, 70 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_04),
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
    },
    {
        .id = NPC_LilOink_10,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 430, 20, -180 },
                .wanderSize = { 150, 70 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 430, 20, -180 },
                .detectSize = { 150, 70 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_04),
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
    },
    {
        .id = NPC_Capsule,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 430, 20, -180 },
                .wanderSize = { 150, 70 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 430, 20, -180 },
                .detectSize = { 150, 70 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_14),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Toads)),
    NPC_GROUP(N(NpcData_Toadette)),
    NPC_GROUP(N(NpcData_ShyGuy)),
    NPC_GROUP(N(NpcData_LilOinks)),
    {}
};
