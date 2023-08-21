#include "flo_13.h"
#include "sprite/player.h"

#include "world/common/util/ChangeNpcToPartner.inc.c"

NpcSettings N(NpcSettings_Lakilester) = {
    .height = 32,
    .radius = 24,
    .level = ACTOR_LEVEL_LAKITU,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#define AI_LAKITU_FIRST_SPINY_ID    NPC_Spiny_01
#define AI_LAKITU_LAST_SPINY_ID     NPC_Spiny_06
#include "world/common/enemy/Lakitu_SpinySpawner.inc.c"

#include "world/common/todo/UnkFunc42.inc.c"

API_CALLABLE(N(PlayLakiluluFlightSounds)) {
    Npc* npc = get_npc_unsafe(NPC_Lakilulu);
    s16 volume;
    s16 pan;

    script->functionTemp[1] = evt_get_variable(script, *script->ptrReadPos);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] % 5 == 0) {
        sfx_get_spatialized_sound_params(npc->pos.x, npc->pos.y, npc->pos.z,
            &volume, &pan, SOUND_PARAM_MORE_QUIET | SOUND_SPACE_FULL);
        sfx_play_sound_with_params(SOUND_FLIGHT, volume, pan,
            update_lerp(EASING_LINEAR, 500.0f, 0.0f, script->functionTemp[0], script->functionTemp[1]));
    }

    script->functionTemp[0]++;

    if (script->functionTemp[0] > script->functionTemp[1]) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(PlayLakilesterFlightSounds)) {
    Npc* npc = get_npc_unsafe(NPC_Lakilester);
    s16 volume;
    s16 pan;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] % 5 == 0) {
        sfx_get_spatialized_sound_params(npc->pos.x, npc->pos.y, npc->pos.z,
            &volume, &pan, SOUND_PARAM_MORE_QUIET | SOUND_SPACE_FULL);
        sfx_play_sound_with_params(SOUND_FLIGHT, volume, pan,
            update_lerp(EASING_LINEAR, 500.0f, 0.0f, script->functionTemp[0], 80));
    }

    script->functionTemp[0]++;

    if (script->functionTemp[0] > 80) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

Vec3f N(FlightPath_LakilesterAmbush)[] = {
    { -250.0,   130.0,  100.0 },
    { -150.0,    90.0,   70.0 },
    {   50.0,    70.0,   10.0 },
    {  200.0,    35.0,   30.0 },
    {   30.0,    10.0,   45.0 },
};

Vec3f N(FlightPath_LakiluluArrives)[] = {
    { -285.0,   130.0,   45.0 },
    { -185.0,    90.0,   25.0 },
    {   15.0,    70.0,   10.0 },
    {  165.0,    35.0,   30.0 },
    {   -5.0,    10.0,   45.0 },
};

Vec3f N(FlightPath_LakiluluDeparts)[] = {
    {   10.0,     0.0,   45.0 },
    {  -90.0,    20.0,   45.0 },
    { -190.0,    60.0,   45.0 },
    { -290.0,   140.0,   45.0 },
    { -390.0,   300.0,   45.0 },
};

EvtScript N(EVS_Lakliester_ManageYaw) = {
    EVT_CALL(GetNpcPos, NPC_Lakilester, LVar0, LVar1, LVar2)
    EVT_LABEL(0)
        EVT_CALL(GetNpcPos, NPC_Lakilester, LVar3, LVar4, LVar5)
        EVT_CALL(N(UnkFunc42))
        EVT_CALL(InterpNpcYaw, NPC_Lakilester, LVarA, 0)
        EVT_SET(LVar0, LVar3)
        EVT_SET(LVar1, LVar4)
        EVT_SET(LVar2, LVar5)
        EVT_CALL(GetAngleBetweenNPCs, NPC_PARTNER, NPC_Lakilester, LVarA)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, LVarA, 0)
        EVT_CALL(PlayerFaceNpc, NPC_Lakilester, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Laklilulu_ManageYaw) = {
    EVT_CALL(GetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
    EVT_LABEL(0)
        EVT_CALL(GetNpcPos, NPC_Lakilulu, LVar3, LVar4, LVar5)
        EVT_CALL(N(UnkFunc42))
        EVT_CALL(InterpNpcYaw, NPC_Lakilulu, LVarA, 0)
        EVT_SET(LVar0, LVar3)
        EVT_SET(LVar1, LVar4)
        EVT_SET(LVar2, LVar5)
        EVT_CALL(GetAngleBetweenNPCs, NPC_PARTNER, NPC_Lakilulu, LVarA)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, LVarA, 0)
        EVT_IF_LT(GB_StoryProgress, STORY_CH6_LAKILESTER_JOINED_PARTY)
            EVT_CALL(GetAngleBetweenNPCs, NPC_Lakilester, NPC_Lakilulu, LVarB)
            EVT_CALL(InterpNpcYaw, NPC_Lakilester, LVarB, 0)
        EVT_END_IF
        EVT_CALL(PlayerFaceNpc, NPC_Lakilulu, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LakiluluAndSpiny_HoverBobbing) = {
    EVT_SET(MV_LakiluluSpinySceneState, 0)
    EVT_LOOP(0)
        EVT_LOOP(2)
            EVT_CALL(GetNpcPos, NPC_Lakilulu_Spiny, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_Lakilulu_Spiny, LVar0, LVar1, LVar2)
            EVT_CALL(GetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
            EVT_WAIT(2)
        EVT_END_LOOP
        EVT_WAIT(1)
        EVT_LOOP(2)
            EVT_CALL(GetNpcPos, NPC_Lakilulu_Spiny, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, -1)
            EVT_CALL(SetNpcPos, NPC_Lakilulu_Spiny, LVar0, LVar1, LVar2)
            EVT_CALL(GetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, -1)
            EVT_CALL(SetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
            EVT_WAIT(2)
        EVT_END_LOOP
        EVT_WAIT(1)
        EVT_IF_EQ(MV_LakiluluSpinySceneState, 1)
            EVT_SET(MV_LakiluluSpinySceneState, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Lakilulu_SpinyToss) = {
    EVT_EXEC(N(EVS_LakiluluAndSpiny_HoverBobbing))
    EVT_CALL(SetNpcAnimation, NPC_Lakilulu, ANIM_Lakilulu_Lift)
    EVT_CALL(GetNpcPos, NPC_Lakilulu, LVar1, LVar2, LVar3)
    EVT_ADD(LVar1, -5)
    EVT_ADD(LVar2, 30)
    EVT_ADD(LVar3, 2)
    EVT_CALL(SetNpcYaw, NPC_Lakilulu_Spiny, 270)
    EVT_CALL(SetNpcPos, NPC_Lakilulu_Spiny, LVar1, LVar2, LVar3)
    EVT_THREAD
        EVT_WAIT(5 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
    EVT_END_THREAD
    EVT_CALL(ContinueSpeech, NPC_Lakilulu, -1, -1, SPEECH_FLAG_200, MSG_CH6_00A8)
    EVT_THREAD
        EVT_WAIT(15 * DT)
        EVT_CALL(EndSpeech, NPC_Lakilulu, -1, -1, SPEECH_FLAG_200)
    EVT_END_THREAD
    EVT_SET(MV_LakiluluSpinySceneState, 1)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(MV_LakiluluSpinySceneState, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_Lakilulu, ANIM_Lakilulu_Throw)
    EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
    EVT_ADD(LVar1, 5)
    EVT_ADD(LVar2, 20)
    EVT_CALL(SetNpcJumpscale, NPC_Lakilulu_Spiny, EVT_FLOAT(0.0))
    EVT_CALL(NpcJump0, NPC_Lakilulu_Spiny, LVar1, LVar2, LVar3, 7)
    EVT_ADD(LVar1, -100)
    EVT_ADD(LVar2, 10)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_Lakilulu_Spiny, EVT_FLOAT(1.5))
        EVT_CALL(NpcJump0, NPC_Lakilulu_Spiny, LVar1, LVar2, LVar3, 15 * DT)
        EVT_CALL(SetNpcPos, NPC_Lakilulu_Spiny, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(2.0))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtPlayer, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Hurt)
    EVT_SET(LVar0, 90)
    EVT_LOOP(20)
        EVT_ADD(LVar0, 144)
        EVT_IF_GT(LVar0, 359)
            EVT_SUB(LVar0, 360)
        EVT_END_IF
        EVT_CALL(InterpPlayerYaw, LVar0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Still)
    EVT_CALL(SetNpcAnimation, NPC_Lakilulu, ANIM_Lakilulu_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Lakilester) = {
    EVT_IF_NE(GB_StoryProgress, STORY_CH6_SPOKE_WITH_THE_SUN)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(AwaitPlayerApproach, 200, 20, 275)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcPos, NPC_Lakilester, -250, 120, 45)
    EVT_CALL(SetMusicTrack, 0, SONG_LAKILESTER_THEME, 0, 8)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH6_00A0, 160, 40)
    EVT_CALL(InterruptUsePartner)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_WAIT(20 * DT)
    EVT_CALL(InterpPlayerYaw, 270, 1)
    EVT_WAIT(20 * DT)
    EVT_CALL(InterpPlayerYaw, 90, 1)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Still)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(SetNpcAnimation, NPC_Lakilester, ANIM_WorldLakilester_Run)
    EVT_THREAD
        EVT_CALL(N(PlayLakilesterFlightSounds))
    EVT_END_THREAD
    EVT_EXEC_GET_TID(N(EVS_Lakliester_ManageYaw), LVar9)
    EVT_CALL(LoadPath, 80 * DT, EVT_PTR(N(FlightPath_LakilesterAmbush)), ARRAY_COUNT(N(FlightPath_LakilesterAmbush)), EASING_LINEAR)
    EVT_LABEL(0)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetNpcPos, NPC_Lakilester, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_KILL_THREAD(LVar9)
    EVT_CALL(SetNpcAnimation, NPC_Lakilester, ANIM_WorldLakilester_Idle)
    EVT_CALL(PlayerFaceNpc, NPC_Lakilester, FALSE)
    EVT_WAIT(15 * DT)
    EVT_CALL(GetNpcPos, NPC_Lakilester, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 200)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.0), EVT_FLOAT(-8.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_CALL(PlayerMoveTo, -75, 65, 10 * DT)
        EVT_CALL(PlayerFaceNpc, NPC_Lakilester, FALSE)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00A1)
    EVT_CALL(SetNpcAnimation, NPC_Lakilester, ANIM_WorldLakilester_Run)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Lakilester, ANIM_WorldLakilester_Idle)
    EVT_THREAD
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 1000)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Lakilulu_FlyAway) = {
    EVT_CALL(GetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
    EVT_CALL(AwaitPlayerLeave, LVar0, LVar2, 120)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(5.5), EVT_FLOAT(-7.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(NpcFaceNpc, NPC_Lakilulu, NPC_Lakilester, 1)
    EVT_CALL(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_00B4)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Lakilulu, 1)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 600)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(10.0), EVT_FLOAT(-8.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 130, -200)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_CALL(N(PlayLakiluluFlightSounds), 55 * DT)
    EVT_END_THREAD
    EVT_CALL(SetNpcFlagBits, NPC_Lakilulu, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_EXEC_GET_TID(N(EVS_Laklilulu_ManageYaw), LVar9)
    EVT_CALL(LoadPath, 55 * DT, EVT_PTR(N(FlightPath_LakiluluDeparts)), ARRAY_COUNT(N(FlightPath_LakiluluDeparts)), EASING_LINEAR)
    EVT_LABEL(20)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetNpcPos, NPC_Lakilulu, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_KILL_THREAD(LVar9)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_CALL(BringPartnerOut, PARTNER_LAKILESTER)
    EVT_IF_NE(LVar0, PARTNER_LAKILESTER)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.0))
        EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
        EVT_ADD(LVar1, 20)
        EVT_ADD(LVar2, 20)
        EVT_ADD(LVar3, 20)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar1, LVar2, LVar3, 30 * DT)
    EVT_END_IF
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_WAIT(5 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 5, MSG_CH6_00B5)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(PutPartnerAway)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_LakilesterDefeated) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Lakilester, ANIM_WorldLakilester_TiredTalk, ANIM_WorldLakilester_Tired, 0, MSG_CH6_00A2)
    EVT_CALL(SetNpcPos, NPC_Lakilulu, -290, 120, 45)
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldLakilester_Idle)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EVT_WAIT(20 * DT)
        EVT_CALL(InterpPlayerYaw, 270, 1)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 5, MSG_CH6_00A3)
    EVT_CALL(SetNpcAnimation, NPC_Lakilulu, ANIM_Lakilulu_Panic)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 500)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(5.5), EVT_FLOAT(-6.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 130, -200)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_THREAD
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
        EVT_CALL(SetCamPosB, CAM_DEFAULT, 130, 60)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(PlayLakiluluFlightSounds), 80 * DT)
    EVT_END_THREAD
    EVT_EXEC_GET_TID(N(EVS_Laklilulu_ManageYaw), LVar9)
    EVT_CALL(LoadPath, 80 * DT, EVT_PTR(N(FlightPath_LakiluluArrives)), ARRAY_COUNT(N(FlightPath_LakiluluArrives)), EASING_LINEAR)
    EVT_LABEL(0)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetNpcPos, NPC_Lakilulu, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_KILL_THREAD(LVar9)
    EVT_CALL(SetNpcAnimation, NPC_Lakilulu, ANIM_Lakilulu_ConcernedNod)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Still)
    EVT_WAIT(20 * DT)
    EVT_CALL(GetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(5.5), EVT_FLOAT(-7.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00A4)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Shout, ANIM_Lakilulu_Shout, 0, MSG_CH6_00A5)
    EVT_CALL(GetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Lakilester, ANIM_WorldLakilester_Shout, ANIM_WorldLakilester_IdleTough, 0, MSG_CH6_00A6)
    EVT_CALL(SetNpcAnimation, NPC_Lakilester, ANIM_WorldLakilester_Idle)
    EVT_CALL(EndSpeech, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(10.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_LABEL(10)
    EVT_CALL(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_ConcernedTalk, ANIM_Lakilulu_ConcernedNod, 0, MSG_CH6_00A7)
    EVT_CALL(ShowChoice, MSG_Choice_0020)
    EVT_IF_NE(LVar0, 0)
        EVT_EXEC_WAIT(N(EVS_Lakilulu_SpinyToss))
        EVT_WAIT(10 * DT)
        EVT_GOTO(10)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_00A9)
        EVT_CALL(SetNpcAnimation, NPC_Lakilulu, ANIM_Lakilulu_Idle)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Still)
        EVT_WAIT(20 * DT)
        EVT_CALL(GetNpcPos, NPC_Lakilulu, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 20)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SpeakToPlayer, NPC_Lakilester, ANIM_WorldLakilester_Shout, ANIM_WorldLakilester_IdleTough, 0, MSG_CH6_00AA)
        EVT_CALL(SetNpcAnimation, NPC_Lakilester, ANIM_WorldLakilester_Idle)
        EVT_CALL(EndSpeech, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 40)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_WAIT(10 * DT)
        EVT_CALL(SpeakToPlayer, NPC_Lakilester, ANIM_WorldLakilester_Shout, ANIM_WorldLakilester_IdleTough, 0, MSG_CH6_00AB)
        EVT_WAIT(10 * DT)
        EVT_CALL(ShowChoice, MSG_Choice_0021)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(-1)
            EVT_CASE_EQ(0)
                EVT_CALL(ContinueSpeech, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00AC)
            EVT_CASE_EQ(1)
                EVT_CALL(ContinueSpeech, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00AD)
            EVT_CASE_EQ(2)
                EVT_CALL(ContinueSpeech, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00AE)
            EVT_CASE_EQ(3)
                EVT_CALL(ContinueSpeech, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00AF)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(InterpNpcYaw, NPC_Lakilulu, 90, 1)
    EVT_CALL(SetNpcAnimation, NPC_Lakilulu, ANIM_Lakilulu_ConcernedNod)
    EVT_CALL(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_ConcernedTalk, ANIM_Lakilulu_ConcernedNod, 5, MSG_CH6_00B0)
    EVT_CALL(SpeakToPlayer, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00B1)
    EVT_WAIT(15 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_ConcernedTalk, ANIM_Lakilulu_ConcernedNod, 5, MSG_CH6_00B2)
    EVT_CALL(SpeakToPlayer, NPC_Lakilester, ANIM_WorldLakilester_Talk, ANIM_WorldLakilester_Idle, 0, MSG_CH6_00B3)
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetNpcSpeed, NPC_Lakilester, EVT_FLOAT(3.5 / DT))
    EVT_CALL(NpcMoveTo, NPC_Lakilester, LVar0, 60, 0)
    EVT_CALL(N(ChangeNpcToPartner), 0, 8)
    EVT_CALL(N(LoadPartyImage))
    EVT_EXEC(N(EVS_PushPartnerSong))
    EVT_WAIT(15 * DT)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0190, 160, 40)
    EVT_EXEC(N(EVS_PopSong))
    EVT_WAIT(10 * DT)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_SET(GB_StoryProgress, STORY_CH6_LAKILESTER_JOINED_PARTY)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_EXEC_WAIT(N(EVS_Lakilulu_FlyAway))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Lakilester) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldLakilester_Tired)
            EVT_CALL(SetCamType, CAM_DEFAULT, 6, TRUE)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar1, LVar2)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, LVar3)
            EVT_DIV(LVar0, 2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-7.5))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_EXEC(N(EVS_Scene_LakilesterDefeated))
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Lakilulu) = {
    EVT_IF_LE(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_0032)
    EVT_ELSE
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_IF_NE(LVar0, PARTNER_LAKILESTER)
            EVT_CALL(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_0034)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_Lakilulu, ANIM_Lakilulu_Talk, ANIM_Lakilulu_Idle, 0, MSG_CH6_0032)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Lakilester) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_LAKILESTER_JOINED_PARTY)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Lakilester)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Lakilester)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Lakilulu) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Lakilulu)))
        EVT_CALL(SetNpcCollisionSize, NPC_SELF, 36, 28)
        EVT_IF_GE(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            EVT_CALL(SetNpcPos, NPC_SELF, -50, 180, -50)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Lakilulu_Spiny) = {
    EVT_CALL(SetNpcPos, NPC_Lakilulu_Spiny, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcAnimation, NPC_Lakilulu_Spiny, ANIM_Lakilulu_Spiny)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Lakitu) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH6_SPOKE_WITH_THE_SUN)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Spiny) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH6_SPOKE_WITH_THE_SUN)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_CALL(SetSelfVar, 13, 1)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Lakilester) = {
    .id = NPC_Lakilester,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Lakilester),
    .settings = &N(NpcSettings_Lakilester),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_WorldLakilester_Idle,
        .walk   = ANIM_WorldLakilester_Idle,
        .run    = ANIM_WorldLakilester_Idle,
        .chase  = ANIM_WorldLakilester_Idle,
        .anim_4 = ANIM_WorldLakilester_Idle,
        .anim_5 = ANIM_WorldLakilester_Idle,
        .death  = ANIM_WorldLakilester_Idle,
        .hit    = ANIM_WorldLakilester_Idle,
        .anim_8 = ANIM_WorldLakilester_Idle,
        .anim_9 = ANIM_WorldLakilester_Idle,
        .anim_A = ANIM_WorldLakilester_Idle,
        .anim_B = ANIM_WorldLakilester_Idle,
        .anim_C = ANIM_WorldLakilester_Idle,
        .anim_D = ANIM_WorldLakilester_Idle,
        .anim_E = ANIM_WorldLakilester_Idle,
        .anim_F = ANIM_WorldLakilester_Idle,
    },
};

NpcData N(NpcData_Lakilulu) = {
    .id = NPC_Lakilulu,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Lakilulu),
    .settings = &N(NpcSettings_Lakilester),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Lakilulu_Idle,
        .walk   = ANIM_Lakilulu_Idle,
        .run    = ANIM_Lakilulu_Idle,
        .chase  = ANIM_Lakilulu_Idle,
        .anim_4 = ANIM_Lakilulu_Idle,
        .anim_5 = ANIM_Lakilulu_Idle,
        .death  = ANIM_Lakilulu_Idle,
        .hit    = ANIM_Lakilulu_Idle,
        .anim_8 = ANIM_Lakilulu_Idle,
        .anim_9 = ANIM_Lakilulu_Idle,
        .anim_A = ANIM_Lakilulu_Idle,
        .anim_B = ANIM_Lakilulu_Idle,
        .anim_C = ANIM_Lakilulu_Idle,
        .anim_D = ANIM_Lakilulu_Idle,
        .anim_E = ANIM_Lakilulu_Idle,
        .anim_F = ANIM_Lakilulu_Idle,
    },
    .tattle = MSG_NpcTattle_Lakilulu,
};

NpcData N(NpcData_Lakilulu_Spiny) = {
    .id = NPC_Lakilulu_Spiny,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Lakilulu_Spiny),
    .settings = &N(NpcSettings_Lakilester),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Lakilulu_Idle,
        .walk   = ANIM_Lakilulu_Idle,
        .run    = ANIM_Lakilulu_Idle,
        .chase  = ANIM_Lakilulu_Idle,
        .anim_4 = ANIM_Lakilulu_Idle,
        .anim_5 = ANIM_Lakilulu_Idle,
        .death  = ANIM_Lakilulu_Idle,
        .hit    = ANIM_Lakilulu_Idle,
        .anim_8 = ANIM_Lakilulu_Idle,
        .anim_9 = ANIM_Lakilulu_Idle,
        .anim_A = ANIM_Lakilulu_Idle,
        .anim_B = ANIM_Lakilulu_Idle,
        .anim_C = ANIM_Lakilulu_Idle,
        .anim_D = ANIM_Lakilulu_Idle,
        .anim_E = ANIM_Lakilulu_Idle,
        .anim_F = ANIM_Lakilulu_Idle,
    },
};

NpcData N(NpcData_Lakitu_01) = {
    .id = NPC_Lakitu_01,
    .pos = { 335.0f, 90.0f, 45.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 335, 90, 45 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 335, 90, 45 },
            .detectSize = { 250 },
        }
    },
    .init = &N(EVS_NpcInit_Lakitu),
    .settings = &N(NpcSettings_Lakitu_SpinySpawner),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = LAKITU_DROPS,
    .animations = LAKITU_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Lakitu_02) = {
    .id = NPC_Lakitu_02,
    .pos = { -320.0f, 90.0f, 0.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -320, 90, 0 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -320, 90, 0 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_Lakitu),
    .settings = &N(NpcSettings_Lakitu_SpinySpawner),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = LAKITU_DROPS,
    .animations = LAKITU_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_01) = {
    .id = NPC_Spiny_01,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
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
    .init = &N(EVS_NpcInit_Spiny),
    .settings = &N(NpcSettings_SpawnedSpiny),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_02) = {
    .id = NPC_Spiny_02,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
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
    .init = &N(EVS_NpcInit_Spiny),
    .settings = &N(NpcSettings_SpawnedSpiny),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_03) = {
    .id = NPC_Spiny_03,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
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
    .init = &N(EVS_NpcInit_Spiny),
    .settings = &N(NpcSettings_SpawnedSpiny),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_04) = {
    .id = NPC_Spiny_04,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
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
    .init = &N(EVS_NpcInit_Spiny),
    .settings = &N(NpcSettings_SpawnedSpiny),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_05) = {
    .id = NPC_Spiny_05,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
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
    .init = &N(EVS_NpcInit_Spiny),
    .settings = &N(NpcSettings_SpawnedSpiny),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_06) = {
    .id = NPC_Spiny_06,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
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
    .init = &N(EVS_NpcInit_Spiny),
    .settings = &N(NpcSettings_SpawnedSpiny),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Lakitu_01), BTL_FLO_FORMATION_06, BTL_FLO_STAGE_04),
    NPC_GROUP(N(NpcData_Lakitu_02), BTL_FLO_FORMATION_04, BTL_FLO_STAGE_04),
    NPC_GROUP(N(NpcData_Spiny_01), BTL_FLO_FORMATION_0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_02), BTL_FLO_FORMATION_0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_03), BTL_FLO_FORMATION_0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_04), BTL_FLO_FORMATION_0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_05), BTL_FLO_FORMATION_0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_06), BTL_FLO_FORMATION_0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Lakilester), BTL_FLO2_FORMATION_05, BTL_FLO2_STAGE_01),
    NPC_GROUP(N(NpcData_Lakilulu)),
    NPC_GROUP(N(NpcData_Lakilulu_Spiny)),
    {}
};
