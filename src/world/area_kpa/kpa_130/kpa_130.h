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
    NPC_BombshellBlaster_01     = 0,
    NPC_BombshellBlaster_02     = 1,
    NPC_BombshellBlaster_03     = 2,
    NPC_BombshellBlaster_04     = 3,
    NPC_BombshellBlaster_05     = 4,
    NPC_BombshellBlaster_06     = 5,
    NPC_BombshellBlaster_07     = 6,
    NPC_BombshellBlaster_08     = 7,
    NPC_BombshellBill_01        = 50,
    NPC_BombshellBill_02        = 51,
    NPC_BombshellBill_03        = 52,
    NPC_BombshellBill_04        = 53,
    NPC_BombshellBill_05        = 54,
    NPC_BombshellBill_06        = 55,
    NPC_BombshellBill_07        = 56,
    NPC_BombshellBill_08        = 57,
    NPC_BombshellBill_09        = 58,
    NPC_BombshellBill_10        = 59,
    NPC_BombshellBill_11        = 60,
    NPC_BombshellBill_12        = 61,
    NPC_BombshellBill_13        = 62,
    NPC_BombshellBill_14        = 63,
    NPC_BombshellBill_15        = 64,
    NPC_BombshellBill_16        = 65,
    NPC_BombshellBill_17        = 66,
    NPC_BombshellBill_18        = 67,
    NPC_BombshellBill_19        = 68,
    NPC_BombshellBill_20        = 69,
};

#define NAMESPACE kpa_130

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
