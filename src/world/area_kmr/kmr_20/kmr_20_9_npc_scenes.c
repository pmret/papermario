#include "kmr_20.h"

NpcSettings N(NpcSettings_Scenes) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

EvtScript N(EVS_NpcInit_Luigi_Scenes) = {
    EVT_CALL(SetNpcCollisionSize, NPC_SELF, 46, 26)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(kmr_20_ENTRY_2)
        EVT_CASE_OR_EQ(kmr_20_ENTRY_3)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Luigi_IdleSit)
            EVT_CALL(SetNpcPos, NPC_SELF, 196, 44, -37)
            EVT_CALL(SetNpcYaw, NPC_SELF, 270)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Scenes)[] = {
    {
        .id = NPC_Scene_Parakarry,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .settings = &N(NpcSettings_Scenes),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldParakarry_Idle,
            .walk   = ANIM_WorldParakarry_Walk,
            .run    = ANIM_WorldParakarry_Run,
            .chase  = ANIM_WorldParakarry_Run,
            .anim_4 = ANIM_WorldParakarry_Idle,
            .anim_5 = ANIM_WorldParakarry_Idle,
            .death  = ANIM_WorldParakarry_Still,
            .hit    = ANIM_WorldParakarry_Still,
            .anim_8 = ANIM_WorldParakarry_Idle,
            .anim_9 = ANIM_WorldParakarry_Idle,
            .anim_A = ANIM_WorldParakarry_Idle,
            .anim_B = ANIM_WorldParakarry_Idle,
            .anim_C = ANIM_WorldParakarry_Idle,
            .anim_D = ANIM_WorldParakarry_Idle,
            .anim_E = ANIM_WorldParakarry_Idle,
            .anim_F = ANIM_WorldParakarry_Idle,
        },
    },
    {
        .id = NPC_Scene_Luigi,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Luigi_Scenes),
        .settings = &N(NpcSettings_Scenes),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_GRAVITY,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Luigi_Still,
            .walk   = ANIM_Luigi_Still,
            .run    = ANIM_Luigi_Still,
            .chase  = ANIM_Luigi_Still,
            .anim_4 = ANIM_Luigi_Still,
            .anim_5 = ANIM_Luigi_Still,
            .death  = ANIM_Luigi_Still,
            .hit    = ANIM_Luigi_Still,
            .anim_8 = ANIM_Luigi_Still,
            .anim_9 = ANIM_Luigi_Still,
            .anim_A = ANIM_Luigi_Still,
            .anim_B = ANIM_Luigi_Still,
            .anim_C = ANIM_Luigi_Still,
            .anim_D = ANIM_Luigi_Still,
            .anim_E = ANIM_Luigi_Still,
            .anim_F = ANIM_Luigi_Still,
        },
    },
};

NpcGroupList N(SceneNPCs) = {
    NPC_GROUP(N(NpcData_Scenes)),
    {}
};
