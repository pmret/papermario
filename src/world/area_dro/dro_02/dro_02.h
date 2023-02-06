#ifndef _DRO_02_H_
#define _DRO_02_H_

/// @file dro_02.h
/// @brief Dry Dry Outpost - Outpost 2

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dro.h"
#include "mapfs/dro_02_shape.h"
#include "mapfs/dro_02_hit.h"

#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/WorldMerlee.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/Archeologist.h"
#include "sprite/npc/Dryite.h"

enum {
    NPC_Archeologist            = 0,
    NPC_Dryite_01               = 1,
    NPC_DisguisedMoustafa       = 2,
    NPC_Toad                    = 3,
    NPC_Merlee                  = 4,
    NPC_Moustafa                = 5,
    NPC_Dryite_02               = 6,
    NPC_Mouser_01               = 7,
    NPC_Mouser_02               = 8,
    NPC_Mouser_03               = 9,
    NPC_ChuckQuizmo             = 10,
    NPC_Dryite_03               = 11,
};

enum {
    MF_Unk_00           = MapFlag(0),
};

#define NAMESPACE dro_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PlayRestMusic);
extern EvtScript N(EVS_PlayMoustafaMusic);

extern EvtScript N(EVS_SetupRooms);
extern EvtScript N(8024D434);

#endif
