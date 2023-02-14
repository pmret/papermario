#include "common.h"
#include "sprite/npc/WorldEldstar.h"
#include "sprite/npc/WorldMamar.h"
#include "sprite/npc/WorldSkolar.h"
#include "sprite/npc/WorldMuskular.h"
#include "sprite/npc/WorldMisstar.h"
#include "sprite/npc/WorldKlevar.h"
#include "sprite/npc/WorldKalmar.h"
#include "sprite/npc/StarMan.h"
#include "sprite/npc/Twink.h"

#define ELDSTAR_ANIMS \
{ \
    .idle   = ANIM_WorldEldstar_Idle, \
    .walk   = ANIM_WorldEldstar_Idle, \
    .run    = ANIM_WorldEldstar_Idle, \
    .chase  = ANIM_WorldEldstar_Idle, \
    .anim_4 = ANIM_WorldEldstar_Idle, \
    .anim_5 = ANIM_WorldEldstar_Idle, \
    .death  = ANIM_WorldEldstar_Idle, \
    .hit    = ANIM_WorldEldstar_Idle, \
    .anim_8 = ANIM_WorldEldstar_Still, \
    .anim_9 = ANIM_WorldEldstar_Idle, \
    .anim_A = ANIM_WorldEldstar_Idle, \
    .anim_B = ANIM_WorldEldstar_Idle, \
    .anim_C = ANIM_WorldEldstar_Idle, \
    .anim_D = ANIM_WorldEldstar_Idle, \
    .anim_E = ANIM_WorldEldstar_Idle, \
    .anim_F = ANIM_WorldEldstar_Idle, \
}

#define MAMAR_ANIMS \
{ \
    .idle   = ANIM_WorldMamar_Idle, \
    .walk   = ANIM_WorldMamar_Idle, \
    .run    = ANIM_WorldMamar_Idle, \
    .chase  = ANIM_WorldMamar_Idle, \
    .anim_4 = ANIM_WorldMamar_Idle, \
    .anim_5 = ANIM_WorldMamar_Idle, \
    .death  = ANIM_WorldMamar_Idle, \
    .hit    = ANIM_WorldMamar_Idle, \
    .anim_8 = ANIM_WorldMamar_Still, \
    .anim_9 = ANIM_WorldMamar_Idle, \
    .anim_A = ANIM_WorldMamar_Idle, \
    .anim_B = ANIM_WorldMamar_Idle, \
    .anim_C = ANIM_WorldMamar_Idle, \
    .anim_D = ANIM_WorldMamar_Idle, \
    .anim_E = ANIM_WorldMamar_Idle, \
    .anim_F = ANIM_WorldMamar_Idle, \
}

#define SKOLAR_ANIMS \
{ \
    .idle   = ANIM_WorldSkolar_Idle, \
    .walk   = ANIM_WorldSkolar_Idle, \
    .run    = ANIM_WorldSkolar_Idle, \
    .chase  = ANIM_WorldSkolar_Idle, \
    .anim_4 = ANIM_WorldSkolar_Idle, \
    .anim_5 = ANIM_WorldSkolar_Idle, \
    .death  = ANIM_WorldSkolar_Idle, \
    .hit    = ANIM_WorldSkolar_Idle, \
    .anim_8 = ANIM_WorldSkolar_Still, \
    .anim_9 = ANIM_WorldSkolar_Idle, \
    .anim_A = ANIM_WorldSkolar_Idle, \
    .anim_B = ANIM_WorldSkolar_Idle, \
    .anim_C = ANIM_WorldSkolar_Idle, \
    .anim_D = ANIM_WorldSkolar_Idle, \
    .anim_E = ANIM_WorldSkolar_Idle, \
    .anim_F = ANIM_WorldSkolar_Idle, \
}

#define MUSKULAR_ANIMS \
{ \
    .idle   = ANIM_WorldMuskular_Idle, \
    .walk   = ANIM_WorldMuskular_Idle, \
    .run    = ANIM_WorldMuskular_Idle, \
    .chase  = ANIM_WorldMuskular_Idle, \
    .anim_4 = ANIM_WorldMuskular_Idle, \
    .anim_5 = ANIM_WorldMuskular_Idle, \
    .death  = ANIM_WorldMuskular_Idle, \
    .hit    = ANIM_WorldMuskular_Idle, \
    .anim_8 = ANIM_WorldMuskular_Still, \
    .anim_9 = ANIM_WorldMuskular_Idle, \
    .anim_A = ANIM_WorldMuskular_Idle, \
    .anim_B = ANIM_WorldMuskular_Idle, \
    .anim_C = ANIM_WorldMuskular_Idle, \
    .anim_D = ANIM_WorldMuskular_Idle, \
    .anim_E = ANIM_WorldMuskular_Idle, \
    .anim_F = ANIM_WorldMuskular_Idle, \
}

#define MISSTAR_ANIMS \
{ \
    .idle   = ANIM_WorldMisstar_Idle, \
    .walk   = ANIM_WorldMisstar_Idle, \
    .run    = ANIM_WorldMisstar_Idle, \
    .chase  = ANIM_WorldMisstar_Idle, \
    .anim_4 = ANIM_WorldMisstar_Idle, \
    .anim_5 = ANIM_WorldMisstar_Idle, \
    .death  = ANIM_WorldMisstar_Idle, \
    .hit    = ANIM_WorldMisstar_Idle, \
    .anim_8 = ANIM_WorldMisstar_Still, \
    .anim_9 = ANIM_WorldMisstar_Idle, \
    .anim_A = ANIM_WorldMisstar_Idle, \
    .anim_B = ANIM_WorldMisstar_Idle, \
    .anim_C = ANIM_WorldMisstar_Idle, \
    .anim_D = ANIM_WorldMisstar_Idle, \
    .anim_E = ANIM_WorldMisstar_Idle, \
    .anim_F = ANIM_WorldMisstar_Idle, \
}

#define KLEVAR_ANIMS \
{ \
    .idle   = ANIM_WorldKlevar_Idle, \
    .walk   = ANIM_WorldKlevar_Idle, \
    .run    = ANIM_WorldKlevar_Idle, \
    .chase  = ANIM_WorldKlevar_Idle, \
    .anim_4 = ANIM_WorldKlevar_Idle, \
    .anim_5 = ANIM_WorldKlevar_Idle, \
    .death  = ANIM_WorldKlevar_Idle, \
    .hit    = ANIM_WorldKlevar_Idle, \
    .anim_8 = ANIM_WorldKlevar_Still, \
    .anim_9 = ANIM_WorldKlevar_Idle, \
    .anim_A = ANIM_WorldKlevar_Idle, \
    .anim_B = ANIM_WorldKlevar_Idle, \
    .anim_C = ANIM_WorldKlevar_Idle, \
    .anim_D = ANIM_WorldKlevar_Idle, \
    .anim_E = ANIM_WorldKlevar_Idle, \
    .anim_F = ANIM_WorldKlevar_Idle, \
}

#define KALMAR_ANIMS \
{ \
    .idle   = ANIM_WorldKalmar_Idle, \
    .walk   = ANIM_WorldKalmar_Idle, \
    .run    = ANIM_WorldKalmar_Idle, \
    .chase  = ANIM_WorldKalmar_Idle, \
    .anim_4 = ANIM_WorldKalmar_Idle, \
    .anim_5 = ANIM_WorldKalmar_Idle, \
    .death  = ANIM_WorldKalmar_Idle, \
    .hit    = ANIM_WorldKalmar_Idle, \
    .anim_8 = ANIM_WorldKalmar_Still, \
    .anim_9 = ANIM_WorldKalmar_Idle, \
    .anim_A = ANIM_WorldKalmar_Idle, \
    .anim_B = ANIM_WorldKalmar_Idle, \
    .anim_C = ANIM_WorldKalmar_Idle, \
    .anim_D = ANIM_WorldKalmar_Idle, \
    .anim_E = ANIM_WorldKalmar_Idle, \
    .anim_F = ANIM_WorldKalmar_Idle, \
}

#define STAR_MAN_ANIMS \
{ \
    .idle   = ANIM_StarMan_Idle, \
    .walk   = ANIM_StarMan_Idle, \
    .run    = ANIM_StarMan_Idle, \
    .chase  = ANIM_StarMan_Idle, \
    .anim_4 = ANIM_StarMan_Idle, \
    .anim_5 = ANIM_StarMan_Idle, \
    .death  = ANIM_StarMan_Idle, \
    .hit    = ANIM_StarMan_Idle, \
    .anim_8 = ANIM_StarMan_Idle, \
    .anim_9 = ANIM_StarMan_Idle, \
    .anim_A = ANIM_StarMan_Idle, \
    .anim_B = ANIM_StarMan_Idle, \
    .anim_C = ANIM_StarMan_Idle, \
    .anim_D = ANIM_StarMan_Idle, \
    .anim_E = ANIM_StarMan_Idle, \
    .anim_F = ANIM_StarMan_Idle, \
}

#define STAR_KID_ANIMS \
{ \
    .idle   = ANIM_Twink_Idle, \
    .walk   = ANIM_Twink_Fly, \
    .run    = ANIM_Twink_Angry, \
    .chase  = ANIM_Twink_Angry, \
    .anim_4 = ANIM_Twink_Idle, \
    .anim_5 = ANIM_Twink_Idle, \
    .death  = ANIM_Twink_Idle, \
    .hit    = ANIM_Twink_Idle, \
    .anim_8 = ANIM_Twink_Idle, \
    .anim_9 = ANIM_Twink_Idle, \
    .anim_A = ANIM_Twink_Idle, \
    .anim_B = ANIM_Twink_Idle, \
    .anim_C = ANIM_Twink_Idle, \
    .anim_D = ANIM_Twink_Idle, \
    .anim_E = ANIM_Twink_Idle, \
    .anim_F = ANIM_Twink_Idle, \
}
