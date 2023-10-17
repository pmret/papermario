#include "omo_02.h"

#include "world/common/enemy/ShyGuy_Wander.inc.c"
#include "world/common/enemy/ShyGuy_Guard.inc.c"
#include "world/common/enemy/ShyGuy_Stationary.inc.c"
#include "world/common/enemy/SpyGuy.inc.c"

EvtScript N(EVS_RestrictCamFromBarricade) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
        EVT_CALL(GetCamPosB, CAM_DEFAULT, LVar0, LVar1)
        EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(-600.0), LVar1)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayShyGuyRunSounds) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_SEQ_SHY_GUY_STEP, SOUND_SPACE_DEFAULT)
        EVT_WAIT(8)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_ShyGuy_Loner) = {
    EVT_IF_EQ(GF_OMO02_ShyGuyFledBehindWall, FALSE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 15 * DT)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -570, 0, 0)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -570, 0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_EXEC_GET_TID(N(EVS_PlayShyGuyRunSounds), LVarA)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(6.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_SELF, -575, 0, 0)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_SELF, -460, 0, -20, 40 / DT)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_EXEC_GET_TID(N(EVS_RestrictCamFromBarricade), MV_RestrictCamScript)
        EVT_SET(GF_OMO02_ShyGuyFledBehindWall, TRUE)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_EXEC_GET_TID(N(EVS_RestrictCamFromBarricade), MV_RestrictCamScript)
        EVT_CALL(SetNpcPos, NPC_SELF, -575, 0, -20)
        EVT_LABEL(10)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, -760)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_WAIT(20 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_SELF, -460, 0, -20, 40 / DT)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy_Loner) = {
    EVT_IF_EQ(GF_OMO02_BombedWall, FALSE)
        EVT_CALL(SetNpcPos, NPC_SELF, -800, 0, 0)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ShyGuy_Loner)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
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
    EVT_CALL(GetNpcPos, NPC_SELF, LVarA, LVarB, LVarC)
    EVT_LABEL(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(CROWD_STATE_INIT)
                EVT_CALL(RandInt, 2, LVar0)
                EVT_ADD(LVar0, 1)
                EVT_CALL(SetSelfVar, 0, LVar0)
            EVT_CASE_EQ(CROWD_STATE_RANDOM_LOOK)
                EVT_LOOP(3)
                    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
                    EVT_WAIT(2)
                    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
                    EVT_WAIT(2)
                    EVT_CALL(RandInt, 1, LVar0)
                    EVT_IF_EQ(LVar0, 1)
                        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
                        EVT_WAIT(2)
                    EVT_END_IF
                    EVT_CALL(RandInt, 10, LVar0)
                    EVT_ADD(LVar0, 5)
                    EVT_WAIT(LVar0)
                EVT_END_LOOP
                EVT_CALL(GetSelfVar, 0, LVar0)
                EVT_IF_EQ(LVar0, CROWD_STATE_RANDOM_LOOK)
                    EVT_CALL(SetSelfVar, 0, CROWD_STATE_RANDOM_DELAY)
                EVT_END_IF
            EVT_CASE_EQ(CROWD_STATE_RANDOM_JUMP)
                EVT_CALL(RandInt, 1, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
                    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 15)
                    EVT_END_IF
                EVT_END_IF
                EVT_CALL(GetSelfVar, 0, LVar0)
                EVT_IF_EQ(LVar0, CROWD_STATE_RANDOM_JUMP)
                    EVT_CALL(SetSelfVar, 0, CROWD_STATE_RANDOM_DELAY)
                EVT_END_IF
            EVT_CASE_EQ(CROWD_STATE_RANDOM_DELAY)
                EVT_CALL(RandInt, 30, LVar0)
                EVT_ADD(LVar0, 10)
                EVT_WAIT(LVar0)
                EVT_CALL(RandInt, 1, LVar0)
                EVT_ADD(LVar0, 1)
                EVT_CALL(GetSelfVar, 0, LVar1)
                EVT_IF_EQ(LVar1, CROWD_STATE_RANDOM_DELAY)
                    EVT_CALL(SetSelfVar, 0, LVar0)
                EVT_END_IF
            EVT_CASE_EQ(CROWD_STATE_TURN_AROUND)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
                EVT_WAIT(2)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
                EVT_WAIT(2)
            EVT_CASE_EQ(CROWD_STATE_RUN_AWAY)
                EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_WORLD_COLLISION, 1)
                EVT_CALL(GetSelfNpcID, LVar0)
                EVT_USE_BUF(EVT_PTR(N(CrowdFleeScripts)))
                EVT_LOOP(LVar0)
                    EVT_BUF_READ1(LVar1)
                EVT_END_LOOP
                EVT_USE_BUF(LVar1)
                EVT_LABEL(10)
                    EVT_BUF_READ1(LVar2) // get cmd
                    EVT_SWITCH(LVar2)
                        EVT_CASE_EQ(op_CS_MOVE)
                            EVT_BUF_READ2(LVar3, LVar4)
                            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim04)
                            EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(10.0))
                            EVT_CALL(NpcMoveTo, NPC_SELF, LVar3, LVar4, 0)
                        EVT_CASE_EQ(op_CS_JUMP)
                            EVT_BUF_READ3(LVar3, LVar4, LVar5)
                            EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
                            EVT_CALL(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 10)
                    EVT_END_SWITCH
                    EVT_IF_NE(LVar2, op_CS_END)
                        EVT_GOTO(10)
                    EVT_END_IF
                EVT_CALL(SetSelfVar, 0, CROWD_STATE_DISPOSE)
            EVT_CASE_EQ(CROWD_STATE_DISPOSE)
                EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
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
    EVT_IF_EQ(GF_OMO02_BombedWall, FALSE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ShyGuy_Crowd)))
        EVT_CALL(GetSelfNpcID, LVar0)
        EVT_SUB(LVar0, NPC_ShyGuy_01)
        EVT_USE_BUF(EVT_PTR(N(InitialCrowdPositions)))
        EVT_LOOP(LVar0)
            EVT_BUF_READ3(LVar1, LVar2, LVar3)
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
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
