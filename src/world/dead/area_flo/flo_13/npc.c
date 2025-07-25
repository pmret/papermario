#include "flo_13.h"
#include "sprite/player.h"

#include "world/common/util/ChangeNpcToPartner.inc.c"

NpcSettings N(NpcSettings_Lakilester) = {
    .height = 32,
    .radius = 24,
    .level = ACTOR_LEVEL_LAKITU,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#define AI_LAKITU_FIRST_SPINY_ID    NPC_Spiny_01
#define AI_LAKITU_LAST_SPINY_ID     NPC_Spiny_06
#define DEBUG_LAKITU
#include "world/common/enemy/Lakitu_SpinySpawner.inc.c"

#include "world/common/todo/UnkFunc42.inc.c"

API_CALLABLE(N(PlayLakiluluFlightSounds)) {
    Npc* npc = get_npc_unsafe(NPC_Lakilulu);
    s16 volume;
    s16 pan;

    script->functionTemp[1] = evt_get_variable(script, *script->ptrReadPos);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] % 5 == 0) {
        sfx_get_spatialized_sound_params(npc->pos.x, npc->pos.y, npc->pos.z,
            &volume, &pan, SOUND_PARAM_MORE_QUIET | SOUND_SPACE_FULL);
        sfx_play_sound_with_params(SOUND_FLIGHT, volume, pan,
            update_lerp(EASING_LINEAR, 500.0f, 0.0f, script->functionTemp[0], script->functionTemp[1]));
    }

    script->functionTemp[0]++;

    if (script->functionTemp[0] > script->functionTemp[1]) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(PlayLakilesterFlightSounds)) {
    Npc* npc = get_npc_unsafe(NPC_Lakilester);
    s16 volume;
    s16 pan;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] % 5 == 0) {
        sfx_get_spatialized_sound_params(npc->pos.x, npc->pos.y, npc->pos.z,
            &volume, &pan, SOUND_PARAM_MORE_QUIET | SOUND_SPACE_FULL);
        sfx_play_sound_with_params(SOUND_FLIGHT, volume, pan,
            update_lerp(EASING_LINEAR, 500.0f, 0.0f, script->functionTemp[0], 80));
    }

    script->functionTemp[0]++;

    if (script->functionTemp[0] > 80) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

Vec3f N(FlightPath_LakilesterAmbush)[] = {
    { -250.0,   130.0,  100.0 },
    { -150.0,    90.0,   70.0 },
    {   50.0,    70.0,   10.0 },
    {  200.0,    35.0,   30.0 },
    {   30.0,    10.0,   45.0 },
};

Vec3f N(FlightPath_LakiluluArrives)[] = {
    { -285.0,   130.0,   45.0 },
    { -185.0,    90.0,   25.0 },
    {   15.0,    70.0,   10.0 },
    {  165.0,    35.0,   30.0 },
    {   -5.0,    10.0,   45.0 },
};

Vec3f N(FlightPath_LakiluluDeparts)[] = {
    {   10.0,     0.0,   45.0 },
    {  -90.0,    20.0,   45.0 },
    { -190.0,    60.0,   45.0 },
    { -290.0,   140.0,   45.0 },
    { -390.0,   300.0,   45.0 },
};

EvtScript N(EVS_Lakliester_ManageYaw) = {
    Call(GetNpcPos, NPC_Lakilester, LVar0, LVar1, LVar2)
    Label(0)
        Call(GetNpcPos, NPC_Lakilester, LVar3, LVar4, LVar5)
        Call(N(UnkFunc42))
        Call(InterpNpcYaw, NPC_Lakilester, LVarA, 0)
        Set(LVar0, LVar3)
        Set(LVar1, LVar4)
        Set(LVar2, LVar5)
        Call(GetAngleBetweenNPCs, NPC_PARTNER, NPC_Lakilester, LVarA)
        Call(InterpNpcYaw, NPC_PARTNER, LVarA, 0)
        Call(PlayerFaceNpc, NPC_Lakilester, false)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Laklilulu_ManageYaw) = {
    Call(GetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
    Label(0)
        Call(GetNpcPos, NPC_Lakilulu, LVar3, LVar4, LVar5)
        Call(N(UnkFunc42))
        Call(InterpNpcYaw, NPC_Lakilulu, LVarA, 0)
        Set(LVar0, LVar3)
        Set(LVar1, LVar4)
        Set(LVar2, LVar5)
        Call(GetAngleBetweenNPCs, NPC_PARTNER, NPC_Lakilulu, LVarA)
        Call(InterpNpcYaw, NPC_PARTNER, LVarA, 0)
        IfLt(GB_StoryProgress, STORY_CH6_LAKILESTER_JOINED_PARTY)
            Call(GetAngleBetweenNPCs, NPC_Lakilester, NPC_Lakilulu, LVarB)
            Call(InterpNpcYaw, NPC_Lakilester, LVarB, 0)
        EndIf
        Call(PlayerFaceNpc, NPC_Lakilulu, false)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_LakiluluAndSpiny_HoverBobbing) = {
    Set(MV_LakiluluSpinySceneState, 0)
    Loop(0)
        Loop(2)
            Call(GetNpcPos, NPC_Lakilulu_Spiny, LVar0, LVar1, LVar2)
            Add(LVar1, 1)
            Call(SetNpcPos, NPC_Lakilulu_Spiny, LVar0, LVar1, LVar2)
            Call(GetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
            Add(LVar1, 1)
            Call(SetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
            Wait(2)
        EndLoop
        Wait(1)
        Loop(2)
            Call(GetNpcPos, NPC_Lakilulu_Spiny, LVar0, LVar1, LVar2)
            Add(LVar1, -1)
            Call(SetNpcPos, NPC_Lakilulu_Spiny, LVar0, LVar1, LVar2)
            Call(GetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
            Add(LVar1, -1)
            Call(SetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
            Wait(2)
        EndLoop
        Wait(1)
        IfEq(MV_LakiluluSpinySceneState, 1)
            Set(MV_LakiluluSpinySceneState, 2)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Lakilulu_SpinyToss) = {
    Exec(N(EVS_LakiluluAndSpiny_HoverBobbing))
    Call(SetNpcAnimation, NPC_Lakilulu, ANIM_Lakilulu_Lift)
    Call(GetNpcPos, NPC_Lakilulu, LVar1, LVar2, LVar3)
    Add(LVar1, -5)
    Add(LVar2, 30)
    Add(LVar3, 2)
    Call(SetNpcYaw, NPC_Lakilulu_Spiny, 270)
    Call(SetNpcPos, NPC_Lakilulu_Spiny, LVar1, LVar2, LVar3)
    Thread
        Wait(5)
        Call(SetPlayerAnimation, ANIM_Mario1_Flail)
    EndThread
    Call(ContinueSpeech, NPC_Lakilulu, -1, -1, SPEECH_FLAG_200, MSG_CH6_00A8)
    Thread
        Wait(15)
        Call(EndSpeech, NPC_Lakilulu, -1, -1, SPEECH_FLAG_200)
    EndThread
    Set(MV_LakiluluSpinySceneState, 1)
    Loop(0)
        Wait(1)
        IfEq(MV_LakiluluSpinySceneState, 2)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcAnimation, NPC_Lakilulu, ANIM_Lakilulu_Throw)
    Call(GetPlayerPos, LVar1, LVar2, LVar3)
    Add(LVar1, 5)
    Add(LVar2, 20)
    Call(SetNpcJumpscale, NPC_Lakilulu_Spiny, Float(0.0))
    Call(NpcJump0, NPC_Lakilulu_Spiny, LVar1, LVar2, LVar3, 7)
    Add(LVar1, -100)
    Add(LVar2, 10)
    Thread
        Call(SetNpcJumpscale, NPC_Lakilulu_Spiny, Float(1.5))
        Call(NpcJump0, NPC_Lakilulu_Spiny, LVar1, LVar2, LVar3, 15)
        Call(SetNpcPos, NPC_Lakilulu_Spiny, NPC_DISPOSE_LOCATION)
    EndThread
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(2.0))
    EndThread
    Call(PlaySoundAtPlayer, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
    Call(SetPlayerAnimation, ANIM_Mario1_Hurt)
    Set(LVar0, 90)
    Loop(20)
        Add(LVar0, 144)
        IfGt(LVar0, 359)
            Sub(LVar0, 360)
        EndIf
        Call(InterpPlayerYaw, LVar0, 1)
        Wait(1)
    EndLoop
    Call(SetPlayerAnimation, ANIM_Mario1_Still)
    Call(SetNpcAnimation, NPC_Lakilulu, ANIM_Lakilulu_Idle)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Lakilester) = {
    IfNe(GB_StoryProgress, STORY_CH6_SPOKE_WITH_THE_SUN)
        Return
    EndIf
    Call(AwaitPlayerApproach, 200, 20, 275)
    Call(DisablePlayerInput, true)
    Call(SetNpcPos, NPC_Lakilester, -250, 120, 45)
    Call(SetMusic, 0, SONG_LAKILESTER_THEME, 0, VOL_LEVEL_FULL)
    Call(ShowMessageAtScreenPos, MSG_CH6_00A0, 160, 40)
    Call(InterruptUsePartner)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Wait(20)
    Call(InterpPlayerYaw, 270, 1)
    Wait(20)
    Call(InterpPlayerYaw, 90, 1)
    Wait(20)
    Call(SetPlayerAnimation, ANIM_Mario1_Still)
    Call(func_802CF56C, 2)
    Call(SetNpcAnimation, NPC_Lakilester, ANIM_WorldLakilester_Run)
    Thread
        Call(N(PlayLakilesterFlightSounds))
    EndThread
    ExecGetTID(N(EVS_Lakliester_ManageYaw), LVar9)
    Call(LoadPath, 80, Ref(N(FlightPath_LakilesterAmbush)), ARRAY_COUNT(N(FlightPath_LakilesterAmbush)), EASING_LINEAR)
    Label(0)
    Call(GetNextPathPos)
    Call(SetNpcPos, NPC_Lakilester, LVar1, LVar2, LVar3)
    Wait(1)
    IfEq(LVar0, 1)
        Goto(0)
    EndIf
    KillThread(LVar9)
    Call(SetNpcAnimation, NPC_Lakilester, ANIM_WorldLakilester_Idle)
    Call(PlayerFaceNpc, NPC_Lakilester, false)
    Wait(15)
    Call(GetNpcPos, NPC_Lakilester, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 200)
    Call(SetCamPitch, CAM_DEFAULT, Float(18.0), Float(-8.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Call(PlayerMoveTo, -75, 65, 10)
        Call(PlayerFaceNpc, NPC_Lakilester, false)
    EndThread
    Call(SpeakToPlayer, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00A1)
    Call(SetNpcAnimation, NPC_Lakilester, ANIM_WorldLakilester_Run)
    Wait(10)
    Call(SetNpcAnimation, NPC_Lakilester, ANIM_WorldLakilester_Idle)
    Thread
        Call(SetCamDistance, CAM_DEFAULT, 1000)
        Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-6.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndThread
    Call(DisablePlayerInput, false)
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_Lakilulu_FlyAway) = {
    Call(GetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
    Call(AwaitPlayerLeave, LVar0, LVar2, 120)
    Call(DisablePlayerInput, true)
    Call(GetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamPitch, CAM_DEFAULT, Float(5.5), Float(-7.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(NpcFaceNpc, NPC_Lakilulu, NPC_Lakilester, 1)
    Call(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_00B4)
    Call(NpcFaceNpc, NPC_PARTNER, NPC_Lakilulu, 1)
    Call(SetCamDistance, CAM_DEFAULT, 600)
    Call(SetCamPitch, CAM_DEFAULT, Float(10.0), Float(-8.0))
    Call(SetCamPosA, CAM_DEFAULT, 0, 0)
    Call(SetCamPosB, CAM_DEFAULT, 130, -200)
    Call(SetCamPosC, CAM_DEFAULT, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Call(N(PlayLakiluluFlightSounds), 55)
    EndThread
    Call(SetNpcFlagBits, NPC_Lakilulu, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
    ExecGetTID(N(EVS_Laklilulu_ManageYaw), LVar9)
    Call(LoadPath, 55, Ref(N(FlightPath_LakiluluDeparts)), ARRAY_COUNT(N(FlightPath_LakiluluDeparts)), EASING_LINEAR)
    Label(20)
    Call(GetNextPathPos)
    Call(SetNpcPos, NPC_Lakilulu, LVar1, LVar2, LVar3)
    Wait(1)
    IfEq(LVar0, 1)
        Goto(20)
    EndIf
    KillThread(LVar9)
    Call(GetCurrentPartnerID, LVar0)
    Call(BringPartnerOut, PARTNER_LAKILESTER)
    IfNe(LVar0, PARTNER_LAKILESTER)
        Call(SetNpcJumpscale, NPC_PARTNER, Float(0.0))
        Call(GetPlayerPos, LVar1, LVar2, LVar3)
        Add(LVar1, 20)
        Add(LVar2, 20)
        Add(LVar3, 20)
        Call(NpcJump0, NPC_PARTNER, LVar1, LVar2, LVar3, 30)
    EndIf
    Call(DisablePartnerAI, 0)
    Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
    Wait(5)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 5, MSG_CH6_00B5)
    Call(EnablePartnerAI)
    Call(PutPartnerAway)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_Scene_LakilesterDefeated) = {
    Call(DisablePlayerInput, true)
    Wait(30)
    Call(SpeakToPlayer, NPC_Lakilester, ANIM_WorldLakilester_TiredTalk, ANIM_WorldLakilester_Tired, 0, MSG_CH6_00A2)
    Call(SetNpcPos, NPC_Lakilulu, -290, 120, 45)
    Thread
        Wait(10)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldLakilester_Idle)
        Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
        Wait(20)
        Call(InterpPlayerYaw, 270, 1)
    EndThread
    Call(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 5, MSG_CH6_00A3)
    Call(SetNpcAnimation, NPC_Lakilulu, ANIM_Lakilulu_Panic)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, 500)
    Call(SetCamPitch, CAM_DEFAULT, Float(5.5), Float(-6.0))
    Call(SetCamPosA, CAM_DEFAULT, 0, 0)
    Call(SetCamPosB, CAM_DEFAULT, 130, -200)
    Call(SetCamPosC, CAM_DEFAULT, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Wait(1)
    Thread
        Call(SetCamDistance, CAM_DEFAULT, 400)
        Call(SetCamPosB, CAM_DEFAULT, 130, 60)
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndThread
    Thread
        Call(N(PlayLakiluluFlightSounds), 80)
    EndThread
    ExecGetTID(N(EVS_Laklilulu_ManageYaw), LVar9)
    Call(LoadPath, 80, Ref(N(FlightPath_LakiluluArrives)), ARRAY_COUNT(N(FlightPath_LakiluluArrives)), EASING_LINEAR)
    Label(0)
    Call(GetNextPathPos)
    Call(SetNpcPos, NPC_Lakilulu, LVar1, LVar2, LVar3)
    Wait(1)
    IfEq(LVar0, 1)
        Goto(0)
    EndIf
    KillThread(LVar9)
    Call(SetNpcAnimation, NPC_Lakilulu, ANIM_Lakilulu_ConcernedNod)
    Call(SetPlayerAnimation, ANIM_Mario1_Still)
    Wait(20)
    Call(GetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamPitch, CAM_DEFAULT, Float(5.5), Float(-7.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00A4)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 40)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Shout, ANIM_Lakilulu_Shout, 0, MSG_CH6_00A5)
    Call(GetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Lakilester, ANIM_WorldLakilester_Shout, ANIM_WorldLakilester_IdleTough, 0, MSG_CH6_00A6)
    Call(SetNpcAnimation, NPC_Lakilester, ANIM_WorldLakilester_Idle)
    Call(EndSpeech, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 40)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 350)
    Call(SetCamSpeed, CAM_DEFAULT, Float(10.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Label(10)
    Call(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_ConcernedTalk, ANIM_Lakilulu_ConcernedNod, 0, MSG_CH6_00A7)
    Call(ShowChoice, MSG_Choice_0020)
    IfNe(LVar0, 0)
        ExecWait(N(EVS_Lakilulu_SpinyToss))
        Wait(10)
        Goto(10)
    Else
        Call(ContinueSpeech, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_00A9)
        Call(SetNpcAnimation, NPC_Lakilulu, ANIM_Lakilulu_Idle)
        Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
        Wait(10)
        Call(SetPlayerAnimation, ANIM_Mario1_Still)
        Wait(20)
        Call(GetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
        Add(LVar0, 20)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, 250)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(SpeakToPlayer, NPC_Lakilester, ANIM_WorldLakilester_Shout, ANIM_WorldLakilester_IdleTough, 0, MSG_CH6_00AA)
        Call(SetNpcAnimation, NPC_Lakilester, ANIM_WorldLakilester_Idle)
        Call(EndSpeech, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, 40)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, 350)
        Call(SetCamSpeed, CAM_DEFAULT, Float(5.0))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Wait(10)
        Call(SpeakToPlayer, NPC_Lakilester, ANIM_WorldLakilester_Shout, ANIM_WorldLakilester_IdleTough, 0, MSG_CH6_00AB)
        Wait(10)
        Call(ShowChoice, MSG_Choice_0021)
        Switch(LVar0)
            CaseEq(-1)
            CaseEq(0)
                Call(ContinueSpeech, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00AC)
            CaseEq(1)
                Call(ContinueSpeech, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00AD)
            CaseEq(2)
                Call(ContinueSpeech, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00AE)
            CaseEq(3)
                Call(ContinueSpeech, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00AF)
        EndSwitch
    EndIf
    Call(InterpNpcYaw, NPC_Lakilulu, 90, 1)
    Call(SetNpcAnimation, NPC_Lakilulu, ANIM_Lakilulu_ConcernedNod)
    Call(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_ConcernedTalk, ANIM_Lakilulu_ConcernedNod, 5, MSG_CH6_00B0)
    Call(SpeakToPlayer, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00B1)
    Wait(15)
    Call(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_ConcernedTalk, ANIM_Lakilulu_ConcernedNod, 5, MSG_CH6_00B2)
    Call(SpeakToPlayer, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00B3)
    Wait(10)
    Thread
        Call(ResetCam, CAM_DEFAULT, Float(90.0))
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Call(SetNpcSpeed, NPC_Lakilester, Float(3.5))
    Call(NpcMoveTo, NPC_Lakilester, LVar0, 60, 0)
    Call(N(ChangeNpcToPartner), 0, 8)
    Call(N(LoadPartyImage))
    Exec(N(EVS_PushPartnerSong))
    Wait(15)
    Call(ShowMessageAtScreenPos, MSG_Menus_0190, 160, 40)
    Exec(N(EVS_PopSong))
    Wait(10)
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Set(GB_StoryProgress, STORY_CH6_LAKILESTER_JOINED_PARTY)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, false)
    ExecWait(N(EVS_Lakilulu_FlyAway))
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Lakilester) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetNpcAnimation, NPC_SELF, ANIM_WorldLakilester_Tired)
            Call(SetCamType, CAM_DEFAULT, 6, true)
            Call(GetNpcPos, NPC_SELF, LVar3, LVar1, LVar2)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Add(LVar0, LVar3)
            Div(LVar0, 2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamDistance, CAM_DEFAULT, 300)
            Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-7.5))
            Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Exec(N(EVS_Scene_LakilesterDefeated))
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Lakilulu) = {
    IfLe(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        Call(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_0032)
    Else
        Call(GetCurrentPartnerID, LVar0)
        IfNe(LVar0, PARTNER_LAKILESTER)
            Call(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_0034)
        Else
            Call(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_0032)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Lakilester) = {
    IfLt(GB_StoryProgress, STORY_CH6_LAKILESTER_JOINED_PARTY)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Lakilester)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Lakilester)))
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Lakilulu) = {
    IfLt(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Lakilulu)))
        Call(SetNpcCollisionSize, NPC_SELF, 36, 28)
        IfGe(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            Call(SetNpcPos, NPC_SELF, -50, 180, -50)
        EndIf
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Lakilulu_Spiny) = {
    Call(SetNpcPos, NPC_Lakilulu_Spiny, NPC_DISPOSE_LOCATION)
    Call(SetNpcAnimation, NPC_Lakilulu_Spiny, ANIM_Lakilulu_Spiny)
    Return
    End
};

EvtScript N(EVS_NpcInit_Lakitu) = {
    IfEq(GB_StoryProgress, STORY_CH6_SPOKE_WITH_THE_SUN)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Spiny) = {
    IfEq(GB_StoryProgress, STORY_CH6_SPOKE_WITH_THE_SUN)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Call(SetSelfVar, 13, 1)
    Return
    End
};

NpcData N(NpcData_Lakilester) = {
    .id = NPC_Lakilester,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Lakilester),
    .settings = &N(NpcSettings_Lakilester),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DELAY_AFTER_FLEE,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_WorldLakilester_Idle,
        .walk   = ANIM_WorldLakilester_Idle,
        .run    = ANIM_WorldLakilester_Idle,
        .chase  = ANIM_WorldLakilester_Idle,
        .anim_4 = ANIM_WorldLakilester_Idle,
        .anim_5 = ANIM_WorldLakilester_Idle,
        .death  = ANIM_WorldLakilester_Idle,
        .hit    = ANIM_WorldLakilester_Idle,
        .anim_8 = ANIM_WorldLakilester_Idle,
        .anim_9 = ANIM_WorldLakilester_Idle,
        .anim_A = ANIM_WorldLakilester_Idle,
        .anim_B = ANIM_WorldLakilester_Idle,
        .anim_C = ANIM_WorldLakilester_Idle,
        .anim_D = ANIM_WorldLakilester_Idle,
        .anim_E = ANIM_WorldLakilester_Idle,
        .anim_F = ANIM_WorldLakilester_Idle,
    },
};

NpcData N(NpcData_Lakilulu) = {
    .id = NPC_Lakilulu,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Lakilulu),
    .settings = &N(NpcSettings_Lakilester),
    .flags = BASE_PASSIVE_FLAGS,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Lakilulu_Idle,
        .walk   = ANIM_Lakilulu_Idle,
        .run    = ANIM_Lakilulu_Idle,
        .chase  = ANIM_Lakilulu_Idle,
        .anim_4 = ANIM_Lakilulu_Idle,
        .anim_5 = ANIM_Lakilulu_Idle,
        .death  = ANIM_Lakilulu_Idle,
        .hit    = ANIM_Lakilulu_Idle,
        .anim_8 = ANIM_Lakilulu_Idle,
        .anim_9 = ANIM_Lakilulu_Idle,
        .anim_A = ANIM_Lakilulu_Idle,
        .anim_B = ANIM_Lakilulu_Idle,
        .anim_C = ANIM_Lakilulu_Idle,
        .anim_D = ANIM_Lakilulu_Idle,
        .anim_E = ANIM_Lakilulu_Idle,
        .anim_F = ANIM_Lakilulu_Idle,
    },
    .tattle = MSG_NpcTattle_Lakilulu,
};

NpcData N(NpcData_Lakilulu_Spiny) = {
    .id = NPC_Lakilulu_Spiny,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Lakilulu_Spiny),
    .settings = &N(NpcSettings_Lakilester),
    .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Lakilulu_Idle,
        .walk   = ANIM_Lakilulu_Idle,
        .run    = ANIM_Lakilulu_Idle,
        .chase  = ANIM_Lakilulu_Idle,
        .anim_4 = ANIM_Lakilulu_Idle,
        .anim_5 = ANIM_Lakilulu_Idle,
        .death  = ANIM_Lakilulu_Idle,
        .hit    = ANIM_Lakilulu_Idle,
        .anim_8 = ANIM_Lakilulu_Idle,
        .anim_9 = ANIM_Lakilulu_Idle,
        .anim_A = ANIM_Lakilulu_Idle,
        .anim_B = ANIM_Lakilulu_Idle,
        .anim_C = ANIM_Lakilulu_Idle,
        .anim_D = ANIM_Lakilulu_Idle,
        .anim_E = ANIM_Lakilulu_Idle,
        .anim_F = ANIM_Lakilulu_Idle,
    },
};

NpcData N(NpcData_Lakitu_01) = {
    .id = NPC_Lakitu_01,
    .pos = { 335.0f, 90.0f, 45.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 335, 90, 45 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 335, 90, 45 },
            .detectSize = { 250 },
        }
    },
    .init = &N(EVS_NpcInit_Lakitu),
    .settings = &N(NpcSettings_Lakitu_SpinySpawner),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = LAKITU_DROPS,
    .animations = LAKITU_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Lakitu_02) = {
    .id = NPC_Lakitu_02,
    .pos = { -320.0f, 90.0f, 0.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -320, 90, 0 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -320, 90, 0 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_Lakitu),
    .settings = &N(NpcSettings_Lakitu_SpinySpawner),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = LAKITU_DROPS,
    .animations = LAKITU_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_01) = {
    .id = NPC_Spiny_01,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_NpcInit_Spiny),
    .settings = &N(NpcSettings_SpawnedSpiny),
    .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_02) = {
    .id = NPC_Spiny_02,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_NpcInit_Spiny),
    .settings = &N(NpcSettings_SpawnedSpiny),
    .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_03) = {
    .id = NPC_Spiny_03,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_NpcInit_Spiny),
    .settings = &N(NpcSettings_SpawnedSpiny),
    .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_04) = {
    .id = NPC_Spiny_04,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_NpcInit_Spiny),
    .settings = &N(NpcSettings_SpawnedSpiny),
    .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_05) = {
    .id = NPC_Spiny_05,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_NpcInit_Spiny),
    .settings = &N(NpcSettings_SpawnedSpiny),
    .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_06) = {
    .id = NPC_Spiny_06,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_NpcInit_Spiny),
    .settings = &N(NpcSettings_SpawnedSpiny),
    .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Lakitu_01), 0x1A06, BTL_FLO_STAGE_04),
    NPC_GROUP(N(NpcData_Lakitu_02), 0x1A04, BTL_FLO_STAGE_04),
    NPC_GROUP(N(NpcData_Spiny_01), 0x1A0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_02), 0x1A0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_03), 0x1A0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_04), 0x1A0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_05), 0x1A0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_06), 0x1A0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Lakilester), 0x1B05, BTL_FLO2_STAGE_01),
    NPC_GROUP(N(NpcData_Lakilulu)),
    NPC_GROUP(N(NpcData_Lakilulu_Spiny)),
    {}
};
