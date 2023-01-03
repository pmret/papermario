/// @file kpa_130.h
/// @brief Bowser's Castle - Bill Blaster Hall

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_130_shape.h"
#include "mapfs/kpa_130_hit.h"

#include "sprite/npc/BillBlaster.h"
#include "sprite/npc/BulletBill.h"

enum {
    NPC_BillBlaster_01          = 0,
    NPC_BillBlaster_02          = 1,
    NPC_BillBlaster_03          = 2,
    NPC_BillBlaster_04          = 3,
    NPC_BillBlaster_05          = 4,
    NPC_BillBlaster_06          = 5,
    NPC_BillBlaster_07          = 6,
    NPC_BillBlaster_08          = 7,
    NPC_BulletBill_01           = 50,
    NPC_BulletBill_02           = 51,
    NPC_BulletBill_03           = 52,
    NPC_BulletBill_04           = 53,
    NPC_BulletBill_05           = 54,
    NPC_BulletBill_06           = 55,
    NPC_BulletBill_07           = 56,
    NPC_BulletBill_08           = 57,
    NPC_BulletBill_09           = 58,
    NPC_BulletBill_10           = 59,
    NPC_BulletBill_11           = 60,
    NPC_BulletBill_12           = 61,
    NPC_BulletBill_13           = 62,
    NPC_BulletBill_14           = 63,
    NPC_BulletBill_15           = 64,
    NPC_BulletBill_16           = 65,
    NPC_BulletBill_17           = 66,
    NPC_BulletBill_18           = 67,
    NPC_BulletBill_19           = 68,
    NPC_BulletBill_20           = 69,
};

#define NAMESPACE kpa_130

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
