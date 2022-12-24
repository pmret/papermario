/// @file obk_08.h
/// @brief Boo's Mansion - Record Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../obk.h"
#include "mapfs/obk_08_shape.h"
#include "mapfs/obk_08_hit.h"

#include "sprite/npc/Boo.h"

enum {
    NPC_Boo_01              = 0,
    NPC_KeepAwayBoo1        = 1,
    NPC_KeepAwayBoo2        = 2,
    NPC_KeepAwayBoo3        = 3,
    NPC_KeepAwayBoo4        = 4,
    NPC_KeepAwayBoo5        = 5,
    NPC_KeepAwayBoo6        = 6,
    NPC_KeepAwayBoo7        = 7,
    NPC_KeepAwayBoo8        = 8,
    NPC_TrafficBoo1         = 9,
    NPC_TrafficBoo2         = 10,
    NPC_LeaderBoo           = 11,
    NPC_DummyBoo            = 12,
};

enum {
    MV_KeepAwayItem         = MapVar(0),
    MV_Unk_01               = MapVar(1),
    MV_Unk_02               = MapVar(2),
    MV_ThrowTargetNpc       = MapVar(3),
    MV_KeepAwayResult       = MapVar(4),
    MV_Unk_Angle            = MapVar(5),
    MV_ItemCarrierNpc       = MapVar(6),
    MV_KnockdownPosX        = MapVar(7),
    MV_KnockdownPosY        = MapVar(8),
    MV_KnockdownPosZ        = MapVar(9),
    MV_Knockdown            = MapVar(10),
    MV_WindowsIdle          = MapVar(11),
    MV_Trigger_NearCabinet  = MapVar(12),
    MV_Trigger_MidCabinet   = MapVar(13),
    MV_Trigger_FarCabinet   = MapVar(14),
};

enum KeepAwayResult {
    KEEP_AWAY_WAITING   = 0,
    KEEP_AWAY_RIGHT     = 1,
    KEEP_AWAY_WRONG     = 2,
};

#define NAMESPACE obk_08

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_ManageWindows);
extern EvtScript N(EVS_SetupCabinets);
extern EvtScript N(EVS_BindCabinetTriggers);
extern EvtScript N(EVS_Scene_BoosUnleashed);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
