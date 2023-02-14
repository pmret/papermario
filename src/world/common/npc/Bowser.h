#include "common.h"
#include "sprite/npc/WorldBowser.h"

#define BOWSER_ANIMS \
{ \
    .idle   = ANIM_WorldBowser_Idle, \
    .walk   = ANIM_WorldBowser_Idle, \
    .run    = ANIM_WorldBowser_Idle, \
    .chase  = ANIM_WorldBowser_Idle, \
    .anim_4 = ANIM_WorldBowser_Idle, \
    .anim_5 = ANIM_WorldBowser_Idle, \
    .death  = ANIM_WorldBowser_Idle, \
    .hit    = ANIM_WorldBowser_Idle, \
    .anim_8 = ANIM_WorldBowser_Idle, \
    .anim_9 = ANIM_WorldBowser_Idle, \
    .anim_A = ANIM_WorldBowser_Idle, \
    .anim_B = ANIM_WorldBowser_Idle, \
    .anim_C = ANIM_WorldBowser_Idle, \
    .anim_D = ANIM_WorldBowser_Idle, \
    .anim_E = ANIM_WorldBowser_Idle, \
    .anim_F = ANIM_WorldBowser_Idle, \
}
