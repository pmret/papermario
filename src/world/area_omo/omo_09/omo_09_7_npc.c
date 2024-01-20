#include "omo_09.h"

#include "world/common/enemy/ShyGuy_Wander.inc.c"

MobileAISettings N(AISettings_ShyGuy_Wander_NoReaction) = {
    .moveSpeed = 2.0f,
    .moveTime = 60,
    .waitTime = 15,
    .alertRadius = 100.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 4,
    .chaseSpeed = 4.0f,
    .chaseTurnRate = 6,
    .chaseUpdateInterval = 1,
    .chaseRadius = 140.0f,
    .chaseOffsetDist = 30.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_ShyGuy_Wander_NoReaction) = {
    Call(BasicAI_Main, Ref(N(AISettings_ShyGuy_Wander_NoReaction)))
    Return
    End
};

NpcSettings N(NpcSettings_ShyGuy_Wander_NoReaction) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_SHY_GUY,
    .ai = &N(EVS_NpcAI_ShyGuy_Wander_NoReaction),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = 0,
};

#include "world/common/enemy/ShyGuy_Patrol.inc.c"
#include "world/common/enemy/SpyGuy.inc.c"
#include "world/common/enemy/Koopatrol_Stationary.inc.c"
#include "world/common/enemy/Pokey.inc.c"
#include "world/common/enemy/Kammy_Flying.inc.c"

#include "world/common/DisableCameraLeadingPlayer.inc.c"
#include "world/common/EnableCameraLeadingPlayer.inc.c"

EvtScript N(EVS_ShyGuy_CarryItem) = {
    Set(LVarA, LVar0) // npcID
    Set(LVarB, LVar1) // itemID
    Set(LVarD, LVar2) // item type
    Set(LVarE, LVar3) // pickup flag
    Call(SetNpcVar, LVarA, 10, 0)
    Call(GetNpcPos, LVarA, LVar2, LVar3, LVar4)
    Add(LVar3, 26)
    Call(MakeItemEntity, LVarB, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(LVar9, LVar0)
    Wait(1)
    Label(10)
        Call(GetNpcPos, LVarA, LVar2, LVar3, LVar4)
        Add(LVar3, 26)
        Call(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        Wait(1)
        Call(GetNpcVar, LVarA, 10, LVar0)
        IfEq(LVar0, 0)
            Goto(10)
        EndIf
    Call(RemoveItemEntity, LVar9)
    Switch(LVarD)
        CaseEq(ITEM_TYPE_CONSUMABLE)
            Call(MakeItemEntity, LVarB, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS, LVarE)
        CaseEq(ITEM_TYPE_KEY)
            Call(DropItemEntity, LVarB, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, LVarE)
        CaseEq(ITEM_TYPE_BADGE)
            Call(DropItemEntity, LVarB, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_FALL, LVarE)
    EndSwitch
    Return
    End
};


EvtScript N(EVS_NpcDefeat_ShyGuy_Thief) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Set(GF_OMO09_Defeated_MysteryNoteThief, TRUE)
            Call(SetSelfVar, 10, 1)
            Wait(2)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_FLED)
        CaseEq(OUTCOME_ENEMY_FLED)
            Set(GF_OMO09_Defeated_MysteryNoteThief, TRUE)
            Call(SetSelfVar, 10, 1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_Pokey) = {
    Label(0)
        Wait(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar0, 1850)
            Goto(0)
        EndIf
        IfLt(LVar1, 150)
            Goto(0)
        EndIf
    Call(DisablePlayerInput, TRUE)
    Call(N(DisableCameraLeadingPlayer))
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(SetCamProperties, CAM_DEFAULT, Float(5.0), LVar0, LVar1, LVar2, 300, Float(13.0), Float(-9.5))
    IfEq(GB_OMO_PeachChoice3, 0)
        Call(SpeakToPlayer, NPC_Pokey, ANIM_Pokey_Idle4, ANIM_Pokey_Idle4, 0, MSG_CH4_003E)
    Else
        Call(SpeakToPlayer, NPC_Koopatrol, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_CH4_003F)
    EndIf
    Thread
        Call(N(EnableCameraLeadingPlayer))
        Call(ResetCam, CAM_DEFAULT, Float(4.0))
    EndThread
    Call(DisablePlayerInput, FALSE)
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Pokey) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Set(GF_OMO09_Item_SuperSoda, TRUE)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Pokey) = {
    IfEq(GB_OMO_PeachChoice3, 0)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Pokey)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Pokey)))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol) = {
    IfEq(GB_OMO_PeachChoice3, 1)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Pokey)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Pokey)))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Kammy) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kammy)))
    Return
    End
};

EvtScript N(EVS_NpcAI_ShyGuy_Jackpot) = {
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        Switch(LVar0)
            CaseEq(0)
                Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                IfEq(LVar1, 0)
                    Call(SetSelfVar, 0, 1)
                    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_ShyGuy_Wander)))
                EndIf
            CaseEq(2)
                Call(DisablePlayerInput, TRUE)
                Wait(25)
                Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
                Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
                Call(SetSelfVar, 0, 0)
                Call(DisablePlayerInput, FALSE)
        EndSwitch
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcDefeat_ShyGuy_Jackpot) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetSelfVar, 0, 2)
            Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_ShyGuy_Jackpot)))
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_ShyGuy_Jackpot) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcAI_ShyGuy_Jackpot)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_ShyGuy_Jackpot)))
    Return
    End
};

NpcData N(NpcData_Pokey) = {
    .id = NPC_Pokey,
    .pos = { 1900.0f, 150.0f, -30.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Pokey),
    .settings = &N(NpcSettings_Pokey),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = POKEY_ANIMS,
};

NpcData N(NpcData_Koopatrol) = {
    .id = NPC_Koopatrol,
    .pos = { 1900.0f, 150.0f, -30.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Koopatrol),
    .settings = &N(NpcSettings_Koopatrol_Stationary),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = KOOPATROL_ANIMS,
};

NpcData N(NpcData_ShyGuy_01) = {
    .id = NPC_ShyGuy_Jackpot1,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 460, 0, 50 },
            .wanderSize = { 80 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 460, 0, 50 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy_Jackpot),
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcData N(NpcData_ShyGuy_02) = {
    .id = NPC_ShyGuy_Jackpot2,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 497, 0, 50 },
            .wanderSize = { 80 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 497, 0, 50 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy_Jackpot),
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcData N(NpcData_ShyGuy_03) = {
    .id = NPC_ShyGuy_Jackpot3,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 535, 0, 50 },
            .wanderSize = { 80 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 535, 0, 50 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy_Jackpot),
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcData N(NpcData_ShyGuy_04) = {
    .id = NPC_ShyGuy_Jackpot4,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 573, 0, 50 },
            .wanderSize = { 80 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 573, 0, 50 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy_Jackpot),
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcData N(NpcData_ShyGuy_05) = {
    .id = NPC_ShyGuy_Jackpot5,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 610, 0, 50 },
            .wanderSize = { 80 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 610, 0, 50 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy_Jackpot),
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

AnimID N(ExtraAnims_Kammy)[] = {
    ANIM_WorldKammy_Anim0E,
    ANIM_WorldKammy_Anim0F,
    ANIM_WorldKammy_Anim10,
    ANIM_WorldKammy_Anim13,
    ANIM_WorldKammy_Anim15,
    ANIM_WorldKammy_Anim16,
    ANIM_LIST_END
};

NpcData N(NpcData_Kammy) = {
    .id = NPC_Kammy,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kammy),
    .settings = &N(NpcSettings_Kammy_Flying),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = KAMMY_ANIMS,
    .extraAnimations = N(ExtraAnims_Kammy),
};

EvtScript N(EVS_ShyGuy_Thief) = {
    IfEq(GF_OMO09_Defeated_MysteryNoteThief, TRUE)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_ShyGuy_Thief)))
    Set(LVar0, NPC_ShyGuy_Thief)
    Set(LVar1, ITEM_MYSTERY_NOTE)
    Set(LVar2, ITEM_TYPE_KEY)
    SetConst(LVar3, GF_OMO09_Item_MysteryNote)
    Exec(N(EVS_ShyGuy_CarryItem))
    Return
    End
};

NpcData N(NpcData_ShyGuy_Thief) = {
    .id = NPC_ShyGuy_Thief,
    .pos = { 155.0f, 10.0f, -96.0f },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points  = {
                { 155, 10, -96 },
                { 90, 10, -96 },
            },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 135, 10, 0 },
            .detectSize = { 105, 140 },
        }
    },
    .init = &N(EVS_ShyGuy_Thief),
    .settings = &N(NpcSettings_ShyGuy_Patrol),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SHY_GUY_DROPS,
    .animations = YELLOW_SHY_GUY_ANIMS,
    .aiFlags = ENEMY_AI_FLAG_1,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_SpyGuy)[] = {
    {
        .id = NPC_SpyGuy,
        .pos = { 850.0f, 0.0f, 0.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 850, 0, 0 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 850, 0, 0 },
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
    SPY_GUY_ROCK_HITBOX(NPC_SpyGuy_Rock3),
};

NpcGroupList N(PokeyAmbushNPCs) = {
    NPC_GROUP(N(NpcData_Pokey), BTL_OMO3_FORMATION_08, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_01), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_02), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_03), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_04), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_05), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_Thief), BTL_OMO_FORMATION_09, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_SpyGuy), BTL_OMO_FORMATION_19, BTL_OMO_STAGE_00),
    {}
};

NpcGroupList N(KoopatrolAmbushNPCs) = {
    NPC_GROUP(N(NpcData_Koopatrol), BTL_OMO3_FORMATION_09, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_01), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_02), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_03), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_04), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_05), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_Thief), BTL_OMO_FORMATION_09, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_SpyGuy), BTL_OMO_FORMATION_19, BTL_OMO_STAGE_00),
    {}
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_ShyGuy_01), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_02), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_03), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_04), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_05), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_ShyGuy_Thief), BTL_OMO_FORMATION_09, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_SpyGuy), BTL_OMO_FORMATION_19, BTL_OMO_STAGE_00),
    {}
};

NpcGroupList N(KammySceneNPCs) = {
    NPC_GROUP(N(NpcData_Kammy)),
    NPC_GROUP(N(NpcData_Pokey), BTL_OMO3_FORMATION_08, BTL_OMO3_STAGE_04),
    NPC_GROUP(N(NpcData_Koopatrol), BTL_OMO3_FORMATION_09, BTL_OMO3_STAGE_04),
    {}
};
