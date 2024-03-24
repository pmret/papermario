#include "iwa_10.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/npc/Parakarry.inc.c"

#include "world/common/util/ChangeNpcToPartner.inc.c"

#include "world/common/complete/KeyItemChoice.inc.c"

EvtScript N(EVS_Scene_MeetParakarry) = {
    Label(0)
    Wait(1)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLt(LVar1, 215)
        Goto(0)
    EndIf
    IfLt(LVar0, -600)
        Goto(0)
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_CH2_000E, 320, 150)
    Thread
        Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
        Call(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, 0, EMOTE_QUESTION, 0, 20, EMOTER_PLAYER, 0, 0, 0, 0)
    EndThread
    Call(AdjustCam, CAM_DEFAULT, Float(3.0 / DT), 30, 300, Float(15.0), Float(-9.5))
    Thread
        Call(SetPlayerAnimation, ANIM_MarioW2_LookAround)
        Wait(20 * DT)
        Call(InterpPlayerYaw, 270, 0)
        Wait(55 * DT)
        Call(InterpPlayerYaw, 90, 0)
    EndThread
    Wait(20 * DT)
    Call(SetNpcPos, NPC_Parakarry, -400, 215, -510)
    Call(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Thread
        Call(SetNpcRotation, NPC_Parakarry, 0, 0, 15)
        Call(InterpNpcYaw, NPC_Parakarry, 270, 0)
        Wait(20 * DT)
        Call(SetNpcRotation, NPC_Parakarry, 0, 0, 0)
        Call(InterpNpcYaw, NPC_Parakarry, 90, 0)
        Wait(5 * DT)
        Call(SetNpcRotation, NPC_Parakarry, 0, 0, -15)
        Wait(30 * DT)
        Call(InterpNpcYaw, NPC_Parakarry, 270, 0)
        Call(SetNpcRotation, NPC_Parakarry, 0, 0, 0)
    EndThread
    Set(MV_ParakarryPosZ, -510)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Thread
        Call(MakeLerp, -510, LVar2, 60 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Set(MV_ParakarryPosZ, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Add(LVar0, 25)
    Call(MakeLerp, -400, LVar0, 55 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcPos, NPC_Parakarry, LVar0, 220, MV_ParakarryPosZ)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetPlayerAnimation, ANIM_Mario1_Hurt)
    Call(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_HurtStill)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(2.0))
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Parakarry, LVar3, LVar4, LVar5)
    Add(LVar0, LVar3)
    Div(LVar0, 2)
    Add(LVar2, LVar5)
    Div(LVar2, 2)
    Call(PlaySoundAt, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT, LVar0, 230, LVar2)
    PlayEffect(EFFECT_DAMAGE_STARS, FX_DAMAGE_STARS_3, LVar0, 230, LVar2, 0, -1, 0, 2)
    Set(LVarA, LVar0)
    Set(LVarB, 230)
    Set(LVarC, LVar2)
    Call(DisablePlayerPhysics, TRUE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfGt(LVar2, -380)
        Set(LVar2, -380)
    EndIf
    Thread
        Call(SetNpcJumpscale, NPC_Parakarry, Float(1.0))
        Call(GetNpcPos, NPC_Parakarry, LVar0, LVar1, LVar3)
        Add(LVar0, 30)
        Call(NpcJump1, NPC_Parakarry, LVar0, 215, LVar2, 15 * DT)
        Add(LVar0, 15)
        Call(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Hurt)
        Call(NpcJump1, NPC_Parakarry, LVar0, 215, LVar2, 8 * DT)
    EndThread
    Call(SetPlayerJumpscale, Float(1.0))
    Sub(LVar0, 30)
    Call(PlayerJump1, LVar0, LVar1, LVar2, 15 * DT)
    Call(SetPlayerPos, LVar0, LVar1, LVar2)
    Call(PlaySoundAt, SOUND_TRIP, SOUND_SPACE_DEFAULT, LVarA, LVarB, LVarC)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
    EndThread
    Sub(LVar0, 15)
    Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
    Call(InterpPlayerYaw, 270, 0)
    Wait(1)
    Call(SetPlayerAnimation, ANIM_Mario1_Fallen)
    Call(PlayerJump1, LVar0, LVar1, LVar2, 8 * DT)
    Call(SetPlayerPos, LVar0, LVar1, LVar2)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(1.0))
    EndThread
    Wait(20 * DT)
    Call(NpcFaceNpc, NPC_PARTNER, NPC_Parakarry, 0)
    Call(SetPlayerAnimation, ANIM_Mario1_GetUp)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Idle)
    Call(GetNpcPos, NPC_Parakarry, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Call(NpcJump1, NPC_Parakarry, LVar0, LVar1, LVar2, 8 * DT)
    Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, FALSE)
    Call(InterpPlayerYaw, 90, 0)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(30 * DT)
    Call(AdjustCam, CAM_DEFAULT, Float(3.0 / DT), 35, 255, Float(17.5), Float(-11.5))
    Call(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Walk)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 60)
    Call(SetNpcSpeed, NPC_Parakarry, Float(3.0))
    Call(NpcMoveTo, NPC_Parakarry, LVar0, LVar2, 0)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Idle)
    Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_000F)
    Wait(10 * DT)
    Call(GetNpcPos, NPC_Parakarry, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_Parakarry, LVar0, LVar1, LVar2, 10)
    Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0010)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0011)
    Set(GB_StoryProgress, STORY_CH2_SPOKE_WITH_PARAKARRY)
    Call(ResetCam, CAM_DEFAULT, Float(3.0 / DT))
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(BindNpcAI, NPC_Parakarry, Ref(N(EVS_NpcIdle_Parakarry)))
    Return
    End
};

s32 N(LetterList)[] = {
    ITEM_LETTER_TO_MERLON,
    ITEM_LETTER_TO_KOLORADO,
    ITEM_LETTER_CHAIN_GOOMPAPA_1,
    ITEM_NONE
};

EvtScript N(EVS_NpcInteract_Parakarry) = {
    Set(LFlag0, FALSE)
    IfEq(GB_IWA10_ReturnedLetterCount, 2)
        Set(LVar0, 0)
        IfEq(GF_IWA01_Item_Letter01, TRUE)
            Add(LVar0, 1)
        EndIf
        IfEq(GF_IWA03_Item_LettertoKolorado, TRUE)
            Add(LVar0, 1)
        EndIf
        IfEq(GF_IWA04_Item_Letter10, TRUE)
            Add(LVar0, 1)
        EndIf
        IfEq(LVar0, 3)
            Call(GetPlayerPos, LVar1, LVar2, LVar3)
            Call(GetNpcPos, NPC_Parakarry, LVar4, LVar5, LVar6)
            IfLt(LVar1, LVar4)
                Add(LVar4, -30)
            Else
                Add(LVar4, 30)
            EndIf
            Call(PlayerMoveTo, LVar4, LVar6, 20 * DT)
            Call(PlayerFaceNpc, NPC_Parakarry, FALSE)
            Wait(10 * DT)
            Call(func_802CF56C, 2)
            Call(AdjustCam, CAM_DEFAULT, Float(4.0 / DT), Float(0.0), Float(300.0), Float(17.5), Float(-10.0))
        EndIf
    EndIf
    Set(LVar0, Ref(N(LetterList)))
    Set(LVar1, 4)
    ExecWait(N(EVS_ChooseKeyItem))
    Switch(LVar0)
        CaseEq(0)
            Switch(GB_IWA10_ReturnedLetterCount)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0012)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0015)
                CaseEq(2)
                    Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0017)
                CaseEq(3)
                    Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_001C)
                    Call(ShowChoice, MSG_Choice_000F)
                    IfNe(LVar0, 0)
                        Call(ContinueSpeech, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_001B)
                        Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
                        Return
                    EndIf
                    Set(LFlag0, TRUE)
            EndSwitch
        CaseEq(-1)
            Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0013)
        CaseDefault
            Call(RemoveKeyItemAt, LVar0)
            Add(GB_IWA10_ReturnedLetterCount, 1)
            Switch(GB_IWA10_ReturnedLetterCount)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0014)
                CaseEq(2)
                    Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0016)
                CaseEq(3)
                    Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Celebrate, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0018)
                    Call(SetPlayerAnimation, ANIM_Mario1_Question)
                    Wait(30 * DT)
                    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
                    Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0019)
                    Call(ShowChoice, MSG_Choice_000F)
                    IfNe(LVar0, 0)
                        Call(ContinueSpeech, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_001A)
                        Call(ShowChoice, MSG_Choice_000F)
                        IfNe(LVar0, 0)
                            Call(ContinueSpeech, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_001B)
                            Call(ResetCam, CAM_DEFAULT, Float(4.0))
                            Return
                        EndIf
                    EndIf
                    Set(LFlag0, TRUE)
            EndSwitch
    EndSwitch
    IfEq(LFlag0, TRUE)
        Call(DisablePartnerAI, 0)
        Call(ContinueSpeech, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_001D)
        Call(N(ChangeNpcToPartner), 4, 4)
        Set(GB_StoryProgress, STORY_CH2_PARAKARRY_JOINED_PARTY)
        Call(N(LoadPartyImage))
        Exec(N(EVS_PushSong))
        Wait(15 * DT)
        Call(ShowMessageAtScreenPos, MSG_Menus_018C, 160, 40)
        Exec(N(EVS_PopSong))
        Wait(10 * DT)
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_001E)
        Call(AddKeyItem, ITEM_LETTER_TO_MERLON)
        Call(AddKeyItem, ITEM_LETTER_TO_KOLORADO)
        Call(AddKeyItem, ITEM_LETTER_CHAIN_GOOMPAPA_1)
    EndIf
    Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
    Call(EnablePartnerAI)
    Return
    Return
    End
};

EvtScript N(EVS_NpcIdle_Parakarry) = {
    Call(SetNpcSpeed, NPC_SELF, Float(1.0))
    Add(LVar0, -670)
    Add(LVar2, -485)
    Loop(0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldParakarry_Walk)
        Call(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldParakarry_Idle)
        Call(InterpNpcYaw, NPC_SELF, 90, 7)
        Wait(10)
        Call(InterpNpcYaw, NPC_SELF, 270, 7)
        Wait(30)
        Add(LVar0, 120)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldParakarry_Walk)
        Call(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldParakarry_Idle)
        Call(InterpNpcYaw, NPC_SELF, 270, 7)
        Wait(10)
        Call(InterpNpcYaw, NPC_SELF, 90, 7)
        Wait(30)
        Add(LVar0, -120)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_Parakarry) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Parakarry)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_SPOKE_WITH_PARAKARRY)
            Call(SetNpcPos, NPC_Parakarry, NPC_DISPOSE_LOCATION)
        CaseLt(STORY_CH2_PARAKARRY_JOINED_PARTY)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Parakarry)))
        CaseDefault
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

NpcData N(NpcData_Parakarry) = {
    .id = NPC_Parakarry,
    .pos = { -610.0f, 230.0f, -485.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Parakarry),
    .settings = &N(NpcSettings_Parakarry),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = PARAKARRY_ANIMS,
    .tattle = MSG_NpcTattle_IWA_Parakarry,
};
