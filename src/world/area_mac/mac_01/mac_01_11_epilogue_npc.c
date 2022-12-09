#include "mac_01.h"
#define NAME_SUFFIX _Epilogue

NpcSettings N(NpcSettings_Toad_01) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_Chanterelle) = {
    .height = 30,
    .radius = 24,
    .level = 99,
};

s32 N(missing_8025FAA8_1FAA8)[] = {
    0x00000000, 0x00170013, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00630000, 
};

NpcSettings N(NpcSettings_Kolorado) = {
    .height = 40,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_KoloradoWife) = {
    .height = 38,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_KoopaKoot) = {
    .height = 32,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_Koopa) = {
    .height = 35,
    .radius = 24,
    .level = 99,
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

NpcSettings N(NpcSettings_Bombomb) = {
    .height = 23,
    .radius = 20,
    .level = 6,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_Dryite_01) = {
    .height = 26,
    .radius = 23,
    .level = 99,
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_Outro_003C)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_KoloradoWife) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_Outro_003D)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoloradoWife) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_KoloradoWife)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_KoopaKoot) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_Outro_003E)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaKoot) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_KoopaKoot)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bombomb) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_Outro_004E)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bombomb) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bombomb)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopa) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_Outro_004F)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopa)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Rowf) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_Outro_0040)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Rowf) = {
    EVT_CALL(SetNpcPos, NPC_SELF, -225, 0, 320)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Rowf)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Rhuff) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_Outro_0041)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Rhuff) = {
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(0.75), EVT_FLOAT(0.75), EVT_FLOAT(0.75))
    EVT_CALL(SetNpcPos, NPC_SELF, -250, 0, 295)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Rhuff)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Dryite_01) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_Outro_0050)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Dryite_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Dryite_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Dryite_02) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_Outro_0051)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Dryite_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Dryite_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Chanterelle) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Chanterelle_Talk, ANIM_Chanterelle_Idle, 16, MSG_Outro_0052)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Chanterelle) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Chanterelle_Sing)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Chanterelle)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ArtistToad_01) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 16, MSG_Outro_0053)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ArtistToad_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ArtistToad_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ArtistToad_02) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 16, MSG_Outro_0054)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ArtistToad_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ArtistToad_02)))
    EVT_RETURN
    EVT_END
};

s32 N(D_8026005C_8208DC)[] = {
    ANIM_Kolorado_Still,
    ANIM_Kolorado_Idle,
    ANIM_Kolorado_Talk,
    -1
};

s32 N(D_8026006C_8208EC)[] = {
    ANIM_KoloradoWife_Still,
    ANIM_KoloradoWife_Idle,
    ANIM_KoloradoWife_Talk,
    -1
};

s32 N(D_8026007C_8208FC)[] = {
    ANIM_KoopaKoot_Still,
    ANIM_KoopaKoot_Idle,
    ANIM_KoopaKoot_Talk,
    -1
};

s32 N(D_8026008C_82090C)[] = {
    ANIM_Koopa_Still,
    ANIM_Koopa_Idle,
    ANIM_Koopa_Talk,
    -1
};

s32 N(D_8026009C_82091C)[] = {
    ANIM_WorldBobomb_Green_Still,
    ANIM_WorldBobomb_Green_Idle,
    ANIM_WorldBobomb_Green_Talk,
    -1
};

StaticNpc N(NpcData_Kolorado)[] = {
    {
        .id = NPC_Kolorado,
        .settings = &N(NpcSettings_Kolorado),
        .pos = { 60.0f, 0.0f, -120.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Kolorado),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Kolorado_Idle,
            .walk   = ANIM_Kolorado_Walk,
            .run    = ANIM_Kolorado_Run,
            .chase  = ANIM_Kolorado_Run,
            .anim_4 = ANIM_Kolorado_Idle,
            .anim_5 = ANIM_Kolorado_Idle,
            .death  = ANIM_Kolorado_Idle,
            .hit    = ANIM_Kolorado_Idle,
            .anim_8 = ANIM_Kolorado_Idle,
            .anim_9 = ANIM_Kolorado_Idle,
            .anim_A = ANIM_Kolorado_Idle,
            .anim_B = ANIM_Kolorado_Idle,
            .anim_C = ANIM_Kolorado_Idle,
            .anim_D = ANIM_Kolorado_Idle,
            .anim_E = ANIM_Kolorado_Idle,
            .anim_F = ANIM_Kolorado_Idle,
        },
        .extraAnimations = N(D_8026005C_8208DC),
    },
    {
        .id = NPC_KoloradoWife,
        .settings = &N(NpcSettings_KoloradoWife),
        .pos = { 100.0f, 0.0f, -110.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_KoloradoWife),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_KoloradoWife_Idle,
            .walk   = ANIM_KoloradoWife_Walk,
            .run    = ANIM_KoloradoWife_Run,
            .chase  = ANIM_KoloradoWife_Run,
            .anim_4 = ANIM_KoloradoWife_Idle,
            .anim_5 = ANIM_KoloradoWife_Idle,
            .death  = ANIM_KoloradoWife_Idle,
            .hit    = ANIM_KoloradoWife_Idle,
            .anim_8 = ANIM_KoloradoWife_Idle,
            .anim_9 = ANIM_KoloradoWife_Idle,
            .anim_A = ANIM_KoloradoWife_Idle,
            .anim_B = ANIM_KoloradoWife_Idle,
            .anim_C = ANIM_KoloradoWife_Idle,
            .anim_D = ANIM_KoloradoWife_Idle,
            .anim_E = ANIM_KoloradoWife_Idle,
            .anim_F = ANIM_KoloradoWife_Idle,
        },
        .extraAnimations = N(D_8026006C_8208EC),
    },
    {
        .id = NPC_KoopaKoot,
        .settings = &N(NpcSettings_KoopaKoot),
        .pos = { -330.0f, 0.0f, 330.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_KoopaKoot),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_KoopaKoot_Idle,
            .walk   = ANIM_KoopaKoot_Idle,
            .run    = ANIM_KoopaKoot_Idle,
            .chase  = ANIM_KoopaKoot_Idle,
            .anim_4 = ANIM_KoopaKoot_Idle,
            .anim_5 = ANIM_KoopaKoot_Idle,
            .death  = ANIM_KoopaKoot_Idle,
            .hit    = ANIM_KoopaKoot_Idle,
            .anim_8 = ANIM_KoopaKoot_Idle,
            .anim_9 = ANIM_KoopaKoot_Idle,
            .anim_A = ANIM_KoopaKoot_Idle,
            .anim_B = ANIM_KoopaKoot_Idle,
            .anim_C = ANIM_KoopaKoot_Idle,
            .anim_D = ANIM_KoopaKoot_Idle,
            .anim_E = ANIM_KoopaKoot_Idle,
            .anim_F = ANIM_KoopaKoot_Idle,
        },
        .extraAnimations = N(D_8026007C_8208FC),
    },
    {
        .id = NPC_Koopa,
        .settings = &N(NpcSettings_Koopa),
        .pos = { 300.0f, 20.0f, -100.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Koopa),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Koopa_Idle,
            .walk   = ANIM_Koopa_Walk,
            .run    = ANIM_Koopa_Run,
            .chase  = ANIM_Koopa_Run,
            .anim_4 = ANIM_Koopa_Idle,
            .anim_5 = ANIM_Koopa_Idle,
            .death  = ANIM_Koopa_Still,
            .hit    = ANIM_Koopa_Still,
            .anim_8 = ANIM_Koopa_Still,
            .anim_9 = ANIM_Koopa_Still,
            .anim_A = ANIM_Koopa_Still,
            .anim_B = ANIM_Koopa_Still,
            .anim_C = ANIM_Koopa_Still,
            .anim_D = ANIM_Koopa_Still,
            .anim_E = ANIM_Koopa_Still,
            .anim_F = ANIM_Koopa_Still,
        },
        .extraAnimations = N(D_8026008C_82090C),
    },
    {
        .id = NPC_Bombomb,
        .settings = &N(NpcSettings_Bombomb),
        .pos = { 252.0f, 20.0f, -100.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Bombomb),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldBobomb_Blue_Idle,
            .walk   = ANIM_WorldBobomb_Blue_Walk,
            .run    = ANIM_WorldBobomb_Blue_Run,
            .chase  = ANIM_WorldBobomb_Blue_Run,
            .anim_4 = ANIM_WorldBobomb_Blue_Idle,
            .anim_5 = ANIM_WorldBobomb_Blue_Idle,
            .death  = ANIM_WorldBobomb_Blue_Still,
            .hit    = ANIM_WorldBobomb_Blue_Still,
            .anim_8 = ANIM_WorldBobomb_Blue_Still,
            .anim_9 = ANIM_WorldBobomb_Blue_Still,
            .anim_A = ANIM_WorldBobomb_Blue_Still,
            .anim_B = ANIM_WorldBobomb_Blue_Still,
            .anim_C = ANIM_WorldBobomb_Blue_Still,
            .anim_D = ANIM_WorldBobomb_Blue_Still,
            .anim_E = ANIM_WorldBobomb_Blue_Still,
            .anim_F = ANIM_WorldBobomb_Blue_Still,
        },
        .extraAnimations = N(D_8026009C_82091C),
    },
};

s32 N(ExtraAnims_Rowf)[] = {
    ANIM_Rowf_Still,
    ANIM_Rowf_Idle,
    ANIM_Rowf_Talk,
    -1
};

StaticNpc N(NpcData_RowfAndRhuff)[] = {
    {
        .id = NPC_Rowf,
        .settings = &N(NpcSettings_Toad_01),
        .pos = { -213.0f, -54.0f, 256.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Rowf),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Rowf_Idle,
        },
        .extraAnimations = N(ExtraAnims_Rowf),
        .tattle = MSG_NpcTattle_Rowf,
    },
    {
        .id = NPC_Rhuff,
        .settings = &N(NpcSettings_Toad_01),
        .pos = { -250.0f, 0.0f, 263.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Rhuff),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Rowf_Idle,
        },
        .extraAnimations = N(ExtraAnims_Rowf),
        .tattle = MSG_NpcTattle_Rhuff,
    },
};

s32 N(D_80260E4C_8216CC)[] = {
    ANIM_Dryite_Green_Still,
    ANIM_Dryite_Green_Idle,
    ANIM_Dryite_Green_Talk,
    -1
};

StaticNpc N(NpcData_Dryite_01)[] = {
    {
        .id = NPC_Dryite_01,
        .settings = &N(NpcSettings_Dryite_01),
        .pos = { -10.0f, 0.0f, 360.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Dryite_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Dryite_Green_Idle,
            .walk   = ANIM_Dryite_Green_Walk,
            .run    = ANIM_Dryite_Green_Run,
            .chase  = ANIM_Dryite_Green_Run,
            .anim_4 = ANIM_Dryite_Green_Idle,
            .anim_5 = ANIM_Dryite_Green_Idle,
            .death  = ANIM_Dryite_Green_Still,
            .hit    = ANIM_Dryite_Green_Still,
            .anim_8 = ANIM_Dryite_Green_Idle,
            .anim_9 = ANIM_Dryite_Green_Idle,
            .anim_A = ANIM_Dryite_Green_Idle,
            .anim_B = ANIM_Dryite_Green_Idle,
            .anim_C = ANIM_Dryite_Green_Idle,
            .anim_D = ANIM_Dryite_Green_Idle,
            .anim_E = ANIM_Dryite_Green_Idle,
            .anim_F = ANIM_Dryite_Green_Idle,
        },
        .extraAnimations = N(D_80260E4C_8216CC),
    },
    {
        .id = NPC_Dryite_02,
        .settings = &N(NpcSettings_Dryite_01),
        .pos = { 25.0f, 0.0f, 300.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
        .init = &N(EVS_NpcInit_Dryite_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Dryite_Green_Idle,
            .walk   = ANIM_Dryite_Green_Walk,
            .run    = ANIM_Dryite_Green_Run,
            .chase  = ANIM_Dryite_Green_Run,
            .anim_4 = ANIM_Dryite_Green_Idle,
            .anim_5 = ANIM_Dryite_Green_Idle,
            .death  = ANIM_Dryite_Green_Still,
            .hit    = ANIM_Dryite_Green_Still,
            .anim_8 = ANIM_Dryite_Green_Idle,
            .anim_9 = ANIM_Dryite_Green_Idle,
            .anim_A = ANIM_Dryite_Green_Idle,
            .anim_B = ANIM_Dryite_Green_Idle,
            .anim_C = ANIM_Dryite_Green_Idle,
            .anim_D = ANIM_Dryite_Green_Idle,
            .anim_E = ANIM_Dryite_Green_Idle,
            .anim_F = ANIM_Dryite_Green_Idle,
        },
        .extraAnimations = N(D_80260E4C_8216CC),
    },
};

s32 N(ExtraAnims_Chanterelle)[] = {
    ANIM_Chanterelle_Still,
    ANIM_Chanterelle_Idle,
    ANIM_Chanterelle_Sing,
    ANIM_Chanterelle_Talk,
    -1
};

s32 N(ExtraAnims_Poet)[] = {
    ANIM_Musician_Poet_Still,
    ANIM_Musician_Poet_Idle,
    ANIM_Musician_Poet_Talk,
    -1
};

StaticNpc N(NpcData_EpilogueNPCs)[] = {
    {
        .id = NPC_Chanterelle,
        .settings = &N(NpcSettings_Chanterelle),
        .pos = { 260.0f, 20.0f, 560.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_400000,
        .init = &N(EVS_NpcInit_Chanterelle),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .id = NPC_ArtistToad_01,
        .settings = &N(NpcSettings_Chanterelle),
        .pos = { 230.0f, 20.0f, 500.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_400000,
        .init = &N(EVS_NpcInit_ArtistToad_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .id = NPC_ArtistToad_02,
        .settings = &N(NpcSettings_Chanterelle),
        .pos = { 300.0f, 20.0f, 500.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_400000,
        .init = &N(EVS_NpcInit_ArtistToad_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
extern StaticNpc N(NpcData_Toad_04)[10];

NpcGroupList N(EpilogueNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado_Epilogue)),
    NPC_GROUP(N(NpcData_RowfAndRhuff_Epilogue)),
    NPC_GROUP(N(NpcData_Dryite_01_Epilogue)),
    NPC_GROUP(N(NpcData_EpilogueNPCs_Epilogue)),
    NPC_GROUP(N(NpcData_Toad_04)),
    {}
};
