/// @file sam_11.h
/// @brief Mt Shiver - Shiver City Pond Area

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../sam.h"
#include "mapfs/sam_11_shape.h"
#include "mapfs/sam_11_hit.h"

#include "sprite/npc/Herringway.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/PenguinPatrol.h"
#include "sprite/npc/Penguin.h"
#include "sprite/npc/Toadette.h"
#include "sprite/npc/WorldKooper.h"
#include "sprite/npc/Archeologist.h"
#include "sprite/npc/Kolorado.h"
#include "sprite/npc/WorldParakarry.h"

#include "animation_script.h"

enum {
	NPC_PenguinPatrol           = 0,
	NPC_Penguin_01              = 1,
	NPC_Herringway              = 2,
	NPC_Penguin_02              = 3,
	NPC_Penguin_03              = 4,
	NPC_Penguin_04              = 5,
	NPC_Penguin_05              = 6,
	NPC_Penguin_06              = 7,
	NPC_ThreeSisters_01         = 8,
	NPC_ThreeSisters_02         = 9,
	NPC_ThreeSisters_03         = 10,
	NPC_0B                      = 11,
	NPC_Kolorado                = 12,
	NPC_Archeologist_01         = 13,
	NPC_Archeologist_02         = 14,
	NPC_Kooper                  = 15,
	NPC_Parakarry               = 16,
	NPC_ChuckQuizmo             = 17,
};

enum {
	MV_Unk_00		= MapVar(0),
	MV_Unk_01		= MapVar(1),
	MV_Unk_02		= MapVar(2),
	MV_Unk_03		= MapVar(3),
	MV_Unk_04		= MapVar(4),
	MV_Unk_05		= MapVar(5),
	MV_Unk_06		= MapVar(6),
	MV_Unk_07		= MapVar(7),
	MV_Unk_09		= MapVar(9),
};

enum {
	MF_Unk_00		= MapFlag(0),
	MF_Unk_01		= MapFlag(1),
	MF_Unk_02		= MapFlag(2),
};

#define NAMESPACE sam_11

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_80243A78);
extern EvtScript N(EVS_8024D994);
extern EvtScript N(EVS_8024E544);
extern EvtScript N(D_80242280_D3C850);
extern EvtScript N(EVS_8024E090);
extern EvtScript N(D_80243B40_D3E110);
extern EvtScript N(D_80243BC0_D3E190);
extern EvtScript N(D_80243C40_D3E210);
extern EvtScript N(D_80243A38_D3E008);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(EpilogueNPCs);
extern NpcGroupList N(NpcGroup1);
extern NpcGroupList N(NpcGroup2);
extern NpcGroupList N(NpcGroup3);

extern StaticAnimatorNode* N(ShatterPondSkeleton)[];
extern AnimScript N(AS_ShatterPond);

//TODO sort these into an include somewhere
ApiStatus InitAnimatedModels(Evt* script, s32 isInitialCall);
ApiStatus SetAnimatedModelRenderMode(Evt* script, s32 isInitialCall);
ApiStatus DeleteAnimatedModel(Evt* script, s32 isInitialCall);
