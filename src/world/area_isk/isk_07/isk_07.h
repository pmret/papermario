/// @file isk_07.h
/// @brief Dry Dry Ruins - Sarcophagus Hall 2

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../isk.h"
#include "mapfs/isk_07_shape.h"
#include "mapfs/isk_07_hit.h"

#include "sprite/npc/Pokey.h"

enum {
    NPC_Pokey_01                = 0,
    NPC_Pokey_02                = 1,
    NPC_Pokey_03                = 2,
};

enum {
    MV_LockEntityID         = MapVar(0),
};

enum {
    MF_StairsFlipped        = MapFlag(0),
};

#define NAMESPACE isk_07

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupLock);
extern EvtScript N(EVS_SetupStairs);
extern EvtScript N(EVS_SetupSwitch);
extern EvtScript N(EVS_SetupSarcophagi);
extern EvtScript N(EVS_OpenEntryDoor);
extern EvtScript N(EVS_ShutEntryDoor);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
