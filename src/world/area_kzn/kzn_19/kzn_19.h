/// @file kzn_19.h
/// @brief Mt Lavalava - Boss Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_19_shape.h"
#include "mapfs/kzn_19_hit.h"

#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/Kolorado.h"
#include "sprite/npc/WorldMisstar.h"
#include "sprite/npc/LavaPiranha.h"
#include "sprite/npc/LavaBud.h"

enum {
	NPC_Kolorado                = 0,
	NPC_Misstar                 = 1,
	NPC_LavaPiranhaHead         = 2,
	NPC_LavaBud_01              = 3,
	NPC_LavaBud_02              = 4,
	NPC_05                      = 5,
};

enum {
	MV_Unk_00					= MapVar(0),
	MV_Unk_0A					= MapVar(10),
};

#define NAMESPACE kzn_19
