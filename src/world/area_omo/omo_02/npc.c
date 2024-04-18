#include "omo_02.h"

#include "world/common/enemy/ShyGuy_Wander.inc.c"
#include "world/common/enemy/ShyGuy_Guard.inc.c"
#include "world/common/enemy/ShyGuy_Stationary.inc.c"
#include "world/common/enemy/SpyGuy.inc.c"

EvtScript N(EVS_RestrictCamFromBarricade) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
        Call(GetCamPosB, CAM_DEFAULT, LVar0, LVar1)
        Call(SetCamPosB, CAM_DEFAULT, Float(-600.0), LVar1)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_PlayShyGuyRunSounds) = {
    Loop(0)
        Call(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_SEQ_SHY_GUY_STEP, SOUND_SPACE_DEFAULT)
        Wait(8)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_ShyGuy_Loner) = {
    IfEq(GF_OMO02_ShyGuyFledBehindWall, FALSE)
        Call(DisablePlayerInput, TRUE)
        Wait(30 * DT)
        Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 15 * DT)
        Call(UseSettingsFrom, CAM_DEFAULT, -570, 0, 0)
        Call(SetPanTarget, CAM_DEFAULT, -570, 0, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        ExecGetTID(N(EVS_PlayShyGuyRunSounds), LVarA)
        Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
        Call(SetNpcSpeed, NPC_SELF, Float(6.0 / DT))
        Call(NpcMoveTo, NPC_SELF, -575, 0, 0)
        KillThread(LVarA)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, -460, 0, -20, 40 / DT)
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        ExecGetTID(N(EVS_RestrictCamFromBarricade), MV_RestrictCamScript)
        Set(GF_OMO02_ShyGuyFledBehindWall, TRUE)
        Call(DisablePlayerInput, FALSE)
    Else
        ExecGetTID(N(EVS_RestrictCamFromBarricade), MV_RestrictCamScript)
        Call(SetNpcPos, NPC_SELF, -575, 0, -20)
        Label(10)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar0, -760)
            Wait(1)
            Goto(10)
        EndIf
        Wait(20 * DT)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, -460, 0, -20, 40 / DT)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_ShyGuy_Loner) = {
    IfEq(GF_OMO02_BombedWall, FALSE)
        Call(SetNpcPos, NPC_SELF, -800, 0, 0)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_ShyGuy_Loner)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

s32 N(CrowdScriptA)[] = {
    CS_MOVE(-320,  30)
    CS_MOVE(-234,  23)
    CS_JUMP(-172,   0,  25)
    CS_MOVE(-120,  43)
    CS_MOVE( -63, -16)
    CS_JUMP( -24,   0, -11)
    CS_MOVE(  17,  46)
    CS_JUMP(  65,   0,  87)
    CS_MOVE( 115,  72)
    CS_JUMP( 154,   0,  33)
    CS_MOVE( 194,   0)
    CS_MOVE( 240,  -2)
    CS_END
};

s32 N(CrowdScriptB)[] = {
    CS_MOVE(-279,   20)
    CS_MOVE(-168,   30)
    CS_MOVE(-106,  -11)
    CS_MOVE( -60,  -67)
    CS_MOVE( -19, -104)
    CS_MOVE(  29,  -72)
    CS_MOVE(  76,    8)
    CS_MOVE( 128,   99)
    CS_MOVE( 196,   79)
    CS_MOVE( 259,   14)
    CS_MOVE( 309,  -20)
    CS_MOVE( 371,   30)
    CS_END
};

s32 N(CrowdScriptC)[] = {
    CS_MOVE(-326,  42)
    CS_MOVE(-288,  69)
    CS_MOVE(-256,  84)
    CS_MOVE(-229,  68)
    CS_MOVE(-208,  43)
    CS_MOVE(-181,  21)
    CS_MOVE(-155,  21)
    CS_MOVE(-121,  50)
    CS_MOVE(-120, 103)
    CS_MOVE(-145, 111)
    CS_MOVE(-168,  73)
    CS_MOVE(-164,  22)
    CS_MOVE(-123, -13)
    CS_MOVE( -77,   0)
    CS_JUMP( -30,   0,  27)
    CS_MOVE(   5,  45)
    CS_MOVE(  40,  41)
    CS_MOVE(  87,   0)
    CS_MOVE( 120,  -7)
    CS_MOVE( 177,  18)
    CS_MOVE( 219,  46)
    CS_MOVE( 260,  54)
    CS_END
};

s32 N(CrowdScriptD)[] = {
    CS_MOVE(-309,   9)
    CS_MOVE(-230,  27)
    CS_MOVE(-150,  16)
    CS_MOVE( -97, -24)
    CS_MOVE( -31, -13)
    CS_MOVE(  25,  30)
    CS_MOVE(  84,  27)
    CS_MOVE( 133,  -3)
    CS_END
};

s32* N(CrowdFleeScripts)[] = {
    N(CrowdScriptA),
    N(CrowdScriptB),
    N(CrowdScriptC),
    N(CrowdScriptD),
    N(CrowdScriptA),
    N(CrowdScriptB),
    N(CrowdScriptA),
    N(CrowdScriptD),
    N(CrowdScriptA),
    N(CrowdScriptB),
};

EvtScript N(EVS_NpcIdle_ShyGuy_Crowd) = {
    Call(GetNpcPos, NPC_SELF, LVarA, LVarB, LVarC)
    Label(0)
        Call(GetSelfVar, 0, LVar0)
        Switch(LVar0)
            CaseEq(CROWD_STATE_INIT)
                Call(RandInt, 2, LVar0)
                Add(LVar0, 1)
                Call(SetSelfVar, 0, LVar0)
            CaseEq(CROWD_STATE_RANDOM_LOOK)
                Loop(3)
                    Call(InterpNpcYaw, NPC_SELF, 270, 0)
                    Wait(2)
                    Call(InterpNpcYaw, NPC_SELF, 90, 0)
                    Wait(2)
                    Call(RandInt, 1, LVar0)
                    IfEq(LVar0, 1)
                        Call(InterpNpcYaw, NPC_SELF, 270, 0)
                        Wait(2)
                    EndIf
                    Call(RandInt, 10, LVar0)
                    Add(LVar0, 5)
                    Wait(LVar0)
                EndLoop
                Call(GetSelfVar, 0, LVar0)
                IfEq(LVar0, CROWD_STATE_RANDOM_LOOK)
                    Call(SetSelfVar, 0, CROWD_STATE_RANDOM_DELAY)
                EndIf
            CaseEq(CROWD_STATE_RANDOM_JUMP)
                Call(RandInt, 1, LVar0)
                IfEq(LVar0, 1)
                    Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
                    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                    IfEq(LVar1, 0)
                        Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 15)
                    EndIf
                EndIf
                Call(GetSelfVar, 0, LVar0)
                IfEq(LVar0, CROWD_STATE_RANDOM_JUMP)
                    Call(SetSelfVar, 0, CROWD_STATE_RANDOM_DELAY)
                EndIf
            CaseEq(CROWD_STATE_RANDOM_DELAY)
                Call(RandInt, 30, LVar0)
                Add(LVar0, 10)
                Wait(LVar0)
                Call(RandInt, 1, LVar0)
                Add(LVar0, 1)
                Call(GetSelfVar, 0, LVar1)
                IfEq(LVar1, CROWD_STATE_RANDOM_DELAY)
                    Call(SetSelfVar, 0, LVar0)
                EndIf
            CaseEq(CROWD_STATE_TURN_AROUND)
                Call(InterpNpcYaw, NPC_SELF, 270, 0)
                Wait(2)
                Call(InterpNpcYaw, NPC_SELF, 90, 0)
                Wait(2)
            CaseEq(CROWD_STATE_RUN_AWAY)
                Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_WORLD_COLLISION, 1)
                Call(GetSelfNpcID, LVar0)
                UseBuf(Ref(N(CrowdFleeScripts)))
                Loop(LVar0)
                    BufRead1(LVar1)
                EndLoop
                UseBuf(LVar1)
                Label(10)
                    BufRead1(LVar2) // get cmd
                    Switch(LVar2)
                        CaseEq(op_CS_MOVE)
                            BufRead2(LVar3, LVar4)
                            Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim04)
                            Call(SetNpcSpeed, NPC_SELF, Float(10.0))
                            Call(NpcMoveTo, NPC_SELF, LVar3, LVar4, 0)
                        CaseEq(op_CS_JUMP)
                            BufRead3(LVar3, LVar4, LVar5)
                            Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
                            Call(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 10)
                    EndSwitch
                    IfNe(LVar2, op_CS_END)
                        Goto(10)
                    EndIf
                Call(SetSelfVar, 0, CROWD_STATE_DISPOSE)
            CaseEq(CROWD_STATE_DISPOSE)
                Call(RemoveNpc, NPC_SELF)
        EndSwitch
        Wait(1)
        Goto(0)
    Return
    End
};

Vec3i N(InitialCrowdPositions)[] = {
    { -462, 0, -80 },
    { -447, 0, -40 },
    { -432, 0,   0 },
    { -437, 0,  80 },
    { -402, 0,  80 },
    { -438, 0, -80 },
    { -423, 0, -40 },
    { -408, 0,   0 },
    { -474, 0, -59 },
    { -378, 0,  80 },
};

EvtScript N(EVS_NpcInit_ShyGuy_Crowd) = {
    IfEq(GF_OMO02_BombedWall, FALSE)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_ShyGuy_Crowd)))
        Call(GetSelfNpcID, LVar0)
        Sub(LVar0, NPC_ShyGuy_01)
        UseBuf(Ref(N(InitialCrowdPositions)))
        Loop(LVar0)
            BufRead3(LVar1, LVar2, LVar3)
        EndLoop
        Call(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_ShyGuy_Loner) = {
    .id = NPC_ShyGuy_01,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_ShyGuy_Loner),
    .settings = &N(NpcSettings_ShyGuy_Stationary),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcData N(NpcData_ShyGuy_Crowd)[] = {
    {
        .id = NPC_ShyGuy_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_06,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_07,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_08,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_09,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_10,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_11,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
};

NpcData N(NpcData_SpyGuy)[] = {
    {
        .id = NPC_SpyGuy,
        .pos = { 200.0f, 0.0f, 30.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 200, 0, 30 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 200, 0, 30 },
                .detectSize = { 200 },
            }
        },
        .settings = &N(NpcSettings_SpyGuy),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = SPY_GUY_DROPS,
        .animations = SPY_GUY_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    SPY_GUY_ROCK_HITBOX(NPC_SpyGuy_Rock1),
    SPY_GUY_ROCK_HITBOX(NPC_SpyGuy_Rock2),
};

// separated into its own NPC to make the group count match in DefaultNPCs
NpcData N(NpcData_SpyGuy_UnusedRock)[] = {
    SPY_GUY_ROCK_HITBOX(NPC_SpyGuy_Rock3),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_ShyGuy_Loner)),
    NPC_GROUP(N(NpcData_ShyGuy_Crowd)),
    NPC_GROUP(N(NpcData_SpyGuy), BTL_OMO_FORMATION_1B, BTL_OMO_STAGE_00),
    {}
};
