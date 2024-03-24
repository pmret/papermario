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
    Call(PlaySoundAtNpc, NPC_Bowser_Prop, SOUND_LOOP_BOWSER_PROPELLER, SOUND_SPACE_DEFAULT)
    Loop(0)
        Call(N(UpdatePropellerSoundPos))
        IfLt(LVar0, 0)
            BreakLoop
        EndIf
        IfEq(GF_KKJ13_BowserTaunts, TRUE)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(StopSound, SOUND_LOOP_BOWSER_PROPELLER)
    Return
    End
};

EvtScript N(EVS_MoveToBattlePositions) = {
    Thread
        Call(SetNpcPos, NPC_Bowser_Prop, NPC_DISPOSE_LOCATION)
        Call(PlayerMoveTo, 525, 0, 50)
        Call(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
    EndThread
    Thread
        Call(UseSettingsFrom, CAM_DEFAULT, 600, 0, 0)
        Call(SetPanTarget, CAM_DEFAULT, 600, 0, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.5))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Thread
        Wait(20)
        Call(SetNpcJumpscale, NPC_Bowser_Body, Float(0.0))
        Call(NpcJump0, NPC_Bowser_Body, 675, 0, 0, 10)
        Call(PlaySoundAtNpc, NPC_Bowser_Body, SOUND_LARGE_NPC_IMPACT, SOUND_SPACE_DEFAULT)
    EndThread
    Thread
        Wait(20)
        Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Jump)
        Wait(5)
        Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Land)
        Wait(5)
        Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_PostJump)
        Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(2.0))
        Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Idle)
    EndThread
    Return
    End
};

EvtScript N(EVS_Scene_MarioConfrontsBowser) = {
    IfLt(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
        Return
    EndIf
    IfEq(GF_KKJ13_BowserTaunts, TRUE)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(SetNpcPos, NPC_Bowser_Body, 725, 210, -25)
    Call(SetNpcPos, NPC_Bowser_Prop, 725, 210, -25)
    Exec(N(EVS_UpdatePropellerSounds))
    Call(SpeakToPlayer, NPC_CaptivePeach, ANIM_Peach2_TiedHangStruggle, ANIM_Peach2_TiedHangIdle, 0, MSG_CH8_006F)
    Call(EnableNpcShadow, NPC_Bowser_Body, FALSE)
    Call(SetCamType, CAM_DEFAULT, 1, FALSE)
    Set(LVar0, 725)
    Set(LVar1, 50)
    Set(LVar2, -25)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(11.0), Float(-2.5))
    Call(SetCamDistance, CAM_DEFAULT, 600)
    Call(SetCamPosA, CAM_DEFAULT, Float(85.0), Float(-3.5))
    Call(SetCamPosB, CAM_DEFAULT, Float(210.0), Float(240.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(60)
    Call(EnableNpcShadow, NPC_Bowser_Body, TRUE)
    Thread
        Call(SetNpcJumpscale, NPC_Bowser_Body, Float(0.0))
        Call(NpcJump0, NPC_Bowser_Body, 725, 50, -25, 20)
    EndThread
    Call(SetNpcJumpscale, NPC_Bowser_Prop, Float(0.0))
    Call(NpcJump0, NPC_Bowser_Prop, 725, 50, -25, 20)
    Wait(10)
    Call(GetNpcPos, NPC_Bowser_Body, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-12.0))
    Call(SetCamDistance, CAM_DEFAULT, 350)
    Call(SetCamPosA, CAM_DEFAULT, Float(72.5), Float(-25.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(210.0), Float(240.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10)
    Call(SpeakToPlayer, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarTalk, ANIM_WorldBowser_ClownCarIdle, 0, MSG_CH8_0070)
    Wait(5)
    Call(GetNpcPos, NPC_CaptivePeach, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-7.0))
    Call(SetCamDistance, CAM_DEFAULT, 325)
    Call(SetCamPosA, CAM_DEFAULT, Float(72.0), Float(0.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(170.0), Float(240.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(20)
    Call(SpeakToPlayer, NPC_CaptivePeach, ANIM_Peach2_TiedHangStruggle, ANIM_Peach2_TiedHangIdle, 0, MSG_CH8_0071)
    Wait(20)
    Call(SetPlayerPos, 400, 0, -15)
    Call(PartnerIsFlying, LVar0)
    IfEq(LVar0, FALSE)
        Call(SetNpcPos, NPC_PARTNER, 370, 20, -15)
    Else
        Call(SetNpcPos, NPC_PARTNER, 370, 0, -15)
    EndIf
    Call(ClearPartnerMoveHistory, NPC_PARTNER)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    ExecWait(N(EVS_MoveToBattlePositions))
    Wait(50)
    Call(SpeakToPlayer, NPC_Bowser_Body, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_CH8_0072)
    Wait(10)
    Call(SetNpcVar, NPC_Bowser_Body, 0, 1)
    Wait(10)
    Thread
        Call(PlayerMoveTo, 580, 0, 25)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Walk)
        Call(NpcMoveTo, NPC_Bowser_Body, 630, 0, 25)
        Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Idle)
    EndThread
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_BowserAwaitBattle) = {
    Label(0)
        Call(SetSelfVar, 0, 0)
        Loop(0)
            Call(GetSelfVar, 0, LVar0)
            IfNe(LVar0, 0)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Call(StartBossBattle, SONG_BOWSER_THEME)
        Goto(0)
    Return
    End
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
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Bowser_Body, LVar1, LVar2, LVar3)
        Call(SetNpcPos, NPC_Bowser_Prop, LVar1, LVar2, LVar3)
        Add(LVar1, 28)
        Add(LVar2, 40)
        Add(LVar3, -3)
        Call(SetNpcPos, NPC_CaptivePeach, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_BowserFliesAway) = {
    Call(SetNpcPos, NPC_Bowser_Body, 800, 0, 0)
    Call(SetNpcYaw, NPC_Bowser_Body, 270)
    Call(SetNpcPos, NPC_Bowser_Prop, 800, 0, 0)
    Call(SetNpcYaw, NPC_Bowser_Prop, 270)
    Call(SetNpcPos, NPC_CaptivePeach, 828, 90, -3)
    Exec(N(EVS_UpdatePropellerSounds))
    Thread
        Wait(15)
        Call(SetPlayerAnimation, ANIM_Mario1_Flail)
        Wait(20)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        Call(InterpPlayerYaw, 0, 1)
    EndThread
    Call(LoadPath, 25, Ref(N(ToWindowPath)), ARRAY_COUNT(N(ToWindowPath)), EASING_LINEAR)
    ExecWait(N(EVS_FlyBowserAndPeach))
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarLaugh)
    Wait(40)
    Call(LoadPath, 25, Ref(N(ThroughWindowPath)), ARRAY_COUNT(N(ThroughWindowPath)), EASING_LINEAR)
    ExecWait(N(EVS_FlyBowserAndPeach))
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarIdle)
    Wait(15)
    Call(LoadPath, 25, Ref(N(UpAndAwayPath)), ARRAY_COUNT(N(UpAndAwayPath)), EASING_LINEAR)
    Exec(N(EVS_FlyBowserAndPeach))
    Wait(10)
    Return
    End
};

EvtScript N(EVS_Scene_BowserDefeated) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 1)
    Call(EnableGroup, MODEL_g153, FALSE)
    Call(SetPlayerPos, 525, 0, 0)
    Call(PartnerIsFlying, LVar0)
    IfEq(LVar0, FALSE)
        Set(LVar1, 10)
    Else
        Set(LVar1, 0)
    EndIf
    Call(SetNpcPos, NPC_PARTNER, 490, LVar1, 0)
    Call(SetNpcYaw, NPC_PARTNER, 90)
    Call(SetNpcPos, NPC_Bowser_Body, 675, 0, 0)
    Call(AdjustCam, CAM_DEFAULT, Float(90.0), 75, 450, Float(17.0), Float(-7.0))
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Tantrum)
    Wait(30)
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Idle)
    Wait(10)
    Call(SpeakToPlayer, NPC_Bowser_Body, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_CH8_0078)
    Wait(20)
    Call(InterpNpcYaw, NPC_Bowser_Body, 90, 1)
    Wait(10)
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_Walk)
    Call(NpcMoveTo, NPC_Bowser_Body, 800, 0, 20)
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarIdle)
    Call(SetNpcAnimation, NPC_CaptivePeach, ANIM_Peach2_TiedIdle)
    Call(SpeakToPlayer, NPC_CaptivePeach, ANIM_Peach2_TiedHangStruggle, ANIM_Peach2_TiedHangIdle, 0, MSG_CH8_0079)
    Call(EnablePartnerAI)
    Call(PlayerMoveTo, 580, 0, 10)
    ExecWait(N(EVS_BowserFliesAway))
    Wait(10)
    Call(SpeakToPlayer, NPC_Bowser_Body, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_CH8_007A)
    Call(ResetCam, CAM_DEFAULT, Float(1.0))
    Set(GF_KKJ13_BowserTaunts, TRUE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Bowser_Body) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_2, TRUE)
            Exec(N(EVS_Scene_BowserDefeated))
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Bowser_Body) = {
    Call(SetNpcPos, NPC_Bowser_Body, NPC_DISPOSE_LOCATION)
    IfEq(GF_KKJ13_BowserTaunts, TRUE)
        Return
    EndIf
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_BowserAwaitBattle)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Bowser_Body)))
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarIdle)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bowser_Prop) = {
    Call(EnableNpcShadow, NPC_Bowser_Prop, FALSE)
    Call(SetNpcPos, NPC_Bowser_Prop, NPC_DISPOSE_LOCATION)
    IfEq(GF_KKJ13_BowserTaunts, TRUE)
        Return
    EndIf
    Call(SetNpcAnimation, NPC_Bowser_Prop, ANIM_WorldBowser_ClownCarPropeller)
    Return
    End
};

EvtScript N(EVS_NpcInit_CaptivePeach) = {
    Call(SetNpcPos, NPC_CaptivePeach, NPC_DISPOSE_LOCATION)
    IfEq(GF_KKJ13_BowserTaunts, TRUE)
        Return
    EndIf
    Call(SetNpcPos, NPC_CaptivePeach, 775, 90, 0)
    Call(SetNpcAnimation, NPC_CaptivePeach, ANIM_Peach2_TiedHangStruggle)
    Return
    End
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
