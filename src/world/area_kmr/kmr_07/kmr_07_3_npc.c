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
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_GOOMBA_BROS_STEP, SOUND_SPACE_DEFAULT)
        EVT_WAIT(4)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_GoombaBros_Red) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_IF_LT(LVar0, 210)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(SetMusicTrack, 0, SONG_MINIBOSS_BATTLE, 0, 8)
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_WAIT(1)
    EVT_END_THREAD
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH0_00BB, 320, 60)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_LookAround)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 360, 80, 35)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(30 * DT)
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_GoombaBros_Red, EVT_FLOAT(6.0 / DT))
        EVT_CALL(SetNpcAnimation, NPC_GoombaBros_Red, ANIM_GoombaBros_Red_Walk)
        EVT_SET(LVar0, 0)
        EVT_EXEC_GET_TID(N(EVS_PlayWalkingSounds), LVarA)
        EVT_CALL(NpcMoveTo, NPC_GoombaBros_Red, 405, 42, 0)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(SetNpcAnimation, NPC_GoombaBros_Red, ANIM_GoombaBros_Red_Idle)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_GoombaBros_Blue, ANIM_GoombaBros_Blue_Walk)
    EVT_CALL(SetNpcSpeed, NPC_GoombaBros_Blue, EVT_FLOAT(6.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_GoombaBros_Blue, ANIM_GoombaBros_Blue_Walk)
    EVT_SET(LVar0, 1)
    EVT_EXEC_GET_TID(N(EVS_PlayWalkingSounds), LVarA)
    EVT_CALL(NpcMoveTo, NPC_GoombaBros_Blue, 376, 11, 0)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcAnimation, NPC_GoombaBros_Blue, ANIM_GoombaBros_Blue_Idle)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_CALL(SpeakToPlayer, NPC_GoombaBros_Red, ANIM_GoombaBros_Red_Talk, ANIM_GoombaBros_Red_Idle, 0, MSG_CH0_00BC)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 270, 80, 45)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-3.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_GoombaBros_Red, ANIM_GoombaBros_Red_Talk, ANIM_GoombaBros_Red_Idle, 0, MSG_CH0_00BD)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_GoombaBros_Blue, ANIM_GoombaBros_Blue_Talk, ANIM_GoombaBros_Blue_Idle, 0, MSG_CH0_00BE)
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetNpcJumpscale, NPC_GoombaBros_Blue, EVT_FLOAT(0.8))
        EVT_CALL(SetNpcAnimation, NPC_GoombaBros_Blue, ANIM_GoombaBros_Blue_Walk)
        EVT_CALL(PlaySoundAtNpc, NPC_GoombaBros_Blue, SOUND_ACTOR_HURT, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_GoombaBros_Blue, 267, 0, 28, 30 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_GoombaBros_Red, EVT_FLOAT(0.8))
        EVT_CALL(SetNpcAnimation, NPC_GoombaBros_Red, ANIM_GoombaBros_Red_Walk)
        EVT_CALL(PlaySoundAtNpc, NPC_GoombaBros_Red, SOUND_ACTOR_HURT, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_GoombaBros_Red, 276, 0, 55, 30 * DT)
    EVT_END_THREAD
    EVT_WAIT(15 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(5 * DT)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_GoombaBros_Red) = {
    EVT_THREAD
        EVT_WAIT(5 * DT)
        EVT_CALL(SetMusicTrack, 0, SONG_GOOMBA_BROS_RETREAT, 0, 8)
    EVT_END_THREAD
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetNpcAnimation, NPC_GoombaBros_Red, ANIM_GoombaBros_Red_CryIdle)
            EVT_CALL(SetNpcAnimation, NPC_GoombaBros_Blue, ANIM_GoombaBros_Blue_CryIdle)
            EVT_CALL(SpeakToPlayer, NPC_GoombaBros_Red, ANIM_GoombaBros_Red_CryTalk, ANIM_GoombaBros_Red_CryIdle, 0, MSG_CH0_00C2)
            EVT_WAIT(10)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_WAIT(10)
            EVT_THREAD
                EVT_CALL(SetNpcJumpscale, NPC_GoombaBros_Blue, EVT_FLOAT(1.8))
                EVT_CALL(SetNpcAnimation, NPC_GoombaBros_Blue, ANIM_GoombaBros_Blue_CryWalk)
                EVT_CALL(PlaySoundAtNpc, NPC_GoombaBros_Blue, SOUND_ACTOR_HURT, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump0, NPC_GoombaBros_Blue, 307, 25, 49, 20 * DT)
                EVT_CALL(N(PlaySpringReboundAnimation))
                EVT_CALL(PlaySoundAtNpc, NPC_GoombaBros_Blue, SOUND_SPRING, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump0, NPC_GoombaBros_Blue, 401, 80, 25, 30 * DT)
                EVT_WAIT(5 * DT)
                EVT_CALL(SetNpcSpeed, NPC_GoombaBros_Blue, EVT_FLOAT(6.0 / DT))
                EVT_SET(LVar0, 1)
                EVT_EXEC_GET_TID(N(EVS_PlayWalkingSounds), LVarA)
                EVT_CALL(NpcMoveTo, NPC_GoombaBros_Blue, 616, -47, 0)
                EVT_KILL_THREAD(LVarA)
                EVT_CALL(SetNpcFlagBits, NPC_GoombaBros_Blue, NPC_FLAG_GRAVITY, FALSE)
                EVT_CALL(SetNpcPos, NPC_GoombaBros_Blue, NPC_DISPOSE_LOCATION)
                EVT_WAIT(1)
            EVT_END_THREAD
            EVT_WAIT(30 * DT)
            EVT_CALL(SetNpcJumpscale, NPC_GoombaBros_Red, EVT_FLOAT(1.8))
            EVT_CALL(SetNpcAnimation, NPC_GoombaBros_Red, ANIM_GoombaBros_Red_CryWalk)
            EVT_CALL(PlaySoundAtNpc, NPC_GoombaBros_Red, SOUND_ACTOR_HURT, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_GoombaBros_Red, 307, 25, 49, 20 * DT)
            EVT_CALL(N(PlaySpringReboundAnimation))
            EVT_CALL(PlaySoundAtNpc, NPC_GoombaBros_Red, SOUND_SPRING, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_GoombaBros_Red, 401, 80, 25, 30 * DT)
            EVT_WAIT(5 * DT)
            EVT_CALL(SetNpcSpeed, NPC_GoombaBros_Red, EVT_FLOAT(6.0 / DT))
            EVT_SET(LVar0, 0)
            EVT_EXEC_GET_TID(N(EVS_PlayWalkingSounds), LVarA)
            EVT_CALL(NpcMoveTo, NPC_GoombaBros_Red, 616, -47, 0)
            EVT_KILL_THREAD(LVarA)
            EVT_CALL(SetNpcFlagBits, NPC_GoombaBros_Red, NPC_FLAG_GRAVITY, FALSE)
            EVT_CALL(SetNpcPos, NPC_GoombaBros_Red, NPC_DISPOSE_LOCATION)
            EVT_WAIT(1)
            EVT_EXEC(N(EVS_SetupMusic))
            EVT_SET(MV_GoombaBrosDefeated, TRUE)
            EVT_SET(GB_StoryProgress, STORY_CH0_DEFEATED_GOOMBA_BROS)
            EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GoombaBros_Red) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_GoombaBros_Red)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_GoombaBros_Red)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_SET(MV_GoombaBrosDefeated, FALSE)
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_DEFEATED_GOOMBA_BROS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_GoombaBros_Blue) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_GoombaBros_Blue) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_LABEL(0)
            EVT_IF_EQ(MV_GoombaBrosDefeated, FALSE)
                EVT_WAIT(1)
                EVT_GOTO(0)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GoombaBros_Blue) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_GoombaBros_Blue)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_GoombaBros_Blue)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_DEFEATED_GOOMBA_BROS)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
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
