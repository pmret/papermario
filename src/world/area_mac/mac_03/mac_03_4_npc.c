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
    Call(N(LetterDelivery_Init), NPC_ToadKid_01,
        ANIM_ToadKid_Red_Talk, ANIM_ToadKid_Red_Idle,
        ITEM_LETTER_CHAIN_DANE_T_1, ITEM_NONE,
        MSG_MAC_Station_0049, MSG_MAC_Station_004A,
        MSG_MAC_Station_004B, MSG_MAC_Station_004C,
        Ref(N(LetterList_A)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_LetterReward_ToadKid1A) = {
    IfEq(LVarC, DELIVERY_ACCEPTED)
        Call(SpeakToPlayer, NPC_ToadKid_02, ANIM_ToadKid_Yellow_Talk, ANIM_ToadKid_Yellow_Idle, 0, MSG_MAC_Station_004D)
        EVT_GIVE_KEY_REWARD(ITEM_LETTER_CHAIN_YOSHI_KID)
    EndIf
    Return
    End
};

s32 N(LetterList_B)[] = {
    ITEM_LETTER_CHAIN_DANE_T_2,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_ToadKid1B) = {
    Call(N(LetterDelivery_Init), NPC_ToadKid_01,
        ANIM_ToadKid_Red_Talk, ANIM_ToadKid_Red_Idle,
        ITEM_LETTER_CHAIN_DANE_T_2, ITEM_NONE,
        MSG_MAC_Station_004E, MSG_MAC_Station_004F,
        MSG_MAC_Station_0050, MSG_MAC_Station_0051,
        Ref(N(LetterList_B)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_LetterReward_ToadKid1B) = {
    IfEq(LVarC, DELIVERY_ACCEPTED)
        Call(SpeakToPlayer, NPC_ToadKid_02, ANIM_ToadKid_Yellow_Talk, ANIM_ToadKid_Yellow_Idle, 0, MSG_MAC_Station_0052)
        // EVT_GIVE_KEY_REWARD(ITEM_LETTER_CHAIN_FROST_T), but LVar1/LVar0 are set in wrong order
        Set(LVar1, 1)
        Set(LVar0, ITEM_LETTER_CHAIN_FROST_T)
        ExecWait(N(GiveItemReward))
        Call(AddKeyItem, ITEM_LETTER_CHAIN_FROST_T)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_TrainToad_01) = {
    IfEq(GF_MAC03_BombedRock, FALSE)
        Call(SpeakToPlayer, NPC_TrainToad_01, ANIM_TrainToad_White_SadTalk, ANIM_TrainToad_White_SadIdle, 0, MSG_MAC_Station_0000)
        Return
    EndIf
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            IfEq(GF_MAC03_ShyGuyChasedOff, FALSE)
                Call(SpeakToPlayer, NPC_TrainToad_01, ANIM_TrainToad_White_SadTalk, ANIM_TrainToad_White_SadIdle, 0, MSG_MAC_Station_0007)
                Return
            EndIf
    EndSwitch
    Call(GetEntryID, LVar0)
    IfEq(LVar0, mac_03_ENTRY_1)
        Call(SpeakToPlayer, NPC_TrainToad_01, ANIM_TrainToad_White_Talk, ANIM_TrainToad_White_Idle, 0, MSG_MAC_Station_0006)
        Return
    EndIf
    IfEq(GF_MAC03_ShyGuyChasedOff, FALSE)
        IfEq(GF_MAC03_Conductor_ThankYouA, FALSE)
            Set(GF_MAC03_Conductor_ThankYouA, TRUE)
            Set(LVar0, MSG_MAC_Station_0001)
        Else
            Set(LVar0, MSG_MAC_Station_0002)
        EndIf
    Else
        IfEq(GF_MAC03_Conductor_ThankYouB, FALSE)
            Set(GF_MAC03_Conductor_ThankYouB, TRUE)
            Set(LVar0, MSG_MAC_Station_0008)
        Else
            Set(LVar0, MSG_MAC_Station_0002)
        EndIf
    EndIf
    Call(SpeakToPlayer, NPC_TrainToad_01, ANIM_TrainToad_White_Talk, ANIM_TrainToad_White_Idle, 0, LVar0)
    Call(ShowChoice, MSG_Choice_000C)
    IfEq(LVar0, 0)
        Call(ContinueSpeech, NPC_TrainToad_01, ANIM_TrainToad_White_Talk, ANIM_TrainToad_White_Idle, 0, MSG_MAC_Station_0003)
        Exec(N(EVS_DepartForMtRugged))
    Else
        Call(ContinueSpeech, NPC_TrainToad_01, ANIM_TrainToad_White_Talk, ANIM_TrainToad_White_Idle, 0, MSG_MAC_Station_0004)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_TrainToad_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_TrainToad_01)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_01) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Station_000A)
            Else
                Set(LVar0, MSG_MAC_Station_000B)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Station_000C)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_ShyGuyBlockingTracks, FALSE)
                Set(LVar0, MSG_MAC_Station_000D)
            Else
                IfEq(GF_MAC03_ShyGuyChasedOff, FALSE)
                    Set(LVar0, MSG_MAC_Station_000E)
                Else
                    Set(LVar0, MSG_MAC_Station_000F)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Station_0010)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Station_0011)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Station_0012)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Station_0013)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Station_0014)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Station_0015)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Station_0016)
    EndSwitch
    Call(SpeakToPlayer, NPC_Toad_01, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_01)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toadette_01) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Station_0017)
            Else
                Set(LVar0, MSG_MAC_Station_0018)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Station_0019)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_ShyGuyBlockingTracks, FALSE)
                Set(LVar0, MSG_MAC_Station_001A)
            Else
                IfEq(GF_MAC03_ShyGuyChasedOff, FALSE)
                    Set(LVar0, MSG_MAC_Station_001B)
                Else
                    Set(LVar0, MSG_MAC_Station_001C)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Station_001D)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Station_001E)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Station_001F)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Station_0020)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Station_0021)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Station_0022)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Station_0023)
    EndSwitch
    Call(SpeakToPlayer, NPC_Toadette_01, ANIM_Toadette_Purple_Talk, ANIM_Toadette_Purple_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toadette_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toadette_01)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_02) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Station_0024)
            Else
                Set(LVar0, MSG_MAC_Station_0025)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Station_0026)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_ShyGuyBlockingTracks, FALSE)
                Set(LVar0, MSG_MAC_Station_0027)
            Else
                IfEq(GF_MAC03_ShyGuyChasedOff, FALSE)
                    Set(LVar0, MSG_MAC_Station_0028)
                Else
                    Set(LVar0, MSG_MAC_Station_0029)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Station_002A)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Station_002B)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Station_002C)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Station_002D)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Station_002E)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Station_002F)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Station_0030)
    EndSwitch
    Call(SpeakToPlayer, NPC_Toad_02, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_02)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_ToadKid_02) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_FULL)
    Call(EnableNpcAI, NPC_ToadKid_01, FALSE)
    Call(EnableNpcAI, NPC_ToadKid_02, FALSE)
    Call(GetNpcAnimation, NPC_ToadKid_01, LVar2)
    Call(GetNpcAnimation, NPC_ToadKid_02, LVar3)
    Call(SetNpcAnimation, NPC_ToadKid_01, ANIM_ToadKid_Red_Idle)
    Call(SetNpcAnimation, NPC_ToadKid_02, ANIM_ToadKid_Yellow_Idle)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Station_0031)
                Set(LVar1, MSG_MAC_Station_0032)
            Else
                Set(LVar0, MSG_MAC_Station_0033)
                Set(LVar1, MSG_MAC_Station_0034)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Station_0035)
            Set(LVar1, MSG_MAC_Station_0036)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_ShyGuyBlockingTracks, FALSE)
            Else
                IfEq(GF_MAC03_ShyGuyChasedOff, FALSE)
                    Set(LVar0, MSG_MAC_Station_0037)
                    Set(LVar1, MSG_MAC_Station_0038)
                Else
                    Set(LVar0, MSG_MAC_Station_0039)
                    Set(LVar1, MSG_MAC_Station_003A)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Station_003B)
            Set(LVar1, MSG_MAC_Station_003C)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Station_003D)
            Set(LVar1, MSG_MAC_Station_003E)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Station_003F)
            Set(LVar1, MSG_MAC_Station_0040)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Station_0041)
            Set(LVar1, MSG_MAC_Station_0042)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Station_0043)
            Set(LVar1, MSG_MAC_Station_0044)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Station_0045)
            Set(LVar1, MSG_MAC_Station_0046)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Station_0047)
            Set(LVar1, MSG_MAC_Station_0048)
    EndSwitch
    Call(SpeakToPlayer, NPC_ToadKid_01, ANIM_ToadKid_Red_Talk, ANIM_ToadKid_Red_Idle, 0, LVar0)
    Wait(10)
    Call(SpeakToPlayer, NPC_ToadKid_02, ANIM_ToadKid_Yellow_Talk, ANIM_ToadKid_Yellow_Idle, 0, LVar1)
    Call(SetNpcAnimation, NPC_ToadKid_01, LVar2)
    Call(SetNpcAnimation, NPC_ToadKid_02, LVar3)
    Call(EnableNpcAI, NPC_ToadKid_01, TRUE)
    Call(EnableNpcAI, NPC_ToadKid_02, TRUE)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Return
    End
};

EvtScript N(EVS_NpcInteract_ToadKid_01) = {
    ExecWait(N(EVS_NpcInteract_ToadKid_02))
    ExecWait(N(EVS_LetterPrompt_ToadKid1A))
    ExecWait(N(EVS_LetterReward_ToadKid1A))
    IfNe(LVarC, 0)
        Return
    EndIf
    ExecWait(N(EVS_LetterPrompt_ToadKid1B))
    ExecWait(N(EVS_LetterReward_ToadKid1B))
    IfNe(LVarC, 0)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_ToadKid_01) = {
    Call(BindNpcInteract, NPC_ToadKid_01, Ref(N(EVS_NpcInteract_ToadKid_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_ToadKid_02) = {
    Call(BindNpcInteract, NPC_ToadKid_02, Ref(N(EVS_NpcInteract_ToadKid_02)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toadette_02) = {
    IfEq(GF_MAC03_BombedRock, FALSE)
        Set(LVar0, MSG_MAC_Station_0061)
        Set(LVar1, MSG_MAC_Station_0062)
        Set(LVar2, MSG_MAC_Station_0063)
    Else
        Set(LVar0, MSG_MAC_Station_0064)
        Set(LVar1, MSG_MAC_Station_0065)
        Set(LVar2, MSG_MAC_Station_0066)
    EndIf
    Call(SpeakToPlayer, NPC_Toadette_02, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, LVar0)
    Call(SpeakToPlayer, NPC_Toadette_03, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, LVar1)
    Call(SpeakToPlayer, NPC_Toadette_04, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 0, LVar2)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toadette_02) = {
    IfLt(GB_StoryProgress, STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toadette_02)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_03) = {
    IfEq(GB_MAC03_LilOinkCount, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MAC_Station_0053)
        Call(ShowChoice, MSG_Choice_000D)
        IfEq(LVar0, 0)
            Set(LVar0, MSG_MAC_Station_0056)
        Else
            Set(LVar0, MSG_MAC_Station_0055)
        EndIf
        Call(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
        Wait(10)
        Call(InterpNpcYaw, NPC_SELF, 90, 0)
        Set(MF_Unk_08, TRUE)
        Return
    EndIf
    IfEq(MF_Unk_07, FALSE)
        Set(LVar0, MSG_MAC_Station_0054)
    Else
        Call(N(GetOinkCount))
        Switch(LVar0)
            CaseEq(9)
                Set(LVar0, MSG_MAC_Station_0058)
            CaseEq(8)
                Set(LVar0, MSG_MAC_Station_0057)
            CaseEq(0)
                Set(LVar0, MSG_MAC_Station_0059)
            CaseEq(1)
                Set(LVar0, MSG_MAC_Station_005A)
            CaseEq(2)
                Set(LVar0, MSG_MAC_Station_005B)
            CaseEq(3)
                Set(LVar0, MSG_MAC_Station_005C)
            CaseEq(4)
                Set(LVar0, MSG_MAC_Station_005D)
            CaseEq(5)
                Set(LVar0, MSG_MAC_Station_005E)
            CaseEq(6)
                Set(LVar0, MSG_MAC_Station_005F)
            CaseEq(7)
                Set(LVar0, MSG_MAC_Station_0060)
        EndSwitch
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 16, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_03)))
    Return
    End
};

EvtScript N(D_8024A7F4_83BFF4) = {
    Loop(0)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_SHY_GUY_STEP, SOUND_SPACE_DEFAULT)
        Wait(2)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_ShyGuy) = {
    Call(SetNpcPos, NPC_SELF, -100, 0, -25)
    Call(InterpNpcYaw, NPC_SELF, 270, 1)
    Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
    Loop(0)
        Call(NpcMoveTo, NPC_SELF, -250, -25, 30)
        Call(InterpNpcYaw, NPC_SELF, 90, 1)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, -250, 0, 30, 15)
        Call(NpcMoveTo, NPC_SELF, -100, 30, 30)
        Call(InterpNpcYaw, NPC_SELF, 270, 1)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, -100, 0, -25, 15)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcAI_ShyGuy) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim0C)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 10)
    Call(SetNpcSpeed, NPC_SELF, Float(8.0))
    Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    Call(InterpNpcYaw, NPC_SELF, 90, 1)
    ExecGetTID(N(D_8024A7F4_83BFF4), LVarA)
    Call(NpcMoveTo, NPC_SELF, -100, 0, 0)
    KillThread(LVarA)
    Call(ShowSweat, NPC_SELF, 1, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
    Call(DisablePlayerInput, FALSE)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, -30, 0, 0, 20)
    Call(ShowSweat, NPC_SELF, 1, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_SHY_GUY_RUN_AWAY, SOUND_SPACE_DEFAULT)
    ExecGetTID(N(D_8024A7F4_83BFF4), LVarA)
    Call(SetNpcSpeed, NPC_SELF, Float(8.0))
    Call(NpcMoveTo, NPC_SELF, 30, -200, 0)
    Call(ShowSweat, NPC_SELF, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    Call(NpcMoveTo, NPC_SELF, -30, -400, 0)
    Call(ShowSweat, NPC_SELF, 1, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
    Call(NpcMoveTo, NPC_SELF, 30, -600, 0)
    Call(ShowSweat, NPC_SELF, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    Call(NpcMoveTo, NPC_SELF, 0, -650, 0)
    KillThread(LVarA)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Wait(200)
    Return
    End
};

EvtScript N(EVS_NpcHit_ShyGuy) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_HAMMER)
            Set(LVar1, 1)
        CaseEq(ENCOUNTER_TRIGGER_JUMP)
            Set(LVar1, 1)
        CaseEq(ENCOUNTER_TRIGGER_PARTNER)
            Set(LVar1, 1)
        CaseDefault
            Set(LVar1, 0)
    EndSwitch
    IfEq(LVar1, 0)
        Return
    EndIf
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_SHY_GUY_OUCH, SOUND_SPACE_DEFAULT)
    Set(GF_MAC03_ShyGuyChasedOff, TRUE)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_ShyGuy)))
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER, 1)
    Return
    End
};

EvtScript N(EVS_NpcInit_ShyGuy) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            Call(GetEntryID, LVar0)
            IfEq(LVar0, mac_03_ENTRY_1)
                Set(GF_MAC03_ShyGuyBlockingTracks, TRUE)
                Set(GF_MAC03_ShyGuyChasedOff, TRUE)
            EndIf
            IfEq(GF_MAC03_ShyGuyChasedOff, FALSE)
                Set(GF_MAC03_ShyGuyBlockingTracks, TRUE)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_ShyGuy)))
                Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_ShyGuy)))
                Return
            EndIf
    EndSwitch
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Toad_14) = {
    Loop(0)
        Switch(GB_MAC03_LilOinkCapsuleState)
            CaseEq(1)
                Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                Call(TranslateModel, MODEL_capsule, LVar0, LVar1, LVar2)
            CaseEq(2)
                Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                Call(GetNpcYaw, NPC_SELF, LVar3)
                Call(N(func_80241BD8_8333D8), 10, LVar0, LVar1, LVar2, LVar3)
        EndSwitch
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_14) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Toad_14)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_04) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    Call(SetNpcPos, NPC_SELF, 420, 20, -170)
    Return
    End
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
