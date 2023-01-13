#include "common.h"
#include "sprite/npc/TrainStationToad.h"

#define TRAIN_CONDUCTOR_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .heartDrops  = NO_DROPS, \
    .flowerDrops = NO_DROPS, \
}

#define TRAIN_CONDUCTOR_ANIMS \
{ \
    .idle   = ANIM_TrainStationToad_Idle, \
    .walk   = ANIM_TrainStationToad_Walk, \
    .run    = ANIM_TrainStationToad_Idle, \
    .chase  = ANIM_TrainStationToad_Idle, \
    .anim_4 = ANIM_TrainStationToad_Idle, \
    .anim_5 = ANIM_TrainStationToad_Idle, \
    .death  = ANIM_TrainStationToad_Idle, \
    .hit    = ANIM_TrainStationToad_Idle, \
    .anim_8 = ANIM_TrainStationToad_Idle, \
    .anim_9 = ANIM_TrainStationToad_Idle, \
    .anim_A = ANIM_TrainStationToad_Idle, \
    .anim_B = ANIM_TrainStationToad_Idle, \
    .anim_C = ANIM_TrainStationToad_Idle, \
    .anim_D = ANIM_TrainStationToad_Idle, \
    .anim_E = ANIM_TrainStationToad_Idle, \
    .anim_F = ANIM_TrainStationToad_Idle, \
}

// walk is different from the anims above -- maybe this NPC palette should have a distinct name
#define TRAIN_CONDUCTOR_WHITE_ANIMS \
{ \
    .idle   = ANIM_TrainStationToad_White_Idle, \
    .walk   = ANIM_TrainStationToad_White_Idle, \
    .run    = ANIM_TrainStationToad_White_Idle, \
    .chase  = ANIM_TrainStationToad_White_Idle, \
    .anim_4 = ANIM_TrainStationToad_White_Idle, \
    .anim_5 = ANIM_TrainStationToad_White_Idle, \
    .death  = ANIM_TrainStationToad_White_Idle, \
    .hit    = ANIM_TrainStationToad_White_Idle, \
    .anim_8 = ANIM_TrainStationToad_White_Idle, \
    .anim_9 = ANIM_TrainStationToad_White_Idle, \
    .anim_A = ANIM_TrainStationToad_White_Idle, \
    .anim_B = ANIM_TrainStationToad_White_Idle, \
    .anim_C = ANIM_TrainStationToad_White_Idle, \
    .anim_D = ANIM_TrainStationToad_White_Idle, \
    .anim_E = ANIM_TrainStationToad_White_Idle, \
    .anim_F = ANIM_TrainStationToad_White_Idle, \
}
