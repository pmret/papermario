/// @file nok_04.h
/// @brief Koopa Region - Fuzzy Forest

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../nok.h"
#include "mapfs/nok_04_shape.h"
#include "mapfs/nok_04_hit.h"

#include "sprite/npc/Fuzzy.h"
#include "sprite/npc/KooperWithoutShell.h"
#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/WorldKooper.h"

enum {
	NPC_Fuzzy_01                = 0,
	NPC_Kooper_01               = 1,
	NPC_Fuzzy_02                = 2,
	NPC_Fuzzy_03                = 3,
	NPC_Fuzzy_04                = 4,
	NPC_Fuzzy_05                = 5,
	NPC_Kooper_02               = 6,
};

enum {
	MV_Unk_00		= MapVar(0),
	MV_Unk_01		= MapVar(1),
	MV_Unk_02		= MapVar(2),
	MV_Unk_03		= MapVar(3),
	MV_Unk_04		= MapVar(4),
};

#define NAMESPACE nok_04

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PushPartnerSong);
extern EvtScript N(EVS_PopSong);
extern EvtScript N(EVS_80245BD8);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(DefaultNPCs);

API_CALLABLE(N(LoadPartyImage));
