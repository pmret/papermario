/// @file kzn_20.h
/// @brief Mt Lavalava - Rising Lava 1

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_20_shape.h"
#include "mapfs/kzn_20_hit.h"

#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/Kolorado.h"
#include "sprite/npc/WorldMisstar.h"

enum {
	NPC_Kolorado                = 0,
	NPC_Misstar                 = 1,
};

enum {
	MV_LavaPosOffset           	= MapVar(10),
	MV_WaveScaleOffset        	= MapVar(11),
	MV_PosScaleCoeff			= MapVar(12),
	MV_MisstarHintState			= MapVar(13),
};

#define NAMESPACE kzn_20
