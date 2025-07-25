#include "arn_11.h"

#include "world/common/npc/TubbasHeart.inc.c"

EvtScript N(EVS_NpcIdle_TubbasHeart) = {
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfNe(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Thread
        Call(SetCamType, CAM_DEFAULT, 6, true)
        Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, 50)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, 3000)
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndThread
    Call(StartBossBattle, SONG_TUBBA_BLUBBA_BATTLE)
    Return
    End
};

EvtScript N(EVS_Heart_OpenDoor) = {
    Wait(15)
    Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 80, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o37, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Heart_CloseDoor) = {
    Call(MakeLerp, 80, 0, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o37, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Return
    End
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
    Thread
        Call(SetCamType, CAM_DEFAULT, 6, true)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, 50)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, 450)
        Call(PanToTarget, CAM_DEFAULT, 0, true)
    EndThread
    Wait(10 * DT)
    Call(PlayerFaceNpc, NPC_TubbasHeart, true)
    Loop(2)
        Call(GetNpcPos, NPC_TubbasHeart, LVar0, LVar1, LVar2)
        Call(SetNpcJumpscale, NPC_TubbasHeart, Float(2.5))
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_TubbasHeart, LVar0, LVar1, LVar2, 12 * DT)
        Wait(1)
    EndLoop
    Thread
        Wait(10 * DT)
        Call(SetCamType, CAM_DEFAULT, 4, true)
        Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
        Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-7.0))
        Call(SetCamDistance, CAM_DEFAULT, 450)
        Call(SetCamPosA, CAM_DEFAULT, -56, 70)
        Call(SetCamPosB, CAM_DEFAULT, -90, 40)
        Call(SetCamPosC, CAM_DEFAULT, 0, 0)
        Call(PanToTarget, CAM_DEFAULT, 0, true)
    EndThread
    Call(PlayerFaceNpc, NPC_TubbasHeart, true)
    UseBuf(Ref(N(HeartJumpPath)))
    Loop(0)
        BufRead3(LVar0, LVar1, LVar2)
        IfEq(LVar0, SUBLIST_DONE)
            BreakLoop
        EndIf
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_TubbasHeart, LVar0, LVar1, LVar2, 12 * DT)
        Wait(1)
    EndLoop
    Exec(N(EVS_Heart_OpenDoor))
    Loop(0)
        BufRead3(LVar0, LVar1, LVar2)
        IfEq(LVar0, SUBLIST_DONE)
            BreakLoop
        EndIf
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_TubbasHeart, LVar0, LVar1, LVar2, 12 * DT)
        Wait(1)
    EndLoop
    Exec(N(EVS_Heart_CloseDoor))
    Wait(30 * DT)
    Call(SetCamType, CAM_DEFAULT, 6, true)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 450)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Set(GB_StoryProgress, STORY_CH3_HEART_FLED_FIRST_TUNNEL)
    Return
    End
};

EvtScript N(EVS_NpcInit_TubbasHeart) = {
    IfGe(GB_StoryProgress, STORY_CH3_HEART_FLED_FIRST_TUNNEL)
        Call(RemoveNpc, NPC_SELF)
    Else
        Call(SetSelfVar, 0, 0)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_TubbasHeart)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_Scene_HeartEscape)))
    EndIf
    Return
    End
};

NpcData N(NpcData_TubbasHeart) = {
    .id = NPC_TubbasHeart,
    .pos = { 119.0f, 60.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_TubbasHeart),
    .settings = &N(NpcSettings_TubbasHeart),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DELAY_AFTER_FLEE,
    .drops = NO_DROPS,
    .animations = TUBBAS_HEART_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_TubbasHeart), BTL_ARN_FORMATION_0F),
    {}
};
