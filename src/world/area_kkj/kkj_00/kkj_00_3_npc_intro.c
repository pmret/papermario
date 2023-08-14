#include "kkj_00.h"

#define NAME_SUFFIX _Intro

#include "world/common/npc/Luigi.inc.c"
#include "world/common/npc/Toad_Patrol.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/Penguin.inc.c"

EvtScript N(EVS_NpcIdle_RussT) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 1, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(SetNpcAnimation, NPC_RussT_01, ANIM_RussT_Talk)
            EVT_CALL(SetSelfVar, 1, 1)
        EVT_ELSE
            EVT_CALL(SetNpcAnimation, NPC_ShiverToad_01, ANIM_ShiverToad_Green_Talk)
            EVT_CALL(SetSelfVar, 1, 0)
        EVT_END_IF
        EVT_CALL(RandInt, 60, LVar0)
        EVT_ADD(LVar0, 30)
        EVT_WAIT(LVar0)
        EVT_CALL(SetNpcAnimation, NPC_RussT_01, ANIM_RussT_Idle)
        EVT_CALL(SetNpcAnimation, NPC_ShiverToad_01, ANIM_ShiverToad_Green_Idle)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_END
};

EvtScript N(EVS_NpcIdle_Toadette_01) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 1, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(SetNpcAnimation, NPC_Toadette_01, ANIM_Toadette_Pink_Talk)
            EVT_CALL(SetSelfVar, 1, 1)
        EVT_ELSE
            EVT_CALL(SetNpcAnimation, NPC_Toadette_02, ANIM_Toadette_Green_Talk)
            EVT_CALL(SetSelfVar, 1, 0)
        EVT_END_IF
        EVT_CALL(RandInt, 60, LVar0)
        EVT_ADD(LVar0, 30)
        EVT_WAIT(LVar0)
        EVT_CALL(SetNpcAnimation, NPC_Toadette_01, ANIM_Toadette_Pink_Idle)
        EVT_CALL(SetNpcAnimation, NPC_Toadette_02, ANIM_Toadette_Green_Idle)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_END
};

EvtScript N(EVS_NpcIdle_Toad_01) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kkj_00_ENTRY_5)
        EVT_CALL(WaitForPlayerInputEnabled)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(AwaitPlayerLeave, LVar0, LVar2, 100)
        EVT_WAIT(50)
        EVT_CALL(SetNpcSpeed, NPC_Toad_01, EVT_FLOAT(2.0))
        EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Toad_Red_Walk)
        EVT_CALL(NpcMoveTo, NPC_Toad_01, 60, 320, 0)
        EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Toad_Red_Idle)
    EVT_END_IF
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 1, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Toad_Red_Talk)
            EVT_CALL(SetSelfVar, 1, 1)
        EVT_ELSE
            EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Talk)
            EVT_CALL(SetSelfVar, 1, 0)
        EVT_END_IF
        EVT_CALL(RandInt, 60, LVar0)
        EVT_ADD(LVar0, 30)
        EVT_WAIT(LVar0)
        EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Idle)
        EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Toad_Red_Idle)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_END
};

EvtScript N(EVS_NpcIdle_Toad_03) = {
    EVT_LOOP(0)
        EVT_WAIT(150)
        EVT_LOOP(2)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 7)
            EVT_WAIT(20)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 7)
            EVT_WAIT(20)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Luigi) = {
    EVT_CALL(EnableNpcAI, NPC_Toad_01, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Toad_Red_Idle)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 16, MSG_Intro_0025)
    EVT_CALL(EnableNpcAI, NPC_Toad_01, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_01) = {
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Toad_Red_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Idle)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 16, MSG_Intro_0029)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_02) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 16, MSG_Intro_002A)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_03) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_Intro_002B)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toadette_01) = {
    EVT_CALL(SetNpcAnimation, NPC_Toadette_01, ANIM_Toadette_Pink_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Toadette_02, ANIM_Toadette_Green_Idle)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 16, MSG_Intro_002C)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toadette_02) = {
    EVT_CALL(EnableNpcAI, NPC_Toadette_01, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Toadette_02, ANIM_Toadette_Green_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Toadette_01, ANIM_Toadette_Pink_Idle)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toadette_Green_Talk, ANIM_Toadette_Green_Idle, 16, MSG_Intro_002D)
    EVT_CALL(EnableNpcAI, NPC_Toadette_01, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_RussT) = {
    EVT_CALL(SetNpcAnimation, NPC_ShiverToad_01, ANIM_ShiverToad_Green_Idle)
    EVT_CALL(SetNpcAnimation, NPC_RussT_01, ANIM_RussT_Idle)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RussT_Talk, ANIM_RussT_Idle, 16, MSG_Intro_0027)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ShiverToad) = {
    EVT_CALL(EnableNpcAI, NPC_RussT_01, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_RussT_01, ANIM_RussT_Idle)
    EVT_CALL(SetNpcAnimation, NPC_ShiverToad_01, ANIM_ShiverToad_Green_Idle)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShiverToad_Green_Talk, ANIM_ShiverToad_Green_Idle, 16, MSG_Intro_0028)
    EVT_CALL(EnableNpcAI, NPC_RussT_01, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_01) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_Intro_0030)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadGuard_01) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Red_Talk, ANIM_ToadGuard_Red_Idle, 16, MSG_Intro_002E)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadGuard_02) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Blue_Talk, ANIM_ToadGuard_Blue_Idle, 16, MSG_Intro_002F)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Luigi) = {
    EVT_CALL(SetNpcCollisionSize, NPC_SELF, 46, 26)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kkj_00_ENTRY_5)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, 0, 580)
        EVT_CALL(SetNpcYaw, NPC_SELF, 0)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 20, 0, 320)
        EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Luigi)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, kkj_00_ENTRY_5)
        EVT_CALL(SetNpcPos, NPC_SELF, 60, 0, 320)
        EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_END_IF
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad_01)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_03) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad_03)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toadette_01) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toadette_01)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toadette_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toadette_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toadette_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_RussT) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_RussT)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_RussT)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShiverToad) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ShiverToad)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadGuard_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadGuard_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadGuard_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadGuard_02)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Characters)[] = {
    {
        .id = NPC_Luigi,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Luigi),
        .settings = &N(NpcSettings_Luigi),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = LUIGI_ANIMS,
    },
    {
        .id = NPC_Toad_01,
        .pos = { 182.0f, 0.0f, 320.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Toad_01),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
    },
    {
        .id = NPC_Toad_02,
        .pos = { -250.0f, 0.0f, 250.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { -250, 0, 250 },
                    { 250, 0, 250 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -250, 0, 250 },
                .detectSize = { 200 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_02),
        .settings = &N(NpcSettings_Toad_Patrol),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
    },
    {
        .id = NPC_Toad_03,
        .pos = { 150.0f, 0.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Toad_03),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TOAD_YELLOW_ANIMS,
    },
    {
        .id = NPC_Toadette_01,
        .pos = { -300.0f, 0.0f, 100.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toadette_01),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOADETTE_PINK_ANIMS,
    },
    {
        .id = NPC_Toadette_02,
        .pos = { -270.0f, 0.0f, 85.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Toadette_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOADETTE_GREEN_ANIMS,
    },
    {
        .id = NPC_RussT_01,
        .pos = { 300.0f, 0.0f, 150.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_RussT),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_RussT_Idle,
            .walk   = ANIM_RussT_Idle,
            .run    = ANIM_RussT_Idle,
            .chase  = ANIM_RussT_Idle,
            .anim_4 = ANIM_RussT_Idle,
            .anim_5 = ANIM_RussT_Idle,
            .death  = ANIM_RussT_Idle,
            .hit    = ANIM_RussT_Idle,
            .anim_8 = ANIM_RussT_Idle,
            .anim_9 = ANIM_RussT_Idle,
            .anim_A = ANIM_RussT_Idle,
            .anim_B = ANIM_RussT_Idle,
            .anim_C = ANIM_RussT_Idle,
            .anim_D = ANIM_RussT_Idle,
            .anim_E = ANIM_RussT_Idle,
            .anim_F = ANIM_RussT_Idle,
        },
    },
    {
        .id = NPC_ShiverToad_01,
        .pos = { 330.0f, 0.0f, 135.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShiverToad),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ShiverToad_Green_Idle,
            .walk   = ANIM_ShiverToad_Green_Walk,
            .run    = ANIM_ShiverToad_Green_Idle,
            .chase  = ANIM_ShiverToad_Green_Idle,
            .anim_4 = ANIM_ShiverToad_Green_Idle,
            .anim_5 = ANIM_ShiverToad_Green_Idle,
            .death  = ANIM_ShiverToad_Green_Idle,
            .hit    = ANIM_ShiverToad_Green_Idle,
            .anim_8 = ANIM_ShiverToad_Green_Idle,
            .anim_9 = ANIM_ShiverToad_Green_Idle,
            .anim_A = ANIM_ShiverToad_Green_Idle,
            .anim_B = ANIM_ShiverToad_Green_Idle,
            .anim_C = ANIM_ShiverToad_Green_Idle,
            .anim_D = ANIM_ShiverToad_Green_Idle,
            .anim_E = ANIM_ShiverToad_Green_Idle,
            .anim_F = ANIM_ShiverToad_Green_Idle,
        },
    },
    {
        .id = NPC_Penguin_01,
        .pos = { -120.0f, 100.0f, -305.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Penguin_01),
        .settings = &N(NpcSettings_Penguin),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
    },
    {
        .id = NPC_ToadGuard_01,
        .pos = { 100.0f, 0.0f, 150.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ToadGuard_01),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOAD_GUARD_RED_ANIMS,
    },
    {
        .id = NPC_ToadGuard_02,
        .pos = { -50.0f, 100.0f, -365.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ToadGuard_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOAD_GUARD_BLUE_ANIMS,
    },
};

#define NAME_SUFFIX

NpcGroupList N(IntroNPCs) = {
    NPC_GROUP(N(NpcData_Characters_Intro)),
    {}
};
