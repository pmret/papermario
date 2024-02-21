#include "mac_01.h"
#define NAME_SUFFIX _Epilogue

#include "world/common/npc/Dummy.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/Kolorado.inc.c"
#include "world/common/npc/KoloradoWife.inc.c"
#include "world/common/npc/KoopaKoot.inc.c"
#include "world/common/npc/Koopa.inc.c"
#include "world/common/npc/Bobomb.inc.c"
#include "world/common/npc/Dryite_Stationary.inc.c"

EvtScript N(EVS_NpcInteract_Kolorado) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_Outro_003C)
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kolorado)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_KoloradoWife) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_Outro_003D)
    Return
    End
};

EvtScript N(EVS_NpcInit_KoloradoWife) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_KoloradoWife)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_KoopaKoot) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_Outro_003E)
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopaKoot) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_KoopaKoot)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bobomb) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_Outro_004E)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bobomb) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bobomb)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Koopa) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_Outro_004F)
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopa) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopa)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Rowf) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_Outro_0040)
    Return
    End
};

EvtScript N(EVS_NpcInit_Rowf) = {
    Call(SetNpcPos, NPC_SELF, -225, 0, 320)
    Call(SetNpcYaw, NPC_SELF, 270)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Rowf)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Rhuff) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_Outro_0041)
    Return
    End
};

EvtScript N(EVS_NpcInit_Rhuff) = {
    Call(SetNpcScale, NPC_SELF, Float(0.75), Float(0.75), Float(0.75))
    Call(SetNpcPos, NPC_SELF, -250, 0, 295)
    Call(SetNpcYaw, NPC_SELF, 270)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Rhuff)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Dryite_01) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_Outro_0050)
    Return
    End
};

EvtScript N(EVS_NpcInit_Dryite_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Dryite_01)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Dryite_02) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_Outro_0051)
    Return
    End
};

EvtScript N(EVS_NpcInit_Dryite_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Dryite_02)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Chanterelle) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 16, MSG_Outro_0052)
    Return
    End
};

EvtScript N(EVS_NpcInit_Chanterelle) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_Chanterelle_Sing)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Chanterelle)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Poet) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 16, MSG_Outro_0053)
    Return
    End
};

EvtScript N(EVS_NpcInit_Poet) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Poet)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Composer) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 16, MSG_Outro_0054)
    Return
    End
};

EvtScript N(EVS_NpcInit_Composer) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Composer)))
    Return
    End
};

AnimID N(ExtraAnims_Kolorado)[] = {
    ANIM_Kolorado_Still,
    ANIM_Kolorado_Idle,
    ANIM_Kolorado_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_KoloradoWife)[] = {
    ANIM_KoloradoWife_Still,
    ANIM_KoloradoWife_Idle,
    ANIM_KoloradoWife_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_KoopaKoot)[] = {
    ANIM_KoopaKoot_Still,
    ANIM_KoopaKoot_Idle,
    ANIM_KoopaKoot_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Koopa)[] = {
    ANIM_Koopa_Still,
    ANIM_Koopa_Idle,
    ANIM_Koopa_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Bobomb)[] = {
    ANIM_WorldBobomb_Green_Still,
    ANIM_WorldBobomb_Green_Idle,
    ANIM_WorldBobomb_Green_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Koopas)[] = {
    {
        .id = NPC_Kolorado,
        .pos = { 60.0f, 0.0f, -120.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Kolorado),
        .settings = &N(NpcSettings_Kolorado),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .extraAnimations = N(ExtraAnims_Kolorado),
    },
    {
        .id = NPC_KoloradoWife,
        .pos = { 100.0f, 0.0f, -110.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_KoloradoWife),
        .settings = &N(NpcSettings_KoloradoWife),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOLORADO_WIFE_ANIMS,
        .extraAnimations = N(ExtraAnims_KoloradoWife),
    },
    {
        .id = NPC_KoopaKoot,
        .pos = { -330.0f, 0.0f, 330.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_KoopaKoot),
        .settings = &N(NpcSettings_KoopaKoot),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_KOOT_ANIMS,
        .extraAnimations = N(ExtraAnims_KoopaKoot),
    },
    {
        .id = NPC_Koopa,
        .pos = { 300.0f, 20.0f, -100.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Koopa),
        .settings = &N(NpcSettings_Koopa),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopa),
    },
    {
        .id = NPC_Bobomb,
        .pos = { 252.0f, 20.0f, -100.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Bobomb),
        .settings = &N(NpcSettings_Bobomb),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = BOBOMB_BLUE_ANIMS,
        .extraAnimations = N(ExtraAnims_Bobomb),
    },
};

AnimID N(ExtraAnims_Rowf)[] = {
    ANIM_Rowf_Still,
    ANIM_Rowf_Idle,
    ANIM_Rowf_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_RowfAndRhuff)[] = {
    {
        .id = NPC_Rowf,
        .pos = { -213.0f, -54.0f, 256.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Rowf),
        .settings = &N(NpcSettings_Dummy),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Rowf_Idle,
        },
        .extraAnimations = N(ExtraAnims_Rowf),
        .tattle = MSG_NpcTattle_Rowf,
    },
    {
        .id = NPC_Rhuff,
        .pos = { -250.0f, 0.0f, 263.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Rhuff),
        .settings = &N(NpcSettings_Dummy),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Rowf_Idle,
        },
        .extraAnimations = N(ExtraAnims_Rowf),
        .tattle = MSG_NpcTattle_Rhuff,
    },
};

AnimID N(ExtraAnims_Dryite)[] = {
    ANIM_Dryite_Green_Still,
    ANIM_Dryite_Green_Idle,
    ANIM_Dryite_Green_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Dryites)[] = {
    {
        .id = NPC_Dryite_01,
        .pos = { -10.0f, 0.0f, 360.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Dryite_01),
        .settings = &N(NpcSettings_Dryite),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = DRYITE_GREEN_ANIMS,
        .extraAnimations = N(ExtraAnims_Dryite),
    },
    {
        .id = NPC_Dryite_02,
        .pos = { 25.0f, 0.0f, 300.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Dryite_02),
        .settings = &N(NpcSettings_Dryite),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = DRYITE_GREEN_ANIMS,
        .extraAnimations = N(ExtraAnims_Dryite),
    },
};

AnimID N(ExtraAnims_Chanterelle)[] = {
    ANIM_Chanterelle_Still,
    ANIM_Chanterelle_Idle,
    ANIM_Chanterelle_Sing,
    ANIM_Chanterelle_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Poet)[] = {
    ANIM_Musician_Poet_Still,
    ANIM_Musician_Poet_Idle,
    ANIM_Musician_Poet_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Artists)[] = {
    {
        .id = NPC_Chanterelle,
        .pos = { 260.0f, 20.0f, 560.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Chanterelle),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Chanterelle_Idle,
            .walk   = ANIM_Chanterelle_Still,
            .run    = ANIM_Chanterelle_Still,
            .chase  = ANIM_Chanterelle_Still,
            .anim_4 = ANIM_Chanterelle_Still,
            .anim_5 = ANIM_Chanterelle_Still,
            .death  = ANIM_Chanterelle_Still,
            .hit    = ANIM_Chanterelle_Still,
            .anim_8 = ANIM_Chanterelle_Still,
            .anim_9 = ANIM_Chanterelle_Still,
            .anim_A = ANIM_Chanterelle_Still,
            .anim_B = ANIM_Chanterelle_Still,
            .anim_C = ANIM_Chanterelle_Still,
            .anim_D = ANIM_Chanterelle_Still,
            .anim_E = ANIM_Chanterelle_Still,
            .anim_F = ANIM_Chanterelle_Still,
        },
        .extraAnimations = N(ExtraAnims_Chanterelle),
        .tattle = MSG_NpcTattle_PopDiva_CantSing,
    },
    {
        .id = NPC_Poet,
        .pos = { 230.0f, 20.0f, 500.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Poet),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Musician_Poet_Idle,
            .walk   = ANIM_Musician_Poet_Idle,
            .run    = ANIM_Musician_Poet_Idle,
            .chase  = ANIM_Musician_Poet_Idle,
            .anim_4 = ANIM_Musician_Poet_Idle,
            .anim_5 = ANIM_Musician_Poet_Idle,
            .death  = ANIM_Musician_Poet_Idle,
            .hit    = ANIM_Musician_Poet_Idle,
            .anim_8 = ANIM_Musician_Poet_Idle,
            .anim_9 = ANIM_Musician_Poet_Idle,
            .anim_A = ANIM_Musician_Poet_Idle,
            .anim_B = ANIM_Musician_Poet_Idle,
            .anim_C = ANIM_Musician_Poet_Idle,
            .anim_D = ANIM_Musician_Poet_Idle,
            .anim_E = ANIM_Musician_Poet_Idle,
            .anim_F = ANIM_Musician_Poet_Idle,
        },
        .extraAnimations = N(ExtraAnims_Poet),
        .tattle = MSG_NpcTattle_MasterPoet,
    },
    {
        .id = NPC_Composer,
        .pos = { 300.0f, 20.0f, 500.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Composer),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Musician_Composer_Idle,
            .walk   = ANIM_Musician_Composer_Still,
            .run    = ANIM_Musician_Composer_Still,
            .chase  = ANIM_Musician_Composer_Still,
            .anim_4 = ANIM_Musician_Composer_Still,
            .anim_5 = ANIM_Musician_Composer_Still,
            .death  = ANIM_Musician_Composer_Still,
            .hit    = ANIM_Musician_Composer_Still,
            .anim_8 = ANIM_Musician_Composer_Still,
            .anim_9 = ANIM_Musician_Composer_Still,
            .anim_A = ANIM_Musician_Composer_Still,
            .anim_B = ANIM_Musician_Composer_Still,
            .anim_C = ANIM_Musician_Composer_Still,
            .anim_D = ANIM_Musician_Composer_Still,
            .anim_E = ANIM_Musician_Composer_Still,
            .anim_F = ANIM_Musician_Composer_Still,
        },
        .extraAnimations = N(ExtraAnims_Poet),
        .tattle = MSG_NpcTattle_Composer,
    },
};

#define NAME_SUFFIX
extern NpcData N(NpcData_Townsfolk)[10];

NpcGroupList N(EpilogueNPCs) = {
    NPC_GROUP(N(NpcData_Koopas_Epilogue)),
    NPC_GROUP(N(NpcData_RowfAndRhuff_Epilogue)),
    NPC_GROUP(N(NpcData_Dryites_Epilogue)),
    NPC_GROUP(N(NpcData_Artists_Epilogue)),
    NPC_GROUP(N(NpcData_Townsfolk)),
    {}
};
