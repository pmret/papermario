#include "osr_02.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/npc/Peach.inc.c"
#include "world/common/npc/Twink.inc.c"
#include "world/common/npc/StarSpirit.inc.c"
#include "world/common/npc/StarRod.inc.c"

Vec3f N(FlightPath_TwinkStepForward)[] = {
    {  -10.0,    40.0,   10.0 },
    {   15.0,    33.0,   20.0 },
    {   50.0,    30.0,   30.0 },
};

Vec3f N(FlightPath_TwinkDepart)[] = {
    {   50.0,    30.0,   30.0 },
    {   70.0,    45.0,   10.0 },
    {   90.0,    60.0,   30.0 },
    {   70.0,    75.0,   50.0 },
    {   50.0,    90.0,   30.0 },
    {   70.0,   105.0,   10.0 },
    {   90.0,   120.0,   30.0 },
    {   70.0,   135.0,   50.0 },
    {   50.0,   150.0,   30.0 },
    {   70.0,   165.0,   10.0 },
    {   90.0,   180.0,   30.0 },
    {   70.0,   195.0,   50.0 },
    {   50.0,   210.0,   30.0 },
};

EvtScript N(EVS_StarSpirit_FlyAway) = {
    Call(SetNpcFlagBits, LVar4, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, true)
    Thread
        Loop(30)
            Call(GetNpcPos, LVar4, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 20)
            Wait(6)
        EndLoop
    EndThread
    Thread
        Loop(30)
            Call(GetNpcPos, LVar4, LVar0, LVar1, LVar2)
            Add(LVar1, 20)
            PlayEffect(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 40)
            Wait(8)
        EndLoop
    EndThread
    Thread
        Call(MakeLerp, 0, 1800, 100, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, LVar4, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(GetNpcPos, LVar4, LVar7, LVar8, LVar9)
    Call(MakeLerp, 80, 260, 100, EASING_CUBIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcPos, LVar4, LVar7, LVar0, LVar9)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcPos, LVar4, LVar7, NPC_DISPOSE_POS_Y, LVar9)
    Return
    End
};

EvtScript N(EVS_Twink_FlyAway) = {
    Thread
        Loop(30)
            Call(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 20)
            Wait(6)
        EndLoop
    EndThread
    Thread
        Loop(30)
            Call(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
            Add(LVar1, 20)
            PlayEffect(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 40)
            Wait(8)
        EndLoop
    EndThread
    Thread
        Call(MakeLerp, 0, 2160, 120, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_Twink, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(PlaySoundAtNpc, NPC_Twink, SOUND_TWINK_DEPART, SOUND_SPACE_DEFAULT)
        Call(LoadPath, 120, Ref(N(FlightPath_TwinkDepart)), ARRAY_COUNT(N(FlightPath_TwinkDepart)), EASING_QUADRATIC_IN)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetNpcPos, NPC_Twink, LVar1, NPC_DISPOSE_POS_Y, LVar3)
    EndThread
    Thread
        Call(AdjustCam, CAM_DEFAULT, Float(0.5), 0, 550, Float(17.0), Float(-10.0))
    EndThread
    Return
    End
};

EvtScript N(EVS_Scene_ReturnStarRod) = {
    Call(DisablePlayerInput, true)
    Call(DisablePartnerAI, 0)
    Call(SetMusic, 0, SONG_STAR_SPIRIT_THEME, BGM_VARIATION_2, VOL_LEVEL_FULL)
    Call(SetPlayerPos, 15, 0, 30)
    Call(InterpPlayerYaw, 90, 0)
    Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_PARTNER, -70, LVar1, 15)
    Call(SetNpcYaw, NPC_PARTNER, 90)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-7.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(700.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Wait(1)
    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(20)
    Call(SetPlayerAnimation, ANIM_MarioW1_TakeItem)
    Call(SetNpcPos, NPC_StarRod, 30, 25, 30)
    Wait(20)
    Call(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Leap)
    Call(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    Set(LVar1, 80)
    Set(LVar2, 35)
    Call(SetNpcJumpscale, NPC_StarRod, Float(0.5))
    Call(NpcJump1, NPC_StarRod, LVar0, LVar1, LVar2, 20)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(PlaySound, SOUND_RECEIVE_STAR_POWER)
    Loop(6)
        PlayEffect(EFFECT_RADIAL_SHIMMER, 9, LVar0, LVar1, LVar2, 1, 20)
        PlayEffect(EFFECT_SPARKLES, 1, LVar0, LVar1, LVar2, 30)
        Wait(10)
    EndLoop
    Loop(20)
        Add(LVar1, -1)
        Call(SetNpcPos, NPC_StarRod, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(SetNpcPos, NPC_StarRod, NPC_DISPOSE_LOCATION)
    Wait(20)
    Call(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Idle)
    Wait(10)
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_Outro_0000)
    Wait(10)
    Thread
        Wait(5)
        Call(SetNpcJumpscale, NPC_Eldstar, Float(0.0))
        Call(NpcJump0, NPC_Eldstar, 120, 80, 0, 40)
        Call(InterpNpcYaw, NPC_Eldstar, 270, 0)
    EndThread
    Call(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    Set(LVar0, 120)
    Set(LVar1, 80)
    Set(LVar2, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-5.5))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-5.5))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Mamar, ANIM_WorldMamar_TalkHappy, ANIM_WorldMamar_Idle, 0, MSG_Outro_0001)
    Call(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-5.5))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Skolar, ANIM_WorldSkolar_TalkAngry, ANIM_WorldSkolar_Idle, 0, MSG_Outro_0002)
    Call(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-5.5))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 0, MSG_Outro_0003)
    Call(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-5.5))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Misstar, ANIM_WorldMisstar_Talk, ANIM_WorldMisstar_Idle, 0, MSG_Outro_0004)
    Call(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-5.5))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Klevar, ANIM_WorldKlevar_Talk, ANIM_WorldKlevar_Idle, 0, MSG_Outro_0005)
    Call(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-5.5))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Kalmar, ANIM_WorldKalmar_Talk, ANIM_WorldKalmar_Idle, 0, MSG_Outro_0006)
    Call(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-5.5))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_Outro_0007)
    Call(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-2.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(5)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Outro_0008)
    Call(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-6.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(275.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_Outro_0009)
    Wait(20)
    Call(AdjustCam, CAM_DEFAULT, Float(90.0), 70, 400, Float(17.0), Float(-11.0))
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Thread
        Set(LVar4, NPC_Eldstar)
        Call(PlaySoundAtNpc, LVar4, SOUND_STAR_SPIRIT_DEPART_1, SOUND_SPACE_DEFAULT)
        ExecWait(N(EVS_StarSpirit_FlyAway))
    EndThread
    Thread
        Wait(30)
        Set(LVar4, NPC_Misstar)
        Call(PlaySoundAtNpc, LVar4, SOUND_STAR_SPIRIT_DEPART_2, SOUND_SPACE_DEFAULT)
        ExecWait(N(EVS_StarSpirit_FlyAway))
    EndThread
    Thread
        Wait(60)
        Set(LVar4, NPC_Skolar)
        Call(PlaySoundAtNpc, LVar4, SOUND_STAR_SPIRIT_DEPART_1, SOUND_SPACE_DEFAULT)
        ExecWait(N(EVS_StarSpirit_FlyAway))
    EndThread
    Thread
        Wait(90)
        Set(LVar4, NPC_Mamar)
        Call(PlaySoundAtNpc, LVar4, SOUND_STAR_SPIRIT_DEPART_2, SOUND_SPACE_DEFAULT)
        ExecWait(N(EVS_StarSpirit_FlyAway))
    EndThread
    Thread
        Wait(120)
        Set(LVar4, NPC_Kalmar)
        Call(PlaySoundAtNpc, LVar4, SOUND_STAR_SPIRIT_DEPART_1, SOUND_SPACE_DEFAULT)
        ExecWait(N(EVS_StarSpirit_FlyAway))
    EndThread
    Thread
        Wait(150)
        Set(LVar4, NPC_Muskular)
        Call(PlaySoundAtNpc, LVar4, SOUND_STAR_SPIRIT_DEPART_2, SOUND_SPACE_DEFAULT)
        ExecWait(N(EVS_StarSpirit_FlyAway))
    EndThread
    Wait(180)
    Set(LVar4, NPC_Klevar)
    Call(PlaySoundAtNpc, LVar4, SOUND_STAR_SPIRIT_DEPART_1, SOUND_SPACE_DEFAULT)
    ExecWait(N(EVS_StarSpirit_FlyAway))
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(20)
    Call(SetMusic, 0, SONG_TWINK_THEME, BGM_VARIATION_1, VOL_LEVEL_FULL)
    Call(LoadPath, 30, Ref(N(FlightPath_TwinkStepForward)), ARRAY_COUNT(N(FlightPath_TwinkStepForward)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(5)
    Call(InterpNpcYaw, NPC_Twink, 270, 0)
    Wait(10)
    Call(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-4.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Outro_000A)
    Wait(10)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_RaiseArms)
    Wait(10)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Outro_000B)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_LowerArms)
    Wait(10)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Idle)
    Wait(10)
    Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_Disappointed)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Disappointed, ANIM_Twink_Disappointed, 0, MSG_Outro_000C)
    Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_Idle)
    Call(EndSpeech, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0)
    Wait(20)
    Exec(N(EVS_Twink_FlyAway))
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Wait(250)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Walk)
    Call(NpcMoveTo, NPC_Peach, -10, 30, 40)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Idle)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(InterpPlayerYaw, 270, 0)
    Wait(60)
    Call(InterpPlayerYaw, 90, 0)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Wait(20)
    Call(GotoMap, Ref("hos_10"), hos_10_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_NpcInit_Peach) = {
    Call(SetNpcPos, NPC_SELF, -25, 0, 40)
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Twink) = {
    Call(SetNpcPos, NPC_SELF, -10, 40, 10)
    Call(SetNpcYaw, NPC_SELF, 90)
    Return
    End
};

s16 N(SpiritHoverOffsets)[] = {
    1, 3, 5, 7, 7, 5, 3
};

API_CALLABLE(N(AnimateSpiritHover)) {
    Npc* npc;

    if (isInitialCall) {
        script->functionTemp[1] = 0.0f;
        script->functionTempPtr[2] = get_npc_safe(script->owner2.npcID);
        script->functionTemp[3] = N(SpiritHoverOffsets)[script->owner2.npcID - 2];
    }

    if (script->functionTemp[3] != 0) {
        script->functionTemp[3]--;
        return ApiStatus_BLOCK;
    }

    npc = script->functionTempPtr[2];
    npc->verticalRenderOffset = sin_deg(script->functionTempF[1]) * 1.5f;
    script->functionTempF[1] = clamp_angle(script->functionTempF[1] + 18.0f);
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_NpcAux_Eldstar) = {
    Call(N(AnimateSpiritHover))
    Return
    End
};

EvtScript N(EVS_NpcInit_Eldstar) = {
    Call(SetNpcPos, NPC_Eldstar, 60, 20, 30)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Eldstar)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Mamar) = {
    Call(SetNpcPos, NPC_SELF, 66, 80, -27)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Eldstar)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Skolar) = {
    Call(SetNpcPos, NPC_SELF, 53, 80, -95)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Eldstar)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Muskular) = {
    Call(SetNpcPos, NPC_SELF, 91, 80, -132)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Eldstar)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Misstar) = {
    Call(SetNpcPos, NPC_SELF, 151, 80, -132)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Eldstar)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Klevar) = {
    Call(SetNpcPos, NPC_SELF, 189, 80, -95)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Eldstar)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Kalmar) = {
    Call(SetNpcPos, NPC_SELF, 176, 80, -27)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Eldstar)))
    Return
    End
};

EvtScript N(EVS_NpcInit_StarRod) = {
    Return
    End
};

AnimID N(ExtraAnims_Peach)[] = {
    ANIM_Peach1_Idle,
    ANIM_Peach1_Walk,
    ANIM_Peach2_RaiseArms,
    ANIM_Peach2_Talk,
    ANIM_Peach2_LowerArms,
    ANIM_Peach2_GaspStill,
    ANIM_Peach2_TiedIdle,
    ANIM_Peach2_TalkIdle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Twink)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Talk,
    ANIM_Twink_Disappointed,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Eldstar)[] = {
    ANIM_WorldEldstar_Idle,
    ANIM_WorldEldstar_Wave,
    ANIM_WorldEldstar_Leap,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Mamar)[] = {
    ANIM_WorldMamar_Idle,
    ANIM_WorldMamar_TalkHappy,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Skolar)[] = {
    ANIM_WorldSkolar_Idle,
    ANIM_WorldSkolar_TalkAngry,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Muskular)[] = {
    ANIM_WorldMuskular_Idle,
    ANIM_WorldMuskular_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Misstar)[] = {
    ANIM_WorldMisstar_Idle,
    ANIM_WorldMisstar_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Klevar)[] = {
    ANIM_WorldKlevar_Idle,
    ANIM_WorldKlevar_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Kalmar)[] = {
    ANIM_WorldKalmar_Idle,
    ANIM_WorldKalmar_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Spirits)[] = {
    {
        .id = NPC_Peach,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Peach),
        .settings = &N(NpcSettings_Peach),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_PLAYER_SPRITE,
        .drops = NO_DROPS,
        .animations = PEACH_ANIMS,
        .extraAnimations = N(ExtraAnims_Peach),
    },
    {
        .id = NPC_Twink,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Twink),
        .settings = &N(NpcSettings_Twink),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_Twink),
    },
    {
        .id = NPC_Eldstar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Eldstar),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = ELDSTAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Eldstar),
    },
    {
        .id = NPC_Mamar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Mamar),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MAMAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Mamar),
    },
    {
        .id = NPC_Skolar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Skolar),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = SKOLAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Skolar),
    },
    {
        .id = NPC_Muskular,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Muskular),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MUSKULAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Muskular),
    },
    {
        .id = NPC_Misstar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Misstar),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MISSTAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Misstar),
    },
    {
        .id = NPC_Klevar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Klevar),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KLEVAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Klevar),
    },
    {
        .id = NPC_Kalmar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Kalmar),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KALMAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Kalmar),
    },
    {
        .id = NPC_StarRod,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_StarRod),
        .settings = &N(NpcSettings_StarRod),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = STAR_ROD_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Spirits)),
    {}
};
