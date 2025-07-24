#include "dgb_15.h"

#define INCLUDE_CLUBBA_WANDER
#include "world/common/enemy/Clubba_Multi.inc.c"

#include "world/common/enemy/TubbaBlubba.inc.c"

NpcSettings N(NpcSettings_Yakkey) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_CLUBBA,
};

extern EvtScript N(EVS_NpcAI_Tubba);

EvtScript N(EVS_WaitForCloseCall) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(GetNpcPos, NPC_Tubba, LVar1, LVar2, LVar3)
        Sub(LVar1, LVar0)
        IfLt(LVar1, 150)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Set(GF_DGB15_CloseCallWithTubba, true)
    Set(AF_DGB_01, true)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Tubba) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGe(LVar0, -1150)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, true)
    Call(SetMusic, 0, SONG_TUBBA_BLUBBA_THEME, 0, VOL_LEVEL_FULL)
    Wait(15)
    Thread
        Call(UseSettingsFrom, CAM_DEFAULT, -50, 0, 180)
        Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
        Call(SetPanTarget, CAM_DEFAULT, -50, 0, 180)
        Call(PanToTarget, CAM_DEFAULT, 0, true)
    EndThread
    Set(GB_ARN_Tubba_MapID, 15)
    Call(SetNpcPos, NPC_SELF, 0, 0, 88)
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim09)
    Call(SetNpcYaw, NPC_SELF, 270)
    Call(NpcMoveTo, NPC_SELF, -53, 180, 60)
    Call(SetMusic, 0, SONG_TUBBA_BLUBBA_THEME, 0, VOL_LEVEL_FULL)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim06)
    Wait(15)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldTubba_Anim10, ANIM_WorldTubba_Anim06, 0, MSG_CH3_00F3)
    Wait(15)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(PanToTarget, CAM_DEFAULT, 0, false)
        Call(DisablePlayerInput, false)
    EndThread
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_Tubba)))
    Return
    End
};

EvtScript N(EVS_PlayFootstepFX) = {
    Call(GetNpcPos, NPC_SELF, LVar6, LVar7, LVar8)
    Loop(0)
        Wait(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
        IfNe(LVar3, LVar6)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_HEAVY_NPC_STEP_C, SOUND_PARAM_MUTE | SOUND_SPACE_FULL)
            Call(GetDist2D, LVarA, LVar0, LVar2, LVar3, LVar5)
            Switch(LVarA)
                CaseLt(200)
                    Thread
                        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.6))
                        Wait(5)
                        Call(ShakeCam, CAM_DEFAULT, 0, 2, Float(0.8))
                    EndThread
                CaseLt(300)
                    Thread
                        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.6))
                        Wait(5)
                        Call(ShakeCam, CAM_DEFAULT, 0, 2, Float(0.3))
                    EndThread
                CaseGe(300)
                    Thread
                        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.1))
                        Wait(5)
                        Call(ShakeCam, CAM_DEFAULT, 0, 2, Float(0.05))
                    EndThread
            EndSwitch
            Wait(12)
        Else
        EndIf
        Call(GetNpcPos, NPC_SELF, LVar6, LVar7, LVar8)
    EndLoop
    Return
    End
};

MobileAISettings N(AISettings_Tubba) = {
    .moveSpeed = 3.0f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 150.0f,
    .alertOffsetDist = 80.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 3.5f,
    .chaseTurnRate = 180,
    .chaseUpdateInterval = 2,
    .chaseRadius = 160.0f,
    .chaseOffsetDist = 80.0f,
    .unk_AI_2C = 1,
};

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

EvtScript N(EVS_NpcAI_Tubba) = {
    Exec(N(EVS_WaitForCloseCall))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, true)
    Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim0C)
    Exec(N(EVS_PlayFootstepFX))
    Call(N(PatrolNoAttackAI_Main), Ref(N(AISettings_Tubba)))
    Return
    End
};

#include "world/common/todo/UnkFunc1.inc.c"

EvtScript N(EVS_NpcDefeat_Tubba) = {
    Call(N(UnkFunc1))
    Call(GotoMap, Ref("dgb_14"), dgb_14_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_NpcInit_Tubba) = {
    IfNe(GB_StoryProgress, STORY_CH3_ARRIVED_AT_TUBBAS_MANOR)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Call(SetNpcScale, NPC_SELF, Float(1.25), Float(1.25), Float(1.25))
    IfNe(GB_ARN_Tubba_MapID, 15)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Tubba)))
    Else
        Call(SetNpcPos, NPC_SELF, -310, 0, 180)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcAI_Tubba)))
    EndIf
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Tubba)))
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
            .numPoints  = 7,
            .points  = {
                { -500, 0, 200 },
                { -700, 0, 200 },
                { -900, 0, 200 },
                { -1000, 0, 200 },
                { -800, 0, 200 },
                { -600, 0, 200 },
                { -400, 0, 200 },
            },
            .detectShape = SHAPE_RECT,
            .detectPos  = { -500, 0, 200 },
            .detectSize = { 1000, 250 },
        }
    },
    .init = &N(EVS_NpcInit_Tubba),
    .settings = &N(NpcSettings_TubbaBlubba),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
    .drops = CLUBBA_DROPS,
    .animations = TUBBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Tubba), BTL_DGB_FORMATION_04, BTL_DGB_STAGE_00),
    {}
};
