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

#define GOOMA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .heartDrops  = NO_DROPS, \
    .flowerDrops = NO_DROPS, \
}

#define GOOMA_ANIMS \
{ \
    .idle   = ANIM_Gooma_Idle, \
    .walk   = ANIM_Gooma_Walk, \
    .run    = ANIM_Gooma_Run, \
    .chase  = ANIM_Gooma_Run, \
    .anim_4 = ANIM_Gooma_Idle, \
    .anim_5 = ANIM_Gooma_Idle, \
    .death  = ANIM_Gooma_Still, \
    .hit    = ANIM_Gooma_Still, \
    .anim_8 = ANIM_Gooma_Run, \
    .anim_9 = ANIM_Gooma_Run, \
    .anim_A = ANIM_Gooma_Run, \
    .anim_B = ANIM_Gooma_Run, \
    .anim_C = ANIM_Gooma_Run, \
    .anim_D = ANIM_Gooma_Run, \
    .anim_E = ANIM_Gooma_Run, \
    .anim_F = ANIM_Gooma_Run, \
}

#define GOOMPAPA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .heartDrops  = NO_DROPS, \
    .flowerDrops = NO_DROPS, \
}

#define GOOMPAPA_ANIMS \
{ \
    .idle   = ANIM_Goompapa_Idle, \
    .walk   = ANIM_Goompapa_Walk, \
    .run    = ANIM_Goompapa_Run, \
    .chase  = ANIM_Goompapa_Run, \
    .anim_4 = ANIM_Goompapa_Idle, \
    .anim_5 = ANIM_Goompapa_Idle, \
    .death  = ANIM_Goompapa_Still, \
    .hit    = ANIM_Goompapa_Still, \
    .anim_8 = ANIM_Goompapa_Run, \
    .anim_9 = ANIM_Goompapa_Run, \
    .anim_A = ANIM_Goompapa_Run, \
    .anim_B = ANIM_Goompapa_Run, \
    .anim_C = ANIM_Goompapa_Run, \
    .anim_D = ANIM_Goompapa_Run, \
    .anim_E = ANIM_Goompapa_Run, \
    .anim_F = ANIM_Goompapa_Run, \
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
