#include "omo_12.h"
#include "sprite/player.h"

#include "world/common/npc/BigLanternGhost.inc.c"

NpcSettings N(NpcSettings_Watt) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_SHY_GUY,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

#include "world/common/util/ChangeNpcToPartner.inc.c"

#include "world/common/atomic/CreateDarkness.inc.c"

#include "world/common/DisableCameraLeadingPlayer.inc.c"
#include "world/common/EnableCameraLeadingPlayer.inc.c"

API_CALLABLE(N(SetLightOriginAndPower)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 alpha = evt_get_variable(script, *args++);

    set_screen_overlay_center_worldpos(SCREEN_LAYER_BACK, 1, x, y, z);
    set_screen_overlay_alpha(SCREEN_LAYER_BACK, alpha);
    set_screen_overlay_params_back(OVERLAY_WORLD_DARKNESS, 255.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetLightOff)) {
    set_screen_overlay_alpha(SCREEN_LAYER_BACK, 0.0f);
    set_screen_overlay_params_back(OVERLAY_WORLD_DARKNESS, 0.0f);
    return ApiStatus_DONE2;
}

MAP_STATIC_PAD(1, unk);

enum {
    LIGHT_FROM_DEFAULT      = 0,
    LIGHT_FROM_GHOST        = 1,
    LIGHT_FROM_WATT         = 2,
    LIGHT_FROM_LANTERN      = 3,
    LIGHT_FROM_FLICK_OFF    = 4,
    LIGHT_FROM_HIDDEN       = 5,
    LIGHT_FROM_NO_CHANGE    = 6,
};

EvtScript N(EVS_ManageLanternLight) = {
    SetGroup(EVT_GROUP_00)
    Label(0)
        Switch(AB_OMO12_LightSource)
            CaseEq(LIGHT_FROM_DEFAULT)
            CaseEq(LIGHT_FROM_GHOST)
                Call(GetNpcPos, NPC_BigLanternGhost, LVar0, LVar1, LVar2)
                Set(LVar3, AB_OMO12_LightPowerMod)
                Add(LVar3, 128)
                Call(N(SetLightOriginAndPower), LVar0, LVar1, LVar2, LVar3)
            CaseEq(LIGHT_FROM_WATT)
                Call(GetNpcPos, NPC_Watt, LVar0, LVar1, LVar2)
                Set(LVar3, AB_OMO12_LightPowerMod)
                Add(LVar3, 128)
                Call(N(SetLightOriginAndPower), LVar0, LVar1, LVar2, LVar3)
            CaseEq(LIGHT_FROM_LANTERN)
                Call(GetNpcPos, NPC_LaternTop, LVar0, LVar1, LVar2)
                Set(LVar3, AB_OMO12_LightPowerMod)
                Add(LVar3, 128)
                Call(N(SetLightOriginAndPower), LVar0, LVar1, LVar2, LVar3)
            CaseEq(LIGHT_FROM_FLICK_OFF)
                Call(N(SetLightOff))
                Set(AB_OMO12_LightSource, LIGHT_FROM_DEFAULT)
            CaseEq(LIGHT_FROM_HIDDEN)
                Set(LVar3, AB_OMO12_LightPowerMod)
                Add(LVar3, 128)
                Call(N(SetLightOriginAndPower), NPC_DISPOSE_LOCATION, LVar3)
                Set(AB_OMO12_LightSource, LIGHT_FROM_DEFAULT)
            CaseEq(LIGHT_FROM_NO_CHANGE)
                Return
        EndSwitch
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_SetupLightSource) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH4_DEFEATED_LANTERN_GHOST)
            Set(AB_OMO12_LightSource, LIGHT_FROM_HIDDEN)
            Set(AB_OMO12_LightPowerMod, 127)
            Exec(N(EVS_ManageLanternLight))
        CaseLt(STORY_CH4_WATT_JOINED_PARTY)
            Set(AB_OMO12_LightSource, LIGHT_FROM_LANTERN)
            Set(AB_OMO12_LightPowerMod, 102)
            Exec(N(EVS_ManageLanternLight))
        CaseGe(STORY_CH4_WATT_JOINED_PARTY)
            ExecWait(N(EVS_CreateDarkness))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_EnterScene) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetPlayerPos, 70, 20, 0)
    Call(ShowMessageAtScreenPos, MSG_CH4_004E, 160, 40)
    Call(SetNpcPos, NPC_BigLanternGhost, -150, 0, 20)
    Call(UseSettingsFrom, CAM_DEFAULT, -150, 0, 20)
    Call(SetPanTarget, CAM_DEFAULT, -150, 0, 20)
    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(20 * DT)
    Call(GetNpcPos, NPC_BigLanternGhost, LVar2, LVar3, LVar4)
    Add(LVar2, 32)
    Add(LVar3, 10)
    // turn on lantern light
    Call(MakeLerp, 255, 100, 60 * DT, EASING_LINEAR)
    Label(0)
        Call(UpdateLerp)
        Call(N(SetLightOriginAndPower), LVar2, LVar3, LVar4, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(SpeakToPlayer, NPC_BigLanternGhost, ANIM_BigLanternGhost_Anim05, ANIM_BigLanternGhost_Anim01, 0, MSG_CH4_004F)
    Call(SetPanTarget, CAM_DEFAULT, 50, 0, 20)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.7 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Set(AB_OMO12_LightSource, LIGHT_FROM_GHOST)
    Set(AB_OMO12_LightPowerMod, -28)
    Call(SetNpcAnimation, NPC_BigLanternGhost, ANIM_BigLanternGhost_Anim06)
    Call(SetNpcSpeed, NPC_BigLanternGhost, Float(3.0 / DT))
    Call(NpcMoveTo, NPC_BigLanternGhost, 0, 20, 0)
    Call(SetNpcAnimation, NPC_BigLanternGhost, ANIM_BigLanternGhost_Anim01)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_BigLanternGhost, ANIM_BigLanternGhost_Anim05, ANIM_BigLanternGhost_Anim01, 0, MSG_CH4_0050)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(0.5))
    EndThread
    Call(SetNpcAnimation, NPC_BigLanternGhost, ANIM_BigLanternGhost_Anim0F)
    Wait(5 * DT)
    Call(SetPlayerAnimation, ANIM_MarioW2_Shocked)
    Wait(15 * DT)
    Thread
        Wait(20 * DT)
        Set(AB_OMO12_LightSource, LIGHT_FROM_FLICK_OFF)
    EndThread
    Call(SetNpcVar, NPC_BigLanternGhost, 0, 1)
    Return
    End
};

EvtScript N(EVS_UseWattTutorial) = {
    Loop(0)
        Call(GetPartnerInUse, LVar0)
        IfEq(LVar0, PARTNER_WATT)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldWatt_Celebrate, ANIM_WorldWatt_Idle, 5, MSG_CH4_005C)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

Vec3f N(WattRightFlightPath)[] = {
    {    0.0,     0.0,    0.0 },
    {   25.0,    -5.0,    0.0 },
    {   60.0,    30.0,    0.0 },
};

Vec3f N(WattLeftFlightPath)[] = {
    {    0.0,     0.0,    0.0 },
    {  -25.0,    -5.0,    0.0 },
    {  -60.0,    30.0,    0.0 },
};

BombTrigger N(BombPos_Lantern_Unused) = {
    .pos = { 0.0f, 0.0f, 20.0f },
    .radius = 0.0f
};

EvtScript N(EVS_Scene_ReleaseWatt) = {
    Call(DisablePlayerInput, TRUE)
    Call(N(DisableCameraLeadingPlayer))
    Call(GetNpcPos, NPC_LaternTop, LVar0, LVar1, LVar2)
    Call(SetCamProperties, CAM_DEFAULT, Float(2.0 / DT), LVar0, LVar1, LVar2, Float(450.0), Float(15.0), Float(-6.0))
    Set(LVarA, 0)
    Call(GetOwnerEncounterTrigger, LVar0)
    IfEq(LVar0, ENCOUNTER_TRIGGER_PARTNER)
        Call(GetCurrentPartnerID, LVar0)
        IfEq(LVar0, PARTNER_BOMBETTE)
            Call(SetNpcAnimation, NPC_Watt, ANIM_WorldWatt_Hurt)
            Set(LVarA, -1)
        EndIf
    EndIf
    Call(NpcFacePlayer, NPC_Watt, 0)
    IfEq(LVarA, 0)
        Call(GetOwnerEncounterTrigger, LVar0)
        Switch(LVar0)
            CaseEq(ENCOUNTER_TRIGGER_HAMMER)
            CaseEq(ENCOUNTER_TRIGGER_PARTNER)
            CaseDefault
                Call(GetEncounterTriggerHitTier, LVar0)
                IfEq(LVar0, 0)
                    Wait(25 * DT)
                    Call(DisablePlayerInput, FALSE)
                    Return
                EndIf
        EndSwitch
    EndIf
    Call(PlaySound, SOUND_OMO_LANTERN_BREAK)
    Set(AF_OMO_10, FALSE)
    Loop(8)
        Call(SetNpcFlagBits, NPC_LaternTop, NPC_FLAG_INVISIBLE, TRUE)
        Wait(3)
        Call(SetNpcFlagBits, NPC_LaternTop, NPC_FLAG_INVISIBLE, FALSE)
        Wait(3)
    EndLoop
    Call(SetNpcAnimation, NPC_LaternTop, ANIM_BigLanternGhost_Anim03)
    Call(SetNpcAnimation, NPC_LaternBottom, ANIM_BigLanternGhost_Anim04)
    Thread
        Label(10)
            Call(SetNpcFlagBits, NPC_LaternTop, NPC_FLAG_INVISIBLE, TRUE)
            Call(SetNpcFlagBits, NPC_LaternBottom, NPC_FLAG_INVISIBLE, TRUE)
            Wait(2)
            Call(SetNpcFlagBits, NPC_LaternTop, NPC_FLAG_INVISIBLE, FALSE)
            Call(SetNpcFlagBits, NPC_LaternBottom, NPC_FLAG_INVISIBLE, FALSE)
            Wait(2)
            IfEq(AF_OMO_10, FALSE)
                Goto(10)
            EndIf
    EndThread
    Call(GetAngleToPlayer, NPC_LaternTop, LVar0)
    IfLt(LVar0, 180)
        Set(LVar1, 27)
        Set(LVar2, 50)
    Else
        Set(LVar1, -27)
        Set(LVar2, -50)
    EndIf
    Call(func_802D2C14, 1)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetPlayerSpeed, Float(3.0 / DT))
    Call(PlayerMoveTo, LVar1, 0, 0)
    Call(PlayerFaceNpc, NPC_LaternTop, 3)
    Thread
        Call(SetNpcJumpscale, NPC_LaternTop, 0)
        Call(GetNpcPos, NPC_LaternTop, LVar0, 20, LVar2)
        Call(NpcJump0, NPC_LaternTop, LVar0, 20, LVar2, 20 * DT)
    EndThread
    Thread
        Wait(6 * DT)
        Call(GetNpcPos, NPC_LaternTop, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_Watt, LVar0, 6, LVar2)
        Loop(7)
            Call(SetNpcFlagBits, NPC_LaternTop, NPC_FLAG_INVISIBLE, TRUE)
            Wait(1)
            Call(SetNpcFlagBits, NPC_LaternTop, NPC_FLAG_INVISIBLE, FALSE)
            Wait(1)
        EndLoop
    EndThread
    Wait(10 * DT)
    Set(AB_OMO12_LightSource, LIGHT_FROM_WATT)
    Set(AB_OMO12_LightPowerMod, 72)
    Wait(40 * DT)
    Set(AF_OMO_10, TRUE)
    Call(SetNpcPos, NPC_LaternTop, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_LaternBottom, NPC_DISPOSE_LOCATION)
    Wait(25)
    Call(GetPlayerPos, LVar3, LVar1, LVar2)
    Call(GetNpcPos, NPC_Watt, LVar0, LVar1, LVar2)
    Add(LVar0, LVar3)
    Div(LVar0, 2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-8.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    IfEq(LVarA, -1)
        Call(SpeakToPlayer, NPC_Watt, ANIM_WorldWatt_Strain, ANIM_WorldWatt_Hurt, 0, MSG_CH4_0058)
        Thread
            Wait(10 * DT)
            Call(SetPlayerAnimation, ANIM_Mario1_Pray)
            Wait(15 * DT)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        EndThread
        Call(EndSpeech, NPC_Watt, ANIM_WorldWatt_Strain, ANIM_WorldWatt_Hurt, 0)
    Else
        Call(SpeakToPlayer, NPC_Watt, ANIM_WorldWatt_Celebrate, ANIM_WorldWatt_Idle, 0, MSG_CH4_0057)
        Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
    EndIf
    Call(func_802D2C14, 0)
    Wait(20 * DT)
    Call(SetNpcAnimation, NPC_Watt, ANIM_WorldWatt_Idle)
    Call(PlaySoundAtNpc, NPC_Watt, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Watt, EMOTE_EXCLAMATION, 0, 30, EMOTER_NPC, 0, 0, 0, 0)
    Wait(40 * DT)
    Call(SpeakToPlayer, NPC_Watt, ANIM_WorldWatt_Talk, ANIM_WorldWatt_Idle, 0, MSG_CH4_0059)
    Call(SetPlayerAnimation, ANIM_MarioW2_TouchNose)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
    Wait(20 * DT)
    Call(EndSpeech, NPC_Watt, ANIM_WorldWatt_Talk, ANIM_WorldWatt_Idle, 0)
    Wait(20 * DT)
    Call(GetAngleToPlayer, NPC_Watt, LVar0)
    IfLt(LVar0, 180)
        Set(LVar1, -25)
    Else
        Set(LVar1, 25)
    EndIf
    Call(GetPlayerPos, LVar2, LVar3, LVar4)
    Thread
        Call(DisablePartnerAI, 0)
        Add(LVar1, LVar2)
        Call(SetNpcSpeed, NPC_PARTNER, Float(3.0 / DT))
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        Call(NpcMoveTo, NPC_PARTNER, LVar1, LVar4, 0)
        Call(NpcFacePlayer, NPC_PARTNER, 3)
        Call(EnablePartnerAI)
    EndThread
    Call(SetNpcFlagBits, NPC_Watt, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(GetNpcPos, NPC_Watt, LVar7, LVar8, LVar9)
    Call(GetAngleToPlayer, NPC_Watt, LVar0)
    IfLt(LVar0, 180)
        Call(LoadPath, 15 * DT, Ref(N(WattRightFlightPath)), ARRAY_COUNT(N(WattRightFlightPath)), EASING_LINEAR)
        Set(LVar4, 12)
    Else
        Call(LoadPath, 15 * DT, Ref(N(WattLeftFlightPath)), ARRAY_COUNT(N(WattLeftFlightPath)), EASING_LINEAR)
        Set(LVar4, -12)
    EndIf
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, LVar4)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Label(30)
        Call(GetNextPathPos)
        Add(LVar1, LVar7)
        Add(LVar2, LVar8)
        Add(LVar3, LVar9)
        Call(SetNpcPos, NPC_Watt, LVar1, LVar2, LVar3)
        Call(PlayerFaceNpc, NPC_Watt, FALSE)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(30)
        EndIf
    Call(NpcFacePlayer, NPC_Watt, 3)
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_Watt, ANIM_WorldWatt_Talk, ANIM_WorldWatt_Idle, 0, MSG_CH4_005A)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(5 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
    Wait(20 * DT)
    Call(EndSpeech, NPC_Watt, ANIM_WorldWatt_Talk, ANIM_WorldWatt_Idle, 0)
    Set(AB_OMO12_LightSource, LIGHT_FROM_NO_CHANGE)
    Wait(1)
    Call(N(ChangeNpcToPartner), NPC_Watt, PARTNER_WATT)
    Call(N(LoadPartyImage))
    Exec(N(EVS_PushPartnerSong))
    Wait(15 * DT)
    Call(ShowMessageAtScreenPos, MSG_Menus_018E, 160, 40)
    Exec(N(EVS_PopSong))
    Wait(10 * DT)
    Thread
        Call(GetNpcPos, NPC_PARTNER, LVar2, LVar3, LVar4)
        Call(MakeLerp, 200, 255, 45 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(N(SetLightOriginAndPower), LVar2, LVar3, LVar4, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(GetPlayerPos, LVar2, LVar3, LVar4)
        Add(LVar3, 8)
        Call(N(SetLightOriginAndPower), LVar2, LVar3, LVar4, LVar0)
    EndThread
    Wait(30 * DT)
    Call(CloseMessage)
    Wait(10 * DT)
    ExecWait(N(EVS_CreateDarkness))
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldWatt_Talk, ANIM_WorldWatt_Idle, 0, MSG_CH4_005B)
    Call(EnablePartnerAI)
    Exec(N(EVS_UseWattTutorial))
    Call(N(EnableCameraLeadingPlayer))
    Call(ResetCam, CAM_DEFAULT, Float(5.0 / DT))
    Set(GB_StoryProgress, STORY_CH4_WATT_JOINED_PARTY)
    Call(DisablePlayerInput, FALSE)
    Call(RemoveNpc, NPC_LaternTop)
    Call(RemoveNpc, NPC_LaternBottom)
    Unbind
    Return
    End
};

EvtScript N(EVS_NpcIdle_BigLanternGhost) = {
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        Wait(1)
        IfNe(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(1)
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_BigLanternGhost) = {
    Wait(1)
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(ResetCam, CAM_DEFAULT, Float(90.0))
            Set(AB_OMO12_LightSource, LIGHT_FROM_DEFAULT)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(N(SetLightOriginAndPower), LVar0, LVar1, LVar2, 100)
            Thread
                Set(MF_LanternGhost_DoneSpeaking, FALSE)
                Call(SpeakToPlayer, NPC_BigLanternGhost, ANIM_BigLanternGhost_Anim08, ANIM_BigLanternGhost_Anim08, 0, MSG_CH4_0054)
                Set(MF_LanternGhost_DoneSpeaking, TRUE)
            EndThread
            Thread
                Wait(15)
                Call(SetNpcJumpscale, NPC_LaternTop, Float(1.0))
                Call(SetNpcPos, NPC_LaternTop, 0, 0, 20)
                Call(NpcJump0, NPC_LaternTop, 0, 0, 20, 10)
                Call(SetNpcPos, NPC_LaternBottom, 0, 0, 20)
            EndThread
            Call(SetNpcAnimation, NPC_SELF, ANIM_BigLanternGhost_Anim07)
            Call(SetNpcSpeed, NPC_SELF, Float(10.0))
            Call(NpcMoveTo, NPC_SELF, 400, 0, 0)
            Label(0)
                IfEq(MF_LanternGhost_DoneSpeaking, FALSE)
                    Wait(1)
                    Goto(0)
                EndIf
            Call(GetNpcPos, NPC_LaternTop, LVar3, LVar4, LVar5)
            SubF(LVar3, LVar0)
            SubF(LVar4, LVar1)
            SubF(LVar5, LVar2)
            DivF(LVar3, Float(60.0))
            DivF(LVar4, Float(60.0))
            DivF(LVar5, Float(60.0))
            SetF(LVar6, Float(2.167))
            SetF(LVar7, Float(100.0))
            Loop(60)
                AddF(LVar0, LVar3)
                AddF(LVar1, LVar4)
                AddF(LVar2, LVar5)
                AddF(LVar7, LVar6)
                Call(N(SetLightOriginAndPower), LVar0, LVar1, LVar2, LVar7)
                Wait(1)
            EndLoop
            Set(AB_OMO12_LightSource, LIGHT_FROM_LANTERN)
            Set(AB_OMO12_LightPowerMod, 102)
            Wait(1)
            Call(SetNpcVar, NPC_LaternTop, 0, 1)
            Set(GB_StoryProgress, STORY_CH4_DEFEATED_LANTERN_GHOST)
            Call(DisablePlayerInput, FALSE)
            Call(RemoveNpc, NPC_SELF)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_BigLanternGhost) = {
    IfGe(GB_StoryProgress, STORY_CH4_DEFEATED_LANTERN_GHOST)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_BigLanternGhost)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_BigLanternGhost)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_LanternTop) = {
    Thread
        Wait(15)
        Call(SetNpcRotation, NPC_SELF, 0, 0, 10)
        Wait(6)
        Call(SetNpcRotation, NPC_SELF, 0, 0, -9)
        Wait(6)
        Call(SetNpcRotation, NPC_SELF, 0, 0, 8)
        Wait(5)
        Call(SetNpcRotation, NPC_SELF, 0, 0, -7)
        Wait(5)
        Call(SetNpcRotation, NPC_SELF, 0, 0, 6)
        Wait(4)
        Call(SetNpcRotation, NPC_SELF, 0, 0, -5)
        Wait(4)
        Call(SetNpcRotation, NPC_SELF, 0, 0, 4)
        Wait(3)
        Call(SetNpcRotation, NPC_SELF, 0, 0, -3)
        Wait(3)
        Call(SetNpcRotation, NPC_SELF, 0, 0, 2)
        Wait(2)
        Call(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EndThread
    Call(SpeakToPlayer, NPC_SELF, ANIM_BigLanternGhost_Anim02, ANIM_BigLanternGhost_Anim02, 5, MSG_CH4_0055)
    Return
    End
};

EvtScript N(EVS_NpcIdle_LanternTop) = {
    Label(0)
        Call(GetSelfVar, 0, LVar0)
        Switch(LVar0)
            CaseEq(0)
            CaseEq(1)
                Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                Call(AwaitPlayerLeave, LVar0, LVar2, 100)
                Call(PartnerCanUseAbility, LVar0)
                IfNe(LVar0, TRUE)
                    Call(DisablePlayerInput, TRUE)
                    Thread
                        Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
                        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                        Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 16)
                        Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 8)
                        Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 4)
                    EndThread
                    Call(SpeakToPlayer, NPC_SELF, ANIM_BigLanternGhost_Anim02, ANIM_BigLanternGhost_Anim02, 0, MSG_CH4_0056)
                    Call(DisablePlayerInput, FALSE)
                EndIf
                Call(GetSelfVar, 0, LVar0)
                IfEq(LVar0, 1)
                    Call(SetSelfVar, 0, 2)
                EndIf
            CaseEq(2)
                Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                Call(AwaitPlayerApproach, LVar0, LVar2, 60)
                Call(GetSelfVar, 0, LVar0)
                IfEq(LVar0, 2)
                    Call(SetSelfVar, 0, 1)
                EndIf
        EndSwitch
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcInit_LanternTop) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH4_DEFEATED_LANTERN_GHOST)
            Call(SetNpcAnimation, NPC_SELF, ANIM_BigLanternGhost_Anim02)
        CaseLt(STORY_CH4_WATT_JOINED_PARTY)
            Call(SetNpcAnimation, NPC_SELF, ANIM_BigLanternGhost_Anim02)
            Call(SetNpcPos, NPC_SELF, 0, 0, 20)
            Call(SetSelfVar, 0, 2)
        CaseGe(STORY_CH4_WATT_JOINED_PARTY)
            Call(RemoveNpc, NPC_SELF)
            Return
    EndSwitch
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_LanternTop)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_LanternTop)))
    Return
    End
};

EvtScript N(EVS_NpcInit_LanternBottom) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH4_DEFEATED_LANTERN_GHOST)
            Call(SetNpcAnimation, NPC_SELF, ANIM_BigLanternGhost_Anim02)
        CaseLt(STORY_CH4_WATT_JOINED_PARTY)
            Call(SetNpcAnimation, NPC_SELF, ANIM_BigLanternGhost_Anim02)
            Call(SetNpcPos, NPC_SELF, 0, 0, 20)
        CaseGe(STORY_CH4_WATT_JOINED_PARTY)
            Call(RemoveNpc, NPC_SELF)
            Return
    EndSwitch
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_Scene_ReleaseWatt)))
    Call(SetNpcFlagBits, NPC_LaternBottom, NPC_FLAG_INVISIBLE, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Watt) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH4_DEFEATED_LANTERN_GHOST)
        CaseLt(STORY_CH4_WATT_JOINED_PARTY)
        CaseGe(STORY_CH4_WATT_JOINED_PARTY)
            Call(RemoveNpc, NPC_SELF)
            Return
    EndSwitch
    Return
    End
};

AnimID N(ExtraAnims_LanternGhost)[] = {
    ANIM_BigLanternGhost_Anim01,
    ANIM_BigLanternGhost_Anim06,
    ANIM_BigLanternGhost_Anim07,
    ANIM_BigLanternGhost_Anim08,
    ANIM_BigLanternGhost_Anim0F,
    ANIM_BigLanternGhost_Anim05,
    ANIM_BigLanternGhost_Anim02,
    ANIM_BigLanternGhost_Anim03,
    ANIM_BigLanternGhost_Anim04,
    ANIM_LIST_END
};

NpcData N(NpcData_BigLanternGhost) = {
    .id = NPC_BigLanternGhost,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_BigLanternGhost),
    .initVarCount = 1,
    .initVar = { .value = 0 },
    .settings = &N(NpcSettings_BigLanternGhost),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
    .drops = NO_DROPS,
    .animations = BIG_LANTERN_GHOST_ANIMS,
    .extraAnimations = N(ExtraAnims_LanternGhost),
    .tattle = MSG_NpcTattle_OMO_Lantern,
};

NpcData N(NpcData_Watt) = {
    .id = NPC_Watt,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Watt),
    .initVarCount = 1,
    .initVar = { .value = 0 },
    .settings = &N(NpcSettings_Watt),
    .flags = COMMON_PASSIVE_FLAGS,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_WorldWatt_Idle,
        .walk   = ANIM_WorldWatt_Idle,
        .run    = ANIM_WorldWatt_Idle,
        .chase  = ANIM_WorldWatt_Idle,
        .anim_4 = ANIM_WorldWatt_Idle,
        .anim_5 = ANIM_WorldWatt_Idle,
        .death  = ANIM_WorldWatt_Idle,
        .hit    = ANIM_WorldWatt_Idle,
        .anim_8 = ANIM_WorldWatt_Idle,
        .anim_9 = ANIM_WorldWatt_Idle,
        .anim_A = ANIM_WorldWatt_Idle,
        .anim_B = ANIM_WorldWatt_Idle,
        .anim_C = ANIM_WorldWatt_Idle,
        .anim_D = ANIM_WorldWatt_Idle,
        .anim_E = ANIM_WorldWatt_Idle,
        .anim_F = ANIM_WorldWatt_Idle,
    },
    .tattle = MSG_NpcTattle_OMO_Lantern,
};

NpcData N(NpcData_LanternTop) = {
    .id = NPC_LaternTop,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_LanternTop),
    .initVarCount = 1,
    .initVar = { .value = 0 },
    .settings = &N(NpcSettings_Watt),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = BIG_LANTERN_GHOST_ANIMS,
    .extraAnimations = N(ExtraAnims_LanternGhost),
    .tattle = MSG_NpcTattle_OMO_Lantern,
};

NpcData N(NpcData_LanternBottom) = {
    .id = NPC_LaternBottom,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_LanternBottom),
    .initVarCount = 1,
    .initVar = { .value = 0 },
    .settings = &N(NpcSettings_Watt),
    .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_CANT_INTERACT,
    .drops = NO_DROPS,
    .animations = BIG_LANTERN_GHOST_ANIMS,
    .extraAnimations = N(ExtraAnims_LanternGhost),
    .tattle = MSG_NpcTattle_OMO_Lantern,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_BigLanternGhost), BTL_OMO3_FORMATION_00),
    NPC_GROUP(N(NpcData_Watt)),
    NPC_GROUP(N(NpcData_LanternTop)),
    NPC_GROUP(N(NpcData_LanternBottom)),
    {}
};
