/// @file kmr_02.h
/// @brief Goomba Region - Goomba Village

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kmr.h"
#include "mapfs/kmr_02_shape.h"
#include "mapfs/kmr_02_hit.h"

#include "sprite/npc/Goompa.h"
#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/Goombaria.h"
#include "sprite/npc/Gooma.h"
#include "sprite/npc/Goompapa.h"
#include "sprite/npc/Goomama.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/WorldEldstar.h"
#include "sprite/npc/WorldKammy.h"

enum {
    NPC_Goompa                  = 0,
    NPC_Goombaria               = 1,
    NPC_Goombario               = 2,
    NPC_Goompapa                = 3,
    NPC_Goomama                 = 4,
    NPC_Gooma                   = 5,
    NPC_Toad                    = 6,
    NPC_Kammy                   = 7,
    NPC_ChuckQuizmo             = 8,
    NPC_Eldstar_01              = 11,
    NPC_Eldstar_02              = 12,
    NPC_Parakarry               = 13,
};

enum {
    MV_Unk_00       = MapVar(0),
    MV_Unk_01       = MapVar(1),
#if VERSION_PAL
    MV_Unk_04       = MapVar(5),
    MV_Unk_05       = MapVar(6),
#else
    MV_Unk_04       = MapVar(4),
    MV_Unk_05       = MapVar(5),
#endif
};

enum {
    MF_SpawnFlag_BushCoin   = MapFlag(10),
    MF_SpawnFlag_Goomnut    = MapFlag(11),
};

#define NAMESPACE kmr_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_FadeOutMusic);
extern EvtScript N(EVS_PlayRestingSong);
extern EvtScript N(EVS_PushNewPartnerSong);
extern EvtScript N(EVS_PopSong);
extern EvtScript N(EVS_SetupRooms);
extern EvtScript N(EVS_SetupToadHouse);
extern EvtScript N(EVS_SetWallsDown_ToadHouse);
extern EvtScript N(EVS_Scene_KammyStrikes);
extern EvtScript N(EVS_NpcAux_Kammy);
extern EvtScript N(EVS_SummonGateBlock);
extern EvtScript N(EVS_NpcInteract_ToadHouse);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(EpilogueNPCs);
extern NpcGroupList N(NpcGroup1);
extern NpcGroupList N(PrologueNPCs);
extern NpcGroupList N(DefaultNPCs);

extern IMG_BIN N(heart_block_img)[];
extern PAL_BIN N(heart_block_pal)[];

API_CALLABLE(N(LoadPartyImage));
