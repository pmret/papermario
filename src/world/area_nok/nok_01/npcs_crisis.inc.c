#include "sprite/player.h"

EvtScript N(EVS_Scene_RecoverTreeShell) = {
    Wait(1)
    IfEq(GF_NOK01_RecoveredTreeShell, TRUE)
        Return
    EndIf
    Set(GF_NOK01_RecoveredTreeShell, TRUE)
    Call(BindNpcAI, NPC_Koopa_03, Ref(N(EVS_DoNothing)))
    Call(SetNpcAux, NPC_Koopa_03, Ref(N(EVS_DoNothing)))
    Call(DisablePlayerInput, TRUE)
    Wait(5)
    Call(NpcJump0, NPC_KoopaShell_03, 220, 0, 210, 20)
    Call(PlaySoundAtNpc, NPC_KoopaShell_03, SOUND_ITEM_BOUNCE, SOUND_SPACE_DEFAULT)
    Call(PlayerFaceNpc, NPC_KoopaShell_03, FALSE)
    Call(NpcFaceNpc, NPC_Koopa_03, NPC_KoopaShell_03, 0)
    Call(SetNpcFlagBits, NPC_Koopa_03, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Add(LVar0, -1)
    Add(LVar2, -1)
    Call(GetNpcPos, NPC_Koopa_03, LVar0, LVar1, LVar2)
    Call(SetNpcAnimation, NPC_Koopa_03, ANIM_KoopaWithoutShell_Happy)
    Call(NpcJump0, NPC_Koopa_03, LVar0, 0, LVar2, 15)
    Call(GetNpcPos, NPC_KoopaShell_03, LVar0, LVar1, LVar2)
    Add(LVar0, 1)
    Add(LVar2, 1)
    Call(SetNpcAnimation, NPC_Koopa_03, ANIM_KoopaWithoutShell_Run)
    Call(NpcMoveTo, NPC_Koopa_03, LVar0, LVar2, 15)
    Call(SetNpcAnimation, NPC_Koopa_03, ANIM_KoopaWithoutShell_Idle)
    Call(GetNpcPos, NPC_Koopa_03, LVar0, LVar1, LVar2)
    Add(LVar0, 1)
    Add(LVar2, 1)
    Add(LVar1, 10)
    Call(NpcJump0, NPC_KoopaShell_03, LVar0, LVar1, LVar2, 10)
    Call(PlayerFaceNpc, NPC_Koopa_03, FALSE)
    Call(NpcFacePlayer, NPC_Koopa_03, 0)
    Wait(10)
    Call(SetNpcAnimation, NPC_Koopa_03, ANIM_KoopaWithoutShell_Still)
    Call(EnableNpcBlur, NPC_KoopaShell_03, TRUE)
    Call(GetNpcPos, NPC_Koopa_03, LVar0, LVar1, LVar2)
    Add(LVar0, 1)
    Add(LVar2, 1)
    Add(LVar1, 20)
    Set(LVar3, NPC_KoopaShell_03)
    Set(LVar4, NPC_Koopa_03)
    Exec(N(EVS_GetIntoShell))
    Call(InterpNpcYaw, LVar3, 60, 0)
    Call(NpcJump0, NPC_KoopaShell_03, LVar0, LVar1, LVar2, 30)
    Call(SetNpcPos, NPC_KoopaShell_03, NPC_DISPOSE_LOCATION)
    Call(SetNpcSprite, NPC_Koopa_03, ANIM_Koopa_Idle)
    Call(SetNpcFlagBits, NPC_Koopa_03, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcAnimation, NPC_Koopa_03, ANIM_Koopa_Still)
    Wait(4)
    Call(EnableNpcBlur, NPC_KoopaShell_03, TRUE)
    Call(SetNpcAnimation, NPC_Koopa_03, ANIM_Koopa_Happy)
    Wait(30)
    Call(SetNpcAnimation, NPC_Koopa_03, ANIM_Koopa_Idle)
    Call(SpeakToPlayer, NPC_Koopa_03, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_001A)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Koopa_03_Crisis) = {
    IfEq(GF_NOK01_RecoveredTreeShell, TRUE)
        Call(SpeakToPlayer, NPC_Koopa_03, ANIM_Koopa_Talk, ANIM_Koopa_Happy, 0, MSG_CH1_001B)
        Return
    EndIf
    Call(SpeakToPlayer, NPC_Koopa_03, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_0019)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopa_03_Crisis) = {
    IfEq(GF_NOK01_RecoveredTreeShell, TRUE)
        Return
    EndIf
    ExecWait(N(EVS_NpcAI_KoopaWithoutShell_Wander))
    Return
    End
};

EvtScript N(EVS_Scene_RecoverBlockShell) = {
    IfEq(GF_NOK01_RecoveredBlockShell, TRUE)
        Return
    EndIf
    Set(GF_NOK01_RecoveredBlockShell, TRUE)
    Call(BindNpcAI, NPC_Koopa_02, Ref(N(EVS_DoNothing)))
    Call(SetNpcAux, NPC_Koopa_02, Ref(N(EVS_DoNothing)))
    Call(DisablePlayerInput, TRUE)
    Call(NpcJump0, NPC_KoopaShell_02, 60, 0, 328, 20)
    Call(PlaySound, SOUND_ITEM_BOUNCE)
    Call(PlayerFaceNpc, NPC_KoopaShell_02, FALSE)
    Call(NpcFaceNpc, NPC_Koopa_02, NPC_KoopaShell_02, 0)
    Call(SetNpcFlagBits, NPC_Koopa_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Add(LVar0, -1)
    Add(LVar2, -1)
    Call(GetNpcPos, NPC_Koopa_02, LVar0, LVar1, LVar2)
    Call(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_Happy)
    Call(NpcJump0, NPC_Koopa_02, LVar0, 0, LVar2, 15)
    Call(GetNpcPos, NPC_KoopaShell_02, LVar0, LVar1, LVar2)
    Add(LVar0, 1)
    Add(LVar2, 1)
    Call(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_Run)
    Call(NpcMoveTo, NPC_Koopa_02, LVar0, LVar2, 15)
    Call(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_Idle)
    Call(GetNpcPos, NPC_Koopa_02, LVar0, LVar1, LVar2)
    Add(LVar0, 1)
    Add(LVar2, 1)
    Add(LVar1, 10)
    Call(NpcJump0, NPC_KoopaShell_02, LVar0, LVar1, LVar2, 10)
    Call(PlayerFaceNpc, NPC_Koopa_02, FALSE)
    Call(NpcFacePlayer, NPC_Koopa_02, 0)
    Wait(10)
    Call(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_Still)
    Call(EnableNpcBlur, NPC_KoopaShell_02, TRUE)
    Call(GetNpcPos, NPC_Koopa_02, LVar0, LVar1, LVar2)
    Add(LVar0, 1)
    Add(LVar2, 1)
    Add(LVar1, 20)
    Set(LVar3, NPC_KoopaShell_02)
    Set(LVar4, NPC_Koopa_02)
    Exec(N(EVS_GetIntoShell))
    Call(InterpNpcYaw, LVar3, 60, 0)
    Call(NpcJump0, NPC_KoopaShell_02, LVar0, LVar1, LVar2, 30)
    Call(SetNpcPos, NPC_KoopaShell_02, NPC_DISPOSE_LOCATION)
    Call(SetNpcSprite, NPC_Koopa_02, ANIM_Koopa_Idle)
    Call(SetNpcFlagBits, NPC_Koopa_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcAnimation, NPC_Koopa_02, ANIM_Koopa_Still)
    Wait(4)
    Call(EnableNpcBlur, NPC_KoopaShell_02, TRUE)
    Call(SetNpcAnimation, NPC_Koopa_02, ANIM_Koopa_Happy)
    Wait(30)
    Call(SetNpcAnimation, NPC_Koopa_02, ANIM_Koopa_Idle)
    Call(SpeakToPlayer, NPC_Koopa_02, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0012)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_BreakBlock_DropShell) = {
    Exec(N(EVS_Scene_RecoverBlockShell))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Koopa_02_Crisis) = {
    IfEq(GF_NOK01_RecoveredBlockShell, TRUE)
        Call(SpeakToPlayer, NPC_Koopa_02, ANIM_Koopa_Idle, ANIM_Koopa_Happy, 0, MSG_CH1_0013)
        Return
    EndIf
    Call(SpeakToPlayer, NPC_Koopa_02, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_0011)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopa_02_Crisis) = {
    IfEq(GF_NOK01_RecoveredBlockShell, TRUE)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_Scene_KooverGetsMugged) = {
    Call(GetNpcPos, NPC_Koover, LVar0, LVar1, LVar2)
    Add(LVar0, 1)
    Add(LVar2, 1)
    Add(LVar1, 200)
    Call(SetNpcPos, NPC_FuzzyWithShell, LVar0, LVar1, LVar2)
    Add(LVar1, -200)
    Call(NpcJump0, NPC_FuzzyWithShell, LVar0, LVar1, LVar2, 20)
    PlayEffect(EFFECT_DAMAGE_STARS, FX_DAMAGE_STARS_3, LVar0, LVar1, LVar2, 0, -1, 0, 3)
    Thread
        Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
        Call(SetCamSpeed, CAM_DEFAULT, 4)
        Wait(60)
        Call(SetCamSpeed, CAM_DEFAULT, 1)
    EndThread
    Thread
        Call(SetPlayerAnimation, ANIM_MarioW2_Shocked)
        Wait(30)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    EndThread
    Call(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
    Call(SetNpcSprite, NPC_Koover, ANIM_KoopaWithoutShell_Idle)
    Call(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_Toppled)
    Call(GetNpcPos, NPC_Koover, LVar0, LVar1, LVar2)
    Add(LVar0, -20)
    Add(LVar2, -10)
    Call(NpcJump0, NPC_Koover, LVar0, LVar1, LVar2, 15)
    Call(GetNpcPos, NPC_FuzzyWithShell, LVar0, LVar1, LVar2)
    Add(LVar0, 1)
    Add(LVar2, 1)
    Call(SetNpcPos, NPC_KooversShell, LVar0, LVar1, LVar2)
    Add(LVar0, -1)
    Add(LVar2, -1)
    Wait(10)
    Add(LVar0, 50)
    Add(LVar2, -20)
    Thread
        Add(LVar0, 1)
        Add(LVar2, 1)
        Call(NpcJump0, NPC_KooversShell, LVar0, 0, LVar2, 20)
    EndThread
    Wait(1)
    Call(SetNpcAnimation, NPC_FuzzyWithShell, ANIM_Fuzzy_Idle)
    Call(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 20)
    Call(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_Idle)
    Call(SetNpcAnimation, NPC_FuzzyWithShell, ANIM_Fuzzy_Anim0C)
    Thread
        Add(LVar0, 1)
        Add(LVar2, 1)
        Call(NpcJump0, NPC_KooversShell, LVar0, 0, LVar2, 20)
    EndThread
    Wait(1)
    Call(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 20)
    Call(NpcFaceNpc, NPC_Koover, NPC_FuzzyWithShell, 0)
    Call(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_CryIdle)
    Thread
        Add(LVar0, 1)
        Add(LVar2, 1)
        Call(NpcJump0, NPC_KooversShell, LVar0, 0, LVar2, 20)
    EndThread
    Wait(1)
    Call(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 20)
    Call(SetNpcAnimation, NPC_FuzzyWithShell, ANIM_Fuzzy_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Koover_Crisis) = {
    IfEq(GF_NOK01_RecoveredShellA, TRUE)
        Call(SpeakToPlayer, NPC_Koover, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0003)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
        Return
    EndIf
    Call(SpeakToPlayer, NPC_Koover, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0000)
    Call(InterpPlayerYaw, 227, 5)
    Call(SetPlayerAnimation, ANIM_Mario1_Thinking)
    Call(EndSpeech, NPC_Koover, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0)
    Call(InterpPlayerYaw, 47, 5)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(EndSpeech, NPC_Koover, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0)
    Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
    Wait(15)
    Call(EndSpeech, NPC_Koover, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0)
    ExecWait(N(EVS_Scene_KooverGetsMugged))
    Call(SpeakToNpc, NPC_Koover, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, NPC_FuzzyWithShell, MSG_CH1_0001)
    Set(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koover_Crisis) = {
    IfEq(GF_NOK01_RecoveredShellA, TRUE)
        Call(SetNpcPos, NPC_FuzzyWithShell, NPC_DISPOSE_LOCATION)
        Return
    EndIf
    IfLt(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
        Call(DisablePlayerInput, TRUE)
        Call(SetPlayerPos, -386, 0, 399)
        Call(PlayerMoveTo, -308, 326, 30)
        Call(DisablePlayerPhysics, TRUE)
        Call(NpcFacePlayer, NPC_Koover, 5)
        Wait(5)
        Call(GetNpcPos, NPC_Koover, LVar0, LVar1, LVar2)
        Sub(LVar0, 5)
        Add(LVar1, 35)
        Call(PlaySoundAtNpc, NPC_Koover, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, NPC_Koover, EMOTE_EXCLAMATION, 0, 20, EMOTER_POS, LVar0, LVar1, LVar2, 0)
        Wait(20)
        Call(SetNpcAnimation, NPC_Koover, ANIM_Koopa_Run)
        Call(GetPlayerPos, LVarA, LVarB, LVarC)
        Call(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
        Call(SetPanTarget, CAM_DEFAULT, LVarA, LVarB, LVarC)
        Call(GetCamDistance, CAM_DEFAULT, LVarA)
        MulF(LVarA, Float(0.7))
        Call(SetCamDistance, CAM_DEFAULT, LVarA)
        Call(SetCamSpeed, CAM_DEFAULT, 4)
        Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
        Call(NpcMoveTo, NPC_Koover, -280, 301, 30)
        Call(SetNpcAnimation, NPC_Koover, ANIM_Koopa_Idle)
        Wait(7)
        ExecWait(N(EVS_NpcInteract_Koover_Crisis))
        Call(DisablePlayerPhysics, FALSE)
        Call(DisablePlayerInput, FALSE)
    Else
        Wait(5)
        Call(GetNpcPos, NPC_FuzzyWithShell, LVar0, LVar1, LVar2)
        Sub(LVar0, 40)
        Call(SetNpcPos, NPC_Koover, LVar0, LVar1, LVar2)
    EndIf
    Call(BindNpcInteract, NPC_Koover, 0)
    Call(SetNpcFlagBits, NPC_Koover, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Set(LVar0, 0)
    Label(0)
        IfEq(GF_NOK01_RecoveredShellA, TRUE)
            Call(BindNpcInteract, NPC_Koover, Ref(N(EVS_NpcInteract_Koover_Crisis)))
            Call(SetNpcFlagBits, NPC_Koover, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            Return
        EndIf
        Call(GetNpcPos, NPC_FuzzyWithShell, LVar0, LVar1, LVar2)
        Call(NpcFaceNpc, NPC_Koover, NPC_FuzzyWithShell, 0)
        Call(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_CryRun)
        Call(NpcMoveTo, NPC_Koover, LVar0, LVar2, 17)
        Call(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_CryIdle)
        Label(1)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcIdle_FuzzyWithShell) = {
    SetGroup(EVT_GROUP_0A)
    IfEq(GF_NOK01_RecoveredShellA, TRUE)
        Call(SetNpcPos, NPC_FuzzyWithShell, NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_KooversShell, NPC_DISPOSE_LOCATION)
        Return
    EndIf
    Set(LVarA, -208)
    Set(LVarB, 0)
    Set(LVarC, 282)
    Label(10)
        IfLt(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
            Call(GetNpcPos, NPC_FuzzyWithShell, LVarA, LVarB, LVarC)
            Add(LVarA, 20)
            Wait(1)
            Goto(10)
        EndIf
    Set(LVar0, 162)
    Label(0)
        IfEq(GF_NOK01_RecoveredShellA, TRUE)
            Call(SetNpcPos, NPC_FuzzyWithShell, NPC_DISPOSE_LOCATION)
            Return
        EndIf
        Call(N(CosInterpMinMax), LVar0, LVar1, -50, 50, 120, 0, 180)
        Call(N(CosInterpMinMax), LVar0, LVar2, -32, 32, 120, 0, 30)
        Add(LVar1, LVarA)
        Add(LVar2, LVarC)
        Call(SetNpcAnimation, NPC_FuzzyWithShell, ANIM_Fuzzy_Run)
        Call(SetNpcPos, NPC_FuzzyWithShell, LVar1, LVarB, LVar2)
        Set(LVar3, LVarB)
        Add(LVar3, 2)
        Add(LVar0, 2)
        Add(LVar2, 1)
        IfEq(LVar0, 240)
            Set(LVar0, 0)
        EndIf
        Call(SetNpcPos, NPC_KooversShell, LVar1, LVar3, LVar2)
        Label(1)
        Wait(1)
    Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcHit_FuzzyWithShell) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Set(LVar1, 0)
    IfEq(LVar0, ENCOUNTER_TRIGGER_HAMMER)
        Add(LVar1, 1)
    EndIf
    IfEq(LVar0, ENCOUNTER_TRIGGER_JUMP)
        Add(LVar1, 1)
    EndIf
    IfNe(LVar1, 0)
        Call(DisablePlayerInput, TRUE)
        Set(GF_NOK01_RecoveredShellA, TRUE)
        Call(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, 1)
        Thread
            Call(GetNpcPos, NPC_KooversShell, LVar0, LVar1, LVar2)
            Call(SetNpcAnimation, NPC_FuzzyWithShell, ANIM_Fuzzy_Hurt)
            Call(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 25)
            Add(LVar0, 40)
            Add(LVar2, -40)
            Call(SetNpcAnimation, NPC_FuzzyWithShell, ANIM_Fuzzy_Hurt)
            Call(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 15)
            Add(LVar0, 30)
            Add(LVar2, -30)
            Call(SetNpcAnimation, NPC_FuzzyWithShell, ANIM_Fuzzy_Anim09)
            Call(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 13)
            Add(LVar0, 20)
            Add(LVar2, -20)
            Call(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 11)
            Add(LVar0, 10)
            Add(LVar2, -10)
            Call(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 9)
            Add(LVar0, 80)
            Add(LVar2, -80)
            Call(SetNpcAnimation, NPC_FuzzyWithShell, ANIM_Fuzzy_Run)
            Call(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 15)
            Call(SetNpcPos, NPC_FuzzyWithShell, NPC_DISPOSE_LOCATION)
        EndThread
        Call(GetNpcPos, NPC_KooversShell, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_KooversShell, LVar0, 0, LVar2, 15)
        Loop(70)
            Call(PlayerFaceNpc, NPC_FuzzyWithShell, FALSE)
            Call(NpcFaceNpc, NPC_Koover, NPC_FuzzyWithShell, 0)
            Wait(1)
        EndLoop
        Call(PlayerFaceNpc, NPC_KooversShell, FALSE)
        Call(NpcFaceNpc, NPC_Koover, NPC_KooversShell, 0)
        Thread
            Call(AdjustCam, CAM_DEFAULT, 4, 0, Float(-300.0), Float(17.0), Float(-7.0))
        EndThread
        Call(SetNpcFlagBits, NPC_Koover, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(GetNpcPos, NPC_Koover, LVar0, LVar1, LVar2)
        Call(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_Happy)
        Call(NpcJump0, NPC_Koover, LVar0, 0, LVar2, 15)
        Call(GetNpcPos, NPC_KooversShell, LVar0, LVar1, LVar2)
        Add(LVar0, 1)
        Add(LVar2, 1)
        Call(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_Run)
        Call(NpcMoveTo, NPC_Koover, LVar0, LVar2, 15)
        Call(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_Idle)
        Call(GetNpcPos, NPC_Koover, LVar0, LVar1, LVar2)
        Add(LVar0, 1)
        Add(LVar2, 1)
        Add(LVar1, 10)
        Call(NpcJump0, NPC_KooversShell, LVar0, LVar1, LVar2, 10)
        Call(PlayerFaceNpc, NPC_Koover, FALSE)
        Call(NpcFacePlayer, NPC_Koover, 0)
        Wait(10)
        Call(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_Still)
        Call(EnableNpcBlur, NPC_KooversShell, TRUE)
        Call(GetNpcPos, NPC_Koover, LVar0, LVar1, LVar2)
        Add(LVar0, 1)
        Add(LVar2, 1)
        Add(LVar1, 20)
        Set(LVar3, NPC_KooversShell)
        Set(LVar4, NPC_Koover)
        Exec(N(EVS_GetIntoShell))
        Call(InterpNpcYaw, LVar3, 60, 0)
        Call(NpcJump0, NPC_KooversShell, LVar0, LVar1, LVar2, 30)
        Call(SetNpcPos, NPC_KooversShell, NPC_DISPOSE_LOCATION)
        Call(SetNpcSprite, NPC_Koover, ANIM_Koopa_Idle)
        Call(SetNpcFlagBits, NPC_Koover, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        Call(SetNpcAnimation, NPC_Koover, ANIM_Koopa_Still)
        Wait(4)
        Call(EnableNpcBlur, NPC_KooversShell, TRUE)
        Call(SetNpcAnimation, NPC_Koover, ANIM_Koopa_Idle)
        Call(SetNpcAnimation, NPC_Koover, ANIM_Koopa_Happy)
        Wait(30)
        Call(SetNpcAnimation, NPC_Koover, ANIM_Koopa_Idle)
        Call(SpeakToPlayer, NPC_Koover, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0002)
        Thread
            Call(ResetCam, CAM_DEFAULT, 4)
        EndThread
        Call(DisablePlayerInput, FALSE)
        Call(SetEnemyFlagBits, NPC_Koover, ENEMY_FLAG_400000, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bobomb_01_Crisis) = {
    IfEq(AF_NOK01_Dialogue_Bobomb_01_Crisis, FALSE)
        Set(AF_NOK01_Dialogue_Bobomb_01_Crisis, TRUE)
        Set(LVar0, MSG_CH1_003D)
    Else
        Set(AF_NOK01_Dialogue_Bobomb_01_Crisis, FALSE)
        Set(LVar0, MSG_CH1_003E)
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bobomb_01_Crisis) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bobomb_01_Crisis)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bobomb_02_Crisis) = {
    IfEq(AF_NOK01_Dialogue_Bobomb_02, FALSE)
        Set(AF_NOK01_Dialogue_Bobomb_02, TRUE)
        Set(LVar0, MSG_CH1_0044)
    Else
        Set(AF_NOK01_Dialogue_Bobomb_02, FALSE)
        Set(LVar0, MSG_CH1_0045)
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bobomb_02_Crisis) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bobomb_02_Crisis)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Koover_Crisis) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koover_Crisis)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koover_Crisis)))
    IfEq(GF_NOK01_RecoveredShellA, TRUE)
        Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_400000, 0)
        Return
    EndIf
    IfGe(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
        Call(SetNpcSprite, NPC_SELF, ANIM_KoopaWithoutShell_Idle)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_FuzzyWithShell) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_FuzzyWithShell)))
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_FuzzyWithShell)))
    Return
    End
};

EvtScript N(EVS_NpcInit_MiscFuzzy1) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_MiscFuzzy1)))
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_MiscFuzzy1)))
    Return
    End
};

EvtScript N(EVS_NpcInit_MiscFuzzy2) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_MiscFuzzy2)))
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_MiscFuzzy2)))
    Return
    End
};

EvtScript N(EVS_NpcInit_KooversShell) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Shell)
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopa_02_Crisis) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopa_02_Crisis)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopa_02_Crisis)))
    Call(SetNpcPos, NPC_Koopa_02, 40, 0, 325)
    Call(InterpNpcYaw, NPC_Koopa_02, 180, 0)
    IfEq(GF_NOK01_RecoveredBlockShell, FALSE)
        Call(SetNpcPos, NPC_KoopaShell_02, 22, 85, 375)
        Call(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_CryRun)
        Return
    EndIf
    Call(SetNpcSprite, NPC_Koopa_02, ANIM_Koopa_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopaShell_02) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Shell)
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopa_03_Crisis) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopa_03_Crisis)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopa_03_Crisis)))
    IfEq(GF_NOK01_RecoveredTreeShell, FALSE)
        Call(SetNpcPos, NPC_KoopaShell_03, 190, 114, 220)
        Return
    EndIf
    Call(SetNpcSprite, NPC_Koopa_03, ANIM_Koopa_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopaShell_03) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Shell)
    Return
    End
};
