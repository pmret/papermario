#include "omo_15.h"

#include "world/common/enemy/ShyGuy_Stationary.inc.c"

enum {
    MANAGER_IDLE_STATE      = 0,
    MANAGER_ARMY_CHARGE     = 10,
    MANAGER_ARMY_FLEE       = 40,
};

s32 N(BeginSurroundCrowdPositions)[] = {
    8, -35, -240,
    7,  -5, -180,
    6,  10, -120,
    6,  25,  -60,
    6,  25,   60,
    6,  10,  120,
    7,  -5,  180,
    8, -35,  240,
    6,  30,    0,
};

EvtScript N(EVS_Scene_MeetingGeneralGuy) = {
    Call(DisablePlayerInput, TRUE)
    Wait(30 * DT)
    Thread
        Wait(10 * DT)
        Call(GetPartnerInUse, LVar0)
        IfNe(LVar0, PARTNER_NONE)
            Call(InterruptUsePartner)
            Wait(30 * DT)
            Call(func_802D2C14, 1)
            Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Wait(45 * DT)
            Call(func_802D2C14, 0)
        EndIf
    EndThread
    Call(SpeakToPlayer, NPC_GeneralGuy, ANIM_GeneralGuy_Anim0A, ANIM_GeneralGuy_Anim02, 0, MSG_CH4_005F)
    Wait(10 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, 250, -50, 10)
    Call(SetPanTarget, CAM_DEFAULT, 250, -50, 10)
    Call(SetCamPosB, CAM_DEFAULT, Float(205.0), Float(11.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_GeneralGuy, ANIM_GeneralGuy_Anim0A, ANIM_GeneralGuy_Anim02, 0, MSG_CH4_0060)
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_GeneralGuy, ANIM_GeneralGuy_Anim0A, ANIM_GeneralGuy_Anim02, 0, MSG_CH4_0061)
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_GeneralGuy, ANIM_GeneralGuy_Anim0A, ANIM_GeneralGuy_Anim02, 0, MSG_CH4_0062)
    Call(SetPlayerSpeed, Float(3.0 / DT))
    Call(PlayerMoveTo, -200, 0, 0)
    Set(LVar0, NPC_ShyGuy_01)
    Loop(9)
        Call(SetNpcAnimation, LVar0, ANIM_ShyGuy_Red_Anim02)
        Add(LVar0, 1)
    EndLoop
    Call(SetNpcAnimation, NPC_GeneralGuy, ANIM_GeneralGuy_Anim0C)
    Call(ShowMessageAtScreenPos, MSG_CH4_0063, 160, 40)
    Call(SetNpcAnimation, NPC_GeneralGuy, ANIM_GeneralGuy_Anim02)
    Wait(20 * DT)
    Set(LVar0, NPC_ShyGuy_01)
    Loop(9)
        Call(SetNpcAnimation, LVar0, ANIM_ShyGuy_Red_Anim01)
        Add(LVar0, 1)
    EndLoop
    Call(SpeakToPlayer, NPC_GeneralGuy, ANIM_GeneralGuy_Anim02, ANIM_GeneralGuy_Anim0A, 0, MSG_CH4_0064)
    Thread
        Wait(10 * DT)
        Call(PlaySound, SOUND_LOOP_SHY_GUY_CROWD_2)
        Set(LVar0, NPC_ShyGuy_01)
        Loop(9)
            Call(SetNpcVar, LVar0, 0, MANAGER_ARMY_CHARGE)
            Add(LVar0, 1)
        EndLoop
    EndThread
    // screen 'shaking' from charging army
    Loop(30)
        Call(SetCamDistance, CAM_DEFAULT, Float(330.0))
        Wait(1)
        Call(SetCamDistance, CAM_DEFAULT, Float(320.0))
        Wait(1)
    EndLoop
    Set(LVar0, NPC_ShyGuy_01)
    UseBuf(Ref(N(BeginSurroundCrowdPositions)))
    Loop(9)
        BufRead3(LVar1, LVar2, LVar3)
        Call(SetNpcSpeed, LVar0, LVar1)
        Call(SetNpcPos, LVar0, LVar2, 0, LVar3)
        Add(LVar0, 1)
    EndLoop
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Wait(20 * DT)
    // wait for battle to be over
    Label(5)
        Call(GetNpcVar, NPC_ShyGuy_09, 0, LVar0)
        IfNe(LVar0, MANAGER_ARMY_FLEE)
            Wait(1)
            Goto(5)
        EndIf
    Call(GetCurrentPartnerID, LVar0)
    IfEq(LVar0, PARTNER_WATT)
        Call(DisablePartnerAI, 0)
        Call(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 0, MSG_CH4_0075)
        Call(EnablePartnerAI)
    EndIf
    Call(InterpPlayerYaw, 90, 0)
    Call(SetPanTarget, CAM_DEFAULT, 150, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.5 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(FadeOutMusic, 0, 3000 * DT)
    Exec(N(EVS_TrySpawningStarCard))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

s32 N(CrowdFleeScriptA)[] = {
    CS_JUMP(  65,   0,  87)
    CS_MOVE(  17,  46)
    CS_JUMP( -24,   0, -11)
    CS_MOVE( -63, -16)
    CS_MOVE(-120,  43)
    CS_JUMP(-172,   0,  25)
    CS_MOVE(-234,  23)
    CS_MOVE(-320,  30)
    CS_MOVE(-400,   0)
    CS_END
};

s32 N(CrowdFleeScriptB)[] = {
    CS_MOVE(  29,  -72)
    CS_MOVE( -19, -104)
    CS_MOVE( -60,  -67)
    CS_MOVE(-106,  -50)
    CS_MOVE(-168, -100)
    CS_MOVE(-279,  -20)
    CS_MOVE(-400,    0)
    CS_END
};

s32 N(CrowdFleeScriptC)[] = {
    CS_JUMP( -30,   0,  27)
    CS_MOVE(-123, -13)
    CS_MOVE(-168,  73)
    CS_MOVE(-120, 103)
    CS_MOVE(-155,  21)
    CS_MOVE(-208,  43)
    CS_MOVE(-256,  84)
    CS_MOVE(-326,  42)
    CS_MOVE(-400,   0)
    CS_END
};

s32 N(CrowdFleeScriptD)[] = {
    CS_MOVE( 133,  -3)
    CS_MOVE(  84,  27)
    CS_MOVE(  25,   0)
    CS_MOVE( -31, -23)
    CS_MOVE( -97,   0)
    -50, //@bug -- ignored by event running this script; previous op should probably be CS_JUMP with this as third arg
    CS_MOVE(-150, -75)
    CS_MOVE(-230, -90)
    CS_MOVE(-309, -55)
    CS_MOVE(-400,   0)
    CS_END
};

s32 N(CrowdFleeScriptE)[] = {
    CS_MOVE( -40, 200)
    CS_MOVE(-100, 256)
    CS_MOVE(-180, 270)
    CS_MOVE(-210, 200)
    CS_MOVE(-179, 102)
    CS_JUMP(-167,   0,  52)
    CS_MOVE(-261, 118)
    CS_MOVE(-400,   0)
    CS_END
};

s32 N(CrowdPratfallScript)[] = {
    CS_MOVE( -97, -24)
    CS_MOVE( -25, 300)
    CS_MOVE( 100,   0)
    CS_MOVE( -50,  50)
    CS_MOVE(-100,  30)
    CS_MOVE(-160,  63)
    CS_FALL()
    CS_MOVE(-400,   0)
    CS_END
};

s32 N(GeneralGuyFleeScript)[] = {
    CS_MOVE(-153,   0)
    CS_MOVE(-170,  70)
    CS_MOVE(-208,  80)
    CS_MOVE(-246,  70)
    CS_MOVE(-263,   0)
    CS_MOVE(-246, -70)
    CS_MOVE(-208, -80)
    CS_MOVE(-170, -70)
    CS_MOVE(-153,   0)
    CS_MOVE(-170,  70)
    CS_MOVE(-208,  80)
    CS_MOVE(-400,   0)
    CS_END
};

s32* N(CrowdFleeScripts)[] = {
    N(CrowdFleeScriptA),
    N(CrowdFleeScriptB),
    N(CrowdFleeScriptC),
    N(CrowdFleeScriptD),
    N(CrowdFleeScriptE),
    N(CrowdFleeScriptB),
    N(CrowdFleeScriptA),
    N(CrowdFleeScriptD),
    N(CrowdPratfallScript),
};

s32* N(GeneralGuyFleeScripts)[] = {
    N(GeneralGuyFleeScript),
};

Vec3i N(FinalSurroundCrowdPositions)[] = {
    { -238, -55,  0 },
    { -218, -60,  0 },
    { -198, -60,  0 },
    { -178, -50,  0 },
    { -178,  35,  0 },
    { -192,  50,  0 },
    { -210,  60,  0 },
    { -228,  55,  0 },
    { -165, -10,  0 },
};

Vec3i N(PostBattleGeneralPosition) = {
    -182, 0, 0,
};

EvtScript N(EVS_NpcIdle_ShyGuy) = {
    Label(0)
        Call(GetSelfVar, 0, LVar0)
        Switch(LVar0)
            CaseEq(MANAGER_ARMY_CHARGE)
                Thread
                    Call(GetSelfNpcID, LVar0)
                    Sub(LVar0, 0)
                    UseBuf(Ref(N(FinalSurroundCrowdPositions)))
                    Loop(LVar0)
                        BufRead3(LVar1, LVar2, LVar3)
                    EndLoop
                    Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
                    Call(SetNpcSpeed, NPC_SELF, Float(3.0))
                    Call(NpcMoveTo, NPC_SELF, LVar1, LVar2, LVar3)
                EndThread
                Wait(60)
                Call(GetSelfNpcID, LVar0)
                Call(SetSelfVar, 0, MANAGER_IDLE_STATE)
                IfEq(LVar0, NPC_ShyGuy_09)
                    Thread
                        Wait(20)
                        Call(StopSound, SOUND_LOOP_SHY_GUY_CROWD_2)
                    EndThread
                    Call(StartBossBattle, SONG_GENERAL_GUY_BATTLE)
                EndIf
        EndSwitch
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_BossDefeated_RunAway) = {
    Call(GetSelfNpcID, LVar9)
    IfEq(LVar9, NPC_GeneralGuy)
        Call(PlaySound, SOUND_LOOP_SHY_GUY_CROWD_2)
        UseBuf(Ref(N(GeneralGuyFleeScripts)))
        BufRead1(LVar1)
        UseBuf(LVar1)
        Call(SetNpcAnimation, LVar9, ANIM_GeneralGuy_Anim0E)
        Loop(0)
            BufRead1(LVar2)
            Switch(LVar2)
                CaseEq(op_CS_MOVE)
                    BufRead2(LVar3, LVar4)
                    Call(SetNpcSpeed, NPC_GeneralGuy, Float(8.0))
                    Call(NpcMoveTo, NPC_GeneralGuy, LVar3, LVar4, 0)
                CaseEq(op_CS_JUMP)
                    BufRead3(LVar3, LVar4, LVar5)
                    Call(SetNpcJumpscale, NPC_GeneralGuy, Float(1.0))
                    Call(NpcJump0, NPC_GeneralGuy, LVar3, LVar4, LVar5, 10)
            EndSwitch
            IfEq(LVar2, op_CS_END)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySound, SOUND_LRAW_SHY_GUY_CROWD_2 | SOUND_ID_TRIGGER_CHANGE_SOUND)
        Call(StopTrackingSoundPos, SOUND_LRAW_SHY_GUY_CROWD_2)
    Else
        Set(LVar0, LVar9)
        Sub(LVar0, 0)
        UseBuf(Ref(N(CrowdFleeScripts)))
        Loop(LVar0)
            BufRead1(LVar1)
        EndLoop
        UseBuf(LVar1)
        Loop(0)
            BufRead1(LVar2)
            Switch(LVar2)
                CaseEq(op_CS_MOVE)
                    BufRead2(LVar3, LVar4)
                    Call(SetNpcAnimation, LVar9, ANIM_ShyGuy_Red_Anim04)
                    Call(SetNpcSpeed, LVar9, Float(8.0))
                    Call(NpcMoveTo, LVar9, LVar3, LVar4, 0)
                CaseEq(op_CS_JUMP)
                    BufRead3(LVar3, LVar4, LVar5)
                    Call(SetNpcJumpscale, LVar9, Float(1.0))
                    Call(NpcJump0, LVar9, LVar3, LVar4, LVar5, 10)
                CaseEq(op_CS_FALL)
                    Call(SetNpcRotationPivot, LVar9, 10)
                    Thread
                        Set(LVar3, 0)
                        Loop(10)
                            Add(LVar3, 9)
                            Call(SetNpcRotation, LVar9, 0, 0, LVar3)
                            Wait(1)
                        EndLoop
                    EndThread
                    Call(NpcJump0, LVar9, -180, 0, 63, 4)
                    Thread
                        Wait(10)
                        Call(SetNpcRotation, LVar9, 0, 0, 0)
                        Call(SetNpcAnimation, LVar9, ANIM_ShyGuy_Red_Anim10)
                        Call(PlayerFaceNpc, LVar9, 3)
                        Call(NpcFaceNpc, NPC_PARTNER, LVar9, 3)
                    EndThread
                    Call(NpcJump0, LVar9, -220, 0, 63, 10)
                    Call(PlaySoundAtNpc, LVar9, SOUND_ACTOR_TRIP, SOUND_SPACE_DEFAULT)
                    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
                    Wait(50)
                    Loop(2)
                        Call(PlaySoundAtNpc, LVar9, SOUND_ACTOR_TWITCH, SOUND_SPACE_DEFAULT)
                        Wait(7)
                    EndLoop
                    Wait(6)
                    Call(SetNpcRotationPivot, LVar9, 0)
                    Call(SetNpcAnimation, LVar9, ANIM_ShyGuy_Red_Anim01)
                    Call(NpcJump0, LVar9, -230, 0, 63, 10)
                    Call(InterpNpcYaw, LVar9, 90, 0)
                    Wait(20)
                    Thread
                        Call(PlaySoundAtNpc, LVar9, SOUND_SHY_GUY_FLEE_LOOP, SOUND_SPACE_DEFAULT)
                        Wait(45)
                        Call(StopSound, SOUND_SHY_GUY_FLEE_LOOP)
                        Call(SetNpcVar, NPC_ShyGuy_09, 0, MANAGER_ARMY_FLEE)
                    EndThread
            EndSwitch
            IfEq(LVar2, op_CS_END)
                BreakLoop
            EndIf
        EndLoop
    EndIf
    Call(SetNpcFlagBits, LVar9, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcPos, LVar9, NPC_DISPOSE_LOCATION)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_GeneralGuy) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
            Call(GetSelfNpcID, LVar0)
            IfEq(LVar0, NPC_GeneralGuy)
                Call(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_2, TRUE)
                UseBuf(Ref(N(FinalSurroundCrowdPositions)))
                Set(LVar0, NPC_ShyGuy_01)
                Loop(9)
                    BufRead3(LVar1, LVar2, LVar3)
                    Call(SetNpcPos, LVar0, LVar1, 0, LVar2)
                    Call(NpcFacePlayer, LVar0, 0)
                    Add(LVar0, 1)
                EndLoop
                UseBuf(Ref(N(PostBattleGeneralPosition)))
                BufRead3(LVar1, LVar2, LVar3)
                Call(SetNpcPos, NPC_GeneralGuy, LVar1, LVar2, LVar3)
            EndIf
            Exec(N(EVS_BossDefeated_RunAway))
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

Vec3i N(InitialCrowdPositions)[] = {
    { 140, 19,   5 },
    { 147, 19,  32 },
    { 154, 19,  59 },
    { 161, 19,  86 },
    { 100,  0,  30 },
    { 106,  0,  55 },
    { 112,  0,  80 },
    { 118,  0, 105 },
    { 124,  0, 130 },
};

EvtScript N(EVS_NpcInit_ShyGuy) = {
    IfLt(GB_StoryProgress, STORY_CH4_DEFEATED_GENERAL_GUY)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_ShyGuy)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_GeneralGuy)))
        Call(GetSelfNpcID, LVar0)
        Sub(LVar0, 0)
        UseBuf(Ref(N(InitialCrowdPositions)))
        Loop(LVar0)
            BufRead3(LVar1, LVar2, LVar3)
        EndLoop
        Call(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
    Else
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_GeneralGuy) = {
    IfLt(GB_StoryProgress, STORY_CH4_DEFEATED_GENERAL_GUY)
        Exec(N(EVS_Scene_MeetingGeneralGuy))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_GeneralGuy)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_GeneralGuy)[] = {
    {
        .id = NPC_GeneralGuy,
        .pos = { 187.0f, 38.0f, 20.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_GeneralGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_GeneralGuy_Anim02,
            .walk   = ANIM_GeneralGuy_Anim02,
            .run    = ANIM_GeneralGuy_Anim02,
            .chase  = ANIM_GeneralGuy_Anim02,
            .anim_4 = ANIM_GeneralGuy_Anim02,
            .anim_5 = ANIM_GeneralGuy_Anim02,
            .death  = ANIM_GeneralGuy_Anim02,
            .hit    = ANIM_GeneralGuy_Anim02,
            .anim_8 = ANIM_GeneralGuy_Anim02,
            .anim_9 = ANIM_GeneralGuy_Anim02,
            .anim_A = ANIM_GeneralGuy_Anim02,
            .anim_B = ANIM_GeneralGuy_Anim02,
            .anim_C = ANIM_GeneralGuy_Anim02,
            .anim_D = ANIM_GeneralGuy_Anim02,
            .anim_E = ANIM_GeneralGuy_Anim02,
            .anim_F = ANIM_GeneralGuy_Anim02,
        },
    },
    {
        .id = NPC_ShyGuy_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_06,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_07,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_08,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_09,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_GeneralGuy), BTL_OMO2_FORMATION_00),
    {}
};
