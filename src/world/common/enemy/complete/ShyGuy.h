#include "common.h"
#include "sprite/npc/ShyGuy.h"

#define SHY_GUY_NO_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .heartDrops  = NO_DROPS, \
    .flowerDrops = NO_DROPS, \
}

#define SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Red_Anim01, \
    .walk   = ANIM_ShyGuy_Red_Anim02, \
    .run    = ANIM_ShyGuy_Red_Anim03, \
    .chase  = ANIM_ShyGuy_Red_Anim03, \
    .anim_4 = ANIM_ShyGuy_Red_Anim01, \
    .anim_5 = ANIM_ShyGuy_Red_Anim01, \
    .death  = ANIM_ShyGuy_Red_Anim0C, \
    .hit    = ANIM_ShyGuy_Red_Anim0C, \
    .anim_8 = ANIM_ShyGuy_Red_Anim15, \
    .anim_9 = ANIM_ShyGuy_Red_Anim12, \
    .anim_A = ANIM_ShyGuy_Red_Anim11, \
    .anim_B = ANIM_ShyGuy_Red_Anim10, \
    .anim_C = ANIM_ShyGuy_Red_Anim05, \
    .anim_D = ANIM_ShyGuy_Red_Anim01, \
    .anim_E = ANIM_ShyGuy_Red_Anim01, \
    .anim_F = ANIM_ShyGuy_Red_Anim01, \
}
