#include "omo_04.h"

#include "world/common/enemy/SkyGuy.inc.c"
#include "world/common/enemy/ShyGuy_Wander.inc.c"

#include "world/common/enemy/Goomba.h"

// level changed from 5 -> 14
NpcSettings N(NpcSettings_Goomba) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_SHY_GUY,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

#include "world/common/enemy/Clubba.inc.c"
#include "world/common/enemy/Kammy_Flying.inc.c"

#include "world/common/DisableCameraLeadingPlayer.inc.c"
#include "world/common/EnableCameraLeadingPlayer.inc.c"

EvtScript N(EVS_NpcIdle_Goomba) = {
    Label(0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLt(LVar0, 1050)
        Wait(1)
        Goto(0)
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(N(DisableCameraLeadingPlayer))
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(SetCamProperties, CAM_DEFAULT, Float(5.0), LVar0, LVar1, LVar2, 300, Float(13.0), Float(-9.5))
    IfEq(GB_OMO_PeachChoice1, 0)
        Call(SpeakToPlayer, NPC_Goomba, ANIM_Goomba_Run, ANIM_Goomba_Idle, 0, MSG_CH4_003A)
    Else
        Call(SpeakToPlayer, NPC_Clubba, ANIM_WorldClubba_Anim05, ANIM_WorldClubba_Anim02, 0, MSG_CH4_003B)
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

EvtScript N(EVS_NpcDefeat_Goomba) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Set(GF_OMO04_Item_Mushroom, TRUE)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Goomba) = {
    IfEq(GB_OMO_PeachChoice1, 0)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Goomba)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Goomba)))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Clubba) = {
    IfEq(GB_OMO_PeachChoice1, 1)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Goomba)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Goomba)))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Kammy) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kammy)))
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Kammy)))
    Return
    End
};

NpcData N(NpcData_Goomba) = {
    .id = NPC_Goomba,
    .pos = { 1100.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Goomba),
    .settings = &N(NpcSettings_Goomba),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = GOOMBA_ANIMS,
};

NpcData N(NpcData_Clubba) = {
    .id = NPC_Clubba,
    .pos = { 1100.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Clubba),
    .settings = &N(NpcSettings_Clubba),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = CLUBBA_ANIMS_ALT,
};

NpcData N(NpcData_ShyGuy) = {
    .id = NPC_ShyGuy,
    .pos = { -770.0f, 0.0f, 0.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -770, 0, 0 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -770, 0, 0 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .flags = ENEMY_FLAG_FLYING,
    .drops = SHY_GUY_DROPS,
    .animations = PINK_SHY_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_SkyGuy) = {
    .id = NPC_SkyGuy,
    .pos = { -170.0f, 60.0f, 30.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -170, 60, 30 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -170, 60, 30 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_SkyGuy),
    .flags = ENEMY_FLAG_FLYING,
    .drops = SKY_GUY_DROPS,
    .animations = SKY_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
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

NpcGroupList N(GoombaAmbushNPCs) = {
    NPC_GROUP(N(NpcData_Goomba), BTL_OMO3_FORMATION_01, BTL_OMO3_STAGE_00),
    NPC_GROUP(N(NpcData_ShyGuy), BTL_OMO_FORMATION_04, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_SkyGuy), BTL_OMO_FORMATION_0F, BTL_OMO_STAGE_00),
    {}
};

NpcGroupList N(ClubbaAmbushNPCs) = {
    NPC_GROUP(N(NpcData_Clubba), BTL_OMO3_FORMATION_03, BTL_OMO3_STAGE_00),
    NPC_GROUP(N(NpcData_ShyGuy), BTL_OMO_FORMATION_04, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_SkyGuy), BTL_OMO_FORMATION_0F, BTL_OMO_STAGE_00),
    {}
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_ShyGuy), BTL_OMO_FORMATION_04, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_SkyGuy), BTL_OMO_FORMATION_0F, BTL_OMO_STAGE_00),
    {}
};

NpcGroupList N(KammySceneNPCs) = {
    NPC_GROUP(N(NpcData_Kammy)),
    NPC_GROUP(N(NpcData_Goomba), BTL_OMO3_FORMATION_01, BTL_OMO3_STAGE_00),
    NPC_GROUP(N(NpcData_Clubba), BTL_OMO3_FORMATION_03, BTL_OMO3_STAGE_00),
    {}
};
