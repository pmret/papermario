#include "trd_00.h"
#include "effects.h"
#include "sprite/player.h"

extern EvtScript N(EVS_SetupMusic);

API_CALLABLE(N(UpgradeStarPowerCh1)) {
    set_max_star_power(1);
    gPlayerData.curHP = gPlayerData.curMaxHP;
    gPlayerData.curFP = gPlayerData.curMaxFP;
    sync_status_bar();
    return ApiStatus_DONE2;
}

#include "world/common/todo/SyncStatusBar.inc.c"

NpcSettings N(NpcSettings_KoopaBros) = {
    .height = 34,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#include "world/common/npc/StarSpirit.inc.c"

EvtScript N(EVS_NpcIdle_KoopaBros) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    Call(AwaitPlayerApproach, -580, 276, 50)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
    Thread
        Call(PlaySoundAtCollider, COLLIDER_tt2, SOUND_METAL_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        Call(MakeLerp, 0, 100, 10, EASING_COS_IN_OUT)
        Label(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o62, LVar0, 0, -1, 0)
        Call(RotateModel, MODEL_doa, LVar0, 0, 1, 0)
        Wait(1)
        IfNe(LVar1, 0)
            Goto(0)
        EndIf
    EndThread
    Call(DisablePlayerInput, TRUE)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, 350)
        Call(SetPanTarget, CAM_DEFAULT, -570, 0, 173)
        Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
        Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    EndThread
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_Run)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Call(SetNpcSpeed, NPC_SELF, Float(4.5 / DT))
    Call(NpcMoveTo, NPC_SELF, -556, 180, 0)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_ANIM, IMGFX_ANIM_STARTLE, 2, 1, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_Shock)
    Wait(12 * DT)
    Call(SetNpcImgFXParams, NPC_SELF, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_Idle)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_SELF, ANIM_KoopaBros_Black_Talk, ANIM_KoopaBros_Black_Idle, 0, MSG_CH1_00D2)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_Walk)
    Call(InterpNpcYaw, NPC_SELF, 45, 2)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_RUN_AWAY_BUILDUP, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_Run)
    Call(SetNpcJumpscale, NPC_SELF, Float(0.8))
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 8 * DT)
    Wait(8 * DT)
    Wait(12 * DT)
    Thread
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_RUN_AWAY, SOUND_SPACE_DEFAULT)
        Call(SetNpcSpeed, NPC_SELF, Float(8.0 / DT))
        Call(NpcMoveTo, NPC_SELF, -496, 101, 0)
    EndThread
    Wait(10 * DT)
    Thread
        Wait(8)
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
    EndThread
    Call(MakeLerp, 100, 0, 10, EASING_COS_IN_OUT)
    Label(1)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_o62, LVar0, 0, -1, 0)
    Call(RotateModel, MODEL_doa, LVar0, 0, 1, 0)
    Wait(1)
    IfNe(LVar1, 0)
        Goto(1)
    EndIf
    Call(PlaySoundAtCollider, COLLIDER_tt2, SOUND_METAL_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Wait(10 * DT)
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.5 / DT))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(DisablePlayerInput, FALSE)
    Set(GB_StoryProgress, STORY_CH1_SPOTTED_BY_KOOPA_BROS)
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopaBros) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_KoopaBros)))
    IfGe(GB_StoryProgress, STORY_CH1_SPOTTED_BY_KOOPA_BROS)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcIdle_Eldstar) = {
    Loop(0)
        Loop(10)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Sub(LVar1, 1)
            Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
        Loop(10)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 1)
            Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Eldstar) = {
    Call(SetSelfVar, 0, 1)
    Return
    End
};

EvtScript N(D_80241DA4_99BA14) = {
    Call(DisablePartnerAI, 0)
    Call(func_802CF56C, 2)
    Call(SetNpcPos, NPC_Eldstar, -567, 26, 236)
    Call(PlayerFaceNpc, NPC_Eldstar, FALSE)
    Call(NpcFaceNpc, NPC_PARTNER, NPC_Eldstar, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, -527, 0, 216)
    Call(SetPanTarget, CAM_DEFAULT, -527, 0, 216)
    Call(SetCamDistance, CAM_DEFAULT, Float(475.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(1)
    Call(WaitForPlayerInputEnabled)
    Call(DisablePlayerInput, TRUE)
    Wait(40 * DT)
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH1_010D)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(18.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(MakeLerp, 0, 360, 10 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_Eldstar, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(EnableNpcAI, NPC_Eldstar, FALSE)
    Call(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Leap)
    Wait(20 * DT)
    Call(PlaySoundAtPlayer, SOUND_RECEIVE_STAR_POWER, SOUND_SPACE_DEFAULT)
    Call(SetPlayerAnimation, ANIM_Mario1_UsePower)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Set(LVar3, LVar1)
    Add(LVar0, 5)
    Add(LVar1, 50)
    Add(LVar2, 10)
    Add(LVar3, 30)
    Loop(6)
        PlayEffect(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 20)
        Wait(6 * DT)
        PlayEffect(EFFECT_SPARKLES, 1, LVar0, LVar3, LVar2, 20)
        Wait(6 * DT)
    EndLoop
    Wait(20 * DT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Call(PlaySoundAtPlayer, SOUND_GET_STAR_POWER_WAVE, SOUND_SPACE_DEFAULT)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 30)
    Wait(40 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Idle)
    Call(EnableNpcAI, NPC_Eldstar, TRUE)
    Call(N(UpgradeStarPowerCh1))
    Call(ShowMessageAtScreenPos, MSG_Menus_0191, 160, 40)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH1_010E)
    Call(ShowChoice, MSG_Choice_0013)
    IfEq(LVar0, 1)
        Call(ContinueSpeech, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH1_010F)
        Call(ShowChoice, MSG_Choice_0013)
        IfEq(LVar0, 1)
            Call(ContinueSpeech, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH1_0110)
            Goto(10)
        EndIf
    EndIf
    Call(ContinueSpeech, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH1_0111)
    Call(SetSelfVar, 0, 0)
    Call(StartBattle)
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(FullyRestoreSP)
    Call(N(SyncStatusBar))
    Label(10)
    Wait(30 * DT)
    Call(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH1_0112)
    Wait(10 * DT)
    Call(SetPanTarget, CAM_DEFAULT, -527, 0, 216)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(18.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH1_0113)
    Call(SetNpcFlagBits, NPC_Eldstar, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    Thread
        Loop(25)
            Call(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 20)
            Wait(4 * DT)
        EndLoop
    EndThread
    Thread
        Set(LVar2, 0)
        Set(LVar3, 0x00000708)
        Call(MakeLerp, LVar2, LVar3, 100 * DT, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_Eldstar, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(GetNpcPos, NPC_Eldstar, LVar2, LVar3, LVar4)
        Set(LVar5, LVar3)
        Add(LVar5, 180)
        Call(MakeLerp, LVar3, LVar5, 100 * DT, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcPos, NPC_Eldstar, LVar2, LVar0, LVar4)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetNpcPos, NPC_Eldstar, NPC_DISPOSE_LOCATION)
    EndThread
    Thread
        Wait(15 * DT)
        Call(PlaySoundAtNpc, NPC_Eldstar, SOUND_STAR_SPIRIT_DEPART_1, SOUND_SPACE_DEFAULT)
    EndThread
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Wait(90 * DT)
    Call(ResetCam, CAM_DEFAULT, 3)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Set(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
    Exec(N(EVS_SetupMusic))
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Eldstar) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, trd_00_ENTRY_5)
        Call(GetLoadType, LVar1)
        IfEq(LVar1, 1)
            Call(RemoveNpc, NPC_SELF)
        Else
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Eldstar)))
            Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Eldstar)))
            Exec(N(D_80241DA4_99BA14))
        EndIf
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_KoopaBros) = {
    .id = NPC_KoopaBros,
    .pos = { -469.0f, 0.0f, 101.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_KoopaBros),
    .settings = &N(NpcSettings_KoopaBros),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_KoopaBros_Green_Idle,
        .walk   = ANIM_KoopaBros_Green_Walk,
        .run    = ANIM_KoopaBros_Green_Run,
        .chase  = ANIM_KoopaBros_Green_Run,
        .anim_4 = ANIM_KoopaBros_Green_Idle,
        .anim_5 = ANIM_KoopaBros_Green_Idle,
        .death  = ANIM_KoopaBros_Green_HurtStill,
        .hit    = ANIM_KoopaBros_Green_HurtStill,
        .anim_8 = ANIM_KoopaBros_Green_Run,
        .anim_9 = ANIM_KoopaBros_Green_Run,
        .anim_A = ANIM_KoopaBros_Green_Run,
        .anim_B = ANIM_KoopaBros_Green_Run,
        .anim_C = ANIM_KoopaBros_Green_Run,
        .anim_D = ANIM_KoopaBros_Green_Run,
        .anim_E = ANIM_KoopaBros_Green_Run,
        .anim_F = ANIM_KoopaBros_Green_Run,
    },
};

NpcData N(NpcData_Eldstar) = {
    .id = NPC_Eldstar,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { NPC_DISPOSE_LOCATION },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { NPC_DISPOSE_LOCATION },
            .detectSize = { 500 },
        }
    },
    .init = &N(EVS_NpcInit_Eldstar),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = ELDSTAR_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaBros)),
    NPC_GROUP(N(NpcData_Eldstar), BTL_TRD_3_FORMATION_00),
    {}
};
