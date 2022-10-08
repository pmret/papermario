#include "common.h"

#define YAKKEY_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .heartDrops  = NO_DROPS, \
    .flowerDrops = NO_DROPS, \
}

#define YAKKEY_ANIMS \
{ \
    .idle   = ANIM_Yakkey_Idle, \
    .walk   = ANIM_Yakkey_Idle, \
    .run    = ANIM_Yakkey_Idle, \
    .chase  = ANIM_Yakkey_Idle, \
    .anim_4 = ANIM_Yakkey_Idle, \
    .anim_5 = ANIM_Yakkey_Idle, \
    .death  = ANIM_Yakkey_Idle, \
    .hit    = ANIM_Yakkey_Idle, \
    .anim_8 = ANIM_Yakkey_Idle, \
    .anim_9 = ANIM_Yakkey_Idle, \
    .anim_A = ANIM_Yakkey_Idle, \
    .anim_B = ANIM_Yakkey_Idle, \
    .anim_C = ANIM_Yakkey_Idle, \
    .anim_D = ANIM_Yakkey_Idle, \
    .anim_E = ANIM_Yakkey_Idle, \
    .anim_F = ANIM_Yakkey_Idle, \
}

NpcSettings N(NpcSettings_Yakkey) = {
    .height = 24,
    .radius = 24,
    .level = 13,
};
