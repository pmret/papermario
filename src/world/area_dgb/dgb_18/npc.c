#include "dgb_18.h"
#include "effects.h"
#include "sprite/player.h"

extern EvtScript N(EVS_NpcAI_Tubba_Chase);
extern EvtScript N(EVS_NpcAI_Tubba_WakeUp);

#include "world/common/enemy/TubbaBlubba_Patrol.inc.c"
#include "world/common/enemy/TubbaBlubba.inc.c"

#include "world/common/todo/UnkFunc1.inc.c"

API_CALLABLE(N(UnusedChasePlayer)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_unsafe(NPC_Tubba);
    f32 posX, posZ;

    if (isInitialCall) {
        posX = npc->pos.x;
        posZ = npc->pos.z;
        npc->moveSpeed = 3.7f;
        npc->yaw = atan2(posX, posZ, playerStatus->pos.x, playerStatus->pos.z);
        script->functionTemp[1] = 0;
        npc->duration = 15;
    }

    if (script->functionTemp[1] == 0) {
        if (npc->duration == 0) {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z);
            npc->duration = 15;
        }
        npc->duration--;
    }

    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    return ApiStatus_BLOCK;
}

NpcSettings N(NpcSettings_Yakkey) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_CLUBBA,
};

EvtScript N(EVS_Scene_TubbaFallsAsleep) = {
    Label(10)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        IfLt(LVar0, 700)
            Goto(10)
        EndIf
        IfGt(LVar2, 185)
            Goto(10)
        EndIf
    Call(DisablePlayerInput, true)
    Wait(10)
    Thread
        Wait(10)
        Call(InterpPlayerYaw, 270, 0)
    EndThread
    Call(FadeOutMusic, 0, 500)
    Loop(3)
        Call(SetPlayerAnimation, ANIM_MarioW2_JoltAwake)
        Call(PlaySoundAt, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT, 382, 0, 218)
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
        Wait(20)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        Wait(10)
    EndLoop
    Loop(2)
        Call(InterpPlayerYaw, 270, 0)
        Wait(10)
        Call(InterpPlayerYaw, 90, 0)
        Wait(10)
    EndLoop
    Call(UseSettingsFrom, CAM_DEFAULT, -40, 0, 180)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetPanTarget, CAM_DEFAULT, -40, 0, 180)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetPlayerPos, 740, 0, 180)
    Call(SetNpcPos, NPC_PARTNER, 765, 0, 180)
    Call(InterpPlayerYaw, 270, 0)
    Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
    Call(SetPlayerAnimation, ANIM_MarioW2_LookClosely)
    Call(PlaySoundAtCollider, COLLIDER_deilittw, SOUND_CREAKY_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 80, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o140, LVar0, 0, -1, 0)
        Call(RotateModel, MODEL_o141, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Thread
        Loop(3)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT)
            Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.3))
            Wait(5)
        EndLoop
    EndThread
    Call(SetMusic, 0, SONG_TUBBA_BLUBBA_THEME, 0, VOL_LEVEL_FULL)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim09)
    Call(SetNpcPos, NPC_SELF, -210, 0, 180)
    Call(NpcMoveTo, NPC_SELF, -60, 180, 30)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim06)
    Thread
        Call(MakeLerp, 80, 0, 10, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o140, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_o141, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySoundAtCollider, COLLIDER_deilittw, SOUND_CREAKY_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EndThread
    Wait(20)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldTubba_Anim10, ANIM_WorldTubba_Anim06, 5, MSG_CH3_00F4)
    Wait(20)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim09)
    Call(SetSelfVar, 0, 0)
    Thread
        Loop(0)
            Call(GetSelfVar, 0, LVar0)
            IfEq(LVar0, 1)
                BreakLoop
            EndIf
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT)
            Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.3))
            Wait(9)
            Call(GetSelfVar, 0, LVar0)
            IfEq(LVar0, 1)
                BreakLoop
            EndIf
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_HEAVY_NPC_STEP_C, SOUND_SPACE_DEFAULT)
            Call(ShakeCam, CAM_DEFAULT, 0, 2, Float(0.15))
            Wait(12)
        EndLoop
    EndThread
    Thread
        Loop(0)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Wait(1)
            Call(GetSelfVar, 0, LVar0)
            IfEq(LVar0, 1)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(SetNpcSpeed, NPC_SELF, Float(4.0))
    Call(NpcMoveTo, NPC_SELF, 45, 215, 0)
    Call(NpcMoveTo, NPC_SELF, 140, 245, 0)
    Call(NpcMoveTo, NPC_SELF, 615, 245, 0)
    Call(SetSelfVar, 0, 1)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim06)
    Wait(15)
    Wait(20)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldTubba_Anim10, ANIM_WorldTubba_Anim06, 5, MSG_CH3_00F5)
    Wait(20)
    Thread
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim14)
        Wait(5)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim15)
        Wait(5)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim16)
        Wait(5)
    EndThread
    Wait(5)
    Call(SetNpcJumpscale, NPC_SELF, Float(0.7))
    Call(NpcJump0, NPC_SELF, 600, 50, 115, 20)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.3))
    EndThread
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim05)
    Call(SetNpcScale, NPC_SELF, Float(1.25), Float(1.2), Float(1.25))
    Wait(1)
    Call(SetNpcScale, NPC_SELF, Float(1.35), Float(1.15), Float(1.25))
    Wait(1)
    Call(SetNpcScale, NPC_SELF, Float(1.45), Float(1.05), Float(1.25))
    Wait(1)
    Call(SetNpcScale, NPC_SELF, Float(1.35), Float(1.15), Float(1.25))
    Wait(1)
    Call(SetNpcScale, NPC_SELF, Float(1.25), Float(1.2), Float(1.25))
    Wait(1)
    Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    Thread
        Call(SetNpcJumpscale, NPC_SELF, Float(0.5))
        Call(NpcJump0, NPC_SELF, LVar3, 30, LVar5, 23)
    EndThread
    Wait(2)
    Thread
        Call(MakeLerp, 0, 50, 18, EASING_QUADRATIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotationPivot, NPC_SELF, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(MakeLerp, 0, -90, 18, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_SELF, 0, 0, LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(0.4))
    EndThread
    Wait(5)
    Call(FadeOutMusic, 0, 1000)
    Call(SetNpcScale, NPC_SELF, Float(1.25), Float(1.25), Float(1.25))
    Call(SetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    Call(SetNpcRotationPivot, NPC_SELF, 0)
    Call(SetNpcRotation, NPC_SELF, 0, 0, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim02)
    Wait(15)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim24)
    Wait(30)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_SNORE_INHALE, SOUND_SPACE_DEFAULT)
    Wait(30)
    Thread
        Call(SetSelfVar, 1, 0)
        Loop(0)
            Call(GetSelfVar, 1, LVar0)
            IfEq(LVar0, 1)
                BreakLoop
            EndIf
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_SNORE_EXHALE, SOUND_SPACE_DEFAULT)
            Call(RandInt, 10, LVar1)
            Add(LVar1, 15)
            Call(ShowSleepBubble, NPC_Tubba, 0, 0, 2, 628, 121, 127, LVar1, LVar0)
            Wait(48)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_SNORE_INHALE, SOUND_SPACE_DEFAULT)
            Call(RandInt, 10, LVar1)
            Add(LVar1, 10)
            Call(SetSleepBubbleTimeLeft, LVar0, LVar1)
            Wait(30)
        EndLoop
    EndThread
    Wait(30)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Set(GB_StoryProgress, STORY_CH3_TUBBA_BEGAN_NAPPING)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Tubba_Asleep) = {
    Call(SetNpcScale, NPC_SELF, Float(1.25), Float(1.25), Float(1.25))
    Call(SetNpcPos, NPC_SELF, 600, 50, 115)
    Call(SetNpcRotationPivot, NPC_SELF, 0)
    Call(SetNpcRotation, NPC_SELF, 0, 0, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim02)
    Wait(15)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim24)
    Wait(30)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_SNORE_INHALE, SOUND_SPACE_DEFAULT)
    Wait(30)
    Thread
        Call(SetSelfVar, 1, 0)
        Loop(0)
            Call(GetSelfVar, 1, LVar0)
            IfEq(LVar0, 1)
                BreakLoop
            EndIf
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_SNORE_EXHALE, SOUND_SPACE_DEFAULT)
            Call(RandInt, 10, LVar1)
            Add(LVar1, 15)
            Call(ShowSleepBubble, NPC_Tubba, 0, 0, 2, 628, 121, 127, LVar1, LVar0)
            Wait(48)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_SNORE_INHALE, SOUND_SPACE_DEFAULT)
            Call(RandInt, 10, LVar1)
            Add(LVar1, 10)
            Call(SetSleepBubbleTimeLeft, LVar0, LVar1)
            Wait(30)
        EndLoop
    EndThread
    Return
    End
};

EvtScript N(EVS_NpcAI_Tubba_WakeUp) = {
    SetGroup(EVT_GROUP_HOSTILE_NPC)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_SNORE_EXHALE, SOUND_SPACE_DEFAULT)
    Call(ShowSleepBubble, NPC_Tubba, 0, 50, 2, 552, 111, 128, 30, LVar0)
    Wait(360)
    Call(SetSleepBubbleTimeLeft, LVar0, 20)
    Call(SetNpcVar, NPC_SELF, 1, 2)
    Wait(20)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_SNAP_AWAKE_A, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim19)
    Wait(30)
    Thread
        Call(NpcJump0, NPC_SELF, 650, 0, 250, 25)
    EndThread
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim1A)
    Wait(10)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim1B)
    Wait(12)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim1C)
    Wait(5)
    Call(BindNpcAI, NPC_Tubba, Ref(N(EVS_NpcAI_Tubba_Chase)))
    Return
    End
};

EvtScript N(EVS_NpcAI_Tubba_Chase) = {
    SetGroup(EVT_GROUP_HOSTILE_NPC)
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim0D)
    Thread
        Loop(0)
            Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(2.0))
            Wait(5)
            Call(ShakeCam, CAM_DEFAULT, 0, 2, Float(1.0))
            Wait(8)
        EndLoop
    EndThread
    Call(N(PatrolNoAttackAI_Main), Ref(N(AISettings_Tubba_Patrol)))
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Tubba) = {
    Call(N(UnkFunc1))
    Call(GotoMap, Ref("dgb_01"), dgb_01_ENTRY_6)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_NpcInit_Tubba) = {
    Call(SetNpcScale, NPC_SELF, Float(1.25), Float(1.25), Float(1.25))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Tubba)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_BEGAN_NAPPING)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_Scene_TubbaFallsAsleep)))
        CaseLt(STORY_CH3_TUBBA_WOKE_UP)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Tubba_Asleep)))
        CaseLt(STORY_CH3_TUBBA_SMASHED_THE_BRIDGES)
            Call(SetNpcPos, NPC_SELF, 245, 0, 250)
            Call(SetNpcYaw, NPC_SELF, 270)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcAI_Tubba_Chase)))
        CaseLt(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Scene_YakkeyShouts) = {
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, true)
    Wait(40)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
    Call(SetNpcPos, NPC_SELF, 845, 0, 140)
    Call(SetNpcJumpscale, NPC_SELF, Float(0.8))
    Call(NpcJump1, NPC_SELF, 845, 35, 145, 15)
    Call(PlayerFaceNpc, NPC_SELF, false)
    Wait(15)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPosB, CAM_DEFAULT, 800, 245)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 5, MSG_CH3_00F6)
    Wait(15)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 5, MSG_CH3_00F7)
    Call(ShowChoice, MSG_Choice_000D)
    IfEq(LVar0, 0)
        Call(ContinueSpeech, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 0, MSG_CH3_00F8)
    Else
        Call(ContinueSpeech, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 0, MSG_CH3_00F9)
    EndIf
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(UseSettingsFrom, CAM_DEFAULT, 740, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 600)
    Call(SetCamPosB, CAM_DEFAULT, 800, 245)
    Call(SetPanTarget, CAM_DEFAULT, 740, LVar1, LVar2)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Set(MF_Sync_YakkeyDialogue, false)
#if VERSION_JP
        Call(ShowMessageAtScreenPos, MSG_CH3_00FA, 160, 40)
#else
        Call(SpeakToPlayer, NPC_SELF, ANIM_Yakkey_Talk, ANIM_Yakkey_Idle, 517, MSG_CH3_00FA)
#endif
        Set(MF_Sync_YakkeyDialogue, true)
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Loop(0)
        Call(SetCamDistance, CAM_DEFAULT, Float(550.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(SetPanTarget, CAM_DEFAULT, 740, LVar1, LVar2)
        Wait(1)
        Call(SetCamDistance, CAM_DEFAULT, Float(600.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(SetPanTarget, CAM_DEFAULT, 740, LVar1, LVar2)
        Wait(1)
        IfEq(MF_Sync_YakkeyDialogue, true)
            BreakLoop
        EndIf
    EndLoop
    Call(SetMusic, 0, SONG_TUBBA_ESCAPE, 0, VOL_LEVEL_FULL)
    Call(SetNpcVar, NPC_Tubba, 1, 1)
    Wait(15)
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim25)
    Thread
        Loop(0)
            Call(GetNpcVar, NPC_Tubba, 1, LVar0)
            IfEq(LVar0, 2)
                BreakLoop
            EndIf
            Call(RandInt, 40, LVar0)
            Call(RandInt, 40, LVar1)
            Add(LVar0, 537)
            Add(LVar1, 110)
            PlayEffect(EFFECT_SMOKE_BURST, 2, LVar0, LVar1, 128, Float(0.3), 24)
            Wait(5)
        EndLoop
    EndThread
    Wait(15)
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim05)
    Call(SpeakToPlayer, NPC_Tubba, ANIM_WorldTubba_Anim13, ANIM_WorldTubba_Anim05, 5, MSG_CH3_00FB)
    Wait(15)
    Call(DisablePartnerAI, 0)
    Call(GetCurrentPartnerID, LVar0)
    Switch(LVar0)
        CaseEq(PARTNER_GOOMBARIO)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH3_00FC)
        CaseEq(PARTNER_KOOPER)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH3_00FD)
        CaseEq(PARTNER_BOMBETTE)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH3_00FE)
        CaseEq(PARTNER_PARAKARRY)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH3_00FF)
        CaseEq(PARTNER_BOW)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_0100)
    EndSwitch
    Call(EnablePartnerAI)
    Wait(15)
    Call(BindNpcAI, NPC_Tubba, Ref(N(EVS_NpcAI_Tubba_WakeUp)))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
    Sub(LVar1, 10)
    Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Set(GB_StoryProgress, STORY_CH3_TUBBA_WOKE_UP)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_NpcInit_Yakkey) = {
    Call(SetSelfVar, 0, 0)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_Scene_YakkeyShouts)))
    Return
    End
};

NpcData N(NpcData_Tubba) = {
    .id = NPC_Tubba,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 5,
            .points  = {
                { 0, 0, 240 },
                { 175, 0, 240 },
                { 350, 0, 240 },
                { 525, 0, 240 },
                { 700, 0, 240 },
            },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 300, 0, 240 },
            .detectSize = { 1000, 250 },
        }
    },
    .init = &N(EVS_NpcInit_Tubba),
    .settings = &N(NpcSettings_TubbaBlubba),
    .flags = ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = TUBBA_ANGRY_ANIMS,
};

NpcData N(NpcData_Yakkey) = {
    .id = NPC_Yakkey,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Yakkey),
    .settings = &N(NpcSettings_Yakkey),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Yakkey_Idle,
        .walk   = ANIM_Yakkey_Idle,
        .run    = ANIM_Yakkey_Idle,
        .chase  = ANIM_Yakkey_Idle,
        .anim_4 = ANIM_Yakkey_Idle,
        .anim_5 = ANIM_Yakkey_Idle,
        .death  = ANIM_Yakkey_Idle,
        .hit    = ANIM_Yakkey_Idle,
        .anim_8 = ANIM_Yakkey_Idle,
        .anim_9 = ANIM_Yakkey_Idle,
        .anim_A = ANIM_Yakkey_Idle,
        .anim_B = ANIM_Yakkey_Idle,
        .anim_C = ANIM_Yakkey_Idle,
        .anim_D = ANIM_Yakkey_Idle,
        .anim_E = ANIM_Yakkey_Idle,
        .anim_F = ANIM_Yakkey_Idle,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Tubba), BTL_DGB_FORMATION_04),
    NPC_GROUP(N(NpcData_Yakkey)),
    {}
};
