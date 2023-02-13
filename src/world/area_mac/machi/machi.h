/// @file machi.h
/// @brief Debug Warp Zone - Debug Warp Zone

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mac.h"
#include "mapfs/machi_shape.h"
#include "mapfs/machi_hit.h"

#include "sprite/npc/StarRod.h"
#include "sprite/npc/Koopa.h"
#include "sprite/npc/Kolorado.h"
#include "sprite/npc/Goompa.h"
#include "sprite/npc/Goombaria.h"
#include "sprite/npc/GoombaKing.h"
#include "sprite/npc/WorldMisstar.h"

enum {
    NPC_05          = 5,
    NPC_06          = 6,
    NPC_07          = 7,
    NPC_Goompa      = 10,
    NPC_0B          = 11,
    NPC_0C          = 12,
    NPC_0D          = 13,
    NPC_0E          = 14,
    NPC_0F          = 15,
    NPC_10          = 16,
    NPC_11          = 17,
    NPC_12          = 18,
    NPC_13          = 19,
    NPC_GoombaKing  = 40,
    NPC_Misstar     = 55,
};

#define NAMESPACE machi

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_GoombaKing_Init);
extern EvtScript N(EVS_FlyPartnerAround);
extern EvtScript N(EVS_MakeEntities);

extern NpcSettings N(NpcSettings_GoombaKing);
extern NpcData N(NpcData_Misstar);
extern NpcGroupList N(DefaultNPCs);

typedef struct GameVarRange {
    /* 00 */ char* name;
    /* 04 */ s32 first;
    /* 08 */ s32 count;
    /* 0C */ s32 next;
} GameVarRange; // size = 0x10

extern GameVarRange N(GameByteTable)[];
extern GameVarRange N(GameFlagTable)[];
