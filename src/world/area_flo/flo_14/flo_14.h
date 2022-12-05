/// @file flo_14.h
/// @brief Flower Fields - (NW) Bubble Flower

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_14_shape.h"
#include "mapfs/flo_14_hit.h"

#include "sprite/npc/Bubulb.h"
#include "sprite/npc/Bzzap.h"

enum {
    NPC_BubbleFlower    = 0,
    NPC_Bzzap           = 1,
};

enum {
    MV_SavedPartnerFlags    = MapVar(0),
    MV_BubbleCamScript      = MapVar(9),
    MV_RotAngle_Log_01      = MapVar(10),
    MV_RotVelocity_Log_01   = MapVar(11),
    MV_RotAngle_Log_02      = MapVar(12),
    MV_RotVelocity_Log_02   = MapVar(13),
};

#define NAMESPACE flo_14

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupBubbles);
extern EvtScript N(EVS_SetupLogBridges);
extern EvtScript N(EVS_MakeEntities);

extern EvtScript N(EVS_BlowBigBubble);
extern EvtScript N(EVS_RideBigBubble);

extern NpcGroupList N(DefaultNPCs);
