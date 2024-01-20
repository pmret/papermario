#include "mac_00.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Shared
#include "world/common/npc/Toad_Wander.inc.c"
#include "world/common/npc/Toad_Patrol.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/complete/LetterDelivery.inc.c"
#define NAME_SUFFIX

s32 N(LetterList_MissT)[] = {
    ITEM_LETTER_CHAIN_MISS_T,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_MissT) = {
    Call(N(LetterDelivery_Init_Shared),
        NPC_MissT, ANIM_Toadette_Orange_Talk, ANIM_Toadette_Orange_Idle,
        ITEM_LETTER_CHAIN_MISS_T, ITEM_LETTER_CHAIN_LITTLE_MOUSER,
        MSG_MAC_Gate_00FF, MSG_MAC_Gate_0100, MSG_MAC_Gate_0101, MSG_MAC_Gate_0102,
        Ref(N(LetterList_MissT)))
    ExecWait(N(EVS_DoLetterDelivery_Shared))
    Return
    End
};

EvtScript N(EVS_Scene_ToadTownGreeting) = {
    Call(DisablePlayerInput, TRUE)
    Call(UseSettingsFrom, CAM_DEFAULT, -225, 0, -300)
    Call(SetPanTarget, CAM_DEFAULT, -225, 0, -300)
    Call(SetCamDistance, CAM_DEFAULT, Float(800.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Thread
        Wait(35 * DT)
        Call(SetCamSpeed, CAM_DEFAULT, Float(2.1 / DT))
        Call(UseSettingsFrom, CAM_DEFAULT, -225, 0, -300)
        Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Wait(10 * DT)
        Call(InterpNpcYaw, NPC_Toad_04, 230, 0)
        Call(SetNpcJumpscale, NPC_Toad_04, Float(1.5))
        Call(GetNpcPos, NPC_Toad_04, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_Toad_04, LVar0, LVar1, LVar2, 5 * DT)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_Toad_04, ANIM_Toad_Red_Run)
        Call(NpcMoveTo, NPC_Toad_04, -185, -295, 15 * DT)
        Call(SetNpcAnimation, NPC_Toad_04, ANIM_Toad_Red_Idle)
    EndThread
    Wait(2)
    Call(PlayerMoveTo, -225, -300, 80)
    Call(SetPlayerPos, -225, 0, -300)
    Wait(50 * DT)
    Thread
        Wait(20 * DT)
        Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EndThread
    Call(SpeakToPlayer, NPC_Toad_04, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MAC_Gate_007E)
    Call(DisablePlayerInput, FALSE)
    Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_04) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Gate_007F)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Gate_0080)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_0081)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Gate_0082)
            Else
                Set(LVar0, MSG_MAC_Gate_0083)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_0084)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC00_DictionaryStolen, FALSE)
                Set(LVar0, MSG_MAC_Gate_0085)
            Else
                IfEq(GF_MAC00_DictionaryReturned, FALSE)
                    Set(LVar0, MSG_MAC_Gate_0086)
                Else
                    Set(LVar0, MSG_MAC_Gate_0087)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Gate_0088)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_0089)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Gate_008A)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_008B)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Gate_008C)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_008D)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Gate_008E)
        CaseGe(STORY_EPILOGUE)
            Set(LVar0, MSG_Outro_002C)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_Scene_CantLeaveTown) = {
    Call(DisablePlayerInput, TRUE)
    Call(NpcFacePlayer, NPC_Toad_04, 0)
    Wait(5)
    Call(SpeakToPlayer, NPC_Toad_04, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Outro_002D)
    Wait(10)
    Call(SetPlayerSpeed, Float(4.0))
    Call(PlayerMoveTo, -220, -250, 0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_BlockExitToGoomaRoad) = {
    BindTrigger(Ref(N(EVS_Scene_CantLeaveTown)), TRIGGER_FLOOR_TOUCH, COLLIDER_o484, 1, 0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_05) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Gate_008F)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Gate_0090)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_0091)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Gate_0092)
            Else
                Set(LVar0, MSG_MAC_Gate_0093)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_0094)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC00_DictionaryStolen, FALSE)
                Set(LVar0, MSG_MAC_Gate_0095)
            Else
                IfEq(GF_MAC00_DictionaryReturned, FALSE)
                    Set(LVar0, MSG_MAC_Gate_0096)
                Else
                    Set(LVar0, MSG_MAC_Gate_0097)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Gate_0098)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_0099)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Gate_009A)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_009B)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Gate_009C)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_009D)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Gate_009E)
        CaseGe(STORY_EPILOGUE)
            Set(LVar0, MSG_Outro_002E)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_06) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Gate_009F)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Gate_00A0)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_00A1)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Gate_00A2)
            Else
                Set(LVar0, MSG_MAC_Gate_00A3)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_00A4)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC00_DictionaryStolen, FALSE)
                Set(LVar0, MSG_MAC_Gate_00A5)
            Else
                IfEq(GF_MAC00_DictionaryReturned, FALSE)
                    Set(LVar0, MSG_MAC_Gate_00A6)
                Else
                    Set(LVar0, MSG_MAC_Gate_00A7)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Gate_00A8)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_00A9)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Gate_00AA)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_00AB)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Gate_00AC)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_00AD)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Gate_00AE)
        CaseGe(STORY_EPILOGUE)
            Set(LVar0, MSG_Outro_002F)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Lovers) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Gate_00AF)
            Set(LVar1, MSG_MAC_Gate_00B0)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Gate_00B1)
            Set(LVar1, MSG_MAC_Gate_00B2)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_00B3)
            Set(LVar1, MSG_MAC_Gate_00B4)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Gate_00B5)
                Set(LVar1, MSG_MAC_Gate_00B6)
            Else
                Set(LVar0, MSG_MAC_Gate_00B7)
                Set(LVar1, MSG_MAC_Gate_00B8)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_00B9)
            Set(LVar1, MSG_MAC_Gate_00BA)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_ShyGuyBlockingTracks, FALSE)
                Set(LVar0, MSG_MAC_Gate_00BB)
                Set(LVar1, MSG_MAC_Gate_00BC)
            Else
                IfEq(GF_MAC03_ShyGuyChasedOff, FALSE)
                    Set(LVar0, MSG_MAC_Gate_00BD)
                    Set(LVar1, MSG_MAC_Gate_00BE)
                Else
                    Set(LVar0, MSG_MAC_Gate_00BF)
                    Set(LVar1, MSG_MAC_Gate_00C0)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Gate_00C1)
            Set(LVar1, MSG_MAC_Gate_00C2)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_00C3)
            Set(LVar1, MSG_MAC_Gate_00C4)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Gate_00C5)
            Set(LVar1, MSG_MAC_Gate_00C6)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_00C7)
            Set(LVar1, MSG_MAC_Gate_00C8)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Gate_00C9)
            Set(LVar1, MSG_MAC_Gate_00CA)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_00CB)
            Set(LVar1, MSG_MAC_Gate_00CC)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Gate_00CD)
            Set(LVar1, MSG_MAC_Gate_00CE)
        CaseGe(STORY_EPILOGUE)
            Set(LVar0, MSG_Outro_0030)
            Set(LVar1, MSG_Outro_0031)
    EndSwitch
    Call(SpeakToPlayer, NPC_FickleLover, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 5, LVar0)
    Call(SpeakToPlayer, NPC_ShamelessLover, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, LVar1)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toadette) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Gate_00CF)
            Set(LVar1, MSG_MAC_Gate_00D0)
            Set(LVar2, MSG_MAC_Gate_00D1)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Gate_00D2)
            Set(LVar1, MSG_MAC_Gate_00D3)
            Set(LVar2, MSG_MAC_Gate_00D4)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_00D5)
            Set(LVar1, MSG_MAC_Gate_00D6)
            Set(LVar2, MSG_MAC_Gate_00D7)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Gate_00D8)
                Set(LVar1, MSG_MAC_Gate_00D9)
                Set(LVar2, MSG_MAC_Gate_00DA)
            Else
                Set(LVar0, MSG_MAC_Gate_00DB)
                Set(LVar1, MSG_MAC_Gate_00DC)
                Set(LVar2, MSG_MAC_Gate_00DD)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_00DE)
            Set(LVar1, MSG_MAC_Gate_00DF)
            Set(LVar2, MSG_MAC_Gate_00E0)
        CaseLt(STORY_CH4_RETURNED_STOREROOM_KEY)
            IfEq(GF_MAC04_StoreroomKeyStolen, FALSE)
                Set(LVar0, MSG_MAC_Gate_00E1)
                Set(LVar1, MSG_MAC_Gate_00E2)
                Set(LVar2, MSG_MAC_Gate_00E3)
            Else
                Set(LVar0, MSG_MAC_Gate_00E4)
                Set(LVar1, MSG_MAC_Gate_00E5)
                Set(LVar2, MSG_MAC_Gate_00E6)
            EndIf
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_00E7)
            Set(LVar1, MSG_MAC_Gate_00E8)
            Set(LVar2, MSG_MAC_Gate_00E9)
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Gate_00EA)
            Set(LVar1, MSG_MAC_Gate_00EB)
            Set(LVar2, MSG_MAC_Gate_00EC)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_00ED)
            Set(LVar1, MSG_MAC_Gate_00EE)
            Set(LVar2, MSG_MAC_Gate_00EF)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Gate_00F0)
            Set(LVar1, MSG_MAC_Gate_00F1)
            Set(LVar2, MSG_MAC_Gate_00F2)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_00F3)
            Set(LVar1, MSG_MAC_Gate_00F4)
            Set(LVar2, MSG_MAC_Gate_00F5)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Gate_00F6)
            Set(LVar1, MSG_MAC_Gate_00F7)
            Set(LVar2, MSG_MAC_Gate_00F8)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_00F9)
            Set(LVar1, MSG_MAC_Gate_00FA)
            Set(LVar2, MSG_MAC_Gate_00FB)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Gate_00FC)
            Set(LVar1, MSG_MAC_Gate_00FD)
            Set(LVar2, MSG_MAC_Gate_00FE)
        CaseGe(STORY_EPILOGUE)
            Set(LVar0, MSG_Outro_0032)
            Set(LVar1, MSG_Outro_0033)
            Set(LVar2, MSG_Outro_0034)
    EndSwitch
    Call(SpeakToPlayer, NPC_KrisT, ANIM_Toadette_Green_Talk, ANIM_Toadette_Green_Idle, 0, LVar0)
    Call(SpeakToPlayer, NPC_MissT, ANIM_Toadette_Orange_Talk, ANIM_Toadette_Orange_Idle, 0, LVar1)
    Call(SpeakToPlayer, NPC_FelissaT, ANIM_Toadette_Purple_Talk, ANIM_Toadette_Purple_Idle, 0, LVar2)
    Return
    End
};

EvtScript N(EVS_NpcInteract_MissT) = {
    ExecWait(N(EVS_NpcInteract_Toadette))
    ExecWait(N(EVS_LetterPrompt_MissT))
    IfNe(LVarC, 0)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_08) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Gate_0103)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Gate_0104)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_0105)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Gate_0106)
            Else
                Set(LVar0, MSG_MAC_Gate_0107)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_0108)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC00_DictionaryStolen, FALSE)
                Set(LVar0, MSG_MAC_Gate_0109)
            Else
                IfEq(GF_MAC00_DictionaryReturned, FALSE)
                    Set(LVar0, MSG_MAC_Gate_010A)
                Else
                    Set(LVar0, MSG_MAC_Gate_010B)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Gate_010C)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_010D)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Gate_010E)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_010F)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Gate_0110)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_0111)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Gate_0112)
        CaseGe(STORY_EPILOGUE)
            Set(LVar0, MSG_Outro_0035)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcAux_ShamelessLover) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_Toadette_Pink_Still)
    Wait(3)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Toadette_Pink_Idle)
    Return
    End
};

EvtScript N(EVS_NpcAux_KrisT) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_Toadette_Green_Still)
    Wait(2)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Toadette_Green_Idle)
    Return
    End
};

EvtScript N(EVS_NpcAux_MissT) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_Toadette_Orange_Still)
    Wait(6)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Toadette_Orange_Idle)
    Return
    End
};

EvtScript N(EVS_NpcAux_FelissaT) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_Toadette_Purple_Still)
    Wait(8)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Toadette_Purple_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_09) = {
    Call(FindKeyItem, ITEM_FIRST_DEGREE_CARD, LVar1)
    Call(FindKeyItem, ITEM_SECOND_DEGREE_CARD, LVar2)
    Call(FindKeyItem, ITEM_THIRD_DEGREE_CARD, LVar3)
    Call(FindKeyItem, ITEM_FOURTH_DEGREE_CARD, LVar4)
    Call(FindKeyItem, ITEM_DIPLOMA, LVar5)
    IfNe(LVar1, -1)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_MAC_Gate_0114)
        Return
    EndIf
    IfNe(LVar2, -1)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_MAC_Gate_0115)
        Return
    EndIf
    IfNe(LVar3, -1)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_MAC_Gate_0116)
        Return
    EndIf
    IfNe(LVar4, -1)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_MAC_Gate_0117)
        Return
    EndIf
    IfNe(LVar5, -1)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_MAC_Gate_0118)
        Return
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_MAC_Gate_0113)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_04) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_04)))
    IfLt(GB_StoryProgress, STORY_EPILOGUE)
        Return
    EndIf
    Call(GetEntryID, LVar0)
    IfNe(LVar0, mac_00_ENTRY_7)
        Exec(N(EVS_BlockExitToGoomaRoad))
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_05) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_05)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_06) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_06)))
    Return
    End
};

EvtScript N(EVS_NpcInit_FickleLover) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Lovers)))
    Return
    End
};

EvtScript N(EVS_NpcInit_ShamelessLover) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Lovers)))
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_ShamelessLover)))
    Return
    End
};

EvtScript N(EVS_NpcInit_KrisT) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toadette)))
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_KrisT)))
    Return
    End
};

EvtScript N(EVS_NpcInit_MissT) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_MissT)))
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_MissT)))
    Return
    End
};

EvtScript N(EVS_NpcInit_FelissaT) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toadette)))
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_FelissaT)))
    Return
    End
};

EvtScript N(EVS_NpcInit_DojoSpectator) = {
    IfGe(GB_StoryProgress, STORY_EPILOGUE)
        Call(SetNpcPos, NPC_DojoSpectator, 350, 20, -100)
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_08)))
    Return
    End
};

EvtScript N(EVS_NpcInit_DojoFan) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_09)))
    Return
    End
};

NpcData N(NpcData_SharedTownsfolk)[] = {
    {
        .id = NPC_Toad_04,
        .pos = { -150.0f, 0.0f, -275.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toad_04),
        .settings = &N(NpcSettings_Toad_Stationary_Shared),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_MAC_GateGuardian,
    },
    {
        .id = NPC_Toad_05,
        .pos = { 219.0f, 0.0f, -45.0f },
        .yaw = 90,
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
        .init = &N(EVS_NpcInit_Toad_05),
        .settings = &N(NpcSettings_Toad_Wander_Shared),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_MAC_ShopLoiterer,
    },
    {
        .id = NPC_Toad_06,
        .pos = { -290.0f, 0.0f, -120.0f },
        .yaw = 90,
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
        .init = &N(EVS_NpcInit_Toad_06),
        .settings = &N(NpcSettings_Toad_Patrol_Shared),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000,
        .drops = NO_DROPS,
        .animations = TOAD_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_MAC_NewsEnthusiast,
    },
    {
        .id = NPC_FickleLover,
        .pos = { -40.0f, 0.0f, 61.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_FickleLover),
        .settings = &N(NpcSettings_Toad_Stationary_Shared),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_FickleLovers,
    },
    {
        .id = NPC_ShamelessLover,
        .pos = { -15.0f, 0.0f, 60.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShamelessLover),
        .settings = &N(NpcSettings_Toad_Stationary_Shared),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOADETTE_PINK_ANIMS,
        .tattle = MSG_NpcTattle_MAC_ShamelessLover,
    },
    {
        .id = NPC_KrisT,
        .pos = { 426.0f, 20.0f, 268.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_KrisT),
        .settings = &N(NpcSettings_Toad_Stationary_Shared),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000,
        .drops = NO_DROPS,
        .animations = TOADETTE_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_MAC_ThreeSisters_Eldest,
    },
    {
        .id = NPC_MissT,
        .pos = { 381.0f, 20.0f, 326.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_MissT),
        .settings = &N(NpcSettings_Toad_Stationary_Shared),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000,
        .drops = NO_DROPS,
        .animations = TOADETTE_ORANGE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_ThreeSisters_Middle,
    },
    {
        .id = NPC_FelissaT,
        .pos = { 476.0f, 20.0f, 326.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_FelissaT),
        .settings = &N(NpcSettings_Toad_Stationary_Shared),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000,
        .drops = NO_DROPS,
        .animations = TOADETTE_PURPLE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_ThreeSisters_Youngest,
    },
    {
        .id = NPC_DojoSpectator,
        .pos = { 424.0f, 20.0f, -85.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_DojoSpectator),
        .settings = &N(NpcSettings_Toad_Stationary_Shared),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_DojoSpectator,
    },
    {
        .id = NPC_DojoFan,
        .pos = { 373.0f, 0.0f, 22.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_DojoFan),
        .settings = &N(NpcSettings_Toad_Stationary_Shared),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000,
        .drops = NO_DROPS,
        .animations = TOAD_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_MAC_DojoFanToad,
    },
};
