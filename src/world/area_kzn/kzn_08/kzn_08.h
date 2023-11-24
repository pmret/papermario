/// @file kzn_08.h
/// @brief Mt Lavalava - Dizzy Stomp Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_08_shape.h"
#include "mapfs/kzn_08_hit.h"

enum {
    NPC_PutridPiranha       = 0,
    NPC_Piranha_Hitbox      = 1
};

enum {
    MV_GlowIntensity        = MapVar(0),
};

#define NAMESPACE kzn_08

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(DefaultNPCs);
extern EvtScript N(EVS_802455A0);
extern API_CALLABLE(N(ApplyLavaGlowLighting));
extern API_CALLABLE(N(ClearLavaGlowLighting));

void disable_world_fog(void);
void mdl_get_depth_tint_params(u8*, u8*, u8*, u8*, u8*, u8*, u8*, s32*, s32*);
