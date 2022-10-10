#include "common.h"
#include "sprite/npc/Bzzap.h"

#define BZZAP_NO_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .heartDrops  = NO_DROPS, \
    .flowerDrops = NO_DROPS, \
}

#define BZZAP_ANIMS \
{ \
    .idle   = ANIM_Bzzap_Anim02, \
    .walk   = ANIM_Bzzap_Anim02, \
    .run    = ANIM_Bzzap_Anim03, \
    .chase  = ANIM_Bzzap_Anim03, \
    .anim_4 = ANIM_Bzzap_Anim01, \
    .anim_5 = ANIM_Bzzap_Anim02, \
    .death  = ANIM_Bzzap_Anim06, \
    .hit    = ANIM_Bzzap_Anim06, \
    .anim_8 = ANIM_Bzzap_Anim04, \
    .anim_9 = ANIM_Bzzap_Anim02, \
    .anim_A = ANIM_Bzzap_Anim01, \
    .anim_B = ANIM_Bzzap_Anim01, \
    .anim_C = ANIM_Bzzap_Anim01, \
    .anim_D = ANIM_Bzzap_Anim01, \
    .anim_E = ANIM_Bzzap_Anim01, \
    .anim_F = ANIM_Bzzap_Anim01, \
}
