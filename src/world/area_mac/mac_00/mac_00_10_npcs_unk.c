#include "mac_00.h"

#define NAME_SUFFIX _Shared
#include "world/common/npc/Toad_Wander.inc.c"
#include "world/common/npc/Toad_Patrol.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/complete/LetterDelivery.inc.c"
#define NAME_SUFFIX

s32 N(D_8024F5F4_7FA304)[] = {
    ITEM_LETTER18,
    ITEM_NONE
};

EvtScript N(D_8024F5FC_7FA30C) = {
    EVT_CALL(N(LetterDelivery_Init_Shared),
        NPC_ThreeSisters_03, ANIM_Toadette_Orange_Talk, ANIM_Toadette_Orange_Idle,
        ITEM_LETTER18, ITEM_LETTER19,
        MSG_MAC_Gate_00FF, MSG_MAC_Gate_0100, MSG_MAC_Gate_0101, MSG_MAC_Gate_0102,
        EVT_PTR(N(D_8024F5F4_7FA304)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery_Shared))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024F64C) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -225, 0, -300)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -225, 0, -300)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(800.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_WAIT(35)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.1))
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -225, 0, -300)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_Toad_04, 230, 0)
        EVT_CALL(SetNpcJumpscale, NPC_Toad_04, EVT_FLOAT(1.5))
        EVT_CALL(GetNpcPos, NPC_Toad_04, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Toad_04, LVar0, LVar1, LVar2, 5)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_Toad_04, ANIM_Toad_Red_Run)
        EVT_CALL(NpcMoveTo, NPC_Toad_04, -185, -295, 15)
        EVT_CALL(SetNpcAnimation, NPC_Toad_04, ANIM_Toad_Red_Idle)
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_CALL(PlayerMoveTo, -225, -300, 80)
    EVT_CALL(SetPlayerPos, -225, 0, -300)
    EVT_WAIT(50)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_80007)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Toad_04, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MAC_Gate_007E)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_04) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, 0x0002007F)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, 0x00020080)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x00020081)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, 0x00020082)
            EVT_ELSE
                EVT_SET(LVar0, 0x00020083)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x00020084)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC00_DictionaryStolen, FALSE)
                EVT_SET(LVar0, 0x00020085)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC00_DictionaryReturned, FALSE)
                    EVT_SET(LVar0, 0x00020086)
                EVT_ELSE
                    EVT_SET(LVar0, 0x00020087)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, 0x00020088)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x00020089)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, 0x0002008A)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x0002008B)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, 0x0002008C)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x0002008D)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x0002008E)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x0001002C)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024FBA0_7FA8B0) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(NpcFacePlayer, NPC_Toad_04, 0)
    EVT_WAIT(5)
    EVT_CALL(SpeakToPlayer, NPC_Toad_04, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Outro_002D)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0))
    EVT_CALL(PlayerMoveTo, -220, -250, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024FC44_7FA954) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(D_8024FBA0_7FA8B0)), TRIGGER_FLOOR_TOUCH, COLLIDER_o484, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_05) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, 0x0002008F)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, 0x00020090)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x00020091)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, 0x00020092)
            EVT_ELSE
                EVT_SET(LVar0, 0x00020093)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x00020094)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC00_DictionaryStolen, FALSE)
                EVT_SET(LVar0, 0x00020095)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC00_DictionaryReturned, FALSE)
                    EVT_SET(LVar0, 0x00020096)
                EVT_ELSE
                    EVT_SET(LVar0, 0x00020097)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, 0x00020098)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x00020099)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, 0x0002009A)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x0002009B)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, 0x0002009C)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x0002009D)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x0002009E)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x0001002E)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_06) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, 0x0002009F)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, 0x000200A0)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000200A1)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, 0x000200A2)
            EVT_ELSE
                EVT_SET(LVar0, 0x000200A3)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x000200A4)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC00_DictionaryStolen, FALSE)
                EVT_SET(LVar0, 0x000200A5)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC00_DictionaryReturned, FALSE)
                    EVT_SET(LVar0, 0x000200A6)
                EVT_ELSE
                    EVT_SET(LVar0, 0x000200A7)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, 0x000200A8)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000200A9)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, 0x000200AA)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x000200AB)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, 0x000200AC)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000200AD)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x000200AE)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x0001002F)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_07) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, 0x000200AF)
            EVT_SET(LVar1, 0x000200B0)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, 0x000200B1)
            EVT_SET(LVar1, 0x000200B2)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000200B3)
            EVT_SET(LVar1, 0x000200B4)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, 0x000200B5)
                EVT_SET(LVar1, 0x000200B6)
            EVT_ELSE
                EVT_SET(LVar0, 0x000200B7)
                EVT_SET(LVar1, 0x000200B8)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x000200B9)
            EVT_SET(LVar1, 0x000200BA)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_ShyGuyBlockingTracks, FALSE)
                EVT_SET(LVar0, 0x000200BB)
                EVT_SET(LVar1, 0x000200BC)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC03_ShyGuyChasedOff, FALSE)
                    EVT_SET(LVar0, 0x000200BD)
                    EVT_SET(LVar1, 0x000200BE)
                EVT_ELSE
                    EVT_SET(LVar0, 0x000200BF)
                    EVT_SET(LVar1, 0x000200C0)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, 0x000200C1)
            EVT_SET(LVar1, 0x000200C2)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000200C3)
            EVT_SET(LVar1, 0x000200C4)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, 0x000200C5)
            EVT_SET(LVar1, 0x000200C6)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x000200C7)
            EVT_SET(LVar1, 0x000200C8)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, 0x000200C9)
            EVT_SET(LVar1, 0x000200CA)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000200CB)
            EVT_SET(LVar1, 0x000200CC)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x000200CD)
            EVT_SET(LVar1, 0x000200CE)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x00010030)
            EVT_SET(LVar1, 0x00010031)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_07, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 5, LVar0)
    EVT_CALL(SpeakToPlayer, NPC_ThreeSisters_01, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, LVar1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ThreeSisters_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, 0x000200CF)
            EVT_SET(LVar1, 0x000200D0)
            EVT_SET(LVar2, 0x000200D1)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, 0x000200D2)
            EVT_SET(LVar1, 0x000200D3)
            EVT_SET(LVar2, 0x000200D4)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000200D5)
            EVT_SET(LVar1, 0x000200D6)
            EVT_SET(LVar2, 0x000200D7)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, 0x000200D8)
                EVT_SET(LVar1, 0x000200D9)
                EVT_SET(LVar2, 0x000200DA)
            EVT_ELSE
                EVT_SET(LVar0, 0x000200DB)
                EVT_SET(LVar1, 0x000200DC)
                EVT_SET(LVar2, 0x000200DD)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x000200DE)
            EVT_SET(LVar1, 0x000200DF)
            EVT_SET(LVar2, 0x000200E0)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_IF_EQ(GF_MAC04_StoreroomKeyStolen, FALSE)
                EVT_SET(LVar0, 0x000200E1)
                EVT_SET(LVar1, 0x000200E2)
                EVT_SET(LVar2, 0x000200E3)
            EVT_ELSE
                EVT_SET(LVar0, 0x000200E4)
                EVT_SET(LVar1, 0x000200E5)
                EVT_SET(LVar2, 0x000200E6)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000200E7)
            EVT_SET(LVar1, 0x000200E8)
            EVT_SET(LVar2, 0x000200E9)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, 0x000200EA)
            EVT_SET(LVar1, 0x000200EB)
            EVT_SET(LVar2, 0x000200EC)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000200ED)
            EVT_SET(LVar1, 0x000200EE)
            EVT_SET(LVar2, 0x000200EF)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, 0x000200F0)
            EVT_SET(LVar1, 0x000200F1)
            EVT_SET(LVar2, 0x000200F2)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x000200F3)
            EVT_SET(LVar1, 0x000200F4)
            EVT_SET(LVar2, 0x000200F5)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, 0x000200F6)
            EVT_SET(LVar1, 0x000200F7)
            EVT_SET(LVar2, 0x000200F8)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x000200F9)
            EVT_SET(LVar1, 0x000200FA)
            EVT_SET(LVar2, 0x000200FB)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x000200FC)
            EVT_SET(LVar1, 0x000200FD)
            EVT_SET(LVar2, 0x000200FE)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x00010032)
            EVT_SET(LVar1, 0x00010033)
            EVT_SET(LVar2, 0x00010034)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_ThreeSisters_02, ANIM_Toadette_Green_Talk, ANIM_Toadette_Green_Idle, 0, LVar0)
    EVT_CALL(SpeakToPlayer, NPC_ThreeSisters_03, ANIM_Toadette_Orange_Talk, ANIM_Toadette_Orange_Idle, 0, LVar1)
    EVT_CALL(SpeakToPlayer, NPC_ThreeSisters_04, ANIM_Toadette_Purple_Talk, ANIM_Toadette_Purple_Idle, 0, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ThreeSisters_03) = {
    EVT_EXEC_WAIT(N(EVS_NpcInteract_ThreeSisters_02))
    EVT_EXEC_WAIT(N(D_8024F5FC_7FA30C))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_08) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, 0x00020103)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, 0x00020104)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x00020105)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, 0x00020106)
            EVT_ELSE
                EVT_SET(LVar0, 0x00020107)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x00020108)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC00_DictionaryStolen, FALSE)
                EVT_SET(LVar0, 0x00020109)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC00_DictionaryReturned, FALSE)
                    EVT_SET(LVar0, 0x0002010A)
                EVT_ELSE
                    EVT_SET(LVar0, 0x0002010B)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, 0x0002010C)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x0002010D)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, 0x0002010E)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, 0x0002010F)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, 0x00020110)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, 0x00020111)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x00020112)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, 0x00010035)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_ThreeSisters_01) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Toadette_Pink_Still)
    EVT_WAIT(3)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Toadette_Pink_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_ThreeSisters_02) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Toadette_Green_Still)
    EVT_WAIT(2)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Toadette_Green_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_ThreeSisters_03) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Toadette_Orange_Still)
    EVT_WAIT(6)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Toadette_Orange_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_ThreeSisters_04) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Toadette_Purple_Still)
    EVT_WAIT(8)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Toadette_Purple_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_09) = {
    EVT_CALL(FindKeyItem, ITEM_FIRST_DEGREE_CARD, LVar1)
    EVT_CALL(FindKeyItem, ITEM_SECOND_DEGREE_CARD, LVar2)
    EVT_CALL(FindKeyItem, ITEM_THIRD_DEGREE_CARD, LVar3)
    EVT_CALL(FindKeyItem, ITEM_FOURTH_DEGREE_CARD, LVar4)
    EVT_CALL(FindKeyItem, ITEM_DIPLOMA, LVar5)
    EVT_IF_NE(LVar1, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_MAC_Gate_0114)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(LVar2, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_MAC_Gate_0115)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(LVar3, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_MAC_Gate_0116)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(LVar4, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_MAC_Gate_0117)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_NE(LVar5, -1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_MAC_Gate_0118)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_MAC_Gate_0113)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_04)))
    EVT_IF_LT(GB_StoryProgress, STORY_EPILOGUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, mac_00_ENTRY_7)
        EVT_EXEC(N(D_8024FC44_7FA954))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_05) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_05)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_06) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_06)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_07) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_07)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ThreeSisters_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_07)))
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_ThreeSisters_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ThreeSisters_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ThreeSisters_02)))
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_ThreeSisters_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ThreeSisters_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ThreeSisters_03)))
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_ThreeSisters_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ThreeSisters_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ThreeSisters_02)))
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_ThreeSisters_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_08) = {
    EVT_IF_GE(GB_StoryProgress, STORY_EPILOGUE)
        EVT_CALL(SetNpcPos, NPC_Toad_08, 350, 20, -100)
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_08)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_09) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_09)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Toad_04)[] = {
    {
        .id = NPC_Toad_04,
        .settings = &N(NpcSettings_Toad_Stationary_Shared),
        .pos = { -150.0f, 0.0f, -275.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000 | ENEMY_FLAGS_100000,
        .init = &N(EVS_NpcInit_Toad_04),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toad_Red_Idle,
            .walk   = ANIM_Toad_Red_Walk,
            .run    = ANIM_Toad_Red_Run,
            .chase  = ANIM_Toad_Red_Run,
            .anim_4 = ANIM_Toad_Red_Idle,
            .anim_5 = ANIM_Toad_Red_Idle,
            .death  = ANIM_Toad_Red_Disappointed,
            .hit    = ANIM_Toad_Red_Disappointed,
            .anim_8 = ANIM_Toad_Red_Run,
            .anim_9 = ANIM_Toad_Red_Run,
            .anim_A = ANIM_Toad_Red_Run,
            .anim_B = ANIM_Toad_Red_Run,
            .anim_C = ANIM_Toad_Red_Run,
            .anim_D = ANIM_Toad_Red_Run,
            .anim_E = ANIM_Toad_Red_Run,
            .anim_F = ANIM_Toad_Red_Run,
        },
        .tattle = MSG_NpcTattle_MAC_GateGuardian,
    },
    {
        .id = NPC_Toad_05,
        .settings = &N(NpcSettings_Toad_Wander_Shared),
        .pos = { 219.0f, 0.0f, -45.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000,
        .init = &N(EVS_NpcInit_Toad_05),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 5,
                .points  = {
                    { 219, 0, -45 },
                    { 144, 0, -10 },
                    { 163, 0, -50 },
                    { 240, 0, 50 },
                    { 275, 0, 10 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 200 },
            }
        },
        .animations = {
            .idle   = ANIM_Toad_Red_Idle,
            .walk   = ANIM_Toad_Red_Walk,
            .run    = ANIM_Toad_Red_Run,
            .chase  = ANIM_Toad_Red_Run,
            .anim_4 = ANIM_Toad_Red_Idle,
            .anim_5 = ANIM_Toad_Red_Idle,
            .death  = ANIM_Toad_Red_Disappointed,
            .hit    = ANIM_Toad_Red_Disappointed,
            .anim_8 = ANIM_Toad_Red_Run,
            .anim_9 = ANIM_Toad_Red_Run,
            .anim_A = ANIM_Toad_Red_Run,
            .anim_B = ANIM_Toad_Red_Run,
            .anim_C = ANIM_Toad_Red_Run,
            .anim_D = ANIM_Toad_Red_Run,
            .anim_E = ANIM_Toad_Red_Run,
            .anim_F = ANIM_Toad_Red_Run,
        },
        .tattle = MSG_NpcTattle_MAC_ShopLoiterer,
    },
    {
        .id = NPC_Toad_06,
        .settings = &N(NpcSettings_Toad_Patrol_Shared),
        .pos = { -290.0f, 0.0f, -120.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000,
        .init = &N(EVS_NpcInit_Toad_06),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { -290, 0, -120 },
                    { 37, 0, -150 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 200 },
            }
        },
        .animations = {
            .idle   = ANIM_Toad_Yellow_Idle,
            .walk   = ANIM_Toad_Yellow_Walk,
            .run    = ANIM_Toad_Yellow_Run,
            .chase  = ANIM_Toad_Yellow_Run,
            .anim_4 = ANIM_Toad_Yellow_Idle,
            .anim_5 = ANIM_Toad_Yellow_Idle,
            .death  = ANIM_Toad_Yellow_Disappointed,
            .hit    = ANIM_Toad_Yellow_Disappointed,
            .anim_8 = ANIM_Toad_Yellow_Run,
            .anim_9 = ANIM_Toad_Yellow_Run,
            .anim_A = ANIM_Toad_Yellow_Run,
            .anim_B = ANIM_Toad_Yellow_Run,
            .anim_C = ANIM_Toad_Yellow_Run,
            .anim_D = ANIM_Toad_Yellow_Run,
            .anim_E = ANIM_Toad_Yellow_Run,
            .anim_F = ANIM_Toad_Yellow_Run,
        },
        .tattle = MSG_NpcTattle_MAC_NewsEnthusiast,
    },
    {
        .id = NPC_Toad_07,
        .settings = &N(NpcSettings_Toad_Stationary_Shared),
        .pos = { -40.0f, 0.0f, 61.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000 | ENEMY_FLAGS_400000,
        .init = &N(EVS_NpcInit_Toad_07),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toad_Blue_Idle,
            .walk   = ANIM_Toad_Blue_Walk,
            .run    = ANIM_Toad_Blue_Run,
            .chase  = ANIM_Toad_Blue_Run,
            .anim_4 = ANIM_Toad_Blue_Idle,
            .anim_5 = ANIM_Toad_Blue_Idle,
            .death  = ANIM_Toad_Blue_Disappointed,
            .hit    = ANIM_Toad_Blue_Disappointed,
            .anim_8 = ANIM_Toad_Blue_Run,
            .anim_9 = ANIM_Toad_Blue_Run,
            .anim_A = ANIM_Toad_Blue_Run,
            .anim_B = ANIM_Toad_Blue_Run,
            .anim_C = ANIM_Toad_Blue_Run,
            .anim_D = ANIM_Toad_Blue_Run,
            .anim_E = ANIM_Toad_Blue_Run,
            .anim_F = ANIM_Toad_Blue_Run,
        },
        .tattle = MSG_NpcTattle_MAC_FickleLovers,
    },
    {
        .id = NPC_ThreeSisters_01,
        .settings = &N(NpcSettings_Toad_Stationary_Shared),
        .pos = { -15.0f, 0.0f, 60.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000 | ENEMY_FLAGS_400000,
        .init = &N(EVS_NpcInit_ThreeSisters_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toadette_Pink_Idle,
            .walk   = ANIM_Toadette_Pink_Walk,
            .run    = ANIM_Toadette_Pink_Run,
            .chase  = ANIM_Toadette_Pink_Run,
            .anim_4 = ANIM_Toadette_Pink_Idle,
            .anim_5 = ANIM_Toadette_Pink_Idle,
            .death  = ANIM_Toadette_Pink_Disappointed,
            .hit    = ANIM_Toadette_Pink_Disappointed,
            .anim_8 = ANIM_Toadette_Pink_Run,
            .anim_9 = ANIM_Toadette_Pink_Run,
            .anim_A = ANIM_Toadette_Pink_Run,
            .anim_B = ANIM_Toadette_Pink_Run,
            .anim_C = ANIM_Toadette_Pink_Run,
            .anim_D = ANIM_Toadette_Pink_Run,
            .anim_E = ANIM_Toadette_Pink_Run,
            .anim_F = ANIM_Toadette_Pink_Run,
        },
        .tattle = MSG_NpcTattle_MAC_ShamlessLover,
    },
    {
        .id = NPC_ThreeSisters_02,
        .settings = &N(NpcSettings_Toad_Stationary_Shared),
        .pos = { 426.0f, 20.0f, 268.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000,
        .init = &N(EVS_NpcInit_ThreeSisters_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toadette_Green_Idle,
            .walk   = ANIM_Toadette_Green_Walk,
            .run    = ANIM_Toadette_Green_Run,
            .chase  = ANIM_Toadette_Green_Run,
            .anim_4 = ANIM_Toadette_Green_Idle,
            .anim_5 = ANIM_Toadette_Green_Idle,
            .death  = ANIM_Toadette_Green_Disappointed,
            .hit    = ANIM_Toadette_Green_Disappointed,
            .anim_8 = ANIM_Toadette_Green_Run,
            .anim_9 = ANIM_Toadette_Green_Run,
            .anim_A = ANIM_Toadette_Green_Run,
            .anim_B = ANIM_Toadette_Green_Run,
            .anim_C = ANIM_Toadette_Green_Run,
            .anim_D = ANIM_Toadette_Green_Run,
            .anim_E = ANIM_Toadette_Green_Run,
            .anim_F = ANIM_Toadette_Green_Run,
        },
        .tattle = MSG_NpcTattle_MAC_ThreeSisters_Eldest,
    },
    {
        .id = NPC_ThreeSisters_03,
        .settings = &N(NpcSettings_Toad_Stationary_Shared),
        .pos = { 381.0f, 20.0f, 326.0f },
        .yaw = 180,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000,
        .init = &N(EVS_NpcInit_ThreeSisters_03),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toadette_Orange_Idle,
            .walk   = ANIM_Toadette_Orange_Walk,
            .run    = ANIM_Toadette_Orange_Run,
            .chase  = ANIM_Toadette_Orange_Run,
            .anim_4 = ANIM_Toadette_Orange_Idle,
            .anim_5 = ANIM_Toadette_Orange_Idle,
            .death  = ANIM_Toadette_Orange_Disappointed,
            .hit    = ANIM_Toadette_Orange_Disappointed,
            .anim_8 = ANIM_Toadette_Orange_Run,
            .anim_9 = ANIM_Toadette_Orange_Run,
            .anim_A = ANIM_Toadette_Orange_Run,
            .anim_B = ANIM_Toadette_Orange_Run,
            .anim_C = ANIM_Toadette_Orange_Run,
            .anim_D = ANIM_Toadette_Orange_Run,
            .anim_E = ANIM_Toadette_Orange_Run,
            .anim_F = ANIM_Toadette_Orange_Run,
        },
        .tattle = MSG_NpcTattle_MAC_ThreeSisters_Middle,
    },
    {
        .id = NPC_ThreeSisters_04,
        .settings = &N(NpcSettings_Toad_Stationary_Shared),
        .pos = { 476.0f, 20.0f, 326.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000,
        .init = &N(EVS_NpcInit_ThreeSisters_04),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toadette_Purple_Idle,
            .walk   = ANIM_Toadette_Purple_Walk,
            .run    = ANIM_Toadette_Purple_Run,
            .chase  = ANIM_Toadette_Purple_Run,
            .anim_4 = ANIM_Toadette_Purple_Idle,
            .anim_5 = ANIM_Toadette_Purple_Idle,
            .death  = ANIM_Toadette_Purple_Disappointed,
            .hit    = ANIM_Toadette_Purple_Disappointed,
            .anim_8 = ANIM_Toadette_Purple_Run,
            .anim_9 = ANIM_Toadette_Purple_Run,
            .anim_A = ANIM_Toadette_Purple_Run,
            .anim_B = ANIM_Toadette_Purple_Run,
            .anim_C = ANIM_Toadette_Purple_Run,
            .anim_D = ANIM_Toadette_Purple_Run,
            .anim_E = ANIM_Toadette_Purple_Run,
            .anim_F = ANIM_Toadette_Purple_Run,
        },
        .tattle = MSG_NpcTattle_MAC_hreeSisters_Youngest,
    },
    {
        .id = NPC_Toad_08,
        .settings = &N(NpcSettings_Toad_Stationary_Shared),
        .pos = { 424.0f, 20.0f, -85.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000,
        .init = &N(EVS_NpcInit_Toad_08),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toad_Blue_Idle,
            .walk   = ANIM_Toad_Blue_Walk,
            .run    = ANIM_Toad_Blue_Run,
            .chase  = ANIM_Toad_Blue_Run,
            .anim_4 = ANIM_Toad_Blue_Idle,
            .anim_5 = ANIM_Toad_Blue_Idle,
            .death  = ANIM_Toad_Blue_Disappointed,
            .hit    = ANIM_Toad_Blue_Disappointed,
            .anim_8 = ANIM_Toad_Blue_Run,
            .anim_9 = ANIM_Toad_Blue_Run,
            .anim_A = ANIM_Toad_Blue_Run,
            .anim_B = ANIM_Toad_Blue_Run,
            .anim_C = ANIM_Toad_Blue_Run,
            .anim_D = ANIM_Toad_Blue_Run,
            .anim_E = ANIM_Toad_Blue_Run,
            .anim_F = ANIM_Toad_Blue_Run,
        },
        .tattle = MSG_NpcTattle_MAC_DojoSpectator,
    },
    {
        .id = NPC_Toad_09,
        .settings = &N(NpcSettings_Toad_Stationary_Shared),
        .pos = { 373.0f, 0.0f, 22.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_10000,
        .init = &N(EVS_NpcInit_Toad_09),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Toad_Yellow_Idle,
            .walk   = ANIM_Toad_Yellow_Walk,
            .run    = ANIM_Toad_Yellow_Run,
            .chase  = ANIM_Toad_Yellow_Run,
            .anim_4 = ANIM_Toad_Yellow_Idle,
            .anim_5 = ANIM_Toad_Yellow_Idle,
            .death  = ANIM_Toad_Yellow_Disappointed,
            .hit    = ANIM_Toad_Yellow_Disappointed,
            .anim_8 = ANIM_Toad_Yellow_Run,
            .anim_9 = ANIM_Toad_Yellow_Run,
            .anim_A = ANIM_Toad_Yellow_Run,
            .anim_B = ANIM_Toad_Yellow_Run,
            .anim_C = ANIM_Toad_Yellow_Run,
            .anim_D = ANIM_Toad_Yellow_Run,
            .anim_E = ANIM_Toad_Yellow_Run,
            .anim_F = ANIM_Toad_Yellow_Run,
        },
        .tattle = MSG_NpcTattle_MAC_DojoFanToad,
    },
};
