/// @file hos_06.h
/// @brief Shooting Star Summit - Merluvlee's House

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../hos.h"
#include "mapfs/hos_06_shape.h"
#include "mapfs/hos_06_hit.h"

#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/Merlow.h"
#include "sprite/npc/Merluvlee.h"

enum {
	NPC_Merluvlee   = 0,
	NPC_Merlow      = 1,
};

enum {
	MV_Unk_0A		= MapVar(10),
};

enum {
    MF_Unk_00       = MapFlag(0),
};

#define NAMESPACE hos_06

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMagicChest);
extern EvtScript N(EVS_Interact_MagicChest);
extern EvtScript N(EVS_802444B8);
extern EvtScript N(EVS_80245878_Merluvlee);

extern EvtScript N(EVS_NpcInteract_Merluvlee);
extern EvtScript N(EVS_NpcInit_Merluvlee);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
