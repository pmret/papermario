#include "common.h"
#include "sprite/npc/Goompa.h"
#include "sprite/npc/Gooma.h"
#include "sprite/npc/Goompapa.h"
#include "sprite/npc/Goomama.h"
#include "sprite/npc/Goombaria.h"

#define GOOMPA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .heartDrops  = NO_DROPS, \
    .flowerDrops = NO_DROPS, \
}

#define GOOMPA_ANIMS \
{ \
    ANIM_Dryite_Green_Idle, \
    ANIM_Dryite_Green_Walk, \
    ANIM_Dryite_Green_Run, \
    ANIM_Dryite_Green_Run, \
    ANIM_Dryite_Green_Idle, \
    ANIM_Dryite_Green_Idle, \
    ANIM_Dryite_Green_Still, \
    ANIM_Dryite_Green_Still, \
    ANIM_Dryite_Green_Idle, \
    ANIM_Dryite_Green_Idle, \
    ANIM_Dryite_Green_Idle, \
    ANIM_Dryite_Green_Idle, \
    ANIM_Dryite_Green_Idle, \
    ANIM_Dryite_Green_Idle, \
    ANIM_Dryite_Green_Idle, \
    ANIM_Dryite_Green_Idle, \
}

#define GOOMAMA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .heartDrops  = NO_DROPS, \
    .flowerDrops = NO_DROPS, \
}

#define GOOMAMA_ANIMS \
{ \
    .idle   = ANIM_Goomama_Idle, \
    .walk   = ANIM_Goomama_Walk, \
    .run    = ANIM_Goomama_Run, \
    .chase  = ANIM_Goomama_Run, \
    .anim_4 = ANIM_Goomama_Idle, \
    .anim_5 = ANIM_Goomama_Idle, \
    .death  = ANIM_Goomama_Still, \
    .hit    = ANIM_Goomama_Still, \
    .anim_8 = ANIM_Goomama_Run, \
    .anim_9 = ANIM_Goomama_Run, \
    .anim_A = ANIM_Goomama_Run, \
    .anim_B = ANIM_Goomama_Run, \
    .anim_C = ANIM_Goomama_Run, \
    .anim_D = ANIM_Goomama_Run, \
    .anim_E = ANIM_Goomama_Run, \
    .anim_F = ANIM_Goomama_Run, \
}

#define GOOMBARIA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .heartDrops  = NO_DROPS, \
    .flowerDrops = NO_DROPS, \
}

#define GOOMBARIA_ANIMS \
{ \
    .idle   = ANIM_Goombaria_Idle, \
    .walk   = ANIM_Goombaria_Walk, \
    .run    = ANIM_Goombaria_Run, \
    .chase  = ANIM_Goombaria_Run, \
    .anim_4 = ANIM_Goombaria_Idle, \
    .anim_5 = ANIM_Goombaria_Idle, \
    .death  = ANIM_Goombaria_Still, \
    .hit    = ANIM_Goombaria_Still, \
    .anim_8 = ANIM_Goombaria_Run, \
    .anim_9 = ANIM_Goombaria_Run, \
    .anim_A = ANIM_Goombaria_Run, \
    .anim_B = ANIM_Goombaria_Run, \
    .anim_C = ANIM_Goombaria_Run, \
    .anim_D = ANIM_Goombaria_Run, \
    .anim_E = ANIM_Goombaria_Run, \
    .anim_F = ANIM_Goombaria_Run, \
}
