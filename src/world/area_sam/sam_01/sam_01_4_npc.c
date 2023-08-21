#include "sam_01.h"

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/NormalItemChoice.inc.c"
#include "world/common/complete/GiveReward.inc.c"

#include "world/common/npc/Penguin_Wander.inc.c"
#include "world/common/npc/Penguin.inc.c"

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(MayorLetterList)[] = {
    ITEM_LETTER_TO_MAYOR_PENGUIN,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Mayor) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_MayorPenguin, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle,
        ITEM_LETTER_TO_MAYOR_PENGUIN, ITEM_NONE,
        MSG_CH7_0041, MSG_CH7_0042, MSG_CH7_0043, MSG_CH7_0044,
        EVT_PTR(N(MayorLetterList)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LetterReward_Mayor) = {
    EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Mayor_CarryBucket) = {
    EVT_LABEL(0)
        EVT_CALL(GetNpcPos, NPC_MayorPenguin, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -5)
        EVT_ADD(LVar1, 15)
        EVT_CALL(GetNpcYaw, NPC_MayorPenguin, LVar3)
        EVT_IF_GE(LVar3, 90)
            EVT_IF_LE(LVar3, 270)
                EVT_ADD(LVar2, 10)
            EVT_ELSE
                EVT_ADD(LVar2, -10)
            EVT_END_IF
        EVT_ELSE
            EVT_ADD(LVar2, -10)
        EVT_END_IF
        EVT_CALL(SetItemPos, MV_BucketItemID, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Mayor_HandOverBucket) = {
    EVT_CALL(GetNpcYaw, NPC_MayorPenguin, LVar3)
    EVT_IF_GE(LVar3, 90)
        EVT_IF_LE(LVar3, 270)
            EVT_ADD(LVar2, 10)
            EVT_SET(LVar4, 10)
        EVT_ELSE
            EVT_ADD(LVar2, -10)
            EVT_SET(LVar4, -10)
        EVT_END_IF
    EVT_ELSE
        EVT_SUB(LVar2, 10)
        EVT_SET(LVar4, 10)
    EVT_END_IF
    EVT_THREAD
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_MayorPenguin, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, -5)
            EVT_ADD(LVar1, 15)
            EVT_ADD(LVar2, LVar4)
            EVT_CALL(SetItemPos, MV_BucketItemID, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetItemPos, MV_BucketItemID, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_MayorPenguin, LVar0, LVar2, 10 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_MayorPenguin) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_CALL(FadeOutMusic, 0, 500)
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH7_0002, 160, 40)
            EVT_EXEC_WAIT(N(EVS_Scene_MysteryBegins))
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH7_0002, 160, 40)
        EVT_CASE_LT(STORY_CH7_GOT_SNOWMAN_SCARF)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_0039)
        EVT_CASE_LT(STORY_CH7_GOT_SNOWMAN_BUCKET)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
            EVT_IF_GE(LVar2, LVar5)
                EVT_SET(MV_PlayerLeftOfMayor, 0)
            EVT_ELSE
                EVT_SET(MV_PlayerLeftOfMayor, 1)
            EVT_END_IF
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_003A)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MayorPenguin_Walk)
            EVT_CALL(NpcMoveTo, NPC_SELF, -338, -247, 20)
            EVT_CALL(PlaySoundAtCollider, COLLIDER_yana, SOUND_WOODEN_DOOR_OPEN, 0)
            EVT_CALL(MakeLerp, 0, 70, 30, EASING_LINEAR)
            EVT_LABEL(10)
                EVT_CALL(UpdateLerp)
                EVT_CALL(RotateModel, MODEL_o411, LVar0, 0, -1, 0)
                EVT_CALL(RotateModel, MODEL_o412, LVar0, 0, 1, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(10)
                EVT_END_IF
            EVT_WAIT(20 * DT)
            EVT_CALL(MakeLerp, 70, 0, 30, EASING_LINEAR)
            EVT_LABEL(20)
                EVT_CALL(UpdateLerp)
                EVT_CALL(RotateModel, MODEL_o411, LVar0, 0, -1, 0)
                EVT_CALL(RotateModel, MODEL_o412, LVar0, 0, 1, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(20)
                EVT_END_IF
            EVT_CALL(PlaySoundAtCollider, COLLIDER_yana, SOUND_WOODEN_DOOR_CLOSE, 0)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MayorPenguin_Carry)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 180, 0)
            EVT_EXEC_GET_TID(N(EVS_Mayor_CarryBucket), LVarA)
            EVT_WAIT(10 * DT)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_IF_EQ(MV_PlayerLeftOfMayor, 0)
                EVT_ADD(LVar2, -40)
            EVT_ELSE
                EVT_ADD(LVar2, 40)
            EVT_END_IF
            EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 20)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_003B)
            EVT_KILL_THREAD(LVarA)
            EVT_EXEC_WAIT(N(EVS_Mayor_HandOverBucket))
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MayorPenguin_Idle)
            EVT_GIVE_KEY_REWARD(ITEM_SNOWMAN_BUCKET)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_003C)
            EVT_CALL(GetNpcPos, NPC_MayorPenguin, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-8.5))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_003D)
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_SET(GB_StoryProgress, STORY_CH7_GOT_SNOWMAN_BUCKET)
        EVT_CASE_LT(STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_003E)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_003F)
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 0, MSG_CH7_0040)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_Mayor))
    EVT_EXEC_WAIT(N(EVS_LetterReward_Mayor))
    EVT_IF_NE(LVarC, DELIVERY_NOT_POSSIBLE)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_MayorPenguinWife) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_IF_EQ(GF_SAM01_Met_MayorsWife, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguinWife_Talk, ANIM_MayorPenguinWife_Idle, 0, MSG_CH7_0000)
                EVT_SET(GF_SAM01_Met_MayorsWife, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguinWife_Talk, ANIM_MayorPenguinWife_Idle, 0, MSG_CH7_0001)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguinWife_PointTalk, ANIM_MayorPenguinWife_Idle, 0, MSG_CH7_001C)
        EVT_CASE_LT(STORY_CH7_GOT_SNOWMAN_SCARF)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguinWife_Laugh, ANIM_MayorPenguinWife_Idle, 0, MSG_CH7_0035)
        EVT_CASE_LT(STORY_CH7_GOT_SNOWMAN_BUCKET)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguinWife_Laugh, ANIM_MayorPenguinWife_Idle, 0, MSG_CH7_0036)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguinWife_Laugh, ANIM_MayorPenguinWife_Idle, 0, MSG_CH7_0037)
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguinWife_Laugh, ANIM_MayorPenguinWife_Idle, 0, MSG_CH7_0038)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_PenguinPatrol) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_SPOKE_WITH_HERRINGWAY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_001B)
        EVT_CASE_GE(STORY_CH7_SPOKE_WITH_HERRINGWAY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_001D)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_PenguinPatrol) = {
    EVT_LABEL(0)
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_EQ(STORY_CH7_HERRINGWAY_AT_MAYORS_HOUSE)
                EVT_IF_EQ(AF_SAM_03, TRUE)
                    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                    EVT_IF_LT(LVar2, -130)
                        EVT_EXEC_WAIT(N(EVS_Scene_MysterySolved))
                    EVT_END_IF
                EVT_END_IF
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Herringway) = {
    EVT_IF_EQ(AF_SAM_04, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D3)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_SWITCH(MV_DialogueState_Penguin1)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0045)
                    EVT_SET(MV_DialogueState_Penguin1, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0046)
                    EVT_SET(MV_DialogueState_Penguin1, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_SWITCH(MV_DialogueState_Penguin1)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0047)
                    EVT_SET(MV_DialogueState_Penguin1, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0048)
                    EVT_SET(MV_DialogueState_Penguin1, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(MV_DialogueState_Penguin1)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0049)
                    EVT_SET(MV_DialogueState_Penguin1, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_004A)
                    EVT_SET(MV_DialogueState_Penguin1, 0)
            EVT_END_SWITCH
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_004B)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_SWITCH(MV_DialogueState_Penguin2)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_004C)
                    EVT_SET(MV_DialogueState_Penguin2, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_004D)
                    EVT_SET(MV_DialogueState_Penguin2, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_SWITCH(MV_DialogueState_Penguin2)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_004E)
                    EVT_SET(MV_DialogueState_Penguin2, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_004F)
                    EVT_SET(MV_DialogueState_Penguin2, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(MV_DialogueState_Penguin2)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0050)
                    EVT_SET(MV_DialogueState_Penguin2, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0051)
                    EVT_SET(MV_DialogueState_Penguin2, 0)
            EVT_END_SWITCH
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0052)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_SWITCH(MV_DialogueState_Penguin3)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0053)
                    EVT_SET(MV_DialogueState_Penguin3, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0054)
                    EVT_SET(MV_DialogueState_Penguin3, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_SWITCH(MV_DialogueState_Penguin3)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0055)
                    EVT_SET(MV_DialogueState_Penguin3, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0056)
                    EVT_SET(MV_DialogueState_Penguin3, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(MV_DialogueState_Penguin3)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0057)
                    EVT_SET(MV_DialogueState_Penguin3, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0058)
                    EVT_SET(MV_DialogueState_Penguin3, 0)
            EVT_END_SWITCH
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0059)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_04) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_SWITCH(MV_DialogueState_Penguin4)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_005A)
                    EVT_SET(MV_DialogueState_Penguin4, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_005B)
                    EVT_SET(MV_DialogueState_Penguin4, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_SWITCH(MV_DialogueState_Penguin4)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_005C)
                    EVT_SET(MV_DialogueState_Penguin4, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_005D)
                    EVT_SET(MV_DialogueState_Penguin4, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(MV_DialogueState_Penguin4)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_005E)
                    EVT_SET(MV_DialogueState_Penguin4, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_005F)
                    EVT_SET(MV_DialogueState_Penguin4, 0)
            EVT_END_SWITCH
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0060)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PenguinCrowd_Leave) = {
    EVT_CALL(SetNpcFlagBits, NPC_Penguin_05, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Penguin_06, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Penguin_07, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Penguin_08, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(BindNpcInteract, NPC_Penguin_05, 0)
    EVT_CALL(BindNpcInteract, NPC_Penguin_06, 0)
    EVT_CALL(BindNpcInteract, NPC_Penguin_07, 0)
    EVT_CALL(BindNpcInteract, NPC_Penguin_08, 0)
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_Penguin_05, EVT_FLOAT(3.0))
        EVT_CALL(SetNpcAnimation, NPC_Penguin_05, ANIM_Penguin_Walk)
        EVT_CALL(NpcMoveTo, NPC_Penguin_05, 600, 0, 0)
        EVT_CALL(SetNpcAnimation, NPC_Penguin_05, ANIM_Penguin_Idle)
        EVT_CALL(SetNpcPos, NPC_Penguin_05, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_Penguin_06, EVT_FLOAT(3.0))
        EVT_CALL(SetNpcAnimation, NPC_Penguin_06, ANIM_Penguin_Walk)
        EVT_CALL(NpcMoveTo, NPC_Penguin_06, 600, 0, 0)
        EVT_CALL(SetNpcAnimation, NPC_Penguin_06, ANIM_Penguin_Idle)
        EVT_CALL(SetNpcPos, NPC_Penguin_06, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_Penguin_07, EVT_FLOAT(3.0))
        EVT_CALL(SetNpcAnimation, NPC_Penguin_07, ANIM_Penguin_Walk)
        EVT_CALL(NpcMoveTo, NPC_Penguin_07, 600, 0, 0)
        EVT_CALL(SetNpcAnimation, NPC_Penguin_07, ANIM_Penguin_Idle)
        EVT_CALL(SetNpcPos, NPC_Penguin_07, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_Penguin_08, EVT_FLOAT(3.0))
        EVT_CALL(SetNpcAnimation, NPC_Penguin_08, ANIM_Penguin_Walk)
        EVT_CALL(NpcMoveTo, NPC_Penguin_08, 600, 0, 0)
        EVT_CALL(SetNpcAnimation, NPC_Penguin_08, ANIM_Penguin_Idle)
        EVT_CALL(SetNpcPos, NPC_Penguin_08, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_PenguinCrowd) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SpeakToPlayer, NPC_Penguin_05, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 5, MSG_CH7_0061)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_Penguin_06, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 5, MSG_CH7_0062)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_Penguin_07, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 5, MSG_CH7_0063)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_Penguin_08, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 5, MSG_CH7_0064)
        EVT_CASE_EQ(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SpeakToPlayer, NPC_Penguin_05, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 5, MSG_CH7_0065)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_Penguin_06, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 5, MSG_CH7_0066)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_Penguin_07, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 5, MSG_CH7_0067)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_Penguin_08, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 5, MSG_CH7_0068)
            EVT_EXEC(N(EVS_PenguinCrowd_Leave))
            EVT_WAIT(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_06) = {
    EVT_EXEC_WAIT(N(EVS_NpcInteract_PenguinCrowd))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_07) = {
    EVT_EXEC_WAIT(N(EVS_NpcInteract_PenguinCrowd))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_08) = {
    EVT_EXEC_WAIT(N(EVS_NpcInteract_PenguinCrowd))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Inspect_Present) = {
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH7_0004, 160, 40)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MayorPenguin) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_MayorPenguin)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SetNpcPos, NPC_SELF, -270, 0, -205)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 180, 0)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MayorPenguin_Dead)
        EVT_CASE_GE(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SetNpcPos, NPC_SELF, -300, 0, -160)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MayorDummy) = {
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 183, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MayorPenguinWife) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_MayorPenguinWife)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_CALL(SetNpcPos, NPC_SELF, -310, 0, 94)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SetNpcPos, NPC_SELF, -297, 0, -69)
        EVT_CASE_GE(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SetNpcPos, NPC_SELF, -297, 0, -69)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_PenguinPatrol) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_PenguinPatrol)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_PenguinPatrol)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SetNpcPos, NPC_SELF, -255, 0, -178)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Herringway) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_SPOKE_WITH_HERRINGWAY)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_LT(STORY_CH7_HERRINGWAY_AT_MAYORS_HOUSE)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(BindNpcInteract, NPC_Herringway, EVT_PTR(N(EVS_NpcInteract_Herringway)))
            EVT_CALL(SetNpcPos, NPC_SELF, -228, 0, 91)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
        EVT_CASE_GE(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_05) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_PenguinCrowd)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SetNpcPos, NPC_SELF, -150, 0, 0)
        EVT_CASE_GE(STORY_CH7_MAYOR_MURDER_SOLVED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_06) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_06)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SetNpcPos, NPC_SELF, -90, 0, 0)
        EVT_CASE_GE(STORY_CH7_MAYOR_MURDER_SOLVED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_07) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_07)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SetNpcPos, NPC_SELF, -120, 0, -30)
        EVT_CASE_GE(STORY_CH7_MAYOR_MURDER_SOLVED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_08) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_08)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SetNpcPos, NPC_SELF, -120, 0, 30)
        EVT_CASE_GE(STORY_CH7_MAYOR_MURDER_SOLVED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_09) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_SOLVED)
        EVT_CALL(SetNpcFlagBits, NPC_Penguin_09, NPC_FLAG_INVISIBLE | NPC_FLAG_10000000, TRUE)
        EVT_CALL(EnableNpcShadow, NPC_Penguin_09, FALSE)
        EVT_CALL(SetNpcPos, NPC_Penguin_09, -325, 0, -240)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_MayorPenguin)[] = {
    {
        .id = NPC_MayorPenguin,
        .pos = { -272.0f, 0.0f, -180.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_MayorPenguin),
        .settings = &N(NpcSettings_Penguin),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = MAYOR_PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_MayorPenguin,
    },
    {
        .id = NPC_MayorDummy,
        .pos = { -272.0f, 0.0f, -180.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_MayorDummy),
        .settings = &N(NpcSettings_Penguin),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = MAYOR_PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_MayorPenguin,
    },
    {
        .id = NPC_MayorPenguinWife,
        .pos = { -316.0f, 0.0f, 113.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_MayorPenguinWife),
        .settings = &N(NpcSettings_Penguin),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = MAYOR_PENGUIN_WIFE_ANIMS,
        .tattle = MSG_NpcTattle_MayorPenguinWife,
    },
    {
        .id = NPC_PenguinPatrol,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_PenguinPatrol),
        .settings = &N(NpcSettings_Penguin),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_PATROL_ANIMS,
        .tattle = MSG_NpcTattle_SAM_Patrol,
    },
    {
        .id = NPC_Herringway,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Herringway),
        .settings = &N(NpcSettings_Penguin),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = HERRINGWAY_ANIMS,
        .tattle = MSG_NpcTattle_Herringway,
    },
    {
        .id = NPC_Penguin_01,
        .pos = { -150.0f, 0.0f, 400.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -150, 0, 400 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Penguin_01),
        .settings = &N(NpcSettings_Penguin_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_GossipPenguin,
    },
    {
        .id = NPC_Penguin_02,
        .pos = { 100.0f, 0.0f, 250.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 100, 0, 250 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Penguin_02),
        .settings = &N(NpcSettings_Penguin_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_FriendlyPenguin,
    },
    {
        .id = NPC_Penguin_03,
        .pos = { 400.0f, 0.0f, 50.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 400, 0, 50 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Penguin_03),
        .settings = &N(NpcSettings_Penguin_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_CheerfulPenguin,
    },
    {
        .id = NPC_Penguin_04,
        .pos = { 350.0f, 0.0f, -190.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Penguin_04),
        .settings = &N(NpcSettings_Penguin),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_GenericPenguin,
    },
};

NpcData N(NpcData_Penguin_05)[] = {
    {
        .id = NPC_Penguin_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Penguin_05),
        .settings = &N(NpcSettings_Penguin),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_RumorLovingPenguins,
    },
    {
        .id = NPC_Penguin_06,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Penguin_06),
        .settings = &N(NpcSettings_Penguin),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_NotAdventurous,
    },
    {
        .id = NPC_Penguin_07,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 180,
        .init = &N(EVS_NpcInit_Penguin_07),
        .settings = &N(NpcSettings_Penguin),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_GenericPenguin,
    },
    {
        .id = NPC_Penguin_08,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Penguin_08),
        .settings = &N(NpcSettings_Penguin),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_GenericPenguin,
    },
};

NpcData N(NpcData_Penguin_09) = {
    .id = NPC_Penguin_09,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Penguin_09),
    .settings = &N(NpcSettings_Penguin),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = PENGUIN_ANIMS,
};

NpcData N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .pos = { 230.0f, 0.0f, 150.0f },
    .yaw = 90,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_SAM, QUIZ_COUNT_SAM, QUIZ_MAP_SAM_01 }},
    .settings = &N(NpcSettings_ChuckQuizmo),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = QUIZMO_ANIMS,
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

NpcGroupList N(BeforeNPCs) = {
    NPC_GROUP(N(NpcData_MayorPenguin), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_Penguin_05), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_Penguin_09), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};

NpcGroupList N(MysteryNPCs) = {
    NPC_GROUP(N(NpcData_MayorPenguin), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_Penguin_05), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_Penguin_09), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};

NpcGroupList N(AfterNPCs) = {
    NPC_GROUP(N(NpcData_MayorPenguin), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};
