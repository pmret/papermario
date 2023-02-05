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

EvtScript N(EVS_NpcInteract_Bobomb) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_Outro_004E)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bobomb) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bobomb)))
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

EvtScript N(EVS_NpcInteract_Poet) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Poet_Talk, ANIM_Musician_Poet_Idle, 16, MSG_Outro_0053)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Poet) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Poet)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Composer) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Musician_Composer_Talk, ANIM_Musician_Composer_Idle, 16, MSG_Outro_0054)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Composer) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Composer)))
    EVT_RETURN
    EVT_END
};

s32 N(ExtraAnims_Kolorado)[] = {
    ANIM_Kolorado_Still,
    ANIM_Kolorado_Idle,
    ANIM_Kolorado_Talk,
    -1
};

s32 N(ExtraAnims_KoloradoWife)[] = {
    ANIM_KoloradoWife_Still,
    ANIM_KoloradoWife_Idle,
    ANIM_KoloradoWife_Talk,
    -1
};

s32 N(ExtraAnims_KoopaKoot)[] = {
    ANIM_KoopaKoot_Still,
    ANIM_KoopaKoot_Idle,
    ANIM_KoopaKoot_Talk,
    -1
};

s32 N(ExtraAnims_Koopa)[] = {
    ANIM_Koopa_Still,
    ANIM_Koopa_Idle,
    ANIM_Koopa_Talk,
    -1
};

s32 N(ExtraAnims_Bobomb)[] = {
    ANIM_WorldBobomb_Green_Still,
    ANIM_WorldBobomb_Green_Idle,
    ANIM_WorldBobomb_Green_Talk,
    -1
};

StaticNpc N(NpcData_Koopas)[] = {
    {
        .id = NPC_Kolorado,
        .settings = &N(NpcSettings_Kolorado),
        .pos = { 60.0f, 0.0f, -120.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Kolorado),
        .drops = KOLORADO_DROPS,
        .animations = KOLORADO_ANIMS,
        .extraAnimations = N(ExtraAnims_Kolorado),
    },
    {
        .id = NPC_KoloradoWife,
        .settings = &N(NpcSettings_KoloradoWife),
        .pos = { 100.0f, 0.0f, -110.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_KoloradoWife),
        .drops = KOLORADO_WIFE_DROPS,
        .animations = KOLORADO_WIFE_ANIMS,
        .extraAnimations = N(ExtraAnims_KoloradoWife),
    },
    {
        .id = NPC_KoopaKoot,
        .settings = &N(NpcSettings_KoopaKoot),
        .pos = { -330.0f, 0.0f, 330.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_KoopaKoot),
        .drops = KOOPA_KOOT_DROPS,
        .animations = KOOPA_KOOT_ANIMS,
        .extraAnimations = N(ExtraAnims_KoopaKoot),
    },
    {
        .id = NPC_Koopa,
        .settings = &N(NpcSettings_Koopa),
        .pos = { 300.0f, 20.0f, -100.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Koopa),
        .drops = KOOPA_DROPS,
        .animations = KOOPA_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopa),
    },
    {
        .id = NPC_Bobomb,
        .settings = &N(NpcSettings_Bobomb),
        .pos = { 252.0f, 20.0f, -100.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Bobomb),
        .drops = BOBOMB_DROPS,
        .animations = BOBOMB_BLUE_ANIMS,
        .extraAnimations = N(ExtraAnims_Bobomb),
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
        .settings = &N(NpcSettings_Dummy),
        .pos = { -213.0f, -54.0f, 256.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Rowf),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
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
        .settings = &N(NpcSettings_Dummy),
        .pos = { -250.0f, 0.0f, 263.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Rhuff),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
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

s32 N(ExtraAnims_Dryite)[] = {
    ANIM_Dryite_Green_Still,
    ANIM_Dryite_Green_Idle,
    ANIM_Dryite_Green_Talk,
    -1
};

StaticNpc N(NpcData_Dryites)[] = {
    {
        .id = NPC_Dryite_01,
        .settings = &N(NpcSettings_Dryite),
        .pos = { -10.0f, 0.0f, 360.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Dryite_01),
        .drops = DRYITE_DROPS,
        .animations = DRYITE_GREEN_ANIMS,
        .extraAnimations = N(ExtraAnims_Dryite),
    },
    {
        .id = NPC_Dryite_02,
        .settings = &N(NpcSettings_Dryite),
        .pos = { 25.0f, 0.0f, 300.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Dryite_02),
        .drops = DRYITE_DROPS,
        .animations = DRYITE_GREEN_ANIMS,
        .extraAnimations = N(ExtraAnims_Dryite),
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

StaticNpc N(NpcData_Artists)[] = {
    {
        .id = NPC_Chanterelle,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 260.0f, 20.0f, 560.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000 | ENEMY_FLAG_400000,
        .init = &N(EVS_NpcInit_Chanterelle),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
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
        .id = NPC_Poet,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 230.0f, 20.0f, 500.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000 | ENEMY_FLAG_400000,
        .init = &N(EVS_NpcInit_Poet),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
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
        .id = NPC_Composer,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 300.0f, 20.0f, 500.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000 | ENEMY_FLAG_400000,
        .init = &N(EVS_NpcInit_Composer),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
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
extern StaticNpc N(NpcData_Townsfolk)[10];

NpcGroupList N(EpilogueNPCs) = {
    NPC_GROUP(N(NpcData_Koopas_Epilogue)),
    NPC_GROUP(N(NpcData_RowfAndRhuff_Epilogue)),
    NPC_GROUP(N(NpcData_Dryites_Epilogue)),
    NPC_GROUP(N(NpcData_Artists_Epilogue)),
    NPC_GROUP(N(NpcData_Townsfolk)),
    {}
};
