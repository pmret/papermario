/// @file dgb_01.h
/// @brief Tubba's Castle - Great Hall

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dgb.h"
#include "mapfs/dgb_01_shape.h"
#include "mapfs/dgb_01_hit.h"

#include "sprite/npc/WorldTubba.h"
#include "sprite/npc/Sentinel.h"
#include "animation_script.h"

enum {
    NPC_Sentinel_01     = 0,
    NPC_Sentinel_02     = 1,
    NPC_Sentinel_03     = 2,
    NPC_Sentinel_04     = 3,
    NPC_Tubba           = 4,
};

enum {
    MV_PadlockEntityID  = MapVar(0),
};

#define NAMESPACE dgb_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_ExitDoors_dgb_08_0);
extern EvtScript N(EVS_ExitDoors_dgb_08_1);
extern EvtScript N(802449C4);
extern EvtScript N(EVS_UnlockPrompt_Door);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
extern NpcGroupList N(NpcGroup1);
extern NpcGroupList N(NpcGroup2);
extern NpcGroupList N(NpcGroup3);

extern StaticAnimatorNode* N(D_80252F4C_C107CC)[];
extern AnimScript N(AS_SmashBridges);

ApiStatus InitAnimatedModels(Evt* script, s32 isInitialCall);
ApiStatus SetAnimatedModelRenderMode(Evt* script, s32 isInitialCall);
ApiStatus DeleteAnimatedModel(Evt* script, s32 isInitialCall);

extern Gfx dgb_01_img0_gfx[];
extern Gfx dgb_01_img1_gfx[];
extern Gfx dgb_01_img2_gfx[];
extern Gfx dgb_01_img3_gfx[];
extern Gfx dgb_01_img4_gfx[];
extern Gfx dgb_01_img5_gfx[];
extern Gfx dgb_01_img6_gfx[];
extern Gfx dgb_01_img7_gfx[];
extern Gfx D_8024BCF8_C09578[];

extern Mtx N(D_80253160_C109E0);
extern Mtx N(D_802531A0_C10A20);
extern Mtx N(D_802531E0_C10A60);
extern Mtx N(D_80253220_C10AA0);
extern Mtx N(D_80253260_C10AE0);
extern Mtx N(D_802532A0_C10B20);
extern Mtx N(D_802532E0_C10B60);
extern Mtx N(D_80253320_C10BA0);
extern Mtx N(D_80253360_C10BE0);
extern Mtx N(D_802533A0_C10C20);
extern Mtx N(D_802533E0_C10C60);
extern Mtx N(D_80253420_C10CA0);
extern Mtx N(D_80253460_C10CE0);
extern Mtx N(D_802534A0_C10D20);
extern Mtx N(D_802534E0_C10D60);
extern Mtx N(D_80253520_C10DA0);
extern Mtx N(D_802535A0_C10E20);
extern Mtx N(D_802535E0_C10E60);
extern Mtx N(D_80253620_C10EA0);
extern Mtx N(D_80253660_C10EE0);
extern Mtx N(D_80253560_C10DE0);
extern Mtx N(D_802536A0_C10F20);
extern Mtx N(D_802536E0_C10F60);
extern Mtx N(D_80253720_C10FA0);
extern Mtx N(D_80253760_C10FE0);
extern Mtx N(D_802537A0_C11020);
extern Mtx N(D_802537E0_C11060);
extern Mtx N(D_80253820_C110A0);
extern Mtx N(D_80253860_C110E0);
extern Mtx N(D_802538A0_C11120);
extern Mtx N(D_802538E0_C11160);
extern Mtx N(D_80253920_C111A0);
extern Mtx N(D_80253960_C111E0);
