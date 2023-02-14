/// @file arn_07.h
/// @brief Gusty Gulch - Windmill Exterior

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../arn.h"
#include "mapfs/arn_07_shape.h"
#include "mapfs/arn_07_hit.h"

#include "sprite/npc/TubbasHeart.h"
#include "sprite/npc/WorldTubba.h"
#include "sprite/npc/WorldBow.h"
#include "sprite/npc/Boo.h"
#include "sprite/npc/Bootler.h"

enum {
    NPC_TubbasHeart         = 0,
    NPC_Tubba               = 1,
    NPC_Boo_01              = 2,
    NPC_Boo_02              = 3,
    NPC_Boo_03              = 4,
    NPC_Boo_04              = 5,
    NPC_Boo_05              = 6,
    NPC_Boo_06              = 7,
    NPC_Bow                 = 8,
    NPC_Bootler             = 9,
    NPC_HyperParagoomba_01  = 10,
    NPC_HyperParagoomba_02  = 11,
    NPC_HyperParagoomba_03  = 12,
    NPC_Skolar              = 13,
};

enum {
    MV_Unk_00               = MapVar(0),
    MV_Unk_01               = MapVar(1),
};

#define NAMESPACE arn_07

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_UnlockDoor);
extern EvtScript N(EVS_SetupWindmill);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript(N(EVS_SpawnStarCard));
extern EvtScript(N(EVS_ExitDoor_arn_08_0));

extern NpcGroupList N(DefaultNPCs);
extern NpcGroupList N(BossNPCs);
extern NpcGroupList N(SpiritNPCs);
