#include "common.h"
#include "sprite/npc/Sentinel.h"

#define SENTINEL_ANIMS \
{ \
    .idle   = ANIM_Sentinel_Idle, \
    .walk   = ANIM_Sentinel_FlySlow, \
    .run    = ANIM_Sentinel_FlyFast, \
    .chase  = ANIM_Sentinel_FlyFast, \
    .anim_4 = ANIM_Sentinel_Idle, \
    .anim_5 = ANIM_Sentinel_Idle, \
    .death  = ANIM_Sentinel_Idle, \
    .hit    = ANIM_Sentinel_Idle, \
    .anim_8 = ANIM_Sentinel_Alert, \
    .anim_9 = ANIM_Sentinel_Idle, \
    .anim_A = ANIM_Sentinel_Grab, \
    .anim_B = ANIM_Sentinel_Idle, \
    .anim_C = ANIM_Sentinel_Idle, \
    .anim_D = ANIM_Sentinel_Idle, \
    .anim_E = ANIM_Sentinel_Idle, \
    .anim_F = ANIM_Sentinel_Idle, \
}
