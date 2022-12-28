/// @file mgm_00.h
/// @brief Minigame - Playroom Lobby

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mgm.h"
#include "mapfs/mgm_00_shape.h"
#include "mapfs/mgm_00_hit.h"

#include "sprite/npc/Toad.h"

enum {
    NPC_RedToad         = 0,
    NPC_GreenToad       = 1,
    NPC_BlueToad        = 2,
};

enum {
    MV_RecordDisplayData        = MapVar(10),
};

#define NAMESPACE mgm_00

extern EvtScript N(EVS_Main);
extern EvtScript N(D_80243C40_E123E0);
extern EvtScript N(EVS_BindInteractTriggers);
extern EvtScript N(EVS_OnEnterPipe_JumpAttack);
extern EvtScript N(EVS_OnEnterPipe_SmashAttack);
extern NpcGroupList N(DefaultNPCs);

void msg_draw_frame(s32 posX, s32 posY, s32 sizeX, s32 sizeY, s32 style, s32 palette, s32 fading, s32 bgAlpha, s32 frameAlpha);
