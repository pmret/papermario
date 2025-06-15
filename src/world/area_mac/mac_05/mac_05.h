/// @file mac_05.h
/// @brief Toad Town - Port District

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mac.h"
#include "mapfs/mac_05_shape.h"
#include "mapfs/mac_05_hit.h"

#include "sprite/npc/Kolorado.h"
#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/Fuzzipede.h"
#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/WorldKooper.h"
#include "sprite/npc/WorldBombette.h"
#include "sprite/npc/WorldBow.h"
#include "sprite/npc/WorldWatt.h"
#include "sprite/npc/JrTroopa.h"
#include "sprite/npc/Fishmael.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/Bartender.h"
#include "sprite/npc/Musician.h"
#include "sprite/npc/Chanterelle.h"

enum {
    NPC_Whale                   = 0,
    NPC_Kolorado                = 1,
    NPC_Fishmael                = 2,
    NPC_Fuzzipede               = 3,
    NPC_JrTroopa_01             = 4,
    NPC_JrTroopa_02             = 5,
    NPC_ChuckQuizmo             = 6,
    NPC_Bartender               = 7,
    NPC_WaiterToad              = 8,
    NPC_Chanterelle             = 9,
    NPC_ArtistToad              = 10,
    NPC_TradeEventToad          = 11,
    NPC_Toad_04                 = 12,
    NPC_Toad_05                 = 13,
    NPC_Toad_06                 = 14,
    NPC_Toad_07                 = 15,
};

enum {
    MF_Unk_01       = MapFlag(1),
    MF_DivaSinging  = MapFlag(10),
};

#define NAMESPACE mac_05

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_802496FC);
extern EvtScript N(EVS_80248878);
extern EvtScript N(EVS_SetupWhale);
extern EvtScript N(EVS_SetupRooms);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_AnimateClub64Sign);
extern EvtScript N(EVS_MakeEntities);

extern EvtScript N(EVS_80244298);
extern EvtScript N(EVS_802442C4);
extern EvtScript N(EVS_802442E8);
extern EvtScript N(EVS_80244314);
extern EvtScript N(EVS_80244340);

extern NpcGroupList N(NpcSetA);
extern NpcGroupList N(NpcSetB);
extern NpcGroupList N(NpcSetC);
