/// @file obk_09.h
/// @brief Boo's Mansion - Lady Bow's Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../obk.h"
#include "mapfs/obk_09_shape.h"
#include "mapfs/obk_09_hit.h"

#include "sprite/npc/WorldBow.h"
#include "sprite/npc/Bootler.h"
#include "sprite/npc/WorldSkolar.h"

enum {
    NPC_Bow                     = 0,
    NPC_Bootler                 = 1,
    NPC_Skolar                  = 2,
};

#define NAMESPACE obk_09

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PlayNewPartnerSong);
extern EvtScript N(EVS_ResetMusic);
extern EvtScript N(EVS_Scene_Epilogue);
extern EvtScript N(EVS_Scene_MeetBow);
extern NpcGroupList N(DefaultNPCs);
extern NpcGroupList N(EpilogueNPCs);

API_CALLABLE(N(LoadPartyImage));

//TODO awkward
extern const char NEXT_EPILOGUE_MAP[];
