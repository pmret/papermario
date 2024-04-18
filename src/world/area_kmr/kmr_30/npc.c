#include "kmr_30.h"

NpcSettings N(NpcSettings_ParadePeach) = {
    .height = 46,
    .radius = 36,
    .level = ACTOR_LEVEL_NONE,
};

NpcData N(NpcData_ParadePeach) = {
    .id = NPC_ParadePeach,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .settings = &N(NpcSettings_ParadePeach),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_ParadePeach_IdleRaisedArms,
        .walk   = ANIM_ParadePeach_IdleRaisedArms,
        .run    = ANIM_ParadePeach_IdleRaisedArms,
        .chase  = ANIM_ParadePeach_IdleRaisedArms,
        .anim_4 = ANIM_ParadePeach_IdleRaisedArms,
        .anim_5 = ANIM_ParadePeach_IdleRaisedArms,
        .death  = ANIM_ParadePeach_IdleRaisedArms,
        .hit    = ANIM_ParadePeach_IdleRaisedArms,
        .anim_8 = ANIM_ParadePeach_IdleRaisedArms,
        .anim_9 = ANIM_ParadePeach_IdleRaisedArms,
        .anim_A = ANIM_ParadePeach_IdleRaisedArms,
        .anim_B = ANIM_ParadePeach_IdleRaisedArms,
        .anim_C = ANIM_ParadePeach_IdleRaisedArms,
        .anim_D = ANIM_ParadePeach_IdleRaisedArms,
        .anim_E = ANIM_ParadePeach_IdleRaisedArms,
        .anim_F = ANIM_ParadePeach_IdleRaisedArms,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_ParadePeach)),
    {}
};
