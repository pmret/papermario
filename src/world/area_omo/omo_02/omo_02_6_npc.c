#include "omo_02.h"

#include "world/common/enemy/complete/ShyGuy_Wander.inc.c"
#include "world/common/enemy/complete/ShyGuy_Guard.inc.c"
#include "world/common/enemy/complete/ShyGuy_Stationary.inc.c"
#include "world/common/enemy/complete/SpyGuy.inc.c"

EvtScript N(D_80244D64_DA2234) = {
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

EvtScript N(D_80244E44_DA2314) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, NPC_ShyGuy_01, SOUND_B0000021, 0)
        EVT_WAIT(8)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_ShyGuy_Loner) = {
    EVT_IF_EQ(GF_OMO02_ShyGuyFledBehindWall, FALSE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_WAIT(30)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 15)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -570, 0, 0)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -570, 0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_EXEC_GET_TID(N(D_80244E44_DA2314), LVarA)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(6.0))
        EVT_CALL(NpcMoveTo, NPC_SELF, -575, 0, 0)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, -460, 0, -20, 40)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_EXEC_GET_TID(N(D_80244D64_DA2234), MV_Unk_0A)
        EVT_SET(GF_OMO02_ShyGuyFledBehindWall, TRUE)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_EXEC_GET_TID(N(D_80244D64_DA2234), MV_Unk_0A)
        EVT_CALL(SetNpcPos, NPC_SELF, -575, 0, -20)
        EVT_LABEL(10)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, -760)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_WAIT(20)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, -460, 0, -20, 40)
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

s32 N(D_802451B4_DA2684)[] = {
    0, -320,  30,
    0, -234,  23,
    1, -172,   0,  25,
    0, -120,  43,
    0,  -63, -16,
    1,  -24,   0, -11,
    0,   17,  46,
    1,   65,   0,  87,
    0,  115,  72,
    1,  154,   0,  33,
    0,  194,   0,
    0,  240,  -2,
    -1,
};

s32 N(D_80245258_DA2728)[] = {
    0, -279,   20,
    0, -168,   30,
    0, -106,  -11,
    0,  -60,  -67,
    0,  -19, -104,
    0,   29,  -72,
    0,   76,    8,
    0,  128,   99,
    0,  196,   79,
    0,  259,   14,
    0,  309,  -20,
    0,  371,   30,
    -1,
};

s32 N(D_802452EC_DA27BC)[] = {
    0, -326,  42,
    0, -288,  69,
    0, -256,  84,
    0, -229,  68,
    0, -208,  43,
    0, -181,  21,
    0, -155,  21,
    0, -121,  50,
    0, -120, 103,
    0, -145, 111,
    0, -168,  73,
    0, -164,  22,
    0, -123, -13,
    0,  -77,   0,
    1,  -30,   0,  27,
    0,    5,  45,
    0,   40,  41,
    0,   87,   0,
    0,  120,  -7,
    0,  177,  18,
    0,  219,  46,
    0,  260,  54,
    -1, 
};

s32 N(D_802453FC_DA28CC)[] = {
    0, -309,   9,
    0, -230,  27,
    0, -150,  16,
    0,  -97, -24,
    0,  -31, -13,
    0,   25,  30,
    0,   84,  27,
    0,  133,  -3,
    -1,
};

s32* N(D_80245460_DA2930)[] = {
    N(D_802451B4_DA2684),
    N(D_80245258_DA2728),
    N(D_802452EC_DA27BC),
    N(D_802453FC_DA28CC),
    N(D_802451B4_DA2684),
    N(D_80245258_DA2728),
    N(D_802451B4_DA2684),
    N(D_802453FC_DA28CC), 
    N(D_802451B4_DA2684),
    N(D_80245258_DA2728), 
};

EvtScript N(EVS_NpcIdle_ShyGuy_Crowd) = {
    EVT_CALL(GetNpcPos, NPC_SELF, LVarA, LVarB, LVarC)
    EVT_LABEL(0)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(RandInt, 2, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_CALL(SetSelfVar, 0, LVar0)
        EVT_CASE_EQ(1)
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
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(SetSelfVar, 0, 10)
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_CALL(RandInt, 1, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 15)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(GetSelfVar, 0, LVar0)
            EVT_IF_EQ(LVar0, 2)
                EVT_CALL(SetSelfVar, 0, 10)
            EVT_END_IF
        EVT_CASE_EQ(10)
            EVT_CALL(RandInt, 30, LVar0)
            EVT_ADD(LVar0, 10)
            EVT_WAIT(LVar0)
            EVT_CALL(RandInt, 1, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_CALL(GetSelfVar, 0, LVar1)
            EVT_IF_EQ(LVar1, 10)
                EVT_CALL(SetSelfVar, 0, LVar0)
            EVT_END_IF
        EVT_CASE_EQ(11)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
            EVT_WAIT(2)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
            EVT_WAIT(2)
        EVT_CASE_EQ(20)
            EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_100, 1)
            EVT_CALL(GetSelfNpcID, LVar0)
            EVT_USE_BUF(EVT_PTR(N(D_80245460_DA2930)))
            EVT_LOOP(LVar0)
                EVT_BUF_READ1(LVar1)
            EVT_END_LOOP
            EVT_USE_BUF(LVar1)
            EVT_LABEL(10)
            EVT_BUF_READ1(LVar2)
            EVT_SWITCH(LVar2)
                EVT_CASE_EQ(0)
                    EVT_BUF_READ2(LVar3, LVar4)
                    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim04)
                    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(10.0))
                    EVT_CALL(NpcMoveTo, NPC_SELF, LVar3, LVar4, 0)
                EVT_CASE_EQ(1)
                    EVT_BUF_READ3(LVar3, LVar4, LVar5)
                    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
                    EVT_CALL(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 10)
            EVT_END_SWITCH
            EVT_IF_NE(LVar2, -1)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_CALL(SetSelfVar, 0, 21)
        EVT_CASE_EQ(21)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(D_802459DC_DA2EAC)[] = {
    -462, 0, -80, -447, 0, -40, -432, 0, 
    0, -437, 0, 80, -402, 0, 80, -438, 
    0, -80, -423, 0, -40, -408, 0, 0, 
    -474, 0, -59, -378, 0, 80, 
};

EvtScript N(EVS_NpcInit_ShyGuy_Crowd) = {
    EVT_IF_EQ(GF_OMO02_BombedWall, FALSE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ShyGuy_Crowd)))
        EVT_CALL(GetSelfNpcID, LVar0)
        EVT_SUB(LVar0, 0)
        EVT_USE_BUF(EVT_PTR(N(D_802459DC_DA2EAC)))
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

StaticNpc N(NpcData_ShyGuy_Loner) = {
    .id = NPC_ShyGuy_01,
    .settings = &N(NpcSettings_ShyGuy_Stationary),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .flags = ENEMY_FLAG_1 | ENEMY_FLAG_200 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_ShyGuy_Loner),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = RED_SHY_GUY_ANIMS,
};

StaticNpc N(NpcData_ShyGuy_Crowd)[] = {
    {
        .id = NPC_ShyGuy_02,
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .drops = NPC_NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_03,
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .drops = NPC_NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_04,
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .drops = NPC_NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_05,
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .drops = NPC_NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_06,
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .drops = NPC_NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_07,
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .drops = NPC_NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_08,
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .drops = NPC_NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_09,
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .drops = NPC_NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_10,
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .drops = NPC_NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_11,
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_ShyGuy_Crowd),
        .drops = NPC_NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
};

StaticNpc N(NpcData_SpyGuy)[] = {
    {
        .id = NPC_SpyGuy,
        .settings = &N(NpcSettings_SpyGuy),
        .pos = { 200.0f, 0.0f, 30.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .drops = SPY_GUY_DROPS,
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
        .animations = SPY_GUY_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    SPY_GUY_ROCK_HITBOX(NPC_SpyGuy_Rock1),
    SPY_GUY_ROCK_HITBOX(NPC_SpyGuy_Rock2),
};

// separated into its own NPC to make the group count match in DefaultNPCs
StaticNpc N(NpcData_SpyGuy_UnusedRock)[] = {
    SPY_GUY_ROCK_HITBOX(NPC_SpyGuy_Rock3),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_ShyGuy_Loner)),
    NPC_GROUP(N(NpcData_ShyGuy_Crowd)),
    NPC_GROUP(N(NpcData_SpyGuy), BTL_OMO_FORMATION_1B, BTL_OMO_STAGE_00),
    {}
};
