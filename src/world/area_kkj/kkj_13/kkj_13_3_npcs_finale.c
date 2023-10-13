#include "kkj_13.h"
#include "sprite/player.h"

#include "world/common/npc/Peach.h"

#include "world/common/npc/Bowser.inc.c"
#include "world/common/npc/Dummy.inc.c"

API_CALLABLE(N(UpdatePropellerSoundPos)) {
    Npc* npc = get_npc_safe(NPC_Bowser_Prop);
    f32 x = npc->pos.x;
    f32 y = npc->pos.y;
    f32 z = npc->pos.z;

    sfx_adjust_env_sound_pos(SOUND_LRAW_BOWSER_PROPELLER, SOUND_SPACE_DEFAULT, x, y, z);
    script->varTable[0] = y;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_UpdatePropellerSounds) = {
    EVT_CALL(PlaySoundAtNpc, NPC_Bowser_Prop, SOUND_LOOP_BOWSER_PROPELLER, SOUND_SPACE_DEFAULT)
    EVT_LOOP(0)
        EVT_CALL(N(UpdatePropellerSoundPos))
        EVT_IF_LT(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_IF_EQ(GF_KKJ13_BowserTaunts, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(StopSound, SOUND_LOOP_BOWSER_PROPELLER)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MoveToBattlePositions) = {
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_Bowser_Prop, NPC_DISPOSE_LOCATION)
        EVT_CALL(PlayerMoveTo, 525, 0, 50)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 600, 0, 0)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 600, 0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetNpcJumpscale, NPC_Bowser_Body, EVT_FLOAT(0.0))
        EVT_CALL(NpcJump0, NPC_Bowser_Body, 675, 0, 0, 10)
        EVT_CALL(PlaySoundAtNpc, NPC_Bowser_Body, SOUND_LARGE_NPC_IMPACT, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Jump)
        EVT_WAIT(5)
        EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Land)
        EVT_WAIT(5)
        EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_PostJump)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(2.0))
        EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Idle)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_MarioConfrontsBowser) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_KKJ13_BowserTaunts, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcPos, NPC_Bowser_Body, 725, 210, -25)
    EVT_CALL(SetNpcPos, NPC_Bowser_Prop, 725, 210, -25)
    EVT_EXEC(N(EVS_UpdatePropellerSounds))
    EVT_CALL(SpeakToPlayer, NPC_CaptivePeach, ANIM_Peach2_TiedHangStruggle, ANIM_Peach2_TiedHangIdle, 0, MSG_CH8_006F)
    EVT_CALL(EnableNpcShadow, NPC_Bowser_Body, FALSE)
    EVT_CALL(SetCamType, CAM_DEFAULT, 1, FALSE)
    EVT_SET(LVar0, 725)
    EVT_SET(LVar1, 50)
    EVT_SET(LVar2, -25)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(11.0), EVT_FLOAT(-2.5))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 600)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(85.0), EVT_FLOAT(-3.5))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(210.0), EVT_FLOAT(240.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(60)
    EVT_CALL(EnableNpcShadow, NPC_Bowser_Body, TRUE)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_Bowser_Body, EVT_FLOAT(0.0))
        EVT_CALL(NpcJump0, NPC_Bowser_Body, 725, 50, -25, 20)
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_Bowser_Prop, EVT_FLOAT(0.0))
    EVT_CALL(NpcJump0, NPC_Bowser_Prop, 725, 50, -25, 20)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, NPC_Bowser_Body, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-12.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(72.5), EVT_FLOAT(-25.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(210.0), EVT_FLOAT(240.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarTalk, ANIM_WorldBowser_ClownCarIdle, 0, MSG_CH8_0070)
    EVT_WAIT(5)
    EVT_CALL(GetNpcPos, NPC_CaptivePeach, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 325)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(72.0), EVT_FLOAT(0.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(170.0), EVT_FLOAT(240.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_CaptivePeach, ANIM_Peach2_TiedHangStruggle, ANIM_Peach2_TiedHangIdle, 0, MSG_CH8_0071)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerPos, 400, 0, -15)
    EVT_CALL(PartnerIsFlying, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 370, 20, -15)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_PARTNER, 370, 0, -15)
    EVT_END_IF
    EVT_CALL(ClearPartnerMoveHistory, NPC_PARTNER)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_EXEC_WAIT(N(EVS_MoveToBattlePositions))
    EVT_WAIT(50)
    EVT_CALL(SpeakToPlayer, NPC_Bowser_Body, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_CH8_0072)
    EVT_WAIT(10)
    EVT_CALL(SetNpcVar, NPC_Bowser_Body, 0, 1)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(PlayerMoveTo, 580, 0, 25)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Walk)
        EVT_CALL(NpcMoveTo, NPC_Bowser_Body, 630, 0, 25)
        EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Idle)
    EVT_END_THREAD
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_BowserAwaitBattle) = {
    EVT_LABEL(0)
        EVT_CALL(SetSelfVar, 0, 0)
        EVT_LOOP(0)
            EVT_CALL(GetSelfVar, 0, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(StartBossBattle, SONG_BOWSER_THEME)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

Vec3f N(ToWindowPath)[] = {
    {  800.0,    50.0,    0.0 },
    {  780.0,    40.0,    0.0 },
    {  700.0,    20.0,    5.0 },
    {  620.0,    15.0,   15.0 },
    {  610.0,    25.0,    0.0 },
    {  595.0,    50.0,  -15.0 },
};

Vec3f N(ThroughWindowPath)[] = {
    {  595.0,    50.0,  -15.0 },
    {  595.0,    45.0, -150.0 },
    {  595.0,    35.0, -170.0 },
    {  595.0,    40.0, -190.0 },
};

Vec3f N(UpAndAwayPath)[] = {
    {  595.0,    40.0, -190.0 },
    {  595.0,   145.0, -185.0 },
    {  595.0,   250.0, -180.0 },
};

EvtScript N(EVS_FlyBowserAndPeach) = {
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Bowser_Body, LVar1, LVar2, LVar3)
        EVT_CALL(SetNpcPos, NPC_Bowser_Prop, LVar1, LVar2, LVar3)
        EVT_ADD(LVar1, 28)
        EVT_ADD(LVar2, 40)
        EVT_ADD(LVar3, -3)
        EVT_CALL(SetNpcPos, NPC_CaptivePeach, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BowserFliesAway) = {
    EVT_CALL(SetNpcPos, NPC_Bowser_Body, 800, 0, 0)
    EVT_CALL(SetNpcYaw, NPC_Bowser_Body, 270)
    EVT_CALL(SetNpcPos, NPC_Bowser_Prop, 800, 0, 0)
    EVT_CALL(SetNpcYaw, NPC_Bowser_Prop, 270)
    EVT_CALL(SetNpcPos, NPC_CaptivePeach, 828, 90, -3)
    EVT_EXEC(N(EVS_UpdatePropellerSounds))
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
        EVT_WAIT(20)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_CALL(InterpPlayerYaw, 0, 1)
    EVT_END_THREAD
    EVT_CALL(LoadPath, 25, EVT_PTR(N(ToWindowPath)), ARRAY_COUNT(N(ToWindowPath)), EASING_LINEAR)
    EVT_EXEC_WAIT(N(EVS_FlyBowserAndPeach))
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarLaugh)
    EVT_WAIT(40)
    EVT_CALL(LoadPath, 25, EVT_PTR(N(ThroughWindowPath)), ARRAY_COUNT(N(ThroughWindowPath)), EASING_LINEAR)
    EVT_EXEC_WAIT(N(EVS_FlyBowserAndPeach))
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarIdle)
    EVT_WAIT(15)
    EVT_CALL(LoadPath, 25, EVT_PTR(N(UpAndAwayPath)), ARRAY_COUNT(N(UpAndAwayPath)), EASING_LINEAR)
    EVT_EXEC(N(EVS_FlyBowserAndPeach))
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BowserDefeated) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 1)
    EVT_CALL(EnableGroup, MODEL_g153, FALSE)
    EVT_CALL(SetPlayerPos, 525, 0, 0)
    EVT_CALL(PartnerIsFlying, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_SET(LVar1, 10)
    EVT_ELSE
        EVT_SET(LVar1, 0)
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_PARTNER, 490, LVar1, 0)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
    EVT_CALL(SetNpcPos, NPC_Bowser_Body, 675, 0, 0)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(90.0), 75, 450, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Tantrum)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Idle)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Bowser_Body, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_CH8_0078)
    EVT_WAIT(20)
    EVT_CALL(InterpNpcYaw, NPC_Bowser_Body, 90, 1)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Walk)
    EVT_CALL(NpcMoveTo, NPC_Bowser_Body, 800, 0, 20)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarIdle)
    EVT_CALL(SetNpcAnimation, NPC_CaptivePeach, ANIM_Peach2_TiedIdle)
    EVT_CALL(SpeakToPlayer, NPC_CaptivePeach, ANIM_Peach2_TiedHangStruggle, ANIM_Peach2_TiedHangIdle, 0, MSG_CH8_0079)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(PlayerMoveTo, 580, 0, 10)
    EVT_EXEC_WAIT(N(EVS_BowserFliesAway))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Bowser_Body, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_CH8_007A)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_SET(GF_KKJ13_BowserTaunts, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Bowser_Body) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_2, TRUE)
            EVT_EXEC(N(EVS_Scene_BowserDefeated))
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bowser_Body) = {
    EVT_CALL(SetNpcPos, NPC_Bowser_Body, NPC_DISPOSE_LOCATION)
    EVT_IF_EQ(GF_KKJ13_BowserTaunts, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_BowserAwaitBattle)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Bowser_Body)))
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarIdle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bowser_Prop) = {
    EVT_CALL(EnableNpcShadow, NPC_Bowser_Prop, FALSE)
    EVT_CALL(SetNpcPos, NPC_Bowser_Prop, NPC_DISPOSE_LOCATION)
    EVT_IF_EQ(GF_KKJ13_BowserTaunts, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Prop, ANIM_WorldBowser_ClownCarPropeller)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_CaptivePeach) = {
    EVT_CALL(SetNpcPos, NPC_CaptivePeach, NPC_DISPOSE_LOCATION)
    EVT_IF_EQ(GF_KKJ13_BowserTaunts, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_CaptivePeach, 775, 90, 0)
    EVT_CALL(SetNpcAnimation, NPC_CaptivePeach, ANIM_Peach2_TiedHangStruggle)
    EVT_RETURN
    EVT_END
};

AnimID N(ExtraAnims_Bowser)[] = {
    ANIM_WorldBowser_Still,
    ANIM_WorldBowser_Idle,
    ANIM_WorldBowser_Walk,
    ANIM_WorldBowser_Run,
    ANIM_WorldBowser_Talk,
    ANIM_WorldBowser_Jump,
    ANIM_WorldBowser_Land,
    ANIM_WorldBowser_PostJump,
    ANIM_WorldBowser_ClownCarIdle,
    ANIM_WorldBowser_Tantrum,
    ANIM_WorldBowser_ClownCarTalk,
    ANIM_WorldBowser_ClownCarLaugh,
    ANIM_WorldBowser_ClownCarPropeller,
    ANIM_LIST_END
};

NpcData N(NpcData_Bowser_Body) = {
    .id = NPC_Bowser_Body,
    .pos = { 0.0f, -500.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Bowser_Body),
    .settings = &N(NpcSettings_Bowser),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = BOWSER_ANIMS,
    .extraAnimations = N(ExtraAnims_Bowser),
};

NpcData N(NpcData_Bowser_Prop) = {
    .id = NPC_Bowser_Prop,
    .pos = { 0.0f, -500.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Bowser_Prop),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = BOWSER_ANIMS,
    .extraAnimations = N(ExtraAnims_Bowser),
};

NpcData N(NpcData_CaptivePeach) = {
    .id = NPC_CaptivePeach,
    .pos = { 670.0f, 0.0f, -12.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_CaptivePeach),
    .settings = &N(NpcSettings_Dummy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_PLAYER_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = PEACH_ANIMS,
};

NpcGroupList N(ChapterNPCs) = {
    NPC_GROUP(N(NpcData_Bowser_Body), BTL_KPA2_FORMATION_02),
    NPC_GROUP(N(NpcData_Bowser_Prop), BTL_KPA2_FORMATION_02),
    NPC_GROUP(N(NpcData_CaptivePeach)),
    {}
};
