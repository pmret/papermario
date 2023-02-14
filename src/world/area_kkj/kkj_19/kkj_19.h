/// @file kkj_19.h
/// @brief Peach's Castle - Kitchen (1F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kkj.h"
#include "mapfs/kkj_19_shape.h"
#include "mapfs/kkj_19_hit.h"

#include "sprite/npc/TayceT.h"
#include "sprite/npc/Twink.h"

enum {
    // intro
    NPC_TayceT      = 0,
    NPC_Toad        = 1,
    // peach
    NPC_Twink       = 0, // normally, you cant interact with your partner, so a dummy npc is created to allow it
};

#define NAMESPACE kkj_19

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_ManageBaking);

extern NpcGroupList N(IntroNPCs);
extern NpcGroupList N(PeachNPCs);

extern unsigned char ui_box_corners5_png[];
