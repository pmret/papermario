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

ApiStatus InitAnimatedModels(Evt* script, s32 isInitialCall);
ApiStatus SetAnimatedModelRenderMode(Evt* script, s32 isInitialCall);
ApiStatus DeleteAnimatedModel(Evt* script, s32 isInitialCall);

extern StaticAnimatorNode* N(AS_Stairs_Skeleton)[];
extern AnimScript N(AS_Stairs_InitializeBefore);
extern AnimScript N(AS_Stairs_Unfold);
extern AnimScript N(AS_Stairs_InitializeAfter);

extern Gfx N(texture_1_gfx)[];
extern Gfx N(texture_2_gfx)[];
extern Gfx N(texture_3_gfx)[];

extern Vtx N(stairs_vtx)[];
extern Lights1 N(stairs_lights);
extern Matrix4s N(D_80247740_D864A0);
extern Matrix4s N(D_80247780_D864E0);
extern Matrix4s N(D_802477C0_D86520);
extern Matrix4s N(D_80247800_D86560);
extern Matrix4s N(D_80247840_D865A0);
extern Matrix4s N(D_80247880_D865E0);
extern Matrix4s N(D_802478C0_D86620);
extern Matrix4s N(D_80247900_D86660);
extern Matrix4s N(D_80247940_D866A0);
extern Matrix4s N(D_80247980_D866E0);
extern Matrix4s N(D_802479C0_D86720);
extern Matrix4s N(D_80247A00_D86760);
extern Matrix4s N(D_80247A40_D867A0);
extern Matrix4s N(D_80247A80_D867E0);
