/// @file pra_31.h
/// @brief Crystal Palace - Dino Puzzle Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../pra.h"
#include "mapfs/pra_31_shape.h"
#include "mapfs/pra_31_hit.h"

#include "animation_script.h"

enum {
    NPC_AlbinoDino_01       = 0,
    NPC_AlbinoDino_02       = 1,
    NPC_AlbinoDino_03       = 2,
};

enum {
    MV_PuzzleDataPtr    = MapVar(0),
    MV_PuzzleSolved     = MapVar(1),
    MV_PushingStatue    = MapVar(2),
    MV_DinoYaw_01       = MapVar(3),
    MV_DinoYaw_02       = MapVar(4),
    MV_DinoYaw_03       = MapVar(5),
    MV_StatueYaw_01     = MapVar(6),
    MV_StatueYaw_02     = MapVar(7),
    MV_StatueYaw_03     = MapVar(8),
};

#define NAMESPACE pra_31

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupPuzzle);
extern NpcGroupList N(DefaultNPCs);

API_CALLABLE(N(SetDinoAngle));

API_CALLABLE(InitAnimatedModels);
API_CALLABLE(SetAnimatedModelRenderMode);
API_CALLABLE(DeleteAnimatedModel);

extern StaticAnimatorNode* N(AS_Stairs_Skeleton)[];
extern AnimScript N(AS_Stairs_InitializeBefore);
extern AnimScript N(AS_Stairs_Unfold);
extern AnimScript N(AS_Stairs_InitializeAfter);

extern Gfx N(texture_1_gfx)[];
extern Gfx N(texture_2_gfx)[];
extern Gfx N(texture_3_gfx)[];

extern Vtx N(stairs_vtx)[];
extern Lights1 N(stairs_lights);
extern Matrix4s N(unk_30_mtx);
extern Matrix4s N(unk_26_mtx);
extern Matrix4s N(unk_24_mtx);
extern Matrix4s N(unk_22_mtx);
extern Matrix4s N(unk_20_mtx);
extern Matrix4s N(unk_18_mtx);
extern Matrix4s N(unk_16_mtx);
extern Matrix4s N(unk_14_mtx);
extern Matrix4s N(unk_12_mtx);
extern Matrix4s N(unk_10_mtx);
extern Matrix4s N(unk_08_mtx);
extern Matrix4s N(unk_06_mtx);
extern Matrix4s N(unk_04_mtx);
extern Matrix4s N(unk_02_mtx);
