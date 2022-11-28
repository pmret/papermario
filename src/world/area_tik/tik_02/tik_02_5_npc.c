#include "tik_02.h"

#include "world/common/enemy/complete/Blooper.inc.c"

s32 N(BlooperBattles)[] = {
    BTL_TIK2_FORMATION_00,
    BTL_TIK2_FORMATION_01,
    BTL_TIK2_FORMATION_02,
};

API_CALLABLE(N(GetBlooperBattleID)) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    s32 index = evt_get_variable(script, *args++);

    gCurrentEncounter.encounterList[enemy->encounterIndex]->battle = N(BlooperBattles)[index];
    return ApiStatus_DONE2;
}

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
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_3DC, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_3E7, 0)
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
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_3DD, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_3E7, 0)
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

StaticNpc N(NpcData_Blooper) = {
    .id = NPC_Blooper,
    .settings = &N(NpcSettings_Blooper),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_4 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_40000 | ENEMY_FLAGS_800000,
    .init = &N(EVS_NpcInit_Blooper),
    .drops = BLOOPER_NO_DROPS,
    .animations = BLOOPER_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Blooper), BTL_TIK2_FORMATION_00, BTL_TIK2_STAGE_00),
    {}
};