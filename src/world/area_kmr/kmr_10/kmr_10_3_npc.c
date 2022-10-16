#include "kmr_10.h"

NpcSettings N(NpcSettings_Toad) = {
    .height = 30,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_Unused1) = {
    .height = 23,
    .radius = 19,
    .level = 99,
};

EvtScript N(EVS_NpcInit_Toad) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Toad) = {
    .id = NPC_Dummy,
    .settings = &N(NpcSettings_Toad),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_4000 | NPC_FLAG_200000,
    .init = &N(EVS_NpcInit_Toad),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Toad_Red_Idle,
        .walk   = ANIM_Toad_Red_Walk,
        .run    = ANIM_Toad_Red_Run,
        .chase  = ANIM_Toad_Red_Run,
        .anim_4 = ANIM_Toad_Red_Idle,
        .anim_5 = ANIM_Toad_Red_Idle,
        .death  = ANIM_Toad_Red_Disappointed,
        .hit    = ANIM_Toad_Red_Disappointed,
        .anim_8 = ANIM_Toad_Red_Run,
        .anim_9 = ANIM_Toad_Red_Run,
        .anim_A = ANIM_Toad_Red_Run,
        .anim_B = ANIM_Toad_Red_Run,
        .anim_C = ANIM_Toad_Red_Run,
        .anim_D = ANIM_Toad_Red_Run,
        .anim_E = ANIM_Toad_Red_Run,
        .anim_F = ANIM_Toad_Red_Run,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Toad)),
    {}
};
