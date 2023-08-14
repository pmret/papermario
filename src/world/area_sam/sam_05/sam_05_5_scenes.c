#include "sam_05.h"
#include "effects.h"

EvtScript N(EVS_Scene_MonstarAppears) = {
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_IF_LT(LVar0, 450)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterruptUsePartner)
    EVT_CALL(SetMusicTrack, 0, SONG_MONSTAR_THEME, 0, 8)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH7_00E0, 160, 40)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Monstar_Idle1)
    EVT_CALL(SetNpcPos, NPC_Monstar, 635, 85, 0)
    EVT_CALL(NpcMoveTo, NPC_Monstar, 615, 0, 10 * DT)
    EVT_LABEL(2)
    EVT_CALL(GetNpcPos, NPC_Monstar, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-15.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_ADD(LVar0, -25)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(SetNpcPos, NPC_Monstar, 615, 85, 0)
        EVT_WAIT(1)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Monstar, ANIM_Monstar_Talk, ANIM_Monstar_Idle1, 256, 50, 100, MSG_CH7_00E1)
    EVT_CALL(SetPlayerPos, 495, 80, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Monstar, LVar3, LVar4, LVar5)
    EVT_ADDF(LVar0, LVar3)
    EVT_ADDF(LVar1, LVar4)
    EVT_ADDF(LVar2, LVar5)
    EVT_DIVF(LVar0, EVT_FLOAT(2.0))
    EVT_DIVF(LVar1, EVT_FLOAT(2.0))
    EVT_DIVF(LVar2, EVT_FLOAT(2.0))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(425.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-9.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(5 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Monstar, ANIM_Monstar_Talk, ANIM_Monstar_Idle1, 256, 0, 100, MSG_CH7_00E2)
    EVT_CALL(ShowChoice, MSG_Choice_0015)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ContinueSpeech, NPC_Monstar, ANIM_Monstar_HappyTalk, ANIM_Monstar_HappyTalk, 256, 0, 100, MSG_CH7_00E3)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(450.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-5.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Monstar_Idle1)
        EVT_EXEC(N(EVS_SetupMusic))
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_LABEL(4)
        EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
        EVT_WAIT(1)
        EVT_IF_GT(LVar3, LVar0)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(InterruptUsePartner)
            EVT_CALL(SetMusicTrack, 0, SONG_MONSTAR_THEME, 0, 8)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_IF_GT(LVar3, 420)
            EVT_GOTO(4)
        EVT_END_IF
        EVT_CALL(SetNpcPos, NPC_Monstar, NPC_DISPOSE_LOCATION)
        EVT_SET(LFlag0, FALSE)
        EVT_GOTO(0)
    EVT_ELSE
        EVT_CALL(CloseMessage)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Monstar_RearUp)
        EVT_CALL(GetNpcPos, NPC_Monstar, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -35)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-12.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SpeakToPlayer, NPC_Monstar, ANIM_Monstar_RearUp, ANIM_Monstar_RearUp, 256, 0, 200, MSG_CH7_00E4)
        EVT_CALL(SetNpcVar, NPC_Monstar, 0, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

// npcID followed by initial pos Vec3i
s32 N(StarKidList)[] = {
    NPC_StarKid_01, 615, 129, 0,
    NPC_StarKid_02, 612, 157, 2,
    NPC_StarKid_03, 606, 146, 4,
    NPC_StarKid_04, 649, 140, 6,
    NPC_StarKid_05, 625, 145, 0,
    NPC_StarKid_06, 580, 131, 4,
    NPC_StarKid_07, 630,  88, 6,
    NPC_StarKid_08, 635, 134, 0,
    NPC_StarKid_09, 625, 121, 2,
    NPC_StarKid_10, 590, 122, 4,
    NPC_StarKid_11, 595, 108, 6,
    NPC_StarKid_12, 600, 132, 0,
    NPC_StarKid_13, 604,  99, 2,
    NPC_StarKid_14, 610, 114, 4,
    NPC_StarKid_15, 635, 112, 6,
    NPC_StarKid_16, 620,  96, 0,
    -1,
};

Vec3f N(RelativeFleePath)[] = {
    {    0.0,     0.0,    0.0 },
    {   40.0,    10.0,    0.0 },
    {   50.0,    15.0,    0.0 },
    {   70.0,    25.0,    0.0 },
    {   80.0,    30.0,    0.0 },
    {  100.0,    35.0,    0.0 },
    {  200.0,    45.0,    0.0 },
};

EvtScript N(EVS_StarKid_LookAroundPanic) = {
    EVT_CALL(RandInt, 4, LVar0)
    EVT_WAIT(LVar0)
    EVT_LOOP(0)
        EVT_CALL(InterpNpcYaw, LVarA, 90, 0)
        EVT_WAIT(7 * DT)
        EVT_CALL(InterpNpcYaw, LVarA, 270, 0)
        EVT_WAIT(7 * DT)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StarKid_RunAway) = {
    EVT_IF_EQ(LVarA, NPC_StarKid_01)
        EVT_ADD(LVarB, 40 * DT)
    EVT_END_IF
    EVT_EXEC_GET_TID(N(EVS_StarKid_LookAroundPanic), LVar9)
    EVT_ADD(LVarB, 20 * DT)
    EVT_WAIT(LVarB)
    EVT_KILL_THREAD(LVar9)
    EVT_CALL(PlaySoundAtNpc, LVarA, SOUND_STAR_KID_FLYING, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetNpcPos, LVarA, LVar7, LVar8, LVar9)
    EVT_CALL(LoadPath, 60 * DT, EVT_PTR(N(RelativeFleePath)), ARRAY_COUNT(N(RelativeFleePath)), EASING_LINEAR)
    EVT_LABEL(0)
        EVT_CALL(GetNextPathPos)
        EVT_ADD(LVar1, LVar7)
        EVT_ADD(LVar2, LVar8)
        EVT_ADD(LVar3, LVar9)
        EVT_CALL(SetNpcPos, LVarA, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(SetNpcPos, LVarA, NPC_DISPOSE_LOCATION)
    EVT_CALL(EnableNpcShadow, LVar0, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StarKid_SpawnSparkles) = {
    EVT_LOOP(20)
        EVT_CALL(RandInt, 80, LVar0)
        EVT_CALL(RandInt, 80, LVar1)
        EVT_ADD(LVar0, 575)
        EVT_ADD(LVar1, 89)
        EVT_ADD(LVar2, 0)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 1, LVar0, LVar1, LVar2, 7)
        EVT_WAIT(2)
        EVT_CALL(RandInt, 80, LVar0)
        EVT_CALL(RandInt, 80, LVar1)
        EVT_ADD(LVar0, 575)
        EVT_ADD(LVar1, 89)
        EVT_ADD(LVar2, 0)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 1, LVar0, LVar1, LVar2, 7)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StarKidsFlee) = {
    EVT_USE_BUF(EVT_PTR(N(StarKidList)))
    EVT_LOOP(0)
        EVT_BUF_READ4(LVar0, LVar1, LVar2, LVar3)
        EVT_IF_EQ(LVar0, -1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtNpc, NPC_Monstar, SOUND_MONSTAR_BREAKS_APART, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_Monstar, 615, -5, 10 * DT)
    EVT_END_THREAD
    EVT_EXEC(N(EVS_StarKid_SpawnSparkles))
    EVT_CALL(MakeLerp, 220, 0, 90, EASING_COS_IN_OUT)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetNpcVar, NPC_Monstar, 3, LVar0)
    EVT_SET(LVar2, 255)
    EVT_SUB(LVar2, LVar0)
    EVT_USE_BUF(EVT_PTR(N(StarKidList)))
    EVT_LOOP(0)
        EVT_BUF_READ4(LVarA, LVar9, LVar9, LVar9)
        EVT_IF_EQ(LVarA, -1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(SetNpcImgFXParams, LVarA, IMGFX_SET_ALPHA, LVar2, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_Monstar, NPC_DISPOSE_LOCATION)
    EVT_WAIT(10 * DT)
    EVT_USE_BUF(EVT_PTR(N(StarKidList)))
    EVT_SET(LVarB, 0)
    EVT_LOOP(0)
        EVT_BUF_READ4(LVarA, LVar9, LVar9, LVar9)
        EVT_IF_EQ(LVarA, -1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_EXEC(N(EVS_StarKid_RunAway))
        EVT_ADD(LVarB, 1)
    EVT_END_LOOP
    EVT_WAIT(100 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_MonstarDefeated) = {
    EVT_CALL(ClearDefeatedEnemies)
    EVT_CALL(SetNpcFlagBits, NPC_Monstar, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcPos, NPC_Monstar, 615, 87, -4)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Monstar_Flail)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Monstar, LVar3, LVar4, LVar5)
    EVT_ADDF(LVar0, LVar3)
    EVT_ADDF(LVar1, LVar4)
    EVT_ADDF(LVar2, LVar5)
    EVT_DIVF(LVar0, EVT_FLOAT(2.0))
    EVT_DIVF(LVar1, EVT_FLOAT(2.0))
    EVT_DIVF(LVar2, EVT_FLOAT(2.0))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(375.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-9.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Monstar, ANIM_Monstar_Flail, ANIM_Monstar_Flail, 256, 170, 150, MSG_CH7_00E8)
    EVT_EXEC_WAIT(N(EVS_StarKidsFlee))
    EVT_SET(GB_StoryProgress, STORY_CH7_DEFEATED_MONSTAR)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(450.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-5.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
