/// @file sam_08.h
/// @brief Mt Shiver - Shiver Mountain Hills

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../sam.h"
#include "mapfs/sam_08_shape.h"
#include "mapfs/sam_08_hit.h"

#include "sprite/npc/WorldClubba.h"
#include "sprite/npc/WorldKooper.h"
#include "sprite/npc/Duplighost.h"

enum {
    NPC_Kooper_01A      = 0,
    NPC_Kooper_02A      = 1,
    NPC_Duplighost      = 2,
    NPC_Kooper_01B      = 3,
    NPC_Kooper_02B      = 4,
    NPC_Clubba_01       = 5,
    NPC_Clubba_02       = 6,
};

enum {
    MV_KoopersFightingScript    = MapVar(0),
    MV_SuperBlock               = MapVar(1),
};

enum {
    MF_KooperDoneMoving         = MapFlag(0),
};

#define NAMESPACE sam_08

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupBridge);
extern EvtScript N(EVS_Scene_HitTrueKooper);
extern EvtScript N(EVS_Scene_HitFakeKooper);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
