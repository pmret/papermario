/// @file dgb_01.h
/// @brief Tubba's Castle - Great Hall

#include "common.h"
#include "map.h"

#define NAMESPACE dgb_01

enum {
    NPC_SENTINEL0,
    NPC_SENTINEL1,
    NPC_SENTINEL2,
    NPC_SENTINEL3,
    NPC_WORLD_TUBBA,
};

ApiStatus InitAnimatedModels(Evt* script, s32 isInitialCall);
ApiStatus SetAnimatedModelRenderMode(Evt* script, s32 isInitialCall);
ApiStatus DeleteAnimatedModel(Evt* script, s32 isInitialCall);

ApiStatus N(func_80240000_BFD880)(void);
ApiStatus N(GetEntityPosition)(Evt* script, s32 isInitialCall);
ApiStatus N(SetEntityFlags100000)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc1)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802422B0_BFFB30)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802430C0_C00940)(Evt* script, s32 isInitialCall);

extern EvtSource N(802449C4);
extern EvtSource N(80244AD0);
extern EvtSource N(main);
extern EvtSource N(makeEntities);
extern StaticAnimatorNode* N(D_80252F4C_C107CC)[];
extern EvtSource N(D_802539A0_C11220);
extern NpcGroupList N(npcGroupList_80246E50);
extern NpcGroupList N(npcGroupList_80246ED4);
extern NpcGroupList N(npcGroupList_80246E8C);
extern NpcGroupList N(npcGroupList_80246F1C);

extern Gfx D_80247F70_C057F0[];
extern Gfx D_80248FF0_C06870[];
extern Gfx D_80249870_C070F0[];
extern Gfx D_80249CF0_C07570[];
extern Gfx D_8024A170_C079F0[];
extern Gfx D_8024A5F0_C07E70[];
extern Gfx D_8024AE70_C086F0[];
extern Gfx D_8024B6F0_C08F70[];
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
