#include "kmr_07.h"
#include "animation_script.h"
#include "sprite/player.h"

#include "world/common/enemy/GoombaBros_Guard.inc.c"

extern AnimScript Entity_SimpleSpring_AnimLaunch;

API_CALLABLE(N(PlaySpringReboundAnimation)) {
    Entity* entity = get_entity_by_index(evt_get_variable(NULL, MV_SpringEntityIndex));

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, Entity_SimpleSpring_AnimLaunch);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_PlayWalkingSounds) = {
    Loop(0)
        Call(PlaySoundAtNpc, LVar0, SOUND_GOOMBA_BROS_STEP, SOUND_SPACE_DEFAULT)
        Wait(4)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_GoombaBros_Red) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        IfLt(LVar0, 210)
            Goto(0)
        EndIf
    Call(SetMusicTrack, 0, SONG_MINIBOSS_BATTLE, 0, 8)
    SetGroup(EVT_GROUP_EF)
    Thread
        Wait(3)
        Call(DisablePlayerInput, TRUE)
        Wait(1)
    EndThread
    Call(ShowMessageAtScreenPos, MSG_CH0_00BB, 320, 60)
    Call(SetPlayerAnimation, ANIM_MarioW2_LookAround)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, 360, 80, 35)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-7.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(30 * DT)
    Thread
        Call(SetNpcSpeed, NPC_GoombaBros_Red, Float(6.0 / DT))
        Call(SetNpcAnimation, NPC_GoombaBros_Red, ANIM_GoombaBros_Red_Walk)
        Set(LVar0, 0)
        ExecGetTID(N(EVS_PlayWalkingSounds), LVarA)
        Call(NpcMoveTo, NPC_GoombaBros_Red, 405, 42, 0)
        KillThread(LVarA)
        Call(SetNpcAnimation, NPC_GoombaBros_Red, ANIM_GoombaBros_Red_Idle)
    EndThread
    Call(SetNpcAnimation, NPC_GoombaBros_Blue, ANIM_GoombaBros_Blue_Walk)
    Call(SetNpcSpeed, NPC_GoombaBros_Blue, Float(6.0 / DT))
    Call(SetNpcAnimation, NPC_GoombaBros_Blue, ANIM_GoombaBros_Blue_Walk)
    Set(LVar0, 1)
    ExecGetTID(N(EVS_PlayWalkingSounds), LVarA)
    Call(NpcMoveTo, NPC_GoombaBros_Blue, 376, 11, 0)
    KillThread(LVarA)
    Call(SetNpcAnimation, NPC_GoombaBros_Blue, ANIM_GoombaBros_Blue_Idle)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Call(SpeakToPlayer, NPC_GoombaBros_Red, ANIM_GoombaBros_Red_Talk, ANIM_GoombaBros_Red_Idle, 0, MSG_CH0_00BC)
    Wait(10 * DT)
    Call(SetPanTarget, CAM_DEFAULT, 270, 80, 45)
    Call(SetCamDistance, CAM_DEFAULT, 450)
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-3.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_GoombaBros_Red, ANIM_GoombaBros_Red_Talk, ANIM_GoombaBros_Red_Idle, 0, MSG_CH0_00BD)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_GoombaBros_Blue, ANIM_GoombaBros_Blue_Talk, ANIM_GoombaBros_Blue_Idle, 0, MSG_CH0_00BE)
    Wait(10 * DT)
    Thread
        Wait(5)
        Call(SetNpcJumpscale, NPC_GoombaBros_Blue, Float(0.8))
        Call(SetNpcAnimation, NPC_GoombaBros_Blue, ANIM_GoombaBros_Blue_Walk)
        Call(PlaySoundAtNpc, NPC_GoombaBros_Blue, SOUND_ACTOR_HURT, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_GoombaBros_Blue, 267, 0, 28, 30 * DT)
        Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EndThread
    Thread
        Call(SetNpcJumpscale, NPC_GoombaBros_Red, Float(0.8))
        Call(SetNpcAnimation, NPC_GoombaBros_Red, ANIM_GoombaBros_Red_Walk)
        Call(PlaySoundAtNpc, NPC_GoombaBros_Red, SOUND_ACTOR_HURT, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_GoombaBros_Red, 276, 0, 55, 30 * DT)
    EndThread
    Wait(15 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(5 * DT)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(DisablePlayerInput, FALSE)
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_GoombaBros_Red) = {
    Thread
        Wait(5 * DT)
        Call(SetMusicTrack, 0, SONG_GOOMBA_BROS_RETREAT, 0, 8)
    EndThread
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetNpcAnimation, NPC_GoombaBros_Red, ANIM_GoombaBros_Red_CryIdle)
            Call(SetNpcAnimation, NPC_GoombaBros_Blue, ANIM_GoombaBros_Blue_CryIdle)
            Call(SpeakToPlayer, NPC_GoombaBros_Red, ANIM_GoombaBros_Red_CryTalk, ANIM_GoombaBros_Red_CryIdle, 0, MSG_CH0_00C2)
            Wait(10)
            Call(DisablePlayerInput, TRUE)
            Wait(10)
            Thread
                Call(SetNpcJumpscale, NPC_GoombaBros_Blue, Float(1.8))
                Call(SetNpcAnimation, NPC_GoombaBros_Blue, ANIM_GoombaBros_Blue_CryWalk)
                Call(PlaySoundAtNpc, NPC_GoombaBros_Blue, SOUND_ACTOR_HURT, SOUND_SPACE_DEFAULT)
                Call(NpcJump0, NPC_GoombaBros_Blue, 307, 25, 49, 20 * DT)
                Call(N(PlaySpringReboundAnimation))
                Call(PlaySoundAtNpc, NPC_GoombaBros_Blue, SOUND_SPRING, SOUND_SPACE_DEFAULT)
                Call(NpcJump0, NPC_GoombaBros_Blue, 401, 80, 25, 30 * DT)
                Wait(5 * DT)
                Call(SetNpcSpeed, NPC_GoombaBros_Blue, Float(6.0 / DT))
                Set(LVar0, 1)
                ExecGetTID(N(EVS_PlayWalkingSounds), LVarA)
                Call(NpcMoveTo, NPC_GoombaBros_Blue, 616, -47, 0)
                KillThread(LVarA)
                Call(SetNpcFlagBits, NPC_GoombaBros_Blue, NPC_FLAG_GRAVITY, FALSE)
                Call(SetNpcPos, NPC_GoombaBros_Blue, NPC_DISPOSE_LOCATION)
                Wait(1)
            EndThread
            Wait(30 * DT)
            Call(SetNpcJumpscale, NPC_GoombaBros_Red, Float(1.8))
            Call(SetNpcAnimation, NPC_GoombaBros_Red, ANIM_GoombaBros_Red_CryWalk)
            Call(PlaySoundAtNpc, NPC_GoombaBros_Red, SOUND_ACTOR_HURT, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_GoombaBros_Red, 307, 25, 49, 20 * DT)
            Call(N(PlaySpringReboundAnimation))
            Call(PlaySoundAtNpc, NPC_GoombaBros_Red, SOUND_SPRING, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_GoombaBros_Red, 401, 80, 25, 30 * DT)
            Wait(5 * DT)
            Call(SetNpcSpeed, NPC_GoombaBros_Red, Float(6.0 / DT))
            Set(LVar0, 0)
            ExecGetTID(N(EVS_PlayWalkingSounds), LVarA)
            Call(NpcMoveTo, NPC_GoombaBros_Red, 616, -47, 0)
            KillThread(LVarA)
            Call(SetNpcFlagBits, NPC_GoombaBros_Red, NPC_FLAG_GRAVITY, FALSE)
            Call(SetNpcPos, NPC_GoombaBros_Red, NPC_DISPOSE_LOCATION)
            Wait(1)
            Exec(N(EVS_SetupMusic))
            Set(MV_GoombaBrosDefeated, TRUE)
            Set(GB_StoryProgress, STORY_CH0_DEFEATED_GOOMBA_BROS)
            Call(DisablePlayerInput, FALSE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_GoombaBros_Red) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_GoombaBros_Red)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_GoombaBros_Red)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Set(MV_GoombaBrosDefeated, FALSE)
    IfGe(GB_StoryProgress, STORY_CH0_DEFEATED_GOOMBA_BROS)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcIdle_GoombaBros_Blue) = {
    Return
    End
};

EvtScript N(EVS_NpcDefeat_GoombaBros_Blue) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Label(0)
            IfEq(MV_GoombaBrosDefeated, FALSE)
                Wait(1)
                Goto(0)
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_GoombaBros_Blue) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_GoombaBros_Blue)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_GoombaBros_Blue)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    IfGe(GB_StoryProgress, STORY_CH0_DEFEATED_GOOMBA_BROS)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Return
    End
};

NpcData N(NpcData_GoombaBros_Red)[] = {
    {
        .id = NPC_GoombaBros_Red,
        .pos = { 526.0f, 80.0f, 0.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_GoombaBros_Red),
        .settings = &N(NpcSettings_GoombaBros_Guard),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = GOOMBA_BROS_RED_ANIMS,
    },
    {
        .id = NPC_GoombaBros_Blue,
        .pos = { 498.0f, 80.0f, -10.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_GoombaBros_Blue),
        .settings = &N(NpcSettings_GoombaBros_Guard),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = GOOMBA_BROS_BLUE_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_GoombaBros_Red), BTL_KMR_2_FORMATION_00, BTL_KMR_2_STAGE_01),
    {}
};
