#include "arn_11.h"

#include "world/common/npc/TubbasHeart.inc.c"

EvtScript N(EVS_NpcIdle_TubbasHeart) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(SetCamType, CAM_DEFAULT, 6, TRUE)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 50)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 3000)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(StartBossBattle, SONG_TUBBA_BLUBBA_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Heart_OpenDoor) = {
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 80, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o37, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Heart_CloseDoor) = {
    EVT_CALL(MakeLerp, 80, 0, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o37, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_RETURN
    EVT_END
};

#define SUBLIST_DONE -10000

Vec3i N(HeartJumpPath)[] = {
    {    100,    30,    70 },
    {     25,    30,    80 },
    { SUBLIST_DONE, 0, 0 },
    {    -70,    10,    20 },
    {   -180,     0,     0 },
    {   -300,     0,     0 },
    { SUBLIST_DONE, 0, 0 },
};

EvtScript N(EVS_Scene_HeartEscape) = {
    EVT_THREAD
        EVT_CALL(SetCamType, CAM_DEFAULT, 6, TRUE)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 50)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_WAIT(10 * DT)
    EVT_CALL(PlayerFaceNpc, NPC_TubbasHeart, TRUE)
    EVT_LOOP(2)
        EVT_CALL(GetNpcPos, NPC_TubbasHeart, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcJumpscale, NPC_TubbasHeart, EVT_FLOAT(2.5))
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_TubbasHeart, LVar0, LVar1, LVar2, 12 * DT)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(SetCamType, CAM_DEFAULT, 4, TRUE)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
        EVT_CALL(SetCamPosA, CAM_DEFAULT, -56, 70)
        EVT_CALL(SetCamPosB, CAM_DEFAULT, -90, 40)
        EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(PlayerFaceNpc, NPC_TubbasHeart, TRUE)
    EVT_USE_BUF(EVT_PTR(N(HeartJumpPath)))
    EVT_LOOP(0)
        EVT_BUF_READ3(LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar0, SUBLIST_DONE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_TubbasHeart, LVar0, LVar1, LVar2, 12 * DT)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_EXEC(N(EVS_Heart_OpenDoor))
    EVT_LOOP(0)
        EVT_BUF_READ3(LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar0, SUBLIST_DONE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_TubbasHeart, LVar0, LVar1, LVar2, 12 * DT)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_EXEC(N(EVS_Heart_CloseDoor))
    EVT_WAIT(30 * DT)
    EVT_CALL(SetCamType, CAM_DEFAULT, 6, TRUE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_SET(GB_StoryProgress, STORY_CH3_HEART_FLED_FIRST_TUNNEL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TubbasHeart) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_HEART_FLED_FIRST_TUNNEL)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_ELSE
        EVT_CALL(SetSelfVar, 0, 0)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TubbasHeart)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_Scene_HeartEscape)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_TubbasHeart) = {
    .id = NPC_TubbasHeart,
    .pos = { 119.0f, 60.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_TubbasHeart),
    .settings = &N(NpcSettings_TubbasHeart),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
    .drops = NO_DROPS,
    .animations = TUBBAS_HEART_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_TubbasHeart), BTL_ARN_FORMATION_0F),
    {}
};
