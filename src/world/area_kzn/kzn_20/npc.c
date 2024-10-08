#include "kzn_20.h"
#include "effects.h"
#include "sprite/player.h"

enum {
    SCENE_STATE_BEGIN                   = 15,
    SCENE_STATE_STARFISH_REMARK         = 20,
    SCENE_STATE_KOLORADO_LOOKS_AROUND   = 25,
    SCENE_STATE_KOLORADO_WENT_BACK      = 30,
    SCENE_STATE_KOLORADO_CAM_SYNC       = 31,
    SCENE_STATE_KOLORADO_WARNED         = 35,
    SCENE_STATE_KOLORADO_BURNED         = 36,
    SCENE_STATE_MISSTAR_SPEAKS          = 40,
    SCENE_STATE_KOLORADO_RETURN         = 45,
    SCENE_STATE_SEARCH_FOR_EXIT         = 50,
    SCENE_STATE_DONE                    = -1,
};

#include "world/common/npc/Kolorado.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EVT_LETTER_PROMPT(Kolorado, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
    MSG_CH5_00E4, MSG_CH5_00E5, MSG_CH5_00E6, MSG_CH5_00E7,
    ITEM_LETTER_TO_KOLORADO, N(LetterList));

EVT_LETTER_REWARD(Kolorado);

EvtScript N(EVS_SpawnFallingDust) = {
    SetGroup(EVT_GROUP_HOSTILE_NPC)
    Loop(0)
        Call(RandInt, 100, LVar0)
        Sub(LVar0, 100)
        PlayEffect(EFFECT_DUST, 1, LVar0, 350, 0, 60)
        Call(RandInt, 100, LVar0)
        Wait(30)
        PlayEffect(EFFECT_DUST, 1, LVar0, 350, 0, 60)
        Wait(30)
    EndLoop
    Return
    End
};

EvtScript N(EVS_ShakingWorld) = {
    SetGroup(EVT_GROUP_PASSIVE_NPC)
    IfGe(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
        Exec(N(EVS_SpawnFallingDust))
    Else
        Loop(0)
            Call(ShakeCam, CAM_DEFAULT, 0, 2, Float(0.5))
            IfNe(AF_KZN_RumblingIntensified, FALSE)
                BreakLoop
            EndIf
        EndLoop
        Exec(N(EVS_SpawnFallingDust))
        Call(MakeLerp, 20, 250, 5, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            DivF(LVar0, Float(100.0))
            Call(ShakeCam, CAM_DEFAULT, 0, 3, LVar0)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, 250, 30, 60, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            DivF(LVar0, Float(100.0))
            Call(ShakeCam, CAM_DEFAULT, 0, 5, LVar0)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndIf
    Loop(0)
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.5))
    EndLoop
    Return
    End
};

s32 N(Kolorado_Wander1)[] = {
    // speed, moveToX, moveToZ, loiter time
    2,  -75, 195, 35,
    2,  -60, 175, 25,
    1,  -95, 165, 15,
    1, -110, 120, 35,
    -1,
};

s32 N(Kolorado_Wander2)[] = {
    // speed, moveToX, moveToZ, loiter time
    1,  -25, 195, 20,
    2,  -75, 195, 35,
    1,  -60, 175, 25,
    2, -120, 140, 15,
    -1,
};

EvtScript N(EVS_Kolorado_CalmIdle) = {
    SetGroup(EVT_GROUP_NOT_BATTLE)
    Label(0)
    Call(RandInt, 1, LVar1)
    IfEq(LVar1, 0)
        UseBuf(N(Kolorado_Wander1))
    Else
        UseBuf(N(Kolorado_Wander2))
    EndIf
    Label(10)
        BufRead3(LVar1, LVar2, LVar3)
        IfEq(LVar1, -1)
            Goto(0)
        EndIf
        Call(SetNpcSpeed, NPC_Kolorado, LVar1)
        Call(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Walk)
        Call(NpcMoveTo, NPC_Kolorado, LVar2, LVar3, 0)
        BufRead1(LVar2)
        Call(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Idle)
        Wait(5)
        Call(RandInt, 2, LVar4)
        Add(LVar4, 1)
        Loop(LVar4)
            Call(GetNpcYaw, NPC_Kolorado, LVar5)
            Add(LVar5, 180)
            IfGt(LVar5, 360)
                Sub(LVar5, 360)
            EndIf
            Call(InterpNpcYaw, NPC_Kolorado, LVar5, 1)
            Wait(20)
        EndLoop
        Wait(LVar2)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_KoloradoBurned_PlayerReaction) = {
    Call(GetPlayerPos, LVar0, LVar3, LVar2)
    Add(LVar3, 30)
    Loop(0)
        Wait(1)
        Call(GetNpcPos, NPC_Kolorado, LVar0, LVar1, LVar2)
        IfGt(LVar1, LVar3)
            BreakLoop
        EndIf
    EndLoop
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Loop(0)
        Wait(1)
        Call(GetNpcPos, NPC_Kolorado, LVar0, LVar1, LVar2)
        IfLt(LVar1, LVar3)
            BreakLoop
        EndIf
    EndLoop
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Return
    End
};

API_CALLABLE(N(func_80240A68_C96998)) {
    snd_ambient_mute(0, TRUE);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_Kolorado) = {
    ExecGetTID(N(EVS_Kolorado_CalmIdle), LVar9)
    // wait for scene to begin
    Label(0)
        Wait(1)
        IfNe(MV_SceneState, SCENE_STATE_BEGIN)
            Goto(0)
        EndIf
    KillThread(LVar9)
    Wait(10)
    // cutscene actions
    Label(10)
        Switch(MV_SceneState)
            CaseEq(SCENE_STATE_BEGIN)
                Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
                Call(InterpNpcYaw, NPC_SELF, 90, 1)
                Call(SetNpcPos, NPC_SELF, -30, 100, 40)
                Call(SetNpcJumpscale, NPC_SELF, Float(2.0))
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
                Call(NpcJump0, NPC_SELF, -25, 125, -20, 10)
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
                Call(NpcJump0, NPC_SELF, 20, 150, 5, 10)
                Call(SetNpcSpeed, NPC_SELF, Float(3.0))
                Call(NpcMoveTo, NPC_SELF, 40, 35, 0)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_010A)
                Set(MV_SceneState, SCENE_STATE_STARFISH_REMARK)
            CaseEq(SCENE_STATE_KOLORADO_LOOKS_AROUND)
                Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
                Call(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
                Add(LVar3, -30)
                Call(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
                Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
                Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
                Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
                Call(InterpNpcYaw, NPC_SELF, 270, 4)
                Wait(10)
                Call(InterpNpcYaw, NPC_SELF, 90, 4)
                Wait(10)
                Call(InterpNpcYaw, NPC_SELF, 270, 4)
                Wait(10)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
                Call(SetNpcSpeed, NPC_SELF, Float(2.0))
                Call(NpcMoveTo, NPC_SELF, 20, 0, 0)
                Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
                Call(NpcJump0, NPC_SELF, -35, 125, -20, 12)
                Call(PlayerFaceNpc, NPC_SELF, FALSE)
                Call(SetNpcSpeed, NPC_SELF, Float(1.0))
                Label(25)
                Call(NpcMoveTo, NPC_SELF, -15, -20, 0)
                Call(NpcMoveTo, NPC_SELF, -40, -20, 0)
                IfEq(AF_KZN20_SceneSync, FALSE)
                    Wait(1)
                    Goto(25)
                EndIf
                Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 5, MSG_CH5_010B)
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
                Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 15, EMOTER_NPC, 0, 0, 0, 0)
                Wait(15)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
                Call(SetNpcJumpscale, NPC_SELF, Float(1.5))
                Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
                Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
                Call(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 8)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
                Thread
                    Wait(8)
                    Call(NpcFacePlayer, NPC_SELF, 0)
                EndThread
                Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 5, MSG_CH5_010C)
                Set(AF_KZN_RumblingIntensified, TRUE)
                Call(SetMusicTrack, 0, SONG_VOLCANO_ESCAPE, 0, 8)
                Wait(20)
                Thread
                    Call(SetPlayerAnimation, ANIM_Mario1_Flail)
                    Wait(60)
                    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
                EndThread
                Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Yell)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_010D)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
                Call(SetNpcJumpscale, NPC_SELF, Float(2.0))
                Set(MV_SceneState, SCENE_STATE_KOLORADO_WENT_BACK)
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
                Call(NpcJump0, NPC_SELF, -30, 100, 40, 10)
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
                Call(NpcJump0, NPC_SELF, -15, 75, 80, 10)
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
                Call(NpcJump0, NPC_SELF, 35, 50, 120, 10)
            CaseEq(SCENE_STATE_KOLORADO_WARNED)
                Call(N(func_80240A68_C96998))
                Exec(N(EVS_KoloradoBurned_PlayerReaction))
                Thread
                    Call(PlayerFaceNpc, NPC_SELF, FALSE)
                    Call(ShowMessageAtScreenPos, MSG_CH5_010F, 160, 40)
                EndThread
                Thread
                    Loop(0)
                        Wait(1)
                        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                        Add(LVar2, -10)
                        PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, 1, 10)
                        IfEq(MV_SceneState, SCENE_STATE_KOLORADO_BURNED)
                            BreakLoop
                        EndIf
                    EndLoop
                EndThread
                Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Hurt)
                Call(SetNpcJumpscale, NPC_SELF, Float(0.8))
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_TOUCH_LAVA, SOUND_SPACE_DEFAULT)
                Call(NpcJump1, NPC_SELF, LVar0, LVar1, LVar2, 60)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
                Set(MV_SceneState, SCENE_STATE_KOLORADO_BURNED)
                Call(UseSettingsFrom, CAM_DEFAULT, 100, 25, 100)
                Call(SetPanTarget, CAM_DEFAULT, 100, 25, 100)
                Call(SetCamDistance, CAM_DEFAULT, Float(450.0))
                Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-7.0))
                Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
                Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
                Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Panic, ANIM_Kolorado_Panic, 0, MSG_CH5_0110)
                Call(ResetCam, CAM_DEFAULT, Float(90.0))
                Set(MV_SceneState, SCENE_STATE_MISSTAR_SPEAKS)
            CaseEq(SCENE_STATE_KOLORADO_RETURN)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
                Call(SetNpcPos, NPC_SELF, -30, 100, 40)
                Call(SetNpcJumpscale, NPC_SELF, Float(2.0))
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
                Call(NpcJump0, NPC_SELF, -25, 125, -20, 10)
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
                Call(NpcJump0, NPC_SELF, 20, 150, 5, 8)
                Set(MV_SceneState, SCENE_STATE_SEARCH_FOR_EXIT)
                Call(SetNpcSpeed, NPC_SELF, Float(3.0))
                Call(NpcMoveTo, NPC_SELF, 75, -30, 0)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
                Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EndSwitch
        Wait(1)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    IfLt(LVar1, 100)
        Call(EnableNpcAI, NPC_SELF, FALSE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0108)
        EVT_LETTER_CHECK(Kolorado)
        Call(EnableNpcAI, NPC_SELF, TRUE)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_0113)
        EVT_LETTER_CHECK(Kolorado)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    IfLt(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kolorado)))
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kolorado)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

Vec3f N(FlightPath1)[] = {
    { -120.0,  70.0, 45.0 },
    {  -75.0,  80.0, 90.0 },
    {  -10.0, 115.0, 90.0 },
    {   10.0, 180.0, 70.0 },
    {   50.0, 210.0, 30.0 },
    {  100.0, 160.0,  0.0 },
};

Vec3f N(FlightPath2)[] = {
    { 145.0, 195.0, -10.0 },
    { 100.0, 190.0, -90.0 },
    {  80.0, 180.0, -60.0 },
    { 115.0, 175.0, -40.0 },
    { 165.0, 170.0, -10.0 },
    { 230.0, 170.0, -20.0 },
    { 270.0, 175.0, -30.0 },
};

API_CALLABLE(N(GetFloorCollider)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, gCollisionStatus.curFloor);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_Misstar) = {
    IfEq(AF_KZN20_MisstarFlightDone, FALSE)
        Call(SetNpcPos, NPC_SELF, -120, 70, 45)
        Wait(30)
        Set(AF_KZN20_MisstarFlightDone, TRUE)
        Call(InterpNpcYaw, NPC_SELF, 90, 0)
        Call(LoadPath, 60, Ref(N(FlightPath1)), ARRAY_COUNT(N(FlightPath1)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
            Wait(1)
            IfNe(LVar0, 1)
                BreakLoop
            EndIf
        EndLoop
        Call(InterpNpcYaw, NPC_SELF, 270, 0)
    EndIf
    // wait for player to reach the top of the stairs
    Label(0)
        Call(N(GetFloorCollider), LVar0)
        IfNe(LVar0, COLLIDER_o870)
            Wait(1)
            Goto(0)
        EndIf
    Call(DisablePlayerInput, TRUE)
    Wait(10)
    Thread
        Wait(10)
        Call(SetPlayerSpeed, Float(2.0))
        Call(PlayerMoveTo, 60, 0, 0)
    EndThread
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Set(AF_KZN_RumblingIntensified, FALSE)
    Set(MV_SceneState, SCENE_STATE_BEGIN)
    Label(10)
        Switch(MV_SceneState)
            CaseEq(SCENE_STATE_STARFISH_REMARK)
                Set(AF_KZN20_SceneSync, FALSE)
                Thread
                    Wait(30)
                    Set(MV_SceneState, SCENE_STATE_KOLORADO_LOOKS_AROUND)
                EndThread
                Set(AF_KZN20_SceneSync, TRUE)
            CaseEq(SCENE_STATE_KOLORADO_WENT_BACK)
                Thread
                    Call(GetPlayerPos, LVar0, LVar1, LVar2)
                    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
                    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
                    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
                    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                    Set(MV_SceneState, SCENE_STATE_KOLORADO_CAM_SYNC)
                EndThread
                Wait(10)
                Call(SpeakToPlayer, NPC_SELF, ANIM_WorldMisstar_TalkAngry, ANIM_WorldMisstar_IdleAngry, 5, MSG_CH5_010E)
                Label(30)
                    IfEq(MV_SceneState, SCENE_STATE_KOLORADO_WENT_BACK)
                        Wait(1)
                        Goto(30)
                    EndIf
                Set(MV_SceneState, SCENE_STATE_KOLORADO_WARNED)
            CaseEq(SCENE_STATE_MISSTAR_SPEAKS)
                Call(SpeakToPlayer, NPC_SELF, ANIM_WorldMisstar_TalkAngry, ANIM_WorldMisstar_IdleAngry, 0, MSG_CH5_0111)
                Set(MV_SceneState, SCENE_STATE_KOLORADO_RETURN)
            CaseEq(SCENE_STATE_SEARCH_FOR_EXIT)
                Call(InterpNpcYaw, NPC_SELF, 90, 0)
                Wait(15)
                Call(InterpNpcYaw, NPC_SELF, 270, 0)
                Wait(15)
                Call(InterpNpcYaw, NPC_SELF, 90, 0)
                Wait(15)
                Call(SetNpcSpeed, NPC_SELF, Float(3.0))
                Call(NpcMoveTo, NPC_SELF, 145, -10, 0)
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
                Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 15, EMOTER_NPC, 0, 0, 0, 0)
                Wait(20)
                Call(SetNpcRotation, NPC_SELF, 0, -30, 0)
                Call(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_Back)
                Call(SetNpcJumpscale, NPC_SELF, 0)
                Call(NpcJump0, NPC_SELF, 170, 170, 50, 20)
                Wait(5)
                Call(SetNpcRotation, NPC_SELF, 0, -60, 0)
                Call(SetNpcYaw, NPC_SELF, 270)
                Call(NpcJump0, NPC_SELF, 145, 170, -10, 15)
                Wait(10)
                Call(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_IdleAngry)
                Call(SetNpcRotation, NPC_SELF, 0, 0, 0)
                Call(NpcJump1, NPC_SELF, 145, 160, -10, 5)
                Call(SpeakToPlayer, NPC_SELF, ANIM_WorldMisstar_TalkAngry, ANIM_WorldMisstar_IdleAngry, 0, MSG_CH5_0112)
                Call(NpcFacePlayer, NPC_SELF, 0)
                Set(MV_SceneState, SCENE_STATE_DONE)
        EndSwitch
        IfNe(MV_SceneState, SCENE_STATE_DONE)
            Wait(1)
            Goto(10)
        EndIf
    Call(DisablePlayerInput, FALSE)
    Label(90)
        IfLt(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
            Wait(1)
            Goto(90)
        EndIf
    Call(DisablePlayerInput, TRUE)
    Wait(40)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    Thread
        Call(SetNpcFlagBits, NPC_Kolorado, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Panic)
        Call(SetNpcSpeed, NPC_Kolorado, Float(5.0))
        Call(NpcMoveTo, NPC_Kolorado, 305, 0, 0)
        Call(RemoveNpc, NPC_Kolorado)
    EndThread
    Wait(30)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcJumpscale, NPC_SELF, Float(0.5))
    Call(NpcJump0, NPC_SELF, 145, 195, -10, 5)
    Wait(5)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldMisstar_Panic, ANIM_WorldMisstar_IdleAngry, 0, MSG_CH5_0115)
    Wait(5)
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Call(LoadPath, 30, Ref(N(FlightPath2)), ARRAY_COUNT(N(FlightPath2)), EASING_LINEAR)
    Label(91)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(91)
        EndIf
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Misstar) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldMisstar_TalkAngry, ANIM_WorldMisstar_IdleAngry, 0, MSG_CH5_0114)
    Return
    End
};

EvtScript N(EVS_NpcInit_Misstar) = {
    IfEq(GB_StoryProgress, STORY_CH5_MT_LAVA_LAVA_ERUPTING)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_IdleAngry)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_Scene_Misstar)))
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Misstar)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { -65.0f, 0.0f, 190.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_RAYCAST_TO_INTERACT | ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = NO_DROPS,
    .animations = KOLORADO_ANIMS,
    .tattle = MSG_NpcTattle_Kolorado,
};

NpcData N(NpcData_Misstar) = {
    .id = NPC_Misstar,
    .pos = { 100.0f, 160.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Misstar),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = NO_DROPS,
    .animations = MISSTAR_ANIMS,
    .tattle = MSG_NpcTattle_Misstar,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_Misstar)),
    {}
};
