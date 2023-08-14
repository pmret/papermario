#include "kkj_01.h"

#include "world/common/npc/Toad_Wander.inc.c"
#include "world/common/npc/Toad_Patrol.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/Dryite_Stationary.inc.c"
#include "world/common/npc/Mouser.inc.c"
#include "world/common/npc/Penguin.inc.c"
#include "world/common/npc/Koopa.inc.c"

EvtScript N(EVS_NpcIdle_Dryite) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 1, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(SetNpcAnimation, NPC_Dryite, ANIM_Dryite_Yellow_Talk)
            EVT_CALL(SetSelfVar, 1, 1)
        EVT_ELSE
            EVT_CALL(SetNpcAnimation, NPC_Mouser, ANIM_Mouser_Blue_Talk)
            EVT_CALL(SetSelfVar, 1, 0)
        EVT_END_IF
        EVT_CALL(RandInt, 60, LVar0)
        EVT_ADD(LVar0, 30)
        EVT_WAIT(LVar0)
        EVT_CALL(SetNpcAnimation, NPC_Dryite, ANIM_Dryite_Yellow_Idle)
        EVT_CALL(SetNpcAnimation, NPC_Mouser, ANIM_Mouser_Blue_Idle)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_END
};

EvtScript N(EVS_NpcIdle_MayorPenguin) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 1, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Talk)
            EVT_CALL(SetSelfVar, 1, 1)
        EVT_ELSE
            EVT_CALL(SetNpcAnimation, NPC_Koopa, ANIM_Koopa_Talk)
            EVT_CALL(SetSelfVar, 1, 0)
        EVT_END_IF
        EVT_CALL(RandInt, 60, LVar0)
        EVT_ADD(LVar0, 30)
        EVT_WAIT(LVar0)
        EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Idle)
        EVT_CALL(SetNpcAnimation, NPC_Koopa, ANIM_Koopa_Idle)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_END
};

EvtScript N(EVS_NpcIdle_ToadMinister) = {
    EVT_WAIT(30)
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

EvtScript N(EVS_NpcIdle_Toad_01) = {
    EVT_LOOP(0)
        EVT_WAIT(150)
        EVT_LOOP(2)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 7)
            EVT_WAIT(15)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 7)
            EVT_WAIT(15)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_ToadGuard_02) = {
    EVT_IF_EQ(AF_KKJ_02, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, kkj_01_ENTRY_4)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Yellow_Talk, ANIM_ToadGuard_Yellow_Idle, 16, MSG_Intro_0042)
    EVT_SET(AF_KKJ_02, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadMinister) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadMinister_Talk, ANIM_ToadMinister_Idle, 0, MSG_Intro_0033)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_01) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 16, MSG_Intro_0038)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_02) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 16, MSG_Intro_0039)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_03) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 16, MSG_Intro_003A)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toadette) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toadette_Orange_Talk, ANIM_Toadette_Orange_Idle, 16, MSG_Intro_003B)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadGuard_01) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Red_Talk, ANIM_ToadGuard_Red_Idle, 16, MSG_Intro_003C)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadGuard_02) = {
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Yellow_Talk, ANIM_ToadGuard_Yellow_Idle, 16, MSG_Intro_003D)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Yellow_Talk, ANIM_ToadGuard_Yellow_Idle, 16, MSG_Intro_003E)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(3)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Yellow_Talk, ANIM_ToadGuard_Yellow_Idle, 16, MSG_Intro_003F)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(4)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Yellow_Talk, ANIM_ToadGuard_Yellow_Idle, 16, MSG_Intro_0040)
            EVT_WAIT(10)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcAnimation, NPC_ToadGuard_02, ANIM_ToadGuard_Yellow_Walk)
            EVT_IF_GT(LVar0, 0)
                EVT_SET(LVar3, -50)
            EVT_ELSE
                EVT_SET(LVar3, 50)
            EVT_END_IF
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
            EVT_CALL(NpcMoveTo, NPC_SELF, LVar3, -245, 0)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_CALL(SetNpcAnimation, NPC_ToadGuard_02, ANIM_ToadGuard_Yellow_Idle)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 180, 5)
            EVT_SET(AF_KKJ_01, TRUE)
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_14_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttn2, 1, 0)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Yellow_Talk, ANIM_ToadGuard_Yellow_Idle, 16, MSG_Intro_0041)
    EVT_END_SWITCH
    EVT_ADD(LVar0, 1)
    EVT_CALL(SetSelfVar, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Dryite) = {
    EVT_CALL(SetNpcAnimation, NPC_Mouser, ANIM_Mouser_Blue_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Dryite, ANIM_Dryite_Yellow_Idle)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Yellow_Talk, ANIM_Dryite_Yellow_Idle, 16, MSG_Intro_0034)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Mouser) = {
    EVT_CALL(EnableNpcAI, NPC_Dryite, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Mouser, ANIM_Mouser_Blue_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Dryite, ANIM_Dryite_Yellow_Idle)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 16, MSG_Intro_0035)
    EVT_CALL(EnableNpcAI, NPC_Dryite, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_MayorPenguin) = {
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Koopa, ANIM_Koopa_Idle)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 16, MSG_Intro_0036)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopa) = {
    EVT_CALL(EnableNpcAI, NPC_MayorPenguin, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Koopa, ANIM_Koopa_Idle)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 16, MSG_Intro_0037)
    EVT_CALL(EnableNpcAI, NPC_MayorPenguin, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadMinister) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ToadMinister)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadMinister)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_01) = {
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
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toadette) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toadette)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadGuard_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadGuard_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadGuard_02) = {
    EVT_IF_EQ(AF_KKJ_01, TRUE)
        EVT_CALL(SetNpcPos, NPC_SELF, -50, 0, -245)
        EVT_CALL(SetSelfVar, 0, 5)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, 0, -260)
    EVT_END_IF
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ToadGuard_02)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadGuard_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Dryite) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Dryite)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Dryite)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Mouser) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Mouser)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MayorPenguin) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_MayorPenguin)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_MayorPenguin)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopa)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_ToadMinister)[] = {
    {
        .id = NPC_ToadMinister,
        .pos = { 0.0f, 0.0f, 350.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ToadMinister),
        .drops  = NO_DROPS,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .animations = TOAD_MINISTER_ANIMS,
    },
    {
        .id = NPC_Toad_01,
        .pos = { 100.0f, 0.0f, 175.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Toad_01),
        .drops  = NO_DROPS,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .animations = TOAD_BLUE_ANIMS,
    },
    {
        .id = NPC_Toad_02,
        .pos = { 200.0f, 0.0f, 110.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 200, 0, 110 },
                .wanderSize = { 70 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 200, 0, 110 },
                .detectSize = { 70 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_02),
        .drops  = NO_DROPS,
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .animations = TOAD_GREEN_ANIMS,
    },
    {
        .id = NPC_Toad_03,
        .pos = { -250.0f, 0.0f, 225.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { -250, 0, 225 },
                    { 300, 0, -50 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -250, 0, 225 },
                .detectSize = { 200 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_03),
        .drops  = NO_DROPS,
        .settings = &N(NpcSettings_Toad_Patrol),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .animations = TOAD_RED_ANIMS,
    },
    {
        .id = NPC_Toadette,
        .pos = { -170.0f, 0.0f, 100.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -170, 0, 100 },
                .wanderSize = { 70 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -170, 0, 100 },
                .detectSize = { 70 },
            }
        },
        .init = &N(EVS_NpcInit_Toadette),
        .drops  = NO_DROPS,
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .animations = TOADETTE_ORANGE_ANIMS,
    },
    {
        .id = NPC_ToadGuard_01,
        .pos = { -55.0f, 100.0f, -360.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ToadGuard_01),
        .drops  = NO_DROPS,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .animations = TOAD_GUARD_RED_ANIMS,
    },
    {
        .id = NPC_ToadGuard_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ToadGuard_02),
        .drops  = NO_DROPS,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .animations = TOAD_GUARD_YELLOW_ANIMS,
    },
    {
        .id = NPC_Dryite,
        .pos = { 170.0f, 0.0f, 345.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Dryite),
        .drops  = NO_DROPS,
        .settings = &N(NpcSettings_Dryite),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .animations = DRYITE_YELLOW_ANIMS,
    },
    {
        .id = NPC_Mouser,
        .pos = { 200.0f, 0.0f, 325.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Mouser),
        .drops  = NO_DROPS,
        .settings = &N(NpcSettings_Mouser),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .animations = MOUSER_BLUE_ANIMS,
    },
    {
        .id = NPC_MayorPenguin,
        .pos = { -150.0f, 0.0f, 0.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_MayorPenguin),
        .drops  = NO_DROPS,
        .settings = &N(NpcSettings_Penguin),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .animations = MAYOR_PENGUIN_ANIMS,
    },
    {
        .id = NPC_Koopa,
        .pos = { -120.0f, 0.0f, -15.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Koopa),
        .drops  = NO_DROPS,
        .settings = &N(NpcSettings_Koopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .animations = KOOPA_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_ToadMinister)),
    {}
};
