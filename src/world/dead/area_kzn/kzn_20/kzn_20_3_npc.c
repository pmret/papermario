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
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_LOOP(0)
        EVT_CALL(RandInt, 100, LVar0)
        EVT_SUB(LVar0, 100)
        EVT_PLAY_EFFECT(EFFECT_DUST, 1, LVar0, 350, 0, 60)
        EVT_CALL(RandInt, 100, LVar0)
        EVT_WAIT(30)
        EVT_PLAY_EFFECT(EFFECT_DUST, 1, LVar0, 350, 0, 60)
        EVT_WAIT(30)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShakingWorld) = {
    EVT_SET_GROUP(EVT_GROUP_0A)
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
        EVT_EXEC(N(EVS_SpawnFallingDust))
    EVT_ELSE
        EVT_LOOP(0)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 2, EVT_FLOAT(0.5))
            EVT_IF_NE(AF_KZN_RumblingIntensified, FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_EXEC(N(EVS_SpawnFallingDust))
        EVT_CALL(MakeLerp, 20, 250, 5, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, EVT_FLOAT(100.0))
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, LVar0)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 250, 30, 60, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, EVT_FLOAT(100.0))
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, LVar0)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_LOOP(0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.5))
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
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
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_LABEL(0)
    EVT_CALL(RandInt, 1, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_USE_BUF(N(Kolorado_Wander1))
    EVT_ELSE
        EVT_USE_BUF(N(Kolorado_Wander2))
    EVT_END_IF
    EVT_LABEL(10)
        EVT_BUF_READ3(LVar1, LVar2, LVar3)
        EVT_IF_EQ(LVar1, -1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(SetNpcSpeed, NPC_Kolorado, LVar1)
        EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Walk)
        EVT_CALL(NpcMoveTo, NPC_Kolorado, LVar2, LVar3, 0)
        EVT_BUF_READ1(LVar2)
        EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Idle)
        EVT_WAIT(5)
        EVT_CALL(RandInt, 2, LVar4)
        EVT_ADD(LVar4, 1)
        EVT_LOOP(LVar4)
            EVT_CALL(GetNpcYaw, NPC_Kolorado, LVar5)
            EVT_ADD(LVar5, 180)
            EVT_IF_GT(LVar5, 360)
                EVT_SUB(LVar5, 360)
            EVT_END_IF
            EVT_CALL(InterpNpcYaw, NPC_Kolorado, LVar5, 1)
            EVT_WAIT(20)
        EVT_END_LOOP
        EVT_WAIT(LVar2)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KoloradoBurned_PlayerReaction) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar3, LVar2)
    EVT_ADD(LVar3, 30)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcPos, NPC_Kolorado, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar1, LVar3)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcPos, NPC_Kolorado, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar1, LVar3)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(func_80240A68_C96998)) {
    snd_ambient_mute(0, TRUE);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_Kolorado) = {
    EVT_EXEC_GET_TID(N(EVS_Kolorado_CalmIdle), LVar9)
    // wait for scene to begin
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_IF_NE(MV_SceneState, SCENE_STATE_BEGIN)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_KILL_THREAD(LVar9)
    EVT_WAIT(10)
    // cutscene actions
    EVT_LABEL(10)
        EVT_SWITCH(MV_SceneState)
            EVT_CASE_EQ(SCENE_STATE_BEGIN)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
                EVT_CALL(SetNpcPos, NPC_SELF, -30, 100, 40)
                EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.0))
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump0, NPC_SELF, -25, 125, -20, 10)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump0, NPC_SELF, 20, 150, 5, 10)
                EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0))
                EVT_CALL(NpcMoveTo, NPC_SELF, 40, 35, 0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_010A)
                EVT_SET(MV_SceneState, SCENE_STATE_STARFISH_REMARK)
            EVT_CASE_EQ(SCENE_STATE_KOLORADO_LOOKS_AROUND)
                EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
                EVT_ADD(LVar3, -30)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
                EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 4)
                EVT_WAIT(10)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 4)
                EVT_WAIT(10)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 4)
                EVT_WAIT(10)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
                EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
                EVT_CALL(NpcMoveTo, NPC_SELF, 20, 0, 0)
                EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump0, NPC_SELF, -35, 125, -20, 12)
                EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
                EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(1.0))
                EVT_LABEL(25)
                EVT_CALL(NpcMoveTo, NPC_SELF, -15, -20, 0)
                EVT_CALL(NpcMoveTo, NPC_SELF, -40, -20, 0)
                EVT_IF_EQ(AF_KZN20_SceneSync, FALSE)
                    EVT_WAIT(1)
                    EVT_GOTO(25)
                EVT_END_IF
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 5, MSG_CH5_010B)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
                EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 15, EMOTER_NPC, 0, 0, 0, 0)
                EVT_WAIT(15)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
                EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.5))
                EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
                EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
                EVT_CALL(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 8)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
                EVT_THREAD
                    EVT_WAIT(8)
                    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
                EVT_END_THREAD
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 5, MSG_CH5_010C)
                EVT_SET(AF_KZN_RumblingIntensified, TRUE)
                EVT_CALL(SetMusicTrack, 0, SONG_VOLCANO_ESCAPE, 0, 8)
                EVT_WAIT(20)
                EVT_THREAD
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
                    EVT_WAIT(60)
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                EVT_END_THREAD
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Yell)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_010D)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
                EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.0))
                EVT_SET(MV_SceneState, SCENE_STATE_KOLORADO_WENT_BACK)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump0, NPC_SELF, -30, 100, 40, 10)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump0, NPC_SELF, -15, 75, 80, 10)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump0, NPC_SELF, 35, 50, 120, 10)
            EVT_CASE_EQ(SCENE_STATE_KOLORADO_WARNED)
                EVT_CALL(N(func_80240A68_C96998))
                EVT_EXEC(N(EVS_KoloradoBurned_PlayerReaction))
                EVT_THREAD
                    EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
                    EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_010F, 160, 40)
                EVT_END_THREAD
                EVT_THREAD
                    EVT_LOOP(0)
                        EVT_WAIT(1)
                        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                        EVT_ADD(LVar2, -10)
                        EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, 1, 10)
                        EVT_IF_EQ(MV_SceneState, SCENE_STATE_KOLORADO_BURNED)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                    EVT_END_LOOP
                EVT_END_THREAD
                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Hurt)
                EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.8))
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_TOUCH_LAVA, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump1, NPC_SELF, LVar0, LVar1, LVar2, 60)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
                EVT_SET(MV_SceneState, SCENE_STATE_KOLORADO_BURNED)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 100, 25, 100)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, 100, 25, 100)
                EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(450.0))
                EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Panic, ANIM_Kolorado_Panic, 0, MSG_CH5_0110)
                EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
                EVT_SET(MV_SceneState, SCENE_STATE_MISSTAR_SPEAKS)
            EVT_CASE_EQ(SCENE_STATE_KOLORADO_RETURN)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
                EVT_CALL(SetNpcPos, NPC_SELF, -30, 100, 40)
                EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.0))
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump0, NPC_SELF, -25, 125, -20, 10)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump0, NPC_SELF, 20, 150, 5, 8)
                EVT_SET(MV_SceneState, SCENE_STATE_SEARCH_FOR_EXIT)
                EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0))
                EVT_CALL(NpcMoveTo, NPC_SELF, 75, -30, 0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar1, 100)
        EVT_CALL(EnableNpcAI, NPC_SELF, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0108)
        EVT_LETTER_CHECK(Kolorado)
        EVT_CALL(EnableNpcAI, NPC_SELF, TRUE)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_0113)
        EVT_LETTER_CHECK(Kolorado)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kolorado)))
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
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
    EVT_IF_EQ(AF_KZN20_MisstarFlightDone, FALSE)
        EVT_CALL(SetNpcPos, NPC_SELF, -120, 70, 45)
        EVT_WAIT(30)
        EVT_SET(AF_KZN20_MisstarFlightDone, TRUE)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
        EVT_CALL(LoadPath, 60, EVT_PTR(N(FlightPath1)), ARRAY_COUNT(N(FlightPath1)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_NE(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_END_IF
    // wait for player to reach the top of the stairs
    EVT_LABEL(0)
        EVT_CALL(N(GetFloorCollider), LVar0)
        EVT_IF_NE(LVar0, COLLIDER_o870)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0))
        EVT_CALL(PlayerMoveTo, 60, 0, 0)
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_SET(AF_KZN_RumblingIntensified, FALSE)
    EVT_SET(MV_SceneState, SCENE_STATE_BEGIN)
    EVT_LABEL(10)
        EVT_SWITCH(MV_SceneState)
            EVT_CASE_EQ(SCENE_STATE_STARFISH_REMARK)
                EVT_SET(AF_KZN20_SceneSync, FALSE)
                EVT_THREAD
                    EVT_WAIT(30)
                    EVT_SET(MV_SceneState, SCENE_STATE_KOLORADO_LOOKS_AROUND)
                EVT_END_THREAD
                EVT_SET(AF_KZN20_SceneSync, TRUE)
            EVT_CASE_EQ(SCENE_STATE_KOLORADO_WENT_BACK)
                EVT_THREAD
                    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
                    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
                    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                    EVT_SET(MV_SceneState, SCENE_STATE_KOLORADO_CAM_SYNC)
                EVT_END_THREAD
                EVT_WAIT(10)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldMisstar_TalkAngry, ANIM_WorldMisstar_IdleAngry, 5, MSG_CH5_010E)
                EVT_LABEL(30)
                    EVT_IF_EQ(MV_SceneState, SCENE_STATE_KOLORADO_WENT_BACK)
                        EVT_WAIT(1)
                        EVT_GOTO(30)
                    EVT_END_IF
                EVT_SET(MV_SceneState, SCENE_STATE_KOLORADO_WARNED)
            EVT_CASE_EQ(SCENE_STATE_MISSTAR_SPEAKS)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldMisstar_TalkAngry, ANIM_WorldMisstar_IdleAngry, 0, MSG_CH5_0111)
                EVT_SET(MV_SceneState, SCENE_STATE_KOLORADO_RETURN)
            EVT_CASE_EQ(SCENE_STATE_SEARCH_FOR_EXIT)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
                EVT_WAIT(15)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
                EVT_WAIT(15)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
                EVT_WAIT(15)
                EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0))
                EVT_CALL(NpcMoveTo, NPC_SELF, 145, -10, 0)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
                EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 15, EMOTER_NPC, 0, 0, 0, 0)
                EVT_WAIT(20)
                EVT_CALL(SetNpcRotation, NPC_SELF, 0, -30, 0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_Back)
                EVT_CALL(SetNpcJumpscale, NPC_SELF, 0)
                EVT_CALL(NpcJump0, NPC_SELF, 170, 170, 50, 20)
                EVT_WAIT(5)
                EVT_CALL(SetNpcRotation, NPC_SELF, 0, -60, 0)
                EVT_CALL(SetNpcYaw, NPC_SELF, 270)
                EVT_CALL(NpcJump0, NPC_SELF, 145, 170, -10, 15)
                EVT_WAIT(10)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_IdleAngry)
                EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
                EVT_CALL(NpcJump1, NPC_SELF, 145, 160, -10, 5)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldMisstar_TalkAngry, ANIM_WorldMisstar_IdleAngry, 0, MSG_CH5_0112)
                EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
                EVT_SET(MV_SceneState, SCENE_STATE_DONE)
        EVT_END_SWITCH
        EVT_IF_NE(MV_SceneState, SCENE_STATE_DONE)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_LABEL(90)
        EVT_IF_LT(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
            EVT_WAIT(1)
            EVT_GOTO(90)
        EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(40)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Kolorado, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Panic)
        EVT_CALL(SetNpcSpeed, NPC_Kolorado, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Kolorado, 305, 0, 0)
        EVT_CALL(RemoveNpc, NPC_Kolorado)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.5))
    EVT_CALL(NpcJump0, NPC_SELF, 145, 195, -10, 5)
    EVT_WAIT(5)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldMisstar_Panic, ANIM_WorldMisstar_IdleAngry, 0, MSG_CH5_0115)
    EVT_WAIT(5)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_CALL(LoadPath, 30, EVT_PTR(N(FlightPath2)), ARRAY_COUNT(N(FlightPath2)), EASING_LINEAR)
    EVT_LABEL(91)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(91)
        EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Misstar) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldMisstar_TalkAngry, ANIM_WorldMisstar_IdleAngry, 0, MSG_CH5_0114)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Misstar) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_MT_LAVA_LAVA_ERUPTING)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_IdleAngry)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_Scene_Misstar)))
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Misstar)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { -65.0f, 0.0f, 190.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_10000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000,
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
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = MISSTAR_ANIMS,
    .tattle = MSG_NpcTattle_Misstar,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_Misstar)),
    {}
};
