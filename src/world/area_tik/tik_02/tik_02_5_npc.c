#include "tik_02.h"

#include "world/common/enemy/Blooper.inc.c"

EvtScript N(EVS_NpcIdle_Blooper) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 65)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC(N(EVS_PlayBlooperSong))
    EVT_CALL(ShowMessageAtScreenPos, MSG_MGM_0000, 160, 40)
    EVT_THREAD
        EVT_CALL(InterpPlayerYaw, 315, 0)
        EVT_WAIT(50)
        EVT_CALL(InterpPlayerYaw, 45, 0)
    EVT_END_THREAD
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -25, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -25, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(20)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 140, LVar1, LVar2)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BLOOPER_MOVE, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_LARGE_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcPos, NPC_SELF, -100, -300, -120)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Blooper_Anim01)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_SELF, 175, 0, 0, 40)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Blooper_Anim0C)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_WAIT(15)
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Blooper) = {
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Blooper_Anim04)
        EVT_CALL(MakeLerp, 0, 6 * 360, 40, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
            EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BLOOPER_FALL, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_LARGE_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_SELF, -100, -300, -120, 40)
    EVT_WAIT(1)
    EVT_IF_EQ(GF_TIK_DefeatedOneBlooper, FALSE)
        EVT_SET(GF_TIK_DefeatedOneBlooper, TRUE)
    EVT_ELSE
        EVT_SET(GF_TIK_DefeatedTwoBloopers, TRUE)
    EVT_END_IF
    EVT_SET(GF_TIK02_Defeated_Blooper, TRUE)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Blooper) = {
    EVT_IF_EQ(GF_TIK02_Defeated_Blooper, FALSE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Blooper)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Blooper)))
        EVT_IF_EQ(GF_TIK_DefeatedOneBlooper, FALSE)
            EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(0.75), EVT_FLOAT(0.75), EVT_FLOAT(0.75))
            EVT_CALL(N(GetBlooperBattleID), 0)
        EVT_ELSE
            EVT_IF_EQ(GF_TIK_DefeatedTwoBloopers, FALSE)
                EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
                EVT_CALL(N(GetBlooperBattleID), 1)
            EVT_ELSE
                EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(2.0), EVT_FLOAT(2.0), EVT_FLOAT(2.0))
                EVT_CALL(N(GetBlooperBattleID), 2)
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Blooper) = {
    .id = NPC_Blooper,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Blooper),
    .settings = &N(NpcSettings_Blooper),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = BLOOPER_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Blooper), BTL_TIK2_FORMATION_00, BTL_TIK2_STAGE_00),
    {}
};
