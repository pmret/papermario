/// @file omo_09.h
/// @brief Shy Guy's Toybox - GRN Treadmills/Slot Machine

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../omo.h"
#include "mapfs/omo_09_shape.h"
#include "mapfs/omo_09_hit.h"

#include "sprite/npc/WorldKammy.h"

enum {
    NPC_ShyGuy_Jackpot1     = 0,
    NPC_ShyGuy_Jackpot2     = 1,
    NPC_ShyGuy_Jackpot3     = 2,
    NPC_ShyGuy_Jackpot4     = 3,
    NPC_ShyGuy_Jackpot5     = 4,
    NPC_Pokey               = 5,
    NPC_Koopatrol           = 6,
    NPC_Kammy               = 7,
    NPC_ShyGuy_Thief        = 8,
    NPC_SpyGuy              = 20,
    NPC_SpyGuy_Rock1        = 21,
    NPC_SpyGuy_Rock2        = 22,
    NPC_SpyGuy_Rock3        = 23,
};

enum {
    MV_SlotWheel1_Angle     = MapVar(0),
    MV_SlotWheel2_Angle     = MapVar(1),
    MV_SlotWheel3_Angle     = MapVar(2),
    MV_ProgressOnHitBlock1  = MapVar(3),
    MV_ProgressOnHitBlock2  = MapVar(4),
    MV_ProgressOnHitBlock3  = MapVar(5),
    MV_SlotMachineProgress  = MapVar(6),
    MV_AmbushID             = MapVar(10),
    MV_ResetCamSpeed        = MapVar(11),
};

enum {
    MF_HitStartBlock        = MapFlag(0),
    MF_Block1_Hit           = MapFlag(1),
    MF_Block2_Hit           = MapFlag(2),
    MF_Block3_Hit           = MapFlag(3),
    MF_Block1_Active        = MapFlag(4),
    MF_Block2_Active        = MapFlag(5),
    MF_Block3_Active        = MapFlag(6),
    MF_AnimateSlotLights    = MapFlag(7),
};

#define NAMESPACE omo_09

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupGizmos);
extern EvtScript N(EVS_SetupConveyors);
extern EvtScript N(EVS_SetupSlotMachine);
extern EvtScript N(EVS_Scene_KammySetAmbush);
extern EvtScript N(EVS_NpcIdle_Kammy);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(KammySceneNPCs);
extern NpcGroupList N(PokeyAmbushNPCs);
extern NpcGroupList N(KoopatrolAmbushNPCs);
extern NpcGroupList N(DefaultNPCs);

API_CALLABLE(N(DisableCameraLeadingPlayer));
API_CALLABLE(N(EnableCameraLeadingPlayer));
