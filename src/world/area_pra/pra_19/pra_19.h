/// @file pra_19.h
/// @brief Crystal Palace - Reflection Mimic Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../pra.h"
#include "mapfs/pra_19_shape.h"
#include "mapfs/pra_19_hit.h"

#include "sprite/npc/Duplighost.h"
#include "sprite/npc/WorldKooper.h"
#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/Kolorado.h"
#include "sprite/npc/Goompa.h"
#include "sprite/npc/KoopaKoot.h"
#include "sprite/npc/Luigi.h"

enum {
    // passive NPC for each imposter than can be interacted with
    NPC_FakeKooper              = 0,
    NPC_FakeGoompa              = 1,
    NPC_FakeLuigi               = 2,
    NPC_FakeKoopaKoot           = 3,
    NPC_FakeKolorado            = 4,
    // mario and partner in the mirror showing what to do
    NPC_ExamplePlayer           = 5,
    NPC_ExampleKooper           = 6,
    // duplighosts for each imposter
    NPC_GoompaGhost             = 7,
    NPC_LuigiGhost              = 8,
    NPC_KoopaKootGhost          = 9,
    NPC_KoloradoGhost           = 10,
    NPC_Duplighost_Controller   = 11, // controls the scene
    // second set of NPCs for each imposter which detect hammer hits
    NPC_TargetKooper            = 12,
    NPC_TargetGoompa            = 13,
    NPC_TargetLuigi             = 14,
    NPC_TargetKoopaKoot         = 15,
    NPC_TargetKolorado          = 16,
};

enum {
    MV_UnmaskingState           = MapVar(0),
    MV_RevealedFakeGoompa       = MapVar(2),
    MV_RevealedFakeLuigi        = MapVar(3),
    MV_RevealedFakeKoopaKoot    = MapVar(4),
    MV_RevealedFakeKolorado     = MapVar(5),
};

#define NAMESPACE pra_19

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_ExitWalk_pra_20_0);
extern NpcGroupList N(DefaultNPCs);
