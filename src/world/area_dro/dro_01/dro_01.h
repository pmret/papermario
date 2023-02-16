#ifndef _DRO_01_H_
#define _DRO_01_H_

/// @file dro_01.h
/// @brief Dry Dry Outpost - Outpost 1

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dro.h"
#include "mapfs/dro_01_shape.h"
#include "mapfs/dro_01_hit.h"

#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/Mouser.h"
#include "sprite/npc/Dryite.h"
#include "sprite/npc/Musician.h"
#include "sprite/npc/Toadette.h"

enum {
    NPC_Mouser_01               = 0,
    NPC_Dryite_01               = 1,
    NPC_Dryite_02               = 2,
    NPC_Dryite_03               = 3,
    NPC_Dryite_04               = 4,
    NPC_ArtistToad              = 5,
    NPC_Mouser_ShopOwner        = 6,
    NPC_Toadette_01             = 7,
    NPC_Toadette_02             = 8,
    NPC_Toadette_03             = 9,
    NPC_ChuckQuizmo             = 10,
    NPC_Dryite_05               = 11,
    NPC_Dryite_06               = 12,
};

#define NAMESPACE dro_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
extern NpcGroupList N(Chapter3NPCs);

extern EvtScript N(EVS_SetupRooms);
extern EvtScript N(EVS_SwingSign_Shop);
extern EvtScript N(EVS_OpenShopDoor);
extern EvtScript N(EVS_CloseShopDoor);

extern ShopItemData N(Shop_Inventory)[];
extern ShopSellPriceData N(Shop_PriceList)[];
extern ShopItemLocation N(Shop_ItemPositions)[];
extern ShopOwner N(Shop_Owner);

extern EvtScript N(80244450);

extern EvtScript N(8024CDA0);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(main);
extern EvtScript N(makeEntities);
extern EvtScript N(unk_80248088);
extern EvtScript N(unk_8024884C);

#endif
