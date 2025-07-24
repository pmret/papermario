#include "kkj_01.h"

#include "world/common/npc/Toad_Wander.inc.c"
#include "world/common/npc/Toad_Patrol.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/Dryite_Stationary.inc.c"
#include "world/common/npc/Mouser.inc.c"
#include "world/common/npc/Penguin.inc.c"
#include "world/common/npc/Koopa.inc.c"

EvtScript N(EVS_NpcIdle_Dryite) = {
    Loop(0)
        Call(GetSelfVar, 1, LVar0)
        IfEq(LVar0, 0)
            Call(SetNpcAnimation, NPC_Dryite, ANIM_Dryite_Yellow_Talk)
            Call(SetSelfVar, 1, 1)
        Else
            Call(SetNpcAnimation, NPC_Mouser, ANIM_Mouser_Blue_Talk)
            Call(SetSelfVar, 1, 0)
        EndIf
        Call(RandInt, 60, LVar0)
        Add(LVar0, 30)
        Wait(LVar0)
        Call(SetNpcAnimation, NPC_Dryite, ANIM_Dryite_Yellow_Idle)
        Call(SetNpcAnimation, NPC_Mouser, ANIM_Mouser_Blue_Idle)
        Wait(10)
    EndLoop
    End
};

EvtScript N(EVS_NpcIdle_MayorPenguin) = {
    Loop(0)
        Call(GetSelfVar, 1, LVar0)
        IfEq(LVar0, 0)
            Call(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Talk)
            Call(SetSelfVar, 1, 1)
        Else
            Call(SetNpcAnimation, NPC_Koopa, ANIM_Koopa_Talk)
            Call(SetSelfVar, 1, 0)
        EndIf
        Call(RandInt, 60, LVar0)
        Add(LVar0, 30)
        Wait(LVar0)
        Call(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Idle)
        Call(SetNpcAnimation, NPC_Koopa, ANIM_Koopa_Idle)
        Wait(10)
    EndLoop
    End
};

EvtScript N(EVS_NpcIdle_ToadMinister) = {
    Wait(30)
    Loop(0)
        Wait(150)
        Loop(2)
            Call(InterpNpcYaw, NPC_SELF, 90, 7)
            Wait(20)
            Call(InterpNpcYaw, NPC_SELF, 270, 7)
            Wait(20)
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_Toad_01) = {
    Loop(0)
        Wait(150)
        Loop(2)
            Call(InterpNpcYaw, NPC_SELF, 90, 7)
            Wait(15)
            Call(InterpNpcYaw, NPC_SELF, 270, 7)
            Wait(15)
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_ToadGuard_02) = {
    IfEq(AF_KKJ_02, true)
        Return
    EndIf
    Call(GetEntryID, LVar0)
    IfNe(LVar0, kkj_01_ENTRY_4)
        Return
    EndIf
    Call(WaitForPlayerInputEnabled)
    Call(DisablePlayerInput, true)
    Call(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Yellow_Talk, ANIM_ToadGuard_Yellow_Idle, 16, MSG_Intro_0042)
    Set(AF_KKJ_02, true)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_NpcInteract_ToadMinister) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_ToadMinister_Talk, ANIM_ToadMinister_Idle, 0, MSG_Intro_0033)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_01) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 16, MSG_Intro_0038)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_02) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 16, MSG_Intro_0039)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_03) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 16, MSG_Intro_003A)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toadette) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toadette_Orange_Talk, ANIM_Toadette_Orange_Idle, 16, MSG_Intro_003B)
    Return
    End
};

EvtScript N(EVS_NpcInteract_ToadGuard_01) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Red_Talk, ANIM_ToadGuard_Red_Idle, 16, MSG_Intro_003C)
    Return
    End
};

EvtScript N(EVS_NpcInteract_ToadGuard_02) = {
    Call(GetSelfVar, 0, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Yellow_Talk, ANIM_ToadGuard_Yellow_Idle, 16, MSG_Intro_003D)
        CaseEq(1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Yellow_Talk, ANIM_ToadGuard_Yellow_Idle, 16, MSG_Intro_003E)
        CaseOrEq(2)
        CaseOrEq(3)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Yellow_Talk, ANIM_ToadGuard_Yellow_Idle, 16, MSG_Intro_003F)
        EndCaseGroup
        CaseEq(4)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Yellow_Talk, ANIM_ToadGuard_Yellow_Idle, 16, MSG_Intro_0040)
            Wait(10)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(SetNpcAnimation, NPC_ToadGuard_02, ANIM_ToadGuard_Yellow_Walk)
            IfGt(LVar0, 0)
                Set(LVar3, -50)
            Else
                Set(LVar3, 50)
            EndIf
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
            Call(SetNpcSpeed, NPC_SELF, Float(2.0))
            Call(NpcMoveTo, NPC_SELF, LVar3, -245, 0)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, false)
            Call(SetNpcAnimation, NPC_ToadGuard_02, ANIM_ToadGuard_Yellow_Idle)
            Call(InterpNpcYaw, NPC_SELF, 180, 5)
            Set(AF_KKJ_01, true)
            BindTrigger(Ref(N(EVS_ExitDoors_kkj_14_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttn2, 1, 0)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Yellow_Talk, ANIM_ToadGuard_Yellow_Idle, 16, MSG_Intro_0041)
    EndSwitch
    Add(LVar0, 1)
    Call(SetSelfVar, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Dryite) = {
    Call(SetNpcAnimation, NPC_Mouser, ANIM_Mouser_Blue_Idle)
    Call(SetNpcAnimation, NPC_Dryite, ANIM_Dryite_Yellow_Idle)
    Wait(10)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Yellow_Talk, ANIM_Dryite_Yellow_Idle, 16, MSG_Intro_0034)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Mouser) = {
    Call(EnableNpcAI, NPC_Dryite, false)
    Call(SetNpcAnimation, NPC_Mouser, ANIM_Mouser_Blue_Idle)
    Call(SetNpcAnimation, NPC_Dryite, ANIM_Dryite_Yellow_Idle)
    Wait(10)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Mouser_Blue_Talk, ANIM_Mouser_Blue_Idle, 16, MSG_Intro_0035)
    Call(EnableNpcAI, NPC_Dryite, true)
    Return
    End
};

EvtScript N(EVS_NpcInteract_MayorPenguin) = {
    Call(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Idle)
    Call(SetNpcAnimation, NPC_Koopa, ANIM_Koopa_Idle)
    Wait(10)
    Call(SpeakToPlayer, NPC_SELF, ANIM_MayorPenguin_Talk, ANIM_MayorPenguin_Idle, 16, MSG_Intro_0036)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Koopa) = {
    Call(EnableNpcAI, NPC_MayorPenguin, false)
    Call(SetNpcAnimation, NPC_MayorPenguin, ANIM_MayorPenguin_Idle)
    Call(SetNpcAnimation, NPC_Koopa, ANIM_Koopa_Idle)
    Wait(10)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 16, MSG_Intro_0037)
    Call(EnableNpcAI, NPC_MayorPenguin, true)
    Return
    End
};

EvtScript N(EVS_NpcInit_ToadMinister) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_ToadMinister)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadMinister)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Toad_01)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_02)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_03)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Toadette) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toadette)))
    Return
    End
};

EvtScript N(EVS_NpcInit_ToadGuard_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadGuard_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_ToadGuard_02) = {
    IfEq(AF_KKJ_01, true)
        Call(SetNpcPos, NPC_SELF, -50, 0, -245)
        Call(SetSelfVar, 0, 5)
    Else
        Call(SetNpcPos, NPC_SELF, 0, 0, -260)
    EndIf
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_ToadGuard_02)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadGuard_02)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Dryite) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Dryite)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Dryite)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Mouser) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Mouser)))
    Return
    End
};

EvtScript N(EVS_NpcInit_MayorPenguin) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_MayorPenguin)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_MayorPenguin)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopa) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopa)))
    Return
    End
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
                .isFlying = true,
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
                .isFlying = true,
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
                .isFlying = true,
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
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .animations = DRYITE_YELLOW_ANIMS,
    },
    {
        .id = NPC_Mouser,
        .pos = { 200.0f, 0.0f, 325.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Mouser),
        .drops  = NO_DROPS,
        .settings = &N(NpcSettings_Mouser),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .animations = MOUSER_BLUE_ANIMS,
    },
    {
        .id = NPC_MayorPenguin,
        .pos = { -150.0f, 0.0f, 0.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_MayorPenguin),
        .drops  = NO_DROPS,
        .settings = &N(NpcSettings_Penguin),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .animations = MAYOR_PENGUIN_ANIMS,
    },
    {
        .id = NPC_Koopa,
        .pos = { -120.0f, 0.0f, -15.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Koopa),
        .drops  = NO_DROPS,
        .settings = &N(NpcSettings_Koopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .animations = KOOPA_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_ToadMinister)),
    {}
};
