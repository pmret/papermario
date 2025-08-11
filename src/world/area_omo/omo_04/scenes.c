#include "omo_04.h"
#include "effects.h"

s32 N(HoverOffsets)[] = {
     1,  2,  3,  2,  1,
    -1, -2, -3, -2, -1,
};

EvtScript N(EVS_NpcIdle_Kammy) = {
    Call(SetSelfVar, 0, 0)
    Call(GetNpcPos, NPC_SELF, LVar6, LVar3, LVar4)
    Loop(0)
        UseBuf(Ref(N(HoverOffsets)))
        Loop(10)
            Call(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
            Call(GetSelfVar, 0, LVar5)
            IfEq(LVar5, 0)
                Switch(LVar6)
                    CaseLt(LVar2)
                        Call(SetNpcYaw, NPC_SELF, 90)
                    CaseGt(LVar2)
                        Call(SetNpcYaw, NPC_SELF, 270)
                EndSwitch
                Set(LVar6, LVar2)
                Wait(1)
            Else
                BufRead1(LVar1)
                Add(LVar3, LVar1)
                Call(SetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
                Wait(3)
            EndIf
        EndLoop
    EndLoop
    Return
    End
};

#define KAMMY_NPC NPC_Kammy
#include "world/common/util/GetKammyBroomEmitterPos.inc.c"

EvtScript N(EVS_NpcAux_Kammy) = {
    Set(MF_KammyFlying, false)
    Call(GetNpcPos, NPC_Kammy, LVar6, LVar7, LVar8)
    Loop(0)
        Call(N(GetKammyBroomEmitterPos), MF_KammyFlying)
        Call(GetNpcPos, NPC_Kammy, LVar9, LVarA, LVarB)
        Set(LVar3, LVar9)
        Set(LVar4, LVarA)
        Set(LVar5, LVarB)
        SubF(LVar3, LVar6)
        SubF(LVar4, LVar7)
        SubF(LVar5, LVar8)
        SetF(LVar6, LVar9)
        SetF(LVar7, LVarA)
        SetF(LVar8, LVarB)
        IfNe(LVar3, 0)
            IfNe(LVar5, 0)
                PlayEffect(EFFECT_PURPLE_RING, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.0))
            EndIf
        EndIf
        Wait(3)
    EndLoop
    Return
    End
};

Vec3f N(FlightPath_Kammy1)[] = {
    {  800.0,   140.0,  -20.0 },
    { 1050.0,   120.0,  -70.0 },
    { 1150.0,    95.0, -100.0 },
    { 1200.0,    77.0,  -30.0 },
    { 1150.0,    62.0,   85.0 },
    { 1050.0,    50.0,  130.0 },
    {  800.0,    40.0,   50.0 },
    { 1000.0,    20.0,    0.0 },
};

Vec3f N(FlightPath_Kammy2)[] = {
    { 1000.0,    20.0,    0.0 },
    { 1010.0,    17.0,    0.0 },
    { 1020.0,    15.0,    0.0 },
};

Vec3f N(FlightPath_Kammy3)[] = {
    { 1020.0,    15.0,    0.0 },
    { 1080.0,    30.0,   30.0 },
    { 1160.0,    80.0,  -40.0 },
    {  600.0,   150.0,   90.0 },
};

EvtScript N(EVS_PlayKammyFlightSounds) = {
    Loop(0)
        Call(PlaySoundAtNpc, NPC_Kammy, SOUND_FLIGHT, SOUND_SPACE_DEFAULT)
        Wait(4)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_KammySetAmbush) = {
    Call(DisablePlayerInput, true)
    Set(GF_OMO04_SpawnedPeachChoice1, true)
    Set(AB_OMO_CurrentPeachChoice, GB_OMO_PeachChoice1)
    Switch(AB_OMO_CurrentPeachChoice)
        CaseEq(0)
            Set(MV_AmbushID, NPC_Goomba)
        CaseEq(1)
            Set(MV_AmbushID, NPC_Clubba)
        CaseEq(2)
            Set(MV_AmbushID, ITEM_MUSHROOM)
    EndSwitch
    Call(SetNpcPos, NPC_Kammy, 800, 140, -20)
    Call(SetNpcYaw, NPC_Kammy, 270)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim15)
    IfNe(AB_OMO_CurrentPeachChoice, 2)
        Call(SetNpcPos, MV_AmbushID, NPC_DISPOSE_LOCATION)
    EndIf
    Call(UseSettingsFrom, CAM_DEFAULT, 1100, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 1100, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(500.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-7.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(60 * DT)
    ExecGetTID(N(EVS_PlayKammyFlightSounds), MV_FlightSoundsScriptID)
    Set(MF_KammyFlying, true)
    Thread
        Wait(100 * DT)
        Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
#if VERSION_PAL
        Call(SetCamSpeed, CAM_DEFAULT, Float(2 / DT))
#else
        Call(SetCamSpeed, CAM_DEFAULT, 2)
#endif
        Call(PanToTarget, CAM_DEFAULT, 0, true)
    EndThread
    Call(LoadPath, 150 * DT, Ref(N(FlightPath_Kammy1)), ARRAY_COUNT(N(FlightPath_Kammy1)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        Wait(1)
        IfNe(LVar0, 1)
            BreakLoop
        EndIf
    EndLoop
    Set(MF_KammyFlying, false)
    KillThread(MV_FlightSoundsScriptID)
    Call(PlaySoundAtNpc, NPC_Kammy, SOUND_SKID, SOUND_SPACE_DEFAULT)
    Thread
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim10)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -5)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -10)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -15)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -10)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -15)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -10)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -15)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -10)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -15)
        Wait(3)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, 0)
    EndThread
    Call(LoadPath, 10 * DT, Ref(N(FlightPath_Kammy2)), ARRAY_COUNT(N(FlightPath_Kammy2)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        Wait(1)
        IfNe(LVar0, 1)
            BreakLoop
        EndIf
    EndLoop
    Wait(15 * DT)
    Call(SetNpcVar, NPC_Kammy, 0, 1)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim13)
    Wait(45 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0E)
    Call(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
    Add(LVar0, 25)
    Add(LVar1, 38)
    Call(PlaySoundAt, SOUND_KAMMY_SUMMON_MAGIC, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, Float(1.0), 100)
    Wait(100 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0F)
    Add(LVar0, 55)
    Call(PlaySoundAt, SOUND_VANISH_IN_SMOKE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, 0, 0, 1, 15, 3, 8)
    Wait(5 * DT)
    IfNe(AB_OMO_CurrentPeachChoice, 2)
        Call(SetNpcPos, MV_AmbushID, LVar0, 0, 0)
    Else
        Call(MakeItemEntity, MV_AmbushID, LVar0, 0, 0, ITEM_SPAWN_MODE_DECORATION, 0)
    EndIf
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim13)
    Wait(45 * DT)
    Switch(AB_OMO_CurrentPeachChoice)
        CaseEq(0)
            Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 517, MSG_CH4_0036)
            Wait(30 * DT)
            Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 517, MSG_CH4_0037)
        CaseEq(1)
            Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 517, MSG_CH4_0038)
            Wait(10 * DT)
            Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 517, MSG_CH4_0039)
        CaseEq(2)
            Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 517, MSG_CH4_0034)
            Wait(30 * DT)
            Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 517, MSG_CH4_0035)
    EndSwitch
    Call(SetNpcVar, NPC_Kammy, 0, 0)
    Wait(5 * DT)
    Call(SetCamDistance, CAM_DEFAULT, Float(500.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    ExecGetTID(N(EVS_PlayKammyFlightSounds), MV_FlightSoundsScriptID)
    Set(MF_KammyFlying, true)
    Thread
        Call(LoadPath, 130 * DT, Ref(N(FlightPath_Kammy3)), ARRAY_COUNT(N(FlightPath_Kammy3)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
            Wait(1)
            IfNe(LVar0, 1)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(90 * DT)
    IfNe(AB_OMO_CurrentPeachChoice, 2)
        Call(PlaySoundAtNpc, MV_AmbushID, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, MV_AmbushID, EMOTE_QUESTION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
        Wait(5 * DT)
    EndIf
    Call(GotoMap, Ref("omo_04"), omo_04_ENTRY_0)
    Wait(100 * DT)
    Return
    End
};
