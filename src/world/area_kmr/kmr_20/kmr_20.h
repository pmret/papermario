/// @file kmr_20.h
/// @brief Goomba Region - Mario's House

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kmr.h"
#include "mapfs/kmr_20_shape.h"
#include "mapfs/kmr_20_hit.h"

#include "sprite/npc/Luigi.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/ShyGuy.h"

enum {
	NPC_Parakarry               = 0,
	NPC_Luigi                   = 1,
	NPC_ShyGuy                  = 2,
};

enum {
    MF_Unk_0A       = MapFlag(10),
    MF_Unk_0B       = MapFlag(11),
    MF_Unk_0C       = MapFlag(12),
    MF_Unk_0D       = MapFlag(13),
};

#define NAMESPACE kmr_20

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_80242D78);
extern EvtScript N(EVS_PlayRestingSong);
extern EvtScript N(EVS_80242C40);
extern EvtScript N(EVS_80244228);
extern EvtScript N(EVS_80245638);
extern EvtScript N(EVS_8024A3A0);
extern EvtScript N(EVS_8024FD70);
extern EvtScript N(EVS_80250C5C);
extern EvtScript N(EVS_8025232C);
extern EvtScript N(EVS_80252490);
extern EvtScript N(EVS_8024AC34);
extern EvtScript N(EVS_8024BD40);
extern EvtScript N(EVS_80252E8C);
extern EvtScript N(D_80245374_8F1194);
extern EvtScript N(EVS_SetupTrees);
extern EvtScript N(EVS_SetupBushes);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(IntroNPCs);
extern NpcGroupList N(PrologueNPCs);
extern NpcGroupList N(EpilogueNPCs);
extern NpcGroupList N(NpcGroup1);

API_CALLABLE(N(func_80241C9C_8EDABC));
void msg_draw_frame(s32 posX, s32 posY, s32 sizeX, s32 sizeY, s32 style, s32 palette, s32 fading, s32 bgAlpha, s32 frameAlpha);
