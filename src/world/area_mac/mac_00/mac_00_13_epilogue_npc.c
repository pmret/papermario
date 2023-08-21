#include "mac_00.h"

#define NAME_SUFFIX _Epilogue
#include "world/common/npc/Luigi.inc.c"
#include "world/common/npc/GoombaFamily.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#define NAME_SUFFIX

EvtScript N(EVS_NpcInteract_Goompapa_Epilogue) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_Outro_0024)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goompapa_Epilogue) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Goompapa_Epilogue)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Goomama_Epilogue) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_Outro_0025)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goomama_Epilogue) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Goomama_Epilogue)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Gooma_Epilogue) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Gooma_Talk, ANIM_Gooma_Idle, 0, MSG_Outro_0026)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Gooma_Epilogue) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Gooma_Epilogue)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ChuckQuizmo_Epilogue) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ChuckQuizmo_Talk, ANIM_ChuckQuizmo_Idle, 0, MSG_Outro_0027)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ChuckQuizmo_Epilogue) = {
    EVT_CALL(SetNpcPos, NPC_ChuckQuizmo, 460, 20, -130)
    EVT_CALL(SetNpcYaw, NPC_ChuckQuizmo, 90)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ChuckQuizmo_Epilogue)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_VannaT_Epilogue) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VannaT_Wave, ANIM_VannaT_Wave, 0, MSG_Outro_003B)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_VannaT_Epilogue) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_VannaT_Happy)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_VannaT_Epilogue)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Chan_Epilogue) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Chan_Run, ANIM_Chan_Idle, 0, MSG_Outro_0029)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Chan_Epilogue) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Chan_Epilogue)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Lee_Epilogue) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lee_Talk, ANIM_Lee_Idle, 0, MSG_Outro_002A)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Lee_Epilogue) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Lee_Epilogue)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_TheMaster_Epilogue) = {
    EVT_CALL(SpeakToPlayer, NPC_TheMaster, ANIM_TheMaster_Talk, ANIM_TheMaster_Idle, 0, MSG_Outro_0028)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TheMaster_Epilogue) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_TheMaster_Epilogue)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_01_Epilogue) = {
    EVT_CALL(SpeakToPlayer, NPC_Toad_01, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_Outro_002B)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_01_Epilogue) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono4, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono5, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono6, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_dummy, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_01_Epilogue)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_HarryT_Epilogue) = {
    EVT_CALL(SpeakToPlayer, NPC_HarryT, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_Outro_003A)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_HarryT_Epilogue) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_HarryT_Epilogue)))
    EVT_RETURN
    EVT_END
};

AnimID N(ExtraAnims_Luigi_Epilogue)[] = {
    ANIM_Luigi_Still,
    ANIM_Luigi_Idle,
    ANIM_Luigi_Walk,
    ANIM_Luigi_Run,
    ANIM_Luigi_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Luigi_Epilogue) = {
    .id = NPC_Luigi_Epilogue,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .settings = &N(NpcSettings_Luigi_Epilogue),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = LUIGI_ANIMS,
    .extraAnimations = N(ExtraAnims_Luigi_Epilogue),
};

AnimID N(ExtraAnims_Goompapa_Epilogue)[] = {
    ANIM_Goompapa_Still,
    ANIM_Goompapa_Idle,
    ANIM_Goompapa_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Goomama_Epilogue)[] = {
    ANIM_Goomama_Still,
    ANIM_Goomama_Idle,
    ANIM_Goomama_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Gooma_Epilogue)[] = {
    ANIM_Gooma_Still,
    ANIM_Gooma_Idle,
    ANIM_Gooma_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_GoombaFamilypa_Epilogue)[] = {
    {
        .id = NPC_Goompapa_Epilogue,
        .pos = { 70.0f, 0.0f, -30.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Goompapa_Epilogue),
        .settings = &N(NpcSettings_GoombaFamily_Epilogue),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000,
        .drops = NO_DROPS,
        .animations = GOOMPAPA_ANIMS,
        .extraAnimations = N(ExtraAnims_Goompapa_Epilogue),
        .tattle = MSG_NpcTattle_Goompapa,
    },
    {
        .id = NPC_Goomama_Epilogue,
        .pos = { 40.0f, 0.0f, 20.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Goomama_Epilogue),
        .settings = &N(NpcSettings_GoombaFamily_Epilogue),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000,
        .drops = NO_DROPS,
        .animations = GOOMAMA_ANIMS,
        .extraAnimations = N(ExtraAnims_Goomama_Epilogue),
        .tattle = MSG_NpcTattle_Goomama,
    },
    {
        .id = NPC_Gooma_Epilogue,
        .pos = { 20.0f, 0.0f, -35.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Gooma_Epilogue),
        .settings = &N(NpcSettings_GoombaFamily_Epilogue),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000,
        .drops = NO_DROPS,
        .animations = GOOMA_ANIMS,
        .extraAnimations = N(ExtraAnims_Gooma_Epilogue),
        .tattle = MSG_NpcTattle_Gooma,
    },
};

AnimID N(ExtraAnims_Quizmo_Epilogue)[] = {
    ANIM_ChuckQuizmo_Still,
    ANIM_ChuckQuizmo_Idle,
    ANIM_ChuckQuizmo_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_VannaT_Epilogue)[] = {
    ANIM_VannaT_Still,
    ANIM_VannaT_Happy,
    ANIM_VannaT_Wave,
    ANIM_LIST_END
};

NpcData N(NpcData_ChuckQuizmo_Epilogue)[] = {
    {
        .id = NPC_ChuckQuizmo,
        .pos = { 545.0f, 20.0f, 150.0f },
        .yaw = 30,
        .init = &N(EVS_NpcInit_ChuckQuizmo_Epilogue),
        .settings = &N(NpcSettings_Luigi_Epilogue),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ChuckQuizmo_Idle,
            .walk   = ANIM_ChuckQuizmo_Walk,
            .run    = ANIM_ChuckQuizmo_Run,
            .chase  = ANIM_ChuckQuizmo_Run,
            .anim_4 = ANIM_ChuckQuizmo_Idle,
            .anim_5 = ANIM_ChuckQuizmo_Idle,
            .death  = ANIM_ChuckQuizmo_Still,
            .hit    = ANIM_ChuckQuizmo_Still,
            .anim_8 = ANIM_ChuckQuizmo_Run,
            .anim_9 = ANIM_ChuckQuizmo_Run,
            .anim_A = ANIM_ChuckQuizmo_Run,
            .anim_B = ANIM_ChuckQuizmo_Run,
            .anim_C = ANIM_ChuckQuizmo_Run,
            .anim_D = ANIM_ChuckQuizmo_Run,
            .anim_E = ANIM_ChuckQuizmo_Run,
            .anim_F = ANIM_ChuckQuizmo_Run,
        },
        .extraAnimations = N(ExtraAnims_Quizmo_Epilogue),
        .tattle = MSG_NpcTattle_ChuckQuizmo,
    },
    {
        .id = NPC_VannaT_Epilogue,
        .pos = { 500.0f, 20.0f, -130.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_VannaT_Epilogue),
        .settings = &N(NpcSettings_Toad_Stationary_Epilogue),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_VannaT_Still,
            .walk   = ANIM_VannaT_Walk,
            .run    = ANIM_VannaT_Still,
            .chase  = ANIM_VannaT_Still,
            .anim_4 = ANIM_VannaT_Still,
            .anim_5 = ANIM_VannaT_Still,
            .death  = ANIM_VannaT_Still,
            .hit    = ANIM_VannaT_Still,
            .anim_8 = ANIM_VannaT_Still,
            .anim_9 = ANIM_VannaT_Still,
            .anim_A = ANIM_VannaT_Still,
            .anim_B = ANIM_VannaT_Still,
            .anim_C = ANIM_VannaT_Still,
            .anim_D = ANIM_VannaT_Still,
            .anim_E = ANIM_VannaT_Still,
            .anim_F = ANIM_VannaT_Still,
        },
        .extraAnimations = N(ExtraAnims_VannaT_Epilogue),
        .tattle = MSG_NpcTattle_MAC00_ShopOwner,
    },
};

AnimID N(ExtraAnims_TheMaster_Epilogue)[] = {
    ANIM_TheMaster_Still,
    ANIM_TheMaster_Idle,
    ANIM_TheMaster_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Chan_Epilogue)[] = {
    ANIM_Chan_Still,
    ANIM_Chan_Idle,
    ANIM_Chan_Run,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Lee_Epilogue)[] = {
    ANIM_Lee_Still,
    ANIM_Lee_Idle,
    ANIM_Lee_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_DojoMembers_Epilogue)[] = {
    {
        .id = NPC_TheMaster,
        .pos = { 375.0f, 115.0f, -440.0f },
        .yaw = 225,
        .init = &N(EVS_NpcInit_TheMaster_Epilogue),
        .settings = &N(NpcSettings_Luigi_Epilogue),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_TheMaster_Idle,
            .walk   = ANIM_TheMaster_Still,
            .run    = ANIM_TheMaster_Still,
            .chase  = ANIM_TheMaster_Still,
            .anim_4 = ANIM_TheMaster_Still,
            .anim_5 = ANIM_TheMaster_Still,
            .death  = ANIM_TheMaster_Still,
            .hit    = ANIM_TheMaster_Still,
            .anim_8 = ANIM_TheMaster_Still,
            .anim_9 = ANIM_TheMaster_Still,
            .anim_A = ANIM_TheMaster_Still,
            .anim_B = ANIM_TheMaster_Still,
            .anim_C = ANIM_TheMaster_Still,
            .anim_D = ANIM_TheMaster_Still,
            .anim_E = ANIM_TheMaster_Still,
            .anim_F = ANIM_TheMaster_Still,
        },
        .extraAnimations = N(ExtraAnims_TheMaster_Epilogue),
        .tattle = MSG_NpcTattle_TheMaster,
    },
    {
        .id = NPC_Chan,
        .pos = { 310.0f, 115.0f, -390.0f },
        .yaw = 45,
        .init = &N(EVS_NpcInit_Chan_Epilogue),
        .settings = &N(NpcSettings_Luigi_Epilogue),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Chan_Idle,
        },
        .extraAnimations = N(ExtraAnims_Chan_Epilogue),
        .tattle = MSG_NpcTattle_Chan,
    },
    {
        .id = NPC_Lee,
        .pos = { 330.0f, 115.0f, -410.0f },
        .yaw = 45,
        .init = &N(EVS_NpcInit_Lee_Epilogue),
        .settings = &N(NpcSettings_Luigi_Epilogue),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Lee_Idle,
        },
        .extraAnimations = N(ExtraAnims_Lee_Epilogue),
        .tattle = MSG_NpcTattle_Lee,
    },
};

AnimID N(ExtraAnims_HarryT_Epilogue)[] = {
    ANIM_HarryT_Still,
    ANIM_HarryT_Idle,
    ANIM_HarryT_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Toad_01_Epilogue)[] = {
    {
        .id = NPC_Toad_01,
        .pos = { 430.0f, 20.0f, -373.0f },
        .yaw = 223,
        .init = &N(EVS_NpcInit_Toad_01_Epilogue),
        .settings = &N(NpcSettings_Toad_Stationary_Epilogue),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_HarryT_Idle,
            .walk   = ANIM_HarryT_Walk,
            .run    = ANIM_HarryT_Run,
            .chase  = ANIM_HarryT_Run,
            .anim_4 = ANIM_HarryT_Idle,
        },
        .extraAnimations = N(ExtraAnims_HarryT_Epilogue),
        .tattle = MSG_NpcTattle_MAC00_ShopOwner,
    },
    {
        .id = NPC_HarryT,
        .pos = { 410.0f, 20.0f, -320.0f },
        .yaw = 43,
        .init = &N(EVS_NpcInit_HarryT_Epilogue),
        .settings = &N(NpcSettings_Toad_Stationary_Epilogue),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_HarryT_Idle,
            .walk   = ANIM_HarryT_Walk,
            .run    = ANIM_HarryT_Run,
            .chase  = ANIM_HarryT_Run,
            .anim_4 = ANIM_HarryT_Idle,
        },
        .extraAnimations = N(ExtraAnims_HarryT_Epilogue),
        .tattle = MSG_NpcTattle_MAC00_ShopOwner,
    },
};

extern NpcData N(NpcData_SharedTownsfolk)[9]; //@bug this NPC list actually has 10 NPCs in it...
extern NpcData N(NpcData_Waterfront_Family)[4];

NpcGroupList N(EpilogueNPCs) = {
    NPC_GROUP(N(NpcData_Luigi_Epilogue)),
    NPC_GROUP(N(NpcData_DojoMembers_Epilogue)),
    NPC_GROUP(N(NpcData_GoombaFamilypa_Epilogue)),
    NPC_GROUP(N(NpcData_ChuckQuizmo_Epilogue)),
    NPC_GROUP(N(NpcData_Toad_01_Epilogue)),
    NPC_GROUP(N(NpcData_SharedTownsfolk)),
    NPC_GROUP(N(NpcData_Waterfront_Family)),
    {}
};
